#include "interpreter/InterpreterCore.hpp"
#include "runtime/RuntimeContext.hpp"

#include <gtest/gtest.h>

// =============================================================================
// InterpreterCore 头文件独立性测试
// =============================================================================
// 验证 InterpreterCore.hpp 能独立编译，不传递依赖 vm/VM.hpp

TEST(InterpreterCore, HeaderCompiles)
{
	// 如果编译通过，说明 InterpreterCore.hpp 不依赖 VM.hpp
	Interpreter interp;
	EXPECT_EQ(interp.execution_frame(), nullptr);
	EXPECT_EQ(interp.modules(), nullptr);
	EXPECT_EQ(interp.builtins(), nullptr);
	EXPECT_EQ(interp.importlib(), nullptr);
	EXPECT_EQ(interp.importfunc(), nullptr);
	EXPECT_EQ(interp.codec_error_registry(), nullptr);
	EXPECT_EQ(interp.codec_search_path(), nullptr);
	EXPECT_EQ(interp.codec_search_path_cache(), nullptr);
	EXPECT_TRUE(interp.entry_script().empty());
	EXPECT_TRUE(interp.argv().empty());
}

TEST(InterpreterCore, RuntimeContextInterpreterBinding)
{
	// 保存原始上下文
	auto *saved = py::RuntimeContext::has_current() ? &py::RuntimeContext::current() : nullptr;

	py::RuntimeContext ctx;
	Interpreter interp;
	ctx.set_interpreter(&interp);
	py::RuntimeContext::set_current(&ctx);

	EXPECT_TRUE(py::RuntimeContext::has_current());
	EXPECT_TRUE(py::RuntimeContext::current().has_interpreter());
	EXPECT_EQ(py::RuntimeContext::current().interpreter(), &interp);

	// 恢复
	py::RuntimeContext::set_current(saved);
}