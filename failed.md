[main] 正在生成文件夹: /build/debug 
 正在启动生成
[proc] 正在执行命令: /home/lux/soft/cmake/bin/cmake --build /build/debug --config Debug --target all --
 [0/2] Re-checking globbed directories...
 [1/278] Building CXX object src/CMakeFiles/python-cpp.dir/ast/optimizers/ConstantFolding.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/ast/optimizers/ConstantFolding.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/ast/optimizers/ConstantFolding.cpp.o -MF src/CMakeFiles/python-cpp.dir/ast/optimizers/ConstantFolding.cpp.o.d -o src/CMakeFiles/python-cpp.dir/ast/optimizers/ConstantFolding.cpp.o -c /src/ast/optimizers/ConstantFolding.cpp
 In file included from /src/ast/optimizers/ConstantFolding.cpp:2:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:2:
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:2:
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:2:
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:2:
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:1:
 In file included from /src/ast/optimizers/ConstantFolding.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:1:
 In file included from /src/ast/optimizers/ConstantFolding.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:1326:23: error: incomplete type 'py::RtValue' used in type trait expression
  1326 |                     __bool_constant<__has_trivial_destructor(_Tp)>>::type
       |                                     ^
 include/c++/13/type_traits:3297:5: note: in instantiation of template class 'std::is_trivially_destructible<py::RtValue>' requested here
  3297 |     is_trivially_destructible<_Tp>::value;
       |     ^
 include/c++/13/variant:367:5: note: in instantiation of variable template specialization 'std::is_trivially_destructible_v<py::RtValue>' requested here
   367 |           (is_trivially_destructible_v<_Types> && ...);
       |            ^
 include/c++/13/variant:376:4: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_trivial_dtor' requested here
   376 |           _S_trivial_dtor && _S_trivial_move_ctor
       |           ^
 include/c++/13/variant:759:45: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_trivial_move_assign' requested here
   759 |       _Move_assign_base<_Traits<_Types...>::_S_trivial_move_assign, _Types...>;
       |                                             ^
 include/c++/13/variant:762:28: note: in instantiation of template type alias '_Move_assign_alias' requested here
   762 |     struct _Variant_base : _Move_assign_alias<_Types...>
       |                            ^
 include/c++/13/variant:1362:15: note: in instantiation of template class 'std::__detail::__variant::_Variant_base<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
  1362 |     : private __detail::__variant::_Variant_base<_Types...>,
       |               ^
 /src/ast/optimizers/ConstantFolding.cpp:7:55: note: in instantiation of template class 'std::variant<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
     7 |         std::variant<py::Value, std::shared_ptr<BinaryExpr>> evaluate_binary_expr(
       |                                                              ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:1:
 In file included from /src/ast/optimizers/ConstantFolding.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:1328:21: error: static assertion failed due to requirement 'std::__is_complete_or_unbounded(std::__type_identity<py::RtValue>{})': template argument must be a complete class or an unbounded array
  1328 |       static_assert(std::__is_complete_or_unbounded(__type_identity<_Tp>{}),
       |                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/type_traits:3282:7: error: incomplete type 'py::RtValue' used in type trait expression
  3282 |     = __is_trivially_constructible(_Tp, __add_rval_ref_t<_Tp>);
       |       ^
 include/c++/13/variant:371:5: note: in instantiation of variable template specialization 'std::is_trivially_move_constructible_v<py::RtValue>' requested here
   371 |           (is_trivially_move_constructible_v<_Types> && ...);
       |            ^
 include/c++/13/variant:376:23: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_trivial_move_ctor' requested here
   376 |           _S_trivial_dtor && _S_trivial_move_ctor
       |                              ^
 include/c++/13/variant:759:45: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_trivial_move_assign' requested here
   759 |       _Move_assign_base<_Traits<_Types...>::_S_trivial_move_assign, _Types...>;
       |                                             ^
 include/c++/13/variant:762:28: note: in instantiation of template type alias '_Move_assign_alias' requested here
   762 |     struct _Variant_base : _Move_assign_alias<_Types...>
       |                            ^
 include/c++/13/variant:1362:15: note: in instantiation of template class 'std::__detail::__variant::_Variant_base<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
  1362 |     : private __detail::__variant::_Variant_base<_Types...>,
       |               ^
 /src/ast/optimizers/ConstantFolding.cpp:7:55: note: in instantiation of template class 'std::variant<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
     7 |         std::variant<py::Value, std::shared_ptr<BinaryExpr>> evaluate_binary_expr(
       |                                                              ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:1:
 In file included from /src/ast/optimizers/ConstantFolding.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/variant:354:4: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   354 |           is_default_constructible_v<typename _Nth_type<0, _Types...>::type>;
       |           ^
 include/c++/13/variant:1364:43: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_default_ctor' requested here
  1364 |         __detail::__variant::_Traits<_Types...>::_S_default_ctor,
       |                                                  ^
 /src/ast/optimizers/ConstantFolding.cpp:7:55: note: in instantiation of template class 'std::variant<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
     7 |         std::variant<py::Value, std::shared_ptr<BinaryExpr>> evaluate_binary_expr(
       |                                                              ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/optimizers/ConstantFolding.cpp:1:
 In file included from /src/ast/optimizers/ConstantFolding.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:3254:7: error: incomplete type 'py::RtValue' used in type trait expression
  3254 |     = __is_constructible(_Tp, __add_lval_ref_t<const _Tp>);
       |       ^
 include/c++/13/variant:356:5: note: in instantiation of variable template specialization 'std::is_copy_constructible_v<py::RtValue>' requested here
   356 |           (is_copy_constructible_v<_Types> && ...);
       |            ^
 include/c++/13/variant:1367:43: note: in instantiation of static data member 'std::__detail::__variant::_Traits<py::RtValue, std::shared_ptr<ast::BinaryExpr>>::_S_copy_ctor' requested here
  1367 |         __detail::__variant::_Traits<_Types...>::_S_copy_ctor,
       |                                                  ^
 /src/ast/optimizers/ConstantFolding.cpp:7:55: note: in instantiation of template class 'std::variant<py::RtValue, std::shared_ptr<ast::BinaryExpr>>' requested here
     7 |         std::variant<py::Value, std::shared_ptr<BinaryExpr>> evaluate_binary_expr(
       |                                                              ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [2/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteName.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteName.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteName.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteName.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteName.cpp.o -c /src/executable/bytecode/instructions/DeleteName.cpp
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteName.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteName.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [3/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ForIter.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ForIter.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ForIter.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ForIter.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ForIter.cpp.o -c /src/executable/bytecode/instructions/ForIter.cpp
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ForIter.cpp:1:
 In file included from /src/executable/bytecode/instructions/ForIter.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [4/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteDeref.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteDeref.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteDeref.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteDeref.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteDeref.cpp.o -c /src/executable/bytecode/instructions/DeleteDeref.cpp
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteDeref.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteDeref.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [5/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinaryOperation.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinaryOperation.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinaryOperation.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinaryOperation.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinaryOperation.cpp.o -c /src/executable/bytecode/instructions/BinaryOperation.cpp
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinaryOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [6/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteAttr.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteAttr.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteAttr.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteAttr.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteAttr.cpp.o -c /src/executable/bytecode/instructions/DeleteAttr.cpp
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteAttr.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteAttr.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [7/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearExceptionState.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearExceptionState.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearExceptionState.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearExceptionState.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearExceptionState.cpp.o -c /src/executable/bytecode/instructions/ClearExceptionState.cpp
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearExceptionState.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [8/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteGlobal.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteGlobal.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteGlobal.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteGlobal.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteGlobal.cpp.o -c /src/executable/bytecode/instructions/DeleteGlobal.cpp
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteGlobal.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [9/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/BytecodeProgram.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/BytecodeProgram.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/BytecodeProgram.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/BytecodeProgram.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/BytecodeProgram.cpp.o -c /src/executable/bytecode/BytecodeProgram.cpp
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 /src/./executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/BytecodeProgram.cpp:1:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:14:
 In file included from /src/./lexer/Lexer.hpp:3:
 In file included from /src/./utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [10/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/Bytecode.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/Bytecode.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/Bytecode.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/Bytecode.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/Bytecode.cpp.o -c /src/executable/bytecode/Bytecode.cpp
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 /src/./executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/Bytecode.cpp:1:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:14:
 In file included from /src/./lexer/Lexer.hpp:3:
 In file included from /src/./utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [11/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCallEx.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCallEx.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCallEx.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCallEx.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCallEx.cpp.o -c /src/executable/bytecode/instructions/FunctionCallEx.cpp
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCallEx.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [12/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildDict.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildDict.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildDict.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildDict.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildDict.cpp.o -c /src/executable/bytecode/instructions/BuildDict.cpp
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildDict.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildDict.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [13/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictAdd.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictAdd.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictAdd.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictAdd.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictAdd.cpp.o -c /src/executable/bytecode/instructions/DictAdd.cpp
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictAdd.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictAdd.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [14/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildString.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildString.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildString.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildString.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildString.cpp.o -c /src/executable/bytecode/instructions/BuildString.cpp
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:54:
 In file included from include/c++/13/bits/basic_string.h:39:
 In file included from include/c++/13/ext/alloc_traits.h:34:
 include/c++/13/bits/alloc_traits.h:932:33: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   932 |       for (; __first != __last; ++__first)
       |                                 ^ ~~~~~~~
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<py::RtValue *, py::GCTracingAllocator<py::RtValue>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:370:35: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   370 |                       _M_impl._M_end_of_storage - _M_impl._M_start);
       |                       ~~~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:733:7: note: in instantiation of member function 'std::_Vector_base<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~_Vector_base' requested here
   733 |       ~vector() _GLIBCXX_NOEXCEPT
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:48:
 include/c++/13/bits/stl_iterator.h:1337:27: error: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1337 |     { return __lhs.base() - __rhs.base(); }
       |              ~~~~~~~~~~~~ ^
 include/c++/13/bits/ranges_base.h:363:54: note: in instantiation of function template specialization '__gnu_cxx::operator-<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' requested here
   363 |             return __detail::__to_unsigned_like(_End{}(__t) - _Begin{}(__t));
       |                                                             ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of function template specialization 'std::ranges::__cust_access::_Size::operator()<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of requirement here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^~~~~~~~~~~~~~~~~
 include/c++/13/bits/ranges_base.h:545:10: note: while substituting template arguments into constraint expression here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while checking the satisfaction of concept 'sized_range<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while substituting template arguments into constraint expression here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: while checking constraint satisfaction for template 'span<py::RtValue, 18446744073709551615UL>' required here
    37 |                 return PyTuple::create(const_cast<const py::GCVector<Value> &>(elements));
       |                                        ^~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: in instantiation of function template specialization 'std::span<py::RtValue>::span<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildString.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildString.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:43:
 include/c++/13/bits/stl_iterator_base_funcs.h:106:21: error: invalid operands to binary expression ('__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' and '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>')
   106 |       return __last - __first;
       |              ~~~~~~ ^ ~~~~~~~
 include/c++/13/bits/stl_iterator_base_funcs.h:151:19: note: in instantiation of function template specialization 'std::__distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   151 |       return std::__distance(__first, __last,
       |                   ^
 include/c++/13/bits/stl_vector.h:1690:31: note: in instantiation of function template specialization 'std::distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
  1690 |           const size_type __n = std::distance(__first, __last);
       |                                      ^
 include/c++/13/bits/stl_vector.h:711:4: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::_M_range_initialize<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   711 |           _M_range_initialize(__first, __last,
       |           ^
 /src/./runtime/PyTuple.hpp:43:23: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::vector<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>, void>' requested here
    43 |                 py::GCVector<Value> tmp(elements.begin(), elements.end());
       |                                     ^
 include/c++/13/bits/stl_iterator.h:625:5: note: candidate template ignored: could not match 'reverse_iterator' against '__gnu_cxx::__normal_iterator'
   625 |     operator-(const reverse_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1321:5: note: candidate template ignored: substitution failure [with _IteratorL = const py::RtValue *, _IteratorR = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1321 |     operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
       |     ^
  1322 |               const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
  1323 |     -> decltype(__lhs.base() - __rhs.base())
       |                              ~
 include/c++/13/bits/stl_iterator.h:1334:5: note: candidate template ignored: substitution failure [with _Iterator = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]
  1334 |     operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
       |     ^
 include/c++/13/bits/stl_iterator.h:1800:5: note: candidate template ignored: could not match 'move_iterator' against '__gnu_cxx::__normal_iterator'
  1800 |     operator-(const move_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1157:7: note: candidate function not viable: no known conversion from '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' to 'difference_type' (aka 'long') for 1st argument
  1157 |       operator-(difference_type __n) const _GLIBCXX_NOEXCEPT
       |       ^         ~~~~~~~~~~~~~~~~~~~
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [15/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FormatValue.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FormatValue.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FormatValue.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FormatValue.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FormatValue.cpp.o -c /src/executable/bytecode/instructions/FormatValue.cpp
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:54:
 In file included from include/c++/13/bits/basic_string.h:39:
 In file included from include/c++/13/ext/alloc_traits.h:34:
 include/c++/13/bits/alloc_traits.h:932:33: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   932 |       for (; __first != __last; ++__first)
       |                                 ^ ~~~~~~~
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<py::RtValue *, py::GCTracingAllocator<py::RtValue>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:370:35: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   370 |                       _M_impl._M_end_of_storage - _M_impl._M_start);
       |                       ~~~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:733:7: note: in instantiation of member function 'std::_Vector_base<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~_Vector_base' requested here
   733 |       ~vector() _GLIBCXX_NOEXCEPT
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:48:
 include/c++/13/bits/stl_iterator.h:1337:27: error: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1337 |     { return __lhs.base() - __rhs.base(); }
       |              ~~~~~~~~~~~~ ^
 include/c++/13/bits/ranges_base.h:363:54: note: in instantiation of function template specialization '__gnu_cxx::operator-<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' requested here
   363 |             return __detail::__to_unsigned_like(_End{}(__t) - _Begin{}(__t));
       |                                                             ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of function template specialization 'std::ranges::__cust_access::_Size::operator()<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of requirement here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^~~~~~~~~~~~~~~~~
 include/c++/13/bits/ranges_base.h:545:10: note: while substituting template arguments into constraint expression here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while checking the satisfaction of concept 'sized_range<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while substituting template arguments into constraint expression here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: while checking constraint satisfaction for template 'span<py::RtValue, 18446744073709551615UL>' required here
    37 |                 return PyTuple::create(const_cast<const py::GCVector<Value> &>(elements));
       |                                        ^~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: in instantiation of function template specialization 'std::span<py::RtValue>::span<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FormatValue.cpp:1:
 In file included from /src/executable/bytecode/instructions/FormatValue.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:43:
 include/c++/13/bits/stl_iterator_base_funcs.h:106:21: error: invalid operands to binary expression ('__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' and '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>')
   106 |       return __last - __first;
       |              ~~~~~~ ^ ~~~~~~~
 include/c++/13/bits/stl_iterator_base_funcs.h:151:19: note: in instantiation of function template specialization 'std::__distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   151 |       return std::__distance(__first, __last,
       |                   ^
 include/c++/13/bits/stl_vector.h:1690:31: note: in instantiation of function template specialization 'std::distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
  1690 |           const size_type __n = std::distance(__first, __last);
       |                                      ^
 include/c++/13/bits/stl_vector.h:711:4: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::_M_range_initialize<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   711 |           _M_range_initialize(__first, __last,
       |           ^
 /src/./runtime/PyTuple.hpp:43:23: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::vector<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>, void>' requested here
    43 |                 py::GCVector<Value> tmp(elements.begin(), elements.end());
       |                                     ^
 include/c++/13/bits/stl_iterator.h:625:5: note: candidate template ignored: could not match 'reverse_iterator' against '__gnu_cxx::__normal_iterator'
   625 |     operator-(const reverse_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1321:5: note: candidate template ignored: substitution failure [with _IteratorL = const py::RtValue *, _IteratorR = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1321 |     operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
       |     ^
  1322 |               const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
  1323 |     -> decltype(__lhs.base() - __rhs.base())
       |                              ~
 include/c++/13/bits/stl_iterator.h:1334:5: note: candidate template ignored: substitution failure [with _Iterator = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]
  1334 |     operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
       |     ^
 include/c++/13/bits/stl_iterator.h:1800:5: note: candidate template ignored: could not match 'move_iterator' against '__gnu_cxx::__normal_iterator'
  1800 |     operator-(const move_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1157:7: note: candidate function not viable: no known conversion from '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' to 'difference_type' (aka 'long') for 1st argument
  1157 |       operator-(difference_type __n) const _GLIBCXX_NOEXCEPT
       |       ^         ~~~~~~~~~~~~~~~~~~~
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [16/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteSubscript.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteSubscript.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteSubscript.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteSubscript.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteSubscript.cpp.o -c /src/executable/bytecode/instructions/DeleteSubscript.cpp
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteSubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [17/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/VariablesResolver.cpp.o
 [18/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearTopCleanup.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearTopCleanup.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearTopCleanup.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearTopCleanup.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/ClearTopCleanup.cpp.o -c /src/executable/bytecode/instructions/ClearTopCleanup.cpp
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.cpp:1:
 In file included from /src/executable/bytecode/instructions/ClearTopCleanup.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [19/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCall.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCall.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCall.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCall.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/FunctionCall.cpp.o -c /src/executable/bytecode/instructions/FunctionCall.cpp
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/FunctionCall.cpp:1:
 In file included from /src/executable/bytecode/instructions/FunctionCall.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [20/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteFast.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteFast.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteFast.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteFast.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DeleteFast.cpp.o -c /src/executable/bytecode/instructions/DeleteFast.cpp
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DeleteFast.cpp:1:
 In file included from /src/executable/bytecode/instructions/DeleteFast.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [21/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildTuple.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildTuple.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildTuple.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildTuple.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildTuple.cpp.o -c /src/executable/bytecode/instructions/BuildTuple.cpp
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:54:
 In file included from include/c++/13/bits/basic_string.h:39:
 In file included from include/c++/13/ext/alloc_traits.h:34:
 include/c++/13/bits/alloc_traits.h:932:33: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   932 |       for (; __first != __last; ++__first)
       |                                 ^ ~~~~~~~
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<py::RtValue *, py::GCTracingAllocator<py::RtValue>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:370:35: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   370 |                       _M_impl._M_end_of_storage - _M_impl._M_start);
       |                       ~~~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:733:7: note: in instantiation of member function 'std::_Vector_base<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~_Vector_base' requested here
   733 |       ~vector() _GLIBCXX_NOEXCEPT
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyTuple
       |       ^
 /src/./runtime/PyTuple.hpp:8:7: note: in implicit destructor for 'py::PyTuple' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:48:
 include/c++/13/bits/stl_iterator.h:1337:27: error: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1337 |     { return __lhs.base() - __rhs.base(); }
       |              ~~~~~~~~~~~~ ^
 include/c++/13/bits/ranges_base.h:363:54: note: in instantiation of function template specialization '__gnu_cxx::operator-<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' requested here
   363 |             return __detail::__to_unsigned_like(_End{}(__t) - _Begin{}(__t));
       |                                                             ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of function template specialization 'std::ranges::__cust_access::_Size::operator()<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^
 include/c++/13/bits/ranges_base.h:545:31: note: in instantiation of requirement here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |                               ^~~~~~~~~~~~~~~~~
 include/c++/13/bits/ranges_base.h:545:10: note: while substituting template arguments into constraint expression here
   545 |       && requires(_Tp& __t) { ranges::size(__t); };
       |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while checking the satisfaction of concept 'sized_range<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/span:211:43: note: while substituting template arguments into constraint expression here
   211 |           && ranges::contiguous_range<_Range> && ranges::sized_range<_Range>
       |                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: while checking constraint satisfaction for template 'span<py::RtValue, 18446744073709551615UL>' required here
    37 |                 return PyTuple::create(const_cast<const py::GCVector<Value> &>(elements));
       |                                        ^~~~~~~~~~
 /src/./runtime/PyTuple.hpp:37:26: note: in instantiation of function template specialization 'std::span<py::RtValue>::span<const std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>> &>' requested here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildTuple.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildTuple.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:43:
 include/c++/13/bits/stl_iterator_base_funcs.h:106:21: error: invalid operands to binary expression ('__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' and '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>')
   106 |       return __last - __first;
       |              ~~~~~~ ^ ~~~~~~~
 include/c++/13/bits/stl_iterator_base_funcs.h:151:19: note: in instantiation of function template specialization 'std::__distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   151 |       return std::__distance(__first, __last,
       |                   ^
 include/c++/13/bits/stl_vector.h:1690:31: note: in instantiation of function template specialization 'std::distance<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
  1690 |           const size_type __n = std::distance(__first, __last);
       |                                      ^
 include/c++/13/bits/stl_vector.h:711:4: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::_M_range_initialize<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>>' requested here
   711 |           _M_range_initialize(__first, __last,
       |           ^
 /src/./runtime/PyTuple.hpp:43:23: note: in instantiation of function template specialization 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::vector<__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>, void>' requested here
    43 |                 py::GCVector<Value> tmp(elements.begin(), elements.end());
       |                                     ^
 include/c++/13/bits/stl_iterator.h:625:5: note: candidate template ignored: could not match 'reverse_iterator' against '__gnu_cxx::__normal_iterator'
   625 |     operator-(const reverse_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1321:5: note: candidate template ignored: substitution failure [with _IteratorL = const py::RtValue *, _IteratorR = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]: arithmetic on a pointer to an incomplete type 'const py::RtValue'
  1321 |     operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
       |     ^
  1322 |               const __normal_iterator<_IteratorR, _Container>& __rhs) noexcept
  1323 |     -> decltype(__lhs.base() - __rhs.base())
       |                              ~
 include/c++/13/bits/stl_iterator.h:1334:5: note: candidate template ignored: substitution failure [with _Iterator = const py::RtValue *, _Container = std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>]
  1334 |     operator-(const __normal_iterator<_Iterator, _Container>& __lhs,
       |     ^
 include/c++/13/bits/stl_iterator.h:1800:5: note: candidate template ignored: could not match 'move_iterator' against '__gnu_cxx::__normal_iterator'
  1800 |     operator-(const move_iterator<_IteratorL>& __x,
       |     ^
 include/c++/13/bits/stl_iterator.h:1157:7: note: candidate function not viable: no known conversion from '__gnu_cxx::__normal_iterator<const py::RtValue *, std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>>' to 'difference_type' (aka 'long') for 1st argument
  1157 |       operator-(difference_type __n) const _GLIBCXX_NOEXCEPT
       |       ^         ~~~~~~~~~~~~~~~~~~~
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [22/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictMerge.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictMerge.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictMerge.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictMerge.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictMerge.cpp.o -c /src/executable/bytecode/instructions/DictMerge.cpp
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictMerge.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictMerge.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [23/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSlice.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSlice.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSlice.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSlice.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSlice.cpp.o -c /src/executable/bytecode/instructions/BuildSlice.cpp
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSlice.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSlice.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [24/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildList.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildList.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildList.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildList.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildList.cpp.o -c /src/executable/bytecode/instructions/BuildList.cpp
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:45:
 In file included from include/c++/13/sstream:40:
 In file included from include/c++/13/istream:40:
 In file included from include/c++/13/ios:44:
 In file included from include/c++/13/bits/ios_base.h:41:
 In file included from include/c++/13/bits/locale_classes.h:40:
 In file included from include/c++/13/string:54:
 In file included from include/c++/13/bits/basic_string.h:39:
 In file included from include/c++/13/ext/alloc_traits.h:34:
 include/c++/13/bits/alloc_traits.h:932:33: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   932 |       for (; __first != __last; ++__first)
       |                                 ^ ~~~~~~~
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<py::RtValue *, py::GCTracingAllocator<py::RtValue>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /src/./runtime/PyList.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyList
       |       ^
 /src/./runtime/PyList.hpp:8:7: note: in implicit destructor for 'py::PyList' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:370:35: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   370 |                       _M_impl._M_end_of_storage - _M_impl._M_start);
       |                       ~~~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:733:7: note: in instantiation of member function 'std::_Vector_base<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~_Vector_base' requested here
   733 |       ~vector() _GLIBCXX_NOEXCEPT
       |       ^
 /src/./runtime/PyList.hpp:8:7: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::~vector' requested here
     8 | class PyList
       |       ^
 /src/./runtime/PyList.hpp:8:7: note: in implicit destructor for 'py::PyList' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildList.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildList.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [25/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSet.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSet.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSet.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSet.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BuildSet.cpp.o -c /src/executable/bytecode/instructions/BuildSet.cpp
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BuildSet.cpp:1:
 In file included from /src/executable/bytecode/instructions/BuildSet.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [26/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/CompareOperation.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/CompareOperation.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/CompareOperation.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/CompareOperation.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/CompareOperation.cpp.o -c /src/executable/bytecode/instructions/CompareOperation.cpp
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/CompareOperation.cpp:1:
 In file included from /src/executable/bytecode/instructions/CompareOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [27/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictUpdate.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictUpdate.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictUpdate.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictUpdate.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/DictUpdate.cpp.o -c /src/executable/bytecode/instructions/DictUpdate.cpp
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:7:
 In file included from /include/spdlog/details/null_mutex.h:7:
 In file included from include/c++/13/utility:69:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/DictUpdate.cpp:1:
 In file included from /src/executable/bytecode/instructions/DictUpdate.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:3:
 In file included from /src/./runtime/../forward.hpp:4:
 In file included from include/c++/13/variant:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [28/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinarySubscript.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinarySubscript.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinarySubscript.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinarySubscript.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/instructions/BinarySubscript.cpp.o -c /src/executable/bytecode/instructions/BinarySubscript.cpp
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:100:25: note: in instantiation of member function 'std::vector<py::RtValue>::size' requested here
   100 |                 ASSERT(idx < r->get().size());
       |                                       ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1129:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1129 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:101:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   101 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:47:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:1148:34: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
  1148 |         return *(this->_M_impl._M_start + __n);
       |                  ~~~~~~~~~~~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:109:18: note: in instantiation of member function 'std::vector<py::RtValue>::operator[]' requested here
   109 |                 return r->get()[idx];
       |                                ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/instructions/BinarySubscript.cpp:1:
 In file included from /src/executable/bytecode/instructions/BinarySubscript.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 In file included from /src/./runtime/Value.hpp:4:
 In file included from /src/./runtime/../utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:10:
 In file included from include/c++/13/chrono:3370:
 In file included from include/c++/13/bits/chrono_io.h:39:
 In file included from include/c++/13/format:44:
 include/c++/13/span:289:24: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   289 |         return *(this->_M_ptr + __idx);
       |                  ~~~~~~~~~~~~ ^
 /src/./vm/VM.hpp:117:15: note: in instantiation of member function 'std::span<py::RtValue>::operator[]' requested here
   117 |                 return local[idx];
       |                             ^
 /src/./runtime/../forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [29/278] Building CXX object src/CMakeFiles/python-cpp.dir/ast/AST.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/ast/AST.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/ast/AST.cpp.o -MF src/CMakeFiles/python-cpp.dir/ast/AST.cpp.o.d -o src/CMakeFiles/python-cpp.dir/ast/AST.cpp.o -c /src/ast/AST.cpp
 In file included from /src/ast/AST.cpp:3:
 In file included from /src/./runtime/PyBool.hpp:3:
 In file included from /src/./runtime/PyInteger.hpp:3:
 In file included from /src/./runtime/PyNumber.hpp:3:
 In file included from /src/./runtime/PyObject.hpp:4:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/AST.cpp:3:
 In file included from /src/./runtime/PyBool.hpp:3:
 In file included from /src/./runtime/PyInteger.hpp:3:
 In file included from /src/./runtime/PyNumber.hpp:3:
 In file included from /src/./runtime/PyObject.hpp:4:
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/AST.cpp:3:
 In file included from /src/./runtime/PyBool.hpp:3:
 In file included from /src/./runtime/PyInteger.hpp:3:
 In file included from /src/./runtime/PyNumber.hpp:3:
 In file included from /src/./runtime/PyObject.hpp:4:
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/AST.cpp:3:
 In file included from /src/./runtime/PyBool.hpp:3:
 In file included from /src/./runtime/PyInteger.hpp:3:
 In file included from /src/./runtime/PyNumber.hpp:3:
 In file included from /src/./runtime/PyObject.hpp:4:
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/AST.cpp:3:
 In file included from /src/./runtime/PyBool.hpp:3:
 In file included from /src/./runtime/PyInteger.hpp:3:
 In file included from /src/./runtime/PyNumber.hpp:3:
 In file included from /src/./runtime/PyObject.hpp:4:
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:3:
 In file included from include/c++/13/memory:66:
 In file included from include/c++/13/bits/stl_tempbuf.h:62:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:3:
 In file included from include/c++/13/memory:66:
 In file included from include/c++/13/bits/stl_tempbuf.h:62:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/ast/AST.cpp:1:
 In file included from /src/ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:3260:64: error: incomplete type 'py::RtValue' used in type trait expression
  3260 |   inline constexpr bool is_assignable_v = __is_assignable(_Tp, _Up);
       |                                                                ^
 include/c++/13/bits/stl_pair.h:395:18: note: in instantiation of variable template specialization 'std::is_assignable_v<py::RtValue &, py::RtValue>' requested here
   395 |           if constexpr (is_assignable_v<_T1&, _U1>)
       |                         ^
 include/c++/13/bits/stl_pair.h:429:17: note: in instantiation of function template specialization 'std::pair<py::RtValue, py::RtValue>::_S_assignable<py::RtValue, py::RtValue>' requested here
   429 |       requires (_S_assignable<_T1, _T2>())
       |                 ^
 include/c++/13/bits/stl_pair.h:429:17: note: while substituting template arguments into constraint expression here
   429 |       requires (_S_assignable<_T1, _T2>())
       |                 ^~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:427:7: note: while checking constraint satisfaction for function 'operator=' required here
   427 |       operator=(pair&& __p)
       |       ^~~~~~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [30/278] Building CXX object src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/BytecodeGenerator.cpp.o
 FAILED: [code=1] src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/BytecodeGenerator.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DCPPTRACE_STATIC_DEFINE -DGC_THREADS -DPYLANG_HAS_LLD=1 -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -DSPDLOG_COMPILED_LIB -I/src/. -I/build/debug/src -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -isystem /build/debug/_deps/cpptrace-build/include -isystem /include -isystem /build/debug/.cache/CPM/ordered-map/397e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -fno-omit-frame-pointer -Wall -Wextra -Wextra-semi -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2 -Wimplicit-fallthrough -Wno-sign-conversion -Wno-shadow -Wno-implicit-fallthrough -Wno-old-style-cast -Wno-deprecated-copy -Wno-missing-field-initializers -Wno-null-dereference -Wno-unknown-warning-option -MD -MT src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/BytecodeGenerator.cpp.o -MF src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/BytecodeGenerator.cpp.o.d -o src/CMakeFiles/python-cpp.dir/executable/bytecode/codegen/BytecodeGenerator.cpp.o -c /src/executable/bytecode/codegen/BytecodeGenerator.cpp
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/./runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/./runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/./executable/bytecode/instructions/Instructions.hpp:3:
 /src/./runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/./ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/./runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 /src/./executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:66:
 In file included from include/c++/13/bits/stl_tempbuf.h:62:
 include/c++/13/bits/stl_pair.h:193:11: error: field has incomplete type 'py::RtValue'
   193 |       _T1 first;                 ///< The first member
       |           ^
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:66:
 In file included from include/c++/13/bits/stl_tempbuf.h:62:
 include/c++/13/bits/stl_pair.h:194:11: error: field has incomplete type 'py::RtValue'
   194 |       _T2 second;                ///< The second member
       |           ^
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:1040:25: error: incomplete type 'py::RtValue' used in type trait expression
  1040 |       = __bool_constant<__is_constructible(_Tp, _Args...)>;
       |                         ^
 include/c++/13/type_traits:1265:21: note: in instantiation of template type alias '__is_constructible_impl' requested here
  1265 |     : public __and_<__is_constructible_impl<_Tp>,
       |                     ^
 include/c++/13/type_traits:161:30: note: in instantiation of template class 'std::__is_implicitly_default_constructible<py::RtValue>' requested here
   161 |                                       __enable_if_t<bool(_Bn::value)>...>;
       |                                                          ^
 include/c++/13/type_traits:177:16: note: while substituting explicitly-specified template arguments into function template '__and_fn' 
   177 |     : decltype(__detail::__and_fn<_Bn...>(0))
       |                ^
 include/c++/13/type_traits:182:29: note: in instantiation of template class 'std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>' requested here
   182 |     : __bool_constant<!bool(_Pp::value)>
       |                             ^
 include/c++/13/bits/stl_pair.h:247:16: note: in instantiation of template class 'std::__not_<std::__and_<std::__is_implicitly_default_constructible<py::RtValue>, std::__is_implicitly_default_constructible<py::RtValue>>>' requested here
   247 |       explicit(__not_<__and_<__is_implicitly_default_constructible<_T1>,
       |                ^
 include/c++/13/bits/alloc_traits.h:932:33: note: (skipping 1 context in backtrace; use -ftemplate-backtrace-limit=0 to see all)
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.cpp:1:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/./ast/AST.hpp:3:
 In file included from include/c++/13/memory:65:
 In file included from include/c++/13/bits/allocator.h:46:
 In file included from include/x86_64-linux-gnu/c++/13/bits/c++allocator.h:33:
 In file included from include/c++/13/bits/new_allocator.h:36:
 In file included from include/c++/13/bits/move.h:37:
 include/c++/13/type_traits:3251:54: error: incomplete type 'py::RtValue' used in type trait expression
  3251 |   inline constexpr bool is_default_constructible_v = __is_constructible(_Tp);
       |                                                      ^
 include/c++/13/bits/stl_pair.h:250:16: note: in instantiation of variable template specialization 'std::is_default_constructible_v<py::RtValue>' requested here
   250 |       requires is_default_constructible_v<_T1>
       |                ^
 include/c++/13/bits/stl_pair.h:250:16: note: while substituting template arguments into constraint expression here
   250 |       requires is_default_constructible_v<_T1>
       |                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:249:7: note: while checking constraint satisfaction for function 'pair' required here
   249 |       pair()
       |       ^~~~
 include/c++/13/bits/alloc_traits.h:932:33: note: in instantiation of template class 'std::pair<py::RtValue, py::RtValue>' requested here
   932 |       for (; __first != __last; ++__first)
       |                                 ^
 include/c++/13/bits/stl_vector.h:735:7: note: in instantiation of function template specialization 'std::_Destroy<std::pair<py::RtValue, py::RtValue> *, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>' requested here
   735 |         std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
       |              ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_hash.h:292:7: note: in instantiation of member function 'std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>::~vector' requested here
   292 | class ordered_hash : private Hash, private KeyEqual {
       |       ^
 /build/debug/.cache/CPM/ordered-map/397e/include/tsl/ordered_map.h:81:7: note: in implicit destructor for 'tsl::detail_ordered_hash::ordered_hash<std::pair<py::RtValue, py::RtValue>, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::KeySelect, tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>::ValueSelect, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>, unsigned int>' first required here
    81 | class ordered_map {
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'tsl::ordered_map<py::RtValue, py::RtValue, py::ValueHash, py::ValueEq, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>, std::vector<std::pair<py::RtValue, py::RtValue>, py::GCTracingAllocator<std::pair<py::RtValue, py::RtValue>>>>' first required here
    22 | class PyDict : public PyBaseObject
       |       ^
 /src/./runtime/PyDict.hpp:22:7: note: in implicit destructor for 'py::PyDict' first required here
 /src/./forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 20 errors generated.
 [31/278] Building CXX object src/executable/mlir/CMakeFiles/python-mlir.dir/compile.cpp.o
 [32/278] Building CXX object src/executable/mlir/Conversion/PythonToPythonBytecode/CMakeFiles/obj.PythonToPythonBytecode.dir/PythonToPythonBytecode.cpp.o
 FAILED: [code=1] src/executable/mlir/Conversion/PythonToPythonBytecode/CMakeFiles/obj.PythonToPythonBytecode.dir/PythonToPythonBytecode.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -I/usr/lib/llvm-20/include -I/src/executable/mlir -I/build/debug/src/executable/mlir -I/src -I/src/executable/mlir/Dialect -I/build/debug/src/executable/mlir/Dialect -I/include -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -MD -MT src/executable/mlir/Conversion/PythonToPythonBytecode/CMakeFiles/obj.PythonToPythonBytecode.dir/PythonToPythonBytecode.cpp.o -MF src/executable/mlir/Conversion/PythonToPythonBytecode/CMakeFiles/obj.PythonToPythonBytecode.dir/PythonToPythonBytecode.cpp.o.d -o src/executable/mlir/Conversion/PythonToPythonBytecode/CMakeFiles/obj.PythonToPythonBytecode.dir/PythonToPythonBytecode.cpp.o -c /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:2:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:6:
 In file included from /src/ast/AST.hpp:14:
 In file included from /src/lexer/Lexer.hpp:3:
 In file included from /src/utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:36:
 In file included from /include/spdlog/fmt/fmt.h:23:
 /include/spdlog/fmt/bundled/format.h:3943:48: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3943 | FMT_CONSTEXPR detail::udl_arg<char> operator"" _a(const char* s, size_t) {
       |                                     ~~~~~~~~~~~^~
       |                                     operator""_a
 /include/spdlog/fmt/bundled/format.h:3946:51: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3946 | FMT_CONSTEXPR detail::udl_arg<wchar_t> operator"" _a(const wchar_t* s, size_t) {
       |                                        ~~~~~~~~~~~^~
       |                                        operator""_a
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:2:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineExpr.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Visitors.h:17:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/STLExtras.h:33:
 In file included from include/c++/13/functional:64:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:8:
 In file included from /src/executable/bytecode/instructions/BinaryOperation.hpp:3:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:144:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   144 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:144:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   144 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:148:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   148 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:148:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   148 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:157:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   157 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:157:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   157 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1127:29: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1127 |                                         add_local(op, arg_name.cast<mlir::StringAttr>().getValue(), builder);
       |                                                                ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1127:29: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1127 |                                         add_local(op, arg_name.cast<mlir::StringAttr>().getValue(), builder);
       |                                                                ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1138:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1138 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1138:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1138 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1142:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1142 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1142:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1142 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1151:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1151 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1151:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1151 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1187:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1187 |                                                                 return name.cast<mlir::StringAttr>() == "__class__";
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:1187:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
  1187 |                                                                 return name.cast<mlir::StringAttr>() == "__class__";
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:2233:9: warning: 'applyPatternsAndFoldGreedily' is deprecated: Use applyPatternsGreedily() instead [-Wdeprecated-declarations]
  2233 |                 (void)applyPatternsAndFoldGreedily(getOperation(), frozen_patterns, config);
       |                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~
       |                       applyPatternsGreedily
 /usr/lib/llvm-20/include/mlir/Transforms/GreedyPatternRewriteDriver.h:184:1: note: 'applyPatternsAndFoldGreedily' has been explicitly marked deprecated here
   184 | LLVM_DEPRECATED("Use applyPatternsGreedily() instead", "applyPatternsGreedily")
       | ^
 /usr/lib/llvm-20/include/llvm/Support/Compiler.h:234:50: note: expanded from macro 'LLVM_DEPRECATED'
   234 | #define LLVM_DEPRECATED(MSG, FIX) __attribute__((deprecated(MSG, FIX)))
       |                                                  ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:198:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::StoreFastOp>>::addLocalIdentifierToParentFunction' requested here
   198 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:116:43: note: while substituting into a lambda expression here
   116 |                                                         [identifier](mlir::Attribute attr) {
       |                                                                                            ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:198:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::StoreFastOp>>::addLocalIdentifierToParentFunction' requested here
   198 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:125:32: note: while substituting into a lambda expression here
   125 |                                                 [](mlir::Attribute attr) {
       |                                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:198:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::StoreFastOp>>::addLocalIdentifierToParentFunction' requested here
   198 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:282:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::LoadFastOp>>::addLocalIdentifierToParentFunction' requested here
   282 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:116:43: note: while substituting into a lambda expression here
   116 |                                                         [identifier](mlir::Attribute attr) {
       |                                                                                            ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:282:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::LoadFastOp>>::addLocalIdentifierToParentFunction' requested here
   282 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:125:32: note: while substituting into a lambda expression here
   125 |                                                 [](mlir::Attribute attr) {
       |                                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:282:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::LoadFastOp>>::addLocalIdentifierToParentFunction' requested here
   282 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:338:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::DeleteFastOp>>::addLocalIdentifierToParentFunction' requested here
   338 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:113:23: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   113 |                                         auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                                          ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:116:43: note: while substituting into a lambda expression here
   116 |                                                         [identifier](mlir::Attribute attr) {
       |                                                                                            ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:338:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::DeleteFastOp>>::addLocalIdentifierToParentFunction' requested here
   338 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:117:21: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   117 |                                                                 return attr.cast<mlir::StringAttr>().getValue() == identifier;
       |                                                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:125:32: note: while substituting into a lambda expression here
   125 |                                                 [](mlir::Attribute attr) {
       |                                                                          ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:338:5: note: in instantiation of member function 'mlir::py::(anonymous namespace)::LocalDeclarationInterface<mlir::OpRewritePattern<mlir::py::DeleteFastOp>>::addLocalIdentifierToParentFunction' requested here
   338 |                                 addLocalIdentifierToParentFunction(fn, object_name, rewriter);
       |                                 ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Conversion/PythonToPythonBytecode/PythonToPythonBytecode.cpp:126:20: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   126 |                                                         return attr.cast<mlir::StringAttr>().getValue();
       |                                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 44 warnings and 15 errors generated.
 [33/278] Building CXX object src/executable/mlir/Target/PythonBytecode/CMakeFiles/obj.TargetPythonBytecode.dir/TranslateToPythonBytecode.cpp.o
 FAILED: [code=1] src/executable/mlir/Target/PythonBytecode/CMakeFiles/obj.TargetPythonBytecode.dir/TranslateToPythonBytecode.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -I/usr/lib/llvm-20/include -I/src/executable/mlir -I/src -I/src/executable/mlir/Dialect -I/build/debug/src/executable/mlir/Dialect -I/include -I/src/. -I/build/debug/_deps/cpptrace-build/include -I/build/debug/.cache/CPM/ordered-map/397e/include -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -MD -MT src/executable/mlir/Target/PythonBytecode/CMakeFiles/obj.TargetPythonBytecode.dir/TranslateToPythonBytecode.cpp.o -MF src/executable/mlir/Target/PythonBytecode/CMakeFiles/obj.TargetPythonBytecode.dir/TranslateToPythonBytecode.cpp.o.d -o src/executable/mlir/Target/PythonBytecode/CMakeFiles/obj.TargetPythonBytecode.dir/TranslateToPythonBytecode.cpp.o -c /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:3:
 In file included from /src/executable/bytecode/codegen/VariablesResolver.hpp:3:
 In file included from /src/ast/AST.hpp:14:
 In file included from /src/lexer/Lexer.hpp:3:
 In file included from /src/utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:36:
 In file included from /include/spdlog/fmt/fmt.h:23:
 /include/spdlog/fmt/bundled/format.h:3943:48: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3943 | FMT_CONSTEXPR detail::udl_arg<char> operator"" _a(const char* s, size_t) {
       |                                     ~~~~~~~~~~~^~
       |                                     operator""_a
 /include/spdlog/fmt/bundled/format.h:3946:51: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3946 | FMT_CONSTEXPR detail::udl_arg<wchar_t> operator"" _a(const wchar_t* s, size_t) {
       |                                        ~~~~~~~~~~~^~
       |                                        operator""_a
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 In file included from /src/executable/bytecode/instructions/Instructions.hpp:3:
 /src/runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineExpr.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Visitors.h:17:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/STLExtras.h:33:
 In file included from include/c++/13/functional:64:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:5:
 In file included from /src/executable/bytecode/BytecodeProgram.hpp:3:
 In file included from /src/executable/bytecode/Bytecode.hpp:3:
 In file included from /src/executable/bytecode/codegen/BytecodeGenerator.hpp:8:
 /src/executable/bytecode/instructions/Instructions.hpp:20:13: error: field has incomplete type 'py::Value' (aka 'py::RtValue')
    20 |                 py::Value reg0;
       |                           ^
 /src/forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>[4], llvm::SmallDenseMap<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/Metadata.h:395:58: note: in instantiation of template class 'llvm::SmallDenseMap<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>' requested here
   395 |   SmallDenseMap<void *, std::pair<OwnerTy, uint64_t>, 4> UseMap;
       |                                                          ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<llvm::AnalysisKey *, bool>[8], llvm::SmallDenseMap<llvm::AnalysisKey *, bool, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/PassManager.h:336:39: note: in instantiation of template class 'llvm::SmallDenseMap<llvm::AnalysisKey *, bool, 8>' requested here
   336 |       auto IMapI = IsResultInvalidated.find(ID);
       |                                       ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>>[2], llvm::SmallDenseMap<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>, 2>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/PassManager.h:771:9: note: in instantiation of template class 'llvm::SmallDenseMap<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>, 2>' requested here
   771 |         OuterAnalysisInvalidationMap;
       |         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/Support/ErrorOr.h:256:44: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<std::error_code>' requested here
   256 |     AlignedCharArrayUnion<std::error_code> ErrorStorage;
       |                                            ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/Support/Error.h:731:39: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<std::unique_ptr<llvm::ErrorInfoBase>>' requested here
   731 |     AlignedCharArrayUnion<error_type> ErrorStorage;
       |                                       ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<const llvm::Value *, bool>[8], llvm::SmallDenseMap<const llvm::Value *, bool, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/Analysis/AliasAnalysis.h:163:41: note: in instantiation of template class 'llvm::SmallDenseMap<const llvm::Value *, bool, 8>' requested here
   163 |   SmallDenseMap<const Value *, bool, 8> IsCapturedCache;
       |                                         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry>[8], llvm::SmallDenseMap<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/Analysis/AliasAnalysis.h:266:15: note: in instantiation of template class 'llvm::SmallDenseMap<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry, 8>' requested here
   266 |   AliasCacheT AliasCache;
       |               ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:1:
 In file included from /src/executable/mlir/Dialect/EmitPythonBytecode/IR/EmitPythonBytecode.hpp:3:
 In file included from /src/executable/mlir/Dialect/Python/IR/PythonTypes.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinTypes.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/BuiltinAttributeInterfaces.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AffineMap.h:18:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Value.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Types.h:12:
 In file included from /usr/lib/llvm-20/include/mlir/IR/TypeSupport.h:17:
 In file included from /usr/lib/llvm-20/include/mlir/IR/StorageUniquerSupport.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/AttrTypeSubElements.h:19:
 In file included from /usr/lib/llvm-20/include/mlir/Support/CyclicReplacerCache.h:18:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<const llvm::Value *, unsigned int>[4], llvm::SmallDenseMap<const llvm::Value *, unsigned int>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:37:11: note: in instantiation of template class 'llvm::SmallDenseMap<const llvm::Value *, unsigned int>' requested here
    37 |   MapType Map;
       |           ^
 /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:253:7: note: in instantiation of template class 'llvm::MapVector<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>, llvm::SmallDenseMap<const llvm::Value *, unsigned int>, llvm::SmallVector<std::pair<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>>, 4>>' requested here
   253 |     : MapVector<KeyT, ValueT, SmallDenseMap<KeyT, unsigned, N>,
       |       ^
 /usr/lib/llvm-20/include/llvm/Frontend/OpenMP/OMPIRBuilder.h:2320:9: note: in instantiation of template class 'llvm::SmallMapVector<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>, 4>' requested here
  2320 |         DevicePtrInfoMap;
       |         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:259:37: warning: 'isa' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   259 |                                                 && std::get<mlir::Value>(val).isa<BlockArgument>()
       |                                                                               ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:102:8: note: 'isa' has been explicitly marked deprecated here
   102 |   bool isa() const {
       |        ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:259:37: warning: 'isa<mlir::BlockArgument>' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   259 |                                                 && std::get<mlir::Value>(val).isa<BlockArgument>()
       |                                                                               ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:101:5: note: 'isa<mlir::BlockArgument>' has been explicitly marked deprecated here
   101 |   [[deprecated("Use mlir::isa<U>() instead")]]
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:260:37: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   260 |                                                 && std::get<mlir::Value>(val).cast<BlockArgument>() == arg) {
       |                                                                               ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:120:5: note: 'cast' has been explicitly marked deprecated here
   120 |   U cast() const {
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:260:37: warning: 'cast<mlir::BlockArgument>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   260 |                                                 && std::get<mlir::Value>(val).cast<BlockArgument>() == arg) {
       |                                                                               ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:119:5: note: 'cast<mlir::BlockArgument>' has been explicitly marked deprecated here
   119 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:702:25: warning: 'isa' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   702 |                                                 if (current_value.isa<mlir::BlockArgument>()) {
       |                                                                   ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:102:8: note: 'isa' has been explicitly marked deprecated here
   102 |   bool isa() const {
       |        ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:702:25: warning: 'isa<mlir::BlockArgument>' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   702 |                                                 if (current_value.isa<mlir::BlockArgument>()) {
       |                                                                   ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:101:5: note: 'isa<mlir::BlockArgument>' has been explicitly marked deprecated here
   101 |   [[deprecated("Use mlir::isa<U>() instead")]]
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:710:32: warning: 'isa' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   710 |                                                                                 ASSERT(current_value.isa<mlir::BlockArgument>());
       |                                                                                                      ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:102:8: note: 'isa' has been explicitly marked deprecated here
   102 |   bool isa() const {
       |        ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:710:32: warning: 'isa<mlir::BlockArgument>' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   710 |                                                                                 ASSERT(current_value.isa<mlir::BlockArgument>());
       |                                                                                                      ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:101:5: note: 'isa<mlir::BlockArgument>' has been explicitly marked deprecated here
   101 |   [[deprecated("Use mlir::isa<U>() instead")]]
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:717:29: warning: 'isa' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   717 |                                                 ASSERT(!current_value.isa<mlir::BlockArgument>());
       |                                                                       ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:102:8: note: 'isa' has been explicitly marked deprecated here
   102 |   bool isa() const {
       |        ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:717:29: warning: 'isa<mlir::BlockArgument>' is deprecated: Use mlir::isa<U>() instead [-Wdeprecated-declarations]
   717 |                                                 ASSERT(!current_value.isa<mlir::BlockArgument>());
       |                                                                       ^
 /usr/lib/llvm-20/include/mlir/IR/Value.h:101:5: note: 'isa<mlir::BlockArgument>' has been explicitly marked deprecated here
   101 |   [[deprecated("Use mlir::isa<U>() instead")]]
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:820:11: error: no matching function for call to 'holds_alternative'
   820 |                                                         && std::holds_alternative<::py::Number>(value)) {
       |                                                            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/variant:1141:5: note: candidate template ignored: could not match 'variant<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1141 |     holds_alternative(const variant<_Types...>& __v) noexcept
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:822:16: error: no matching function for call to 'get'
   822 |                                                                            == std::get<::py::Number>(value).value.index()
       |                                                                               ^~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:1059:5: note: candidate template ignored: could not match 'pair< ::py::Number, _Up>' against '::py::Value' (aka 'py::RtValue')
  1059 |     get(pair<_Tp, _Up>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1064:5: note: candidate template ignored: could not match 'pair< ::py::Number, _Up>' against '::py::Value' (aka 'py::RtValue')
  1064 |     get(const pair<_Tp, _Up>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1069:5: note: candidate template ignored: could not match 'pair< ::py::Number, _Up>' against '::py::Value' (aka 'py::RtValue')
  1069 |     get(pair<_Tp, _Up>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1074:5: note: candidate template ignored: could not match 'pair< ::py::Number, _Up>' against '::py::Value' (aka 'py::RtValue')
  1074 |     get(const pair<_Tp, _Up>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1079:5: note: candidate template ignored: could not match 'pair<_Up, ::py::Number>' against '::py::Value' (aka 'py::RtValue')
  1079 |     get(pair<_Up, _Tp>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1084:5: note: candidate template ignored: could not match 'pair<_Up, ::py::Number>' against '::py::Value' (aka 'py::RtValue')
  1084 |     get(const pair<_Up, _Tp>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1089:5: note: candidate template ignored: could not match 'pair<_Up, ::py::Number>' against '::py::Value' (aka 'py::RtValue')
  1089 |     get(pair<_Up, _Tp>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1094:5: note: candidate template ignored: could not match 'pair<_Up, ::py::Number>' against '::py::Value' (aka 'py::RtValue')
  1094 |     get(const pair<_Up, _Tp>&& __p) noexcept
       |     ^
 include/c++/13/tuple:1844:5: note: candidate template ignored: could not match 'tuple<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1844 |     get(tuple<_Types...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1855:5: note: candidate template ignored: could not match 'tuple<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1855 |     get(tuple<_Types...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1866:5: note: candidate template ignored: could not match 'tuple<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1866 |     get(const tuple<_Types...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1878:5: note: candidate template ignored: could not match 'tuple<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1878 |     get(const tuple<_Types...>&& __t) noexcept
       |     ^
 include/c++/13/variant:1150:5: note: candidate template ignored: could not match 'variant<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1150 |     get(variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1160:5: note: candidate template ignored: could not match 'variant<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1160 |     get(variant<_Types...>&& __v)
       |     ^
 include/c++/13/variant:1170:5: note: candidate template ignored: could not match 'variant<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1170 |     get(const variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1180:5: note: candidate template ignored: could not match 'variant<_Types...>' against '::py::Value' (aka 'py::RtValue')
  1180 |     get(const variant<_Types...>&& __v)
       |     ^
 include/c++/13/bits/stl_pair.h:1035:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1035 |     get(pair<_Tp1, _Tp2>& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1040:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1040 |     get(pair<_Tp1, _Tp2>&& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1045:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1045 |     get(const pair<_Tp1, _Tp2>& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1050:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1050 |     get(const pair<_Tp1, _Tp2>&& __in) noexcept
       |     ^
 include/c++/13/bits/ranges_util.h:438:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Num'
   438 |     get(const subrange<_It, _Sent, _Kind>& __r)
       |     ^
 include/c++/13/bits/ranges_util.h:449:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Num'
   449 |     get(subrange<_It, _Sent, _Kind>&& __r)
       |     ^
 include/c++/13/tuple:1803:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1803 |     get(tuple<_Elements...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1809:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1809 |     get(const tuple<_Elements...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1815:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1815 |     get(tuple<_Elements...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1824:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1824 |     get(const tuple<_Elements...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1834:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1834 |     get(const tuple<_Elements...>&) = delete;
       |     ^
 include/c++/13/array:384:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   384 |     get(array<_Tp, _Nm>& __arr) noexcept
       |     ^
 include/c++/13/array:393:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   393 |     get(array<_Tp, _Nm>&& __arr) noexcept
       |     ^
 include/c++/13/array:402:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   402 |     get(const array<_Tp, _Nm>& __arr) noexcept
       |     ^
 include/c++/13/array:411:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   411 |     get(const array<_Tp, _Nm>&& __arr) noexcept
       |     ^
 include/c++/13/variant:1711:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1711 |     get(variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1722:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1722 |     get(variant<_Types...>&& __v)
       |     ^
 include/c++/13/variant:1733:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1733 |     get(const variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1744:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1744 |     get(const variant<_Types...>&& __v)
       |     ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:825:34: error: no member named 'index' in 'py::RtValue'
   825 |                                                 return el.index() == value.index() && el == value;
       |                                                                      ~~~~~ ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:819:11: error: no matching function for call to 'holds_alternative'
   819 |                                                 if (std::holds_alternative<::py::Number>(el)
       |                                                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/predefined_ops.h:318:16: note: in instantiation of function template specialization 'codegen::PythonBytecodeEmitter::FunctionInfo::add_const(::py::Value)::(anonymous class)::operator()<py::RtValue>' requested here
   318 |         { return bool(_M_pred(*__it)); }
       |                       ^
 include/c++/13/bits/stl_algobase.h:2072:8: note: in instantiation of function template specialization '__gnu_cxx::__ops::_Iter_pred<(lambda at /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:818:6)>::operator()<__gnu_cxx::__normal_iterator<py::RtValue *, std::vector<py::RtValue>>>' requested here
  2072 |           if (__pred(__first))
       |               ^
 include/c++/13/bits/stl_algobase.h:2117:14: note: in instantiation of function template specialization 'std::__find_if<__gnu_cxx::__normal_iterator<py::RtValue *, std::vector<py::RtValue>>, __gnu_cxx::__ops::_Iter_pred<(lambda at /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:818:6)>>' requested here
  2117 |       return __find_if(__first, __last, __pred,
       |              ^
 include/c++/13/bits/stl_algo.h:3923:19: note: in instantiation of function template specialization 'std::__find_if<__gnu_cxx::__normal_iterator<py::RtValue *, std::vector<py::RtValue>>, __gnu_cxx::__ops::_Iter_pred<(lambda at /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:818:6)>>' requested here
  3923 |       return std::__find_if(__first, __last,
       |                   ^
 /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:816:23: note: in instantiation of function template specialization 'std::find_if<__gnu_cxx::__normal_iterator<py::RtValue *, std::vector<py::RtValue>>, (lambda at /src/executable/mlir/Target/PythonBytecode/TranslateToPythonBytecode.cpp:818:6)>' requested here
   816 |                         if (auto it = std::find_if(m_consts.begin(),
       |                                            ^
 include/c++/13/variant:1141:5: note: candidate template ignored: could not match 'const variant<_Types...>' against 'const py::RtValue'
  1141 |     holds_alternative(const variant<_Types...>& __v) noexcept
       |     ^
 fatal error: too many errors emitted, stopping now [-ferror-limit=]
 21 warnings and 20 errors generated.
 [34/278] Building CXX object src/executable/mlir/Dialect/Python/CMakeFiles/obj.PythonMLIRDialect.dir/MLIRGenerator.cpp.o
 FAILED: [code=1] src/executable/mlir/Dialect/Python/CMakeFiles/obj.PythonMLIRDialect.dir/MLIRGenerator.cpp.o 
 /usr/bin/ccache /usr/lib/ccache/c++ -DCMAKE_BINARY_DIR=\"/build/debug\" -DPYLANG_USE_ARENA -DPYLANG_USE_Boehm_GC -I/src -I/usr/lib/llvm-20/include -I/src/executable/mlir/Dialect -I/build/debug/src/executable/mlir/Dialect -I/include -isystem /src/PUBLIC -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include -isystem /build/debug/.cache/CPM/yalantinglibs/f7f2/include/ylt/thirdparty -isystem /build/debug/.cache/CPM/bdwgc/2bfb/include -isystem /build/debug/.cache/CPM/cpptrace/2b0e/include -DALWAYS_SMALL_CLEAR_STACK -DSMALL_CLEAR_SIZE=4 -g -std=c++23 -fcolor-diagnostics -MD -MT src/executable/mlir/Dialect/Python/CMakeFiles/obj.PythonMLIRDialect.dir/MLIRGenerator.cpp.o -MF src/executable/mlir/Dialect/Python/CMakeFiles/obj.PythonMLIRDialect.dir/MLIRGenerator.cpp.o.d -o src/executable/mlir/Dialect/Python/CMakeFiles/obj.PythonMLIRDialect.dir/MLIRGenerator.cpp.o -c /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1:
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.hpp:3:
 In file included from /src/ast/AST.hpp:14:
 In file included from /src/lexer/Lexer.hpp:3:
 In file included from /src/utilities.hpp:3:
 In file included from /include/spdlog/spdlog.h:12:
 In file included from /include/spdlog/common.h:36:
 In file included from /include/spdlog/fmt/fmt.h:23:
 /include/spdlog/fmt/bundled/format.h:3943:48: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3943 | FMT_CONSTEXPR detail::udl_arg<char> operator"" _a(const char* s, size_t) {
       |                                     ~~~~~~~~~~~^~
       |                                     operator""_a
 /include/spdlog/fmt/bundled/format.h:3946:51: warning: identifier '_a' preceded by whitespace in a literal operator declaration is deprecated [-Wdeprecated-literal-operator]
  3946 | FMT_CONSTEXPR detail::udl_arg<wchar_t> operator"" _a(const wchar_t* s, size_t) {
       |                                        ~~~~~~~~~~~^~
       |                                        operator""_a
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:12:
 /src/runtime/Value.hpp:67:24: error: unknown type name 'Bytes'
    67 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:68:24: error: unknown type name 'Ellipsis'
    68 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:69:24: error: unknown type name 'NameConstant'
    69 |         bool operator==(const NameConstant &) const;
       |                               ^
 /src/runtime/Value.hpp:70:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    70 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:12:
 /src/runtime/Value.hpp:88:24: error: unknown type name 'Bytes'
    88 |         bool operator==(const Bytes &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:89:24: error: unknown type name 'Ellipsis'
    89 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:90:24: error: unknown type name 'NameConstant'
    90 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:92:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
    92 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:12:
 /src/runtime/Value.hpp:116:24: error: unknown type name 'Ellipsis'
   116 |         bool operator==(const Ellipsis &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:117:24: error: unknown type name 'NameConstant'
   117 |         bool operator==(const NameConstant &) const { return false; }
       |                               ^
 /src/runtime/Value.hpp:119:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   119 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:12:
 /src/runtime/Value.hpp:137:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   137 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:12:
 /src/runtime/Value.hpp:167:24: error: unknown type name 'Tuple'; did you mean 'ast::Tuple'?
   167 |         bool operator==(const Tuple &) const { return false; }
       |                               ^~~~~
       |                               ast::Tuple
 /src/ast/AST.hpp:244:7: note: 'ast::Tuple' declared here
   244 | class Tuple : public ASTNode
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1:
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.hpp:3:
 In file included from /src/ast/AST.hpp:9:
 In file included from include/c++/13/vector:66:
 include/c++/13/bits/stl_vector.h:993:50: error: arithmetic on a pointer to an incomplete type 'py::RtValue'
   993 |       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
       |                          ~~~~~~~~~~~~~~~~~~~~~~~ ^
 include/c++/13/bits/stl_vector.h:2041:19: note: in instantiation of member function 'std::vector<py::RtValue, py::GCTracingAllocator<py::RtValue>>::size' requested here
  2041 |     { return (__x.size() == __y.size()
       |                   ^
 /src/runtime/Value.hpp:192:62: note: in instantiation of function template specialization 'std::operator==<py::RtValue, py::GCTracingAllocator<py::RtValue>>' requested here
   192 |         bool operator==(const Tuple &other) const { return elements == other.elements; }
       |                                                                     ^
 /src/forward.hpp:33:7: note: forward declaration of 'py::RtValue'
    33 | class RtValue;
       |       ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>[4], llvm::SmallDenseMap<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/Metadata.h:395:58: note: in instantiation of template class 'llvm::SmallDenseMap<void *, std::pair<llvm::PointerUnion<llvm::MetadataAsValue *, llvm::Metadata *, llvm::DebugValueUser *>, unsigned long>>' requested here
   395 |   SmallDenseMap<void *, std::pair<OwnerTy, uint64_t>, 4> UseMap;
       |                                                          ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<llvm::AnalysisKey *, bool>[8], llvm::SmallDenseMap<llvm::AnalysisKey *, bool, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/PassManager.h:336:39: note: in instantiation of template class 'llvm::SmallDenseMap<llvm::AnalysisKey *, bool, 8>' requested here
   336 |       auto IMapI = IsResultInvalidated.find(ID);
       |                                       ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>>[2], llvm::SmallDenseMap<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>, 2>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/IR/PassManager.h:771:9: note: in instantiation of template class 'llvm::SmallDenseMap<llvm::AnalysisKey *, llvm::TinyPtrVector<llvm::AnalysisKey *>, 2>' requested here
   771 |         OuterAnalysisInvalidationMap;
       |         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/Support/ErrorOr.h:256:44: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<std::error_code>' requested here
   256 |     AlignedCharArrayUnion<std::error_code> ErrorStorage;
       |                                            ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/Support/Error.h:731:39: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<std::unique_ptr<llvm::ErrorInfoBase>>' requested here
   731 |     AlignedCharArrayUnion<error_type> ErrorStorage;
       |                                       ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<const llvm::Value *, bool>[8], llvm::SmallDenseMap<const llvm::Value *, bool, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/Analysis/AliasAnalysis.h:163:41: note: in instantiation of template class 'llvm::SmallDenseMap<const llvm::Value *, bool, 8>' requested here
   163 |   SmallDenseMap<const Value *, bool, 8> IsCapturedCache;
       |                                         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry>[8], llvm::SmallDenseMap<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry, 8>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/Analysis/AliasAnalysis.h:266:15: note: in instantiation of template class 'llvm::SmallDenseMap<std::pair<llvm::AACacheLoc, llvm::AACacheLoc>, llvm::AAQueryInfo::CacheEntry, 8>' requested here
   266 |   AliasCacheT AliasCache;
       |               ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 In file included from /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:2:
 In file included from /src/executable/mlir/Dialect/Python/IR/Dialect.hpp:3:
 In file included from /usr/lib/llvm-20/include/mlir/IR/Dialect.h:16:
 In file included from /usr/lib/llvm-20/include/mlir/IR/DialectRegistry.h:19:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:20:
 In file included from /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:19:
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: warning: 'aligned_union_t' is deprecated [-Wdeprecated-declarations]
    28 |   using AlignedUnion = std::aligned_union_t<1, T, Ts...>;
       |                             ^
 /usr/lib/llvm-20/include/llvm/Support/AlignOf.h:28:29: note: in instantiation of template type alias 'aligned_union_t' requested here
 /usr/lib/llvm-20/include/llvm/ADT/DenseMap.h:904:59: note: in instantiation of template class 'llvm::AlignedCharArrayUnion<llvm::detail::DenseMapPair<const llvm::Value *, unsigned int>[4], llvm::SmallDenseMap<const llvm::Value *, unsigned int>::LargeRep>' requested here
   904 |   AlignedCharArrayUnion<BucketT[InlineBuckets], LargeRep> storage;
       |                                                           ^
 /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:37:11: note: in instantiation of template class 'llvm::SmallDenseMap<const llvm::Value *, unsigned int>' requested here
    37 |   MapType Map;
       |           ^
 /usr/lib/llvm-20/include/llvm/ADT/MapVector.h:253:7: note: in instantiation of template class 'llvm::MapVector<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>, llvm::SmallDenseMap<const llvm::Value *, unsigned int>, llvm::SmallVector<std::pair<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>>, 4>>' requested here
   253 |     : MapVector<KeyT, ValueT, SmallDenseMap<KeyT, unsigned, N>,
       |       ^
 /usr/lib/llvm-20/include/llvm/Frontend/OpenMP/OMPIRBuilder.h:2320:9: note: in instantiation of template class 'llvm::SmallMapVector<const llvm::Value *, std::pair<llvm::Value *, llvm::Value *>, 4>' requested here
  2320 |         DevicePtrInfoMap;
       |         ^
 include/c++/13/type_traits:2601:27: note: 'aligned_union_t' has been explicitly marked deprecated here
  2601 |     using aligned_union_t _GLIBCXX23_DEPRECATED = typename aligned_union<_Len, _Types...>::type;
       |                           ^
 include/x86_64-linux-gnu/c++/13/bits/c++config.h:137:34: note: expanded from macro '_GLIBCXX23_DEPRECATED'
   137 | # define _GLIBCXX23_DEPRECATED [[__deprecated__]]
       |                                  ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:51:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    51 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:51:20: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    51 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:55:18: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    55 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:55:18: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    55 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:62:17: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    62 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:62:17: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    62 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:78:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    78 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:78:20: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    78 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:82:18: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    82 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:82:18: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    82 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:89:17: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    89 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:89:17: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
    89 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:105:20: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   105 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:105:20: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   105 |                 auto arr = names.cast<mlir::ArrayAttr>().getValue();
       |                                  ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:109:18: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   109 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:109:18: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   109 |                                         return attr.cast<mlir::StringAttr>().getValue() == name;
       |                                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:116:17: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   116 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:116:17: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   116 |                                 return attr.cast<mlir::StringAttr>().getValue();
       |                                             ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:397:42: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   397 |                 auto arr = parent->getAttr("cellvars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:397:42: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   397 |                 auto arr = parent->getAttr("cellvars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:399:16: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   399 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:399:16: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   399 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:410:42: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   410 |                 auto arr = parent->getAttr("freevars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:410:42: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   410 |                 auto arr = parent->getAttr("freevars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:412:16: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   412 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:412:16: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   412 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:480:42: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   480 |                 auto arr = parent->getAttr("cellvars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:480:42: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   480 |                 auto arr = parent->getAttr("cellvars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:482:16: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   482 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:482:16: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   482 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:492:42: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   492 |                 auto arr = parent->getAttr("freevars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:492:42: warning: 'cast<mlir::ArrayAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   492 |                 auto arr = parent->getAttr("freevars").cast<mlir::ArrayAttr>().getValue();
       |                                                        ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::ArrayAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:494:16: warning: 'cast' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   494 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:194:14: note: 'cast' has been explicitly marked deprecated here
   194 | U Attribute::cast() const {
       |              ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:494:16: warning: 'cast<mlir::StringAttr>' is deprecated: Use mlir::cast<U>() instead [-Wdeprecated-declarations]
   494 |                         return attr.cast<mlir::StringAttr>().getValue() == mlir::StringRef{ name };
       |                                     ^
 /usr/lib/llvm-20/include/mlir/IR/Attributes.h:65:5: note: 'cast<mlir::StringAttr>' has been explicitly marked deprecated here
    65 |   [[deprecated("Use mlir::cast<U>() instead")]]
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1440:9: error: no matching function for call to 'visit'
  1440 |         return std::visit(
       |                ^~~~~~~~~~
 include/c++/13/variant:1891:5: note: candidate template ignored: couldn't infer template argument '_Res'
  1891 |     visit(_Visitor&& __visitor, _Variants&&... __variants)
       |     ^
 include/c++/13/variant:1851:5: note: candidate template ignored: substitution failure [with _Visitor = overloaded<(lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1442:4), (lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1462:4), (lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1484:4), (lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1488:4), (lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1493:4), (lambda at /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1499:4)>, _Variants = <const py::Value &>]: no matching function for call to '__as'
  1115 |     visit(_Visitor&& __visitor, _Variants&&... __variants)
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1826:9: error: no matching function for call to 'holds_alternative'
  1826 |                         c && std::holds_alternative<py::String>(*c->value())) {
       |                              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 include/c++/13/variant:1141:5: note: candidate template ignored: could not match 'const variant<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1141 |     holds_alternative(const variant<_Types...>& __v) noexcept
       |     ^
 /src/executable/mlir/Dialect/Python/MLIRGenerator.cpp:1827:24: error: no matching function for call to 'get'
  1827 |                         current_string.s += std::get<py::String>(*as<ast::Constant>(value)->value()).s;
       |                                             ^~~~~~~~~~~~~~~~~~~~
 include/c++/13/bits/stl_pair.h:1059:5: note: candidate template ignored: could not match 'pair<py::String, _Up>' against 'const py::Value' (aka 'const py::RtValue')
  1059 |     get(pair<_Tp, _Up>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1064:5: note: candidate template ignored: could not match 'const pair<py::String, _Up>' against 'const py::Value' (aka 'const py::RtValue')
  1064 |     get(const pair<_Tp, _Up>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1069:5: note: candidate template ignored: could not match 'pair<py::String, _Up>' against 'const py::Value' (aka 'const py::RtValue')
  1069 |     get(pair<_Tp, _Up>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1074:5: note: candidate template ignored: could not match 'const pair<py::String, _Up>' against 'const py::Value' (aka 'const py::RtValue')
  1074 |     get(const pair<_Tp, _Up>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1079:5: note: candidate template ignored: could not match 'pair<_Up, py::String>' against 'const py::Value' (aka 'const py::RtValue')
  1079 |     get(pair<_Up, _Tp>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1084:5: note: candidate template ignored: could not match 'const pair<_Up, py::String>' against 'const py::Value' (aka 'const py::RtValue')
  1084 |     get(const pair<_Up, _Tp>& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1089:5: note: candidate template ignored: could not match 'pair<_Up, py::String>' against 'const py::Value' (aka 'const py::RtValue')
  1089 |     get(pair<_Up, _Tp>&& __p) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1094:5: note: candidate template ignored: could not match 'const pair<_Up, py::String>' against 'const py::Value' (aka 'const py::RtValue')
  1094 |     get(const pair<_Up, _Tp>&& __p) noexcept
       |     ^
 include/c++/13/tuple:1844:5: note: candidate template ignored: could not match 'tuple<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1844 |     get(tuple<_Types...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1855:5: note: candidate template ignored: could not match 'tuple<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1855 |     get(tuple<_Types...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1866:5: note: candidate template ignored: could not match 'const tuple<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1866 |     get(const tuple<_Types...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1878:5: note: candidate template ignored: could not match 'const tuple<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1878 |     get(const tuple<_Types...>&& __t) noexcept
       |     ^
 include/c++/13/variant:1150:5: note: candidate template ignored: could not match 'variant<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1150 |     get(variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1160:5: note: candidate template ignored: could not match 'variant<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1160 |     get(variant<_Types...>&& __v)
       |     ^
 include/c++/13/variant:1170:5: note: candidate template ignored: could not match 'const variant<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1170 |     get(const variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1180:5: note: candidate template ignored: could not match 'const variant<_Types...>' against 'const py::Value' (aka 'const py::RtValue')
  1180 |     get(const variant<_Types...>&& __v)
       |     ^
 include/c++/13/bits/stl_pair.h:1035:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1035 |     get(pair<_Tp1, _Tp2>& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1040:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1040 |     get(pair<_Tp1, _Tp2>&& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1045:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1045 |     get(const pair<_Tp1, _Tp2>& __in) noexcept
       |     ^
 include/c++/13/bits/stl_pair.h:1050:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
  1050 |     get(const pair<_Tp1, _Tp2>&& __in) noexcept
       |     ^
 include/c++/13/bits/ranges_util.h:438:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Num'
   438 |     get(const subrange<_It, _Sent, _Kind>& __r)
       |     ^
 include/c++/13/bits/ranges_util.h:449:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Num'
   449 |     get(subrange<_It, _Sent, _Kind>&& __r)
       |     ^
 include/c++/13/tuple:1803:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1803 |     get(tuple<_Elements...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1809:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1809 |     get(const tuple<_Elements...>& __t) noexcept
       |     ^
 include/c++/13/tuple:1815:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1815 |     get(tuple<_Elements...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1824:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1824 |     get(const tuple<_Elements...>&& __t) noexcept
       |     ^
 include/c++/13/tuple:1834:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '__i'
  1834 |     get(const tuple<_Elements...>&) = delete;
       |     ^
 include/c++/13/variant:1711:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1711 |     get(variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1722:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1722 |     get(variant<_Types...>&& __v)
       |     ^
 include/c++/13/variant:1733:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1733 |     get(const variant<_Types...>& __v)
       |     ^
 include/c++/13/variant:1744:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Np'
  1744 |     get(const variant<_Types...>&& __v)
       |     ^
 include/c++/13/array:384:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   384 |     get(array<_Tp, _Nm>& __arr) noexcept
       |     ^
 include/c++/13/array:393:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   393 |     get(array<_Tp, _Nm>&& __arr) noexcept
       |     ^
 include/c++/13/array:402:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   402 |     get(const array<_Tp, _Nm>& __arr) noexcept
       |     ^
 include/c++/13/array:411:5: note: candidate template ignored: invalid explicitly-specified argument for template parameter '_Int'
   411 |     get(const array<_Tp, _Nm>&& __arr) noexcept
       |     ^
 45 warnings and 17 errors generated.
 ninja: build stopped: subcommand failed.
[proc] 命令“/home/lux/soft/cmake/bin/cmake --build /build/debug --config Debug --target all --”已退出，代码为 1
[driver] 生成完毕: 00:00:15.492
 生成已完成，退出代码为 1
