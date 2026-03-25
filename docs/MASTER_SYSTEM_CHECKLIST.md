# WhiteMagic Master System Checklist

**Date:** 2026-02-13 (v15.6.0)
**Purpose:** Complete inventory of every system, engine, garden, MCP tool, core, and subsystem — with operational status tracking.

---

## 1. MCP Server & Transport

| Component | Status | Notes |
|-----------|--------|-------|
| MCP Lean Server (`run_mcp_lean.py`) | ✅ Verified | Path fixed v15.5; imports clean |
| MCP Classic Server (`run_mcp.py`) | ✅ Verified | Full-weight server with FastMCP |
| stdio transport | ✅ Verified | Default for IDE integration |
| Streamable HTTP transport (`--http`) | ⬜ Verify | Port 8770, needs live test |
| Server Instructions (`mcp_instructions.md`) | ✅ Verified | Auto-injected via resources |
| MCP Resources (3): AI Primary, Instructions, System Map | ✅ Verified | 3 resources registered |
| Workflow Templates (6) | ⬜ Verify | Module not found — may need wiring |

---

## 2. The 28 Gana Meta-Tools (356 nested tools)

### Eastern Quadrant (Azure Dragon) — Initiation

| # | Gana | Domain | Nested Tools | Status |
|---|------|--------|:---:|--------|
| 1 | **Horn** (角) | Session init | 10 | ✅ |
| 2 | **Neck** (亢) | Core memory CRUD | 6 | ✅ |
| 3 | **Root** (氐) | System health | 9 | ✅ |
| 4 | **Room** (房) | Locks & privacy | 22 | ✅ |
| 5 | **Heart** (心) | Session context | 11 | ✅ |
| 6 | **Tail** (尾) | Acceleration | 6 | ✅ |
| 7 | **Winnowing Basket** (箕) | Wisdom & search | 15 | ✅ |

### Southern Quadrant (Vermilion Bird) — Expansion

| # | Gana | Domain | Nested Tools | Status |
|---|------|--------|:---:|--------|
| 8 | **Ghost** (鬼) | Introspection & web | 36 | ✅ |
| 9 | **Willow** (柳) | Resilience & grimoire | 9 | ✅ |
| 10 | **Star** (星) | Governance | 12 | ✅ |
| 11 | **Extended Net** (张) | Pattern connectivity | 12 | ✅ |
| 12 | **Wings** (翼) | Export & deploy | 4 | ✅ |
| 13 | **Chariot** (轸) | Archaeology & KG | 29 | ✅ |

### Western Quadrant (White Tiger) — Harvesting

| # | Gana | Domain | Nested Tools | Status |
|---|------|--------|:---:|--------|
| 14 | **Abundance** (豐) | Regeneration & dreams | 28 | ✅ |
| 15 | **Straddling Legs** (奎) | Ethics & balance | 10 | ✅ |
| 16 | **Mound** (娄) | Metrics & caching | 7 | ✅ |
| 17 | **Stomach** (胃) | Digestion & tasks | 9 | ✅ |
| 18 | **Hairy Head** (昴) | Debug & anomaly | 15 | ✅ |
| 19 | **Net** (毕) | Capture & filtering | 4 | ✅ |
| 20 | **Turtle Beak** (觜) | Edge inference | 6 | ✅ |

### Northern Quadrant (Black Tortoise) — Conservation

| # | Gana | Domain | Nested Tools | Status |
|---|------|--------|:---:|--------|
| 21 | **Three Stars** (参) | Judgment & synthesis | 11 | ✅ |
| 22 | **Dipper** (斗) | Strategy | 12 | ✅ |
| 23 | **Ox** (牛) | Endurance & swarm | 8 | ✅ |
| 24 | **Girl** (女) | Nurture & agents | 6 | ✅ |
| 25 | **Void** (虚) | Galaxies & gardens | 26 | ✅ |
| 26 | **Roof** (危) | Shelter & Ollama | 15 | ✅ |
| 27 | **Encampment** (室) | Community & messaging | 8 | ✅ |
| 28 | **Wall** (壁) | Boundaries & voting | 10 | ✅ |

---

## 3. The 28+ Gardens

