# Pylang Runtime 下一阶段重构执行计划

基于以下文档与当前代码状态整理：

- `refactor_variant.md`
- `refactor_check.md`
- `perfdoc_v4.md`

本文档的目标不是重复理想设计，而是回答一个更实际的问题：

> 在当前代码已经部分重构的前提下，接下来应该按什么顺序继续做，才能最快把 `test.py` 的热点压下去，并让架构逐步靠近最终状态。

---

## 一、当前状态总结

### 已经完成或基本完成的部分

1. `forward.hpp` 已经将 `Value` 收敛为 `RtValue`
2. AOT 到 Runtime 的主调用 ABI 已经大体切换到 `PyObject** + argc + kwargs`
3. 前端没有把 PIC 判断逻辑硬编码进 IR
4. `IREmitter::call_method_ic_ptrs()` 已经为每个 callsite 生成独立 cache 全局变量
5. `getattr_fast` / `setattr_fast` 已经开始使用 interned `PyString*`
6. `PyDict` / `PyTuple` / `PyList` 的底层元素类型已经不再是旧的超重 variant

### 还没有完成、且正在主路径上拖慢性能的部分

1. `Shape` 仍然是链式查找，`lookup()` 不是 O(1) offset 命中
2. 属性访问还没有形成“callsite attr cache -> shape/offset”体系
3. 方法 PIC 的 guard 还不完整，命中后仍会重复做实例遮蔽检查和参数重拼装
4. `PyType::call_fast_ptrs()` / `PyObject::call_fast_ptrs()` 仍有明显 tuple fallback
5. `call_slot()` 仍保留 `std::variant<std::function<...>, PyObject*>` 的厚调度层
6. 小整数仍频繁退化成 `PyInteger/GMP` 再被 `flatten()`
7. 当前 profile 很可能还是 Debug / 带 instrumentation 的，不适合和 CPython release 直接对比

---

## 二、总原则

后续重构顺序必须遵守以下原则：

1. 先砍掉 `test.py` 主热点，再做“架构纯化”
2. 先做不改变前端 IR 语义的 runtime 内部重构
3. 每一步都要有明确 benchmark 和回归验证
4. 不要一次性同时改 `Shape`、PIC、slot dispatch、容器和 codegen
5. 每个阶段必须留下可工作的中间状态

---

## 三、推荐工作顺序

建议按下面 6 个阶段执行。

顺序不是按“设计最优雅”，而是按“收益/风险/依赖关系”平衡后的执行顺序。

---

## 阶段 1：先把对象属性路径做成真正快路径

### 目标

优先解决 `generate_trie()` 和 `Node.__init__()` 的热点。

### 为什么它应该排第一

从 `refactor_check.md` 和你的 profile 看，当前真正吃时间的是：

- `rt_setattr_fast`
- `PyObject::__setattribute__`
- `Shape::transition`
- `PyType::lookup`

也就是说，`test.py` 现在最痛的不是“函数调一次贵”，而是“对象属性太厚”。

### 这一阶段要做什么

#### 1. 重写 `Shape`

把当前的：

- `parent + property_name + offset`
- `transition()` 时 `unordered_map` 创建下级 shape
- `lookup()` 沿 parent 链回溯

改成更适合 runtime 快路径的结构。

建议目标形态：

1. `Shape` 内部直接维护 `name -> offset`
2. `Shape` 维护 `version`
3. `transition(name)` 仍可共享结构，但 lookup 不能再靠 parent 链
4. 为高频对象类型准备 root shape 复用策略

#### 2. 增加属性 callsite cache

新增类似 `rt_attr_cache.cpp` 的导出层，提供：

- `rt_getattr_ic(cache, obj, name_obj/name_cstr)`
- 可选 `rt_setattr_ic(...)`

cache 建议至少包含：

- `expected_shape`
- `slot_offset`
- `kind`
- `version` 或等价 invalidation 信息

#### 3. 让 codegen 用 attr IC

当前 `IREmitter::call_getattr()` 仍直连 `getattr_fast`。

这一阶段之后应该改成：

1. 每个 attr load site 生成独立 cache global
2. 统一调用 runtime export 的 attr IC
3. cache miss 时由 runtime 完成慢路径与 cache 更新

#### 4. 明确实例属性与 descriptor 的 guard 语义

必须保持 Python 3.9 语义：

1. data descriptor 优先于实例属性
2. 非 data descriptor 允许被实例属性遮蔽
3. 类型属性变更时 cache 失效

### 建议先优化的场景

