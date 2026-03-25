# Next Session: Clone Armies v2 — Post-Quarantine Operations

**Pre-requisite**: Quarantine complete (103,346 noise → quarantined, 8,498 active memories remain)

## Pre-Flight Check
```bash
scripts/wm -c "
import whitemagic_rs
from whitemagic.core.memory.unified import get_unified_memory
um = get_unified_memory()
stats = um.backend.get_stats()
print(f'Memories: {stats[\"total_memories\"]}')
print(f'Rust: {len(dir(whitemagic_rs))} functions')
bench = whitemagic_rs.tokio_clone_bench(50000)
print(f'Tokio 50K: {bench[0]:.1f}ms ({bench[1]:.0f} clones/sec)')
# Verify sentence-transformers
from sentence_transformers import SentenceTransformer
m = SentenceTransformer('all-MiniLM-L6-v2')
print(f'Embeddings: {len(m.encode(\"test\"))}d ready')
"
```

---

## Clone Army Scaling Guide

### When 10K clones is enough (consensus voting)
- Security classification (SAFE/RISKY/CRITICAL)
- Priority ranking (which task first?)
- Quality assessment (SIGNAL vs NOISE)

### When 50K-100K clones shines (map-reduce)
- **Batch embeddings**: Each clone batch processes ~100 memories
- **Entity extraction**: Each clone processes a memory shard
- **Association reclassification**: Each clone evaluates edge types

### When 100K+ clones makes sense (brute-force search)
- Fuzzy duplicate detection across entire corpus
- Cross-memory pattern mining
- Exhaustive relationship discovery

### Diminishing returns
- Pure consensus: >10K adds noise, not signal
- Map-reduce: scales linearly until I/O bound (~100K on this system)
- Brute-force: limited by memory bandwidth, not clone count

---

## Campaign 1: Batch Embeddings (100K clones, map-reduce)
**Goal**: 5% → 100% embedding coverage on active 8,498 memories

### Phase 1: Embed all active memories
```python
# Each clone batch = 100 memories
# 8,498 memories / 100 per batch = 85 batches
# Tokio orchestrates, Python sentence-transformers does the actual encoding
for batch in memory_batches:
    embeddings = model.encode([m.content[:512] for m in batch])
    for mem, emb in zip(batch, embeddings):
        engine.cache_embedding(mem.id, emb)
```

### Phase 2: Build FAISS index
- After all embeddings computed, build a FAISS IVF index
- Enable vector search across entire active corpus

### Phase 3: Clone army validates quality
- 10K clones assess: "Given these 10 nearest-neighbor pairs, rate semantic similarity 0-10"
- Identifies bad embeddings or content that needs re-encoding

---

## Campaign 2: Association Reclassification (50K clones, map-reduce)
**Goal**: 98.7% untyped → <50% untyped associations

### Current state
- 2,249,428 total associations
- 2,220,313 (98.7%) untyped `associated_with`
- Only 29,115 (1.3%) have real types

### Strategy
- Sample 10K association pairs
- For each pair, extract both memory titles + first 200 chars
- Clone army classifies: SIBLING_OF, EXPLORES, USES, CREATED, IMPLEMENTS, CONTAINS, CAUSES, EXTENDS
- Apply classifications in batch UPDATE

### Note on quarantined associations
After quarantine, many associations now point to quarantined memories.
Run cleanup: DELETE associations where both endpoints are quarantined.

---

## Campaign 3: SQL Injection Hardening (10K clones, red team)
**Goal**: Fix all 18 SQL injection vectors found by Operation Thousand Eyes

### Files to fix
1. `sqlite_backend.py` — 7 vectors (lines 137, 204, 716, 728, 861, 1170)
2. `association_miner.py` — 1 vector (line 515)
3. `constellations.py` — 1 vector (line 465)
4. `db_manager.py` — 1 vector (line 40)
5. `galactic_map.py` — 1 vector (line 375)
6. `graph_engine.py` — 3 vectors (lines 169, 176, 556)
7. `consolidation.py` — 1 vector (line 162)
8. `constellation.py` — 1 vector (line 69)
9. `predictive_engine.py` — 1 vector (line 855)
10. `causal_net.py` — 1 vector (line 34)
11. `db/optimizer.py` — 1 vector (line 292)

