import re

with open('src/runtime/shape/Shape.hpp', 'r') as f:
    text = f.read()

new_shape = '''#pragma once

#include "runtime/PyObject.hpp"
#include "runtime/PyString.hpp"
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <unordered_map>

namespace py {

class Shape
{
    Shape *m_parent;
    PyString *m_property_name;
    size_t m_offset;

    // maps property name to next shape
    std::unordered_map<PyString *, Shape *> m_transitions;

  public:
    Shape() : m_parent(nullptr), m_property_name(nullptr), m_offset(0) {}
    Shape(Shape *parent, PyString *name, size_t offset)
        : m_parent(parent), m_property_name(name), m_offset(offset)
    {}

    size_t offset() const { return m_offset; }
    size_t slot_count() const { return m_offset + 1; }

    Shape *transition(PyString *name)
    {
        // Ensure name is interned for fast pointer comparisons!
        auto interned = PyString::intern(name->value());
        if (auto it = m_transitions.find(interned); it != m_transitions.end()) { return it->second; }
        auto *next = new Shape(this, interned, slot_count());
        m_transitions[interned] = next;
        return next;
    }

    std::optional<size_t> lookup(PyString *name) const
    {
        auto interned = PyString::intern(name->value());
        const Shape *current = this;
        while (current && current->m_property_name) {
            if (current->m_property_name == interned) { return current->m_offset; }
            current = current->m_parent;
        }
        return std::nullopt;
    }
};

}// namespace py
'''

with open('src/runtime/shape/Shape.hpp', 'w') as f:
    f.write(new_shape)

