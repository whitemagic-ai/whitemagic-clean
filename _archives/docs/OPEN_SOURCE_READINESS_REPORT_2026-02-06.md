# Whitemagic Open-Source Readiness Report (2026-02-06)

This report is written to be *actionable* and *self-contained* so another AI (or human) can execute the recommendations without needing prior conversation context.

## Goals (As Stated By Owner)

1. Make Whitemagic a **shareable open-source repo** that any human or AI can clone and set up easily.
2. Ensure **no personal/runtime data** ships in the repo/package (memories, conversations, logs, caches, model blobs).
3. Make **MCP the canonical public interface** (with CLI/REST as adapters).
4. Keep **“gardens” internal** as an implementation detail, unless there’s a strong ecosystem reason to elevate them.
5. **De-emphasize embedded local-model inference** inside Whitemagic (local/cloud models should call Whitemagic via MCP/REST instead).

## Snapshot Of Current Workspace (Verified)

Repository root: `<REPO_ROOT>`

Top-level size hotspots (local workspace; not what should be committed):

```text
1.8G  .venv/                  (runtime venv; should never ship)
884M  whitemagic-mojo/         (contains mojo-env + binaries; should ship source only)
587M  temp_venv/               (runtime venv; should never ship)
490M  whitemagic-zig/          (contains .pixi/.zig-cache + binary; should ship source only)
276M  whitemagic-rust/         (contains target/ + .so; should ship source only)
130M  tmp/                     (contains archived git garbage pack)
76M   mesh/                    (contains compiled Go binaries; should ship source only)
21M   elixir/                  (contains deps/_build locally; should ship source only)
18M   whitemagic/              (Python package; this is the actual “core”)
```

Key verified repo hygiene state:

1. Git object store is now clean (no “garbage pack”).
   - `.git/` is ~5MB
   - `git count-objects -vH` shows `garbage: 0`
2. `.gitignore` has been expanded to exclude polyglot build artifacts, venvs, reports, binaries, etc.
3. Tests now complete.
   - `python -m pytest` passes (23 tests).

## What Was Fixed In This Pass (So The Team Doesn’t Redo It)

1. Git cleanup (archive, don’t delete):
   - Moved `.git/objects/pack/tmp_pack_*` into `tmp/git_archive/` (ignored by git).
   - Result: `.git/` shrank from ~134MB to ~5MB and has no garbage packs.
2. Hardened ignore rules:
   - Updated `.gitignore` to ignore: `reports/`, `temp_venv/`, `*.so`, `**/target/`, Mojo env, Zig caches, Elixir deps/_build, Haskell `dist-newstyle`, Go binaries, etc.
3. Fixed the hanging integration test:
   - Root cause: `asyncio` + `loop.run_in_executor` does not reliably wake the event loop in this environment, and also causes shutdown hangs.
   - Fix: `whitemagic/cascade/advanced_parallel.py` now avoids `run_in_executor` entirely; it uses `ThreadPoolExecutor.submit(...)` and polls completion via `await asyncio.sleep(...)`.
   - Result: `tests/integration/test_bridge_integration.py::test_parallel_executor` passes.
4. Open-source packaging basics:
   - Added `LICENSE` (MIT) and ensured it’s included by `MANIFEST.in`.
   - Added `whitemagic/py.typed` so `pyproject.toml`’s package-data declaration is correct.
5. Docs/install correctness:
   - Updated `README.md` to use real CLI commands and correct Python API shape.
   - Updated `DEPLOY.md` to avoid unsafe `git add .`.
   - Updated `docs/CONTRIBUTING.md` to reflect current repo layout and install flow.
6. Removed a hard-coded developer path:
   - `whitemagic/core/zodiac/zodiac_cores.py` no longer references a developer-specific `/home/<user>/...` path.

## Major Remaining Issues (Open-Source Blockers)

### P0: “Git Add” Safety Still Depends On Human Review

Even with improved ignore rules, the repo contains many *local-only* artifacts on disk (venvs, caches, compiled binaries). The rules are better now, but the risk profile is still:

