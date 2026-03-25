# Living Memory Gap Analysis — Transcript-Inspired Improvements
**Date:** 2026-02-11  
**Sources:** 5 conversation transcripts (multimodal holographic core, 5D temporal memory architecture, living memory systems, 5D memory space theory, ChatGPT discussion on WM theory + 2026 trends + neuroscience)  
**Methodology:** Internal codebase audit + external research (Zep/Graphiti paper, HRR library, agent memory survey, neuroscience literature)

---

## Executive Summary

WhiteMagic already implements a remarkable amount of what the research papers describe. Out of ~25 major features discussed across the transcripts, **~15 are already built**. The remaining gaps cluster around three themes:

1. **Multimodal expansion** — WM only ingests text; needs PDF/image/audio support
2. **Semantic graph intelligence** — Graph walks lack semantic steering and compositional binding
3. **Knowledge graph quality** — Statistical association mining should be augmented with LLM-driven entity extraction

Below is a systematic audit of what exists vs. what's missing, followed by prioritized proposals.

---

## Part 1: What WhiteMagic Already Has

### ✅ 5D Holographic Coordinate System
- **File:** `whitemagic/core/intelligence/hologram/encoder.py`
- **Axes:** X (Logic↔Emotion), Y (Micro↔Macro), Z (Time), W (Gravity), V (Vitality)
- **Implementation:** Keyword heuristic encoding with Rust/Mojo/Zig acceleration paths
- **Matches paper:** Axes map to paper's recommendations (Logic/Emotion ≈ Modality, Micro/Macro ≈ Orientation)

### ✅ Graph-Guided Vector Search (GGVS)
- **File:** `whitemagic/core/memory/graph_walker.py` (~535 LOC)
- **Pattern:** Anchor search via embeddings → weighted random walk → ranked terminal nodes
- **Transition probability:** `P(v|u) ∝ Strength × Gravity^α × Recency × (1-Staleness)^β`
- **Matches paper:** Core GGVS architecture is implemented. Paper argues GGVS > RRF for multi-hop reasoning — WM chose correctly.

### ✅ Dual Decay Model (Exponential + Power-Law)
- **File:** `whitemagic/core/memory/sqlite_backend.py:821-918`
- **Episodic:** `w(t) = w_prev × e^(-0.0231 × Δt_days)` — 30-day half-life
- **Semantic:** `w(t) = w₀ × (1 + 0.1Δt)^(-0.5)` — power-law long tail
- **Pruning:** Edges below 0.05 strength are deleted
- **Matches paper:** Exactly the dual-model the "Living Memory" transcript recommends (exponential for episodic, power-law for semantic).

### ✅ Hebbian Strengthening
- **Files:** `sqlite_backend.py:hebbian_strengthen()`, `unified_types.py:Memory.recall()`, `linking/strength_tracker.py`
- **Mechanisms:** Co-access boost (+0.05 × (1-w)), neuro_score boost on recall, MemoryLink co-activation
- **Half-life:** Configurable per-memory (default 30 days), `neuro_score = 0.5^(days/half_life)`
- **Matches paper:** "Neurons that fire together wire together" — fully implemented.

### ✅ HDBSCAN Clustering + Grid Fallback
- **File:** `whitemagic/core/memory/constellations.py` (~948 LOC)
- **Primary:** HDBSCAN with variable-density, noise rejection, per-cluster stability scores
- **Fallback:** 5D grid-based density scan + flood-fill merge
- **Matches paper:** Paper recommends HDBSCAN over K-Means/DBSCAN. WM already uses it.

### ✅ Hungarian Optimal Drift Matching
- **File:** `constellations.py:851-898`
- **Algorithm:** scipy `linear_sum_assignment` on centroid distance matrix
- **Outputs:** matched pairs, novel concepts, forgotten concepts
- **Events:** Emits NOVEL_CONCEPT/FORGOTTEN_CONCEPT to Gan Ying bus
- **Matches paper:** Exactly what the "Constellation Drift" section recommends.

### ✅ Constellation Drift Tracking
- **File:** `constellations.py:734-845`
- **History:** Per-constellation centroid history (max 100 snapshots)
- **Drift vectors:** 5D displacement over configurable window
- **Windowed analysis:** Filters by time cutoff

### ✅ Bitemporal on Associations
- **File:** `sqlite_backend.py:158-163`
- **Columns:** `valid_from`, `valid_until`, `ingestion_time` on associations table
- **Note:** Columns exist but are sparsely populated by current miners.

