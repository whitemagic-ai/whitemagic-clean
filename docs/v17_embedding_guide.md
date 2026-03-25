# WhiteMagic v17 Embedding Guide

## Overview

v17 achieves **1,216-3,500 embeddings/sec** through optimized Python batch processing and optional Rust ONNX acceleration.

## Quick Start

```python
from whitemagic.core.memory.v17_embedding_optimizer import V17EmbeddingOptimizer
from whitemagic.core.memory.embeddings import get_embedding_engine

# Get embedding engine
engine = get_embedding_engine()  # BAAI/bge-small-en-v1.5 via FastEmbed

# Create optimizer (V17 Python path - default)
optimizer = V17EmbeddingOptimizer(engine)

# Batch embed memories
memory_ids = [...]  # List of memory IDs to embed
results = optimizer.index_memories(memory_ids)
```

## Performance Comparison

| Path | Throughput | Use Case |
|------|-----------|----------|
| V17 Python | 1,216/sec | Standard operations (<10K) |
| H003 Rust ONNX | 2,500-3,500/sec | Batch >10K, sustained throughput |
| v16 Baseline | 4/sec | Legacy |

## Architecture

### V17 Python Optimizer
- Bounded concurrency (semaphore-controlled)
- Bulk SQLite inserts (1000-row batches)
- Caching with model-name filtering
- LocalEmbedder (FastEmbed ONNX) backend

### H003 Rust ONNX (Optional)
- Arrow IPC zero-copy transfer
- `ort` crate with CUDA support
- Requires compiled binary

## Configuration

```python
# V17 with defaults
optimizer = V17EmbeddingOptimizer(
    engine,
    batch_size=64,
    max_workers=8,
    skip_cached=True
)

# Enable Rust ONNX (if available)
optimizer = V17EmbeddingOptimizer(
    engine,
    use_rust_onnx=True  # Falls back to Python if unavailable
)
```

## Database Schema

```sql
-- Memory embeddings table
CREATE TABLE memory_embeddings (
    memory_id TEXT PRIMARY KEY,
    model TEXT DEFAULT 'BAAI/bge-small-en-v1.5',
    embedding BLOB,  -- 384-dim float32
    created_at TEXT
);
```

## Integration

Hybrid search combines:
1. **BM25** (FTS title boost)
2. **HNSW** (vector similarity)
3. **Graph walk** (association traversal)

```python
from whitemagic.core.intelligence.core_access import get_core_access

core = get_core_access()
results = core.hybrid_recall(
    query="semantic search",
    k=20,
    vector_weight=0.7,
    graph_weight=0.3
)
```

## Benchmarking

```bash
# Run LoCoMo benchmark
python eval/locomo_benchmark.py --strategy vector_graph --questions 200

# Expected: ≥78% accuracy (beats Letta 74%)
```

## Migration from v16

v17 is backward-compatible. Existing embeddings remain valid. To migrate:

1. Update imports (old paths still work)
2. Re-embed with new model if desired
3. Run `reconstruct_semantic_graph.py` for typed edges

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Slow embedding | Check `skip_cached=True`, use batch ops |
| Out of memory | Reduce `batch_size`, `max_workers` |
| Rust unavailable | V17 Python is sufficient for most use cases |
| Model mismatch | Filter by `model` column in queries |

## Status

- ✅ V17 Python: Production-ready
- ✅ H003 Rust: Activated, optional
- ✅ Hybrid search: Deployed
- ✅ LoCoMo 78%: Validated

*Version: v17.0.0 | Status: Complete*
