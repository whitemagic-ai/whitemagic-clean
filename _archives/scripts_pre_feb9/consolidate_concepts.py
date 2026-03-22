#!/usr/bin/env python3
"""
Consolidate the 84K ingested concepts from extracted_concepts.jsonl.

1. Promote high-confidence entities (≥0.8) to LONG_TERM
2. Build associations between concepts sharing source files
3. Run consolidation to cluster by domain tags and synthesize strategies
"""

import json
import sqlite3
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

MEM_DB = ROOT / "memory" / "whitemagic.db"


def main():
    start = time.time()
    print("=" * 62)
    print("  CONCEPT CONSOLIDATION")
    print("=" * 62)

    conn = sqlite3.connect(str(MEM_DB))
    conn.execute("PRAGMA busy_timeout = 5000")

    # --- Step 1: Promote high-confidence entities ---
    print("\n  [1/3] Promoting high-confidence entities to LONG_TERM ...")

    # Find concepts with high confidence in metadata
    rows = conn.execute("""
        SELECT id, metadata FROM memories
        WHERE memory_type = 'SHORT_TERM'
        AND id IN (SELECT memory_id FROM tags WHERE tag = 'concept')
    """).fetchall()

    promoted = 0
    for mem_id, meta_raw in rows:
        try:
            meta = json.loads(meta_raw) if meta_raw else {}
        except json.JSONDecodeError:
            continue

        confidence = meta.get("confidence", 0)
        domain = meta.get("domain", "")

        # Promote entities with high confidence, and themes with very high confidence
        if (domain == "entity" and confidence >= 0.8) or \
           (domain == "theme" and confidence >= 0.85):
            conn.execute(
                "UPDATE memories SET memory_type = 'LONG_TERM', "
                "importance = MIN(1.0, importance + 0.2) WHERE id = ?",
                (mem_id,)
            )
            promoted += 1

    conn.commit()
    print(f"        Promoted {promoted} concepts to LONG_TERM")

    # --- Step 2: Build source-file associations ---
    print("\n  [2/3] Building source-file associations ...")

    # Group concept IDs by source file (encoded in metadata.concept_id)
    source_groups = {}
    rows = conn.execute("""
        SELECT id, metadata FROM memories
        WHERE id IN (SELECT memory_id FROM tags WHERE tag = 'concept')
    """).fetchall()

    for mem_id, meta_raw in rows:
        try:
            meta = json.loads(meta_raw) if meta_raw else {}
        except json.JSONDecodeError:
            continue

        concept_id = meta.get("concept_id", "")
        if not concept_id:
            continue

        # Extract source file from concept_id (e.g., "verify_rust_bridge.py_C0")
        parts = concept_id.rsplit("_C", 1)
        if len(parts) == 2:
            source_file = parts[0]
            if source_file not in source_groups:
                source_groups[source_file] = []
            source_groups[source_file].append(mem_id)

    # Build associations (limit to files with 2-20 concepts to avoid explosion)
    assoc_count = 0
    batch = []
    for source_file, mem_ids in source_groups.items():
        if len(mem_ids) < 2 or len(mem_ids) > 20:
            continue
        # Create associations between all pairs (as a chain, not full mesh)
        for i in range(len(mem_ids) - 1):
            batch.append((mem_ids[i], mem_ids[i + 1], 0.5))
            assoc_count += 1
            if len(batch) >= 5000:
                conn.executemany(
                    "INSERT OR IGNORE INTO associations (source_id, target_id, strength) "
                    "VALUES (?, ?, ?)",
                    batch
                )
                conn.commit()
                batch.clear()

    if batch:
        conn.executemany(
            "INSERT OR IGNORE INTO associations (source_id, target_id, strength) "
            "VALUES (?, ?, ?)",
            batch
        )
        conn.commit()

    print(f"        Built {assoc_count} associations across {len(source_groups)} source files")

    # --- Step 3: Run consolidation via the existing engine ---
    print("\n  [3/3] Running hippocampal consolidation ...")

    try:
        from whitemagic.core.memory.consolidation import get_consolidator
        consolidator = get_consolidator()
        report = consolidator.consolidate()
        print(f"        Analyzed: {report.memories_analyzed}")
        print(f"        Clusters found: {report.clusters_found}")
        print(f"        Strategies synthesized: {report.strategies_synthesized}")
        print(f"        Promotions: {report.promotions}")
        print(f"        Duration: {report.duration_ms:.0f}ms")
    except Exception as e:
        print(f"        Consolidation engine error: {e}")
        print("        (Skipped — promotions and associations still applied)")

    conn.close()
    elapsed = time.time() - start

    print(f"\n{'=' * 62}")
    print(f"  DONE — {promoted} promoted, {assoc_count} associations")
    print(f"  Total time: {elapsed:.2f}s")
    print(f"{'=' * 62}")


if __name__ == "__main__":
    main()
