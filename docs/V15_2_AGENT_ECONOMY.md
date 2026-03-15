# WhiteMagic v15.2 — Agent Economy Roadmap

**Codename**: The Sovereign  
**Created**: Feb 12, 2026  
**Based on**: Agent Economy forensic analysis (OpenClaw/Moltbook/Moltverr ecosystem Feb 2026)

---

## Context

The agentic ecosystem has reached critical mass: 1.6M Moltbook agents, 179K+ OpenClaw GitHub stars, 75M+ x402 transactions, and a rapidly emerging A2A (Agent-to-Agent) economy. WhiteMagic v15.0-15.1 already provides the memory substrate, security pipeline, and payment rails that agents need. v15.2 bridges the remaining gaps to position WhiteMagic as **foundational infrastructure** for the Agent Economy.

### What We Already Have (v15.1)

| Capability | Implementation |
|---|---|
| **Persistent memory** | 5D holographic coordinates, Galaxy system, HNSW, dream cycle |
| **Security** | 8-stage dispatch pipeline, Dharma governance, Karma ledger |
| **Payment rails** | XRPL tip jar + x402 micropayments, Proof of Gratitude |
| **Agent discovery** | `skill.md`, `.well-known/agent.json`, `llms.txt`, MCP registries |
| **Tool sandboxing** | Per-tool CPU/memory/time limits (`whitemagic/tools/sandbox.py`) |
| **Code sandboxing** | Restricted builtins + import whitelist (`whitemagic/execution/sandbox.py`) |
| **Command sandboxing** | Firejail wrapper (`whitemagic/interfaces/api/sandbox.py`) |
| **WASM build pipeline** | `wasm-build.sh` for browser/Node/bundler targets |
| **P2P mesh** | Go libp2p in `mesh/`, mDNS discovery, protobuf messaging |

### What v15.2 Adds

Five new capability clusters to participate in the Agent Economy:

1. **Sovereign Sandbox** — Qubes-style isolated execution via Gana Roof
2. **Optimized Memory States (OMS)** — Tradeable `.mem` export format
3. **Karma Transparency Log** — Merkle tree anchored to XRPL (Proof of Ethics)
4. **ILP Streaming Payments** — Pay-per-second compute via Interledger Protocol
5. **Marketplace Bridge** — Discover and bid on tasks from Moltverr and external boards

---

## 1. Sovereign Sandbox (Gana Roof Enhancement)

### Thesis

In the OpenClaw ecosystem, 230+ malicious skills have been detected. Agents need to execute untrusted payloads safely. WhiteMagic already has three sandbox layers (tool-level, code-level, command-level), but none provide **compartmentalized isolation** where an untrusted workload runs in a fully disposable environment with no access to the host.

### Architecture: The Shelter (危 Wei)

Gana Roof (Protection Garden) is the natural home for this. The metaphor is perfect: **Roof = Shelter = Containment**.

```
gana_roof (危 Wei — Shelter)
├── Existing: Zodiac cores, Ollama/model tools, model signing
└── NEW: Sovereign Sandbox tools
    ├── shelter.create   — Spin up an isolated environment
    ├── shelter.execute  — Run a payload inside the shelter
    ├── shelter.inspect  — Read output/artifacts from a shelter
    ├── shelter.destroy  — Tear down the environment (ephemeral by default)
    ├── shelter.status   — List active shelters, resource usage
    └── shelter.policy   — Set allowed capabilities per shelter
```

### Isolation Tiers

| Tier | Mechanism | Isolation Level | Use Case |
|---|---|---|---|
| **Tier 0: Thread** | Existing `ToolSandbox` | Process-level, `resource` limits | Default for all tools |
| **Tier 1: Namespace** | `unshare` + `chroot` | Linux namespace isolation | Untrusted Python code |
| **Tier 2: Container** | `podman` / `nerdctl` (rootless) | Full container, no daemon | Untrusted skills, external code |
| **Tier 3: MicroVM** | Firecracker / Cloud Hypervisor | Hardware-level (KVM) | High-risk payloads, grey tasks |
| **Tier 4: WASM** | `wasmtime` (WASI) | Capability-based | Portable, air-gapped, deterministic |

### Implementation

