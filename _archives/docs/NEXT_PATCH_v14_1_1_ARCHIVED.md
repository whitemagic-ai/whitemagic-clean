# WhiteMagic v14.1.1 Patch Plan — "Hours After Release"

**Prepared:** 2026-02-11 (evening)
**For:** First patch session after v14.1.0 public release
**Goal:** Ship v14.1.1 within hours of v14.1.0 landing. Focus on quick wins that improve real-world usability without destabilizing the core.

---

## Priority Legend

| Tag | Meaning | Time |
|-----|---------|------|
| **P0** | Do first — blocks real users | < 30 min each |
| **P1** | Do second — significant quality improvement | 30-90 min each |
| **P2** | Do if time allows — nice to have | 1-3 hours each |
| **DEFERRED** | Tracked here, do in a future session | Multi-session |

---

## P0: Ship-Blocking Quick Fixes

### 1. Galaxy Data Hygiene for Public Release
**Source:** `BEYOND_V14_1.md` Horizon 1
**Problem:** The default galaxy ships with ~5,600 personal/development memories. Public users should get only the 12 quickstart seed memories.
**Action:**
1. Export current DB to a personal galaxy backup
2. Reset default galaxy (`~/.whitemagic/memory/whitemagic.db`)
3. Run `scripts/seed_quickstart_memories.py`
4. Verify clean state with `wm doctor`
**Effort:** 30 minutes (scripted)
**Files:** No code changes — operational step before `git tag`

### 2. TestPyPI Dry Run
**Source:** STRATEGIC_ROADMAP Leap 5
**Problem:** `python -m build --sdist --wheel` has never been run in CI. Must verify the wheel installs cleanly in a fresh venv.
**Action:**
```bash
make build
pip install dist/whitemagic-14.1.0-py3-none-any.whl
wm doctor
python -c "from whitemagic.tools.unified_api import call_tool; print(call_tool('capabilities')['status'])"
twine upload --repository testpypi dist/*
```
**Effort:** 30 minutes
**Files:** Potentially fix any missing `__init__.py` or `MANIFEST.in` gaps discovered

### 3. `llms.txt` / `llms-full.txt` Auto-Generation
**Source:** `BEYOND_V14_1.md` Horizon 1
**Problem:** Both files are hand-written and will drift from the registry as tools are added. Need a script that generates them from the canonical tool registry.
**Action:** Create `scripts/generate_llms_txt.py` that reads `dispatch_table.py` + `registry_defs/` and emits both files.
**Effort:** 1-2 hours
**Files:** `scripts/generate_llms_txt.py` (new), `llms.txt`, `llms-full.txt`

---

## P1: Quality & Usability Improvements

### 4. HDBSCAN Constellation Upgrade (Deferred 3C)
**Source:** V14_UNIFIED_STRATEGY Phase 3C, LIVING_MEMORY_STRATEGY §2
**Problem:** Constellation detection uses a crude grid-based density scan (8 bins/axis). HDBSCAN provides variable-density clustering with noise rejection and cluster stability metrics. This was spec'd for v14.1 but deferred.
**Action:**
- Add `_detect_hdbscan()` method to `whitemagic/core/memory/constellations.py`
- Fall back to existing `_detect_grid()` when `hdbscan` package is unavailable
- Add `hdbscan>=0.8.33` to `pyproject.toml` `[project.optional-dependencies.search]`
**Effort:** 1-2 hours
**Files:** `whitemagic/core/memory/constellations.py`, `pyproject.toml`, `tests/unit/test_constellations.py`

### 5. Hungarian Algorithm for Drift Correspondence (Deferred 3D)
**Source:** V14_UNIFIED_STRATEGY Phase 3D, LIVING_MEMORY_STRATEGY §2
**Problem:** Constellation drift tracking uses fragile name-based matching. The Hungarian algorithm provides optimal centroid matching across time snapshots, enabling detection of novel/forgotten concept events.
**Action:**
- Upgrade `get_drift_vectors()` in `constellations.py` to use `scipy.optimize.linear_sum_assignment`
- Emit `NOVEL_CONCEPT` / `FORGOTTEN_CONCEPT` events to Gan Ying bus
- Fallback to current name-matching when scipy unavailable
**Effort:** 1-2 hours
**Files:** `whitemagic/core/memory/constellations.py`, `tests/unit/test_constellations.py`

