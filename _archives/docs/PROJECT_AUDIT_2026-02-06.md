# Whitemagic Project Audit & Recommendations (2026-02-06)

This report is intended to be self-contained so another AI (or human) can pick it up and execute the recommended changes without needing the full conversation context.

**Stated goals (from owner):**
1. Publish Whitemagic as a **shareable open-source repo** that any human or AI can download and set up easily.
2. Ensure **no personal runtime data** (memories, conversations, logs, model blobs) ships in the repo/package.
3. Make **MCP the canonical public interface**.
4. Keep **gardens internal** (not a first-class stable Python API).
5. Move away from **embedding local models** inside Whitemagic; local models should *use* Whitemagic via MCP/REST instead.

---

## Executive Summary

Whitemagic is ambitious: a polyglot “cognitive substrate” with memory, orchestration, ethics/boundaries, and multiple frontends. The codebase already contains many of the right building blocks for an agent-first system (tool registry, unified dispatcher, security gating, MCP server).

However, the repo in its current form is not “easy setup” for strangers (human or AI). The major blockers are:
- **Scale and sprawl**: multiple overlapping systems and duplicated “release/archive” trees.
- **Git hygiene**: this workspace has **no commits yet**, but `.git/` is already **~13GB** due to previously staged/added heavyweight artifacts and build caches.
- **Docs/build drift**: `README.md`, `Makefile`, `Dockerfile`, and `docker-compose.yml` are out of sync with the actual filesystem layout and runnable entrypoints.
- **Test reliability**: unit test suite hangs on `tests/unit/test_bridge.py::test_parallel_executor` (likely process-pool/pickling behavior). Full `pytest` run does not currently complete.
- **State isolation**: tools respect `WM_STATE_ROOT` in some places, but several components still write to user-home paths by default (e.g. `~/.whitemagic`, `~/.cache/whitemagic`), which breaks hermetic tests and fails in sandboxed environments.

**Positive note:** `python3 -m compileall -q whitemagic` currently succeeds (no syntax-invalid modules in the active Python package), and `.mcp.json` is portable (relative paths).

On the “local models” question, the direction is clear and coherent: Whitemagic should be a tool substrate, not an LLM runtime. As part of this audit, local-model embedding code was **physically relocated into an archived tree** and **disabled by default**, while leaving thin compatibility shims.

---

## What Was Changed In This Pass (Local Models Only, No Data Deleted)

### Data Safety: Nothing Was Deleted From Disk
- `memory/` and `windsurf_conversations/` remain on disk.
- They are still ignored/untracked for open-source distribution (so they won’t ship by accident).

**Important follow-up:** there are additional “runtime artifact” files at repo root that are *currently staged for commit* in this workspace (example: `extracted_concepts.jsonl`, `resonance_state.json`). These are very likely to be derived from local data and should not be published.

**Recommendation (P0):**
- Move/keep such artifacts under an ignored runtime directory (`data/`, `logs/`, `tmp/`, etc.).
- Ensure they are untracked before the first public commit (with *no deletion from disk*).

### Local-Model Artifacts (Weights/Blobs): Moved Out Of Root
To reduce confusion (and keep the repo root “open-source clean”), local-model artifact paths were physically relocated:
- `local_models/` → `archive/local_models/`
- `ollama` (local runner stub) → `archive/ollama`
- `ollama.log` (root) → `logs/ollama_2026-02-03_root.log`

These moves preserve everything on disk while making it much harder to accidentally treat local-model blobs/logs as part of the product surface.

### Local-Model Embedding: Archived + Disabled By Default
Local-model code was physically relocated to a tracked archive subtree:
- `whitemagic/_archived/local_models/…`

Thin compatibility wrappers remain at the original import paths, but they do nothing unless:
- `WHITEMAGIC_ENABLE_LOCAL_MODELS=1` is set before startup.

Examples:
- `whitemagic/local_ml/*` is now wrappers. Archived implementation lives at `whitemagic/_archived/local_models/local_ml/*`.
- `whitemagic/cascade/local_models.py` and related local-model modules are now wrappers. Archived implementations live at `whitemagic/_archived/local_models/cascade/*`.
- `whitemagic/autonomous_execution/local_model_integration.py` is now a wrapper.
- `whitemagic/edge/local_llm.py` is now a wrapper.
- `whitemagic/cli_local.py` is now a wrapper.
- The old `whitemagic/brain.py` (shadowed by the `whitemagic/brain/` package) was moved into the archived tree.

