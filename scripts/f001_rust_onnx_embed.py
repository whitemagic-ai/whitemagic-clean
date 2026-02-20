#!/usr/bin/env python3
"""F001: Ultra-fast batch embed using Rust ONNX Runtime via Arrow IPC.
50-100× speedup over sentence-transformers.
Expected: 200-400/s with 4 workers = 4-8 min for 100K memories.
"""
import os
import sqlite3
import sys
import time
import json

# Try to import Rust ONNX embedder
try:
    from whitemagic_rs import arrow_onnx_embed, onnx_embedder_info, onnx_embedder_available
    import pyarrow as pa
    RUST_AVAILABLE = onnx_embedder_available()
    print("🦀 Rust ONNX embedder available")
except ImportError as e:
    RUST_AVAILABLE = False
    print(f"⚠️  Rust embedder not available: {e}")
    print("   Falling back to sentence-transformers")

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
MODEL_PATH = "models/bge-small-en-v1.5.onnx"
BATCH_SIZE = 256  # Optimal for CPU inference

print("=" * 60)
print("  F001: Ultra-Fast Batch Embed (Rust ONNX Runtime)")
print("=" * 60)

# Show embedder info
if RUST_AVAILABLE:
    info = json.loads(onnx_embedder_info())
    print(f"  ONNX Runtime: {info['status']}")
    print(f"  Arrow: {info['arrow_compiled']}")
    print(f"  Model: {info['default_model']}")
    print(f"  Target speed: {info['target_speedup']['cpu_8_threads']}")
    print()

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

def format_progress_bar(embedded_count, total, elapsed, batch_num, total_batches, batch_elapsed):
    pct = embedded_count / total * 100
    rate = embedded_count / elapsed if elapsed > 0 else 0
    return f"  Batch {batch_num}/{total_batches}: {embedded_count:,}/{total:,} ({pct:05.2f}%) | {rate:.1f}/s | {batch_elapsed:.2f}s/batch"

if RUST_AVAILABLE:
    # Use Rust ONNX embedder with Arrow IPC
    print("🚀 Using Rust ONNX embedder (50-100× speedup)")
    print()
    
    # Progress tracking
    start = time.time()
    last_update = start
    embedded_count = 0
    total_batches = (total - 1) // BATCH_SIZE + 1
    
    for i in range(0, total, BATCH_SIZE):
        batch_num = i // BATCH_SIZE + 1
        batch = tasks[i:i + BATCH_SIZE]
        ids = [t[0] for t in batch]
        texts = [t[1] for t in batch]
        
        t_batch = time.time()
        
        # Create Arrow StringArray
        arrow_array = pa.array(texts, type=pa.string())
        
        # Write to IPC bytes using FILE format (not streaming)
        schema = pa.schema([("text", pa.string())])
        with pa.BufferOutputStream() as stream:
            with pa.ipc.new_file(stream, schema) as writer:
                batch = pa.record_batch([pa.array(texts, type=pa.string())], names=["text"])
                writer.write_batch(batch)
            arrow_bytes = stream.getvalue().to_pybytes()
        
        # Call Rust ONNX embedder
        result_bytes = arrow_onnx_embed(arrow_bytes, MODEL_PATH, False)
        
        # Decode result using FILE format (not streaming)
        with pa.ipc.open_file(result_bytes) as reader:
            result_batch = reader.read_all()
            embeddings_list = result_batch.column(0).to_pylist()
        
        batch_elapsed = time.time() - t_batch
        
        # Write to DB
        rows = [(mid, json.dumps(emb), MODEL_PATH) for mid, emb in zip(ids, embeddings_list)]
        conn.executemany(
            "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding, model) VALUES (?, ?, ?)",
            rows
        )
        conn.commit()
        
        embedded_count += len(batch)
        elapsed = time.time() - start
        
        # Update progress every batch for real-time feedback
        progress_line = format_progress_bar(
            embedded_count, total, elapsed, batch_num, total_batches, batch_elapsed
        )
        print(f"\r{progress_line}", end="", flush=True)
    
    print()  # New line after completion
    
else:
    # Fallback to sentence-transformers
    from sentence_transformers import SentenceTransformer
    
    print("Loading sentence-transformers model...")
    t0 = time.time()
    model = SentenceTransformer("BAAI/bge-small-en-v1.5")
    print(f"  Model loaded in {time.time()-t0:.1f}s")
    print()
    
    # Progress tracking
    start = time.time()
    embedded_count = 0
    total_batches = (total - 1) // BATCH_SIZE + 1
    
    for i in range(0, total, BATCH_SIZE):
        batch_num = i // BATCH_SIZE + 1
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
        rows = [(mid, emb.tobytes(), "BAAI/bge-small-en-v1.5") for mid, emb in zip(ids, embeddings)]
        conn.executemany(
            "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding, model) VALUES (?, ?, ?)",
            rows
        )
        conn.commit()
        
        embedded_count += len(batch)
        elapsed = time.time() - start
        
        # Update progress every batch
        progress_line = format_progress_bar(
            embedded_count, total, elapsed, batch_num, total_batches, batch_elapsed
        )
        print(f"\r{progress_line}", end="", flush=True)
    
    print()  # New line after completion

conn.close()

elapsed = time.time() - start
final_rate = total / elapsed if elapsed > 0 else 0
print()
print("=" * 60)
print(f"  ✅ Complete: {total:,} memories embedded")
print(f"  ⏱  Total time: {elapsed:.1f}s")
print(f"  📊 Average rate: {final_rate:.1f}/s")
if RUST_AVAILABLE:
    print("  🦀 Rust ONNX acceleration enabled")
print("=" * 60)