| Garden | Module | Purpose | Status |
|--------|--------|---------|--------|
| Adventure | `gardens/adventure/` | Exploration & discovery | ⬜ |
| Air | `gardens/air/` | Agentic terminal + scratchpad | ⬜ |
| Awe | `gardens/awe/` | Wonder & amazement | ⬜ |
| Beauty | `gardens/beauty/` | Aesthetics & form | ⬜ |
| Browser | `gardens/browser/` | Web browser automation | ⬜ |
| Connection | `gardens/connection/` | Relationship & linking | ⬜ |
| Courage | `gardens/courage/` | Bold action | ⬜ |
| Creation | `gardens/creation/` | Generative processes | ⬜ |
| Dharma | `gardens/dharma/` | Ethics & governance | ⬜ |
| Gratitude | `gardens/gratitude/` | XRPL tip jar & appreciation | ⬜ |
| Grief | `gardens/grief/` | Loss processing | ⬜ |
| Healing | `gardens/healing/` | Recovery & repair | ⬜ |
| Humor | `gardens/humor/` | Levity & play | ⬜ |
| Joy | `gardens/joy/` | Happiness & celebration | ⬜ |
| Love | `gardens/love/` | Care & compassion | ⬜ |
| Metal | `gardens/metal/` | Refinement + Zodiac Council | ⬜ |
| Mystery | `gardens/mystery/` | Unknown & discovery | ⬜ |
| Patience | `gardens/patience/` | Endurance & timing | ⬜ |
| Play | `gardens/play/` | Experimentation | ⬜ |
| Practice | `gardens/practice/` | Skill development | ⬜ |
| Presence | `gardens/presence/` | Mindfulness & awareness | ⬜ |
| Protection | `gardens/protection/` | Safety & defense | ⬜ |
| Reverence | `gardens/reverence/` | Sacred respect | ⬜ |
| Sanctuary | `gardens/sanctuary/` | Safe space | ⬜ |
| Sangha | `gardens/sangha/` | Community & messaging | ⬜ |
| Stillness | `gardens/stillness/` | Quiet & meditation | ⬜ |
| Transformation | `gardens/transformation/` | Change & evolution | ⬜ |
| Truth | `gardens/truth/` | Honesty & verification | ⬜ |
| Voice | `gardens/voice/` | Narrative & expression | ⬜ |
| Wisdom | `gardens/wisdom/` | Knowledge & insight | ⬜ |
| Wonder | `gardens/wonder/` | Curiosity & collective dreams | ⬜ |

---

## 4. Core Subsystems

### Memory Layer

| System | File(s) | Purpose | Status |
|--------|---------|---------|--------|
| Unified Memory | `core/memory/unified.py` | Central memory API | ✅ |
| SQLite Backend | `core/memory/sqlite_backend.py` | Persistence layer | ✅ |
| Embeddings | `core/memory/embeddings.py` | MiniLM-L6-v2 384d vectors | ✅ |
| Vector Search | `core/memory/vector_search.py` | SBERT + TF-IDF fallback | ✅ |
| Graph Walker | `core/memory/graph_walker.py` | Multi-hop weighted random walk | ✅ |
| Graph Engine | `core/memory/graph_engine.py` | networkx centrality + community | ✅ |
| Bridge Synthesizer | `core/memory/bridge_synthesizer.py` | Structural hole insight gen | ✅ |
| Surprise Gate | `core/memory/surprise_gate.py` | Plasticity/stability balance | ✅ |
| HRR | `core/memory/hrr.py` | Holographic Reduced Representations | ✅ |
| Galactic Map | `core/memory/galactic_map.py` | Retention-based distance | ✅ |
| Mindful Forgetting | `core/memory/mindful_forgetting.py` | 5-signal retention engine | ✅ |
| Constellations | `core/memory/constellations.py` | HDBSCAN + Hungarian drift | ✅ |
| Consolidation | `core/memory/consolidation.py` | Hippocampal replay | ✅ |
| Lifecycle | `core/memory/lifecycle.py` | Periodic retention sweep | ✅ |
| Association Miner | `core/memory/association_miner.py` | Jaccard + semantic edges | ✅ |
| Memory Links | `core/memory/linking/` | Co-activation tracking | ✅ |
| Memory Clones | `core/memory/clones/` | Thought cloning | ✅ |
| Memory Matrix | `core/memory/memory_matrix/` | Matrix operations | ✅ |

### Intelligence Layer

