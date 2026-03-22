# P2 Static Quality Ratchet Plan (2026-02-09)

## Snapshot After Current Pass

- Ruff (`whitemagic`, excluding `_archived`): **571**
  - `E402`: 571
  - `E741/F811/F823`: 0 (burned down)
- Mypy (`whitemagic/interfaces` + `whitemagic/tools`): **1422 errors in 242 files**
- Test suite: **1199 passed, 4 skipped**

## Scouting Run 2 (Project-Wide)

- Full mypy (`whitemagic/**`, includes `_archived`): **3692 errors in 636 files** (`1068` files checked)
- Full mypy (excluding `_archived` in analysis): **2494** errors
- `interfaces/tools` residual: **0** (clean in this ratchet scope)

Top mypy codes (non-archived):
- `no-untyped-def`: 1255
- `assignment`: 229
- `attr-defined`: 217
- `no-any-return`: 181
- `arg-type`: 130

Top mypy files (non-archived):
- `whitemagic/cli_app.py`: 77
- `whitemagic/optimization/polyglot_router.py`: 38
- `whitemagic/core/immune/response.py`: 34
- `whitemagic/core/automation/consolidation.py`: 33

Scoped cluster sizing (non-archived):
- **Cluster A (bridge + fusions)**: 24
  - `whitemagic/core/fusions.py` (6)
  - `whitemagic/core/bridge/tools.py` (12)
  - `whitemagic/core/bridge/garden.py` (3)
  - `whitemagic/core/bridge/gana.py` (2)
  - `whitemagic/core/bridge/memory.py` (1)
- **Cluster B (automation)**: 75
  - `whitemagic/core/automation/consolidation.py` (33)
  - `whitemagic/core/automation/orchestra.py` (21)
  - `whitemagic/automation/daemon.py` (21)
- **Cluster C (optimization/polyglot)**: 50
  - `whitemagic/optimization/polyglot_router.py` (38)
  - `whitemagic/optimization/rust_accelerators.py` (12)
- **Cluster D (immune stack)**: 40
  - `whitemagic/core/immune/response.py` (34)
  - `whitemagic/core/immune/health_check.py` (5)
  - `whitemagic/core/immune/pattern_immunity.py` (1)

Ruff scout:
- Global (excluding `_archived`): **588**
  - `E402`: 571
  - `E741`: 11
  - `F811`: 5
  - `F823`: 1
- Non-E402 tail is small (**17 total**) and suitable for a dedicated quick cleanup pass.

Security/risk scout:
- No active `shell=True` execution in `.py` sources (only `shell=False` comments in safe executor).
- `exec(...)` remains in `whitemagic/execution/sandbox.py`, behind explicit env guard (`WHITEMAGIC_ENABLE_IN_PROCESS_EXEC=true`) and marked as not recommended for untrusted input.

## What Was Completed In This Pass (Follow-up Cluster)

- Cleared focused mypy for this 9-file hotspot cluster:
  - `whitemagic/interfaces/api/websocket.py`
  - `whitemagic/interfaces/api/auth_unified.py`
  - `whitemagic/interfaces/api/db_engine.py`
  - `whitemagic/interfaces/api/routes/performance.py`
  - `whitemagic/interfaces/api/middleware/security.py`
  - `whitemagic/interfaces/api/middleware/rate_limit.py`
  - `whitemagic/interfaces/api/middleware/metrics.py`
  - `whitemagic/interfaces/api/database_sqlalchemy.py`
  - `whitemagic/tools/gnosis.py`
- Added optional-import guards and typed fallbacks for `slowapi` and JWT module loading.
- Normalized middleware signatures and return annotations for FastAPI/Starlette call chains.
- Hardened DB fallback typing (`AsyncIterator[Any]` where stub and SQLAlchemy sessions can both flow).
- Preserved runtime behavior; only static quality and type-safety changes.

## What Was Completed In This Pass (Ratchet Continuation)

- Cleared this 7-file hotspot cluster:
  - `whitemagic/interfaces/tui.py`
  - `whitemagic/interfaces/cli/graph.py`
  - `whitemagic/tools/sandbox.py`
  - `whitemagic/interfaces/terminal/config.py`
  - `whitemagic/tools/introspection.py`
  - `whitemagic/tools/capability_matrix.py`
  - `whitemagic/tools/dependency_graph.py`
- Fixed a real runtime issue in CLI graph (`Console.logger.info` -> `Console.print`).
- Reduced `interfaces/tools` residual from **60** to **32** errors.
- Created detailed report: `audit/P2_RATCHET_REPORT_2026_02_09_PASS2.md`.

## What Was Completed In This Pass (Ratchet Continuation 2)

- Cleared this 6-file hotspot cluster:
  - `whitemagic/interfaces/api/rate_limiter.py`
  - `whitemagic/interfaces/api/routes/search.py`
  - `whitemagic/interfaces/cli/exec.py`
  - `whitemagic/interfaces/api/middleware/auth.py`
  - `whitemagic/tools/envelope.py`
  - `whitemagic/tools/audit_export.py`
