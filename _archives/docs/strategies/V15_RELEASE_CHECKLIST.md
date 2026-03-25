# WhiteMagic v15.0 Release Checklist

> Generated: 2026-02-11 | Current Version: **14.6.0**
> Source: V15_STRATEGY.md, RELEASE_READINESS_AUDIT, ECONOMIC_AUDIT, CHANGELOG, live project audit

---

## Current State Snapshot (v14.6.0)

| Metric | Value |
|--------|-------|
| **MCP Tools** | 305 (28 PRAT Gana meta-tools) |
| **PRAT Orphans** | 0 |
| **MCP Resources** | 9 (3 orientation + 6 workflows) |
| **Dream Phases** | 7 (added NARRATIVE in v14.6) |
| **Tests** | 18/18 integration, ~1,656 unit (last full run) |
| **Polyglot** | 9 languages (~25K LOC) |
| **Rust PyO3 functions** | 74+ |
| **Embeddings** | 384-dim MiniLM-L6-v2, HNSW indexed |
| **Constellations** | 19 detected, recall-boosted |
| **Version Sync** | VERSION ✅ pyproject.toml ✅ Cargo.toml ✅ agent.json ✅ |

---

## Phase 2: Packaging & Distribution (v14.7)

**Effort:** ~1 week | **Status:** NOT STARTED

### Must-Do

- [ ] **TestPyPI dry run** — `python -m build --sdist --wheel` → `twine upload --repository testpypi` → fresh venv install → `wm doctor`
- [ ] **Clean install matrix** — Python 3.10, 3.11, 3.12 on Ubuntu + macOS
- [ ] **Docker image verification** — Multi-stage build, `docker run whitemagic` starts MCP stdio server
- [ ] **GitHub Actions release workflow** — Tag → build → publish → GitHub Release with RELEASE_NOTES
- [ ] **Dependency audit** — Verify extras groups resolve, pin vulnerable transitive deps
- [ ] **`__version__` runtime sync** — Currently reads stale package metadata (14.5.0); `pip install -e .` or version read from VERSION file fallback needs verification
- [ ] **Setuptools deprecation warnings** — License metadata/classifier style in pyproject.toml

### Operational (No Code)

- [ ] **Galaxy data hygiene** — Reset default galaxy to 12 seed memories before public release
- [ ] **MCP registry submission** — Submit to `registry.modelcontextprotocol.io` and PulseMCP
- [ ] **llms.txt regeneration** — Run `scripts/generate_llms_txt.py` to sync tool count to 305

---

## Phase 3: Nervous System Authoritative (v14.8)

**Effort:** 3-5 sessions | **Status:** NOT STARTED

### Built (Advisory Only)

| Component | File | Perf |
|-----------|------|------|
| StateBoard | `whitemagic-rust/src/state_board.rs` (418 LOC) | 2.3µs read, 432K ops/sec |
| EventRing | `whitemagic-rust/src/event_ring.rs` (383 LOC) | 387ns pub, 2.58M ops/sec |
| Dispatch Core | `whitemagic-zig/src/dispatch_core.zig` (275 LOC) | 1.6µs pipeline, 641K ops/sec |

### Must-Do (Make Authoritative)

- [ ] **StateBoard → Source of Truth** — Python reads HarmonyVector from StateBoard via mmap bridge, not Python singleton
- [ ] **EventRing → Primary Bus** — `gan_ying_enhanced.py emit()` writes to EventRing FIRST, then Python subscribers
- [ ] **Dispatch Authoritative** — If Zig says CIRCUIT_OPEN or RATE_LIMITED, skip Python pipeline entirely
- [ ] **FFI Consolidation** — Compile Zig as static lib, link into Rust PyO3 module (one FFI crossing)

### Files to Modify

- `whitemagic/core/acceleration/state_board_bridge.py`
- `whitemagic/core/acceleration/event_ring_bridge.py`
- `whitemagic/core/acceleration/dispatch_bridge.py`
- `whitemagic/harmony/vector.py`
- `whitemagic/core/resonance/gan_ying_enhanced.py`
- `whitemagic/tools/dispatch_table.py`

---

## Phase 4B-C: Cryptographic Trust (v15.0 Tag)

**Effort:** 2-3 weeks | **Status:** 4A DONE, 4B-C NOT STARTED

### 4A: Ed25519 Manifest Signing ✅ DONE (v14.3.0)

