# Whitemagic v11 AI-Primary Implementation Report (2026-02-07)

This report summarizes the **AI-primary hardening work** applied to the Whitemagic v11 codebase, and provides a concrete checklist for the team to validate/open-source the repository safely.

This is written for **humans and AIs**: it includes explicit file paths, invariants, and runnable verification steps.

## Executive Summary

Whitemagic now has a **stable tool response envelope**, **idempotent write semantics**, **determinism hooks**, **state-root isolation**, and **contract-level introspection tools** designed for automated agent runtimes.

Major deliverables:
- Canonical tool response envelope for *every* `call_tool()` invocation
- Idempotency ledger for write tools (`idempotency_key`)
- Deterministic runs via `now` override (timestamp replay)
- Centralized runtime state under `WM_STATE_ROOT` (no repo writes by default)
- Introspection tools (`capabilities`, `manifest`, `state.*`, `repo.*`, `ship.check`)
- OSS hygiene scanner (`ship.check`) that avoids scanning user memory
- CLI improvements for AI callers (`wm --json …`, `wm doctor`)
- Minimal base dependencies + modular extras in `pyproject.toml`
- Lightweight eval harness under `eval/`
- Canonical AI spec doc: `AI_PRIMARY.md`

## Non-Negotiables (Project Invariants)

1. The repo must be cloneable and runnable without shipping personal state.
2. Runtime state must be created under `WM_STATE_ROOT` (default `~/.whitemagic`, with `/tmp` fallback).
3. AI callers must receive **stable envelopes** from tools (no ad-hoc shapes).
4. Write tools must support safe retries via `idempotency_key`.

## What Changed (High Signal)

### 1) Tool Contract Envelope (Stable Output Shape)

Canonical entrypoint:
- `whitemagic/tools/unified_api.py:call_tool`

Envelope helpers:
- `whitemagic/tools/envelope.py`
- `whitemagic/tools/errors.py`
- `whitemagic/tools/contract.py`

Contract tests:
- `tests/unit/test_tool_contract.py`

Invariant:
- Every tool returns a JSON-serializable object with stable top-level keys and tool-specific data under `details`.

### 2) Idempotency For Write Tools

Implementation:
- `whitemagic/tools/idempotency.py`

Storage:
- `$WM_STATE_ROOT/artifacts/idempotency/*.json`

Behavior:
- Replay returns the same envelope and sets `side_effects.idempotency_replay = true`.

### 3) Determinism Via `now`

Implementation:
- `whitemagic/utils/time.py` (`override_now`, `now_iso`)
- `whitemagic/tools/unified_api.py` wraps tool execution in `override_now(now)`

Behavior:
- If a caller passes `now="...Z"`, the returned envelope **timestamp must equal it verbatim**.

### 4) State Root Isolation (No Repo Writes)

Implementation:
- `whitemagic/config/paths.py`

Paths include:
- `WM_ROOT`, `MEMORY_DIR`, `CACHE_DIR`, `LOGS_DIR`, `ARTIFACTS_DIR`, etc.

Policy:
- Whitemagic should not write into the repo by default.
- Default is `~/.whitemagic`. If not writable, fallback is `/tmp/whitemagic_state`.

### 5) Introspection Tools (For Agents)

Implementation:
- `whitemagic/tools/introspection.py`

Tools:
- `capabilities`, `manifest`
- `state.paths`, `state.summary`
- `repo.summary`, `ship.check`

Notes:
- `ship.check` uses `git ls-files -co --exclude-standard` when possible, meaning it scans only tracked/unignored files.
- `ship.check` explicitly avoids scanning `WM_STATE_ROOT` (user memory).

### 6) CLI (AI-Friendly)

CLI entry:
- `whitemagic/cli_app.py`

Key behaviors:
- `wm --json …` outputs clean JSON (no preamble).
- `wm doctor` runs an AI-first hygiene + contract check.
- `wm doctor-deep` exists but is marked legacy/unstable.

