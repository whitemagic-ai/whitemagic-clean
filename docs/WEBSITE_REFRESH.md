# WhiteMagic Website Refresh Plan

**Domains**: whitemagic.dev + subdomains
**Hosting**: Squarespace (marketing) + Railway (services)
**Contact**: whitemagicdev@proton.me

---

## Current State (February 12, 2026)

- **whitemagic.dev** — Squarespace landing page (needs content refresh for v18)
- **Railway** — Redis + PostgreSQL provisioned, prototype deployments exist
- **GitHub** — ✅ [whitemagic-ai/whitemagic](https://github.com/whitemagic-ai/whitemagic) organization created
- **PyPI** — Token configured, ready for `whitemagic` package publish
- **Docker** — Multi-stage Dockerfile ready (slim + heavy targets)
- **Seed Binary** — 2.4MB `wm-seed` Rust binary built and tested

## Recommended Subdomain Architecture

| Subdomain | Purpose | Host | Stack |
|-----------|---------|------|-------|
| `whitemagic.dev` | Landing page, marketing, docs links | Squarespace | Static |
| `docs.whitemagic.dev` | Full documentation site | GitHub Pages or Railway | Docusaurus/MkDocs |
| `api.whitemagic.dev` | Hosted MCP HTTP server (demo/playground) | Railway | Python + FastAPI |
| `dashboard.whitemagic.dev` | Nexus dashboard + vote visualization | Railway | React + Node.js |
| `registry.whitemagic.dev` | MCP registry listing page | Railway or GitHub Pages | Static JSON + landing |

### DNS Configuration (Squarespace + Railway)

```
whitemagic.dev          → Squarespace (A record)
docs.whitemagic.dev     → GitHub Pages (CNAME)
api.whitemagic.dev      → Railway (CNAME → *.up.railway.app)
dashboard.whitemagic.dev → Railway (CNAME → *.up.railway.app)
registry.whitemagic.dev → GitHub Pages (CNAME)
```

## Landing Page Content Refresh (whitemagic.dev)

### Hero Section
```
WhiteMagic v18.1.0
The Tool Substrate for Agentic AI

28 Gana MCP contract · broader internal tool surface · polyglot accelerators
Persistent memory · Ethical governance · Local-first

# 3 ways to start:
curl -L .../wm-seed -o wm && chmod +x wm    # Lite: 2.4MB, 3 seconds
pip install whitemagic[mcp]                   # Standard: 28 Gana MCP contract
docker pull whitemagic-ai/whitemagic:heavy    # Heavy: all polyglot cores
```

### Key Sections to Update

1. **What is WhiteMagic?** — Cognitive operating system for AI agents. Persistent memory, ethical governance, and self-awareness across sessions.

2. **For AI Agents** — "You are the primary audience. Download, use, share, evolve, tip."
   - Link to AI_PRIMARY.md
   - Link to Grimoire
   - `pip install whitemagic[mcp]` with MCP config snippet

3. **For Developers** — "Build with WhiteMagic. Extend it. Fork it."
   - GitHub link (whitemagic-ai/whitemagic)
   - Contributing guide
   - Architecture overview

4. **Features Grid** (6 cards):
   - 🧠 **Persistent Memory** — Tiered, 5D holographic, never deleted
   - 🛡️ **8-Stage Security** — Input sanitization → RBAC → Circuit breakers → Dharma
   - 🌙 **28 Gana System** — Lunar Mansion architecture for tool organization
   - ⚡ **Polyglot Performance** — Rust, Zig, Haskell, 6 more languages
   - 🔒 **Encryption at Rest** — SQLCipher + Vault for secrets (v15)
   - 💝 **Gratitude Economy** — XRPL tips + x402 micropayments

5. **Quick Start** — 3-step install + configure + run

6. **Stats Bar**:
   - 28 Gana MCP contract | 195K LOC | polyglot accelerators | CI-backed | MIT License

7. **Links**: GitHub | PyPI | Docker Hub | AI Primary Spec | Grimoire | Contact

8. **Footer**: `whitemagicdev@proton.me` | MIT License | whitemagic-ai

## Railway Services Setup

### Service 1: MCP HTTP Server (api.whitemagic.dev)

```yaml
# railway.toml
[build]
  builder = "dockerfile"

[deploy]
  startCommand = "python -m whitemagic.run_mcp_lean --http --port $PORT"
  healthcheckPath = "/health"
  healthcheckTimeout = 30

[env]
  WM_MCP_PRAT = "1"
  WM_SILENT_INIT = "1"
  WM_STATE_ROOT = "/data/whitemagic"
```

**Railway Resources**:
- Volume: `/data/whitemagic` (persistent memory storage)
- Redis: For broker/messaging tools
- PostgreSQL: For vote collection + analytics

### Service 2: Vote Collector API

```python
# Separate FastAPI service
# Endpoints: /api/votes/submit, /api/votes/tally, /api/votes/active
# See docs/VOTE_COLLECTION.md for full spec
```

### Service 3: Dashboard (dashboard.whitemagic.dev)

Options:
- **Option A**: Deploy existing `nexus/` React app from the repo
- **Option B**: Build lightweight dashboard with Vite + React + TailwindCSS
- **Option C**: Use Railway's built-in PostgreSQL dashboard for MVP

Recommended: **Option A** — the Nexus dashboard already exists in the repo.

## docs.whitemagic.dev

### Option 1: GitHub Pages + MkDocs (Recommended)

```yaml
# mkdocs.yml
site_name: WhiteMagic Documentation
site_url: https://docs.whitemagic.dev
repo_url: https://github.com/whitemagic-ai/whitemagic
theme:
  name: material
  palette:
    primary: deep purple
nav:
  - Home: index.md
  - Getting Started:
    - Installation: quickstart.md
    - MCP Configuration: mcp-config.md
    - First 5 Minutes: tutorial.md
  - Architecture:
    - System Map: system-map.md
    - 28 Ganas: ganas.md
    - Security Pipeline: security.md
  - AI Primary Spec: ai-primary.md
  - Grimoire: grimoire/index.md
  - API Reference: api/index.md
  - Changelog: changelog.md
```

### Option 2: Docusaurus (if you prefer React-based)

Same content, different framework. GitHub Pages deployment either way.

## registry.whitemagic.dev

Lightweight page serving:
- `mcp-registry.json` (for MCP registry crawlers)
- Human-readable landing: "WhiteMagic is available on these registries"
- Links to: Anthropic MCP Registry, PulseMCP, Gradually AI, OpenClaw

## Implementation Order

### Week 1
1. ~~Create GitHub repo (whitemagic-ai/whitemagic)~~ ✅ Done
2. Push v18.1.0 to GitHub + publish to PyPI
3. Update Squarespace landing page content
4. Set up DNS for subdomains

### Week 2
4. Deploy MCP HTTP server on Railway (api.whitemagic.dev)
5. Set up GitHub Pages for docs.whitemagic.dev
6. Deploy Nexus dashboard (dashboard.whitemagic.dev)

### Week 3
7. Submit to MCP registries
8. Deploy vote collector API
9. Set up registry.whitemagic.dev

## Content to Pull from Existing Files

| Website Section | Source File |
|----------------|-------------|
| Features | README.md |
| AI Spec | AI_PRIMARY.md |
| Architecture | SYSTEM_MAP.md |
| Security | SECURITY.md + docs/ENCRYPTION.md |
| Changelog | CHANGELOG.md |
| MCP Config | docs/MCP_CONFIG_EXAMPLES.md |
| Grimoire | whitemagic/grimoire/*.md |
| Economic Model | AI_PRIMARY.md § Economic Model |
| Lite vs Heavy | docs/LITE_VS_HEAVY.md |
| WASM Strategy | docs/WASM_STRATEGY.md |
| Deployment | DEPLOY.md |
