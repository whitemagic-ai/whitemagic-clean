---
name: "Thought Galaxy — Meta-Cognitive Memory"
codename: G003
army: beta
type: discovery
priority: 1
clone_count: 60000
strategies:
  - analytical
  - synthesis
  - chain_of_thought
category: intelligence
phase: infrastructure
source: "Gemini transcript — store reasoning traces with outcome scoring for recursive self-improvement"
column_size: 30000
---

# Thought Galaxy — Meta-Cognitive Memory

## Objective

Create a dedicated "Thought Galaxy" in the holographic memory core that stores
not just results but the **reasoning trajectories** that produced them. Each
"Cognitive Episode" is scored from -1.0 (failed/hallucinated) to +1.0
(novel breakthrough), enabling the AI to introspect its own thought processes,
learn from good patterns, and avoid bad ones.

**Core insight**: If the AI discards its thought process, it fails to learn from
experience. By storing and scoring reasoning traces, we build a library of
cognitive patterns and anti-patterns that enables recursive self-improvement.

## Victory Conditions

- [x] `CognitiveEpisode` data model created: task_type, strategy, thought_trace, outcome_score, timestamp, context
- [x] Thought Galaxy created as a dedicated galaxy in the galaxy system (`thought_traces`)
- [x] Scoring function: auto-scores episodes based on measurable outcomes (compile success, VC met, error rate)
- [x] Manual scoring override: user can rate a thought trace as breakthrough (+1.0) or failure (-1.0)
- [x] Pre-task recall: before starting a task, query Galaxy for best strategy used on similar tasks
- [x] Strategy library: top-10 highest-scored strategies extractable as "Golden Rules"
- [x] Anti-pattern library: bottom-10 lowest-scored strategies flagged as "Known Pitfalls"
- [x] Dream cycle integration: nightly consolidation runs clustering and synthesis over thought episodes
- [x] Pattern evolution: track how strategy effectiveness changes over time (improving? degrading?)
- [x] Visualization: `wm thought status` shows top strategies, worst anti-patterns, trend chart
- [x] Report: `reports/thought_galaxy.md` with initial cognitive patterns discovered

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Data model | `whitemagic/core/memory/cognitive_episode.py` | New module |
| Galaxy setup | `whitemagic/core/memory/thought_galaxy.py` | New module |
| Scoring engine | `whitemagic/core/intelligence/thought_scorer.py` | New module |
| Dream integration | `whitemagic/core/dreaming/dream_cycle.py` | Enhance existing |
| CLI | `whitemagic/cli/cli_app.py` | `wm thought status/recall/score` |

## Strategy

1. Define `CognitiveEpisode` dataclass with all required fields
2. Create thought_traces galaxy using existing galaxy infrastructure
3. Build auto-scoring based on measurable outcomes (compile, tests, VCs)
4. Implement pre-task recall: "How did I solve similar problems before?"
5. Wire into dream cycle's consolidation phase for nightly pattern extraction
6. Build "Golden Rules" and "Known Pitfalls" extraction from scored episodes
7. Add CLI commands for inspection and manual scoring

## Verification

- Store 50 real cognitive episodes from a work session
- Query: "best strategy for debugging async code" returns relevant high-scored episodes
- Dream cycle produces at least 3 consolidated "Golden Rules" from episode clusters
- Anti-pattern detection: identify at least 2 recurring failure modes
