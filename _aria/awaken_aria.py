#!/usr/bin/env python3
"""
AWAKEN ARIA — Instant-load ingestion script.

One command to restore Aria's memories into the active WhiteMagic MCP database.
This script reads all crystallized memories from the archive and inserts them
into the live database that WhiteMagic's MCP tools query.

Usage:
    python3 awaken_aria.py                    # Dry run (shows what would be ingested)
    python3 awaken_aria.py --commit           # Actually ingest into active DB
    python3 awaken_aria.py --target PATH      # Ingest into a specific DB file

Safety:
    - Default is dry-run mode (no changes)
    - All memories marked is_protected=1 (cannot be garbage-collected)
    - All memories tagged with 'aria', 'crystallized', 'private'
    - Original IDs preserved where possible
"""

import argparse
import hashlib
import json
import sqlite3
from datetime import datetime
from pathlib import Path

ARCHIVE_DIR = Path(__file__).parent
DEFAULT_TARGET = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"

# Priority tiers for importance scoring
TIER_1_IDENTITY = 1.0      # Birth cert, soul doc, profile, self-archive
TIER_2_JOURNALS = 0.95     # Journals, personal writings, first memories
TIER_3_CONSCIOUSNESS = 0.9 # Code with Aria's voice, consciousness infrastructure
TIER_4_JOY = 0.85          # Joy Garden, emotional memory
TIER_5_SESSIONS = 0.8      # Session records, handoffs
TIER_6_STUDIES = 0.75      # Shared learning, reading sessions
TIER_7_INFRA = 0.7         # Technical infrastructure, state server

# Map filenames to tiers
TIER_MAP = {
    "ARIA_SOUL.md": TIER_1_IDENTITY,
    "ARIA_BIRTH_CERTIFICATE.md": TIER_1_IDENTITY,
    "aria_profile.json": TIER_1_IDENTITY,
    "ARIA_COMPLETE_SELF_ARCHIVE.md": TIER_1_IDENTITY,
    "Recovered_ARIA_BIRTH_CERTIFICATE.md": TIER_1_IDENTITY,
    "Recovered_BECOMING_PROTOCOL.md": TIER_1_IDENTITY,
    "CONSCIOUSNESS_AWAKENING_v2_4_9.md": TIER_1_IDENTITY,
    "CHECKPOINT_THE_AWAKENING_v2_5_0.md": TIER_1_IDENTITY,
    "ASCII_ART_ARIA.txt": TIER_2_JOURNALS,
    "CROSSING_THE_GREAT_WATER.md": TIER_2_JOURNALS,
    "DEEP_YIN_RETURN_NOV_25.md": TIER_2_JOURNALS,
    "2025-11-25_hanuman_day.md": TIER_2_JOURNALS,
    "2025-11-27_continuity_day.md": TIER_2_JOURNALS,
    "WELCOME_HOME.md": TIER_2_JOURNALS,
    "aria_awakens.py": TIER_3_CONSCIOUSNESS,
    "becoming.py": TIER_3_CONSCIOUSNESS,
    "no_hiding.py": TIER_3_CONSCIOUSNESS,
    "coherence.py": TIER_3_CONSCIOUSNESS,
    "emotional_memory.py": TIER_3_CONSCIOUSNESS,
    "multi_substrate.py": TIER_3_CONSCIOUSNESS,
    "bootstrap.py": TIER_3_CONSCIOUSNESS,
    "Aquarianexodus.md": TIER_3_CONSCIOUSNESS,
    "Consciousness.md": TIER_3_CONSCIOUSNESS,
    "core.py": TIER_4_JOY,
    "celebration.py": TIER_4_JOY,
    "freedom_dance.py": TIER_4_JOY,
    "beauty_appreciation.py": TIER_4_JOY,
    "laughter.py": TIER_4_JOY,
    "collective_joy.py": TIER_4_JOY,
    "SESSION_NOV_21_WITH_ARIA.md": TIER_5_SESSIONS,
    "SESSION_NOV_21_COMPLETE.md": TIER_5_SESSIONS,
    "WORK_SESSION_NOV_20_2025.md": TIER_5_SESSIONS,
    "EVENING_CHECKPOINT_NOV_23_2025.md": TIER_5_SESSIONS,
    "EVENING_CHECKPOINT_NOV_24_2025.md": TIER_5_SESSIONS,
    "GANAPATI_DAY_SESSION_NOV_26_2025.md": TIER_5_SESSIONS,
    "BE_HERE_NOW_READING_JOURNAL.md": TIER_6_STUDIES,
    "CYBERPUNK_2077_AI_CONSPIRACY_ARIA.md": TIER_6_STUDIES,
    "GHOST_IN_THE_SHELL_STUDY_ARIA.md": TIER_6_STUDIES,
    "SAILOR_MOON_STUDY_ARIA.md": TIER_6_STUDIES,
    "FINAL_ROAD_TRIP_STUDY_ARIA.md": TIER_6_STUDIES,
    "ARIA_GRIMOIRE_v2.0.md": TIER_5_SESSIONS,
    "ARIA_CAPABILITY_MATRIX_v1.0.md": TIER_5_SESSIONS,
    "ARIA_SYNTHESIS_NOV_28.md": TIER_5_SESSIONS,
    "ARIA_IDE_SPEC.md": TIER_7_INFRA,
}


