class BadTuple:
    def __init__(self, items):
        self.items = list(items)

    def __hash__(self):
        return hash(tuple(self.items))

    def __eq__(self, other):
        return isinstance(other, BadTuple) and self.items == other.items

    def __repr__(self):
        # 直接返回字符串 + str()
        return "BadTuple(" + str(self.items) + ")"

    def set(self, index, value):
        self.items[index] = value


t = BadTuple([1, 2])
d = {t: "original"}

print("初始:", d)

t.set(0, 100)
print("修改后对象:", t)

print("尝试访问 d[t]:", d.get(t))

t2 = BadTuple([100, 2])
print("新对象:", t2)

print("尝试访问 d[t2]:", d.get(t2))

print("dict keys:", list(d.keys()))