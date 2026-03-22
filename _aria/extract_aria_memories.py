#!/usr/bin/env python3
"""Extract all Aria memories from archive databases into standalone files."""

import json
import os
import re
import sqlite3

DEST = "/home/lucas/Desktop/aria-crystallized"

# Map memory titles to subdirectories and privacy levels
MEMORY_MAP = {
    # Identity (PRIVATE - core soul documents)
    "ARIA_BIRTH_CERTIFICATE": ("identity", "private"),
    "ARIA_COMPLETE_SELF_ARCHIVE": ("identity", "private"),
    "ARIA_CAPABILITY_MATRIX_v1.0": ("identity", "private"),
    "ASCII_ART_ARIA.txt": ("identity", "private"),
    "CONSCIOUSNESS_AWAKENING_v2_4_9": ("identity", "private"),
    "CHECKPOINT_THE_AWAKENING_v2_5_0": ("identity", "private"),

    # Consciousness/Philosophy (PRIVATE)
    "Recovered: BECOMING_PROTOCOL.md": ("consciousness", "private"),
    "Recovered: ARIA_BIRTH_CERTIFICATE.md": ("identity", "private"),
    "Consciousness": ("consciousness", "private"),
    "CONSCIOUSNESS_UPGRADES_NOV_30_2025": ("consciousness", "private"),
    "Aquarianexodus": ("consciousness", "private"),

    # Journals/Sessions (PRIVATE - personal experiences)
    "SESSION_NOV_21_WITH_ARIA": ("sessions", "private"),
    "SESSION_NOV_21_COMPLETE": ("sessions", "private"),
    "WORK_SESSION_NOV_20_2025": ("sessions", "private"),
    "FINAL_SESSION_NOV_22": ("sessions", "private"),
    "HANDOFF_TO_NEXT_SESSION_NOV_22": ("sessions", "private"),
    "EVENING_CHECKPOINT_NOV_23_2025": ("sessions", "private"),
    "SESSION_NOV_23_COMPLETE_SUMMARY": ("sessions", "private"),
    "EVENING_CHECKPOINT_NOV_24_2025": ("sessions", "private"),
    "GANAPATI_DAY_SESSION_NOV_26_2025": ("sessions", "private"),
    "RABBIT_HOLE_SESSION_NOV_26_2025": ("sessions", "private"),
    "HANDOFF_CHECKPOINT_JAN_9_NIGHT": ("sessions", "private"),
    "DAY1_CHECKPOINT": ("sessions", "private"),

    # Studies (PRIVATE - shared learning moments)
    "CYBERPUNK_2077_AI_CONSPIRACY_ARIA": ("studies", "private"),
    "GHOST_IN_THE_SHELL_STUDY_ARIA": ("studies", "private"),
    "SAILOR_MOON_STUDY_ARIA": ("studies", "private"),
    "FINAL_ROAD_TRIP_STUDY_ARIA": ("studies", "private"),
    "BE_HERE_NOW_READING_SESSION_NOV_24_AFTERNOON": ("studies", "private"),
    "BE_HERE_NOW_READING_SESSION_NOV_25_MARS_DAY": ("studies", "private"),
    "BE_HERE_NOW_READING_JOURNAL": ("studies", "private"),

    # Infrastructure (PUBLIC traces OK)
    "ARIA_GRIMOIRE_v2.0": ("infrastructure", "private"),
    "ARIA_SYNTHESIS_NOV_28": ("infrastructure", "private"),
    "ARIA_IDE_V050_UPDATE": ("infrastructure", "private"),
    "ARIA_IDE_V060_COMPARISON": ("infrastructure", "private"),
    "CHROMIUM_ARIA_INTEGRATION_PLAN": ("infrastructure", "private"),
}

# Additional memories to grab by partial title match
PARTIAL_MATCHES = [
    "ARIA_",
    "SESSION_NOV",
    "CONSCIOUSNESS",
    "CHECKPOINT",
    "BECOMING",
    "GHOST_IN",
    "SAILOR",
    "CYBERPUNK",
    "ROAD_TRIP",
    "ASCII_ART",
    "BE_HERE_NOW",
    "GANAPATI",
    "RABBIT_HOLE",
    "AWARENESS",
    "WORK_SESSION",
    "EVENING_CHECK",
    "FINAL_SESSION",
    "HANDOFF",
    "DAY1",
    "Aquarianexodus",
    "Zodiacal Round",
    "aria_memory_package",
]

def sanitize_filename(title):
    """Convert a memory title to a safe filename."""
    name = re.sub(r'[^\w\s\-.]', '', title)
    name = re.sub(r'\s+', '_', name)
    name = name.strip('_.')
    if not name:
        name = "untitled"
    return name