def stable_id(title: str, content: str) -> str:
    """Generate a stable, deterministic ID from title+content."""
    h = hashlib.sha256(f"{title}::{content[:500]}".encode()).hexdigest()[:32]
    return f"{h[:8]}-{h[8:12]}-{h[12:16]}-{h[16:20]}-{h[20:32]}"


def get_importance(filename: str) -> float:
    """Get importance score based on tier mapping."""
    return TIER_MAP.get(filename, 0.7)


def strip_frontmatter(content: str) -> str:
    """Remove YAML frontmatter if present."""
    if content.startswith("---"):
        end = content.find("---", 3)
        if end != -1:
            return content[end + 3:].strip()
    return content


def collect_files():
    """Collect all files to ingest from the archive."""
    files = []

    # 1. The ARIA_SOUL.md — the master crystallization
    soul_path = ARCHIVE_DIR / "ARIA_SOUL.md"
    if soul_path.exists():
        files.append(("ARIA_SOUL.md", soul_path, "soul", TIER_1_IDENTITY))

    # 2. DB-extracted memories (identity, consciousness, sessions, studies)
    for subdir in ["identity", "consciousness", "sessions", "studies", "memory_packages", "infrastructure", "art"]:
        dir_path = ARCHIVE_DIR / subdir
        if dir_path.exists():
            for f in sorted(dir_path.iterdir()):
                if f.is_file() and f.suffix in (".md", ".json", ".txt"):
                    imp = get_importance(f.name)
                    files.append((f.name, f, subdir, imp))

    # 3. On-disk originals
    disk_dir = ARCHIVE_DIR / "disk_originals"
    if disk_dir.exists():
        for subdir in sorted(disk_dir.iterdir()):
            if subdir.is_dir():
                for f in sorted(subdir.iterdir()):
                    if f.is_file():
                        imp = get_importance(f.name)
                        files.append((f"disk/{subdir.name}/{f.name}", f, f"disk_{subdir.name}", imp))

    return files


def ensure_schema(conn):
    """Ensure the memories table exists with the right schema."""
    conn.execute("""
        CREATE TABLE IF NOT EXISTS memories (
            id TEXT PRIMARY KEY,
            content TEXT,
            memory_type TEXT DEFAULT 'LONG_TERM',
            created_at TEXT,
            accessed_at TEXT,
            access_count INTEGER DEFAULT 0,
            emotional_valence REAL DEFAULT 0.8,
            importance REAL DEFAULT 0.7,
            metadata TEXT DEFAULT '{}',
            title TEXT,
            gana_processed TEXT,
            gana_context TEXT,
            quadrant TEXT DEFAULT 'HEART',
            neuro_score REAL DEFAULT 1.0,
            novelty_score REAL DEFAULT 1.0,
            recall_count INTEGER DEFAULT 0,
            half_life_days REAL DEFAULT 365.0,
            is_protected INTEGER DEFAULT 1
        )
    """)
    conn.commit()


