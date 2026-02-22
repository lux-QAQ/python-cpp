#pragma once

#include <atomic>
#include <mutex>
#include <string>
#include <unordered_map>

namespace py {

/// Per-key 版本追踪器 — 避免 inline cache 全模块震荡
///
/// 场景:
///   for i in range(N):
///       global_counter += 1   # bump "global_counter" key_version
///       x = math.pi           # "pi" 的 cache 不受影响
///
/// 旧方案 (单一 m_dict_version) 会导致 math.pi 每次 cache miss。
/// 新方案: 每个 key 独立版本号，互不干扰。
class KeyVersionTracker
{
  public:
    /// 获取 key 的当前版本号（0 = 从未写入）
    uint64_t get(const std::string &key) const
    {
        std::lock_guard lock(m_mutex);
        auto it = m_versions.find(key);
        if (it == m_versions.end()) return 0;
        return it->second.load(std::memory_order_relaxed);
    }

    /// 递增 key 的版本号
    void bump(const std::string &key)
    {
        std::lock_guard lock(m_mutex);
        auto [it, inserted] = m_versions.try_emplace(key, 0);
        it->second.fetch_add(1, std::memory_order_relaxed);
    }

    /// 是否包含该 key
    bool contains(const std::string &key) const { return m_versions.contains(key); }

  private:
     mutable std::mutex m_mutex;
    std::unordered_map<std::string, std::atomic<uint64_t>> m_versions;
};

}// namespace py