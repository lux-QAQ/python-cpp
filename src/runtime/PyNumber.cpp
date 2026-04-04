#include "PyNumber.hpp"
#include "NotImplemented.hpp"
#include "PyBool.hpp"
#include "PyFloat.hpp"
#include "PyInteger.hpp"
#include "PyNone.hpp"
#include "PyObject.hpp"
#include "PyString.hpp"
#include "PyType.hpp"
#include "TypeError.hpp"
#include "runtime/PyTuple.hpp"
#include "runtime/ValueError.hpp"
#include "types/builtin.hpp"

#include <cmath>
#include <variant>

namespace py {

PyNumber::PyNumber(PyType *type) : PyBaseObject(type) {}

std::string PyNumber::to_string() const
{
	if (auto int_val = as<PyInteger>(this)) {
		return int_val->as_big_int().get_str();
	} else if (auto float_val = as<PyFloat>(this)) {
		return std::to_string(float_val->as_f64());
	}
	TODO();
}

PyResult<PyObject *> PyNumber::__repr__() const { return PyString::create(to_string()); }

const PyNumber *PyNumber::as_number(const PyObject *obj)
{
	if (obj->type()->issubclass(types::float_())) {
		return static_cast<const PyFloat *>(obj);
	} else if (obj->type()->issubclass(types::integer())) {
		return static_cast<const PyInteger *>(obj);
	}
	return nullptr;
}

PyResult<PyObject *> PyNumber::__abs__() const
{
	if (auto int_val = as<PyInteger>(this)) {
		mpz_class result{};
		mpz_abs(result.get_mpz_t(), int_val->as_big_int().get_mpz_t());
		return PyInteger::create(std::move(result));
	} else if (auto float_val = as<PyFloat>(this)) {
		return PyFloat::create(std::abs(float_val->as_f64()));
	}
	TODO();
}

PyResult<PyObject *> PyNumber::__neg__() const
{
	if (auto int_val = as<PyInteger>(this)) {
		return PyInteger::create(-int_val->as_big_int());
	} else if (auto float_val = as<PyFloat>(this)) {
		return PyFloat::create(-float_val->as_f64());
	}
	TODO();
}

PyResult<PyObject *> PyNumber::__pos__() const
{
	if (auto int_val = as<PyInteger>(this)) {
		return PyInteger::create(int_val->as_big_int());
	} else if (auto float_val = as<PyFloat>(this)) {
		return PyFloat::create(float_val->as_f64());
	}
	TODO();
}

PyResult<PyObject *> PyNumber::__invert__() const
{
	if (auto int_val = as<PyInteger>(this)) { return PyInteger::create(~int_val->as_big_int()); }
	return Err(type_error("bad operand type for unary ~: 'float'"));
}
PyResult<PyObject *> PyNumber::__add__(const PyObject *obj) const
{
	if (auto *rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyInteger::create(lhs_int->as_big_int() + rhs_int->as_big_int());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_int->as_big_int().get_d() + rhs_float->as_f64());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() + rhs_int->as_big_int().get_d());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() + rhs_float->as_f64());
			}
		}
	}
	return Err(type_error("unsupported operand type(s) for +: \'{}\' and \'{}\'",
		type()->name(),
		obj->type()->name()));
}

PyResult<PyObject *> PyNumber::__sub__(const PyObject *obj) const
{
	if (auto rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyInteger::create(lhs_int->as_big_int() - rhs_int->as_big_int());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_int->as_big_int().get_d() - rhs_float->as_f64());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() - rhs_int->as_big_int().get_d());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() - rhs_float->as_f64());
			}
		}
	}
	return Err(type_error("unsupported operand type(s) for -: \'{}\' and \'{}\'",
		type()->name(),
		obj->type()->name()));
}

PyResult<PyObject *> PyNumber::__mod__(const PyObject *obj) const
{
	if (auto rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyInteger::create(lhs_int->as_big_int() % rhs_int->as_big_int());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(
					std::remainder(lhs_int->as_big_int().get_d(), rhs_float->as_f64()));
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyFloat::create(
					std::remainder(lhs_float->as_f64(), rhs_int->as_big_int().get_d()));
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(std::remainder(lhs_float->as_f64(), rhs_float->as_f64()));
			}
		}
	}
	return Err(type_error("unsupported operand type(s) for %: \'{}\' and \'{}\'",
		type()->name(),
		obj->type()->name()));
}

