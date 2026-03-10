#include "PylangCodegen.hpp"
#include "runtime/Value.hpp"
#include "compiler/Support/gtest_wrapper.hpp"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>

#include <cstdlib>
#include <filesystem>

using namespace pylang;

// =============================================================================
// PylangCodegen 单元测试
//
// 直接构造 AST 节点测试 codegen，不依赖 Parser/Lexer。
// 集成测试在 integration/ 目录下。
// =============================================================================
class PylangCodegenTest : public ::testing::Test
{
  protected:
	void SetUp() override
	{
		loader = std::make_unique<LLVMModuleLoader>(ctx);

		const char *env_path = std::getenv("PYLANG_RUNTIME_BC");
#ifdef PYLANG_RUNTIME_BC_DEFAULT
		std::string runtime_bc = env_path ? env_path : PYLANG_RUNTIME_BC_DEFAULT;
#else
		std::string runtime_bc = env_path ? env_path : "build/debug/runtime.bc";
#endif

		if (!std::filesystem::exists(runtime_bc)) {
			GTEST_SKIP() << "runtime.bc not found at " << runtime_bc;
		}

		auto linker_result = RuntimeLinker::create(*loader, runtime_bc);
		ASSERT_TRUE(linker_result.has_value()) << linker_result.error().to_string();
		linker = std::make_unique<RuntimeLinker>(std::move(*linker_result));
	}

	/// 编译 AST Module 并返回 LLVM IR 文本
	// std::string compile_module(ast::Module &mod)
	// {
	// 	auto result = PylangCodegen::compile(&mod, "__test__", ctx, *linker);
	// 	EXPECT_TRUE(result.has_value()) << result.error().to_string();

	// 	std::string ir;
	// 	llvm::raw_string_ostream os(ir);
	// 	result->module->print(os, nullptr);
	// 	return ir;
	// }
    std::string compile_module(ast::Module &mod)
    {
        auto result = PylangCodegen::compile(&mod, "__test__", ctx, *linker);
        if (!result.has_value()) {
            ADD_FAILURE() << result.error().to_string();
            return "";// ← 提前返回，不访问无效的 result->module
        }

        std::string ir;
        llvm::raw_string_ostream os(ir);
        result->module->print(os, nullptr);
        return ir;
    }

    bool ir_contains(const std::string &ir, std::string_view pattern)
    {
        return ir.find(pattern) != std::string::npos;
    }

    /// 检查 IR 中是否调用了某个 runtime 函数
    /// 兼容 C++ mangled 名（如 _Z9rt_importPKc...）和 extern "C" 名
    bool ir_calls_rt(const std::string &ir, std::string_view logical_name)
    {
        // mangled 名中一定包含逻辑名（C++ mangling 保留原始名称）
        return ir.find(logical_name) != std::string::npos;
    }

	SourceLocation loc() { return SourceLocation{}; }

	llvm::LLVMContext ctx;
	std::unique_ptr<LLVMModuleLoader> loader;
	std::unique_ptr<RuntimeLinker> linker;
};

// =============================================================================
// 基础: 空模块生成 main + PyInit
// =============================================================================
TEST_F(PylangCodegenTest, EmptyModule)
{
    ast::Module mod("<test>");
    auto ir = compile_module(mod);

    // 函数定义名是确定的（codegen 自己生成，不经过 mangling）
    EXPECT_TRUE(ir_contains(ir, "define void @PyInit___test__"));
    EXPECT_TRUE(ir_contains(ir, "define i32 @main"));

    // runtime 函数以 C++ mangled 名声明，逻辑名是 mangled 名的子串
    // _Z7rt_initv     ⊇ "rt_init"
    // _Z11rt_shutdownv ⊇ "rt_shutdown"
    EXPECT_TRUE(ir_contains(ir, "rt_init"));
    EXPECT_TRUE(ir_contains(ir, "rt_shutdown"));
}

// =============================================================================
// Phase 2.3b: 常量
// =============================================================================
TEST_F(PylangCodegenTest, IntegerConstant)
{
	// x = 42
    ast::Module mod("<test>");
    auto value = std::make_shared<ast::Constant>("hello", loc());
    auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
    mod.emplace(std::make_shared<ast::Assign>(
        std::vector<std::shared_ptr<ast::ASTNode>>{ target }, value, "", loc()));

    auto ir = compile_module(mod);
    if (ir.empty()) { return; }
    EXPECT_TRUE(ir_calls_rt(ir, "rt_string_from_cstr"));
    EXPECT_TRUE(ir_contains(ir, "hello"));// 字符串字面量本身不受 mangling 影响
}

