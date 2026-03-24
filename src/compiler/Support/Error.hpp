#pragma once

// =============================================================================
// Compiler Error Infrastructure
//
// 使用 C++23 std::expected<T, CompilerError> + 单子操作 (monadic ops)。
// 与 runtime 的 PyResult<T> 完全独立。
//
// 链式用法:
//   load_bitcode(path, ctx)
//     .and_then([](auto mod) { return verify(std::move(mod)); })
//     .transform([](auto &mod) { return mod->getName(); })
//     .or_else([](auto &err) -> Result<StringRef> {
//         err.note("while loading runtime");
//         return std::unexpected(std::move(err));
//     });
//
//   // 管道风格:
//   load_bitcode(path, ctx)
//     | and_then(verify)
//     | map_err(add_context("loading runtime"))
//     | unwrap_or_die("fatal: cannot load runtime");
// =============================================================================

#include <cpptrace/cpptrace.hpp>
#include <spdlog/spdlog.h>

#include <cstdint>
#include <cstdlib>
#include <expected>
#include <format>
#include <functional>
#include <iostream>
#include <optional>
#include <source_location>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>
#include <vector>

namespace pylang {

// =============================================================================
// ErrorKind
// =============================================================================
enum class ErrorKind : uint8_t {
	// Phase 2: RuntimeLinker
	BitcodeLoadFailed,
	AnnotationParseFailed,
	RuntimeFunctionNotFound,
	RuntimeFunctionSignatureMismatch,

	// Phase 2: Codegen
	CodegenUnsupportedNode,
	CodegenTypeError,
	CodegenInternalError,

	// Phase 2: Module / Linking
	ModuleNotFound,
	SymbolConflict,
	LinkError,

	// Phase 3+: 优化 / 验证
	VerificationFailed,
	OptimizationFailed,

	// General
	IOError,
	InvalidArgument,
	NotImplemented,
	InternalError,
};

[[nodiscard]] constexpr std::string_view to_string(ErrorKind kind) noexcept
{
	switch (kind) {
	case ErrorKind::BitcodeLoadFailed:
		return "BitcodeLoadFailed";
	case ErrorKind::AnnotationParseFailed:
		return "AnnotationParseFailed";
	case ErrorKind::RuntimeFunctionNotFound:
		return "RuntimeFunctionNotFound";
	case ErrorKind::RuntimeFunctionSignatureMismatch:
		return "RuntimeFunctionSignatureMismatch";
	case ErrorKind::CodegenUnsupportedNode:
		return "CodegenUnsupportedNode";
	case ErrorKind::CodegenTypeError:
		return "CodegenTypeError";
	case ErrorKind::CodegenInternalError:
		return "CodegenInternalError";
	case ErrorKind::ModuleNotFound:
		return "ModuleNotFound";
	case ErrorKind::SymbolConflict:
		return "SymbolConflict";
	case ErrorKind::LinkError:
		return "LinkError";
	case ErrorKind::VerificationFailed:
		return "VerificationFailed";
	case ErrorKind::OptimizationFailed:
		return "OptimizationFailed";
	case ErrorKind::IOError:
		return "IOError";
	case ErrorKind::InvalidArgument:
		return "InvalidArgument";
	case ErrorKind::NotImplemented:
		return "NotImplemented";
	case ErrorKind::InternalError:
		return "InternalError";
	}
	return "Unknown";
}

// =============================================================================
// CompilerError
// =============================================================================
class CompilerError
{
  public:
	CompilerError(ErrorKind kind,
		std::string message,
		std::source_location loc,
		cpptrace::raw_trace trace = cpptrace::generate_raw_trace())
		: m_kind(kind), m_message(std::move(message)), m_location(loc), m_trace(std::move(trace))
	{}

	// ---- 链式附加信息 ----
	CompilerError &note(std::string text) &
	{
		m_notes.push_back(std::move(text));
		return *this;
	}

	CompilerError &&note(std::string text) &&
	{
		m_notes.push_back(std::move(text));
		return std::move(*this);
	}

	template<typename... Args>
	CompilerError &note_fmt(std::format_string<Args...> fmt, Args &&...args) &
	{
		m_notes.push_back(std::format(fmt, std::forward<Args>(args)...));
		return *this;
	}

	template<typename... Args>
	CompilerError &&note_fmt(std::format_string<Args...> fmt, Args &&...args) &&
	{
		m_notes.push_back(std::format(fmt, std::forward<Args>(args)...));
		return std::move(*this);
	}

	CompilerError &context(std::string ctx) &
	{
		m_context = std::move(ctx);
		return *this;
	}

