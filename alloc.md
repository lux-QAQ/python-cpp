已完成: *Write comprehensive analysis & solutions* (4/4)

## 完整分析：log.log 中所有 Stack trace 分类与优化方案

### 一、最终分配统计（截止程序运行结束）

| 类型 | 总分配量 | 严重程度 |
|---|---|---|
| **PyTuple** | ~40,000,000+ | **极严重** |
| **PyDict** | ~11,000,000 | 严重 |
| **Type (heap PyObject)** | ~11,000,000 | 严重 |
| **PyNativeFunction** | ~10,000,000 | 严重 |
| **PyInteger** | ~6,500,000 | 中等 |
| **PyStringIterator** | ~6,000,000 | 中等 |
| **PyTupleIterator** | ~1,000,000 | 中等 |
| **PyDictItems/Iterator** | ~500,000 | 低 |

---

### 二、所有 Stack trace 来源分类

#### Stack Trace 类型 A — PyTuple (占比最高，~40M，5个不同来源)

**A1: `PyNativeFunction::call_fast_ptrs` → 方法调用参数打包** (最高频)
```
PyTuple::create (PyTuple.cpp:120)
  ← PyNativeFunction::call_fast_ptrs (PyFunction.cpp:334)
    ← rt_call_raw_ptrs (rt_func.cpp:222)
      ← rt_call_method_raw_ptrs / rt_call_method_ic_ptrs
        ← Sieve.to_list / find / generate_trie / run_stress_test
```
**根因**：PyFunction.cpp 中每次 `call_fast_ptrs` 从 `PyObject**` 调用没有 `m_aot_ptr` 的 FreeFunctionType（即 Python 绑定方法）时，必须先把 `args` 数组打包成 `PyTuple`，再调 `operator()(tuple, kwargs)`。**每次方法调用都分配一个 PyTuple**。

**A2: `PyType::call_fast_ptrs → new_` → 构造对象参数打包**
```
PyTuple::create (PyTuple.cpp:120)
  ← PyType::call_fast_ptrs (PyObject.cpp:1301)
    ← rt_call_raw_ptrs
      ← generate_trie.70:0   （Node() 构造）
```
**根因**：PyObject.cpp 中 `PyType::call_fast_ptrs` 的第3段回退路径：有参数时必须打包成 `PyTuple` 给 `new_()`。这里每次创建 `Node()` 对象都走这条路。

**A3: `PySlotWrapper::call_fast_ptrs` → `__init__` 参数打包**
```
PyTuple::create (PyTuple.cpp:120)
  ← PySlotWrapper::call_fast_ptrs (PySlotWrapper.cpp:97)
    ← PyObject::init_fast_ptrs (PyObject.cpp:1341)
      ← PyType::call_fast_ptrs (PyObject.cpp:1312)
        ← generate_trie.70:0   （Node.__init__(self) 调用）
```
**根因**：PySlotWrapper.cpp 在 `__init__` slot 被调用时，有参数（self 之外的）时仍然分配 PyTuple。

**A4: `PyMethodDescriptor::__get__` 产生的闭包内再分配 PyTuple**
```
PyTuple::create (PyTuple.hpp:69)
  ← PyMethodDescriptor::__get__::$_0 (PyMethodDescriptor.cpp:146)
    ← PyNativeFunction::operator() (PyFunction.hpp:180)
      ← PyNativeFunction::call_fast_ptrs (PyFunction.cpp:335)
        ← Sieve.to_list.14:4
```
**根因**：PyMethodDescriptor.cpp 中 `__get__` 每次被调用都创建一个 `PyNativeFunction` 闭包，闭包内部再将参数打包成带 self 前缀的新 PyTuple 转发给 `__call__`。**双倍分配**：先分配 PyNativeFunction，闭包内再分配 PyTuple。

**A5: `PyMethodDescriptor::__call__` 内部再次打包 args**
```
PyTuple::create (PyMethodDescriptor.cpp:76)
  ← PyMethodDescriptor::__call__
    ← (通过 A4 闭包调用)
```

#### Stack Trace 类型 B — PyNativeFunction (~10M)

**B1: `PyMethodDescriptor::__get__` 每次属性访问都创建绑定方法**
```
PyNativeFunction::create (PyFunction.hpp:124)
  ← PyMethodDescriptor::__get__ (PyMethodDescriptor.cpp:136)
    ← PyObject::get (PyObject.cpp:1197)
      ← PyObject::__getattribute__ (PyObject.cpp:1455)
        ← getattribute (PyObject.cpp:668)
          ← rt_call_method_raw_ptrs (rt_func.cpp:246)
            ← rt_call_method_ic_ptrs (rt_method_cache.cpp:116)  ← CACHE MISS
              ← Sieve.to_list.14:4
```
**根因**：当 inline cache **miss** 时 (`rt_call_method_ic_ptrs` 第116行 fallback 到 `rt_call_method_raw_ptrs`) → `getattribute` → `PyMethodDescriptor::__get__` → **每次分配一个 PyNativeFunction 作为绑定方法包装器**。这说明**方法缓存频繁 miss**。

