#pragma once

#include "PyObject.hpp"
#include "PyTuple.hpp"

#include <optional>

namespace py {

class PyString
	: public PyBaseObject
	, public PySequence
{
#ifndef PYLANG_USE_ARENA
	friend class ::Heap;
#endif
	friend class ::py::Arena;
	std::string m_value;

	PyString(PyType *);

  public:
	struct FormatSpec
	{
		size_t start;
		size_t end;
		std::optional<std::string> mapping;
		std::optional<char> conversion_flag;
		std::optional<uint32_t> minimum_width;
		std::optional<uint32_t> precision;
		std::optional<char> conversion_type;

		PyResult<std::string> apply(PyObject *obj) const;
	};

	struct ReplacementField
	{
		enum class Conversion {
			REPR = 1,
			STR = 2,
			ASCII = 3,
		};
		std::optional<std::string> field_name;
		std::optional<Conversion> conversion;
		std::optional<FormatSpec> format_spec;
		size_t start;
		size_t end;
		bool display_expression{ false };

		static std::optional<Conversion> get_conversion(char);
	};

  public:
	// 已有的工厂方法
	static PyResult<PyString *> create(const std::string &value);
	static PyResult<PyString *> create(std::string &&value);

	// [性能优化] 不走 intern 的原始创建，用于不做 dict key 的临时字符串（如 str(int)）
	static PyResult<PyString *> create_raw(std::string &&value);

	// 新增：字符串驻留 (String Interning)
	// 对同一个字符串内容，永远返回同一个 PyString 对象
	// 驻留的字符串不会被 GC 回收
	static PyString *intern(const char *cstr);
	static PyString *intern(const std::string &str);
	static PyString *intern(std::string &&str);

	static PyResult<PyString *> create(PyObject *);

	static PyResult<PyString *> create(const std::vector<std::byte> &bytes,
		const std::string &encoding = "");

	static std::string from_unescaped_string(const std::string &s);

	PyString(const std::string &s);
	PyString(std::string &&s);

	// static PyResult<PyString *> create(const Bytes &, const std::string &encoding);

	// 修改：将实现移到 .cpp，防止访问 incomplete type PyTuple
	static PyResult<PyString *> create(PyString *self, PyTuple *args, PyDict *kwargs);

	const std::string &value() const { return m_value; }
	std::vector<uint32_t> codepoints() const;
	std::optional<uint32_t> codepoint() const;

	std::string to_string() const override { return m_value; }
	size_t size() const;

	static PyResult<PyObject *> __new__(const PyType *type, PyTuple *args, PyDict *kwargs);
	PyResult<PyObject *> __repr__() const;
	PyResult<PyObject *> __str__() const;
	PyResult<int64_t> __hash__() const;
	PyResult<PyObject *> __eq__(const PyObject *obj) const;
	PyResult<PyObject *> __ne__(const PyObject *obj) const;
	PyResult<PyObject *> __lt__(const PyObject *obj) const;
	PyResult<bool> __bool__() const;
	PyResult<PyObject *> __iter__() const;
	PyResult<PyObject *> __getitem__(PyObject *index);

	PyResult<size_t> __len__() const;
	PyResult<PyObject *> __add__(const PyObject *obj) const;
	PyResult<PyObject *> __mul__(size_t count) const;
	PyResult<PyObject *> __mod__(const PyObject *obj) const;

	PyResult<PyObject *> isalpha() const;
	PyResult<PyObject *> isalnum() const;
	PyResult<PyObject *> isascii() const;
	PyResult<PyObject *> isdigit() const;
	PyResult<PyObject *> islower() const;
	PyResult<PyObject *> isupper() const;
	PyResult<PyObject *> isidentifier() const;

	PyResult<PyObject *> capitalize() const;
	PyResult<PyObject *> casefold() const;
	PyResult<PyObject *> find(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> rfind(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> count(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> startswith(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> endswith(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> join(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> lower() const;
	PyResult<PyObject *> upper() const;
	PyResult<PyObject *> partition(PyObject *sep) const;
	PyResult<PyObject *> rpartition(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> replace(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> translate(PyObject *table) const;
	PyResult<PyObject *> encode(PyTuple *args, PyDict *kwargs) const;

	PyResult<PyObject *> rstrip(PyTuple *args, PyDict *kwargs) const;
	PyResult<PyObject *> strip(PyTuple *args, PyDict *kwargs) const;

	PyResult<PyList *> split(PyTuple *args, PyDict *kwargs) const;

	static PyResult<PyObject *> maketrans(PyTuple *args, PyDict *kwargs);

	PyResult<PyObject *> format(PyTuple *args, PyDict *kwargs) const;

	static PyResult<PyString *> convert_to_ascii(PyObject *obj);
	static PyResult<PyString *> from_encoded_object(const PyObject *obj,
		const std::string &encoding,
		const std::string &errors);
	static PyResult<PyString *>
		decode(std::span<const std::byte>, const std::string &encoding, const std::string &errors);

	static std::function<std::unique_ptr<TypePrototype>()> type_factory();
	// PyType *static_type() const override;;

	PyResult<PyObject *> operator[](int64_t) const;

	static PyResult<PyString *> chr(BigIntType cp);

  private:
	size_t get_position_from_slice(int64_t) const;

	PyResult<PyString *> printf(const PyObject *values) const;
};

class PyStringIterator : public PyBaseObject
{
#ifndef PYLANG_USE_ARENA
	friend class ::Heap;
#endif
	friend class ::py::Arena;
	friend class PyString;// 允许 __iter__ 访问私有成员进行复用

	const PyString *m_pystring_ptr;
	size_t m_current_index{ 0 };

  public:
	PyStringIterator(const PyString &pystring);

	// [性能优化] 复用接口：重置迭代器指向新字符串
	void reset(const PyString &pystring)
	{
		m_pystring_ptr = &pystring;
		m_current_index = 0;
	}

	const PyString &pystring() const { return *m_pystring_ptr; }

	std::string to_string() const override;

	void visit_graph(Visitor &) override;

	PyResult<PyObject *> __repr__() const;
	PyResult<PyObject *> __next__();

	// 快速迭代接口：返回原始指针，不分配 StopIteration
	PyObject *next_raw();

	static std::function<std::unique_ptr<TypePrototype>()> type_factory();
	// PyType *static_type() const override;;
};

}// namespace py
