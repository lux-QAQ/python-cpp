#include "PyInteger.hpp"
#include "MemoryError.hpp"
#include "PyBytes.hpp"
#include "PyFloat.hpp"
#include "TypeError.hpp"
#include "ValueError.hpp"
#include "runtime/PyByteArray.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/compat.hpp"
#include "types/api.hpp"
#include "types/builtin.hpp"


#include <gmpxx.h>

#include <ranges>

namespace py {

template<> PyInteger *as(PyObject *obj)
{
	if (obj->type() == types::integer()) { return static_cast<PyInteger *>(obj); }
	return nullptr;
}

template<> const PyInteger *as(const PyObject *obj)
{
	if (obj->type() == types::integer()) { return static_cast<const PyInteger *>(obj); }
	return nullptr;
}

PyInteger::PyInteger(PyType *type) : PyNumber(type) {}

PyInteger::PyInteger(BigIntType value) : PyNumber(types::integer()), m_value(std::move(value)) {}


// PyInteger::PyInteger(TypePrototype &type, BigIntType value)
// 	: Interface(type), m_value(std::move(value))
// {}

PyInteger::PyInteger(PyType *type, BigIntType value) : PyNumber(type), m_value(std::move(value)) {}

PyResult<PyInteger *> PyInteger::create(int64_t value)
{
	return PyInteger::create(BigIntType{ value });
}

PyResult<PyInteger *> PyInteger::create(BigIntType value)
{
	auto *result = PYLANG_ALLOC(PyInteger, value);
	PYLANG_CHECK_ALLOC(result, PyInteger);
	return Ok(result);
}

PyResult<PyInteger *> PyInteger::create(PyType *type, BigIntType value)
{
	if (type == types::integer()) { return create(std::move(value)); }
	ASSERT(type->issubclass(types::integer()));
	auto result = type->underlying_type().__alloc__(type);
	return result.and_then([value = std::move(value)](PyObject *obj) -> PyResult<PyInteger *> {
		static_cast<PyInteger &>(*obj).m_value = std::move(value);
		return Ok(static_cast<PyInteger *>(obj));
	});
}

PyResult<PyObject *> PyInteger::__new__(const PyType *type, PyTuple *args, PyDict *kwargs)
{
	ASSERT(!kwargs || kwargs->map().empty());
	PyObject *value = nullptr;
	PyObject *base = nullptr;
	if (!args) { return PyInteger::create(0); }
	if (args->elements().size() > 0) {
		if (auto obj = PyObject::from(args->elements()[0]); obj.is_ok()) {
			value = obj.unwrap();
		} else {
			return obj;
		}
	}

	if (args->elements().size() > 1) { base = PyObject::from(args->elements()[1]).unwrap(); }

	if (!value) {
		return PyInteger::create(const_cast<PyType *>(type), 0);
	} else if (value->type()->issubclass(types::integer())) {
		if (base) { return Err(type_error("int() can't convert non-string with explicit base")); }
		return PyInteger::create(
			const_cast<PyType *>(type), static_cast<const PyInteger &>(*value).as_big_int());
	} else if (value->type()->issubclass(types::float_())) {
		if (base) { return Err(type_error("int() can't convert non-string with explicit base")); }
		return PyInteger::create(const_cast<PyType *>(type),
			BigIntType{ static_cast<const PyFloat &>(*value).as_f64() });
	} else if (value->type()->issubclass(types::bytes())
			   || value->type()->issubclass(types::bytearray())
			   || value->type()->issubclass(types::str())) {
		std::string str;
		if (value->type()->issubclass(types::str())) {
			auto str_value = static_cast<PyString *>(value);
			str = str_value->value();
		} else {
			std::vector<std::byte> bytes;
			if (value->type()->issubclass(types::bytes())) {
				bytes = static_cast<const PyBytes &>(*value).value();
			} else {
				bytes = static_cast<const PyByteArray &>(*value).value();
			}
			str = PyBytes::create(bytes).unwrap()->to_string();
			// remove b' and trailing ' from byte string representation
			str.erase(0, 2);
			str.erase(str.size() - 1);
		}
		std::erase_if(str, [](const auto &c) { return std::isspace(c); });
		if (base) {
			if (!base->type()->issubclass(types::integer())) {
				return Err(type_error(
					"'{}' object cannot be interpreted as an integer", base->type()->name()));
			}
			auto b = static_cast<const PyInteger &>(*base).as_i64();
			BigIntType result;
			if (mpz_init_set_str(result.get_mpz_t(), str.c_str(), static_cast<int32_t>(b)) != 0) {
				return Err(type_error("invalid literal for int(): '{}'", str));
			}
			return PyInteger::create(const_cast<PyType *>(type), std::move(result));
		} else {
			size_t pos{ 0 };
			double result = std::stod(str, &pos);
			if (pos != str.size()) {
				return Err(type_error("invalid literal for int(): '{}'", str));
			}
			return PyInteger::create(const_cast<PyType *>(type), static_cast<int64_t>(result));
		}
	}
	TODO();
	return Err(nullptr);
}


namespace {
	constexpr int kPyHashBits = (sizeof(void *) >= 8) ? 61 : 31;
	constexpr uint64_t kPyHashModulus = (uint64_t{ 1 } << kPyHashBits) - 1;
	constexpr int64_t kPyHashModulusSigned = static_cast<int64_t>(kPyHashModulus);

