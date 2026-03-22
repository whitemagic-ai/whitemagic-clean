#!/usr/bin/env python3
"""Test SimHash duplicate detection on real embeddings"""

import sqlite3
import sys
from pathlib import Path

import numpy as np

# Add whitemagic to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.memory.embeddings import EmbeddingEngine


def test_simhash_on_real_data():
    """Test SimHash LSH on actual embeddings from DB"""

    # Connect to DB
    db_path = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
    if not db_path.exists():
        print(f"❌ DB not found: {db_path}")
        return

    conn = sqlite3.connect(str(db_path))
    cursor = conn.cursor()

    # Get embeddings count (table is memory_embeddings)
    cursor.execute("SELECT COUNT(*) FROM memory_embeddings WHERE embedding IS NOT NULL")
    count = cursor.fetchone()[0]
    print(f"📊 Found {count} embeddings in database")

    if count < 2:
        print("❌ Need at least 2 embeddings to test duplicate detection")
        return

    # Load sample of embeddings (limit to 100 for quick test)
    cursor.execute("""
        SELECT memory_id, embedding 
        FROM memory_embeddings 
        WHERE embedding IS NOT NULL 
        LIMIT 100
    """)
    rows = cursor.fetchall()
    conn.close()

    print(f"🔍 Testing on {len(rows)} embeddings")

    # Parse embeddings
    engine = EmbeddingEngine()
    memory_ids = []
    vectors = []

    for memory_id, emb_blob in rows:
        try:
            # Embeddings stored as JSON array
            import json
            emb = json.loads(emb_blob)
            memory_ids.append(memory_id)
            vectors.append(emb)
        except Exception as e:
            print(f"⚠️  Failed to parse embedding for {memory_id}: {e}")

    if len(vectors) < 2:
        print("❌ Failed to load valid embeddings")
        return

    vectors_array = np.array(vectors, dtype=np.float32)
    print(f"✅ Loaded {len(vectors)} embeddings, shape: {vectors_array.shape}")

    # Test at different thresholds
    for threshold in [0.99, 0.95, 0.90, 0.85]:
        print(f"\n🎯 Testing threshold={threshold}")

        # Create memory ID lookup
        engine.memory_ids = memory_ids
        engine.embeddings = vectors_array

        duplicates = engine.find_duplicates(threshold=threshold, max_results=50)

        if duplicates:
            print(f"   ✅ Found {len(duplicates)} duplicate pairs")
            for i, dup in enumerate(duplicates[:5]):  # Show first 5
                print(f"      {i+1}. {dup['source_id'][:8]} ↔ {dup['target_id'][:8]} (sim={dup['similarity']:.4f})")
        else:
            print("   ⚠️  No duplicates found")

    # Also test with synthetic identical embeddings
    print("\n🧪 Testing with synthetic identical embeddings")
    test_vectors = np.array([
        [1.0, 0.0, 0.0, 0.0],
        [1.0, 0.0, 0.0, 0.0],  # Identical to first
        [0.99, 0.01, 0.0, 0.0],  # Very similar to first
        [0.0, 1.0, 0.0, 0.0],  # Orthogonal
    ], dtype=np.float32)

    test_engine = EmbeddingEngine()
    test_engine.memory_ids = ["test1", "test2", "test3", "test4"]
    test_engine.embeddings = test_vectors

    synthetic_dups = test_engine.find_duplicates(threshold=0.90, max_results=10)
    print(f"   Synthetic duplicates found: {len(synthetic_dups)}")
    for dup in synthetic_dups:
        print(f"      {dup['source_id']} ↔ {dup['target_id']} (sim={dup['similarity']:.4f})")

if __name__ == "__main__":
    test_simhash_on_real_data()
