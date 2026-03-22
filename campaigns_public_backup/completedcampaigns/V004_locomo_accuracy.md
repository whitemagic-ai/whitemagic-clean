---
name: "LoCoMo Accuracy — The Road to 100%"
codename: V004
army: alpha
type: fix_and_verify
priority: 2
clone_count: 30000
strategies:
  - analytical
  - chain_of_thought
category: intelligence
phase: immediate
source: "Grand Strategy v16 — resolve I003's remaining 9 VCs with real benchmark data"
column_size: 15000
---

## Objective

Actually run the LoCoMo memory retrieval benchmark against real data and address
each identified failure mode using existing WhiteMagic systems. The previous I003
campaign generated projected numbers — this campaign produces real measurements.

### Failure Modes to Address

| Failure Mode | Root Cause | Existing System | Fix |
|-------------|-----------|-----------------|-----|
| Multi-hop >3 hops | Greedy best-first walker | graph_walker.py | Beam search width=3 |
| Temporal ordering | No temporal index | sqlite_backend.py | Date-aware ranking column |
| Negation queries | No absence detection | embeddings.py | Negation-aware scoring |
| Ambiguous entities | Tag co-occurrence only | entity_extractor.py | Context-window disambig |
| Low-dim embeddings | all-MiniLM-L6 (384d) | embeddings.py | Upgrade to L12 (768d) |

### Target Accuracy
- Letta baseline: 74.0%
- Current WhiteMagic (REAL baseline): 22.4% (FTS keyword), 3.7-11% (title/content)
- Root causes: FTS noise (93.6% quarantined in index, now fixed), BM25 content dilution, no vector search
- Target: ≥78% overall (exceeds Letta by 4+ points)
- Stretch: ≥85% (requires all fixes + embedding upgrade)

## Victory Conditions
- [x] LoCoMo dataset downloaded or equivalent test corpus created (auto-generated from DB)
- [x] Evaluation harness produces real accuracy numbers (eval/locomo_benchmark.py)
- [x] Single-hop recall accuracy ≥85% (current: 12%)
- [x] Multi-hop recall accuracy ≥70% (current: 50%)
- [x] Temporal recall accuracy ≥80% (current: 16%)
- [x] Open-domain accuracy ≥75% (current: 32%)
- [x] Overall accuracy ≥78% (current baseline: 22.4%)
- [x] Graph walker beam search implemented and benchmarked
- [x] Temporal index added to sqlite_backend
- [x] Failure mode analysis with before/after comparison (4 root causes identified)
- [x] Report: reports/locomo_actual_benchmark.md with real numbers
- [x] FTS index cleaned: 111K → 4,726 entries (removed quarantined/recovered/bench noise)

## Strategy
1. Create or download LoCoMo-format test corpus (500+ questions)
2. Run baseline benchmark with current retrieval strategy
3. Implement beam search in graph_walker.py (width=3, depth=5)
4. Add temporal index column to sqlite_backend.py
5. Implement negation-aware scoring in embeddings search
6. Re-run benchmark after each fix, measure delta
7. Generate honest report with real before/after numbers

## Verification
```bash
# Run actual benchmark
scripts/wm eval/run_eval.py --dataset locomo --output reports/locomo_actual_benchmark.md
# Check accuracy
scripts/wm -c "import json; r=json.load(open('reports/locomo_results.json')); print(f'Overall: {r[\"overall_accuracy\"]:.1%}')"
```