1. Someone runs `git add -A` without reviewing `git diff --cached`.
2. A missed ignore pattern stages multi-GB content or private derived artifacts.

Recommendation:

1. Add a CI check that fails if any committed file exceeds a size threshold (example: 10MB) and/or matches forbidden globs (`memory/**`, `windsurf_conversations/**`, `*.db`, `*.gguf`, `*.safetensors`, etc.).
2. Add a repo script like `scripts/release/check_ship_surface.py` that:
   - runs `git ls-files`
   - flags “forbidden” paths
   - prints the top N largest tracked files

### P0: Docs Drift / Conflicting “System Maps”

`SYSTEM_MAP.md` (root) and multiple docs under `docs/` still describe directories that are no longer in-repo (frontends/, archive/, toolchains/, grimoire/, staging paths, etc.).

This is especially dangerous because you explicitly stated “AI are the primary users.” An AI reading stale maps will take incorrect actions.

Recommendation (pick one):

1. Trim: Keep **one** canonical map (recommend: root `SYSTEM_MAP.md`), update it to *only describe what exists*.
2. Split: Add a `SYSTEM_MAP_LEGACY.md` and clearly label it “moved out / archived”.

### P0: Hard-Coded Absolute Paths Still Exist (Mostly In `audit/`, `docs/`, `scripts/`)

Search hits include:

1. `audit/*` scripts referencing `/home/<user>/Desktop/whitemagic/...`
2. docs referencing `/home/<user>/.gemini/...`
3. Elixir sources referencing `/home/<user>/Desktop/...`

These will either:

1. break for any user who is not you, and/or
2. leak “local machine assumptions” into the open-source story.

Recommendation:

1. For runnable code (Python, Elixir, Go, etc.), replace absolute paths with:
   - `Path(__file__).resolve()` relative roots, or
   - `WM_STATE_ROOT` / config-based roots, or
   - explicit CLI args.
2. For docs, replace absolute paths with placeholders like:
   - `<PROJECT_ROOT>`
   - `<HOME>`
   - `$WM_STATE_ROOT`

### P1: `pyproject.toml` Still Carries “Heavy Defaults”

Current base dependencies include large and/or failure-prone libs for many environments (notably `cvxpy`, plus always-on server deps like FastAPI/Flask/Redis/asyncpg).

If the goal is “anyone can install easily,” the default install should be lean.

Recommendation:

1. Define a truly minimal core dependency set.
2. Move heavyweight features behind extras:
   - `api` (fastapi/uvicorn/flask)
   - `db-postgres` (asyncpg)
   - `cache-redis` (redis)
   - `solver` (cvxpy)
   - `mcp` (fastmcp)

### P1: Tool Surface Sprawl (Multiple “Canonical” Layers)

There are overlapping tool/execution systems:

1. `whitemagic/tools/registry.py` (schemas)
2. `whitemagic/tools/unified_api.py` (executor via huge if/elif chain)
3. `whitemagic/core/bridge/*` (legacy bridge dispatch)
4. `whitemagic/run_mcp.py` (FastMCP adapter)
5. REST routes under `whitemagic/interfaces/api/routes/*`
6. CLI commands under `whitemagic/cli_app.py`

Recommendation (MCP-first, AI-friendly):

1. Choose one canonical “tool contract” source:
   - keep `whitemagic/tools/registry.py` as the only schema authority
2. Convert `call_tool(...)` into a dispatch table keyed by tool name:
   - eliminates drift, simplifies testing, makes it auditable
3. Make MCP/REST/CLI thin adapters over the same dispatcher.

### P2: “Archived Local Models” Is Half-In / Half-Out

Local-model execution is mostly disabled behind `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`, which is good.

But there are still many non-archived “local LLM” modules in the Python package (for example `whitemagic/llm_router.py`, `whitemagic/llm_model_pool.py`, `whitemagic/llm_chatroom.py`, etc.) and scripts that install Ollama/BitNet.