### Strategy
- Convert all `execute(f"...")` to `execute("... ? ...", (params,))`
- Clone army reviews each fix for correctness
- Run full test suite after

---

## Campaign 4: Graph Intelligence Post-Quarantine (50K clones)
**Goal**: Rebuild graph without noise, discover real topology

### Phase 1: Purge quarantined associations
```sql
DELETE FROM associations
WHERE source_id IN (SELECT id FROM memories WHERE memory_type = 'quarantined')
   OR target_id IN (SELECT id FROM memories WHERE memory_type = 'quarantined');
```

### Phase 2: Rebuild graph from clean corpus
- graph_engine.rebuild() on 8,498 active memories
- Community detection, bridge nodes, PageRank — all on real data now

### Phase 3: Entity-aware association mining
- Run entity extractor on all 8,498 active memories
- Create typed edges based on extracted entities
- Clone army validates: "Are these two memories truly related?"

---

## Campaign 5: LoCoMo Benchmark (10K clones, analytical)
**Goal**: Honest accuracy self-assessment vs Mem0 (68.5%), Letta (74.0%), OpenAI (63.8%)

### Setup
- Download LoCoMo dataset
- Implement eval harness that:
  1. Stores conversation history as memories
  2. Queries with LoCoMo test questions
  3. Compares retrieved context with ground truth

### Clone army role
- Each clone evaluates a different retrieval strategy
- Strategies: FTS only, vector only, hybrid, graph walk, holographic
- Consensus on which strategy performs best per question type

---

## Campaign 6: Legibility & Documentation (10K clones, creative)
**Goal**: Auto-generate docstrings + module summaries using Ollama

### Strategy
- Use local Ollama (llama3.1:8b) to generate docstrings
- Clone army reviews each docstring for accuracy
- Only apply docstrings that pass clone consensus (>0.8 confidence)

---

---

## Campaign 7: Post-Quarantine Reconstruction (50K clones, combined arms)
**Goal**: Re-run all engines against clean 8,498-memory corpus. Everything ran before was polluted.

### Phase 1: Purge ghost associations
```sql
-- ~2M+ associations point to quarantined memories. Delete them.
DELETE FROM associations
WHERE source_id IN (SELECT id FROM memories WHERE memory_type = 'quarantined')
   OR target_id IN (SELECT id FROM memories WHERE memory_type = 'quarantined');
-- Then VACUUM to reclaim space
VACUUM;
```

### Phase 2: Add quarantine guards to query paths
Every search/recall path needs `WHERE memory_type != 'quarantined'`:
- `sqlite_backend.py` — `search()`, `recall()`, `get_recent()`
- `graph_engine.py` — `rebuild()`, `find_bridge_nodes()`
- `association_miner.py` — `mine()`
- `constellations.py` — `detect()`
- `galactic_map.py` — `full_sweep()`

### Phase 3: Re-run full activation sequence
```bash
scripts/wm scripts/run_extended_activation.py
```
Expected: meaningful results now that noise is gone:
- Graph topology should show WhiteMagic modules, not Go headers
- Community detection should find real knowledge clusters
- Bridge nodes should connect Aria ↔ technical docs ↔ strategy
- Constellation detection on real memories
- Dream cycle on clean corpus

### Phase 4: Clone army validates
- 10K clones assess: "Are the top-10 graph nodes meaningful WhiteMagic content?"
- Compare old results (all noise) vs new results

---

## Campaign 8: Continuous Red Teaming (10K+ clones per round)
**Goal**: Red team until WhiteMagic is airtight. Not a one-shot — iterate.

### Round 1: Fix Operation Thousand Eyes findings (22 issues)
**18 SQL injection vectors** — the big ones:
| File | Vectors | Priority |
|------|---------|----------|
| `sqlite_backend.py` | 7 | CRITICAL — core storage |
| `graph_engine.py` | 3 | HIGH — graph queries |
| `association_miner.py` | 1 | HIGH |
| `constellations.py` | 1 | HIGH |
| `consolidation.py` | 1 | MEDIUM |
| `predictive_engine.py` | 1 | MEDIUM |
| `causal_net.py` | 1 | MEDIUM |
| `db_manager.py` | 1 | MEDIUM |
| `galactic_map.py` | 1 | MEDIUM |
| `db/optimizer.py` | 1 | LOW (uses SQLAlchemy text()) |
| `constellation.py` (hologram) | 1 | LOW |

