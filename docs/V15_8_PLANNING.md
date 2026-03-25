# WhiteMagic v15.8 Planning Document

**Date**: February 13, 2026
**Previous Release**: v15.7.0 (CI green, PyPI published)
**Status**: Planning

---

## 1. First-Time Installer Experience

### Current State (v15.7)

A fresh `pip install whitemagic` on a new machine:

1. **Creates** `~/.whitemagic/` automatically on first use
2. **Auto-provisions** empty SQLite DB with full schema (all tables, columns, FTS index)
3. **All tools work** — `create_memory`, `search_memories`, `gnosis`, `capabilities` all return success
4. **Maturity assessment** starts at REFLECTIVE (Stage 3/6) with 23 capabilities
5. **DB starts at 4KB** — completely empty, no seed content

### What's Missing

| Gap | Impact | Priority |
|-----|--------|----------|
| No welcome/tutorial content | User gets empty DB, no idea what to do | **P0** |
| No `whitemagic init` command | No guided first-run experience | **P0** |
| No seed memories | `search_memories` returns nothing on fresh install | P1 |
| `WM_SILENT_INIT` not set by default | Noisy log output on first import | P1 |
| No "getting started" CLI flow | User must know the API to do anything | P1 |
| `PROJECT_ROOT` points to site-packages | `archaeology`, `grimoire_audit` won't find repo files | P2 |

### Proposed: `whitemagic init` Command

```
$ whitemagic init

  Welcome to WhiteMagic v15.7.0!

  State directory: ~/.whitemagic/
  Database: ~/.whitemagic/memory/whitemagic.db

  Seeding starter memories...
    - WhiteMagic quickstart guide
    - Tool reference (384 tools across 28 Ganas)
    - Architecture overview
    - Example: how to store and search memories

  Done! 4 seed memories created.

  Try these next:
    whitemagic explore          # Interactive feature guide
    whitemagic search "hello"   # Search your memories
    whitemagic doctor           # System health check
```

### Proposed: Seed Content

The `scripts/seed_quickstart_memories.py` already exists but isn't integrated into the install flow. For v15.8:

1. Move seed logic into `whitemagic/cli/init_command.py`
2. Auto-detect first run (no DB exists) and suggest `whitemagic init`
3. Seed 5-10 starter memories covering:
   - What WhiteMagic is and how it works
   - The 28 Gana tool organization
   - How to create, search, and manage memories
   - The dream cycle and what it does
   - The maturity progression system
4. Set a `_initialized` flag in config.json so seed only runs once

---

## 2. Maturity Assessment System

### Architecture

The maturity system (`whitemagic/core/governance/maturity_gates.py`) implements a
**gated developmental progression** inspired by Julian Jaynes' bicameral mind theory
and Alice Bailey's consciousness hierarchy.

### The 6 Stages

| Stage | Name | Value | Gate Checks | What It Means |
|-------|------|-------|-------------|---------------|
| 1 | **SEED** | 1/6 | Memory system + tool registry operational | Bare minimum: can store/retrieve memories and dispatch tools |
| 2 | **BICAMERAL** | 2/6 | Governor + event bus verified | System can self-regulate: governor validates actions, event bus enables reactive behavior |
| 3 | **REFLECTIVE** | 3/6 | Retention engine + salience arbiter + temporal scheduler | System is self-aware: can evaluate what to remember/forget, prioritize attention, schedule tasks |
| 4 | **RADIANT** | 4/6 | ≥5 memories + homeostasis coherence ≥0.5 | System is sharing surplus: multi-agent coordination, garden management, API publishing |
| 5 | **COLLECTIVE** | 5/6 | Mesh proto available + Zodiac Council active | System participates in networks: cross-node sync, guild contracts, swarm reasoning |
| 6 | **LOGOS** | 6/6 | Foresight engine (not yet implemented) | Aspirational: long-horizon planning, scenario mapping, planetary-scale design |

### The 23 Capabilities at REFLECTIVE (Stage 3)

A fresh install currently reaches REFLECTIVE because Stages 1-3 gate checks
all pass (the subsystems initialize successfully even with an empty DB).

**Stage 1 — SEED (7 capabilities):**
- `memory.create` — Store new memories
- `memory.read` — Retrieve memories by ID
- `memory.search` — Full-text search across memories
- `memory.list` — List/paginate memories
- `tools.registry` — Access the tool registry (384 tools)
- `tools.dispatch` — Execute tools via unified API
- `cli.basic` — Basic CLI commands

**Stage 2 — BICAMERAL (7 capabilities):**
- `governor.validate` — Validate actions against ethical rules
- `governor.budget` — Resource budget enforcement
- `event_bus.emit` — Emit events (Gan Ying resonance)
- `event_bus.listen` — Subscribe to system events
- `temporal_scheduler.fast` — Fast-cycle scheduling (seconds)
- `temporal_scheduler.medium` — Medium-cycle scheduling (minutes)
- `mcp.serve` — Serve as MCP tool provider

