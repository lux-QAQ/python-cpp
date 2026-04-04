#pragma once

#include "runtime/PyObject.hpp"
#include "runtime/PyType.hpp"
#include <atomic>

namespace py {
namespace cache {

	struct AttrCache
	{
		std::atomic<py::PyType *> expected_type{ nullptr };
		std::atomic<uint64_t> type_version{ 0 };
		std::atomic<py::Shape *> expected_shape{ nullptr };
		std::atomic<py::Shape *> next_shape{ nullptr };
		std::atomic<uint32_t> slot_offset{ 0 };
		std::atomic<uint8_t> kind{ 0 };
	};

}// namespace cache
}// namespace py
