#pragma once

// =============================================================================
// String Utilities — 支持 C++23 optional 单子链式操作
//
// 用法:
//   // 传统:
//   auto parts = pylang::str::split(annotation, ':');
//
//   // 链式:
//   auto result = pylang::str::strip_prefix(s, "pylang_export:")
//       .and_then([](auto rest) { return pylang::str::try_split_exact(rest, ':', 4); })
//       .transform([](auto parts) { return RuntimeFunction{parts[0], parts[1], ...}; });
// =============================================================================

#include <algorithm>
#include <array>
#include <charconv>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace pylang::str {

// =============================================================================
// 基础操作
// =============================================================================

[[nodiscard]] inline std::vector<std::string_view> split(std::string_view s, char delim)
{
    std::vector<std::string_view> result;
    size_t start = 0;
    while (start <= s.size()) {
        auto pos = s.find(delim, start);
        if (pos == std::string_view::npos) {
            result.push_back(s.substr(start));
            break;
        }
        result.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    return result;
}

[[nodiscard]] inline std::vector<std::string_view> split_n(
    std::string_view s, char delim, size_t max_parts)
{
    std::vector<std::string_view> result;
    size_t start = 0;
    while (start <= s.size() && result.size() + 1 < max_parts) {
        auto pos = s.find(delim, start);
        if (pos == std::string_view::npos) break;
        result.push_back(s.substr(start, pos - start));
        start = pos + 1;
    }
    if (start <= s.size()) { result.push_back(s.substr(start)); }
    return result;
}

/// 分割并要求恰好 N 段（否则返回 nullopt），支持 optional 链式
template<size_t N>
[[nodiscard]] std::optional<std::array<std::string_view, N>> split_exact(
    std::string_view s, char delim)
{
    auto parts = split(s, delim);
    if (parts.size() != N) { return std::nullopt; }
    std::array<std::string_view, N> arr;
    std::copy_n(parts.begin(), N, arr.begin());
    return arr;
}

/// 分割并要求至少 N 段
[[nodiscard]] inline std::optional<std::vector<std::string_view>> split_at_least(
    std::string_view s, char delim, size_t min_parts)
{
    auto parts = split(s, delim);
    if (parts.size() < min_parts) { return std::nullopt; }
    return parts;
}

// =============================================================================
// 去除空白
// =============================================================================

[[nodiscard]] inline std::string_view trim(std::string_view s)
{
    auto start = s.find_first_not_of(" \t\n\r");
    if (start == std::string_view::npos) return {};
    auto end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

// =============================================================================
// 前缀/后缀操作 — 返回 optional 以支持链式
// =============================================================================

[[nodiscard]] inline std::optional<std::string_view> strip_prefix(
    std::string_view s, std::string_view prefix)
{
    if (s.starts_with(prefix)) { return s.substr(prefix.size()); }
    return std::nullopt;
}

[[nodiscard]] inline std::optional<std::string_view> strip_suffix(
    std::string_view s, std::string_view suffix)
{
    if (s.ends_with(suffix)) { return s.substr(0, s.size() - suffix.size()); }
    return std::nullopt;
}

// =============================================================================
// 查找/包含
// =============================================================================

[[nodiscard]] inline bool contains(std::string_view s, std::string_view sub)
{
    return s.find(sub) != std::string_view::npos;
}

[[nodiscard]] inline bool contains(std::string_view s, char ch)
{
    return s.find(ch) != std::string_view::npos;
}

[[nodiscard]] inline size_t count(std::string_view s, char ch)
{
    return static_cast<size_t>(std::count(s.begin(), s.end(), ch));
}

// =============================================================================
// 数值解析 — 返回 optional
// =============================================================================

template<typename T>
    requires std::is_integral_v<T>
[[nodiscard]] std::optional<T> parse_int(std::string_view s)
{
    T value{};
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    if (ec != std::errc{} || ptr != s.data() + s.size()) { return std::nullopt; }
    return value;
}

// =============================================================================
// 拼接/替换
// =============================================================================

[[nodiscard]] inline std::string join(
    const std::vector<std::string_view> &parts, std::string_view sep)
{
    if (parts.empty()) return {};
    std::string result;
    size_t total = sep.size() * (parts.size() - 1);
    for (const auto &p : parts) total += p.size();
    result.reserve(total);
    result.append(parts[0]);
    for (size_t i = 1; i < parts.size(); ++i) {
        result.append(sep);
        result.append(parts[i]);
    }
    return result;
}

template<size_t N>
[[nodiscard]] std::string join(
    const std::array<std::string_view, N> &parts, std::string_view sep)
{
    if constexpr (N == 0) return {};
    std::string result;
    result.append(parts[0]);
    for (size_t i = 1; i < N; ++i) {
        result.append(sep);
        result.append(parts[i]);
    }
    return result;
}

[[nodiscard]] inline std::string replace_all(
    std::string_view s, std::string_view from, std::string_view to)
{
    if (from.empty()) return std::string(s);
    std::string result;
    result.reserve(s.size());
    size_t pos = 0;
    while (true) {
        auto found = s.find(from, pos);
        if (found == std::string_view::npos) {
            result.append(s.substr(pos));
            break;
        }
        result.append(s.substr(pos, found - pos));
        result.append(to);
        pos = found + from.size();
    }
    return result;
}

} // namespace pylang::str