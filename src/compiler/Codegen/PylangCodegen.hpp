#pragma once

// =============================================================================
// PylangCodegen — AST → LLVM IR 代码生成器
//
// 职责:
//   - 继承 ast::CodeGenerator，为每种 AST 节点实现 visit() 方法
//   - 使用 IREmitter 生成对 runtime 导出函数的调用
//   - 使用 CodegenContext 管理变量和作用域
//   - 使用 VariablesResolver 的分析结果确定变量访问方式
//
// 架构层次:
//   PylangCodegen (语义层)
//     → IREmitter (中间层)
//       → RuntimeLinker (底层)
//         → runtime.bc
//
// 参考:
//   BytecodeGenerator 的 visit() 方法结构
//   compile.md §4 的详细设计
// =============================================================================

#include "CodegenContext.hpp"
#include "IREmitter.hpp"

#include "ast/AST.hpp"
#include "executable/Mangler.hpp"
#include "executable/bytecode/codegen/VariablesResolver.hpp"

#include "compiler/Support/Error.hpp"

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <memory>
#include <string>

namespace pylang {

// =============================================================================
// LLVMValue — 包装 llvm::Value*，继承 ast::Value 以融入 CodeGenerator 框架
// =============================================================================
class LLVMValue : public ast::Value
{
	llvm::Value *m_llvm_value;

  public:
	LLVMValue(llvm::Value *val) : ast::Value(""), m_llvm_value(val) {}
	LLVMValue(const std::string &name, llvm::Value *val) : ast::Value(name), m_llvm_value(val) {}

	llvm::Value *llvm_value() const { return m_llvm_value; }
};

// =============================================================================
// PylangCodegen
// =============================================================================
class PylangCodegen : public ast::CodeGenerator
{
  public:
	/// 编译结果
	struct CompileResult
	{
		std::unique_ptr<llvm::Module> module;
	};

	/// 入口: 编译一个 Python 模块
	///
	/// @param module_node  解析后的 AST 模块节点
	/// @param module_name  模块名（用于 LLVM Module name 和函数 mangling）
	/// @param ctx          LLVM 上下文
	/// @param linker       已加载 runtime.bc 的 RuntimeLinker
	static Result<CompileResult> compile(ast::Module *module_node,
		std::string_view module_name,
		llvm::LLVMContext &ctx,
		RuntimeLinker &linker);

  private:
	PylangCodegen(llvm::LLVMContext &ctx,
		RuntimeLinker &linker,
		std::unique_ptr<llvm::Module> module,
		const VisibilityMap &visibility,
		std::string module_name);

	// ---- ast::CodeGenerator 接口 ----
#define __AST_NODE_TYPE(NodeType) ast::Value *visit(const ast::NodeType *node) override;
	AST_NODE_TYPES
#undef __AST_NODE_TYPE

	// ---- 核心生成方法 ----

	/// 对 AST 节点调用 codegen 并提取 llvm::Value*
	llvm::Value *generate(const ast::ASTNode *node);

	/// 编译语句体（多个节点）
	void generate_body(const std::vector<std::shared_ptr<ast::ASTNode>> &body);

	/// 创建模块初始化函数: void @PyInit_<module>()
	llvm::Function *create_module_init_function();

	/// 创建 main(): int main() { rt_init(); PyInit_<mod>(); rt_shutdown(); }
	llvm::Function *create_main_function(llvm::Function *module_init);

	// ---- 变量操作 ----

	/// 加载变量（根据 Visibility 决定路径）
	llvm::Value *load_variable(const std::string &name);

	/// 存储变量（根据 Visibility 决定路径）
	void store_variable(const std::string &name, llvm::Value *value);

	/// 删除变量（根据 Visibility 决定路径）
	void delete_variable(const std::string &name);

	// ---- 赋值目标 ----

	/// 对赋值目标（Name/Tuple/List/Subscript/Attribute）生成存储 IR
	void generate_store_target(const ast::ASTNode *target, llvm::Value *value);

	// ---- 辅助工具 ----

	/// 创建 LLVMValue 并注册到 m_values（GC 管理生命周期）
	LLVMValue *make_value(llvm::Value *val, const std::string &name = "");

	// ---- 成员 ----

	llvm::LLVMContext &m_ctx;
	std::unique_ptr<llvm::Module> m_module;
	llvm::IRBuilder<> m_builder;
	IREmitter m_emitter;
	CodegenContext m_codegen_ctx;
	std::string m_module_name;
	Mangler &m_mangler;
};

} // namespace pylang
