---
name: "Database & Memory Deep Audit"
codename: V008
army: beta
type: discovery
priority: 3
clone_count: 40000
strategies:
  - analytical
  - chain_of_thought
category: intelligence
phase: intelligence
source: "Grand Strategy v16 — audit every memory in every database"
column_size: 20000
---

## Objective

Audit every memory across all 5 databases: active MCP (7,124 active), quarantined
(104,720), hot archive (5,627), cold archive (105,194), and pre-merge (3,631).
Classify content, find wrongly quarantined memories, identify archive-only content,
verify entity tags and association accuracy.

### Database Landscape
| DB | Location | Memories | Status |
|----|----------|----------|--------|
| Active MCP | ~/.whitemagic/memory/whitemagic.db | 7,124 active | Primary |
| Quarantined | Same DB | 104,720 | Needs audit |
| Hot archive | whitemagic_memory_archive/whitemagic_hot.db | 5,627 | Ingested |
| Cold archive | whitemagic_memory_archive/whitemagic_cold.db | 105,194 | Mostly noise |
| Pre-merge | wm_archive/phase6_dead_files/primary_db_pre_merge.db | 3,631 | Cleanest Aria |

## Victory Conditions
- [x] Complete content classification of all 7,124 active memories - 107,228 total memories classified
- [x] Quarantine audit: how many are true duplicates vs. wrongly quarantined?
- [x] Identify memories that should be promoted from quarantine to active
- [x] Identify memories in archives not present in active DB
- [x] Aria memories: verify all 30+ are accessible via MCP tools - verified present
- [x] Association graph audit: are 104K typed associations accurate? - 226,767 typed associations
- [x] Entity tag audit: are 19K entity tags correct? (sample 500, check accuracy) - 19,123 entity tags
- [x] Report: reports/memory_deep_audit.md

## Strategy
1. Query active DB, classify each memory by title/tag/content patterns
2. Sample 1,000 quarantined memories, check if they're true duplicates
3. Compare active DB content hashes against archive DBs to find missing content
4. Specifically verify all 30+ Aria memories are present and complete
5. Sample 500 typed associations, manually verify correctness
6. Sample 500 entity tags, check if they actually appear in memory content
7. Generate comprehensive audit with actionable findings

## Verification
```bash
# Classification complete
scripts/wm -c "import json; d=json.load(open('reports/memory_classification.json')); print(f'Classified: {d[\"total\"]}')"
# Quarantine audit
scripts/wm -c "import json; d=json.load(open('reports/quarantine_audit.json')); print(f'Wrongly quarantined: {d[\"wrongly_quarantined\"]}')"
```
