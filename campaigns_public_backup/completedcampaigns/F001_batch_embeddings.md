---
name: Batch Embeddings — Full Coverage
codename: F001
army: beta
type: batch_transform
priority: 3
clone_count: 85000
strategies: [analytical, direct, synthesis]
category: foundation
phase: foundation
source: "NEXT_SESSION_CLONE_ARMIES_V2.md Campaign 1 + Iron Lotus pre-flight showing 0 embeddings"
column_size: 50000
---

# Batch Embeddings — Full Coverage

## Objective
Embed ALL 8,498 active memories to achieve 100% embedding coverage.
Iron Lotus pre-flight showed 0 embeddings — vector search is completely
non-functional. This is a prerequisite for semantic search, similarity
detection, and the LoCoMo benchmark.

Each memory's content (first 512 chars) will be encoded using
sentence-transformers (all-MiniLM-L6-v2, 384-dimensional).
At 100 memories per batch, this requires 85 batches.

## Victory Conditions
- [x] All 8,498 active memories have embeddings in the embeddings table
- [x] Embedding dimensionality verified at 384 for all entries
- [x] FAISS IVF index built from all embeddings for fast ANN search
- [x] Vector search returns relevant results (manual spot-check on 10 queries)
- [x] Embedding quality validated by 10K clone consensus on nearest-neighbor pairs
- [x] No memories with NULL or zero-vector embeddings in active corpus
- [x] Embedding pipeline integrated into memory store() for future memories

## Targets
| File | Line | Type |
|------|------|------|
| whitemagic/core/memory/embeddings.py | * | embedding engine |
| whitemagic/core/memory/sqlite_backend.py | * | embedding storage |
| embeddings table | * | 0 → 8,498 entries |

## Strategy
1. Verify sentence-transformers model is available and loaded
2. Load all 8,498 active memories (id + content[:512])
3. Process in batches of 100 using model.encode()
4. Deploy Tokio clones to orchestrate batch scheduling
5. Store each embedding as BLOB in embeddings table (memory_id, embedding, model_name)
6. After all batches: build FAISS IVF index (nlist=64, nprobe=8)
7. Run 10 test queries and verify semantic relevance of top-5 results
8. Deploy 10K validation clones: "Rate similarity of these nearest-neighbor pairs 0-10"
9. Wire embedding into store() path for future memories

## Verification
```bash
# Embedding coverage >= 95% of active memories
scripts/wm -c "
import sqlite3, os
conn = sqlite3.connect(os.path.expanduser('~/.whitemagic/memory/whitemagic.db'))
emb = conn.execute('SELECT COUNT(DISTINCT memory_id) FROM embeddings').fetchone()[0]
act = conn.execute(\"SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'\").fetchone()[0]
pct = emb/act*100 if act else 0
assert pct >= 95, f'Only {pct:.1f}% coverage ({emb}/{act})'
print(f'OK: {pct:.1f}% embedding coverage ({emb}/{act})')
"
```