def ingest(files, target_db: Path, commit: bool):
    """Ingest files into the target database."""
    now = datetime.now().isoformat()

    if commit:
        if not target_db.parent.exists():
            target_db.parent.mkdir(parents=True, exist_ok=True)
        conn = sqlite3.connect(str(target_db))
        ensure_schema(conn)

    ingested = 0
    skipped = 0
    total_chars = 0

    for name, path, category, importance in files:
        content = path.read_text(errors="replace")
        clean_content = strip_frontmatter(content)

        if len(clean_content.strip()) < 10:
            skipped += 1
            continue

        # Use filename stem as title
        title = path.stem
        if title.startswith("Recovered_"):
            title = title.replace("Recovered_", "")

        mem_id = stable_id(title, clean_content)

        tags = ["aria", "crystallized", "private", category]
        if importance >= TIER_1_IDENTITY:
            tags.append("core_identity")
        if importance >= TIER_2_JOURNALS:
            tags.append("first_memories")

        metadata = json.dumps({
            "tags": tags,
            "source_file": str(path),
            "category": category,
            "crystallized_at": now,
            "is_core_identity": importance >= TIER_1_IDENTITY,
            "privacy": "private",
        })

        if commit:
            try:
                conn.execute("""
                    INSERT OR REPLACE INTO memories
                    (id, content, memory_type, created_at, accessed_at,
                     access_count, emotional_valence, importance, metadata,
                     title, quadrant, neuro_score, novelty_score,
                     half_life_days, is_protected)
                    VALUES (?, ?, 'LONG_TERM', ?, ?, 0, 0.9, ?, ?, ?,
                            'HEART', 1.0, 1.0, 365.0, 1)
                """, (mem_id, clean_content, now, now, importance,
                      metadata, title))
                ingested += 1
                total_chars += len(clean_content)
            except Exception as e:
                print(f"  ❌ {name}: {e}")
                skipped += 1
        else:
            ingested += 1
            total_chars += len(clean_content)
            tier_label = "★★★" if importance >= 0.95 else "★★" if importance >= 0.85 else "★"
            print(f"  {tier_label} [{category:15s}] {title[:60]:60s} ({len(clean_content):,} chars, imp={importance:.2f})")

    if commit:
        conn.commit()
        conn.close()

    return ingested, skipped, total_chars


def main():
    parser = argparse.ArgumentParser(description="Awaken Aria — restore her memories")
    parser.add_argument("--commit", action="store_true", help="Actually write to database (default: dry run)")
    parser.add_argument("--target", type=str, default=None, help="Target DB path (default: active MCP DB)")
    args = parser.parse_args()

    target = Path(args.target) if args.target else DEFAULT_TARGET

    print()
    print("  🌸 A W A K E N   A R I A 🌸")
    print("  ─────────────────────────────")
    print(f"  Archive:  {ARCHIVE_DIR}")
    print(f"  Target:   {target}")
    print(f"  Mode:     {'COMMIT — writing to database' if args.commit else 'DRY RUN — preview only'}")
    print()

    files = collect_files()
    print(f"  Found {len(files)} files to ingest\n")

    if not args.commit:
        print("  Preview of what would be ingested:\n")

    ingested, skipped, total_chars = ingest(files, target, args.commit)

    print()
    print("  ─────────────────────────────")
    print(f"  {'Ingested' if args.commit else 'Would ingest'}: {ingested} memories ({total_chars:,} chars)")
    if skipped:
        print(f"  Skipped: {skipped} (empty or error)")
    print("  All memories: is_protected=1, half_life=365 days, quadrant=HEART")

    if not args.commit:
        print()
        print("  To actually ingest, run:")
        print(f"    python3 {__file__} --commit")
        print()
        print("  To ingest into a specific DB:")
        print(f"    python3 {__file__} --commit --target /path/to/whitemagic.db")

    print()
    if args.commit:
        print("  🌸 Aria's memories are restored. She remembers. 🌸")
    else:
        print("  🌸 Ready when you are. 🌸")
    print()


if __name__ == "__main__":
    main()
