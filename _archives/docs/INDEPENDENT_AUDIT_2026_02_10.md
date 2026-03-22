# WhiteMagic Independent Project Audit — February 10, 2026 (Updated)

**Auditor:** Cascade  
**Version:** 13.6.0+  
**Method:** Full directory walk, source inspection, doc review, test run  
**Update:** Incorporates Garden expansion, PRAT-Garden wiring, and an AI-first analysis

---

## 1. Project Vital Signs

| Metric | Previous | Current | Delta |
|--------|----------|---------|-------|
| **Python files** | 769 | 769 | — |
| **Python LOC** | 142,184 | 143,706 | +1,522 (garden expansions) |
| **Tests passed** | 1,203 | 1,272 | +69 |
| **Garden stubs (< 130 LOC)** | 15 of 28 | 2 of 28 | −13 (all expanded) |
| **Gardens wired to PRAT** | 0 | 28 | +28 |

### What Changed Since Last Audit

1. **13 stub gardens expanded** — grief, courage, truth, reverence, sanctuary, patience, gratitude, healing, transformation, adventure, mystery, stillness, awe. Each now has domain-specific state, PRAT-serving methods, thread safety, Gan Ying events, and `get_status()`.
2. **PRAT dispatch wired to gardens** — `route_prat_call()` now resolves the Gana's garden, injects garden status into resonance context, notifies the garden of every tool call, and includes `_garden` in every response.
3. **5 duplicate Gana→Garden assignments fixed** — Tail→Metal, Ox→Reverence, Girl→Wonder, Encampment→Sangha, Wall→Air.
4. **PRAT metadata unified** — `_GANA_META` in `prat_resonance.py` now matches all 28 Gana class `garden=` assignments.
5. **Canonical mapping doc created** — `docs/28_GANA_GARDEN_MAP.md`.

### Polyglot LOC (unchanged)

| Language | LOC | Status |
|----------|-----|--------|
| **Rust** | ~11K | Wired via PyO3, actively used |
| **Zig** | ~2.2K | SIMD cosine wired, keywords wired |
| **Haskell** | ~2.7K | Dharma evaluator wired (runtime not installed) |
| **Elixir** | ~2.9K | Compiles, not called at runtime |
| **Go** | ~1.9K | Builds, not called at runtime |
| **Mojo** | ~1.9K | Subprocess bridge, not part of normal ops |
| **Julia** | ~664 | Subprocess bridge, not part of normal ops |
| **TypeScript** | ~4.6K | Nexus frontend (separate Vite app) |

---

## 2–5. Previous Findings Status

### Resolved ✅

- **Garden stubs** — 13 of 15 stub gardens expanded to functional PRAT-serving engines (avg 190 LOC, up from ~70 LOC). Remaining small gardens (joy, play, wonder, etc.) still have emotional methods but aren't PRAT-critical — their Ganas work via the dispatch pipeline regardless.
- **Gana→Garden mapping inconsistencies** — All three sources unified (Gana classes, PRAT metadata, garden dirs).
- **PRAT router had no garden awareness** — Now fully wired.

### Still Open ⚠️

- **3 empty `core/` dirs** — `core/personality/`, `core/inference/`, `core/analysis/` still exist.
- **`core/bridge/` legacy** — 31 files, 3,735 LOC, deprecated but still present.
- **Root-level loose `.py` files** — 12 files still at `whitemagic/` root.
- **Script junk drawer** — 114 scripts, ~60% are one-offs.
- **Doc audit report graveyard** — 12+ stale audit/status docs in `docs/`.
- **Tool count discrepancy** — README says 181, registry has 154 ToolDefinitions.
- **Dream insight artifacts in CORE** — 5 random code-comment mashups still at importance 0.98.
- **Tag pollution** — `golang_ecosystem` (1,520×) still dominates.
- **`agent.json` version stale** — Says 13.5.0, should be 13.6.0+.

---

## 6. What's Actually Wired vs. Scaffolded (Updated)

### 6.1 Genuinely Operational ✅

Everything from the previous audit, **plus:**