- Replaced nonexistent telemetry accessor in audit export (`get_recent`) with `get_summary()['recent_events']`.
- Reduced `interfaces/tools` residual from **32** to **17** errors.
- Created detailed report: `audit/P2_RATCHET_REPORT_2026_02_09_PASS3.md`.

## What Was Completed In This Pass (Ratchet Continuation 3)

- Cleared the final residual `interfaces/tools` cluster:
  - `whitemagic/tools/starter_packs.py`
  - `whitemagic/interfaces/api/database.py`
  - `whitemagic/interfaces/terminal/audit.py`
  - `whitemagic/tools/tui/galaxy.py`
  - `whitemagic/interfaces/terminal/tui.py`
  - `whitemagic/interfaces/terminal/approver.py`
  - `whitemagic/interfaces/dashboard/server.py`
  - `whitemagic/tools/handlers/cyberbrain.py`
  - `whitemagic/tools/handlers/export_import.py`
  - `whitemagic/tools/tool_permissions.py`
  - `whitemagic/interfaces/api/dependencies.py`
  - `whitemagic/tools/handlers/governance.py`
  - `whitemagic/interfaces/api/routes/api_keys.py`
- Reduced `interfaces/tools` residual from **17** to **0**.
- Created detailed report: `audit/P2_RATCHET_REPORT_2026_02_09_PASS4.md`.

## What Was Completed In This Pass (Ratchet Continuation 4)

- Cleared Cluster A (`core/bridge/*` + `core/fusions.py`) from the scouting run:
  - `whitemagic/core/bridge/tools.py`
  - `whitemagic/core/bridge/garden.py`
  - `whitemagic/core/bridge/gana.py`
  - `whitemagic/core/bridge/memory.py`
  - `whitemagic/core/fusions.py`
- Fixed real API/type mismatches, including:
  - `DriveCore.process_event` vs `on_event` compatibility path in fusions.
  - `ResonanceEvent` timestamp construction and temporal scheduler bridge wiring.
  - Legacy websocket set mutation bug in `interfaces/nexus_api.py` (`-=` local shadow) via `difference_update`.
- Burned down all non-E402 Ruff tail (`E741/F811/F823`):
  - Ruff: **588 → 571** (now E402-only).
- Mypy deltas:
  - Full project: **3692 → 3625** total (includes `_archived`).
  - Full project non-archived analysis: **2494 → 2454**.
  - `interfaces + tools`: **1450 → 1422**.
- Validation:
  - `ruff` targeted checks on edited files: pass
  - `pytest -q --no-header tests`: **1199 passed, 4 skipped**

## What Was Completed In This Pass

- Cleared `mypy` for the entire `whitemagic/tools/handlers/` package.
- Fixed broken import path in watcher handlers (`whitemagic.core.semantic_fs`).
- Resolved duplicate session handoff handler conflict by introducing explicit `summary` action routing.
- Added targeted typing and casts in:
  - `whitemagic/tools/unified_api.py`
  - `whitemagic/tools/dispatch_table.py`
  - `whitemagic/interfaces/api/routes/dashboard.py`
  - `whitemagic/interfaces/api/routes/dashboard_api.py`
  - `whitemagic/interfaces/api/rate_limit.py`
  - `whitemagic/interfaces/api/logging_config.py`
  - `whitemagic/interfaces/api/metrics.py`
  - `whitemagic/interfaces/api/exec_service.py`
  - `whitemagic/interfaces/api/routes/exec_enhanced.py`
  - `whitemagic/interfaces/dashboard/server.py`
- Added constrained mypy guard in `whitemagic/interfaces/api/models_exec.py` for optional SQLAlchemy fallback behavior.

## Highest Remaining Mypy Hotspots (interfaces/tools scope)

- **None** — `interfaces/tools` residual reached zero in this ratchet scope.

## Recommended Next Ratchet Slice (P2 continuation)

1. **Expand strict CI gates**
   - Target: enforce strict checks for `whitemagic/interfaces/**` + `whitemagic/tools/**` in CI.
   - Goal: lock in the clean edge state and prevent regression.

2. **Reduce Ruff E402 aggressively**
   - Normalize import order in high-churn API/tools modules first.
   - Keep behavior unchanged; formatting-only patch set.

3. **Choose between Cluster B/C/D for mypy reduction**
   - Pick B for max raw reduction, C for polyglot stability, D for governance/immune correctness.

## Out-of-Scope For This Ratchet Slice (still pending)

- Deep core typing debt outside the selected ratchet scope (for example `whitemagic/core/fusions.py`).
- Archived paths (`whitemagic/_archived`) intentionally excluded from strict quality gating.

## Gating Proposal For v13

- Keep current full-project checks informative.
- Enforce strict CI gates on:
  - `whitemagic/tools/**`
  - `whitemagic/interfaces/**`
- Expand gates directory-by-directory after each ratchet pass.
