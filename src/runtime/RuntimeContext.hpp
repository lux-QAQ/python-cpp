#pragma once

#include <cassert>
#include <functional>
#include <optional>

#include "../forward.hpp"
#include "forward.hpp"

class Interpreter;

namespace py {

class 
RuntimeContext
{
	::Interpreter *m_interpreter{ nullptr };
	std::function<PyDict *()> m_globals_provider{ nullptr };
	std::function<bool(PyObject *)> m_truthy_provider{ nullptr };
	std::function<PyObject *(PyObject *, PyObject *)> m_equals_provider{ nullptr };
	std::function<Value &(size_t)> m_stack_local_provider{ nullptr };

	static thread_local RuntimeContext *s_current;

  public:
	static RuntimeContext &current()
	{
		assert(s_current && "RuntimeContext not initialized");
		return *s_current;
	}

	static bool has_current() { return s_current != nullptr; }
	static void set_current(RuntimeContext *ctx) { s_current = ctx; }

	struct Guard
	{
		RuntimeContext *m_prev;
		explicit Guard(RuntimeContext *ctx) : m_prev(s_current) { s_current = ctx; }
		~Guard() { s_current = m_prev; }
		Guard(const Guard &) = delete;
		Guard &operator=(const Guard &) = delete;
	};

	// ---- Interpreter 访问 ----
	::Interpreter *interpreter() const { return m_interpreter; }
	bool has_interpreter() const { return m_interpreter != nullptr; }
	void set_interpreter(::Interpreter *interp) { m_interpreter = interp; }

	// ---- Globals 访问 ----
	PyDict *current_globals() const;
	void set_globals_provider(std::function<PyDict *()> provider)
	{
		m_globals_provider = std::move(provider);
	}

	// ---- Truthy 判断 ----
	bool is_true(PyObject *obj) const;
	void set_truthy_provider(std::function<bool(PyObject *)> provider)
	{
		m_truthy_provider = std::move(provider);
	}

	// ---- 相等比较 ----
	PyObject *equals(PyObject *lhs, PyObject *rhs) const;
	void set_equals_provider(std::function<PyObject *(PyObject *, PyObject *)> provider)
	{
		m_equals_provider = std::move(provider);
	}

	// ---- 栈访问 ----
	Value &stack_local(size_t index) const;
	void set_stack_local_provider(std::function<Value &(size_t)> provider)
	{
		m_stack_local_provider = std::move(provider);
	}
};

}// namespace py