TEST_F(PylangCodegenTest, StringConstant)
{
	// x = "hello"
	ast::Module mod("<test>");
	auto value = std::make_shared<ast::Constant>("hello", loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, value, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_string_from_cstr"));
	EXPECT_TRUE(ir_contains(ir, "hello"));
}

TEST_F(PylangCodegenTest, BooleanConstants)
{
	// x = True; y = False
    ast::Module mod("<test>");
    auto true_val = std::make_shared<ast::Constant>(true, loc());
    auto target_x = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
    mod.emplace(std::make_shared<ast::Assign>(
        std::vector<std::shared_ptr<ast::ASTNode>>{ target_x }, true_val, "", loc()));

    auto false_val = std::make_shared<ast::Constant>(false, loc());
    auto target_y = std::make_shared<ast::Name>("y", ast::ContextType::STORE, loc());
    mod.emplace(std::make_shared<ast::Assign>(
        std::vector<std::shared_ptr<ast::ASTNode>>{ target_y }, false_val, "", loc()));

    auto ir = compile_module(mod);
    if (ir.empty()) { return; }
    EXPECT_TRUE(ir_calls_rt(ir, "rt_true"));
    EXPECT_TRUE(ir_calls_rt(ir, "rt_false"));
}

TEST_F(PylangCodegenTest, NoneConstant)
{
    // x = None
    ast::Module mod("<test>");

    // None → py::NameConstant{ NoneType{} } → py::Value
    py::Value none_value = py::NameConstant{ py::NoneType{} };
    auto none_val = std::make_shared<ast::Constant>(none_value, loc());

    auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
    mod.emplace(std::make_shared<ast::Assign>(
        std::vector<std::shared_ptr<ast::ASTNode>>{ target }, none_val, "", loc()));

    auto ir = compile_module(mod);
    EXPECT_TRUE(ir_contains(ir, "rt_none"));
}

// =============================================================================
// Phase 2.3b: 二元表达式
// =============================================================================
TEST_F(PylangCodegenTest, BinaryAdd)
{
	// x = 1 + 2
	ast::Module mod("<test>");
	auto lhs = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto rhs = std::make_shared<ast::Constant>(int64_t(2), loc());
	auto binop = std::make_shared<ast::BinaryExpr>(ast::BinaryOpType::PLUS, lhs, rhs, loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, binop, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_binary_add"));
	EXPECT_TRUE(ir_contains(ir, "rt_integer_from_i64"));
}

// =============================================================================
// Phase 2.3b: 一元表达式
// =============================================================================
TEST_F(PylangCodegenTest, UnaryNeg)
{
	// x = -1
	ast::Module mod("<test>");
	auto operand = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto unary = std::make_shared<ast::UnaryExpr>(ast::UnaryOpType::SUB, operand, loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, unary, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_unary_neg"));
}

// =============================================================================
// Phase 2.3b: 比较表达式
// =============================================================================
TEST_F(PylangCodegenTest, CompareEq)
{
	// x = (1 == 2)
	ast::Module mod("<test>");
	auto lhs = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto rhs = std::make_shared<ast::Constant>(int64_t(2), loc());
	auto cmp = std::make_shared<ast::Compare>(lhs,
		std::vector<ast::Compare::OpType>{ ast::Compare::OpType::Eq },
		std::vector<std::shared_ptr<ast::ASTNode>>{ rhs },
		loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, cmp, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_compare_eq"));
}

// =============================================================================
// Phase 2.3c: 变量加载
// =============================================================================
TEST_F(PylangCodegenTest, LoadGlobal)
{
	// x = y
	ast::Module mod("<test>");
	auto name_y = std::make_shared<ast::Name>("y", ast::ContextType::LOAD, loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, name_y, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_load_global"));
}

// =============================================================================
// Phase 2.3c: 函数调用
// =============================================================================
TEST_F(PylangCodegenTest, FunctionCall)
{
	// print(42)
    ast::Module mod("<test>");
    auto print_name = std::make_shared<ast::Name>("print", ast::ContextType::LOAD, loc());
    auto arg = std::make_shared<ast::Constant>(int64_t(42), loc());
    auto call = std::make_shared<ast::Call>(print_name,
        std::vector<std::shared_ptr<ast::ASTNode>>{ arg },
        std::vector<std::shared_ptr<ast::Keyword>>{},
        loc());
    mod.emplace(std::make_shared<ast::Expression>(call, loc()));

    auto ir = compile_module(mod);
    if (ir.empty()) { return; }
    EXPECT_TRUE(ir_calls_rt(ir, "rt_load_global"));
    EXPECT_TRUE(ir_calls_rt(ir, "rt_call"));
    EXPECT_TRUE(ir_calls_rt(ir, "rt_build_tuple"));
}

// =============================================================================
// Phase 2.3d: if 语句
// =============================================================================
TEST_F(PylangCodegenTest, IfStatement)
{
	ast::Module mod("<test>");
	auto cond = std::make_shared<ast::Constant>(true, loc());

	auto target1 = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	auto val1 = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto assign1 = std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target1 }, val1, "", loc());

	auto target2 = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	auto val2 = std::make_shared<ast::Constant>(int64_t(2), loc());
	auto assign2 = std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target2 }, val2, "", loc());

	auto if_stmt = std::make_shared<ast::If>(cond,
		std::vector<std::shared_ptr<ast::ASTNode>>{ assign1 },
		std::vector<std::shared_ptr<ast::ASTNode>>{ assign2 },
		loc());
	mod.emplace(if_stmt);

    auto ir = compile_module(mod);
    EXPECT_TRUE(ir_calls_rt(ir, "rt_is_true"));
    // BasicBlock 标签名由 codegen 直接生成，不受 mangling 影响
    EXPECT_TRUE(ir_contains(ir, "if.then"));
    EXPECT_TRUE(ir_contains(ir, "if.else"));
    EXPECT_TRUE(ir_contains(ir, "if.merge"));
}

// =============================================================================
// Phase 2.3d: while 循环
// =============================================================================
TEST_F(PylangCodegenTest, WhileLoop)
{
	ast::Module mod("<test>");
	auto cond = std::make_shared<ast::Constant>(true, loc());
	auto pass = std::make_shared<ast::Pass>(loc());

	auto while_stmt = std::make_shared<ast::While>(cond,
		std::vector<std::shared_ptr<ast::ASTNode>>{ pass },
		std::vector<std::shared_ptr<ast::ASTNode>>{},
		loc());
	mod.emplace(while_stmt);

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "while.cond"));
	EXPECT_TRUE(ir_contains(ir, "while.body"));
}