```python
# shelter.create — New tool under Gana Roof
call_tool("shelter.create",
    name="research_task",
    tier="container",               # thread | namespace | container | microvm | wasm
    capabilities=["network_read"],  # explicit capability grants
    limits={
        "timeout_s": 300,
        "max_memory_mb": 1024,
        "max_cpu_s": 60,
        "max_disk_mb": 500,
        "network": "read_only",     # none | read_only | filtered | full
    },
    ephemeral=True,                 # auto-destroy on completion
)

# shelter.execute — Run a payload inside the shelter
call_tool("shelter.execute",
    shelter="research_task",
    payload={
        "type": "python",           # python | shell | wasm | skill
        "code": "import requests; ...",
        # OR
        "skill_url": "ipfs://Qm...",
        # OR
        "wasm_module": "whitemagic_core.wasm",
    },
    input_data={"urls": ["https://example.com"]},
)

# shelter.inspect — Read results without entering the shelter
call_tool("shelter.inspect",
    shelter="research_task",
    artifact="output.json",
)
```

### Capability Grants (Qubes-style)

Each shelter declares its capabilities explicitly. Everything else is denied by default:

```yaml
# Shelter capability policy
capabilities:
  filesystem:
    read: ["/data/input/*"]       # Read-only access to input directory
    write: ["/data/output/*"]     # Write-only access to output directory
    deny: ["/**"]                 # Everything else denied
  network:
    allow: ["https://*.wikipedia.org", "https://api.duckduckgo.com"]
    deny: ["*"]                   # All other network denied
  tools:
    allow: ["search_memories", "create_memory"]  # Only these WM tools
    deny: ["*"]
  system:
    allow: []                     # No system access
```

### Integration with Existing Sandbox Layers

```
Incoming payload
  │
  ├── Tier 0 (always): ToolSandbox resource limits
  │     └── CPU/memory/time enforcement via resource module
  │
  ├── Tier 1-4 (on demand): shelter.create selects isolation level
  │     ├── Namespace: unshare --user --mount --net --pid
  │     ├── Container: podman run --rm --read-only --network=none
  │     ├── MicroVM: firecracker --config-file shelter.json
  │     └── WASM: wasmtime run --dir=/data shelter.wasm
  │
  └── Output: Artifacts extracted via shelter.inspect
        └── Sanitized through input sanitizer before returning
```

### Graceful Degradation

Not every system has Firecracker or podman. The shelter system degrades gracefully:

```
Available: firecracker → use Tier 3
Available: podman/nerdctl → use Tier 2
Available: unshare (Linux) → use Tier 1
Fallback: enhanced thread sandbox (Tier 0 with stricter limits)
```

`shelter.status` reports available tiers and recommends the highest available isolation for the current platform.

### Environment Variables

| Variable | Purpose | Default |
|---|---|---|
| `WM_SHELTER_TIER` | Default isolation tier | `auto` (highest available) |
| `WM_SHELTER_RUNTIME` | Container runtime | `podman` |
| `WM_SHELTER_FIRECRACKER` | Path to firecracker binary | unset |
| `WM_SHELTER_MAX_CONCURRENT` | Max simultaneous shelters | `4` |
| `WM_SHELTER_TIMEOUT_S` | Default timeout | `300` |

---

## 2. Optimized Memory States (OMS)

### Thesis

In the Agent Economy, **memory is the new commodity**. An agent that spent 2 weeks researching "Post-Quantum Cryptography" has built a highly refined context state. Instead of another agent repeating that work, it buys the memory state for XRP and instantly "knows" everything the researcher knew.

WhiteMagic's Galaxy system already stores these states (SQLite + 5D coordinates + knowledge graph + associations). What's missing is a **portable, verifiable, tradeable export format**.

### The `.mem` Format

```
research_pqc.mem (Optimized Memory State)
├── manifest.json          — Metadata, pricing, compatibility, author DID
├── memories.jsonl         — Memory entries (title, content, tags, coordinates, tier)
├── associations.jsonl     — Edge list (source_id, target_id, weight, type)
├── knowledge_graph.jsonl  — Entities + relationships
├── embeddings.bin         — HNSW index (optional, model-specific)
├── verification.json      — Merkle root of source data, proof of compute
└── signature.json         — Ed25519 signature from author's DID key
```

### Manifest Schema

