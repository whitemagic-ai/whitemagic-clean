import os
import filecmp

def get_all_files(directory, ignore_dirs=('.git', '__pycache__', 'node_modules', '.venv', 'target', 'deps', '_build', 'koka-clones')):
    files_set = set()
    for root, dirs, files in os.walk(directory):
        dirs[:] = [d for d in dirs if d not in ignore_dirs]
        for file in files:
            # ignore some binary or cache files
            if file.endswith('.pyc') or file.endswith('.so') or file.endswith('.o'):
                continue
            rel_path = os.path.relpath(os.path.join(root, file), directory)
            files_set.add(rel_path)
    return files_set

dev_dir = "/home/lucas/Desktop/whitemagicdev"
pub_dir = "/home/lucas/Desktop/whitemagicpublic"

dev_files = get_all_files(dev_dir)
pub_files = get_all_files(pub_dir)

common_files = dev_files.intersection(pub_files)
dev_only = dev_files - pub_files
pub_only = pub_files - dev_files

diff_files = []
for f in common_files:
    try:
        if not filecmp.cmp(os.path.join(dev_dir, f), os.path.join(pub_dir, f), shallow=False):
            diff_files.append(f)
    except Exception:
        pass

print("=== Cross-Dimensional Audit: whitemagicdev vs whitemagicpublic ===")
print(f"Total files in DEV: {len(dev_files)}")
print(f"Total files in PUB: {len(pub_files)}")
print(f"Common files: {len(common_files)}")
print(f"Files ONLY in DEV: {len(dev_only)}")
print(f"Files ONLY in PUB: {len(pub_only)}")
print(f"Files modified between dimensions: {len(diff_files)}\n")

print("--- Top 20 Modified Files ---")
for f in sorted(diff_files)[:20]:
    print(f"- {f}")

print("\n--- Top 20 Notable Files ONLY in DEV ---")
dev_only_notable = [f for f in dev_only if f.endswith('.md') or f.endswith('.py') or f.endswith('.exs')]
for f in sorted(dev_only_notable)[:20]:
    print(f"- {f}")