1. `self.limit`
2. `self.prime`
3. `head.children`
4. `head.terminal`

### 验收标准

1. `generate_trie` 热点里 `Shape::transition` 占比明显下降
2. `rt_getattr_fast` / `PyType::lookup` 占比明显下降
3. 语义回归通过：descriptor、实例遮蔽、monkey patch 都不出错

---

## 阶段 2：收紧对象构造路径，去掉 `tuple` 回退

### 目标

把 `Node()`、`dict()`、普通类实例化的主路径从“半 fast path”推进到“纯 fast path”。

### 当前问题

虽然外部 ABI 已经是 `PyObject**`，但内部还存在：

1. `PyType::call_fast_ptrs()` 先把 `args` 包成 `PyTuple`
2. `new_` / `init` 部分路径还是围绕 `PyTuple`
3. `PyObject::call_fast_ptrs()` 仍保留通用 fallback：`Value[] -> PyTuple -> call()`

### 这一阶段要做什么

#### 1. 为构造链补齐真正的 fast ABI

建议新增或统一以下接口：

1. `new_fast_ptrs(...)`
2. `init_fast_ptrs(...)`
3. 必要时 `call_tp_new_fast_ptrs(...)`

目标是让：

`PyType::call_fast_ptrs -> __new__ -> __init__`

整个链条都尽量不生成临时 `PyTuple`。

#### 2. 缩小 `PyObject::call_fast_ptrs()` fallback 的使用面

把它从“正常通路”降为“少数未重构类型的保底逻辑”。

#### 3. 梳理哪些内建类型还依赖 `PyTuple`

优先处理：

1. `type`
2. `dict`
3. `list`
4. 用户类实例化

### 验收标准

1. `generate_trie -> Node()` 这一支 profile 中，`PyTuple::create` 热点明显下降
2. `PyType::call_fast_ptrs` 自身开销明显下降

---

## 阶段 3：完善方法 PIC，不再只是“有 cache 壳子”

### 目标

把当前方法 PIC 从“框架存在”推进到“真正低成本命中”。

### 当前问题

当前 `rt_call_method_ic_ptrs()` 的问题主要有：

1. guard 不完整
2. 命中后还要 `shape->lookup(name)` 检查实例遮蔽
3. 仍要动态拼装 `self + args`
4. miss 后仍回到较厚的 `rt_call_method_raw_ptrs`

### 这一阶段要做什么

#### 1. 重设计 `MethodCache`

建议至少保存：

1. `expected_type`
2. `type_version`
3. `expected_shape` 或实例属性版本信息
4. `resolved_func`
5. `call_kind`
6. `prepend_self`

如果 attr cache 已经先完成，可以直接让 method PIC 依赖 attr cache 的结果。

#### 2. 区分几种 method call fast path

1. class function / native function，需要 prepend `self`
2. 非 descriptor callable，不需要 prepend `self`
3. builtin intrinsic，例如 `list.append`、`set.add`

#### 3. 降低命中成本

命中时避免：

1. 重做类型查找
2. 重做实例遮蔽查找
3. 创建临时 `PyTuple`

#### 4. 只让 runtime 负责 cache

前端仍然保持透明：

1. 分配静态 cache
2. 调 runtime export
3. 不在 IR 中内联任何 guard 分支

### 验收标准

1. `self.step1/step2/step3` 这类热点里，`rt_call_method_ic_ptrs` 自身占比明显下降
2. `rt_call_method_raw_ptrs` 退居冷路径

---

## 阶段 4：把整数热路径做成真正 tagged-first

### 目标

减少 `RtValue::flatten -> PyInteger::as_big_int -> GMP` 这种热点链。

### 当前问题

现在的小整数虽然支持 tagged，但并没有端到端保持：

1. 某些运算结果仍会 box 成 `PyInteger`
2. 比较和取模前又要 `flatten()`
3. `flatten()` 一旦遇到 `PyInteger`，又会进 GMP 取值

### 这一阶段要做什么

#### 1. 梳理哪些导出函数仍在频繁 box/unbox

重点看：

1. `rt_cmp.cpp`
2. `rt_op.cpp`
3. `rt_subscr.cpp`
4. `rt_create.cpp`

#### 2. 建立“tagged-first”的边界策略

原则：

1. 热路径优先保留 `RtValue`
2. 只有在对象协议要求时才 box
3. 对 int/bool 的比较、算术、索引尽量不进 `PyInteger`

#### 3. 优化 `PyInteger`

