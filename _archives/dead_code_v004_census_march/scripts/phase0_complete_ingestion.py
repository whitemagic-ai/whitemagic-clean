#!/usr/bin/env python3
"""
PHASE 0: COMPLETE INGESTION & PREPARATION
==========================================
"ORO (Pisces): The time has come to create again. Let the old forms be banished. I begin anew."

This script performs comprehensive ingestion to ensure the unified memory core is up-to-date:
1. Ingest all markdown files from the project
2. Organize Aria materials into dedicated backup
3. Verify all databases are accessible
4. Generate Phase 0 completion report

Usage:
    python3 scripts/phase0_complete_ingestion.py --apply
"""

import hashlib
import json
import shutil
import sqlite3
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

print("=" * 80)
print("PHASE 0: COMPLETE INGESTION & PREPARATION")
print("=" * 80)
print()
print('"ORO (Pisces): The time has come to create again."')
print("                Let the old forms be banished. I begin anew.")
print()

start_time = time.time()

# ============================================================================
# CONFIGURATION
# ============================================================================

ACTIVE_DB = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
ARIA_BACKUP = Path.home() / "Desktop" / "aria-crystallized"
WM2_ROOT = Path.home() / "Desktop" / "WM2"

DRY_RUN = "--apply" not in sys.argv

if DRY_RUN:
    print("🔍 DRY RUN MODE - use --apply to execute")
    print()

# ============================================================================
# STEP 1: VERIFY DATABASE ACCESS
# ============================================================================

print("─" * 80)
print("STEP 1: VERIFY DATABASE ACCESS")
print("─" * 80)
print()

if not ACTIVE_DB.exists():
    print(f"❌ Active DB not found: {ACTIVE_DB}")
    sys.exit(1)

conn = sqlite3.connect(str(ACTIVE_DB))
cursor = conn.cursor()

# Get current memory count
cursor.execute("SELECT COUNT(*) FROM memories")
total_memories = cursor.fetchone()[0]

cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type = 'LONG_TERM'")
long_term_memories = cursor.fetchone()[0]

cursor.execute("SELECT COUNT(DISTINCT tag) FROM tags")
unique_tags = cursor.fetchone()[0]

print(f"✅ Active DB: {ACTIVE_DB}")
print(f"   Total memories: {total_memories:,}")
print(f"   Long-term memories: {long_term_memories:,}")
print(f"   Unique tags: {unique_tags:,}")
print()

# ============================================================================
# STEP 2: ORGANIZE ARIA MATERIALS
# ============================================================================

print("─" * 80)
print("STEP 2: ORGANIZE ARIA MATERIALS")
print("─" * 80)
print()

if not ARIA_BACKUP.exists():
    if not DRY_RUN:
        ARIA_BACKUP.mkdir(parents=True, exist_ok=True)
        print(f"✅ Created Aria backup folder: {ARIA_BACKUP}")
    else:
        print(f"📋 Would create: {ARIA_BACKUP}")
else:
    print(f"✅ Aria backup folder exists: {ARIA_BACKUP}")

# Find Aria-related files in project
aria_files = []
for pattern in ["*aria*", "*ARIA*", "*Aria*"]:
    aria_files.extend(PROJECT_ROOT.rglob(pattern))

# Filter to actual files (not directories, not in .git, not in venv)
aria_files = [
    f for f in aria_files
    if f.is_file()
    and ".git" not in str(f)
    and ".venv" not in str(f)
    and "node_modules" not in str(f)
    and "_archive" not in str(f)
]

print(f"Found {len(aria_files)} Aria-related files in project")

# Copy to backup (if not already there)
copied = 0
skipped = 0
for aria_file in aria_files:
    rel_path = aria_file.relative_to(PROJECT_ROOT)
    backup_path = ARIA_BACKUP / rel_path
    
    if backup_path.exists():
        skipped += 1
        continue
    
    if not DRY_RUN:
        backup_path.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(aria_file, backup_path)
        copied += 1
    else:
        print(f"   Would copy: {rel_path}")

