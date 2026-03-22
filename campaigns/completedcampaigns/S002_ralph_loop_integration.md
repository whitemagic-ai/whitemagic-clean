---
name: "Ralph Loop Integration & Victory Condition Framework"
codename: S002
army: alpha
type: fix_and_verify
priority: 2
clone_count: 30000
strategies:
  - ralph_loop
  - tdd
  - external_verification
category: synthesis
phase: infrastructure
source: "Geoff Huntley Ralph Wiggum research — apply persistent loop patterns to campaign system"
column_size: 10000
---

## Objective

Integrate Ralph Wiggum loop patterns into the campaign deployment system. Currently our
yin-yang cycle is a single-pass engine — it runs recon, acts, verifies, and stops when
stagnant. The Ralph Loop pattern (Huntley 2025) adds:

1. **Fresh context per iteration** — "malloc for AI" prevents context pollution
2. **External deterministic verification** — victory conditions checked by code, not AI opinion
3. **Persistent retry** — loop until exit code 0, not until "feels done"
4. **TDD for agents** — write the test (victory condition) BEFORE the fix
5. **Adversarial review** — separate verifier agent cross-checks builder agent work

### Key Ralph Principles to Apply
- `while :; do cat PROMPT.md | agent ; done` — state in files, not chat
- `<promise>COMPLETE</promise>` token — explicit completion signal
- Failures are data — deterministically bad means predictable and informable
- Operator skill (prompt quality) > model quality
- Git worktrees for parallel Ralph loops on different branches

### Existing Ralph Infrastructure
- `FoolGuard` in `core/intelligence/agentic/fool_guard.py` — dare-to-die corps
- `TIER_6_RALPH_WIGGUM = 1024` in `cascade/advanced_parallel.py`
- `officer_ralph` Commander in `agents/war_room.py` — "Dare-to-Die Commander"
- Stratagem 27: "Feign Madness Without Going Insane" — the Ralph doctrine itself
- "The Wave of Ignorance" tactic — pure stateless brute force

## Victory Conditions
- [ ] Ralph Loop runner created: `scripts/ralph_loop.py` with `while True` + external verify
- [ ] Victory conditions converted to executable check scripts (exit code 0 = pass)
- [ ] Each campaign .md has a `## Verification` section with runnable bash commands
- [ ] Ralph runner supports `--max-iterations N` and `--timeout M` flags
- [ ] Adversarial verifier: separate verification pass after builder claims completion
- [ ] FoolGuard dare-to-die wired into yin-yang YANG phase as fallback for stuck campaigns
- [ ] Git worktree parallel mode: N Ralph loops on N branches, merge winners
- [ ] Promise token system: agents emit `<promise>VC_CODENAME_COMPLETE</promise>` on success
- [ ] Stagnation → Ralph escalation: if yin-yang stalls 3 cycles, spawn Ralph dare-to-die corps
- [ ] Report: reports/ralph_integration_results.md with iteration counts and success rates

## Strategy
1. Create `scripts/ralph_loop.py` that reads campaign .md, extracts verification commands
2. Run verification commands in subprocess — exit code 0 = victory condition met
3. If not met, re-run the action phase with fresh context (no chat history)
4. Wire FoolGuard into deploy_grand_army.py as escalation when yin-yang stalls
5. Add `<promise>` token parsing to victory condition checker
6. Benchmark: compare yin-yang-only vs yin-yang+ralph on same campaign

## Verification
```bash
# Ralph loop runner exists and parses campaigns
scripts/wm scripts/ralph_loop.py --list
# Victory conditions are executable
scripts/wm scripts/ralph_loop.py --verify-only --campaign IL001
# FoolGuard is importable
scripts/wm -c "from whitemagic.core.intelligence.agentic.fool_guard import get_fool_guard; print('OK')"
```