### ✅ PageRank / Centrality
- **File:** `whitemagic/core/memory/graph_engine.py` (~634 LOC)
- **Metrics:** Eigenvector, betweenness, PageRank centrality via networkx
- **Community detection:** Louvain algorithm
- **Echo chamber detection:** Centrality snapshot drift comparison

### ✅ Surprise-Gated Ingestion
- **File:** `whitemagic/core/memory/surprise_gate.py` (~250 LOC)
- **Formula:** `S = -log₂(max_cosine_sim)` — high surprise → boost importance

### ✅ Bridge Node Synthesis
- **File:** `whitemagic/core/memory/bridge_synthesizer.py` (~270 LOC)
- **Method:** Template fallback + optional Ollama LLM for insight generation from structurally important nodes

### ✅ Dream Cycle (Hippocampal Replay Analog)
- **File:** `whitemagic/core/dreaming/dream_cycle.py`
- **6 phases:** CONSOLIDATION, SERENDIPITY, KAIZEN, ORACLE, DECAY, GOVERNANCE
- **Biology:** Maps to hippocampal replay during sleep — consolidate, prune, create novel associations

### ✅ Dual-Store Memory Model
- **Files:** `unified_types.py`, `consolidation.py`, `lifecycle.py`
- **Model:** SHORT_TERM → LONG_TERM promotion via consolidation, frequently accessed memories get promoted
- **Biology:** Maps to hippocampal (SHORT_TERM) → neocortical (LONG_TERM) transfer

---

## Part 2: What's Missing — Gap Analysis

### 🔴 GAP 1: No Multimodal Intake (HIGH IMPACT)

**Current state:** `holographic_intake.py` supports only 9 text file types (.md, .txt, .json, .yaml, .yml, .py, .ts, .js, .html). All ingestion reads UTF-8 text.

**Paper proposal:** MediaProcessor Protocol with pluggable processors per media type.

**Why it matters:** In a 2026-2027 world where agents process PDFs, screenshots, audio transcripts, and video, text-only memory is a ceiling. PDFs alone would unlock enormous value (research papers, documents, reports).

**Proposed implementation:**
```python
class MediaProcessor(Protocol):
    def can_process(self, path: Path) -> bool: ...
    def extract_text(self, path: Path) -> str: ...
    def extract_metadata(self, path: Path) -> dict: ...
    def holographic_bias(self) -> dict[str, float]: ...
```

**Tiers:**
| Tier | Types | Library | Effort |
|------|-------|---------|--------|
| 1 — Documents | .pdf, .docx, .epub | PyMuPDF, python-docx | ~200 LOC |
| 2 — Images | .png, .jpg, .webp | CLIP/BLIP-2, Pillow | ~200 LOC |
| 3 — Audio | .mp3, .wav, .flac | whisper/faster-whisper | ~150 LOC |
| 4 — Video | .mp4, .webm | ffmpeg + whisper + BLIP-2 | ~300 LOC |
| 5 — Structured | .csv, .xlsx, .ipynb | pandas, nbformat | ~200 LOC |

**Holographic biases per media type:**
- Documents: X- (logical), Y+ (abstract), Z- (historical), W+ (weighty)
- Images: X+ (emotional), Y- (concrete), Z≈0 (present)
- Audio: X+ (emotional), Z varies, W+ (embodied)

---

### 🔴 GAP 2: No Semantic Projection in Graph Walks (HIGH IMPACT)

**Current state:** `graph_walker.py:_transition_score()` uses Strength × Gravity × Recency × Staleness but does NOT incorporate semantic similarity to the query.

**Paper proposal:** The walk should be "steered" by semantic alignment:
```
Score(u,v) = SemanticSim(v_projected, v_neighbor)^w × Gravity^α × Recency × (1-Staleness)^β
```

**Why it matters:** Without semantic steering, the walker follows the strongest structural paths regardless of relevance to the query. A walk about "pricing strategy" could wander into "authentication bugs" just because they share high-strength association edges.

**Proposed fix:** ~80 LOC change to `graph_walker.py`:
1. Accept a query embedding in `walk()` and `hybrid_recall()`
2. Load neighbor embeddings (from embeddings cache)
3. Compute cosine similarity between query embedding and each neighbor
4. Fuse into transition score with configurable weight

---

### 🟡 GAP 3: No HRR Circular Convolution (MEDIUM-HIGH IMPACT)

**Current state:** The name "holographic" refers to the 5D coordinate system, NOT to Holographic Reduced Representations (Plate, 1995). No circular convolution, binding, or unbinding exists.

