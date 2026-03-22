import hashlib
import json
import os
import shutil
from pathlib import Path

ROOT = Path("/home/lucas/Desktop/whitemagicdev")
REDUNDANCY_FILE = ROOT / "reports" / "redundancy_pairs_full.json"
ARCHIVE_DIR = ROOT / "_archives" / "redundant_code_v004_census_march"

def test_imports():
    res = os.system("python3 -c \"import whitemagic; from whitemagic.core import memory\" >/dev/null 2>&1")
    return res == 0

def get_file_hash(path: Path) -> str:
    if not path.exists(): return ""
    return hashlib.md5(path.read_bytes()).hexdigest()

def main():
    if not REDUNDANCY_FILE.exists():
        print(f"Error: {REDUNDANCY_FILE} not found.")
        return

    with open(REDUNDANCY_FILE) as f:
        pairs = json.load(f)

    # Let's find content duplicates (exact text match)
    print("Finding exact text duplicates...")
    archived_count = 0
    failed_count = 0

    ARCHIVE_DIR.mkdir(parents=True, exist_ok=True)

    for p in pairs:
        path_a = ROOT / p["file_a"]
        path_b = ROOT / p["file_b"]

        if not path_a.exists() or not path_b.exists():
            continue

        if get_file_hash(path_a) == get_file_hash(path_b):
            print(f"Exact text match found:\n  A: {p['file_a']}\n  B: {p['file_b']}")

            target_to_archive = None
            if "legacy" in path_b.name or "archive" in path_b.name or len(str(path_b)) > len(str(path_a)):
                target_to_archive = path_b
            else:
                target_to_archive = path_a

            rel_target = target_to_archive.relative_to(ROOT)
            dest = ARCHIVE_DIR / rel_target
            dest.parent.mkdir(parents=True, exist_ok=True)

            shutil.move(str(target_to_archive), str(dest))

            if not test_imports():
                shutil.move(str(dest), str(target_to_archive))
                failed_count += 1
                print(f"  [REVERT] Archiving {rel_target} broke imports.")
            else:
                archived_count += 1
                print(f"  [ARCHIVED] {rel_target}")

    print(f"\nCompleted: Archived {archived_count} exact text duplicate files. Reverted {failed_count}.")

if __name__ == "__main__":
    main()
