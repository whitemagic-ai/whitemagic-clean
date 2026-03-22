# Python Distillation Plan — WhiteMagic v13+

**Created**: February 9, 2026  
**Status**: Planning — deep-dive review required before execution  
**Goal**: Reduce Python LOC by ~31% (143,906 → ~99,300), eliminate duplication, collapse parallel trees, reorganize package structure

**Prerequisite**: Full directory-by-directory deep-dive analysis before any code moves/deletes.

---

## Current State

| Metric | Value |
|--------|-------|
| Active Python files | ~790 |
| Active Python LOC | 143,906 |
| `_archived/` LOC | 46,444 (279 files) |
| `scripts/` LOC | 42,063 (134 files, 27K is `get-pip.py`) |
| Exact duplicate groups | 12 (covering ~3,400 wasted LOC) |
| Parallel trees | 4 major (intelligence, zodiac, autonomous, systems) |
| Loose top-level files | 40 (8,291 LOC in `whitemagic/` root) |
| Single-file subpackages | 18 |
| Never-imported files | 5+ confirmed dead |

---

## Objective 1: Delete Exact Duplicates (~3,400 LOC)

**Difficulty**: Easy  
**Risk**: Low (byte-identical copies)  
**Prerequisite**: Verify import paths before deleting; update any direct imports to point to canonical location.

### Duplicate Groups

| File | Keep (canonical) | Delete |
|------|-----------------|--------|
| `continuous_executor.py` (688 LOC) | `autonomous/executor/` | `autonomous_execution/` |
| `objective_generator.py` (422 LOC) | `autonomous/executor/` | `autonomous_execution/` |
| `hexagram_data.py` (206 LOC) | `oracle/` | `intelligence/wisdom/`, `gardens/wisdom/` |
| `assessor.py` (151 LOC) | `autonomous/executor/` | `autonomous_execution/` |
| `gan_ying_integration.py` (141 LOC) | `core/zodiac/` | `gardens/metal/zodiac/` |
| `limits.py` (99 LOC) | `autonomous/executor/` | `autonomous_execution/` |
| `council.py` (59 LOC) | `core/orchestration/` | top-level `council.py` |
| `art_of_war.py` (50 LOC) | `gardens/wisdom/` or `intelligence/wisdom/` | the other copy |
| `local_model_integration.py` (28 LOC) | `autonomous/executor/` | `autonomous_execution/` |

### `autonomous_execution/` — Entire Directory is Duplicate

All 6 files in `autonomous_execution/` are byte-identical to `autonomous/executor/`. After deletion, the `autonomous_execution/__init__.py` should become a thin deprecation shim:

```python
"""Backward-compat shim. Use whitemagic.autonomous.executor instead."""
import warnings
warnings.warn("whitemagic.autonomous_execution is deprecated, use whitemagic.autonomous.executor", DeprecationWarning, stacklevel=2)
from whitemagic.autonomous.executor import *
```

### Execution Steps

1. For each duplicate group, grep all imports pointing to the "delete" path
2. Update imports to point to canonical path
3. Replace deleted file with thin re-export shim (or delete entirely if 0 importers)
4. Run test suite to confirm no breakage
5. Move deleted files to `~/Desktop/wm_archive/duplicates/`

---

## Objective 2: Archive Dead Code & Clean Scripts (~37,000 LOC)

**Difficulty**: Easy  
**Risk**: Low  

### 2a. `_archived/` Directory (279 files, 46,444 LOC)

Already excluded from active development. Move entire tree to `~/Desktop/wm_archive/whitemagic_archived/`.

### 2b. Dead Loose Files (0 importers, confirmed orphans)

| File | LOC | Evidence |
|------|-----|---------|
| `cdn.py` | 358 | 0 importers, CDN upload logic — no active CDN |
| `summaries.py` | 348 | 0 importers |
| `arrow.py` | 42 | 0 importers |
| `diagnose.py` | 114 | 0 importers |
| `shell.py` | 62 | 0 importers |
| **Total** | **924** | |

Move to `~/Desktop/wm_archive/dead_code/`.

### 2c. `scripts/` Cleanup (134 files, 42,063 LOC)

#### Delete Immediately
- **`scripts/misc/get-pip.py`** — 27,368 LOC vendored pip installer. Use `python -m ensurepip` instead.

#### Review for Useful Logic, Then Archive
These scripts may contain algorithms, heuristics, or patterns worth extracting into the main codebase:

