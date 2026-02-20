#include "RuntimeContext.hpp"
#include "NotImplemented.hpp"
#include "PyBool.hpp"
#include "PyDict.hpp"
#include "PyFrame.hpp"
#include "PyNone.hpp"
#include "PyObject.hpp"
#include "Value.hpp"
#include "interpreter/Interpreter.hpp"
#include "vm/VM.hpp"

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

	if (m_interpreter) {
		// 修改：truthy 接收 Value，需要转换
		auto result = truthy(Value(obj), *m_interpreter);
		if (result.is_ok()) { return result.unwrap(); }
		return false;
	}

	// 降级：使用 PyObject::true_() 方法（符合 Python 3 语义）
	auto result = obj->true_();
	if (result.is_ok()) { return result.unwrap(); }

	// 最后的降级
	return obj != py_false() && obj != py_none();
}

PyObject *RuntimeContext::equals(PyObject *lhs, PyObject *rhs) const
{
	if (m_equals_provider) { return m_equals_provider(lhs, rhs); }

	if (m_interpreter) {
		// 修改：equals 接收 Value，需要转换
		auto result = py::equals(Value(lhs), Value(rhs), *m_interpreter);
		if (result.is_ok()) {
			auto eq_result = result.unwrap();
			// 修改：equals 返回 Value，需要提取 PyObject*
			if (std::holds_alternative<PyObject *>(eq_result)) {
				return std::get<PyObject *>(eq_result);
			}
			return not_implemented();
		}
		return not_implemented();
	}

	return lhs == rhs ? py_true() : py_false();
}

Value &RuntimeContext::stack_local(size_t index) const
{
	// 新路径：编译器 Runtime 提供的栈访问
	if (m_stack_local_provider) { return m_stack_local_provider(index); }

	// 旧路径：通过 Interpreter 访问 VM 栈
	if (m_interpreter) { return VirtualMachine::the().stack_local(index); }

	// 错误：无法访问栈
	// 修改：使用 thread_local 静态变量替代 static 局部变量
	thread_local static Value dummy;
	assert(false && "RuntimeContext: no stack_local provider set");
	return dummy;
}

}// namespace py