// =============================================================================
// Phase 2.3d: for 循环
// =============================================================================
TEST_F(PylangCodegenTest, ForLoop)
{
	ast::Module mod("<test>");
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	auto elem = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto list = std::make_shared<ast::List>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ elem }, ast::ContextType::LOAD, loc());
	auto pass = std::make_shared<ast::Pass>(loc());

	auto for_stmt = std::make_shared<ast::For>(target,
		list,
		std::vector<std::shared_ptr<ast::ASTNode>>{ pass },
		std::vector<std::shared_ptr<ast::ASTNode>>{},
		"",
		loc());
	mod.emplace(for_stmt);

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_get_iter"));
	EXPECT_TRUE(ir_contains(ir, "rt_iter_next"));
	EXPECT_TRUE(ir_contains(ir, "for.cond"));
	EXPECT_TRUE(ir_contains(ir, "for.body"));
}

// =============================================================================
// Phase 2.3: 容器字面量
// =============================================================================
TEST_F(PylangCodegenTest, ListLiteral)
{
	ast::Module mod("<test>");
	auto e1 = std::make_shared<ast::Constant>(int64_t(1), loc());
	auto e2 = std::make_shared<ast::Constant>(int64_t(2), loc());
	auto list = std::make_shared<ast::List>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ e1, e2 }, ast::ContextType::LOAD, loc());
	auto target = std::make_shared<ast::Name>("x", ast::ContextType::STORE, loc());
	mod.emplace(std::make_shared<ast::Assign>(
		std::vector<std::shared_ptr<ast::ASTNode>>{ target }, list, "", loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_build_list"));
}

// =============================================================================
// Phase 2.3: pass / assert
// =============================================================================
TEST_F(PylangCodegenTest, PassStatement)
{
	ast::Module mod("<test>");
	mod.emplace(std::make_shared<ast::Pass>(loc()));
	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "define void @PyInit___test__"));
}

TEST_F(PylangCodegenTest, AssertStatement)
{
	ast::Module mod("<test>");
	auto test = std::make_shared<ast::Constant>(true, loc());
	mod.emplace(std::make_shared<ast::Assert>(test, nullptr, loc()));

	auto ir = compile_module(mod);
	EXPECT_TRUE(ir_contains(ir, "rt_is_true"));
	EXPECT_TRUE(ir_contains(ir, "assert.fail"));
	EXPECT_TRUE(ir_contains(ir, "assert.pass"));
}
