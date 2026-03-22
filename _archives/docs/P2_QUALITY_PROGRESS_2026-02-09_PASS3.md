# P2 Quality Progress (2026-02-09, Pass 3)

## Scope of This Pass

This pass continued the P2 tranche requested after P1 verification:

1. Eliminate remaining `E701/E702` debt.
2. Perform guarded `F401` cleanup module-by-module.
3. Continue mypy ratchet in `whitemagic/interfaces/` and `whitemagic/tools/`.

## Starting Baseline (at beginning of this pass)

1. Ruff (non-archived scope): `1395` errors.
2. `E701/E702`: `120` errors (`107` + `13`).
3. `F401`: `479` errors.
4. mypy (`interfaces` + `tools` scope): `2051` errors.
5. tests: `1199 passed, 4 skipped`.

## What Was Completed

### 1) `E701/E702` cleanup to zero

1. Applied deterministic line-splitting cleanup for one-line block/semicolon statements.
2. Repaired syntax and control-flow edge case in:
- `whitemagic/intelligence/agentic/self_mod.py`

Result:

1. `E701/E702` now `0`.

### 2) Guarded `F401` reduction (non-`__init__`)

1. Removed clearly-unused imports where behavior impact is nil.
2. Converted optional dependency probes from direct import to `find_spec(...)` checks where appropriate.
3. Intentionally left `__init__.py` re-export/import-pattern cases untouched.

Representative files updated:

1. `whitemagic/cli_app.py`
2. `whitemagic/optimization/polyglot_router.py`
3. `whitemagic/interfaces/api/app.py`
4. `whitemagic/interfaces/api/middleware/metrics.py`
5. `whitemagic/run_mcp.py`
6. `whitemagic/core/monitoring/otel_export.py`
7. `whitemagic/edge/inference.py`
8. `whitemagic/edge/onnx_export.py`

Result:

1. `F401`: `479 -> 59`
2. Remaining `F401` are all in `__init__.py` files (`non_init = 0`).

### 3) Mypy ratchet in `interfaces` + `tools`

Applied targeted type hygiene across high-churn API/handler files:

1. Added missing return/argument annotations for handler endpoints and helper functions.
2. Replaced direct dynamic-attribute assumptions with `getattr`/shape-safe access where needed.
3. Normalized bridge return values to dict-shaped tool contracts in several handlers.
4. Added narrowly-scoped mypy suppression for a dynamic SQLAlchemy fallback module:
- `whitemagic/interfaces/api/models.py`

Representative files updated:

1. `whitemagic/interfaces/nexus_api.py`
2. `whitemagic/interfaces/api/app.py`
3. `whitemagic/interfaces/api/routes/openai_compat.py`
4. `whitemagic/interfaces/api/routes/tools_gateway.py`
5. `whitemagic/interfaces/api/routes/webhook_triggers.py`
6. `whitemagic/tools/explain_this.py`
7. `whitemagic/tools/handlers/broker.py`
8. `whitemagic/tools/handlers/misc.py`
9. `whitemagic/tools/handlers/introspection.py`
10. `whitemagic/tools/handlers/grimoire.py`
11. `whitemagic/tools/handlers/browser_tools.py`
12. `whitemagic/tools/handlers/garden.py`
13. `whitemagic/tools/handlers/ganying.py`

Result:

1. mypy (`interfaces` + `tools`): `2051 -> 1894` (net `-157`).

## Final Metrics After Pass

1. Ruff (non-archived): `758` errors.
2. `E701/E702`: `0`.
3. `F401`: `59` (all `__init__.py`-scoped).
4. mypy (`interfaces` + `tools`): `1894` errors.
5. tests: `1199 passed, 4 skipped`.

## Remaining P2 Backlog (Current Top Ruff Codes)

1. `E402` module-import-not-at-top-of-file: `610`
2. `F401` unused-import: `59` (all `__init__.py`)
3. `F403` undefined-local-with-import-star: `36`
4. `F821` undefined-name: `34`
5. `E741` ambiguous-variable-name: `11`
6. `F811` redefined-while-unused: `7`
7. `F823` undefined-local: `1`

## Suggested Next Ratchet

1. Resolve `F403/F821` first (higher correctness value than style-only items).
2. Audit remaining `F401` in `__init__.py`:
- keep intentional re-exports with explicit `__all__`
- annotate intentional side-effect imports with targeted `noqa` comments.
3. Continue mypy endpoint/handler pass:
- `whitemagic/tools/handlers/memory.py`
- `whitemagic/tools/handlers/pipeline.py`
- remaining `whitemagic/interfaces/api/routes/*` modules.
