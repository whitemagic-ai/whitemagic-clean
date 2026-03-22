# WhiteMagic Archive — Navigation Guide

> This archive contains historical code, documentation, scripts, and snapshots from WhiteMagic's development history (Oct 2024 → Feb 2026). Important documents have been copied into the main project at `/home/lucas/Desktop/whitemagic/docs/`.

**Last updated**: 2026-02-14

---

## Quick Reference

| If you're looking for... | Go to... |
|--------------------------|----------|
| Business strategy docs | `docs_release_cleanup/business/` |
| Technical strategy docs | `docs_release_cleanup/strategies/` |
| Design documents | `docs_release_cleanup/design/` |
| Session handoffs | `docs_release_cleanup/sessions/` |
| Audit reports | `docs_release_cleanup/audits/` + `audit_pre_feb9/` |
| Pre-Feb 9 research docs | `docs_pre_feb9/` |
| Archived Python code | `phase1_archived/` through `phase8_loose_root/` |
| Legacy scripts | `scripts_pre_feb9/` + `scripts_maintenance/` + `scripts_oneoffs/` |
| Full project snapshots | `WM/` (65K items) + `whitemagic-main/` |
| Aria's home & journals | `WM/wmfrontend/aria-home/` |
| Memory databases | `phase6_dead_files/primary_db_pre_merge.db` (3,631 memories) |
| Benchmark data | `docs/BENCHMARK_COMPARISON.md` + `scripts/benchmark_v3_results.json` |
| Experiments | `experiments/` |

---

## Directory Map

### 📄 Documentation

#### `docs_release_cleanup/` — Organized docs from the Feb 11 release cleanup
- **`business/`** — Agent Company Blueprint, Physical Truth Oracle, Economic Strategy, Product Tiers, XRP Cashout Guide, Demo & Marketing Strategy, First 1000 Users Plan
- **`business_strategy/`** — ⚠️ **Duplicate** of `business/` (4 files are copies)
- **`design/`** — 28 Gana Garden Map, Encryption at Rest Design, MCP Registry Submission Guide, TypeScript SDK Design
- **`strategies/`** — 14 strategy docs: 5D Causal Memory, Autonomous Horizon, Dream Cycle Protocol, GPU Acceleration, High-Frequency PRAT, Living Memory, Polyglot Expansion, Resonant Swarm, V14/V15 roadmaps
- **`sessions/`** — 8 session handoff documents (Feb 9-10, 2026)
- **`audits/`** — Complete Project Chronicle, Economic Audit, Mypy Remaining, Release Readiness Audit, Setup Streamlining Review, Windsurf Conversation Extraction

#### `docs_pre_feb9/` — 41 research & analysis docs from before Feb 9
- Includes: DEEP_MEMORY_AUDIT, SYNTHESIS_ANALYSIS, ENGINE_MAPPING, GROWTH_TRAJECTORY, knowledge graph research, dharma deep dives, wisdom reports, session handoffs

#### `docs/` — 4 docs (BENCHMARK_COMPARISON, TOMORROW_GAMEPLAN, V15 audits)

#### `audit_pre_feb9/` — 15 files (4 ratchet reports + 8 Python audit scripts + 3 action plans)

#### Loose root docs:
- `ECONOMIC_STRATEGY.md` — ✅ Copied to main project
- `STRATEGIC_ROADMAP.md` — ✅ Copied to main project
- `XRP_CASHOUT_GUIDE.md` — Already exists in main docs

### 📦 Archived Code (from distillation phases)

