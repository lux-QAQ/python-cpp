#include "runtime/PyDict.hpp"
#include "runtime/PyFloat.hpp"
#include "runtime/PyInteger.hpp"
#include "runtime/PyList.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyString.hpp"
#include "runtime/PyTuple.hpp"
#include "runtime/RuntimeContext.hpp"

#include <gtest/gtest.h>

using namespace py;

class RuntimeContextTruthyTest : public ::testing::Test
{
  protected:
	RuntimeContext ctx;
	RuntimeContext *saved{ nullptr };

	void SetUp() override
	{
		saved = RuntimeContext::has_current() ? &RuntimeContext::current() : nullptr;
		RuntimeContext::set_current(&ctx);
	}
	void TearDown() override { RuntimeContext::set_current(saved); }
};

TEST_F(RuntimeContextTruthyTest, EmptyList)
{
	EXPECT_FALSE(ctx.is_true(PyList::create().unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonEmptyList)
{
	auto *l = PyList::create().unwrap();
	l->append(py_none());
	EXPECT_TRUE(ctx.is_true(l));
}

TEST_F(RuntimeContextTruthyTest, EmptyDict)
{
	EXPECT_FALSE(ctx.is_true(PyDict::create().unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonEmptyDict)
{
	auto *d = PyDict::create().unwrap();
	d->insert(PyString::create("k").unwrap(), py_none());
	EXPECT_TRUE(ctx.is_true(d));
}

TEST_F(RuntimeContextTruthyTest, EmptyTuple)
{
	EXPECT_FALSE(ctx.is_true(PyTuple::create().unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonEmptyTuple)
{
	EXPECT_TRUE(ctx.is_true(PyTuple::create(py_none()).unwrap()));
}

TEST_F(RuntimeContextTruthyTest, EmptyString)
{
	EXPECT_FALSE(ctx.is_true(PyString::create("").unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonEmptyString)
{
	EXPECT_TRUE(ctx.is_true(PyString::create("x").unwrap()));
}

TEST_F(RuntimeContextTruthyTest, ZeroInteger)
{
	EXPECT_FALSE(ctx.is_true(PyInteger::create(0).unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonZeroInteger)
{
	EXPECT_TRUE(ctx.is_true(PyInteger::create(1).unwrap()));
}

TEST_F(RuntimeContextTruthyTest, ZeroFloat)
{
	EXPECT_FALSE(ctx.is_true(PyFloat::create(0.0).unwrap()));
}

TEST_F(RuntimeContextTruthyTest, NonZeroFloat)
{
	EXPECT_TRUE(ctx.is_true(PyFloat::create(1.5).unwrap()));
}