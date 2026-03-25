# Campaign V020-001: Elixir Event Bus Promotion

**Status**: ACTIVE — Elixir promotion to primary event bus  
**Priority**: P1 — Critical path for v20 COLLECTIVE maturity stage  
**Scope**: `elixir/`, `whitemagic/core/gan_ying/`  
**Lead**: Polyglot Systems Team  
**Metric-Driven**: All decisions backed by benchmark data

---

## Victory Conditions

| VC | Description | Metric Target | Status |
|----|-------------|---------------|--------|
| 1 | Elixir event bus activated as primary for FAST lane | >10K events/sec, <1ms latency | ⬜ |
| 2 | Elixir primary for MEDIUM lane | >5K events/sec, <50ms latency | ⬜ |
| 3 | Elixir primary for SLOW lane | >1K events/sec, <500ms latency | ⬜ |
| 4 | Python Gan Ying demoted to fallback layer | <5% Python event handling | ⬜ |
| 5 | Redis bridge operational | Zero event loss during bridge | ⬜ |
| 6 | Mesh cross-node sync | Events propagate to peer nodes | ⬜ |
| 7 | Metrics dashboard live | Real-time latency/throughput visibility | ⬜ |
| 8 | Documentation updated | Migration guide for contributors | ⬜ |
| 9 | Regression tests pass | All existing Gan Ying tests green | ⬜ |

**Completion Target**: 9/9 VCs for full promotion

---

## Current State Analysis

### Python Gan Ying (Current Primary)
- **Event Bus**: `whitemagic/core/gan_ying/event_bus.py`
- **Throughput**: ~2K events/sec (single-threaded)
- **Latency**: 5-20ms average
- **Lanes**: FAST/MEDIUM/SLOW implemented as priority queues
- **Issues**: GIL contention, no native fault tolerance, blocking I/O

### Elixir Event Bus (Standby)
- **Location**: `elixir/lib/whitemagic_core/gan_ying/event_bus.ex`
- **Status**: Compiled, tested, ready for activation
- **Capabilities**:
  - Actor-model concurrency (millions of lightweight processes)
  - `:rest_for_one` supervision (auto-restart on crash)
  - 3-lane temporal routing with backpressure
  - Hot code reloading (zero-downtime updates)
- **Current Usage**: Python calls via Erlang Port (experimental)

### Benchmark Baseline (Required)

| Metric | Python Current | Elixir Target | Measurement Method |
|--------|---------------|---------------|-------------------|
| FAST lane throughput | 2K evt/s | 10K evt/s | `scripts/benchmark_event_bus.py` |
| FAST lane latency (p99) | 20ms | 1ms | Distributed tracing |
| MEDIUM lane throughput | 1.5K evt/s | 5K evt/s | Load testing |
| SLOW lane throughput | 500 evt/s | 1K evt/s | Batch event injection |
| Memory under load | 150MB | <100MB | `memory_profiler` |
| Crash recovery time | Manual | <100ms | Chaos testing |
| Backpressure handling | Drops events | Smooth degradation | Load spike test |

---

## Promotion Strategy

### Phase 1: Baseline & Shadow Mode (Week 1-2)

1. **Benchmark Current State**
   - Run full Gan Ying benchmark suite
   - Establish Python baseline metrics
   - Document current event patterns/volumes

2. **Elixir Shadow Deployment**
   - Deploy Elixir event bus alongside Python
   - Mirror all events to both systems
   - Compare outputs (should be identical)
   - Metrics: latency, throughput, memory

3. **Validation**
   - Zero event loss in shadow mode
   - Identical event ordering
   - Performance headroom confirmed

### Phase 2: FAST Lane Cutover (Week 3-4)

1. **FAST Lane Migration**
   - Events with `priority: :fast` route to Elixir
   - Python handles MEDIUM/SLOW as fallback
   - Monitor latency/throughput in production

2. **Rollback Plan**
   - Config flag: `gan_ying_backend: :elixir | :python`
   - Instant rollback if issues detected
   - Alert on latency >5ms p99

3. **Success Criteria**
   - >90% FAST events via Elixir
   - Latency <1ms p99
   - No event loss

### Phase 3: MEDIUM Lane Cutover (Week 5-6)

1. **MEDIUM Lane Migration**
   - Add MEDIUM lane to Elixir primary
   - Python handles SLOW only

2. **Tuning**
   - Adjust lane thresholds based on metrics
   - Optimize process pool sizes
   - Tune backpressure thresholds

### Phase 4: SLOW Lane & Cleanup (Week 7-8)

