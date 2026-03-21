#include "rt_common.hpp"

#include "runtime/IndexError.hpp"
#include "runtime/NameError.hpp"
#include "runtime/PyCell.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyFunction.hpp"
#include "runtime/PyString.hpp"
#include "runtime/PyTuple.hpp"
#include "runtime/RuntimeError.hpp"
#include "runtime/taggered_pointer/RtValue.hpp"
#include "runtime/types/api.hpp"
#include "runtime/types/builtin.hpp"
#include <alloca.h>
#include <span>

py::PyObject *rt_getattr(py::PyObject *obj, const char *name);

// =============================================================================
// Tier 0: 函数调用
// =============================================================================

PYLANG_EXPORT_FUNC("call", "obj", "obj,obj,obj")
py::PyObject *rt_call(py::PyObject *callable, py::PyObject *args, py::PyObject *kwargs)
{
	auto *tuple_args = static_cast<py::PyTuple *>(py::ensure_box(args));
	auto *dict_kwargs = kwargs ? static_cast<py::PyDict *>(py::ensure_box(kwargs)) : nullptr;
	return rt_unwrap(py::ensure_box(callable)->call(tuple_args, dict_kwargs));
}

// =============================================================================
// Tier 4: 方法调用
// =============================================================================

PYLANG_EXPORT_FUNC("load_method", "obj", "obj,str")
py::PyObject *rt_load_method(py::PyObject *obj, const char *name)
{
	auto *b_obj = py::ensure_box(obj);
	auto *cached = py::MethodCache::load_method(b_obj, name);
	if (!cached) {
		// 回退抛出原本由于找不到属性导致的抛错
		rt_raise(b_obj->get_method(py::PyString::intern(name)).unwrap_err());
	}
	return cached;
}

// =============================================================================
// Tier 4: tuple 特化访问（闭包实现需要）
// =============================================================================

PYLANG_EXPORT_SUBSCR("tuple_getitem", "obj", "obj,i32")
py::PyObject *rt_tuple_getitem(py::PyObject *tuple, int32_t index)
{
	auto *t = static_cast<py::PyTuple *>(py::ensure_box(tuple));
	return rt_unwrap(t->__getitem__(static_cast<int64_t>(index)));
}

// =============================================================================
// Tier 4: 闭包操作
// =============================================================================

PYLANG_EXPORT_FUNC("create_cell", "obj", "obj")
py::PyObject *rt_create_cell(py::PyObject *value)
{
	if (value) { return rt_unwrap(py::PyCell::create(py::Value{ py::ensure_box(value) })); }
	return rt_unwrap(py::PyCell::create());
}

PYLANG_EXPORT_FUNC("cell_get", "obj", "obj")
py::PyObject *rt_cell_get(py::PyObject *cell)
{
	auto *cell_obj = static_cast<py::PyCell *>(py::ensure_box(cell));
	if (cell_obj->empty()) {
		rt_raise(py::name_error("free variable referenced before assignment in enclosing scope"));
	}
	return rt_unwrap(py::PyObject::from(cell_obj->content()));
}

PYLANG_EXPORT_FUNC("cell_set", "void", "obj,obj")
void rt_cell_set(py::PyObject *cell, py::PyObject *value)
{
	auto *cell_obj = static_cast<py::PyCell *>(py::ensure_box(cell));
	cell_obj->set_cell(py::Value{ py::ensure_box(value) });
}

// =============================================================================
// Phase 4+: 快速调用路径
// =============================================================================

PYLANG_EXPORT_FUNC("call_fast", "obj", "obj,i32,ptr")
py::PyObject *rt_call_fast(py::PyObject *callable, int32_t argc, py::PyObject **argv)
{
	std::vector<py::Value> elements;
	elements.reserve(argc);
	for (int32_t i = 0; i < argc; ++i) { elements.push_back(py::ensure_box(argv[i])); }
	auto *args = rt_unwrap(py::PyTuple::create(elements));
	return rt_unwrap(py::ensure_box(callable)->call(args, nullptr));
}