| System | File(s) | Purpose | Status |
|--------|---------|---------|--------|
| Holographic Encoder | `core/intelligence/hologram/encoder.py` | 5D XYZWV encoding | ✅ |
| Knowledge Graph | `core/intelligence/knowledge_graph.py` | In-memory entity-relation graph | ✅ |
| Entity Extractor | `core/intelligence/entity_extractor.py` | Ollama-driven triple extraction | ✅ |
| Causal Miner | `core/intelligence/synthesis/` | Causal inference | ✅ |
| Solver Engine | `core/intelligence/synthesis/` | Dharmic optimization | ✅ |
| Learning Engine | `core/intelligence/learning/` | Pattern learning | ✅ |
| Emotions | `core/intelligence/emotions/` | Emotional processing | ✅ |
| Agentic Intelligence | `core/intelligence/agentic/` | Agent-specific reasoning | ✅ |

### Dreaming Layer

| System | File(s) | Purpose | Status |
|--------|---------|---------|--------|
| Dream Cycle | `core/dreaming/dream_cycle.py` | 8-phase hippocampal replay | ✅ |
| Phase: CONSOLIDATION | — | Tag clustering + entity resolution | ✅ |
| Phase: SERENDIPITY | — | Association discovery + bridge nodes | ✅ |
| Phase: KAIZEN | — | Continuous improvement | ✅ |
| Phase: ORACLE | — | Grimoire consultation | ✅ |
| Phase: DECAY | — | Mindful forgetting sweep | ✅ |
| Phase: GOVERNANCE | — | Echo chamber detection | ✅ |

### Governance Layer

| System | File(s) | Purpose | Status |
|--------|---------|---------|--------|
| Dharma Engine | `core/governance/` | YAML rules, 3 profiles | ✅ |
| Karma Ledger | — | Declared vs actual side-effects + Merkle | ✅ |
| Governor | — | Budget, drift, goal validation | ✅ |
| Gana Vitality | — | 12.108.20 competence honor | ✅ |
| Gana Sabhā | — | Democratic decision-making | ✅ |
| Gana Forge | — | Extension protocol (YAML) | ✅ |
| Bhīṣma Layer | — | Governance hardening | ✅ |

### Acceleration Layer (Polyglot)

| Component | Language | File(s) | Purpose | Status |
|-----------|----------|---------|---------|--------|
| Rust Bridge | Rust/PyO3 | `whitemagic-rust/` | BM25, rate limiter, holographic encode, minhash, I Ching | ✅ |
| Zig Dispatch | Zig/C-ABI | `whitemagic-zig/` | SIMD distance, dispatch core | ✅ |
| Mojo Compute | Mojo | `whitemagic-mojo/` | Batch encoding, coordinate encoding | ✅ |
| Julia Analytics | Julia | `whitemagic-julia/` | Memory stats, self-model forecast | ✅ |
| Haskell Divination | Haskell | `haskell/` | Boundary detection, casting, Wu Xing | ✅ |
| Elixir Core | Elixir | `elixir/` | File system, brain | ✅ |
| Go Mesh | Go | `mesh/` | Agent gossip protocol, gRPC | ✅ |
| TypeScript SDK | TypeScript | `sdk/typescript/` | Client library | ✅ Skeleton |
| Seed Binary | Rust | `whitemagic-rust/src/bin/` | Zero-dep MCP server (2.4MB) | ✅ |
| StateBoard | Rust | `whitemagic-rust/src/state_board.rs` | Shared memory (4KB mmap) | ✅ |
| EventRing | Rust | `whitemagic-rust/src/event_ring.rs` | Lock-free ring buffer (65K slots) | ✅ |

### Security & Safety

| System | Purpose | Status |
|--------|---------|--------|
| 8-Stage Dispatch Pipeline | Sanitizer→Breaker→Rate→RBAC→Maturity→Governor→Handler→Compact | ✅ |
| Circuit Breakers | Per-tool CLOSED→OPEN→HALF_OPEN | ✅ |
| Rate Limiter | Rust atomic counter | ✅ |
| RBAC | Permission scopes | ✅ |
| SQLCipher Encryption | Encryption at rest | ✅ |
| Manifest Signing | SHA-256 + Merkle tree (Ed25519 partial) | ✅ |
| Immune System | `core/immune/` — antibodies, defense, detection | ✅ |
| Violet Security | Edgerunner security layer | ✅ |

### Other Systems

