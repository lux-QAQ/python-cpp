# Pylang Refactoring Roadmap (Step-by-Step)

This document details the step-by-step roadmap for refactoring `python-cpp` into `Pylang`. 
**Crucially, every step MUST be verified by running the existing test suite (GoogleTest). Do not proceed to the next step until all relevant tests pass.**

## Phase 1: Preparation & Infrastructure

### Step 1.1: Dependency & Build System Setup
- [ ] **Action**: Modify `CMakeLists.txt` to find and link `LLVM` (Core, IRReader, BitWriter, Support, etc.).
- [ ] **Action**: Ensure `GTest` is correctly configured and can run all existing tests (`src/parser/Parser_tests.cpp`, `src/runtime/PyDict_tests.cpp`, etc.).
- [ ] **Verification**: Run `ctest` or `./build/src/unittests_`. All existing tests must pass (parser, lexer, etc.).

### Step 1.2: Isolate Parser Tests
- [ ] **Action**: The current parser tests might depend on `Value` or `PyObject`. Identify dependencies.
- [ ] **Action**: Ensure `src/parser` tests are independent of the VM/GC infrastructure if possible.
- [ ] **Verification**: `src/parser/Parser_tests.cpp` passes.

## Phase 2: Runtime Refactoring (The Incremental Shift)

**Goal**: Transform `src/runtime` from a GC-based pointer system to a `std::shared_ptr` system without breaking the world immediately.

### Step 2.1: Introduce `PyObjPtr` Alias
- [ ] **Action**: Create `src/runtime/forward_new.hpp` (temporary) defining `using PyObjPtr = std::shared_ptr<PyObject>;`.
- [ ] **Action**: Create a compatibility shim if necessary to allow gradual migration.

### Step 2.2: Leaf Type Migration (Integer/Float/Bool)
- [ ] **Action**: Pick `PyInteger`.
- [ ] **Action**: Remove `Cell` inheritance from `PyInteger` (if possible without breaking `PyObject` hierarchy yet).
- [ ] **Action**: Change `PyInteger::create` to return `std::shared_ptr<PyInteger>`.
- [ ] **Action**: **Update Tests**: Modify `PyInteger` related unit tests to use `shared_ptr`.
- [ ] **Verification**: Compile and run unittests. Note: This will break the VM. We might need to temporarily disable VM-related tests or maintain two versions of `PyInteger` during transition?
    *   *Strategy Decision*: Since we are replacing the VM with a Compiler, we can accept that the **VM execution** tests will break and eventually be deleted. However, the **Runtime Logic** tests (e.g., `PyInteger::add` logic) MUST pass.
    *   **Action**: Create a new test file `src/runtime/PyInteger_refactor_tests.cpp` that tests the new `shared_ptr` based implementation.

### Step 2.3: Base Object Migration (`PyObject`)
- [ ] **Action**: Modify `PyObject` to stop inheriting from `Cell`.
- [ ] **Action**: Remove `visit_graph` methods from `PyObject` and subclasses.
- [ ] **Action**: Remove `Heap` allocation logic.
- [ ] **Verification**: Ensure compilation succeeds. This will likely cause massive errors in `src/vm` and `src/memory`.
- [ ] **Action**: **Delete/Exclude** `src/vm`, `src/memory`, `src/executable` (Bytecode VM) from the build. We are pivoting to a compiler.
- [ ] **Verification**: Fix build errors in `src/runtime` until the library compiles as a standalone static library.

### Step 2.4: Container Migration (List/Dict)
- [ ] **Action**: Modify `PyList` to store `std::vector<std::shared_ptr<PyObject>>`.
- [ ] **Action**: Modify `PyDict` to map `shared_ptr` to `shared_ptr`.
- [ ] **Action**: Port existing unit tests (`PyDict_tests.cpp`) to use smart pointers.
- [ ] **Verification**: `PyDict_tests` pass.

### Step 2.5: Runtime Bitcode Generation
- [ ] **Action**: Add a CMake step to compile `src/runtime/*.cpp` into LLVM Bitcode (`runtime.bc`) using Clang.
- [ ] **Action**: Add `__attribute__((annotate("pylang_runtime_export")))` to public runtime APIs (e.g., `PyObject::__add__`).
- [ ] **Verification**: Use `llvm-nm` or `llvm-dis` to inspect `runtime.bc` and verify the attributes and symbols exist.

## Phase 3: Compiler Frontend Implementation

### Step 3.1: Skeleton Compiler
- [ ] **Action**: Create `src/compiler/Compiler.cpp` and `main.cpp`.
- [ ] **Action**: Implement LLVM Context initialization and Module creation.
- [ ] **Action**: Implement loading `runtime.bc` and linking it into the main module.
- [ ] **Verification**: The compiler binary runs and outputs an empty LLVM module linked with runtime.

### Step 3.2: CodeGen - Literals
- [ ] **Action**: Implement `ASTVisitor` for `Constant` nodes.
- [ ] **Action**: Generate IR to call `PyInteger::create` (imported from runtime) for integer literals.
- [ ] **Action**: Create a test case `return 42`.
- [ ] **Verification**: Compile generated IR to an executable, run it, check exit code or output.

### Step 3.3: CodeGen - Printing
- [ ] **Action**: Implement `builtin_print` in Runtime (using `std::cout`).
- [ ] **Action**: Implement CodeGen for `Call` AST node (simple case).
- [ ] **Verification**: `print(42)` works.

### Step 3.4: CodeGen - Arithmetic
- [ ] **Action**: Implement `BinaryExpr` visitor.
- [ ] **Action**: Resolve `__add__` from Runtime attributes.
- [ ] **Verification**: `print(1 + 2)` works.

## Phase 4: Integration & Validation

### Step 4.1: Re-enable Integration Tests
- [ ] **Action**: Update `run_integration_tests.sh` to use the new compiler (generate binary -> execute) instead of the old VM interpreter.
- [ ] **Action**: Run the standard test suite (Fibonacci, Mandelbrot, etc.).

### Step 4.2: Performance Benchmarking
- [ ] **Action**: Compare execution time of `fibonacci.py` between Pylang (compiled) and CPython.

## Phase 5: Advanced Features (Later)
- [ ] Control Flow (`if`, `while`).
- [ ] Functions (`def`).
- [ ] Classes (`class`).
