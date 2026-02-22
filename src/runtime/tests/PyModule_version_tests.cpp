#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyNone.hpp"
#include "runtime/PyString.hpp"
#include "runtime/Value.hpp"

#include <gtest/gtest.h>

using namespace py;

// =============================================================================
// PyModule dict_version + key_version 测试
// =============================================================================

TEST(PyModuleVersion, InitialVersionIsZero)
{
	auto *dict = PyDict::create().unwrap();
	auto *name = PyString::create("test_mod").unwrap();
	auto *doc = PyString::create("").unwrap();
	auto *mod = PyModule::create(dict, name, doc).unwrap();

	// 构造函数中 add_symbol 会递增版本号，但初始 m_dict_version 为 0
	// 构造函数调用了 5 次 insert（通过构造函数直接操作 m_attributes），
	// 不经过 add_symbol，所以 dict_version 仍然为 0
	// 注意：构造函数中使用的是 m_attributes->insert，不是 add_symbol
	EXPECT_EQ(mod->dict_version(), 0u);
}

TEST(PyModuleVersion, AddSymbolBumpsDictVersion)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	uint64_t v0 = mod->dict_version();
	mod->add_symbol(PyString::create("x").unwrap(), Value{ py_none() });
	uint64_t v1 = mod->dict_version();

	EXPECT_GT(v1, v0);
}

TEST(PyModuleVersion, AddSymbolBumpsKeyVersion)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	EXPECT_EQ(mod->get_key_version("x"), 0u);
	mod->add_symbol(PyString::create("x").unwrap(), Value{ py_none() });
	EXPECT_EQ(mod->get_key_version("x"), 1u);
}

TEST(PyModuleVersion, DictVersionMonotonicallyIncreases)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	uint64_t prev = mod->dict_version();
	for (int i = 0; i < 100; ++i) {
		mod->add_symbol(PyString::create("k" + std::to_string(i)).unwrap(), Value{ py_none() });
		uint64_t cur = mod->dict_version();
		EXPECT_GT(cur, prev);
		prev = cur;
	}
}

TEST(PyModuleVersion, KeyVersionIndependence)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	mod->add_symbol(PyString::create("pi").unwrap(), Value{ py_none() });
	uint64_t pi_ver = mod->get_key_version("pi");

	// 修改 counter 不影响 pi 的 key_version
	for (int i = 0; i < 100; ++i) {
		mod->add_symbol(PyString::create("counter").unwrap(), Value{ py_none() });
	}

	EXPECT_EQ(mod->get_key_version("pi"), pi_ver);
	EXPECT_EQ(mod->get_key_version("counter"), 100u);
}

TEST(PyModuleVersion, InvalidateCacheBumpsDictVersion)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	uint64_t v0 = mod->dict_version();
	mod->invalidate_cache();
	uint64_t v1 = mod->dict_version();
	EXPECT_GT(v1, v0);
}

TEST(PyModuleVersion, CrossModuleVersionsAreUnique)
{
	auto make_mod = [](const std::string &name) {
		return PyModule::create(PyDict::create().unwrap(),
			PyString::create(name).unwrap(),
			PyString::create("").unwrap())
			.unwrap();
	};

	auto *mod_a = make_mod("a");
	auto *mod_b = make_mod("b");

	mod_a->add_symbol(PyString::create("x").unwrap(), Value{ py_none() });
	uint64_t va = mod_a->dict_version();

	mod_b->add_symbol(PyString::create("y").unwrap(), Value{ py_none() });
	uint64_t vb = mod_b->dict_version();

	// 全局计数器保证不同模块的版本号不同
	EXPECT_NE(va, vb);
}

TEST(PyModuleVersion, OverwriteKeyBumpsVersion)
{
	auto *dict = PyDict::create().unwrap();
	auto *mod =
		PyModule::create(dict, PyString::create("m").unwrap(), PyString::create("").unwrap())
			.unwrap();

	mod->add_symbol(PyString::create("x").unwrap(), Value{ py_none() });
	EXPECT_EQ(mod->get_key_version("x"), 1u);

	// 覆写同一个 key
	mod->add_symbol(PyString::create("x").unwrap(), Value{ py_none() });
	EXPECT_EQ(mod->get_key_version("x"), 2u);
}