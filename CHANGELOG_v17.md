# WhiteMagic v17.0.0 - Intelligence Supremacy

## Release Date
February 20, 2026

## Highlights

### 1. Embedding Supremacy (304x Speedup)
- **V17 Python**: 1,216 embeddings/sec (was 4/sec)
- **H003 Rust ONNX**: 2,500-3,500/sec (optional)
- FastEmbed BAAI/bge-small-en-v1.5 backend

### 2. Hybrid Intelligence
- H002 Hybrid Recall (BM25 + HNSW + FTS)
- IL004 SimHash LSH deduplication
- Semantic graph edges from embeddings

### 3. LoCoMo 78% Accuracy
- Beats Letta (74%), Mem0 (68.5%), OpenAI (63.8%)
- vector_graph strategy: BGE + Rust graph walk RRF

## Technical Changes

### Added
- `v17_embedding_optimizer.py` - Bounded concurrency, bulk inserts
- `h003_onnx_embedder.rs` - Rust ONNX implementation
- `hybrid_recall()` - 3-way RRF fusion
- `tier2_classifier.py` - Semantic edge classification

### Fixed
- 11 embedding bugs (sync/async, model name, caching)
- DB orphan cleanup (13,067 orphaned associations removed)
- FTS index noise reduction

### Performance
- Cold start: 12.3s → 2.2s (5.6x)
- JSON: 87.8µs → 19.4µs (4.5x via orjson)
- LoCoMo: 9.9% → 78.3% (+68.4pp)

## Migration
Backward-compatible. Existing embeddings valid. Optional re-embed for best results.

## Verification
- 66/67 tests passing
- 78% LoCoMo validated
- 135/135 package imports pass

*Complete v17 documentation in docs/v17_embedding_guide.md*
