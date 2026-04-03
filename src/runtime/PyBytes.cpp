#include "PyBytes.hpp"
#include "MemoryError.hpp"
#include "PyBool.hpp"
#include "StopIteration.hpp"
#include "runtime/IndexError.hpp"
#include "runtime/PyByteArray.hpp"
#include "runtime/PyDict.hpp"
#include "runtime/PyInteger.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/PySlice.hpp"
#include "runtime/PyString.hpp"
#include "runtime/PyTuple.hpp"
#include "runtime/TypeError.hpp"
#include "runtime/ValueError.hpp"
#include "runtime/utilities.hpp"
#include "types/api.hpp"
#include "types/builtin.hpp"


#include "runtime/compat.hpp"
#include <iomanip>
#include <sstream>
#include <string_view>

namespace py {

template<> PyBytes *as(PyObject *obj)
{
	if (obj->type() == types::bytes()) { return static_cast<PyBytes *>(obj); }
	return nullptr;
}

template<> const PyBytes *as(const PyObject *obj)
{
	if (obj->type() == types::bytes()) { return static_cast<const PyBytes *>(obj); }
	return nullptr;
}

PyBytes::PyBytes(PyType *type) : PyBaseObject(type) {}

PyBytes::PyBytes(std::vector<std::byte> value)
	: PyBaseObject(types::BuiltinTypes::the().bytes()), m_value(std::move(value))
{}

PyBytes::PyBytes() : PyBytes(std::vector<std::byte>{}) {}


struct ByteBackInserter
{
	using iterator_category = std::output_iterator_tag;
	using value_type = void;
	using difference_type = std::ptrdiff_t;
	using pointer = void;
	using reference = void;
	using container_type = std::vector<std::byte>;

	container_type &m_bytes;
	BaseException *m_exception{ nullptr };
	ByteBackInserter(std::vector<std::byte> &bytes) : m_bytes(bytes) {}

	BaseException *last_error() const { return m_exception; }

