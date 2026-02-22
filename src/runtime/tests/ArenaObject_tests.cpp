//
// Arena 分配真实 PyObject — 验证 Arena 模式下对象正确工作
//
#include "memory/Arena.hpp"
#include "memory/ArenaManager.hpp"
#include "memory/ScopedRegion.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyFloat.hpp"
#include "runtime/PyInteger.hpp"
#include "runtime/PyList.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyString.hpp"
#include "runtime/PyTuple.hpp"

#include <gtest/gtest.h>

using namespace py;

// =============================================================================
// Arena 分配 PyObject 的生命周期测试
// =============================================================================

class ArenaObjectTest : public ::testing::Test
{
  protected:
	Arena *saved_arena{ nullptr };

	void SetUp() override { saved_arena = Arena::has_current() ? &Arena::current() : nullptr; }

	void TearDown() override
	{
		if (saved_arena) { Arena::set_current(saved_arena); }
	}
};

TEST_F(ArenaObjectTest, ModuleArenaAllocation)
{
	// 模拟: ModuleArena 分配模块级对象
	auto &arena = ArenaManager::module_arena("arena_obj_test");
	Arena::set_current(&arena);

	auto *mod = PyModule::create(PyDict::create().unwrap(),
		PyString::create("arena_obj_test").unwrap(),
		PyString::create("").unwrap())
					.unwrap();

	ASSERT_NE(mod, nullptr);
	EXPECT_EQ(mod->name()->value(), "arena_obj_test");

	// 恢复
	Arena::set_current(saved_arena);
}

TEST_F(ArenaObjectTest, ScopedRegionObjectLifetime)
{
	// 模拟: 函数内部临时对象在 ScopedRegion 中分配
	PyInteger *outer_ref = nullptr;

	{
		ScopedRegion region;
		auto *temp = PyInteger::create(42).unwrap();
		ASSERT_NE(temp, nullptr);
		EXPECT_EQ(temp->as_i64(), 42);

		// 模拟 "逃逸" — 保存到外部指针
		// 注意: 在真实场景中，逃逸对象应分配到父级 Arena
		outer_ref = temp;
	}
	// region 析构后 outer_ref 悬空 — 这里只验证 region 正常析构不崩溃
	// 不访问 outer_ref
	(void)outer_ref;
}

TEST_F(ArenaObjectTest, NestedScopedRegion)
{
	// 模拟嵌套函数调用
	int depth = 0;

	{
		ScopedRegion outer;
		auto *a = PyInteger::create(1).unwrap();
		EXPECT_EQ(a->as_i64(), 1);
		depth++;

		{
			ScopedRegion inner;
			auto *b = PyInteger::create(2).unwrap();
			EXPECT_EQ(b->as_i64(), 2);
			depth++;
		}
		// inner 析构

		auto *c = PyInteger::create(3).unwrap();
		EXPECT_EQ(c->as_i64(), 3);
	}
	// outer 析构

	EXPECT_EQ(depth, 2);
}

TEST_F(ArenaObjectTest, MixedObjectTypes)
{
	ScopedRegion region;

	auto *i = PyInteger::create(42).unwrap();
	auto *f = PyFloat::create(3.14).unwrap();
	auto *s = PyString::create("hello").unwrap();
	auto *lst = PyList::create().unwrap();
	auto *d = PyDict::create().unwrap();

	ASSERT_NE(i, nullptr);
	ASSERT_NE(f, nullptr);
	ASSERT_NE(s, nullptr);
	ASSERT_NE(lst, nullptr);
	ASSERT_NE(d, nullptr);

	EXPECT_EQ(i->as_i64(), 42);
	EXPECT_DOUBLE_EQ(f->as_f64(), 3.14);
	EXPECT_EQ(s->value(), "hello");

	lst->append(i);
	lst->append(f);
	lst->append(s);
	auto len = lst->__len__();
	ASSERT_TRUE(len.is_ok());
	EXPECT_EQ(len.unwrap(), 3u);

	d->insert(s, i);
	auto val = d->__getitem__(s);
	ASSERT_TRUE(val.is_ok());
	EXPECT_EQ(as<PyInteger>(val.unwrap())->as_i64(), 42);
}