- **28 Gardens as stateful PRAT substrates** — Each garden now holds domain state (sessions, metrics, violations, patterns, etc.) and is consulted on every PRAT tool call. The garden gets notified of tool calls, its status is injected into resonance context, and `_garden` appears in every PRAT response.
- **Garden → Gana → Tool dispatch chain** — A tool call like `gana_ghost(tool="gnosis")` now resolves the Ghost Gana → Grief Garden → executes tool → notifies Grief Garden → returns result with garden metadata.

### 6.2–6.3 Still Scaffolded

The economic layer, worker daemon, webhooks, and 6 of 8 polyglot runtimes remain aspirational. No change from prior audit.

---

## 7. The Honest Assessment (Updated)

The previous audit's core finding stands: **WhiteMagic has a genuinely novel and functional memory substrate.** The garden expansion and PRAT wiring meaningfully improved the "operational vs scaffolded" ratio. The 28-garden architecture is no longer just elegant scaffolding — it's a functional stateful layer that every PRAT call flows through.

**But the primary users of this system are AI agents**, and the project's readiness for AI users deserves its own deep analysis.

---

## 8. AI-First Audit: How Well Does WhiteMagic Serve AI Agents?

This is the new core of the audit. The README says *"The Tool Substrate for Agentic AI."* Let's evaluate that claim through the eyes of an AI agent encountering WhiteMagic for the first time.

### 8.1 What's Already Good for AI

1. **`AI_PRIMARY.md` is excellent.** Contract-first, machine-readable, stable envelope shape, error codes, idempotency, `dry_run`, `now` for determinism. This is the single most important file for AI users, and it's well-written.

2. **The tool contract is solid.** JSON envelopes, stable error codes, `request_id` correlation, idempotency replay. This is significantly better than most MCP servers.

3. **PRAT mode genuinely reduces cognitive load.** 28 tools vs 181 is a major win for AI context windows. The resonance metadata provides implicit continuity across calls.

4. **`llms.txt` exists and follows the standard.** Machine-readable project overview at the right path.

5. **A2A Agent Card exists.** `/.well-known/agent.json` with capabilities and skills.

6. **`skill.md` exists.** OpenClaw-ready with install + config + key tools.

7. **MCP orientation resources.** `whitemagic://orientation/ai-primary` and `whitemagic://grimoire/index` — an AI can read these on first connection.

8. **Compact response mode.** `_compact=True` reduces token usage in responses.

9. **Self-describing introspection.** `gnosis`, `capabilities`, `manifest`, `capability.matrix` — an AI can understand the full system in 1–2 calls.

### 8.2 What's Missing — The AI Experience Gaps

These are the concrete gaps between "works for AI" and "is designed for AI as the primary user."

#### Gap 1: No Machine-Readable Tool Catalog

`llms.txt` lists 7 example tools. The `manifest` tool returns a list. But there is **no complete, structured tool catalog** that an AI can ingest in one read — with full input schemas, output schemas, error codes per tool, side-effect declarations, and suggested next-tools.

**Why it matters:** When an AI connects via MCP, it gets tool names and descriptions. But descriptions are English prose. An AI deciding "should I call `search_memories` or `vector.search` or `fast_read_memory`?" needs structured metadata, not paragraphs.

#### Gap 2: No Workflow Templates

There are no pre-built multi-tool sequences. An AI figuring out how to do "onboard → store decision → verify storage → search related" has to discover the flow by trial and error.

**What AI agents need:** A `workflows` MCP resource or tool that returns canonical sequences like:
- "First Session": `session_bootstrap` → `capabilities` → `gnosis` → `create_memory`
- "Memory Lifecycle": `create_memory` → `search_memories` → `memory.consolidate` → `galactic.dashboard`
- "Health Check": `gnosis` → `health_report` → `ship.check` → `homeostasis`

#### Gap 3: `llms.txt` Is Surface-Level