`to_list` 里的 `self.prime[p]` 在运行时是对 `list.__getitem__` 的调用。缓存写入的是 `update_method_cache`，但该函数 **不缓存 PyMethodDescriptor 类型的描述符**（只缓存 `function`/`native_function`/非数据非描述符）。所以 `list.append`、`list.__getitem__` 每次都 miss！

#### Stack Trace 类型 C — PyDict (~11M)

**C1: `Node.__init__` 中 `self.children = {}` 每次创建 Node 都分配一个空 PyDict**
```
PyDict::create (PyDict.cpp:52)
  ← rt_build_dict (rt_create.cpp:74)
    ← Node.__init__.4:4
      ← PyNativeFunction::call_fast_ptrs
        ← PyObject::init_fast_ptrs
          ← PyType::call_fast_ptrs
            ← generate_trie.70:0
```
**根因**：`self.children = {}` 编译成 `rt_build_dict(0, ...)` → `PyDict::create()`。在 `generate_trie` 中每个质数的每个字符都可能创建 `Node()`，每个 Node 都带一个新的空 `PyDict`。这是业务逻辑固有的需求，但可以用 object pool 优化。

#### Stack Trace 类型 D — Type (heap PyObject 实例) (~11M)

**D1: `TypePrototype::create<PyObject>` 的 `__alloc__` 每次构造 Node 时分配**
```
TypePrototype::create<PyObject>::__alloc__ (PyObject.hpp:596)
  ← PyType::heap_object_allocation (PyType.cpp:486)
    ← PyType::call_fast_ptrs (PyObject.cpp:1278)
      ← generate_trie.70:0
```
**根因**：每次 `Node()` 创建都通过 `heap_object_allocation` 分配一个 `PyObject` 实例。这也是业务固有的，但可以用 arena/slab 优化。

#### Stack Trace 类型 E — PyInteger (~6.5M)

**E1: `RtValue::box()` 拆箱回 PyInteger**
```
PyInteger::create (PyInteger.cpp:50)
  ← PyInteger::create(long) (PyInteger.cpp:45)
    ← RtValue::box() (RtValue.cpp:35)
      ← PyObject::from<RtValue> (PyObject.cpp:382)
        ← PyArgsParser::unpack_tuple_helper (PyArgParser.hpp:36)
          ← PyMethodDescriptor::__call__
            ← (list.append 的绑定方法闭包)
              ← Sieve.to_list.14:4
```
**根因**：已有 tagged integer 的值被 `PyArgsParser` 解包时，通过 `RtValue::box()` 强制装箱成 `PyInteger` heap 对象。这发生在 `list.append(p)` 调用中——`p` 是 tagged int，但 `unpack_tuple_helper` 要求 `PyObject*` 类型，于是每次都 box。

#### Stack Trace 类型 F — PyStringIterator (~6M)

**F1: `for ch in s_el` 每次遍历字符串都分配**
```
PyStringIterator (PyString.cpp:1433)
  ← PyString::__iter__
    ← PyObject::iter (PyObject.cpp:1174)
      ← rt_get_iter (rt_subscr.cpp:23)
        ← generate_trie.70:0
```
**根因**：`for ch in s_el`（s_el 是 `str(el)`）每次都创建一个 `PyStringIterator`。348513 个质数 × 每个质数遍历一次 × 多次调用 `find()` = 几百万次。

#### Stack Trace 类型 G — PyTupleIterator (~1M)

来源：`for ch, v in top.children.items()` 中的元组解包，`items()` 返回的每个 `(key, value)` 对被包装成 `PyTuple`，然后迭代。

---

### 三、根因总结与优化方案

#### 核心问题 1：`call_fast_ptrs` 系列函数都把 `PyObject**` 重新打包成 `PyTuple`

**几乎所有** `call_fast_ptrs` 的实现最终都回退到旧的 `operator()(PyTuple*, PyDict*)` 接口，导致必须构建 `PyTuple`。

**解决方案：给 MethodType/FreeFunctionType 增加 raw pointer 调用路径**

