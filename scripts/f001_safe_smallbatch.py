#!/usr/bin/env python3
"""
F001: Ultra-Safe Small-Batch Embedding (Rust ONNX)
Process in tiny batches (16) to avoid memory issues
"""
import os
import sys
import json
import sqlite3
import time
import io
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

# Import Rust bridge
from whitemagic_rs import arrow_onnx_embed, onnx_embedder_info
import pyarrow as pa

# Configuration
BATCH_SIZE = 32  # Moderate batches for stability + speed
MODEL_PATH = "models/bge-small-en-v1.5.onnx"
DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")

def format_progress(current, total, elapsed, batch_num, total_batches, batch_time):
    pct = current / total * 100 if total > 0 else 0
    rate = current / elapsed if elapsed > 0 else 0
    eta = (total - current) / rate if rate > 0 else 0
    return f"  Batch {batch_num}/{total_batches}: {current:,}/{total:,} ({pct:05.2f}%) | {rate:.1f}/s | ETA: {eta/60:.1f}m | {batch_time:.2f}s/batch"

def main():
    print("="*60)
    print("  F001: Safe Small-Batch Embed (16/batch)")
    print("="*60)
    
    # Check embedder
    info = json.loads(onnx_embedder_info())
    print(f"  ONNX: {info['status']}")
    print(f"  Model: {MODEL_PATH}")
    print(f"  Batch size: {BATCH_SIZE} (conservative)")
    
    # Connect to DB
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    
    # Count work
    cursor.execute("SELECT COUNT(*) FROM memory_embeddings")
    already_embedded = cursor.fetchone()[0]
    
    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type NOT IN ('archived_orphan', 'quarantined', 'scavenged')")
    total_active = cursor.fetchone()[0]
    
    remaining = total_active - already_embedded
    print(f"\n  Active: {total_active:,} | Embedded: {already_embedded:,} | Remaining: {remaining:,}")
    
    if remaining == 0:
        print("\n  ✅ All memories already embedded!")
        return
    
    # Get tasks
    cursor.execute("""
        SELECT m.id, m.content 
        FROM memories m
        LEFT JOIN memory_embeddings e ON m.id = e.memory_id
        WHERE m.memory_type NOT IN ('archived_orphan', 'quarantined', 'scavenged') AND e.memory_id IS NULL
        ORDER BY m.id
    """)
    tasks = cursor.fetchall()
    
    total_batches = (len(tasks) + BATCH_SIZE - 1) // BATCH_SIZE
    print(f"\n  Processing {len(tasks):,} texts in {total_batches} batches of {BATCH_SIZE}")
    print("  Press Ctrl+C to stop anytime\n")
    
    # Process
    embedded_count = 0
    start_time = time.time()
    schema = pa.schema([("text", pa.string())])
    
    try:
        for i in range(0, len(tasks), BATCH_SIZE):
            batch_num = i // BATCH_SIZE + 1
            batch = tasks[i:i + BATCH_SIZE]
            ids = [t[0] for t in batch]
            texts = [t[1] for t in batch]
            
            t_batch = time.time()
            
            # Encode texts to Arrow
            with pa.BufferOutputStream() as stream:
                with pa.ipc.new_file(stream, schema) as writer:
                    rb = pa.record_batch([pa.array(texts, type=pa.string())], names=["text"])
                    writer.write_batch(rb)
                arrow_bytes = stream.getvalue().to_pybytes()
            
            # Call Rust embedder
            result_bytes = arrow_onnx_embed(arrow_bytes, MODEL_PATH, False)
            
            # Convert list to bytes if needed
            if isinstance(result_bytes, list):
                result_bytes = bytes(result_bytes)
            
            # Decode result
            with pa.ipc.open_file(io.BytesIO(result_bytes)) as reader:
                result_batch = reader.read_all()
                embeddings_list = result_batch.column(0).to_pylist()
            
            # Write to DB
            rows = [(mid, json.dumps(emb), MODEL_PATH) for mid, emb in zip(ids, embeddings_list)]
            conn.executemany(
                "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding, model) VALUES (?, ?, ?)",
                rows
            )
            conn.commit()
            
            batch_elapsed = time.time() - t_batch
            embedded_count += len(batch)
            elapsed = time.time() - start_time
            
            print(f"\r{format_progress(embedded_count, len(tasks), elapsed, batch_num, total_batches, batch_elapsed)}", end="", flush=True)
            
            # Early exit point for testing
            if batch_num >= 5:  # Stop after 5 batches for testing
                print(f"\n\n  🛑 Stopped after {batch_num} batches for testing")
                break
                
    except KeyboardInterrupt:
        print("\n\n  ⏹️  Stopped by user")
    except Exception as e:
        print(f"\n\n  ❌ Error: {e}")
        import traceback
        traceback.print_exc()
    
    finally:
        elapsed = time.time() - start_time
        rate = embedded_count / elapsed if elapsed > 0 else 0
        print(f"\n\n  {'='*60}")
        print(f"  Embedded: {embedded_count:,} texts in {elapsed:.1f}s ({rate:.1f}/s)")
        print(f"  {'='*60}")
        conn.close()

if __name__ == "__main__":
    main()