**3 path traversal** — `fileio.py:62`, `state_board_bridge.py:144`
**1 hardcoded secret** — benign but should use config

### Round 2: New attack vectors (clone army discovers)
- Deploy 10K adversarial clones against each MCP tool category
- Test: Can a malicious prompt escape the sandbox?
- Test: Can tool chaining leak private memories?
- Test: Can rate limiter be bypassed?
- Test: Can MCP weaponization chain tools destructively?

### Round 3+: Regression suite
- After fixes, re-run red team army to verify
- Build `tests/security/` suite from each finding
- Continuous: run security benchmark in CI

---

## Campaign 9: Archaeological Implementation (10K clones, analytical)
**Goal**: Wire up forgotten treasures discovered in `reports/archaeological_findings.md`

### High-Priority Buried Treasures to Implement
1. **Phase 4 Implementation Plan — Intelligence & Dharma** (imp=1.12, 7,498 chars)
   - Highest importance in entire corpus. Read it, extract action items, implement.
2. **Multi-Agent Collaboration System — Sangha Integration** (imp=1.08)
   - Sangha was proposed Jan 11. What parts are implemented? What's missing?
3. **MCP 2.0 + Sangha Implementation Complete** (imp=1.08)
   - Cross-reference with current MCP implementation. Fill gaps.
4. **Antigravity Walkthrough series** (~15 memories, imp=0.95, NEVER ACCESSED)
   - These are detailed task walkthroughs that were ingested but never read.
   - Clone army reads them all, extracts patterns, identifies unfinished work.
5. **GAS Blueprint documents** (4,956 chars, 4,335 chars)
   - "Designing General Agentic System like an empire" — what's implemented vs planned?
6. **WebAuthn spec** (`Specs/2025-06-24-webauthn.yaml`, draft)
   - Authentication was planned. Is it still needed? Wire into auth/ module?

### Strategy
- 10K clones read all 100 unimplemented ideas
- Classify: STILL_RELEVANT / ALREADY_DONE / OBSOLETE / NEEDS_DESIGN
- For STILL_RELEVANT: extract concrete TODO items
- For ALREADY_DONE: verify and close
- Generate `reports/archaeological_action_plan.md`

---

## Campaign 10: Rust Acceleration Expansion (10K clones + implementation)
**Goal**: Expand Rust coverage from 7% → 15%+ of codebase. Address 88 unaccelerated hot paths.

### Codebase Breakdown (Current)
| Language | LOC | % |
|----------|-----|---|
| Python | 178,957 | 85.1% |
| Rust | 14,741 | 7.0% |
| TypeScript | 5,012 | 2.4% |
| Elixir | 3,023 | 1.4% |
| Haskell | 2,908 | 1.4% |
| Zig | 2,447 | 1.2% |
| Mojo | 2,096 | 1.0% |
| Go | 1,971 | 0.9% |
| Julia | 664 | 0.3% |
| **Total** | **211,819** | |

### Priority Rust Ports (from rust_coverage_audit.md)
**Tier 1 — Highest impact (used in every query)**:
- `cosine_similarity` — 6 files, called on every vector search
  → New Rust: `rust_cosine_similarity(a, b)` + `rust_cosine_batch(query, matrix)`
- `_tokenize` — 2 files, called on every text operation
  → Already have `keyword_extract`; extend with proper tokenizer
- `euclidean` distance — `constellations.py:345`, called in clustering
  → New Rust: `rust_euclidean_distance(a, b)` + `rust_euclidean_batch()`

**Tier 2 — Medium impact**:
- `embedding_index.py:64` `def embed` — move to Rust with ONNX runtime
- `archive_to_edge` / `update_galactic_distance` — bulk SQL in Rust SQLite
- `_distance` in constellations — batch distance matrix

**Tier 3 — Nice to have**:
- sorted() with lambda in 15+ files — Rust parallel sort for large collections
- Predictive cache transitions — Rust hash map