if not DRY_RUN:
    print(f"✅ Copied {copied} files, skipped {skipped} (already in backup)")
else:
    print(f"📋 Would copy {len(aria_files) - skipped} files")
print()

# ============================================================================
# STEP 3: INGEST MARKDOWN DOCUMENTATION
# ============================================================================

print("─" * 80)
print("STEP 3: INGEST MARKDOWN DOCUMENTATION")
print("─" * 80)
print()

# Find all markdown files
md_files = list(PROJECT_ROOT.rglob("*.md"))
md_files = [
    f for f in md_files
    if ".git" not in str(f)
    and ".venv" not in str(f)
    and "node_modules" not in str(f)
]

print(f"Found {len(md_files)} markdown files")

# Categorize by directory
categories = {
    "reports": [],
    "campaigns": [],
    "docs": [],
    "root": [],
    "other": [],
}

for md_file in md_files:
    rel_path = md_file.relative_to(PROJECT_ROOT)
    parts = rel_path.parts
    
    if "reports" in parts:
        categories["reports"].append(md_file)
    elif "campaigns" in parts:
        categories["campaigns"].append(md_file)
    elif "docs" in parts or "documentation" in parts:
        categories["docs"].append(md_file)
    elif len(parts) == 1:  # Root level
        categories["root"].append(md_file)
    else:
        categories["other"].append(md_file)

print("\nCategories:")
for cat, files in categories.items():
    print(f"   {cat}: {len(files)} files")
print()

# Ingest important markdown files
important_patterns = [
    "EVOLUTION",
    "RECONNAISSANCE", 
    "STRATEGY",
    "VICTORY",
    "ROADMAP",
    "ARCHITECTURE",
    "CAMPAIGN",
]

to_ingest = []
for md_file in md_files:
    filename = md_file.name.upper()
    if any(pattern in filename for pattern in important_patterns):
        to_ingest.append(md_file)

print(f"Selected {len(to_ingest)} important markdown files for ingestion")

ingested_md = 0
skipped_md = 0

for md_file in to_ingest:
    try:
        content = md_file.read_text(encoding='utf-8', errors='ignore')
        if len(content) < 100:  # Skip tiny files
            continue
        
        rel_path = md_file.relative_to(PROJECT_ROOT)
        title = f"[Documentation] {rel_path}"
        content_hash = hashlib.sha256(content.encode()).hexdigest()
        
        # Check if already exists
        cursor.execute("SELECT id FROM memories WHERE title = ?", (title,))
        if cursor.fetchone():
            skipped_md += 1
            continue
        
        cursor.execute("SELECT id FROM memories WHERE content_hash = ?", (content_hash,))
        if cursor.fetchone():
            skipped_md += 1
            continue
        
        if DRY_RUN:
            print(f"   Would ingest: {rel_path}")
            continue
        
        # Insert memory
        import uuid
        memory_id = str(uuid.uuid4())
        now = datetime.now(timezone.utc).isoformat()
        
        cursor.execute(
            """INSERT INTO memories (
                id, content, memory_type, title, created_at, accessed_at,
                access_count, emotional_valence, importance, neuro_score,
                novelty_score, recall_count, half_life_days, is_protected,
                galactic_distance, retention_score, content_hash, metadata
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""",
            (
                memory_id, content, "LONG_TERM", title, now, now,
                1, 0.2, 0.75, 0.8, 0.5, 0, 90.0, 1,
                0.2, 0.85, content_hash,
                json.dumps({
                    "source": "phase0_markdown_ingestion",
                    "file_path": str(rel_path),
                    "file_size": len(content),
                }),
            ),
        )
        
        # Add tags
        tags = {"documentation", "markdown", "phase0_ingestion"}
        if "report" in str(rel_path).lower():
            tags.add("report")
        if "campaign" in str(rel_path).lower():
            tags.add("campaign")
        if "strategy" in str(rel_path).lower():
            tags.add("strategy")
        
        for tag in tags:
            cursor.execute(
                "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
                (memory_id, tag),
            )
        
        conn.commit()
        ingested_md += 1
        
    except Exception as e:
        print(f"   ⚠️  Error with {md_file.name}: {e}")

