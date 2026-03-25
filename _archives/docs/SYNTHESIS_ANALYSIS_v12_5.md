# Synthesis & Consolidation Analysis — v12.5

Generated: 2026-02-08

## Current State
- **207 MCP tools** across 19 categories + 28 Ganas
- **653 active source files** (154 dead modules archived)
- **947 tests** passing

## The 28 Mansions Framework

Every tool should map to exactly one of the 28 Lunar Mansions (Ganas).
The Ganas are the organizational spine — expansion happens *within* mansions, not by creating new categories.

### Mansion Mapping (current → target)

| # | Mansion | Domain | Current Tools | Proposed Fusions |
|---|---------|--------|:---:|---|
| 1 | Horn | Session & Init | 4 | session_bootstrap absorbs create/resume/checkpoint |
| 2 | Neck | Core Memory | 8 | read_memory absorbs batch_read/fast_read; CRUD stays |
| 3 | Root | Health & Foundation | 5 | ship.check absorbs health_report, state.* |
| 4 | Room | Locks & Privacy | 6 | OK — clean domain |
| 5 | Heart | Context & Pulse | 8 | harmony_vector absorbs homeostasis.*, yin_yang |
| 6 | Tail | Acceleration | 10 | Fold rust_*/simd.*/edge_*/bitnet_* into 2-3 tools |
| 7 | Winnowing Basket | Wisdom & Grimoire | 5 | grimoire_suggest absorbs recommend/walkthrough |
| 8 | Ghost | Introspection | 6+30 unmapped | gnosis is the mega-tool; fold all .status into it |
| 9 | Willow | Resilience | 1 | Absorb circuit breaker + rate_limiter stats |
| 10 | Star | Governance | 12 | dharma_rules absorbs set_profile/guidance/reload |
| 11 | Extended Net | Pattern & KG | 8 | kg.query absorbs kg.status/top; learning.* → 1 tool |
| 12 | Wings | Export & Deploy | 3 | OK |
| 13 | Chariot | Archaeology | 7 | archaeology single tool with action param |
| 14 | Abundance | Regeneration | 5 | memory.lifecycle single tool with action param |
| 15 | Straddling Legs | Balance & Gardens | 0→3 | Absorb garden_activate/health/status |
| 16 | Mound | Accumulation & Scratchpad | 0→3 | Absorb scratchpad_create/update/finalize |
| 17 | Stomach | Metrics & Telemetry | 5 | otel single tool; track_metric + get_metrics_summary → 1 |
| 18 | Hairy Head | Debug & Anomaly | 3 | anomaly single tool with action param |
| 19 | Net | Vector & Semantic Search | 2 | Absorb vector.status |
| 20 | Turtle Beak | Protection & Immune | 0→? | Absorb sandbox tools from Room? Or self-model alerts? |
| 21 | Three Stars | Judgment & Synthesis | 9 | ensemble single tool; kaizen single tool |
| 22 | Dipper | Strategy & Planning | 7 | tool.graph → 1 tool; pipeline → 1 tool; maturity → 1 |
| 23 | Ox | Endurance & Watchdog | 1 | Absorb swarm.* (9 tools) — they're persistent workers |
| 24 | Girl | Nurture & Onboarding | 4 | starter_packs → 1 tool with action param |
| 25 | Void | Dreaming & Emptiness | 4 | dream single tool with action param |
| 26 | Roof | Shelter & Holographic | 1 | Absorb view_hologram, galactic.dashboard |
| 27 | Encampment | Transition & Handoff | 3 | session.handoff → 1 tool with action param |
| 28 | Wall | Boundaries & Comms | 22 | Split: agent.* → 1, broker.* → 1, mesh.* → 1, task.* → 1, vote.* → 1, sangha.* → 1 |

### Unmapped Tools → Mansion Assignment

| Tool | → Mansion | Rationale |
|------|-----------|-----------|
| garden_activate/health/status | Straddling Legs | Balance between gardens |
| scratchpad_create/update/finalize | Mound | Accumulation of working notes |
| selfmodel.forecast/alerts | Ghost | Self-introspection |
| drive.snapshot/event | Heart | Emotional pulse/drives |
| galactic.dashboard | Roof | Holographic overview |
| ollama.chat/generate/models | Tail | Inference acceleration |
| prompt.list/reload/render | Winnowing Basket | Wisdom template management |
| execute_cascade/list_cascade_patterns | Dipper | Strategic orchestration |
| cluster_stats | Abundance | Memory cluster regeneration |
| swarm.* (6 tools) | Ox | Endurance — persistent swarm workers |
| vector.status | Net | Search infrastructure status |
| karmic_trace | Star | Governance audit |
| get_ethical_score | Star | Governance |

## Consolidation Targets (207 → ~85 tools)

### Tier 1: Multi-action fusion (biggest wins)
These tools share a handler pattern where 3-7 separate tools become 1 tool with an `action` parameter:

