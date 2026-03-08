## 分析 Bytecode 后端架构与 IREmitter 设计

### 1. Bytecode 后端的核心组件分析

#### 1.1 instructions 的作用

这个目录包含 **80+ 条虚拟机指令的定义和执行逻辑**，每条指令对应一个 Python 操作：

```
BuildTuple.cpp       → 创建 tuple 对象
BinaryOperation.cpp  → 二元运算（+, -, *, /）
LoadGlobal.cpp       → 加载全局变量
FunctionCall.cpp     → 函数调用
ForIter.cpp          → for 循环迭代
...
```

**关键观察**：
- 每条指令的 `execute()` 方法 = **runtime API 的调用序列**
- 例如 `BuildTuple::execute()` 调用 `PyTuple::create(elements)`
- 这些调用序列正是我们在 LLVM IR 中需要生成的 `call` 指令

**我们的编译器需要这些吗？**
- ❌ **不需要指令类本身**（我们不生成字节码）
- ✅ **需要其中的 runtime 调用逻辑**（作为 IR 生成的参考）

---

### 2. Bytecode 后端的三层架构

```
BytecodeGenerator (AST Visitor)
    │  职责：遍历 AST，决定生成哪些指令
    │  例如：visit(BinaryExpr*) → emit<BinaryOperation>(+)
    ▼
Instructions (80+ 指令类)
    │  职责：封装单个操作的语义
    │  例如：BinaryOperation::execute() → obj->add(other)
    ▼
Runtime API (src/runtime/)
    │  职责：实际的 Python 对象操作
    │  例如：PyObject::add() → slot 分派 → PyInteger::__add__
```

**对应到我们的编译器**：

```
PylangCodegen (AST Visitor)
    │  职责：遍历 AST，决定生成哪些 IR
    │  例如：visit(BinaryExpr*) → emitter.call_binary_add(lhs, rhs)
    ▼
IREmitter (Runtime Call 生成器)
    │  职责：封装 runtime 函数调用的 IR 生成
    │  例如：call_binary_add() → CreateCall(@rt_binary_add, {lhs, rhs})
    ▼
RuntimeLinker (函数索引)
    │  职责：提供 runtime 函数的 llvm::Function* 声明
    │  例如：declare_in(module, "binary_add") → Function*
    ▼
runtime.bc (LLVM Bitcode)
    │  职责：包含所有 runtime 函数的实现
    │  例如：rt_binary_add(obj, obj) → obj->add(other)
```

---

### 3. 从 Bytecode 指令到 IREmitter 方法的映射

#### 3.1 示例：`BuildTuple` 指令

**Bytecode 版本**（BuildTuple.cpp）：
```cpp
PyResult<Value> BuildTuple::execute(VirtualMachine &vm, Interpreter &) const
{
    std::vector<Value> elements;
    elements.reserve(m_size);
    if (m_size > 0) {
        auto *start = vm.sp() - m_size;  // 从栈顶取 m_size 个元素
        while (start != vm.sp()) {
            elements.push_back(*start);
            start = std::next(start);
        }
    }
    return PyTuple::create(std::move(elements)).and_then([&vm, this](PyTuple *tuple) {
        vm.reg(m_dst) = tuple;  // 结果存入寄存器
        return Ok(tuple);
    });
}
```

**IREmitter 版本**（我们要写的）：
```cpp
llvm::Value *IREmitter::create_tuple(llvm::ArrayRef<llvm::Value *> elements)
{
    if (elements.empty()) {
        // 空 tuple
        return emit_runtime_call("build_tuple", {
            m_builder.getInt32(0),
            llvm::ConstantPointerNull::get(...)
        });
    }

    // 创建临时数组存放元素指针
    auto *arr_type = llvm::ArrayType::get(pyobject_ptr_type(), elements.size());
    auto *arr = m_builder.CreateAlloca(arr_type, nullptr, "tuple_elems");

    for (size_t i = 0; i < elements.size(); ++i) {
        auto *gep = m_builder.CreateConstGEP2_32(arr_type, arr, 0, i);
        m_builder.CreateStore(elements[i], gep);
    }

    auto *count = m_builder.getInt32(static_cast<uint32_t>(elements.size()));
    auto *arr_ptr = m_builder.CreateBitCast(arr, ...);
    
    return emit_runtime_call("build_tuple", {count, arr_ptr});
}
```

**关键差异**：
- Bytecode：从 VM 栈读取元素 → 调用 `PyTuple::create`
- LLVM IR：从 LLVM 值数组读取 → 生成 `call @rt_build_tuple`

