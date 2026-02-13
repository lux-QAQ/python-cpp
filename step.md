# Pylang 重构详细路线图 (Step-by-Step Roadmap)

本文档详细拆解了将 `python-cpp` 重构为 `Pylang` 编译器的具体步骤。
**核心原则：每一步都必须通过测试验证。在当前步骤的测试通过之前，严禁进入下一步。**

## 第一阶段：基础设施与环境准备 (Phase 1: Infrastructure)

此阶段目标是建立 LLVM 开发环境，并确保现有的非 VM 依赖代码（如 Parser）是稳健的。

### 步骤 1.1: 构建系统配置
- [x] **行动 (Action)**: 修改根目录 `CMakeLists.txt`，添加 LLVM 依赖查找与配置。
    ```cmake
    find_package(LLVM REQUIRED CONFIG)
    message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
    include_directories(${LLVM_INCLUDE_DIRS})
    add_definitions(${LLVM_DEFINITIONS})
    ```
- [x] **行动 (Action)**: 确保 GTest 配置正确，能够运行现有的单元测试。
- [x] **验证 (Verification)**: 运行 `cmake .` 成功找到 LLVM。运行 `./build/src/unittests_` 确保现有测试全部通过。

已经添加
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
但是删除了include_directories
否则会导致abi中的异常处理不同而导致报错。



### 步骤 1.2: 隔离 Parser 测试
- [x] **行动 (Action)**: 检查 `src/parser/Parser_tests.cpp`。目前的测试可能隐式依赖了 VM 或 GC 及其相关对象。
- [x] **行动 (Action)**: 如果 Parser 测试依赖了 `PyObject` 的 GC 特性，需要将其解耦。Parser 应仅依赖 AST 结构和基础值类型。
- [x] **验证 (Verification)**: 确保 `src/parser/Parser_tests.cpp` 可以独立通过测试。

---

## 第二阶段：Runtime 增量重构 (Phase 2: Runtime Refactoring)

此阶段目标：将 `src/runtime` 从 **裸指针+GC** 转换为 **智能指针(RAII)**。
**重大变更警告**：一旦开始修改 `PyObject` 基类，原有的 `src/vm` (虚拟机) 将彻底损坏。我们将在此阶段正式废弃 VM，转而维护一个纯粹的 Runtime 库。

### 步骤 2.1: 引入智能指针别名
- [ ] **行动 (Action)**: 创建 `src/runtime/types/forward_new.hpp` (或更新 `api.hpp`)，定义标准指针类型，方便后续统一替换。
    ```cpp
    #include <memory>
    namespace py {
        class PyObject;
        using PyObjPtr = std::shared_ptr<PyObject>;
        
        // 使用 make_shared 优化内存分配（合并对象与控制块）
        // 辅助转换函数
        template<typename T, typename... Args>
        std::shared_ptr<T> make_py(Args&&... args) {
            return std::make_shared<T>(std::forward<Args>(args)...);
        }
    }
    ```

### 步骤 2.2: 叶子类型迁移 (以 PyInteger 为例)
从最简单的类型开始，验证 `shared_ptr` 机制。
- [ ] **行动 (Action)**: 修改 `src/runtime/PyInteger.hpp/cpp`。
    -   修改 `create` 方法：返回 `std::shared_ptr<PyInteger>`，并内部使用 `std::make_shared`。
    -   移除 `visit_graph` 实现（暂时保留空函数以兼容基类，稍后删除）。
- [ ] **行动 (Action)**: **新建测试文件** `src/runtime/PyInteger_refactor_tests.cpp`。
    -   测试整数创建、加法运算。
    -   验证离开作用域后对象是否自动析构（可以通过日志或 Mock 验证）。
- [ ] **验证 (Verification)**: 编译并运行新测试 `PyInteger_refactor_tests`，必须通过。此时原有的 VM 测试可能会编译失败，**从 CMake 中暂时排除 `src/vm` 目录**。

### 步骤 2.3: 基类大重构 (The Pivot)
- [ ] **行动 (Action)**: 修改 `src/runtime/PyObject.hpp`。
    -   **移除** `: public Cell` 继承，改为继承 `public std::enable_shared_from_this<PyObject>`。这是为了在成员函数中能安全调用 `shared_from_this()` (即 `self`)。
    -   **必须**添加 `virtual ~PyObject() = default;` 以确保多态析构正确执行。
    -   **移除** `visit_graph` 虚函数。
    -   **移除** 任何对 `Heap` 的调用。
- [ ] **行动 (Action)**: 全局清理 `src/runtime` 下所有子类的编译错误。
    -   所有 `create` 函数改为返回 `std::shared_ptr`。
    -   所有 `PyObject*` 成员变量改为 `std::shared_ptr<PyObject>`。
    -   删除所有 `visit_graph` 实现。
- [ ] **验证 (Verification)**: 这是一个巨大的工作量。目标是让 `src/runtime` 作为一个静态库 (`libpylang-runtime`) 能够独立编译通过。

### 步骤 2.4: 容器类型迁移 (List/Dict)
- [ ] **行动 (Action)**: 重构 `PyList`。
    -   内部存储从 `std::vector<Value>` (如果 Value 包含裸指针) 改为 `std::vector<PyObjPtr>`。
- [ ] **行动 (Action)**: 重构 `PyDict`。
    -   键值对存储改为智能指针。
- [ ] **验证 (Verification)**: 移植并运行 `src/runtime/PyDict_tests.cpp`，确保在无 GC 环境下字典逻辑正确。

