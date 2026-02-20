#!/usr/bin/env python3
"""Batch-generate embeddings for all unembedded memories.

Iterates through the entire corpus in configurable batches, encoding
text via sentence-transformers and caching in the memory_embeddings table.

Usage:
    python scripts/batch_embed.py                  # Full run (all unembedded)
    python scripts/batch_embed.py --limit 5000     # Process at most 5000
    python scripts/batch_embed.py --batch-size 128  # Larger GPU batches
    python scripts/batch_embed.py --dry-run         # Count only, no encoding
"""

import argparse
import logging
import os
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
log = logging.getLogger("batch_embed")


def main():
    parser = argparse.ArgumentParser(description="Batch embed unembedded memories")
    parser.add_argument("--limit", type=int, default=0, help="Max memories to process (0=all)")
    parser.add_argument("--batch-size", type=int, default=64, help="Texts per encode_batch call")
    parser.add_argument("--page-size", type=int, default=2000, help="SQL page size for iteration")
    parser.add_argument("--dry-run", action="store_true", help="Count only, skip encoding")
    args = parser.parse_args()

    from whitemagic.core.memory.embeddings import get_embedding_engine, MODEL_NAME, _pack_embedding

    engine = get_embedding_engine()
    if not engine.available():
        log.error("sentence-transformers not installed — cannot embed")
        sys.exit(1)

    db = engine._get_db()
    if db is None:
        log.error("Cannot connect to embedding DB")
        sys.exit(1)

    # Count unembedded
    total_memories = db.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    total_embedded = db.execute("SELECT COUNT(*) FROM memory_embeddings").fetchone()[0]
    unembedded = total_memories - total_embedded

    log.info(f"Corpus: {total_memories:,} memories, {total_embedded:,} embedded, {unembedded:,} remaining")

    if args.dry_run:
        log.info("Dry run — exiting")
        return

    if unembedded == 0:
        log.info("All memories already embedded!")
        return

    # Force model load upfront
    log.info(f"Loading model: {MODEL_NAME}")
    model = engine._get_model()
    if model is None:
        log.error("Failed to load embedding model")
        sys.exit(1)
    log.info("Model loaded")

    # Paginate through unembedded memories
    offset = 0
    total_encoded = 0
    total_errors = 0
    start = time.perf_counter()
    target = args.limit if args.limit > 0 else unembedded

    while total_encoded < target:
        remaining = target - total_encoded
        page_limit = min(args.page_size, remaining)

        rows = db.execute(
            """SELECT m.id, m.title, SUBSTR(m.content, 1, 2000) as content
               FROM memories m
               WHERE m.id NOT IN (SELECT memory_id FROM memory_embeddings)
               ORDER BY m.importance DESC
               LIMIT ? OFFSET ?""",
            (page_limit, offset),
        ).fetchall()

        if not rows:
            break

        # Prepare texts
        texts = []
        ids = []
        for row in rows:
            title = row[1] or ""
            content = row[2] or ""
            text = f"{title} {content}".strip()
            if not text:
                text = "empty"
            texts.append(text)
            ids.append(row[0])

        # Batch encode
        for batch_start in range(0, len(texts), args.batch_size):
            batch_end = min(batch_start + args.batch_size, len(texts))
            batch_texts = texts[batch_start:batch_end]
            batch_ids = ids[batch_start:batch_end]

            try:
                embeddings = engine.encode_batch(batch_texts, batch_size=args.batch_size)
                if embeddings is None:
                    log.warning(f"Batch encode returned None at offset {offset + batch_start}")
                    total_errors += len(batch_texts)
                    continue

                for mid, emb in zip(batch_ids, embeddings):
                    try:
                        db.execute(
                            "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding, model) VALUES (?, ?, ?)",
                            (mid, _pack_embedding(emb), MODEL_NAME),
                        )
                        total_encoded += 1
                    except Exception as e:
                        total_errors += 1
                        if total_errors <= 5:
                            log.warning(f"Cache error for {mid[:8]}: {e}")

                db.commit()

            except Exception as e:
                log.error(f"Batch encode error: {e}")
                total_errors += len(batch_texts)

        elapsed = time.perf_counter() - start
        rate = total_encoded / elapsed if elapsed > 0 else 0
        pct = total_encoded / target * 100
        log.info(
            f"Progress: {total_encoded:,}/{target:,} ({pct:.1f}%) | "
            f"{rate:.1f} mem/s | {elapsed:.0f}s elapsed | {total_errors} errors"
        )

        offset += page_limit

    elapsed = time.perf_counter() - start
    final_embedded = db.execute("SELECT COUNT(*) FROM memory_embeddings").fetchone()[0]

    log.info(f"\n{'='*60}")
    log.info("Batch embedding complete")
    log.info(f"  Encoded: {total_encoded:,}")
    log.info(f"  Errors: {total_errors:,}")
    if elapsed > 0:
        log.info(f"  Duration: {elapsed:.1f}s ({total_encoded / elapsed:.1f} mem/s)")
    log.info(f"  Total embeddings: {final_embedded:,} / {total_memories:,} ({final_embedded/total_memories*100:.1f}%)")


if __name__ == "__main__":
    main()