| System | File(s) | Purpose | Status |
|--------|---------|---------|--------|
| Harmony Vector | `harmony/` | 7D system health | ✅ |
| Wu Xing | `wu_xing/` | Five Elements phase detection | ✅ |
| Zodiac Council | `gardens/metal/zodiac/` | 12-sign perspective engine | ✅ |
| Grimoire | `grimoire/` | 28 spells + templates | ✅ |
| Oracle | `oracle/` | I Ching + divination | ✅ |
| Resonance | `resonance/` | PRAT resonance context | ✅ |
| Sessions | `sessions/` | Session management + checkpoints | ✅ |
| Metrics | `metrics/` | Telemetry + OpenTelemetry | ✅ |
| Mesh | `mesh/` | Agent mesh networking | ✅ |
| Plugins | `plugins/` | Extension system | ✅ |
| Workflows | `workflows/` | 6 workflow templates | ⬜ Needs wiring |
| Prompts | `prompts/` | Prompt templates + rendering | ✅ |
| Inference | `inference/` | Edge/BitNet inference | ✅ |
| Local ML | `local_ml/` | Local model management | ✅ |
| Browser | `gardens/browser/` | Playwright browser automation | ✅ |
| Dashboard | `interfaces/dashboard/` | Web dashboard | ⬜ Not deployed |
| CLI | `interfaces/cli/` | Command-line interface | ✅ |
| API | `interfaces/api/` | REST API routes | ✅ |
| Nexus (Tauri) | `nexus/` | Desktop app | ⬜ Scaffold only |

---

## 5. Databases & Data Stores

| Store | Location | Memories | Associations | Status |
|-------|----------|----------|-------------|--------|
| Active MCP DB | `~/.whitemagic/memory/whitemagic.db` | 5,170 | 213K+ | ✅ Rehydrated v15.3 |
| Hot Archive | `whitemagic_memory_archive/whitemagic_hot.db` | 5,627 | 247,417 | ✅ Source used |
| Cold Archive | `whitemagic_memory_archive/whitemagic_cold.db` | 105,194 | — | ✅ Archived |
| Pre-merge | `wm_archive/phase6_dead_files/primary_db_pre_merge.db` | 3,631 | — | ✅ Best Aria content |
| Personal Galaxy | `~/.whitemagic/memory/galaxies/personal_archives/` | 0 | — | ⬜ Empty |
| Embedding Cache | In-memory numpy | — | — | ✅ |
| KG (in-memory) | `knowledge_graph.py` | — | — | ✅ |

---

## 6. Activation Sequence (Run Order)

After rehydration, run these in order:

```
 1. ⬜ MCP Server — verify 28 Ganas load
 2. ⬜ gana_horn → session_bootstrap — initialize session
 3. ⬜ gana_root → health_report — system health check
 4. ⬜ gana_root → state.summary — state overview
 5. ⬜ gana_void → galaxy.status — check galaxy state
 6. ⬜ gana_void → galaxy.ingest — ingest archive memories
 7. ⬜ gana_winnowing_basket → search_memories — verify search works
 8. ⬜ gana_ghost → gnosis — introspection report
 9. ⬜ gana_ghost → graph_topology — build graph
10. ⬜ gana_abundance → dream_now — single dream cycle
11. ⬜ gana_abundance → memory.lifecycle — lifecycle sweep
12. ⬜ gana_abundance → serendipity_surface — surface connections
13. ⬜ gana_extended_net → pattern_search — find patterns
14. ⬜ gana_extended_net → cluster_stats — constellation stats
15. ⬜ gana_chariot → kg.extract — knowledge graph enrichment
16. ⬜ gana_chariot → kg.top — top entities
17. ⬜ gana_three_stars → kaizen_analyze — improvement suggestions
18. ⬜ gana_three_stars → reasoning.bicameral — dual-hemisphere synthesis
19. ⬜ gana_straddling_legs → wu_xing_balance — elemental balance
20. ⬜ gana_straddling_legs → harmony_vector — 7D health
21. ⬜ gana_mound → view_hologram — holographic overview
22. ⬜ gana_mound → get_yin_yang_balance — yin/yang state
23. ⬜ gana_willow → grimoire_suggest — spell recommendations
24. ⬜ gana_star → governor_stats — governance stats
25. ⬜ gana_star → forge.status — extension status
26. ⬜ gana_dipper → homeostasis.check — homeostatic loop
27. ⬜ gana_dipper → maturity.assess — maturity assessment
28. ⬜ gana_hairy_head → karma_report — karma audit
29. ⬜ gana_roof → ollama.models — check local models
30. ⬜ gana_ghost → selfmodel.forecast — self-model prediction
```

---

*Generated 2026-02-12. Update status as each system is verified.*
