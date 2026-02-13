### 文档 2: `refactor_runtime_and_compiler.md`

该文档详细描述如何将现有的 Bytecode 生成逻辑改造为 LLVM IR 生成逻辑，以及 Runtime 配合改造的细节。

```markdown
# Runtime 重构与编译器后端实现指南 (Refactor Runtime & Compiler Backend)

本文档旨在指导如何将 `BytecodeGenerator` 转换为 `LLVMGenerator`，以及如何重构 Runtime 以暴露适合编译器调用的 ABI。

## 1. Runtime 重构：导出 ABI (Runtime Export)

为了支持 LLVM IR 编译，我们需要将核心操作（如加法、打印、属性访问）暴露为标准的 C++ 函数，并使用属性标记以便编译器前端发现。

### 1.1 定义导出宏
在 `src/runtime/common.hpp` 中定义宏：

```cpp
// 使用 annotate 属性标记导出函数，不破坏 C++ 名称修饰
#define PYLANG_EXPORT __attribute__((annotate("pylang_runtime_export")))
```

### 1.2 暴露核心操作 (`src/runtime/operations.cpp`)
目前的 `src/executable/bytecode/instructions/*.cpp` 包含了大量业务逻辑。我们需要将这些逻辑下沉到 Runtime 的导出函数中。

**必须完成的迁移工作：**

1.  **运算操作**: `BINARY_ADD` -> `runtime_add(lhs, rhs)`, `BINARY_SUBSCR` -> `runtime_getitem(obj, key)` 等。
2.  **内置函数**: `print` -> `runtime_print(arg)`.
3.  **属性访问**: `LOAD_ATTR` -> `runtime_getattr(obj, name)`.

**代码示例:**
```cpp
namespace py {

PYLANG_EXPORT
std::shared_ptr<PyObject> runtime_binary_add(std::shared_ptr<PyObject> lhs, std::shared_ptr<PyObject> rhs) {
    // 复用原有的 Value/PyObject add 逻辑
    return lhs->add(rhs);
}

PYLANG_EXPORT
std::shared_ptr<PyObject> runtime_call(std::shared_ptr<PyObject> callable, std::shared_ptr<PyTuple> args) {
    return callable->call(args);
}

}
```

---

## 2. 编译逻辑重构：从 `BytecodeGenerator` 到 `LLVMGenerator`

我们将创建一个新的类 `LLVMGenerator`，它继承自 `ast::CodeGenerator`。我们需要将“栈操作”思维转换为“SSA 值传递”思维。

### 2.1 架构对比

| 特性 | BytecodeGenerator | LLVMGenerator (新架构) |
| :--- | :--- | :--- |
| **输出目标** | `InstructionVector` | `llvm::IRBuilder<>` |
| **值表示** | `BytecodeValue` (寄存器索引) | `llvm::Value*` |
| **局部变量** | 寄存器映射 | `llvm::AllocaInst*` (栈上分配) |
| **类型系统** | 动态 (Runtime 处理) | 静态结构体 (`%class.std::shared_ptr`) |
| **控制流** | Label 跳转 | `llvm::BasicBlock` + `Br/CondBr` |

### 2.2 核心组件设计 (`LLVMGenerator`)

```cpp
class LLVMGenerator : public ast::CodeGenerator {
    llvm::LLVMContext& m_context;
    llvm::Module* m_module;
    llvm::IRBuilder<> m_builder;
    
    // 符号表：存储局部变量对应的 alloca 指令
    std::unordered_map<std::string, llvm::AllocaInst*> m_named_values;
    
    // Runtime 函数缓存
    std::unordered_map<std::string, llvm::Function*> m_runtime_funcs;

public:
    // 初始化时必须加载 runtime.bc
    void initialize(const std::string& runtime_bc_path);
    
    // 将 AST 节点转换为 llvm::Value*
    llvm::Value* visit(const ast::BinaryOperator* node) override;
    // ...
};
```

### 2.3 关键逻辑重构模式

#### A. 二元运算 (Binary Operations)
*旧模式*: 递归生成左右子树 -> 压栈 -> 发射指令。
*新模式*: 递归生成左右子树 (得到 `Value*`) -> 查找 Runtime 函数 -> 生成 Call 指令。

```cpp
llvm::Value* LLVMGenerator::visit(const ast::BinaryOperator* node) {
    llvm::Value* lhs = node->left->codegen(this);
    llvm::Value* rhs = node->right->codegen(this);
    
    // 根据 OpType 查找对应的 runtime_binary_xxx 函数
    llvm::Function* func = get_runtime_func(node->op_type()); 
    
    // 生成调用: runtime_add(lhs, rhs)
    return m_builder.CreateCall(func, {lhs, rhs}, "bin_op");
}
```

#### B. 局部变量与 SSA (Local Variables)
由于 Python 变量的动态性，我们不在前端进行 SSA 构建，而是利用 `alloca` 在栈上分配内存，后续依赖 LLVM 的 `mem2reg` Pass 自动优化为寄存器。

*   **函数入口**: 为所有局部变量创建 `alloca`。
*   **赋值 (Store)**: `m_builder.CreateStore(value, alloca_inst)`.
*   **读取 (Load)**: `m_builder.CreateLoad(type, alloca_inst)`.

#### C. 控制流 (Control Flow)
使用 LLVM 的 BasicBlock 机制。

*   `if` 语句:
    1.  创建 `ThenBB`, `ElseBB`, `MergeBB`。
    2.  生成条件表达式代码。
    3.  `m_builder.CreateCondBr(cond, ThenBB, ElseBB)`.
    4.  在 `ThenBB` 结束时 `CreateBr(MergeBB)`.

---

## 3. 具体实施步骤总结

### 第一步：Runtime 准备
1.  修改 CMakeLists.txt，增加 `add_custom_command` 调用 Clang 将 runtime 编译为 `runtime.bc`。
2.  创建 `src/runtime/operations.cpp`，实现并导出所有基础指令逻辑。
3.  确保所有导出函数均接受并返回 `std::shared_ptr<PyObject>`。

### 第二步：LLVMGenerator 基础
1.  复制 `VariablesResolver` (作用域解析逻辑完全复用)。
2.  实现 `RuntimeLinker`：解析 `runtime.bc`，根据 Attributes 填充函数映射表。
3.  实现 `LLVMGenerator::visit(Constant)`：生成创建 `PyInteger`, `PyString` 的 Runtime 调用。

### 第三步：控制流与运算
1.  实现 `visit(BinaryOperator)`。
2.  实现 `visit(IfStatement)` 和 `visit(WhileStatement)`。
3.  实现 `visit(FunctionDef)`：注意这里需要生成一个新的 LLVM Function，并处理闭包捕获（初期可先跳过闭包）。

### 第四步：集成测试
1.  编写简单的 `test.py` (`print(1+2)`).
2.  运行编译器 -> 生成 IR -> 链接 Runtime -> JIT 执行或编译为可执行文件。