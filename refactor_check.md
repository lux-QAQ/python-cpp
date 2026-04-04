重构做了很多，但还不能算“彻底完成”。Value -> RtValue 和 AOT 的 PyObject** 调用 ABI 已经落地了一大半，不过真正决定 test.py 性能的那部分对象模型还没有进入你文档里设想的最终形态，所以热点从“旧 variant 传参”转移到了“对象属性/构造/slot 调度/小整数装箱”上。

最关键的证据：

Shape/slots 还是半成品，不是文档里的“shape + offset cache”终态。src/runtime/shape/Shape.hpp (line 30) 的 transition 仍然是 unordered_map + new Shape，而 src/runtime/shape/Shape.hpp (line 40) 的 lookup 还是沿 parent 链线性回溯。rt_getattr_fast/rt_getattr 每次访问属性都还在做这次 lookup，而不是命中“callsite -> slot offset”的缓存。src/runtime/export/rt_attr.cpp (line 24) src/runtime/export/rt_attr.cpp (line 67)

方法 PIC 也没有达到 perfdoc_v4.md 里那种完整 guard。当前 cache 只有 expected_type/type_version/attr_name/resolved_func/tag，没有实例字典/shape version guard。src/runtime/export/cache/rt_cache.hpp (line 17) 命中后仍然要额外做一次 shape->lookup(name)，并且每次重新拼 self + args 数组。src/runtime/export/cache/rt_method_cache.cpp (line 120) 这说明 PIC 框架有了，但还不是文档里的“彻底完成态”。

调用链并没有完全 tuple-free。基类 fallback 还会把 PyObject** 重新包装成 Value[] 和 PyTuple。src/runtime/PyObject.cpp (line 1205) 类型调用 PyType::call_fast_ptrs 也仍然先构 PyTuple 再走 new_。src/runtime/PyObject.cpp (line 1269) 这也是为什么 Node()/dict() 这种大量构造在 generate_trie 里依然贵。

你去掉了 py::Value 这个旧 variant，但 runtime 里还有另一层很重的 std::variant<std::function<...>, PyObject*> slot 调度。call_slot 一旦走 PyObject* 分支，就会临时构 PyTuple、再走通用 call。src/runtime/PyObject.cpp (line 117) 这和 profile 里的 call_slot 热点是对上的。

现在的二进制大概率还是调试/带 instrumentation 的，不适合和 CPython release 直接比。_pylang_debug_log_alloc 只会在 #ifndef NDEBUG 下编进来，src/runtime/compat.hpp (line 5) 而它已经出现在你的 profile 里；同时 src/runtime/PyFunction.cpp (line 259) 里每次 call_fast_ptrs 还有 spdlog::debug。这本身就会明显拉低跑分。

test.py 的慢点已经不是“函数调用 ABI”本身，而是对象模型成本。你的 profile 里 generate_trie -> Node.__init__ -> rt_setattr_fast -> PyObject::__setattribute__ -> Shape::transition 很重，这和实现完全一致。src/runtime/PyObject.cpp (line 1582) src/runtime/shape/Shape.hpp (line 30) Node 每创建一次就要建 children dict、写 terminal、扩 shape；CPython 这套路径是极度成熟的 C 实现，你这里还在走通用 descriptor/type lookup/GC 容器。

小整数也没有保持“端到端 tagged”。你的热点里有 rt_compare_le -> RtValue::flatten -> PyInteger::as_big_int -> __gmpz_init_set，而 src/runtime/taggered_pointer/RtValue.cpp (line 65) 的 flatten 对 boxed int 仍然要进 PyInteger/GMP 路径。说明算术结果或比较输入仍经常退化成 heap integer，再被 flatten 回来，这非常伤循环性能。

为什么现在还比 CPython 慢

不是一个单点问题，而是三个大头叠加：

你优化的是“跨 ABI 调用”，但 test.py 的大头在 Node 大量创建、属性写入、dict 访问、list/tuple 构造、字符串/整数操作。
这些路径里当前 runtime 仍然有 PyType::lookup MRO 扫描、Shape::transition 分配、call_slot 通用调度、PyTuple 构造、GMP 小整数回退。
CPython 在这个脚本上吃的是成熟的 C 容器实现和 specializing interpreter；你这里虽然有 AOT，但运行时对象模型还比 CPython“厚”很多，所以 AOT 的收益被 runtime tax 吃掉了。
我建议的优先级

先确认是 Release 构建，去掉 NDEBUG 外的分配日志和 spdlog::debug。
先做真正的属性 callsite cache：(expected_shape, slot_offset)，别每次 shape->lookup。
把 Node()/dict() 这类构造路径做成真正 tuple-free，不要在 src/runtime/PyObject.cpp (line 1269) 回退到 PyTuple。
让小整数算术/比较保持 tagged 到底，避免 flatten -> PyInteger::as_big_int()。
再看 method PIC；它现在不是主瓶颈第一名了。
如果你愿意，我下一步可以直接按这份分析给你列一个“最值得先改的 5 个点”，并且按收益/工作量排序。