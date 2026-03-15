# WhiteMagic v15.1+ Plan — Gaps, Shortcomings & Roadmap

**Created**: Feb 12, 2026 | **Based on**: v15.0.0 release verification

---

## Critical (Fix Before v15.0.1)

### 1. PyPI Token Exposed
- **Issue**: Token was displayed in terminal output during publish setup
- **Fix**: Rotate token at https://pypi.org/manage/account/token/, update `~/.pypirc`
- **Priority**: CRITICAL — do this immediately

### 2. Test Count Discrepancy
- **Issue**: AI_PRIMARY.md claims 1,955 tests, but pytest reports 1,324 passed + 7 skipped = 1,331
- **Root cause**: ~600 tests were in files that got archived (cold_storage_embeddings, benchmarks, etc.) or are in integration/network-gated suites
- **Fix**: Audit test count, update AI_PRIMARY.md to reflect actual passing count, or restore missing test files
- **Priority**: High — misleading metric

### 3. `capabilities` Tool Shows 237, Not 313
- **Issue**: 104 tools are registered in the dispatch table but lack formal `ToolDefinition` entries in `registry_defs/`
- **Impact**: `capabilities` tool, `wm doctor`, and the MCP tool listing all report 237
- **Fix**: Create `ToolDefinition` entries for the remaining 104 tools across new registry_defs files
- **Effort**: Medium (need to write descriptions and input schemas for each)
- **Priority**: High — users see 237 but we advertise 313

### 4. `tags` Parameter UX
- **Issue**: `create_memory` requires `tags` as a JSON array `["a", "b"]`, but examples in docs and intuition suggest comma-separated strings `"a,b"` should also work
- **Fix**: Add string-to-list coercion in the `create_memory` handler: if tags is a string, split on commas
- **Effort**: 5 lines of code
- **Priority**: High — first thing new users hit

---

## Important (v15.1 Release)

### 5. CI/CD Pipeline
- **Issue**: `.github/workflows/ci.yml` exists but has never run
- **Fix**: Trigger CI, fix any failures, add badge to README
- **Includes**: pytest, cargo check, mypy (optional), secret scan
- **Priority**: High — gives confidence in every push

### 6. Cross-Compiled Seed Binaries
- **Issue**: `wm-seed` binary exists but isn't published to GitHub Releases
- **Fix**: Add a GitHub Actions workflow that cross-compiles for linux-x64, darwin-arm64, windows-x64 and attaches to releases
- **Priority**: High — WhiteMagic Lite isn't accessible without this

### 7. Fresh Install Health Score
- **Issue**: Fresh `pip install` + `wm doctor` shows "80% healthy" with 2 alerts: `homeostasis_stopped`, `temporal_scheduler_stopped`
- **Root cause**: Background services aren't started on pip install (expected), but the health check penalizes for it
- **Fix**: Don't penalize for stopped optional services on first run. Consider a "first run" vs "running" health mode
- **Priority**: Medium — bad first impression

### 8. Maturity Stage on Fresh Install
- **Issue**: Fresh install starts at `RADIANT` (stage 4/6) instead of `SEED` (stage 1/6)
- **Root cause**: The maturity assessment counts capabilities (28 ganas = high score) regardless of actual usage history
- **Fix**: Factor in memory count, session count, and age — not just capability count
- **Priority**: Medium — semantically wrong

### 9. Schema Migration Log Noise
- **Issue**: First `call_tool()` on a fresh DB prints 18 INFO lines about adding columns
- **Fix**: Suppress migration logs behind `WM_SILENT_INIT` or set them to DEBUG level
- **Priority**: Medium — noisy first experience

### 10. Documentation Site
- **Issue**: No docs.whitemagic.dev — all docs are .md files in the repo
- **Fix**: Set up MkDocs Material on GitHub Pages, auto-deploy from `docs/` folder
- **Priority**: Medium — important for discoverability

---

## Nice-to-Have (v15.2+)

### 11. Package Signing
- **Issue**: No Sigstore/cosign signing on PyPI package or GitHub releases
- **Fix**: Add `sigstore` to publish workflow, sign wheel + tarball
- **Priority**: Low — trust signal for enterprise adoption

