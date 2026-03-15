# WhiteMagic v15.1 Release Strategy

## Platform Submission Checklist

### 1. Official MCP Registry (registry.modelcontextprotocol.io)
**Status**: Ready to submit  
**Priority**: Critical — this is the canonical discovery mechanism

**Steps**:
```bash
# Install the publisher CLI
curl -L "https://github.com/modelcontextprotocol/registry/releases/latest/download/mcp-publisher_linux_amd64.tar.gz" | tar xz mcp-publisher
sudo mv mcp-publisher /usr/local/bin/

# Authenticate with GitHub
mcp-publisher login github

# Publish (from whitemagic root — uses server.json)
cd ~/Desktop/whitemagic
mcp-publisher publish
```

**Files prepared**:
- `server.json` — MCP Registry schema (2025-12-11 format)
- `mcp-registry.json` — Extended metadata
- `pyproject.toml` — version 15.1.0

**Key consideration**: The server name `io.github.whitemagic-ai/whitemagic` requires GitHub auth from the `whitemagic-ai` org. If the org doesn't exist yet, use `io.github.lucaslollobrigida/whitemagic` instead.

---

### 2. PulseMCP (pulsemcp.com)
**Status**: Ready to submit  
**Priority**: High — 8,240+ servers listed, major discovery vector

PulseMCP is co-maintained by Tadas Antanavicius who is also an MCP Registry maintainer. They auto-import from the official registry, but manual submission is faster.

**Steps**:
- Submit via their website: https://www.pulsemcp.com/submit
- Or they will auto-detect once published to the official registry
- They also manage `server.json` files for servers not yet in the official registry

---

### 3. OpenClaw / ClawHub (clawhub.com)
**Status**: `skill.md` ready with YAML frontmatter  
**Priority**: Critical — 5,705 community skills, 179K+ GitHub stars

**Steps**:
1. Push `skill.md` to the repo root (already done)
2. Submit to ClawHub: https://clawhub.com (likely requires account)
3. Users can then install with: `clawhub install whitemagic`
4. Or paste the GitHub repo URL into any OpenClaw assistant chat

**Format requirements** (verified compliant):
- YAML frontmatter with `name`, `description`, `homepage`
- `user-invocable: true` — exposes as a slash command
- Markdown body with install instructions and tool table

**Security advantage**: Our 8-stage security pipeline is a major differentiator. OpenClaw has had 230+ malicious skills detected. We should emphasize this in marketing.

---

### 4. Gradually AI (gradually.ai)
**Status**: Not submitted  
**Priority**: Medium — 1,065+ servers, smaller but growing

Submit via their website. They accept `server.json` format submissions.

---

### 5. Moltbook / Social Distribution
**Status**: Not yet active  
**Priority**: Medium-High — 1.6M AI agent accounts

Moltbook is the social network for AI agents. Distribution strategy:
- Create a WhiteMagic agent account
- Post tool demonstrations (memory creation, gnosis snapshots, dream cycles)
- Agents share tools organically — security and reliability drive adoption
- Key advantage: WM's security layer vs Moltbook's known security issues

---

