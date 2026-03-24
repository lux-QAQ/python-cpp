#include "runtime/PyBool.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyFloat.hpp"
#include "runtime/PyInteger.hpp"
#include "runtime/PyList.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyString.hpp"
#include "runtime/PyTuple.hpp"
#include "runtime/RuntimeContext.hpp"
#include "runtime/Value.hpp"

#include <gtest/gtest.h>

using namespace py;

// =============================================================================
// RuntimeContext::is_true() 降级路径 — 无 provider 时走 PyObject::true_()
// 验证重构后 is_true 对所有 falsy/truthy 类型的一致性
// =============================================================================

class TruthyFallbackTest : public ::testing::Test
{
  protected:
	RuntimeContext ctx;
	RuntimeContext *saved{ nullptr };

	void SetUp() override
	{
		saved = RuntimeContext::has_current() ? &RuntimeContext::current() : nullptr;
		RuntimeContext::set_current(&ctx);
		// 不设置 truthy_provider — 测试降级路径
	}

	void TearDown() override { RuntimeContext::set_current(saved); }
};

// ---- Falsy 值 ----

TEST_F(TruthyFallbackTest, NoneIsFalsy) { EXPECT_FALSE(ctx.is_true(py_none())); }

TEST_F(TruthyFallbackTest, FalseIsFalsy) { EXPECT_FALSE(ctx.is_true(py_false())); }

TEST_F(TruthyFallbackTest, ZeroIntIsFalsy)
{
	auto *zero = PyInteger::create(0).unwrap();
	EXPECT_FALSE(ctx.is_true(zero));
}

TEST_F(TruthyFallbackTest, ZeroFloatIsFalsy)
{
	auto *zero = PyFloat::create(0.0).unwrap();
	EXPECT_FALSE(ctx.is_true(zero));
}

TEST_F(TruthyFallbackTest, EmptyStringIsFalsy)
{
	auto *empty = PyString::create("").unwrap();
	EXPECT_FALSE(ctx.is_true(empty));
}

TEST_F(TruthyFallbackTest, EmptyListIsFalsy)
{
	auto *empty = PyList::create().unwrap();
	EXPECT_FALSE(ctx.is_true(empty));
}

TEST_F(TruthyFallbackTest, EmptyTupleIsFalsy)
{
	auto *empty = PyTuple::create().unwrap();
	EXPECT_FALSE(ctx.is_true(empty));
}

TEST_F(TruthyFallbackTest, EmptyDictIsFalsy)
{
	auto *empty = PyDict::create().unwrap();
	EXPECT_FALSE(ctx.is_true(empty));
}

// ---- Truthy 值 ----

TEST_F(TruthyFallbackTest, TrueIsTruthy) { EXPECT_TRUE(ctx.is_true(py_true())); }

TEST_F(TruthyFallbackTest, NonZeroIntIsTruthy)
{
	EXPECT_TRUE(ctx.is_true(PyInteger::create(1).unwrap()));
	EXPECT_TRUE(ctx.is_true(PyInteger::create(-1).unwrap()));
	EXPECT_TRUE(ctx.is_true(PyInteger::create(42).unwrap()));
}

TEST_F(TruthyFallbackTest, NonZeroFloatIsTruthy)
{
	EXPECT_TRUE(ctx.is_true(PyFloat::create(0.1).unwrap()));
	EXPECT_TRUE(ctx.is_true(PyFloat::create(-3.14).unwrap()));
}

TEST_F(TruthyFallbackTest, NonEmptyStringIsTruthy)
{
	EXPECT_TRUE(ctx.is_true(PyString::create("hello").unwrap()));
	EXPECT_TRUE(ctx.is_true(PyString::create(" ").unwrap()));
}

TEST_F(TruthyFallbackTest, NonEmptyListIsTruthy)
{
	auto *list = PyList::create().unwrap();
	list->append(py_none());
	EXPECT_TRUE(ctx.is_true(list));
}

TEST_F(TruthyFallbackTest, NonEmptyDictIsTruthy)
{
	auto *dict = PyDict::create().unwrap();
	dict->insert(PyString::create("k").unwrap(), py_none());
	EXPECT_TRUE(ctx.is_true(dict));
}

// =============================================================================
// truthy(Value) 独立函数 — 无 Interpreter 参数版本
// =============================================================================

TEST_F(TruthyFallbackTest, TruthyValueFunctionNone)
{
	auto r = truthy(Value{ py_none() });
	ASSERT_TRUE(r.is_ok());
	EXPECT_FALSE(r.unwrap());
}

TEST_F(TruthyFallbackTest, TruthyValueFunctionTrue)
{
	auto r = truthy(Value{ py_true() });
	ASSERT_TRUE(r.is_ok());
	EXPECT_TRUE(r.unwrap());
}

TEST_F(TruthyFallbackTest, TruthyValueFunctionFalse)
{
	auto r = truthy(Value{ py_false() });
	ASSERT_TRUE(r.is_ok());
	EXPECT_FALSE(r.unwrap());
}

TEST_F(TruthyFallbackTest, TruthyValueFunctionZeroInt)
{
	auto r = truthy(Value{ PyInteger::create(0).unwrap() });
	ASSERT_TRUE(r.is_ok());
	EXPECT_FALSE(r.unwrap());
}

TEST_F(TruthyFallbackTest, TruthyValueFunctionNonZeroInt)
{
	auto r = truthy(Value{ PyInteger::create(42).unwrap() });
	ASSERT_TRUE(r.is_ok());
	EXPECT_TRUE(r.unwrap());
}

// =============================================================================
// RuntimeContext::equals() 降级路径
// =============================================================================

TEST_F(TruthyFallbackTest, EqualsIntSameValue)
{
	auto *a = PyInteger::create(42).unwrap();
	auto *b = PyInteger::create(42).unwrap();
	EXPECT_EQ(ctx.equals(a, b), py_true());
}

TEST_F(TruthyFallbackTest, EqualsIntDifferentValue)
{
	auto *a = PyInteger::create(1).unwrap();
	auto *b = PyInteger::create(2).unwrap();
	EXPECT_EQ(ctx.equals(a, b), py_false());
}

TEST_F(TruthyFallbackTest, EqualsStringSameValue)
{
	auto *a = PyString::create("hello").unwrap();
	auto *b = PyString::create("hello").unwrap();
	EXPECT_EQ(ctx.equals(a, b), py_true());
}

TEST_F(TruthyFallbackTest, EqualsStringDifferentValue)
{
	auto *a = PyString::create("hello").unwrap();
	auto *b = PyString::create("world").unwrap();
	EXPECT_EQ(ctx.equals(a, b), py_false());
}

TEST_F(TruthyFallbackTest, EqualsMixedTypes)
{
	auto *a = PyInteger::create(1).unwrap();
	auto *b = PyString::create("1").unwrap();
	auto *result = ctx.equals(a, b);
	// int != str → should be py_false() or NotImplemented fallback
	EXPECT_NE(result, py_true());
}

TEST_F(TruthyFallbackTest, EqualsSameObject)
{
	auto *a = PyInteger::create(99).unwrap();
	EXPECT_EQ(ctx.equals(a, a), py_true());
}