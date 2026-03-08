#pragma once


namespace py {
    /// 全局统一的运行时初始化逻辑
    /// 包含所有类型初始化和单例创建
    /// 线程安全（内部有 static bool 守卫）
    void initialize_types();
}