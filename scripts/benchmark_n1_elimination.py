#!/usr/bin/env python3
"""Benchmark N+1 query elimination speedup (PSR-025/027)."""

import time
import sqlite3
import tempfile
import os
from pathlib import Path

# Ensure whitemagic is in path
import sys
sys.path.insert(0, str(Path(__file__).parent.parent / "whitemagic"))


def benchmark_batch_vs_single():
    """Benchmark batch IN(...) + executemany vs per-row queries."""
    # Create temp database
    with tempfile.NamedTemporaryFile(suffix=".db", delete=False) as tmp:
        db_path = tmp.name
    
    try:
        conn = sqlite3.connect(db_path)
        conn.row_factory = sqlite3.Row
        
        # Setup tables
        conn.execute("""
            CREATE TABLE memories (
                id TEXT PRIMARY KEY,
                title TEXT,
                content TEXT,
                access_count INTEGER DEFAULT 0
            )
        """)
        conn.execute("""
            CREATE TABLE associations (
                source_id TEXT,
                target_id TEXT,
                strength REAL,
                last_traversed_at TEXT,
                traversal_count INTEGER DEFAULT 0
            )
        """)
        conn.commit()
        
        # Seed data: 1000 memories, 500 associations
        memories = [(f"mem_{i:04d}", f"Title {i}", f"Content {i}", i % 10) 
                    for i in range(1000)]
        conn.executemany(
            "INSERT INTO memories (id, title, content, access_count) VALUES (?, ?, ?, ?)",
            memories
        )
        
        associations = []
        for i in range(500):
            src = f"mem_{i:04d}"
            tgt = f"mem_{(i+1) % 1000:04d}"
            associations.append((src, tgt, 0.5 + (i % 5) * 0.1))
        conn.executemany(
            "INSERT INTO associations (source_id, target_id, strength) VALUES (?, ?, ?)",
            associations
        )
        conn.commit()
        
        # Test 1: Per-row title queries (N+1 pattern)
        test_ids = [f"mem_{i:04d}" for i in range(100)]
        
        start = time.perf_counter()
        for _ in range(10):  # 10 iterations
            for mid in test_ids:
                conn.execute("SELECT title FROM memories WHERE id = ?", (mid,)).fetchone()
        single_time = time.perf_counter() - start
        
        # Test 2: Batch IN(...) query
        start = time.perf_counter()
        ph = ",".join("?" * len(test_ids))
        for _ in range(10):
            conn.execute(
                f"SELECT id, title FROM memories WHERE id IN ({ph})",
                test_ids
            ).fetchall()
        batch_time = time.perf_counter() - start
        
        # Test 3: Per-row UPDATE (N+1 pattern)
        start = time.perf_counter()
        for _ in range(5):
            for mid in test_ids[:50]:
                conn.execute(
                    "UPDATE associations SET traversal_count = traversal_count + 1 WHERE source_id = ?",
                    (mid,)
                )
            conn.commit()
        single_update_time = time.perf_counter() - start
        
        # Test 4: executemany UPDATE
        start = time.perf_counter()
        for _ in range(5):
            conn.executemany(
                "UPDATE associations SET traversal_count = traversal_count + 1 WHERE source_id = ?",
                [(mid,) for mid in test_ids[:50]]
            )
            conn.commit()
        batch_update_time = time.perf_counter() - start
        
        conn.close()
        
        # Report
        print("=" * 60)
        print("N+1 ELIMINATION BENCHMARK")
        print("=" * 60)
        print("\n1. SELECT title (100 rows x 10 iterations):")
        print(f"   Per-row queries:  {single_time:.3f}s")
        print(f"   Batch IN(...):    {batch_time:.3f}s")
        print(f"   Speedup:          {single_time/batch_time:.1f}x")
        
        print("\n2. UPDATE traversal_count (50 rows x 5 iterations):")
        print(f"   Per-row UPDATE:   {single_update_time:.3f}s")
        print(f"   executemany:      {batch_update_time:.3f}s")
        print(f"   Speedup:          {single_update_time/batch_update_time:.1f}x")
        
        select_speedup = single_time / batch_time
        update_speedup = single_update_time / batch_update_time
        min_speedup = min(select_speedup, update_speedup)
        
        print(f"\n{'=' * 60}")
        if min_speedup >= 5.0:
            print(f"✅ PASS: Minimum speedup {min_speedup:.1f}x >= 5x")
        else:
            print(f"⚠️  PARTIAL: Minimum speedup {min_speedup:.1f}x < 5x")
        print(f"{'=' * 60}\n")
        
        return min_speedup >= 5.0
        
    finally:
        os.unlink(db_path)


if __name__ == "__main__":
    success = benchmark_batch_vs_single()
    sys.exit(0 if success else 1)