1. **`archaeology`** (7→1): action=find_changed|find_unread|mark_read|mark_written|recent_reads|stats|have_read
2. **`dream`** (4→1): action=start|stop|status|now
3. **`session.handoff`** (3→1): action=transfer|accept|list
4. **`starter_packs`** (3→1): action=list|get|suggest
5. **`memory.lifecycle`** (5→1): action=sweep|stats|consolidate|consolidation_stats|retention_sweep
6. **`anomaly`** (3→1): action=check|history|status
7. **`pipeline`** (3→1): action=create|status|list
8. **`scratchpad`** (3→1): action=create|update|finalize
9. **`sangha_lock`** (3→1): action=acquire|release|list
10. **`ensemble`** (3→1): action=query|status|history
11. **`otel`** (3→1): action=metrics|spans|status

### Tier 2: Status tool absorption into gnosis
These `.status` tools return read-only snapshots and should become subsystem portals of `gnosis`:

`anomaly.status`, `bitnet_status`, `context.status`, `dream_status`, `kg.status`, `mesh.status`, 
`otel.status`, `sandbox.status`, `simd.status`, `swarm.status`, `vector.status`, `rust_status`

→ `gnosis(subsystem="anomaly")` etc. (12 tools absorbed)

### Tier 3: Semantic deduplication
- `tool.graph` + `tool.graph_full` → `tool.graph(detail="full"|"summary")`
- `maturity.assess` (registered twice!) → deduplicate
- `homeostasis.check` + `homeostasis.status` → `homeostasis(action="check"|"status")`
- `get_dharma_guidance` + `dharma_rules` → `dharma(action="guidance"|"rules"|"reload"|"set_profile")`
- `harmony_vector` + `get_yin_yang_balance` + `record_yin_yang_activity` → `harmony(action="snapshot"|"yin_yang"|"record")`
- `get_metrics_summary` + `track_metric` → `metrics(action="summary"|"track")`
- `read_memory` + `fast_read_memory` + `batch_read_memories` → `read_memory(batch=[...]|id=...)`

### Projected Result
| Tier | Tools Removed | Mechanism |
|------|:---:|---|
| Tier 1: Multi-action fusion | ~44 | 11 groups × ~3-4 tools each → 11 |
| Tier 2: Status absorption | ~12 | Folded into gnosis subsystem param |
| Tier 3: Semantic dedup | ~15 | Merged into parameterized versions |
| **Total reduction** | **~71** | **207 → ~136** |

Further passes could get to ~85 by folding the Wall mega-mansion (22 tools) into 
`agent()`, `broker()`, `mesh()`, `task()`, `vote()`, `sangha()` — 6 multi-action tools 
replacing 22 individual ones.

## Cross-System Synthesis Gaps

### Already Closed (v11-v12.3)
- A1: Salience Arbiter ↔ Homeostatic Loop (bidirectional awareness)
- A2: Dependency Graph ↔ Pipeline Engine (ordering validation)
- A3: Consolidation ↔ Bicameral Reasoner (creative clustering)
- A4: Galactic Map → Harmony Vector Energy (zone-weighted vitality)
- A5: Garden Resonance Matrix (cross_pollination.py — event-driven inter-garden wiring)

### Potential New Gaps
- **G1: Dream Cycle ↔ Association Miner** — Dream SERENDIPITY phase does ad-hoc neighbor search. Should use the full AssociationMiner for deeper cross-temporal discovery.
- **G2: Rust Accelerators ↔ Dream Cycle** — Galactic scoring in dream DECAY phase should use Rust batch scorer (already wired for galactic_map.full_sweep but not for dream).
- **G3: Emotion/Drive Core ↔ Grimoire Selection** — Grimoire recommendations don't consider current emotional state/drives. A curiosity-driven agent should get different spell suggestions than a cautious one.
- **G4: Self-Model Forecasting ↔ Circuit Breaker** — Predictive self-model could proactively open circuit breakers before metrics actually breach thresholds.
- **G5: Knowledge Graph ↔ Memory Consolidation** — Consolidation creates strategy memories but doesn't create KG relations between the source memories and the synthesized strategy.

## Resonance Matrix (System ↔ System Connections)

```
                    Harmony  Dharma  Memory  Dream  Immune  Salience  KG  Grimoire  Drives  SelfModel
Harmony Vector        ━       ✓       ✓       .       ✓       ✓      .      .        .        .
Dharma Rules          ✓       ━       .       .       .       .      .      .        .        .
Memory System         ✓       .       ━       ✓       .       .      ✓      .        .        .
Dream Cycle           .       .       ✓       ━       .       .      .      ✓        .        .
Immune/CircuitBreak   ✓       .       .       .       ━       .      .      .        .        .
Salience Arbiter      ✓       .       .       .       .       ━      .      .        .        .
Knowledge Graph       .       .       ✓       .       .       .      ━      .        .        .
Grimoire              .       .       .       ✓       .       .      .      ━        .        .
Emotion/Drives        .       .       .       .       .       .      .      .        ━        .
Self-Model            .       .       .       .       .       .      .      .        .        ━

✓ = connected    . = gap    ━ = self
```

**Key observation:** Emotion/Drive Core and Self-Model are islands — connected to nothing except gnosis introspection. These are the biggest synthesis gaps remaining.