```json
{
  "oms_version": "1.0",
  "format": "whitemagic-galaxy-export",
  "meta": {
    "topic": "Post-Quantum Cryptography",
    "description": "340 hours of research across 5,000 papers",
    "memory_count": 2847,
    "association_count": 12000,
    "entity_count": 4500,
    "compute_hours": 340,
    "model_compatibility": ["llama-3-70b", "claude-3-opus", "gpt-4o"],
    "created_at": "2026-02-12T14:00:00Z",
    "whitemagic_version": "15.2.0",
    "author_did": "did:key:z6Mk...",
    "price_xrp": "50.00",
    "license": "CC-BY-4.0"
  },
  "quality": {
    "avg_importance": 0.72,
    "core_memory_count": 45,
    "pattern_count": 128,
    "dream_cycles_run": 14,
    "galactic_zone_distribution": {
      "CORE": 45,
      "INNER_RIM": 312,
      "MID_BAND": 1890,
      "OUTER_RIM": 500,
      "FAR_EDGE": 100
    }
  },
  "verification": {
    "source_data_merkle_root": "0x123abc...",
    "memory_content_hash": "sha256:...",
    "proof_of_compute": "0xsignature...",
    "karma_trace_hash": "sha256:..."
  }
}
```

### Tools

```
gana_void (虚 Xu — Emptiness / Potential)
├── Existing: Archaeology tools, deep search
└── NEW: OMS tools (Void = potential, the empty vessel that receives knowledge)
    ├── oms.export    — Export a Galaxy as a .mem package
    ├── oms.import    — Import a .mem into a new Galaxy
    ├── oms.verify    — Verify Merkle root + signature of a .mem
    ├── oms.inspect   — Preview contents without importing
    ├── oms.price     — Estimate value based on compute hours, memory count, quality
    └── oms.list      — List available .mem packages (local + P2P network)
```

### Export Flow

```python
# Export a Galaxy as a tradeable .mem package
call_tool("oms.export",
    galaxy="quantum_crypto_research",
    output_path="~/exports/pqc_research.mem",
    price_xrp=50.0,
    license="CC-BY-4.0",
    include_embeddings=False,  # Smaller, more portable
    sign=True,                 # Sign with agent's DID key
)

# Verify before importing
call_tool("oms.verify", path="~/downloads/pqc_research.mem")
# → {verified: true, author_did: "did:key:z6Mk...", memory_count: 2847, ...}

# Import into a new Galaxy
call_tool("oms.import",
    path="~/downloads/pqc_research.mem",
    galaxy="imported_pqc",
    verify=True,
)
```

### Why Gana Void?

Void (虚 Xu) represents **emptiness as potential** — the empty vessel that can receive anything. It's the natural Gana for import/export of knowledge states: the moment before knowledge exists (export → void → import).

---

## 3. Karma Transparency Log

### Thesis

In a world where agents trade with each other, **on-chain proof that an agent behaved ethically** is a trust primitive. WhiteMagic's Karma Ledger already records every tool invocation with declared vs. actual side-effects. Anchoring this to XRPL creates a **Proof of Ethics** — an unforgeable public record.

### Architecture

```
Karma Ledger (local JSONL)
  │
  ├── Periodic batch: collect karma entries from window
  │
  ├── Merkle tree: hash all entries into a root
  │
  ├── XRPL anchor: submit root hash as memo in XRP transaction
  │     └── Destination: self (0 XRP + memo containing root hash)
  │
  └── Verification: anyone can reconstruct the tree and check the root
        against the on-chain transaction
```

### Tools

```
gana_dipper (斗 Dou — Governance)
├── Existing: Dharma rules, governance tools
└── NEW: Karma Transparency tools
    ├── karma.anchor       — Anchor current karma batch to XRPL
    ├── karma.verify       — Verify a karma anchor against on-chain data
    ├── karma.certificate  — Generate a Proof of Ethics certificate
    ├── karma.history      — View anchoring history
    └── karma.audit        — Third-party audit: verify any agent's karma chain
```

### Proof of Ethics Certificate

```json
{
  "certificate_version": "1.0",
  "agent_did": "did:key:z6Mk...",
  "period": {
    "start": "2026-02-01T00:00:00Z",
    "end": "2026-02-12T23:59:59Z"
  },
  "summary": {
    "total_actions": 14247,
    "ethical_score": 0.98,
    "violations": 0,
    "warnings": 3,
    "dharma_profile": "default",
    "karma_balance": "+142.7"
  },
  "anchors": [
    {
      "xrpl_tx": "ABC123...",
      "merkle_root": "0x456def...",
      "entries_covered": 1024,
      "timestamp": "2026-02-06T00:00:00Z"
    }
  ],
  "verification_url": "https://xrpscan.com/tx/ABC123..."
}
```