在 `PyMethodDescriptor` 和 `PySlotWrapper` 中：
1. `PyMethodDescriptor::call_fast_ptrs` 已经有直接路径，但它内部的 `m_method->get().method(self, args, kwargs)` 仍然需要 `PyTuple*`。应该给 `MethodSlot` 增加一个 `method_raw(PyObject* self, PyObject** args, size_t argc, PyDict* kwargs)` 接口。
2. `PySlotWrapper::call_fast_ptrs` 同理。

#### 核心问题 2：`PyMethodDescriptor::__get__` 每次创建 `PyNativeFunction` 绑定方法

**解决方案：BoundMethod 缓存或 inline 直调**

你的 `rt_call_method_raw_ptrs` 和 `rt_call_method_ic_ptrs` 已经对 `function`/`native_function`/`method_wrapper`/`slot_wrapper` 做了直调优化。但 **`PyMethodDescriptor` 类型不在此列**。

具体修复：在 `rt_call_method_raw_ptrs` 和 cache 的 `update_method_cache` 中，**增加对 `PyMethodDescriptor` 的识别**，直接调用 `desc->call_fast_ptrs(final_args_with_self, total_argc, kwargs)`，完全跳过 `__get__`。

#### 核心问题 3：PyInteger 频繁装箱

**解决方案**：在 `list.append` 的 fast path 中，直接接受 `RtValue` 而不是强制 box。实际上 `list.append` 的 intrinsic fast path 已经在 `rt_call_method_raw_ptrs` 中实现了。问题在于这条路径没被命中（因为通过 `PyMethodDescriptor::__get__` 闭包的迂回路径调用了 `list.append`），一旦问题2修复，大量 PyInteger 分配也会消失。

#### 核心问题 4：Node 实例化过重

每个 `Node()` 的创建路径：
1. `PyType::call_fast_ptrs` → 分配 PyObject 实例（Type 分配）
2. 回退路径打包 PyTuple（A2 分配）
3. `init_fast_ptrs` → `PySlotWrapper::call_fast_ptrs` → 又打包 PyTuple（A3 分配）
4. `Node.__init__` 里 `self.children = {}` → PyDict 分配（C1）
5. `self.terminal = False` → setattr

**一次 `Node()` 产生 4-5 次堆分配**。

**解决方案**：
1. 对无参 `__init__` 的用户定义类，编译器可生成专用 `rt_create_instance_fast` 直接调用 `__alloc__` + `__init__` 跳过所有 tuple 打包。
2. `PyType::call_fast_ptrs` 的优化路径（第2段，L1275-1290）应扩展覆盖更多情况：当类型的 `__new__` 是 object.__new__ 时（即用户无自定义 __new__），直接 `__alloc__` + `init_fast_ptrs`，完全不打包 tuple。

#### 核心问题 5：PyStringIterator 频繁分配

**解决方案**：对 `for ch in some_string` 模式，编译器可以生成 specialization：直接用索引循环 `str[i]` 而不是创建 iterator 对象。或者在 runtime 中添加 `rt_string_char_at(str, index)` 直接返回单字符。

---

### 四、优化实施优先级建议

| 优先级 | 修复内容 | 预计减少分配量 |
|---|---|---|
| **P0** | `rt_call_method_raw_ptrs` / cache 增加 `PyMethodDescriptor` 直调 | -10M PyNativeFunction, -15M+ PyTuple |
| **P0** | `PyNativeFunction::call_fast_ptrs` 非 AOT 路径避免打包 PyTuple — 让 FreeFunctionType 支持 raw ptrs | -10M+ PyTuple |
| **P1** | `PyType::call_fast_ptrs` 扩展零 Tuple 路径覆盖有参情况 | -5M PyTuple |
| **P1** | `PySlotWrapper::call_fast_ptrs` 避免有参情况的 PyTuple 分配 | -3M PyTuple |
| **P2** | PyStringIterator 使用 object pool 或编译器 specialization | -6M PyStringIterator |
| **P2** | PyInteger box 消除（修复 P0 后自动大幅减少） | -6M+ PyInteger |
| **P3** | Node 实例化 object pool / slab allocator | -11M Type + PyDict |

---

### 五、最高优先级 P0 修复：让 method cache 缓存 PyMethodDescriptor

想从代码层面立即实施哪些修复？我建议先做 P0——修改 `rt_call_method_raw_ptrs` 和 `update_method_cache` 来识别 `PyMethodDescriptor`，直接绕过 `__get__`。这一个改动就能消灭约 **10M PyNativeFunction** + **15M+ PyTuple** 的分配（因为去掉了 `__get__` 产生的闭包路径上的二次 tuple 打包）。是否要我立即实施这些修改？