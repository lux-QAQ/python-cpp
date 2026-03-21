#include "rt_common.hpp"

#include "runtime/AttributeCache.hpp"
#include "runtime/ModuleRegistry.hpp"
#include "runtime/NameError.hpp"
#include "runtime/PyBoundMethod.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/PyString.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"
#include <spdlog/spdlog.h>
// =============================================================================
// Tier 0: 属性访问
// =============================================================================

// PYLANG_EXPORT_ATTR("getattr", "obj", "obj,str")
// py::PyObject *rt_getattr(py::PyObject *obj, const char *name)
// {
// 	auto rt_obj = py::RtValue::from_ptr(obj);
// 	if (rt_obj.is_tagged_int()) {
// 		return rt_unwrap(rt_obj.box()->getattribute(py::PyString::intern(name)));
// 	}

// 	auto &cache = py::AttributeCache::instance();
// 	uint64_t gv = py::PyType::global_version();

// 	// [DEBUG] 打印查找起始
// 	spdlog::debug("[rt_getattr] Entry: obj={:p} (type={}), attr='{}'",
// 		(void *)obj,
// 		obj->type()->name(),
// 		name);

// 	// 1. 缓存查找 (仅针对类属性/方法)
// 	if (auto *cached = cache.lookup(obj, name, gv)) {
// 		if (py::as<py::PyFunction>(cached) || py::as<py::PyNativeFunction>(cached)) {
// 			spdlog::debug("[rt_getattr] Cache Hit (Method): '{}' on obj={:p}", name, (void *)obj);
// 			return rt_unwrap(py::PyBoundMethod::create(obj, cached));
// 		}
// 		spdlog::debug("[rt_getattr] Cache Hit (Static): '{}' on obj={:p}", name, (void *)obj);
// 		return cached;
// 	}

// 	// 2. 实例属性查找 (Instance Dict) - 绝对不能缓存！
// 	if (obj->attributes()) {
// 		auto it = obj->attributes()->map().find(py::String{ name });
// 		if (it != obj->attributes()->map().end()) {
// 			auto res_val = py::RtValue::from_value(it->second).box();
// 			spdlog::debug(
// 				"[rt_getattr] Found in Instance Dict: '{}' = {:p}", name, (void *)res_val);
// 			return res_val;
// 		}
// 	}

// 	// 3. MRO 查找
// 	auto *interned = py::PyString::intern(name);
// 	auto [res, found] = obj->type()->lookup_attribute(interned);

// 	if (found == py::LookupAttrResult::FOUND) {
// 		if (res.is_err()) {
// 			spdlog::error("[rt_getattr] Error during MRO lookup of '{}'", name);
// 			rt_raise(res.unwrap_err());
// 		}
// 		auto *val = res.unwrap();
// 		spdlog::debug("[rt_getattr] Found in MRO: '{}' (type={})", name, val->type()->name());

// 		if (val && !val->type()->underlying_type().__get__.has_value()) {
// 			cache.update(obj, name, val, gv);
// 		}
// 		return rt_unwrap(val->get(obj, obj->type()));
// 	}

// 	// 如果走到这里，说明属性彻底丢了
// 	spdlog::warn("[rt_getattr] NOT FOUND: '{}' on obj={:p} (Type: {}). Dict size: {}",
// 		name,
// 		(void *)obj,
// 		obj->type()->name(),
// 		obj->attributes() ? obj->attributes()->map().size() : 0);

// 	return rt_unwrap(obj->getattribute(interned));
// }


PYLANG_EXPORT_ATTR("getattr", "obj", "obj,str")
py::PyObject *rt_getattr(py::PyObject *obj, const char *name)
{
	auto rt_obj = py::RtValue::from_ptr(obj);
	if (rt_obj.is_tagged_int()) {
		return rt_unwrap(rt_obj.box()->getattribute(py::PyString::intern(name)));
	}
	spdlog::debug("[rt_getattr] Searching '{}' on obj={:p} (type={})",
		name,
		(void *)obj,
		obj->type()->name());
	auto &cache = py::AttributeCache::instance();
	uint64_t gv = py::PyType::global_version();

	// 1. 实例属性查找 (Instance Dict) - 优先级最高，且绝不进入 Cache，确保实例隔离
    if (obj->attributes()) {
        spdlog::trace("[rt_getattr] Instance dict exists for {:p}, size={}", (void*)obj, obj->attributes()->map().size());
        auto it = obj->attributes()->map().find(py::String{ name });
        if (it != obj->attributes()->map().end()) {
            spdlog::debug("[rt_getattr] Found in instance dict: '{}'", name);
            return py::RtValue::from_value(it->second).box();
        }
    } else {
        spdlog::trace("[rt_getattr] No instance dict for {:p}", (void*)obj);
    }
	spdlog::debug("[rt_getattr] Entry: obj={:p} (type={}), attr='{}'",
		(void *)obj,
		obj->type()->name(),
		name);
	// 2. 缓存查找 (仅针对类层级的 Method 或 Static 属性)
    if (auto *cached = cache.lookup(obj, name, gv)) {
        spdlog::trace("[rt_getattr] Cache hit for '{}' on {:p}", name, (void*)obj);
        return rt_unwrap(cached->get(obj, obj->type()));
    }

	// 3. MRO 查找 (从类和基类中寻找)
	auto *interned = py::PyString::intern(name);
	auto [res, found] = obj->type()->lookup_attribute(interned);

	if (found == py::LookupAttrResult::FOUND) {
		auto *val = rt_unwrap(res);
		// [缓存策略]：只有在类层级找到且不是 Data Descriptor 时才缓存
		// 这样下次访问同一类型的不同实例时，可以快速命中该方法
		if (val) cache.update(obj, name, val, gv);
		return rt_unwrap(val->get(obj, obj->type()));
	}
	spdlog::warn("[rt_getattr] NOT FOUND: '{}' on obj={:p} (Type: {}). Dict size: {}",
		name,
		(void *)obj,
		obj->type()->name(),
		obj->attributes() ? obj->attributes()->map().size() : 0);
	// 4. 回退到 __getattribute__ 或报错
	return rt_unwrap(obj->getattribute(interned));
}

PYLANG_EXPORT_ATTR("load_global", "obj", "obj,str")
py::PyObject *rt_load_global(py::PyObject *module, const char *name)
{
	auto *mod = static_cast<py::PyModule *>(py::ensure_box(module));
	auto result = mod->find_symbol_cstr(name);
	if (result.is_ok()) { return result.unwrap(); }

	auto &reg = py::ModuleRegistry::instance();
	if (auto *builtins_mod = reg.find("builtins")) {
		auto builtin_result = builtins_mod->find_symbol_cstr(name);
		if (builtin_result.is_ok()) { return builtin_result.unwrap(); }
	}

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
	rt_unwrap_void(
		py::ensure_box(obj)->setattribute(py::PyString::intern(name), py::ensure_box(value)));
}

PYLANG_EXPORT_ATTR("delattr", "void", "obj,str")
void rt_delattr(py::PyObject *obj, const char *name)
{
	rt_unwrap_void(py::ensure_box(obj)->delattribute(py::PyString::intern(name)));
}