	CompilerError &&context(std::string ctx) &&
	{
		m_context = std::move(ctx);
		return std::move(*this);
	}

	template<typename... Args>
	CompilerError &context_fmt(std::format_string<Args...> fmt, Args &&...args) &
	{
		m_context = std::format(fmt, std::forward<Args>(args)...);
		return *this;
	}

	template<typename... Args>
	CompilerError &&context_fmt(std::format_string<Args...> fmt, Args &&...args) &&
	{
		m_context = std::format(fmt, std::forward<Args>(args)...);
		return std::move(*this);
	}

	// ---- 访问器 ----
	[[nodiscard]] ErrorKind kind() const noexcept { return m_kind; }
	[[nodiscard]] const std::string &message() const noexcept { return m_message; }
	[[nodiscard]] const std::source_location &location() const noexcept { return m_location; }
	[[nodiscard]] const std::vector<std::string> &notes() const noexcept { return m_notes; }
	[[nodiscard]] const std::optional<std::string> &get_context() const noexcept
	{
		return m_context;
	}

	// ---- 格式化输出 ----
	[[nodiscard]] std::string to_string() const
	{
		return std::format("[{}] {} (at {}:{}:{})",
			pylang::to_string(m_kind),
			m_message,
			m_location.file_name(),
			m_location.line(),
			m_location.column());
	}

	void print_diagnostic() const
	{
		spdlog::error("══════════════════════════════════════════════════");
		spdlog::error("Compiler Error: {}", pylang::to_string(m_kind));
		spdlog::error("  Message: {}", m_message);
		spdlog::error("  At: {}:{}:{} in `{}`",
			m_location.file_name(),
			m_location.line(),
			m_location.column(),
			m_location.function_name());

		if (m_context) { spdlog::error("  Context: {}", *m_context); }
		for (size_t i = 0; i < m_notes.size(); ++i) {
			spdlog::error("  Note[{}]: {}", i, m_notes[i]);
		}

		spdlog::error("  Stack trace:");
		auto resolved = m_trace.resolve();
		resolved.print(std::cerr, cpptrace::isatty(cpptrace::stderr_fileno));
		spdlog::error("══════════════════════════════════════════════════");
	}

	void print_short() const
	{
		spdlog::error("[{}] {}", pylang::to_string(m_kind), m_message);
		for (const auto &n : m_notes) { spdlog::error("  note: {}", n); }
	}

  private:
	ErrorKind m_kind;
	std::string m_message;
	std::source_location m_location;
	cpptrace::raw_trace m_trace;
	std::vector<std::string> m_notes;
	std::optional<std::string> m_context;
};

// =============================================================================
// Result<T> — 核心类型
// =============================================================================
template<typename T> using Result = std::expected<T, CompilerError>;

using VoidResult = std::expected<void, CompilerError>;

// =============================================================================
// 错误构造
// =============================================================================
namespace detail {

	template<typename... Args>
	[[nodiscard]] std::unexpected<CompilerError> make_error_impl(std::source_location loc,
		ErrorKind kind,
		std::format_string<Args...> fmt,
		Args &&...args)
	{
		return std::unexpected(
			CompilerError(kind, std::format(fmt, std::forward<Args>(args)...), loc));
	}

