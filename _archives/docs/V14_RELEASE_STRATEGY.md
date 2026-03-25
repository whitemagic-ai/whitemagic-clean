# WhiteMagic v14.0 Release Strategy

**Created:** 2026-02-10
**Author:** Cascade + Lucas
**Status:** Active — working document

---

## Current State (as of this writing)

| Metric | Value |
|--------|-------|
| Version | 13.6.0 |
| Tests | 1,367 passed, 9 skipped, 0 failed |
| MCP Tools | 181 (28 PRAT, 92 Lite) |
| Python LOC | ~141K across ~763 files |
| Polyglot LOC | ~25K across 8 languages (14.9%) |
| Mypy errors (public surface, strict) | 798 (down from ~1,044) |
| Mypy errors (full codebase, relaxed) | 1,089 (down from ~1,430) |
| CI Pipeline | 6 jobs (core, lint, rust-quality, security, extras, packaging) |
| Docker | Multi-stage Dockerfile ready |
| Release workflow | PyPI + GHCR + GitHub Releases |

---

## Leap Scoreboard

| Leap | Name | Status | Notes |
|------|------|--------|-------|
| 1 | Semantic Memory Revolution | ✅ Done | v13.5 |
| 2 | Cold Storage Awakening | ✅ Done | v13.6 |
| 3 | Test Fortress & Type Safety | 🔧 ~70% | Mypy burndown remaining |
| 4 | Developer Experience & Docs | 🔧 ~80% | llms-full.txt, workflow templates |
| 5 | Packaging & Distribution | 🔧 ~85% | TestPyPI dry run needed |
| 5.5 | Gratitude Architecture | 🔧 Discovery done | Payment infra deferred |
| 6 | Ship Day | ⬜ Blocked on 3-5 | Version bump + tag |
| 7 | The Nervous System | ✅ Done | StateBoard, EventRing, Zig Dispatch |
| 8 | The Swarm | ✅ 2/3 | Tokio monitor deferred |
| 9 | Cryptographic Trust | ✅ Done | Manifests, Merkle trees, wallet gov |
| 10 | Autonomous Horizon | ✅ 2/3 | Static binary deferred |

---

## Phase A: Mypy Burndown (Leap 3 completion)

### Current error profile (public surface — strict mode)

| Error Category | Count | Fix Strategy |
|----------------|-------|-------------|
| Missing return type annotation (`no-untyped-def`) | 211 | Add `-> type` to function signatures |
| `attr-defined` (missing attribute on inferred object type) | 144 | Type-narrow values before attribute access |
| `no-any-return` (Returning Any) | 93 | Add explicit casts or narrow return paths |
| `assignment` (incompatible assignment) | 84 | Normalize types at assignment boundaries |
| `arg-type` (incompatible argument type) | 52 | Fix call signatures and coercions |
| `annotation-unchecked` | 51 | Add typed containers for dynamic structures |
| `var-annotated` | 34 | Add explicit variable annotations |
| `import-not-found` | 30 | Add stubs / conditional imports / ignores |
| `union-attr` (None access) | 27 | Add `is not None` guards |
| `call-arg` | 27 | Reconcile callsite argument mismatches |
| `misc` | 21 | Rename shadowed symbols / cleanup edge cases |
| `operator` | 16 | Type-narrow operands |
| Other | ~8 | Mixed bag — file-by-file |

### Top offending files (public surface)

| File | Errors | Priority |
|------|--------|----------|
| `export_import.py` (root) | 54 | 🔴 Relocate to package + fix |
| `utils/import_optimizer.py` | 44 | 🟡 Internal utility |
| `core/monitoring/telemetry.py` | 23 | 🟡 Internal |
| `core/memory/embeddings.py` | 22 | 🔴 Core hot path |
| `oracle/quantum_iching.py` | 15 | 🟢 Low priority |
| `gardens/browser/actions.py` | 15 | 🟢 Low priority |
| `core/immune/response.py` | 15 | 🟡 Security surface |
| `integration/hub.py` | 14 | 🟢 Low priority |
| `core/intelligence/agentic/auto_activation.py` | 14 | 🟡 Agentic subsystem |
| `core/intelligence/agentic/anti_loop.py` | 14 | 🟡 Agentic subsystem |

### Approach

**Wave 1 — Mechanical fixes ✅ DONE**
These pattern-based edits have been applied:
1. ~~Replace `any` (lowercase, builtin) used as a type annotation with `Any` from `typing`~~ ✅ Fixed 7
2. ~~Add `timestamp` default to `ResonanceEvent`~~ ✅ Fixed (cascading effect on 15+ callers)
3. ~~Fix `param: Type = None` → `param: Type | None = None`~~ ✅ Fixed 39 instances across 18 files
4. Add `-> None` to all `__init__` methods missing return types — remaining
5. Add obvious return type annotations — remaining

**Wave 2 — Type-narrowing fixes (~300 errors, ~1-2 hours)**
1. Add `if x is not None:` guards for `union-attr` errors (27 remaining)
2. Narrow `object` to `list`/`dict`/`str` where the code proves the type
3. Fix `attr-defined` errors (144 remaining — many in FFI bridges)

**Wave 3 — Structural fixes (~300 errors, ~2-3 hours)**
1. Add `-> None` / `-> ReturnType` to 211 untyped functions
2. `export_import.py` — relocate to `whitemagic/tools/export/` subpackage, type all methods
3. Fix `no-any-return` errors in non-FFI code by adding intermediate typed variables

### Mypy Extension Note
If a Windsurf mypy extension is installed, it should provide inline error
highlighting passively — no explicit "activation" needed. It reads the
`[tool.mypy]` config from `pyproject.toml`. If errors aren't showing
inline, check that the extension's Python interpreter is set to the venv
at `.venv/bin/python`.