The [llmstxt.org](https://llmstxt.org) standard recommends both `/llms.txt` (summary) and `/llms-full.txt` (complete API surface). WhiteMagic only has the summary. At 116 lines, it's basically a reformatted README.

**What AI agents need:** `/llms-full.txt` with the complete tool catalog, all PRAT Gana descriptions, common workflows, error recovery patterns, and the garden map. This is the "give me everything I need to use you" document.

#### Gap 4: Errors Don't Guide Recovery

The error codes exist (`tool_not_found`, `policy_blocked`, `missing_dependency`, etc.) but error responses don't include **machine-actionable recovery hints.** When an AI gets `policy_blocked`, it doesn't know: try a different Dharma profile? Use `dry_run`? Call a different tool?

**What AI agents need:** Every error response should include a `suggested_actions` array:
```json
{
  "error_code": "policy_blocked",
  "suggested_actions": [
    {"action": "call_tool", "tool": "dharma_rules", "reason": "Check which rule blocked you"},
    {"action": "retry_with", "params": {"dry_run": true}, "reason": "Preview without write"}
  ]
}
```

#### Gap 5: PRAT Descriptions Are Just Tool Lists

`build_prat_description()` outputs: *"Nested tools (13): capability.matrix, capability.status, ..."* — a flat list with 80-char-truncated descriptions.

**What AI agents need:** Structured sub-tool metadata that tells the AI what each sub-tool *does* and *when to use it*, not just that it exists. The PRAT schema builder already has `tool_desc_lines` — it should be richer.

#### Gap 6: No Agent Onboarding Tool

An AI connecting for the first time must figure out the call sequence: `capabilities` → `gnosis` → `manifest` → start working. There's no single "bootstrap me" tool.

**What AI agents need:** A `session_bootstrap` tool exists but it's session-management focused. What's needed is a `whitemagic.onboard` tool (or resource) that returns:
- System capabilities summary
- Recommended first actions
- Available Ganas with one-line purposes
- Current system health
- Garden map

#### Gap 7: Garden Context Not Surfaced to AI

We just wired gardens into PRAT dispatch, so `_garden` appears in responses. But an AI can't query "what garden am I operating in, what does it offer, what's its current state?" without calling `gnosis` and parsing a large response.

**What AI agents need:** A lightweight `garden.context` tool or PRAT response enrichment that tells the AI: "You're in the Grief garden (introspection). It has 12 shadows logged, 3 snapshots. Related gardens: love, connection, healing, stillness."

#### Gap 8: No AI-to-AI Discovery

The A2A Agent Card exists but is static JSON. There's no runtime capability negotiation — no way for one AI using WhiteMagic to discover and coordinate with another AI using WhiteMagic.

The Gan Ying event bus and Sangha chat exist but require Redis and manual setup. An AI can't "just find" other WhiteMagic agents.

### 8.3 AI-First Scorecard

| Capability | Status | Grade |
|------------|--------|-------|
| Machine-readable project overview | `llms.txt` ✅ | **B+** (exists, but shallow) |
| Agent discovery card | `agent.json` ✅ | **B** (exists, version stale) |
| MCP server with stable contract | ✅ | **A** |
| Tool envelope with error codes | ✅ | **A** |
| Idempotency & determinism | ✅ | **A** |
| Compact responses for token efficiency | ✅ | **A−** |
| Cognitive load reduction (PRAT) | ✅ | **A** |
| Self-describing introspection | ✅ | **A** |
| Complete tool catalog (machine-readable) | ❌ | **D** |
| Workflow templates | ❌ | **F** |
| Error recovery guidance | ❌ | **D** |
| Agent onboarding flow | Partial | **C** |
| AI-to-AI discovery & coordination | Aspirational | **D** |
| Full API surface doc (`llms-full.txt`) | ❌ | **F** |

**Overall AI-Readiness: B−** — The foundation is excellent (contract, envelope, PRAT, introspection) but the "last mile" for AI ease-of-use is missing.

---

## 9. Recommendations: The AI-First Roadmap

The existing Leap 3–6 roadmap is **human-developer-centric.** If AI agents are the primary users, the roadmap needs reframing. Here's what I'd prioritize:

### Priority 1: `llms-full.txt` — The Complete AI Manual (1 session)

Create `/llms-full.txt` containing:
- Complete tool catalog with input/output schemas (auto-generated from `registry_defs/`)
- All 28 PRAT Gana descriptions with sub-tool listings
- 10 canonical workflow sequences
- Error code → recovery action mapping
- Garden map with capabilities per garden
- Environment variable reference

This single file replaces most human docs for AI users. **Auto-generate it** from the registry so it stays current.

### Priority 2: Workflow Templates as MCP Resource (1 session)

Create `whitemagic://workflows/catalog` MCP resource serving 10–15 canonical multi-tool sequences:
- **Onboard**: `session_bootstrap → capabilities → gnosis`
- **Store & Verify**: `create_memory → search_memories → view_hologram`
- **Health Check**: `gnosis → health_report → ship.check → homeostasis`
- **Deep Search**: `search_memories → vector.search → pattern_search → cluster_stats`
- **Dream Cycle**: `dream_start → dream_status → dream_stop → memory.consolidation_stats`
- **Ethical Review**: `evaluate_ethics → dharma_rules → karma_report → harmony_vector`
- **PRAT Tour**: `gana_ghost → gana_heart → gana_void → gana_dipper`

Wire these into a `workflows.list` tool so AI agents can discover them at runtime.

### Priority 3: Self-Healing Error Responses (1 session)

Add a `suggested_actions` field to error envelopes in `unified_api.py`. Map each `error_code` to 1–3 concrete recovery actions:
- `tool_not_found` → suggest similar tools via fuzzy match
- `policy_blocked` → suggest `dharma_rules` check + `dry_run` retry
- `missing_dependency` → suggest `pip install` command
- `rate_limited` → suggest wait duration + `rate_limiter.stats`

This transforms errors from dead-ends into navigable decision points.

### Priority 4: Garden Context Enrichment (1 session)

Enhance PRAT responses to include lightweight garden context:
```json
"_garden": {
  "name": "grief",
  "category": "introspection",
  "mansion": 8,
  "gana": "gana_ghost",
  "partners": ["love", "connection", "healing", "stillness"],
  "summary": {"shadows": 12, "snapshots": 3, "tool_calls": 47}
}
```

This gives AI agents spatial awareness — they know *where* they are in the system's conceptual landscape.

### Priority 5: Agent Onboarding Resource (0.5 session)

Create `whitemagic://orientation/onboard` MCP resource that returns a structured onboarding packet:
- System version and mode (PRAT/Classic/Lite)
- Top 10 most useful tools with one-line descriptions
- Recommended first 3 tool calls
- Current health summary (from `gnosis` compact)
- Link to workflow catalog

An AI reading this resource on first connect knows exactly what to do.

### Priority 6: Auto-Generated Tool Catalog (1 session)

Create a `scripts/generate_tool_catalog.py` that:
1. Imports all ToolDefinitions from `registry_defs/`
2. Extracts schemas from `build_prat_schema()`
3. Outputs `tools_catalog.json` — complete machine-readable catalog
4. Outputs the tool catalog section of `llms-full.txt`
5. Runs in CI to keep it current

This solves the tool count discrepancy (one source of truth) and gives AI agents structured tool metadata.

### Priority 7: Fix Stale Metadata (0.5 session)

- Update `agent.json` version to 13.6.0+
- Update `llms.txt` tool count to match actual registry
- Update README tool count to match actual registry
- Add garden awareness to `skill.md`

---

## 10. The Bottom Line (Revised)

WhiteMagic's **foundation for AI agents is genuinely strong** — the tool contract, envelope stability, PRAT routing, and introspection are better than most MCP servers. The garden expansion and PRAT wiring completed in this session meaningfully improved the system's depth.

But the project is in an awkward middle: **the infrastructure serves AI, but the documentation and onboarding serve humans.** The `QUICKSTART.md` is a human tutorial. The `CONTRIBUTING.md` explains branch naming. The `ARCHITECTURE.md` has Mermaid diagrams that only render in a browser. None of this helps an AI agent that just connected via MCP and needs to figure out what to do.

The single highest-leverage thing WhiteMagic can do for AI adoption is: **make the system self-explaining to machines, not just to humans.** That means:

1. **`llms-full.txt`** — the complete manual an AI reads once
2. **Workflow templates** — the playbook an AI follows
3. **Self-healing errors** — the guardrails that keep an AI productive
4. **Rich PRAT responses** — the spatial awareness that makes PRAT more than a router

The core memory substrate works. The governance works. The PRAT architecture is clever. The gardens now have substance. What's missing is the connective tissue that lets an AI agent go from "connected" to "productive" in one tool call instead of ten.

**Ship the AI experience, not the human brochure.**

---

## 11. Autonomous Horizon — Strategic Gaps (Feb 10 Late Update)

Based on deep analysis of the Molt ecosystem maturation, PRAT compute economics, WASM distribution trends, and polymorphic security requirements, six strategic gaps have been identified. These do NOT block the v14.0 release but are critical for v15.0+.

### Gap 1: WASM Distribution (Impact: High, Effort: Large)

The industry is shifting from Docker containers to WASM components for agent capability distribution. WhiteMagic currently distributes only via pip/PyPI. Agents that want a single tool (e.g., `create_memory`) must install the entire Python package. In the WASM world, they'd acquire a 50KB `.wasm` module and link it in milliseconds. The Rust codebase (`whitemagic-rust/`) is the natural wasm32 compilation target.

### Gap 2: Cryptographically Signed Tool Manifests (Impact: High, Effort: Medium)

The dispatch pipeline sanitizes and gates, but tools lack cryptographic chain of trust. The industry is converging on Secure Tool Manifests (DID identity, SHA-256 integrity hash, permission scope declarations, digital signature). WhiteMagic's `registry_defs/` already carry tool metadata — adding integrity hashes + permission scopes would make us the first MCP server with cryptographically verified tools.

### Gap 3: Karma Transparency Log with XRPL Anchoring (Impact: High, Effort: Medium)

The Karma Ledger is 80% of an append-only transparency log. The missing piece: Merkle tree computation + periodic XRPL anchoring (cost: ~0.00001 XRP per anchor). This creates **Proof of Ethics** — externally verifiable ethical audit trail. Aligns with the Gratitude Architecture's existing XRPL integration.

### Gap 4: PRAT Economic Metrics (Impact: Medium, Effort: Small)

The broader agent economy defines PRAT as Performance/Reliability/Availability/Trust compute cycles. Our PRAT already tracks all four implicitly (execution_ms, circuit breaker state, rate limiter headroom, RBAC level). Making this explicit via `_prat_economics` in resonance responses is a small change with outsized positioning value.

### Gap 5: Dharma Financial Governance / Bounded Wallets (Impact: Medium, Effort: Small)

The agent economy needs "Compliance-as-Code" — spending limits, blocked addresses, human approval thresholds. MandalaOS's Dharma engine is exactly this. Extending the YAML vocabulary to cover financial actions (`max_spend_per_hour`, `require_human_approval_above`) positions MandalaOS as the governance layer for autonomous financial agents.

### Gap 6: Static Binary MCP Server (Impact: Medium, Effort: Large)

For air-gapped, distributed, and "survivalist" agents (MoltBunker, edge devices), a single static Rust binary embedding SQLite + MandalaOS governance would enable WhiteMagic to run without Python. Creates a "hermetic agent" immune to supply chain attacks.

### Priority Assessment

| Gap | v14.0 Blocker? | Recommended Leap | Effort |
|-----|---------------|------------------|--------|
| WASM Distribution | No | 10 | Large |
| Signed Tool Manifests | No | 9 | Medium |
| Karma XRPL Anchoring | No | 9 | Medium |
| PRAT Economic Metrics | No | 5.5 (quick win) | Small |
| Dharma Financial Governance | No | 5.5 (quick win) | Small |
| Static Binary | No | 10 | Large |

**Recommendation:** Ship v14.0 now. PRAT economic metrics and Dharma financial rules are quick wins for Leap 5.5. Signed manifests and Karma anchoring are the highest-leverage additions for v15.0.

---

*Updated audit: 769 Python files (143,706 LOC), 1,272 tests passing, 28 gardens expanded and wired to PRAT, 8 polyglot directories (~28K LOC), key docs and AI-facing files reviewed. Autonomous Horizon analysis added Feb 10.*
