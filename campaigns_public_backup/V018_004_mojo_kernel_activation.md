# Campaign V018-004: Mojo Kernel Activation Initiative

**Campaign Codename**: ALCHEMY  
**Objective**: Wire high-value Mojo kernels from modular/max to Python bridges for hot path acceleration  
**Estimated Impact**: 100K+ Mojo LOC activated | 50x speedup on MAX kernels | Python ↓ to ~12%  
**Shadow Clone Composition**: 7 Specialist Clones  
**Estimated Duration**: 4-6 weeks (kernel audit + bridge building)  
**Depends On**: V018-001, V018-002 (clean codebase first)  
**Priority**: P1 — Performance  

---

## Strategic Overview

**The Opportunity**: 563,346 LOC of Mojo exists in `modular/max/kernels/` — but it's largely dormant. The modular directory contains:
- **Generated kernels** (auto-tuned variants for different architectures)
- **Hand-written kernels** (expert-optimized for specific operations)
- **Benchmark kernels** (performance testing)
- **Demos** (educational, not production)

**Current State**:
- Mojo files: 2,371 files
- Mojo LOC: 563,346 (44.7% of total codebase)
- Active in hot paths: ~500 LOC (embedding bridges)
- Waste: 99.9% of Mojo code is dark matter

**The Goal**: Activate 100K+ LOC of high-value kernels:
1. **Audit**: Separate generated noise from hand-written gems
2. **Benchmark**: Find kernels that beat NumPy/Rust equivalents
3. **Bridge**: Build Python→Mojo FFI for activated kernels
4. **Wire**: Replace Python hot paths with Mojo calls

**Target Hot Paths**:
| Operation | Current | Mojo Target | Expected Speedup |
|-----------|---------|-------------|-------------------|
| Batch embedding (384d) | NumPy 0.005ms | Mojo MAX kernel | 50-100x |
| Cosine similarity (batch) | Rust 0.002ms | Mojo SIMD | 20-50x |
| Matrix multiply (small) | NumPy | Mojo GEMM | 100x |
| Tokenization | Python regex | Mojo Aho-Corasick | 500x |

---

## Victory Conditions (VCs)

### VC-1: Kernel Audit & Classification (Priority: CRITICAL)
**Objective**: Categorize all 2,371 Mojo files by value  
**Success Metrics**:
- [ ] Scan `modular/max/kernels/` for:
  - Hand-written vs auto-generated (heuristic: complexity, comments)
  - Benchmark scores (from embedded benchmark code)
  - Architecture specificity (generic vs AVX512 vs CUDA)
- [ ] Classify into:
  - **TIER_1**: Production-ready, benchmarks show 10x+ speedup (target: 50 files)
  - **TIER_2**: Good but niche use case (target: 200 files)
  - **TIER_3**: Generated noise, duplicates, demos (archive: 2,100 files)
- [ ] Generate kernel catalog: `reports/v018_mojo_kernel_catalog.json`
- [ ] Flag top 20 kernels for immediate activation

**Clone Assignment**: ALCH-LEAD-01 + ALCH-SPEC-01 (Audit team)

### VC-2: TIER_1 Kernel Benchmarking (Priority: CRITICAL)
**Objective**: Validate TIER_1 kernels against current implementations  
**Success Metrics**:
- [ ] For each TIER_1 kernel: build standalone benchmark
- [ ] Compare against:
  - Current Python implementation
  - Rust alternative (if exists)
  - NumPy baseline
- [ ] Verify speedup claims (minimum 10x to qualify)
- [ ] Document: `reports/v018_mojo_benchmarks.md`
- [ ] Flag any kernels that fail validation (demote to TIER_2)

**Clone Assignment**: ALCH-SPEC-02 (Benchmarking)

### VC-3: Python→Mojo Bridge Infrastructure (Priority: CRITICAL)
**Objective**: Build robust FFI bridge for calling Mojo from Python  
**Success Metrics**:
- [ ] Extend `whitemagic/core/acceleration/mojo_bridge.py`:
  - C API wrapper for compiled Mojo shared libraries
  - NumPy array → Mojo Tensor zero-copy where possible
  - Error handling (Mojo exceptions → Python)
  - Async support (Mojo async → Python asyncio)
