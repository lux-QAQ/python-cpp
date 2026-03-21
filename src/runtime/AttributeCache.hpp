#pragma once
#include <cstdint>
#include <spdlog/spdlog.h>

#include "runtime/PyObject.hpp"

#define debugCache


namespace py {
struct AttrCacheEntry {
    PyType* type;
    const char* name;
    PyObject* attr;
    uint64_t version;
};

class AttributeCache {
    static constexpr size_t kSize = 512;
    AttrCacheEntry m_entries[kSize] = {};
public:
    static AttributeCache& instance() {
        static AttributeCache cache;
        return cache;
    }

    PyObject* lookup(PyObject* obj, const char* name, uint64_t gv) {

        size_t h = (reinterpret_cast<uintptr_t>(obj->type()) ^ reinterpret_cast<uintptr_t>(name)) % kSize;
        auto& e = m_entries[h];
        // 语义校验：类型匹配、属性名匹配、版本号匹配
        if (e.type == obj->type() && e.name == name && e.version == gv) {
            return e.attr;
        }
        return nullptr;
    }

    void update(PyObject* obj, const char* name, PyObject* val, uint64_t gv) {
        size_t h = (reinterpret_cast<uintptr_t>(obj->type()) ^ reinterpret_cast<uintptr_t>(name)) % kSize;
        m_entries[h] = { obj->type(), name, val, gv };
    }
};
}