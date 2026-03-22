# Tomorrow's Game Plan — Feb 12, 2026

**Read this when you wake up. Hit the ground running.**

---

## Priority 1: Clean Export (30 min)

The whitemagic folder is 13GB. Actual source is ~25MB. The bloat:

| Source | Size | Action |
|--------|------|--------|
| `whitemagic-rust/target/` | 7.2GB | gitignore (already is, but not cleaned) |
| `whitemagic-mojo/mojo-env/` | 883MB | gitignore + exclude from export |
| `nexus/node_modules/` | 295MB | gitignore (already is) |
| `memory/` (in-project legacy DB) | 74MB | exclude from export |
| `build/` + `dist/` | 13MB | gitignore |

### Option A: Clean the current folder (recommended)

```bash
cd ~/Desktop/whitemagic

# Remove build artifacts (recoverable via cargo build / npm install)
rm -rf whitemagic-rust/target/
rm -rf whitemagic-mojo/mojo-env/
rm -rf nexus/node_modules/
rm -rf mesh/node_modules/
rm -rf build/ dist/ *.egg-info
rm -rf whitemagic-zig/zig-out/
find . -name '__pycache__' -type d -exec rm -rf {} + 2>/dev/null

# Result: ~100MB (source + docs + scripts + polyglot source)
```

### Option B: Export to whitemagic-release/

```bash
cd ~/Desktop
mkdir whitemagic-release
cd whitemagic

# Copy only tracked files (respects .gitignore)
git init --initial-branch=main  # if not already a git repo
git add -A
git stash  # capture current state
rsync -av --files-from=<(git ls-files) . ~/Desktop/whitemagic-release/

# Or simpler: tar up only source
tar czf ~/Desktop/whitemagic-v15-source.tar.gz \
  --exclude='*/target' --exclude='*/node_modules' \
  --exclude='*/.pixi' --exclude='*/mojo-env' \
  --exclude='*/zig-out' --exclude='*/__pycache__' \
  --exclude='*/build' --exclude='*/dist' \
  --exclude='*.egg-info' --exclude='*/memory/*.db' \
  --exclude='*/logs/*' \
  .
```

## Priority 2: GitHub Push (15 min)

1. Create repo at github.com/lbailey94/whitemagic (screenshot shows it ready)
2. Do NOT check "Add README" (we have one)

```bash
cd ~/Desktop/whitemagic  # or whitemagic-release
git init --initial-branch=main
git remote add origin git@github.com:lbailey94/whitemagic.git

# Make sure .gitignore covers everything before adding
git add -A
git commit -m "v15.0.0 — WhiteMagic Release Candidate

311 MCP tools, 28 PRAT Ganas, 9-language polyglot,
8-stage security pipeline, SQLCipher encryption at rest,
persistent RBAC, backup/restore, embedding auto-indexing.

1,955 tests passing. 195K+ LOC."

git push -u origin main
git tag v15.0.0
git push --tags
```

## Priority 3: PyPI Test Publish (15 min)

```bash
cd ~/Desktop/whitemagic
python3 -m build                    # Creates wheel + sdist
twine check dist/*                  # Verify package metadata
twine upload --repository testpypi dist/*   # Test first

# Test install from TestPyPI
pip install --index-url https://test.pypi.org/simple/ whitemagic

# If clean:
twine upload dist/*                 # Real PyPI
```

## Priority 4: Gitignore Pass (10 min)

Add to `.gitignore` before git push:

```
# Build artifacts
whitemagic-rust/target/
whitemagic-mojo/mojo-env/
whitemagic-zig/zig-out/
whitemagic-zig/bin/
nexus/node_modules/
mesh/node_modules/
build/
dist/
*.egg-info/
memory/*.db
logs/
```

Most of these should already be there — verify and add any missing.

## Priority 5: WASM Seed Binary (Start — multi-day effort)

### Day 1 Target: Proof of concept

```bash
cd ~/Desktop/whitemagic/whitemagic-rust

# Add wasm32-wasi target
rustup target add wasm32-wasi

# Create a new binary crate for the seed
cargo new --name wm-seed src/bin/wm_seed
```

The seed binary needs:
- `rusqlite` (already a dep, with `bundled` feature = embedded SQLite)
- `serde_json` (already a dep)
- Embed the 16 quickstart memories as const strings
- Implement basic MCP stdio loop (read JSON-RPC → dispatch → respond)
- Compile to native first, WASM later

### Architecture

```
whitemagic-rust/
├── src/
│   ├── lib.rs              # Existing PyO3 library (stays)
│   ├── bin/
│   │   └── wm_seed.rs      # NEW: standalone seed binary
│   ├── spatial_index_5d.rs  # Reused by both
│   ├── search.rs            # Reused by both
│   └── ...
└── Cargo.toml               # Add [[bin]] section
```

### Realistic Timeline

| Milestone | Effort | What |
|-----------|--------|------|
| Seed binary (native) | 2-3 sessions | SQLite + memory CRUD + MCP stdio |
| Seed binary (WASM) | 1 session | wasm-pack build, test in wasmtime |
| GitHub Releases | 30 min | Cross-compile for linux-x64, darwin-arm64, windows-x64 |
| npm package | 1 session | @whitemagic/core-wasm with JS bindings |

## Priority 6: whitemagic-ai GitHub Org (5 min)

1. Create github.com/whitemagic-ai org
2. Transfer lbailey94/whitemagic → whitemagic-ai/whitemagic
3. GitHub auto-redirects the old URL

## Summary: Tomorrow Morning Checklist

- [ ] Clean build artifacts from whitemagic/ (or export to whitemagic-release/)
- [ ] Verify .gitignore covers all bloat
- [ ] Create GitHub repo + push v15.0.0
- [ ] PyPI test publish
- [ ] Start WASM seed binary proof of concept
- [ ] Create whitemagic-ai org

**Total estimated time: 2-3 hours for priorities 1-4, then open-ended WASM work.**

---

## What We Accomplished Today (for reference)

### Gap Closure (all 6 implemented)
1. SQLCipher encryption at rest (`WM_DB_PASSPHRASE`)
2. `wm backup` / `galaxy.backup` + restore
3. Persistent RBAC (survives restarts)
4. Embedding auto-indexing on memory create
5. FTS query sanitization
6. WASM strategy doc

### Docs Written
- `docs/WASM_STRATEGY.md` — Full WASM roadmap
- `docs/VOTE_COLLECTION.md` — Central vote collection via Railway
- `docs/WEBSITE_REFRESH.md` — Subdomain architecture + content plan

### Version/Cleanup
- All v14 references fixed (llms-full.txt, grimoire, mcp-registry)
- GitHub URL unified to lbailey94/whitemagic
- `wm init` templates now use project-local state root
- Tool count 285→311 in init templates
- Contact email added everywhere
- `wm rules` and `wm systemmap` CLI commands added
- `sqlcipher3` added to pyproject.toml `[encrypt]` extra
- CHANGELOG fully updated

### wmdummy3 Test Results
- Fresh install works, 5/5 core tools pass
- State root leak identified and fixed (was reading dev DB)
- AI test exposed missing CLI commands (now added)
- Grimoire version was stale (fixed)

---

*Contact: whitemagicdev@proton.me*
