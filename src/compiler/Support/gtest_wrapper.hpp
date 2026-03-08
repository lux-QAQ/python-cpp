#pragma once

// =============================================================================
// GTest Wrapper — 解决 LLVM cxxabi.h 与 GCC libstdc++ 冲突
// =============================================================================

// 首先，强行屏蔽所有可能出现的 cxxabi.h 这个罪魁祸首！
// 在这整个文件及被它包含的内容中，我们假装 cxxabi 已经被包含了！
#define __LIBCXXABI_CXXABI_H
#define _LIBCXXABI_CXXABI_H
#define __CXXABI_H
#define _CXXABI_H

#include <cstddef>

// GTest (gtest-type-util.h 的 76 行) 需要 abi::__cxa_demangle 这个函数来打印类型名。
// 既然我们吃掉了整个头文件，必须手动把这个函数的声明喂给它。
// 这就是标准库提供这个函数的原型。
namespace abi {
    extern "C" char* __cxa_demangle(const char* mangled_name,
                                    char* output_buffer, 
                                    size_t* length, 
                                    int* status);
}

// 在屏蔽宏和替代声明下，包含 gtest
#include <gtest/gtest.h>