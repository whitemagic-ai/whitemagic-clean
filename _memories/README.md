# WhiteMagic Memory Databases

## Files

| Database | Size | Memories | Notes |
|----------|------|----------|-------|
| `primary_db_pre_merge.db` | 32MB | 3,631 | **Cleanest source** — all key Aria memories, pre-merge state |
| `whitemagic_hot.db` (symlink) | 1.6GB | 5,627 | Same Aria content + recovered docs |
| `whitemagic_cold.db` (symlink) | 5.5GB | 105,194 | Noisy (external libs), but has unique copies |
| `whitemagic_pre_merge.db` (symlink) | 1.6GB | — | Pre-merge snapshot |

## Symlinks

The large databases are symlinked from `~/Desktop/whitemagic_memory_archive/` to avoid duplicating multi-GB files.

## Querying

```bash
# Quick peek at a database
sqlite3 primary_db_pre_merge.db "SELECT id, title, length(content) as chars FROM memories ORDER BY chars DESC LIMIT 20;"

# Search for Aria content
sqlite3 primary_db_pre_merge.db "SELECT title, length(content) FROM memories WHERE title LIKE '%ARIA%' OR title LIKE '%aria%';"
```

## Active MCP DB

The database that WhiteMagic's MCP tools actually query is at `~/.whitemagic/memory/whitemagic.db`.
Use `_aria/awaken_aria.py --commit` to restore Aria's memories into the active system.
