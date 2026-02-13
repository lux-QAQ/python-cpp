### 文档 1: Multi-file-compilation.md

该文档主要关注构建系统、Import 机制、标准库结构以及解决 AOT 编译中的符号与依赖问题。

```markdown
# Pylang 多文件编译与 Import 系统架构 (Multi-file Compilation & Import Architecture)

本文档详细描述了在 Pylang (AOT 编译器架构) 中如何处理多文件项目、Import 机制以及标准库模块。我们必须解决循环依赖、符号冲突、全局变量语义映射以及递归编译四大核心问题。

## 1. 标准库重构 (`src/runtime/modules`)

`src/runtime/modules` 目录包含 Python 标准库（如 `sys`, `math`, `builtins`）的 C++ 实现。这些模块在重构后将作为静态链接库的一部分。

### 1.1 核心策略：C++ ABI 与属性导出
为了完美支持 `std::shared_ptr<PyObject>` 等 C++ 模板类型在 LLVM IR 中的无缝传递和内联优化，我们**彻底摒弃 `extern "C"`**。

我们采用 **LLVM Attribute** 机制来定位 Runtime 入口函数。

1.  **保留 C++ Name Mangling**: 确保 Runtime 编译出的 `.bc` 文件中，函数签名包含完整的 C++ 类型信息。
2.  **Type Reuse (类型复用)**: 编译器前端在生成 IR 之前，必须先加载 `runtime.bc`，并直接使用其中定义的 `%class.std::shared_ptr` 等结构体类型，**严禁**在前端重新定义这些类型，以防止 ABI 不匹配。
3.  **Attribute 查找**: 编译器通过扫描 `pylang_init_func` 属性来查找模块初始化函数。

### 1.2 改造示例 (SysModule)

```cpp
// src/runtime/modules/SysModule.cpp
#include "runtime/api.hpp" 

