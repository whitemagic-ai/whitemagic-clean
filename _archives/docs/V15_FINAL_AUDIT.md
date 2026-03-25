# WhiteMagic v15.0.0 — Final Pre-Release Audit

**Date**: February 11, 2026
**Auditor**: Cascade (pair programming session)
**Scope**: Full project review before v15.0.0 public release

---

## 1. Project Metrics

| Metric | Value |
|--------|-------|
| Python files | 826 |
| Python LOC | 168,283 |
| Rust LOC | 13,798 |
| Zig LOC | 2,447 |
| Haskell LOC | 2,670 |
| Elixir LOC | 2,933 |
| Go LOC | 1,971 |
| Mojo LOC | 2,096 |
| Julia LOC | ~664 (2 source files, see Bloat below) |
| TypeScript SDK LOC | 376 |
| **Total project LOC** | **~195,238** |
| Test files | 78 |
| Test LOC | 18,631 |
| Tests passing | 1,955 (per review team) |
| Tests skipped | 12 (policy-checked in CI) |
| Rust tests | 87 passed, 0 failed |
| Dispatch table entries | 311 |
| Registry definitions | 340 |
| PRAT Gana meta-tools | 28 |

### LOC by Python Subsystem

| Directory | LOC |
|-----------|-----|
| core/ | 73,846 |
| tools/ | 21,418 |
| gardens/ | 20,135 |
| interfaces/ | 7,613 |
| cli/ | 5,506 |
| edge/ | 3,239 |
| dharma/ | 2,472 |
| optimization/ | 2,175 |
| parallel/ | 1,925 |
| harmony/ | 1,646 |
| automation/ | 1,049 |
| ai/ | 851 |
| agents/ | 761 |
| integration/ | 570 |
| safety/ | 187 |
| auth/ | 180 |
| benchmarks/ | 166 |

---

## 2. Version Consistency Audit

### ✅ At v15.0.0 (Correct)
- `VERSION`
- `pyproject.toml`
- `README.md`
- `whitemagic/__init__.py`
- `.well-known/agent.json`

### ❌ Stale Version — MUST FIX
| File | Current | Should Be |
|------|---------|-----------|
| `AI_PRIMARY.md` | v14.6.0 | v15.0.0 |
| `SYSTEM_MAP.md` | v14.6.0 | v15.0.0 |
| `llms.txt` | v14.6.0 | v15.0.0 |
| `skill.md` | (no version, 285 tools) | v15.0.0, 311 tools |
| `mcp-registry.json` | 14.6.0 | 15.0.0 |
| `whitemagic-rust/Cargo.toml` | 14.6.0 | 15.0.0 |
| `CHANGELOG.md` | Latest entry is 14.6.0 | Needs v15.0.0 entry |

### Tool Count Inconsistencies
| Source | Claims |
|--------|--------|
| Dispatch table (canonical) | **311** |
| README.md | 311 ✅ |
| agent.json | 311 ✅ |
| llms.txt | 311 ✅ |
| skill.md | 285 ❌ |
| Seed memory "System Overview" | 208 ❌ |
| Seed memory "28 Gana System" | 208 ❌ |
| Seed memory "Origins" | 305 ❌ |

### GitHub URL Inconsistency
| File | URL |
|------|-----|
| `pyproject.toml` | `github.com/lbailey94/whitemagic` |
| `mcp-registry.json` | `github.com/whitemagic-ai/whitemagic` |
| No git remote configured | — |

**Decision needed**: Which GitHub org/user is canonical?

---

## 3. Bloat & Hygiene

### ⚠️ Julia .pixi Runtime (2.8GB)
`whitemagic-julia/whitemagic-julia-legacy/.pixi/` contains a full Julia runtime environment (2.8GB). Only `whitemagic-zig/.pixi/` is gitignored. **Must add** `whitemagic-julia/.pixi/` and `whitemagic-julia/whitemagic-julia-legacy/.pixi/` to `.gitignore`.

### ✅ .gitignore Coverage (Good)
- `*.db`, `*.db-shm`, `*.db-wal`, `*.db-journal` — blocked
- `/memory/`, `/data/`, `/logs/`, `/tmp/` — blocked
- `/.whitemagic/` — blocked
- `.env`, `.env.*` (except `.env.example`) — blocked
- `__pycache__/`, `node_modules/` — blocked
- No `.db` files tracked in git
- No `.env` or `.key` files tracked