Recommendation:

1. Decide whether these are:
   - “legacy, kept for reference” → move under `_archived/local_models/` (tracked), add README
   - “supported optional feature” → keep but ensure:
     - dependencies are optional
     - no default boot path touches them
     - the tool registry does not expose them unless enabled

## Gardens: Internal vs First-Class (Implications)

Your stated preference: gardens should be internal.

### Gardens Internal (Recommended For Now)

Benefits:

1. Smaller stable surface.
2. Faster refactors: you can change garden internals without breaking third parties.
3. Better for AI: fewer “nearly-the-same” abstractions to choose from. The MCP tool list can remain the clear “truth.”

Costs:

1. External contributors can’t build “garden plugins” cleanly.
2. You need another extension surface (tools/plugins/events) for the ecosystem.

### Gardens First-Class (Only If You Want A Plugin Ecosystem)

Benefits:

1. “Garden modules” become an explicit extension API:
   - loading lifecycle
   - state model
   - event contracts
2. You can grow a community of “garden authors.”

Costs:

1. Requires versioning discipline:
   - stability promises
   - deprecation policy
2. Testing burden increases dramatically:
   - compatibility tests for each garden
   - plugin ABI/API compliance

### Recommended Middle Path (Best Of Both)

1. Keep gardens as internal Python modules (no stability promise).
2. Expose *garden capabilities* as stable MCP tools:
   - `garden_status`
   - `garden_activate`
   - `garden_resonance_map`
3. If/when you want ecosystem growth:
   - define a “tool plugin” API first (simple, stable)
   - only later formalize “garden plugin” API if needed

## Suggested Action Plan (Priority Order)

### Phase 0: Lock Down What Ships

1. Create a CI check that prevents committing:
   - `memory/`, `data/`, `logs/`, `windsurf_conversations/`, `*.db`
   - venvs and caches
   - compiled binaries
2. Update `SYSTEM_MAP.md` to match reality (or mark it legacy).
3. Scrub absolute paths:
   - runnable code first (`audit/`, `elixir/`, `whitemagic/`)
   - then docs (`docs/`)

### Phase 1: Make The Public Contract Simple (MCP-First)

1. Define “public tool contract” document:
   - stable tool names
   - input/output schemas
   - error format
2. Ensure MCP server and REST gateway share the same tool registry and dispatcher.

### Phase 2: Reduce Default Install Weight

1. Move heavyweight libs to extras.
2. Ensure `pip install whitemagic` works without system dependencies.

### Phase 3: Local Models As External Clients

1. Remove/archival all “Whitemagic runs inference” UX, unless explicitly enabled.
2. Keep “OpenAI-compatible tool server” and MCP server for external LLMs.

## Directory-By-Directory “Ship Surface” Notes

This section is intended to prevent accidental open-sourcing of local artifacts and to reduce ambiguity for AIs.

### Root

Recommended to ship (tracked):

1. `pyproject.toml`, `README.md`, `LICENSE`, `VERSION`, `MANIFEST.in`
2. `whitemagic/` (Python package)
3. `tests/`, `docs/`, `audit/` (but sanitize hard-coded paths)
4. Optional accelerators (source-only):
   - `whitemagic-rust/`
   - `whitemagic-mojo/`
   - `whitemagic-zig/`
   - `mesh/`, `elixir/`, `haskell/` (if you truly want them in the public story)

Recommended to keep local-only (ignored / not tracked):

1. Runtime data: `memory/`, `data/`, `logs/`, `.whitemagic/`, `windsurf_conversations/`
2. Local envs: `.venv/`, `temp_venv/`
3. Generated reports: `reports/`
4. Compiled artifacts everywhere:
   - `**/target/`, `**/dist-newstyle/`, `**/_build/`, `**/deps/`
   - `*.so`, `*.beam`, compiled Go binaries, etc.

### `_archived/`

Current contents:

1. `_archived/legacy_api/*` (old server implementation)
2. `_archived/broken_modules/*` (dead/disabled modules)

