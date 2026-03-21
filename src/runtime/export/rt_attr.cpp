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
    // 1. Tagged Pointer 防火墙
    auto rt_obj = py::RtValue::from_ptr(obj);
    if (rt_obj.is_tagged_int()) {
        return rt_unwrap(rt_obj.box()->getattribute(py::PyString::intern(name)));
    }

    auto &cache = py::AttributeCache::instance();
    uint64_t gv = py::PyType::global_version();

    // 2. 高速缓存查找
    if (auto *cached = cache.lookup(obj, name, gv)) {
        return rt_unwrap(cached->get(obj, obj->type()));
    }

    auto *interned = py::PyString::intern(name);
    
    // 3. 优先级 A: MRO 查找数据描述符 (Property)
    auto [mro_res, found] = obj->type()->lookup_attribute(interned);
    py::PyObject *descr = nullptr;
    if (found == py::LookupAttrResult::FOUND) {
        descr = rt_unwrap(mro_res);
        if (descr && py::descriptor_is_data(descr)) {
            return rt_unwrap(descr->get(obj, obj->type()));
        }
    }

    // 4. 优先级 B: 实例字典查找 (Instance Dict)
    if (auto *attrs = obj->attributes()) {
        auto it = attrs->map().find(py::Value(interned));
        if (it != attrs->map().end()) {
            // [关键优化]：不再调用 .box()，直接返回位表示
            // 这让 self.limit 在 AOT 循环中访问是零开销的
            return py::RtValue::from_value(it->second).as_pyobject_raw();
        }
    }

    // 5. 优先级 C: 非数据描述符 (方法)
    if (found == py::LookupAttrResult::FOUND && descr) {
        cache.update(obj, name, descr, gv);
        return rt_unwrap(descr->get(obj, obj->type()));
    }

    // 6. Fallback
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