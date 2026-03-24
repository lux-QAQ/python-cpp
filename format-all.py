import os
import subprocess
import pathlib

def format_files():
    # 定义需要匹配的文件后缀
    extensions = {".cpp", ".hpp", ".h", ".c", ".cc", ".cxx"}
    
    # 确定 src 目录的路径（假设脚本在根目录）
    root_dir = pathlib.Path(__file__).parent
    src_dir = root_dir / "src"
    
    if not src_dir.exists():
        print(f"错误: 找不到目录 {src_dir}")
        return

    print(f"正在扫描并格式化: {src_dir} ...")
    
    count = 0
    # 递归遍历 src 目录
    for path in src_dir.rglob('*'):
        if path.suffix.lower() in extensions:
            try:
                # 调用 clang-format
                # -i 表示 Inplace (直接修改文件)
                # --style=file 会让它自动去根目录找 .clang-format 文件
                subprocess.run(["clang-format", "-i", "--style=file", str(path)], check=True)
                print(f"已格式化: {path.relative_to(root_dir)}")
                count += 1
            except subprocess.CalledProcessError as e:
                print(f"格式化失败: {path}, 错误: {e}")
            except FileNotFoundError:
                print("错误: 系统未找到 'clang-format' 命令，请确保已安装并在 PATH 中。")
                return

    print(f"\n完成！共处理了 {count} 个文件。")

if __name__ == "__main__":
    format_files()