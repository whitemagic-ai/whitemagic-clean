# WhiteMagic DB Deduplication & Pruning Strategy

## Current State

| Metric | Value |
|--------|-------|
| DB Location | `~/.whitemagic/memory/whitemagic.db` |
| DB Size | ~2 GB |
| Memory Count | ~107K (post-dedup from 192K) |
| Avg Memory Size | ~19 KB |
| Holographic Coords | ~107K rows (1:1 with memories) |
| Dedup Already Done | Content-hash exact dedup (86K removed) |

## Deduplication Approaches

### 1. Content Hash Dedup (DONE)

Already applied via `scripts/kaizen_dedup.py`. Uses Python-side SHA-256 streaming + hash comparison. Removed 86K exact duplicates. **Do not use SQL GROUP BY on content column** — takes 20+ minutes on this DB size.

### 2. Semantic Near-Duplicate Detection

**Goal**: Identify memories with >95% content overlap (e.g., same content with different timestamps or minor edits).

**Approach**:
- Stream memories in batches of 1000
- For each batch, compute SimHash or MinHash fingerprints
- Compare fingerprints within sliding window (O(n) vs O(n^2))
- Flag pairs with similarity > 0.95 for review
- Keep the most recent version, archive older duplicates

**Implementation sketch**:
```python
from datasketch import MinHash, MinHashLSH

lsh = MinHashLSH(threshold=0.95, num_perm=128)
for batch in stream_memories(batch_size=1000):
    for mem in batch:
        mh = MinHash(num_perm=128)
        for word in mem.content.split():
            mh.update(word.encode('utf-8'))
        dupes = lsh.query(mh)
        if dupes:
            mark_for_archive(mem.id, dupes)
        lsh.insert(mem.id, mh)
```

**Expected yield**: 5-15K additional duplicates.

### 3. Metadata Pruning

Remove memories with empty or near-empty content:
```sql
SELECT id FROM memories WHERE length(content) < 10 AND access_count = 0;
```

Expected yield: 1-3K rows.

## Compression Strategies

### 1. Content Column Compression (gzip)

Store `content` as gzip-compressed BLOB instead of TEXT for memories older than 30 days:

```sql
ALTER TABLE memories ADD COLUMN content_compressed BLOB;
-- Migration script:
UPDATE memories SET content_compressed = gzip(content), content = NULL
WHERE created_at < datetime('now', '-30 days');
```

**Trade-off**: Requires Python-side decompression on read. Use a wrapper in `MemoryManager.read()`.

**Expected savings**: 60-80% on text content = ~1.2 GB saved.

### 2. Cold Storage Archive

Move memories with `access_count = 0` and `age > 6 months` to a separate `archive.db`:

```python
# Archive workflow
archive_db = sqlite3.connect("~/.whitemagic/memory/archive.db")
main_db = sqlite3.connect("~/.whitemagic/memory/whitemagic.db")

cursor = main_db.execute("""
    SELECT * FROM memories
    WHERE access_count = 0
    AND created_at < datetime('now', '-6 months')
""")
for row in cursor:
    archive_db.execute("INSERT INTO memories VALUES (?...)", row)
    main_db.execute("DELETE FROM memories WHERE id = ?", (row[0],))
```

**Expected yield**: 30-50K memories moved to cold storage.

### 3. VACUUM After Pruning

SQLite doesn't reclaim space from DELETEs without VACUUM:
```sql
VACUUM;
```

Run after any bulk delete operation. May take 2-5 minutes on a 2GB DB.

## Schema Audit

### Potentially Bloated Columns

| Column | Issue | Fix |
|--------|-------|-----|
| `content` | Raw text, no compression | Add gzip for old memories |
| `tags` | Stored as JSON text, often repeated | Normalize to separate `memory_tags` table |
| `metadata` | JSON blob, often contains redundant info | Strip null values, deduplicate |
| `embedding` | Float array if stored | Move to separate table or use Rust index only |

### Tag Normalization

Current: tags stored as JSON array in each memory row.
Proposed: normalized `tags` and `memory_tags` junction table.

```sql
CREATE TABLE tags (
    id INTEGER PRIMARY KEY,
    name TEXT UNIQUE NOT NULL
);

CREATE TABLE memory_tags (
    memory_id TEXT NOT NULL,
    tag_id INTEGER NOT NULL,
    PRIMARY KEY (memory_id, tag_id),
    FOREIGN KEY (memory_id) REFERENCES memories(id),
    FOREIGN KEY (tag_id) REFERENCES tags(id)
);
```

**Savings**: Eliminates repeated tag strings across 107K rows.

## Release Exclusion

### .gitignore Patterns

Already should include:
```
*.db
*.db-journal
*.db-wal
~/.whitemagic/
```

### Docker Volume Mounts

DB is mounted as a named volume in `docker-compose.yml`:
```yaml
volumes:
  whitemagic-data:
    driver: local
```

The DB should **never** be included in Docker images. Use `WM_DB_PATH` env var to point to the volume.

## Safe Pruning Criteria

### Tier 1: Safe to Delete (No Review Needed)

- Exact content duplicates (already done)
- `content` is empty string or NULL
- `content` length < 5 characters AND `access_count = 0`
- `type = 'short_term'` AND `age > 90 days` AND `access_count = 0`

### Tier 2: Safe to Archive (Move to archive.db)

- `access_count = 0` AND `age > 6 months`
- `type = 'short_term'` AND `age > 30 days`
- Memories tagged `thought_clone` or `scratchpad` older than 30 days
- Near-duplicate memories (keep newest, archive rest)

### Tier 3: Review Before Action

- Memories with `access_count > 0` but `age > 1 year`
- Memories with only system-generated tags (no user tags)
- Orphaned `holographic_coords` rows (no matching memory)

## Execution Plan

1. **Run Tier 1 deletes** — immediate space savings, zero risk
2. **VACUUM** — reclaim space
3. **Run Tier 2 archival** — move to archive.db
4. **VACUUM** again
5. **Benchmark**: measure new DB size and query performance
6. **Optional**: implement gzip compression for remaining old memories
7. **Optional**: normalize tags schema

## Monitoring

After pruning, track these metrics:
- `db.size_bytes` — should drop from 2GB to <800MB
- `db.memory_count` — target: 50-70K active memories
- `db.query_latency_ms` — should improve with smaller DB
- `db.archive_count` — memories in cold storage