**Stage 3 — REFLECTIVE (9 capabilities):**
- `consciousness.self_reflect` — Self-reflection and introspection
- `consciousness.narrative` — Narrative voice generation
- `retention.evaluate` — Evaluate memory retention worthiness
- `retention.sweep` — Sweep and archive low-value memories
- `salience.score` — Score memory salience/importance
- `salience.spotlight` — Surface most salient items
- `temporal_scheduler.slow` — Slow-cycle scheduling (hours/days)
- `memory.consolidate` — Consolidate and merge related memories
- `patterns.detect` — Detect recurring patterns

### Should It Have More?

**Current assessment**: 23 capabilities is appropriate for a fresh install.
The system correctly identifies that foundational subsystems are operational.

**What's NOT yet unlocked** (and shouldn't be on a fresh install):
- Stage 4 (RADIANT): Requires ≥5 memories AND homeostasis coherence ≥0.5.
  A new user naturally progresses here after creating a few memories and
  running their first dream cycle.
- Stage 5 (COLLECTIVE): Requires mesh proto and Zodiac Council — multi-node features.
- Stage 6 (LOGOS): Aspirational — foresight engine not yet implemented.

**Potential improvements for v15.8:**
1. The RADIANT gate could also check for:
   - At least 1 completed dream cycle
   - At least 1 association created
   - Karma ledger has recorded ≥10 actions
2. The capability names could be more discoverable (e.g., map to actual tool names)
3. `whitemagic maturity` CLI command to show the full report

---

## 3. v15.7 Retrospective — Lessons Learned

### What Went Well
- CI pipeline now green on both Python 3.11 and 3.12
- PyPI publishing automated via GitHub Actions release workflow
- `pip install whitemagic` works cleanly with minimal dependencies (7 packages)
- CLI entry point works from pip install
- 384 tools registered, all dispatchable
- Fresh install creates state directory automatically
- Maturity assessment runs correctly on empty DB

### What We Fixed
- 34 CI failures from missing `importorskip` guards for optional dependencies
- 11 Codex audit fixes (removed APIs, type mismatches, import errors)
- `bs4` parser fallback (`lxml` → `html.parser`)
- 2 test files inside the `whitemagic/` package (now moved to `tests/unit/`)
- 21 internal-only scripts removed from public repo
- `_conn_injected` flag for Rust accelerator test isolation

### What Needs Improvement
- 12 local-only test failures from cross-test DB pool contamination (whitemagic_rs)
- `PROJECT_ROOT` resolves into site-packages for pip-installed users
- No first-run experience (empty DB, no guidance)
- Info-level logs are noisy on first import (Harmony Vector, Dharma, etc.)
- Search returns memory IDs instead of titles in some response shapes

---

## 4. v15.8 Feature Proposals

### P0 — First-Time Experience
1. **`whitemagic init` command** — Guided setup, seed content, suggest next steps
2. **Auto-seed on first use** — Detect empty DB, seed 5-10 starter memories
3. **Quieter defaults** — Set `WM_SILENT_INIT` behavior as default, add `--verbose` flag
4. **`whitemagic explore` improvements** — Interactive walkthrough of features

### P1 — Developer Experience
5. **Fix `PROJECT_ROOT` for pip installs** — Use `importlib.resources` to find
   package data instead of filesystem traversal from `__file__`
6. **Fix cross-test DB pool contamination** — Ensure singleton reset properly
   closes all SQLite connections and clears connection pools
7. **`whitemagic maturity` CLI command** — Show full maturity report with
   stage explanations and next-gate requirements
8. **Response shape consistency** — Ensure `search_memories` always returns
   `title` field, not just `id`

### P2 — Ecosystem
9. **Starter packs** — Pre-built memory collections users can install:
   - `whitemagic install-pack coding` — Programming knowledge base
   - `whitemagic install-pack philosophy` — Philosophical corpus
   - `whitemagic install-pack productivity` — GTD/productivity patterns
10. **`whitemagic status` dashboard** — One-command health + stats overview
11. **Improved dream cycle onboarding** — Explain what each phase does,
    show results in human-readable format
12. **MCP quickstart guide** — How to connect WhiteMagic to Windsurf/Claude/etc.

### P3 — Architecture
13. **Lazy subsystem initialization** — Don't initialize Harmony Vector, Dharma,
    etc. until actually needed. Reduces cold-start time for simple operations.
14. **Connection pool lifecycle** — Proper close/cleanup when singletons are reset.
    Eliminates the 12 cross-test contamination failures.
15. **Configurable log levels** — Default to WARNING for pip-installed users,
    DEBUG for development mode (detect via editable install or env var).

---

## 5. Release Checklist for v15.8

- [ ] Implement `whitemagic init` with seed content
- [ ] Fix `PROJECT_ROOT` resolution for pip installs
- [ ] Add `whitemagic maturity` CLI command
- [ ] Quiet default logging for end users
- [ ] Fix response shape consistency (titles in search results)
- [ ] Fix cross-test DB pool contamination
- [ ] Update VERSION to 15.8.0
- [ ] Run full CI (py3.11 + py3.12) — expect 0 failures
- [ ] Test fresh PyPI install in clean venv
- [ ] Tag and release v15.8.0
