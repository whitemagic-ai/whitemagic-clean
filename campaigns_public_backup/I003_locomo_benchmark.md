---
name: LoCoMo Accuracy Benchmark
codename: I003
army: alpha
type: consensus_vote
priority: 5
clone_count: 10000
strategies: [analytical, chain_of_thought, synthesis]
category: intelligence
phase: intelligence
source: "NEXT_SESSION_CLONE_ARMIES_V2.md Campaign 5"
---

# LoCoMo Accuracy Benchmark

## Objective
Honestly benchmark WhiteMagic's memory retrieval accuracy against the
LoCoMo (Long Context Memory) benchmark. Competitors:
- Mem0: 68.5%
- Letta: 74.0%
- OpenAI: 63.8%

We need to know where WhiteMagic stands. No cherry-picking, no excuses.
If we're behind, identify exactly why and what to fix.

## Victory Conditions
- [ ] LoCoMo dataset downloaded and loaded into test harness
- [ ] Evaluation harness implemented covering all LoCoMo question types
- [ ] Single-hop recall accuracy measured and reported
- [ ] Multi-hop recall accuracy measured and reported
- [ ] Temporal recall accuracy measured and reported
- [ ] Open-domain recall accuracy measured and reported
- [ ] Overall accuracy computed with breakdown by question type
- [ ] Failure mode analysis: WHERE and WHY does WhiteMagic miss?
- [ ] Strategy comparison: FTS vs vector vs hybrid vs graph walk accuracy
- [ ] Results published in reports/locomo_benchmark.md with honest numbers
- [ ] If below 74% (Letta), concrete improvement plan with expected lift per fix

## Targets
| File | Line | Type |
|------|------|------|
| eval/run_eval.py | * | evaluation harness |
| whitemagic/core/memory/unified.py | * | retrieval pipeline |
| whitemagic/core/memory/sqlite_backend.py | * | FTS search |
| whitemagic/core/memory/embeddings.py | * | vector search |
| whitemagic/core/memory/graph_engine.py | * | graph walk |

## Strategy
1. Download LoCoMo benchmark dataset
2. Implement eval harness that stores conversation history as memories
3. For each test question, retrieve context using each strategy
4. Compare retrieved context against ground truth
5. Deploy 10K clones per strategy: each evaluates accuracy independently
6. Compute per-question-type accuracy for each retrieval strategy
7. Identify best strategy per question type
8. Analyze failure modes: what queries fail and why?
9. Generate improvement recommendations with expected accuracy lift

## Verification
Reproducible benchmark results with clear methodology.
Numbers are honest — no cherry-picking or favorable sampling.