// =============================================================================
// Tier 4: make_function
// =============================================================================

PYLANG_EXPORT_FUNC("make_function", "obj", "str,ptr,obj,obj,obj,obj")
py::PyObject *rt_make_function(const char *name,
	void *code_ptr,
	py::PyObject *module,
	py::PyObject *defaults,
	py::PyObject *kwdefaults,
	py::PyObject *closure)
{
	return rt_unwrap(py::PyNativeFunction::create_aot(std::string(name),
		code_ptr,
		py::ensure_box(module),
		py::ensure_box(defaults),
		py::ensure_box(kwdefaults),
		py::ensure_box(closure)));
}

// =============================================================================
// Tier 4: get_closure
// =============================================================================

PYLANG_EXPORT_FUNC("get_closure", "obj", "obj")
py::PyObject *rt_get_closure(py::PyObject *func)
{
	auto b_func = py::ensure_box(func);
	if (auto *pyfunc = py::as<py::PyFunction>(b_func)) {
		auto *closure = pyfunc->closure();
		return closure ? static_cast<py::PyObject *>(closure) : rt_unwrap(py::PyTuple::create());
	}

	if (auto *native = py::as<py::PyNativeFunction>(b_func)) {
		auto *closure = native->closure();
		return closure ? static_cast<py::PyObject *>(closure) : rt_unwrap(py::PyTuple::create());
	}

	return rt_unwrap(py::PyTuple::create());
}

PYLANG_EXPORT_FUNC("rt_call_method_raw", "obj", "obj,str,i32,ptr")
py::PyObject *rt_call_method_raw(py::PyObject *obj, const char *name, int32_t argc, py::PyObject **argv)
{
    auto *b_obj = py::ensure_box(obj);
    auto *attr_name = py::PyString::intern(name);
    auto *type = b_obj->type();

    py::PyObject *self = nullptr;
    py::PyObject *method = nullptr;

    // 3.9 语义查找
    auto descr_lookup = type->lookup(attr_name);
    py::PyObject *descr = (descr_lookup.has_value() && descr_lookup->is_ok()) ? descr_lookup->unwrap() : nullptr;

    if (descr) {
        // 如果是数据描述符（如 property），必须走标准 getattr 流程（会创建 BoundMethod）
        if (py::descriptor_is_data(descr)) {
            method = rt_getattr(b_obj, name);
        } else {
            // 检查实例字典
            if (auto* inst_dict = b_obj->attributes()) {
                if (auto it = inst_dict->map().find(attr_name); it != inst_dict->map().end()) {
                    method = py::PyObject::from(it->second).unwrap();
                }
            }
            // 如果实例没覆盖，且 descr 是函数，命中 Fast Path
            if (!method) {
                if (descr->type() == py::types::native_function() || descr->type() == py::types::function()) {
                    method = descr;
                    self = b_obj; // 标记需要传入 self
                } else {
                    method = rt_getattr(b_obj, name);
                }
            }
        }
    } else {
        method = rt_getattr(b_obj, name);
    }

    // 零堆分配参数准备
    size_t total_argc = argc + (self ? 1 : 0);
    auto *stack_args = static_cast<py::Value *>(alloca(sizeof(py::Value) * total_argc));

    if (self) {
        new (&stack_args[0]) py::Value(self);
        for (int i = 0; i < argc; ++i) new (&stack_args[i + 1]) py::Value(py::ensure_box(argv[i]));
    } else {
        for (int i = 0; i < argc; ++i) new (&stack_args[i]) py::Value(py::ensure_box(argv[i]));
    }

    // ✅ 调用 call_raw 接口（此时 PyNativeFunction 内部已不再创建 Tuple）
    auto result = method->call_raw(std::span<py::Value>(stack_args, total_argc), nullptr);
    
    // 析构 Value（清理 tagged 指针不需要，但为了安全一致性）
    for (size_t i = 0; i < total_argc; ++i) stack_args[i].~Value();

    return rt_unwrap(result);
}