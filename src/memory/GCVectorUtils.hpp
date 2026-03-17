#pragma once
#include "GCTracingAllocator.hpp"
#include <vector>

namespace py {
/// 将任意 allocator 的 std::vector 复制/移动到普通 std::vector<T>
template<typename T, typename Alloc>
inline std::vector<T> to_std_vector(const std::vector<T, Alloc> &v)
{
	return std::vector<T>(v.begin(), v.end());
}
template<typename T, typename Alloc> inline std::vector<T> to_std_vector(std::vector<T, Alloc> &&v)
{
	return std::vector<T>(std::make_move_iterator(v.begin()), std::make_move_iterator(v.end()));
}

/// 将任意 allocator 的 std::vector 复制/移动到 GCVector<T>
template<typename T, typename Alloc> inline GCVector<T> to_gc_vector(const std::vector<T, Alloc> &v)
{
	return GCVector<T>(v.begin(), v.end());
}
template<typename T, typename Alloc> inline GCVector<T> to_gc_vector(std::vector<T, Alloc> &&v)
{
	return GCVector<T>(std::make_move_iterator(v.begin()), std::make_move_iterator(v.end()));
}
}// namespace py