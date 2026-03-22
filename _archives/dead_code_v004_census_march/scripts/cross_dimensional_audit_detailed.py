import os
import filecmp

dev_dir = "/home/lucas/Desktop/whitemagicdev"
pub_dir = "/home/lucas/Desktop/whitemagicpublic"

def get_all_files(directory, ignore_dirs=('.git', '__pycache__', 'node_modules', '.venv', 'target', 'deps', '_build', 'koka-clones', '.mypy_cache')):
    files_set = set()
    for root, dirs, files in os.walk(directory):
        dirs[:] = [d for d in dirs if d not in ignore_dirs]
        for file in files:
            if file.endswith('.pyc') or file.endswith('.so') or file.endswith('.o'):
                continue
            rel_path = os.path.relpath(os.path.join(root, file), directory)
            files_set.add(rel_path)
    return files_set

dev_files = get_all_files(dev_dir)
pub_files = get_all_files(pub_dir)
common_files = dev_files.intersection(pub_files)

diff_files = []
for f in common_files:
    try:
        if not filecmp.cmp(os.path.join(dev_dir, f), os.path.join(pub_dir, f), shallow=False):
            diff_files.append(f)
    except Exception:
        pass

print("--- Top 50 Modified Source Files (excluding caches) ---")
diff_source = [f for f in diff_files if f.endswith('.py') or f.endswith('.md') or f.endswith('.rs') or f.endswith('.kk') or f.endswith('.exs')]
for f in sorted(diff_source)[:50]:
    print(f"- {f}")

