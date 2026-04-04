#pragma once

#include "PyObject.hpp"
#include "runtime/Value.hpp"

namespace py {

class PyNumber : public PyBaseObject
{
#ifndef PYLANG_USE_ARENA
	friend class ::Heap;
#endif
	friend class ::py::Arena;
	friend class PyInteger;
	friend class PyFloat;

  protected:
	PyNumber(PyType *);

  public:
	std::string to_string() const override;

	PyResult<PyObject *> __add__(const PyObject *obj) const;
	PyResult<PyObject *> __sub__(const PyObject *obj) const;
	PyResult<PyObject *> __mod__(const PyObject *obj) const;
	PyResult<PyObject *> __divmod__(PyObject *obj);
	PyResult<PyObject *> __mul__(const PyObject *obj) const;
	PyResult<PyObject *> __pow__(const PyObject *obj, const PyObject *modulo) const;
	PyResult<PyObject *> __truediv__(const PyObject *obj) const;
	PyResult<PyObject *> __floordiv__(const PyObject *obj) const;

	PyResult<PyObject *> __abs__() const;
	PyResult<PyObject *> __neg__() const;
	PyResult<PyObject *> __pos__() const;
	PyResult<PyObject *> __invert__() const;

	PyResult<PyObject *> __repr__() const;
	PyResult<PyObject *> __eq__(const PyObject *obj) const;
	PyResult<PyObject *> __ne__(const PyObject *obj) const;
	PyResult<PyObject *> __lt__(const PyObject *obj) const;
	PyResult<PyObject *> __le__(const PyObject *obj) const;
	PyResult<PyObject *> __gt__(const PyObject *obj) const;
	PyResult<PyObject *> __ge__(const PyObject *obj) const;

	PyResult<bool> __bool__() const;

	static const PyNumber *as_number(const PyObject *obj);

  private:
};

}// namespace py