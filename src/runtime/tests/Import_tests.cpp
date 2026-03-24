#include "interpreter/InterpreterCore.hpp"
#include "runtime/Import.hpp"
#include "runtime/ModuleRegistry.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyString.hpp"
#include "runtime/modules/config.hpp"

#include <gtest/gtest.h>

using namespace py;

// =============================================================================
// Import 双路径查找测试
// =============================================================================

TEST(Import, FindFrozenImportlib)
{
	auto *name = PyString::create("_frozen_importlib").unwrap();
	auto result = find_frozen(name);
	EXPECT_TRUE(result.has_value());
	EXPECT_EQ(result->get().name, "_frozen_importlib");
}

TEST(Import, FindFrozenImportlibExternal)
{
	auto *name = PyString::create("_frozen_importlib_external").unwrap();
	auto result = find_frozen(name);
	EXPECT_TRUE(result.has_value());
	EXPECT_EQ(result->get().name, "_frozen_importlib_external");
}

TEST(Import, FindFrozenNonExistent)
{
	auto *name = PyString::create("nonexistent_frozen_xyz").unwrap();
	auto result = find_frozen(name);
	EXPECT_FALSE(result.has_value());
}

TEST(Import, CreateBuiltinWithRegisteredModule)
{

	register_all_builtins();

	auto *builtins = ModuleRegistry::instance().find("builtins");
	EXPECT_NE(builtins, nullptr);
}