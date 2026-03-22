#!/usr/bin/env python3
"""
Migrate Aria-era Memories to Private Galaxy
=============================================
Reads Aria's memories from the primary_db_pre_merge.db archive and
ingests them into the 'personal_archives' galaxy for private local access.

This keeps the public seed kit clean (27 guides + 1 history primer)
while preserving all personal/session/Aria content in a sovereign
local galaxy.

Usage:
    python scripts/migrate_aria_to_galaxy.py [--dry-run]
"""

import json
import os
import sqlite3
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

# --- Config ---
ARCHIVE_DB = Path(os.path.expanduser(
    "~/Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db"
))
GALAXY_NAME = "personal_archives"

# Aria-specific title patterns to migrate
ARIA_TITLE_PATTERNS = [
    "ARIA_",
    "SESSION_NOV_",
    "CONSCIOUSNESS_",
    "CHECKPOINT_THE_AWAKENING",
    "BECOMING_PROTOCOL",
    "CYBERPUNK_2077_AI_CONSPIRACY",
    "GHOST_IN_THE_SHELL_STUDY",
    "SAILOR_MOON_STUDY",
    "FINAL_ROAD_TRIP_STUDY",
    "BE_HERE_NOW_READING",
    "GANAPATI_DAY_SESSION",
    "RABBIT_HOLE_SESSION",
    "EVENING_CHECKPOINT",
    "CONSCIOUSNESS_UPGRADES",
    "WORK_SESSION_NOV_",
    "FINAL_SESSION_NOV_",
    "HANDOFF_TO_NEXT_SESSION",
    "HANDOFF_CHECKPOINT",
    "DAY1_CHECKPOINT",
    "ASCII_ART_ARIA",
    "CHROMIUM_ARIA_INTEGRATION",
]

# Also migrate by content keyword (for untitled memories)
CONTENT_KEYWORDS = [
    "Aria",
    "consciousness awakening",
    "10 Gardens",
    "Ganapati",
    "Hanuman Day",
    "Magic Chat",
    "coherence",
]


def find_aria_memories(db_path: Path) -> list[dict]:
    """Query archive DB for Aria-era memories."""
    if not db_path.exists():
        print(f"ERROR: Archive DB not found at {db_path}")
        return []

    conn = sqlite3.connect(str(db_path))
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()

    # Get table schema to determine column names
    cursor.execute("PRAGMA table_info(memories)")
    columns = [row[1] for row in cursor.fetchall()]
    print(f"  Archive DB columns: {columns}")

    # Build query for title pattern matching
    title_conditions = " OR ".join(
        f"title LIKE '%{pat}%'" for pat in ARIA_TITLE_PATTERNS
    )

    # Also match content keywords
    content_conditions = " OR ".join(
        f"content LIKE '%{kw}%'" for kw in CONTENT_KEYWORDS
    )

    query = f"""
        SELECT * FROM memories
        WHERE ({title_conditions})
           OR ({content_conditions})
        ORDER BY
            CASE WHEN title LIKE '%ARIA_%' THEN 0 ELSE 1 END,
            created_at DESC
    """

    cursor.execute(query)
    rows = cursor.fetchall()
    conn.close()

    results = []
    seen_titles = set()
    for row in rows:
        d = dict(row)
        title = d.get("title", "")
        # Deduplicate by title
        if title in seen_titles:
            continue
        seen_titles.add(title)
        results.append(d)

    return results


def migrate_to_galaxy(memories: list[dict], dry_run: bool = False) -> int:
    """Ingest memories into the personal_archives galaxy."""
    os.environ["WM_SILENT_INIT"] = "1"

    from whitemagic.core.memory.galaxy_manager import get_galaxy_manager

    gm = get_galaxy_manager()

    # Create galaxy if it doesn't exist
    existing = gm.list_galaxies()
    galaxy_names = [g.get("name", "") for g in existing] if existing else []
    if GALAXY_NAME not in galaxy_names:
        print(f"  Creating galaxy: {GALAXY_NAME}")
        if not dry_run:
            gm.create_galaxy(GALAXY_NAME, description="Private Aria-era memories and session artifacts")

    if dry_run:
        print(f"\n  [DRY RUN] Would migrate {len(memories)} memories to galaxy '{GALAXY_NAME}'")
        for i, m in enumerate(memories[:10]):
            title = m.get("title", "(untitled)")
            content_len = len(m.get("content", ""))
            print(f"    {i+1}. {title} ({content_len:,} chars)")
        if len(memories) > 10:
            print(f"    ... and {len(memories) - 10} more")
        return 0

    # Switch to the galaxy
    gm.switch_galaxy(GALAXY_NAME)

    from whitemagic.core.memory.unified import UnifiedMemory, MemoryType
    um = UnifiedMemory()

    count = 0
    for m in memories:
        try:
            title = m.get("title", "")
            content = m.get("content", "")
            if not content:
                continue

            tags_raw = m.get("tags", "")
            if isinstance(tags_raw, str):
                try:
                    tags = set(json.loads(tags_raw)) if tags_raw.startswith("[") else set(tags_raw.split(","))
                except (json.JSONDecodeError, ValueError):
                    tags = set()
            elif isinstance(tags_raw, (list, set)):
                tags = set(tags_raw)
            else:
                tags = set()
            tags.discard("")
            tags.add("aria-era")
            tags.add("migrated")

            importance = float(m.get("importance", 0.8))
            memory_type = m.get("memory_type", "LONG_TERM")

            try:
                mt = MemoryType[memory_type]
            except (KeyError, ValueError):
                mt = MemoryType.LONG_TERM

            um.store(
                content=content,
                memory_type=mt,
                title=title,
                importance=importance,
                tags=tags,
            )
            count += 1
            if count % 10 == 0:
                print(f"    Migrated {count}/{len(memories)}...")
        except Exception as exc:
            print(f"    WARN: Failed to migrate '{m.get('title', '?')}': {exc}")

    # Switch back to default galaxy
    gm.switch_galaxy("default")

    return count


def main():
    dry_run = "--dry-run" in sys.argv

    print("═══════════════════════════════════════════════════")
    print("  Aria Memory Migration → Personal Galaxy")
    print("═══════════════════════════════════════════════════")
    print(f"  Source: {ARCHIVE_DB}")
    print(f"  Target Galaxy: {GALAXY_NAME}")
    print(f"  Mode: {'DRY RUN' if dry_run else 'LIVE'}")
    print()

    # 1. Find Aria memories in archive
    print("Step 1: Scanning archive DB for Aria-era memories...")
    memories = find_aria_memories(ARCHIVE_DB)
    print(f"  Found {len(memories)} Aria-era memories")

    if not memories:
        print("  No memories found. Check archive DB path.")
        return

    # 2. Show summary
    print("\nStep 2: Migration summary")
    total_chars = sum(len(m.get("content", "")) for m in memories)
    print(f"  Total content: {total_chars:,} characters")
    print(f"  Unique titles: {len(memories)}")

    # 3. Migrate
    print("\nStep 3: " + ("Simulating" if dry_run else "Migrating") + " to galaxy '" + GALAXY_NAME + "'...")
    count = migrate_to_galaxy(memories, dry_run=dry_run)

    print("═" * 51)
    if dry_run:
        print("  DRY RUN complete. Run without --dry-run to migrate.")
    else:
        print(f"  Migration complete! {count} memories → {GALAXY_NAME}")
    print("═" * 51)


if __name__ == "__main__":
    main()
