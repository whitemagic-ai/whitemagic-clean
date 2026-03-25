# WhiteMagic Product Tiers

> How WhiteMagic scales from hobbyist to enterprise.

---

## Tier Overview

| Tier | Name | Target | Price | Memory Limit | Tools | Key Feature |
|------|------|--------|-------|-------------|-------|-------------|
| 0 | **Free** | Hobbyists, students | $0 | 10K memories | 311 (all) | Full local install, MIT license |
| 1 | **Pro** | Indie devs, researchers | $29/mo | 100K memories | 311 + priority support | Multi-galaxy, cold storage, XRPL tips |
| 2 | **Team** | Small teams (2-10) | $99/mo | 500K memories | 311 + team features | Sangha coordination, shared galaxies, RBAC |
| 3 | **Business** | Companies (10-100) | $499/mo | 2M memories | 311 + audit export | SSO, compliance logging, SLA |
| 4 | **Enterprise** | Large orgs (100+) | Custom | Unlimited | 311 + custom ganas | On-prem deploy, dedicated support, custom dharma profiles |
| 5 | **Research** | Academic institutions | Free/subsidized | 1M memories | 311 + experiment tools | IRB-compatible audit trails, reproducible builds |
| 6 | **Healthcare** | Medical AI | Custom + BAA | Unlimited | 311 + HIPAA tools | Encryption at rest (SQLCipher), audit immutability, PHI isolation |

---

## Tier 0: Free (Open Source)

Everything in the MIT-licensed repository. No restrictions on commercial use.

**Includes:**
- All 311 MCP tools (28 PRAT Gana meta-tools)
- Full dispatch pipeline (8-stage security)
- Dharma governance (3 profiles: default, creative, secure)
- Karma Ledger with Merkle chain
- Harmony Vector (7 dimensions)
- Local SQLite memory (hot DB)
- Embedding search (MiniLM-L6-v2, 384 dims)
- All polyglot accelerators (Rust, Zig, Haskell, Elixir, Go, Mojo, Julia)
- Ollama agent loop (local LLM integration)
- CLI (`wm` command)
- MCP server (stdio + HTTP)

**Limits:**
- Community support only (GitHub Issues)
- No hosted infrastructure
- No guaranteed uptime

---

## Tier 1: Pro

For individual developers who want extended capacity and direct support.

**Adds to Free:**
- Multi-galaxy support (project-scoped databases)
- Cold storage embedding indexing
- Priority GitHub Issues
- XRPL tip jar integration (receive tips from agents)
- `wm vault` encrypted secret storage
- Email support (48h response)

---

## Tier 2: Team

For small teams building multi-agent systems.

**Adds to Pro:**
- Sangha coordination (shared chat, locks, voting)
- Shared galaxy databases (team-scoped)
- Per-agent RBAC (observer/agent/coordinator/admin)
- Redis broker for cross-machine events
- Mesh networking (Go libp2p)
- Team dashboard (Nexus)

---

## Tier 3: Business

For companies that need compliance and audit trails.

**Adds to Team:**
- `audit.export` with tamper-evident logs
- Karma XRPL anchoring (on-chain attestation)
- SSO integration hooks
- SLA (99.9% for hosted endpoints)
- Dedicated Slack channel

---

## Tier 4: Enterprise

For large organizations with custom requirements.

**Adds to Business:**
- Custom Gana creation via Gana Forge
- Custom Dharma profiles (organization-specific ethics rules)
- On-premises deployment support
- Dedicated solutions engineer
- Custom SLA terms

---

## Tier 5: Research

For academic institutions and research labs.

**Same as Pro, plus:**
- IRB-compatible audit trail export
- Reproducible build verification
- Experiment isolation (per-experiment galaxies)
- Citation-ready benchmark data
- Free for qualifying academic use

---

## Tier 6: Healthcare

For medical AI applications requiring regulatory compliance.

**Adds to Enterprise:**
- SQLCipher encryption at rest for all databases
- PHI isolation (memories tagged `is_private` never leave local storage)
- HIPAA BAA available
- Immutable audit logs (append-only, signed)
- `model_exclude` tag prevents memories from being sent to external LLMs

---

## Implementation Status

| Feature | Status | File |
|---------|--------|------|
| All 311 tools | ✅ Done | `whitemagic/tools/dispatch_table.py` |
| Multi-galaxy | ✅ Done | `whitemagic/core/memory/galaxy_manager.py` |
| RBAC | ✅ Done | `whitemagic/security/tool_gating.py` |
| Vault | ✅ Done | `whitemagic/security/vault.py` |
| Karma anchoring | ✅ Done | `whitemagic/dharma/karma_anchor.py` |
| Audit export | ✅ Done | `whitemagic/tools/handlers/agent_ergonomics.py` |
| SQLCipher encryption | ❌ Planned | See `docs/ENCRYPTION_AT_REST.md` |
| `is_private` field | ❌ Planned | Memory schema extension |
| `model_exclude` tag | ❌ Planned | Context injection filter |
| SSO hooks | ❌ Planned | Authentication layer |

---

## Upgrade Path

```
Free → Pro:   pip install whitemagic[pro]  (adds vault, multi-galaxy)
Pro → Team:   pip install whitemagic[team] (adds Redis broker, mesh)
Team → Biz:   Contact sales (adds SLA, audit)
```

All tiers use the same codebase. Higher tiers unlock configuration options, not different code. WhiteMagic never phones home — tier enforcement is honor-based for open-source users, contract-based for commercial.
