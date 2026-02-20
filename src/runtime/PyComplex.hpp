#pragma once

#include "forward.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/PyType.hpp"
#include "runtime/Value.hpp"

#include <complex>

namespace py {

class PyComplex : public PyBaseObject
{
#ifndef PYLANG_USE_ARENA
	friend class ::Heap;
#endif
	friend class ::py::Arena;

	std::complex<BigIntType> m_complex;

  protected:
	PyComplex(PyType *);

	PyComplex(TypePrototype &, std::complex<BigIntType>);

	PyComplex(PyType *, std::complex<BigIntType>);

  public:
	static std::function<std::unique_ptr<TypePrototype>()> type_factory();
	PyType *static_type() const override;
};

}// namespace py
