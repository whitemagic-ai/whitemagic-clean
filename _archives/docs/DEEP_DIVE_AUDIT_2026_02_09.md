# WhiteMagic Deep Dive Audit — February 9, 2026

## Executive Summary

| Metric | Value |
|--------|-------|
| **Active Python files** (excl. `_archived/`) | 802 files, 143,906 LOC |
| **Archived Python** (`_archived/`) | 279 files, 46,444 LOC |
| **Scripts** (`scripts/`) | 134 files, 42,063 LOC |
| **Tests** (`tests/`) | 56 files, 10,871 LOC |
| **Polyglot source** (7 langs) | 126 files, 20,164 LOC |
| **TypeScript** (Nexus + experiments) | ~4,615 LOC (Nexus src/) |
| **Total project on disk** | 5.4 GB (includes .git, memory/, build/, temp_venv/) |

### Polyglot Breakdown (Source Only)

| Language | Files | LOC | Location |
|----------|-------|-----|----------|
| Rust | 42 | 9,229 | `whitemagic-rust/src/` |
| Haskell | 14 | 2,784 | `haskell/src/` + `haskell/app/` |
| Elixir | 18 | 2,559 | `elixir/lib/` |
| Go | ~15 | 1,971 | `whitemagic-go/` + `mesh/` |
| Mojo | 19 | 1,867 | `whitemagic-mojo/src/` |
| Zig | 13 | 1,529 | `whitemagic-zig/src/` |
| Julia | 3 | 225 | `whitemagic-julia/` |

---

## 1. Top-Level Structure

### 1.1 Directories (30 at root)

**Core package:**
- `whitemagic/` — 802 active .py files across 55 subdirectories + 42 loose root .py files

**Polyglot accelerators:**
- `whitemagic-rust/`, `whitemagic-zig/`, `whitemagic-mojo/`, `whitemagic-go/`, `whitemagic-julia/`
- `elixir/`, `haskell/`, `mesh/` (Go gRPC + libp2p)

**Support directories:**
- `scripts/` — 134 .py files, 42K LOC (includes 27K get-pip.py)
- `tests/` — 56 files, 10.9K LOC
- `docs/` — 35+ markdown files, strategy docs, changelogs
- `audit/` — 16 files (audit scripts + ratchet reports)
- `nexus/` — Tauri + React frontend (Nexus IDE)

