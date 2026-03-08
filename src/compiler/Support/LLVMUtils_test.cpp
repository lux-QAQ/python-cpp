

#include "compiler/Support/LLVMUtils.hpp"
#include "compiler/Support/gtest_wrapper.hpp"

#include <gtest/gtest.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <filesystem>
#include <fstream>

using namespace pylang;

class LLVMModuleLoaderTest : public ::testing::Test
{
  protected:
	void SetUp() override
	{
		loader = std::make_unique<LLVMModuleLoader>(ctx);

		// 创建临时测试文件
		test_dir = std::filesystem::temp_directory_path() / "pylang_test";
		std::filesystem::create_directories(test_dir);
	}

	void TearDown() override { std::filesystem::remove_all(test_dir); }

	llvm::LLVMContext ctx;
	std::unique_ptr<LLVMModuleLoader> loader;
	std::filesystem::path test_dir;
};

TEST_F(LLVMModuleLoaderTest, LoadNonexistentFile)
{
	auto result = loader->load_bitcode(test_dir / "nonexistent.bc");
	EXPECT_FALSE(result.has_value());
	EXPECT_EQ(result.error().kind(), ErrorKind::BitcodeLoadFailed);
}

TEST_F(LLVMModuleLoaderTest, LoadInvalidBitcode)
{
	// 创建一个无效的 bitcode 文件
	auto invalid_bc = test_dir / "invalid.bc";
	std::ofstream(invalid_bc) << "This is not valid LLVM bitcode";

	auto result = loader->load_bitcode(invalid_bc);
	EXPECT_FALSE(result.has_value());
	EXPECT_EQ(result.error().kind(), ErrorKind::BitcodeLoadFailed);
}

TEST_F(LLVMModuleLoaderTest, CacheHit)
{
	// 这个测试需要一个有效的 bitcode 文件
	// 暂时跳过，等 runtime.bc 生成后再测试
	GTEST_SKIP() << "Requires valid bitcode file";
}

TEST_F(LLVMModuleLoaderTest, VerifyModule)
{
	// 创建一个简单的有效 Module
	llvm::Module mod("test", ctx);
	auto *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), false);
	llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "test_func", &mod);

	auto result = LLVMModuleLoader::verify_module(mod);
	EXPECT_TRUE(result.has_value());
}

TEST_F(LLVMModuleLoaderTest, VerifyInvalidModule)
{
	// 创建一个无效的 Module（空的函数体但不是声明）
	llvm::Module mod("test_invalid", ctx);
	auto *func_type = llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), false);
	auto *func =
		llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, "invalid_func", &mod);

	// 创建一个基本块但不添加终止指令（无效）
	llvm::BasicBlock::Create(ctx, "entry", func);

	auto result = LLVMModuleLoader::verify_module(mod);
	EXPECT_FALSE(result.has_value());
	EXPECT_EQ(result.error().kind(), ErrorKind::VerificationFailed);
}