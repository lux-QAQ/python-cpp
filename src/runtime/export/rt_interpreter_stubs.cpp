#include "interpreter/InterpreterCore.hpp"
#include "runtime/GeneratorInterface.hpp"// 现在会根据 PYLANG_AOT_MODE 提供正确的 StackFrame
#include "runtime/PyFrame.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/Value.hpp"

#include <cstdio>
#include <cstdlib>

// 不再需要假的 StackFrame 定义 — GeneratorInterface.hpp 已处理

[[noreturn]] static void aot_unreachable(const char *func)
{
	fprintf(stderr,
		"\n=== FATAL: AOT MODE ===\n"
		"%s called in AOT binary — should never happen.\n",
		func);
	std::abort();
}

ScopedStack::~ScopedStack() {}

std::unique_ptr<StackFrame> ScopedStack::release() { aot_unreachable("ScopedStack::release"); }

ScopedStack Interpreter::setup_call_stack(const std::unique_ptr<Function> &, py::PyFrame *)
{
	aot_unreachable("Interpreter::setup_call_stack");
}

py::PyResult<py::PyObject *> Interpreter::call(const std::unique_ptr<Function> &, py::PyFrame *)
{
	aot_unreachable("Interpreter::call");
}

py::PyResult<py::PyObject *>
	Interpreter::call(const std::unique_ptr<Function> &, py::PyFrame *, StackFrame &)
{
	aot_unreachable("Interpreter::call");
}