### 6. Duplicate Detection at Ingest (Content Hash)
**Source:** `BEYOND_V14_1.md` Improvement Ideas
**Problem:** The surprise gate catches near-duplicates but doesn't handle exact duplicates from re-ingestion. A content hash check would prevent wasted storage.
**Action:**
- Add SHA-256 content hash column to `memories` table (migration in `sqlite_backend.py`)
- Check hash before store; if match, update existing memory's `accessed_at` instead of creating new
- Wire into `unified.py:store()`
**Effort:** 1-2 hours
**Files:** `whitemagic/core/memory/sqlite_backend.py`, `whitemagic/core/memory/unified.py`, tests

### 7. `wm init` CLI Wizard
**Source:** `BEYOND_V14_1.md` Improvement Ideas
**Problem:** First-time users have no guided setup. Need an interactive wizard that sets up galaxy, seeds memories, detects Ollama, runs health check.
**Action:**
- Add `wm init` command to `whitemagic/cli/cli_app.py`
- Steps: create default galaxy → seed quickstart → detect Ollama → run doctor → print summary
**Effort:** 1-2 hours
**Files:** `whitemagic/cli/cli_app.py`

### 8. Workflow Templates as MCP Resources
**Source:** `BEYOND_V14_1.md` Horizon 1
**Problem:** Users have 208 tools but no guidance on which to use together. Canonical workflows served as MCP resources bridge this gap.
**Action:**
- Add 5-8 workflow resources to `run_mcp_lean.py` (onboarding, dream cycle, security audit, memory import, introspection, governance check)
- Each is a structured markdown with ordered tool-call sequences
**Effort:** 2-3 hours
**Files:** `whitemagic/run_mcp_lean.py`, `whitemagic/workflows/` (new directory)

---

## P2: Deeper Improvements (If Time Allows)

### 9. Association Pruning
**Source:** `BEYOND_V14_1.md` Performance, LIVING_MEMORY_STRATEGY
**Problem:** The 27.8M association graph has significant bloat from bulk archive ingestion. Edges with strength <0.3 are noise.
**Action:**
- Script: `scripts/prune_weak_associations.py` — delete edges below threshold
- Add `prune_associations(min_strength)` to `sqlite_backend.py`
- Log stats: before/after counts, DB size delta
**Effort:** 1-2 hours
**Files:** `scripts/prune_weak_associations.py` (new), `whitemagic/core/memory/sqlite_backend.py`

### 10. Tag Normalization Pass
**Source:** `BEYOND_V14_1.md` Memory Quality
**Problem:** 88K "archive" tags and 19K "scavenged" tags dominate. Semantic tags are diluted.
**Action:**
- Script: `scripts/normalize_tags.py` — consolidate bulk tags (archive→_archive, scavenged→_scavenged), merge near-identical tags
- Optionally: rebuild FTS index after tag cleanup
**Effort:** 1-2 hours
**Files:** `scripts/normalize_tags.py` (new)

### 11. End-to-End MCP Client Test
**Source:** `BEYOND_V14_1.md` Testing
**Problem:** No test actually spins up the MCP server and connects a client. The smoke test calls tools in-process.
**Action:**
- `tests/integration/test_mcp_e2e.py` — start lean server as subprocess, connect via stdio, call 5 representative tools, verify JSON responses
- Skip if `fastmcp` not installed
**Effort:** 2-3 hours
**Files:** `tests/integration/test_mcp_e2e.py` (new)

### 12. MCP Elicitation for Governance
**Source:** `BEYOND_V14_1.md` Horizon 1
**Problem:** When Dharma blocks an action, the MCP server silently fails. Elicitation protocol would ask the user for permission.
**Action:**
- Check if MCP SDK supports `ElicitationResult` (requires SDK 1.26+)
- If available, wire into `dispatch()` for Dharma BLOCK actions
**Effort:** 2-3 hours (research-dependent)
**Files:** `whitemagic/tools/dispatch.py`, `whitemagic/run_mcp_lean.py`

