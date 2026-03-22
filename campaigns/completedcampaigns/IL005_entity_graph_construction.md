---
name: Entity Graph Construction
codename: IL005
army: beta
type: batch_transform
priority: 3
clone_count: 70000
strategies: [analytical, synthesis, memory_grounded]
category: infrastructure
phase: foundation
source: "Operation Iron Lotus AAR — 10,099 entities extracted, 136 co-occurrence pairs"
column_size: 50000
---

# Entity Graph Construction

## Objective
Build a proper entity-centric knowledge graph from the 10,099 entities extracted
by Iron Lotus. Currently we have entities but no entity→memory edges in the graph.
The entity extraction found: whitemagic(16K mentions), rust(4.8K), mcp(4.7K),
python(2.2K), consciousness(2K), lucas(1.9K), aria(797).

136 entity co-occurrence pairs were found. The top relationships:
- rust ↔ whitemagic (343 co-occurrences)
- mcp ↔ whitemagic (331)
- dharma ↔ whitemagic (207)
- graph ↔ whitemagic (188)
- gana ↔ whitemagic (176)

These co-occurrences need to become proper typed edges in the association graph,
connecting the memories that mention these entities.

## Victory Conditions
- [ ] Entity extraction re-run on all 8,498 active memories with refined patterns
- [ ] Entity→memory index created (which memories mention which entities)
- [ ] Top 500 entity pairs converted to typed associations between their memories
- [ ] Entity type distribution validated: SYSTEM, CONCEPT, LANGUAGE, PERSON, MODULE
- [ ] New associations have proper types (USES, IMPLEMENTS, EXPLORES, etc.)
- [ ] Graph engine community detection re-run with entity-enriched edges
- [ ] At least 5,000 new typed associations created from entity co-occurrence
- [ ] Entity index queryable: "which memories mention Aria?" returns accurate results

## Targets
| File | Line | Type |
|------|------|------|
| whitemagic/core/memory/graph_engine.py | * | community detection |
| whitemagic/core/memory/association_miner.py | * | new entity-based mining |
| associations table | * | new entity-derived edges |
| tags table | * | entity tags on memories |

## Strategy
1. Re-run entity extraction with refined regex + Rust keyword_extract on all memories
2. Build entity→memory_id inverted index (entity X appears in memories [a, b, c])
3. For each entity pair with >5 co-occurrences, create associations between memories
4. Classify association types based on entity types (PERSON→SYSTEM = CREATED, etc.)
5. Deploy 50K map-reduce clones across entity pairs for parallel edge creation
6. Write new associations to DB in batched inserts
7. Deploy 10K verification clones to validate edge quality on random sample
8. Re-run graph engine community detection with enriched graph
9. Generate entity graph visualization data

## Verification
```sql
-- New entity-derived associations should be >5,000
SELECT COUNT(*) FROM associations
WHERE relation_type NOT IN ('associated_with', 'semantic')
AND created_at > '2026-02-13';
```
