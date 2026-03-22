#!/usr/bin/env python3
"""Quick test of SimHash implementation"""

import json

import numpy as np

# Test SimHash directly
import whitemagic_rs

# Generate test embeddings with known duplicates
np.random.seed(42)
embeddings = []

# Create 10 base embeddings
for i in range(10):
    emb = np.random.randn(384).astype(np.float32)
    emb = emb / np.linalg.norm(emb)
    embeddings.append(emb)

# Add 5 near-duplicates (very similar to first 5)
for i in range(5):
    dup = embeddings[i] + np.random.randn(384).astype(np.float32) * 0.01
    dup = dup / np.linalg.norm(dup)
    embeddings.append(dup)

# Flatten for Rust
vectors = np.array(embeddings, dtype=np.float32)
embeddings_flat = vectors.flatten().tolist()
embedding_dim = 384

print(f"Testing SimHash with {len(embeddings)} embeddings ({len(embeddings)-10} duplicates)")
print(f"Embedding dimension: {embedding_dim}")
print(f"Flattened size: {len(embeddings_flat)}")

# Test SimHash
result_json = whitemagic_rs.simhash_find_duplicates(
    embeddings_flat,
    embedding_dim,
    0.90,  # Lower threshold for near-duplicates
    100
)

results = json.loads(result_json)
print(f"\n✅ SimHash found {len(results)} duplicate pairs")

for i, dup in enumerate(results[:10]):
    print(f"  {i+1}. Pair ({dup['idx_a']}, {dup['idx_b']}): similarity = {dup['similarity']:.4f}")

# Verify with actual cosine similarity
if results:
    pair = results[0]
    a = vectors[pair['idx_a']]
    b = vectors[pair['idx_b']]
    actual_sim = float(np.dot(a, b))
    estimated_sim = pair['similarity']
    print("\nVerification:")
    print(f"  Actual cosine similarity: {actual_sim:.4f}")
    print(f"  SimHash estimate: {estimated_sim:.4f}")
    print(f"  Error: {abs(actual_sim - estimated_sim):.4f}")