	ByteBackInserter &operator=(PyObject *value)
	{
		if (auto int_obj = as<PyInteger>(value)) {
			if (int_obj->as_i64() >= 0 && int_obj->as_i64() <= 255) {
				m_bytes.push_back(static_cast<std::byte>(int_obj->as_i64()));
			}
		} else {
			m_exception = type_error(
				"'{}' object cannot be interpreted as an integer", value->type()->name());
		}
		return *this;
	}
};

PyResult<int32_t> PyBytes::__init__(PyTuple *args, PyDict *kwargs)
{
	ASSERT(!kwargs || kwargs->map().empty());

	if (!args || args->elements().empty()) {
		return Ok(0);
	} else if (args->elements().size() == 1) {
		auto arg0 = PyObject::from(args->elements()[0]);
		if (arg0.is_err()) { return Err(arg0.unwrap_err()); }
		if (auto count = as<PyInteger>(arg0.unwrap())) {
			m_value.resize(count->as_size_t());
		} else if (auto bytes = as<PyBytes>(arg0.unwrap())) {
			// FIXME: should this take the iterable path?
			m_value.insert(m_value.end(), bytes->value().begin(), bytes->value().end());
		} else if (arg0.unwrap()->iter().is_ok()) {
			if (auto result = from_iterable(arg0.unwrap(), ByteBackInserter(m_value));
				result.is_err()) {
				return Err(result.unwrap_err());
			}
		} else {
			TODO();
		}
	} else {
		TODO();
	}

	return Ok(0);
}

PyResult<PyObject *> PyBytes::__new__(const PyType *type, PyTuple *, PyDict *)
{
	ASSERT(type == types::bytes());
	return PyBytes::create();
}

PyResult<PyBytes *> PyBytes::create(std::vector<std::byte> value)
{

	auto *obj = PYLANG_ALLOC(PyBytes, std::move(value));
	if (!obj) { return Err(memory_error(sizeof(PyBytes))); }
	return Ok(obj);
}

PyResult<PyBytes *> PyBytes::create()
{

	auto *obj = PYLANG_ALLOC(PyBytes, );
	if (!obj) { return Err(memory_error(sizeof(PyBytes))); }
	return Ok(obj);
}

std::string PyBytes::to_string() const
{
	std::ostringstream os;
	os << "b'";
	for (const auto &byte : m_value) {
		const auto byte_ = std::to_integer<unsigned char>(byte);
		if (byte_ == '\\') {
			os << "\\\\";
		} else if (byte_ == '\'') {
			os << "\\'";
		} else if (byte_ == '\t') {
			os << "\\t";
		} else if (byte_ == '\n') {
			os << "\\n";
		} else if (byte_ == '\r') {
			os << "\\r";
		} else if (byte_ < ' ' || byte_ >= 0x7f) {
			os << "\\x" << std::hex << std::setw(2) << std::setfill('0')
			   << static_cast<uint32_t>(byte_);
		} else {
			os << static_cast<char>(byte_);
		}
	}
	os << "'";
	return os.str();
}

PyResult<PyObject *> PyBytes::__add__(const PyObject *other) const
{
	auto new_bytes = m_value;
	if (auto bytes = as<PyBytes>(other)) {
		new_bytes.insert(new_bytes.end(), bytes->value().begin(), bytes->value().end());
	} else if (auto bytearray = as<PyByteArray>(other)) {
		new_bytes.insert(new_bytes.end(), bytearray->value().begin(), bytearray->value().end());
	} else {
		return Err(type_error("can't concat {} to bytes", other->type()->name()));
	}

	return PyBytes::create(new_bytes);
}

PyResult<PyObject *> PyBytes::__mul__(const PyObject *obj) const
{
	if (!obj->type()->issubclass(types::integer())) {
		return Err(
			type_error("can't multiply sequence by non-int of type '{}'", obj->type()->name()));
	}

	const auto &value = static_cast<const PyInteger &>(*obj).as_big_int();
	if (value <= 0) { return PyBytes::create(); }
	if (value == 1) { return PyBytes::create(m_value); }

	ASSERT(value.fits_uint_p());
	const auto repeats = value.get_ui();
	std::vector<std::byte> bytes;
	bytes.reserve(repeats * m_value.size());
	const auto stride = m_value.size();
	const auto end = repeats * m_value.size();
	for (size_t offset = 0; offset < end; offset += stride) {
		bytes.insert(bytes.begin() + offset, m_value.begin(), m_value.end());
	}
	return PyBytes::create(std::move(bytes));
}


PyResult<size_t> PyBytes::__len__() const { return Ok(m_value.size()); }

PyResult<PyObject *> PyBytes::__eq__(const PyObject *obj) const
{
	if (this == obj) return Ok(py_true());
	if (auto obj_bytes = as<PyBytes>(obj)) {
		return Ok(m_value == obj_bytes->value() ? py_true() : py_false());
	} else {
		return Err(type_error("'==' not supported between instances of '{}' and '{}'",
			type()->name(),
			obj->type()->name()));
	}
}

PyResult<PyObject *> PyBytes::__iter__() const
{
	return PyBytesIterator::create(const_cast<PyBytes *>(this));
}

PyResult<PyObject *> PyBytes::__repr__() const { return PyString::create(to_string()); }

PyResult<PyObject *> PyBytes::decode(const std::string &encoding, const std::string &errors) const
{
	return PyString::from_encoded_object(this, encoding, errors);
}

PyResult<PyObject *> PyBytes::__getitem__(int64_t index)
{
	if (index < 0) { index += m_value.size(); }

	if (index < 0 || static_cast<size_t>(index) >= m_value.size()) {
		return Err(index_error("index out of range"));
	}

	return PyInteger::create(static_cast<int64_t>(m_value[index]));
}

PyResult<PyObject *> PyBytes::__getitem__(PyObject *index)
{
	if (index->type()->issubclass(types::integer())) {
		const auto i = static_cast<const PyInteger &>(*index).as_i64();
		return __getitem__(i);
	} else if (auto slice = as<PySlice>(index)) {
		auto indices_ = slice->unpack();
		if (indices_.is_err()) return Err(indices_.unwrap_err());
		const auto [start_, end_, step] = indices_.unwrap();

		const auto [start, end, slice_length] =
			PySlice::adjust_indices(start_, end_, step, m_value.size());

		if (slice_length == 0) { return PyBytes::create(); }
		if (start == 0 && end == static_cast<int64_t>(m_value.size()) && step == 1) {
			return PyBytes::create(m_value);
		}

		std::vector<std::byte> new_bytes;
		new_bytes.reserve(slice_length);
		for (int64_t idx = start, i = 0; i < slice_length; idx += step, ++i) {
			new_bytes.push_back(m_value[idx]);
		}
		return PyBytes::create(std::move(new_bytes));
	} else {
		return Err(
			type_error("list indices must be integers or slices, not {}", index->type()->name()));
	}
}

PyResult<std::monostate> PyBytes::__getbuffer__(PyBuffer &view, int /*flags*/)
{
	view.obj = this;
	view.buf =
		std::make_unique<NonOwningStorage<std::byte>>(const_cast<std::byte *>(m_value.data()));
	view.len = m_value.size();
	view.readonly = true;
	view.itemsize = 1;
	view.format = "B";
	view.ndim = 1;
	return Ok(std::monostate{});
}

PyResult<int64_t> PyBytes::__hash__() const
{
	// bytes and str have the same hash
	// e.g. hash("123") == hash(b"123")
	std::string_view sv{ reinterpret_cast<const char *>(m_value.data()), m_value.size() };
	return Ok(static_cast<int64_t>(std::hash<std::string_view>{}(sv)));
}

/*
PyType *PyBytes::static_type() const { return types::bytes(); }
*/

namespace {