namespace py {

// 内部实现 (Standard C++)
std::shared_ptr<PyModule> create_sys_module() {
    auto mod = std::make_shared<PyModule>("sys");
    mod->set_attr("path", std::make_shared<PyList>());
    return mod;
}

// 导出符号: PyInit_sys
// 1. 无 extern "C"，保留 C++ 特性
// 2. 使用 annotate 属性标记，编译器通过属性值 "sys" 识别这是 sys 模块的入口
// 3. 返回值直接使用 shared_ptr
__attribute__((annotate("pylang_init_func=sys")))
std::shared_ptr<PyObject> PyInit_sys() {
    // 使用 Runtime 的注册机制防止重复创建
    return Import::GetOrRegisterModule("sys", []() {
        return create_sys_module();
    });
}

}
```

---

## 2. AOT Import 系统核心设计

在 Pylang 中，`import foo` 不再是在运行时加载 `.py` 文件，而是**编译时**行为。

### 2.1 命名修饰与防冲突机制 (Name Mangling)
为了彻底解决路径与文件名之间的冲突（例如 `foo/bar.py` 与 `foo_bar.py`），我们采用 **Hex 转义编码** 规则生成用户模块的初始化函数名。

**编码规则**:
1.  字母 (`a-z`, `A-Z`) 和数字 (`0-9`) 保持不变。
2.  路径分隔符 `/` 或 `\` 替换为 `_2F_` (ASCII Hex)。
3.  下划线 `_` 替换为 `_5F_`。
4.  其他非字母数字字符替换为 `_XX_` (XX为ASCII十六进制)。
5.  统一前缀 `PyInit_`。

**冲突解决示例**:

| 源文件路径 | 原始名称 | Mangled Function Name |
| :--- | :--- | :--- |
| `main.py` | `main` | `PyInit_main` |
| `foo/bar.py` | `foo/bar` | `PyInit_foo_2F_bar` |
| `foo_bar.py` | `foo_bar` | `PyInit_foo_5F_bar` |

编译器驱动（Driver）负责执行此转义逻辑。

### 2.2 循环依赖与初始化守卫 (Check-Insert-Execute)
为了解决 `a.py` 导入 `b.py` 而 `b.py` 导入 `a.py` 导致的死锁或无限递归，我们需要在 Runtime 和 Codegen 层面共同配合。

#### A. Runtime 支持 (Import.cpp)
新增机制，允许“先占位，后初始化”。

```cpp
// 伪代码
std::shared_ptr<PyModule> GetOrRegisterModule(std::string name) {
    // 1. 如果模块已存在（即使正在初始化中），直接返回引用
    if (sys_modules.contains(name)) {
        return sys_modules[name];
    }
    // 2. 否则创建一个空的 Module 对象并注册到 sys.modules
    auto mod = std::make_shared<PyModule>(name);
    sys_modules[name] = mod;
    return mod;
}
```

#### B. 编译器生成的 IR 逻辑
对于源文件 `a.py`，编译器生成的代码结构如下：

```cpp
// C++ 伪代码展示生成的 IR 逻辑
// 函数名经过 Mangling
std::shared_ptr<PyObject> PyInit_a() {
    // 1. [Check & Insert] 获取或注册模块对象 (防止递归创建新实例)
    auto mod = runtime::GetOrRegisterModule("a"); 
    
    // 2. [Guard] 检查是否已经完成了 Body 执行 (防止递归重复执行)
    if (mod->is_initialized()) return mod; 
    
    // 3. 标记为已初始化 (或正在初始化)
    mod->set_initialized(true);

    // 4. [Execute] 执行模块体 (AST Lowering 的结果)
    
    // 处理 import b
    auto b_mod = PyInit_b(); // 递归调用
    mod->set_attr("b", b_mod);

    // 处理 x = 10
    mod->set_attr("x", PyInteger::create(10));
    
    return mod;
}
```

### 2.3 全局变量语义 (Global Variables)
**重要原则**: Python 的全局变量不是 C 语言的 `.data` 段变量，而是 Module 对象的 `__dict__` 条目。

*   **定义**: `x = 1` 编译为 `current_module->set_attr("x", 1)`。
*   **读取**: `print(x)` 编译为 `current_module->get_attr("x")`。
*   **跨模块读取**: `import a; print(a.x)` 编译为：
    1.  `call PyInit_a()` 获取模块指针。
    2.  `mod_a->get_attr("x")` 动态查找。

只有这样才能保持 Python 的动态特性（如后续代码删除了 `a.x`，或者 `a.x` 类型改变）。

---

## 3. 编译器驱动设计 (Build Manager)

我们将采用类似 Go 或 Rust 的构建模式。编译器驱动 (`Driver`) 将负责依赖分析和编译队列管理。

### 3.1 编译流程
假设用户运行 `./pylangc main.py`：

1.  **Entry Scan**: 解析 `main.py`，发现 `import foo.bar`。
2.  **Path Resolution**: 在 `PYTHONPATH` 中查找 `foo/bar.py`。
3.  **Dependency Queue**:
    *   计算 `foo/bar.py` 的 Mangled Name (`PyInit_foo_2F_bar`)。
    *   检查是否已编译。未编译则加入队列。
4.  **Codegen Loop**:
    *   **Runtime Linking**: 加载 `runtime.bc` 到 `llvm::Module`。建立 `Annotation -> Function*` 映射表。
    *   依次对队列中的文件生成 IR。
    *   对于 `import` 语句，直接通过 Mangled Name 生成 `Call` 指令。
    *   **关键**: 生成的 IR 必须使用 `runtime.bc` 中存在的 Struct Type。
5.  **Main Entry**:
    *   生成 `main()`，负责初始化 Runtime 环境，并调用 `PyInit_main`。
6.  **Backend**: 运行 LLVM Pass 优化，输出可执行文件。

---

## 4. 重构实施步骤 (Action Plan)

### 步骤 1: Runtime 基础改造 (Phase 2)
- [ ] **Import.hpp**: 实现 `GetOrRegisterModule` 和 `sys.modules` 的单例管理（使用 `shared_ptr`）。
- [ ] **Builtins**: 改造所有 modules，移除 `extern "C"`，添加 `__attribute__((annotate("pylang_init_func=name")))`。
- [ ] **PyModule**: 增加 `bool m_initialized` 标志位。

### 步骤 2: 编译器 Codegen 逻辑 (Phase 3)
- [ ] **Runtime Loader**: 实现 `RuntimeLinker`，加载 `.bc`，建立属性索引表。
- [ ] **Name Mangling**: 实现 `PathMangler::mangle(string path)`，使用 Hex 转义。
- [ ] **Init Function**: 修改 `LLVMGenerator`，生成带守卫的 Init 函数。
- [ ] **Var Access**: 确保所有 Module Level 的变量读写都转换为 `get_attr/set_attr` 调用。

### 步骤 3: 编译器 Driver 实现 (Phase 3)
- [ ] **Dependency Scanner**: 实现 AST Visitor 提取 import。
- [ ] **Build Queue**: 管理编译任务队列。
```