---

#### 3.2 示例：`BinaryOperation` 指令

**Bytecode 版本**（BinaryOperation.cpp）：
```cpp
PyResult<Value> BinaryOperation::execute(VirtualMachine &vm, Interpreter &interpreter) const
{
    const auto &lhs = vm.reg(m_lhs);
    const auto &rhs = vm.reg(m_rhs);

    const auto result = [&]() {
        switch (m_operation) {
        case Operation::PLUS:
            return add(lhs, rhs, interpreter);  // → obj->add(other)
        case Operation::MINUS:
            return subtract(lhs, rhs, interpreter);
        // ...
        }
    }();

    if (result.is_ok()) {
        vm.reg(m_destination) = result.unwrap();
    }
    return result;
}
```

**IREmitter 版本**：
```cpp
llvm::Value *IREmitter::call_binary_add(llvm::Value *lhs, llvm::Value *rhs)
{
    return emit_runtime_call("binary_add", {lhs, rhs});
}

// 通用调用生成器
llvm::Value *IREmitter::emit_runtime_call(
    std::string_view func_name,
    llvm::ArrayRef<llvm::Value *> args)
{
    auto *func = m_linker.declare_in(m_module, func_name);
    if (!func) {
        log::codegen()->error("Runtime function not found: {}", func_name);
        return nullptr;
    }
    return m_builder.CreateCall(func, args);
}
```

---

### 4. IREmitter 的设计原则

#### 4.1 职责边界

| 层次 | 职责 | 不负责 |
|:---|:---|:---|
| **IREmitter** | 生成 runtime 函数调用的 IR | AST 遍历、作用域管理、控制流 |
| **PylangCodegen** | AST 遍历、变量管理、控制流 | 知道 runtime 函数的签名 |
| **RuntimeLinker** | 提供 runtime 函数的声明 | 知道 Python 语义 |

#### 4.2 接口设计模式

**模式 1：直接映射**（1 个 bytecode 指令 = 1 个 IREmitter 方法）
```cpp
// BuildTuple → create_tuple
llvm::Value *create_tuple(llvm::ArrayRef<llvm::Value *> elements);

// BinaryOperation(PLUS) → call_binary_add
llvm::Value *call_binary_add(llvm::Value *lhs, llvm::Value *rhs);

// LoadGlobal → call_load_global
llvm::Value *call_load_global(llvm::Value *module, std::string_view name);
```

**模式 2：组合操作**（多个 bytecode 指令 = 1 个 IREmitter 方法）
```cpp
// LoadMethod + MethodCall → call_method
llvm::Value *call_method(llvm::Value *obj, std::string_view method_name,
                         llvm::ArrayRef<llvm::Value *> args);
```

**模式 3：辅助工具**（不对应 bytecode 指令）
```cpp
// 创建全局字符串常量
llvm::Constant *create_global_string(std::string_view str);

// 获取 PyObject* 类型
llvm::Type *pyobject_ptr_type() const;
```

---

### 5. 实施步骤（分阶段）

#### Phase 1: IREmitter 基础框架（Tier 0）

**目标**：支持 `print("hello")` 所需的最小集

```cpp
class IREmitter {
public:
    IREmitter(llvm::IRBuilder<> &builder, RuntimeLinker &linker, llvm::Module *module);

    // ---- Tier 0: 单例 ----
    llvm::Value *get_none();
    llvm::Value *get_true();
    llvm::Value *get_false();

    // ---- Tier 0: 对象创建 ----
    llvm::Value *create_string(std::string_view str);
    llvm::Value *create_tuple(llvm::ArrayRef<llvm::Value *> elements);

    // ---- Tier 0: 属性访问 ----
    llvm::Value *call_getattr(llvm::Value *obj, std::string_view name);
    llvm::Value *call_load_global(llvm::Value *module, std::string_view name);

    // ---- Tier 0: 函数调用 ----
    llvm::Value *call_function(llvm::Value *callable, llvm::Value *args,
                               llvm::Value *kwargs = nullptr);

    // ---- Tier 0: 模块导入 ----
    llvm::Value *call_import(std::string_view module_name);

private:
    llvm::Value *emit_runtime_call(std::string_view func_name,
                                    llvm::ArrayRef<llvm::Value *> args);
    llvm::Constant *create_global_string(std::string_view str);

    llvm::IRBuilder<> &m_builder;
    RuntimeLinker &m_linker;
    llvm::Module *m_module;
    std::unordered_map<std::string, llvm::Constant *> m_string_cache;
};
```

