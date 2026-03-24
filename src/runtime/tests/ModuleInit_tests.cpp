#include "interpreter/InterpreterCore.hpp"
#include "runtime/ModuleRegistry.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyString.hpp"
#include "runtime/builtinTypeInit.hpp"
#include "runtime/modules/Modules.hpp"
#include "runtime/modules/config.hpp"

#include <gtest/gtest.h>
#include <string>

using namespace py;

// =============================================================================
// 模块工厂函数与 config.hpp builtin_modules 表测试
// =============================================================================

TEST(ModuleInit, BuiltinModulesTableNotEmpty) { EXPECT_GT(builtin_modules.size(), 0u); }

TEST(ModuleInit, AllFactoryFunctionsProduceNonNull)
{
	initialize_types();
	for (const auto &[name, factory] : builtin_modules) {
		if (factory) {
			auto *mod = factory();
			ASSERT_NE(mod, nullptr) << "Factory for '" << name << "' returned nullptr";
		}
	}
}

TEST(ModuleInit, BuiltinsModuleHasExpectedSymbols)
{
	initialize_types();
	auto *mod = builtins_module();
	ASSERT_NE(mod, nullptr);

	auto *sym = mod->symbol_table();
	ASSERT_NE(sym, nullptr);

	// 检查关键内建函数存在
	EXPECT_TRUE(sym->map().contains(String{ "print" }));
	EXPECT_TRUE(sym->map().contains(String{ "len" }));
	EXPECT_TRUE(sym->map().contains(String{ "isinstance" }));
	EXPECT_TRUE(sym->map().contains(String{ "type" }));
	EXPECT_TRUE(sym->map().contains(String{ "int" }));
	EXPECT_TRUE(sym->map().contains(String{ "str" }));
	EXPECT_TRUE(sym->map().contains(String{ "list" }));
	EXPECT_TRUE(sym->map().contains(String{ "dict" }));
	EXPECT_TRUE(sym->map().contains(String{ "bool" }));
	// None/True/False 由 Interpreter::internal_setup → initialize_types() 注入
	// 单独调用 builtins_module() 时不包含这三个符号
	EXPECT_TRUE(sym->map().contains(String{ "__import__" }));
	EXPECT_TRUE(sym->map().contains(String{ "__build_class__" }));
}

TEST(ModuleInit, SysModuleHasExpectedSymbols)
{
	initialize_types();
	auto *mod = sys_module();
	ASSERT_NE(mod, nullptr);

	auto *sym = mod->symbol_table();
	ASSERT_NE(sym, nullptr);

	EXPECT_TRUE(sym->map().contains(String{ "path" }));
	EXPECT_TRUE(sym->map().contains(String{ "modules" }));
	EXPECT_TRUE(sym->map().contains(String{ "platform" }));
}

TEST(ModuleInit, FactoryFunctionIdempotent)
{
	initialize_types();
	auto *mod1 = builtins_module();
	auto *mod2 = builtins_module();
	EXPECT_EQ(mod1, mod2);

	auto *sys1 = sys_module();
	auto *sys2 = sys_module();
	EXPECT_EQ(sys1, sys2);
}

TEST(ModuleInit, RegisterAllBuiltinsPopulatesRegistry)
{
	initialize_types();
	register_all_builtins();

	for (const auto &[name, factory] : builtin_modules) {
		if (factory) {
			auto *mod = ModuleRegistry::instance().find(std::string(name));
			EXPECT_NE(mod, nullptr) << "Module '" << name << "' not found in registry";
		}
	}
}

TEST(ModuleInit, RegisterAllBuiltinsIdempotent)
{
	initialize_types();
	register_all_builtins();
	auto *mod1 = ModuleRegistry::instance().find("builtins");

	register_all_builtins();
	auto *mod2 = ModuleRegistry::instance().find("builtins");

	EXPECT_EQ(mod1, mod2);
}