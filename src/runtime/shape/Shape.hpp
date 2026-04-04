#pragma once

#include "runtime/PyObject.hpp"
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <unordered_map>

namespace py {

class Shape
{
	Shape *m_parent;
	std::string m_property_name;
	size_t m_offset;

	// maps property name to next shape
	std::unordered_map<std::string, Shape *> m_transitions;

  public:
	Shape() : m_parent(nullptr), m_offset(0) {}
	Shape(Shape *parent, std::string name, size_t offset)
		: m_parent(parent), m_property_name(std::move(name)), m_offset(offset)
	{}

	size_t offset() const { return m_offset; }
	size_t slot_count() const { return m_offset + 1; }

	Shape *transition(const std::string &name)
	{
		if (auto it = m_transitions.find(name); it != m_transitions.end()) { return it->second; }
		auto *next = new Shape(this, name, slot_count());
		m_transitions[name] = next;
		return next;
	}

	std::optional<size_t> lookup(const std::string &name) const
	{
		const Shape *current = this;
		while (current) {
			if (current->m_property_name == name) { return current->m_offset; }
			current = current->m_parent;
		}
		return std::nullopt;
	}
};

}// namespace py