**参考的 Bytecode 指令**：
- `LoadConst` → `create_string`
- `BuildTuple` → `create_tuple`
- `LoadGlobal` → `call_load_global`
- `LoadAttr` → `call_getattr`
- `FunctionCall` → `call_function`
- `ImportName` → `call_import`

---

#### Phase 2: 表达式与运算（Tier 1）

```cpp
// ---- Tier 1: 二元运算 ----
llvm::Value *call_binary_add(llvm::Value *lhs, llvm::Value *rhs);
llvm::Value *call_binary_sub(llvm::Value *lhs, llvm::Value *rhs);
llvm::Value *call_binary_mul(llvm::Value *lhs, llvm::Value *rhs);
// ... 其他运算符

// ---- Tier 1: 一元运算 ----
llvm::Value *call_unary_neg(llvm::Value *obj);
llvm::Value *call_unary_not(llvm::Value *obj);

// ---- Tier 1: 类型转换 ----
llvm::Value *call_is_true(llvm::Value *obj);

// ---- Tier 1: 对象创建 ----
llvm::Value *create_integer(int64_t value);
llvm::Value *create_float(double value);
```

**参考的 Bytecode 指令**：
- `BinaryOperation` → `call_binary_*`
- `Unary` → `call_unary_*`
- `JumpIfFalse` / `JumpIfTrue` → `call_is_true`

---

#### Phase 3: 比较与控制流（Tier 2）

```cpp
// ---- Tier 2: 比较操作 ----
llvm::Value *call_compare_eq(llvm::Value *lhs, llvm::Value *rhs);
llvm::Value *call_compare_lt(llvm::Value *lhs, llvm::Value *rhs);
// ... 其他比较

// ---- Tier 2: 迭代器 ----
llvm::Value *call_get_iter(llvm::Value *obj);
llvm::Value *call_iter_next(llvm::Value *iter, llvm::Value *flag_out);
```

**参考的 Bytecode 指令**：
- `CompareOperation` → `call_compare_*`
- `GetIter` → `call_get_iter`
- `ForIter` → `call_iter_next`

---

#### Phase 4: 容器与下标（Tier 3）

```cpp
// ---- Tier 3: 容器创建 ----
llvm::Value *create_list(llvm::ArrayRef<llvm::Value *> elements);
llvm::Value *create_dict(llvm::ArrayRef<llvm::Value *> keys,
                         llvm::ArrayRef<llvm::Value *> values);

// ---- Tier 3: 下标访问 ----
llvm::Value *call_getitem(llvm::Value *obj, llvm::Value *key);
llvm::Value *call_setitem(llvm::Value *obj, llvm::Value *key, llvm::Value *value);
```

**参考的 Bytecode 指令**：
- `BuildList` / `BuildDict` → `create_list` / `create_dict`
- `BinarySubscript` → `call_getitem`
- `StoreSubscript` → `call_setitem`

---

### 6. 错误处理策略（利用 `Support/Error.hpp`）

#### 6.1 IREmitter 中的错误处理

**原则**：IREmitter 的方法返回 `llvm::Value*`（可能为 `nullptr`），**不抛出异常**。

```cpp
llvm::Value *IREmitter::emit_runtime_call(
    std::string_view func_name,
    llvm::ArrayRef<llvm::Value *> args)
{
    auto *func = m_linker.declare_in(m_module, func_name);
    if (!func) {
        // ❌ 不使用 Result<llvm::Value*>（LLVM API 不支持）
        // ✅ 记录错误日志 + 返回 nullptr
        log::codegen()->error("Runtime function not found: {}", func_name);
        return nullptr;
    }
    return m_builder.CreateCall(func, args);
}
```

**调用者检查**：
```cpp
// 在 PylangCodegen 中
auto *result = emitter.call_binary_add(lhs, rhs);
if (!result) {
    return MAKE_ERROR(ErrorKind::CodegenInternalError,
        "Failed to generate binary_add call");
}
```

#### 6.2 PylangCodegen 中的错误处理

**使用 `Result<T>` + `PYLANG_TRY` 宏**：

