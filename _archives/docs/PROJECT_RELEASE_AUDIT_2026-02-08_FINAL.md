# Project Release Audit (2026-02-08)

## Scope
This pass covered repository-wide release-readiness checks with emphasis on runtime safety, CI gate health, and critical path behavior for the Python core.

## What Was Fixed In This Pass
1. Fixed Python 3.10-incompatible f-string parsing in solution ID generation.
- File: `whitemagic/core/intelligence/synthesis/solution_library.py:172`

2. Fixed task distribution and worker-daemon mismatch so distributed tasks are now picked up by workers.
- Files: `whitemagic/tools/handlers/task_dist.py:71`, `whitemagic/tools/handlers/task_dist.py:157`, `whitemagic/tools/handlers/task_dist.py:181`, `whitemagic/tools/handlers/task_dist.py:259`

3. Hardened worker shell execution path by removing `shell=True` execution semantics and blocking shell metacharacter chaining.
- File: `whitemagic/agents/worker_daemon.py:221`

4. Fixed broker-status path to fail fast when Redis is unreachable (eliminates gnosis hangs due broker probe).
- Files: `whitemagic/tools/handlers/broker.py:63`, `whitemagic/tools/handlers/broker.py:206`

5. Fixed telemetry portal method call so gnosis telemetry data is returned instead of silently failing.
- File: `whitemagic/tools/gnosis.py:323`

6. Fixed pytest collection breakage from intra-test imports.
- File: `tests/__init__.py:1`

## Validation Results
1. Full test suite now passes.
- Command: `pytest -q tests --no-header`
- Result: `1195 passed, 8 skipped`

2. Targeted lint on changed files passes.
- Command: `ruff check whitemagic/agents/worker_daemon.py whitemagic/tools/handlers/task_dist.py whitemagic/tools/handlers/broker.py whitemagic/tools/gnosis.py tests/__init__.py --select E,F,W --ignore E501`
- Result: `All checks passed`

3. Global lint still fails with large existing debt.
- Command: `ruff check whitemagic --select E,F,W --ignore E501 --exclude 'whitemagic/_archived' --statistics`
- Result: `12437 errors`

4. Global mypy still fails with large existing debt.
- Command: `mypy whitemagic --ignore-missing-imports --no-error-summary --exclude 'whitemagic/_archived'`
- Result: `3084 errors`

5. Ship gate still reports path portability issues.
- Command: `call_tool('ship.check')`
- Result: `ok: false`, absolute path literal hits remain.

6. Tool-smoke gate still hangs without external timeout.
- Command: `timeout 120s python audit/tool_smoke.py`
- Result: `EXIT:124`

## Remaining Release Blockers

### P0: Version and release metadata are inconsistent
- `README.md:1` advertises `v12.6`
- `pyproject.toml:7` is `12.3.0`
- `RELEASE_NOTES.md:1` is `v12.3.0`
- `VERSION:1` is `12.8.0`

Impact: ambiguous artifact identity and incorrect release tagging risk.

### P0: Dynamic code execution remains in active path
- `whitemagic/core/intelligence/synthesis/accelerator_bridge.py:77`

Impact: `exec` with broad builtins in solution execution path is unsafe for untrusted or DB-poisoned inputs.

### P1: Release ship-check is failing
- `AI_PRIMARY.md:18`
- `SYSTEM_MAP.md:14`
- `SESSION_HANDOFF_2026_02_08_EVENING.md:14`
- `scripts/find_dead_modules.py:18`

Impact: non-portable absolute paths; breaks clean release posture.

### P1: Tool smoke test is not bounded
- `audit/tool_smoke.py:241`

Impact: release smoke can hang indefinitely on one tool call.

### P1: Type and lint debt remains substantial
- Global lint errors: `12437`
- Global mypy errors: `3084`

Impact: static quality gates cannot be enforced for release branch protection.

## Recommended Next Pass (Team Plan)
1. Lock release version source of truth.
- Decide one version for this release and update `README.md`, `pyproject.toml`, `VERSION`, `RELEASE_NOTES.md` in one commit.

2. Add execution safety boundary for solution snippets.
- Replace raw `exec` path with AST-validated subset or sandboxed isolated process.

3. Make smoke gate deterministic.
- Add per-tool timeout in `audit/tool_smoke.py` and report timed-out tools explicitly.

4. Clear ship-check portability issues.
- Replace absolute paths with repo-relative or env-derived paths.

5. Gate static quality incrementally.
- Introduce scoped lint/mypy targets (core package subset first), then ratchet toward full enforcement.

## Notes
This pass materially improved runtime reliability and safety in core execution paths while preserving behavior validated by the current test suite.

---

## P0 Closure Addendum (2026-02-08, Follow-up Pass)

Status: **P0 objectives closed**.

1. Version metadata aligned to `12.8.0`.
- `README.md:1`
- `pyproject.toml:7`
- `RELEASE_NOTES.md:1`
- `VERSION:1`

2. Removed arbitrary snippet `exec` from active synthesis path.
- `whitemagic/core/intelligence/synthesis/accelerator_bridge.py:117`
- Snippets now require declarative JSON operations; arbitrary Python code is rejected.

3. Regression verification rerun.
- `pytest -q tests --no-header` => `1195 passed, 8 skipped`
