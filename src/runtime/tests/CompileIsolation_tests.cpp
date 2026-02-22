// =============================================================================
// 编译隔离测试
// =============================================================================
// 此文件的目的: 验证 runtime 核心头文件不传递依赖 vm/VM.hpp
// 如果任何头文件间接 #include "vm/VM.hpp"，则 VM_HEADER_SHOULD_NOT_BE_INCLUDED
// 宏会触发编译错误。
//
// 原理: 在包含 runtime 头文件之前定义一个"毒丸"宏。
// 如果 vm/VM.hpp 被间接包含，它会试图定义 VirtualMachine 类，
// 但我们在此文件中先 static_assert 验证 VirtualMachine 未被声明。
// =============================================================================

// 先包含所有 runtime 头文件（不应拉入 VM.hpp）
#include "interpreter/InterpreterCore.hpp"
#include "runtime/Import.hpp"
#include "runtime/KeyVersionTracker.hpp"
#include "runtime/ModuleRegistry.hpp"
#include "runtime/PyModule.hpp"
#include "runtime/RuntimeContext.hpp"

#include <gtest/gtest.h>

// 如果 VM.hpp 被间接包含，VirtualMachine 类会被定义
// 我们通过检查 VirtualMachine 是否为完整类型来验证隔离性
namespace compile_isolation_detail {

// 辅助: 检查类型是否完整（SFINAE）
template<typename T, typename = void> struct is_complete : std::false_type
{
};

template<typename T> struct is_complete<T, std::void_t<decltype(sizeof(T))>> : std::true_type
{
};

}// namespace compile_isolation_detail

// VirtualMachine 只有前向声明（来自 forward.hpp），不应是完整类型
// 如果此 static_assert 失败 → 某个 runtime 头文件间接包含了 vm/VM.hpp
static_assert(!compile_isolation_detail::is_complete<VirtualMachine>::value,
	"ISOLATION VIOLATION: runtime headers should not include vm/VM.hpp! "
	"VirtualMachine is a complete type, meaning vm/VM.hpp was transitively included.");

TEST(CompileIsolation, RuntimeHeadersDoNotIncludeVM)
{
	// 如果编译到这里，说明 static_assert 通过
	// runtime 头文件没有传递依赖 vm/VM.hpp
	SUCCEED();
}