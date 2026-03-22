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
- [ ] cosine_similarity calls in all 37 instances route through Rust accelerator
- [ ] Batch cosine (query vs matrix) implemented in Rust and wired to Python
- [ ] json_serialize hot paths in top-5 files use Rust orjson or equivalent
- [ ] sorting_lambda in top-5 files uses Rust parallel sort for collections >1000
- [ ] Benchmark shows measurable speedup (>2x) on accelerated paths
- [ ] No regression in existing functionality
- [ ] Rust coverage increases from 7% toward 10%+ of hot paths

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
Run benchmark gauntlet comparing before/after on accelerated paths.
All existing tests must pass. New benchmarks added for each Rust path.
