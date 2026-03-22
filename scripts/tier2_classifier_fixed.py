#!/usr/bin/env python3
"""Tier 2 Semantic Similarity Classifier for remaining untyped associations."""

import os
import sqlite3
import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

def get_embedding_engine():
    try:
        from whitemagic.core.memory.embeddings import get_embedding_engine
        return get_embedding_engine()
    except Exception as e:
        print(f"Failed to load embedding engine: {e}")
        return None

def classify_association(memory_a_content: str, memory_b_content: str, embedder) -> str | None:
    if not embedder or not memory_a_content or not memory_b_content:
        return None

    try:
        emb_a = embedder.encode(memory_a_content)
        emb_b = embedder.encode(memory_b_content)

        import numpy as np
        dot = np.dot(emb_a, emb_b)
        norm_a = np.linalg.norm(emb_a)
        norm_b = np.linalg.norm(emb_b)

        if norm_a == 0 or norm_b == 0:
            return None

        similarity = dot / (norm_a * norm_b)

        if similarity > 0.85:
            return 'SIMILAR_TO'
        elif similarity > 0.70:
            return 'RELATED_TO'
        elif similarity > 0.55:
            return 'CONTEXTUAL_MATCH'
        elif similarity > 0.40:
            return 'TOPICALLY_RELATED'
        else:
            return 'ASSOCIATED_WITH'

    except Exception as e:
        print(f"Classification error: {e}")
        return None

def process_untyped_associations(db_path: str, dry_run: bool = True, limit: int = 100):
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()

    cursor.execute("SELECT COUNT(*) FROM associations WHERE relation_type = 'associated_with' OR relation_type IS NULL")
    total_untyped = cursor.fetchone()[0]
    print(f"Total untyped associations: {total_untyped}")

    if total_untyped == 0:
        print("No untyped associations to process!")
        conn.close()
        return

    embedder = get_embedding_engine()
    if not embedder:
        print("ERROR: Could not load embedding engine")
        conn.close()
        return

    print("Embedding engine loaded")

    # Use composite key (source_id, target_id) for associations table
    cursor.execute("""
        SELECT a.source_id, a.target_id,
               m1.content as source_content, m2.content as target_content
        FROM associations a
        JOIN memories m1 ON a.source_id = m1.id
        JOIN memories m2 ON a.target_id = m2.id
        WHERE a.relation_type = 'associated_with' OR a.relation_type IS NULL
        LIMIT ?
    """, (limit,))

    rows = cursor.fetchall()
    print(f"\nProcessing {len(rows)} associations...")

    classified = 0
    skipped = 0
    type_counts = {}

    for row in rows:
        source_id, target_id, source_content, target_content = row

        source_content = (source_content or "")[:1000]
        target_content = (target_content or "")[:1000]

        if not source_content.strip() or not target_content.strip():
            skipped += 1
            continue

        new_type = classify_association(source_content, target_content, embedder)

        if new_type:
            type_counts[new_type] = type_counts.get(new_type, 0) + 1
            classified += 1

            if not dry_run:
                # Use composite key for UPDATE
                cursor.execute(
                    "UPDATE associations SET relation_type = ? WHERE source_id = ? AND target_id = ?",
                    (new_type, source_id, target_id)
                )

                if classified % 10 == 0:
                    conn.commit()
                    print(f"  Committed {classified} updates...")

    if not dry_run:
        conn.commit()

    conn.close()

    print(f"\n{'DRY RUN - ' if dry_run else ''}Results:")
    print(f"  Processed: {classified}")
    print(f"  Skipped (no content): {skipped}")
    print("  Type distribution:")
    for t, c in sorted(type_counts.items(), key=lambda x: -x[1]):
        print(f"    {t}: {c}")

if __name__ == "__main__":
    db_path = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")

    dry_run = "--apply" not in sys.argv

    limit = 500
    if "--limit" in sys.argv:
        idx = sys.argv.index("--limit")
        limit = int(sys.argv[idx + 1])

    print("=" * 50)
    print("TIER 2 SEMANTIC SIMILARITY CLASSIFIER")
    print("=" * 50)
    print(f"DB: {db_path}")
    print(f"Mode: {'DRY RUN' if dry_run else 'LIVE UPDATE'}")
    print(f"Limit: {limit} associations")
    print("=" * 50)

    process_untyped_associations(db_path, dry_run=dry_run, limit=limit)