**External finding:** The `hrr` pip package (v1.2.3) provides ready-to-use HRR operations for PyTorch, JAX, and Flax. Binding and unbinding via FFT-based circular convolution.

**Why it matters:** HRR enables compositional queries like "What caused X?" by computing `query = concept_X ⊗ relation_caused_by⁻¹`. This would give the graph walker a "look-ahead" vector for the next hop rather than just following structural edges.

**Proposed implementation:**
- New file: `whitemagic/core/memory/hrr.py` (~200 LOC)
- Wrap `hrr` library with numpy fallback
- Define relation vectors: CAUSES, FOLLOWED_BY, PART_OF, SIMILAR_TO
- Use in graph_walker: `projected_vec = bind(current_embedding, relation_vec)`
- Compare neighbors against projected_vec instead of raw query

**Note:** The gap analysis doc (`5D_HOLOGRAPHIC_MEMORY_GAP_ANALYSIS.md`) deferred this as P6/LOW. Recommend upgrading to MEDIUM given the pip library availability.

---

### 🟡 GAP 4: No LLM-Driven Entity Extraction (MEDIUM IMPACT)

**Current state:** `association_miner.py` uses keyword fingerprinting + Jaccard overlap. Statistical, not semantic.

**Zep/Graphiti approach:** Uses LLM prompts to extract (subject, relation, object) triples, then resolves entities against existing graph nodes (deduplication).

**Why it matters:** Statistical mining produces lots of low-quality "associated_with" edges. LLM extraction produces typed, directional edges like "Lucas CREATED WhiteMagic", "Dream Cycle CONSOLIDATES memories". This is the difference between a noisy association graph and a real knowledge graph.

**Proposed implementation:**
- New file: `whitemagic/core/intelligence/entity_extractor.py` (~250 LOC)
- Use Ollama API (already integrated) with structured extraction prompts
- Extract: entities (name, type), relations (subject, predicate, object)
- Wire into store() pipeline after surprise gate
- Graceful degradation: skip when Ollama unavailable

---

### 🟡 GAP 5: Fused Gravity Signal (MEDIUM IMPACT)

**Current state:** Graph walker uses only `galactic_distance` for gravity. Memory has `neuro_score` (Hebbian). Graph engine computes PageRank. These three signals are siloed.

**Paper proposal:** Gravity should be a composite metric:
```
Gravity(v) = w₁ × (1 - galactic_distance) + w₂ × neuro_score + w₃ × pagerank
```

**Proposed fix:** ~40 LOC in `graph_walker.py`:
1. Load `neuro_score` alongside `galactic_distance`
2. Optionally load cached PageRank from graph_engine
3. Fuse with configurable weights

---

### 🟢 GAP 6: No Causality Enforcement in Walks (LOW-MEDIUM)

**Current state:** Walker loads `created_at` for recency scoring but doesn't enforce temporal ordering between hops.

**Paper requirement:** A valid reasoning path A→B→C requires t(A→B) ≤ t(B→C).

**Proposed fix:** ~30 LOC — add optional `enforce_causality: bool = False` to `walk()`, filter neighbors where `created_at < previous_hop_created_at`.

---

### 🟢 GAP 7: Bitemporal on Memories Table (LOW-MEDIUM)

**Current state:** Associations have `valid_from`/`valid_until`/`ingestion_time`. Memories table only has `created_at` and `accessed_at`.

**Zep model:** Every fact carries event_time (when it became true) and ingestion_time (when the system learned it).

**Proposed fix:** ~60 LOC migration adding `event_time TEXT` and `ingestion_time TEXT` to memories table. Store() populates ingestion_time automatically; event_time is caller-provided or defaults to ingestion_time.

---

### 🟢 GAP 8: Working Memory Capacity Model (LOW, STRATEGIC)

**Current state:** No concept of bounded working memory. All memories are equally accessible.

**Biology:** Human working memory holds ~4-7 chunks. This constrains attention and forces prioritization.

**ChatGPT transcript insight:** "Multi-agent systems need a shared working memory that constrains what's in the active focus."

**Proposed concept:** A `WorkingSet` that holds the N most recently accessed/relevant memories, with LRU eviction. Agents read from the working set first, falling back to full search. This models the biological "attentional bottleneck" that forces strategic prioritization.

---

## Part 3: Neuroscience Mapping