- [ ] Create `scripts/compile_mojo_kernel.py`:
  - Compiles .mojo → .so
  - Caches compiled artifacts
  - Version tracking (recompile on source change)
- [ ] Bridge overhead <0.1ms per call (acceptable for batch ops)

**Clone Assignment**: ALCH-SPEC-03 (Bridge engineer)

### VC-4: Hot Path Replacement — Batch Embeddings (Priority: HIGH)
**Objective**: Replace Python embedding batch with Mojo kernel  
**Success Metrics**:
- [ ] Identify: `whitemagic/core/memory/embeddings.py` hot path
- [ ] Activate Mojo kernel: `modular/max/kernels/embedding_batch_*.mojo`
- [ ] Feature flag: `USE_MOJO_EMBEDDINGS` (default False in v18.0.0)
- [ ] Benchmark: match or exceed V17 1,216/sec throughput
- [ ] Fallback: seamless to Python if Mojo unavailable
- [ ] Ship as experimental in v18.0.0, stable in v18.1.0

**Clone Assignment**: ALCH-SPEC-04 (Embedding integration)

### VC-5: Hot Path Replacement — Graph Operations (Priority: HIGH)
**Objective**: Replace graph similarity with Mojo SIMD kernels  
**Success Metrics**:
- [ ] Target: `core/intelligence/graph_walker.py` `_transition_score()`
- [ ] Activate Mojo: cosine similarity batch, PageRank vectorized
- [ ] Compare against Zig SIMD bridge (competition!)
- [ ] Feature flag: `USE_MOJO_GRAPH`
- [ ] Benchmark: graph walk latency reduction 50%+

**Clone Assignment**: ALCH-SPEC-05 (Graph integration)

### VC-6: Kernel Archive Cleanup (Priority: MEDIUM)
**Objective**: Move TIER_3 (noise) to archive, reduce repo bloat  
**Success Metrics**:
- [ ] Move 2,100 TIER_3 files to `_archives/mojo_generated_kernels/`
- [ ] Preserve TIER_1/TIER_2 in `modular/max/kernels/`
- [ ] Update `.gitattributes` for archive handling
- [ ] Reduce clone time for new developers
- [ ] Update documentation: what's active vs archived

**Clone Assignment**: ALCH-SPEC-06 (Cleanup)

### VC-7: Mojo Documentation & Examples (Priority: MEDIUM)
**Objective**: Document how to add new Mojo kernels  
**Success Metrics**:
- [ ] Guide: `docs/MOJO_KERNEL_DEVELOPMENT.md`
- [ ] Example: adding custom embedding kernel
- [ ] Example: adding custom matrix operation
- [ ] Template: `templates/mojo_kernel_template.mojo`
- [ ] Troubleshooting: common FFI issues

**Clone Assignment**: ALCH-SPEC-07 (Docs)

---

## Risk Assessment

**Technical Risks**:
| Risk | Likelihood | Mitigation |
|------|------------|------------|
| Mojo API instability | High | Pin to specific `magic` CLI version |
| Compilation failures | Medium | Fallback to NumPy/Rust always available |
| NumPy interop overhead | Medium | Benchmark before/after, measure total latency |
| Kernel quality varies | High | Strict TIER_1 criteria, benchmark validation |

**Fallback Strategy**:
- Every Mojo hot path has Python implementation
- Feature flags default to Python (opt-in for Mojo)
- Runtime detection: `has_mojo = check_compiled_kernels_available()`

---

## Success Metrics

**v18.0.0**:
- TIER_1 kernels identified and benchmarked: 50
- Bridges built: 2 (embeddings, graph)
- Mojo LOC active: 10,000

**v18.1.0**:
- Mojo hot paths: 5
- Mojo LOC active: 50,000
- Speedup vs Python: 10x average

---

*Campaign ALCHEMY — v18 Performance Phase*
