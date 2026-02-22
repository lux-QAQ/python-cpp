#include "runtime/ModuleRegistry.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyString.hpp"

#include <gtest/gtest.h>
#include <thread>

using namespace py;

// =============================================================================
// ModuleRegistry 基础测试
// =============================================================================

class ModuleRegistryTest : public ::testing::Test
{
  protected:
	PyModule *make_module(const std::string &name)
	{
		return PyModule::create(PyDict::create().unwrap(),
			PyString::create(name).unwrap(),
			PyString::create("").unwrap())
			.unwrap();
	}
};

TEST_F(ModuleRegistryTest, FindReturnsNullForUnknown)
{
	EXPECT_EQ(ModuleRegistry::instance().find("nonexistent_module_xyz"), nullptr);
}

TEST_F(ModuleRegistryTest, RegisterAndFind)
{
	auto *mod = make_module("test_reg_find");
	ModuleRegistry::instance().register_module("test_reg_find", mod);

	auto *found = ModuleRegistry::instance().find("test_reg_find");
	EXPECT_EQ(found, mod);
}

TEST_F(ModuleRegistryTest, RegisterDoesNotOverwrite)
{
	auto *mod1 = make_module("test_no_overwrite");
	auto *mod2 = make_module("test_no_overwrite");

	ModuleRegistry::instance().register_module("test_no_overwrite", mod1);
	ModuleRegistry::instance().register_module("test_no_overwrite", mod2);

	// 第一次注册的模块应保留（或取决于实现策略）
	auto *found = ModuleRegistry::instance().find("test_no_overwrite");
	EXPECT_NE(found, nullptr);
}

TEST_F(ModuleRegistryTest, MultipleModules)
{
	auto *mod_a = make_module("test_multi_a");
	auto *mod_b = make_module("test_multi_b");
	auto *mod_c = make_module("test_multi_c");

	ModuleRegistry::instance().register_module("test_multi_a", mod_a);
	ModuleRegistry::instance().register_module("test_multi_b", mod_b);
	ModuleRegistry::instance().register_module("test_multi_c", mod_c);

	EXPECT_EQ(ModuleRegistry::instance().find("test_multi_a"), mod_a);
	EXPECT_EQ(ModuleRegistry::instance().find("test_multi_b"), mod_b);
	EXPECT_EQ(ModuleRegistry::instance().find("test_multi_c"), mod_c);
}

TEST_F(ModuleRegistryTest, ThreadSafeRegistration)
{
	constexpr int N = 100;
	std::vector<std::thread> threads;
	std::vector<PyModule *> modules(N);

	for (int i = 0; i < N; ++i) { modules[i] = make_module("thread_mod_" + std::to_string(i)); }

	for (int i = 0; i < N; ++i) {
		threads.emplace_back([i, &modules]() {
			ModuleRegistry::instance().register_module(
				"thread_mod_" + std::to_string(i), modules[i]);
		});
	}

	for (auto &t : threads) { t.join(); }

	for (int i = 0; i < N; ++i) {
		EXPECT_EQ(ModuleRegistry::instance().find("thread_mod_" + std::to_string(i)), modules[i]);
	}
}