### MCP/REST/CLI Behavior Changes (Local Models)
- Python MCP server no longer tries to “check Ollama/local inference” at boot.
- REST “local-ml” endpoints return **HTTP 410** unless `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`.
- Tool registry no longer exposes `local_generate` (embedded model execution as a tool).
- Tool dispatcher returns a clear “archived” error for `local_generate` / `local_generate_rag`.
- `/chat` endpoint no longer falls back to Ollama; it returns **503** and instructs callers to use an external model via MCP/REST.
- CLI local inference subcommands are only attached if `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`.

---

## High-Level Repo Map (What Exists Today)

This is a polyglot monorepo containing:
- `whitemagic/`: primary Python package (core memory, resonance, tools, API, etc.)
- `whitemagic/run_mcp.py`: Python MCP server entrypoint (FastMCP) that registers tools from `whitemagic/tools/registry.py`
- `archive/whitemagic-mcp/`: archived TypeScript MCP server/client (currently treated as a heavy artifact; ignored for open-source distribution)
- `frontends/`: multiple UI applications (notably `frontends/hub`, very large locally)
- `whitemagic-rust/`, `whitemagic-zig/`, `whitemagic-mojo/`, `whitemagic-go/`, `whitemagic-julia/`, `elixir/`: performance and experimental/alternative-language implementations
- `scripts/`: ingestion, indexing, utility scripts
- `release/`: appears to be a snapshot/copy of “core” Python at a prior point in time
- `archive/`: contains BitNet and legacy dumps; currently treated as heavy artifacts
- `toolchains/`: large local toolchain caches (Rustup, Go module cache, etc.)

---

## Additional Local-Model References Still Present (Follow-Up Candidates)

Even after archiving the main embedded-local-ML subsystem, there are still *references to Ollama/local inference* scattered across the repo. They don’t necessarily execute by default, but they are confusing for open-source users and should be treated as “archivable” if you want a clean separation.

Notable examples:
- `whitemagic/brain/`: provider abstraction defaults to `"ollama"` via `WM_AI_PROVIDER`. This is “local model by default” behavior.
- `whitemagic/inference/`: contains Ollama-specific turbo config, KV-cache hints, and model warm-up logic.
- `whitemagic/cli_enhanced.py` and some CLI command groups still present “local ML (BitNet/Ollama)” UX even though local models are archived/disabled by default.
- `whitemagic/interfaces/api/routes/local_ml_api.py`: correctly returns **HTTP 410** unless `WHITEMAGIC_ENABLE_LOCAL_MODELS=1`, but still exists and should be documented as archived (or moved under `_archived/` for clarity).
- `infrastructure/devops/ollama-integration.sh`, `infrastructure/devops/redis-async-ai.py`: operational scripts for local LLM automation (should not be part of the *core* open-source surface unless you explicitly want to support it).
- `docs/MCP_TOOLS_QUICK_REFERENCE.md`: contains references implying local inference is first-class.
- `whitemagic/edge/inference.py`: built-in rule responses still market Whitemagic as “local AI” and include Ollama install guidance; this is inconsistent with “external model ↔ MCP ↔ Whitemagic tools/memory”.

**Recommendation (P0/P1):**
- Decide if “Whitemagic runs inference” is in-scope at all.
- If **out-of-scope**: archive `whitemagic/brain/` and `whitemagic/inference/` (or make them thin *client* layers only), remove local inference UX from CLI, and update docs to reflect the new contract.
- If **in-scope but external-only**: keep “clients like Ollama can call Whitemagic tools” (OpenAI-compat gateway), but remove any code that attempts to manage/run Ollama from inside Whitemagic.

### Directory-By-Directory Notes (What Each Area “Means”)

