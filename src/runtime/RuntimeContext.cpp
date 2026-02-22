#include "RuntimeContext.hpp"
#include "NotImplemented.hpp"
#include "PyBool.hpp"
#include "PyDict.hpp"
#include "PyFrame.hpp"
#include "PyNone.hpp"
#include "PyObject.hpp"
#include "Value.hpp"
#include "interpreter/InterpreterCore.hpp"

namespace py {

thread_local RuntimeContext *RuntimeContext::s_current = nullptr;

PyDict *RuntimeContext::current_globals() const
{
	if (m_globals_provider) { return m_globals_provider(); }

	if (m_interpreter) {
		auto *frame = m_interpreter->execution_frame();
		if (frame) {
			auto *globals = frame->globals();
			return as<PyDict>(globals);
		}
	}

	return nullptr;
}

bool RuntimeContext::is_true(PyObject *obj) const
{
	if (m_truthy_provider) { return m_truthy_provider(obj); }

	// 不再需要 Interpreter 特殊路径，直接用 PyObject 协议
	auto result = obj->true_();
	if (result.is_ok()) { return result.unwrap(); }
	return obj != py_false() && obj != py_none();
}

PyObject *RuntimeContext::equals(PyObject *lhs, PyObject *rhs) const
{
	if (m_equals_provider) { return m_equals_provider(lhs, rhs); }

	// 不再需要 Interpreter 特殊路径
	auto result = lhs->richcompare(rhs, RichCompare::Py_EQ);
	if (result.is_ok()) { return result.unwrap(); }
	return lhs == rhs ? py_true() : py_false();
}

Value &RuntimeContext::stack_local(size_t index) const
{
	// provider 路径（VM.cpp 初始化时设置）
	if (m_stack_local_provider) { return m_stack_local_provider(index); }

	// 移除 VM 降级路径 — provider 必须已设置
	thread_local static Value dummy;
	assert(false && "RuntimeContext: no stack_local provider set");
	return dummy;
}

}// namespace py