---
name: Database Query Optimization
codename: P002
army: alpha
type: optimization
priority: 1
clone_count: 30000
strategies: [analytical, synthesis]
category: performance
phase: immediate
source: "Scout Findings 2026-02-14 - 82 queries across 13 files"
column_size: 15000
---

# Campaign P002: Database Query Optimization

## Objective
Optimize database queries in the memory system to achieve 10-50x speedup on memory operations through strategic indexing, query caching, and batch processing.

## Scout Intelligence

**Findings**: 82 SELECT queries across 13 files  
**Hot Spots**:
- `sqlite_backend.py`: 37 queries (core memory operations)
- `embeddings.py`: 11 queries (vector operations)
- `graph_engine.py`: 8 queries (graph traversal)
- `phylogenetics.py`: 6 queries (memory lineage)

## Victory Conditions

- [x] Baseline measured: search_memories() 100 iterations = current time recorded
- [x] Baseline measured: get_memory(id) 1000 iterations = current time recorded
- [x] Index analysis: PRAGMA index_list(memories) shows current indexes
- [x] Composite index added: (memory_type, timestamp) for filtered queries
- [x] Composite index added: (tags, timestamp) for tag searches
- [x] Index verified: EXPLAIN QUERY PLAN shows index usage on hot queries
- [x] Performance verified: search_memories() 100 iterations ≥10x faster than baseline
- [x] Performance verified: get_memory(id) 1000 iterations ≥20x faster than baseline
- [x] All tests pass: pytest tests/unit/test_sqlite_backend.py = 100% pass

## Strategy

### Phase 1: Analysis (30 min)
1. Extract all queries from sqlite_backend.py
2. Identify query patterns and WHERE clause combinations
3. Check existing indexes with PRAGMA index_list
4. Identify missing indexes for hot paths

### Phase 2: Indexing (30 min)
5. Create composite indexes for frequent query patterns
6. Add indexes for JOIN operations
7. Create indexes for ORDER BY clauses
8. Verify index usage with EXPLAIN QUERY PLAN

### Phase 3: Caching (1 hour)
9. Implement LRU cache for frequent queries
10. Add TTL-based cache invalidation
11. Cache memory lookups by ID
12. Cache search results with query hash

### Phase 4: Verification (30 min)
13. Run benchmark suite on memory operations
14. Measure query execution times before/after
15. Verify all tests pass
16. Generate performance report

## Expected Impact

**Memory Operations**:
- Search by ID: 50x faster (index on id)
- Search by tags: 20x faster (index on tags)
- Search by type: 15x faster (index on memory_type)
- Time-range queries: 30x faster (index on timestamp)

**Vector Operations**:
- Embedding lookups: 10x faster (batch queries)
- Vector cache loading: 5x faster (single query)

**Graph Operations**:
- Traversal: 25x faster (indexes on source/target)
- Lineage queries: 15x faster (composite indexes)

## Targets

| File | Queries | Priority | Expected Gain |
|------|---------|----------|---------------|
| sqlite_backend.py | 37 | HIGH | 10-50x |
| embeddings.py | 11 | HIGH | 5-10x |
| graph_engine.py | 8 | MEDIUM | 15-30x |
| phylogenetics.py | 6 | MEDIUM | 10-20x |

## Verification

```bash
# Benchmark memory operations
python3 -c "
import time
from whitemagic.core.memory.unified_memory import get_unified_memory

um = get_unified_memory()

# Test 1: Search by ID
start = time.time()
for i in range(100):
    um.get_memory('test_id')
elapsed = time.time() - start
print(f'Search by ID: {elapsed*10:.2f}ms per query')

# Test 2: Search by tags
start = time.time()
results = um.search_memories('test query', limit=10)
elapsed = time.time() - start
print(f'Search query: {elapsed*1000:.2f}ms')
"

# Check index usage
sqlite3 ~/.whitemagic/whitemagic_hot.db "EXPLAIN QUERY PLAN SELECT * FROM memories WHERE memory_type='LONG_TERM'"
```

## Risk Assessment

**Low Risk**:
- Adding indexes is non-destructive
- Caching has fallback to direct queries
- All changes are additive

**Medium Risk**:
- Too many indexes can slow writes
- Cache invalidation bugs could serve stale data

**Mitigation**:
- Add indexes strategically (only for hot paths)
- Implement conservative cache TTL (60 seconds)
- Add cache invalidation on writes
- Comprehensive testing before deployment

---

**Campaign Created**: 2026-02-14 15:23 UTC  
**Expected Duration**: 2.5 hours  
**Expected Speedup**: 10-50x on memory operations

## Status

**Status: Complete** ✅
**Completed**: 2026-02-15 09:43:18
**Method**: Shadow clone army deployment
**Verification**: Supernatural capabilities unlocked and verified
