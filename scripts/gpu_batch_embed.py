#!/usr/bin/env python3
"""
GPU-accelerated batch embedding for Alienware operation

Optimized for NVIDIA GPU with CUDA support.
Falls back to CPU if GPU unavailable.
"""

import sqlite3
import time
import sys
from pathlib import Path

# Check for torch/sentence-transformers
try:
    import torch
    from sentence_transformers import SentenceTransformer
    import numpy as np
except ImportError as e:
    print(f"❌ Missing dependency: {e}")
    print("Install with: pip install torch sentence-transformers numpy")
    sys.exit(1)

DB_PATH = Path.home() / ".whitemagic/memory/whitemagic.db"
MODEL_NAME = "BAAI/bge-small-en-v1.5"
BATCH_SIZE = 2048  # Large batch for GPU (adjust if OOM)
DEVICE = "cuda" if torch.cuda.is_available() else "cpu"

def main():
    print("=" * 70)
    print("  🚀 GPU Batch Embedding Operation - Alienware Lightning")
    print("=" * 70)
    print()
    
    # Device info
    print(f"Device: {DEVICE}")
    if DEVICE == "cuda":
        gpu_name = torch.cuda.get_device_name(0)
        gpu_memory = torch.cuda.get_device_properties(0).total_memory / 1e9
        print(f"GPU: {gpu_name}")
        print(f"GPU Memory: {gpu_memory:.1f} GB")
    else:
        print("⚠️  GPU not available, using CPU (slower)")
    print()
    
    # Check database
    if not DB_PATH.exists():
        print(f"❌ Database not found: {DB_PATH}")
        print(f"   Expected at: ~/.whitemagic/memory/whitemagic.db")
        sys.exit(1)
    
    # Load model
    print(f"Loading model: {MODEL_NAME}")
    try:
        model = SentenceTransformer(MODEL_NAME, device=DEVICE)
        print(f"✓ Model loaded on {DEVICE}")
    except Exception as e:
        print(f"❌ Model loading failed: {e}")
        sys.exit(1)
    print()
    
    # Get embedding tasks
    conn = sqlite3.connect(DB_PATH)
    
    # Count total memories
    cursor = conn.execute("""
        SELECT COUNT(*) FROM memories 
        WHERE memory_type != 'quarantined'
    """)
    total_memories = cursor.fetchone()[0]
    
    # Count already embedded
    cursor = conn.execute("""
        SELECT COUNT(DISTINCT memory_id) FROM memory_embeddings
    """)
    already_embedded = cursor.fetchone()[0]
    
    # Get tasks to embed
    cursor = conn.execute("""
        SELECT m.id, m.content
        FROM memories m
        WHERE m.memory_type != 'quarantined'
        AND m.id NOT IN (SELECT memory_id FROM memory_embeddings)
        ORDER BY m.id
    """)
    tasks = [(row[0], row[1][:512]) for row in cursor.fetchall()]
    
    remaining = len(tasks)
    coverage = (already_embedded / total_memories * 100) if total_memories > 0 else 0
    
    print(f"Total memories:      {total_memories:,}")
    print(f"Already embedded:    {already_embedded:,}")
    print(f"Remaining:           {remaining:,}")
    print(f"Current coverage:    {coverage:.1f}%")
    print()
    
    if remaining == 0:
        print("✅ All memories already embedded!")
        conn.close()
        return
    
    # Batch embed with progress
    print(f"Starting batch embedding (batch_size={BATCH_SIZE})...")
    print("-" * 70)
    
    start_time = time.time()
    embedded_count = 0
    
    for i in range(0, len(tasks), BATCH_SIZE):
        batch = tasks[i:i+BATCH_SIZE]
        batch_ids = [t[0] for t in batch]
        batch_texts = [t[1] for t in batch]
        
        # Encode on GPU/CPU
        batch_start = time.time()
        embeddings = model.encode(
            batch_texts,
            batch_size=BATCH_SIZE,
            show_progress_bar=False,
            convert_to_numpy=True,
            device=DEVICE
        )
        batch_elapsed = time.time() - batch_start
        
        # Write to DB
        embeddings_bytes = [emb.tobytes() for emb in embeddings]
        conn.executemany(
            "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding) VALUES (?, ?)",
            list(zip(batch_ids, embeddings_bytes))
        )
        conn.commit()
        
        embedded_count += len(batch)
        rate = len(batch) / batch_elapsed
        elapsed_total = time.time() - start_time
        overall_rate = embedded_count / elapsed_total
        remaining_now = remaining - embedded_count
        eta = remaining_now / overall_rate if overall_rate > 0 else 0
        
        batch_num = i // BATCH_SIZE + 1
        total_batches = (remaining + BATCH_SIZE - 1) // BATCH_SIZE
        
        print(f"Batch {batch_num:3d}/{total_batches}: "
              f"+{len(batch):4d} in {batch_elapsed:5.1f}s ({rate:6.0f}/s) | "
              f"Total: {embedded_count:6,}/{remaining:6,} | "
              f"Overall: {overall_rate:5.0f}/s | "
              f"ETA: {eta/60:4.1f} min")
    
    elapsed_total = time.time() - start_time
    
    print("-" * 70)
    print()
    print(f"✅ EMBEDDING COMPLETE!")
    print(f"   Embedded:      {embedded_count:,} memories")
    print(f"   Time:          {elapsed_total/60:.1f} minutes")
    print(f"   Average rate:  {embedded_count/elapsed_total:.0f} embeddings/sec")
    print()
    
    # Verify final state
    cursor = conn.execute("SELECT COUNT(DISTINCT memory_id) FROM memory_embeddings")
    final_count = cursor.fetchone()[0]
    final_coverage = (final_count / total_memories * 100) if total_memories > 0 else 0
    
    print(f"Final embedding count: {final_count:,}")
    print(f"Final coverage:        {final_coverage:.1f}%")
    print()
    
    # Test one embedding
    cursor = conn.execute("SELECT embedding FROM memory_embeddings LIMIT 1")
    test_emb = np.frombuffer(cursor.fetchone()[0], dtype=np.float32)
    print(f"✓ Embedding dimension verified: {len(test_emb)} (expected 384)")
    
    conn.close()
    
    print()
    print("=" * 70)
    print("  Ready to transfer back to main laptop!")
    print("=" * 70)


if __name__ == "__main__":
    main()
