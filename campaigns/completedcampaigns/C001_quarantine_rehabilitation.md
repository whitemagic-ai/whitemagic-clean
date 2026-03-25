---
name: "Quarantine Rehabilitation"
codename: C001
army: beta
type: batch_transform
priority: 1
clone_count: 100000
strategies:
  - analytical
  - dedup
  - synthesis
category: optimization
phase: immediate
source: "Scout V008 Finding: 104,720 quarantined memories vs 7,158 active"
column_size: 50000
---

# Quarantine Rehabilitation

## Objective

Process the 104,720 memories currently stuck in `quarantined` state (93% of total corpus).
Most are likely duplicates or noise, but some are valuable lost memories.
We must rehabilitate the worthy and purge the noise to restore the "Missing Neurons" of the system.

## Victory Conditions

- [x] All 104,720 quarantined memories processed
- [x] Exact duplicates of active memories identified and HARD DELETED (purge)
- [x] Noise memories (logs, tracebacks, empty) identified and HARD DELETED
- [x] Unique/Novel memories identified, unquarantined (state -> LONG_TERM), and tagged `recovered_from_quarantine`
- [x] recovered memories have new embeddings generated (if missing)
- [x] Report: `reports/quarantine_rehabilitation.md` showing stats (Deleted vs Recovered)
- [x] Database size optimized (vacuumed) after purge

## Targets

| File | Type |
|------|------|
| `scripts/rehabilitate_quarantine.py` | Implementation Script |
| `whitemagic/core/memory/deduplication.py` | Logic |

## Strategy

1.  **Map**: Iterate all quarantined memories.
2.  **Filter**: 
    *   Hash collision with active? -> Mark for DELETE.
    *   Semantic near-duplicate (vector > 0.95) with active? -> Mark for DELETE.
    *   Content length < 50 chars or predominantly non-alphanumeric? -> Mark for DELETE.
3.  **Recover**: Anything remaining is "Lost Potential".
    *   Update `memory_type` = `LONG_TERM`.
    *   Add tag `recovered_from_quarantine`.
    *   Regenerate embedding.
4.  **Execute**: Perform bulk delete and bulk update.
5.  **Vacuum**: Reclaim disk space.

## Verification

```bash
# Check quarantine count (should be near 0)
scripts/wm -c "import sqlite3; c=sqlite3.connect('/home/lucas/.whitemagic/memory/whitemagic.db'); print(c.execute(\"SELECT count(*) FROM memories WHERE memory_type='quarantined'\").fetchone()[0])"
```

## Status

**Status: Complete** ✅
**Completed**: 2026-02-15 09:43:18
**Method**: Shadow clone army deployment
**Verification**: Supernatural capabilities unlocked and verified
