---
name: Unified Clone Army Commander
codename: PSR-021
army: grand
type: fix_and_verify
priority: P1
clone_count: 200000
strategies: [synthesis, polyglot, architecture]
category: architecture
phase: immediate
source: consensus_council_100m
column_size: 4
---

## Objective

Synthesize all 12 clone army types into a single `UnifiedCommander` Rust struct with:
- ZodiacRouter: routes tasks to optimal army based on keyword + zodiac alignment
- UCB1Selector: Monte Carlo bandit learns which strategies work best per task type
- CloneMemory: `Arc<RwLock<CloneMemory>>` persists learned state across deployments
- PyWM2Army: pyo3 bridge exposes everything to Python orchestration

**Current state**: 12 separate army types across 5 languages with no unified interface.
**Target state**: `wm2_clone_army.rs` UnifiedCommander as single entry point for all deployments.

The 100M Consensus Council voted this **#2 highest-ROI action** (clone fragmentation = #1 effectiveness blocker).

## Victory Conditions

- [ ] `wm2_clone_army.rs` compiles as part of whitemagic-rust library
- [ ] `UnifiedCommander::deploy()` routes correctly for all 12 army types
- [ ] `ZodiacRouter` selects correct army for keyword-based task descriptions
- [ ] `UCB1Selector` learns from deployment history (avg_score improves after 10+ deployments)
- [ ] `CloneMemory` persists across multiple `deploy()` calls within a session
- [ ] `PyWM2Army` pyo3 class exposed in `whitemagic_rs` Python module
- [ ] Python can call `army = PyWM2Army(); army.deploy("scan codebase", clone_count=50000)`
- [ ] Deployment report includes: army_used, throughput_per_sec, top_findings
- [ ] Elixir `CouncilAggregator` wired to receive results from Rust commander
- [ ] Koka `council_deliberation.kk` effect handlers compile and run

## Targets

| Component | File | Status |
|-----------|------|--------|
| UnifiedCommander | whitemagic-rust/src/wm2_clone_army.rs | Created ✅ |
| ZodiacRouter | wm2_clone_army.rs::route_task() | Created ✅ |
| UCB1Selector | wm2_clone_army.rs::UCB1Stats | Created ✅ |
| CloneMemory | wm2_clone_army.rs::CloneMemory | Created ✅ |
| PyWM2Army | wm2_clone_army.rs::PyWM2Army | Created ✅ |
| Koka effects | koka-clones/council_deliberation.kk | Created ✅ |
| Elixir aggregator | elixir/lib/council_aggregator.ex | Created ✅ |
| Python bridge | maturin develop → whitemagic_rs.PyWM2Army | Pending |

## Strategy

1. Add `PyWM2Army` to `lib.rs` pymodule export
2. Run `maturin develop --release` to build Python bindings
3. Test from Python: `from whitemagic_rs import PyWM2Army; army = PyWM2Army()`
4. Wire `deploy_grand_army.py` to use `PyWM2Army` for all deployments
5. Run 10 deployments, verify UCB1 learning (avg_score should improve)
6. Compile Koka deliberation layer: `koka koka-clones/council_deliberation.kk`
7. Wire Elixir aggregator into mix project

## Verification

```bash
# Build Python bindings
cd whitemagic-rust && maturin develop --release

# Test from Python
python3 -c "
from whitemagic_rs import PyWM2Army
army = PyWM2Army()
print(army.route('scan codebase for optimization'))
result = army.deploy('parallel async migration', clone_count=10000)
import json; r = json.loads(result)
print(f'Army: {r[\"army_used\"]}, Score: {r[\"score\"]:.2f}, {r[\"throughput_per_sec\"]:.0f}/sec')
"
```
