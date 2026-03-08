

#include "compiler/Support/StringUtils.hpp"

#include "compiler/Support/gtest_wrapper.hpp"

#include <gtest/gtest.h>

using namespace pylang::str;

TEST(StringUtilsTest, Split)
{
	auto parts = split("a:b:c", ':');
	ASSERT_EQ(parts.size(), 3);
	EXPECT_EQ(parts[0], "a");
	EXPECT_EQ(parts[1], "b");
	EXPECT_EQ(parts[2], "c");

	// 空字符串
	auto empty = split("", ':');
	ASSERT_EQ(empty.size(), 1);
	EXPECT_EQ(empty[0], "");

	// 无分隔符
	auto no_delim = split("abc", ':');
	ASSERT_EQ(no_delim.size(), 1);
	EXPECT_EQ(no_delim[0], "abc");

	// 连续分隔符
	auto consecutive = split("a::b", ':');
	ASSERT_EQ(consecutive.size(), 3);
	EXPECT_EQ(consecutive[0], "a");
	EXPECT_EQ(consecutive[1], "");
	EXPECT_EQ(consecutive[2], "b");
}

TEST(StringUtilsTest, SplitExact)
{
	auto result = split_exact<3>("a:b:c", ':');
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ((*result)[0], "a");
	EXPECT_EQ((*result)[1], "b");
	EXPECT_EQ((*result)[2], "c");

	// 数量不匹配
	auto too_few = split_exact<4>("a:b:c", ':');
	EXPECT_FALSE(too_few.has_value());

	auto too_many = split_exact<2>("a:b:c", ':');
	EXPECT_FALSE(too_many.has_value());
}

TEST(StringUtilsTest, Trim)
{
	EXPECT_EQ(trim("  hello  "), "hello");
	EXPECT_EQ(trim("\t\nhello\r\n"), "hello");
	EXPECT_EQ(trim("hello"), "hello");
	EXPECT_EQ(trim("   "), "");
	EXPECT_EQ(trim(""), "");
}

TEST(StringUtilsTest, StripPrefix)
{
	auto result = strip_prefix("pylang_export:op:add", "pylang_export:");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(*result, "op:add");

	auto no_match = strip_prefix("hello", "world");
	EXPECT_FALSE(no_match.has_value());

	auto empty_result = strip_prefix("prefix", "prefix");
	ASSERT_TRUE(empty_result.has_value());
	EXPECT_EQ(*empty_result, "");
}

TEST(StringUtilsTest, StripSuffix)
{
	auto result = strip_suffix("hello.txt", ".txt");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(*result, "hello");

	auto no_match = strip_suffix("hello", ".txt");
	EXPECT_FALSE(no_match.has_value());
}

TEST(StringUtilsTest, Contains)
{
	EXPECT_TRUE(contains("hello world", "world"));
	EXPECT_TRUE(contains("hello world", 'o'));
	EXPECT_FALSE(contains("hello", "world"));
	EXPECT_FALSE(contains("hello", 'x'));
}

TEST(StringUtilsTest, Count)
{
	EXPECT_EQ(count("a,b,c", ','), 2);
	EXPECT_EQ(count("aaa", 'a'), 3);
	EXPECT_EQ(count("hello", 'x'), 0);
	EXPECT_EQ(count("", 'a'), 0);
}

TEST(StringUtilsTest, ParseInt)
{
	auto result = parse_int<int>("123");
	ASSERT_TRUE(result.has_value());
	EXPECT_EQ(*result, 123);

	auto negative = parse_int<int>("-456");
	ASSERT_TRUE(negative.has_value());
	EXPECT_EQ(*negative, -456);

	auto invalid = parse_int<int>("abc");
	EXPECT_FALSE(invalid.has_value());

	auto partial = parse_int<int>("123abc");
	EXPECT_FALSE(partial.has_value());

	auto i64_val = parse_int<int64_t>("9223372036854775807");
	ASSERT_TRUE(i64_val.has_value());
	EXPECT_EQ(*i64_val, 9223372036854775807LL);
}

TEST(StringUtilsTest, Join)
{
	std::vector<std::string_view> parts = { "a", "b", "c" };
	EXPECT_EQ(join(parts, ","), "a,b,c");
	EXPECT_EQ(join(parts, "::"), "a::b::c");

	std::vector<std::string_view> empty;
	EXPECT_EQ(join(empty, ","), "");

	std::vector<std::string_view> single = { "hello" };
	EXPECT_EQ(join(single, ","), "hello");
}

TEST(StringUtilsTest, ReplaceAll)
{
	EXPECT_EQ(replace_all("hello world", "world", "universe"), "hello universe");
	EXPECT_EQ(replace_all("aaa", "a", "b"), "bbb");
	EXPECT_EQ(replace_all("hello", "x", "y"), "hello");
	EXPECT_EQ(replace_all("", "a", "b"), "");
}

TEST(StringUtilsTest, AnnotationParsing)
{
	// 模拟 annotation 解析流程
	std::string_view annotation = "pylang_export:op:binary_add:obj:obj,obj";

	auto rest = strip_prefix(annotation, "pylang_export:");
	ASSERT_TRUE(rest.has_value());

	auto parts = split(*rest, ':');
	ASSERT_EQ(parts.size(), 4);
	EXPECT_EQ(parts[0], "op");
	EXPECT_EQ(parts[1], "binary_add");
	EXPECT_EQ(parts[2], "obj");
	EXPECT_EQ(parts[3], "obj,obj");

	auto params = split(parts[3], ',');
	ASSERT_EQ(params.size(), 2);
	EXPECT_EQ(params[0], "obj");
	EXPECT_EQ(params[1], "obj");
}