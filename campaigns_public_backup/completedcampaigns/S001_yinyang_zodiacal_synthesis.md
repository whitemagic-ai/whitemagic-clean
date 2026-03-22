---
name: "Yin-Yang & Zodiacal Round Synthesis"
codename: S001
army: beta
type: discovery
priority: 2
clone_count: 50000
strategies:
  - discovery
  - synthesis
  - integration
category: synthesis
phase: infrastructure
source: "Yin-Yang discovery campaign — fuse existing scattered systems into unified cycle engine"
column_size: 10000
---

## Objective

Discover, audit, and synthesize the 10+ existing yin-yang, wu xing, and zodiacal round systems
scattered across the WhiteMagic codebase into a unified Cycle Engine. The systems currently
operate independently — the YinYangBalanceTracker doesn't talk to the ZodiacalRound, the
WuXingSystem doesn't feed the CascadeExecutor's yin-yang pacing, and the ContextSynthesizer
gathers but doesn't drive action. Fuse them.

### Existing Systems Inventory
| System | File | Integration |
|--------|------|-------------|
| YinYangBalanceTracker | harmony/yin_yang_tracker.py | Gan Ying bus, file persistence |
| ZodiacalRound | zodiac/zodiac_round_cycle.py | 12-phase async cycle, Gan Ying events |
| WuXingSystem | core/intelligence/wisdom/wu_xing.py | Task-element mapping, Gan Ying bus |
| WuXingEngine | wu_xing/__init__.py | Generating/controlling cycles |
| ContextSynthesizer | cascade/context_synthesizer.py | Gathers all states into UnifiedContext |
| CascadeExecutor | cascade/executor.py | Yin-yang balance check per batch |
| FoolGuard | core/intelligence/agentic/fool_guard.py | Ralph Wiggum dare-to-die |
| WarRoom | agents/war_room.py | Tactical framework with stratagems |
| ImperialDoctrine | agents/doctrine.py | 36 Stratagems, force composition |
| ProgressTracker | agents/progress_tracker.py | Granular 00.00% progress bars |

## Victory Conditions
- [ ] All 10 systems audited: each has documented inputs, outputs, and integration points
- [ ] ContextSynthesizer drives ZodiacalRound phase transitions (not just passive gathering)
- [ ] WuXing element maps to campaign phase timing (Wood=recon, Fire=action, Metal=verify)
- [ ] YinYangBalanceTracker integrated into deploy_grand_army.py yin-yang cycles
- [ ] ZodiacalRound phases trigger appropriate campaign actions (Scorpio=emergence, Libra=balance)
- [ ] Gan Ying event bus carries cross-system resonance (wu_xing→zodiac→yin_yang chain)
- [ ] Unified CycleEngine class created that orchestrates all systems in one loop
- [ ] CycleEngine tested: runs 3 full zodiacal rounds with metrics tracking
- [ ] Report: reports/zodiacal_synthesis_audit.md with integration map and gaps

## Strategy
1. Audit each system's public API, events emitted, and events consumed
2. Map cross-system data flows (what does zodiac need from wu_xing?)
3. Create `whitemagic/cycle_engine.py` that imports and orchestrates all systems
4. Wire CycleEngine into deploy_grand_army.py as alternative to raw yin-yang
5. Run 3 full zodiacal cycles through a campaign and measure improvement

## Verification
```bash
# All systems importable
scripts/wm -c "from whitemagic.harmony.yin_yang_tracker import YinYangBalanceTracker; print('OK')"
scripts/wm -c "from whitemagic.zodiac.zodiac_round_cycle import ZodiacalRound; print('OK')"
scripts/wm -c "from whitemagic.cascade.context_synthesizer import ContextSynthesizer; print('OK')"
```
