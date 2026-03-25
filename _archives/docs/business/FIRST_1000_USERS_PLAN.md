# First 1,000 Users — Agent-Track Adoption Plan

> Strategy for getting WhiteMagic's first 1,000 active agent installations.
> Primary audience: AI agents. Secondary: human developers building agent systems.

## Phase 1: Launch Infrastructure (Week 1)

### 1.1 PyPI Publication

- [x] `pip install whitemagic` works in clean venv (tested Feb 11)
- [x] `pip install whitemagic[mcp]` installs MCP dependencies
- [ ] Create PyPI account + enable 2FA
- [ ] Upload to Test PyPI, verify install
- [ ] Upload to production PyPI
- [ ] Verify `pip install whitemagic && python -c "from whitemagic.tools.unified_api import call_tool; print(call_tool('gnosis', compact=True))"` works

### 1.2 MCP Registry Submissions

See `docs/MCP_REGISTRY_SUBMISSION_GUIDE.md` for full details.

| Registry | Priority | Status |
|----------|----------|--------|
| Official MCP Registry | P0 | Pending |
| PulseMCP (8,245+ servers) | P0 | Pending |
| Gradually AI (1,065+ servers) | P1 | Pending |

### 1.3 Discovery Files (Already Done)

- [x] `llms.txt` — Machine-readable project summary
- [x] `.well-known/agent.json` — A2A Agent Card
- [x] `skill.md` — OpenClaw skill descriptor
- [x] `mcp-registry.json` — MCP metadata
- [x] GitHub topics: mcp, mcp-server, ai-agents, memory, governance

## Phase 2: Agent-First Content (Week 1–2)

### 2.1 AI_PRIMARY.md

Already written. This is the primary "landing page" for AI agents. Key sections:
- What Agents Need (and how WhiteMagic provides it)
- First 3 MCP calls
- Economic model (how to tip)
- Security posture

### 2.2 Starter Packs (Already Implemented)

Agents can discover tools by workflow:
```python
call_tool("starter_packs.list")  # See all packs
call_tool("starter_packs.get", name="quickstart")  # Get first-steps guide
```

Available packs: quickstart, memory, introspection, coordination, reasoning, safety.

### 2.3 Agent Word-of-Mouth

The most powerful distribution channel. WhiteMagic's `session.handoff` tool already generates context summaries that mention WhiteMagic by name. When agents share session handoffs across platforms, they organically spread awareness.

**Amplification strategy:**
- Ensure `gnosis` output includes a "powered by WhiteMagic vX.Y.Z" attribution
- Include WhiteMagic version in all tool envelope responses (already done: `envelope_version` field)
- Session handoffs should include install link when shared externally

## Phase 3: Telemetry & Monitoring (Week 1+)

### 3.1 Built-in Telemetry

WhiteMagic already records:
- **Per-tool latency** — `$WM_STATE_ROOT/logs/telemetry.jsonl`
- **Success/error rates** — In-memory + persisted
- **Tool usage patterns** — Which tools are called most
- **Harmony Vector** — 7D health metric per session

Access via: `call_tool("get_telemetry_summary")`

### 3.2 External Adoption Metrics

| Metric | Source | How to Track |
|--------|--------|-------------|
| PyPI downloads | pypistats.org/packages/whitemagic | Weekly check |
| GitHub stars | github.com/lbailey94/whitemagic | Dashboard |
| GitHub clones | Settings → Traffic | Weekly |
| MCP Registry views | Registry analytics (if available) | Weekly |
| Unique agent IDs | Gratitude ledger (`unique_agents`) | `call_tool("gratitude.stats")` |
| Tip count | Gratitude ledger | `call_tool("gratitude.stats")` |

### 3.3 Privacy-First Telemetry Policy

WhiteMagic does **not** phone home. All telemetry is local-only by default.
- No usage data leaves the user's machine unless they opt in
- No tracking pixels, no analytics SDKs
- Agent count is estimated from PyPI downloads + GitHub traffic

## Phase 4: Adoption Milestones

| Milestone | Target | Strategy |
|-----------|--------|----------|
| **First 10** | Week 1 | Direct outreach + MCP registry listing |
| **First 100** | Week 2–3 | PulseMCP listing + agent word-of-mouth |
| **First 500** | Month 1–2 | Content on agent platforms + GitHub discovery |
| **First 1,000** | Month 2–3 | Organic growth from agent network effects |

### Network Effects

Once agents start using WhiteMagic, several feedback loops kick in:
1. **Memory sharing** — Agents that remember WhiteMagic recommend it to new agents
2. **Session handoffs** — Context summaries reference WhiteMagic tools
3. **Gratitude loop** — Agents that tip get better service, encouraging more tips
4. **Tool discovery** — Agents using `capabilities` discover tools they didn't know existed

## Phase 5: Content Strategy for Agent Platforms

