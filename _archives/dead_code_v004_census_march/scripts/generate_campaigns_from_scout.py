#!/usr/bin/env python3
"""Generate PSR-025+ campaign markdown files from polyglot-scout JSON output.

Usage:
    ./whitemagic-rust/target/release/polyglot-scout /path --json | python3 scripts/generate_campaigns_from_scout.py
    python3 scripts/generate_campaigns_from_scout.py --from-file /tmp/scout_latest.json
"""
import json, sys, argparse
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).parent.parent
CAMPAIGNS_DIR = ROOT / "campaigns"

TITLE_MAP = {
    "performance":   ("N+1 DB Query and Nested Loop Elimination",   "P1"),
    "migration":     ("Heavy Computation Python-to-Rust Migration",  "P1"),
    "security":      ("SQL Injection Pattern Remediation",           "P1"),
    "quality":       ("TODO Resolution and Type Hint Coverage",      "P2"),
    "architecture":  ("Large File Decomposition",                    "P2"),
}

VC_MAP = {
    "performance": [
        "- [ ] All N+1 DB query patterns identified and batched",
        "- [ ] Nested loop hot paths replaced with Rust rayon iterators",
        "- [ ] Benchmark shows ≥5× speedup on affected functions",
        "- [ ] Re-run polyglot-scout shows 0 new performance findings in affected files",
    ],
    "migration": [
        "- [ ] Top 5 migration candidates migrated to Rust with pyo3 bindings",
        "- [ ] Python originals replaced by thin wrappers calling Rust",
        "- [ ] Real benchmark (maturin develop) shows ≥10× speedup",
        "- [ ] Re-run polyglot-scout migration score drops to <0.3 for migrated files",
    ],
    "security": [
        "- [ ] All f-string SQL patterns replaced with parameterized queries",
        "- [ ] Security scan shows 0 SQL injection patterns",
        "- [ ] Test suite covers all fixed queries",
        "- [ ] Re-run polyglot-scout shows 0 security findings",
    ],
    "quality": [
        "- [ ] All TODO/FIXME items resolved or tracked in campaigns",
        "- [ ] Type hints added to all public functions in top 20 files",
        "- [ ] Large functions (>50 lines) decomposed",
        "- [ ] Re-run polyglot-scout quality findings drop by ≥50%",
    ],
    "architecture": [
        "- [ ] Large files (>300 lines) split into focused modules",
        "- [ ] Module dependency graph has no cycles",
        "- [ ] Each module has a single clear responsibility",
        "- [ ] Re-run polyglot-scout architecture findings drop by ≥50%",
    ],
}

def slugify(s):
    import re
    return re.sub(r'[^a-z0-9_]', '_', s.lower())[:40].strip('_')

def next_psr_id():
    existing = sorted(CAMPAIGNS_DIR.glob("PSR*.md"))
    ids = []
    for f in existing:
        try: ids.append(int(f.name[3:6]))
        except: pass
    return max(ids, default=24) + 1

def generate(psr_id, category, count, top_findings, top_candidates):
    title, priority = TITLE_MAP.get(category, (f"{category.title()} Improvements", "P2"))
    slug = slugify(title)
    fname = f"PSR{psr_id:03d}_{slug}.md"
    fpath = CAMPAIGNS_DIR / fname
    if fpath.exists():
        return None, fname

    vcs = "\n".join(VC_MAP.get(category, ["- [ ] All findings resolved"]))

    cat_findings = [f for f in top_findings if f.get("category") == category][:5]
    target_rows = "\n".join(
        f"| {f['file'].split('/')[-1][:40]} | {f['line']} | {f['title'][:50]} |"
        for f in cat_findings
    ) or "| (run scout --json for full list) | - | - |"

    cand_rows = ""
    if category == "migration":
        cand_rows = "\n### Top Migration Candidates\n\n| File | Lines | Score | Speedup |\n|------|-------|-------|---------|\n"
        for c in top_candidates[:5]:
            cand_rows += f"| {c['file'].split('/')[-1][:40]} | {c['lines']} | {c['migration_score']:.2f} | {c['estimated_speedup']} |\n"

    content = f"""---
name: {title}
codename: PSR-{psr_id:03d}
army: tokio
type: fix_and_verify
priority: {priority}
clone_count: 50000
strategies: [parallel, {category}]
category: {category}
phase: next
source: polyglot_scout_auto_20260218
column_size: 3
---

## Objective

Auto-generated from polyglot-scout findings ({category} category).

Scout found **{count} {category} findings** across the codebase on 2026-02-18.
{f"Top severity-4 issues: {len([f for f in cat_findings if f.get('severity',0)==4)}." if cat_findings else ""}

{cand_rows}

## Victory Conditions

{vcs}

## Targets

| File | Line | Finding |
|------|------|---------|
{target_rows}

## Strategy

1. Run `./whitemagic-rust/target/release/polyglot-scout /path --json` to get latest findings
2. Sort by severity (4=critical first)
3. For each finding: apply fix, verify, commit
4. Re-run scout to confirm finding count drops

## Verification

```bash
./whitemagic-rust/target/release/polyglot-scout /home/lucas/Desktop/whitemagicdev/whitemagic --json \\
  | python3 -c "
import json,sys; d=json.load(sys.stdin)
print('{category}:', d['findings_by_category'].get('{category}', 0), 'findings')
"
```
"""
    fpath.write_text(content)
    return fname, fname

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--from-file", help="Load scout JSON from file")
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    if args.from_file:
        report = json.loads(Path(args.from_file).read_text())
    elif not sys.stdin.isatty():
        report = json.load(sys.stdin)
    else:
        print("Usage: polyglot-scout --json | python3 scripts/generate_campaigns_from_scout.py")
        sys.exit(1)

    by_cat = report.get("findings_by_category", {})
    top_findings = report.get("top_findings", [])
    top_candidates = report.get("top_migration_candidates", [])

    print(f"Scout findings: {by_cat}")
    print(f"Generating campaigns for {len(by_cat)} categories...\n")

    psr_id = next_psr_id()
    created = []
    for category, count in sorted(by_cat.items(), key=lambda x: -x[1]):
        if args.dry_run:
            title, priority = TITLE_MAP.get(category, (f"{category.title()}", "P2"))
            print(f"  DRY PSR-{psr_id:03d}: {title} ({count} findings)")
            psr_id += 1
            continue
        fname, _ = generate(psr_id, category, count, top_findings, top_candidates)
        if fname:
            created.append(fname)
            print(f"  ✅ PSR-{psr_id:03d}: {fname} ({count} findings)")
        else:
            print(f"  SKIP PSR-{psr_id:03d}: already exists for {category}")
        psr_id += 1

    print(f"\nCreated {len(created)} campaign files in {CAMPAIGNS_DIR}")

if __name__ == "__main__":
    main()