- [x] `generate_signing_keypair()`, `sign_manifest()`, `verify_signature()`
- [x] DID:key format, keypair at `~/.whitemagic/keys/`, PyNaCl
- [ ] **Remaining:** Full per-tool permission scope annotation (only signing infra exists)

### 4B: Karma XRPL Anchoring

- [ ] **Rolling Merkle tree** of karma trace entries (foundation exists: `_merkle_tree_root()`)
- [ ] **XRPL testnet submission** — Hourly anchor: Merkle root → XRPL tx memo field
- [ ] **Verification tool** — Any agent checks audit trail against on-chain anchor
- [ ] **Dependency:** Add `xrpl-py` to optional deps

### 4C: Reproducible Builds

- [ ] **Pin build tool versions** — `SOURCE_DATE_EPOCH` for deterministic wheels
- [ ] **CI publishes build hashes** to transparency ledger
- [ ] **Agent verification** — Check hash against ledger

### v15.0 Exit Criteria

- [ ] Every tool has a signed manifest with permission scopes
- [ ] Karma Merkle root anchored to XRPL testnet
- [ ] Wheel builds are reproducible (same source → same hash)

---

## Economic Layer — Critical Path to First Dollar

### Ready Now ✅

- [x] Manual tip recording via `whitemagic.tip` (handler bug fixed)
- [x] Gratitude stats tracking in persistent ledger
- [x] Proof of Gratitude benefits system (rate limits, badges, voting)

### Blockers (Config Changes)

- [ ] **Set real XRP receive address** — `wallet_manager.py` or env var `WM_XRP_ADDRESS`
- [ ] **Set real beneficiary addresses** — `economies.json` (currently placeholders)
- [ ] **Add tip instructions** to AI_PRIMARY.md and README

### Post-Launch

- [ ] Wire `xrpl-py` for on-chain verification (`verified=True` on real tips)
- [ ] Wire x402 middleware with real USDC verification
- [ ] Gratitude dashboard (web UI)

---

## Bugs Fixed This Session (v14.6.0 tail)

- [x] **Dream cycle e2e test** — Updated for 7-phase rotation (NARRATIVE added in v14.6)
- [x] **Version desync** — Cargo.toml 14.5.0 → 14.6.0, agent.json 14.5.0/285 → 14.6.0/305
- [x] *(Previous session)* Gratitude handler signature mismatch
- [x] *(Previous session)* Missing `ToolCategory.SECURITY` enum

---

## Known Issues (Non-Blocking)

| Issue | Severity | Notes |
|-------|----------|-------|
| `__version__` runtime reads stale 14.5.0 | Low | Package metadata stale; VERSION file fallback works for source checkouts |
| UMAP tests emit sandbox warnings | Low | joblib/numba lock warnings from restricted /dev/shm |
| A2A schema URL 404 | Low | `agent.json` `$schema` URL no longer resolves |
| WindsurfConversationReader non-functional | Info | Cascade .pb files encrypted at rest; reader assumes plaintext protobuf |
| Haskell/Julia accelerators need runtime | Info | Runtime not available on current hardware |

---

## Deferred / Unplanned Items

| Item | Blocker |
|------|---------|
| MCP Bundle (.mcpb) | MCP bundle spec not finalized |
| MCP Elicitation for Governance | MCP SDK elicitation support in clients |
| Holographic Y/Z re-encoding | Low priority, runtime-heavy batch job |
| ~~Iceoryx2 IPC activation~~ | ✅ Compiled + installed (Feb 11, 2026) |
| Mojo GPU megakernel | GPU hardware + Mojo maturity |
| PRAT Compute Marketplace | Depends on Cryptographic Trust |
| MCP Apps Dashboard (Nexus) | UI work, lower priority |
| MCP transport encryption | `--https` flag, self-signed certs |
| Fuzz testing | Testing infrastructure |
| Load testing (100+ parallel) | Testing infrastructure |

---

## Recommended Execution Order

```
v14.7  — Phase 2: Packaging & Distribution (~1 week)
v14.8  — Phase 3: Nervous System Authoritative (~3-5 sessions)
         ── v14.x complete ──
v15.0  — Phase 4B-C: Karma XRPL Anchoring + Reproducible Builds (~2-3 weeks)
         ── EXIT CRITERIA MET → TAG v15.0 ──
v15.1+ — Phase 5: Autonomous Horizon (WASM, static binary, gratitude economy)
```

---

*Supersedes all previous checklists. Source of truth for v15 planning.*
