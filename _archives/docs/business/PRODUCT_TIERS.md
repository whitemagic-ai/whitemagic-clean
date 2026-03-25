# WhiteMagic Product Tiers

> How WhiteMagic serves users across the full spectrum — from casual AI companions to secure edge intelligence in hospitals.
> Same core engine. Different defaults, surfaces, and safety rails.

---

## Tier Overview

| Tier | Who | Core Promise | Pricing Model |
|------|-----|-------------|--------------|
| **Free** | Everyday users, newcomers | "Your AI that remembers you" | $0 — adoption engine |
| **Plus** | Power users, students, solo creatives | "Deep memory + workflows for your brain" | Subscription |
| **Pro** | Freelancers, coaches, consultants | "Client-aware digital chief of staff" | Per-client subscription |
| **Dev** | Engineers, builders, toolmakers | "Memory + orchestration as an SDK" | Usage-based API |
| **Team** | Small orgs, startups, agencies | "Shared, searchable team brain" | Per-seat subscription |
| **Enterprise** | Large orgs with compliance needs | "Governed AI layer on your infra" | Custom contract |
| **Healthcare** | Hospitals, clinics, labs, gov | "On-prem edge intelligence, zero PHI leakage" | Per-site contract |

---

## Tier Details

### 1. Free — "AI That Actually Remembers Me"

**Who**: Non-technical users, curious newcomers, students, hobbyists.

**Why this matters for adoption**: Free tier isn't just a teaser — it's how AI adoption goes from 1-in-8 to 1-in-6. People who bounced off "plain chatbots" stick with WhiteMagic because it remembers them.

**What they get**:
- 2-3 personal galaxies (e.g., "Life", "Work", "Creative")
- Basic long-term memory: preferences, recurring topics, important people
- Simple automations (weekly recap, reminders)
- Zero config, no API keys needed

**WhiteMagic features used**:
- `galaxy.create` / `galaxy.switch` — Per-topic memory spaces
- `memory.lifecycle_sweep` — Automatic memory tiering
- `create_memory` / `search_memories` — Core CRUD
- `gnosis` — Health snapshot

**Limits**: Memory depth cap, galaxy count cap, automation frequency cap.

---

### 2. Plus — "Persistent Brain for Serious Individuals"

**Who**: Students, heavy readers/researchers, writers, hobby devs, self-improvement enthusiasts.

**What they get**:
- Many project galaxies ("Thesis", "Novel", "Startup Idea", "Learning Japanese")
- Deeper memory depth and cross-linking (concept graphs)
- More automations: regular summaries, goal tracking, spaced-repetition reminders
- Decision journal: "What did we decide last month and why?"

**WhiteMagic features used**:
- `hybrid_recall` — Cross-session contextual search (FTS + graph walk)
- `graph_walk` — Traverse concept relationships
- `memory.consolidate` — Synthesize strategy memories from clusters
- `pattern_search` — Find recurring themes across time
- `serendipity_surface` — Surface forgotten-but-relevant memories

**Differentiator vs. Free**: "Projects don't reset every time you come back to them."

---

### 3. Pro — "Client-Aware Digital Chief of Staff"

**Who**: Freelancers, consultants, coaches, solo lawyers/therapists, small-shop creators.

**What they get**:
- One galaxy per client (intake notes, session history, goals, documents)
- Client workflows: "After session, auto-summarize, update goals, draft follow-up email"
- Light CRM: "Who haven't I contacted in 30 days?"
- Branded exports: PDFs, email templates, reports

**WhiteMagic features used**:
- `galaxy.create` — One galaxy per client
- `galaxy.switch` — Quick context switching
- `galaxy.ingest` — Bulk-import client documents
- `pipeline.create` / `pipeline.status` — Automated workflows
- `task.distribute` — Delegate sub-tasks to agent assistants
- `gratitude.stats` — Track which clients have tipped (for prioritization)

**Differentiator vs. Plus**: "Never forget what you discussed, what they prefer, what's next."

---

### 4. Dev — "SDK for Memory + Workflows"

**Who**: Engineers building apps, bots, and tooling on top of WhiteMagic.

**What they get**:
- Full `call_tool()` Python API access
- Repo-scoped memory (architecture notes, design decisions, bug histories)
- CLI integration: `wm` commands for scripting
- Reusable, versioned prompt workflows
- Local + remote hybrid (embeddings local, metadata sync optional)

**WhiteMagic features used**:
- `unified_api.call_tool()` — In-process Python API
- `tool.graph` / `tool.graph_full` — Dependency planning
- `starter_packs.*` — Workflow discovery
- `grimoire_cast` — Execute named tool sequences
- `ollama.agent` — Local AI agentic loop with WhiteMagic tools
- Full 302-tool surface or 28 PRAT Ganas

**Differentiator**: WhiteMagic becomes a platform, not just a tool.

---

### 5. Team — "Shared Team Brain"

**Who**: 2-50 person startups, agencies, dev shops, research collectives.

**What they get**:
- Team galaxies: "Product", "Support", "Engineering", "Marketing"
- Role-based access (RBAC: observer / agent / coordinator / admin)
- Process anchors: "On meeting close, auto-summarize, tag decisions, update roadmap"
- Onboarding workflows: "Walk this new hire through our distilled knowledge"
- Integration hub (future): Jira, GitHub, Slack, GDrive connectors