### 13. Holographic Re-Encoding
**Source:** `BEYOND_V14_1.md` Performance
**Problem:** The Y/Z centroid is severely compressed (-0.58/-0.63) after the 110K corpus merge. Spatial query quality suffers.
**Action:**
- Run batch re-encode with calibrated parameters on the merged corpus
- Script: `scripts/holographic_reencode.py` (already exists as `b1_holographic_reencode.py`)
- Verify improved spatial distribution
**Effort:** 2-3 hours (mostly runtime)
**Files:** Existing `scripts/b1_holographic_reencode.py`

---

## DEFERRED: Track But Don't Do Tomorrow

### Nervous System Wiring (V14_UNIFIED_STRATEGY Phase 2)
**Status:** Built but advisory, not authoritative.
**What exists:**
- `state_board.rs` (418 LOC, 2.3µs read, 432K ops/sec)
- `event_ring.rs` (383 LOC, 387ns pub, 2.58M ops/sec)
- `dispatch_core.zig` (275 LOC, 1.6µs pipeline, 641K ops/sec)
- All three have Python bridge files with graceful fallbacks

**What's needed to make them authoritative:**
1. **StateBoard as Source of Truth** — Python consumers read HarmonyVector from StateBoard via bridge, not Python singleton
2. **EventRing as Primary Bus** — `gan_ying_enhanced.py emit()` writes to EventRing FIRST, then Python subscribers
3. **Dispatch Authoritative** — If Zig says CIRCUIT_OPEN or RATE_LIMITED, skip Python pipeline entirely
4. **FFI Consolidation** — Compile Zig as static lib, link into Rust PyO3 module (one FFI crossing instead of two)

**Target version:** v14.2
**Effort:** 3-5 hours

### WASM Proof-of-Concept (V14_UNIFIED_STRATEGY Phase 4A)
**What's needed:**
- Separate `whitemagic-wasm/` crate targeting `wasm32-wasi`
- WIT interface definitions for rate_limiter, keyword_extract, holographic_encode
- Test with wasmtime CLI
**Target version:** v14.2
**Effort:** 2-3 days

### Ed25519 Manifest Signing + DID (Phase 4B)
**What exists:** `manifest.py` with SHA-256 hashes + Merkle tree, no actual cryptographic signing
**What's needed:** Ed25519 keypair generation, `sign_manifest()` / `verify_signature()`, DID:key format (W3C spec)
**Target version:** v14.2
**Effort:** 1-2 days

### Karma XRPL Anchoring (Phase 4C)
**What exists:** `_merkle_tree_root()` in `karma_ledger.py`
**What's needed:** Wire to XRPL testnet via `xrpl-py`, submit Merkle root as transaction memo, verification tool
**Target version:** v14.2
**Effort:** 1-2 days

### PRAT Pricing Formalization (Phase 4D)
**What exists:** `_prat_economics` metadata injected into every PRAT response
**What's needed:** Formal pricing model `V = w_p*P + w_r*R + w_a*A + w_t*T`, per-tool base costs, `prat.pricing` MCP tool
**Target version:** v14.2
**Effort:** 1 day

### Docker Image
**What exists:** `Dockerfile` and `docker-compose.yml` at repo root
**What's needed:** Multi-stage build verification, pre-built Rust `.so`, minimal footprint, `docker run whitemagic` starts MCP server
**Target version:** v14.1.1 or v14.2
**Effort:** 2-4 hours

### Graph Topology Enhancements
**Source:** DREAM_CYCLE_PROTOCOL_STRATEGY, 5D_HOLOGRAPHIC_MEMORY_GAP_ANALYSIS
**Items not yet implemented:**
1. **Causality enforcement** during graph walker traversal (filter by `associations.created_at`)
2. **Temporal PageRank** — citation decay for topological gravity
3. **Echo chamber detection** via eigenvector centrality comparison (T_now vs T_prev)
4. **LLM hypothesis generation** from bridge nodes during dream cycle serendipity phase
5. **Counterfactual simulation** via sandbox "Dream Graph"
**Target version:** v14.2-v15.0

