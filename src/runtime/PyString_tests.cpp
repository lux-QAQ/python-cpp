#include "PyString.hpp"

#include <gtest/gtest.h>

using namespace py;

TEST(PyString, hash)
{
	std::string foo{ "foo" };
	auto foo_obj_ = PyString::create(foo);
	ASSERT_TRUE(foo_obj_.is_ok());
	auto object_hash = foo_obj_.unwrap()->hash();
	ASSERT_TRUE(object_hash.is_ok());
	ASSERT_EQ(std::hash<std::string>{}(foo), object_hash.unwrap());
}