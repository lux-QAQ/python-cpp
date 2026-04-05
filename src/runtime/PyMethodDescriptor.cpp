#include "PyMethodDescriptor.hpp"
#include "PyFunction.hpp"
#include "PyString.hpp"
#include "PyType.hpp"
#include "TypeError.hpp"
#include "interpreter/InterpreterCore.hpp"
#include "runtime/compat.hpp"
#include "taggered_pointer/RtValue.hpp"
#include "types/api.hpp"
#include "types/builtin.hpp"

namespace py {

template<> PyMethodDescriptor *as(PyObject *obj)
{
	if (obj->type() == types::method_wrapper()) { return static_cast<PyMethodDescriptor *>(obj); }
	return nullptr;
}

template<> const PyMethodDescriptor *as(const PyObject *obj)
{
	if (obj->type() == types::method_wrapper()) {
		return static_cast<const PyMethodDescriptor *>(obj);
	}
	return nullptr;
}

PyMethodDescriptor::PyMethodDescriptor(PyType *type) : PyBaseObject(type) {}

PyMethodDescriptor::PyMethodDescriptor(PyString *name,
	PyType *underlying_type,
	MethodDefinition &method_definition,
	std::vector<PyObject *> &&captures)
	: PyBaseObject(types::BuiltinTypes::the().method_wrapper()), m_name(std::move(name)),
	  m_underlying_type(underlying_type), m_method(method_definition),
	  m_captures(std::move(captures))
{}

PyResult<PyMethodDescriptor *> PyMethodDescriptor::create(PyString *name,
	PyType *underlying_type,
	MethodDefinition &method,
	std::vector<PyObject *> &&captures)
{
	auto *obj =
		PYLANG_ALLOC(PyMethodDescriptor, name, underlying_type, method, std::move(captures));
	if (!obj) { return Err(memory_error(sizeof(PyMethodDescriptor))); }
	return Ok(obj);
}

void PyMethodDescriptor::visit_graph(Visitor &visitor)
{
	PyObject::visit_graph(visitor);
	if (m_name) visitor.visit(*m_name);
	if (m_underlying_type) visitor.visit(*m_underlying_type);
	for (auto *capture : m_captures) { visitor.visit(*capture); }
}

std::string PyMethodDescriptor::to_string() const
{
	return fmt::format(
		"<method '{}' of '{}' objects>", m_name->to_string(), m_underlying_type->name());
}

PyResult<PyObject *> PyMethodDescriptor::__repr__() const { return PyString::create(to_string()); }

PyResult<PyObject *> PyMethodDescriptor::__call__(PyTuple *args, PyDict *kwargs)
{
	// split args tuple -> (args[0], args[1:])
	// since args[0] is self (hopefully)
	std::vector<Value> new_args_vector;
	new_args_vector.reserve(args->size() - 1);
	auto self_ = PyObject::from(args->elements()[0]);
	if (self_.is_err()) return self_;
	auto *self = self_.unwrap();
	for (size_t i = 1; i < args->size(); ++i) { new_args_vector.push_back(args->elements()[i]); }
	auto args_ = PyTuple::create(new_args_vector);
	if (args_.is_err()) return args_;
	args = args_.unwrap();

	ASSERT(m_method);
	return m_method->get().method(self, args, kwargs);
}

PyResult<PyObject *>
	PyMethodDescriptor::call_fast_ptrs(PyObject **args, size_t argc, PyDict *kwargs)
{
	if (__builtin_expect(argc == 0, 0)) {
		return Err(type_error("descriptor '{}' requires self", m_name->value()));
	}

	auto *self = RtValue::from_ptr(args[0]).box();
	ASSERT(m_method);

	if (argc == 1) {
		// [性能优化] 使用缓存的空 tuple，避免每次分配
		static PyTuple *s_empty_tuple = nullptr;
		if (__builtin_expect(s_empty_tuple == nullptr, 0)) {
			s_empty_tuple = PyTuple::create().unwrap();
		}
		return m_method->get().method(self, s_empty_tuple, kwargs);
	}

	// [性能优化] 小参数数量 (<=8) 使用栈上数组避免堆分配
	if (argc - 1 <= 8) {
		RtValue stack_args[8];
		for (size_t i = 1; i < argc; ++i) { stack_args[i - 1] = RtValue::from_ptr(args[i]); }
		py::GCVector<Value> tuple_args(stack_args, stack_args + (argc - 1));
		return PyTuple::create(std::move(tuple_args))
			.and_then([this, self, kwargs](PyTuple *t) -> PyResult<PyObject *> {
				return m_method->get().method(self, t, kwargs);
			});
	}

	py::GCVector<Value> tuple_args;
	tuple_args.reserve(argc - 1);
	for (size_t i = 1; i < argc; ++i) { tuple_args.push_back(RtValue::from_ptr(args[i])); }

	return PyTuple::create(std::move(tuple_args))
		.and_then([this, self, kwargs](PyTuple *t) -> PyResult<PyObject *> {
			return m_method->get().method(self, t, kwargs);
		});
}

PyResult<PyObject *> PyMethodDescriptor::__get__(PyObject *instance, PyObject * /*owner*/) const
{
	if (!instance) { return Ok(const_cast<PyMethodDescriptor *>(this)); }
	if ((instance->type() != m_underlying_type)
		&& !instance->type()->issubclass(m_underlying_type)) {
		return Err(
			type_error("descriptor '{}' for '{}' objects "
					   "doesn't apply to a '{}' object",
				m_name->value(),
				m_underlying_type->underlying_type().__name__,
				instance->type()->underlying_type().__name__));
	}
	return PyNativeFunction::create(
		m_name->value(),
		[this, instance](PyTuple *args, PyDict *kwargs) -> PyResult<PyObject *> {
			std::vector<Value> new_args_vector;
			new_args_vector.reserve((args ? args->size() : 0) + 1);
			new_args_vector.push_back(instance);
			if (args) {
				new_args_vector.insert(
					new_args_vector.end(), args->elements().begin(), args->elements().end());
			}
			auto args_ = PyTuple::create(new_args_vector);
			if (args_.is_err()) return args_;
			args = args_.unwrap();
			return const_cast<PyMethodDescriptor *>(this)->__call__(args, kwargs);
		},
		const_cast<PyMethodDescriptor *>(this),
		instance);
}


/*
PyType *PyMethodDescriptor::static_type() const { return types::method_wrapper(); }
*/

namespace {

	std::once_flag method_wrapper_flag;

	std::unique_ptr<TypePrototype> register_method_wrapper()
	{
		return std::move(klass<PyMethodDescriptor>("method_descriptor").type);
	}
}// namespace

std::function<std::unique_ptr<TypePrototype>()> PyMethodDescriptor::type_factory()
{
	return [] {
		static std::unique_ptr<TypePrototype> type = nullptr;
		std::call_once(method_wrapper_flag, []() { type = register_method_wrapper(); });
		return std::move(type);
	};
}

}// namespace py