| Script Category | Files | Total LOC | Review Priority |
|----------------|-------|-----------|-----------------|
| **Dream cycle iterations** (v8, v9, v10) | 3 | 753 | Medium — may have evolved heuristics |
| **Satkona versions** (v1, v3, v4, v5) | 4 | 1,524 | Medium — coordinate encoding variations |
| **Bulk ingest/sweep** | 9 | ~2,500 | High — may contain useful DB patterns |
| **Test/verify one-shots** | 56 | ~5,000 | Low — mostly superseded by test suite |
| **Benchmark scripts** | 2 | ~400 | Low — move to `tests/benchmarks/` |
| **Remaining misc** | ~60 | ~4,500 | Case-by-case |

#### Review Process
1. For each script, check: Does it contain logic not present in the main codebase?
2. If yes: Extract the useful function/algorithm into the appropriate module
3. If no: Move directly to `~/Desktop/wm_archive/scripts/`
4. Keep only actively-used operational scripts (e.g., `galactic_sweep_direct.py`)

---

## Objective 3: Collapse Parallel Trees (~8,000–10,000 LOC)

**Difficulty**: Medium  
**Risk**: Medium (import chains, possible behavioral differences in diverged copies)  
**Prerequisite**: Deep-dive comparison of each collision pair before merging.

### 3a. `intelligence/` (60 files, 11,359 LOC) → Merge into `core/intelligence/` (33 files, 5,832 LOC)

This is the single largest structural debt. 10 files share the same basename across both trees:

| Basename | `intelligence/` LOC | `core/intelligence/` LOC | Status |
|----------|---------------------|--------------------------|--------|
| `predictive_engine.py` | 648 | 651 | **Diverged** — diff required |
| `kaizen_engine.py` | ? | ? | Need comparison |
| `serendipity_engine.py` | ? | ? | Need comparison |
| `confidence.py` | ? | ? | Need comparison |
| `sub_clustering.py` | ? | ? | Need comparison |
| `tag_normalizer.py` | ? | ? | Need comparison |
| `title_generator.py` | ? | ? | Need comparison |
| `unified_patterns.py` | ? | ? | Need comparison |

#### Merge Protocol
1. **Diff each pair** — if identical, delete the non-canonical copy
2. **If diverged** — identify which has the newer/better logic, merge manually
3. **Files unique to `intelligence/`** — evaluate: move to `core/intelligence/` or archive
4. **Update all imports** — `from whitemagic.intelligence.X` → `from whitemagic.core.intelligence.X`
5. **Create deprecation shim** — `intelligence/__init__.py` re-exports from `core/intelligence/`
6. **Run test suite** after each sub-step

### 3b. Triple Zodiac Tree

| Location | Files | LOC |
|----------|-------|-----|
| `zodiac/` | 4 | 704 (main `zodiac_cores.py`) |
| `core/zodiac/` | 5 | ~200 |
| `gardens/*/zodiac/` | 7 | ~300 |

All three have different hashes for `zodiac_cores.py`. The 704-LOC version in `zodiac/` is likely canonical. Consolidate to one location.

### 3c. `autonomous/` vs `autonomous_execution/`

Already addressed in Objective 1 — `autonomous_execution/` is entirely byte-identical to `autonomous/executor/`.

### 3d. `systems/` (16 files, 319 LOC)

Every file is a thin wrapper (largest is 51 LOC). Real implementations live in `core/`. Delete the entire `systems/` tree and update any imports.

---

## Objective 4: Reorganize Package Structure

**Difficulty**: Medium  
**Risk**: Medium (import path changes across entire codebase)  
**Goal**: Nothing sits in `whitemagic/` root except `__init__.py`, `__main__.py`, `config.py`, and entry points.

### 4a. Relocate 13 `cli_*.py` Files (3,567 LOC) → `cli/`

| File | LOC | Target |
|------|-----|--------|
| `cli_app.py` | 2,368 | `cli/app.py` (then split into submodules) |
| `cli_sangha.py` | 252 | `cli/sangha.py` |
| `cli_watcher.py` | 237 | `cli/watcher.py` |
| `cli_archaeology.py` | 194 | `cli/archaeology.py` |
| `cli_rust.py` | 174 | `cli/rust.py` |
| `cli_commands_gardens.py` | 169 | `cli/commands_gardens.py` |
| `cli_prat.py` | 165 | `cli/prat.py` |
| `cli_autonomous_execution.py` | 158 | `cli/autonomous.py` |
| `cli_commands_intelligence.py` | 152 | `cli/commands_intelligence.py` |
| `cli_fast.py` | 150 | `cli/fast.py` |
| `cli_zodiac.py` | 147 | `cli/zodiac.py` |
| `cli_commands_symbolic.py` | 108 | `cli/commands_symbolic.py` |
| `cli_cache.py` | 88 | `cli/cache.py` |
| `cli_scratchpad.py` | 33 | `cli/scratchpad.py` |
| `cli_local.py` | 25 | `cli/local.py` |

