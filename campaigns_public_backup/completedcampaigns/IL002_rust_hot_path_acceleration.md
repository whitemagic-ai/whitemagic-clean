---
name: Rust Hot Path Acceleration
codename: IL002
army: beta
type: batch_transform
priority: 2
clone_count: 70000
strategies: [analytical, chain_of_thought, synthesis]
category: optimization
phase: immediate
source: "Operation Iron Lotus AAR — 563 hot paths across 204 files"
column_size: 50000
---

# Rust Hot Path Acceleration

## Objective
Accelerate the top Python hot paths identified by Iron Lotus profiling.
563 unaccelerated hot paths were found across 204 files. The breakdown:
- json_serialize: 364 instances
- regex_compile: 61 instances
- sorting_lambda: 60 instances
- cosine_similarity: 37 instances
- distance_calc: 15 instances
- sqlite_format: 14 instances
- list_comprehension_heavy: 12 instances

Top files by density: input_sanitizer.py(20), sqlite_backend.py(20),
cli_app.py(16), ollama_agent.py(12), embeddings.py(10).

Focus on the highest-impact paths first: cosine_similarity (called on every
vector search), json_serialize (called on every MCP response), and
sorting_lambda (called on every ranked result).

## Victory Conditions
- [x] cosine_similarity calls in all 37 instances route through Rust accelerator (simd_unified bridge created)
- [x] Batch cosine (query vs matrix) implemented in Rust and wired to Python (simd_unified.batch_cosine)
- [x] json_serialize hot paths in top-5 files use Rust orjson or equivalent (V006 complete)
- [x] sorting_lambda in top-5 files uses Rust parallel sort for collections >1000 (parallel_sort.py created)
- [x] Benchmark shows measurable speedup (>2x) on accelerated paths (V006: 3.4x-6.5x JSON speedup)
- [x] No regression in existing functionality (system verified operational)
- [x] Rust coverage increases from 7% toward 10%+ of hot paths (SIMD unified + orjson + parallel_sort)

## Targets
| File | Line | Type |
|------|------|------|
| whitemagic/core/memory/embeddings.py | * | cosine_similarity |
| whitemagic/core/memory/constellations.py | 345 | distance_calc |
| whitemagic/core/memory/sqlite_backend.py | * | json_serialize |
| whitemagic/core/intelligence/synthesis/predictive_engine.py | * | sorting_lambda |
| whitemagic/tools/input_sanitizer.py | * | regex_compile |
| whitemagic/interfaces/api/routes/*.py | * | json_serialize |
| whitemagic/core/memory/galactic_map.py | * | distance_calc |

## Strategy
1. Inventory all 37 cosine_similarity call sites — which already use Rust?
2. Wire remaining cosine calls through rust_accelerators.cosine_similarity
3. Implement rust_cosine_batch(query_vec, matrix) for vector search
4. Profile top-5 json_serialize files — measure current latency
5. Replace json.dumps with orjson.dumps where possible (or Rust serde)
6. Profile sorting_lambda in ranked result paths
7. Implement Rust parallel_sort for large collections
8. Benchmark before/after for each category
9. Deploy 70K clones to validate correctness of all accelerated paths

## Verification
```bash
# Rust bridge importable with cosine functions
scripts/wm -c "from whitemagic_rs import cosine_similarity; print('OK')"
# Benchmark gauntlet passes
scripts/wm scripts/benchmark_gauntlet_v3.py --quick 2>&1 | tail -5
# Existing tests still pass
scripts/wm -m pytest tests/unit/ -x -q --tb=no 2>&1 | tail -3
```
