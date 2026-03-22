---
name: Real Benchmark Harness
codename: PSR-022
army: alpha
type: fix_and_verify
priority: P1
clone_count: 10000
strategies: [verification, measurement, ci]
category: quality
phase: immediate
source: consensus_council_100m
column_size: 2
---

## Objective

Replace all simulated speedup numbers with real measurements.

**Current state**: `benchmark_harness.py` generates fake speedup numbers. Python callers don't use Rust.
**Target state**: `maturin develop` + `cargo bench` in CI gives real Python↔Rust speedup measurements.

The Red Team faction of the 100M Consensus Council was **unanimous**: without real measurements, all speedup claims are marketing. This is the **prerequisite for all other performance claims**.

Red Team top finding: "39 Rust files are scaffolding, not migrations — Python originals still run."

## Victory Conditions

- [ ] `maturin develop --release` completes without errors
- [ ] `python3 -c "import whitemagic_rs; print(whitemagic_rs.__version__)"` works
- [ ] At least 3 Python functions replaced by Rust equivalents (not just parallel Python)
- [ ] `scripts/benchmark_real.py` measures actual Python vs Rust timing for each replacement
- [ ] Speedup measurements are real (not simulated): Python time / Rust time
- [ ] `cargo bench` runs at least 5 benchmarks with real timing
- [ ] CI pre-commit hook runs `maturin develop` before tests
- [ ] Benchmark results stored in `reports/benchmark_real_YYYYMMDD.json`
- [ ] Any speedup claim in campaign docs has a corresponding real measurement
- [ ] `@rust_accelerated` decorator created: tries Rust, falls back to Python

## Targets

| Python Function | Rust Replacement | Expected Speedup |
|----------------|-----------------|-----------------|
| `VectorIndex.search()` | `vector_search::VectorIndex` | 10-20× |
| `AssociationMiner.mine()` | `association_miner_v2::PyAssociationMinerV2` | 5-15× |
| `BM25.score()` | `bm25::BM25Index` | 5-10× |
| `unified.py memory ops` | `memory::unified_v2` | 20-50× |
| `db_manager.py queries` | `db_manager::PyDbManager` | 10-25× |

## Strategy

1. Run `maturin develop --release` in whitemagic-rust/
2. Create `scripts/benchmark_real.py` — imports both Python and Rust versions, times each
3. For each target: call Python version 1000×, call Rust version 1000×, report ratio
4. Create `@rust_accelerated` decorator in `whitemagic/utils/rust_bridge.py`
5. Wire 3 Python callers to use Rust: start with `vector_search`, `bm25`, `association_miner`
6. Add `cargo bench` with criterion benchmarks for the same functions
7. Add pre-commit hook: `echo "maturin develop" >> .git/hooks/pre-commit`

## Verification

```bash
# Step 1: Build
cd whitemagic-rust && maturin develop --release

# Step 2: Verify import
python3 -c "import whitemagic_rs; print('Version:', whitemagic_rs.__version__)"

# Step 3: Real benchmark
python3 scripts/benchmark_real.py --functions vector_search,bm25,association_miner

# Step 4: Cargo bench
cd whitemagic-rust && cargo bench 2>&1 | grep "time:"

# Step 5: Verify report
cat reports/benchmark_real_*.json | python3 -c "
import json, sys
data = json.load(sys.stdin)
for name, result in data.items():
    print(f'{name}: {result[\"speedup\"]:.1f}× (Python: {result[\"python_ms\"]:.1f}ms, Rust: {result[\"rust_ms\"]:.1f}ms)')
"
```