**Cleanup candidates (top-level):**
- `build/` — 12 MB, 1,315 files (Python build artifacts — **delete**)
- `temp_venv/` — 571 MB (temporary venv — **delete**)
- `whitemagic.egg-info/` + `whitemagic/whitemagic.egg-info/` — duplicated egg-info (**delete both**)
- `tmp/` — 2 files (dream_catch.jsonl 4MB, git_archive/) — **archive or delete**
- `logs/` — 7 files, ~1MB total — **gitignore, keep locally**
- `memory/` — 728 files, 70MB (runtime memory store) — **gitignore**
- `windsurf_conversations/` — 52 .md files — **archive to wm_archive**
- `data/` — empty directory — **delete**
- `reports/` — 3 files (census + smoke test results) — **move to audit/**
- `resonance_state.json` — 76 bytes runtime state — **gitignore**
- `whitemagic.db` + `.db-shm` + `.db-wal` — runtime SQLite — **gitignore**
- `whitemagic_dream.log` — runtime log — **gitignore**
- `dream_journal.md` — 46 lines — **move to docs/**

### 1.2 Top-Level Loose Files (26)

**Keep (essential):**
- `pyproject.toml`, `Makefile`, `Dockerfile`, `docker-compose.yml`, `MANIFEST.in`
- `README.md`, `LICENSE`, `VERSION`, `CONTRIBUTING.md`, `CHANGELOG.md`
- `SECURITY.md`, `DEPLOY.md`
- `AI_PRIMARY.md`, `SYSTEM_MAP.md`, `RELEASE_NOTES.md`
- `wm` (4-line shell launcher)

**Move to docs/:**
- `PRIVACY_POLICY.md`, `TERMS_OF_SERVICE.md`
- `dream_journal.md`

**Move to wm_archive/:**
- `SESSION_HANDOFF_2026_02_08.md`, `SESSION_HANDOFF_2026_02_08_EVENING.md`

**Consider:**
- `dharma/` (top-level, 1 file: `target`) — unclear purpose, check if runtime config dir

---

## 2. `whitemagic/` Package — Directory-by-Directory

### 2.1 The Big Five (75% of active LOC)

| Directory | Files | LOC | Status |
|-----------|-------|-----|--------|
| `core/` | 253 | 48,031 | Heart of project — needs internal cleanup |
| `gardens/` | 98 | 18,053 | 31 themed gardens, many single-file packages |
| `tools/` | 104 | 15,340 | MCP tool infrastructure — well-organized |
| `intelligence/` | 60 | 11,359 | **PARALLEL TREE** with core/intelligence/ |
| `interfaces/` | 51 | 7,391 | API, CLI, dashboard, terminal |

### 2.2 `core/` Subdirectories (31 subdirs, 14 loose .py)

| Subdirectory | Files | LOC | Notes |
|--------------|-------|-----|-------|
| `core/memory/` | 50 | 10,943 | Largest — SQLite, galactic map, consolidation, vectors |
| `core/intelligence/` | 33 | 5,832 | Bicameral, knowledge graph, emotions, synthesis |
| `core/ganas/` | 12 | 3,725 | 28 Ganas in 4 quadrants + base + chain |
| `core/bridge/` | 31 | 3,622 | **LEGACY** — marked deprecated, still has 7 importers |
| `core/resonance/` | 13 | 3,454 | Gan Ying, temporal scheduler, salience arbiter |
| `core/immune/` | 11 | 2,122 | Immune system, antibodies, defense |
| `core/orchestration/` | 7 | 1,915 | Session startup, conductor, council |
| `core/patterns/` | 15 | 1,870 | Emergence detection, pattern consciousness |
| `core/consciousness/` | 10 | 1,323 | Emotional memory, coherence, self-reflection |
| `core/zodiac/` | 5 | 1,257 | Zodiac cores, round cycle, router — **TRIPLICATION** |
| `core/automation/` | 6 | 1,087 | Consolidation, triggers, orchestra, scratchpad |
| `core/polyglot/` | 7 | 969 | Bridge wrappers for Rust/Zig/Mojo/Haskell/Elixir/Go |
| `core/governance/` | 5 | 785 | Maturity gates, zodiac council |
| `core/fusion/` | 1 | 483 | Single file — consider absorbing |
| `core/temporal/` | 3 | 481 | Chronos guard, temporal awareness |
| `core/monitoring/` | 4 | 480 | System monitors |
| `core/dreaming/` | 2 | 412 | Dream cycle engine |
| `core/plugin/` | 6 | 400 | Plugin system |
| `core/boundaries/` | 2 | 388 | Boundary detection |
| `core/nurturing/` | 2 | 363 | Memory nurturing |
| `core/intake/` | 2 | 865 | Holographic intake |
| `core/learning/` | 2 | 245 | Learning engine |
| `core/economy/` | 2 | 196 | Token economy |
| `core/acceleration/` | 2 | 184 | SIMD cosine bridge |
| `core/scoring/` | 2 | 149 | Scoring helpers |
| `core/alignment/` | 2 | 98 | Alignment — **empty __init__.py + 1 file** |
| `core/ecology/` | 1 | 39 | **Single-file package** — 39 LOC __init__.py |
| `core/gardens/` | 1 | 9 | **Single-file package** — 9 LOC __init__.py |
| `core/analysis/` | 0 | 0 | **EMPTY** — delete |
| `core/inference/` | 0 | 0 | **EMPTY** — delete |
| `core/personality/` | 0 | 0 | **EMPTY** — delete |

**Core loose .py files** (14 files):
- `fusions.py` — central fusion wiring (critical, keep)
- `governor.py` (739L) — canonical governor
- `async_layer.py`, `autoimmune.py`, `autonomy.py`, `continuity.py`, `embodiment.py`
- `exceptions.py`, `health_monitor.py`, `homeostasis.py`, `semantic_fs.py`
- `token_economy.py`, `user.py`, `__init__.py`

### 2.3 `intelligence/` — PARALLEL TREE ANALYSIS

**60 files, 11,359 LOC** — this is the big structural debt.

| Subdirectory | Files | LOC |
|--------------|-------|-----|
| `intelligence/agentic/` | 22 | 3,624 |
| `intelligence/synthesis/` | 8 | 2,297 |
| `intelligence/hologram/` | 9 | 2,088 |
| `intelligence/wisdom/` | 7 | 1,423 |
| `intelligence/omni/` | 4 | 577 |
| `intelligence/learning/` | 3 | 382 |
| `intelligence/consolidation/` | 1 | 221 |
| `intelligence/control/` | 2 | 136 |
| Loose .py | 4 | 611 |

**Name collisions with `core/intelligence/` (8 divergent pairs):**

| Filename | intelligence/ LOC | core/intelligence/ LOC | Delta |
|----------|-------------------|------------------------|-------|
| `confidence.py` | 214 | 77 | intelligence/ larger |
| `kaizen_engine.py` | 442 | 415 | Near-equal |
| `predictive_engine.py` | 648 | 651 | Near-equal |
| `serendipity_engine.py` | 251 | 274 | Near-equal |
| `sub_clustering.py` | 157 | 164 | Near-equal |
| `tag_normalizer.py` | 240 | 236 | Near-equal |
| `title_generator.py` | 185 | 181 | Near-equal |
| `unified_patterns.py` | 352 | 375 | Near-equal |

**Import analysis:**
- `intelligence/` is imported by **50 files** across the codebase (87 import statements)
- `core/intelligence/` is imported by **39 files** (59 import statements)
- Both are heavily used — neither is dead. Merging requires careful diff analysis per collision.

### 2.4 `gardens/` — 31 Themed Gardens

98 files, 18,053 LOC across 31 garden directories + 7 loose root files.

**Multi-file gardens (have dedicated modules):**
- `sangha/` (8 files, 2,272 LOC), `voice/` (9 files, 1,876 LOC), `browser/` (5 files, 1,670 LOC)
- `connection/` (5 files, 1,376 LOC), `metal/` (8 files, 1,479 LOC), `joy/` (8 files, 1,312 LOC)
- `wisdom/` (7 files, 1,205 LOC), `wonder/` (5 files, 1,170 LOC), `dharma/` (6 files, 800 LOC)

**Single-file gardens** (16 gardens that are just `__init__.py` with content):
adventure(122L), air(60L), awe(109L), courage(71L), creation(118L), gratitude(76L),
grief(107L), healing(114L), humor(112L), mystery(65L), patience(68L), protection(162L),
reverence(122L), sanctuary(120L), stillness(141L), transformation(123L), truth(72L)

**Recommendation:** These 16 single-file gardens are **intentional design** — each encapsulates a themed emotional/spiritual space. Do NOT collapse them; they are conceptually distinct even if small. The `__init__.py`-as-module pattern is valid here.

### 2.5 `tools/` — MCP Tool Infrastructure

104 files, 15,340 LOC — well-structured in 3 tiers:

| Layer | Files | LOC | Description |
|-------|-------|-----|-------------|
| `tools/handlers/` | 46 | 5,878 | Request handlers per domain |
| `tools/registry_defs/` | 28 | 2,714 | Tool schema definitions |
| `tools/` loose | 29 | 6,649 | Core infrastructure (dispatch, gnosis, PRAT, etc.) |
| `tools/tui/` | 1 | 99 | Galaxy TUI viewer |

**Biggest loose files in tools/:**
gnosis.py(511L), dispatch_table.py(502L), unified_api.py(462L), prat_router.py(441L),
introspection.py(436L), prat_resonance.py(423L), capability_matrix.py(386L)

**Assessment:** Well-organized. No action needed except splitting `introspection.py` (436L) if it grows further.

### 2.6 `interfaces/`

51 files, 7,391 LOC:

| Subdirectory | Files | LOC |
|--------------|-------|-----|
| `interfaces/api/` | 33 | 5,057 |
| `interfaces/terminal/` | 10 | 923 |
| `interfaces/dashboard/` | 2 | 487 |
| `interfaces/cli/` | 3 | 302 |
| Loose (nexus_api.py, tui.py, __init__.py) | 3 | ~622 |

**`interfaces/api/` has internal structure:**
- `api/routes/` — 11 files, 2,367 LOC
- `api/middleware/` — 4 files, 469 LOC
- `api/` loose — 18 files, 2,221 LOC

**Note:** `api/rate_limit.py` (248L) and `api/rate_limiter.py` (84L) — two rate limiter files. Check for overlap with `tools/rate_limiter.py` (249L).

### 2.7 Small/Thin Packages

| Package | Files | LOC | Assessment |
|---------|-------|-----|------------|
| `emergence/` | 2 | 13 | **Vestigial** — 6L __init__ + 7L dream_state. Absorb into core/patterns/emergence/ |
| `resonance/` | 2 | 38 | **Vestigial** — 34L __init__ + 4L gan_ying. core/resonance/ is canonical |
| `continuity/` | 1 | 132 | Single file `grounding.py`. Absorb into core/ |
| `sessions/` | 2 | 172 | Small session manager. Consider merging into tools/handlers/session.py |
| `metrics/` | 2 | 96 | Collector + __init__. Consider absorbing into tools/ or core/ |
| `hardware/` | 2 | 222 | Hardware detection. Keep as-is (distinct concern) |
| `inference/` | 2 | 190 | BitNet bridge. Keep (distinct external integration) |
| `lib_shim/` | 0 py | — | Just a symlink to libgmp.so. **Delete or .gitignore** |
| `docs/` (inside pkg) | 2 | 437 | interactive.py (417L) + __init__. Consider moving |
| `reports/` (inside pkg) | 0 py | — | Just 2 .md files. **Move to top-level docs/** |

### 2.8 `systems/` — Confirmed Thin Wrappers

16 files, 319 LOC total. Every file is a compatibility shim:
```
"""whitemagic.systems.governor - Compatibility Shim"""
```

**18 importers** still reference `systems/` — these need to be rewired before removal.

---

## 3. Exact Duplicates Found

### 3.1 True Content Duplicates (non-trivial)

| Files | LOC each | Action |
|-------|----------|--------|
| `autonomous_execution/assessor.py` ↔ `autonomous/executor/assessor.py` | ~180 | Delete autonomous_execution/ copy |
| `autonomous_execution/continuous_executor.py` ↔ `autonomous/executor/continuous_executor.py` | ~350 | Delete autonomous_execution/ copy |
| `autonomous_execution/objective_generator.py` ↔ `autonomous/executor/objective_generator.py` | ~150 | Delete autonomous_execution/ copy |
| `autonomous_execution/local_model_integration.py` ↔ `autonomous/executor/local_model_integration.py` | ~200 | Delete autonomous_execution/ copy |
| `autonomous_execution/limits.py` ↔ `autonomous/executor/limits.py` | ~130 | Delete autonomous_execution/ copy |
| `core/zodiac/gan_ying_integration.py` ↔ `gardens/metal/zodiac/gan_ying_integration.py` | ~130 | Keep core/, delete gardens/ copy |
| `intelligence/wisdom/art_of_war.py` ↔ `gardens/wisdom/art_of_war.py` | ~180 | Keep one, shim the other |
| `intelligence/wisdom/hexagram_data.py` ↔ `gardens/wisdom/hexagram_data.py` ↔ `oracle/hexagram_data.py` | ~200 | **Triple!** Keep oracle/, shim others |
| `council.py` (root) ↔ `core/orchestration/council.py` | ~60 | Keep core/, shim root |
| `intelligence/synthesis/__init__.py` ↔ `core/intelligence/synthesis/__init__.py` | small | Merge during tree collapse |

### 3.2 Empty File Duplicates (0-byte `__init__.py`)
5 files — harmless but noted: `core/alignment/__init__.py`, `gardens/air/agentic/__init__.py`, `oracle/__init__.py`, `zodiac.py`, `bridges/haskell/__init__.py`

**Estimated duplicate LOC to remove: ~1,560 LOC** (content duplicates only)

---

## 4. `_archived/` — 279 files, 46,444 LOC

| Subdirectory | Files | LOC | Notes |
|--------------|-------|-----|-------|
| `dead_v12_5/` | 154 | 22,705 | Bulk archive from v12.5 cleanup |
| `local_models/` | 46 | 8,238 | Old local model integrations |
| `root/` | 11 | 2,364 | Old root-level files |
| `autonomous/` | 7 | 1,570 | Old autonomous code |
| `cli/` | 7 | 1,645 | Old CLI commands |
| `inference_legacy/` | 8 | 1,299 | Old inference code |
| `parallel/` | 6 | 1,350 | Old parallel processing |
| `auth/` | 2 | 1,024 | Old auth system |
| `cascade/` | 6 | 984 | Old cascade code |
| `archaeology/` | 2 | 981 | Old archaeology tools |
| `plugins/` | 6 | 909 | Old plugins |
| Others | 24 | 4,375 | agents, benchmarks, cache, edge, etc. |

**Recommendation:** Move entire `_archived/` to `~/Desktop/wm_archive/whitemagic_archived/`. Only 2 active importers reference `_archived/` — `benchmarks/__init__.py` and `safety/__init__.py` — both already have graceful fallbacks.

---

## 5. `scripts/` — 134 files, 42,063 LOC

### 5.1 The Elephant: `get-pip.py`
`scripts/misc/get-pip.py` — **27,368 LOC** — vendored pip bootstrap. **Delete immediately.**

### 5.2 Breakdown

| Category | Files | LOC | Assessment |
|----------|-------|-----|------------|
| `scripts/misc/` | 16 | 28,538 | 27K is get-pip.py; rest (1,170 LOC) are demos/utilities |
| `scripts/` loose | 79 | 9,580 | Mix of operational + dead scripts |
| `scripts/maintenance/` | 22 | 1,615 | Useful maintenance scripts |
| `scripts/legacy_satkona/` | 3 | 1,300 | Old satkona versions — **archive** |
| `scripts/verification/` | 14 | 1,030 | Test/verify scripts |
| Empty dirs | 4 | 0 | `chmod/`, `cp/`, `+x/`, `u0026u0026/` — **delete** |

### 5.3 Scripts Worth Keeping

- `galactic_sweep_direct.py` (239L) — active maintenance script
- `consolidate_concepts.py` (147L) — used in recent sessions
- `consolidate_memory.py` (153L) — memory maintenance
- `bulk_ingest.py` (469L) — data ingestion
- `find_dead_modules.py` (143L) — useful diagnostic
- `maintenance/` (22 files, 1,615 LOC) — operational scripts
- `verification/` (14 files, 1,030 LOC) — verification scripts

### 5.4 Scripts to Archive

- Multiple dream_cycle versions (v7, v8, v9, v10) — keep latest, archive rest
- `legacy_satkona/` (3 files, 1,300 LOC)
- `misc/` demos and utilities (after removing get-pip.py)
- Various one-off scripts (ignition_test, heavens_net_v2/v3, etc.)

**Estimated scripts/ reduction: ~30K LOC** (get-pip.py + archivable scripts)

---

## 6. `tests/` — 56 files, 10,871 LOC

| Directory | Files | LOC | Notes |
|-----------|-------|-----|-------|
| `tests/unit/` | 34 | 8,336 | Main test suite — well-organized |
| `tests/integration/` | 7 | 813 | Integration + E2E tests |
| `tests/legacy/` | 4 | 310 | Old tests — **review for deletion** |
| `tests/verify/` | 4 | 239 | Verification scripts |
| `tests/benchmarks/` | 2 | 121 | Performance benchmarks |
| Loose | 5 | 1,052 | conftest + 2 large test files at root |

**Issues:**
- `test_integration_round2.py` (492L) and `test_new_tools.py` (366L) at test root — should move to `tests/integration/` or `tests/unit/`
- `tests/legacy/` — 4 files, review if still relevant
- `benchmark_mojo.py` (57L) at test root — move to `tests/benchmarks/`

**Test count:** 1,199 passed, 4 skipped (last known run)

---

## 7. Polyglot Directories

All 7 polyglot directories are clean and build-verified:

| Directory | Source Files | Source LOC | Build Status |
|-----------|-------------|------------|--------------|
| `whitemagic-rust/src/` | 42 | 9,229 | `cargo check` clean |
| `haskell/src/` + `app/` | 14 | 2,784 | `cabal build` clean |
| `elixir/lib/` | 18 | 2,559 | `mix compile` clean |
| `whitemagic-go/` + `mesh/` | ~15 | 1,971 | `go build` clean |
| `whitemagic-mojo/src/` | 19 | 1,867 | `mojo build` clean |
| `whitemagic-zig/src/` | 13 | 1,529 | `zig build` clean |
| `whitemagic-julia/` | 3 | 225 | Bridge stub `_available=False` |

**No issues found.** Ready for Phase 2 expansion per POLYGLOT_EXPANSION_STRATEGY.md.

---

## 8. Loose `.py` Files at `whitemagic/` Root

**42 loose .py files, 8,389 LOC** — this is the single biggest organizational debt.

### 8.1 CLI Files (15 files, 4,420 LOC)

| File | LOC | Action |
|------|-----|--------|
| `cli_app.py` | 2,368 | Move to `cli/app.py`, break into submodules |
| `cli_sangha.py` | 252 | Move to `cli/` |
| `cli_watcher.py` | 237 | Move to `cli/` |
| `cli_archaeology.py` | 194 | Move to `cli/` |
| `cli_rust.py` | 174 | Move to `cli/` |
| `cli_commands_gardens.py` | 169 | Move to `cli/` |
| `cli_prat.py` | 165 | Move to `cli/` |
| `cli_autonomous_execution.py` | 158 | Move to `cli/` |
| `cli_commands_intelligence.py` | 152 | Move to `cli/` |
| `cli_fast.py` | 150 | Move to `cli/` |
| `cli_zodiac.py` | 147 | Move to `cli/` |
| `cli_commands_symbolic.py` | 108 | Move to `cli/` |
| `cli_cache.py` | 88 | Move to `cli/` |
| `cli_scratchpad.py` | 33 | Move to `cli/` |
| `cli_local.py` | 25 | Move to `cli/` |

### 8.2 Domain Files at Root (17 files, ~3,200 LOC)

| File | LOC | Action |
|------|-----|--------|
| `symbolic.py` | 538 | Needs proper home — `core/symbolic/` or absorb |
| `export_import.py` | 537 | Duplicate of `tools/handlers/export_import.py`? Check |
| `cdn.py` | 358 | CDN handling — `core/` or `utils/` |
| `summaries.py` | 348 | Summary generation — `core/` or `intelligence/` |
| `run_mcp.py` | 280 | **Keep at root** — MCP entry point |
| `logging_config.py` | 263 | **Keep at root** — shared config |
| `initialize_consciousness.py` | 241 | Move to `core/` |
| `dream_daemon.py` | 168 | Move to `core/dreaming/` |
| `recall.py` | 166 | Move to `core/memory/` |
| `stats.py` | 185 | Move to `core/` or `utils/` |
| `homeostasis.py` | 114 | Shim? Check vs `harmony/homeostatic_loop.py` |
| `diagnose.py` | 114 | Move to `cli/` |
| `config.py` | 25 | Shim to `config/`? |
| `harmony.py` | 29 | Shim to `harmony/`? |
| `resonance.py` | 35 | Shim to `resonance/`? |
| `patterns.py` | 10 | Vestigial — check imports |
| `zodiac.py` | 0 | **Empty file** — delete |

### 8.3 Keep at Root (8 files)

- `__init__.py`, `__main__.py` — package essentials
- `run_mcp.py` — MCP server entry point
- `logging_config.py` — shared logging config
- `ai_contract.py` (76L), `arrow.py` (42L), `fileio.py` (84L) — core utilities
- `shell.py` (62L) — shell interface

---

## 9. Name Collision Analysis

### 9.1 `consolidation.py` × 4

| Location | LOC | Purpose |
|----------|-----|---------|
| `core/memory/consolidation.py` | 613 | **Canonical** — hippocampal replay, clustering |
| `core/automation/consolidation.py` | 530 | Automation consolidation |
| `intelligence/hologram/consolidation.py` | 258 | Holographic consolidation |
| `systems/automation/consolidation.py` | 16 | Thin wrapper — **delete** |

### 9.2 `governor.py` × 5

| Location | LOC | Purpose |
|----------|-----|---------|
| `core/governor.py` | 739 | **Canonical** |
| `dharma/governor.py` | 104 | Dharma-specific governor |
| `tools/handlers/governor.py` | 52 | MCP handler |
| `tools/registry_defs/governor.py` | 48 | Tool schema |
| `systems/governor.py` | 37 | Thin wrapper — **delete with systems/** |

### 9.3 `patterns.py` × 5

| Location | LOC | Purpose |
|----------|-----|---------|
| `cascade/patterns.py` | 279 | Cascade patterns |
| `intelligence/hologram/patterns.py` | 275 | Hologram patterns |
| `edge/patterns.py` | 275 | Edge patterns (different hash from hologram) |
| `utils/patterns.py` | 50 | Utility patterns |
| `patterns.py` (root) | 10 | **Vestigial** — likely just re-exports |

### 9.4 `sandbox.py` × 5

| Location | LOC | Purpose |
|----------|-----|---------|
| `execution/sandbox.py` | 375 | **Canonical** execution sandbox |
| `tools/sandbox.py` | 220 | Tool-level sandbox |
| `interfaces/api/sandbox.py` | 79 | API sandbox |
| `tools/registry_defs/sandbox.py` | 41 | Tool schema |
| `tools/handlers/sandbox.py` | 33 | MCP handler |

### 9.5 `hexagram_data.py` × 3

| Location | LOC | Purpose |
|----------|-----|---------|
| `intelligence/wisdom/hexagram_data.py` | ~200 | **EXACT DUPLICATE** |
| `gardens/wisdom/hexagram_data.py` | ~200 | **EXACT DUPLICATE** |
| `oracle/hexagram_data.py` | ~200 | **EXACT DUPLICATE** |

**Action:** Keep one (oracle/ is most logical), delete or shim the others.

### 9.6 Zodiac Quadruplication

| Location | LOC | Hash |
|----------|-----|------|
| `zodiac/zodiac_cores.py` | 704 | Unique — **canonical** |
| `gardens/connection/zodiac_cores.py` | 478 | Unique variant |
| `core/zodiac/zodiac_cores.py` | 25 | Shim |
| `gardens/metal/zodiac/zodiac_cores.py` | 25 | Shim |

---

## 10. `core/bridge/` — Legacy Layer (31 files, 3,622 LOC)

Marked deprecated with `DeprecationWarning` at import time. **Still has 7 active importers:**
- `tools/dispatch_table.py`
- `tools/handlers/misc.py`
- `tools/handlers/synthesis.py`
- `tools/handlers/sangha.py`
- `tools/handlers/dharma.py`
- `core/governor.py`
- `mcp_api_bridge.py`

**Recommendation:** Cannot delete yet. Plan migration of those 7 files to use canonical imports, then archive.

---

## 11. `autonomous_execution/` — Confirmed Full Duplicate

6 files, 1,418 LOC — **every .py file is an exact duplicate** of `autonomous/executor/`:
- `assessor.py`, `continuous_executor.py`, `limits.py`, `local_model_integration.py`, `objective_generator.py`
- `__init__.py` is a backward-compat shim with DeprecationWarning

**Only 2 importers:** `cli_autonomous_execution.py` and `autonomous/executor/continuous_executor.py`

**Action:** Rewire 2 importers → delete `autonomous_execution/` entirely → save 1,418 LOC.

---

## 12. Action Plan — Prioritized

### Phase 0: Immediate Cleanup (No Risk)

| Action | LOC Saved | Risk |
|--------|-----------|------|
| Delete `build/` | — | None (build artifacts) |
| Delete `temp_venv/` (571 MB) | — | None |
| Delete both `whitemagic.egg-info/` dirs | — | None |
| Delete `data/` (empty) | — | None |
| Delete `scripts/misc/get-pip.py` | 27,368 | None |
| Delete empty dirs: `core/analysis/`, `core/inference/`, `core/personality/`, `scripts/chmod/`, `scripts/cp/`, `scripts/+x/`, `scripts/u0026u0026/` | — | None |
| Delete `whitemagic/zodiac.py` (empty) | 0 | None |
| Add to `.gitignore`: `memory/`, `logs/`, `*.db`, `*.db-shm`, `*.db-wal`, `resonance_state.json`, `whitemagic_dream.log` | — | None |

### Phase 1: Move `_archived/` to `wm_archive/`

| Action | LOC Moved | Risk |
|--------|-----------|------|
| Move `_archived/` → `~/Desktop/wm_archive/whitemagic_archived/` | 46,444 | Low — 2 graceful imports already handle this |
| Move `windsurf_conversations/` → `wm_archive/` | — | None |
| Move session handoff .md files → `wm_archive/` | — | None |

### Phase 2: Delete Exact Duplicates

| Action | LOC Saved | Risk |
|--------|-----------|------|
| Delete `autonomous_execution/` (rewire 2 imports first) | 1,418 | Low |
| Deduplicate `hexagram_data.py` (keep oracle/) | ~400 | Low |
| Deduplicate `art_of_war.py` (keep intelligence/) | ~180 | Low |
| Deduplicate `council.py` root (keep core/orchestration/) | ~60 | Low |
| Deduplicate `core/zodiac/gan_ying_integration.py` | ~130 | Low |

### Phase 3: Reorganize Loose Files

| Action | Files | LOC | Risk |
|--------|-------|-----|------|
| Move 15 `cli_*.py` → `whitemagic/cli/` | 15 | 4,420 | Medium — update all imports |
| Move domain files to proper packages | ~12 | ~2,500 | Medium |
| Delete `systems/` (rewire 18 imports first) | 16 | 319 | Medium |

### Phase 4: Collapse Parallel Trees

| Action | Estimated LOC Saved | Risk |
|--------|---------------------|------|
| Merge `intelligence/` into `core/intelligence/` | ~3,000-5,000 | **High** — 8 divergent pairs, 87 importers |
| Consolidate zodiac triplication | ~500-700 | Medium |

### Phase 5: Archive Dead Scripts

| Action | LOC Moved | Risk |
|--------|-----------|------|
| Archive old dream_cycle versions (v7, v8, v9) | ~700 | None |
| Archive `scripts/legacy_satkona/` | 1,300 | None |
| Archive misc demos and one-offs | ~1,000 | None |

### Phase 6: Fuse Name Collisions

Requires per-file diff analysis before execution. Target: `consolidation.py` ×4, `patterns.py` ×5, `sandbox.py` ×5.

---

## 13. Projected Impact

| Metric | Current | After All Phases |
|--------|---------|-----------------|
| Active Python files | 802 | ~650 |
| Active Python LOC | 143,906 | ~105,000 |
| Scripts LOC | 42,063 | ~12,000 |
| `_archived/` LOC | 46,444 | 0 (moved to wm_archive) |
| Polyglot LOC | 20,164 | 20,164 (unchanged, Phase 2 expansion separate) |
| Polyglot % | 12.3% | ~16.1% (from Python reduction alone) |
| Disk footprint | 5.4 GB | ~4.2 GB |

---

*Report generated by deep-dive audit, Feb 9, 2026. All figures are from direct filesystem analysis.*