### 4b. Absorb 18 Single-File Subpackages

| Package | LOC | Absorb Into |
|---------|-----|-------------|
| `immune/` | 628 | `core/immune/` |
| `search/` | 541 | `core/memory/` (search is memory search) |
| `docs/` | 417 | `utils/` |
| `db/` | 412 | `core/memory/` |
| `cache/` | 354 | `core/` |
| `orchestration/` | 348 | `core/orchestration/` |
| `prompts/` | 302 | `ai/` |
| `hardware/` | 205 | `edge/` |
| `inference/` | 189 | `ai/` |
| `sessions/` | 166 | `core/` |
| `safety/` | 166 | `core/` |
| `auth/` | 163 | `interfaces/api/` |
| `benchmarks/` | 159 | `tests/benchmarks/` |
| `continuity/` | 132 | `core/` |
| `metrics/` | 45 | `utils/` |
| `emergence/` | 7 | Delete (stub) |
| `resonance/` | 4 | Delete (stub, real code in `core/resonance/`) |

### 4c. Relocate Remaining Loose Files

| File | LOC | Target |
|------|-----|--------|
| `symbolic.py` | 538 | `core/symbolic.py` |
| `export_import.py` | 537 | `tools/handlers/` (already has one) |
| `logging_config.py` | 263 | `config/logging.py` |
| `initialize_consciousness.py` | 241 | `core/orchestration/` |
| `stats.py` | 185 | `utils/` |
| `dream_daemon.py` | 168 | `core/dreaming/` |
| `recall.py` | 166 | `core/memory/` |
| `homeostasis.py` | 114 | `harmony/` (already has homeostatic_loop.py) |
| `strategy.py` | 78 | `core/` |
| `ai_contract.py` | 76 | `ai/` |
| `mcp_api_bridge.py` | 50 | `interfaces/` |
| `haskell_bridge.py` | 9 | `bridges/haskell/` |
| `zodiac.py` | 0 | Delete (empty file) |
| `patterns.py` | 10 | Delete or merge into `core/patterns/` |

### Execution Protocol
1. Create target directories if needed
2. `git mv` each file
3. Update all imports (use `sed` or IDE refactoring)
4. Create backward-compat shims at old locations for external tools
5. Run full test suite
6. Remove shims after confirming nothing breaks

---

## Objective 5: Fuse Near-Duplicate Name Collisions (~2,000–4,000 LOC)

**Difficulty**: High  
**Risk**: High (requires understanding what each variant does differently)  
**Prerequisite**: Line-by-line diff of each collision group in the deep-dive session.

### 5a. `consolidation.py` (4 variants, 1,417 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `core/memory/consolidation.py` | 613 | Memory deduplication, merge, decay |
| `core/automation/consolidation.py` | 530 | Automated consolidation scheduling |
| `intelligence/hologram/consolidation.py` | 258 | Holographic coordinate consolidation |
| `systems/automation/consolidation.py` | 16 | Thin wrapper (delete) |

**Action**: Keep `core/memory/consolidation.py` as the engine, merge scheduling logic from `core/automation/` into it as a `ConsolidationScheduler` class, absorb holographic logic as a method. Delete wrapper.

