# P2 Static Quality Ratchet Report (2026-02-09, Pass 4)

## Scope
This pass targeted the final residual `interfaces/tools` files from the rolling plan:

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

Goal: eliminate the remaining `interfaces + tools` mypy tail.

## Baseline vs Final

| Metric | Before | After | Delta |
|---|---:|---:|---:|
| mypy (`whitemagic/interfaces` + `whitemagic/tools`) | 1467 errors in 261 files | 1450 errors in 248 files | -17 errors, -13 files |
| mypy (`interfaces/tools` subtotal) | 17 | 0 | -17 |
| ruff (`whitemagic`, excluding `_archived`) | 589 | 588 | -1 |
| pytest (`tests --no-header -q -rs`) | 1199 passed, 4 skipped | 1199 passed, 4 skipped | no regression |

## Key Fixes Applied

### 1) Final type-surface fixes
- `whitemagic/tools/starter_packs.py`
  - Corrected `list_packs()` return annotation to allow integer `tool_count`.

- `whitemagic/interfaces/api/database.py`
  - Added concrete typed in-memory collections (`list[User]`, `list[APIKey]`, etc.) for stub DB.

- `whitemagic/interfaces/terminal/audit.py`
  - Refactored `AuditLogger.__init__` to resolve/validate writable path before assignment.
  - Eliminated `Optional[Path]` operator issue in path joins.

- `whitemagic/tools/tui/galaxy.py`
  - Added missing return annotations and optional import guard for `vector_lake`.

- `whitemagic/interfaces/terminal/tui.py`
  - Added missing return annotation and fixed import order (`E402`).

- `whitemagic/interfaces/terminal/approver.py`
  - Added missing return annotation to `set_auto_approve()`.

### 2) Dashboard edge compatibility fixes
- `whitemagic/interfaces/dashboard/server.py`
  - Annotated manager instance as `Any` at integration edge.
  - Reworked continuity event retrieval to `getattr`-guarded callable lookup.

### 3) Handler/API cleanup
- `whitemagic/tools/handlers/cyberbrain.py`
  - Added compatibility lookup between `get_forgetting_engine` and `get_retention_engine`.

- `whitemagic/tools/handlers/export_import.py`
  - Added required `compress` field when constructing `ExportRequest`.

- `whitemagic/tools/tool_permissions.py`
  - Added constructor return annotation and normalized category extraction to stable string.

- `whitemagic/interfaces/api/dependencies.py`
  - Added explicit cast on current user return to satisfy strict return typing.

- `whitemagic/tools/handlers/governance.py`
  - Typed `result` as `Dict[str, Any]` to avoid narrow inference mismatch.

- `whitemagic/interfaces/api/routes/api_keys.py`
  - Added explicit return annotation for `retrieve_api_key()`.

## Validation

### Focused static checks
- `temp_venv/bin/mypy --follow-imports=skip <13 files>`
  - Result: `Success: no issues found in 13 source files`

- `temp_venv/bin/ruff check <13 files>`
  - Result: `All checks passed!`

### Full static checks
- `temp_venv/bin/mypy whitemagic/interfaces whitemagic/tools`
  - Result: `Found 1450 errors in 248 files (checked 155 source files)`

- `temp_venv/bin/ruff check whitemagic --exclude whitemagic/_archived --statistics`
  - Result:
    - `E402: 571`
    - `E741: 11`
    - `F811: 5`
    - `F823: 1`
    - Total: `588`

### Tests
- `python3 -m pytest tests --no-header -q -rs`
- Result: `1199 passed, 4 skipped`

## Milestone

`interfaces + tools` mypy residual is now **zero** in this ratchet scope.

This completes the originally proposed strict-gating target for v13 on:
- `whitemagic/interfaces/**`
- `whitemagic/tools/**`

## Recommended Next Ratchet Direction

With `interfaces/tools` clean, the next high-leverage P2 scope is core debt:

1. `whitemagic/core/fusions.py` (multiple concrete errors already visible)
2. `whitemagic/core/bridge/tools.py`
3. `whitemagic/core/bridge/*` adjacent modules

That should drive the next meaningful reduction in total mypy count without re-opening already-clean interface/tool edges.