```cpp
Result<llvm::Value *> PylangCodegen::visit(const BinaryExpr *node)
{
    PYLANG_TRY(lhs, visit(node->lhs()));
    PYLANG_TRY(rhs, visit(node->rhs()));

    auto *result = [&]() -> llvm::Value * {
        switch (node->op_type()) {
        case BinaryOpType::PLUS:
            return m_emitter.call_binary_add(lhs, rhs);
        case BinaryOpType::MINUS:
            return m_emitter.call_binary_sub(lhs, rhs);
        // ...
        }
    }();

    if (!result) {
        return MAKE_ERROR(ErrorKind::CodegenInternalError,
            "Failed to generate binary operation");
    }

    return result;
}
```

---

### 7. 完整的实施计划

#### Step 1: 创建目录结构
```bash
mkdir -p src/compiler/Codegen
touch src/compiler/Codegen/IREmitter.{hpp,cpp}
touch src/compiler/Codegen/IREmitter_test.cpp
```

#### Step 2: 实现 IREmitter（Tier 0）
- 实现 `emit_runtime_call`（核心）
- 实现 `create_global_string`（辅助）
- 实现 Tier 0 的 6 个方法（单例、字符串、tuple、getattr、call、import）

#### Step 3: 编写单元测试
- 测试每个方法生成的 IR 结构
- 验证 runtime 函数声明正确注入
- 测试字符串缓存机制

#### Step 4: 逐步扩展 Tier 1-4
- 每个 Tier 完成后运行测试
- 参考对应的 Bytecode 指令实现

#### Step 5: 集成到 PylangCodegen
- 在 PylangCodegen 中持有 `IREmitter` 实例
- 在 `visit` 方法中调用 IREmitter 的接口

---

### 8. 关键注意事项

#### 8.1 LLVM API 的特殊性

**问题**：LLVM 的 `IRBuilder::CreateCall` 等方法返回裸指针，不支持 `Result<T>`。

**解决方案**：
- IREmitter 的方法返回 `llvm::Value*`（可能为 `nullptr`）
- 调用者（PylangCodegen）负责检查并转换为 `Result<T>`

#### 8.2 字符串常量的管理

**问题**：每次 `call_load_global("print")` 都创建新的全局字符串会导致 IR 膨胀。

**解决方案**：
- `m_string_cache` 缓存已创建的字符串常量
- `create_global_string` 先查缓存，未命中才创建

#### 8.3 参数类型验证

**问题**：`call_binary_add(lhs, rhs)` 如何确保 `lhs` 和 `rhs` 都是 `PyObject*` 类型？

**解决方案**（Phase 2 简化）：
- 不做类型检查，假设调用者传入正确类型
- Phase 3+ 可在 `emit_runtime_call` 中添加 `assert(arg->getType() == pyobject_ptr_type())`

---

## 总结

| 问题 | 答案 |
|:---|:---|
| `instructions/` 是什么？ | Bytecode VM 的指令定义，我们不需要这些类，但需要参考其 `execute()` 中的 runtime 调用逻辑 |
| IREmitter 的职责？ | 封装 runtime 函数调用的 IR 生成，提供高层 API 给 PylangCodegen |
| 如何利用 `Support/Error.hpp`？ | PylangCodegen 使用 `Result<T>` + `PYLANG_TRY`；IREmitter 返回裸指针 + 日志 |
| 实施顺序？ | Tier 0（hello world）→ Tier 1（表达式）→ Tier 2（控制流）→ Tier 3（容器）→ Tier 4（函数/闭包） |

根据 compile.md 的详细规划，我来分析当前 `IREmitter` 的完善程度：

---

## ✅ 已完成部分（Tier 0-3）

### Tier 0: print("hello world") 最小集 ✅

| 功能 | 状态 | 方法 |
|:---|:---:|:---|
| 单例（none/true/false/ellipsis） | ✅ | `get_none()` 等 |
| 字符串创建 | ✅ | `create_string()` |
| Tuple 创建 | ✅ | `create_tuple()` |
| 属性访问 | ✅ | `call_getattr()` |
| 全局变量加载 | ✅ | `call_load_global()` |
| 函数调用 | ✅ | `call_function()` |
| 模块导入 | ✅ | `call_import()` |
| 异常抛出 | ✅ | `call_raise()` |

### Tier 1: 表达式与赋值 ✅

| 功能 | 状态 | 方法 |
|:---|:---:|:---|
| 整数/浮点创建 | ✅ | `create_integer()`, `create_float()` |
| 列表创建 | ✅ | `create_list()` |
| 二元运算（12 种） | ✅ | `call_binary_add()` 等 |
| 一元运算（4 种） | ✅ | `call_unary_neg()` 等 |
| 类型转换 | ✅ | `call_is_true()` |
| 全局变量存储 | ✅ | `call_store_global()` |