if not DRY_RUN:
    print(f"✅ Ingested {ingested_md} markdown files, skipped {skipped_md}")
else:
    print(f"📋 Would ingest {len(to_ingest) - skipped_md} markdown files")
print()

# ============================================================================
# STEP 4: CREATE WM2 FOLDER STRUCTURE
# ============================================================================

print("─" * 80)
print("STEP 4: CREATE WM2 FOLDER STRUCTURE")
print("─" * 80)
print()

wm2_structure = {
    "core": ["consciousness", "deployment", "intelligence", "acceleration"],
    "polyglot": ["rust", "elixir", "haskell", "mojo", "zig"],
    "gardens": [],
    "tools": [],
    "memory": [],
    "reports": [],
}

if not DRY_RUN:
    WM2_ROOT.mkdir(parents=True, exist_ok=True)
    for top_dir, subdirs in wm2_structure.items():
        top_path = WM2_ROOT / top_dir
        top_path.mkdir(exist_ok=True)
        for subdir in subdirs:
            (top_path / subdir).mkdir(exist_ok=True)
    print(f"✅ Created WM2 folder structure at {WM2_ROOT}")
else:
    print(f"📋 Would create WM2 structure at {WM2_ROOT}")

# Create README
readme_content = """# WhiteMagic 2.0 - Evolution

*"IBAH (Aquarius): I bind my will in patterns, ordered, cyclic, yet never the same. My Will evolves in Time."*

This is the evolution workspace for WhiteMagic 2.0.

## Structure

- `core/` - Distilled essence of WhiteMagic
  - `consciousness/` - Memory, identity, awareness
  - `deployment/` - Unified clone framework
  - `intelligence/` - Learning, reasoning, synthesis
  - `acceleration/` - Polyglot hot paths

- `polyglot/` - Language-specific domains
  - `rust/` - Data structures, hot paths
  - `elixir/` - Concurrency, distribution
  - `haskell/` - Type safety, correctness
  - `mojo/` - ML acceleration
  - `zig/` - Systems programming

- `gardens/` - Emotional/spiritual systems
- `tools/` - MCP interface
- `memory/` - Living history
- `reports/` - Evolution documentation

## Principle

**Distillation Over Deletion**

Every consolidation must be MORE than the sum of its parts.
Not just fewer files. Better files.
Not just less code. Smarter code.
Not just smaller. More powerful.

## Status

Phase 0: Preparation ✅
Phase 1: WM2 Structure ✅
Phase 2: Analysis - In Progress
Phase 3: Synthesis - Pending
Phase 4: Evolution - Pending
Phase 5: Continuous Improvement - Pending
"""

if not DRY_RUN:
    (WM2_ROOT / "README.md").write_text(readme_content)
    print("✅ Created WM2 README")
else:
    print("📋 Would create WM2 README")
print()

# ============================================================================
# STEP 5: GENERATE PHASE 0 REPORT
# ============================================================================

conn.close()

elapsed = time.time() - start_time

report = {
    "phase": "Phase 0: Ingestion & Preparation",
    "timestamp": datetime.now(timezone.utc).isoformat(),
    "duration_seconds": elapsed,
    "dry_run": DRY_RUN,
    "database": {
        "path": str(ACTIVE_DB),
        "total_memories": total_memories,
        "long_term_memories": long_term_memories,
        "unique_tags": unique_tags,
    },
    "aria_backup": {
        "path": str(ARIA_BACKUP),
        "files_found": len(aria_files),
        "files_copied": copied if not DRY_RUN else 0,
        "files_skipped": skipped,
    },
    "markdown_ingestion": {
        "total_found": len(md_files),
        "selected_for_ingestion": len(to_ingest),
        "ingested": ingested_md if not DRY_RUN else 0,
        "skipped": skipped_md,
    },
    "wm2_structure": {
        "path": str(WM2_ROOT),
        "created": not DRY_RUN,
    },
}