### 12. SBOM (Software Bill of Materials)
- **Issue**: No SBOM generated
- **Fix**: `pip-audit` + CycloneDX SBOM generation in CI
- **Priority**: Low — enterprise/compliance requirement

### 13. Dependency Pinning
- **Issue**: `pyproject.toml` uses version ranges, not pins
- **Current**: Correct for a library (ranges are standard)
- **Fix**: Add `requirements-lock.txt` for reproducible builds
- **Priority**: Low

### 14. Error Message Quality
- **Issue**: Error messages like "invalid type for 'tags': expected array" don't suggest the fix
- **Fix**: Improve error messages to include suggestions: "Expected list, got string. Try: tags=['a', 'b']"
- **Priority**: Low — quality of life

### 15. x402 Endpoint
- **Issue**: Not implemented (Phase 3 of economic strategy)
- **Fix**: Add HTTP 402 middleware to Nexus API server
- **Requires**: Base L2 wallet address, USDC contract integration
- **Priority**: Low — future revenue, not blocking release

### 16. Workflow Templates as MCP Resources
- **Issue**: `whitemagic/workflows/` has 6 .md files but they aren't exposed as MCP resources
- **Fix**: Register them as `whitemagic://workflow/{name}` resources
- **Priority**: Low

### 17. Cold DB Embedding Indexing
- **Issue**: Script was archived, functionality may be bitrotting
- **Fix**: Either restore and maintain, or remove references
- **Priority**: Low — nice feature but not core

### 18. Web Research Fragility
- **Issue**: DuckDuckGo HTML scraping can break if DDG changes their HTML
- **Fix**: Add fallback search providers, or use an API-based search
- **Priority**: Low — works now but fragile

---

## Distribution Gaps

### 19. MCP Registry Submissions
- **Status**: Not submitted yet
- **Targets**: Anthropic official registry, PulseMCP, Gradually AI
- **Fix**: Submit to all three with correct metadata
- **Priority**: High for visibility

### 20. OpenClaw Skill
- **Status**: `skill.md` exists in repo
- **Fix**: Submit to ClawHub
- **Priority**: Medium

### 21. Docker Hub / GHCR
- **Status**: Dockerfile exists, untested (no Docker on dev machine)
- **Fix**: Build + push images from CI, test locally with Docker
- **Priority**: Medium

### 22. A2A Agent Card
- **Status**: `.well-known/agent.json` exists
- **Fix**: Verify it's served correctly when hosted
- **Priority**: Low

---

## Security Audit Checklist

| Item | Status | Notes |
|------|--------|-------|
| No secrets in repo | ✅ | Verified via grep scan |
| PyPI token rotation | ❌ | Token exposed, needs rotation |
| Input sanitization | ✅ | 8-stage pipeline active |
| Rate limiting | ✅ | Rust atomic pre-check |
| RBAC | ✅ | 4 roles configured |
| SQLCipher encryption | ✅ | Available via WM_DB_PASSPHRASE |
| Dependency audit | ❌ | No `pip-audit` in CI |
| Package signing | ❌ | No Sigstore |
| SBOM | ❌ | No CycloneDX |
| CI secret scanning | ❌ | ci.yml untested |

---

## Effort Estimates

| Priority | Items | Total Effort |
|----------|-------|-------------|
| **Critical** (v15.0.1) | #1-4 | 1-2 days |
| **Important** (v15.1) | #5-10 | 1-2 weeks |
| **Nice-to-have** (v15.2+) | #11-22 | Ongoing |

---

## Suggested Release Cadence

- **v15.0.1** — Fix critical items (tags coercion, test count, token rotation). Same week.
- **v15.1.0** — CI/CD, seed binary releases, ToolDefinition completeness, health score fixes. 2 weeks.
- **v15.2.0** — "The Sovereign" — Agent Economy features: Sovereign Sandbox (shelter.* tools), OMS export/import (.mem format), Karma Transparency Log. See `docs/V15_2_AGENT_ECONOMY.md`. 1-2 months.
- **v15.2.1** — "The Merchant" — ILP streaming payments, earnings dashboard. +2-3 weeks.
- **v15.2.2** — "The Bazaar" — Marketplace bridge, auto-bid policy engine. +3-4 weeks.
- **v16.0.0** — WASM universal portability + multi-agent production. 2-3 months after v15.2.
