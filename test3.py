class Tool:
    count = 0
    
    def __init__(self):
        Tool.count = Tool.count + 1

    @classmethod
    def get_count_cls(cls):
        return cls.count

    @staticmethod
    def calc(x):
        return x * 2

t1 = Tool()
t2 = Tool()

print("Count:", Tool.get_count_cls())
print("Static:", Tool.calc(10))
print("Static via instance:", t1.calc(5))