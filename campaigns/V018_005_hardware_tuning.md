# Campaign V018-005: Hardware Tuning & Optimization

**Campaign Codename**: METALLURGY  
**Objective**: GPU batching, SIMD lane optimization, and Alienware x14-specific tuning for 10K+ embeds/sec  
**Estimated Impact**: 10x throughput on capable hardware | Alienware as reference platform | Benchmark standardization  
**Shadow Clone Composition**: 4 Specialist Clones + Hardware Test Node  
**Estimated Duration**: 2-3 weeks (hardware-dependent)  
**Depends On**: V018-004 (Mojo activation provides kernels to tune)  
**Priority**: P2 — Performance (hardware-limited)  

---

## Strategic Overview

**The Opportunity**: v17 achieved 1,216 embeds/sec (Python) and 2,500-3,500/sec (Rust ONNX). The Alienware x14 has:
- Intel Core i7 (AVX512 capable)
- NVIDIA RTX 3060 Laptop GPU (6GB VRAM)
- 16-32GB DDR5 RAM

**Target**: 10,000+ embeddings/second on GPU-enabled systems.

**Current Bottlenecks**:
1. CPU-only embedding (no GPU batching)
2. Single-threaded Python for batch prep
3. No SIMD lane optimization per architecture
4. No hardware capability detection

**The Strategy**:
1. **GPU Batching**: CUDA kernels for BGE embeddings (batch_size=128+)
2. **SIMD Tuning**: AVX512 vs AVX2 vs NEON detection + kernel selection
3. **Alienware Baseline**: Establish x14 as reference performance platform
4. **Auto-Detection**: Runtime hardware capability → optimal code path

---

## Victory Conditions (VCs)

### VC-1: Hardware Capability Detection (Priority: CRITICAL)
**Objective**: Build runtime detector for CPU/GPU capabilities  
**Success Metrics**:
- [ ] Create `whitemagic/core/acceleration/hardware_probe.py`:
  - CPU: AVX512, AVX2, SSE4.2, NEON (ARM), lane width
  - GPU: CUDA available, VRAM size, compute capability
  - RAM: Total, available, bandwidth estimate
- [ ] Cache detection results in `~/.whitemagic/cache/hardware_profile.json`
- [ ] Detection time <100ms (cached after first run)
- [ ] CLI tool: `scripts/wm hardware-profile` displays capabilities
- [ ] Handle headless environments (no GPU)

**Clone Assignment**: METAL-LEAD-01 (Hardware specialist)

### VC-2: GPU Embedding Pipeline (Priority: CRITICAL)
**Objective**: CUDA batching for BGE embeddings on NVIDIA GPUs  
**Success Metrics**:
- [ ] Extend `v17_embedding_optimizer.py` with GPU path:
  - `use_gpu=True` parameter
  - `batch_size_gpu=128` (vs 32 for CPU)
  - CUDA kernel for BGE forward pass (ONNX Runtime GPU provider)
- [ ] Graceful fallback: GPU OOM → CPU batching
- [ ] Benchmark target: 10,000+ embeds/sec on RTX 3060
- [ ] Memory management: VRAM usage <4GB (leave headroom)
- [ ] Test on Alienware x14 as reference platform

**Clone Assignment**: METAL-SPEC-01 (CUDA engineer)

### VC-3: SIMD Lane Optimization (Priority: HIGH)
**Objective**: Auto-select optimal SIMD width per CPU  
**Success Metrics**:
- [ ] Extend Zig bridge: `simd.batch_cosine(lane_width=auto)`:
  - AVX512 systems: lane_width=16 (512-bit)
  - AVX2 systems: lane_width=8 (256-bit)
  - SSE4.2: lane_width=4 (128-bit)
  - Fallback: lane_width=1 (scalar)
- [ ] Extend Mojo bridge: similar lane detection
- [ ] Benchmark each lane width on target hardware
- [ ] Per-operation optimal width stored in `hardware_profile.json`
- [ ] Speedup: AVX512 vs scalar = 8-16x on graph operations

**Clone Assignment**: METAL-SPEC-02 (SIMD specialist)

### VC-4: Alienware x14 Reference Platform (Priority: HIGH)
**Objective**: Establish x14 as standardized benchmark platform  
**Success Metrics**:
- [ ] Document x14 specs as "WhiteMagic Reference Platform v1"
- [ ] Create `benchmarks/reference_alienware_x14.json` with:
  - CPU: Intel Core i7-12700H (14 cores, 20 threads)
  - GPU: NVIDIA RTX 3060 Laptop 6GB
  - RAM: 32GB DDR5-4800
- [ ] Run full benchmark gauntlet on x14
- [ ] Store baseline scores for regression testing
- [ ] Future hardware compared against x14 (% faster/slower)

**Clone Assignment**: METAL-SPEC-03 (Benchmarking)

### VC-5: Multi-Hardware Testing (Priority: MEDIUM)
**Objective**: Validate tuning across diverse hardware  
**Success Metrics**:
- [ ] Test matrix:
  | Hardware | CPU | GPU | Expected Embed/sec |
  |----------|-----|-----|-------------------|
  | Alienware x14 | i7-12700H | RTX 3060 | 10,000+ |
  | Dual laptop (current) | ? | None | 1,200+ |
  | Cloud GPU (future) | ? | A100 | 50,000+ |
- [ ] Performance regression detection (CI simulates x14 profile)
- [ ] Graceful degradation: unknown hardware → safe defaults
- [ ] Report: `reports/v018_hardware_compatibility.md`

**Clone Assignment**: METAL-SPEC-04 (QA/DevOps)

---

## Alienware x14 Specific Tuning

**Target Configuration**:
```python
# Alienware x14 optimal settings
HARDWARE_PROFILE = {
    "platform": "alienware_x14_v1",
    "embedding": {
        "backend": "cuda_onnx",
        "batch_size": 128,
        "workers": 4,  # Leave cores for OS/other apps
    },
    "simd": {
        "lane_width": 16,  # AVX512
        "backend": "mojo",  # If available, else zig
    },
    "graph": {
        "parallel_walks": 8,
        "cache_size_mb": 512,  # Use that DDR5 bandwidth
    }
}
```

**Expected Performance**:
| Metric | v17 Baseline | v18 Target (x14) | Speedup |
|--------|--------------|------------------|---------|
| Embeddings/sec | 1,216 | 10,000+ | 8.2x |
| Graph walk latency | 2.3s | <1s | 2.3x |
| Batch search (100 queries) | 500ms | <100ms | 5x |
| Dream cycle (8 phases) | 30s | <10s | 3x |

---

## Risk Assessment

| Risk | Mitigation |
|------|------------|
| Alienware not available for testing | Document dual laptop as secondary reference |
| CUDA setup complexity | Provide `scripts/setup_cuda.py` automation |
| GPU memory fragmentation | Implement batch size auto-tuning |
| Thermal throttling on laptops | Monitor temps, scale back if needed |

---

## Dependencies on Other Campaigns

- **V018-004 (Mojo Activation)**: Provides kernels to tune with SIMD
- **V018-003 (Test Coverage)**: Hardware detection needs tests
- **V018-001/002 (Cleanup)**: Removes noise before profiling

---

*Campaign METALLURGY — v18 Performance Phase*