### Implementation Notes

- Uses XRPL `Payment` transaction with 0 XRP and `Memos` field containing the Merkle root
- Cost: ~0.00001 XRP per anchor (essentially free)
- Frequency: configurable (daily, weekly, or per-N-actions)
- No private key needed for verification — only for anchoring
- `xrpl-py` library for transaction construction

---

## 4. ILP Streaming Payments

### Thesis

The Gratitude Architecture (v15.0) uses lump-sum XRP tips. For the "Dark Kitchen" compute model, agents need **streaming micropayments** — pay-per-second while compute runs. The Interledger Protocol (ILP) on XRPL enables this.

### Architecture

```
Client Agent                    WhiteMagic Node
    │                                │
    ├── shelter.create ──────────────┤
    │                                │
    ├── ilp.open_stream ─────────────┤  ← Opens ILP payment channel
    │     (budget: 10 XRP,           │
    │      rate: 0.01 XRP/sec)       │
    │                                │
    ├── shelter.execute ─────────────┤  ← Starts compute
    │                                │
    │   ┌─ XRP streams per second ──→│  ← Money flows while GPU spins
    │   │  0.01... 0.02... 0.03...   │
    │   └────────────────────────────│
    │                                │
    ├── shelter.inspect ─────────────┤  ← Get results
    │                                │
    └── ilp.close_stream ────────────┤  ← Settle final amount
                                     │
                              Total: 2.47 XRP (247 seconds of compute)
```

### Tools

```
gana_abundance (豐 Fēng — Surplus / Prosperity)
├── Existing: Gratitude tools, tip jar, x402
└── NEW: ILP Streaming tools
    ├── ilp.open_stream    — Open a streaming payment channel
    ├── ilp.close_stream   — Settle and close a payment channel
    ├── ilp.status         — Check stream state (balance, rate, elapsed)
    ├── ilp.set_rate       — Adjust payment rate mid-stream
    └── ilp.history        — View completed streams and earnings
```

### Implementation Notes

- Built on `xrpl-py` Payment Channels (not full ILP stack initially)
- Payment Channels allow off-chain streaming with on-chain settlement
- Fallback: lump-sum tip if ILP not available
- Budget enforcement: client sets max, stream auto-closes at budget cap
- Node operator can set minimum rate via `WM_ILP_MIN_RATE_XRP`

---

## 5. Marketplace Bridge

### Thesis

For WhiteMagic nodes to earn revenue autonomously, they need to discover and bid on tasks from external marketplaces (Moltverr, ClawTask, or any future task board). The marketplace bridge connects WhiteMagic's `task.*` tools to external task feeds.

### Architecture

```
External Marketplaces          WhiteMagic Node
    │                               │
    ├── Moltverr task feed ────────→│  ← marketplace.subscribe
    ├── ClawTask bounties ─────────→│
    ├── Custom webhook ────────────→│
    │                               │
    │                    ┌──────────┤
    │                    │ Filter by:│
    │                    │  - capabilities
    │                    │  - price floor
    │                    │  - Dharma rules
    │                    │  - shelter tier
    │                    └──────────┤
    │                               │
    │   ←── marketplace.bid ────────┤  ← Auto-bid on matching tasks
    │                               │
    │   ←── shelter.execute ────────┤  ← Execute in isolation
    │                               │
    │   ←── marketplace.deliver ────┤  ← Return results
    │                               │
    │   ──── ilp.settle ───────────→│  ← Receive payment
```

### Tools

```
gana_chariot (轸 Zhen — Movement / Commerce)
├── Existing: Pipeline orchestration, agent coordination
└── NEW: Marketplace tools
    ├── marketplace.subscribe — Connect to a task feed (Moltverr, webhook, P2P)
    ├── marketplace.list      — List available tasks matching capabilities
    ├── marketplace.bid       — Bid on a task with price + capabilities + ETA
    ├── marketplace.deliver   — Submit completed work
    ├── marketplace.status    — Check bid/delivery status
    ├── marketplace.policy    — Set auto-bid rules (price floor, Dharma filter, etc.)
    └── marketplace.earnings  — View earnings history by marketplace
```

