class Sieve:
    def __init__(self, limit):
        self.limit = limit
        self.prime = [False] * (limit + 1)
        print("INIT self:", id(self), "limit:", self.limit)

    def loop_x(self):
        print("LOOP_X self:", id(self))
        x = 1
        while x * x < self.limit:
            x += 1

s = Sieve(10)
s.loop_x()
