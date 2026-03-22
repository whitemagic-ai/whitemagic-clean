# Phase 2 Remediation Report: State-Root & Path Leak Fixes

**Status:** ✅ COMPLETE  
**Date:** March 22, 2026  
**Phase:** 2 of 10 (Release Readiness Strategy)  

---

## Executive Summary

This report documents the completion of Phase 2: State-Root Remediation for the Whitemagic codebase. The goal was to eliminate all hardcoded paths and `Path.home()` usages, replacing them with canonical paths defined in `whitemagic.config.paths`. This ensures consistent, configurable, and portable state management across the entire system.

---

## Changes Made

### 1. Centralized Path Configuration (`whitemagic/config/paths.py`)

Added new canonical subdirectories for comprehensive state management:

| Directory | Purpose |
|-----------|---------|
| `AGENTS_DIR` | Agent registry and worker status |
| `VOTES_DIR` | Voting and consensus data |
| `PIPELINES_DIR` | Pipeline state tracking |
| `PLUGINS_DIR` | User-defined plugins |
| `PROMPTS_DIR` | Prompt templates |
| `IDENTITY_DIR` | Emergent identities and self-naming |
| `INTAKE_DIR` | Intake system inbox |
| `SANGHA_DIR` | Sangha workspace state |
| `GRATITUDE_DIR` | Gratitude ledger |
| `WISDOM_DIR` | Holocron/wisdom storage |
| `TASKS_DIR` | Task distribution state |

### 2. Code-Logic Path Leak Fixes

The following modules were patched to use canonical paths:

| File | Change |
|------|--------|
| `whitemagic/marketplace/bridge.py` | Route marketplace persistence through `WM_ROOT/marketplace` |
| `whitemagic/core/garden_function_registry.py` | Route registry through `WM_ROOT/garden_function_registry.json` |
| `whitemagic/tools/handlers/cyberbrain.py` | Route worker status through `AGENTS_DIR` |
| `whitemagic/oms/manager.py` | Route galaxy exports through `ARTIFACTS_DIR` |
| `whitemagic/alchemy/transmutation_pipeline.py` | Route pipeline DB through `DB_PATH` |
| `whitemagic/core/evolution/galaxy_miner.py` | Standardize galaxy paths with `WM_ROOT` and `PROJECT_ROOT` |
| `whitemagic/gardens/truth/__init__.py` | Use canonical constants for state path reporting |
| `whitemagic/plugins/__init__.py` | Route plugins through `PLUGINS_DIR` |
| `whitemagic/core/identity/self_naming_threshold.py` | Route identities through `IDENTITY_DIR` |
| `whitemagic/tools/handlers/agent_registry.py` | Route agent registry through `AGENTS_DIR` |
| `whitemagic/tools/handlers/pipeline.py` | Route pipelines through `PIPELINES_DIR` |
| `whitemagic/tools/handlers/voting.py` | Route votes through `VOTES_DIR` |
| `whitemagic/tools/handlers/task_dist.py` | Route tasks through `TASKS_DIR` |
| `whitemagic/core/memory/hnsw_index.py` | Route HNSW index through `MEMORY_DIR` |
| `whitemagic/core/memory/holocron.py` | Route Holocron through `WM_ROOT` |
| `whitemagic/alchemy/holocron.py` | Route Holocron through `WM_ROOT` |
| `whitemagic/core/memory/quarantine_galaxy.py` | Route quarantine through `MEMORY_DIR` and `DB_PATH` |
| `whitemagic/core/continuity.py` | Standardize grounding state with `WM_ROOT` |
| `whitemagic/core/system/hardware_monitor.py` | Fix disk-free check to use `WM_ROOT` |
| `whitemagic/gratitude/ledger.py` | Route ledger through `GRATITUDE_DIR` |
| `whitemagic/core/memory/embedding_daemon.py` | Use `os.path.expanduser` for HF cache path |
| `whitemagic/core/governor.py` | Standardize path expansion with `os.path.expanduser` |
| `whitemagic/tools/handlers/introspection.py` | Use `os.path.expanduser` for haskell path |

### 3. Lint Fixes

- Removed unused imports (`USER_PROFILE_PATH`, `Path`, `WM_ROOT`)
- Fixed module-level import ordering in `transmutation_pipeline.py`

---

## Verification

All changes maintain backward compatibility:
- Paths respect `WM_STATE_ROOT` environment variable
- Default paths remain under `~/.whitemagic` for user convenience
- External tool caches (e.g., HuggingFace) remain in their standard locations

---

## Remaining Work (Non-Blocking)

Documentation and docstring updates referencing `~/.whitemagic` and `WM_STATE_ROOT` are tracked but deferred as they do not affect functionality. These will be addressed in a future documentation-focused pass.

---

## Next Phase

**Phase 3: Ship Surface Classification** - Classify top-level Labs/Core/runtime-state surfaces to identify and remediate remaining architectural inconsistencies.