---

## Phase B: Loose Root File Cleanup

### Files to relocate

| File | LOC | Target | Importers | Action |
|------|-----|--------|-----------|--------|
| `export_import.py` | 541 | `tools/export/manager.py` | `tools/handlers/export_import.py` (2 import sites) | Move + update handler imports |
| `initialize_consciousness.py` | 242 | `core/orchestration/consciousness.py` | `core/bridge/system.py` (+ self import) | Move + update bridge importer |
| `dream_daemon.py` | 169 | `core/dreaming/daemon.py` | cli_app | Move + update 1 importer |
| `fileio.py` | 85 | `utils/fileio.py` | 8 importers across `edge/`, `autonomous/`, `core/temporal/` | Move + update all call sites |
| `mcp_api_bridge.py` | 51 | Keep or move to `core/bridge/facade.py` | `cli/cli_app.py`, `cli/doctor.py` (10 import sites) | High-touch move; keep for v14 unless needed |

### Files to keep at root (essential)

| File | LOC | Reason |
|------|-----|--------|
| `__init__.py` | — | Package root |
| `__main__.py` | — | Entry point |
| `config.py` | — | Configuration |
| `run_mcp.py` | — | MCP server entry |
| `logging_config.py` | — | Logging setup |
| `harmony.py` | 112 | **Rewritten** — now delegates to real HarmonyVector |
| `homeostasis.py` | 152 | **Rewritten** — now delegates to real subsystems |

### Process
For each relocation:
1. Create target file with content
2. Replace source file with thin re-export shim (backward compat)
3. Update direct importers
4. Run tests to confirm

---

## Phase C: Remaining Known Issues

### Tag pollution: `golang_ecosystem` still dominates
- **Root cause**: 4,230 memories in a single constellation from bulk Go file ingestion
- **Fix**: Run tag normalization script to demote bulk-ingest tags
- **Effort**: 30 min script run
- **Priority**: Medium — cosmetic, doesn't affect functionality

### Dream insight artifacts at importance 0.98 in CORE
- **Root cause**: Auto-generated dream insights were promoted to CORE with high importance
- **Fix**: Demote to MID_BAND, cap auto-generated importance at 0.7
- **Effort**: 15 min
- **Priority**: Low — doesn't affect functionality

### ~~Pre-existing test failure: `test_prat_router` mapping_coverage~~
- **Status**: ✅ RESOLVED — test now passes (3 gratitude tools were mapped at some point)

---

## Phase D: Deferred Items (Post-v14.0)

| Item | Leap | Effort | Priority |
|------|------|--------|----------|
| Rust tokio monitor skeleton | 8c | 2-4 hours | Low |
| Static binary MCP server | 10c | 4-8 hours | Low |
| Full WASM dep gating (uuid, rayon, sysinfo, memmap2) | 10 | 2-3 hours | Low |
| `llms-full.txt` generation | 4 | 30 min | Medium |
| Workflow templates for AI agents | 4 | 1-2 hours | Medium |
| Error recovery guidance doc | 4 | 1 hour | Medium |
| TestPyPI dry run | 5 | 30 min | High |
| Payment infra (tip tool, x402) | 5.5 | Multi-session | Low |
| Haskell/Julia runtime install | — | 1 hour | Low |
| 236 short-content memories cleanup | — | 30 min | Low |
| 28 untitled memories cleanup | — | 15 min | Low |

---

## Phase E: Ship Day Checklist (Leap 6)

**Prerequisites (all must pass):**
- [ ] Mypy public surface < 100 errors (currently 798)
- [ ] All tests pass (currently ✅ 1,367)
- [ ] `wm doctor` reports healthy (currently ✅ 0.8)
- [ ] `pip install whitemagic[mcp,cli]` works in fresh venv
- [ ] `wm doctor` clean in fresh venv
- [ ] MCP server starts in all 3 modes (stdio, PRAT, Lite)
- [ ] Core tool loop works (create → search → gnosis → capabilities)
- [ ] TestPyPI dry run completes
- [ ] PRAT routing with _resonance and _garden metadata ✅
- [ ] `test_prat_router` mapping_coverage passes
- [ ] No loose root files (all relocated or justified)

**Ship actions:**
1. Bump VERSION to 14.0.0
2. Update pyproject.toml, Cargo.toml, agent.json, README.md
3. Write v14.0 RELEASE_NOTES.md
4. Final test run
5. `git tag v14.0.0 && git push --tags`
6. CI publishes to PyPI + GHCR automatically

---

## Recommended Afternoon Session Plan

### Hour 1: Mypy Wave 1 (Mechanical fixes) ✅ DONE
- ~~Fix `builtins.any` vs `Any`~~ ✅ (7 errors → 0)
- ~~Add `ResonanceEvent` timestamp default~~ ✅ (15+ cascading errors → 0)
- ~~Fix 39 `param: Type = None` Optional patterns~~ ✅ (39 errors → 0)
- **Result: ~246 errors eliminated from public surface (from ~1,044 to 798)**

### Hour 2: Mypy Wave 2 (Type narrowing)
- Add None guards for union-attr errors
- Narrow object types
- Focus on top offending files: export_import.py, embeddings.py
- **Target: ~300 more errors eliminated → ~300 remaining**

### Hour 3: Cleanup + Pre-Ship
- Relocate loose root files (export_import.py, dream_daemon.py, etc.)
- Fix 3 unmapped gratitude tools in PRAT router
- TestPyPI dry run if time permits
- **Target: Clean file tree, all known issues resolved**

### Ship decision point:
If mypy is under 200 errors and all tests pass, we can bump to v14.0.0
and tag. The remaining mypy errors can be burndown-ed in CI with
`continue-on-error: true` without blocking the release.