Noise reduction:
- Example plugins are not auto-loaded by default anymore:
  - `whitemagic/plugins/__init__.py` gates example plugins behind `WHITEMAGIC_LOAD_EXAMPLE_PLUGINS=1`
- Plugin registry logging respects `WM_SILENT_INIT`:
  - `whitemagic/plugins/registry.py`

### 7) Packaging: Minimal Core + Extras

Config:
- `pyproject.toml`

Base install is intentionally small:
- `click`, `pydantic`, `pyyaml`

Optional extras:
- `mcp` (FastMCP)
- `cli` (Rich)
- `api`, `db`, `cache`, `auth`, `net`, `openai`, `numeric`, `opt`, etc.

Rationale:
- Avoid shipping heavyweight web stacks and compiled ML/optimization stacks by default.

### 8) Eval Harness

Docs:
- `eval/README.md`

Runner:
- `eval/run_eval.py`

Checks:
- Envelope stability
- Invalid param errors
- Idempotency replay
- `ship.check` passes
- `now` timestamp determinism

Output:
- `$WM_STATE_ROOT/artifacts/eval/<timestamp>/report.json`

### 9) AI Spec Doc

Spec:
- `AI_PRIMARY.md`

This is the “single place” describing:
- envelope keys + semantics
- common params (`request_id`, `idempotency_key`, `dry_run`, `now`)
- state-root policy
- introspection tools
- dependency/extras strategy

### 10) Repo Hygiene Defaults

Updated ignore rules:
- `.gitignore` includes explicit ignores for repo-local runtime artifacts like:
  - `dream_journal.md`
  - `.mcp.json` (use `.mcp.json.example`)
  - `wm` (local wrapper)

Template MCP config:
- `.mcp.json.example`

## Verification Checklist (Run These)

From repo root:

1. Unit tests:
```bash
./temp_venv/bin/pytest -q
```

2. Bytecode compile sanity:
```bash
./temp_venv/bin/python -m compileall -q whitemagic eval
```

3. Tool hygiene scan (no personal-data scan; checks tracked/unignored files only):
```bash
WM_STATE_ROOT=/tmp/wm_state WM_SILENT_INIT=1 ./temp_venv/bin/python -c "from whitemagic.tools.unified_api import call_tool; print(call_tool('ship.check')['details']['ok'])"
```

4. Eval harness:
```bash
WM_STATE_ROOT=/tmp/wm_eval WM_SILENT_INIT=1 ./temp_venv/bin/python eval/run_eval.py --now 2026-01-01T00:00:00Z
```

5. CLI JSON mode (should output *only* JSON):
```bash
WM_STATE_ROOT=/tmp/wm_cli WM_SILENT_INIT=1 ./temp_venv/bin/python -m whitemagic.cli_app --json status
WM_STATE_ROOT=/tmp/wm_cli WM_SILENT_INIT=1 ./temp_venv/bin/python -m whitemagic.cli_app --json doctor
```

## Known Risks / Follow-Ups (Not Blocking, But Real)

- **Legacy surface area:** `whitemagic/cli_app.py` still contains many legacy commands. The AI-primary path is stable, but the file is large and includes historical features (local model references, etc.).
- **Local model remnants:** local-model-related modules still exist across the codebase, but are archived/disabled in the contract-level entrypoints. If the goal is to fully remove their presence from the public surface, a deeper archival/refactor pass is still possible.
- **MCP dependency:** MCP server requires the `mcp` extra (`fastmcp`). The repo includes `.mcp.json.example` to make wiring easier.

## “Ready To Open Source” Checklist

Before pushing to a public remote:
- Run `ship.check` and confirm `ok: true`
- Run `eval/run_eval.py` in a fresh `WM_STATE_ROOT`
- Confirm `.gitignore` blocks:
  - `memory/`, `data/`, `logs/`, `reports/`, `tmp/`, `.whitemagic/`, `.env*`, `windsurf_conversations/`
- Confirm no personal artifacts are staged:
  - `git status --ignored`
  - `git diff --cached --name-status`

