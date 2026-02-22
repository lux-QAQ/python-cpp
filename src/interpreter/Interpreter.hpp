#pragma once

// 完整版 — 给 VM 层、bytecode 指令使用
#include "InterpreterCore.hpp"
#include "vm/VM.hpp"

#ifdef PYLANG_USE_ARENA
#include "memory/Arena.hpp"
#endif

// allocate_object 模板实现（需要 VirtualMachine::the().heap()）
template<typename PyObjectType, typename... Args>
py::PyObject *Interpreter::allocate_object(const std::string &name, Args &&...args)
{
#ifdef PYLANG_USE_ARENA
    if (auto obj = py::Arena::current().allocate<PyObjectType>(std::forward<Args>(args)...)) {
#else
    auto &heap = VirtualMachine::the().heap();
    if (auto obj = heap.allocate<PyObjectType>(std::forward<Args>(args)...)) {
#endif
        store_object(name, obj);
        return obj;
    } else {
        return nullptr;
    }
}