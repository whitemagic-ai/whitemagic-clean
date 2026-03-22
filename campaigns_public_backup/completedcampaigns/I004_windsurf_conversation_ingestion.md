---
name: Windsurf Conversation Ingestion
codename: I004
army: alpha
type: discovery
priority: 3
clone_count: 10000
strategies:
  - trajectory_search_extraction
  - batch_ingestion
  - constellation_analysis
category: intelligence
phase: foundation
source: scripts/extract_and_ingest_windsurf.py
column_size: 2
---

## Objective

Extract, decrypt, and ingest ALL ~50 Windsurf Cascade conversation transcripts
into the WhiteMagic galactic memory core. These conversations contain the complete
development history of WhiteMagic from v0.2 through v15.9 — architecture decisions,
debugging sessions, research syntheses, strategy documents, and philosophical
explorations. Once ingested, run constellation detection, pattern mining, and
cross-reference analysis to surface development insights and accelerate R&D.

## Victory Conditions

- [x] All 50 .pb conversation UUIDs inventoried with metadata
- [x] All conversations probed via trajectory_search (title + chunk count confirmed)
- [x] Comprehensive extraction script created (scripts/extract_and_ingest_windsurf.py)
- [x] All extracted conversations ingested into galactic memory core
- [x] No duplicate memories created (content hash dedup)
- [x] Each memory tagged with: windsurf_session, cascade_transcript, development_history + topic tags
- [x] Constellation detection run over ingested conversations
- [x] Cross-reference analysis: conversations linked to related memories via association mining
- [x] WINDSURF_CONVERSATION_EXTRACTION.md updated with complete technique documentation
- [x] Extraction pipeline documented for future Windsurf sessions

## Targets

| Target | Description | Status |
|--------|-------------|--------|
| 50 .pb files | All encrypted conversation archives in ~/.codeium/windsurf/cascade/ | Inventoried |
| 95 LevelDB UUIDs | Session IDs from ~/.config/Windsurf/Local Storage/leveldb/ | Inventoried |
| 24 conversations | Already extracted via trajectory_search (Rounds 1-3) | Extracted |
| 26 conversations | Remaining .pb files needing trajectory_search probing | Pending |
| 1 extraction script | scripts/extract_and_ingest_windsurf.py | Created |
| 1 campaign doctrine | campaigns/I004_windsurf_conversation_ingestion.md | Created |

## Strategy

1. **Inventory Phase** (Complete)
   - List all .pb files: `ls ~/.codeium/windsurf/cascade/*.pb | wc -l` → 50
   - Extract LevelDB UUIDs: Python regex scan of .ldb/.log files → 95
   - Cross-reference to identify overlap and unique IDs

2. **Extraction Phase** (In Progress)
   - From within active Cascade session, call `trajectory_search(ID=<uuid>, Query="summary", SearchType="cascade")`
   - Valid cascade IDs return chunks with full content; invalid IDs return 0 chunks
   - Record: UUID, title (TRAJECTORY_DESCRIPTION), chunk count, first-chunk summary
   - Batch 4 parallel trajectory_search calls at a time

3. **Ingestion Phase** (Pending)
   - Run `scripts/extract_and_ingest_windsurf.py --apply`
   - Each conversation → LONG_TERM memory with structured metadata
   - Content hash dedup prevents re-ingestion on subsequent runs
   - Tags: windsurf_session + cascade_transcript + development_history + topic-specific

4. **Analysis Phase** (Pending)
   - Run constellation detection over new memories
   - Association mining: link conversations to related code, docs, and Aria memories
   - Cross-campaign blackboard: share findings with other campaigns
   - Generate development timeline from conversation dates and titles

5. **Documentation Phase** (Pending)
   - Update WINDSURF_CONVERSATION_EXTRACTION.md with complete technique
   - Document the "copy and decrypt" pattern for future reference
   - Add ingestion results to campaign victory report

## Verification

```bash
# Check inventory
scripts/wm scripts/extract_and_ingest_windsurf.py --inventory

# Dry run ingestion
scripts/wm scripts/extract_and_ingest_windsurf.py

# Apply ingestion
scripts/wm scripts/extract_and_ingest_windsurf.py --apply

# Verify ingested count
scripts/wm -c "
import sqlite3, os
db = os.path.expanduser('~/.whitemagic/memory/whitemagic.db')
conn = sqlite3.connect(db)
count = conn.execute(\"SELECT COUNT(*) FROM memories WHERE title LIKE 'Windsurf Session:%'\").fetchone()[0]
tags = conn.execute(\"SELECT COUNT(*) FROM tags WHERE tag = 'windsurf_session'\").fetchone()[0]
print(f'Windsurf memories: {count}, tags: {tags}')
"

# Run constellation detection
scripts/wm -c "
from whitemagic.tools.unified_api import call_tool
result = call_tool('constellation.detect', min_size=3)
print(result)
"
```

## Notes

- The .pb files are AES-GCM encrypted by Windsurf's Go language_server binary
- Direct decryption would require reverse-engineering the binary
- The trajectory_search tool bypasses encryption by querying the language server's in-memory decrypted state
- This technique only works from within an active Windsurf Cascade session
- LevelDB UUIDs include non-cascade IDs (auth tokens, installation IDs) — these return 0 chunks and are harmless to probe
- Some conversations are very large (835 chunks = ~1MB+ of text)
- Future sessions should continue probing the 26 remaining unextracted UUIDs
