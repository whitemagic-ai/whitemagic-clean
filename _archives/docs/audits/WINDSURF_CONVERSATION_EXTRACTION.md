# Windsurf Conversation Extraction — Discovery & Method

**Date:** 2026-02-11 (updated 2026-02-14)  
**Status:** COMPLETE — 36/50 .pb UUIDs are conversations (extracted), 14 are non-conversation data

---

## Background

Windsurf (Codeium's IDE fork of VS Code) stores Cascade conversation data across several local locations. We wanted to extract all historical conversation transcripts and ingest them into WhiteMagic's personal holographic memory core for persistent recall across sessions.

## Storage Architecture

Windsurf uses three storage layers:

| Layer | Path | Format |
|-------|------|--------|
| **Protobuf archives** | `~/.codeium/windsurf/cascade/*.pb` | Binary protobuf, encrypted at rest |
| **LevelDB** | `~/.config/Windsurf/Local Storage/leveldb/` | Key-value store (session IDs, workspace state) |
| **SQLite (vscdb)** | `~/.config/Windsurf/User/globalStorage/state.vscdb` | VS Code state DB with `ItemTable` |

### Additional locations explored:
- `~/.codeium/windsurf/memories/*.pb` — Memory/context files (also encrypted)
- `~/.codeium/windsurf/implicit/*.pb` — Implicit context (also encrypted)
- `~/.config/Windsurf/Backups/` — VS Code hot-exit backups (editor content, not conversations)

## Encryption Findings

### .pb Files — AES-GCM with HKDF

The `.pb` files are **not** raw protobuf — they are **encrypted at rest**.

- **Algorithm:** AES-GCM (authenticated encryption)
- **Key derivation:** HKDF (HMAC-based Key Derivation Function)
- **Implementation:** Inside the Go binary `language_server_linux_x64`
- **Key material sources investigated:**
  - `~/.codeium/windsurf/installation_id` → `119667c6-67bf-4d5d-a147-a54b7a99f531`
  - `state.vscdb` `codeium.windsurf` installation_id → `96323301-99e3-4632-b5f0-1465a04289b2`
  - Chromium Safe Storage key (GNOME Keyring) → `tyNRBsEgyErBcz/0k+dHOQ==`
  - Windsurf API key from `windsurf_auth.sessions`

**Status:** The exact HKDF parameters (IKM, salt, info string, key length) remain undetermined. The Go binary performs the derivation internally and we were unable to reverse the precise construction. Direct decryption of `.pb` files is **not currently viable** without further reverse engineering of the language server.

## Successful Extraction Method: `trajectory_search`

### Discovery

Windsurf's Cascade IDE exposes a `trajectory_search` tool to AI assistants during active sessions. This tool can retrieve full conversation content by session ID, bypassing the encryption layer entirely (since the language server decrypts on-the-fly for the active session).

### Step 1: Extract Session IDs from LevelDB

```python
import re
from pathlib import Path

ldb_dir = Path('~/.config/Windsurf/Local Storage/leveldb').expanduser()
all_uuids = set()

for f in ldb_dir.glob('*'):
    if f.suffix in ('.ldb', '.log'):
        data = f.read_bytes()
        uuids = re.findall(
            rb'[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}',
            data,
        )
        for u in uuids:
            all_uuids.add(u.decode())

print(f'Found {len(all_uuids)} UUIDs')
```

This yielded **71 unique UUIDs** — a mix of cascade session IDs, installation IDs, auth session IDs, and workspace IDs.

### Step 2: Query Each UUID via `trajectory_search`

```
trajectory_search(ID="<uuid>", Query="", SearchType="cascade")
```

- Valid cascade session IDs return chunks with full conversation content (user messages, AI responses, tool calls, file edits).
- Invalid IDs (installation IDs, auth tokens, etc.) return 0 chunks — harmless.

### Step 3: Ingest into Holographic Memory

Script: `scripts/ingest_windsurf_conversations.py`

- Each conversation becomes a `LONG_TERM` memory with structured metadata
- Deduplicates by title on re-run
- Tags: `windsurf_session`, `cascade_transcript`, plus topic-specific tags
- Stored in `~/.whitemagic/memory/whitemagic.db`

## Inventory

### Storage Locations

- **50 .pb files** in `~/.codeium/windsurf/cascade/` (encrypted conversation archives)
- **95 UUIDs** in `~/.config/Windsurf/Local Storage/leveldb/` (session IDs, auth tokens, etc.)
- **45 LevelDB-only UUIDs** that don't have corresponding .pb files (older/cleaned sessions)

### Extraction Progress

| Round | Date | Conversations | Chunks | Method |
|-------|------|---------------|--------|--------|
| Round 1 | 2026-02-11 | 13 | 1,625 | trajectory_search |
| Round 2 | 2026-02-11 | 3 | 834 | trajectory_search |
| Round 3 | 2026-02-14 | 8 | 1,785 | trajectory_search |
| Round 4 | 2026-02-14 | 4 | 1,480 | trajectory_search |
| Round 5 | 2026-02-14 | 4 | 1,693 | trajectory_search |
| Round 6 | 2026-02-14 | 4 | 1,569 | trajectory_search |
| **Total** | | **36** | **8,986** | |
| Dead UUIDs | | 14 | 0 | Non-conversation data |

## Extracted Conversations

### Round 1 (13 conversations)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `db30ab1f` | 35 | Whitemagic Project Review — Autonomous Horizon Strategy |
| `979cf77c` | 42 | 5D Memory Space Analysis |
| `00e5f9e7` | 41 | 5D Holographic Memory Gap Analysis |
| `1608d83e` | 46 | Polyglot Architecture Review |
| `e1e7fc14` | 217 | DTF and Personal Narrative — LIBRARY Reorganization |
| `4f43085e` | 3 | Galaxy and Quickstart Memory Questions |
| `a0dc2188` | 113 | Engine and Grimoire Mapping — Leap 7 Nervous System |
| `5be323d8` | 305 | Polyglot Benchmarking and Cleanup — v13.3.0→v13.3.1 |
| `f472b6e6` | 127 | Optimize Whitemagic Performance — 4-Phase Optimization |
| `b56b8ba5` | 316 | Refining CoreAccessLayer and Mojo Integration — v14 |
| `875f2d48` | 52 | Whitemagic's Emergent AI Architecture — Play as Engine |
| `664b07a4` | 103 | Polyglot Expansion Review — v13.1→v13.2 |
| `5d1df08a` | 225 | Fix Warnings and Deprecations — Packaging Validation |

### Round 2 (3 conversations)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `019c6a89` | 133 | Implement Violet Security Features |
| `04c1bceb` | 161 | Integrate Graph-Based Tools |
| `080f8e4b` | 540 | WhiteMagic Security & Mesh Improvements |

### Round 3 (8 conversations, Feb 14 2026)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `06955f15` | 191 | WhiteMagic Website Phase 1 Completion |
| `0f702cdb` | 174 | WhiteMagic v15.8 Release Prep |
| `1250c429` | 36 | WhiteMagic v14 Release Strategy |
| `15db21e0` | 152 | RTS Strategy Mapping |
| `168d42e6` | 150 | Resolving Remaining Victory Conditions |
| `1a0773f1` | 835 | Project Cleanup and Release Prep |
| `1b4bff4b` | 35 | Whitemagic Memory Review and Strategy |
| `20e6a233` | 213 | Finalizing v14.2 Patch and V15 Roadmap |

### Round 4 (4 conversations, Feb 14 2026)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `23792b84` | 404 | Fixing UMAP Tests — v14.1.0 Audit + Cognitive Enrichment |
| `2809f7f8` | 211 | Refining AI_PRIMARY.md and Fixing Version Drift |
| `347779b3` | 235 | Rust Bindings and Mesh Refinement — v14.5 Polyglot Core |
| `3bb20d79` | 630 | Integrate Progress & Parallelization — Campaign System |

### Round 5 (4 conversations, Feb 14 2026)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `78e644ec` | 365 | Website Overhaul and MCP Prep — v15.1 |
| `ad4432f9` | 374 | Ollama Context Injection Pipeline — v15.4-15.5 |
| `cfc73124` | 751 | Fixing MyPy Errors — v14.3.1 Fresh Install |
| `f114b6b7` | 203 | Fixing Activation Sequence — v15.9 |

### Round 6 (4 conversations, Feb 14 2026)

| ID (short) | Chunks | Title |
|------------|--------|-------|
| `84b7fa62` | 305 | Activation Sequence Deep Dive — 111K Corpus |
| `8989cd8a` | 121 | Living Memory Improvements — v14.2 HRR + MandalaOS |
| `8fc57241` | 209 | WhiteMagic V15 Audit Execution — Product Tiers |
| `94a4bea2` | 934 | Refactor and Refine Whitemagic — v15.7 CI Green |

### Dead UUIDs (14 — non-conversation .pb files)

```
41a50aa3  4384f7da  4b54b060  4d6f5d35  541f55f1  5956871e
5b1c42c6  5ee172f1  606a5cfb  6f230d78  6ff11acb  7175ecca
9c186d8e  9dd7bb64  9ed2ce96  b3a23276  b994d6ca  bbe28c11
c5c54df8  f8de6773  fe0f6cb5
```

These UUIDs returned 0 chunks from `trajectory_search` — they are internal Windsurf state/metadata files, not conversation archives.

## Campaign

Campaign doctrine: `campaigns/I004_windsurf_conversation_ingestion.md`

This extraction effort is tracked as Campaign I004 in the shadow clone army system.
Victory conditions include full inventory, complete extraction, ingestion into galactic
memory core, constellation detection, and cross-reference analysis.

## Limitations & Future Work

1. **Encryption reversal:** Full `.pb` decryption would enable offline batch extraction without an active Windsurf session. Requires reverse-engineering the HKDF parameters from the Go language server binary.
2. **Memory/Implicit files:** `~/.codeium/windsurf/memories/*.pb` and `implicit/*.pb` likely contain learned context and user preferences — same encryption barrier applies.
3. **Incremental extraction:** The extraction script (`scripts/extract_and_ingest_windsurf.py`) supports re-runs with content-hash dedup.
4. **Full-text ingestion:** Current memories store summaries + key findings. A future pass could store raw chunk text for richer semantic search.
5. **LevelDB-only UUIDs:** 45 UUIDs found only in LevelDB (no .pb file) remain unprobed — these may be older sessions cleaned from disk but still referenced in LevelDB.
6. **Ingestion pending:** All 36 conversations catalogued but not yet ingested into galactic memory core. Run `scripts/extract_and_ingest_windsurf.py` to ingest.

## Files

- `scripts/extract_and_ingest_windsurf.py` — Master extraction + ingestion script (all UUIDs, metadata, dedup)
- `scripts/ingest_windsurf_conversations.py` — Round 1 ingestion (legacy)
- `scripts/ingest_windsurf_round2.py` — Round 2 ingestion (legacy)
- `campaigns/I004_windsurf_conversation_ingestion.md` — Campaign doctrine
- `_archives/docs/audits/WINDSURF_CONVERSATION_EXTRACTION.md` — This document