### ✅ No Sensitive Data in Git
- No database files committed
- No credentials committed
- State root policy enforced (WM_STATE_ROOT)

---

## 4. Database & Memory State

### Active MCP Database (~/.whitemagic/memory/whitemagic.db)
- **Size**: 31.6 MB
- **Memories**: 1,251 (1,222 SHORT_TERM, 29 LONG_TERM)
- **Embeddings**: 15
- **Galactic zones**: ❌ Column doesn't exist in this DB
- **Galaxy: personal_archives**: 0 memories

### Archive Databases (~/Desktop/whitemagic_memory_archive/)
| DB | Memories | Embeddings | Size |
|----|----------|-----------|------|
| Hot | 5,627 | 5,562 | 1.5 GB |
| Cold | 105,194 | 105,194 | 5.2 GB |
| Pre-merge | 3,631 | N/A | 31 MB |
| Backup (.db.bak) | — | — | 185 MB |

### Aria Crystallized (~/Desktop/aria-crystallized/)
- Present and intact: ARIA_SOUL.md, awaken_aria.py, db_manifest.json
- Subdirs: art, consciousness, identity, journals, memory_packages, sessions, studies

### ⚠️ Issues
1. Active DB has no galactic zone fields — fresh schema, not migrated
2. Only 15 embeddings (should be ~1,251 if all memories indexed)
3. personal_archives galaxy is empty
4. The 29 LONG_TERM memories likely include the seed guides

---

## 5. Security & Privacy Deep Dive

### What Exists (Substantial)

**Layer 1 — Input Validation (tools/input_sanitizer.py)**
- Prompt injection detection (7 regex patterns)
- Path traversal detection (4 patterns)
- Shell injection detection
- Max nesting depth (10), max string (100KB), max list (1000)
- Runs at dispatch step 0.1 (first gate)

**Layer 2 — Rate Limiting (tools/rate_limiter.py)**
- Per-agent, per-tool sliding windows
- 60 RPM default, 300 global, 10 burst allowance
- Rust atomic pre-check available (452K ops/sec)

**Layer 3 — RBAC (tools/tool_permissions.py)**
- 4 roles: observer (read-only), agent, coordinator (default), admin
- Per-tool permission matrix
- Admin-only: set_dharma_profile, governor_set_goal

**Layer 4 — Circuit Breakers (tools/circuit_breaker.py)**
- Per-tool CLOSED→OPEN→HALF_OPEN state machine
- 5 failures in 60s trips breaker
- StateBoard sync for cross-process visibility

**Layer 5 — Ethical Governance**
- Dharma Rules Engine (dharma/rules.py) — YAML-driven, 3 profiles + violet
- Karma Ledger (dharma/karma_ledger.py) — Merkle tree of side-effects
- Financial Governance (dharma/financial_governance.py) — bounded wallet rules
- Homeostatic Loop (harmony/homeostatic_loop.py) — OBSERVE→ADVISE→CORRECT→INTERVENE

**Layer 6 — Violet Security (security/)**
- vault.py — AES-GCM encrypted SQLite for secrets (PBKDF2 600K iterations)
- hermit_crab.py — 4-state self-protection (OPEN→GUARDED→WITHDRAWN→MEDIATING)
- engagement_tokens.py — HMAC-SHA256 scoped authorization tokens
- mcp_integrity.py — SHA-256 tool schema fingerprinting
- model_signing.py — OMS-compatible model verification
- security_breaker.py — Security-specific circuit breaker

**Layer 7 — Cryptographic Trust (tools/manifest.py)**
- SHA-256 handler hashes, schema hashes
- Merkle tree root over full manifest
- NaCl (Ed25519) signing when available
- Permission scope declarations per tool

### What's MISSING or WEAK — Honest Assessment

