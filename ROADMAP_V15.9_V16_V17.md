# WhiteMagic Roadmap: v15.9 → v16 → v17
## Strategic Planning Document — March 2026

---

## Current State (v18.1.0)

### Completed Milestones
- **S020 Absolute Self-Knowledge**: 35/35 VCs ✅
- **V018 LoCoMo Benchmark**: 78.3% accuracy (beats Letta 74%, Mem0 68.5%, OpenAI 63.8%)
- **G001-G008 Gemini Campaigns**: All completed
- **v15.8.0 Ship-blocking**: networkx, harmony cold-start, narrative noise filter ✅
- **DB Recovery**: Restored from backup after corruption

### Current Metrics
| Metric | Value | Target |
|--------|-------|--------|
| Python LOC | ~142K | <130K |
| Polyglot LOC | ~45K | >100K |
| Embedding coverage | 80% | 100% |
| Typed associations | 91.6% | 95% |
| MCP tools | 374 | 400+ |
| Test pass rate | 99%+ | 100% |

---

## v15.9 — Quality & Stability (Q2 2026)

### Theme: "Production Hardening"

### Phase 1: Performance Polish (4 weeks)
- [ ] **P1-1**: Cold start optimization — target <1s for MCP init
- [ ] **P1-2**: Memory query latency — p95 <50ms for all search types
- [ ] **P1-3**: Embedding batch throughput — 1000+ embeddings/sec
- [ ] **P1-4**: Graph walker optimization — sub-second for 100-hop traversals

### Phase 2: Error Handling (3 weeks)
- [ ] **P2-1**: Graceful degradation for all optional dependencies
- [ ] **P2-2**: Structured error codes for MCP responses
- [ ] **P2-3**: Automatic retry with exponential backoff for transient failures
- [ ] **P2-4**: Circuit breaker pattern for external API calls

### Phase 3: Observability (3 weeks)
- [ ] **P3-1**: OpenTelemetry tracing integration
- [ ] **P3-2**: Prometheus metrics export
- [ ] **P3-3**: Structured logging with configurable verbosity
- [ ] **P3-4**: Health check endpoints for all subsystems

### Phase 4: Documentation (2 weeks)
- [ ] **P4-1**: API documentation auto-generation from docstrings
- [ ] **P4-2**: Architecture decision records (ADRs) for major choices
- [ ] **P4-3**: Runbook for common operational tasks
- [ ] **P4-4**: Migration guide for v15.x → v16

---

## v16.0 — Architecture Evolution (Q3 2026)

### Theme: "Intelligent Infrastructure"

### A. Embedding Pipeline 2.0
**Problem**: Batch embedding creates backlog; 20% of memories still unembedded.

**Solution**: Incremental embedding on every `store()` call.
```
store() → check embedding cache → if missing, queue for embedding
         → background worker processes queue → embedding saved within 5s
```

**VCs**:
- [ ] **A-1**: Background embedding worker with priority queue
- [ ] **A-2**: Embedding cache invalidation on content change
- [ ] **A-3**: Multi-model embedding support (BGE, OpenAI, local)
- [ ] **A-4**: GPU acceleration path for batch operations

### B. Knowledge Graph 2.0
**Problem**: Only 13 entities in KG; entity extraction is minimal.

**Solution**: Lightweight NER without spaCy dependency.
```
store() → regex entity extraction → entity linking → KG update
         → relation extraction from content patterns
```

**VCs**:
- [ ] **B-1**: Regex-based NER for people, tools, versions, files, dates
- [ ] **B-2**: Entity linking to existing KG nodes
- [ ] **B-3**: Relation extraction (USES, IMPLEMENTS, CONTAINS, CAUSES)
- [ ] **B-4**: KG visualization in dashboard

### C. Novelty Detection 2.0
**Problem**: Cold start always returns 1.0 (no discrimination).

**Solution**: Baseline corpus calibration on first dream cycle.
```
first dream → build TF-IDF from corpus → calibrate threshold
            → store baseline for future sessions
```

**VCs**:
- [ ] **C-1**: TF-IDF baseline builder
- [ ] **C-2**: Threshold auto-calibration
- [ ] **C-3**: Novelty score persistence across sessions
- [ ] **C-4**: Novelty trend tracking in harmony vector

### D. Graph Engine 2.0
**Problem**: Full graph rebuild on every query (slow for large graphs).

**Solution**: Incremental graph updates with persistent structure.
```
store() → update graph delta → persist edge changes
delete() → remove from graph → persist edge removal
query() → read persistent graph → apply recent deltas
```

**VCs**:
- [ ] **D-1**: Persistent graph storage in SQLite
- [ ] **D-2**: Delta application on graph mutations
- [ ] **D-3**: Periodic graph compaction
- [ ] **D-4**: Sub-second incremental updates

### E. Dream Scheduling
**Problem**: Dream cycle must be manually triggered.

**Solution**: Cron-style scheduling with MCP tools.
```
dream.schedule("0 2 * * *") → schedules 2am dream cycle
dream.status() → shows next run, last run, duration
```

**VCs**:
- [ ] **E-1**: `dream.schedule` MCP tool
- [ ] **E-2**: `dream.status` MCP tool
- [ ] **E-3**: Persistent dream journal
- [ ] **E-4**: Dream phase health metrics