### GPU Acceleration
**Source:** GPU_ACCELERATION_ROADMAP
**Blocked by:** No discrete GPU on current hardware
**Items:**
1. Batch holographic encoding (110K → <1s on GPU vs ~55s Rust)
2. N² pairwise distance matrix
3. Embedding similarity (110K × 384)
4. Local neural inference
**Target version:** v15.x (hardware-dependent)

### Temporal Knowledge Graph Enrichment
**Source:** LIVING_MEMORY_STRATEGY §4-5
**Items:**
1. HyTE temporal embeddings (needs training infrastructure)
2. RE-NET link prediction (needs PyTorch training loop)
3. Full DAG learning via Frank-Wolfe optimization
4. Temporal lineage with bitemporal validity windows
5. Signed network analysis (positive/negative edges)
**Target version:** v15.x (research-grade)

---

## Recommended Session Execution Order

```
── PHASE A: Ship-Ready (< 2 hours) ──────────────────────
  1. Galaxy data hygiene (P0 #1)          ~ 30 min
  2. TestPyPI dry run (P0 #2)             ~ 30 min
  3. llms.txt auto-generation (P0 #3)     ~ 1-2 hours
  4. git tag v14.1.0, push, verify        ~ 15 min

── PHASE B: First Patch (2-4 hours) ──────────────────────
  5. HDBSCAN constellations (P1 #4)       ~ 1-2 hours
  6. Hungarian drift tracking (P1 #5)     ~ 1-2 hours
  7. Content hash dedup (P1 #6)           ~ 1-2 hours
  8. wm init wizard (P1 #7)              ~ 1-2 hours
  9. Run full test suite                  ~ 5 min
  10. git commit + tag v14.1.1, push      ~ 15 min

── PHASE C: Polish (if time allows) ──────────────────────
  11. Workflow templates (P2 #8)           ~ 2-3 hours
  12. Association pruning (P2 #9)          ~ 1-2 hours
  13. Tag normalization (P2 #10)           ~ 1-2 hours
  14. E2E MCP test (P2 #11)               ~ 2-3 hours
```

---

## Source Document Cross-Reference

| Item | Primary Source Doc | Section/Page |
|------|-------------------|--------------|
| Galaxy hygiene | BEYOND_V14_1.md | Horizon 1 |
| TestPyPI | STRATEGIC_ROADMAP.md | Leap 5 |
| llms.txt gen | BEYOND_V14_1.md | Horizon 1 |
| HDBSCAN | V14_UNIFIED_STRATEGY.md | Phase 3C |
| Hungarian | V14_UNIFIED_STRATEGY.md | Phase 3D |
| Content hash | BEYOND_V14_1.md | Improvement Ideas |
| wm init | BEYOND_V14_1.md | Improvement Ideas |
| Workflows | BEYOND_V14_1.md | Horizon 1 |
| Association pruning | BEYOND_V14_1.md | Performance |
| Tag normalization | BEYOND_V14_1.md | Memory Quality |
| E2E MCP test | BEYOND_V14_1.md | Testing |
| Elicitation | BEYOND_V14_1.md | Horizon 1 |
| Nervous System | V14_UNIFIED_STRATEGY.md | Phase 2 |
| WASM | V14_UNIFIED_STRATEGY.md | Phase 4A |
| Ed25519 | V14_UNIFIED_STRATEGY.md | Phase 4B |
| Karma XRPL | V14_UNIFIED_STRATEGY.md | Phase 4C |
| PRAT Pricing | V14_UNIFIED_STRATEGY.md | Phase 4D |
| Docker | STRATEGIC_ROADMAP.md | Leap 5 |
| Graph enhancements | DREAM_CYCLE_PROTOCOL_STRATEGY.md | Part III |
| GPU | GPU_ACCELERATION_ROADMAP.md | Full doc |
| Temporal KG | LIVING_MEMORY_STRATEGY.md | §4-5 |
| FFI consolidation | HIGH_FREQUENCY_PRAT_STRATEGY.md | Part I |
| Swarm/IPC | RESONANT_SWARM_STRATEGY.md | Part 2 |

---

*Prepared for the v14.1.1 patch session. All items traced to source strategy documents for context.*
