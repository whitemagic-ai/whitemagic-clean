---
name: "Auto-Prompting Supervisor — The 70% Manager Removal"
codename: G004
army: alpha
type: discovery
priority: 1
clone_count: 25000
strategies:
  - analytical
  - synthesis
  - chain_of_thought
category: intelligence
phase: infrastructure
source: "Gemini transcript — automate the 70% managerial prompts; user becomes Muse, not Manager"
column_size: 12500
---

# Auto-Prompting Supervisor — The 70% Manager Removal

## Objective

Build a "Supervisor Loop" that automatically generates the routine 70% of prompts
that a human manager currently provides: "review this code," "write the session
handoff," "double-check that," "synthesize and optimize." The AI self-prompts these
actions based on high-scored patterns from the Thought Galaxy (G003), freeing the
user to focus on the 30% novel ideas that actually change things.

**Core insight**: Only ~30% of user contributions are novel ideas. The rest is
managerial supervision that the AI should be doing itself — and learning which
self-prompts lead to better outcomes.

## Victory Conditions

- [x] Prompt taxonomy created: classify all user prompts into categories (review, handoff, check, synthesize, novel_idea, etc.)
- [x] Standard Operating Procedures (SOPs) defined for each routine category
- [x] Post-action reflection: after every file write, system auto-triggers a review SOP
- [x] Session boundary detection: on inactivity or "task complete," auto-triggers handoff summary SOP
- [x] Self-prompt scoring: each auto-generated prompt gets an outcome score (did it catch a bug? improve quality?)
- [x] Adaptive frequency: high-scored self-prompts run more often; low-scored ones get deprecated
- [x] User override: user can disable/enable specific SOPs via `wm supervisor enable/disable <sop>`
- [x] Integration with yin-yang cycle: Yang (action) phases auto-trigger Yin (review/reflect) transitions
- [x] Metrics dashboard: `wm supervisor status` shows SOP hit rates, bugs caught, quality improvements
- [x] Historical analysis: run prompt taxonomy over 100+ past session handoffs to identify the actual 70/30 split
- [x] Report: `reports/auto_prompting_supervisor.md` with taxonomy, SOPs, and effectiveness data

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Supervisor engine | `whitemagic/autonomous/supervisor.py` | New module |
| SOP definitions | `whitemagic/autonomous/sops/` | New directory with SOP configs |
| Prompt classifier | `whitemagic/core/intelligence/prompt_classifier.py` | New module |
| CLI | `whitemagic/cli/cli_app.py` | `wm supervisor status/enable/disable` |
| Yin-Yang integration | `scripts/deploy_grand_army.py` | Wire SOPs into cycle transitions |

## Strategy

1. Analyze 100+ historical session transcripts to build prompt taxonomy
2. Classify each prompt type and measure frequency (validate the 70/30 hypothesis)
3. Define SOPs for each routine category (review, handoff, check, synthesize)
4. Build supervisor engine that monitors agent state and triggers SOPs
5. Wire outcome scoring: did the self-prompted review catch a real bug?
6. Implement adaptive frequency based on Thought Galaxy outcome scores
7. Add user controls for enabling/disabling specific SOPs
8. Integrate with yin-yang cycle transitions

## Verification

- Run supervisor in "shadow mode" for 1 full session (logs what it would do, doesn't act)
- Verify it would have caught ≥3 issues that required manual prompting
- Prompt taxonomy validated against real session data (not hypothetical)
- User can cleanly enable/disable individual SOPs
