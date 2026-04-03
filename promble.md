Function Stack	CPU Time: Total	CPU Time: Self	Module	Function (Full)	Source File	Start Address
Total	100.0%	0s	[Unknown]	[Unknown]	[Unknown]	[Unknown]
  _start	94.4%	0s	test	_start	[Unknown]	0x3e8e0
    __libc_start_main_impl	94.4%	0s	libc.so.6	__libc_start_main_impl	libc-start.c	0x2a200
      main	94.4%	0s	test	main	[Unknown]	0x412e0
        PyInit_test	80.4%	0s	test	PyInit_test	[Unknown]	0x3e9d0
          rt_call_raw_ptrs	80.4%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x468e0
            py::PyNativeFunction::call_fast_ptrs	80.4%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
              test.<module>.0:0.find.86:0	80.4%	0s	test	test.<module>.0:0.find.86:0	[Unknown]	0x402d0
                rt_call_raw_ptrs	44.5%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x468e0
                  py::PyNativeFunction::call_fast_ptrs	43.7%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                    test.<module>.0:0.generate_trie.71:0	43.7%	0s	test	test.<module>.0:0.generate_trie.71:0	[Unknown]	0x3ff90
                      rt_call_raw_ptrs	31.6%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x468e0
                        py::PyType::call_fast_ptrs	31.6%	0.012s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x1b71b0
                          py::PyObject::init_fast_ptrs	18.3%	0s	test	py::PyObject::init_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x1b7e70
                            py::PyNativeFunction::call_fast_ptrs	14.7%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                            py::PyObject::lookup_attribute	1.9%	0s	test	py::PyObject::lookup_attribute(py::PyObject*) const	PyObject.cpp	0x1b8330
                            py::PySlotWrapper::call_fast_ptrs	1.2%	0s	test	py::PySlotWrapper::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PySlotWrapper.cpp	0x2009d0
                            py::PyString::intern	0.5%	0s	test	py::PyString::intern(char const*)	PyString.cpp	0x203710
                          py::PyType::new_	13.0%	0.050s	test	py::PyType::new_(py::PyTuple*, py::PyDict*) const	PyType.cpp	0x28d2e0
                            py::PyString::__new__	8.2%	0s	test	py::PyString::__new__(py::PyType const*, py::PyTuple*, py::PyDict*)	PyString.cpp	0x2059f0
                              py::PyString::create	7.9%	0s	test	py::PyString::create(py::PyObject*)	PyString.cpp	0x2049b0
                                py::PyObject::str	7.9%	0.012s	test	py::PyObject::str(void)	PyObject.cpp	0x1cdc10
                                  _ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEES5_EES6_JS5_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINS9_6OkTypeES5_E	7.6%	0s	test	_ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEES5_EES6_JS5_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINS9_6OkTypeES5_E	PyObject.cpp	0x1ce260
                              py::PyType::issubclass	0.4%	0.008s	test	py::PyType::issubclass(py::PyType const*) const	PyType.cpp	0x274ce0
                            py::PyObject::__new__	3.4%	0.017s	test	py::PyObject::__new__(py::PyType const*, py::PyTuple*, py::PyDict*)	PyObject.cpp	0x1e4110
                              py::PyType::heap_object_allocation	3.1%	0.016s	test	py::PyType::heap_object_allocation(py::PyType*)	PyType.cpp	0x2874d0
                            std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*), py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*)*>::_M_manager	0.5%	0.024s	test	std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*), py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*)*>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)	std_function.h	0x2e2e50
                          py::PyTuple::create	0.2%	0s	test	py::PyTuple::create(std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>&&)	PyTuple.cpp	0x23ac10
                      rt_iter_next	4.2%	0s	test	rt_iter_next(py::PyObject*, bool*)	rt_subscr.cpp	0x4c0f0
                        py::PyStringIterator::next_raw	2.5%	0s	test	py::PyStringIterator::next_raw(void)	PyString.cpp	0x233b70
                          py::PyString::intern	2.5%	0.021s	test	py::PyString::intern(char const*)	PyString.cpp	0x203710
                            std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find	1.7%	0.091s	test	std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find(std::basic_string_view<char, std::char_traits<char>> const&)	hashtable.h	0x481210
                            __strlen_avx2	0.2%	0.012s	libc.so.6	__strlen_avx2	strlen-avx2.S	0x18b7c0
                            ___pthread_mutex_unlock	0.2%	0.012s	libc.so.6	___pthread_mutex_unlock	pthread_mutex_unlock.c	0xa1a70
                        py::PyObject::next	1.7%	0s	test	py::PyObject::next(void)	PyObject.cpp	0x1d6780
                      rt_load_global	2.4%	0.012s	test	rt_load_global(py::PyObject*, char const*)	rt_attr.cpp	0x41df0
                        py::PyModule::find_symbol_cstr	1.4%	0.008s	test	py::PyModule::find_symbol_cstr(char const*) const	PyModule.cpp	0x1a55d0
                        py::ModuleRegistry::find	0.8%	0s	test	py::ModuleRegistry::find(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>> const&) const	ModuleRegistry.cpp	0x11b760
                      rt_get_iter	1.2%	0s	test	rt_get_iter(py::PyObject*)	rt_subscr.cpp	0x4c0c0
                      rt_compare_not_in	1.0%	0.053s	test	rt_compare_not_in(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x43860
                      rt_getattr_fast	1.0%	0.053s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x41b00
                      rt_setitem	0.9%	0s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4cef0
                      rt_getitem	0.6%	0.033s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4c790
                      rt_setattr_fast	0.5%	0s	test	rt_setattr_fast(py::PyObject*, py::PyObject*, py::PyObject*)	rt_attr.cpp	0x42a70
                      rt_is_true	0.2%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x43cf0
                  py::PyType::call_fast_ptrs	0.8%	0s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x1b71b0
                rt_call_method_ic_ptrs	35.9%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4dc80
                  py::PyNativeFunction::call_fast_ptrs	35.9%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                    test.<module>.0:0.Sieve.8:0.calc.64:4	32.6%	0s	test	test.<module>.0:0.Sieve.8:0.calc.64:4	[Unknown]	0x3fe90
                      rt_call_method_ic_ptrs	32.6%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4dc80
                        py::PyNativeFunction::call_fast_ptrs	32.6%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                          test.<module>.0:0.Sieve.8:0.loop_x.56:4	32.2%	0s	test	test.<module>.0:0.Sieve.8:0.loop_x.56:4	[Unknown]	0x3fd10
                            rt_call_method_ic_ptrs	32.2%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4dc80
                              py::PyNativeFunction::call_fast_ptrs	32.2%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                                test.<module>.0:0.Sieve.8:0.loop_y.48:4	32.2%	0.028s	test	test.<module>.0:0.Sieve.8:0.loop_y.48:4	[Unknown]	0x3fb80
                                  rt_call_method_ic_ptrs	27.1%	0.217s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x4dc80
                                    py::PyNativeFunction::call_fast_ptrs	22.1%	0.047s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x161950
                                      test.<module>.0:0.Sieve.8:0.step1.33:4	7.3%	0.008s	test	test.<module>.0:0.Sieve.8:0.step1.33:4	[Unknown]	0x3f5e0
                                        rt_getitem	2.0%	0.095s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4c790
                                          py::RtValue::box	0.2%	0.012s	test	py::RtValue::box(void) const	RtValue.cpp	0x4e900
                                        rt_is_true	1.8%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x43cf0
                                          py::RtValue::flatten	1.5%	0.028s	test	py::RtValue::flatten(py::PyObject*)	RtValue.cpp	0x4ec20
                                          py::RtValue::is_truthy	0.2%	0.012s	test	py::RtValue::is_truthy(void) const	RtValue.cpp	0x50fa0
                                        rt_getattr_fast	1.0%	0.051s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x41b00
                                        py::RtValue::mul	0.7%	0.039s	test	py::RtValue::mul(py::RtValue, py::RtValue)	RtValue.cpp	0x4f320
                                        rt_binary_add	0.4%	0s	test	rt_binary_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4a730
                                        rt_compare_le	0.4%	0s	test	rt_compare_le(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x43300
                                        rt_binary_mul	0.3%	0s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4a790
                                        rt_setitem	0.2%	0.012s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4cef0
                                        py::RtValue::add	0.2%	0.012s	test	py::RtValue::add(py::RtValue, py::RtValue)	RtValue.cpp	0x4efc0
                                        rt_none	0.1%	0.008s	test	rt_none(void)	rt_singleton.cpp	0x4c070
                                        py::RtValue::mod	0.1%	0.008s	test	py::RtValue::mod(py::RtValue, py::RtValue)	RtValue.cpp	0x4f710
                                      test.<module>.0:0.Sieve.8:0.step2.38:4	6.0%	0.008s	test	test.<module>.0:0.Sieve.8:0.step2.38:4	[Unknown]	0x3f7f0
                                      test.<module>.0:0.Sieve.8:0.step3.43:4	5.6%	0.028s	test	test.<module>.0:0.Sieve.8:0.step3.43:4	[Unknown]	0x3f9a0
                                      spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>	1.8%	0.016s	test	spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>(spdlog::source_loc, spdlog::level::level_enum, fmt::v7::basic_string_view<char> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&&&)	logger.h	0x426140
                                      __memset_avx2_unaligned_erms	0.2%	0.012s	libc.so.6	__memset_avx2_unaligned_erms	memset-vec-unaligned-erms.S	0x189480
                                      func@0x3a570	0.2%	0.012s	test	func@0x3a570	[Unknown]	0x3a570
                                    rt_unwrap<py::PyObject*>	0.9%	0.047s	test	rt_unwrap<py::PyObject*>(py::PyResult<py::PyObject*>)	rt_common.hpp	0x2b1430
                                    func@0x3a130	0.1%	0.008s	test	func@0x3a130	[Unknown]	0x3a130
                                  rt_is_true	1.8%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x43cf0
                                  rt_compare_lt	1.1%	0s	test	rt_compare_lt(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x432d0
                                  rt_getattr_fast	0.4%	0.024s	test	rt_getattr_fast(py::PyObject*, py::PyObject*)	rt_attr.cpp	0x41b00
                                  py::RtValue::compare_lt	0.4%	0.012s	test	py::RtValue::compare_lt(py::RtValue, py::RtValue)	RtValue.cpp	0x50920
                                  py::RtValue::mul	0.4%	0.024s	test	py::RtValue::mul(py::RtValue, py::RtValue)	RtValue.cpp	0x4f320
                                  py::RtValue::from_int_or_box	0.2%	0.012s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x4ee60
                                  rt_binary_mul	0.2%	0s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4a790
                          test.<module>.0:0.Sieve.8:0.omit_squares.22:4	0.4%	0s	test	test.<module>.0:0.Sieve.8:0.omit_squares.22:4	[Unknown]	0x3f450
                    test.<module>.0:0.Sieve.8:0.to_list.14:4	3.3%	0.012s	test	test.<module>.0:0.Sieve.8:0.to_list.14:4	[Unknown]	0x3f1f0
        rt_init	14.1%	0s	test	rt_init(void)	rt_lifecycle.cpp	0x477a0
          GC_register_finalizer_no_order	12.3%	0.008s	test	GC_register_finalizer_no_order	finalize.c	0x722700