1. **Full Migration**
   - All lanes primary on Elixir
   - Python Gan Ying becomes compatibility layer
   - Legacy code paths preserved

2. **Documentation**
   - Migration guide for contributors
   - Architecture decision record (ADR)
   - Runbook for Elixir operations

---

## Technical Implementation

### Elixir Modules to Expand

```elixir
# Current: ~1,400 LOC
# Target: 2,500 LOC (+1,100)

elixir/lib/whitemagic_core/gan_ying/
├── event_bus.ex           # +300 LOC: Full 3-lane routing
├── event_router.ex        # NEW: Dynamic routing rules
├── lane_fast.ex           # NEW: 0-1s event handlers
├── lane_medium.ex         # NEW: 1-60s event handlers
├── lane_slow.ex           # NEW: 60s+ event handlers
├── backpressure.ex        # NEW: Flow control
├── metrics.ex             # NEW: Prometheus export
├── redis_bridge.ex        # +200 LOC: Python integration
├── mesh_sync.ex           # NEW: Cross-node propagation
├── supervisor.ex          # +100 LOC: Enhanced supervision
└── dream_scheduler.ex     # Existing, keep as-is
```

### Python Bridge Updates

```python
# whitemagic/core/gan_ying/
├── event_bus.py           # -500 LOC: Deprecate primary logic
├── elixir_bridge.py       # NEW: Erlang Port wrapper
├── fallback_bus.py        # NEW: Python compatibility layer
└── gan_ying.py            # Update to route via Elixir
```

### Integration Points

1. **Redis Bridge**
   - Elixir publishes to Redis channels
   - Python subscribes for downstream processing
   - Zero event loss guaranteed

2. **Mesh Sync**
   - Elixir events propagate via Go mesh
   - Cross-node event consistency
   - Vector clock ordering

3. **Metrics Export**
   - Prometheus endpoint: `:9090/metrics`
   - Grafana dashboard: "Elixir Event Bus"
   - Alerts: latency >5ms, throughput <target

---

## Metrics & Success Tracking

### Key Metrics

| Metric | Target | Alert Threshold | Dashboard |
|--------|--------|-----------------|-----------|
| FAST throughput | >10K evt/s | <8K evt/s | Grafana |
| FAST p99 latency | <1ms | >2ms | Grafana |
| MEDIUM throughput | >5K evt/s | <4K evt/s | Grafana |
| SLOW throughput | >1K evt/s | <800 evt/s | Grafana |
| Memory usage | <100MB | >150MB | Grafana |
| Crash recovery | <100ms | >500ms | PagerDuty |
| Event loss rate | 0% | >0.001% | PagerDuty |
| Backpressure events | <1% | >5% | Grafana |

### Measurement Tools

```bash
# Event bus benchmark
python scripts/benchmark_gan_ying.py --backend=elixir --duration=60

# Load testing
python scripts/load_test_events.py --rate=10000 --duration=300

# Chaos testing
python scripts/chaos_event_bus.py --crash-interval=30

# Metrics export
curl http://localhost:9090/metrics | grep gan_ying
```

---

## Risk Mitigation

| Risk | Likelihood | Impact | Mitigation |
|------|------------|--------|------------|
| Event loss during cutover | Low | Critical | Shadow mode, dual-write, rollback plan |
| Latency regression | Medium | High | Gradual cutover, instant rollback config |
| Memory leak | Low | Medium | Supervision, process limits, monitoring |
| FFI stability | Medium | Medium | Erlang Port isolation, Python fallback |
| Contributor confusion | Medium | Low | Documentation, code comments, runbook |

### Rollback Plan

1. **Immediate**: Config flag `gan_ying_backend: :python`
2. **Revert**: Git revert of Elixir promotion commit
3. **Data recovery**: Replay from Redis event log

---

## Dependencies

- **Blocked by**: None (Elixir already compiled)
- **Blocks**: V020_002 (Polyglot Expansion), mesh cross-node sync
- **Requires**: Go mesh for cross-node propagation

---

## Appendix: Event Types by Lane

### FAST Lane (0-1s priority)
- Tool execution start/stop
- Memory store operations
- User input handling
- Real-time queries

### MEDIUM Lane (1-60s priority)
- Association mining
- Constellation updates
- Graph topology changes
- Salience recalculation

### SLOW Lane (60s+ priority)
- Dream cycle phases
- Decay operations
- Batch embeddings
- Analytics exports

---

**Decision**: Elixir promotion approved per user directive — "extensive stats and metrics are important" — all progress tracked via measurable benchmarks.