	inline int64_t normalize_python_hash(int64_t h) noexcept { return (h == -1) ? -2 : h; }
}// namespace

int64_t PyInteger::hash_big_int(const BigIntType &val)
{
	const int sign = mpz_sgn(val.get_mpz_t());
	if (sign == 0) { return 0; }

	uint64_t abs_rem = 0;

	if constexpr (std::numeric_limits<unsigned long>::digits >= kPyHashBits) {
		// 64-bit LP64：P=2^61-1 可直接放进 unsigned long
		// 32-bit：P=2^31-1 也可直接放进 unsigned long
		abs_rem = static_cast<uint64_t>(
			mpz_tdiv_ui(val.get_mpz_t(), static_cast<unsigned long>(kPyHashModulus)));
	} else {
		// LLP64（如 Windows x64）：unsigned long 只有 32 位，61-bit 模数放不下
		// 这里走 mpz_tdiv_r + 读取低 limb 的路径，避免 mpz_export
		static const mpz_class mpz_p = []() {
			mpz_class p;
			mpz_ui_pow_ui(p.get_mpz_t(), 2, kPyHashBits);
			p -= 1;
			return p;
		}();

		static thread_local mpz_class remainder;
		mpz_tdiv_r(remainder.get_mpz_t(), val.get_mpz_t(), mpz_p.get_mpz_t());

		// 余数绝对值必然小于 P，因此这里取低 limb 就够了
		abs_rem = static_cast<uint64_t>(mpz_getlimbn(remainder.get_mpz_t(), 0));
	}

	int64_t h = static_cast<int64_t>(abs_rem);
	if (sign < 0) { h = -h; }

	return normalize_python_hash(h);
}


PyResult<int64_t> PyInteger::__hash__() const
{
	const BigIntType &val = as_big_int();

	if (mpz_sgn(val.get_mpz_t()) == 0) [[unlikely]] { return Ok(0); }

	// 小整数快路径：|i| < P 时，hash(i) == i
	if (val.fits_slong_p()) [[likely]] {
		const int64_t i = static_cast<int64_t>(val.get_si());
		if (i > -kPyHashModulusSigned && i < kPyHashModulusSigned) [[likely]] {
			return Ok(normalize_python_hash(i));
		}
	}

	return Ok(hash_big_int(val));
}

// PyResult<PyObject *> PyInteger::__and__(PyObject *obj)
// {
// 	if (!obj->type()->issubclass(types::integer())) {
// 		return Err(
// 			type_error("unsupported operand type(s) for &: 'int' and '{}'", obj->type()->name()));
// 	}

// 	return PyInteger::create((as_i64() & static_cast<const PyInteger &>(*obj).as_i64()));
// }

PyResult<PyObject *> PyInteger::__and__(PyObject *obj)
{
	if (!obj->type()->issubclass(types::integer())) {
		return Err(
			type_error("unsupported operand type(s) for &: 'int' and '{}'", obj->type()->name()));
	}

	mpz_class result = as_big_int();
	result &= static_cast<const PyInteger &>(*obj).as_big_int();
	return PyInteger::create(std::move(result));
}
// PyResult<PyObject *> PyInteger::__or__(PyObject *obj)
// {
// 	if (!obj->type()->issubclass(types::integer())) {
// 		return Err(
// 			type_error("unsupported operand type(s) for |: 'int' and '{}'", obj->type()->name()));
// 	}

// 	return PyInteger::create((as_i64() | static_cast<const PyInteger &>(*obj).as_i64()));
// }

PyResult<PyObject *> PyInteger::__or__(PyObject *obj)
{
	if (!obj->type()->issubclass(types::integer())) {
		return Err(
			type_error("unsupported operand type(s) for |: 'int' and '{}'", obj->type()->name()));
	}

	mpz_class result = as_big_int();
	result |= static_cast<const PyInteger &>(*obj).as_big_int();
	return PyInteger::create(std::move(result));
}

PyResult<PyObject *> PyInteger::__xor__(PyObject *obj)
{
	if (!obj->type()->issubclass(types::integer())) {
		return Err(
			type_error("unsupported operand type(s) for ^: 'int' and '{}'", obj->type()->name()));
	}

	mpz_class result = as_big_int();
	result ^= static_cast<const PyInteger &>(*obj).as_big_int();

	return PyInteger::create(std::move(result));
}

PyResult<PyObject *> PyInteger::__lshift__(const PyObject *obj) const
{
	if (!obj->type()->issubclass(types::integer())) {
		return Err(
			type_error("unsupported operand type(s) for <<: 'int' and '{}'", obj->type()->name()));
	}

	return PyInteger::create(m_value << static_cast<const PyInteger &>(*obj).as_big_int().get_ui());
}

PyResult<PyObject *> PyInteger::__rshift__(const PyObject *obj) const
{
	if (obj->type() != types::integer()) {
		return Err(
			type_error("unsupported operand type(s) for >>: 'int' and '{}'", obj->type()->name()));
	}

	return PyInteger::create(m_value >> static_cast<const PyInteger &>(*obj).as_big_int().get_ui());
}

PyResult<PyObject *> PyInteger::bit_length() const
{
	return PyInteger::create(mpz_sizeinbase(as_big_int().get_mpz_t(), 2));
}

PyResult<PyObject *> PyInteger::bit_count() const
{
	auto value_ = as_big_int();
	auto *value = value_.get_mpz_t();
	mpz_abs(value, value);
	return PyInteger::create(mpz_popcount(value));
}

PyResult<PyObject *> PyInteger::to_bytes(PyTuple *args, PyDict *kwargs) const
{
	// FIXME: fix signature to to_bytes(length, byteorder, *, signed=False)
	ASSERT(!kwargs || kwargs->map().empty());

	if (args->size() != 2) { return Err(type_error("to_bytes expected two arguments")); }

	auto length_ = PyObject::from(args->elements()[0]);
	if (length_.is_err()) return length_;
	auto byteorder_ = PyObject::from(args->elements()[1]);
	if (byteorder_.is_err()) return byteorder_;

	if (!as<PyInteger>(length_.unwrap())) {
		return Err(type_error(
			"'{}' object cannot be interpreted as an integer", length_.unwrap()->type()->name()));
	}
	if (!as<PyString>(byteorder_.unwrap())) {
		return Err(type_error("to_bytes() argument 'byteorder' must be str, not {}",
			byteorder_.unwrap()->type()->name()));
	}

	if (as<PyInteger>(length_.unwrap())->as_i64() < 0) {
		return Err(type_error("length argument must be non-negative"));
	}
	const auto length = as<PyInteger>(length_.unwrap())->as_size_t();
	const auto byteorder = as<PyString>(byteorder_.unwrap())->value();
	if (byteorder != "little" && byteorder != "big") {
		return Err(value_error("byteorder must be either 'little' or 'big'"));
	}

	std::unique_ptr<std::byte[]> bytes = std::make_unique<std::byte[]>(length);
	const int32_t order = byteorder == "big" ? 1 : -1;
	auto l = length;
	void *result = mpz_export(bytes.get(), &l, order, 1, order, 0, m_value.get_mpz_t());
	ASSERT(result);
	if (l > length) {
		// FIXME: should be an OverflowError
		return Err(value_error("int too big to convert"));
	}

	std::vector<std::byte> bytes_result;
	if (byteorder == "little") {
		bytes_result = std::vector<std::byte>{ bytes.get(), bytes.get() + length };
	} else {
		bytes_result.reserve(length);
		bytes_result.resize(length - l);
		bytes_result.insert(bytes_result.end(), bytes.get(), bytes.get() + l);
	}

	return PyBytes::create(std::move(bytes_result));
}

PyResult<PyObject *> PyInteger::from_bytes(PyType *type, PyTuple *args, PyDict *kwargs)
{
	// FIXME: fix signature to from_bytes(bytes, byteorder, *, signed=False)
	ASSERT(!kwargs || kwargs->map().empty());

	if (args->size() != 2) { return Err(type_error("from_bytes expected two arguments")); }

	ASSERT(type == types::integer());

	auto bytes_ = PyObject::from(args->elements()[0]);
	if (bytes_.is_err()) return bytes_;
	auto byteorder_ = PyObject::from(args->elements()[1]);
	if (byteorder_.is_err()) return byteorder_;

	if (!as<PyBytes>(bytes_.unwrap())) {
		return Err(type_error(
			"'{}' object cannot be interpreted as a bytes array", bytes_.unwrap()->type()->name()));
	}
	if (!as<PyString>(byteorder_.unwrap())) {
		return Err(type_error("to_bytes() argument 'byteorder' must be str, not {}",
			byteorder_.unwrap()->type()->name()));
	}

	const auto bytes = as<PyBytes>(bytes_.unwrap());
	const auto byteorder = as<PyString>(byteorder_.unwrap())->value();
	if (byteorder != "little" && byteorder != "big") {
		return Err(value_error("byteorder must be either 'little' or 'big'"));
	}

	if (bytes->value().size() > 8) { TODO(); }

	uint64_t value{ 0 };
	if (byteorder != "big") {
		for (size_t i = 0; i < bytes->value().size(); ++i) {
			value |= static_cast<uint64_t>(bytes->value()[i]) << i * 8;
		}
	} else {
		const auto &bytes_ = bytes->value();
		for (size_t i = 0; auto el : bytes_ | std::ranges::views::reverse) {
			value |= static_cast<uint64_t>(el) << i * 8;
			++i;
		}
	}

	ASSERT(value < static_cast<uint64_t>(std::numeric_limits<int64_t>::max()));

	auto result = PyInteger::create(static_cast<int64_t>(value));
	if (result.is_err()) return result;
	if (type != types::integer()) {
		return type->__call__(PyTuple::create(result.unwrap()).unwrap(), PyDict::create().unwrap());
	}
	return result;
}

PyResult<PyObject *> PyInteger::__round__(PyObject *ndigits_obj) const
{
	if (!ndigits_obj || ndigits_obj == py_none()) { return PyInteger::create(as_big_int()); }

	if (!ndigits_obj->type()->issubclass(types::integer())) {
		return Err(type_error(
			"'{}' object cannot be interpreted as an integer", ndigits_obj->type()->name()));
	}

	auto ndigits = static_cast<const PyInteger &>(*ndigits_obj).as_big_int();

	if (ndigits >= 0) { return PyInteger::create(as_big_int()); }

	mpz_class power_of_10;
	mpz_class neg_ndigits = -ndigits;
	mpz_pow_ui(power_of_10.get_mpz_t(), BigIntType(10).get_mpz_t(), neg_ndigits.get_ui());

	mpz_class val_copy = m_value;
	mpz_class rem;
	mpz_mod(rem.get_mpz_t(), val_copy.get_mpz_t(), power_of_10.get_mpz_t());
	auto result = val_copy - rem;

	return PyInteger::create(std::move(result));
}

int64_t PyInteger::as_i64() const
{
	ASSERT(m_value.fits_slong_p());
	return m_value.get_si();
}

size_t PyInteger::as_size_t() const
{
	ASSERT(m_value.fits_ulong_p());
	return m_value.get_ui();
}

BigIntType PyInteger::as_big_int() const { return m_value; }

/*
PyType *PyInteger::static_type() const { return types::integer(); }
*/

namespace {

	std::once_flag int_flag;

	std::unique_ptr<TypePrototype> register_int()
	{
		return std::move(klass<PyInteger>("int")
				.def("bit_length", &PyInteger::bit_length)
				.def("bit_count", &PyInteger::bit_count)
				.def("to_bytes", &PyInteger::to_bytes)
				.def("__round__", &PyInteger::__round__)
				.classmethod("from_bytes", &PyInteger::from_bytes)
				.type);
	}
}// namespace

std::function<std::unique_ptr<TypePrototype>()> PyInteger::type_factory()
{
	return [] {
		static std::unique_ptr<TypePrototype> type = nullptr;
		std::call_once(int_flag, []() { type = register_int(); });
		return std::move(type);
	};
}
}// namespace py
