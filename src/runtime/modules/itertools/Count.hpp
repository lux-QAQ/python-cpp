#include "runtime/PyObject.hpp"
#include "runtime/Value.hpp"

namespace py {
namespace itertools {
	class Count : public PyBaseObject
	{
#ifndef PYLANG_USE_ARENA
		friend class ::Heap;
#endif
		friend class ::py::Arena;

		PyObject *m_start{ nullptr };
		PyObject *m_step{ nullptr };
		PyObject *m_current{ nullptr };

		Count(PyType *type);

		Count();
		Count(PyObject *start);
		Count(PyObject *start, PyObject *step);

		static PyResult<PyObject *> create();
		static PyResult<PyObject *> create(PyObject *start);
		static PyResult<PyObject *> create(PyObject *start, PyObject *step);

	  public:
		static PyResult<PyObject *> __new__(const PyType *type, PyTuple *args, PyDict *kwargs);

		PyResult<PyObject *> __iter__() const;
		PyResult<PyObject *> __next__();

		static PyType *register_type(PyModule *module);

		void visit_graph(Visitor &visitor) override;
	};
}// namespace itertools
}// namespace py
