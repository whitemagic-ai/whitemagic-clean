# P2 Static Quality Ratchet Report (2026-02-09, Pass 3)

## Scope
This pass targeted the next API/tool edge cluster identified in the previous plan:

- `whitemagic/interfaces/api/rate_limiter.py`
- `whitemagic/interfaces/api/routes/search.py`
- `whitemagic/interfaces/cli/exec.py`
- `whitemagic/interfaces/api/middleware/auth.py`
- `whitemagic/tools/envelope.py`
- `whitemagic/tools/audit_export.py`

Goal: continue reducing mypy debt in `interfaces+tools` while keeping tests and behavior stable.

## Baseline vs Final

| Metric | Before | After | Delta |
|---|---:|---:|---:|
| mypy (`whitemagic/interfaces` + `whitemagic/tools`) | 1482 errors in 267 files | 1467 errors in 261 files | -15 errors, -6 files |
| mypy (`interfaces/tools` subtotal) | 32 | 17 | -15 |
| ruff (`whitemagic`, excluding `_archived`) | 589 | 589 | no change |
| pytest (`tests --no-header -q -rs`) | 1199 passed, 4 skipped | 1199 passed, 4 skipped | no regression |

## Fixes Applied

### 1) SQLAlchemy fallback typing guard in API rate limiter
- `whitemagic/interfaces/api/rate_limiter.py`
  - Added `Any/cast` fallback assignments for optional DB imports.
  - Eliminated invalid `None` assignment to typed callables/models.

### 2) Optional import typing + route annotation in semantic search
- `whitemagic/interfaces/api/routes/search.py`
  - Added optional import guards for `...search` and `..memory_service`.
  - Added explicit return type on `semantic_search()`.

### 3) CLI exec command typing + audit dir guard
- `whitemagic/interfaces/cli/exec.py`
  - Added explicit annotations for `exec_cli`, `run`, and `audit` handlers.
  - Added `log_dir` None-guard before globbing audit files.

### 4) Auth middleware return annotations
- `whitemagic/interfaces/api/middleware/auth.py`
  - Added return annotations for `validate_api_key()` and `optional_api_key()`.

### 5) Envelope helpers typing corrections
- `whitemagic/tools/envelope.py`
  - Avoided `asdict()` on dataclass types (class objects) by guarding `not isinstance(value, type)`.
  - Replaced ignore-based dict return with explicit `cast` in `_ensure_jsonable_dict()`.

### 6) Audit export telemetry integration fix
- `whitemagic/tools/audit_export.py`
  - Replaced nonexistent `Telemetry.get_recent()` usage with `get_summary()["recent_events"]`.
  - Added cast on exported JSON-safe dict return.

## Focused Validation

- `temp_venv/bin/mypy --follow-imports=skip <6 target files>`
  - Result: `Success: no issues found in 6 source files`

- `temp_venv/bin/ruff check <6 target files>`
  - Result: `All checks passed!`

## Full Validation

- `temp_venv/bin/mypy whitemagic/interfaces whitemagic/tools`
  - Result: `Found 1467 errors in 261 files (checked 155 source files)`

- `temp_venv/bin/ruff check whitemagic --exclude whitemagic/_archived --statistics`
  - Result:
    - `E402: 572`
    - `E741: 11`
    - `F811: 5`
    - `F823: 1`
    - Total: `589`

- `python3 -m pytest tests --no-header -q -rs`
  - Result: `1199 passed, 4 skipped`

## Files Fully Cleared In This Pass

- `whitemagic/interfaces/api/middleware/auth.py` (2 -> 0)
- `whitemagic/interfaces/api/rate_limiter.py` (3 -> 0)
- `whitemagic/interfaces/api/routes/search.py` (3 -> 0)
- `whitemagic/interfaces/cli/exec.py` (3 -> 0)
- `whitemagic/tools/audit_export.py` (2 -> 0)
- `whitemagic/tools/envelope.py` (2 -> 0)

## Remaining `interfaces/tools` Residual (Post-pass)

Current subtotal: **17**

1. `whitemagic/interfaces/dashboard/server.py` (3)
2. `whitemagic/tools/tui/galaxy.py` (2)
3. `whitemagic/tools/handlers/governance.py` (2)
4. `whitemagic/tools/starter_packs.py` (1)
5. `whitemagic/interfaces/api/database.py` (1)
6. `whitemagic/interfaces/terminal/audit.py` (1)
7. `whitemagic/interfaces/terminal/tui.py` (1)
8. `whitemagic/interfaces/terminal/approver.py` (1)
9. `whitemagic/interfaces/api/dependencies.py` (1)
10. `whitemagic/interfaces/api/routes/api_keys.py` (1)
11. `whitemagic/tools/handlers/cyberbrain.py` (1)
12. `whitemagic/tools/handlers/export_import.py` (1)
13. `whitemagic/tools/tool_permissions.py` (1)

## Recommended Next Slice

Highest leverage next pass (estimated ~8-11 easy wins):

1. `whitemagic/interfaces/dashboard/server.py`
2. `whitemagic/tools/tui/galaxy.py`
3. `whitemagic/tools/handlers/governance.py`
4. `whitemagic/interfaces/api/routes/api_keys.py`
5. `whitemagic/interfaces/api/dependencies.py`
6. `whitemagic/interfaces/api/database.py`

This keeps us in high-signal interface/tool edge paths and avoids deep core typing debt for now.