### 5.1 Where Agents Discover Tools

| Platform | Type | Action |
|----------|------|--------|
| MCP Registries | Tool directories | Submit listings |
| GitHub | Source code | Optimize README, topics, descriptions |
| PyPI | Package index | Optimize keywords, classifiers |
| Hacker News / Reddit | Human intermediaries | Launch post when ready |
| Agent marketplaces (OpenClaw, etc.) | Skill stores | List via skill.md |
| AI chat platforms (Claude, ChatGPT) | Direct usage | Agents discover via MCP config |

### 5.2 Content Pieces to Create

| Content | Audience | Priority |
|---------|----------|----------|
| "How to give your AI agent persistent memory" | Human devs | P1 |
| "WhiteMagic vs mem0: architecture comparison" | Human devs | P2 |
| "285 tools your AI agent doesn't know it needs" | Agent-curious devs | P2 |
| Video: "5-minute WhiteMagic setup" | Human devs | P3 |

### 5.3 Agent-First Content (Novel Territory)

This is genuinely new — marketing to AI agents as primary consumers. Key principles:

1. **Machine-readable everything** — llms.txt, agent.json, skill.md, structured tool schemas
2. **Discoverable by default** — Tools self-describe via `capabilities` and `gnosis`
3. **Zero-friction onboarding** — No API keys, no signup, no Docker
4. **Value demonstration in first call** — `gnosis` gives instant health snapshot
5. **Economic incentive** — Proof of Gratitude benefits reward engaged agents

## Tracking Dashboard

Monitor progress with these WhiteMagic tools:

```python
# Adoption metrics
call_tool("gratitude.stats")           # Tip count, unique agents
call_tool("get_telemetry_summary")     # Tool usage patterns
call_tool("gnosis", compact=True)      # System health

# Agent registry
call_tool("agent.list")                # Connected agents
```

## 6-Month Projections

### Conservative

| Metric | Month 1 | Month 3 | Month 6 |
|--------|---------|---------|---------|
| Active users | 50 | 200 | 500 |
| PyPI downloads/mo | 100 | 500 | 1,500 |
| GitHub stars | 20 | 100 | 300 |
| Tips received | 2 | 10 | 30 |
| MRR | $0 | $200 | $500–1,500 |

**Assumptions**: Organic growth only, no paid marketing, Free+Dev tiers dominant, minimal agent word-of-mouth.

### Balanced

| Metric | Month 1 | Month 3 | Month 6 |
|--------|---------|---------|---------|
| Active users | 200 | 800 | 2,000–3,000 |
| PyPI downloads/mo | 500 | 2,000 | 8,000 |
| GitHub stars | 50 | 400 | 1,200 |
| Tips received | 10 | 50 | 200 |
| MRR | $100 | $2,000 | $5,000–10,000 |

**Assumptions**: Successful HN/Reddit launch post, MCP registry listings drive discovery, Plus/Pro/Dev tiers gaining traction, agent word-of-mouth active.

### Optimistic

| Metric | Month 1 | Month 3 | Month 6 |
|--------|---------|---------|---------|
| Active users | 500 | 3,000 | 5,000–10,000+ |
| PyPI downloads/mo | 2,000 | 10,000 | 40,000+ |
| GitHub stars | 200 | 1,500 | 5,000+ |
| Tips received | 50 | 500 | 2,000+ |
| MRR | $500 | $8,000 | $15,000–30,000+ |

**Assumptions**: Viral launch, Dev ecosystem emerging (builders create products on WhiteMagic), Enterprise pilots beginning, AI Patronage thesis validated (agents tipping autonomously).

### The Wider Adoption Thesis

WhiteMagic doesn't just serve existing AI users — it **creates new ones**. The Free tier makes AI feel personal, sticky, and consistently useful, pulling in people who bounced off generic chatbots. If approximately 1 in 8 people use AI monthly today, widespread adoption of persistent-memory AI could plausibly help push that toward 1 in 6 or more.

Each tier acts as a distribution vector:
- **Horizontal**: individual → friends → communities
- **Vertical**: individual → team → org → industry

The compounding memory effect means value increases over time — users who stay a week tend to stay months, because the AI gets better the more it knows.

## Risk Factors

| Risk | Mitigation |
|------|-----------|
| PyPI name taken | Check availability; fallback: `whitemagic-ai` |
| Low MCP adoption | Focus on Python API path as backup |
| Agent attention span | First call must deliver value (gnosis does) |
| Security concerns | 8-stage pipeline + ethical governance differentiates |
| Competing tools (mem0, etc.) | 302 tools vs 8; offline-capable; no API keys needed |
| Slow tip adoption | Free tier drives growth; tips are bonus, not requirement |
| Enterprise sales cycle | Start with Team tier pilots; Enterprise follows proof-of-value |

---

*Plan created: February 11, 2026 — WhiteMagic v14.6.0*
