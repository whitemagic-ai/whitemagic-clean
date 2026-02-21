# v15.7 Morning Plan — "The Launch"

**Date:** 2026-02-13
**Goal:** Get WhiteMagic into people's hands. The code is ready — ship it.

---

## Where We Are After v15.6.0

| Metric | Value |
|--------|-------|
| Dispatch tools | 356 |
| Registry defs | 384 (100% coverage) |
| PRAT Ganas | 28 (all mapped) |
| Unit tests | 1,362 (1,343 pass, 12 skip, 4 env-only) |
| Ruff findings | 0 |
| Checklist verified | ~85% (28/28 Ganas, all subsystems except Dashboard/Nexus deploy) |
| Remaining TODOs | 32 across 13 files (mostly aspirational in autonomous executor) |

### Category Completion After v15.6

| Cat | Domain | Status |
|-----|--------|--------|
| 1 | Distribution & GTM | **0% — biggest gap, all tonight's focus** |
| 2 | Code Quality | **~85%** — ruff clean, tests green, registry 100%, checklist mostly verified |
| 3 | Research Ideas | **Core 4/9 done** — reranker, working memory, reconsolidation, community |
| 4 | WASM & Portability | **30%** — WASM funcs added, .wasm binaries exist, no npm/browser SDK yet |
| 5 | Multi-Agent | **Future** — post-v16 |
| 6 | Frontend | **In progress** — Lucas building wmfrontend/web/ landing page |

---

## v15.7 Morning Steps (Priority Order)

### Phase 1: Ship to PyPI (30 min)

1. **Verify `pyproject.toml`** — version 15.6.0, all metadata correct, classifiers current
2. **Build sdist + wheel**: `python -m build`
3. **Test install in clean venv**: `pip install dist/whitemagic-15.6.0-py3-none-any.whl`
4. **Verify MCP starts**: `WM_MCP_PRAT=1 python -m whitemagic.run_mcp` in test venv
5. **Upload to PyPI**: `twine upload dist/*` (needs PyPI token — `PYPI_TOKEN`)
6. **Verify**: `pip install whitemagic[mcp]` from PyPI

### Phase 2: Docker Publish (20 min)

1. **Build slim image**: `docker build -t whitemagic-ai/whitemagic:15.6.0 -t whitemagic-ai/whitemagic:latest .`
2. **Test**: `docker run --rm whitemagic-ai/whitemagic:15.6.0 python -m whitemagic.run_mcp_lean --help`
3. **Push to GHCR**: `docker push ghcr.io/whitemagic-ai/whitemagic:15.6.0`
4. **Push to Docker Hub** (if account exists)

### Phase 3: GitHub Release (15 min)

1. **Tag**: `git tag v15.6.0 && git push origin v15.6.0`
2. **Trigger `seed-binaries.yml`** — cross-compiled wm-seed for linux-x64, macos-arm64, macos-x64
3. **Create GitHub Release** with CHANGELOG entry as body
4. **Attach seed binaries** to release

### Phase 4: MCP Registry Submissions (20 min)

1. **Anthropic MCP Registry** — submit `server.json` (already formatted)
2. **PulseMCP** — submit listing
3. **Gradually AI** — submit listing
4. **OpenClaw** — verify `skill.md` and `.well-known/agent.json`

### Phase 5: docs.whitemagic.dev (45 min)

1. **MkDocs Material setup**: `pip install mkdocs-material`
2. **Create `mkdocs.yml`** in repo root:
   - Navigation from existing `docs/` markdown files
   - API reference from `docs/reference/API_REFERENCE.md`
   - Architecture from `docs/reference/ARCHITECTURE.md`
   - Quickstart from `AI_PRIMARY.md`
3. **GitHub Pages deploy**: `mkdocs gh-deploy` or GitHub Actions workflow
4. **DNS**: CNAME `docs.whitemagic.dev` → `whitemagic-ai.github.io`

### Phase 6: Version Sync & Polish (15 min)

1. **Update `AI_PRIMARY.md`** — tool count 313→356, version 15.1→15.6
2. **Update `RELEASE_NOTES.md`** — add v15.6 section
3. **Update `pyproject.toml` description** — 313→356 tools
4. **Bump to v15.7.0-dev** after shipping

---

## Remaining Category 2 Work (Optional for v15.7)

These are lower priority since the codebase is functional:

- **Triage 32 remaining TODOs** — most are in `objective_generator.py` (28) and `continuous_executor.py` (9). These are aspirational "someday" items, not broken stubs. Options:
  - Archive as `# FUTURE:` comments
  - Convert to GitHub Issues
  - Implement the important ones (dynamic prioritization, error recovery)
- **mypy strict** on `whitemagic/core/` — optional quality gate
- **Workflow Templates** — `mcp_workflows` module not found, may need wiring
- **Activation Sequence** — run the 30-step verification sequence from the checklist

## Remaining Category 3 Work (v15.8+)

- **Multimodal intake** (PDF via PyMuPDF, DOCX, images via CLIP/BLIP-2, audio via Whisper) — highest impact remaining research item
- **Compiled dispatch pipeline** (single Zig/Rust FFI call) — performance optimization
- **Karma XRPL anchoring** — wire Merkle root to XRPL testnet
- **GPU acceleration** — future

## Category 6: Frontend (Parallel Track)

Lucas is actively building `wmfrontend/web/` (canvas-based landing page with galaxy bg + matrix rain). This is independent of the distribution push. Key frontend targets:

- `whitemagic.dev` — landing page (what Lucas is building now)
- `dashboard.whitemagic.dev` — deploy Nexus or new React dashboard
- `api.whitemagic.dev` — Railway deployment of MCP HTTP server

---

## Decision Points for Morning

1. **PyPI account** — do we have a PyPI token? Need to check.
2. **Docker Hub vs GHCR only** — GHCR is easier (already on GitHub), Docker Hub has more reach
3. **MkDocs vs custom site** — MkDocs Material is fastest to launch with existing markdown
4. **Version strategy** — ship v15.6.0 as-is or bump to v15.7.0 for the distribution release?

---

## Commits Tonight (v15.6.0)

| Commit | Repo | SHA |
|--------|------|-----|
| v15.6.0 — Cognitive Extensions & Code Quality | whitemagicpublic | `6e8cd1a` |
| v15.6.0 — Registry backfill, CHANGELOG, checklist audit | whitemagicpublic | `cbebfad` |

---

*This plan was generated 2026-02-13 00:15 ET. Estimated total execution time: ~2.5 hours.*