### Tier 2: 比较与控制流 ✅

| 功能 | 状态 | 方法 |
|:---|:---:|:---|
| 比较操作（10 种） | ✅ | `call_compare_eq()` 等 |
| 迭代器 | ✅ | `call_get_iter()`, `call_iter_next()` |

### Tier 3: 容器与下标 ✅

| 功能 | 状态 | 方法 |
|:---|:---:|:---|
| 下标访问 | ✅ | `call_getitem()`, `call_setitem()`, `call_delitem()` |
| 容器方法 | ✅ | `call_list_append()`, `call_set_add()` |

---

## ⚠️ 缺失部分（根据 compile.md）

### 1. **Tier 3: 更多容器创建**

```cpp
// ❌ 缺失
llvm::Value *create_dict(llvm::ArrayRef<llvm::Value *> keys,
                         llvm::ArrayRef<llvm::Value *> values);
llvm::Value *create_set(llvm::ArrayRef<llvm::Value *> elements);
llvm::Value *create_slice(llvm::Value *start, llvm::Value *stop, llvm::Value *step);
```

**对应 runtime 函数**：
- `rt_build_dict` (已在 rt_create.cpp 中导出，但 IREmitter 未封装)
- `rt_build_set` (已导出)
- `rt_build_slice` (已导出)

---

### 2. **Tier 3: 更多容器方法**

```cpp
// ❌ 缺失
void call_list_extend(llvm::Value *list, llvm::Value *iterable);
void call_dict_merge(llvm::Value *dict, llvm::Value *other);
void call_dict_update(llvm::Value *dict, llvm::Value *other);
void call_set_update(llvm::Value *set, llvm::Value *iterable);
```

**对应 runtime 函数**：
- `rt_list_extend` (已在 rt_subscr.cpp 中导出)
- `rt_dict_merge` (已导出)
- `rt_dict_update` (已导出)
- `rt_set_update` (已导出)

---

### 3. **Tier 4: 函数与闭包**

```cpp
// ❌ 缺失
llvm::Value *call_make_function(llvm::Value *code, llvm::Value *module,
                                llvm::Value *defaults = nullptr,
                                llvm::Value *kwdefaults = nullptr,
                                llvm::Value *closure = nullptr);

llvm::Value *call_create_cell();
llvm::Value *call_cell_get(llvm::Value *cell);
void call_cell_set(llvm::Value *cell, llvm::Value *value);
llvm::Value *call_get_closure(llvm::Value *func);
```

**对应 runtime 函数**：
- `rt_make_function` (需要在 rt_func.cpp 中添加)
- `rt_create_cell` (需要添加)
- `rt_cell_get` / `rt_cell_set` (需要添加)
- `rt_get_closure` (需要添加)

---

### 4. **Tier 5: 类与继承**

```cpp
// ❌ 缺失
llvm::Value *call_load_build_class();
```

**对应 runtime 函数**：
- `rt_load_build_class` (需要在 `rt_class.cpp` 中添加)

---

### 5. **Tier 7: 增强赋值**

```cpp
// ❌ 缺失
llvm::Value *call_inplace_add(llvm::Value *lhs, llvm::Value *rhs);
llvm::Value *call_inplace_sub(llvm::Value *lhs, llvm::Value *rhs);
// ... 其他增强赋值
```

**对应 runtime 函数**：
- `rt_inplace_add` 等 (需要在 rt_op.cpp 中添加)

---

### 6. **Tier 3: 解包操作**

```cpp
// ❌ 缺失
void call_unpack_sequence(llvm::Value *obj, int32_t count, llvm::Value *out_array);
```

**对应 runtime 函数**：
- `rt_unpack_sequence` (需要在 rt_subscr.cpp 中添加)

---

### 7. **Tier 0: 局部变量操作**

```cpp
// ❌ 缺失（但可能不需要，因为局部变量用 alloca）
llvm::Value *call_load_name(llvm::Value *frame_ns, std::string_view name);
void call_store_name(llvm::Value *frame_ns, std::string_view name, llvm::Value *value);
```

**说明**：compile.md 中提到 `NAME` visibility 需要 `LoadName`/`StoreName`，但这可能在 PylangCodegen 中通过 `alloca` 实现，不一定需要 runtime 调用。

---

### 8. **Tier 6: 更多异常操作**

```cpp
// ❌ 缺失
void call_reraise();
llvm::Value *call_check_exception_match(llvm::Value *exc, llvm::Value *type);
```

