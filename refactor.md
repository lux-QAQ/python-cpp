# Pylang 重构计划 (Refactor Plan)

本文档描述了将现有 `Python C++` 项目重构为 `Pylang` 的技术路线图。`Pylang` 是一个高性能、兼容 Python 3.10+ 语法的编译型语言实现，利用 LLVM 生态系统进行静态分析与优化。

## 1. 核心愿景 (Vision)

*   **生态兼容**: 保持 Python 语法与语义的兼容性（不支持 `eval` 等运行时动态特性）。
*   **高性能**:
    *   **无 GIL (No Global Interpreter Lock)**: 利用 C++ 标准库的原子性实现真正的并行。
    *   **LLVM 优化**: 利用 LLVM 后端进行死代码消除 (DCE)、内联 (Inlining) 和机器码生成。
*   **架构革新**:
    *   `解释器 (VM)` -> `编译器 (Compiler Frontend)`
    *   `手写 GC` -> `C++ Standard RAII (std::shared_ptr)`

## 2. 架构概览 (Architecture)

整体架构转变为“编译器前端 + 静态运行时库”的编译流程。前端负责将 Python 源码转换为 LLVM IR，并与预编译的 Runtime Bitcode 进行链接。

```mermaid
graph TD
    subgraph "Development Time"
    R_SRC[Runtime C++ Source] -->|Clang| R_BC[Runtime Bitcode (.bc)]
    end

    subgraph "Compile Time (Pylang Compiler)"
    A[Python Source Code] -->|Parser| B(AST)
    B -->|Codegen| C(LLVM IR Module)
    R_BC -.->|Load & Link| C
    end
    
    subgraph "Native Compilation"
    C -->|LLVM/Clang Backend| D[Object File (.o)]
    D -->|Linker| E[Native Executable]
    end
```

### 2.1 编译执行流程
1.  **Runtime 预编译**: `src/runtime` 下的 C++ 代码被 Clang 编译为 LLVM Bitcode (`runtime.bc`)。这些代码中包含带有特殊 Attribute 标记的导出函数。
2.  **前端解析**: 用户输入的 Python 源码经过 Parser 生成 AST。
3.  **代码生成 (Lowering)**: 
    *   编译器前端加载 `runtime.bc`。
    *   遍历 AST，生成对应的 LLVM IR。
    *   当需要调用 Runtime 功能（如 `PyInteger::add`）时，前端根据 Attribute 在 `runtime.bc` 中查找对应的函数原型并生成调用指令。
4.  **优化与链接**: 生成的用户模块 IR 与 Runtime IR 进行模块级链接 (Link Modules)，此时大量 Runtime 函数（如小整数加法）可被 LLVM 内联优化。
5.  **后端输出**: 链接后的模块交给 LLVM Backend 生成目标机器码或可执行文件。
    

## 3. 内存管理重构 (Memory Management Refactor)

为了最大化开发便捷性并利用现代 C++ 特性，我们摒弃手写 GC 和复杂的内存池，转而全面拥抱 **C++ 标准库 RAII**。

### 3.1 核心机制：`std::shared_ptr`
所有 Python 对象在 C++ Runtime 中均通过 `std::shared_ptr<PyObject>` 进行管理。

*   **无需 GIL**: `std::shared_ptr` 的引用计数控制块在现代 C++ 标准库实现中是线程安全的（原子操作）。这意味着我们可以安全地在多线程环境传递对象而不需要全局锁。
*   **开发便捷**: C++ 开发人员不需要手动调用 `incref/decref`，也不需要编写 `Visit` 函数。一切生命周期由 C++ 作用域自动管理（Scope-based Resource Management）。

#### 示例代码对比
**旧代码 (GC Style):**
```cpp
// 需要手动考虑 GC 根节点，或者在 heap 上分配
auto* list = heap.allocate<PyList>();
list->append(value); // value 必须已经是被追踪的
```

**新代码 (RAII Style):**
```cpp
// 就像写普通 C++ 程序一样
std::shared_ptr<PyObject> py_add(std::shared_ptr<PyObject> a, std::shared_ptr<PyObject> b) {
    // 自动类型推导，自动内存释放
    auto result = std::make_shared<PyInteger>(a->as<PyInteger>()->value() + b->as<PyInteger>()->value());
    return result; 
} 
```

