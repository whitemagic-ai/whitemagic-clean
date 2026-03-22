# Whitemagic v11 – Local Model Code Re-Home (Archive) Report (2026-02-07)

## Goal
Make the repository safer and more shareable as open source by:

1. Keeping Whitemagic **MCP-first** and **model-agnostic** by default.
2. Ensuring anything that *embeds* local-model inference is **archived** (physically relocated), not deleted.
3. Preserving legacy/local-model experiments in a **tracked** archive tree so future work can revive it if desired.
4. Tightening docs so they match the actual shipped tool surface.

## Changes Made

### 1) Tracked Archive Tree Added: `whitemagic/_archived/`
Local-model integrations that had been relocated to `~/Desktop/wm_archive/_archived/...` are now copied into the repo as a **tracked** Python package:

- Added: `whitemagic/_archived/__init__.py`
- Added (legacy packages):
  - `whitemagic/_archived/local_models/`
  - `whitemagic/_archived/inference_legacy/`
  - `whitemagic/_archived/brain_legacy/`

This directly fixes the previously broken opt-in shims that referenced:
`whitemagic._archived.local_models...` (the package now exists).

### 2) Embedded LLM / Local-Inference Modules Re-Homed into Archive
The `whitemagic/llm_*.py` modules were “active surface area” even though Whitemagic v11 wants to avoid embedded inference by default.

Action taken:

- Copied the original implementations to:
  - `whitemagic/_archived/local_models/llm/llm_*.py`
- Replaced the public modules with thin wrappers:
  - `whitemagic/llm_*.py` now gates access behind `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`
  - When disabled, most modules raise on attribute access via `__getattr__`
  - `whitemagic/llm_bridge.py` provides safe stub classes (`LLMBridge`, `LLMConfig`, etc.) so imports don’t crash

Net effect:

- Default installs no longer “advertise” embedded inference as first-class.
- The code is still preserved, tracked, and re-activatable for future work.

### 3) Tool Docs Are Now Generated From the Canonical Registry
The previous `docs/MCP_TOOLS_QUICK_REFERENCE.md` drifted (it listed 143 tools, duplicates, and stubs).

Action taken:

- Added generator script: `scripts/generate_mcp_tools_quick_reference.py`
- Regenerated: `docs/MCP_TOOLS_QUICK_REFERENCE.md`

The quick reference is now deterministic and derived from:
`whitemagic/tools/registry.py` (`TOOL_REGISTRY`).

### 4) README Tightening for DB Path
Updated `README.md` to explicitly document `WM_DB_PATH`:

- Default DB: `$WM_STATE_ROOT/memory/whitemagic.db`
- Override with: `export WM_DB_PATH=...`

### 5) Safer Failure Mode for Legacy Batch Optimizer
`whitemagic/core/bridge/optimization.py` previously imported `whitemagic.llm_speculative` during the `batch_optimizer` operation.

Now it:

- returns a clean “archived/disabled” response unless `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`
- returns a structured error dict if the import fails

## How To Use (Legacy / Opt-In)

### Enable Archived Local-Model Code
Whitemagic defaults to **external-model first**. To opt into legacy embedded local models:

```bash
export WHITEMAGIC_ENABLE_LOCAL_MODELS=1
```

This enables the shims in:

- `whitemagic/local_ml/*` (BitNet/Ollama legacy)
- `whitemagic/cascade/*` local-inference integrations
- `whitemagic/edge/local_llm.py`
- `whitemagic/llm_*.py` (now wrappers into the archive tree)

Important:

- Enabling this does **not** automatically install optional dependencies (e.g., `llama_cpp`).
- Some archived modules may be historical and not guaranteed to work.

## Verification Performed

### Python Syntax
```bash
python -m compileall -q whitemagic eval
```

### Tests
```bash
./temp_venv/bin/python -m pytest -q
```

## Open Items / Recommendations

1. Consider splitting the current single toggle:
   - `WHITEMAGIC_ENABLE_LOCAL_MODELS` (local backends)
   - `WHITEMAGIC_ENABLE_EMBEDDED_INFERENCE` (any embedded inference bridge)
   This would better match the architecture (“no embedded inference by default”), while still allowing
   non-local embedded inference in controlled contexts.
2. Keep `docs/MCP_TOOLS_QUICK_REFERENCE.md` strictly generated (don’t hand-edit). Add a brief note
   to `docs/README.md` if desired.
3. If you want a “fresh clone seed test”, write it as a scripted checklist (no secrets, no local paths),
   and run it in a clean temp directory with a clean venv; compare artifacts only under `WM_STATE_ROOT`.

