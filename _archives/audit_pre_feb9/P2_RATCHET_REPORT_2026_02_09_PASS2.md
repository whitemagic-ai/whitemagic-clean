# P2 Static Quality Ratchet Report (2026-02-09, Pass 2)

## Scope
This pass continued the P2 ratchet on `whitemagic/interfaces` + `whitemagic/tools` with a targeted hotspot slice:

- `whitemagic/interfaces/tui.py`
- `whitemagic/interfaces/cli/graph.py`
- `whitemagic/tools/sandbox.py`
- `whitemagic/interfaces/terminal/config.py`
- `whitemagic/tools/introspection.py`
- `whitemagic/tools/capability_matrix.py`
- `whitemagic/tools/dependency_graph.py`

Primary goal: reduce mypy and ruff counts without behavior regressions.

## Baseline vs Final

| Metric | Before | After | Delta |
|---|---:|---:|---:|
| mypy (`whitemagic/interfaces` + `whitemagic/tools`) | 1510 errors in 274 files | 1482 errors in 267 files | -28 errors, -7 files |
| mypy (`interfaces/tools` local hotspot subset) | 60 errors | 32 errors | -28 |
| ruff (`whitemagic`, excluding `_archived`) | 596 | 589 | -7 |
| pytest (`tests --no-header -q -rs`) | 1199 passed, 4 skipped | 1199 passed, 4 skipped | no regression |

## Key Fixes Applied

### 1) Optional dependency typing guards
- `whitemagic/interfaces/tui.py`
  - Added `# type: ignore[import-not-found]` on optional `textual` imports.
  - Added ignore on optional `vector_lake` import.
  - Result: resolved 5 import-not-found errors in optional TUI path.

### 2) CLI graph typing and runtime correctness
- `whitemagic/interfaces/cli/graph.py`
  - Added explicit function annotations for `command_graph`, `_build_graph_tree`, `command_graph_stats`.
  - Added local type annotations for `visited` and `relationship_types`.
  - Replaced invalid `Console.logger.info(...)` calls with `Console.print(...)`.
  - Result: resolved mypy issues and fixed a real runtime misuse of Rich `Console` API.

### 3) Sandbox typing cleanup
- `whitemagic/tools/sandbox.py`
  - Typed `SandboxResult.to_dict()` accumulator as `Dict[str, Any]`.
  - Added return annotations for `ToolSandbox.__init__`, `set_limits`, and nested `_run` callable.
  - Result: resolved dict-assignment and untyped-def errors.

### 4) Terminal config model typing
- `whitemagic/interfaces/terminal/config.py`
  - `from_env()` now passes required typed fields explicitly.
  - Added return annotation for `save()`.
  - Cast result of `model_validate_json` in `load()`.
  - Result: resolved call-arg and no-any-return issues.

### 5) Introspection manifest typing and Any leak reduction
- `whitemagic/tools/introspection.py`
  - Removed loop variable name reuse across format branches (`whitemagic_tools`, `mcp_tools`, `openai_tools`).
  - Typed tool list outputs as `list[dict[str, Any]]`.
  - Tightened `telemetry_summary()` return type to concrete dict conversion.
  - Result: resolved no-redef/no-any-return errors.

### 6) Capability matrix probe/type fixes
- `whitemagic/tools/capability_matrix.py`
  - Typed `by_diff` structure (`Dict[str, List[str]]`).
  - Typed `pick` as optional dict in `suggest_next_fusion()`.
  - Reworked dream probe to use `getattr` for compatibility with current `DreamCycle` surface.
  - Result: resolved var-annotated/assignment/attr-defined errors.

### 7) Dependency graph typed collections
- `whitemagic/tools/dependency_graph.py`
  - Added return annotation on constructor.
  - Typed `edge_types` and `all_edges` accumulators.
  - Result: resolved untyped-def and var-annotated errors.

## Validation Performed

### Static checks
- Focused mypy (7-file slice):
  - `temp_venv/bin/mypy --follow-imports=skip ...`
  - Result: `Success: no issues found in 7 source files`.

- Full ratchet mypy scope:
  - `temp_venv/bin/mypy whitemagic/interfaces whitemagic/tools`
  - Result: `Found 1482 errors in 267 files (checked 155 source files)`.

- Ruff checks:
  - Focused: `temp_venv/bin/ruff check <edited files>` -> `All checks passed!`
  - Global: `temp_venv/bin/ruff check whitemagic --exclude whitemagic/_archived --statistics`
  - Result:
    - `E402: 572`
    - `E741: 11`
    - `F811: 5`
    - `F823: 1`
    - Total: `589`

### Tests
- `python3 -m pytest tests --no-header -q -rs`
- Result: `1199 passed, 4 skipped`.

## Residual `interfaces/tools` Hotspots (Post-pass)

Top remaining files in `interfaces/tools` scope:

1. `whitemagic/interfaces/api/rate_limiter.py` (3)
2. `whitemagic/interfaces/dashboard/server.py` (3)
3. `whitemagic/interfaces/cli/exec.py` (3)
4. `whitemagic/interfaces/api/routes/search.py` (3)
5. `whitemagic/tools/envelope.py` (2)
6. `whitemagic/tools/tui/galaxy.py` (2)
7. `whitemagic/tools/handlers/governance.py` (2)
8. `whitemagic/interfaces/api/middleware/auth.py` (2)
9. `whitemagic/tools/audit_export.py` (2)

`interfaces/tools` subtotal is now **32 errors** (down from 60).

## Files Fully Cleared in This Pass

- `whitemagic/interfaces/cli/graph.py` (4 -> 0)
- `whitemagic/interfaces/terminal/config.py` (4 -> 0)
- `whitemagic/interfaces/tui.py` (5 -> 0)
- `whitemagic/tools/capability_matrix.py` (4 -> 0)
- `whitemagic/tools/dependency_graph.py` (3 -> 0)
- `whitemagic/tools/introspection.py` (4 -> 0)
- `whitemagic/tools/sandbox.py` (4 -> 0)

## Recommended Next Ratchet Slice

High-confidence next target (estimated 12 to 16 easy wins):

1. `whitemagic/interfaces/api/rate_limiter.py`
2. `whitemagic/interfaces/api/routes/search.py`
3. `whitemagic/interfaces/cli/exec.py`
4. `whitemagic/tools/envelope.py`
5. `whitemagic/tools/audit_export.py`
6. `whitemagic/interfaces/api/middleware/auth.py`

This keeps scope tight in API/tool edges and should continue reducing errors without entering deep core/system typing debt.
