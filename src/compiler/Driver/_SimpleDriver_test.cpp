#include "_SimpleDriver.hpp"

#include "ast/AST.hpp"
#include "compiler/Support/gtest_wrapper.hpp"
#include "runtime/PyObject.hpp"
#include "runtime/Value.hpp"

#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace pylang;

class SimpleDriverTest : public ::testing::Test
{
  protected:
	static llvm::LLVMContext s_ctx;

	static void SetUpTestSuite() { log::set_level(spdlog::level::warn); }

	/// 创建驱动（需要 runtime.bc 存在）
	Result<SimpleDriver> make_driver(
		SimpleDriver::OutputKind kind = SimpleDriver::OutputKind::IRText)
	{
		SimpleDriver::Options opts;
		opts.runtime_bc_path = PYLANG_RUNTIME_BC_DEFAULT;// CMake 定义
		opts.output_kind = kind;
		opts.opt_level = 0;// 测试时不优化，便于检查 IR
		opts.verify_module = true;
		return SimpleDriver::create(std::move(opts), s_ctx);
	}

	SourceLocation loc()
	{
		static const std::string s_filename = "<test>";
		// Position {row, column, pointer_to_program}
		Position p{ 1, 0, s_filename.c_str() };
		return SourceLocation{ p, p };// start和end用同一个位置
	}
};

llvm::LLVMContext SimpleDriverTest::s_ctx;

// =============================================================================
// 基础功能
// =============================================================================

TEST_F(SimpleDriverTest, CreateDriver)
{
	auto result = make_driver();
	ASSERT_TRUE(result.has_value()) << result.error().to_string();
}

TEST_F(SimpleDriverTest, EmitEmptyModule)
{
	auto driver = make_driver();
	if (!driver) { GTEST_SKIP() << driver.error().message(); }

	ast::Module mod("<test>");
	auto ir = driver->emit_unoptimized_ir(mod, "__test__");
	ASSERT_TRUE(ir.has_value()) << ir.error().to_string();
	EXPECT_TRUE(ir->find("PyInit___test__") != std::string::npos);
	EXPECT_TRUE(ir->find("@main") != std::string::npos);
}

TEST_F(SimpleDriverTest, CompileToIRWithRuntime)
{
	auto driver = make_driver();
	if (!driver) { GTEST_SKIP() << driver.error().message(); }

	// x = 1 + 2
	ast::Module mod("<test>");
	auto lhs = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto rhs = std::make_shared<ast::Constant>(int64_t(2), loc());
	auto binop = std::make_shared<ast::BinaryExpr>(ast::BinaryOpType::PLUS, lhs, rhs, loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, binop, "", loc()));

	auto ir = driver->compile_to_ir(mod, "__test__");
	ASSERT_TRUE(ir.has_value()) << ir.error().to_string();

	// runtime 链接后，rt_binary_add 应该有函数体（define 而非 declare）
	EXPECT_TRUE(ir->find("define") != std::string::npos);
}

// =============================================================================
// Hello World 里程碑
// =============================================================================

TEST_F(SimpleDriverTest, HelloWorldExecutable)
{
	SimpleDriver::Options opts;
	opts.runtime_bc_path = PYLANG_RUNTIME_BC_DEFAULT;
	opts.output_kind = SimpleDriver::OutputKind::Executable;
	opts.opt_level = 0;// 先用 O0 排查问题，避免优化干扰
	opts.dump_ir_before_opt = false;// dump 优化前 IR 到 stderr
	opts.dump_ir_after_opt = false;// dump 优化后 IR 到 stderr

	std::string build_dir = CMAKE_BINARY_DIR;

	opts.extra_link_flags = {
		"-g",
		"-fno-omit-frame-pointer",
		"-L" + build_dir + "/_deps/spdlog-build",
		"-lspdlogd",
		"-lgmpxx",
		"-lgmp",
		"-licuuc",
		"-licudata",
		"-fsanitize=address",
	};

	auto driver = SimpleDriver::create(std::move(opts), s_ctx);
	if (!driver) { GTEST_SKIP() << driver.error().message(); }

	// print("hello world")
	ast::Module mod("<hello>");
	auto print_name = std::make_shared<ast::Name>("print", ast::ContextType::LOAD, loc());
	auto hello_str = std::make_shared<ast::Constant>(std::string("hello world"), loc());
	auto call = std::make_shared<ast::Call>(print_name,
		std::vector<std::shared_ptr<ast::ASTNode>>{ hello_str },
		std::vector<std::shared_ptr<ast::Keyword>>{},
		loc());
	mod.emplace(std::make_shared<ast::Expression>(call, loc()));

	// =========================================================================
	// 额外: 单独 dump 链接前/后的 IR 到文件，方便离线分析
	// =========================================================================

	// Step 1: 未优化、未链接的用户 IR
	{
		auto ir = driver->emit_unoptimized_ir(mod, "__hello__");
		if (ir.has_value()) {
			std::string path = build_dir + "/hello_unoptimized.ll";
			std::ofstream ofs(path);
			ofs << *ir;
			std::cerr << "=== Unoptimized IR written to: " << path << " ===" << std::endl;
		}
	}

	// Step 2: 链接 runtime 后、优化前的 IR
	{
		auto ir = driver->compile_to_ir(mod, "__hello__");
		if (ir.has_value()) {
			std::string path = build_dir + "/hello_linked.ll";
			std::ofstream ofs(path);
			ofs << *ir;
			std::cerr << "=== Linked IR written to: " << path << " ===" << std::endl;
		}
	}

	// Step 3: 完整编译管道
	auto result = driver->compile_module(mod, "__hello__");
	ASSERT_TRUE(result.has_value()) << result.error().to_string();

	// 运行可执行文件并捕获输出
	auto cmd = std::format("{} 2>&1", result->string());
	auto *pipe = popen(cmd.c_str(), "r");
	ASSERT_NE(pipe, nullptr);

	std::string output;
	char buf[256];
	while (fgets(buf, sizeof(buf), pipe)) { output += buf; }
	int exit_code = pclose(pipe);

	EXPECT_EQ(exit_code, 0);
	EXPECT_EQ(output, "hello world\n");
}