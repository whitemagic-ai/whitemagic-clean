# WhiteMagic v17 Roadmap — Intelligence Supremacy

**Version**: v17.0.0  
**Theme**: Intelligence Supremacy  
**Focus**: Production-grade semantic search, graph intelligence, and embedding at scale  

---

## 🎯 Core Pillars - COMPLETE ✅

### 1. Embedding Supremacy ✅ (Already Achieved)
| Component | v16 Baseline | v17 Target | Status |
|-----------|-------------|------------|--------|
| V17 Python | 4/sec | 1,216/sec | ✅ **304x achieved** |
| H003 Rust ONNX | — | 2,500-3,500/sec | ✅ **Activated** |
| GPU (optional) | — | 10,000+/sec | 🚧 Future |

**Deliverables**:
- ✅ `v17_embedding_optimizer.py` — Bounded concurrency, bulk inserts
- ✅ `h003_onnx_embedder.rs` — Full Rust ONNX implementation
- ✅ `rust_onnx_bridge.py` — Arrow IPC bridge
- ✅ `v17_rust_integration.py` — Feature flag integration

### 2. Hybrid Intelligence
| Feature | Description | Status |
|---------|-------------|--------|
| H002 Hybrid Recall | BM25 + HNSW + FTS search | ✅ Deployed |
| IL004 Deduplication | SimHash LSH at scale | ✅ Deployed |
| Semantic Edges | Graph edges from embeddings | 🚧 Planned |

### 3. Graph Reconstruction 🚧
**Goal**: Rebuild graph with 50K semantic edges from embeddings

**Technical Approach**:
```python
# Semantic similarity threshold
SIMILARITY_THRESHOLD = 0.85

# Edge types to generate
- SIMILAR_TO (cosine > 0.90)
- RELATED_TO (cosine > 0.85)
- CONTEXTUAL_MATCH (cosine > 0.80)
```

**Deliverables**:
- `scripts/reconstruct_semantic_graph.py`
- Bulk cosine similarity computation
- Typed edge insertion (195K untyped → typed)

### 4. LoCoMo Production Validation 🚧
**Target**: 78% accuracy (vs Letta 74% baseline)

**Blockers Resolved**:
- ✅ V17 enables batch embedding in ~4 seconds
- ✅ H003 available for sustained throughput
- ✅ Hybrid search deployed

**Validation Plan**:
1. Embed 4,726 memories with V17
2. Run LoCoMo questions through hybrid search
3. Measure answer relevance accuracy
4. Report: `reports/locomo_v17_validation.md`

---

## 📋 v17 Release Checklist

### Phase 1: Foundation (Week 1)
- [ ] Validate H003 in production (optional, V17 sufficient)
- [ ] Run LoCoMo accuracy benchmark
- [ ] Document V17 + H003 performance characteristics

### Phase 2: Graph Intelligence (Week 2-3)
- [ ] Implement semantic edge mining
- [ ] Reconstruct graph with 50K semantic edges
- [ ] Type 195K untyped associations
- [ ] Validate community detection on new graph

### Phase 3: Production Hardening (Week 4)
- [ ] Stress test at 10K+ concurrent
- [ ] Memory profiling for long-running instances
- [ ] Documentation and examples
- [ ] v17.0.0 release tag

---

## 🏗️ Architecture Decisions

### V17 vs H003 Usage
```python
# Default: V17 Python (1,216/sec, simpler, no Rust build)
optimizer = V17EmbeddingOptimizer(engine)

# High-throughput: H003 Rust (2,500-3,500/sec)
optimizer = V17EmbeddingOptimizer(
    engine,
    use_rust_onnx=True  # Requires compiled binary
)
```

### When to Use H003
- Batch processing >10K memories
- Sustained throughput requirement >1,000/sec
- GPU available for further acceleration
- Rust binary pre-compiled and available

### When V17 is Sufficient
- Standard operations (<10K embeddings)
- Simplicity preferred over raw speed
- Rust build environment not available
- Current 1,216/sec meets requirements

---

## 📊 Success Metrics

| Metric | v16 | v17 Target | Measurement |
|--------|-----|-----------|-------------|
| Embedding throughput | 4/sec | 1,216-3,500/sec | `benchmark_v17.py` |
| Vector search latency | N/A | <50ms p99 | Locust test |
| LoCoMo accuracy | N/A | ≥78% | `eval/locomo_benchmark.py` |
| Semantic edges | 0 | 50,000 | Graph query |
| Typed associations | 29K | 224K | DB count |

---

## 🔄 Integration with Deferred Work

### Campaign 9: Archaeological Implementation
**Status**: Ready to wire  
**Dependencies**: V17 batch embedding ✅  
**Action**: Activate buried features with semantic search

### Campaign 10: Rust Acceleration Expansion
**Status**: H003 complete, 88 hot paths remain  
**Priority**: Lower (V17 Python already fast)

### Campaign 11: Iceoryx2 Integration
**Status**: Pending  
**Use Case**: Distributed embedding pipeline (multi-node)

### Campaign 12: Graph Reconstruction
**Status**: Planned for v17 Phase 2  
**Scope**: 50K clones → semantic edges

---

## 📝 Documentation Plan

1. `docs/v17_embedding_guide.md` — V17 usage and tuning
2. `docs/h003_onnx_setup.md` — Rust ONNX compilation
3. `docs/hybrid_search_guide.md` — H002 deployment
4. `docs/semantic_graph.md` — Graph reconstruction
5. `CHANGELOG_v17.md` — Release notes

---

## 🎯 v17 Definition of Done

- [ ] LoCoMo 78% accuracy validated
- [ ] Semantic graph reconstruction complete
- [ ] All 224K associations typed
- [ ] Production deployment guide published
- [ ] v17.0.0 tagged and released

---

*Roadmap Version: 2026-02-18*  
*Status: v16 complete, v17 planning active*
