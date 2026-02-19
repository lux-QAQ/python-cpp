#!/usr/bin/env bash
# filepath: /home/lux/code/language/python-cpp/src/runtime/1.sh
set -euo pipefail

# 1. 获取脚本所在的绝对路径 (即 src/runtime)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 2. 自动寻找项目根目录 (向上查找，直到找到 src 文件夹)
# 这样无论你在哪个目录下运行脚本，它都能找到正确的根
CURRENT="$SCRIPT_DIR"
while [[ "$CURRENT" != "/" && ! -d "$CURRENT/src" ]]; do
  CURRENT="$(dirname "$CURRENT")"
done
ROOT="$CURRENT"

cd "$ROOT"

# 3. 此时 SCAN_DIR 就是相对于 ROOT 的路径
SCAN_DIR="src/runtime"
BACKUP_ROOT="back/src"

# 调试信息：如果报错，可以一眼看出路径哪里错了
echo "--- 路径检查 ---"
echo "脚本目录: $SCRIPT_DIR"
echo "项目根目录: $ROOT"
echo "扫描目标: $ROOT/$SCAN_DIR"
echo "----------------"

if [ ! -d "$SCAN_DIR" ]; then
  echo "错误: 找不到目录 $SCAN_DIR，请确认你在正确的项目目录下运行。"
  exit 1
fi

echo "正在递归扫描 ${SCAN_DIR} 下的内存分配函数使用情况..."

# 2. 仅在 src/runtime 下查找包含 heap().allocate 或 heap.allocate 的文件
# 使用 -E 开启扩展正则
mapfile -t FILES < <(grep -rnl -E "heap\(\)\.allocate(_static)?<|heap\.allocate(_static)?<" "$SCAN_DIR" || true)

if [ ${#FILES[@]} -eq 0 ]; then
  echo "在 ${SCAN_DIR} 中未发现匹配项。"
  exit 0
fi

headers=()
candidates=()

for f in "${FILES[@]}"; do
  case "$f" in
    *.hpp|*.h|*.hh) headers+=("$f") ;;
    *) candidates+=("$f") ;;
  esac
done

echo "待自动修改的实现文件 (.cpp/.cc): ${#candidates[@]}"
[ ${#candidates[@]} -gt 0 ] && printf ' - %s\n' "${candidates[@]}"

echo "检测到的 Header (仅列出供参考，脚本不会自动修改): ${#headers[@]}"
[ ${#headers[@]} -gt 0 ] && printf ' - %s\n' "${headers[@]}"

if [ ${#candidates[@]} -eq 0 ]; then
  echo "没有需要处理的实现文件。"
  exit 0
fi

read -p "继续在上述实现文件中执行自动替换并创建备份吗？ [y/N] " yn
yn=${yn:-N}
if [[ ! "$yn" =~ ^[Yy]$ ]]; then
  echo "已取消。"
  exit 0
fi

# 3. 执行替换逻辑
for f in "${candidates[@]}"; do
  # 创建备份 (保持相对于根目录的结构)
  # 如果 f 是 src/runtime/foo.cpp，则备份到 back/src/runtime/foo.cpp
  rel_path="${f#src/}"
  backup_file="$BACKUP_ROOT/$rel_path"
  mkdir -p "$(dirname "$backup_file")"
  cp "$f" "$backup_file"
  echo "正在处理: $f"

  # A. 注入 include "runtime/compat.hpp" (如果不存在)
  if ! grep -Fq '#include "runtime/compat.hpp"' "$f"; then
    # 在最后一个 #include 行之后插入
    perl -i -0777 -pe 's/(.*^#include[^\n]*\n)/$1#include "runtime\/compat.hpp"\n/sm' "$f"
    echo "  -> 已添加 #include \"runtime/compat.hpp\""
  fi

  # B. 替换 VirtualMachine::the().heap().allocate<Type>(args...)
  # 增加了对多行参数的处理 (s 标志)
  perl -0777 -i -pe 's/\bVirtualMachine::the\(\)\.heap\(\)\.allocate(?:_static)?<\s*([A-Za-z0-9_:]+)\s*>\s*\((.*?)\)/PYLANG_ALLOC($1, $2)/gs' "$f"

  # C. 替换 var.allocate<Type>(args...) 
  # 排除指针调用 (->)
  perl -0777 -i -pe 's/(?<!->)\b([A-Za-z_][A-Za-z0-9_]*)\.allocate(?:_static)?<\s*([A-Za-z0-9_:]+)\s*>\s*\((.*?)\)/PYLANG_ALLOC($2, $3)/gs' "$f"

done

echo "------------------------------------------"
echo "处理完成！"
echo "修改的文件数: ${#candidates[@]}"
echo "备份位置: $BACKUP_ROOT"
echo "提示：请检查 PYLANG_ALLOC 后的参数括号配对情况，尤其是复杂的构造函数参数。"