---
name: Polyglot Scout Migration
codename: PSR-020
army: tokio
type: fix_and_verify
priority: P1
clone_count: 100000
strategies: [parallel, rust_migration, performance]
category: performance
phase: immediate
source: consensus_council_100m
column_size: 5
---

## Objective

Migrate all Python scout scripts to Rust + Zig compiled binaries.

**Current state**: `deep_scout_deployment.py` processes 77 files/sec (Python ast module, GIL-bound).
**Target state**: `polyglot-scout` Rust binary processes 5,000+ files/sec (rayon parallel, no GIL).

The 100M Consensus Council voted this the **#1 highest-ROI action** (score: 1.9, impact: 0.95, feasibility: 0.90).

First deployment of `polyglot-scout` achieved **506 files/sec (6.6× baseline)** on whitemagic/ (746 files, 154K LOC, 1475ms).

## Victory Conditions

- [ ] `cargo run --bin polyglot-scout` compiles and runs without errors
- [ ] Scout achieves ≥500 files/sec on whitemagic/ directory (DONE: 506/sec ✅)
- [ ] Scout achieves ≥1000 files/sec on full whitemagicdev/ tree (release build)
- [ ] Scout produces structured JSON output (`--json` flag)
- [ ] Scout detects all 4 finding categories: performance, migration, quality, architecture
- [ ] Scout identifies N+1 DB query problems (DONE: 61 critical findings ✅)
- [ ] Scout identifies top migration candidates with scores (DONE: 100 candidates ✅)
- [ ] Zig SIMD variant created for pattern matching hot path
- [ ] Python `deep_scout_deployment.py` replaced by shell wrapper calling Rust binary
- [ ] Scout results feed into campaign generation pipeline

## Targets

| File | Lines | Migration Score | Speedup |
|------|-------|----------------|---------|
| fusions.py | 1346 | 0.75 | 20-50× |
| constellations.py | 1075 | 0.75 | 20-50× |
| rust_accelerators.py | 1253 | 0.65 | 10-20× |
| core_access.py | 833 | 0.75 | 20-50× |
| dream_cycle.py | 838 | 0.75 | 20-50× |
| association_miner.py | 649 | 0.75 | 20-50× |

## Strategy

1. Build release binary: `cargo build --bin polyglot-scout --features native-deps --release`
2. Benchmark release vs dev: `time ./target/release/polyglot-scout /path/to/whitemagicdev`
3. Add Zig SIMD pattern matcher for byte-level grep acceleration
4. Wire JSON output to campaign generator: `polyglot-scout --json | python3 scripts/generate_campaigns.py`
5. Replace `deep_scout_deployment.py` with thin Python wrapper calling the binary
6. Deploy on full whitemagicdev/ tree and generate PSR-025+ campaigns from findings

## Verification

```bash
# Build release
cargo build --bin polyglot-scout --features native-deps --release

# Benchmark
time ./target/release/polyglot-scout /home/lucas/Desktop/whitemagicdev/whitemagic

# JSON output
./target/release/polyglot-scout /home/lucas/Desktop/whitemagicdev/whitemagic --json | python3 -c "import json,sys; d=json.load(sys.stdin); print(f'files/sec: {d[\"files_per_sec\"]:.0f}')"
```