	[[nodiscard]] inline std::unexpected<CompilerError>
		make_error_impl(std::source_location loc, ErrorKind kind, std::string msg)
	{
		return std::unexpected(CompilerError(kind, std::move(msg), loc));
	}

}// namespace detail

#define MAKE_ERROR(kind, ...) \
	::pylang::detail::make_error_impl(std::source_location::current(), (kind), __VA_ARGS__)

#define INTERNAL_ERROR(...) MAKE_ERROR(::pylang::ErrorKind::InternalError, __VA_ARGS__)

#define NOT_IMPLEMENTED(...) MAKE_ERROR(::pylang::ErrorKind::NotImplemented, __VA_ARGS__)

// =============================================================================
// PYLANG_TRY 宏族 — 命令式解包（适合多步顺序操作）
// =============================================================================
#define PYLANG_TRY(var, expr)                                            \
	auto _pylang_result_##var = (expr);                                  \
	if (!_pylang_result_##var) [[unlikely]] {                            \
		return std::unexpected(std::move(_pylang_result_##var).error()); \
	}                                                                    \
	auto var = *std::move(_pylang_result_##var)

#define PYLANG_TRY_REF(var, expr)                                        \
	auto _pylang_result_##var = (expr);                                  \
	if (!_pylang_result_##var) [[unlikely]] {                            \
		return std::unexpected(std::move(_pylang_result_##var).error()); \
	}                                                                    \
	auto &&var = *std::move(_pylang_result_##var)

#define PYLANG_TRY_VOID(expr)                                             \
	do {                                                                  \
		auto _pylang_try_void_ = (expr);                                  \
		if (!_pylang_try_void_) [[unlikely]] {                            \
			return std::unexpected(std::move(_pylang_try_void_).error()); \
		}                                                                 \
	} while (false)

#define PYLANG_TRY_CTX(var, expr, ...)                                   \
	auto _pylang_result_##var = (expr);                                  \
	if (!_pylang_result_##var) [[unlikely]] {                            \
		_pylang_result_##var.error().context_fmt(__VA_ARGS__);           \
		return std::unexpected(std::move(_pylang_result_##var).error()); \
	}                                                                    \
	auto var = *std::move(_pylang_result_##var)

// =============================================================================
// 管道适配器 — 利用 C++23 expected 单子操作，支持 result | op 链式
//
// C++23 std::expected 自带:
//   .and_then(f)        — 值 → Result（链式调用）
//   .transform(f)       — 值 → 映射（包装为 Result）
//   .or_else(f)         — 错误 → 恢复或修改
//   .transform_error(f) — 错误 → 映射
//
// 我们额外提供管道适配器，使链式更简洁:
//   load(path, ctx)
//     | pylang::and_then([](auto m) { return verify(std::move(m)); })
//     | pylang::map_err([](auto e) { return e.context("loading"); })
//     | pylang::unwrap("fatal");
// =============================================================================
namespace pipe {

	/// and_then 管道适配器
	template<typename F> struct AndThen
	{
		F func;
	};

	template<typename F> [[nodiscard]] constexpr auto and_then(F &&f)
	{
		return AndThen<std::decay_t<F>>{ std::forward<F>(f) };
	}

	template<typename T, typename F> [[nodiscard]] auto operator|(Result<T> &&r, AndThen<F> &&a)
	{
		return std::move(r).and_then(std::move(a.func));
	}

	/// transform 管道适配器
	template<typename F> struct Transform
	{
		F func;
	};

	template<typename F> [[nodiscard]] constexpr auto transform(F &&f)
	{
		return Transform<std::decay_t<F>>{ std::forward<F>(f) };
	}

	template<typename T, typename F> [[nodiscard]] auto operator|(Result<T> &&r, Transform<F> &&t)
	{
		return std::move(r).transform(std::move(t.func));
	}

	/// or_else 管道适配器
	template<typename F> struct OrElse
	{
		F func;
	};

	template<typename F> [[nodiscard]] constexpr auto or_else(F &&f)
	{
		return OrElse<std::decay_t<F>>{ std::forward<F>(f) };
	}

	template<typename T, typename F> [[nodiscard]] auto operator|(Result<T> &&r, OrElse<F> &&o)
	{
		return std::move(r).or_else(std::move(o.func));
	}

	/// transform_error 管道适配器
	template<typename F> struct TransformError
	{
		F func;
	};

	template<typename F> [[nodiscard]] constexpr auto transform_error(F &&f)
	{
		return TransformError<std::decay_t<F>>{ std::forward<F>(f) };
	}

	template<typename T, typename F>
	[[nodiscard]] auto operator|(Result<T> &&r, TransformError<F> &&te)
	{
		return std::move(r).transform_error(std::move(te.func));
	}

	/// map_err — 对错误附加上下文（最常用的 or_else 特化）
	[[nodiscard]] inline auto add_context(std::string ctx)
	{
		return or_else([c = std::move(ctx)](CompilerError e) -> Result<void> {
			return std::unexpected(std::move(e).context(std::string(c)));
		});
	}

	template<typename... Args>
	[[nodiscard]] auto add_context_fmt(std::format_string<Args...> fmt, Args &&...args)
	{
		auto msg = std::format(fmt, std::forward<Args>(args)...);
		return or_else([m = std::move(msg)](CompilerError e) -> Result<void> {
			return std::unexpected(std::move(e).context(std::string(m)));
		});
	}

	/// add_note — 对错误附加备注
	[[nodiscard]] inline auto add_note(std::string text)
	{
		return or_else([t = std::move(text)](CompilerError e) -> Result<void> {
			return std::unexpected(std::move(e).note(std::string(t)));
		});
	}

}// namespace pipe

// =============================================================================
// unwrap 工具 — 解包 Result 或 abort
// =============================================================================

/// 解包 Result，失败时打印诊断并 abort
template<typename T> [[nodiscard]] T unwrap_or_die(Result<T> &&result, std::string_view msg = "")
{
	if (result) { return *std::move(result); }
	if (!msg.empty()) { spdlog::error("Fatal: {}", msg); }
	result.error().print_diagnostic();
	std::abort();
}

/// 解包 VoidResult，失败时打印诊断并 abort
inline void unwrap_or_die(VoidResult &&result, std::string_view msg = "")
{
	if (result) { return; }
	if (!msg.empty()) { spdlog::error("Fatal: {}", msg); }
	result.error().print_diagnostic();
	std::abort();
}

/// 解包 Result，失败时返回默认值并记录 warning
template<typename T> [[nodiscard]] T unwrap_or(Result<T> &&result, T default_value)
{
	if (result) { return *std::move(result); }
	spdlog::warn("Result unwrap failed: {}", result.error().to_string());
	return default_value;
}

// =============================================================================
// optional 桥接 — optional<T> → Result<T>
// =============================================================================

/// 将 optional 转为 Result（None 时创建指定错误）
template<typename T>
[[nodiscard]] Result<T> ok_or(std::optional<T> &&opt,
	ErrorKind kind,
	std::string msg,
	std::source_location loc = std::source_location::current())
{
	if (opt) { return *std::move(opt); }
	return std::unexpected(CompilerError(kind, std::move(msg), loc));
}

template<typename T, typename F>
	requires std::invocable<F> && std::same_as<std::invoke_result_t<F>, CompilerError>
[[nodiscard]] Result<T> ok_or_else(std::optional<T> &&opt, F &&err_fn)
{
	if (opt) { return *std::move(opt); }
	return std::unexpected(std::invoke(std::forward<F>(err_fn)));
}

// =============================================================================
// PYLANG_ASSERT / PYLANG_UNREACHABLE
// =============================================================================
#define PYLANG_ASSERT(cond, ...)                                                    \
	do {                                                                            \
		if (!(cond)) [[unlikely]] {                                                 \
			std::string _pylang_assert_msg = "Assertion `" #cond "` failed";        \
			__VA_OPT__(_pylang_assert_msg += ": ";                                  \
				_pylang_assert_msg += std::format(__VA_ARGS__);)                    \
			auto _err = ::pylang::CompilerError(::pylang::ErrorKind::InternalError, \
				std::move(_pylang_assert_msg),                                      \
				std::source_location::current());                                   \
			_err.print_diagnostic();                                                \
			std::abort();                                                           \
		}                                                                           \
	} while (false)

#define PYLANG_UNREACHABLE(...)                                                                   \
	do {                                                                                          \
		std::string _pylang_unreach_msg = "Unreachable code reached";                             \
		__VA_OPT__(_pylang_unreach_msg += ": "; _pylang_unreach_msg += std::format(__VA_ARGS__);) \
		auto _err = ::pylang::CompilerError(::pylang::ErrorKind::InternalError,                   \
			std::move(_pylang_unreach_msg),                                                       \
			std::source_location::current());                                                     \
		_err.print_diagnostic();                                                                  \
		std::abort();                                                                             \
	} while (false)

// =============================================================================
// ResultCollector — 收集多个错误（批量验证场景）
// =============================================================================
class ResultCollector
{
  public:
	void add(CompilerError err) { m_errors.push_back(std::move(err)); }

	template<typename T> std::optional<T> try_collect(Result<T> &&result)
	{
		if (result) { return *std::move(result); }
		m_errors.push_back(std::move(result).error());
		return std::nullopt;
	}

	void try_collect_void(VoidResult &&result)
	{
		if (!result) { m_errors.push_back(std::move(result).error()); }
	}

	[[nodiscard]] bool has_errors() const noexcept { return !m_errors.empty(); }
	[[nodiscard]] size_t error_count() const noexcept { return m_errors.size(); }
	[[nodiscard]] const std::vector<CompilerError> &errors() const noexcept { return m_errors; }

	void print_all() const
	{
		for (const auto &e : m_errors) { e.print_short(); }
		if (!m_errors.empty()) { spdlog::error("{} error(s) total", m_errors.size()); }
	}

	VoidResult finish()
	{
		if (m_errors.empty()) { return {}; }
		auto first = std::move(m_errors.front());
		if (m_errors.size() > 1) {
			first.note_fmt("({} more error(s) suppressed)", m_errors.size() - 1);
		}
		return std::unexpected(std::move(first));
	}

  private:
	std::vector<CompilerError> m_errors;
};

}// namespace pylang