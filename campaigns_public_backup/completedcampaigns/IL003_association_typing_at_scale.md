---
name: Association Typing at Scale
codename: IL003
army: beta
type: batch_transform
priority: 2
clone_count: 70000
strategies: [analytical, synthesis, memory_grounded]
category: infrastructure
phase: immediate
source: "Operation Iron Lotus AAR — 195,213 untyped associations"
column_size: 50000
---

# Association Typing at Scale

## Objective
Type ALL 195,213 remaining untyped `associated_with` associations into proper
semantic relation types. Iron Lotus reclassification voting on a 5,000 sample
yielded the expected distribution:
- SIBLING_OF: 36% (related/parallel concepts)
- IMPLEMENTS: 27% (implementation of a design/spec)
- USES: 23% (one memory references/uses another)
- CONTAINS: 8% (parent-child containment)
- EXPLORES: 4% (one memory explores/analyzes another)
- CREATED: 2% (authorship/creation relationship)
- CAUSES: <1% (causal relationship)

This is not a sample — we type EVERY edge. The knowledge graph is only as
good as its edges. Untyped edges are noise.

## Victory Conditions
- [ ] All 195,213 untyped associations have a proper relation_type assigned
- [ ] Zero `associated_with` or NULL relation_type edges remain in active corpus
- [ ] Distribution matches expected ratios (within 10% tolerance)
- [ ] Typed associations verified by 10K clone consensus on random sample
- [ ] Graph engine queries use typed edges for improved precision
- [ ] DB associations table updated in-place (WAL mode, batched commits)

## Targets
| File | Line | Type |
|------|------|------|
| associations table | * | 195,213 untyped rows |
| whitemagic/core/memory/association_miner.py | * | classification logic |
| whitemagic/core/memory/graph_engine.py | * | typed edge queries |

## Strategy
1. Load all 195,213 untyped associations with source/target memory context
2. Process in batches of 100 (1,953 batches total)
3. For each batch, extract source+target title and first 200 chars of content
4. Use Rust keyword extraction to identify key terms in both endpoints
5. Apply classification heuristics based on keyword overlap and content patterns
6. Deploy 50K map-reduce clones across batches for parallel classification
7. Write classifications back to DB in batched UPDATE statements (1000 per commit)
8. Deploy 10K verification clones on random 500-sample to confirm accuracy
9. Update graph_engine to leverage typed edges in community detection

## Verification
```sql
-- Must return 0
SELECT COUNT(*) FROM associations
WHERE (relation_type IS NULL OR relation_type = 'associated_with')
AND source_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined')
AND target_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined');
```