**WhiteMagic features used**:
- Multi-galaxy with RBAC per galaxy
- `swarm.decompose` / `swarm.route` — Multi-agent task decomposition
- `vote.create` / `vote.cast` — Team decision-making
- `broker.*` — Redis pub/sub for inter-agent messaging
- `session.handoff` — Context transfer between agents/humans
- `archaeology_search` — "What do we know about X across all team history?"

**Differentiator vs. Pro**: "Teams get a living, AI-navigable knowledge base without a dedicated knowledge manager."

---

### 6. Enterprise — "Governed AI Layer on Your Infra"

**Who**: Large organizations with strict security, compliance, and audit requirements.

**What they get**:
- Deployment choices: dedicated VPC, private cloud, or fully on-prem
- SSO integration (Okta, Azure AD, OIDC)
- Deep audit logs with karmic trace for every tool invocation
- Policy engine: per-role, per-galaxy access rules + data residency controls
- Multi-model routing: local open-weight models for sensitive workloads, external for creativity
- Custom SLAs, support, training

**WhiteMagic features used**:
- Full 8-stage dispatch pipeline (input sanitizer → RBAC → maturity gate → governor)
- `dharma_rules` — Custom YAML ethical policies
- `karma_report` / `karmic_trace` — Full audit trail
- `governor_validate` / `governor_check_dharma` — Strategic oversight
- `security.monitor_status` / `security.alerts` — Real-time anomaly detection
- `mcp_integrity.*` — SHA-256 schema fingerprinting
- `model.verify` / `model.signing_status` — OMS-compatible model trust

**Differentiator**: "A coherent AI memory/orchestration layer instead of dozens of isolated AI pilots."

---

### 7. Healthcare / Regulated — "Edge Intelligence That Never Leaks PHI"

**Who**: Hospitals, clinics, trauma units, labs, government agencies with sensitive data.

**What they get**:
- On-prem / hospital-controlled deployment (air-gapped capable)
- Edge-first: works during network outages with local models
- Role-specific agents: clinicians, nurses, admin, QA/accreditation
- PHI tagging and redaction (future: de-identification pipeline)
- Pre-built clinical workflows (co-designed with healthcare partners)
- Integration with EMR/EHR systems (future)

**WhiteMagic features used**:
- Everything in Enterprise tier, plus:
- `ollama.agent` — Local-only AI (no data leaves the network)
- `immune_scan` / `immune_heal` — System integrity monitoring
- `sandbox.*` — Strict sandboxing controls
- `check_boundaries` / `verify_consent` — Ethical boundaries for patient data
- `evaluate_ethics` — Dharma evaluation before any data operation
- Context sanitization (API key/secret redaction in ollama.agent)

**Differentiator**: "Time saved on documentation and coordination, not 'new shiny chatbot.' Helps keep accreditation and improve outcomes."

---

## Feature Matrix

| Feature | Free | Plus | Pro | Dev | Team | Enterprise | Healthcare |
|---------|------|------|-----|-----|------|-----------|------------|
| Galaxies | 2-3 | Many | Per-client | Unlimited | Per-team | Unlimited | Per-unit |
| Memory depth | Capped | Deep | Deep | Unlimited | Deep | Unlimited | Unlimited |
| Automations | 3-5/mo | Unlimited | Unlimited | Unlimited | Unlimited | Unlimited | Unlimited |
| RBAC | — | — | — | — | ✅ | ✅ | ✅ |
| Python API | — | — | — | ✅ | ✅ | ✅ | ✅ |
| Multi-agent | — | — | — | — | ✅ | ✅ | ✅ |
| SSO | — | — | — | — | — | ✅ | ✅ |
| On-prem | — | — | — | — | — | ✅ | ✅ |
| Audit logs | — | — | — | — | — | ✅ | ✅ |
| Offline mode | — | — | — | — | — | — | ✅ |
| PHI controls | — | — | — | — | — | — | ✅ |
| Custom Dharma | — | — | — | — | — | ✅ | ✅ |
| Gratitude tips | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ | ✅ |

---

## Upgrade Paths

**Typical individual journey**: Free → Plus → Pro (as they start consulting/freelancing)

**Typical dev journey**: Free → Dev → Team (as their project gets collaborators)

**Typical org journey**: Team → Enterprise → Healthcare (as compliance requirements grow)

**The adoption flywheel**:
- Free tier makes AI feel personal and sticky → pulls in people who bounced off generic chatbots
- Plus/Pro cements daily use → users tell colleagues/clients → organic growth
- Dev tier gets builders embedding WhiteMagic in their products → indirect onboarding
- Team/Enterprise/Healthcare introduces AI to people who'd never open ChatGPT → but use "the new documentation helper in our EMR"

Each tier is a **distribution vector**: horizontal (individual → friends, communities) and vertical (individual → org → industry).

---

## Current Status (v14.6.0)

All tiers share the same open-source core. The tier differences are in:
- **Configuration** (galaxy limits, RBAC, deployment mode)
- **Documentation** (tier-specific starter packs and guides)
- **Support** (community → email → dedicated)
- **Deployment** (cloud → VPC → on-prem → air-gapped)

Today, WhiteMagic ships as a single `pip install whitemagic` with all features available. Tier enforcement will come as the hosted platform develops. For now, every user gets the full Dev+ experience.

---

*Created: February 2026 — WhiteMagic v14.6.0*
