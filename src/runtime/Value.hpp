#pragma once

#include "../forward.hpp"
#include "../utilities.hpp"
#include "forward.hpp"
#include "memory/GCTracingAllocator.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"

#include <gmpxx.h>
#include <spdlog/fmt/fmt.h>

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <sstream>
#include <variant>
#include <vector>

template<> struct fmt::formatter<mpz_class> : fmt::formatter<std::string>
{
	template<typename FormatContext> auto format(const mpz_class &number, FormatContext &ctx)
	{
		std::ostringstream os;
		os << number;
		return fmt::formatter<std::string>::format(os.str(), ctx);
	}
};


namespace py {

using BigIntType = mpz_class;


class BaseException;

template<typename T> struct Ok
{
	T value;
	constexpr Ok(T value_) : value(std::move(value_)) {}
};

template<typename T> Ok(T) -> Ok<T>;

struct Err
{
	BaseException *exc;
	constexpr Err(BaseException *value_) : exc(value_) {}
};

template<typename T> class PyResult;

namespace detail {
	template<typename> struct is_ok : std::false_type
	{
	};

	template<typename T> struct is_ok<Ok<T>> : std::true_type
	{
		using type = T;
	};

	template<typename> struct is_pyresult : std::false_type
	{
	};

	template<typename T> struct is_pyresult<PyResult<T>> : std::true_type
	{
		using type = T;
	};
}// namespace detail


template<typename T> class PyResult
{
  public:
	using OkType = T;
	using ErrType = BaseException *;
	using StorageType = std::variant<Ok<T>, Err>;

  private:
	StorageType result;

  public:
	PyResult(Ok<T> result_) : result(std::move(result_)) {}
	template<typename U> constexpr PyResult(Ok<U> result_) : result(Ok<T>(std::move(result_.value)))
	{
		static_assert(std::is_convertible_v<U, T>);
	}
	constexpr PyResult(Err result_) : result(result_) {}

	template<typename U> constexpr PyResult(const PyResult<U> &other) : result(Err(nullptr))
	{
		static_assert(std::is_convertible_v<U, T>);
		if (other.is_ok()) {
			result = Ok<T>(other.unwrap());
		} else {
			result = Err(other.unwrap_err());
		}
	}

	bool is_ok() const { return std::holds_alternative<Ok<T>>(result); }
	bool is_err() const { return !is_ok(); }

	const T &unwrap() const &
	{
		if (!is_ok()) { fmt::print("ERROR: Result is Err!\n"); }
		ASSERT(is_ok());
		return std::get<Ok<T>>(result).value;
	}

	T &unwrap() &
	{
		if (!is_ok()) { fmt::print("ERROR: Result is Err!\n"); }
		ASSERT(is_ok());
		return std::get<Ok<T>>(result).value;
	}
	T &&unwrap() &&
	{
		if (!is_ok()) { fmt::print("ERROR: Result is Err!\n"); }
		ASSERT(is_ok());
		return std::move(std::get<Ok<T>>(result).value);
	}

	BaseException *unwrap_err() const
	{
		ASSERT(is_err());
		return std::get<Err>(result).exc;
	}

	template<typename FunctorType,
		typename PyResultType =
			std::conditional_t<detail::is_ok<typename std::invoke_result_t<FunctorType, T>>{},
				typename detail::is_ok<typename std::invoke_result_t<FunctorType, T>>::type,
				typename detail::is_pyresult<typename std::invoke_result_t<FunctorType, T>>::type>>
	PyResult<PyResultType> and_then(FunctorType &&op) const;

	template<typename FunctorType> PyResult<T> or_else(FunctorType &&op) const;
};

template<typename T>
template<typename FunctorType, typename PyResultType>
PyResult<PyResultType> PyResult<T>::and_then(FunctorType &&op) const
{
	using ResultType = typename std::invoke_result_t<FunctorType, T>;
	static_assert(detail::is_ok<ResultType>{} || detail::is_pyresult<ResultType>{},
		"Return type of function must be of type Ok<U> or PyResult<U>");
	if (is_ok()) {
		return op(unwrap());
	} else {
		return PyResult<PyResultType>(Err(unwrap_err()));
	}
}

template<typename T>
template<typename FunctorType>
PyResult<T> PyResult<T>::or_else(FunctorType &&op) const
{
	using ResultType = typename std::invoke_result_t<FunctorType, ErrType>;
	static_assert(detail::is_ok<ResultType>{} || detail::is_pyresult<ResultType>{},
		"Return type of function must be of type Ok<U> or PyResult<U>");
	if (is_err()) {
		return op(unwrap_err());
	} else {
		return PyResult<T>(Ok(unwrap()));
	}
}

PyResult<Value> add(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> subtract(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> multiply(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> exp(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> modulo(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> true_divide(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> floordiv(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> lshift(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> rshift(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> equals(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> equals(Value lhs, Value rhs);
PyResult<Value> not_equals(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> less_than_equals(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> less_than(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> greater_than(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> greater_than_equals(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> and_(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> or_(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<Value> xor_(Value lhs, Value rhs, Interpreter &interpreter);

PyResult<bool> is(Value lhs, Value rhs, Interpreter &interpreter);
PyResult<bool> in(Value lhs, Value rhs, Interpreter &interpreter);

PyResult<bool> truthy(Value lhs, Interpreter &);
PyResult<bool> truthy(Value lhs);


}// namespace py
