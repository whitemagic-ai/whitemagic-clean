#!/usr/bin/env python3
"""
Archive Large Windsurf Cascade Files
Moves .pb files > 10MB to an archive directory to reduce IDE memory pressure.
"""
import os
import shutil
from pathlib import Path

CASCADE_DIR = Path.home() / ".codeium" / "windsurf" / "cascade"
ARCHIVE_DIR = Path.home() / ".codeium" / "windsurf" / "cascade_archive"

def archive_large_files(threshold_mb=10):
    if not ARCHIVE_DIR.exists():
        ARCHIVE_DIR.mkdir(parents=True)
        print(f"Created archive directory: {ARCHIVE_DIR}")

    files = list(CASCADE_DIR.glob("*.pb"))
    archived_count = 0
    
    for f in files:
        size_mb = f.stat().st_size / (1024 * 1024)
        if size_mb > threshold_mb:
            print(f"Archiving {f.name} ({size_mb:.2f} MB)...")
            shutil.move(str(f), str(ARCHIVE_DIR / f.name))
            archived_count += 1
            
    print(f"\nSuccessfully archived {archived_count} files.")

if __name__ == "__main__":
    archive_large_files()
