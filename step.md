# Pylang 去 Variant 重构 - 第一阶段：拆解 Value.hpp

本阶段的核心目标是将 Value.hpp 中的 Number、String、Bytes 等辅助类彻底移除，并将其逻辑功能分别迁移到对应的 PyInteger/PyFloat、PyString 和 PyByteArray/PyBytes 类中。

## 步骤一：将 Number 类的逻辑迁移至 PyInteger 和 PyNumber

Number 类封装了整数和浮点数的算术运算。我们需要将这些运算逻辑直接实现在 PyInteger 和 PyNumber 上。

1.  **PyInteger.hpp**:
    -   为 PyInteger 添加 __and__, __or__, __xor__ 的成员函数声明。

2.  **PyInteger.cpp**:
    -   实现 __and__, __or__, __xor__。这些函数现在应该直接操作底层的 mpz_class (BigIntType)，而不是像之前那样只处理 int64_t。这将支持对任意大小的整数进行位运算。

3.  **PyNumber.cpp**:
    -   PyNumber 是 PyInteger 和 PyFloat 的基类，它已经有了 __add__, __sub__ 等算术运算符的实现。检查这些实现，确保它们正确地处理了 PyInteger 和 PyFloat 之间的交互。当前实现依赖于 Number 类的 std::visit，暂时保持不变，后续步骤会清理。

## 步骤二：将 Bytes 类的逻辑迁移至 PyBytes 和 PyByteArray

Bytes 类处理字节序列。其功能需要被 PyBytes (不可变) 和 PyByteArray (可变) 吸收。

1.  **PyBytes.hpp / PyByteArray.hpp**:
    -   确认这两个类已经包含了 m_value 成员（类型为 Bytes，内部是 std::vector<std::byte>)。
    -   确认它们已经暴露了 value() 方法来访问这个成员。

2.  **PyBytes.cpp / PyByteArray.cpp**:
    -   检查 __add__ (拼接), __getitem__ (索引/切片), __len__ 等方法的实现。它们应该直接操作 m_value.b (std::vector<std::byte>)。
    -   PyByteArray.cpp 中的 __setitem__ 也是关键，它实现了可变性。

## 步骤三：清理 Value.hpp 和 Value.cpp

在逻辑迁移完成后，我们可以开始移除 Value.hpp 中的冗余定义。

1.  **Value.hpp**:
    -   删除 Number 结构体的所有算术运算符重载 (operator+, operator- 等)。
    -   删除 String 结构体。
    -   删除 Bytes 结构体。
    -   删除 Ellipsis、NoneType 和 NameConstant 结构体。
    -   删除 Tuple 结构体。
    -   **暂时保留** Number 结构体本身，但只留下 std::variant<double, BigIntType> value; 成员，因为它仍被 PyNumber 使用。

2.  **Value.cpp**:
    -   删除所有已迁移的函数实现，包括 Number 的运算符、String::from_unescaped_string、Bytes::from_unescaped_string、Bytes::to_string 等。
    -   删除所有全局的辅助函数，如 add, subtract, equals 等，这些函数都依赖于旧的 Value 变体。

## 步骤四：修改 forward.hpp 和 PyObject.cpp

现在 Value 的结构已经大大简化，我们需要更新依赖它的核心部分。

1.  **src/forward.hpp**:
    -   这是最关键的一步。将 using Value = std::variant<...> **彻底修改为 using Value = RtValue;**。这标志着我们正式从 std::variant 切换到 RtValue。

2.  **PyObject.cpp**:
    -   ValueHash 和 ValueEq 的实现需要修改。它们之前对 Value 进行 box() 操作，现在 Value 就是 RtValue，可以直接使用 RtValueHash 和 RtValueEq 的逻辑，或者直接操作 RtValue。
    -   所有 PyObject::from(const T&) 模板特化，如果 T 是 Number, String, Bytes 等已被删除的类型，需要将它们一并删除。

## 步骤五：全局修复与编译

将 using Value = RtValue; 之后，编译器会报告大量错误。这是预期之中的。我们需要逐一修复。

1.  **PyTuple.hpp / PyTuple.cpp**:
    -   m_elements 的类型从 py::GCVector<Value> 变为 py::GCVector<RtValue>。
    -   所有处理 std::vector<Value> 的 create 重载都需要相应修改或删除。

2.  **PyDict.hpp / PyDict.cpp**:
    -   底层哈希表的类型从 tsl::ordered_map<Value, Value, ValueHash, ValueEq> 变为 tsl::ordered_map<RtValue, RtValue, RtValueHash, RtValueEq>。

3.  **PyFunction.hpp / PyFunction.cpp**:
    -   call_raw(std::span<const Value> args, ...) 的签名现在是 call_raw(std::span<const RtValue> args, ...)。
    -   所有与 Value 相关的打包/解包逻辑都需要调整。

4.  **其他文件**:
    -   遍历所有编译错误，将 Value 替换为 RtValue，并修复因类型不匹配导致的问题。
    -   特别注意 PyObject::from(const Value&) 的实现，它现在应该处理从 RtValue 到 PyObject* 的转换（即 box() 操作）。

完成以上步骤后，第一阶段的重构就结束了。代码的性能应该会有质的飞跃，因为我们消除了大量围绕 std::variant 的装箱、拆箱和动态分派开销。