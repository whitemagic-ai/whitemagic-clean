# Whitemagic Remediation Verification (2026-02-06)

This document verifies the remediation transcript against the **current on-disk state** of `<REPO_ROOT>` and captures remaining P0/P1 issues before open-sourcing.

Goal (per owner): a shareable open-source repo that is easy to set up for humans/AIs, and does **not** ship private runtime data (memories, conversations, logs, model blobs).

---

## What The Team’s Transcript Got Right (Verified)

### 1) Heavy Directories Were Moved Out Of The Repo Root
These directories are **not present** in the repo root anymore:
- `frontends/` (previously ~3.8GB)
- `archive/` (previously ~6.2GB)
- `toolchains/` (previously ~5.5GB)
- `release/`
- `_archived_rust_crates/`
- `whitemagic/_archived/` (archived local-model implementation moved out)

Current top-level disk usage snapshot (2026-02-06, via `du -sh`):

```text
2.8G  whitemagic-julia/
2.2G  memory/
1.2G  whitemagic-rust/
884M  whitemagic-mojo/
800M  data/
504M  whitemagic-zig/
134M  .git/
76M   mesh/
21M   elixir/
18M   whitemagic/
```

This is consistent with “project under ~11GB” (not counting whatever was moved to the Desktop).

### 2) Core Python Syntax Is Clean
`python3 -m compileall -q whitemagic` succeeds.

### 3) Python Census Numbers Match
Re-running `python3 audit/python_census.py` reports:
- **1063 Python files**
- **205,283 LOC**

This is consistent with the team transcript and reflects that large legacy/vendor trees were moved away.

---

## Critical Mismatches / Remaining Blockers (P0)

### P0.1 Git Repo Still Contains Old Objects (“Not Truly Fresh”)
The repo is now a git repo (I had to re-run `git init` because `.git/HEAD` was missing initially), but `.git/objects/` still contains:
- **172 loose objects**
- **~129MB “garbage” pack/tmp** (`.git/objects/pack/tmp_pack_*`)

`git count-objects -vH` currently reports:

```text
count: 171
size: 4.24 MiB
garbage: 1
size-garbage: 129.13 MiB
```

Implication:
- This **defeats the privacy goal** of “no past artifacts in downloadable package” if the repo is ever shared as a directory/zip.
- Even if unreachable objects won’t push to a new remote, keeping them locally is risky and confusing.

Recommended fix:
- Since there are **no commits yet**, do a *true* reset:
  - move `.git/` aside (archive it) or delete it
  - `git init` again
  - verify `.git/` is small and `git count-objects` shows no garbage

### P0.2 `.gitignore` Is Not Strict Enough (High Risk Of Accidental Multi-GB Commit)
Current `.gitignore` is minimal and does **not** exclude major build/env artifacts that still exist on disk:
- `whitemagic-rust/target/` (~1.2GB)
- `whitemagic-mojo/mojo-env/` (~883MB)
- `whitemagic-julia/.pixi/` (~2.8GB)
- `haskell/dist-newstyle/`
- `temp_venv/` (~587MB, currently untracked)
- Zig caches: `whitemagic-zig/.zig-cache/`, `whitemagic-zig/zig-out/`

If someone runs `git add .` before hardening ignores, the “open source repo” will immediately become enormous.

Recommended fix:
- Expand root `.gitignore` to cover polyglot build caches + environments (`target/`, `.pixi/`, `mojo-env/`, `dist-newstyle/`, `.zig-cache/`, etc.).
- Add per-language `.gitignore` files where missing (`whitemagic-rust/`, `whitemagic-julia/`, `haskell/`, `whitemagic-mojo/`).

### P0.3 Integration Test Still Hangs (Not Fixed)
Running pytest on the “bridge integration test” still hangs at:
- `tests/integration/test_bridge_integration.py::test_parallel_executor`

The attempted “10s timeout” is only inside the `if __name__ == "__main__":` block, which **pytest never executes**.

Root cause (reproducible in this environment):
- `asyncio` + `run_in_executor` results are not reliably waking the event loop unless the loop has another periodic timer (“ticker”) scheduled.
- `whitemagic/cascade/advanced_parallel.py` uses `loop.run_in_executor(None, ...)` for sync tasks, which triggers the hang.

Recommended fix:
- Make `AdaptiveParallelExecutor` robust:
  - avoid `await asyncio.gather(...)` directly on `run_in_executor` futures
  - use a polling `asyncio.wait(..., timeout=poll_interval)` loop to ensure loop wakeups
  - add a real timeout in the pytest test (inside the test function)
- Or: remove this from pytest collection entirely (rename file to not match `test_*.py`) and treat it as a manual verification script.

### P0.4 `README.md` And “Setup Claims” Still Drift From Reality
`README.md` still contains:
- outdated claims (tests “1600+”, multiple frontends “integrated”, etc.)
- references to missing files (`docs/POLYGLOT_SETUP.md`, `QUICKSTART.md`, etc.)
- invalid extras (`pip install -e .[rust,dev]` but no `rust` extra exists in `pyproject.toml`)
- references to Node-based MCP setup (`npx whitemagic-mcp-setup`) even though the Node MCP tree was moved out

Recommended fix:
- Replace with a minimal, verified “from clean clone” sequence.
- Add a clearly-scoped “Optional accelerators” section (Rust/Mojo/Zig/Julia/Haskell) that does not imply they are required.

---

## Additional Hygiene (P1)

### P1.1 Pytest Timeout Config Is Ineffective
`pyproject.toml` sets `timeout = 30`, but `pytest` warns:
- `PytestConfigWarning: Unknown config option: timeout`

Meaning: `pytest-timeout` (or equivalent) is not installed/enabled.

Fix:
- Add `pytest-timeout` to `[project.optional-dependencies].dev`, or remove the setting.

### P1.2 Makefile `format` Target References `isort` (Not In Dev Extras)
`Makefile` runs `isort .` but `pyproject.toml` dev deps do not include `isort`.

Fix:
- either add `isort` to dev deps
- or remove it and standardize on Ruff for import sorting.

### P1.3 Root Runtime Artifacts Are Unignored
These are currently untracked (and will be committed unless ignored/moved):
- `extracted_concepts.jsonl`
- `resonance_state.json`
- `compile_errors.log`
- `kgen.trace.json.time-trace`, `kgen.trace.json.time-events.txt`
- `temp_blob.hex`
- `whitemagic_dream.log`

Fix:
- Move them under `data/` or `logs/` (both ignored), or add ignore patterns.

---

## Recommended “Next Actions” Checklist

1. **True git reset** (privacy + size): delete/archive `.git/` and re-`git init`, confirm `.git` is tiny and clean.
2. **Harden `.gitignore`** for polyglot environments/caches + runtime artifacts (P0).
3. **Fix `AdaptiveParallelExecutor`** so it cannot hang, and update/mark integration test accordingly (P0).
4. **Rewrite `README.md`** to only include commands verified in this repo state (P0).
5. **Stabilize CI target**: default CI runs `tests/unit` + `audit/tool_smoke.py` only; optional polyglot verification is a separate job/command.

---

## Verification Commands (Copy/Paste)

```bash
# Size overview
du -sh -- */ .git 2>/dev/null | sort -h | tail -n 80

# Python syntax
python3 -m compileall -q whitemagic

# Census
python3 audit/python_census.py

# Unit tests only (fast, reliable baseline)
python3 -m pytest -q tests/unit

# Integration test (currently hangs; run with external timeout until fixed)
timeout 30s python3 -m pytest -vv tests/integration/test_bridge_integration.py -s

# Git bloat signal
git count-objects -vH
```