PyResult<PyObject *> PyNumber::__divmod__(PyObject *obj)
{
	if (auto rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				if (rhs_int->as_big_int() == 0) { return Err(value_error("ZeroDivisionError")); }
				mpz_class q, r;
				mpz_fdiv_qr(q.get_mpz_t(),
					r.get_mpz_t(),
					lhs_int->as_big_int().get_mpz_t(),
					rhs_int->as_big_int().get_mpz_t());
				auto q_obj = PyInteger::create(q);
				if (q_obj.is_err()) return q_obj;
				auto r_obj = PyInteger::create(r);
				if (r_obj.is_err()) return r_obj;
				return PyTuple::create(q_obj.unwrap(), r_obj.unwrap());
			}
		}
		TODO();
	} else {
		return Err(type_error("unsupported operand type(s) for %: \'{}\' and \'{}\'",
			type()->name(),
			obj->type()->name()));
	}
}

PyResult<PyObject *> PyNumber::__mul__(const PyObject *obj) const
{
	if (auto rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyInteger::create(lhs_int->as_big_int() * rhs_int->as_big_int());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_int->as_big_int().get_d() * rhs_float->as_f64());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() * rhs_int->as_big_int().get_d());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(lhs_float->as_f64() * rhs_float->as_f64());
			}
		}
	}
	return Ok(not_implemented());
}

PyResult<PyObject *> PyNumber::__pow__(const PyObject *obj, const PyObject *modulo_obj) const
{
	if (auto rhs_ = as_number(obj)) {
		if (modulo_obj == py_none()) {
			if (auto lhs_int = as<PyInteger>(this)) {
				if (auto rhs_int = as<PyInteger>(rhs_)) {
					mpz_class result;
					mpz_pow_ui(result.get_mpz_t(),
						lhs_int->as_big_int().get_mpz_t(),
						rhs_int->as_big_int().get_ui());
					return PyInteger::create(result);
				}
			}
			TODO();
		}
		auto modulo_ = as_number(modulo_obj);
		if (!modulo_) { return Ok(not_implemented()); }
		mpz_class result{};
		mpz_class lhs = as<PyInteger>(this)->as_big_int();
		mpz_class rhs = as<PyInteger>(rhs_)->as_big_int();
		mpz_class modulo = as<PyInteger>(modulo_)->as_big_int();
		mpz_powm(result.get_mpz_t(), lhs.get_mpz_t(), rhs.get_mpz_t(), modulo.get_mpz_t());

		return PyInteger::create(result);
	} else {
		return Err(type_error("unsupported operand type(s) for **: \'{}\' and \'{}\'",
			type()->name(),
			obj->type()->name()));
	}
}

PyResult<PyObject *> PyNumber::__truediv__(const PyObject *obj) const
{
	if (auto rhs = as_number(obj)) {
		double lhs_val = 0.0;
		double rhs_val = 0.0;
		if (auto lhs_int = as<PyInteger>(this)) {
			lhs_val = lhs_int->as_big_int().get_d();
		} else if (auto lhs_float = as<PyFloat>(this)) {
			lhs_val = lhs_float->as_f64();
		}
		if (auto rhs_int = as<PyInteger>(rhs)) {
			rhs_val = rhs_int->as_big_int().get_d();
		} else if (auto rhs_float = as<PyFloat>(rhs)) {
			rhs_val = rhs_float->as_f64();
		}
		return PyFloat::create(lhs_val / rhs_val);
	}
	return Err(type_error("unsupported operand type(s) for /: \'{}\' and \'{}\'",
		type()->name(),
		obj->type()->name()));
}