### 步骤 2.5: Runtime Bitcode 生成与导出
- [ ] **行动 (Action)**: 定义导出宏 (在 `runtime/api.hpp` 中)。
    ```cpp
    #define PYLANG_EXPORT __attribute__((annotate("pylang_runtime_export")))
    ```
- [ ] **行动 (Action)**: 标记关键 API。例如在 `PyInteger::add` 或 `py_add` 函数上添加 `PYLANG_EXPORT`。
- [ ] **行动 (Action)**: 修改 CMake，增加 `clang -emit-llvm` 步骤，将 Runtime 源码编译为 `runtime.bc` (Bitcode 文件)。
- [ ] **验证 (Verification)**: 使用 `llvm-dis runtime.bc | grep "pylang_runtime_export"` 确认 Attribute 存在。

---

## 第三阶段：编译器前端实现 (Phase 3: Compiler Frontend)

此阶段目标：实现 `src/compiler`，将 AST 转换为 LLVM IR，并链接 Runtime。

### 步骤 3.1: 编译器骨架 (Skeleton)
- [ ] **行动 (Action)**: 创建 `src/compiler/Main.cpp` 和 `Compiler.hpp`。
- [ ] **行动 (Action)**: 初始化 `llvm::LLVMContext`, `llvm::Module`, `llvm::IRBuilder`。
- [ ] **行动 (Action)**: 移植 `src/executable/bytecode/codegen/VariablesResolver.cpp` 到 `src/compiler/VariablesResolver.cpp`。这是为了复用现有的作用域分析逻辑（LEGB规则）。
- [ ] **验证 (Verification)**: 编译并运行编译器，输出一个空的 `.ll` 文件。

### 3.2: Runtime 链接器 (Runtime Linker)
这是连接 Runtime 和编译器的桥梁。
- [ ] **行动 (Action)**: 实现 `RuntimeLinker` 类。
    -   加载 `runtime.bc` 文件。
    -   遍历 Module 中的所有 Function。
    -   建立 `std::map<std::string, llvm::Function*>` 符号表，仅包含带有 `pylang_runtime_export` 属性的函数。
- [ ] **验证 (Verification)**: 编译器启动时打印出所有检测到的 Runtime 导出函数名（如 `py_add`, `PyInteger_create`）。

### 步骤 3.3: CodeGen - 移植核心逻辑
**策略**: 不要从头重写 AST 访问器。参考 `src/executable/bytecode/codegen/BytecodeGenerator.cpp` 的逻辑，将其移植到 `LLVMGenerator`。
- [ ] **行动 (Action)**: 移植 `visit(Constant*)`。参考 `BytecodeGenerator::load_const`，改为生成 `PyInteger_create` 等 Runtime 调用。
- [ ] **行动 (Action)**: 实现 `ASTVisitor` 的 `visit(Constant*)`。
    -   对于整数：生成调用 Runtime 函数 `PyInteger::create(int64_t)` 的 IR 指令。
- [ ] **行动 (Action)**: 创建简单的测试用例 `test_int.py` (内容: `42`)。
- [ ] **验证 (Verification)**: 
    1. 编译器生成 IR。
    2. 生成的 IR 链接 `runtime.bc`。
    3. 使用 `lli` (LLVM Interpreter) 或编译为可执行文件运行，不崩溃。

### 步骤 3.4: CodeGen - 移植控制流与运算
**策略**: 借鉴 `BytecodeGenerator` 的语义处理逻辑，直接在 AST Visitor 中生成等价的 LLVM IR。
- [ ] **行动 (Action)**: 在 Runtime 中实现 `builtin_print` 并导出。
- [ ] **行动 (Action)**: 实现 `Call` 节点的 CodeGen。
- [ ] **验证 (Verification)**: 编译并运行 `print(123)`，终端输出 `123`。

### 3.5: CodeGen - 移植循环与异常
- [ ] **行动 (Action)**: 实现 `BinaryExpr` 的 CodeGen。
- [ ] **行动 (Action)**: 查找 Runtime 中的 `py_add` (或类似分发函数) 并生成调用。
- [ ] **行动 (Action)**: 移植 `For` 循环逻辑。参考 `ForIter.cpp` 指令，将其中的 `StopIteration` 异常捕获逻辑转换为 LLVM 的 BasicBlock 跳转 (invoke/landingpad)。
- [ ] **验证 (Verification)**: 编译并运行 `print(1 + 2)`，输出 `3`。

---

## 第四阶段：集成与验证 (Phase 4: Integration)

### 步骤 4.1: 端到端测试套件修复
- [ ] **行动 (Action)**: 重写 `run_integration_tests.sh`。
    -   旧流程：`./python-cpp input.py`
    -   新流程：`./pylangc input.py -o output && ./output`
- [ ] **验证 (Verification)**: 运行 `integration/fibonacci/fibo.py`，确保结果正确。

### 步骤 4.2: 性能基准测试
- [ ] **行动 (Action)**: 对比 Pylang 编译版 vs CPython 解释版的斐波那契数列计算时间。
- [ ] **行动 (Action)**: 验证是否存在内存泄漏 (使用 Valgrind 或 ASAN)。

---

## 第五阶段：高级特性补全 (Phase 5: Advanced Features)

- [ ] 实现控制流 (`if`, `while`, `for`) 的 IR 生成。
- [ ] 实现函数定义 (`def`) 的 IR 生成（涉及闭包和栈帧结构，较为复杂）。
- [ ] 实现类定义 (`class`)。