**Root files**
- `.mcp.json`: MCP server configuration. Currently portable (relative paths + `PYTHONPATH=.`) and suitable as a default template.
- `.gitignore`: contains rules to keep runtime state and heavyweight assets out of git. This is essential, but should be backed by CI checks.
- `pyproject.toml`: declares the Python distribution. Uses setuptools package discovery (`include = ["whitemagic*"]`) and is broadly aligned with the on-disk layout.
- `Makefile`: appears to intend a unified build system, but some directory paths don’t match the actual repo layout (risk: newcomers run `make build` and hit immediate failure).
- `README.md`: contains ambitious claims (tests count, integration breadth, etc.) that may be out of sync with current runnable reality. For open-source, “commands that work” matter more than “claims”.

**`whitemagic/` (Python package)**
- Contains several overlapping systems:
  - “Bridge” modules meant to expose tools via MCP.
  - “Tools” registry + dispatcher intended as a canonical tool system.
  - “Core” systems: memory, resonance/event bus, orchestration, gardens, etc.
- `whitemagic/core/gardens` is now a small compatibility shim that re-exports `whitemagic.gardens` (no more drift).
- `python3 -m compileall -q whitemagic` currently succeeds (the active Python package is syntactically valid).
- Main remaining issues are *behavioral* rather than syntax: heavy import-time side effects, inconsistent runtime state roots, and long/hanging tests.

**`archive/whitemagic-mcp/` (TypeScript MCP)**
- This code exists locally but is currently treated as archived/ignored for open-source distribution.
- If you want a Node MCP server long-term, either resurrect it as a first-class component (with a single canonical tool schema source), or keep MCP purely in Python and remove the Node implementation entirely.

**`frontends/`**
- Contains multiple UI apps (including a very large `frontends/hub` local workspace).
- For open source, do not ship `node_modules`. Ensure builds are reproducible from `package-lock.json` and a documented Node version.

**`release/`**
- Looks like a copy of Python code at a prior “release snapshot” state.
- Risk: duplication multiplies maintenance, increases audit burden, and confuses AIs.
- Recommendation: either remove from the primary repo, or move into an explicit tracked archive subtree with a README explaining provenance and staleness.

**`archive/`**
- Contains BitNet and a “legacy reference dump”.
- If these are vendor drops, treat them as third-party and avoid mixing into the main narrative of the repo.
- If you want them in open source, ensure licensing is correct and that you are not accidentally redistributing huge model artifacts.

**`toolchains/`**
- Local machine caches (Rustup, Go module cache, etc.). These should never be tracked.
- Recommendation: do not keep toolchain caches inside the repo root long-term; store them in user-local paths.

**`memory/`, `windsurf_conversations/`, `local_models/`**
- Local runtime data and assets. Do not track in git for open source.
- Ensure docs explicitly state where runtime state lives and how to migrate it.

### Size Reality Check (Local Workspace Snapshot)
The working tree contains extremely large directories (GBs). For open-source distribution, the important point is not “what exists locally”, but “what is tracked in git”. Still, this footprint correlates with a high risk of accidentally committing large/private artifacts.

Observed on this machine (via `du -sh`, 2026-02-06):

```text
13G   .git
6.2G  archive/
5.5G  toolchains/
3.8G  frontends/
2.8G  whitemagic-julia/
2.2G  memory/
1.2G  whitemagic-rust/
884M  whitemagic-mojo/
800M  data/
504M  whitemagic-zig/
76M   mesh/
18M   whitemagic/
```

Implication: you must define a minimal open-source footprint and enforce it (ignore rules + CI checks), and you should strongly consider reinitializing git before your first public commit.

---

## Python Codebase Census (Automated Scan)

An automated scan was run using `audit/python_census.py`. Results:
- **2689 Python files**
- **540,673 lines of code**

Note: the current census script includes Python found under `archive/` and `toolchains/`. For “open-source core” metrics, consider excluding those paths.

Report output:
- `reports/python_census_v1.md`
- `reports/python_census.json`

Interpretation:
- The project is effectively multiple projects living together (active core + multiple “copies” + vendor dumps).
- For open-source usability, you need a clearly-defined “core path” that works reliably without reading the whole universe.

---

## Critical Technical Risks (P0)

### 1) Git Repo Is “Dirty Before First Commit”
There are **no commits yet** (`git log` reports an unborn `master`), but `.git/` is already **~13GB**.

`git count-objects -vH` currently reports:
- ~1.66 GiB loose objects
- ~4.50 GiB packed objects
- ~4.13 GiB garbage pack/tmp objects

