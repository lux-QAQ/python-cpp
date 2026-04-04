按 next_refactor_plan.md 来看，当前大概只算完成了“阶段 1 的前半段”。

已经基本到位的部分：

Shape 已经不是 parent 链回溯了，属性读也接上了 attr IC，这部分方向是对的。
AOT 主 ABI 也已经切到 PyObject** + argc + kwargs。
还明显没完成的部分：

“阶段 1 后半段”没有做完：还缺真正的 setattr IC / 更轻的属性写路径。
“阶段 2”基本没做完：构造链和通用调用链还在大量回退到 PyTuple。
“阶段 3”只做了 cache 外壳，方法命中后仍然很厚。
“阶段 4”几乎没做：tagged int 还在频繁 box() 成 PyInteger。
“阶段 5”也没做：call_slot + std::function + descriptor wrapper 还在主路径上。
所以现在 6s 并不意外。重构已经把“旧 variant 大毒瘤”拆掉了一部分，但还没有把主路径 runtime tax 真正拿掉。

从 log.log 看到的真实瓶颈

最明显的不是单一热点，而是 4 条链一起在烧：

PyTuple 仍然是第一大分配源
log.log 里最后到了大约 1,740,000 个 PyTuple。调用栈直接指向 PyObject.cpp (line 1205) 的 fallback：
PyObject.cpp (line 1212)
PyObject.cpp (line 1217)
这里仍然会：

ensure_box(args[i])
构 Value[]
再 PyTuple::create(...)
再走 call(...)
这说明“ABI 变快了”，但“内部调用路径”还没变快。
只要这条 fallback 还挂在主路径上，PyTuple 就不可能降下来。

方法调用 PIC 还没真正打到“低成本命中”
log.log 里的主链是：
rt_call_method_ic_ptrs
rt_call_method_raw_ptrs
PyNativeFunction::call_fast_ptrs
PyObject::call_fast_ptrs
PyTuple::create
对应源码：

rt_method_cache.cpp (line 94)
rt_method_cache.cpp (line 164)
现在即使命中 PIC，也还是：

只缓存了“resolved callable”
命中后还要 prepend self
然后继续 resolved_func->call_fast_ptrs(...)
而这个 call_fast_ptrs 又经常掉进 PyFunction.cpp (line 308) 的基类 fallback
也就是说，PIC 目前更多是在“省查找”，还没有“省调用”。

PyNativeFunction 大量创建，说明 descriptor 绑定仍在疯狂分配
log.log 里 PyNativeFunction 到了大约 300,000 个，栈直接指向：
PyMethodDescriptor.cpp (line 95)
PyMethodDescriptor.cpp (line 97)
这里每次 descriptor.__get__ 都在新建一个 PyNativeFunction wrapper。
这和 plan 里的“阶段 3/5 未完成”完全一致：你现在的方法调用还不是“直接 call resolved target”，而是“先绑定成新对象，再调”。

这类分配对 self.to_list()、children.keys()、各种内建方法特别伤。

PyInteger 大量创建不是算术本身慢，而是 tagged int 被调用链强制装箱了
log.log 里 PyInteger 到了大约 300,000 个，栈非常明确：
RtValue.cpp (line 18)
RtValue.cpp (line 35)
PyObject.cpp (line 1214)
也就是：

参数本来是 tagged int
PyObject::call_fast_ptrs() fallback 里调用 ensure_box
RtValue::box() 生成 PyInteger
再塞进 tuple 调旧接口
所以 PyInteger 热点的根因不是“整数运算没有 tagged”，而是“调用 ABI 内部还没彻底 tagged-first”。

PyDict 很多，但它不全是“坏分配”
log.log 里 PyDict 到了大约 600,000 个，栈来自：
rt_create.cpp (line 74)
Node.__init__
这部分里有一部分是业务本身必须的：trie 每个节点一个 children = {}，字典创建数量本来就会大。
所以 PyDict 不能简单理解成“runtime 设计失败”。真正比 CPython 慢的，是每次 Node() 除了建 dict 之外，还顺带付了：

类型分配/构造链成本
__init__ 调用成本
属性写入/descriptor 成本
可能的 tuple/boxing 成本
为什么现在还跑不到 CPython 的 2s 左右

一句话：现在最贵的已经不是“算法”，也不是“属性读”，而是“对象构造 + 方法调用 + descriptor 绑定 + tuple fallback + int boxing”这一整条运行时框架链。

Shape 重写是必要的，但它只砍掉了“属性查找的一段”。
而你的 workload 里真正爆炸的是：

大量 Node() 构造
大量方法调用
大量内建 descriptor/bound-call
大量把 tagged int 硬转回 heap object
所以瓶颈已经从“阶段 1”自然移动到了“阶段 2/3/4/5”。

接下来最该做的顺序

先完成阶段 2：彻底去掉调用主路径里的 PyTuple fallback
优先改这几个点：
PyObject.cpp (line 1205)
PyObject.cpp (line 1269)
PyFunction.cpp (line 308)
PyMethodDescriptor.cpp (line 75)
PyMethodDescriptor.cpp (line 105)
目标是让：

普通函数调用
type.__call__ -> __new__ -> __init__
method descriptor 调用
都能直接走 PyObject**，不再中间落回 PyTuple*。

再完成阶段 3：让 method PIC 直接缓存“调用形态”，不要缓存“会继续分配的 callable 对象”
建议 MethodCache 直接区分：
native/aot function + prepend_self
method descriptor intrinsic
plain callable attribute
命中后应该直接调目标，不要再先造 PyNativeFunction wrapper。
否则 PyMethodDescriptor.cpp (line 95) 这一类分配永远压不下去。

再做阶段 4：把调用边界变成真正 tagged-first
现在最该改的不是先抠 RtValue::flatten()，而是先让调用链别去 PyObject.cpp (line 1214) 做 ensure_box。
只要 tuple fallback 还在，PyInteger 分配就会持续爆炸。

然后补阶段 1 的写路径
属性读已经接近 plan，属性写还没有。
Node.__init__ 是重灾区，应该补：

rt_setattr_ic
shape/slot 写缓存
尽量减少 __setattr__ 的慢路径检查次数
最后再瘦身 slot dispatch
当前 call_slot + std::function 仍在 __getattribute__ / descriptor 路径上明显可见。
这属于阶段 5，可以放在 tuple-free 和 method PIC 之后。

一个很重要的提醒

你现在这份 log.log 本身带了 debug alloc trace，里面反复进 _pylang_debug_log_alloc。这份日志很适合“看对象创建来源”，但不适合直接当最终性能基准。
所以建议两套配置分开：

分析版：保留 alloc trace，只看热点来源
跑分版：彻底关掉 trace/logging，再和 CPython 比
最核心的结论

现在不是 Shape 还不够快，而是它已经不再是第一瓶颈了。
真正该继续推进的是：

收掉 PyObject::call_fast_ptrs() 的 tuple fallback
收掉 PyType::call_fast_ptrs() 的 tuple 构造
收掉 PyMethodDescriptor::__get__ 里的 PyNativeFunction 分配
让 method PIC 命中后直接调用，而不是继续走 raw path/fallback
让 tagged int 不再因为调用链被强制 box()
如果你愿意，我下一步可以不只分析，直接开始做“阶段 2”的第一刀：把 PyObject.cpp (line 1205) 和 PyObject.cpp (line 1269) 这两条主 fallback 改掉。