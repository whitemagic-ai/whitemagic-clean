# P2 Scouting Report (Run 2) — 2026-02-09

## Purpose
Quick project-wide reconnaissance before the next ratchet pass, focused on:
- global static quality concentration,
- likely high-yield next clusters,
- potential blind spots (security/risk patterns),
- clarity for sequencing.

## Current Baseline

- Full mypy (`whitemagic/**`, includes `_archived`): **3692 errors in 636 files** (`1068` checked)
- Full mypy (non-archived analysis): **2494** errors
- Mypy (`whitemagic/interfaces` + `whitemagic/tools`): **1450 errors in 248 files**
  - Note: this command follows imports into core modules; `interfaces/tools` local residual is now zero.
- Ruff (`whitemagic`, excluding `_archived`): **588**
  - `E402`: 571
  - `E741`: 11
  - `F811`: 5
  - `F823`: 1
- Tests: **1199 passed, 4 skipped**

## Error Shape (non-archived mypy)

Top error codes:
- `no-untyped-def`: 1255
- `assignment`: 229
- `attr-defined`: 217
- `no-any-return`: 181
- `arg-type`: 130

Interpretation:
- Largest remaining debt is broad annotation coverage (`no-untyped-def`).
- Most bug-relevant remaining classes are `attr-defined` and `arg-type`.

## Highest-Pressure Files (non-archived)

- `whitemagic/cli_app.py` (77)
- `whitemagic/optimization/polyglot_router.py` (38)
- `whitemagic/core/immune/response.py` (34)
- `whitemagic/core/automation/consolidation.py` (33)

## Candidate Cluster Sizing

### Cluster A — Bridge + Fusions (recommended first)
- Total: **24**
- `whitemagic/core/fusions.py` (6)
- `whitemagic/core/bridge/tools.py` (12)
- `whitemagic/core/bridge/garden.py` (3)
- `whitemagic/core/bridge/gana.py` (2)
- `whitemagic/core/bridge/memory.py` (1)

Why first:
- Small scope,
- concrete and localized error types,
- aligns with previous roadmap direction.

### Cluster B — Automation
- Total: **75**
- `whitemagic/core/automation/consolidation.py` (33)
- `whitemagic/core/automation/orchestra.py` (21)
- `whitemagic/automation/daemon.py` (21)

### Cluster C — Optimization/Polyglot
- Total: **50**
- `whitemagic/optimization/polyglot_router.py` (38)
- `whitemagic/optimization/rust_accelerators.py` (12)

### Cluster D — Immune Stack
- Total: **40**
- `whitemagic/core/immune/response.py` (34)
- `whitemagic/core/immune/health_check.py` (5)
- `whitemagic/core/immune/pattern_immunity.py` (1)

## Ruff Recon

- Non-E402 tail is only **17** findings (`E741+F811+F823`) and can be burned down quickly.
- E402 concentration leaders include:
  - `core/intake/holographic_intake.py` (10)
  - `core/memory/unified.py` (10)
  - `export_import.py` (10)

## Risk Pattern Recon

- No active `shell=True` execution found in Python code.
- `exec(...)` appears in `whitemagic/execution/sandbox.py`, but guarded by explicit env switch (`WHITEMAGIC_ENABLE_IN_PROCESS_EXEC=true`) and documented with security warnings.
- This is a conscious risk boundary, not a silent code path.

## Suggested Immediate Sequence

1. Execute **Cluster A** (`core/bridge/*` + `core/fusions.py`) for quick, low-risk reduction.
2. Burn down non-E402 ruff tail (`E741/F811/F823`).
3. Decide next major block by objective:
   - max reduction: Cluster B,
   - polyglot correctness: Cluster C,
   - governance/defense correctness: Cluster D.

## Execution Update (After This Scout)

- Cluster A completed (bridge + fusions files now absent from full-project mypy error list).
- Non-E402 Ruff tail completed:
  - `ruff` **588 -> 571** (E402-only now).
- Mypy progression:
  - full project (includes `_archived`): **3692 -> 3625**
  - non-archived analysis: **2494 -> 2454**
  - `interfaces + tools`: **1450 -> 1422**
- Validation remains green: `pytest -q --no-header tests` => **1199 passed, 4 skipped**.