This almost certainly came from an earlier `git add` that captured heavyweight content (e.g. build caches like `haskell/dist-newstyle/`, vendor dumps, toolchains, etc.).

**Recommendation (P0):**
- Treat the current `.git/` as tainted and make an explicit decision:
- Option A (simplest): **reinitialize git** before open-sourcing (delete `.git/`, `git init`, then add only the curated open-source surface).
- Option B: surgically unstage/remove cached files from the index, then aggressively prune unreachable objects (riskier, more error-prone, and still requires careful verification).

### 2) Docs And Build Artifacts Are Out Of Sync With Reality
Examples:
- `Makefile` points Rust to `whitemagic/whitemagic-rs` but the repo uses `whitemagic-rust/`.
- `Dockerfile` copies wheels from a path that doesn’t match `maturin build --out dist`, and runs `pip install .` without copying the package source first.
- `docker-compose.yml` uses `python -m whitemagic.cli ...` which does not match current Python entrypoints.
- `README.md` references packages/tools that don’t exist in this repo snapshot (`whitemagic-core`, `requirements.txt`, `npx whitemagic-mcp-setup`, etc.).

**Recommendation (P0):**
- Update `README.md` to a “commands that work from a clean clone” truth table.
- Fix or remove broken build instructions until they are validated.

### 3) Tests Do Not Complete (Hang)
`pytest` in the workspace virtualenv hangs at:
- `tests/unit/test_bridge.py::test_parallel_executor`

This blocks CI and prevents confidence-building for new contributors.

**Recommendation (P0):**
- Move `tests/unit/test_bridge.py` into `tests/integration/` (it’s a “verification script”, not a unit test).
- Refactor `test_parallel_executor` so it cannot hang:
- Use a top-level function for process pools (picklable), or force threadpool execution.
- Add timeouts and deterministic teardown.

### 4) Runtime State Is Not Fully Relocatable
Even when `WM_STATE_ROOT` is set, some components still write to user-home paths (`~/.whitemagic`, `~/.cache/whitemagic`). This breaks hermetic runs and fails in sandboxed/locked-down environments.

Evidence from `audit/tool_smoke.py`:
- Tool smoke test passes (85 tools, 0 failures), but logs include sandbox permission failures when writing outside the repo or `/tmp`.

**Recommendation (P0):**
- Define one canonical “state root” resolution function and use it everywhere.
- Prefer XDG base directories by default, but allow `WM_STATE_ROOT` to fully relocate *all* state for tests/containers.

---

## MCP As Canonical Interface: What To Normalize (P0/P1)

Right now, there are multiple overlapping “tool surfaces”:
- MCP server that exposes functions via a bridge module.
- A Python tool registry + dispatcher system (`whitemagic/tools/registry.py`, `whitemagic/tools/unified_api.py`).
- REST API gateway and OpenAI-compatible endpoints.
- CLI.

This creates ambiguity for both humans and AIs:
- Which tool list is authoritative?
- Which dispatcher is the source of truth for tool behavior?
- Which names are stable?

**Recommendation (P0/P1):**
1. Choose **one canonical tool registry** for schemas, names, safety levels.
2. Choose **one canonical dispatcher** that actually implements those tools.
3. Make MCP/REST/CLI thin adapters over that dispatcher.

A pragmatic target design:
- Canonical registry: `whitemagic/tools/registry.py`
- Canonical executor: `whitemagic/tools/unified_api.py` (but it should implement all registry tools)
- MCP server registers tools from the registry and calls the executor
- REST tools gateway calls the same executor
- OpenAI-compat endpoint uses the registry’s OpenAI schemas and calls the executor

---

## Local Models: Implications Of “Archived, Not First Class”

### Benefits
- Dramatically reduces maintenance burden and dependency complexity (Ollama, BitNet, LM Studio, torch, etc.)
- Keeps Whitemagic focused on what it can do best: memory, ingestion, patterning, orchestration, safety.
- Avoids security pitfalls of embedded execution paths.

### Costs
- You lose “single binary” experience where Whitemagic is both the tool substrate and the model.
- Some “autonomous intelligence” features that previously depended on embedded inference become stubs or require an external model loop.