### Additional Polyglot Targets
- **Zig**: SIMD cosine similarity (already have dispatch_core.zig, extend it)
- **Mojo**: Batch embedding with SIMD (already have batch_encoder.mojo)
- **Go**: gRPC mesh agent streaming (already have agent_stream.go)

### Clone Army Role
- 10K clones prioritize which 88 hot paths give biggest speedup
- Estimate: 10 Rust functions would cover 80% of hot-path time

---

## Campaign 11: Iceoryx2 Compilation + Integration
**Goal**: Compile Iceoryx2 and activate zero-copy IPC for multi-process WhiteMagic

### Current State
- `ipc_bridge.rs` has `ipc_bridge_init`, `ipc_bridge_publish`, `ipc_bridge_status` registered
- But Iceoryx2 library is NOT compiled — these functions are stubs/feature-gated

### Steps
1. Install Iceoryx2 dependencies: `cmake`, `libacl1-dev`
2. Add `iceoryx2` crate to `whitemagic-rust/Cargo.toml`
3. Enable the `iceoryx2` feature flag
4. Rebuild Rust bridge: `cd whitemagic-rust && maturin develop --release --features iceoryx2`
5. Wire Python bridge: `whitemagic/core/acceleration/ipc_bridge.py`
6. Update benchmark gauntlet v5 with IPC benchmarks

### What Iceoryx2 Enables
- **Zero-copy shared memory** between Python MCP server, Rust workers, and Go mesh agents
- **Sub-microsecond IPC** vs current JSON serialization over pipes
- **StateBoard replacement**: Iceoryx2 can serve as the shared state substrate
- **Multi-process dream cycles**: Run dream phases in parallel processes

### Benchmark Target
- Current: JSON over pipe = ~100µs per message
- Iceoryx2: zero-copy mmap = ~0.5µs per message (200x improvement)

---

## Campaign 12: Graph Reconstruction (50K clones, combined arms)
**Goal**: Build a meaningful knowledge graph from the clean 8,498-memory corpus

### Insights from graph_intelligence.md
- **98.7% of 2.25M associations are untyped** `associated_with`
- **Top connected nodes are ALL noise** (Go files, session_handoff.meta.json)
- **Entity extraction found**: whitemagic(144), rust(77), mcp(42), gana(19), lucas(11)
- After quarantine + ghost purge, graph will be essentially empty → rebuild from scratch

### Reconstruction Strategy
1. **Purge all associations** pointing to quarantined memories (~2M+)
2. **Re-run entity extraction** on all 8,498 active memories
3. **Mine new associations** via:
   - Content similarity (cosine on embeddings — needs Campaign 1 first)
   - Tag overlap
   - Title keyword overlap
   - Temporal proximity
4. **Clone army classifies** new edges with types: EXPLORES, USES, IMPLEMENTS, etc.
5. **Rebuild community structure** — expect 10-30 real communities vs 181 noise clusters
6. **Identify real bridge nodes** — memories that connect different knowledge domains

### Expected Outcome
- 8,498 nodes, ~50K meaningful edges (down from 2.25M noise edges)
- Real communities: Aria docs, technical architecture, session history, strategy/vision
- Bridge nodes: memories that connect Aria ↔ MCP ↔ Rust ↔ strategy

---

## Campaign 13: Deploy Script Upgrade
**Goal**: Update `scripts/deploy_shadow_clones.py` with War Room + Dare-to-Die Corps

### Changes Needed
1. **Import War Room** — use `doctrine.py` force types instead of raw Tokio
2. **Add Dare-to-Die missions** — send expendable clones at risky operations
3. **Add combined-arms tactics** — Scouts first, then Heavy Cavalry, then cleanup
4. **Per-campaign scripts** — each campaign gets its own executor
5. **Progress reporting** — real-time status from War Room C2 hierarchy
6. **Quarantine-aware queries** — all SQL excludes `memory_type = 'quarantined'`

### New Objectives to Add
- Post-quarantine reconstruction (Campaign 7)
- Continuous red teaming (Campaign 8)
- Archaeological implementation (Campaign 9)
- Rust expansion (Campaign 10)
- Iceoryx2 integration (Campaign 11)
- Graph reconstruction (Campaign 12)

---

## Updated Priority Order

