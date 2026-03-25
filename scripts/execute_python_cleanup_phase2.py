#!/usr/bin/env python3
"""
Python Cleanup Campaign - Phase 2 Archival Execution
Archives the next 50 candidates identified by the scout
"""

import shutil
from pathlib import Path
from datetime import datetime

# Phase 2 Archival Candidates (next 50 after Phase 1)
# These are small files, stubs, single-function utilities identified by scout
ARCHIVAL_PHASE2 = [
    # Small utility files (<50 LOC, single function)
    "whitemagic/core/activation.py",
    "whitemagic/core/consciousness/__init__.py",
    "whitemagic/core/dreaming/__init__.py",
    "whitemagic/core/memory/__init__.py",
    "whitemagic/core/intelligence/__init__.py",
    "whitemagic/core/metabolism/__init__.py",
    "whitemagic/core/identity/__init__.py",
    "whitemagic/core/genetic/__init__.py",
    "whitemagic/core/immune/__init__.py",
    "whitemagic/core/resonance/__init__.py",
    
    # Tiny stub files
    "whitemagic/agents/__init__.py",
    "whitemagic/cascade/__init__.py",
    "whitemagic/cli/__init__.py",
    "whitemagic/edge/__init__.py",
    "whitemagic/gardens/__init__.py",
    "whitemagic/plugins/__init__.py",
    "whitemagic/tools/__init__.py",
    "whitemagic/benchmarks/__init__.py",
    "whitemagic/docs/__init__.py",
    "whitemagic/ai/__init__.py",
    
    # Single-function utilities (scout identified)
    "whitemagic/core/utils/quick_hash.py",
    "whitemagic/core/utils/timestamp.py",
    "whitemagic/core/utils/uuid_gen.py",
    "whitemagic/core/helpers/string_utils.py",
    "whitemagic/core/helpers/dict_utils.py",
    "whitemagic/core/helpers/list_utils.py",
    
    # Deprecated/legacy files
    "whitemagic/core/legacy/__init__.py",
    "whitemagic/core/legacy/v15_compatibility.py",
    "whitemagic/core/legacy/v14_adapter.py",
    
    # Test stubs (not actual tests)
    "tests/__init__.py",
    "tests/unit/__init__.py",
    "tests/integration/__init__.py",
    "tests/e2e/__init__.py",
    "tests/fixtures/__init__.py",
    
    # Script stubs
    "scripts/__init__.py",
    "scripts/utils/__init__.py",
    "scripts/helpers/__init__.py",
    
    # Eval stubs
    "eval/__init__.py",
    "eval/fixtures/__init__.py",
    
    # SDK stubs
    "sdk/__init__.py",
    "sdk/python/__init__.py",
    
    # Nexus stubs
    "nexus/__init__.py",
    "nexus/core/__init__.py",
    
    # Small orphan files
    "whitemagic/core/constants.py",
    "whitemagic/core/version.py",
    "whitemagic/core/exceptions.py",
    "whitemagic/core/types.py",
]

def execute_phase2_archival():
    """Execute Phase 2 archival of 50 candidates."""
    root = Path('/home/lucas/Desktop/whitemagicdev')
    archive_dir = root / '_archives' / 'python_cleanup_v17_phase2'
    archive_dir.mkdir(parents=True, exist_ok=True)
    
    archived = []
    failed = []
    skipped = []
    
    print("🗂️  Python Cleanup Campaign - Phase 2 Archival Execution")
    print("=" * 60)
    print(f"Target: {len(ARCHIVAL_PHASE2)} candidates")
    print("")
    
    for candidate in ARCHIVAL_PHASE2:
        src = root / candidate
        if not src.exists():
            skipped.append((candidate, "File not found"))
            continue
        
        # Check if file is small (<100 LOC) or stub
        try:
            with open(src, 'r') as f:
                lines = len(f.readlines())
            if lines > 200:
                skipped.append((candidate, f"Too large ({lines} LOC)"))
                continue
        except:
            skipped.append((candidate, "Cannot read"))
            continue
        
        # Preserve directory structure in archive
        dest = archive_dir / candidate
        dest.parent.mkdir(parents=True, exist_ok=True)
        
        try:
            shutil.move(str(src), str(dest))
            archived.append((candidate, lines))
            print(f"  ✅ Archived: {candidate} ({lines} LOC)")
        except Exception as e:
            failed.append((candidate, str(e)))
            print(f"  ❌ Failed: {candidate} - {e}")
    
    # Write manifest
    manifest = archive_dir / 'MANIFEST.md'
    with open(manifest, 'w') as f:
        f.write("# Python Cleanup v17 - Phase 2 Archived Files\n\n")
        f.write(f"Date: {datetime.now().isoformat()}\n\n")
        f.write(f"## Successfully Archived ({len(archived)} files)\n\n")
        total_loc = sum(loc for _, loc in archived)
        for candidate, loc in archived:
            f.write(f"- `{candidate}` ({loc} LOC)\n")
        f.write(f"\n**Total LOC archived**: {total_loc}\n\n")
        
        if skipped:
            f.write(f"## Skipped ({len(skipped)} files)\n\n")
            for candidate, reason in skipped:
                f.write(f"- `{candidate}`: {reason}\n")
            f.write("\n")
        
        if failed:
            f.write(f"## Failed ({len(failed)} files)\n\n")
            for candidate, reason in failed:
                f.write(f"- `{candidate}`: {reason}\n")
    
    print("\n" + "=" * 60)
    print(f"Phase 2 complete: {len(archived)} archived, {len(skipped)} skipped, {len(failed)} failed")
    print(f"Archive location: {archive_dir}")
    print(f"Manifest: {manifest}")
    
    return len(archived), len(skipped), len(failed)

if __name__ == '__main__':
    archived, skipped, failed = execute_phase2_archival()
    print(f"\nSummary: {archived} archived, {skipped} skipped, {failed} failed")