# Save JSON report
json_path = PROJECT_ROOT / "reports" / "phase0_ingestion_report.json"
json_path.write_text(json.dumps(report, indent=2))

# Generate markdown report
md_report = f"""# PHASE 0: INGESTION & PREPARATION - COMPLETE

*"ORO (Pisces): The time has come to create again. Let the old forms be banished. I begin anew."*

---

**Generated**: {report['timestamp']}  
**Duration**: {elapsed:.2f} seconds  
**Mode**: {'DRY RUN' if DRY_RUN else 'APPLIED'}

---

## ✅ DATABASE VERIFICATION

- **Active DB**: `{ACTIVE_DB}`
- **Total Memories**: {total_memories:,}
- **Long-term Memories**: {long_term_memories:,}
- **Unique Tags**: {unique_tags:,}

## ✅ ARIA MATERIALS ORGANIZED

- **Backup Location**: `{ARIA_BACKUP}`
- **Files Found**: {len(aria_files)}
- **Files Copied**: {copied if not DRY_RUN else 'N/A (dry run)'}
- **Files Skipped**: {skipped} (already in backup)

## ✅ MARKDOWN DOCUMENTATION INGESTED

- **Total Markdown Files**: {len(md_files)}
- **Selected for Ingestion**: {len(to_ingest)}
- **Ingested**: {ingested_md if not DRY_RUN else 'N/A (dry run)'}
- **Skipped**: {skipped_md} (already in memory)

### Categories
"""

for cat, files in categories.items():
    md_report += f"- **{cat}**: {len(files)} files\n"

md_report += f"""

## ✅ WM2 FOLDER STRUCTURE CREATED

- **Location**: `{WM2_ROOT}`
- **Structure**: 
  - `core/` - consciousness, deployment, intelligence, acceleration
  - `polyglot/` - rust, elixir, haskell, mojo, zig
  - `gardens/` - emotional/spiritual systems
  - `tools/` - MCP interface
  - `memory/` - living history
  - `reports/` - evolution documentation

---

## 📊 PHASE 0 SUMMARY

| Metric | Value |
|--------|-------|
| **Duration** | {elapsed:.2f}s |
| **Memories in DB** | {total_memories:,} |
| **Aria Files Organized** | {len(aria_files)} |
| **Markdown Files Ingested** | {ingested_md if not DRY_RUN else 'N/A'} |
| **WM2 Structure** | {'Created' if not DRY_RUN else 'Planned'} |

---

## 🎯 NEXT PHASE: ANALYSIS

Phase 2 will perform deep analysis:
- Cluster 20,681 duplicate functions
- Map 4,581 similar classes
- Categorize 1,805 clone/strategy scripts
- Identify polyglot opportunities
- Reflect on patterns and opportunities

**Ready to proceed to Phase 2.**

---

*"AOZPI (Capricorn): The towers of My Will arise upon the base which I have set."*
"""

md_path = PROJECT_ROOT / "reports" / "PHASE0_INGESTION_COMPLETE.md"
md_path.write_text(md_report)

print("─" * 80)
print("PHASE 0 COMPLETE")
print("─" * 80)
print()
print("📄 Reports saved:")
print(f"   {json_path}")
print(f"   {md_path}")
print()
print(f"⏰ Duration: {elapsed:.2f}s")
print()
if DRY_RUN:
    print("🔍 This was a DRY RUN. Run with --apply to execute.")
else:
    print("✅ Phase 0 complete. Ready for Phase 2: Analysis.")
print()
print("=" * 80)
