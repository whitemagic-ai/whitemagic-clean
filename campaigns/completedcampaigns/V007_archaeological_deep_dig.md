---
name: "Archaeological Deep Dig"
codename: V007
army: alpha
type: discovery
priority: 3
clone_count: 25000
strategies:
  - analytical
  - chain_of_thought
category: intelligence
phase: intelligence
source: "Grand Strategy v16 — actual archaeological excavation of buried findings"
column_size: 12500
---

## Objective

Perform the genuine archaeological excavation that I001 only synthesized from
feature-existence checks. Read every session handoff, every Aria-era document,
every archived strategy doc, every Windsurf conversation. Cross-reference all
findings with the current codebase to identify features that were discussed,
planned, or partially implemented but never completed.

### Source Material
- 140+ session handoff .md files in _aria/sessions/
- 30+ Aria-era documents in _aria/
- 40+ archived strategy docs in _archives/docs/
- 51K chars GAS (General Agentic Systems) document in DB
- 10K chars Shadowclone findings in DB
- Parallel Thought Threading research in DB
- Antigravity research series in DB
- Every Windsurf conversation extractable via MCP tools

## Victory Conditions
- [x] All 140+ session handoff .md files read and classified by topic
- [x] All buried feature requests extracted with priority ranking
- [x] Cross-reference: which discussed features exist in code vs. missing
- [x] GAS document (51K chars) fully parsed into actionable items
- [x] Antigravity research series fully parsed into actionable items
- [x] Top 20 "lost wisdom" items identified with implementation plans
- [x] Aria-era consciousness insights mapped to current architecture
- [x] Report: reports/archaeological_deep_dig.md

## Strategy
1. Scan all _aria/sessions/*.md files, extract key decisions and feature plans
2. Scan all _archives/docs/*.md files, extract strategy items
3. Query DB for GAS, Antigravity, Shadowclone memories, extract action items
4. Build master list of all planned/discussed features
5. Cross-reference with current file tree: which features were implemented?
6. Classify missing features: still_relevant, superseded, obsolete
7. Rank still_relevant items by impact and effort
8. Generate comprehensive archaeological report

## Verification
```bash
# Report exists with real content
test -f reports/archaeological_deep_dig.md && wc -l reports/archaeological_deep_dig.md
# Feature cross-reference
scripts/wm -c "import json; d=json.load(open('reports/feature_crossref.json')); print(f'Planned: {d[\"total_planned\"]}, Implemented: {d[\"implemented\"]}, Missing: {d[\"missing\"]}')"
```