**对应 runtime 函数**：
- `rt_reraise` (已在 rt_error.cpp 中导出)
- `rt_check_exception_match` (需要添加)

---

### 9. **Tier 7: f-string 支持**

```cpp
// ❌ 缺失
llvm::Value *call_format_value(llvm::Value *value, llvm::Value *format_spec);
llvm::Value *call_build_string(llvm::ArrayRef<llvm::Value *> parts);
```

**对应 runtime 函数**：
- `rt_format_value` (需要在 rt_create.cpp 中添加)
- `rt_build_string` (已导出)

---

### 10. **Tier 7: 更多模块操作**

```cpp
// ❌ 缺失
llvm::Value *call_import_from(llvm::Value *module, std::string_view name);
void call_import_star(llvm::Value *module, llvm::Value *namespace_dict);
```

**对应 runtime 函数**：
- `rt_import_from` (需要在 rt_module.cpp 中添加)
- `rt_import_star` (需要添加)

---

## 📊 完善度评估

| Tier | 功能 | 完成度 | 缺失项 |
|:---:|:---|:---:|:---|
| **Tier 0** | print("hello") 最小集 | **100%** | 无 |
| **Tier 1** | 表达式与赋值 | **100%** | 无 |
| **Tier 2** | 比较与控制流 | **100%** | 无 |
| **Tier 3** | 容器与下标 | **70%** | dict/set/slice 创建，容器方法，解包 |
| **Tier 4** | 函数与闭包 | **30%** | make_function, cell 操作 |
| **Tier 5** | 类与继承 | **20%** | load_build_class, setattr/delattr |
| **Tier 6** | 异常处理 | **50%** | reraise, check_exception_match |
| **Tier 7** | 增强赋值/f-string | **0%** | 全部缺失 |

**总体完成度**：**约 65%**（Tier 0-2 完整，Tier 3-7 部分缺失）

---

## 🎯 优先级建议

### Phase 2.5（Hello World）需要补充：

**无需补充**，当前 Tier 0-1 已足够支持 `print("hello")`。

### Phase 3.1（表达式 + 控制流）需要补充：

1. ✅ **Tier 3 容器创建**（优先级：高）
   ```cpp
   llvm::Value *create_dict(...);
   llvm::Value *create_set(...);
   ```

2. ✅ **Tier 3 解包操作**（优先级：高）
   ```cpp
   void call_unpack_sequence(...);
   ```

### Phase 3.2（函数定义）需要补充：

3. ✅ **Tier 4 函数与闭包**（优先级：高）
   ```cpp
   llvm::Value *call_make_function(...);
   llvm::Value *call_create_cell();
   llvm::Value *call_cell_get(...);
   void call_cell_set(...);
   ```

### Phase 3.3（类定义）需要补充：

4. ✅ **Tier 5 类与继承**（优先级：中）
   ```cpp
   llvm::Value *call_load_build_class();
   ```

5. ✅ **setattr/delattr**（已有，但需验证）

### Phase 3.4（异常处理）需要补充：

6. ✅ **Tier 6 异常操作**（优先级：中）
   ```cpp
   void call_reraise();
   llvm::Value *call_check_exception_match(...);
   ```

### Phase 3.5（高级特性）需要补充：

7. ✅ **Tier 7 增强赋值**（优先级：低）
   ```cpp
   llvm::Value *call_inplace_add(...);
   // ... 其他 11 种
   ```

8. ✅ **Tier 7 f-string**（优先级：低）
   ```cpp
   llvm::Value *call_format_value(...);
   llvm::Value *call_build_string(...);
   ```

---

## ✅ 结论

**当前 IREmitter 对于 Phase 2.5（Hello World）是完全足够的**。

**对于 Phase 3.1-3.5，需要逐步补充以下内容**：

1. **立即需要**（Phase 3.1）：
   - `create_dict()`, `create_set()`, `create_slice()`
   - `call_unpack_sequence()`
   - 容器方法（`list_extend`, `dict_merge` 等）

2. **Phase 3.2 需要**：
   - `call_make_function()` 及相关 cell 操作

3. **Phase 3.3+ 需要**：
   - `call_load_build_class()`
   - 增强赋值、f-string、import_from/star

**建议**：按照 compile.md 的 Tier 顺序，在实施 Phase 3.1 之前补充 Tier 3 的缺失方法，在 Phase 3.2 之前补充 Tier 4 的方法，以此类推。

**当前代码质量**：✅ 架构清晰，测试完善，可直接用于 Phase 2.5 的 Hello World 验证。