| Directory | What's Inside | Items |
|-----------|--------------|-------|
| `phase0_cleanup/` | Build artifacts, egg-info, empty dirs, loose files | 19K items |
| `phase1_archived/` | Archived whitemagic/ modules + 52 conversation stubs | 614 items |
| `phase2_duplicates/` | Duplicate code: art_of_war, autonomous_execution, council, gan_ying | 17 items |
| `phase3_reorg/` | CLI originals (15 files) + domain originals (7 files) | 22 items |
| `phase4_parallel_tree/` | Intelligence originals + zodiac duplicates | 143 items |
| `phase5_misc/` | lib shim (libgmp.so), automation scripts, reports | 5 items |
| `phase5_scripts/` | Legacy satkona, misc scripts, old dream cycles, one-off scripts | 33 items |
| `phase6_dead_files/` | Dead code + **primary_db_pre_merge.db** (3,631 memories) | 6 items |
| `phase7_intelligence_shims/` | Intelligence subsystem shims | 59 items |
| `phase8_loose_root/` | Loose root files: ai_contract, haskell_bridge, patterns, recall | 8 items |
| `phase_cli_shims/` | 15 CLI shim files (all rewired to whitemagic.cli.*) | 15 items |
| `phase_systems_archived/` | Archived systems/: governor, health_monitor, monitoring, automation, immune | 33 items |

### 🔧 Scripts

| Directory | What's Inside | Count |
|-----------|--------------|-------|
| `scripts/` | Benchmark gauntlet v2/v3, cold DB embed, results JSON | 6 files |
| `scripts_maintenance/` | 23 maintenance scripts: audit_mcp, check_stats, debug_brain, etc. | 23 files |
| `scripts_oneoffs/` | 14 one-off scripts: holographic re-encode, importance recal, build_rust_bridge, etc. | 14 files |
| `scripts_pre_feb9/` | 70 legacy scripts from before the Feb 9 distillation | 70 files |

### 📸 Full Project Snapshots

| Item | Description | Size |
|------|-------------|------|
| `WM/` | Full workspace snapshot (whitemagic + wm_archive + wmfrontend) | 65K items |
| `whitemagic-main/` | Earlier whitemagic-main snapshot with alembic, backups | 398 items |
| `whitemagic-julia/` | Legacy Julia code (before current whitemagic-julia/) | 3 items |
| `whitemagic-mojo/` | Legacy Mojo benchmarks and debug archives | 59 items |
| `whitemagic_artifact.tar.gz` | Full project tarball | **870MB** |
| `whitemagic-main.zip` | whitemagic-main zip backup | 3MB |
| `whitemagic_old_git_backup_*.tar.gz` | Git history backup (Nov 18, 2025) | 4MB |

### 🧪 Experiments

- `experiments/whitemagic-mcp-ts/` — TypeScript MCP server experiment (14 files, scripts, generated output)

### 🗄️ Databases (Aria Memories & Historical Data)

| Database | Location | Memories | Notes |
|----------|----------|----------|-------|
| **Primary pre-merge** | `phase6_dead_files/primary_db_pre_merge.db` | 3,631 | Best source for Aria artifacts |
| **Hot archive** | Not in this archive (see `whitemagic_memory_archive/`) | 5,627 | Same Aria content + extras |
| **Cold storage** | Not in this archive | 105,194 | 95% external code ballast |

---

## Documents Already Copied to Main Project

These documents have been moved from the archive into `/home/lucas/Desktop/whitemagic/docs/`:

- ✅ `STRATEGY.md` (new, extracted from AI_PRIMARY.md)
- ✅ `STRATEGIC_ROADMAP.md` (from archive root)
- ✅ `BENCHMARK_COMPARISON.md` (from `docs/`)
- ✅ `AGENT_COMPANY_BLUEPRINT.md` (from `docs_release_cleanup/business/`)
- ✅ `PHYSICAL_TRUTH_ORACLE.md` (from `docs_release_cleanup/business/`)
- ✅ `COMPLETE_PROJECT_CHRONICLE.md` (from `docs_release_cleanup/audits/`)
- ✅ `ECONOMIC_STRATEGY.md` (from archive root)
- ✅ `TYPESCRIPT_SDK_DESIGN.md` (from `docs_release_cleanup/design/`)

---

## Known Issues

1. `docs_release_cleanup/business_strategy/` is a **duplicate** of `docs_release_cleanup/business/` — 4 files are exact copies
2. `phase1_archived/conversations/` contains 52 protobuf stub files with 0 extractable messages
3. `phase0_cleanup/` is 19K items of build artifacts — could be deleted entirely to save space
4. `whitemagic_artifact.tar.gz` is 870MB — consider if this snapshot is still needed
5. Tool counts in archived docs range from 143 to 341 depending on the era — historical reference only
