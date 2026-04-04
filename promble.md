Function Stack	CPU Time: Total	CPU Time: Self	Module	Function (Full)	Source File	Start Address
Total	100.0%	0s	[Unknown]	[Unknown]	[Unknown]	[Unknown]
  _start	95.3%	0s	test	_start	[Unknown]	0x3d8e0
    __libc_start_main_impl	95.3%	0s	libc.so.6	__libc_start_main_impl	libc-start.c	0x2a200
      main	95.3%	0s	test	main	[Unknown]	0x402e0
        PyInit_test	82.2%	0s	test	PyInit_test	[Unknown]	0x3d9d0
          rt_call_raw_ptrs	82.2%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46b10
            py::PyNativeFunction::call_fast_ptrs	82.2%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
              test.<module>.0:0.find.86:0	82.2%	0s	test	test.<module>.0:0.find.86:0	[Unknown]	0x3f2d0
                rt_call_raw_ptrs	42.3%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46b10
                  py::PyNativeFunction::call_fast_ptrs	41.4%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                    test.<module>.0:0.generate_trie.71:0	41.4%	0.020s	test	test.<module>.0:0.generate_trie.71:0	[Unknown]	0x3ef90
                      rt_call_raw_ptrs	30.7%	0.012s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46b10
                        py::PyType::call_fast_ptrs	30.3%	0.024s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x1851f0
                          py::PyObject::init_fast_ptrs	14.9%	0.012s	test	py::PyObject::init_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x185b80
                            py::PyNativeFunction::call_fast_ptrs	9.2%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                              test.<module>.0:0.Node.3:0.__init__.4:4	9.2%	0s	test	test.<module>.0:0.Node.3:0.__init__.4:4	[Unknown]	0x3de10
                                rt_setattr_fast	6.0%	0s	test	rt_setattr_fast(py::PyObject*, py::PyObject*, py::PyObject*)	rt_attr.cpp	0x419e0
                                  py::PyObject::setattribute	6.0%	0.016s	test	py::PyObject::setattribute(py::PyObject*, py::PyObject*)	PyObject.cpp	0x193a70
                                    _ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultISt9monostateEEPNS_8PyObjectES7_S7_EES5_JS7_RS7_SA_EEET0_RKSt7variantIJT_S7_EESt17basic_string_viewIcSt11char_traitsIcEEDpOT1_Qntsr3stdE9is_same_vINSB_6OkTypeES7_E	5.4%	0.008s	test	_ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultISt9monostateEEPNS_8PyObjectES7_S7_EES5_JS7_RS7_SA_EEET0_RKSt7variantIJT_S7_EESt17basic_string_viewIcSt11char_traitsIcEEDpOT1_Qntsr3stdE9is_same_vINSB_6OkTypeES7_E	PyObject.cpp	0x194c20
                                      py::PyObject::__setattribute__	5.3%	0s	test	py::PyObject::__setattribute__(py::PyObject*, py::PyObject*)	PyObject.cpp	0x1a6360
                                        py::Shape::transition	3.1%	0.012s	test	py::Shape::transition(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)	Shape.hpp	0x3eea80
                                          std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const, py::Shape*>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const, py::Shape*>>, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>, (bool)1>::operator[]	1.7%	0.105s	test	std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const, py::Shape*>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const, py::Shape*>>, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>, (bool)1>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)	hashtable_policy.h	0x3ef070
                                          operator new	1.0%	0.061s	libstdc++.so.6	operator new(unsigned long)	new_op.cc	0xa5a9a
                                          __memset_avx2_unaligned_erms	0.2%	0.012s	libc.so.6	__memset_avx2_unaligned_erms	memset-vec-unaligned-erms.S	0x189480
                                        std::vector<py::PyObject*, py::GCTracingAllocator<py::PyObject*>>::_M_realloc_insert<py::PyObject* const&>	0.9%	0.020s	test	std::vector<py::PyObject*, py::GCTracingAllocator<py::PyObject*>>::_M_realloc_insert<py::PyObject* const&>(__gnu_cxx::__normal_iterator<py::PyObject**, std::vector<py::PyObject*, py::GCTracingAllocator<py::PyObject*>>>, py::PyObject* const&&&)	vector.tcc	0x3ee8a0
                                        py::PyType::lookup	0.8%	0.028s	test	py::PyType::lookup(py::PyObject*) const	PyType.cpp	0x22f220
                                        operator new	0.5%	0.032s	libstdc++.so.6	operator new(unsigned long)	new_op.cc	0xa5a9a
                                    std::_Function_handler<py::PyResult<std::monostate> (py::PyObject*, py::PyObject*, py::PyObject*), py::PyResult<std::monostate> (py::PyObject*, py::PyObject*, py::PyObject*)*>::_M_manager	0.3%	0.020s	test	std::_Function_handler<py::PyResult<std::monostate> (py::PyObject*, py::PyObject*, py::PyObject*), py::PyResult<std::monostate> (py::PyObject*, py::PyObject*, py::PyObject*)*>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)	std_function.h	0x288d60
                                rt_build_dict	3.2%	0s	test	rt_build_dict(int, py::PyObject**, py::PyObject**)	rt_create.cpp	0x44790
                                  py::PyDict::create	3.1%	0s	test	py::PyDict::create(void)	PyDict.cpp	0x11f1e0
                                    py::Arena::allocate<py::PyDict>	2.0%	0.012s	test	py::Arena::allocate<py::PyDict>()	Arena.hpp	0x392510
                                      GC_malloc	1.8%	0s	test	GC_malloc	malloc.c	0x6a92b0
                                    _pylang_debug_log_alloc	1.1%	0.028s	test	_pylang_debug_log_alloc(char const*, std::atomic<unsigned long>&)	compat.hpp	0x255360
                                  _ZNR2py8PyResultIPNS_6PyDictEE6unwrapEv	0.1%	0.008s	test	_ZNR2py8PyResultIPNS_6PyDictEE6unwrapEv	Value.hpp	0x25c590
                            py::PyObject::lookup_attribute	3.6%	0.028s	test	py::PyObject::lookup_attribute(py::PyObject*) const	PyObject.cpp	0x185f00
                              py::PyObject::get_attribute	2.8%	0s	test	py::PyObject::get_attribute(py::PyObject*) const	PyObject.cpp	0x186940
                              py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>	0.3%	0s	test	py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>(std::variant<std::function<py::PyResult<py::PyObject*> (py::PyObject const*)>, py::PyObject*> const&)	PyObject.hpp	0x3eba90
                            py::PySlotWrapper::call_fast_ptrs	0.9%	0s	test	py::PySlotWrapper::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PySlotWrapper.cpp	0x1c0980
                            py::PyString::intern	0.8%	0s	test	py::PyString::intern(char const*)	PyString.cpp	0x1c3050
                            _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.1%	0.008s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x2546f0
                          py::PyType::new_	9.9%	0.016s	test	py::PyType::new_(py::PyTuple*, py::PyDict*) const	PyType.cpp	0x23fe20
                          py::PyTuple::create	4.8%	0s	test	py::PyTuple::create(std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>&&)	PyTuple.cpp	0x1f37c0
                          py::PyType::issubclass	0.2%	0.012s	test	py::PyType::issubclass(py::PyType const*) const	PyType.cpp	0x22b6f0
                          py::PyTuple::create	0.2%	0.012s	test	py::PyTuple::create(void)	PyTuple.cpp	0x1f3740
                        _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.2%	0.012s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x2546f0
                      rt_iter_next	3.6%	0s	test	rt_iter_next(py::PyObject*, bool*)	rt_subscr.cpp	0x4d0e0
                      rt_load_global	1.7%	0s	test	rt_load_global(py::PyObject*, char const*)	rt_attr.cpp	0x40fb0
                      rt_get_iter	1.2%	0s	test	rt_get_iter(py::PyObject*)	rt_subscr.cpp	0x4d000
                      rt_getattr_fast	1.2%	0.012s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x40cc0
                      rt_setitem	0.9%	0s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4ded0
                      rt_compare_not_in	0.7%	0.016s	test	rt_compare_not_in(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x42870
                      rt_setattr_fast	0.5%	0s	test	rt_setattr_fast(py::PyObject*, py::PyObject*, py::PyObject*)	rt_attr.cpp	0x419e0
                      rt_getitem	0.3%	0.020s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4d650
                      rt_is_true	0.3%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42e10
                  py::PyType::call_fast_ptrs	0.9%	0s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x1851f0
                rt_call_method_ic_ptrs	39.9%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4ef30
                  py::PyNativeFunction::call_fast_ptrs	39.9%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                    test.<module>.0:0.Sieve.8:0.calc.64:4	36.8%	0s	test	test.<module>.0:0.Sieve.8:0.calc.64:4	[Unknown]	0x3ee90
                      rt_call_method_ic_ptrs	36.8%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4ef30
                        py::PyNativeFunction::call_fast_ptrs	36.8%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                          test.<module>.0:0.Sieve.8:0.loop_x.56:4	36.3%	0s	test	test.<module>.0:0.Sieve.8:0.loop_x.56:4	[Unknown]	0x3ed10
                            rt_call_method_ic_ptrs	36.3%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4ef30
                              py::PyNativeFunction::call_fast_ptrs	36.3%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                                test.<module>.0:0.Sieve.8:0.loop_y.48:4	36.3%	0.012s	test	test.<module>.0:0.Sieve.8:0.loop_y.48:4	[Unknown]	0x3eb80
                                  rt_call_method_ic_ptrs	31.5%	0.211s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4ef30
                                    py::PyNativeFunction::call_fast_ptrs	24.2%	0.085s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x139790
                                      test.<module>.0:0.Sieve.8:0.step1.33:4	10.4%	0.044s	test	test.<module>.0:0.Sieve.8:0.step1.33:4	[Unknown]	0x3e5e0
                                        rt_compare_le	2.3%	0s	test	rt_compare_le(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x42200
                                          py::RtValue::flatten	2.3%	0.012s	test	py::RtValue::flatten(py::PyObject*)	RtValue.cpp	0x4fb60
                                            py::PyInteger::as_big_int	2.0%	0s	test	py::PyInteger::as_big_int(void) const	PyInteger.cpp	0x143f30
                                              __gmpz_init_set	2.0%	0.024s	test	__gmpz_init_set	[Unknown]	0x5f34c0
                                                GC_malloc_atomic	1.6%	0s	test	GC_malloc_atomic	malloc.c	0x6a9290
                                            __gmpz_clear	0.1%	0.008s	test	__gmpz_clear	[Unknown]	0x5f1680
                                        rt_getitem	2.2%	0.134s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4d650
                                        rt_getattr_fast	1.4%	0.032s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x40cc0
                                        rt_is_true	1.3%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42e10
                                        rt_binary_mul	0.7%	0s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4ae70
                                        py::RtValue::mod	0.5%	0.032s	test	py::RtValue::mod(py::RtValue, py::RtValue)	RtValue.cpp	0x506d0
                                        rt_binary_add	0.5%	0s	test	rt_binary_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4ae10
                                        py::RtValue::mul	0.2%	0.012s	test	py::RtValue::mul(py::RtValue, py::RtValue)	RtValue.cpp	0x501a0
                                        rt_binary_mod	0.2%	0.012s	test	rt_binary_mod(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4afd0
                                        py::RtValue::from_int_or_box	0.1%	0.008s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x4fca0
                                        rt_value_array_get	0.1%	0.008s	test	rt_value_array_get(py::PyObject**, int)	rt_func.cpp	0x46350
                                        rt_setitem	0.1%	0s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4ded0
                                      test.<module>.0:0.Sieve.8:0.step3.43:4	5.8%	0s	test	test.<module>.0:0.Sieve.8:0.step3.43:4	[Unknown]	0x3e9a0
                                      test.<module>.0:0.Sieve.8:0.step2.38:4	5.7%	0s	test	test.<module>.0:0.Sieve.8:0.step2.38:4	[Unknown]	0x3e7f0
                                      spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>	0.9%	0s	test	spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>(spdlog::source_loc, spdlog::level::level_enum, fmt::v7::basic_string_view<char> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&&&)	logger.h	0x3b2ad0
                                    _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	2.0%	0.121s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x2546f0
                                    __memcmp_avx2_movbe	0.9%	0.057s	libc.so.6	__memcmp_avx2_movbe	memcmp-avx2-movbe.S	0x188320
                                    py::PyString::to_string[abi:cxx11]	0.7%	0.032s	test	py::PyString::to_string[abi:cxx11](void) const	PyString.hpp	0x40f940
                                    py::RtValue::box	0.2%	0.012s	test	py::RtValue::box(void) const	RtValue.cpp	0x4fa80
                                  rt_compare_lt	2.5%	0.008s	test	rt_compare_lt(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x421d0
                                  rt_getattr_fast	1.3%	0.024s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x40cc0
                                  rt_is_true	0.4%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42e10
                                  py::RtValue::compare_lt	0.2%	0.012s	test	py::RtValue::compare_lt(py::RtValue, py::RtValue)	RtValue.cpp	0x51b40
                                  rt_inplace_add	0.1%	0s	test	rt_inplace_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b5b0
                                  py::RtValue::mul	0.1%	0.008s	test	py::RtValue::mul(py::RtValue, py::RtValue)	RtValue.cpp	0x501a0
                          test.<module>.0:0.Sieve.8:0.omit_squares.22:4	0.5%	0s	test	test.<module>.0:0.Sieve.8:0.omit_squares.22:4	[Unknown]	0x3e450
                    test.<module>.0:0.Sieve.8:0.to_list.14:4	3.1%	0.012s	test	test.<module>.0:0.Sieve.8:0.to_list.14:4	[Unknown]	0x3e1f0
        rt_init	13.1%	0s	test	rt_init(void)	rt_lifecycle.cpp	0x47940
          GC_register_finalizer_no_order	11.4%	0s	test	GC_register_finalizer_no_order	finalize.c	0x6a4d00
          GC_malloc	1.5%	0s	test	GC_malloc	malloc.c	0x6a92b0
          py::initialize_types	0.2%	0s	test	py::initialize_types(void)	builtinTypeInit.cpp	0xea380
  __clone3	4.7%	0s	libc.so.6	__clone3	clone3.S	0x129c40