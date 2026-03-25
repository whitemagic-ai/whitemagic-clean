#!/usr/bin/env python3
"""F001: Fast batch embed using sentence-transformers directly.
Bypasses WhiteMagic EmbeddingEngine to avoid FastEmbed/network issues.
Tested at 114/s on this machine → ~15 min for 99K memories.
"""
import os
import sqlite3
import sys
import time

from sentence_transformers import SentenceTransformer

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
MODEL_NAME = "BAAI/bge-small-en-v1.5"
BATCH_SIZE = 512

print("=" * 60)
print("  F001: Fast Batch Embed (sentence-transformers direct)")
print("=" * 60)

# Count
conn = sqlite3.connect(DB_PATH)
active = conn.execute(
    "SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'"
).fetchone()[0]
already = conn.execute(
    """SELECT COUNT(DISTINCT memory_id) FROM memory_embeddings
       WHERE memory_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined')"""
).fetchone()[0]
remaining = active - already
print(f"  Active memories:  {active:,}")
print(f"  Already embedded: {already:,}")
print(f"  Remaining:        {remaining:,}")
print(f"  Batch size:       {BATCH_SIZE}")
print()

if remaining == 0:
    print("✅ All active memories already embedded!")
    conn.close()
    sys.exit(0)

print("Loading sentence-transformers model...")
t0 = time.time()
model = SentenceTransformer(MODEL_NAME)
print(f"  Model loaded in {time.time()-t0:.1f}s")
print()

# Fetch all unembedded active memory IDs + content
cursor = conn.execute("""
    SELECT m.id, COALESCE(m.title, '') || ' ' || COALESCE(m.content, '')
    FROM memories m
    WHERE m.memory_type != 'quarantined'
    AND m.id NOT IN (SELECT memory_id FROM memory_embeddings)
    ORDER BY m.id
""")
tasks = [(row[0], row[1][:512]) for row in cursor.fetchall()]
total = len(tasks)
print(f"  Tasks loaded: {total:,}")
print()

start = time.time()
embedded_count = 0
batch_num = 0

for i in range(0, total, BATCH_SIZE):
    batch = tasks[i:i + BATCH_SIZE]
    ids = [t[0] for t in batch]
    texts = [t[1] for t in batch]

    t_batch = time.time()
    embeddings = model.encode(
        texts,
        batch_size=BATCH_SIZE,
        show_progress_bar=False,
        convert_to_numpy=True,
    )
    batch_elapsed = time.time() - t_batch

    # Write to DB
    rows = [(mid, emb.tobytes(), MODEL_NAME) for mid, emb in zip(ids, embeddings)]
    conn.executemany(
        "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding, model) VALUES (?, ?, ?)",
        rows,
    )
    conn.commit()

    embedded_count += len(batch)
    elapsed_total = time.time() - start
    rate = embedded_count / elapsed_total
    remaining_count = total - embedded_count
    eta_min = remaining_count / rate / 60 if rate > 0 else 0
    batch_num += 1
    pct = embedded_count / total * 100

    print(
        f"  Batch {batch_num:3d}: +{len(batch):4d} in {batch_elapsed:.1f}s "
        f"({len(batch)/batch_elapsed:.0f}/s) | "
        f"Total: {embedded_count:,}/{total:,} ({pct:.1f}%) | "
        f"Avg: {rate:.0f}/s | ETA: {eta_min:.1f}min"
    )

elapsed = time.time() - start
conn.close()

print()
print("=" * 60)
print("  COMPLETE!")
print("=" * 60)
print(f"  Embedded:   {embedded_count:,} memories")
print(f"  Time:       {elapsed:.1f}s ({elapsed/60:.1f} min)")
print(f"  Avg rate:   {embedded_count/elapsed:.0f} embeddings/sec")

# Final verification
conn2 = sqlite3.connect(DB_PATH)
final = conn2.execute(
    """SELECT COUNT(DISTINCT memory_id) FROM memory_embeddings
       WHERE memory_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined')"""
).fetchone()[0]
conn2.close()
print(f"  Final coverage: {final:,} / {active:,} ({final/active*100:.1f}%)")
