#pragma once

// =============================================================================
// Compiler Logging — spdlog 子系统封装
//
// 每个编译器子系统独立 logger，支持独立日志级别控制。
// 线程安全：使用 std::call_once 保证 logger 只创建一次。
//
// 用法:
//   pylang::log::codegen()->info("Generating function: {}", name);
//   pylang::log::linker()->debug("Loading runtime.bc from: {}", path);
//   pylang::log::set_level(spdlog::level::trace);  // 全局设置
// =============================================================================

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <memory>
#include <mutex>
#include <string_view>

namespace pylang::log {

namespace detail {

	/// 线程安全的 logger 创建（每个 name 只创建一次）
	inline std::shared_ptr<spdlog::logger> get_or_create(std::string_view name)
	{
		// spdlog::get 本身是线程安全的
		auto logger = spdlog::get(std::string(name));
		if (logger) { return logger; }

		// 但 register + create 之间可能竞争，用全局锁保护
		static std::mutex s_mutex;
		std::lock_guard lock(s_mutex);

		// double-check
		logger = spdlog::get(std::string(name));
		if (logger) { return logger; }

		logger = spdlog::stderr_color_mt(std::string(name));
		logger->set_pattern("[%H:%M:%S.%e] [%n] [%^%l%$] %v");
		return logger;
	}

}// namespace detail

// ---- 子系统 logger ----
inline auto linker() { return detail::get_or_create("linker"); }
inline auto codegen() { return detail::get_or_create("codegen"); }
inline auto compiler() { return detail::get_or_create("compiler"); }
inline auto module() { return detail::get_or_create("module"); }
inline auto opt() { return detail::get_or_create("opt"); }

/// 全局设置所有 pylang logger 的日志级别
inline void set_level(spdlog::level::level_enum level)
{
	for (auto name : { "linker", "codegen", "compiler", "module", "opt" }) {
		auto logger = spdlog::get(name);
		if (logger) { logger->set_level(level); }
	}
}

/// 设置单个子系统的日志级别
inline void set_level(std::string_view subsystem, spdlog::level::level_enum level)
{
	auto logger = spdlog::get(std::string(subsystem));
	if (logger) { logger->set_level(level); }
}

}// namespace pylang::log