## 含义

Multi-file-compilation.md 中设计了 `InitGuard`：

```cpp
struct InitGuard {
    std::string name;
    bool committed{false};
    explicit InitGuard(const std::string& n) : name(n) {}
    ~InitGuard() {
        if (!committed)
            ModuleRegistry::instance().mark_failed(name);
    }
    void commit() {
        committed = true;
        ModuleRegistry::instance().mark_initialized(name);
    }
};
```

**但当前所有模块工厂函数没有使用它**。以 `sys_module()` 为例：

````cpp
// 当前实现 — 无守卫
PyModule *sys_module()
{
    if (s_sys_module) return s_sys_module;       // 简单 static 指针检查
    s_sys_module = PyModule::create(...).unwrap();
    s_sys_module->add_symbol(...);               // 如果这里抛异常？
    // ...30+ 个 add_symbol...
    return s_sys_module;                          // ← s_sys_module 半初始化!
}
````

**风险**：如果中间任何一个 `add_symbol` 失败（`unwrap()` 触发 abort 或未来改为异常），`s_sys_module` 已被赋值但内容不完整。其他线程通过 `ModuleRegistry::find("sys")` 拿到的是**半成品模块**。

**设计目标**是改为三阶段模式：

````cpp
// 目标实现 — 有守卫
PyModule *sys_module()
{
    auto [mod, is_owner] = ModuleRegistry::instance().get_or_register("sys");
    if (!is_owner) return mod;  // 已初始化或同线程递归 import

    InitGuard guard("sys");     // RAII: 异常时自动 mark_failed

    mod->add_symbol(...);
    // ...

    guard.commit();             // 成功: mark_initialized + notify_all
    return mod;
}
````

**现状**：`ModuleRegistry` 只实现了 `register_module` / `find`，没有实现 `get_or_register` / `mark_initialized` / `mark_failed`。所以 `InitGuard` 虽然在文档中设计了，但无法使用。

**优先级不高**——当前所有模块工厂都在单线程中调用（`register_all_builtins` 串行执行），不会出现并发初始化问题。等 Phase 3 实现多文件并行编译时才需要。