如果对象已经是“小整数可表示”的 `PyInteger`，应尽量避免每次取值都走 GMP 拷贝语义。

可以考虑：

1. 给 `PyInteger` 增加 cheap path
2. 缓存 small-int 表示
3. 区分 small-int 与 big-int 内部布局

### 验收标准

1. profile 中 `PyInteger::as_big_int` 和 `__gmpz_init_set` 占比明显下降
2. `step1/step2/step3` 中整数比较和取模更集中在 `RtValue` 层

---

## 阶段 5：瘦身 slot 调度层

### 目标

压缩 `call_slot()` 的框架成本。

### 当前问题

`call_slot()` 仍然基于：

- `std::variant<std::function<...>, PyObject*>`

一旦进入 `PyObject*` 分支，经常会：

1. 构造 `PyTuple`
2. 走通用 `call`
3. 带来额外的动态分派与分配

### 这一阶段要做什么

#### 1. 区分 runtime-native slot 和 python-level slot

建议将 slot 表示拆成更轻的结构，而不是继续依赖 `std::function`。

方向可以是：

1. 原生函数指针
2. 描述符对象
3. 必要时 method wrapper

#### 2. 对高频 slot 先做特化

优先考虑：

1. `__getattribute__`
2. `__setattr__`
3. `__getitem__`
4. `__setitem__`
5. 比较类 slot

### 验收标准

1. profile 中 `call_slot` 占比下降
2. `PyObject*` 分支触发次数显著减少

---

## 阶段 6：最后再做“全面架构纯化”

### 目标

把剩余历史兼容层彻底清理掉。

### 这一阶段要做什么

1. 清理 `call_raw` 残留接口
2. 清理 `std::span<Value>` / `std::vector<Value>` 风格旧签名
3. 清理仅用于过渡期的 fallback
4. 统一 tuple/list/dict/set 的热路径元素模型
5. 重新梳理解释器模式和 AOT 模式共用的最小抽象

### 为什么要放最后

这一阶段工程量大，但对 `test.py` 这种 workload 的直接收益通常不如前 4 个阶段。

---

## 四、推荐的首批落地任务

如果接下来只做最值得先动手的 5 项，我建议是：


2. 重写 `Shape` lookup 结构，让属性查找不再走 parent 链
3. 新增 attr callsite cache，并让 codegen 的 `call_getattr()` 走 attr IC
4. 去掉 `PyType::call_fast_ptrs()` 的 tuple 构造主路径
5. 优化小整数热路径，减少 `PyInteger/GMP` 回退

---

## 五、每阶段建议的验证项

每完成一个阶段，都至少验证下面 4 类用例：

### 1. 语义回归

1. descriptor 优先级
2. 实例属性遮蔽方法
3. monkey patch 后 cache 正确失效
4. `__getattribute__` / `__setattr__` 自定义类行为正确

### 2. AOT 回归

1. 普通函数调用
2. 方法调用
3. 类实例化
4. 闭包

### 3. 容器回归

1. `dict/list/tuple/set` 基本操作
2. `in` / `getitem` / `setitem`
3. `keys/items/get`

### 4. 性能回归

至少保留这几个 benchmark：

1. 当前 `test.py`
2. 一个属性读写密集 microbenchmark
3. 一个方法调用密集 microbenchmark
4. 一个整数运算密集 microbenchmark

---

## 六、建议的实际执行节奏

### 第一周

1. 做阶段 0
2. 重写 `Shape`
3. 设计 attr cache 数据结构

### 第二周

1. 落地 `rt_getattr_ic`
2. 接入 `IREmitter::call_getattr`
3. 跑回归和 benchmark

### 第三周

1. 收紧 `PyType::call_fast_ptrs`
2. 清理构造链上的 `PyTuple` 主路径

### 第四周

1. 完善 method PIC
2. 处理小整数 tagged 热路径

---

## 七、最终判断标准

如果重构方向是对的，那么后续 profile 应该呈现出下面的变化：

1. `Shape::transition` 和 `Shape::lookup` 不再是主热点
2. `PyType::lookup` 占比下降
3. `PyTuple::create` / `std::vector<Value>` 热点下降
4. `rt_call_method_raw_ptrs` 下降到冷路径
5. `PyInteger::as_big_int` / `__gmpz_init_set` 显著下降
6. 主热点逐渐转移到真正的业务逻辑循环，而不是 runtime 框架本身

如果这 6 条没有出现，说明重构仍然停留在“接口形式变化”，还没有真正把成本从主路径上拿掉。

