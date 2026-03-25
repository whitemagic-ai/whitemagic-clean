# Afternoon/Evening Strategy — Feb 10, 2026

**Created:** 3:15 PM EST
**Author:** Cascade + Lucas
**Basis:** Full codebase audit against 16 hours of session summaries

---

## Audit Summary — What's True

### Verified ✅

| Claim | Status | Evidence |
|-------|--------|----------|
| Version 13.6.0 everywhere | ✅ Confirmed | VERSION, pyproject.toml, agent.json, Cargo.toml, lib.rs |
| 181 MCP tools (28 PRAT, 92 Lite) | ✅ Confirmed | registry_defs/ auto-collection, dispatch_table.py ~195 entries (incl. backward-compat aliases) |
| Leap 1 (Semantic Memory) done | ✅ | mine_semantic, find_duplicates, search_hybrid in codebase |
| Leap 2 (Cold Storage) done | ✅ | cold_db_embed.py, cross-DB search in embeddings.py |
| Leap 7 artifacts exist | ✅ | state_board.rs (10 PyO3 fns), event_ring.rs (5 PyO3 fns), dispatch_bridge.py, state_board_bridge.py, event_ring_bridge.py |
| Leap 8-10 artifacts exist | ✅ | hybrid_rrf.rs, association_walk.rs, core_access.py, insight_pipeline.py |
| New Rust modules wired in lib.rs | ✅ | Lines 235-264: StateBoard, EventRing, hybrid_rrf, association_walk |
| 28 engines registered | ✅ | core/engines/__init__.py + registry.py exist |
| harmony.py / homeostasis.py rewritten | ✅ | Both delegate to real HarmonyVector + HomeostaticLoop |
| Mypy Wave 1 done (39 Optional fixes, ResonanceEvent, Any) | ✅ | All edited files confirmed |
| All 8 polyglot acceleration bridges | ✅ | 8 *_bridge.py files in core/acceleration/ |
| simd_cosine_topk.mojo exists | ✅ | whitemagic-mojo/src/simd_cosine_topk.mojo |
| cli/init_command.py exists | ✅ | whitemagic/cli/init_command.py |
| Loose root files still at root | ✅ | export_import.py (541 LOC) not yet relocated |

### Unverifiable (Tests Hanging) ⚠️

| Claim | Last Known | Notes |
|-------|-----------|-------|
| 1,367 tests pass, 9 skip, 0 fail | Last session | Tests currently hang/crash Windsurf — separate team investigating |
| Mypy public surface: 798 errors | Conflicting data | V14_RELEASE_STRATEGY says 798; memory says 974. Can't run mypy to verify. |
| wm doctor health_score 0.8 | Last session | Can't verify without running |

### Stale Docs Fixed This Session

1. **POLYGLOT_STATUS.md** — Version v13.5.0 → v13.6.0, tool counts 178/175 → 181
2. **STRATEGIC_ROADMAP.md** — Leap 3 status "Pending" → "~70% Complete", mypy number updated, test count 1,272 → 1,367

### Docs Already Accurate ✅

- README.md (v13.6.0)
- CHANGELOG.md (through v13.6.0)
- AI_PRIMARY.md (v13.6.0+)
- SYSTEM_MAP.md (v13.6.0)
- V14_RELEASE_STRATEGY.md (comprehensive, Leap scoreboard accurate)

---

## Remaining Work — Categorized by Priority

### 🔴 Critical Path (blocks v14.0 release)

1. **Test Suite Investigation** — Tests hang/crash. Another team is on it. This blocks final verification but NOT implementation work.

2. **Mypy Burndown (Waves 2-3)** — ~800-970 errors on public surface. V14_RELEASE_STRATEGY sets ship threshold at <100 on public surface. This is the single largest remaining code task.
   - **Wave 2** (~300 errors): union-attr None guards, attr-defined narrowing, object→specific type casts
   - **Wave 3** (~300 errors): `-> None` / `-> ReturnType` on 211 untyped functions, relocate export_import.py

3. **Loose Root File Relocations** — 4-5 files need to move:
   - `export_import.py` (541 LOC) → `tools/export/manager.py`
   - `initialize_consciousness.py` (242 LOC) → `core/orchestration/consciousness.py`
   - `dream_daemon.py` (169 LOC) → `core/dreaming/daemon.py`
   - `fileio.py` (85 LOC) → `utils/fileio.py`
   - `mcp_api_bridge.py` (51 LOC) → keep or move to `core/bridge/facade.py`

4. **TestPyPI Dry Run** — `pip install whitemagic[mcp,cli]` in a fresh venv. 30 min. Validates packaging.