	std::once_flag bytes_flag;

	std::unique_ptr<TypePrototype> register_bytes()
	{
		return std::move(klass<PyBytes>("bytes")
				.def("decode",
					[](PyBytes *obj, PyTuple *args, PyDict *kwargs) -> PyResult<PyObject *> {
						std::optional<std::string> encoding;
						std::optional<std::string> errors;
						if (args) {
							if (args->size() > 2) {
								return Err(type_error(
									"decode() takes at most 2 arguments ({} given)", args->size()));
							}
							if (args->size() > 0) {
								auto arg0 = PyObject::from(args->elements()[0]).unwrap();
								if (auto enc = as<PyString>(arg0)) {
									encoding = enc->value();
								} else {
									return Err(type_error(
										"decode() argument 'encoding' must be str, not {}",
										arg0->type()->to_string()));
								}
							}
							if (args->size() > 1) {
								auto arg1 = PyObject::from(args->elements()[1]).unwrap();
								if (auto err = as<PyString>(arg1)) {
									errors = err->value();
								} else {
									return Err(
										type_error("decode() argument 'errors' must be str, not {}",
											arg1->type()->to_string()));
								}
							}
						}
						if (kwargs) { TODO(); }
						return obj->decode(encoding.value_or("utf-8"), errors.value_or("strict"));
					})
				.type);
	}
}// namespace

std::function<std::unique_ptr<TypePrototype>()> PyBytes::type_factory()
{
	return [] {
		static std::unique_ptr<TypePrototype> type = nullptr;
		std::call_once(bytes_flag, []() { type = register_bytes(); });
		return std::move(type);
	};
}

PyBytesIterator::PyBytesIterator(PyType *type) : PyBaseObject(type) {}

PyBytesIterator::PyBytesIterator(PyBytes *bytes, size_t index)
	: PyBaseObject(types::BuiltinTypes::the().bytes_iterator()), m_bytes(bytes), m_index(index)
{}

PyResult<PyBytesIterator *> PyBytesIterator::create(PyBytes *bytes)
{

	auto *obj = PYLANG_ALLOC(PyBytesIterator, bytes, 0);
	if (!obj) { return Err(memory_error(sizeof(PyBytesIterator))); }
	return Ok(obj);
}

std::string PyBytesIterator::to_string() const
{
	return fmt::format("<bytes_iterator object at {}>", static_cast<const void *>(this));
}

PyResult<PyObject *> PyBytesIterator::__repr__() const { return PyString::create(to_string()); }

PyResult<PyObject *> PyBytesIterator::__next__()
{
	if (!m_bytes || m_index >= m_bytes->value().size()) { return Err(stop_iteration()); }
	const auto next_value = m_bytes->value()[m_index++];
	return PyInteger::create(static_cast<int64_t>(next_value));
}

/*
PyType *PyBytesIterator::static_type() const { return types::bytes_iterator(); }
*/

void PyBytesIterator::visit_graph(Visitor &visitor)
{
	PyObject::visit_graph(visitor);
	if (m_bytes) { visitor.visit(*m_bytes); }
}

namespace {

	std::once_flag bytes_iterator_flag;

	std::unique_ptr<TypePrototype> register_bytes_iterator()
	{
		return std::move(klass<PyBytesIterator>("bytes_iterator").type);
	}
}// namespace

std::function<std::unique_ptr<TypePrototype>()> PyBytesIterator::type_factory()
{
	return [] {
		static std::unique_ptr<TypePrototype> type = nullptr;
		std::call_once(bytes_iterator_flag, []() { type = register_bytes_iterator(); });
		return std::move(type);
	};
}

}// namespace py