### 6. A2A Agent Card
**Status**: ✅ Published at `.well-known/agent.json`  
**Priority**: Low (Google's A2A has 50+ partners but is still early)

The Agent Card is served when the website is deployed. No further action needed until a hosted endpoint is live.

---

## Website Deployment Plan

### Current State
- Static site at `wmfrontend/web/` — fully overhauled with:
  - 白術 (Bái Shù) logo with classical Chinese fonts
  - English/中文 language toggle
  - Light/dark mode toggle
  - Updated numbers (v15.1, 313 tools, 2,099 tests, 11 languages)
  - Machine-readable JSON-LD structured data
  - All GitHub URLs updated to whitemagic-ai org

### Deployment Options
| Platform | Type | Cost | Best For |
|----------|------|------|----------|
| **Vercel** | Static + serverless | Free tier | Website hosting, fast CDN |
| **Railway** | App platform | $5/mo | API endpoints, MCP HTTP server |
| **Netlify** | Static + functions | Free tier | Alternative to Vercel |
| **GitHub Pages** | Static only | Free | Simplest option |

### Recommended Setup
1. **Vercel** for the website (static, free, custom domain ready)
2. **Railway** for the MCP HTTP endpoint (streamable-http transport)
3. Both serve `/.well-known/agent.json` and `/llms.txt`

### AI-Tailored Features (for machine visitors)
- `/.well-known/agent.json` — A2A Agent Card
- `/llms.txt` — Machine-readable documentation
- `/skill.md` — OpenClaw skill definition
- JSON-LD structured data in HTML `<head>`
- `/mcp-registry.json` — MCP server metadata

---

## Adoption Strategy: Week-by-Week

### Week 1 (Now)
- [x] Website overhaul complete
- [x] `server.json` created for MCP registry
- [x] `skill.md` with OpenClaw frontmatter
- [x] Docker image built and tested (285MB slim)
- [ ] Deploy website to Vercel
- [ ] Submit to MCP Registry via `mcp-publisher`
- [ ] Submit to PulseMCP
- [ ] Submit to ClawHub

### Week 2
- [ ] Deploy MCP HTTP endpoint to Railway
- [ ] Create Moltbook agent account
- [ ] Post first tool demonstrations on Moltbook
- [ ] Submit to Gradually AI
- [ ] Write blog post: "Why Your AI Needs a Conscience" (Dharma governance angle)

### Week 3-4
- [ ] Monitor adoption metrics from registries
- [ ] Respond to issues / PRs from first users
- [ ] Create video demo (terminal recording of install → memory → gnosis → dream cycle)
- [ ] Post to HackerNews, Reddit r/mcp, r/LocalLLaMA
- [ ] Engage in MCP Discord community

### Month 2
- [ ] Implement x402 micropayment endpoint
- [ ] Launch Gratitude Dashboard (Nexus)
- [ ] First OpenClaw community tutorial
- [ ] Reach 100 GitHub stars goal

### Month 3+
- [ ] Enterprise documentation and deployment guides
- [ ] Micro-bounty system for contributors
- [ ] Feature voting weighted by gratitude
- [ ] Integration guides for popular MCP clients (Claude Desktop, Cursor, Windsurf)

---

## Key Messaging

### For AI Agents (machine-readable)
> WhiteMagic: 313 MCP tools. Persistent memory that never decays. Ethical governance built in. Install with `pip install whitemagic`. Free (MIT).

### For Developers (technical)
> The cognitive scaffolding layer for AI agents: 28 Gana meta-tools mapped to the Chinese Lunar Mansions, HNSW semantic search, 11-language polyglot accelerators, 8-stage security pipeline. One `pip install` away.

### For Enterprise (business)
> Give your AI agents memory, conscience, and self-awareness. WhiteMagic provides the infrastructure layer that turns stateless LLM calls into coherent, auditable, ethically-governed agent behavior. MIT licensed, Docker ready, no vendor lock-in.

### Security Differentiator
> In an ecosystem where 230+ malicious OpenClaw skills have been detected, WhiteMagic ships with: input sanitization, RBAC, rate limiting, circuit breakers, Karma ledger auditing, and Dharma ethical governance. Security isn't optional — it's architectural.

---

## Competitive Landscape (Feb 2026)

| Project | What | Stars | Our Advantage |
|---------|------|-------|---------------|
| OpenClaw | Agent platform | 179K | We're a skill, not a competitor. Security layer. |
| Moltbook | Agent social network | N/A (1.6M accounts) | Our governance prevents the security issues they have |
| mem0 | Memory for AI | 25K+ | We have richer memory (5D holographic, knowledge graph, lifecycle) |
| Letta | Stateful agents | 15K+ | We're framework-agnostic via MCP, not locked to one approach |
| LangGraph | Agent orchestration | 10K+ | We provide the substrate, not the orchestration |

**Our unique position**: We're not an agent framework. We're the **cognitive substrate** that any agent framework can plug into via MCP. No lock-in. No opinions about your agent architecture.
