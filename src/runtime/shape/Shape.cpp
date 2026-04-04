#include "Shape.hpp"

#include "runtime/PyString.hpp"
#include "runtime/PyType.hpp"

#include <atomic>
#include <mutex>

namespace py {
namespace {

	std::atomic<uint64_t> &shape_version_counter()
	{
		static std::atomic<uint64_t> counter{ 1 };
		return counter;
	}

	uint64_t next_shape_version()
	{
		return shape_version_counter().fetch_add(1, std::memory_order_relaxed);
	}

	std::unordered_map<PyType *, Shape *> &shape_roots()
	{
		static std::unordered_map<PyType *, Shape *> roots;
		return roots;
	}

	std::mutex &shape_roots_mutex()
	{
		static std::mutex mutex;
		return mutex;
	}

}// namespace

Shape::Shape(PyType *owner_type, uint64_t version) : m_owner_type(owner_type), m_version(version) {}

Shape::Shape(Shape *parent, PyString *name, size_t offset, uint64_t version)
	: m_parent(parent), m_owner_type(parent->m_owner_type), m_property_name(name),
	  m_slot_count(offset + 1), m_version(version), m_offsets(parent->m_offsets)
{
	m_offsets.emplace(name, offset);
}

Shape *Shape::root(PyType *owner_type)
{
	std::lock_guard lock(shape_roots_mutex());
	auto &roots = shape_roots();
	if (auto it = roots.find(owner_type); it != roots.end()) { return it->second; }

	auto *root_shape = new Shape(owner_type, next_shape_version());
	roots.emplace(owner_type, root_shape);
	return root_shape;
}

Shape *Shape::transition(PyString *name)
{
	auto *interned = PyString::intern(name->value());
	if (auto it = m_transitions.find(interned); it != m_transitions.end()) { return it->second; }

	const size_t offset = m_slot_count;
	auto *next = new Shape(this, interned, offset, next_shape_version());
	m_transitions.emplace(interned, next);
	return next;
}

std::optional<size_t> Shape::lookup(PyString *name) const
{
	auto *interned = PyString::intern(name->value());
	if (auto it = m_offsets.find(interned); it != m_offsets.end()) { return it->second; }
	return std::nullopt;
}

}// namespace py
