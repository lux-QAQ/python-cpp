# 1. 核心比较与哈希一致性 (Hash Parity)
# Python 规定 1.0 == 1 必须成立，且它们的哈希值必须相等
print("eq_check", 1.0 == 1, 1.5 == 1)
print("hash_parity", hash(1.0) == hash(1))
print("hash_large", hash(123456789.0) == hash(123456789))

# 2. 符号与零的处理
# 0.0 与 -0.0 在比较上是相等的
print("zero_eq", 0.0 == -0.0)
print("abs_neg", abs(-1.5) == 1.5)

# 3. 浮点数特有方法 (无需 import)
print("is_int", (1.0).is_integer(), (1.5).is_integer())

# 4. 精确分数还原 (as_integer_ratio)
# 0.75 应该还原为 (3, 4)
ratio = (0.75).as_integer_ratio()
print("ratio", ratio[0], ratio[1])

# 5. 银行家舍入法 (Round half to even)
# Python 的 round() 在 .5 的时候会向偶数取整
print("round_half", round(0.5), round(1.5), round(2.5), round(3.5))

# 6. 类型转换语义
print("to_int", int(1.9), int(-1.9)) # 向零截断
print("from_str", float("1.25") == 1.25)

# 7. 特殊值构造与比较 (通过字符串构造以避开字面量格式测试)
inf = float("inf")
neg_inf = float("-inf")
nan = float("nan")

print("nan_self", nan == nan) # NaN 不等于自身是 IEEE 754 标准
print("inf_hash", hash(inf) == 314159) # Python 64位系统标准哈希常数

# 8. 逻辑运算
print("float_bool", bool(0.0), bool(1.5))