---

## v17.0 — Polyglot Supremacy (Q4 2026)

### Theme: "Multi-Language Excellence"

### S026 Campaign Execution

**Objective**: Python < 40%, 49,500 LOC migrated, 3x+ speedup on all paths.

### Phase 1: Rust Foundation (Weeks 1-6)
**Target**: 20,000 LOC → Python 59% → 52%

| Priority | File | LOC | Speedup Target |
|----------|------|-----|----------------|
| P0 | constellations.py | 1,076 | 15x |
| P0 | graph_engine.py | 706 | 10x |
| P0 | hnsw_index.py | 800 | 20x |
| P1 | galaxy_miner.py | 355 | 8x |
| P1 | recursive_intelligence.py | 600 | 12x |
| P1 | hologram/encoder.py | 483 | 5x |

**Gate**: All 6 compile, pass tests, demonstrate 5x+ speedup.

### Phase 2: Vector & Scientific (Weeks 5-10)
**Target**: 9,000 LOC → Python 52% → 47%

| Language | Files | LOC | Speedup Target |
|----------|-------|-----|----------------|
| Zig SIMD | hrr.py, embeddings, simd_unified | 3,500 | 15x |
| Julia | multi_spectral, gravity, sub_clustering | 2,500 | 30x |
| Both | Additional candidates | 3,000 | 10x |

**Gate**: SIMD shows 8x+, Julia shows 10x+.

### Phase 3: Concurrency & Effects (Weeks 9-14)
**Target**: 9,000 LOC → Python 47% → 41%

| Language | Files | LOC | Speedup Target |
|----------|-------|-----|----------------|
| Elixir | dream_cycle, streaming, session_startup | 2,800 | 5x throughput |
| Koka | sqlite_backend transactions, continuity | 4,500 | 3x safety |

**Gate**: Elixir GenServer pools show 3x+ throughput.

### Phase 4: Specialized Domains (Weeks 13-18)
**Target**: 11,500 LOC → Python 41% → 37%

| Language | Files | LOC | Speedup Target |
|----------|-------|-----|----------------|
| Haskell | pattern_engine, patterns, skeletonizer | 2,650 | 4x |
| Mojo | inference, mojo_bridge, voice_synthesis | 3,000 | 10x |
| Go | HTTP client, ipc_bridge, monitoring | 1,000 | 3x |

**Gate**: All 8 languages have production workloads.

---

## v17.1+ — Future Horizons (2027)

### F1. Distributed Memory
- Multi-node memory federation
- CRDT-based conflict resolution
- Cross-instance memory sync

### F2. Advanced Reasoning
- Chain-of-thought verification
- Self-critique and revision loops
- Multi-agent debate protocols

### F3. Embodied Cognition
- Sensor integration pipeline
- Real-time state tracking
- Physical environment modeling

### F4. Collective Intelligence
- Multi-instance collaboration
- Shared knowledge pools
- Emergent consensus protocols

---

## Priority Matrix

### Immediate (Next 4 Weeks)
1. v15.9 Phase 1: Performance polish
2. S026 Phase 1 prep: Rust toolchain setup
3. LoCoMo v19: Push to 85%+ accuracy

### Near-term (Months 2-3)
4. v15.9 Phases 2-4: Error handling, observability, docs
5. S026 Phase 1 execution: Rust migrations
6. v16 A/B: Embedding + KG pipelines

### Medium-term (Months 4-6)
7. v16 C/D/E: Novelty, graph, dream scheduling
8. S026 Phases 2-3: Zig/Julia/Elixir/Koka
9. Dashboard v2: React-based visualization

### Long-term (Months 7+)
10. S026 Phase 4: Haskell/Mojo/Go
11. v17.0 release: Polyglot supremacy achieved
12. F1-F4: Future horizons R&D

---

## Risk Register

| Risk | Probability | Impact | Mitigation |
|------|-------------|--------|------------|
| FFI overhead > speedup | Medium | High | Benchmark every 500 LOC |
| Polyglot maintenance burden | High | Medium | Documentation budget |
| Mojo toolchain immaturity | High | Medium | Python fallback always |
| DB corruption recurrence | Low | Critical | Auto-backup, WAL mode |
| Performance regression | Medium | High | Canary deployments |

---

## Success Metrics

### v15.9 Exit Criteria
- [ ] Cold start < 1s
- [ ] P95 query latency < 50ms
- [ ] 100% error handling coverage
- [ ] OpenTelemetry traces for all MCP calls

### v16.0 Exit Criteria
- [ ] 100% embedding coverage (auto-maintained)
- [ ] 1000+ KG entities
- [ ] Novelty scores calibrated (0.3-0.7 range for real content)
- [ ] Incremental graph updates < 1s

### v17.0 Exit Criteria
- [ ] Python ≤ 37% of codebase
- [ ] All 20 S026 VCs complete
- [ ] 3x+ speedup on all migrated paths
- [ ] Zero critical bugs for 2 weeks
- [ ] Single-command polyglot build

---

*Document Created: 2026-03-08*
*Last Updated: 2026-03-08*
*Review Cadence: Weekly during active development*