### 3.2 内存分配 (Allocation)
*   **策略**: 暂时直接使用系统默认分配器（即 `std::make_shared` 底层的 `new`）。
*   **理由**: 
    1.  **降低复杂度**: 引入第三方内存池（如 mimalloc）会增加构建和调试难度。
    2.  **足够快**: 现代操作系统的 `malloc` (如 glibc 2.30+, jemalloc) 性能已经非常优异。
    3.  **未来优化**: 如果瓶颈真的出现在分配上，我们可以在不改变应用逻辑的情况下，全局替换 `operator new` 或为 `shared_ptr` 提供自定义 `Allocator`。

### 3.3 循环引用 (Cycle Reference)
*   **策略**: 初期开发阶段接受循环引用可能导致的内存泄漏。这使得我们可以专注于核心语言特性的编译实现，而不是被 GC 算法细节拖累。
*   **未来规划**: 由于采用了标准的 `shared_ptr`，未来可以通过引入 `std::weak_ptr` 或编写一个运行在后台的 Cycle Detector（利用 `shared_ptr` 的 `use_count` 特征）来解决。

## 4. 关键模块重构清单

### 4.1 目录结构调整
```
pylang/
├── src/
│   ├── compiler/          # (New) 编译器前端
│   │   ├── codegen/       # AST -> LLVM IR 生成器
│   │   ├── driver/        # main入口，调用 LLVM 工具链
│   ├── runtime/           # (Refactor) 纯净的 Runtime 库
│   │   ├── core/          # PyObject (不再包含 GC 头)
│   │   ├── types/         # 重写为使用 shared_ptr 的容器
│   │   └── builtins/      # print, len 等内建函数
│   └── parser/            # (Keep) 现有的 Parser 实现
├── third_party/
│   └── llvm/              # LLVM 依赖
```

### 4.2 API 导出与 ABI
为了让编译器前端能够动态发现 Runtime 中的可用函数并生成正确的调用指令，我们不使用 `extern "C"`，而是利用 C++ 的 Attribute 特性。

1.  **定义 Attribute**: 在 Runtime 源码中使用特定的宏标记需要导出的 API。
2.  **Bitcode 保留**: 这些 Attribute 会被 Clang 编译到 `.bc` 文件中。
3.  **前端查找**: 编译器前端在加载 `runtime.bc` 后，遍历所有 Function，检查是否包含该 Attribute，从而建立 "Runtime Symbol Table"。

```cpp
// Runtime 代码示例
#define PYLANG_EXPORT __attribute__((annotate("pylang_runtime_export")))

PYLANG_EXPORT
std::shared_ptr<PyObject> runtime_add(std::shared_ptr<PyObject> a, std::shared_ptr<PyObject> b) {
    return a->add(b);
}
```

前端 Codegen 阶段：
```cpp
// 伪代码
Function* add_func = module->getFunctionWithAttribute("pylang_runtime_export", "runtime_add");
builder.CreateCall(add_func, {val_a, val_b});
```

## 5. 实施步骤 (Roadmap)

*详细的执行步骤请参见 `step.md`*

### 第一阶段：Runtime 清理与重组 (The Great Cleanup)
**注意**: 此阶段不能简单地删除或全局替换，必须采用**增量式重构**，确保每一步修改后测试均能通过。
1.  **基础设施准备**: 引入 LLVM 依赖，配置 GTest 环境。
2.  **对象模型改造**: 从叶子节点类型（如 `PyInteger`）开始，逐步移除 GC 依赖，替换为 `shared_ptr`。
3.  **测试驱动**: 利用现有的测试用例（Integration Tests 和 Unit Tests），修改一个模块即修复对应的测试，确保行为一致性。

### 第二阶段：编译器原型 (Compiler Prototype)
1.  **AST Lowering**: 创建 `src/compiler/codegen`，开始实现 `AST -> LLVM IR` 的转换器。
2.  **Hello World**: 
    *   并在 Runtime 中实现 `builtin_print`。
    *   实现生成 `main` 函数，构造字符串对象，调用 `print`。

### 第三阶段：功能补全
1.  **控制流**: `if`, `while` 等。
2.  **类与函数**: 实现 Python 函数调用约定（参数传递即 `shared_ptr` 拷贝）。

## 6. 与原项目的兼容性说明
*   **Parser**: 100% 复用。
*   **算法逻辑**: `src/runtime/types` 中的大部分 Python 语义逻辑（如切片计算、哈希算法）直接复用，仅修改内存管理接口。
*   **测试资产**: 必须完整保留 `integration/` 和 `src/*/tests` 下的测试用例，作为重构正确性的唯一标准。