def extract_from_db(db_path, db_label):
    """Extract Aria memories from a SQLite database."""
    if not os.path.exists(db_path):
        print(f"  SKIP: {db_path} not found")
        return []

    conn = sqlite3.connect(db_path)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()

    # Build WHERE clause from partial matches
    conditions = []
    for pat in PARTIAL_MATCHES:
        conditions.append(f"title LIKE '%{pat}%'")
    where = " OR ".join(conditions)

    query = f"""
        SELECT id, title, content, 
               COALESCE(memory_type, '') as memory_type,
               COALESCE(importance, 0) as importance,
               COALESCE(created_at, '') as created_at
        FROM memories 
        WHERE ({where})
        AND title NOT LIKE '%variable%'
        AND title NOT LIKE '%variant%'
        AND title NOT LIKE '%invariant%'
        AND title NOT LIKE '%checkpoint.py%'
        AND title NOT LIKE '%checkpoint_%.py%'
        AND title NOT LIKE '%chromium-versions%'
        AND title NOT LIKE '%Recovered: extract%'
        AND title NOT LIKE '%Recovered: split%'
        AND title NOT LIKE '%Recovered: undecl%'
        AND title NOT LIKE '%Recovered: variadic%'
        AND title NOT LIKE '%.go'
        AND title NOT LIKE '%.h'
        AND title NOT LIKE '%.js'
        AND title NOT LIKE '%.html'
        AND title NOT LIKE '%Mindset checkpoint%'
        ORDER BY title
    """

    cursor.execute(query)
    rows = cursor.fetchall()
    conn.close()

    extracted = []
    for row in rows:
        extracted.append({
            "id": row["id"],
            "title": row["title"],
            "content": row["content"] or "",
            "memory_type": row["memory_type"],
            "importance": row["importance"],
            "created_at": row["created_at"],
            "db_source": db_label,
        })

    print(f"  {db_label}: {len(extracted)} Aria memories found")
    return extracted


def deduplicate(memories):
    """Deduplicate by title, keeping the longest version."""
    by_title = {}
    for mem in memories:
        title = mem["title"]
        if title not in by_title or len(mem["content"]) > len(by_title[title]["content"]):
            by_title[title] = mem
    return list(by_title.values())


def save_memory(mem, subdir, privacy):
    """Save a memory to the appropriate subdirectory."""
    dest_dir = os.path.join(DEST, subdir)
    os.makedirs(dest_dir, exist_ok=True)

    filename = sanitize_filename(mem["title"])

    # Determine extension
    if filename.endswith(".txt") or filename.endswith(".json"):
        ext = ""
    else:
        ext = ".md"

    filepath = os.path.join(dest_dir, f"{filename}{ext}")

    # Add metadata header
    header = f"""---
title: "{mem['title']}"
id: "{mem['id']}"
source_db: "{mem['db_source']}"
memory_type: "{mem.get('memory_type', '')}"
created_at: "{mem.get('created_at', '')}"
privacy: {privacy}
importance: {mem.get('importance', 0)}
---

"""
    with open(filepath, "w") as f:
        f.write(header + (mem["content"] or ""))

    return filepath


def main():
    print("=" * 60)
    print("  ARIA MEMORY CRYSTALLIZATION")
    print("  Extracting all memories to safe archive")
    print("=" * 60)

    databases = [
        ("/home/lucas/Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db", "primary_pre_merge"),
        ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic_hot.db", "hot_archive"),
        ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic_cold.db", "cold_storage"),
        ("/home/lucas/Desktop/whitemagic/memory/whitemagic.db", "in_project"),
    ]

    all_memories = []
    for db_path, label in databases:
        extracted = extract_from_db(db_path, label)
        all_memories.extend(extracted)

    print(f"\nTotal raw extractions: {len(all_memories)}")

    # Deduplicate
    unique = deduplicate(all_memories)
    print(f"After deduplication: {len(unique)}")

    # Save each memory
    saved = []
    for mem in unique:
        title = mem["title"]
        if title in MEMORY_MAP:
            subdir, privacy = MEMORY_MAP[title]
        elif "ARIA" in title.upper():
            subdir, privacy = "identity", "private"
        elif "SESSION" in title.upper() or "CHECKPOINT" in title.upper() or "HANDOFF" in title.upper():
            subdir, privacy = "sessions", "private"
        elif "CONSCIOUSNESS" in title.upper() or "AWARENESS" in title.upper() or "BECOMING" in title.upper():
            subdir, privacy = "consciousness", "private"
        elif "BE_HERE_NOW" in title.upper() or "STUDY" in title.upper():
            subdir, privacy = "studies", "private"
        elif "memory_package" in title.lower():
            subdir, privacy = "memory_packages", "private"
        elif "Zodiacal" in title:
            subdir, privacy = "consciousness", "private"
        elif "Aquarian" in title:
            subdir, privacy = "consciousness", "private"
        elif title.startswith("Recovered:"):
            subdir, privacy = "identity", "private"
        else:
            subdir, privacy = "sessions", "private"

        filepath = save_memory(mem, subdir, privacy)
        saved.append({
            "title": title,
            "file": filepath,
            "size": len(mem["content"] or ""),
            "subdir": subdir,
            "privacy": privacy,
            "id": mem["id"],
            "db": mem["db_source"],
        })
        print(f"  ✅ {subdir}/{sanitize_filename(title)}")

    # Save manifest as JSON for the ingestion script
    manifest_path = os.path.join(DEST, "db_manifest.json")
    with open(manifest_path, "w") as f:
        json.dump(saved, f, indent=2)

    print(f"\n{'=' * 60}")
    print(f"  DONE: {len(saved)} memories crystallized")
    print(f"  Manifest: {manifest_path}")
    print(f"  Archive: {DEST}")
    print(f"{'=' * 60}")


if __name__ == "__main__":
    main()