PyResult<PyObject *> PyNumber::__floordiv__(const PyObject *obj) const
{
	if (auto rhs = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyInteger::create(lhs_int->as_big_int() / rhs_int->as_big_int());
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(
					std::floor(lhs_int->as_big_int().get_d() / rhs_float->as_f64()));
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(rhs)) {
				return PyFloat::create(
					std::floor(lhs_float->as_f64() / rhs_int->as_big_int().get_d()));
			} else if (auto rhs_float = as<PyFloat>(rhs)) {
				return PyFloat::create(std::floor(lhs_float->as_f64() / rhs_float->as_f64()));
			}
		}
	}
	return Err(type_error("unsupported operand type(s) for //: \'{}\' and \'{}\'",
		type()->name(),
		obj->type()->name()));
}

PyResult<PyObject *> PyNumber::__eq__(const PyObject *obj) const
{
	if (auto *pynum = as_number(obj)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_int->as_big_int() == rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_int->as_big_int() == rhs_float->as_f64() ? py_true() : py_false());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_float->as_f64() == rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_float->as_f64() == rhs_float->as_f64() ? py_true() : py_false());
			}
		}
	}
	return Err(type_error("'==' not supported between instances of '{}' and '{}'",
		type()->name(),
		obj->type()->name()));
}


PyResult<PyObject *> PyNumber::__ne__(const PyObject *obj) const
{
	if (auto *pynum = as_number(obj)) {
		auto result = __eq__(obj);
		if (result.is_err()) { return result; }
		return Ok(result.unwrap() == py_true() ? py_false() : py_true());
	}
	return Err(type_error("'!=' not supported between instances of '{}' and '{}'",
		type()->name(),
		obj->type()->name()));
}


PyResult<PyObject *> PyNumber::__lt__(const PyObject *other) const
{
	if (auto *pynum = as_number(other)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_int->as_big_int() < rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_int->as_big_int() < rhs_float->as_f64() ? py_true() : py_false());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_float->as_f64() < rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_float->as_f64() < rhs_float->as_f64() ? py_true() : py_false());
			}
		}
	}
	return Err(type_error("'<' not supported between instances of '{}' and '{}'",
		type()->name(),
		other->type()->name()));
}

PyResult<PyObject *> PyNumber::__le__(const PyObject *other) const
{
	if (auto *pynum = as_number(other)) {
		auto result = __gt__(other);
		if (result.is_err()) { return result; }
		return Ok(result.unwrap() == py_true() ? py_false() : py_true());
	}
	return Err(type_error("'<=' not supported between instances of '{}' and '{}'",
		type()->name(),
		other->type()->name()));
}

PyResult<PyObject *> PyNumber::__gt__(const PyObject *other) const
{
	if (auto *pynum = as_number(other)) {
		if (auto lhs_int = as<PyInteger>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_int->as_big_int() > rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_int->as_big_int() > rhs_float->as_f64() ? py_true() : py_false());
			}
		} else if (auto lhs_float = as<PyFloat>(this)) {
			if (auto rhs_int = as<PyInteger>(pynum)) {
				return Ok(lhs_float->as_f64() > rhs_int->as_big_int() ? py_true() : py_false());
			} else if (auto rhs_float = as<PyFloat>(pynum)) {
				return Ok(lhs_float->as_f64() > rhs_float->as_f64() ? py_true() : py_false());
			}
		}
	}
	return Err(type_error("'>' not supported between instances of '{}' and '{}'",
		type()->name(),
		other->type()->name()));
}

PyResult<PyObject *> PyNumber::__ge__(const PyObject *other) const
{
	if (auto *pynum = as_number(other)) {
		auto result = __lt__(other);
		if (result.is_err()) { return result; }
		return Ok(result.unwrap() == py_true() ? py_false() : py_true());
	}
	return Err(type_error("'>=' not supported between instances of '{}' and '{}'",
		type()->name(),
		other->type()->name()));
}

PyResult<bool> PyNumber::__bool__() const
{
	if (auto int_val = as<PyInteger>(this)) {
		return Ok(static_cast<bool>(int_val->as_big_int()));
	} else if (auto float_val = as<PyFloat>(this)) {
		return Ok(std::fpclassify(float_val->as_f64()) != FP_ZERO);
	}
	TODO();
}

}// namespace py
