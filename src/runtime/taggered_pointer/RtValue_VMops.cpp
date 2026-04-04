#include "interpreter/Interpreter.hpp"
#include "runtime/PyBool.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/Value.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"

namespace py {

PyResult<RtValue> add(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->add(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> subtract(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->subtract(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> multiply(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->multiply(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> exp(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->pow(rhs.box(), py_none()).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> lshift(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->lshift(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> rshift(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->rshift(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> modulo(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->modulo(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> true_divide(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->truediv(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> floordiv(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->floordiv(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> equals(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_EQ).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> equals(const RtValue &lhs, const RtValue &rhs)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_EQ).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> not_equals(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_NE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> less_than_equals(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_LE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> less_than(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_LT).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> greater_than(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_GT).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> greater_than_equals(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->richcompare(rhs.box(), RichCompare::Py_GE).and_then([](PyObject *obj) {
		return Ok(RtValue::from_ptr(obj));
	});
}

PyResult<RtValue> and_(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->and_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> or_(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->or_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<RtValue> xor_(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return lhs.box()->xor_(rhs.box()).and_then(
		[](PyObject *obj) { return Ok(RtValue::from_ptr(obj)); });
}

PyResult<bool> is(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return Ok(lhs.box() == rhs.box());
}

PyResult<bool> in(const RtValue &lhs, const RtValue &rhs, Interpreter &)
{
	return rhs.box()->contains(lhs.box());
}

PyResult<bool> truthy(const RtValue &value) { return Ok(value.is_truthy()); }

PyResult<bool> truthy(const RtValue &value, Interpreter &) { return truthy(value); }

}// namespace py