### Recommended Replacement Pattern
Run a model externally (local or cloud) and let it call Whitemagic via MCP:
- External model: decides what to do next, writes plans, does reasoning.
- Whitemagic: stores/retrieves context, enforces safety gates, executes deterministic tools.

This is aligned with MCP’s design and is a cleaner separation of concerns.

---

## Gardens: Internal vs First-Class (Pros/Cons)

You stated a preference for “gardens internal”. That is reasonable and likely correct at this stage.

### Gardens Internal (Recommended For Now)
- Pros:
  - Smaller, safer public surface.
  - Faster refactors without breaking external users.
  - You can keep the “metaphor” rich internally, while exposing stable MCP tools.
- Cons:
  - Harder for third parties to build extensions (“garden plugins”) without depending on internals.

### Gardens First-Class (Only If You Want An Ecosystem)
- Pros:
  - Explicit extension framework.
  - External contributors can build “new gardens” reliably.
- Cons:
  - You must commit to a stable API contract, lifecycle, state model, and event contracts.
  - Versioning/testing burden increases significantly.

### Middle Path
Keep gardens internal in Python import terms, but make them first-class in MCP terms:
- Expose stable tools like `garden_status`, `garden_activate`, `garden_resonance_map`.
- Provide a narrow plugin interface later (tools + event subscribers), not a full public class hierarchy.

---

## Security & Safety Observations

There is a real security posture emerging:
- Path validation allowlists.
- Tool risk classification.

But there is drift:
- Risk table entries don’t always match the actual tool registry.
- Some tools are classified “dangerous” for historical reasons rather than real side effects.

**Recommendation (P1):**
- Generate risk policy from the canonical registry metadata.
- Make “dangerous” classification depend on capabilities:
  - filesystem write outside allowed roots
  - shell execution
  - network access
  - browser automation
  - secrets access

---

## Open-Source Readiness Checklist (Action Plan)

### Phase 1: Make The Core Installable And Runnable (P0)
1. Reinitialize git (recommended) or surgically clean the index so the first public commit cannot include build caches / vendor dumps / private artifacts.
2. Replace “marketing” setup docs with “commands that work”:
   - fix `README.md`
   - fix `Makefile`, `Dockerfile`, `docker-compose.yml` or remove them until validated
3. Validate install from a clean clone:
   - `python -m venv .venv && . .venv/bin/activate`
   - `pip install -e .[mcp,dev]` (or decide your default extras)
4. Make MCP runnable with one command:
   - `python3 whitemagic/run_mcp.py` (or a `wm mcp run` wrapper)
5. Fix tests so CI can run:
   - stop the hang in `tests/unit/test_bridge.py::test_parallel_executor`
6. Add CI smoke checks:
   - `python -m compileall -q whitemagic`
   - `python audit/tool_smoke.py` (isolated state root)
   - a small unit test subset that completes quickly

### Phase 2: Unify The Tool Surface (P1)
1. Choose one canonical registry + dispatcher.
2. Ensure MCP and REST use the same tool list and same execution code.
3. Document “stable tool contracts” for agents.

### Phase 3: Reduce Monorepo Weight (P1/P2)
1. Ensure huge local dirs never get tracked:
   - `memory/`, `local_models/`, `toolchains/`, `data/`, build artifacts, frontend node_modules
2. Decide what “ships”:
   - core Python only (recommended)
   - optional language accelerators via extras and separate docs
3. Consider splitting into multiple repos if you want a truly lightweight clone.

### Phase 4: Developer Experience (P2)
1. Fix `Makefile` paths to reflect real directories.
2. Provide `wm doctor` / `wm status` to validate environment.
3. Provide example MCP configuration and an installer script.

---

## Appendix: Useful Commands

These are helpful for an AI agent to validate progress:

```bash
# Python syntax validity (must be clean for open-source readiness)
python3 -m compileall -q whitemagic

# Python census (understands size and hotspots)
python3 audit/python_census.py

# Quick directory sizes (spot huge accidental artifacts)
du -sh -- */ .git 2>/dev/null | sort -h | tail -n 40

# Git object store bloat (helps decide if re-init is needed)
git count-objects -vH

# What is currently staged (dangerous before first commit)
git diff --cached --name-status | head -n 200
```
