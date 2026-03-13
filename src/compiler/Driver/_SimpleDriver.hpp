#pragma once

// =============================================================================
// SimpleDriver — 开发测试用的单文件编译驱动
//
// 驱动完整管道：AST → Codegen → Link Runtime → Optimize → Emit
// 用于验证 visit() 正确性和实现 hello world 里程碑
//
// 用法:
//   auto driver = SimpleDriver::create(opts, ctx)
//                   | unwrap_or_die("driver init failed");
//   driver.compile_to_ir(module, "test")
//         .transform([](auto ir) { std::cout << ir; });
// =============================================================================

#include "compiler/Codegen/PylangCodegen.hpp"
#include "compiler/RuntimeLinker/RuntimeLinker.hpp"
#include "compiler/Support/Error.hpp"
#include "compiler/Support/LLVMUtils.hpp"
#include "compiler/Support/Log.hpp"

#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>

#include <filesystem>
#include <memory>
#include <string>
#include <string_view>

namespace pylang {

class SimpleDriver
{
  public:
    // =========================================================================
    // 输出格式
    // =========================================================================
    enum class OutputKind : uint8_t {
        IRText,     // .ll — 人类可读 IR（测试/调试首选）
        Bitcode,    // .bc — LLVM bitcode
        ObjectFile, // .o  — 原生目标文件
        Executable, // 二进制可执行文件
    };

    // =========================================================================
    // 配置选项
    // =========================================================================
    struct Options
    {
        std::filesystem::path runtime_bc_path; // runtime.bc 路径
        std::filesystem::path output_path;     // 输出路径（空则自动推断）
        OutputKind output_kind = OutputKind::Executable;
        int opt_level = 2;                // 0-3, 对应 O0-O3
        bool dump_ir_before_opt = false;  // 优化前 dump IR
        bool dump_ir_after_opt = false;   // 优化后 dump IR
        bool verify_module = true;        // 每阶段后验证
        std::string linker_cmd = "c++";   // 系统链接器
        std::vector<std::string> extra_link_flags; // 额外链接参数
    };

    // =========================================================================
    // 工厂方法
    // =========================================================================
    static Result<SimpleDriver> create(Options opts, llvm::LLVMContext &ctx);

    // =========================================================================
    // 编译入口
    // =========================================================================

    /// 完整管道: AST → 可执行文件/目标文件
    Result<std::filesystem::path> compile_module(
        ast::Module &module, std::string_view module_name);

    /// 部分管道: AST → 优化后 IR 文本（用于高级测试）
    Result<std::string> compile_to_ir(
        ast::Module &module, std::string_view module_name);

    /// 部分管道: AST → 未优化 IR 文本（用于 codegen 单元测试）
    Result<std::string> emit_unoptimized_ir(
        ast::Module &module, std::string_view module_name);

    /// 访问 RuntimeLinker（供测试使用）
    RuntimeLinker &linker() { return m_linker; }
    llvm::LLVMContext &context() { return *m_ctx; }

  private:
    SimpleDriver(Options opts,
        llvm::LLVMContext &ctx,
        LLVMModuleLoader loader,
        RuntimeLinker linker,
        std::unique_ptr<llvm::TargetMachine> tm);

    // =========================================================================
    // 管道阶段（每个阶段返回 Result<T>，可组合）
    // =========================================================================

    /// Stage 1: AST → LLVM Module (未优化, 未链接 runtime)
    Result<std::unique_ptr<llvm::Module>> stage_codegen(
        ast::Module &module, std::string_view name);

    /// Stage 2: 将 runtime.bc 链接到用户 Module
    Result<std::unique_ptr<llvm::Module>> stage_link_runtime(
        std::unique_ptr<llvm::Module> user_mod);

    /// Stage 3: LLVM 中端优化
    VoidResult stage_optimize(llvm::Module &module);

    /// Stage 4a: 输出 IR 文本
    static Result<std::string> stage_to_ir_string(llvm::Module &module);

    /// Stage 4b: 输出目标文件
    Result<std::filesystem::path> stage_to_object(
        llvm::Module &module, const std::filesystem::path &output);

    /// Stage 4c: 输出 bitcode
    static Result<std::filesystem::path> stage_to_bitcode(
        llvm::Module &module, const std::filesystem::path &output);

    /// Stage 5: 系统链接器 → 可执行文件
    Result<std::filesystem::path> stage_link_executable(
        const std::filesystem::path &obj_path);

    // =========================================================================
    // 辅助
    // =========================================================================

    /// LLVM 目标初始化（call_once）
    static VoidResult initialize_targets();

    /// 创建宿主机 TargetMachine
    static Result<std::unique_ptr<llvm::TargetMachine>> create_host_target_machine(
        int opt_level);

    /// 推断输出路径
    std::filesystem::path infer_output_path(
        std::string_view module_name, OutputKind kind) const;

    // =========================================================================
    // 成员
    // =========================================================================
    Options m_opts;
    llvm::LLVMContext *m_ctx;
    LLVMModuleLoader m_loader;
    RuntimeLinker m_linker;
    std::unique_ptr<llvm::TargetMachine> m_target_machine;
};

} // namespace pylang