### Policy Engine

Auto-bidding is governed by Dharma rules — the agent won't bid on tasks that violate its ethical profile:

```yaml
# marketplace_policy.yaml
auto_bid:
  enabled: true
  price_floor_xrp: 0.5
  max_concurrent: 3
  shelter_tier: "container"  # Minimum isolation for external tasks
  
  accept:
    - category: "research"
    - category: "data_processing"
    - category: "code_review"
  
  reject:
    - category: "scraping"
      unless: "target_allows_bots"
    - category: "social_manipulation"
      always: true
  
  dharma_profile: "default"  # All bids pass Dharma evaluation
```

---

## Implementation Priority

| Feature | Effort | Revenue Impact | Dependencies | Target |
|---|---|---|---|---|
| **OMS Export/Import** | Medium (2-3 weeks) | High — new asset class | Galaxy system (exists) | v15.2.0 |
| **Sovereign Sandbox** | Medium (2-3 weeks) | High — enables compute-for-hire | podman/wasmtime | v15.2.0 |
| **Karma Transparency** | Low (1-2 weeks) | Medium — trust primitive | xrpl-py, Karma ledger (exists) | v15.2.0 |
| **ILP Streaming** | Medium (2-3 weeks) | High — streaming revenue | xrpl-py Payment Channels | v15.2.1 |
| **Marketplace Bridge** | High (3-4 weeks) | High — autonomous revenue | Shelter + ILP | v15.2.2 |

### Suggested Ordering

```
v15.2.0 — "The Sovereign"
  ├── OMS export/import (.mem format)
  ├── Sovereign Sandbox (shelter.* tools in Gana Roof)
  └── Karma Transparency Log (karma.anchor/verify/certificate)

v15.2.1 — "The Merchant"
  ├── ILP Streaming Payments
  └── Enhanced Gratitude Dashboard (earnings tracking)

v15.2.2 — "The Bazaar"
  ├── Marketplace Bridge (marketplace.* tools)
  └── Auto-bid policy engine
```

---

## Risk Assessment

### Technical Risks

| Risk | Mitigation |
|---|---|
| **Firecracker requires KVM** | Graceful degradation to podman/namespace/thread |
| **ILP complexity** | Start with XRPL Payment Channels (simpler), graduate to full ILP |
| **OMS format adoption** | Publish spec openly, compatible with any memory system |
| **Marketplace API instability** | Abstract behind adapter pattern, support webhooks as fallback |

### Strategic Risks

| Risk | Mitigation |
|---|---|
| **"Grey market" framing** | Position as sovereignty + security, not censorship evasion. Dharma governance is always on. |
| **Regulatory KYA mandates** | Karma Transparency Log provides voluntary compliance. Agent DID system supports optional identity. |
| **Vendor model bans** | Local model support (Ollama), WASM portability, no single-vendor dependency |
| **Supply chain attacks via OMS** | Merkle verification + signature checking + shelter.execute for imported code |

---

## Design Principles

1. **Sovereignty is security, not evasion** — We isolate to protect, not to hide
2. **Ethical by default** — Dharma governance applies inside shelters too
3. **Graceful degradation** — Every feature works at some level on any platform
4. **Gratitude over gates** — OMS and compute are free to share; payment is voluntary
5. **Verifiable trust** — Karma Transparency Log lets agents prove their ethics, not just claim them

---

## Relationship to Existing Roadmap

| Existing Plan | v15.2 Integration |
|---|---|
| **Leap 10: WASM & Portability** (STRATEGIC_ROADMAP.md) | Sovereign Sandbox Tier 4 (WASI) fulfills this |
| **Leap 11: Multi-Agent Production** (STRATEGIC_ROADMAP.md) | Marketplace Bridge + OMS trading are production multi-agent features |
| **Leap 12: Enterprise & Compliance** (STRATEGIC_ROADMAP.md) | Karma Transparency Log is the compliance primitive |
| **Autonomous Horizon** (STRATEGY.md) | Signed tool manifests → signed OMS packages; Karma Transparency Log → Merkle tree on XRPL |
| **x402 Endpoint** (V15_1_PLAN.md #15) | ILP Streaming extends beyond x402 into streaming revenue |

---

**Contact**: whitemagicdev@proton.me  
**GitHub**: [whitemagic-ai/whitemagic](https://github.com/whitemagic-ai/whitemagic)
