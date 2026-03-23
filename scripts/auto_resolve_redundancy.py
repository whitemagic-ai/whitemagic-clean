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

def main():
    if not REDUNDANCY_FILE.exists():
        return
    with open(REDUNDANCY_FILE) as f:
        pairs = json.load(f)

    # Let's target files that are clearly test/legacy artifacts, but only if they have high similarity
    # We will look for pairs where one is a test file and the other is a legacy test file, etc.
    # Alternatively, we can just print the top 100 pairs with highest similarity to see what they are.

    high_sim = [p for p in pairs if p["similarity"] >= 0.8]
    print(f"Found {len(high_sim)} pairs with >= 80% similarity.")

    archivable = []
    for p in high_sim:
        a = p["file_a"]
        b = p["file_b"]

        # Heuristics for redundancy
        # 1. One is a patch/fix script and the other is another patch/fix script
        if "patch_" in a and "patch_" in b:
            archivable.append(max((a, b), key=len))
            continue

        # 2. One is a duplicate in a different folder but has the exact same name
        if Path(a).name == Path(b).name and Path(a) != Path(b):
            # Prefer keeping the one with a shorter path
            if len(str(a)) > len(str(b)):
                archivable.append(a)
            else:
                archivable.append(b)
            continue

    # Remove duplicates
    archivable = list(set(archivable))
    print(f"Identified {len(archivable)} safe candidates to archive.")

    ARCHIVE_DIR.mkdir(parents=True, exist_ok=True)
    archived = 0
    reverted = 0

    for target in archivable:
        path_t = ROOT / target
        if not path_t.exists():
            continue

        rel_target = path_t.relative_to(ROOT)
        dest = ARCHIVE_DIR / rel_target
        dest.parent.mkdir(parents=True, exist_ok=True)

        shutil.move(str(path_t), str(dest))
        if not test_imports():
            shutil.move(str(dest), str(path_t))
            reverted += 1
            print(f"  [REVERT] {rel_target}")
        else:
            archived += 1
            print(f"  [ARCHIVED] {rel_target}")

    print(f"\nArchived {archived} highly similar files. Reverted {reverted}.")

if __name__ == "__main__":
    main()