| Biological Principle | WhiteMagic Implementation | Status | Gap |
|---|---|---|---|
| Hebbian learning | neuro_score + co-access strengthening | ✅ Complete | — |
| Hippocampal replay | Dream cycle CONSOLIDATION phase | ✅ Complete | — |
| Synaptic pruning | decay_associations() + lifecycle sweeps | ✅ Complete | — |
| Dual-store model | SHORT_TERM → LONG_TERM promotion | ✅ Complete | — |
| Surprise-gated learning | surprise_gate.py | ✅ Complete | — |
| Spreading activation | graph_walker multi-hop | ✅ Partial | Sequential, not parallel |
| Reconsolidation | — | ❌ Missing | Retrieved memories should enter labile state |
| Working memory limits | — | ❌ Missing | No bounded active set |
| Sleep consolidation cycles | Dream cycle (idle-triggered) | ✅ Complete | — |
| Ebbinghaus forgetting curve | Power-law decay on semantic edges | ✅ Complete | — |
| Long-term potentiation | hebbian_strengthen() | ✅ Complete | — |
| Emotional tagging (amygdala) | emotional_valence field, joy_score | ✅ Partial | Not used in graph walk gravity |

---

## Part 4: Zep/Graphiti Comparison

| Feature | Zep/Graphiti | WhiteMagic | Delta |
|---|---|---|---|
| Three-tier graph (episodic/semantic/community) | ✅ Core architecture | ✅ Partial (memories/associations/constellations) | Communities are post-hoc, not incremental |
| Bitemporal modeling | ✅ t_valid/t_invalid on all edges | ✅ On associations only | Add to memories table |
| LLM-driven entity extraction | ✅ GPT-4/Claude prompts | ❌ Statistical keyword mining | Major gap |
| Entity resolution (dedup) | ✅ Embedding-based matching | ✅ consolidation.py resolve_entities() | Exists but not in intake pipeline |
| Community detection | ✅ Label propagation (incremental) | ✅ Louvain + HDBSCAN (batch) | Consider incremental |
| Hybrid search | ✅ BM25 + embedding + graph expansion | ✅ Same pattern | Comparable |
| Reranking | ✅ Cross-encoder reranker | ❌ | Could add as optional layer |
| DMR benchmark: 94.8% | ✅ Published | — | WM not benchmarked on DMR |
| Temporal reasoning | ✅ Strong | ✅ Partial | Add causality enforcement |

---

## Part 5: Recommended Implementation Order

### Phase A — Quick Wins (v14.x, this week)
1. **A2: Semantic projection in graph walks** — ~80 LOC, biggest reasoning quality gain
2. **A3: Fused gravity signal** — ~40 LOC, better node ranking
3. **B3: Causality enforcement** — ~30 LOC, temporal reasoning
4. **GAP 7: Bitemporal on memories** — ~60 LOC migration

### Phase B — Multimodal (v15.0)
5. **A1: MediaProcessor protocol + PDF** — ~300 LOC, opens non-text world
6. **C2: Image processor** — ~200 LOC, depends on A1

### Phase C — Knowledge Graph Quality (v15.x)
7. **B2: LLM-driven entity extraction** — ~250 LOC, transforms association quality
8. **B1: HRR binding module** — ~250 LOC, compositional retrieval

### Phase D — Strategic / Research (v16+)
9. **GAP 8: Working memory capacity model** — architectural
10. **C3: Incremental community maintenance** — ~300 LOC refactor
11. **Reconsolidation model** — research-grade

---

## Part 6: Alignment with 2026-2027 Trends

The ChatGPT conversation identifies several trends WM is well-positioned for:

| Trend | WM Readiness | Gap to Close |
|---|---|---|
| Local/edge AI growth | ✅ SQLite + file-based + local-first | None |
| Multi-agent coordination | ✅ Agent registry + swarm + shared memory | Working memory model |
| Memory as alignment lever | ✅ Human-editable files + Dharma rules | None |
| Model-agnostic substrate | ✅ MCP interface, works with any LLM | None |
| Multimodal agents | ❌ Text-only intake | MediaProcessor protocol |
| Longer context windows | ✅ Memory is complementary, not replaced | None |
| Agent economy/monetization | ✅ Gratitude architecture + x402 | None |

**Key insight from transcripts:** "The missing piece for most AI right now isn't more clever tokens, it's good memory architecture + sanitation." WM is building exactly this. The gaps identified here would extend it from "excellent text memory" to "comprehensive cognitive memory system."

---

*Generated by codebase audit + external research. See also: `5D_HOLOGRAPHIC_MEMORY_GAP_ANALYSIS.md`, `STRATEGIC_ROADMAP.md`, `V15_STRATEGY.md`*