Recommendation:

1. Decide whether `_archived/` is part of the open-source product story.
2. If yes: add a `_archived/README.md` that explains:
   - why it exists
   - what is safe to ignore
   - that nothing inside is “supported”

### `whitemagic/` (Python package)

High-value core areas:

1. `whitemagic/core/memory/*`: SQLite-backed memory substrate.
2. `whitemagic/tools/*`: tool registry + executor.
3. `whitemagic/run_mcp.py`: MCP server entrypoint (FastMCP).

High-risk drift areas:

1. **State root usage**:
   - `whitemagic/config/paths.py` provides `WM_ROOT`, but many modules still hardcode `Path.home() / ".whitemagic"`.
   - This breaks sandbox/container/test isolation.
2. **Import-time side effects**:
   - CLI startup registers plugins and logs heavily even for `--help`.
   - For AI tooling, “quiet by default” is valuable (make verbose opt-in).
3. **Tool surface duplication**:
   - `whitemagic/tools/unified_api.py` is an enormous if/elif dispatcher.
   - `whitemagic/core/bridge/*` duplicates “tool-like” entrypoints.

Recommendation:

1. Create one canonical dispatcher mapping tool name → callable.
2. Make every adapter (MCP/REST/CLI) call that dispatcher.
3. Standardize tool outputs:
   - always return `{"status": "success"|"error", ...}` (no mixed conventions)

### `whitemagic/run_mcp.py`

This file registers tools dynamically by building Python source code with `exec(...)`.

Observations:

1. It works, but it increases audit surface area and makes debugging harder.
2. It is not necessary for MCP; you can register a single handler that accepts a dict payload.

Recommendation:

1. Replace `exec`-generated wrappers with:
   - a simple closure `def wrapper(**kwargs): return call_tool(name, **kwargs)`
2. Let FastMCP validate against the tool schema if it supports that; otherwise validate in `call_tool`.

### `whitemagic/core/memory/unified.py` (Representative Code Quality Notes)

This module is functional but shows “research-mode” residue:

1. A shebang line appears after an import.
2. Logging includes emojis and “DEBUG:” statements in production code paths (`prune()`).
3. IDs are SHA256(content+timestamp) truncated to 16 chars.

Recommendation:

1. Remove debug logs or guard them behind a debug flag.
2. Standardize IDs:
   - `uuid4().hex[:16]` is fine if you just need a short unique key
   - or keep SHA but include a collision strategy
3. Ensure all memory writes are routed through a single “state root” (`WM_STATE_ROOT` / `WM_ROOT`).

### Polyglot Directories (`whitemagic-rust/`, `whitemagic-mojo/`, `whitemagic-zig/`, `mesh/`, `elixir/`, `haskell/`)

Current reality:

1. Source exists, but local builds have produced large caches/binaries inside these trees.

Open-source recommendation:

1. Keep source, ignore build outputs.
2. Add per-language README(s) that explain:
   - how to build
   - what the produced artifact is called
   - how Python discovers it (`import whitemagic_rs`, etc.)
3. Consider moving all accelerators under a single `accelerators/` directory to make the repo narrative simpler.

## “AI-First” Usability Recommendations (Non-Optional If AI Are Primary Users)

1. One canonical “How do I run this?” path.
   - right now there are many: CLI, MCP, REST, bridge scripts, polyglot bridges.
2. One canonical tool list and naming convention.
3. Deterministic and machine-readable errors.
4. Quiet by default:
   - avoid noisy logs on import/`--help`
5. Stable state root semantics:
   - `WM_STATE_ROOT` should relocate *everything*, across all modules.

## Appendix: Verification Commands

```bash
# Directory sizes (spot accidental blobs)
du -sh -- * .git .venv 2>/dev/null | sort -h

# Git ignore sanity (what would be committed)
git add -n -A | head -n 200

# Tests
python -m compileall -q whitemagic
python -m pytest

# Smoke test the tool dispatcher (isolated state)
python audit/tool_smoke.py
```
