UPPER_BOUND = 5000000
PREFIX = 32338

class Node:
    def __init__(self):
        self.children = {}
        self.terminal = False

class Sieve:
    def __init__(self, limit):
        self.limit = limit
        self.prime = [False] * (limit + 1)
        print("Sieve initialized with limit:", limit)

    def to_list(self):
        result = [2, 3]
        for p in range(5, self.limit + 1):
            if self.prime[p]:
                result.append(p)
        print("Total primes found:", len(result))
        return result

    def omit_squares(self):
        r = 5
        while r * r < self.limit:
            if self.prime[r]:
                i = r * r
                while i < self.limit:
                    self.prime[i] = False
                    i = i + r * r
            r += 1
        return self

    def step1(self, x, y):
        n = (4 * x * x) + (y * y)
        if n <= self.limit and (n % 12 == 1 or n % 12 == 5):
            self.prime[n] = not self.prime[n]

    def step2(self, x, y):
        n = (3 * x * x) + (y * y)
        if n <= self.limit and n % 12 == 7:
            self.prime[n] = not self.prime[n]

    def step3(self, x, y):
        n = (3 * x * x) - (y * y)
        if x > y and n <= self.limit and n % 12 == 11:
            self.prime[n] = not self.prime[n]

    def loop_y(self, x):
        y = 1
        while y * y < self.limit:
            self.step1(x, y)
            self.step2(x, y)
            self.step3(x, y)
            y += 1

    def loop_x(self):
        x = 1
        while x * x < self.limit:
            if x % 500 == 0:
                print("Processing loop_x, x =", x)
            self.loop_y(x)
            x += 1

    def calc(self):
        print("Starting sieve calculation...")
        self.loop_x()
        print("Sieve loops finished, omitting squares...")
        return self.omit_squares()

def generate_trie(l):
    print("Generating trie for primes, list size:", len(l))
    root = Node()
    for el in l:
        s_el = str(el)
        head = root
        for ch in s_el:
            if ch not in head.children:
                head.children[ch] = Node()
            head = head.children[ch]
        head.terminal = True
    print("Trie generation complete.")
    return root

def find(upper_bound, prefix):
    primes = Sieve(upper_bound).calc()
    str_prefix = str(prefix)
    print("Searching for prefix:", str_prefix)
    
    prime_list = primes.to_list()
    # 调试：检查原始质数列表中是否包含预期值
    if upper_bound == 100:
        print("Base primes check for 100:", 2 in prime_list, 23 in prime_list, 29 in prime_list)

    head = generate_trie(prime_list)
    
    print("Navigating to prefix node...")
    for ch in str_prefix:
        print("Link check for char:", ch)
        head = head.children.get(ch)
        if head is None:
            print("Prefix node break at char:", ch)
            return None
    
    print("Prefix node found. Terminal state of prefix node:", head.terminal)

    queue, result = [(head, str_prefix)], []
    print("Starting queue traversal. Initial queue size:", len(queue))
    
    while queue:
        top, current_prefix = queue.pop()
        #print("Queue pop:", current_prefix, "Terminal:", top.terminal)
        
        if top.terminal:
            result.append(int(current_prefix))
        


        
        for ch, v in top.children.items():
            new_prefix = current_prefix + ch
            #print("Pushing to queue:", new_prefix)
            queue.insert(0, (v, new_prefix))

    result.sort()
    print("Find completed. Results count:", len(result))
    return result

def verify():
    print("Running verify()...")
    left = [2, 23, 29]
    right = find(100, 2)
    print("Verify results match:", left == right)
    print("Expected:", left)
    print("Actual:", right)


# ==========================================
# 下方为新增的压力测试与多范围测试入口
# ==========================================

def run_stress_test():
    # 1. 验证基本逻辑
    verify()
    
    # 2. 设置测试参数：遍历遍数、不同的数据范围、不同的前缀
    iterations = 3
    test_bounds = [1000, 50000, 500000, UPPER_BOUND]
    test_prefixes = [3, 32, 323, 3233, PREFIX]

    print("\n--------------------------------------------------")
    print("Starting Comprehensive Stress Test...")
    print("Total Iterations:", iterations)
    print("Bounds Array:", test_bounds)
    print("Prefixes Array:", test_prefixes)
    print("--------------------------------------------------\n")

    for i in range(iterations):
        print("==================================================")
        print(">>> ITERATION:", i + 1, "OF", iterations)
        print("==================================================")
        
        # 范围测试：用较短的前缀，测试筛法在各种数据量级下的稳定性
        print("\n--- Phase 1: Range Testing ---")
        for bound in test_bounds:
            print("Testing with upper bound:", bound)
            res = find(bound, 3)  # 使用短前缀3保证有结果输出
            if res is not None:
                print(">> Range Test Output | Bound:", bound, "| Prefix: 3 | Match Count:", len(res))
            else:
                print(">> Range Test Output | Bound:", bound, "| Prefix: 3 | Match Count: 0")
        
        # 前缀压力测试：在最大的500万上限中，持续挖掘不同深度（长度）的前缀
        print("\n--- Phase 2: Prefix Stress Testing (Max Bound) ---")
        for pref in test_prefixes:
            print("Testing with prefix:", pref, "at max bound:", UPPER_BOUND)
            res = find(UPPER_BOUND, pref)
            if res is not None:
                print(">> Stress Test Output | Bound:", UPPER_BOUND, "| Prefix:", pref, "| Match Count:", len(res))
                # 碰到我们的主目标时，打印完整数组用于对照
                if pref == PREFIX:
                    print(">> Target Prefix Results Array:", res)
            else:
                print(">> Stress Test Output | Bound:", UPPER_BOUND, "| Prefix:", pref, "| Match Count: 0")

# 启动全量测试
run_stress_test()