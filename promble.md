Function Stack	CPU Time: Total	CPU Time: Self	Module	Function (Full)	Source File	Start Address
Total	100.0%	0s	[Unknown]	[Unknown]	[Unknown]	[Unknown]
  _start	94.7%	0s	test	_start	[Unknown]	0x3d8e0
    __libc_start_main_impl	94.7%	0s	libc.so.6	__libc_start_main_impl	libc-start.c	0x2a200
      main	94.7%	0s	test	main	[Unknown]	0x40db0
        PyInit_test	94.1%	0s	test	PyInit_test	[Unknown]	0x3d9d0
          rt_call_raw_ptrs	94.1%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46800
            py::PyNativeFunction::call_fast_ptrs	94.1%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
              test.<module>.0:0.run_stress_test.141:0	94.1%	0s	test	test.<module>.0:0.run_stress_test.141:0	[Unknown]	0x3ff70
                rt_call_raw_ptrs	94.1%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46800
                  py::PyNativeFunction::call_fast_ptrs	94.1%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                    test.<module>.0:0.find.84:0	94.1%	0s	test	test.<module>.0:0.find.84:0	[Unknown]	0x3f250
                      rt_call_method_ic_ptrs	60.2%	0.088s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x51d40
                        py::PyNativeFunction::call_fast_ptrs	52.1%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                          test.<module>.0:0.Sieve.8:0.calc.64:4	40.6%	0s	test	test.<module>.0:0.Sieve.8:0.calc.64:4	[Unknown]	0x3edf0
                            rt_call_method_ic_ptrs	40.6%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x51d40
                              py::PyNativeFunction::call_fast_ptrs	40.6%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                                test.<module>.0:0.Sieve.8:0.loop_x.56:4	39.9%	0s	test	test.<module>.0:0.Sieve.8:0.loop_x.56:4	[Unknown]	0x3ec70
                                  rt_call_method_ic_ptrs	39.9%	0s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x51d40
                                    py::PyNativeFunction::call_fast_ptrs	39.9%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                                      test.<module>.0:0.Sieve.8:0.loop_y.48:4	39.9%	0.161s	test	test.<module>.0:0.Sieve.8:0.loop_y.48:4	[Unknown]	0x3eae0
                                        rt_call_method_ic_ptrs	34.8%	4.742s	test	rt_call_method_ic_ptrs(py::cache::MethodCache*, py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_method_cache.cpp	0x51d40
                                          py::PyNativeFunction::call_fast_ptrs	27.1%	1.291s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                                            test.<module>.0:0.Sieve.8:0.step1.33:4	9.9%	0.485s	test	test.<module>.0:0.Sieve.8:0.step1.33:4	[Unknown]	0x3e500
                                              rt_getattr_ic	2.3%	1.414s	test	rt_getattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x4ff10
                                              rt_compare_le	2.2%	0.043s	test	rt_compare_le(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x41ef0
                                              rt_getitem	1.4%	1.514s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4e630
                                              rt_is_true	1.1%	0.044s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42b00
                                              rt_binary_mul	0.8%	0.392s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b2c0
                                              rt_binary_add	0.4%	0.247s	test	rt_binary_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4afa0
                                              rt_binary_mod	0.3%	0.310s	test	rt_binary_mod(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b760
                                              py::RtValue::compare_eq	0.2%	0.252s	test	py::RtValue::compare_eq(py::RtValue, py::RtValue)	RtValue.cpp	0x544a0
                                              py::RtValue::from_int_or_box	0.2%	0.214s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x52c20
                                              py::RtValue::compare_le	0.1%	0.107s	test	py::RtValue::compare_le(py::RtValue, py::RtValue)	RtValue.cpp	0x54d00
                                              rt_setitem	0.1%	0.052s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4eeb0
                                              rt_integer_from_i64	0.1%	0.109s	test	rt_integer_from_i64(long)	rt_create.cpp	0x437a0
                                              rt_compare_eq	0.1%	0.055s	test	rt_compare_eq(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x41e60
                                              rt_value_array_get	0.1%	0.086s	test	rt_value_array_get(py::PyObject**, int)	rt_func.cpp	0x46040
                                              rt_unary_not	0.0%	0.012s	test	rt_unary_not(py::PyObject*)	rt_op.cpp	0x4c550
                                              rt_none	0.0%	0.019s	test	rt_none(void)	rt_singleton.cpp	0x4df90
                                              py::py_none	0.0%	0.012s	test	py::py_none(void)	PyNone.cpp	0x17c860
                                            test.<module>.0:0.Sieve.8:0.step2.38:4	8.1%	0.280s	test	test.<module>.0:0.Sieve.8:0.step2.38:4	[Unknown]	0x3e730
                                              rt_getattr_ic	2.1%	1.411s	test	rt_getattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x4ff10
                                                py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>	0.7%	0.636s	test	py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>(std::variant<std::function<py::PyResult<py::PyObject*> (py::PyObject const*)>, py::PyObject*> const&)	PyObject.hpp	0x262130
                                                py::RtValue::box	0.1%	0.093s	test	py::RtValue::box(void) const	RtValue.cpp	0x52a00
                                                py::types::object	0.0%	0.056s	test	py::types::object(void)	builtin.cpp	0xd77f0
                                                py::PyType::global_version	0.0%	0.015s	test	py::PyType::global_version(void)	atomic_base.h	0x2005a0
                                              rt_compare_le	2.1%	0.027s	test	rt_compare_le(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x41ef0
                                                py::RtValue::flatten	2.1%	0.515s	test	py::RtValue::flatten(py::PyObject*)	RtValue.cpp	0x52ae0
                                                  py::PyInteger::as_big_int	1.5%	0.039s	test	py::PyInteger::as_big_int(void) const	PyInteger.cpp	0x1480a0
                                                    __gmpz_init_set	1.5%	0.170s	test	__gmpz_init_set	[Unknown]	0x5f9320
                                                  __gmpz_fits_slong_p	0.1%	0.094s	test	__gmpz_fits_slong_p	[Unknown]	0x5f8330
                                                  py::types::integer	0.0%	0.035s	test	py::types::integer(void)	builtin.cpp	0xd6730
                                                  __gmpz_get_si	0.0%	0.034s	test	__gmpz_get_si	[Unknown]	0x5f83c0
                                              rt_is_true	0.8%	0.052s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42b00
                                              rt_getitem	0.8%	0.863s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4e630
                                              rt_binary_mul	0.7%	0.321s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b2c0
                                              rt_binary_add	0.4%	0.254s	test	rt_binary_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4afa0
                                              rt_binary_mod	0.3%	0.279s	test	rt_binary_mod(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b760
                                              py::RtValue::compare_le	0.2%	0.179s	test	py::RtValue::compare_le(py::RtValue, py::RtValue)	RtValue.cpp	0x54d00
                                              py::RtValue::from_int_or_box	0.1%	0.158s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x52c20
                                              py::RtValue::compare_eq	0.1%	0.120s	test	py::RtValue::compare_eq(py::RtValue, py::RtValue)	RtValue.cpp	0x544a0
                                              rt_compare_eq	0.1%	0.024s	test	rt_compare_eq(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x41e60
                                              rt_value_array_get	0.1%	0.079s	test	rt_value_array_get(py::PyObject**, int)	rt_func.cpp	0x46040
                                              rt_setitem	0.0%	0s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4eeb0
                                              rt_none	0.0%	0.020s	test	rt_none(void)	rt_singleton.cpp	0x4df90
                                              rt_integer_from_i64	0.0%	0.012s	test	rt_integer_from_i64(long)	rt_create.cpp	0x437a0
                                              rt_unary_not	0.0%	0s	test	rt_unary_not(py::PyObject*)	rt_op.cpp	0x4c550
                                            test.<module>.0:0.Sieve.8:0.step3.43:4	5.8%	0.155s	test	test.<module>.0:0.Sieve.8:0.step3.43:4	[Unknown]	0x3e8f0
                                            spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>	1.0%	0.472s	test	spdlog::logger::log_<fmt::v7::basic_string_view<char>, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&, unsigned long&, bool, bool>(spdlog::source_loc, spdlog::level::level_enum, fmt::v7::basic_string_view<char> const&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&&&)	logger.h	0x3b85c0
                                            spdlog::default_logger_raw	0.9%	0.076s	test	spdlog::default_logger_raw(void)	spdlog-inl.h	0x56e570
                                            __memset_avx2_unaligned_erms	0.3%	0.295s	libc.so.6	__memset_avx2_unaligned_erms	memset-vec-unaligned-erms.S	0x189480
                                            func@0x39570	0.0%	0.042s	test	func@0x39570	[Unknown]	0x39570
                                          py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>	1.9%	1.350s	test	py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>(std::variant<std::function<py::PyResult<py::PyObject*> (py::PyObject const*)>, py::PyObject*> const&)	PyObject.hpp	0x262130
                                          _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	1.3%	1.448s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                                          __memmove_avx_unaligned_erms	0.1%	0.163s	libc.so.6	__memmove_avx_unaligned_erms	memmove-vec-unaligned-erms.S	0x188a80
                                          py::RtValue::box	0.1%	0.162s	test	py::RtValue::box(void) const	RtValue.cpp	0x52a00
                                          py::types::object	0.1%	0.086s	test	py::types::object(void)	builtin.cpp	0xd77f0
                                          func@0x39130	0.0%	0.051s	test	func@0x39130	[Unknown]	0x39130
                                          py::PyType::global_version	0.0%	0.039s	test	py::PyType::global_version(void)	atomic_base.h	0x2005a0
                                        rt_compare_lt	1.7%	0.057s	test	rt_compare_lt(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x41ec0
                                        rt_getattr_ic	1.6%	0.917s	test	rt_getattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x4ff10
                                        rt_inplace_add	0.7%	0.293s	test	rt_inplace_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4c590
                                        rt_is_true	0.3%	0.007s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42b00
                                        rt_binary_mul	0.3%	0.199s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b2c0
                                        py::RtValue::compare_lt	0.2%	0.220s	test	py::RtValue::compare_lt(py::RtValue, py::RtValue)	RtValue.cpp	0x54ac0
                                        py::RtValue::from_int_or_box	0.1%	0.116s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x52c20
                                  rt_inplace_add	0.0%	0s	test	rt_inplace_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4c590
                                test.<module>.0:0.Sieve.8:0.omit_squares.22:4	0.7%	0s	test	test.<module>.0:0.Sieve.8:0.omit_squares.22:4	[Unknown]	0x3e350
                          test.<module>.0:0.Sieve.8:0.to_list.14:4	11.6%	0.105s	test	test.<module>.0:0.Sieve.8:0.to_list.14:4	[Unknown]	0x3e0e0
                        rt_call_method_raw_ptrs	7.9%	0.044s	test	rt_call_method_raw_ptrs(py::PyObject*, char const*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46950
                        py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>	0.0%	0.008s	test	py::get_address<py::PyResult<py::PyObject*>, py::PyObject const*, py::PyObject*>(std::variant<std::function<py::PyResult<py::PyObject*> (py::PyObject const*)>, py::PyObject*> const&)	PyObject.hpp	0x262130
                      rt_call_raw_ptrs	32.0%	0s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46800
                        py::PyNativeFunction::call_fast_ptrs	27.2%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                          test.<module>.0:0.generate_trie.70:0	27.2%	0.155s	test	test.<module>.0:0.generate_trie.70:0	[Unknown]	0x3eef0
                            rt_call_raw_ptrs	15.5%	0.127s	test	rt_call_raw_ptrs(py::PyObject*, py::PyObject**, int, py::PyObject*)	rt_func.cpp	0x46800
                              py::PyType::call_fast_ptrs	15.2%	0.266s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x189d50
                                py::PyObject::init_fast_ptrs	8.4%	0.064s	test	py::PyObject::init_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x18b030
                                  py::PyNativeFunction::call_fast_ptrs	3.6%	0.051s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                                  py::PyObject::lookup_attribute	2.8%	0.110s	test	py::PyObject::lookup_attribute(py::PyObject*) const	PyObject.cpp	0x18b3b0
                                  py::PySlotWrapper::call_fast_ptrs	1.4%	0.128s	test	py::PySlotWrapper::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PySlotWrapper.cpp	0x1c6370
                                  py::PyString::intern	0.4%	0.016s	test	py::PyString::intern(char const*)	PyString.cpp	0x1c8a40
                                  _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.1%	0.120s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                                  func@0x39130	0.0%	0.012s	test	func@0x39130	[Unknown]	0x39130
                                py::PyType::new_	3.7%	0.093s	test	py::PyType::new_(py::PyTuple*, py::PyDict*) const	PyType.cpp	0x244660
                                  py::PyString::__new__	3.6%	0.450s	test	py::PyString::__new__(py::PyType const*, py::PyTuple*, py::PyDict*)	PyString.cpp	0x1ca600
                                    py::PyString::create	3.0%	0.032s	test	py::PyString::create(py::PyObject*)	PyString.cpp	0x1ca190
                                      py::PyObject::str	3.0%	0.019s	test	py::PyObject::str(void)	PyObject.cpp	0x19c2a0
                                        _ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEES5_EES6_JS5_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINS9_6OkTypeES5_E	2.9%	0.027s	test	_ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEES5_EES6_JS5_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINS9_6OkTypeES5_E	PyObject.cpp	0x19c7d0
                                          py::PyObject::__str__	2.9%	0.028s	test	py::PyObject::__str__(void)	PyObject.cpp	0x1941a0
                                            py::PyObject::repr	2.8%	0.027s	test	py::PyObject::repr(void) const	PyObject.cpp	0x194330
                                              _ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEEPKS4_EES6_JS8_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINSB_6OkTypeES5_E	2.7%	0.008s	test	_ZN2py12_GLOBAL__N_19call_slotISt8functionIFNS_8PyResultIPNS_8PyObjectEEEPKS4_EES6_JS8_EEET0_RKSt7variantIJT_S5_EEDpOT1_Qsr3stdE9is_same_vINSB_6OkTypeES5_E	PyObject.cpp	0x194b50
                                                py::PyNumber::__repr__	2.6%	0.009s	test	py::PyNumber::__repr__(void) const	PyNumber.cpp	0x17cb90
                                                  py::PyString::create	2.1%	0s	test	py::PyString::create(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&&)	PyString.cpp	0x1ca140
                                                    py::PyString::intern	2.1%	0.012s	test	py::PyString::intern(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>&&)	PyString.cpp	0x1c9670
                                                      std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find	1.8%	2.111s	test	std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find(std::basic_string_view<char, std::char_traits<char>> const&)	hashtable.h	0x414bc0
                                                      std::__detail::_Map_base<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>, (bool)1>::operator[]	0.1%	0.083s	test	std::__detail::_Map_base<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>, (bool)1>::operator[](std::basic_string_view<char, std::char_traits<char>>&&)	hashtable_policy.h	0x4150d0
                                                      ___pthread_mutex_lock	0.1%	0.078s	libc.so.6	___pthread_mutex_lock	pthread_mutex_lock.c	0x9fff0
                                                      ___pthread_mutex_unlock	0.0%	0.055s	libc.so.6	___pthread_mutex_unlock	pthread_mutex_unlock.c	0xa1a70
                                                      GC_malloc_atomic	0.0%	0s	test	GC_malloc_atomic	malloc.c	0x6af0d0
                                                      _pylang_debug_log_alloc	0.0%	0s	test	_pylang_debug_log_alloc(char const*, std::atomic<unsigned long>&)	compat.hpp	0x259ba0
                                                      GC_register_finalizer_no_order	0.0%	0s	test	GC_register_finalizer_no_order	finalize.c	0x6aab40
                                                  py::PyNumber::to_string[abi:cxx11]	0.5%	0s	test	py::PyNumber::to_string[abi:cxx11](void) const	PyNumber.cpp	0x17ca70
                                                  py::PyResult<py::PyObject*>::PyResult<py::PyString*>	0.0%	0.011s	test	py::PyResult<py::PyObject*>::PyResult<py::PyString*>(py::PyResult<py::PyString*> const&)	Value.hpp	0x26e740
                                              _ZNKR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.0%	0.050s	test	_ZNKR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x265680
                                              py::PyObject::type_prototype	0.0%	0.039s	test	py::PyObject::type_prototype(void) const	PyObject.cpp	0x187d50
                                              py::as<py::PyString>	0.0%	0.020s	test	py::as<py::PyString>(py::PyObject*)	PyString.cpp	0x1c9a70
                                            py::PyResult<py::PyObject*>::PyResult<py::PyString*>	0.1%	0.058s	test	py::PyResult<py::PyObject*>::PyResult<py::PyString*>(py::PyResult<py::PyString*> const&)	Value.hpp	0x26e740
                                        _ZNKR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.1%	0.067s	test	_ZNKR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x265680
                                        py::PyObject::type_prototype	0.0%	0.023s	test	py::PyObject::type_prototype(void) const	PyObject.cpp	0x187d50
                                    py::PyType::issubclass	0.1%	0.089s	test	py::PyType::issubclass(py::PyType const*) const	PyType.cpp	0x2301f0
                                    py::PyResult<py::PyObject*>::PyResult<py::PyString*>	0.1%	0.022s	test	py::PyResult<py::PyObject*>::PyResult<py::PyString*>(py::PyResult<py::PyString*> const&)	Value.hpp	0x26e740
                                    py::types::str	0.0%	0.020s	test	py::types::str(void)	builtin.cpp	0xd5aa0
                                  std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*), py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*)*>::_M_manager	0.0%	0.024s	test	std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*), py::PyResult<py::PyObject*> (py::PyType const*, py::PyTuple*, py::PyDict*)*>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)	std_function.h	0x28e780
                                  func@0x39570	0.0%	0.008s	test	func@0x39570	[Unknown]	0x39570
                                py::PyType::heap_object_allocation	2.1%	0.208s	test	py::PyType::heap_object_allocation(py::PyType*)	PyType.cpp	0x23f660
                                py::PyTuple::create	0.5%	0.039s	test	py::PyTuple::create(std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>&&)	PyTuple.cpp	0x1f9ca0
                                py::get_address<py::PyResult<py::PyObject*>, py::PyType const*, py::PyTuple*, py::PyDict*>	0.2%	0.117s	test	py::get_address<py::PyResult<py::PyObject*>, py::PyType const*, py::PyTuple*, py::PyDict*>(std::variant<std::function<py::PyResult<py::PyObject*> (py::PyType const*)>, py::PyObject*> const&)	PyObject.hpp	0x3f1130
                                std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::reserve	0.1%	0.012s	test	std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::reserve(unsigned long)	vector.tcc	0x38ac70
                                _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.1%	0.070s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                                _ZNR2py8PyResultIPNS_7PyTupleEE6unwrapEv	0.0%	0.023s	test	_ZNR2py8PyResultIPNS_7PyTupleEE6unwrapEv	Value.hpp	0x2598c0
                                std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType*), py::PyResult<py::PyObject*> (py::PyType*)*>::_M_invoke	0.0%	0.017s	test	std::_Function_handler<py::PyResult<py::PyObject*> (py::PyType*), py::PyResult<py::PyObject*> (py::PyType*)*>::_M_invoke(std::_Any_data const&, py::PyType*&&)	invoke.h	0x492a10
                                py::PyType::issubclass	0.0%	0.012s	test	py::PyType::issubclass(py::PyType const*) const	PyType.cpp	0x2301f0
                              _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.1%	0.124s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                              py::RtValue::box	0.0%	0.023s	test	py::RtValue::box(void) const	RtValue.cpp	0x52a00
                            rt_iter_next	2.3%	0.165s	test	rt_iter_next(py::PyObject*, bool*)	rt_subscr.cpp	0x4e0c0
                              py::PyStringIterator::next_raw	2.0%	0.326s	test	py::PyStringIterator::next_raw(void)	PyString.cpp	0x1f3460
                                py::PyString::intern	1.5%	0.086s	test	py::PyString::intern(char const*)	PyString.cpp	0x1c8a40
                                  std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find	0.9%	1.061s	test	std::_Hashtable<std::basic_string_view<char, std::char_traits<char>>, std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>, std::allocator<std::pair<std::basic_string_view<char, std::char_traits<char>> const, py::PyString*>>, std::__detail::_Select1st, std::equal_to<std::basic_string_view<char, std::char_traits<char>>>, std::hash<std::basic_string_view<char, std::char_traits<char>>>, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<(bool)1, (bool)0, (bool)1>>::find(std::basic_string_view<char, std::char_traits<char>> const&)	hashtable.h	0x414bc0
                                  ___pthread_mutex_unlock	0.2%	0.284s	libc.so.6	___pthread_mutex_unlock	pthread_mutex_unlock.c	0xa1a70
                                  ___pthread_mutex_lock	0.2%	0.229s	libc.so.6	___pthread_mutex_lock	pthread_mutex_lock.c	0x9fff0
                                  func@0x39410	0.0%	0.024s	test	func@0x39410	[Unknown]	0x39410
                                  func@0x394c0	0.0%	0.012s	test	func@0x394c0	[Unknown]	0x394c0
                                  __strlen_avx2	0.0%	0.008s	libc.so.6	__strlen_avx2	strlen-avx2.S	0x18b7c0
                                _ZNR2py8PyResultIPNS_8PyStringEE6unwrapEv	0.2%	0.180s	test	_ZNR2py8PyResultIPNS_8PyStringEE6unwrapEv	Value.hpp	0x2594e0
                              py::PyObject::next	0.1%	0.012s	test	py::PyObject::next(void)	PyObject.cpp	0x1a3380
                              py::RtValue::box	0.1%	0.058s	test	py::RtValue::box(void) const	RtValue.cpp	0x52a00
                              _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.0%	0.040s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                              py::types::range_iterator	0.0%	0.023s	test	py::types::range_iterator(void)	builtin.cpp	0xdc780
                              py::types::str_iterator	0.0%	0.023s	test	py::types::str_iterator(void)	builtin.cpp	0xd5ed0
                            rt_load_global	1.9%	0.153s	test	rt_load_global(py::PyObject*, char const*)	rt_attr.cpp	0x40e50
                            rt_setitem	1.8%	0.047s	test	rt_setitem(py::PyObject*, py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4eeb0
                            rt_getattr_ic	1.7%	0.922s	test	rt_getattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x4ff10
                            rt_get_iter	1.5%	0.031s	test	rt_get_iter(py::PyObject*)	rt_subscr.cpp	0x4dfe0
                            rt_compare_not_in	1.3%	1.081s	test	rt_compare_not_in(py::PyObject*, py::PyObject*)	rt_cmp.cpp	0x42560
                            rt_getitem	0.8%	0.715s	test	rt_getitem(py::PyObject*, py::PyObject*)	rt_subscr.cpp	0x4e630
                            rt_is_true	0.2%	0.016s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42b00
                            rt_setattr_ic	0.1%	0.048s	test	rt_setattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x51010
                            rt_true	0.0%	0.007s	test	rt_true(void)	rt_singleton.cpp	0x4dfa0
                        py::PyType::call_fast_ptrs	4.8%	0s	test	py::PyType::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x189d50
                          py::PyObject::init_fast_ptrs	4.5%	0s	test	py::PyObject::init_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyObject.cpp	0x18b030
                            py::PyNativeFunction::call_fast_ptrs	4.4%	0s	test	py::PyNativeFunction::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PyFunction.cpp	0x13cf90
                              test.<module>.0:0.Sieve.8:0.__init__.9:4	4.4%	0s	test	test.<module>.0:0.Sieve.8:0.__init__.9:4	[Unknown]	0x3dfb0
                                rt_binary_mul	4.4%	0s	test	rt_binary_mul(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4b2c0
                                  py::PyObject::multiply	4.4%	0s	test	py::PyObject::multiply(py::PyObject const*) const	PyObject.cpp	0x19e750
                                    py::PySequenceWrapper::repeat	4.4%	0s	test	py::PySequenceWrapper::repeat(py::PyObject const*)	PyObject.cpp	0x18fa00
                                      py::PyList::__mul__	4.4%	0.036s	test	py::PyList::__mul__(unsigned long) const	PyList.cpp	0x157cb0
                                        py::PyList::create	3.9%	0s	test	py::PyList::create(std::vector<py::RtValue, std::allocator<py::RtValue>>)	PyList.cpp	0x1501e0
                                          py::Arena::allocate<py::PyList, std::vector<py::RtValue, std::allocator<py::RtValue>>>	3.9%	0s	test	py::Arena::allocate<py::PyList, std::vector<py::RtValue, std::allocator<py::RtValue>>>(std::vector<py::RtValue, std::allocator<py::RtValue>>&&)	Arena.hpp	0x3ce6e0
                                            std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::_M_assign_aux<std::move_iterator<__gnu_cxx::__normal_iterator<py::RtValue*, std::vector<py::RtValue, std::allocator<py::RtValue>>>>>	3.9%	0.012s	test	std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::_M_assign_aux<std::move_iterator<__gnu_cxx::__normal_iterator<py::RtValue*, std::vector<py::RtValue, std::allocator<py::RtValue>>>>>(std::move_iterator<__gnu_cxx::__normal_iterator<py::RtValue*, std::vector<py::RtValue, std::allocator<py::RtValue>>>>, std::move_iterator<__gnu_cxx::__normal_iterator<py::RtValue*, std::vector<py::RtValue, std::allocator<py::RtValue>>>>, std::forward_iterator_tag)	vector.tcc	0x3ce470
                                              GC_malloc	3.9%	0s	test	GC_malloc	malloc.c	0x6af0f0
                                            __GI___libc_free	0.0%	0.016s	libc.so.6	__GI___libc_free	malloc.c	0xadd50
                                        std::vector<py::RtValue, std::allocator<py::RtValue>>::_M_range_insert<__gnu_cxx::__normal_iterator<py::RtValue const*, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>	0.5%	0.531s	test	std::vector<py::RtValue, std::allocator<py::RtValue>>::_M_range_insert<__gnu_cxx::__normal_iterator<py::RtValue const*, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>(__gnu_cxx::__normal_iterator<py::RtValue*, std::vector<py::RtValue, std::allocator<py::RtValue>>>, __gnu_cxx::__normal_iterator<py::RtValue const*, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>, __gnu_cxx::__normal_iterator<py::RtValue const*, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>, std::forward_iterator_tag)	vector.tcc	0x38c350
                            py::PyObject::lookup_attribute	0.1%	0s	test	py::PyObject::lookup_attribute(py::PyObject*) const	PyObject.cpp	0x18b3b0
                            py::PySlotWrapper::call_fast_ptrs	0.0%	0.012s	test	py::PySlotWrapper::call_fast_ptrs(py::PyObject**, unsigned long, py::PyDict*)	PySlotWrapper.cpp	0x1c6370
                            py::PyString::intern	0.0%	0s	test	py::PyString::intern(char const*)	PyString.cpp	0x1c8a40
                          py::PyType::new_	0.2%	0s	test	py::PyType::new_(py::PyTuple*, py::PyDict*) const	PyType.cpp	0x244660
                          py::PyTuple::create	0.0%	0.011s	test	py::PyTuple::create(std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>&&)	PyTuple.cpp	0x1f9ca0
                          std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::reserve	0.0%	0s	test	std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::reserve(unsigned long)	vector.tcc	0x38ac70
                          _ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	0.0%	0.008s	test	_ZNR2py8PyResultIPNS_8PyObjectEE6unwrapEv	Value.hpp	0x258f30
                          _ZNR2py8PyResultIPNS_7PyTupleEE6unwrapEv	0.0%	0.008s	test	_ZNR2py8PyResultIPNS_7PyTupleEE6unwrapEv	Value.hpp	0x2598c0
                      rt_unpack_sequence	0.6%	0.011s	test	rt_unpack_sequence(py::PyObject*, int, py::PyObject**)	rt_subscr.cpp	0x4e450
                      rt_binary_add	0.4%	0s	test	rt_binary_add(py::PyObject*, py::PyObject*)	rt_op.cpp	0x4afa0
                      rt_get_iter	0.2%	0.008s	test	rt_get_iter(py::PyObject*)	rt_subscr.cpp	0x4dfe0
                      rt_iter_next	0.2%	0.011s	test	rt_iter_next(py::PyObject*, bool*)	rt_subscr.cpp	0x4e0c0
                      rt_build_tuple	0.1%	0s	test	rt_build_tuple(int, py::PyObject**)	rt_create.cpp	0x42fd0
                      rt_getattr_ic	0.1%	0.071s	test	rt_getattr_ic(py::cache::AttrCache*, py::PyObject*, py::PyObject*)	rt_attr_cache.cpp	0x4ff10
                      rt_load_global	0.1%	0.012s	test	rt_load_global(py::PyObject*, char const*)	rt_attr.cpp	0x40e50
                      rt_is_true	0.1%	0s	test	rt_is_true(py::PyObject*)	rt_convert.cpp	0x42b00
                      py::RtValue::from_int_or_box	0.0%	0.008s	test	py::RtValue::from_int_or_box(long)	RtValue.cpp	0x52c20
        rt_init	0.6%	0.008s	test	rt_init(void)	rt_lifecycle.cpp	0x47ad0