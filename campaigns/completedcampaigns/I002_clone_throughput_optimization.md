---
name: Clone Throughput Optimization
codename: I002
army: gamma
type: stress_test
priority: 4
clone_count: 500000
strategies: [analytical, direct]
category: optimization
phase: intelligence
source: "Operation Iron Lotus AAR — throughput degrades from 934K/sec at 50K to 157K/sec at 500K"
column_size: 50000
---

# Clone Throughput Optimization

## Objective
Optimize Tokio clone army throughput to maintain >500K clones/sec at sustained
high deployment. Iron Lotus stress test revealed a significant degradation curve:
- 10K: 810K/sec (warm)
- 50K: 934K/sec (peak — the sweet spot)
- 100K: 900K/sec (slight drop)
- 250K: 822K/sec (noticeable drop)
- 500K: 157-825K/sec (highly variable, sometimes severe degradation)

The Sun Bin strategy (multiple columns of 50K) avoids this degradation.
But we should also optimize the underlying Tokio runtime for sustained load.

Additionally, test the Sun Bin multi-column deployment strategy:
5 generals × 50K each = 250K total force, each column independent.
Compare throughput vs single 250K deployment.

## Victory Conditions
- [ ] Root cause of >100K degradation identified (memory pressure? scheduler?)
- [ ] Tokio clone runtime optimized — sustained 500K+ clones/sec at 250K deployment
- [ ] Sun Bin multi-column benchmark: 5×50K vs 1×250K throughput comparison
- [ ] Multi-column proves superior (predicted: 5×934K/sec aggregate vs 822K/sec single)
- [ ] Optimal column size empirically determined (expected: 50K based on historical data)
- [ ] Results documented with benchmark data in reports/clone_optimization.md
- [ ] Recommendations integrated into deploy_grand_army.py default column_size

## Targets
| File | Line | Type |
|------|------|------|
| whitemagic-rust/src/tokio_clones.rs | * | Tokio runtime tuning |
| whitemagic/optimization/rust_accelerators.py | * | Python bridge |
| scripts/deploy_grand_army.py | * | multi-column defaults |

## Strategy
1. Profile Tokio clone deployment at 10K, 50K, 100K, 250K, 500K
2. Instrument Rust code to measure: task scheduling time, memory allocation, GC pressure
3. Test with different Tokio runtime configurations (work-stealing vs current-thread)
4. Implement Sun Bin multi-column: ThreadPoolExecutor with N columns
5. Benchmark multi-column vs single at equivalent total force
6. Find optimal column size by testing 25K, 50K, 75K, 100K columns
7. Optimize based on findings (batch size, memory pooling, async scheduling)
8. Re-benchmark to confirm improvements
9. Update deploy script defaults with empirically optimal parameters

## Verification
Benchmark suite showing sustained >500K clones/sec at 250K+ total deployment.
Multi-column vs single comparison data with clear recommendation.
