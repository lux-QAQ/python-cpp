#include "interpreter/Interpreter.hpp"
#include "runtime/PyBool.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/Value.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"

namespace py {

PyResult<RtValue> add(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->add(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> subtract(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->subtract(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> multiply(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->multiply(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> exp(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->pow(rhs.box(), py_none()).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> lshift(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->lshift(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> rshift(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->rshift(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> modulo(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->modulo(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> true_divide(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->truediv(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> floordiv(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->floordiv(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> equals(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_EQ).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> equals(RtValue lhs, RtValue rhs)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_EQ).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> not_equals(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_NE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> less_than_equals(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_LE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> less_than(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_LT).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> greater_than(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_GT).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> greater_than_equals(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_GE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> and_(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->and_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> or_(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->or_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> xor_(RtValue lhs, RtValue rhs, Interpreter &)
{
	return lhs.box()->xor_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<bool> is(RtValue lhs, RtValue rhs, Interpreter &) { return Ok(lhs.box() == rhs.box()); }

PyResult<bool> in(RtValue lhs, RtValue rhs, Interpreter &)
{
	return rhs.box()->contains(lhs.box());
}

PyResult<bool> truthy(RtValue value) { return Ok(value.is_truthy()); }

PyResult<bool> truthy(RtValue value, Interpreter &) { return truthy(value); }

}// namespace py