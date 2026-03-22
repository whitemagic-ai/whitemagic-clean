---
name: Large File Decomposition
codename: PSR-028
army: tokio
type: fix_and_verify
priority: P2
clone_count: 50000
strategies: [parallel, architecture]
category: architecture
phase: next
source: polyglot_scout_auto_20260218
column_size: 3
---

## Objective

Auto-generated from polyglot-scout findings (architecture category).
Scout found **198 architecture findings** across the codebase on 2026-02-18.


## Victory Conditions

- [x] Large files (>300 lines) catalogued (198 architecture findings)
- [x] `cli_app.py` Dharma CLI group extracted to `cli/commands/dharma_commands.py`
- [x] `cli_app.py` wisdom group extracted to `cli/commands/wisdom_commands.py`
- [x] `cli_app.py` maintenance group extracted to `cli/commands/maintenance_commands.py`
- [x] `cli_app.py` gana group extracted to `cli/commands/gana_commands.py` (~130 lines saved)
- [x] `cli_app.py` scratchpad group extracted to `cli/commands/scratchpad_commands.py` (~160 lines saved)
- [x] `cli_app.py` army group extracted to `cli/commands/army_commands.py`
- [x] `cli_app.py` dream group extracted to `cli/commands/dream_commands.py`
- [x] `cli_app.py` balance group extracted to `cli/commands/balance_commands.py`
- [x] `cli_app.py` vault group extracted to `cli/commands/vault_commands.py`
- [x] resonance/health commands extracted to `cli/commands/health_commands.py` (~200 lines)
- [x] conductor commands extracted to `cli/commands/conductor_commands.py` (~230 lines)
- [x] scratchpad group extracted to `cli/commands/scratchpad_commands.py`
- [x] `cli_app.py` reduced below 1500 lines (1386 lines, was 2807 — 51% reduction)
- [x] All extracted modules import-tested (10/10 critical path tests passing)

**Status**: 5/5 VCs (100%) ✅ COMPLETE — 12 modules extracted, 2807→1386 lines (Feb 18 2026) - First decomposition complete: cli_app.py 2920→2803 lines (Feb 18 2026)

## Targets

| File | Line | Finding |
|------|------|---------|
| (run scout --json for full list) | - | - |

## Strategy

1. Run `./whitemagic-rust/target/release/polyglot-scout /path --json` to get latest findings
2. Sort by severity (4=critical first)
3. For each finding: apply fix, verify, commit
4. Re-run scout to confirm finding count drops

## Verification

```bash
./whitemagic-rust/target/release/polyglot-scout /home/lucas/Desktop/whitemagicdev/whitemagic --json \
  | python3 -c "import json,sys; d=json.load(sys.stdin); print(d['findings_by_category'])"
```
