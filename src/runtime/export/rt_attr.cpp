#include "cache/rt_attr_cache.hpp"
#include "rt_common.hpp"
#include "runtime/shape/Shape.hpp"

#include "runtime/AttributeCache.hpp"
#include "runtime/ModuleRegistry.hpp"
#include "runtime/NameError.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyString.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"

py::PyObject *rt_getattr_ic(py::cache::AttrCache *cache, py::PyObject *obj, py::PyObject *name_obj);
void rt_setattr_ic(py::cache::AttrCache *cache,
	py::PyObject *obj,
	py::PyObject *name_obj,
	py::PyObject *value);

PYLANG_EXPORT_ATTR("getattr", "obj", "obj,str")
py::PyObject *rt_getattr(py::PyObject *obj, const char *name)
{
	return rt_getattr_ic(nullptr, obj, py::PyString::intern(name));
}


PYLANG_EXPORT_ATTR("getattr_fast", "obj", "obj,obj")
py::PyObject *rt_getattr_fast(py::PyObject *obj, py::PyObject *name_obj)
{
	if (!name_obj) {
		spdlog::critical(
			"Runtime Error: getattr_fast received NULL name_obj. "
			"This usually means PyInit failed to initialize string constants.");
		std::abort();
	}
	return rt_getattr_ic(nullptr, obj, name_obj);
}

// PYLANG_EXPORT_ATTR("load_global", "obj", "obj,str")
// py::PyObject *rt_load_global(py::PyObject *module, const char *name)
// {
// 	auto *mod = static_cast<py::PyModule *>(py::ensure_box(module));
// 	auto result = mod->find_symbol_cstr(name);
// 	if (result.is_ok()) { return result.unwrap(); }

// 	auto &reg = py::ModuleRegistry::instance();
// 	if (auto *builtins_mod = reg.find("builtins")) {
// 		auto builtin_result = builtins_mod->find_symbol_cstr(name);
// 		if (builtin_result.is_ok()) { return builtin_result.unwrap(); }
// 	}

// 	rt_raise(py::name_error("name '{}' is not defined", name));
// 	return nullptr;
// }

PYLANG_EXPORT_ATTR("load_global", "obj", "obj,str")
py::PyObject *rt_load_global(py::PyObject *module, const char *name)
{
	auto *mod = static_cast<py::PyModule *>(py::ensure_box(module));
	auto *globals_dict = mod->dict();
	auto *builtins_mod = py::ModuleRegistry::instance().find("builtins");
	auto *builtins_dict = builtins_mod ? builtins_mod->dict() : nullptr;

	// 1. 快速路径：语义安全缓存
	if (auto *cached = py::GlobalCache::lookup(mod, name, globals_dict, builtins_dict)) {
		return cached;
	}

	// 2. 慢速路径：标准查找
	py::PyObject *found = nullptr;
	auto result = mod->find_symbol_cstr(name);
	if (result.is_ok()) {
		found = result.unwrap();
	} else {
		auto &reg = py::ModuleRegistry::instance();
		if (auto *builtins_mod = reg.find("builtins")) {
			auto builtin_result = builtins_mod->find_symbol_cstr(name);
			if (builtin_result.is_ok()) found = builtin_result.unwrap();
		}
	}

	if (found) {
		py::GlobalCache::update(mod,
			name,
			found,
			globals_dict->version(),
			builtins_dict ? builtins_dict->version() : 0);
		return found;
	}

	// 只有最后确定找不到，才分配一次异常
	rt_raise(py::name_error("name '{}' is not defined", name));
	return nullptr;
}

// =============================================================================
// Tier 1: 存储操作
// =============================================================================

PYLANG_EXPORT_ATTR("store_global", "void", "obj,str,obj")
void rt_store_global(py::PyObject *module, const char *name, py::PyObject *value)
{
	rt_unwrap_void(
		py::ensure_box(module)->setattribute(py::PyString::intern(name), py::ensure_box(value)));
}

// =============================================================================
// Tier 5: setattr / delattr
// =============================================================================

PYLANG_EXPORT_ATTR("setattr", "void", "obj,str,obj")
void rt_setattr(py::PyObject *obj, const char *name, py::PyObject *value)
{
	rt_setattr_ic(nullptr, obj, py::PyString::intern(name), value);
}

PYLANG_EXPORT_ATTR("setattr_fast", "void", "obj,obj,obj")
void rt_setattr_fast(py::PyObject *obj, py::PyObject *name_obj, py::PyObject *value)
{
	rt_setattr_ic(nullptr, obj, name_obj, value);
}

PYLANG_EXPORT_ATTR("delattr", "void", "obj,str")
void rt_delattr(py::PyObject *obj, const char *name)
{
	rt_unwrap_void(py::ensure_box(obj)->delattribute(py::PyString::intern(name)));
}