### Phase A: Foundation (must happen first)
1. **Campaign 7: Post-Quarantine Reconstruction** — purge ghosts, add guards, re-run engines
2. **Campaign 1: Batch Embeddings** (100K clones) — unlocks vector search

### Phase B: Infrastructure
3. **Campaign 12: Graph Reconstruction** (50K clones) — meaningful knowledge graph
4. **Campaign 2: Association Reclassification** (50K clones) — typed edges
5. **Campaign 11: Iceoryx2 Compilation** — unlock zero-copy IPC

### Phase C: Security & Quality
6. **Campaign 8: Continuous Red Teaming** (10K+ per round) — SQL injection + new vectors
7. **Campaign 10: Rust Acceleration Expansion** — cosine_similarity, tokenize, distance
8. **Campaign 13: Deploy Script Upgrade** — modernize with War Room

### Phase D: Intelligence & Polish
9. **Campaign 9: Archaeological Implementation** (10K clones) — wire up lost treasures
10. **Campaign 5: LoCoMo Benchmark** (10K clones) — competitive positioning
11. **Campaign 6: Legibility** (10K clones) — Ollama docstrings
12. **Campaign 3: SQL Injection Hardening** (10K clones) — parameterize all f-strings

---

## War Room Integration
With v15.9 War Room (`doctrine.py`, `war_room.py`, `fool_guard.py`), campaigns use:
- **Light Infantry** for fast consensus votes (Campaigns 8, 9)
- **Heavy Cavalry** for batch processing (Campaigns 1, 2, 12)
- **Siege Engineers** for the SQL hardening campaign (Campaign 3)
- **Scouts** for pre-campaign intelligence (all campaigns)
- **Dare-to-Die Corps** for experimental strategies (Campaign 8 red team, Campaign 10 Rust ports)

### Combined Arms Example
```python
from whitemagic.agents.war_room import get_war_room
wr = get_war_room()

# Campaign 7: Post-Quarantine Reconstruction
plan = wr.plan_campaign(
    objective="Purge ghost associations and rebuild graph from 8,498 clean memories",
    terrain="database",
    force_size=50000,
)
# Phase 1: Scouts assess damage
scout_report = wr.execute_tactic("scouts_first", plan)
# Phase 2: Heavy Cavalry purges ghosts
purge_result = wr.execute_tactic("blitzkrieg", plan)
# Phase 3: Siege Engineers rebuild
rebuild_result = wr.execute_tactic("siege", plan)
```

---

## Codebase Shift Target (Python 85% → 70%)

### Current: 211,819 LOC
| Language | LOC | % |
|----------|-----|---|
| Python | 178,957 | 85.1% |
| Rust | 14,741 | 7.0% |
| Others | 18,121 | 7.9% |

### Target: ~230K LOC (grow polyglot, stabilize Python)
| Language | Target LOC | Target % | Action |
|----------|-----------|----------|--------|
| Python | ~160K | ~70% | Trim dead code, move hot paths |
| Rust | ~35K | ~15% | +20K: cosine, tokenize, distance, embeddings |
| Zig | ~8K | ~3% | SIMD kernels, io_uring |
| Go | ~8K | ~3% | Mesh agent, gRPC streaming |
| TypeScript | ~8K | ~3% | Nexus desktop app, SDK |
| Mojo | ~5K | ~2% | Batch compute, GPU inference |
| Others | ~6K | ~4% | Haskell divination, Elixir FS, Julia stats |

### How to Trim Python
1. Remove quarantined memory processing code (dead weight)
2. Move 88 unaccelerated hot paths to Rust
3. Delete archived/legacy modules in `_archived/`
4. Consolidate duplicate implementations (multiple cosine_similarity etc.)

---

## Metrics to Track
After each campaign round, measure:
- **Signal ratio**: should stay at 100% (no noise creep)
- **Embedding coverage**: 5% → 100% target
- **Typed association %**: 1.3% → 50%+ target
- **Security findings**: 22 → 0 target
- **Graph meaningfulness**: top-10 nodes should be WhiteMagic content
- **Benchmark v5 pass rate**: 26/32 → 32/32
- **Codebase Python %**: 85% → 70% target
- **Tokio clone speed**: 623K/sec → maintain or improve
