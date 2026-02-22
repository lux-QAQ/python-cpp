#include "runtime/ModuleMangler.hpp"

#include <gtest/gtest.h>

using namespace py;

// =============================================================================
// ModuleMangler 测试
// =============================================================================

TEST(ModuleMangler, SimpleModule) { EXPECT_EQ(ModuleMangler::mangle("main"), "PyInit_main"); }

TEST(ModuleMangler, DottedModule)
{
	EXPECT_EQ(ModuleMangler::mangle("foo.bar"), "PyInit_foo_2E_bar");
}

TEST(ModuleMangler, DeepDottedModule)
{
	EXPECT_EQ(ModuleMangler::mangle("foo.bar.baz"), "PyInit_foo_2E_bar_2E_baz");
}

TEST(ModuleMangler, UnderscoreModule)
{
	EXPECT_EQ(ModuleMangler::mangle("foo_bar"), "PyInit_foo_5F_bar");
}

TEST(ModuleMangler, LeadingUnderscore)
{
	EXPECT_EQ(ModuleMangler::mangle("_codecs"), "PyInit__5F_codecs");
}

TEST(ModuleMangler, Collections)
{
	EXPECT_EQ(ModuleMangler::mangle("collections"), "PyInit_collections");
}

TEST(ModuleMangler, EmptyString) { EXPECT_EQ(ModuleMangler::mangle(""), "PyInit_"); }

TEST(ModuleMangler, PureAlphaNumeric)
{
	EXPECT_EQ(ModuleMangler::mangle("abc123"), "PyInit_abc123");
}

TEST(ModuleMangler, MixedSpecialChars)
{
	// 下划线 + 点号
	EXPECT_EQ(ModuleMangler::mangle("foo_bar.baz"), "PyInit_foo_5F_bar_2E_baz");
}