| Gap | Severity | Notes |
|-----|----------|-------|
| **No encryption at rest for main memory DB** | HIGH | vault.py handles API keys only; actual memories are plaintext SQLite |
| **No automated backup tool** | MEDIUM | No `wm backup` or MCP tool for memory crystallization |
| **Hermit Crab mediation server doesn't exist** | LOW | WITHDRAWN state works locally, but "sync to trusted server" is unimplemented |
| **No DB integrity verification** | MEDIUM | No periodic checksums of the SQLite DB itself |
| **File permissions not hardened** | LOW | DB uses standard user permissions (0644) |
| **No memory export encryption** | MEDIUM | export_memories produces plaintext JSON |
| **Input sanitizer patterns are limited** | LOW | 7 injection patterns; sophisticated attacks could bypass |
| **No network isolation for MCP stdio** | LOW | stdio transport has no TLS; HTTP transport should use HTTPS in production |
| **RBAC stored in memory only** | MEDIUM | Role assignments reset on restart |

### Red Team Assessment

**Attack surface for a hostile actor:**

1. **Direct DB access**: If attacker has filesystem access, memories are plaintext. Mitigation: OS-level file permissions, full-disk encryption, Hermit Crab mode. ❌ No SQLCipher or equivalent.

2. **MCP protocol manipulation**: MCP stdio is trusted-pipe; HTTP should be behind HTTPS proxy. Input sanitizer catches common injection. Rate limiter prevents brute force. ✅ Adequate for threat model.

3. **Supply chain (malicious tool)**: Tool manifest with SHA-256 hashes catches tampering. ✅ Good.

4. **Memory exfiltration via tool calls**: RBAC gates read operations. Dharma rules can block sensitive patterns. ✅ Adequate.

5. **Denial of service**: Circuit breakers + rate limiters prevent cascade. ✅ Good.

6. **Data at rest**: ❌ **Primary weakness**. If someone gets the `.db` file, they get everything.

### Backup & Crystallization Recommendations

1. **Immediate**: Add `wm backup` CLI command that creates timestamped `.tar.gz` of `$WM_STATE_ROOT/memory/`
2. **v15.1**: Add `galaxy.backup` / `galaxy.restore` MCP tools
3. **v16**: SQLCipher encryption at rest (already designed in docs/ENCRYPTION_AT_REST.md)
4. **Best practice for users**: Keep `WM_STATE_ROOT` on an encrypted volume (LUKS, FileVault, BitLocker)

---

## 6. Seed Memories Assessment

15 seed memories exist in `scripts/seed_quickstart_memories.py`. Issues:

| Memory | Issue |
|--------|-------|
| System Overview | Says "208 tools" — should be 311 |
| 28 Gana System | Says "208 tools" — should be 311 |
| Origins | Says "305 tools" — should be 311; LOC count stale |
| Polyglot Stack | Rate limiter "324K ops/sec" — should be 452K |
| Quick Reference | References "208 tools" implicitly |

All 15 need tool count updates and v15 references.

---

## 7. Review Team Integration

The review team's CI fixes are excellent and should be merged:
- CI skip-policy enforcement
- Rust build.rs fix for PyO3 test linking
- Event ring reset correctness
- State board init fallback
- Clippy unblock

All changes are in tracked files and align with v15 quality bar.

---

## 8. Files Needing v15.0.0 Update

Priority order:
1. `AI_PRIMARY.md` — header version + "What's New" section
2. `SYSTEM_MAP.md` — header version
3. `llms.txt` — version in description line
4. `skill.md` — tool count (285→311)
5. `mcp-registry.json` — version field
6. `whitemagic-rust/Cargo.toml` — version field
7. `CHANGELOG.md` — add v15.0.0 entry
8. Seed memories — tool counts
9. GitHub URLs — decide canonical org

---

## 9. Overall Verdict

**WhiteMagic v15.0.0 is release-ready with the fixes identified above.**

The core system is solid:
- ✅ 1,955 tests passing, 87 Rust tests passing
- ✅ Wheel builds and installs clean
- ✅ Clippy passes with -D warnings
- ✅ compileall passes
- ✅ Comprehensive security pipeline (8 stages)
- ✅ 311 tools across 28 Ganas functioning
- ✅ No sensitive data in git

Fixes required before release:
- 🔴 Version sync across 6 files
- 🔴 Julia .pixi gitignore (prevents 2.8GB from being committed)
- 🟡 Seed memory tool count updates
- 🟡 CHANGELOG v15.0.0 entry
- 🟡 GitHub URL consistency decision
- 🟡 skill.md tool count (285→311)