### 5b. `governor.py` (5 variants, 980 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `core/governor.py` | 739 | **Canonical** — full Governor implementation |
| `dharma/governor.py` | 104 | Dharma-specific governor subset |
| `tools/handlers/governor.py` | 52 | MCP handler (keep, it's a handler) |
| `tools/registry_defs/governor.py` | 48 | Tool definitions (keep, it's a registry) |
| `systems/governor.py` | 37 | Thin wrapper (delete) |

**Action**: Merge `dharma/governor.py` into `core/governor.py` as a method. Delete `systems/governor.py`. Keep the handler and registry_defs as-is (they serve different purposes).

### 5c. `patterns.py` (5 variants, 889 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `cascade/patterns.py` | 279 | Cascade execution patterns |
| `intelligence/hologram/patterns.py` | 275 | Holographic pattern detection |
| `edge/patterns.py` | 275 | Edge deployment patterns |
| `utils/patterns.py` | 50 | Shared pattern utilities |
| `patterns.py` (root) | 10 | Dead stub (delete) |

**Action**: These likely serve genuinely different domains. Deep-dive needed to confirm. Potential to extract shared pattern primitives into `utils/patterns.py` and have others import from there.

### 5d. `sandbox.py` (5 variants, 748 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `execution/sandbox.py` | 375 | **Canonical** — execution sandbox |
| `tools/sandbox.py` | 220 | Tool-specific sandbox wrapper |
| `interfaces/api/sandbox.py` | 79 | API sandbox endpoint |
| `tools/registry_defs/sandbox.py` | 41 | Tool definitions |
| `tools/handlers/sandbox.py` | 33 | MCP handler |

**Action**: `tools/sandbox.py` likely wraps `execution/sandbox.py`. Fuse into one, keep handler/registry/api as-is.

### 5e. `token_economy.py` (3 variants, 430 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `autonomous/token_economy.py` | 319 | **Canonical** — full token budget system |
| `core/token_economy.py` | 90 | Subset/shim |
| `systems/token_economy.py` | 21 | Thin wrapper (delete) |

**Action**: Merge `core/token_economy.py` into `autonomous/token_economy.py`. Delete wrapper.

### 5f. `multi_agent.py` (4 variants, 542 LOC)

| Location | LOC | Role |
|----------|-----|------|
| `gardens/wonder/multi_agent.py` | 292 | Garden-specific multi-agent |
| `core/immune/defense/multi_agent.py` | 198 | Immune system multi-agent |
| `cascade/multi_agent.py` | 43 | Cascade multi-agent |
| `systems/immune/defense/multi_agent.py` | 9 | Thin wrapper (delete) |

**Action**: These serve different domains (garden, immune, cascade). Extract shared base class into `agents/multi_agent_base.py`, have each inherit. Delete wrapper.

### Fusion Protocol
1. **Diff** each pair/group in the deep-dive session
2. **Identify** shared logic vs domain-specific logic
3. **Extract** shared primitives into a canonical location
4. **Refactor** domain-specific files to import from shared
5. **Delete** thin wrappers and shims
6. **Test** after each fusion

---

## Objective 6: Full Deep-Dive Review (Next Session)

**Difficulty**: Time-intensive  
**Goal**: Before executing Objectives 1–5, perform a comprehensive directory-by-directory analysis.

### Review Checklist

For every directory and file in `whitemagic/`:
1. **Purpose**: What does this file/module do?
2. **Usage**: Who imports it? (grep importers count)
3. **Duplication**: Is it duplicated elsewhere?
4. **Quality**: Is the code well-structured or a quick hack?
5. **Extractable**: Could this be offloaded to a polyglot language?
6. **Archivable**: Is this dead, legacy, or superseded?

### Priority Order
1. `core/` (253 files) — the heart, must be clean
2. `tools/` (104 files) — the MCP interface, high traffic
3. `intelligence/` (60 files) — largest parallel tree candidate
4. `gardens/` (98 files) — domain modules, check for stubs
5. `interfaces/` (51 files) — API/CLI layer
6. `cascade/` (13 files), `edge/` (12 files), `autonomous/` (13 files)
7. Everything else (loose files, small packages)

### Also Review
- `whitemagic-julia/` — 3 existing Julia source files (225 LOC) + Python bridge stub
- `scripts/` — 134 files, identify anything worth extracting before archiving
- `tests/` — ensure coverage maps to active code, remove tests for deleted modules

---

## Expected Outcome

| Metric | Before | After | Change |
|--------|--------|-------|--------|
| Active Python LOC | 143,906 | ~99,300 | **-31%** |
| Active Python files | ~790 | ~550 | **-30%** |
| Duplicate groups | 12 | 0 | **-100%** |
| Parallel trees | 4 | 0 | **-100%** |
| Loose root files | 40 | ~5 | **-87%** |
| Single-file packages | 18 | 0 | **-100%** |
| `scripts/` LOC | 42,063 | ~5,000 | **-88%** |
| Polyglot % (no new code) | 14.2% | 19.4% | **+5.2pp** |

---

**Author**: Lucas Bailey + Cascade  
**Next Step**: Full deep-dive review before any execution
