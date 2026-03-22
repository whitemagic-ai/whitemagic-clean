# Demo & Marketing Strategy

> How to show WhiteMagic to the world.

---

## Demo Tiers

### Tier 1: CLI Demo (Zero Setup)

**Audience:** Developers at a terminal
**Time:** 2 minutes

```bash
pip install whitemagic[mcp,cli]
wm init
wm remember "The Dharma Rules Engine supports 3 profiles" --title "Dharma Profiles" --tags governance
wm recall "dharma" --limit 3
wm doctor
```

**Story:** "Install, store a memory, search it, check health. Under 60 seconds."

### Tier 2: MCP Demo (AI Client Integration)

**Audience:** AI agent developers
**Time:** 5 minutes

1. Start MCP server: `python -m whitemagic.run_mcp_lean`
2. Connect from Claude Desktop / Windsurf / Cursor
3. Show: `gnosis(compact=True)` → system health
4. Show: `create_memory` → `search_memories` → `hybrid_recall`
5. Show: `evaluate_ethics` on a proposed action
6. Show: `dream_now` → watch consolidation happen

**Story:** "Your AI agent now has persistent memory, ethical governance, and self-awareness."

### Tier 3: Hosted Playground (Browser-Based)

**Audience:** Non-technical decision makers, curious visitors
**Time:** 10 minutes

- Read-only gnosis portal
- Memory search demo (pre-populated galaxy)
- Harmony Vector visualization
- Galactic Map with zone distribution
- PRAT Gana explorer (28 mansions with icons)

**Tech:** Static site + WhiteMagic MCP HTTP backend (read-only mode)

### Tier 4: Full Workshop

**Audience:** Conference attendees, team onboarding
**Time:** 45-60 minutes

1. Architecture overview (10 min)
2. Hands-on: Install + first memories (10 min)
3. PRAT mode deep-dive: Call 5 different Ganas (10 min)
4. Build a custom agent with Ollama + WhiteMagic (15 min)
5. Q&A (10 min)

---

## Marketing Channels

### Primary (Own)

| Channel | Content Type | Cadence |
|---------|-------------|---------|
| GitHub README | Hero section, badges, quickstart | Update per release |
| `llms.txt` / `skill.md` | Machine-readable capability listing | Update per release |
| Blog (GitHub Pages) | Tutorials, case studies, benchmarks | 2x/month |
| Discord | Community, support, announcements | Daily presence |
| Twitter/X | Threads, demos, release notes | 3x/week |

### Secondary (Earned)

| Channel | Strategy |
|---------|----------|
| Hacker News | Launch post + Show HN for major releases |
| Reddit (r/LocalLLaMA, r/MachineLearning) | Technical deep-dives, not self-promotion |
| YouTube | Tutorial videos, architecture walkthroughs |
| MCP directories | Listings on modelcontextprotocol.io, PulseMCP, mcp.so |
| Conference talks | AI Engineer Summit, local meetups |

### Tertiary (Paid, if funded)

| Channel | Budget | Expected ROI |
|---------|--------|-------------|
| GitHub Sponsors | $0 (receive) | Developer goodwill |
| Twitter promoted | $200/mo | Brand awareness |
| Dev newsletter sponsorships | $500/mo | Targeted developer reach |

---

## Messaging Framework

### One-Liner
> WhiteMagic: 311 MCP tools for AI agents — persistent memory, ethical governance, polyglot accelerators. Free and open.

### Elevator Pitch (30 seconds)
> AI agents need more than an LLM. They need persistent memory that survives across sessions, ethical guardrails that prevent harmful actions, and coordination tools for working with other agents. WhiteMagic provides all of this as a single pip install with 311 MCP tools. It's free, open-source, and runs entirely on your machine.

### Technical Pitch (2 minutes)
> WhiteMagic is a high-performance cognitive infrastructure layer for AI agents. It provides tiered memory with 5D holographic coordinates and HNSW semantic search, a Dharma Rules Engine for ethical governance, a Karma Ledger for side-effect auditing, and polyglot accelerators in 9 languages. The entire system is accessible through 28 PRAT Gana meta-tools or 311 individual MCP tools. Install with `pip install whitemagic[mcp]` and connect any MCP-compatible AI client. All data stays local. MIT licensed.

---

## Competitive Positioning

| Competitor | Their Strength | Our Differentiation |
|-----------|---------------|-------------------|
| LangChain Memory | Ecosystem size | Deeper memory model (5D, galactic lifecycle, no-delete) |
| Mem0 | Simplicity | More tools (311 vs ~10), governance, polyglot speed |
| Pinecone | Scale | Local-first, no cloud dependency, richer metadata |
| Custom solutions | Flexibility | 311 pre-built tools, battle-tested governance |

**Our unique angle:** No other system combines memory + governance + coordination + self-awareness in one package. WhiteMagic is the only MCP server with built-in ethical guardrails.

---

## Performance Claims (Verifiable)

All claims must be reproducible. Scripts in `scripts/benchmark_gauntlet.py` and `scripts/benchmark_mcp.py`.

| Claim | Benchmark | Script |
|-------|-----------|--------|
| Sub-microsecond event bus | 735ns publish latency | `benchmark_gauntlet.py` |
| 452K rate-limit ops/sec | Rust atomic pre-check | `benchmark_gauntlet.py` |
| 500K+ clones/sec | Tokio Clone Army | `benchmark_gauntlet.py` |
| 28.6x search speedup | Cached HNSW vs brute-force | `benchmark_gauntlet.py` |
| 32x Arrow IPC | vs JSON serialization | `benchmark_gauntlet.py` |

---

## Launch Checklist

- [ ] PyPI package published and installable
- [ ] GitHub README with badges, quickstart, architecture diagram
- [ ] MCP directory listings submitted
- [ ] llms.txt and skill.md up to date
- [ ] agent.json validates against A2A schema
- [ ] Demo video recorded (Tier 2 MCP demo)
- [ ] Blog post written ("Introducing WhiteMagic v15")
- [ ] Discord server created with channels
- [ ] Twitter account active
- [ ] HN post drafted