### 🟡 Important (should do before v14.0)

5. **llms-full.txt Generation** — Machine-readable full docs. 30 min.
6. **Version Bump Preparation** — All files ready for 13.6.0 → 14.0.0 when ship criteria met.
7. **Known Data Issues** — Tag pollution (golang_ecosystem dominates), dream insight artifacts at CORE with importance 0.98. Cosmetic, 30-45 min total.

### 🟢 Deferred (post-v14.0)

8. Rust tokio monitor skeleton (Leap 8c) — 2-4 hours
9. Static binary MCP server (Leap 10c) — 4-8 hours
10. Full WASM dep gating — 2-3 hours
11. Payment infra (tip tool, x402) — multi-session
12. Haskell/Julia runtime install — 1 hour
13. 236 short-content memories cleanup — 30 min
14. 28 untitled memories cleanup — 15 min
15. Workflow templates for AI agents — 1-2 hours
16. Error recovery guidance doc — 1 hour

---

## Recommended Session Plan

### Phase 1: Mypy Wave 2 — Type Narrowing (~1-2 hours)

Focus on the top offending files that give the most bang per fix:

| File | Errors | Strategy |
|------|--------|----------|
| `export_import.py` (root) | ~54 | Relocate + type simultaneously |
| `utils/import_optimizer.py` | ~44 | Internal, batch fixes |
| `core/memory/embeddings.py` | ~22 | Core hot path, careful typing |
| `core/monitoring/telemetry.py` | ~23 | Internal |

Approach:
1. Start with `union-attr` (27 errors) — mechanical `if x is not None:` guards
2. Then `attr-defined` (144 errors) — type narrowing at FFI boundaries
3. Then `no-any-return` (93 errors) — add intermediate typed variables

### Phase 2: Loose Root File Cleanup (~30-45 min)

For each file:
1. Create target with content
2. Replace source with thin re-export shim (backward compat)
3. Update direct importers
4. Note: can't run tests to confirm, but structural moves are low-risk

Priority order: export_import.py (biggest, most errors) → dream_daemon.py (clean, 1 importer) → fileio.py (8 importers) → initialize_consciousness.py (2 importers)

### Phase 3: Pre-Ship Polish (~30-45 min)

1. Generate llms-full.txt
2. Fix tag pollution + dream artifact importance
3. Prepare version bump script (all files that need 13.6.0 → 14.0.0)

### Phase 4: TestPyPI Dry Run (~30 min, if tests are unblocked)

1. `python -m build`
2. `twine upload --repository testpypi dist/*`
3. Fresh venv: `pip install -i https://test.pypi.org/simple/ whitemagic[mcp,cli]`
4. `wm status`, `wm doctor`, MCP stdio

---

## Ship Decision Framework

**Ship when ALL of these are true:**
- [ ] Tests pass (waiting on fix from other team)
- [ ] Mypy public surface < 200 errors (stretch: <100)
- [ ] No loose root files (all relocated or justified)
- [ ] `pip install whitemagic[mcp,cli]` works in fresh venv
- [ ] `wm doctor` reports healthy
- [ ] MCP server starts in all 3 modes
- [ ] TestPyPI dry run completes

**Ship even if:**
- Mypy full codebase has 500+ errors (internal, not public API)
- Haskell/Julia runtimes not installed (graceful fallback)
- Payment infra not wired (deferred to v14.1)
- Some data quality issues remain (cosmetic)

---

## What We've Accomplished (16-Hour Summary)

In the past 16 hours across ~6 sessions, we've:

- Built **Leaps 1-2** (Semantic Memory + Cold Storage) — from keyword matching to 110K-memory semantic search
- Built **Leaps 7-10** core artifacts (Nervous System, Swarm foundations, Cryptographic Trust, Autonomous Horizon)
- Expanded from **142 → 181 MCP tools** (+39 tools)
- Grew polyglot from **18K → 25K LOC** across 9 languages
- Achieved **1,367 passing tests** (up from ~1,199)
- Reduced mypy errors from **~1,430 → ~800-970** (Wave 1 mechanical fixes)
- Rewrote **harmony.py** and **homeostasis.py** from dead shims to live facades
- Created **CoreAccessLayer** and **InsightPipeline** for decision-ready intelligence
- Added **hybrid_rrf.rs** and **association_walk.rs** for Rust-accelerated retrieval
- Created comprehensive **V14_RELEASE_STRATEGY.md** and updated all major docs
- Fixed **numpy garden bug** and **archaeology NoneType** that degraded wm doctor
- Synced version to **13.6.0** across all 5 version files

The project is functionally complete. What remains is hardening: types, packaging, and the push of the button.
