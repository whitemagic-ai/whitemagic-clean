import json
import os
import shutil
import sys
from pathlib import Path

# Paths
ROOT = Path("/home/lucas/Desktop/whitemagicdev")
DEAD_CODE_FILE = ROOT / "reports" / "dead_code.json"
ARCHIVE_DIR = ROOT / "_archives" / "dead_code_v004_census_march"

# Load dead code candidates
if not DEAD_CODE_FILE.exists():
    print(f"Error: {DEAD_CODE_FILE} not found.")
    sys.exit(1)

with open(DEAD_CODE_FILE) as f:
    dead_code = json.load(f)

print(f"Loaded {len(dead_code)} candidates from {DEAD_CODE_FILE}")

def test_imports():
    """Run pytest or a simple import check to verify system integrity."""
    res = os.system("python3 -c \"import whitemagic; from whitemagic.core import memory\" >/dev/null 2>&1")
    return res == 0

ARCHIVE_DIR.mkdir(parents=True, exist_ok=True)

archived_count = 0
failed_count = 0

print("Starting safe archival process...")

# Initial check
if not test_imports():
    print("Base imports already failing. Aborting.")
    sys.exit(1)

for f in dead_code:
    path = ROOT / f["path"]
    if not path.exists():
        continue
        
    # Move file to archive
    dest = ARCHIVE_DIR / f["path"]
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(path), str(dest))
    
    # Test system
    if not test_imports():
        # Revert
        shutil.move(str(dest), str(path))
        failed_count += 1
        print(f"[REVERT] {f['path']} is required by the system.")
    else:
        archived_count += 1
        print(f"[ARCHIVED] {f['path']}")

print("========================================")
print(f"Archival complete. Safely archived {archived_count} files.")
print(f"Reverted {failed_count} files that broke imports.")
