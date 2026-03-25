---
name: "Wu Xing Waking Scheduler — 5-Phase State Machine"
codename: G007
army: alpha
type: fix_and_verify
priority: 2
clone_count: 20000
strategies:
  - analytical
  - synthesis
category: synthesis
phase: infrastructure
source: "Gemini transcript — Wu Xing state machine for waking hours + Zodiacal project lifecycle"
column_size: 10000
---

# Wu Xing Waking Scheduler — 5-Phase State Machine

## Objective

Transform the existing Wu Xing balance check (currently just a metric) into a real
5-phase state machine that governs the AI's waking work cycle. Each phase (Wood,
Fire, Earth, Metal, Water) maps to a distinct operational mode with specific allowed
actions, preventing burnout (too much Fire) and stagnation (too much Earth).

Additionally, overlay the Zodiacal Round as a project lifecycle manager that knows
"what house the project is in" and adjusts strategy accordingly.

**Core insight**: The AI shouldn't just grind — it should flow through natural phases
of expansion (Yang/Wood/Fire) and contraction (Yin/Metal/Water), with Earth as the
stabilizing integration point. This prevents the common failure of endless generation
without reflection.

## Victory Conditions

### Wu Xing State Machine
- [x] `WuXingScheduler` class created with 5 states and transition rules
- [x] Wood (木): Generative/expansive — scaffolding, brainstorming, new file creation
- [x] Fire (火): Parallel/high-energy — async execution, batch processing, max concurrency
- [x] Earth (土): Stabilizing/integration — compilation, testing, reality checks
- [x] Metal (金): Refining/cutting — optimization, linting, dead code removal, search/replace
- [x] Water (水): Reflecting/storing — thought galaxy upload, session summary, pattern extraction
- [x] Automatic phase transitions based on project state (high errors → Earth, bloat → Metal, stuck → Wood)
- [x] Phase enforcement: system warns or blocks inappropriate actions for current phase
- [x] Integration with existing `wu_xing_balance` metric — scheduler drives the balance, not just measures it

### Zodiacal Project Lifecycle
- [x] Project phase detection: which "house" is the current project in? (Aries-Gemini=init, Cancer-Virgo=build, Libra-Sag=interface, Cap-Pisces=complete)
- [x] Phase-appropriate strategy injection: "Current phase: Scorpio — focus on hidden dependencies, not new features"
- [x] Integration with existing `zodiac_round_cycle.py`

### Dashboard & Controls
- [x] `wm phase status` shows current Wu Xing phase, zodiacal house, recommended actions
- [x] `wm phase set <element>` allows manual phase override
- [x] Report: `reports/wu_xing_scheduler.md` with phase transition logic and integration plan

## Targets

| Component | Location | Type |
|-----------|----------|------|
| Wu Xing scheduler | `whitemagic/core/wuxing_scheduler.py` | New module |
| Phase enforcer | `whitemagic/autonomous/phase_enforcer.py` | New module |
| Zodiacal overlay | `whitemagic/zodiac/zodiac_round_cycle.py` | Enhance existing |
| Existing balance | `whitemagic/` (wu_xing_balance tool) | Wire into scheduler |
| CLI | `whitemagic/cli/cli_app.py` | `wm phase status/set` |
| Supervisor integration | `whitemagic/autonomous/supervisor.py` (G004) | Cross-campaign |

## Strategy

1. Design state machine with 5 states + transition rules + triggers
2. Implement `WuXingScheduler` with state tracking and automatic transitions
3. Wire project state signals (error rate, file count, test results) into transition triggers
4. Build phase-appropriate action recommendations
5. Integrate with existing zodiacal round cycle for project lifecycle overlay
6. Add CLI commands for visibility and manual override
7. Wire into auto-prompting supervisor (G004) for phase-aware SOPs

## Verification

- Scheduler correctly transitions Wood→Fire→Earth→Metal→Water in a full work cycle
- High error rate automatically triggers Earth (stabilize) phase
- Zodiacal phase detection correctly identifies project lifecycle stage
- `wm phase status` shows coherent current state
