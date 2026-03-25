# Release Readiness Checklist (Pass 6) — 2026-02-09

Scope: close the six pre-release blockers identified for v13 preparation.

## Executive Status

| Blocker | Status | Notes |
|---|---|---|
| 1. Zero-state first-run install/startup | PARTIAL (offline-validated) | Internet install path cannot be fully exercised in this offline environment; local/offline equivalent validated. |
| 2. Secrets/credential scan | PASS | No high-confidence key/token/private-key patterns detected in tracked source/docs. |
| 3. Optional dependency graceful degradation audit | PASS (public surfaces) | CLI/optional interfaces now degrade more cleanly; missing dashboard deps give actionable install hint. |
| 4. MCP resource serving (AI_PRIMARY + Grimoire index) | PASS | Resources added and verified readable through FastMCP resource APIs. |
| 5. Example MCP configs | PASS | `.mcp.json.example` expanded (PRAT/classic/lite) + docs examples added. |
| 6. `full` extras group + packaging sanity | PASS | Added `dashboard` + `full` extras; wheel build and editable install checks succeeded. |

---

## Evidence

### 1) Zero-state first-run install/startup

What was tested:
- Attempted true fresh install path in new venv (`pip install .[mcp]`) and captured offline network failure (cannot reach PyPI from this environment).
- Executed offline equivalent in fresh venv with system site packages:
  - `pip install -e '.[mcp]' --no-deps --no-build-isolation`
  - `python -m whitemagic.run_mcp` in classic/PRAT/lite modes

Results:
- Classic startup: `EXIT:0`
- PRAT startup: `PRAT_EXIT:0`
- Lite startup: `LITE_EXIT:0`
- Server banner and worker initialization logs confirmed startup path is healthy.

Residual for final sign-off:
- Run one internet-connected seed test in CI:
  - `python -m venv .venv && . .venv/bin/activate`
  - `pip install 'whitemagic[mcp]'`
  - `timeout 10s python -m whitemagic.run_mcp`

### 2) Secrets/credential scan

Command used:
- regex scan for private key headers + common API token signatures (`AKIA`, `sk-`, `ghp_`, `xoxb`, JWT-like patterns, etc.)

Result:
- `SECRET_SCAN: no high-confidence token/key patterns found`

### 3) Optional dependency graceful degradation audit

Checks:
- `wm --help` on fresh env: no noisy optional Holographic warning anymore.
- `wm tools --json` now supported directly and returns structured JSON.
- Optional dashboard package import no longer hard-fails package import path.
- Missing dashboard runtime deps now return explicit installation guidance:
  - `Dashboard server requires optional deps. Install with "pip install 'whitemagic[dashboard]'" or "pip install 'whitemagic[full]'".`

### 4) MCP resource serving

Added resources:
- `whitemagic://orientation/ai-primary`
- `whitemagic://grimoire/index`

Validation:
- FastMCP introspection lists both resources.
- Read path validated; both resources returned markdown content payloads.

### 5) Example MCP configs

Delivered:
- `.mcp.json.example` now includes:
  - `whitemagic-prat`
  - `whitemagic-classic`
  - `whitemagic-lite`
- Added `docs/MCP_CONFIG_EXAMPLES.md` with repo-local + Claude Desktop templates.
- `.mcp.json.example` validated as JSON via `python -m json.tool`.

### 6) Full extras + packaging sanity

Changes:
- Added optional extra: `dashboard` (`flask`, `flask-cors`)
- Added convenience extra: `full` (all optional feature deps)

Validation:
- TOML parse confirms extras exist:
  - `has_full True`
  - `has_dashboard True`
- Packaging build:
  - `python -m pip wheel --no-deps --no-build-isolation . -w /tmp/wm_dist`
  - Result: `whitemagic-12.8.0-py3-none-any.whl`
- Editable install sanity:
  - `pip install -e '.[full]' --no-deps --no-build-isolation`
  - Result: success (`FULL_INSTALL_EXIT:0`)

---

## Code/Doc Changes Applied

### Runtime + CLI
- `whitemagic/run_mcp.py`
  - Added `register_resources()` with two orientation resources.
  - Added `_safe_read_text()` helper.
  - Added idempotent `_RESOURCES_REGISTERED` guard.
- `whitemagic/cli_app.py`
  - Added `wm tools --json` command-level support.
  - Suppressed expected optional Holographic warning noise unless debug/real failure.
- `whitemagic/interfaces/dashboard/server.py`
  - Added explicit actionable error message for missing dashboard deps.
- `whitemagic/interfaces/dashboard/__init__.py`
  - Optionalized dashboard package import to avoid hard import failure on missing flask.

### Packaging + Config
- `pyproject.toml`
  - Added `[project.optional-dependencies].dashboard`
  - Added `[project.optional-dependencies].full`
- `.mcp.json.example`
  - Expanded to PRAT/classic/lite profiles.

### Documentation
- `README.md`
  - Added MCP orientation resource URIs.
  - Added `docs/MCP_CONFIG_EXAMPLES.md` reference.
  - Added `pip install -e '.[full]'` option.
- `AI_PRIMARY.md`
  - Added MCP orientation resource section.
  - Updated capability matrix counts to `25 subsystems / 28 active / 0 unexplored`.
  - Added `dashboard` and `full` install options.
- `docs/MCP_CONFIG_EXAMPLES.md` (new)
- `docs/README.md`
  - Added MCP config examples index entry.

---

## Regression Checks

- `temp_venv/bin/ruff check ...` on changed Python files: **pass**
- `python3 -m pytest tests -q --no-header`: **1199 passed, 4 skipped**

---

## Final Release Note For This Pass

All six blockers have been addressed in this pass; one item (true internet seed install) remains an environmental validation step and is ready to be executed in CI or an internet-connected machine for final public-release sign-off.
