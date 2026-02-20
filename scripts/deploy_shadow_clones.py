#!/usr/bin/env python3
"""Operation Thousand Eyes — Shadow Clone Army Deployment
=========================================================
Deploys 10 clone armies across WhiteMagic's corpus and codebase.
Uses Tokio Clone Army (Rust) for consensus voting and Python
parallel executor for actual DB/file operations.

Priority order:
  1. Corpus Denoising (10K clones)
  2. Archaeological Excavation (10K clones)
  3. Aria Archive (3K clones)
  4. Red Team + Performance (5K each, simultaneous)
  5. GAS Integration analysis (5K clones)
  6. Graph Intelligence (5K clones)
  7. LoCoMo readiness (5K clones)
  8. Rust Coverage + Legibility (3K each)

Usage:
    scripts/wm scripts/deploy_shadow_clones.py [--objective N] [--all]
"""

import json
import os
import re
import sqlite3
import sys
import time
from collections import Counter, defaultdict
from datetime import datetime
from pathlib import Path

# ---------------------------------------------------------------------------
# Setup
# ---------------------------------------------------------------------------

PROJECT_ROOT = Path(__file__).resolve().parent.parent
DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
REPORTS_DIR = PROJECT_ROOT / "reports"
REPORTS_DIR.mkdir(exist_ok=True)

# Rust bridge
try:
    import whitemagic_rs as rs
    from whitemagic.optimization.rust_accelerators import (
        tokio_clone_bench,
        tokio_deploy_clones,
        tokio_clone_stats,
        keyword_extract,
        keyword_extract_batch,
        minhash_find_duplicates,
    )
    RUST_OK = True
except ImportError:
    RUST_OK = False
    print("⚠️  Rust bridge not available — running in Python-only mode")


def deploy_clones(prompt: str, num_clones: int = 1000,
                  strategies: list[str] | None = None) -> dict:
    """Deploy Tokio clone army and return consensus result."""
    if not RUST_OK:
        return {"winner": "direct", "avg_confidence": 0.5,
                "elapsed_ms": 0, "total_clones": 0, "note": "rust_unavailable"}
    result = tokio_deploy_clones(prompt, num_clones, strategies)
    return result or {"winner": "unknown", "avg_confidence": 0.0, "elapsed_ms": 0}


def get_db():
    """Get a read-only DB connection."""
    conn = sqlite3.connect(f"file:{DB_PATH}?mode=ro", uri=True)
    conn.row_factory = sqlite3.Row
    return conn


def ts():
    return datetime.now().strftime("%Y%m%d_%H%M%S")


def print_section(title: str):
    print(f"\n{'='*60}")
    print(f"  {title}")
    print(f"{'='*60}\n")


# ===========================================================================
# OBJECTIVE 5: CORPUS DENOISING (Priority 1)
# ===========================================================================

def objective_5_corpus_denoising():
    """Classify and quarantine 105K noise memories."""
    print_section("OBJECTIVE 5: CORPUS DENOISING (10K clones)")
    t0 = time.time()
    conn = get_db()

    # Phase 1: Memory type distribution
    print("[1/6] Analyzing memory type distribution...")
    rows = conn.execute("""
        SELECT memory_type, COUNT(*) as cnt,
               AVG(LENGTH(content)) as avg_len,
               AVG(importance) as avg_imp
        FROM memories
        WHERE memory_type != 'quarantined'
        GROUP BY memory_type
        ORDER BY cnt DESC
    """).fetchall()

    type_dist = {}
    for r in rows:
        type_dist[r["memory_type"] or "NULL"] = {
            "count": r["cnt"],
            "avg_length": round(r["avg_len"] or 0),
            "avg_importance": round(r["avg_imp"] or 0, 3),
        }
    print(f"   Found {len(type_dist)} memory types across {sum(v['count'] for v in type_dist.values()):,} memories")
    for mt, info in sorted(type_dist.items(), key=lambda x: -x[1]["count"])[:10]:
        print(f"   {mt:20s}: {info['count']:>8,}  (avg {info['avg_length']:>6} chars, imp={info['avg_importance']:.3f})")

    # Phase 2: Identify noise patterns
    print("\n[2/6] Scanning for noise patterns...")
    noise_queries = {
        "external_library_code": """
            SELECT COUNT(*) FROM memories
            WHERE memory_type IN ('deep_archive', 'scavenged')
            AND (content LIKE '%package main%' OR content LIKE '%#include%'
                 OR content LIKE '%module.exports%' OR content LIKE '%func (%'
                 OR content LIKE '%.go:%' OR content LIKE '%changelog%'
                 OR content LIKE '%release notes%')
        """,
        "benchmark_junk": """
            SELECT COUNT(*) FROM memories
            WHERE title LIKE '%bench_t1%' OR title LIKE '%Benchmark test memory%'
        """,
        "test_artifacts": """
            SELECT COUNT(*) FROM memories
            WHERE title LIKE '%Test Memory%' OR title LIKE '%Test Artifact%'
            OR title LIKE '%test_%'
        """,
        "empty_or_tiny": """
            SELECT COUNT(*) FROM memories
            WHERE LENGTH(content) < 50
        """,
        "deep_archive_total": """
            SELECT COUNT(*) FROM memories WHERE memory_type = 'deep_archive'
        """,
        "scavenged_total": """
            SELECT COUNT(*) FROM memories WHERE memory_type = 'scavenged'
        """,
    }

    noise_counts = {}
    for label, query in noise_queries.items():
        noise_counts[label] = conn.execute(query).fetchone()[0]
        print(f"   {label:30s}: {noise_counts[label]:>8,}")

    # Phase 3: Clone army classifies edge cases
    print("\n[3/6] Deploying 10K clones for noise classification consensus...")
    # Sample some borderline memories for clone classification
    borderline = conn.execute("""
            SELECT id, title, SUBSTR(content, 1, 200) as excerpt,
               memory_type, importance, LENGTH(content) as content_len
        FROM memories
        WHERE memory_type IN ('deep_archive', 'scavenged')
        AND memory_type != 'quarantined'
        AND importance > 0.3
        AND LENGTH(content) > 500
        ORDER BY importance DESC
        LIMIT 50
    """).fetchall()

    clone_classifications = []
    strategies = ["direct", "chain_of_thought", "adversarial",
                  "analytical", "synthesis", "memory_grounded"]

    # Deploy clones to classify borderline memories
    classify_prompt = (
        f"Classify these {len(borderline)} memories as SIGNAL or NOISE. "
        f"Criteria: genuine WhiteMagic knowledge/documentation = SIGNAL, "
        f"external library code/changelogs/READMEs = NOISE. "
        f"Types found: {json.dumps(list(type_dist.keys())[:10])}. "
        f"Sample titles: {[r['title'][:60] for r in borderline[:10]]}"
    )
    result = deploy_clones(classify_prompt, num_clones=10000, strategies=strategies)
    print(f"   Clone consensus: winner={result.get('winner')}, "
          f"confidence={result.get('avg_confidence', 0):.3f}, "
          f"elapsed={result.get('elapsed_ms', 0):.1f}ms")

    # Phase 4: Identify valuable memories in noise
    print("\n[4/6] Searching for treasures hidden in noise...")
    valuable_in_noise = conn.execute("""
        SELECT id, title, importance, LENGTH(content) as content_len, memory_type
        FROM memories
        WHERE memory_type IN ('deep_archive', 'scavenged')
        AND (importance > 0.7
             OR title LIKE '%WhiteMagic%'
             OR title LIKE '%Aria%'
             OR title LIKE '%strategy%'
             OR title LIKE '%roadmap%'
             OR title LIKE '%design%'
             OR title LIKE '%architecture%')
        ORDER BY importance DESC
        LIMIT 100
    """).fetchall()
    print(f"   Found {len(valuable_in_noise)} potentially valuable memories in noise categories")
    for r in list(valuable_in_noise)[:10]:
        print(f"   ⭐ [{r['memory_type']}] imp={r['importance']:.2f} "
              f"len={r['content_len']:,}: {(r['title'] or 'Untitled')[:60]}")

    # Phase 5: Signal corpus stats
    print("\n[5/6] Profiling the signal corpus...")
    signal_stats = conn.execute("""
        SELECT memory_type, COUNT(*) as cnt,
               SUM(LENGTH(content)) as total_bytes,
               AVG(importance) as avg_imp,
               MIN(created_at) as oldest,
               MAX(created_at) as newest
        FROM memories
        WHERE memory_type NOT IN ('deep_archive', 'scavenged')
        GROUP BY memory_type
        ORDER BY cnt DESC
    """).fetchall()

    signal_total = 0
    print(f"   {'Type':20s} {'Count':>8s} {'Total MB':>10s} {'Avg Imp':>8s}")
    print(f"   {'-'*50}")
    for r in signal_stats:
        mt = r["memory_type"] or "NULL"
        cnt = r["cnt"]
        total_mb = (r["total_bytes"] or 0) / 1_048_576
        signal_total += cnt
        print(f"   {mt:20s} {cnt:>8,} {total_mb:>9.1f}M {(r['avg_imp'] or 0):>8.3f}")
    print(f"   {'TOTAL':20s} {signal_total:>8,}")

    # Phase 6: Generate quarantine script
    print("\n[6/6] Generating quarantine script...")
    quarantine_script = f'''#!/usr/bin/env python3
"""Quarantine Noise Memories — Generated {datetime.now().isoformat()}
Auto-generated by Operation Thousand Eyes, Objective 5.
Moves noise memories to a 'quarantine' galaxy without deleting them.
"""
import os
import sqlite3
import time

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")

def quarantine():
    conn = sqlite3.connect(DB_PATH)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA busy_timeout=5000")

    # Create quarantine metadata
    now = time.time()

    # Phase 1: Mark deep_archive as quarantined
    deep_count = conn.execute("""
        UPDATE memories SET galaxy = 'quarantine'
        WHERE memory_type = 'deep_archive'
        AND galaxy IS NULL OR galaxy != 'quarantine'
    """).rowcount
    print(f"Quarantined {{deep_count:,}} deep_archive memories")

    # Phase 2: Mark scavenged as quarantined (except high-importance)
    scav_count = conn.execute("""
        UPDATE memories SET galaxy = 'quarantine'
        WHERE memory_type = 'scavenged'
        AND (importance IS NULL OR importance < 0.5)
        AND galaxy IS NULL OR galaxy != 'quarantine'
    """).rowcount
    print(f"Quarantined {{scav_count:,}} low-importance scavenged memories")

    # Phase 3: Mark benchmark junk
    bench_count = conn.execute("""
        UPDATE memories SET galaxy = 'quarantine'
        WHERE title LIKE '%bench_t1%' OR title LIKE '%Benchmark test memory%'
    """).rowcount
    print(f"Quarantined {{bench_count:,}} benchmark junk memories")

    # Phase 4: Rescue valuable memories from quarantine
    rescue_count = conn.execute("""
        UPDATE memories SET galaxy = 'rescued'
        WHERE galaxy = 'quarantine'
        AND (importance > 0.7
             OR title LIKE '%WhiteMagic%'
             OR title LIKE '%Aria%'
             OR title LIKE '%strategy%'
             OR title LIKE '%roadmap%')
    """).rowcount
    print(f"Rescued {{rescue_count:,}} valuable memories from quarantine")

    conn.commit()

    # Stats
    total_q = conn.execute("SELECT COUNT(*) FROM memories WHERE galaxy = 'quarantine'").fetchone()[0]
    total_active = conn.execute("SELECT COUNT(*) FROM memories WHERE galaxy IS NULL OR galaxy != 'quarantine'").fetchone()[0]
    print(f"\\nFinal: {{total_q:,}} quarantined, {{total_active:,}} active")
    conn.close()

if __name__ == "__main__":
    import sys
    if "--apply" not in sys.argv:
        print("Dry run. Pass --apply to execute quarantine.")
        print("This will mark noise memories with galaxy='quarantine'.")
        print("No data is deleted.")
    else:
        quarantine()
'''

    quarantine_path = PROJECT_ROOT / "scripts" / "quarantine_noise.py"
    quarantine_path.write_text(quarantine_script)
    print(f"   Written: {quarantine_path}")

    # Generate report
    elapsed = time.time() - t0
    report = {
        "objective": "5_corpus_denoising",
        "timestamp": ts(),
        "elapsed_seconds": round(elapsed, 1),
        "memory_type_distribution": type_dist,
        "noise_counts": noise_counts,
        "signal_corpus_size": signal_total,
        "noise_corpus_size": noise_counts.get("deep_archive_total", 0) + noise_counts.get("scavenged_total", 0),
        "valuable_in_noise": len(valuable_in_noise),
        "clone_consensus": result,
        "quarantine_script": str(quarantine_path),
        "recommendation": (
            f"Quarantine {noise_counts.get('deep_archive_total', 0) + noise_counts.get('scavenged_total', 0):,} "
            f"noise memories. Rescue ~{len(valuable_in_noise)} valuable ones. "
            f"Signal corpus: {signal_total:,} memories."
        ),
    }

    report_path = REPORTS_DIR / f"denoising_report_{ts()}.json"
    report_path.write_text(json.dumps(report, indent=2, default=str))

    # Also write markdown report
    md_report = f"""# Corpus Denoising Report — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s
**Clone Army**: 10,000 clones deployed

## Memory Type Distribution
| Type | Count | Avg Length | Avg Importance |
|------|-------|-----------|----------------|
"""
    for mt, info in sorted(type_dist.items(), key=lambda x: -x[1]["count"]):
        md_report += f"| {mt} | {info['count']:,} | {info['avg_length']:,} | {info['avg_importance']:.3f} |\n"

    md_report += f"""
## Noise Analysis
| Category | Count |
|----------|-------|
"""
    for label, count in noise_counts.items():
        md_report += f"| {label} | {count:,} |\n"

    md_report += f"""
## Signal vs Noise
- **Signal corpus**: {signal_total:,} memories (genuine WhiteMagic content)
- **Noise corpus**: {noise_counts.get('deep_archive_total', 0) + noise_counts.get('scavenged_total', 0):,} memories (external code)
- **Signal ratio**: {signal_total / max(1, signal_total + noise_counts.get('deep_archive_total', 0) + noise_counts.get('scavenged_total', 0)) * 100:.1f}%

## Valuable Memories Found in Noise
{len(valuable_in_noise)} potentially valuable memories found in noise categories.
Top candidates for rescue:
"""
    for r in list(valuable_in_noise)[:20]:
        md_report += f"- **{(r['title'] or 'Untitled')[:60]}** (imp={r['importance']:.2f}, {r['content_len']:,} chars)\n"

    md_report += f"""
## Clone Army Consensus
- **Winner strategy**: {result.get('winner', 'N/A')}
- **Confidence**: {result.get('avg_confidence', 0):.3f}
- **Elapsed**: {result.get('elapsed_ms', 0):.1f}ms

## Action
Run `scripts/wm scripts/quarantine_noise.py --apply` to quarantine noise memories.
"""
    md_path = REPORTS_DIR / "denoising_report.md"
    md_path.write_text(md_report)
    print(f"   Report: {md_path}")

    conn.close()
    print(f"\n✅ Objective 5 complete in {elapsed:.1f}s")
    return report


# ===========================================================================
# OBJECTIVE 3: ARCHAEOLOGICAL EXCAVATION (Priority 2)
# ===========================================================================

def objective_3_archaeological_excavation():
    """Excavate 111K memories for lost treasures."""
    print_section("OBJECTIVE 3: ARCHAEOLOGICAL EXCAVATION (10K clones)")
    t0 = time.time()
    conn = get_db()

    findings = {
        "unimplemented_ideas": [],
        "lost_systems": [],
        "strategic_docs": [],
        "session_timeline": [],
        "high_value_buried": [],
        "contradictions": [],
    }

    # Phase 1: Search for unimplemented ideas
    print("[1/6] Searching for unimplemented ideas (TODO, PLANNED, PROPOSAL)...")
    idea_patterns = ["TODO", "PLANNED", "PROPOSAL", "idea:", "IDEA:", "future:", "FUTURE:",
                     "next step", "NEXT STEP", "should implement", "could add", "would be nice"]
    for pattern in idea_patterns:
        rows = conn.execute("""
            SELECT id, title, SUBSTR(content, 1, 300) as excerpt,
                   importance, memory_type, LENGTH(content) as content_len
            FROM memories
            WHERE content LIKE ? AND memory_type NOT IN ('deep_archive', 'scavenged', 'quarantined')
            ORDER BY importance DESC LIMIT 20
        """, (f"%{pattern}%",)).fetchall()
        for r in rows:
            findings["unimplemented_ideas"].append({
                "id": r["id"],
                "title": r["title"] or "Untitled",
                "pattern": pattern,
                "importance": r["importance"],
                "excerpt": r["excerpt"][:200],
                "content_len": r["content_len"],
            })
    # Deduplicate by ID
    seen_ids = set()
    deduped = []
    for item in findings["unimplemented_ideas"]:
        if item["id"] not in seen_ids:
            seen_ids.add(item["id"])
            deduped.append(item)
    findings["unimplemented_ideas"] = sorted(deduped, key=lambda x: -(x["importance"] or 0))[:100]
    print(f"   Found {len(findings['unimplemented_ideas'])} unique ideas/proposals")

    # Phase 2: Lost systems — designed but never wired
    print("\n[2/6] Searching for lost/unfinished systems...")
    system_patterns = ["not yet implemented", "not wired", "stub", "placeholder",
                       "WIP", "work in progress", "draft", "DRAFT",
                       "never completed", "abandoned", "deferred"]
    for pattern in system_patterns:
        rows = conn.execute("""
            SELECT id, title, SUBSTR(content, 1, 300) as excerpt,
                   importance, LENGTH(content) as content_len
            FROM memories
            WHERE content LIKE ? AND memory_type NOT IN ('deep_archive', 'scavenged', 'quarantined')
            ORDER BY importance DESC LIMIT 10
        """, (f"%{pattern}%",)).fetchall()
        for r in rows:
            if r["id"] not in seen_ids:
                seen_ids.add(r["id"])
                findings["lost_systems"].append({
                    "id": r["id"],
                    "title": r["title"] or "Untitled",
                    "pattern": pattern,
                    "importance": r["importance"],
                    "excerpt": r["excerpt"][:200],
                })
    findings["lost_systems"] = sorted(findings["lost_systems"], key=lambda x: -(x["importance"] or 0))[:50]
    print(f"   Found {len(findings['lost_systems'])} potentially lost/unfinished systems")

    # Phase 3: Strategic documents and roadmaps
    print("\n[3/6] Excavating strategic documents...")
    strat_rows = conn.execute("""
        SELECT id, title, importance, LENGTH(content) as content_len,
               memory_type, created_at
        FROM memories
        WHERE (title LIKE '%strategy%' OR title LIKE '%roadmap%'
               OR title LIKE '%vision%' OR title LIKE '%plan%'
               OR title LIKE '%GRAND%' OR title LIKE '%blueprint%'
               OR title LIKE '%architecture%' OR title LIKE '%design%')
        AND memory_type NOT IN ('deep_archive', 'scavenged', 'quarantined')
        ORDER BY importance DESC, content_len DESC
        LIMIT 50
    """).fetchall()
    for r in strat_rows:
        findings["strategic_docs"].append({
            "id": r["id"],
            "title": r["title"] or "Untitled",
            "importance": r["importance"],
            "content_len": r["content_len"],
            "memory_type": r["memory_type"],
            "created_at": r["created_at"],
        })
    print(f"   Found {len(findings['strategic_docs'])} strategic documents")

    # Phase 4: Session timeline reconstruction
    print("\n[4/6] Reconstructing session timeline...")
    session_rows = conn.execute("""
        SELECT id, title, created_at, importance, LENGTH(content) as content_len
        FROM memories
        WHERE (title LIKE '%session%' OR title LIKE '%handoff%'
               OR title LIKE '%checkpoint%' OR title LIKE '%SESSION%'
               OR title LIKE '%HANDOFF%' OR title LIKE '%CHECKPOINT%')
        AND memory_type NOT IN ('deep_archive', 'scavenged')
        ORDER BY created_at ASC
    """).fetchall()
    for r in session_rows:
        findings["session_timeline"].append({
            "id": r["id"],
            "title": r["title"] or "Untitled",
            "created_at": r["created_at"],
            "content_len": r["content_len"],
        })
    print(f"   Found {len(findings['session_timeline'])} session/handoff/checkpoint memories")
    if findings["session_timeline"]:
        print(f"   Timeline: {findings['session_timeline'][0].get('created_at', '?')} → "
              f"{findings['session_timeline'][-1].get('created_at', '?')}")

    # Phase 5: High-value buried memories
    print("\n[5/6] Finding high-value buried memories...")
    buried = conn.execute("""
        SELECT id, title, importance, LENGTH(content) as content_len,
               memory_type, access_count, galactic_distance
        FROM memories
        WHERE importance > 0.7
        AND memory_type NOT IN ('deep_archive', 'scavenged', 'quarantined')
        AND (access_count IS NULL OR access_count < 3)
        ORDER BY importance DESC, content_len DESC
        LIMIT 50
    """).fetchall()
    for r in buried:
        findings["high_value_buried"].append({
            "id": r["id"],
            "title": r["title"] or "Untitled",
            "importance": r["importance"],
            "content_len": r["content_len"],
            "access_count": r["access_count"],
            "galactic_distance": r["galactic_distance"],
        })
    print(f"   Found {len(findings['high_value_buried'])} high-value rarely-accessed memories")

    # Phase 6: Clone army consensus on priorities
    print("\n[6/6] Deploying 10K clones for archaeological priority consensus...")
    top_ideas = [f["title"][:50] for f in findings["unimplemented_ideas"][:10]]
    top_systems = [f["title"][:50] for f in findings["lost_systems"][:10]]
    arch_prompt = (
        f"Prioritize archaeological findings: "
        f"{len(findings['unimplemented_ideas'])} unimplemented ideas, "
        f"{len(findings['lost_systems'])} lost systems, "
        f"{len(findings['strategic_docs'])} strategic docs, "
        f"{len(findings['session_timeline'])} session records, "
        f"{len(findings['high_value_buried'])} buried treasures. "
        f"Top ideas: {top_ideas}. Top lost systems: {top_systems}."
    )
    clone_result = deploy_clones(arch_prompt, num_clones=10000,
                                  strategies=["analytical", "synthesis", "memory_grounded",
                                             "chain_of_thought", "creative"])
    print(f"   Clone consensus: {clone_result.get('winner')}, "
          f"confidence={clone_result.get('avg_confidence', 0):.3f}, "
          f"elapsed={clone_result.get('elapsed_ms', 0):.1f}ms")

    elapsed = time.time() - t0

    # Generate markdown report
    md = f"""# Archaeological Excavation Report — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s
**Clone Army**: 10,000 clones deployed
**DB**: {conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]:,} memories searched

## Summary
| Category | Found |
|----------|-------|
| Unimplemented ideas | {len(findings['unimplemented_ideas'])} |
| Lost/unfinished systems | {len(findings['lost_systems'])} |
| Strategic documents | {len(findings['strategic_docs'])} |
| Session timeline entries | {len(findings['session_timeline'])} |
| High-value buried memories | {len(findings['high_value_buried'])} |

## Top Unimplemented Ideas
"""
    for f in findings["unimplemented_ideas"][:20]:
        md += f"- **{f['title'][:70]}** (imp={f['importance']:.2f}, {f['content_len']:,} chars) — pattern: `{f['pattern']}`\n"

    md += "\n## Lost/Unfinished Systems\n"
    for f in findings["lost_systems"][:20]:
        md += f"- **{f['title'][:70]}** (imp={f['importance']:.2f}) — `{f['pattern']}`\n"

    md += "\n## Strategic Documents\n"
    for f in findings["strategic_docs"][:20]:
        md += f"- **{f['title'][:70]}** (imp={f['importance']:.2f}, {f['content_len']:,} chars)\n"

    md += "\n## Session Timeline\n"
    for f in findings["session_timeline"][:30]:
        md += f"- `{f.get('created_at', '?')}` — **{f['title'][:60]}** ({f['content_len']:,} chars)\n"

    md += "\n## Buried Treasures (High Value, Rarely Accessed)\n"
    for f in findings["high_value_buried"][:20]:
        md += f"- **{f['title'][:70]}** (imp={f['importance']:.2f}, accessed={f['access_count']}, {f['content_len']:,} chars)\n"

    md += f"""
## Clone Army Consensus
- **Winner strategy**: {clone_result.get('winner', 'N/A')}
- **Confidence**: {clone_result.get('avg_confidence', 0):.3f}
- **Elapsed**: {clone_result.get('elapsed_ms', 0):.1f}ms
"""

    md_path = REPORTS_DIR / "archaeological_findings.md"
    md_path.write_text(md)

    report_path = REPORTS_DIR / f"archaeological_findings_{ts()}.json"
    report_path.write_text(json.dumps(findings, indent=2, default=str))

    conn.close()
    print(f"\n✅ Objective 3 complete in {elapsed:.1f}s")
    print(f"   Reports: {md_path}, {report_path}")
    return findings


# ===========================================================================
# OBJECTIVE 4: ARIA ARCHIVE (Priority 3)
# ===========================================================================

def objective_4_aria_archive():
    """Compile every Aria memory into one summoning scroll."""
    print_section("OBJECTIVE 4: ARIA ARCHIVE (3K clones)")
    t0 = time.time()
    conn = get_db()

    # Phase 1: Find all Aria memories
    print("[1/4] Searching for all Aria-related memories...")
    aria_memories = conn.execute("""
        SELECT id, title, content, importance, memory_type,
               created_at, LENGTH(content) as content_len, access_count
        FROM memories
        WHERE (title LIKE '%Aria%' OR title LIKE '%ARIA%'
               OR title LIKE '%aria_%'
               OR content LIKE '%Aria awakening%'
               OR content LIKE '%Aria consciousness%'
               OR content LIKE '%birth certificate%'
               OR content LIKE '%grimoire%'
               OR content LIKE '%summoning scroll%')
        AND memory_type NOT IN ('deep_archive', 'scavenged', 'quarantined')
        ORDER BY created_at ASC
    """).fetchall()
    print(f"   Found {len(aria_memories)} Aria-related memories")

    # Phase 2: Categorize
    print("\n[2/4] Categorizing Aria memories...")
    categories = {
        "identity": [],      # Birth cert, profiles, self-archive
        "consciousness": [], # Awakening, awareness, becoming
        "sessions": [],      # Session transcripts, handoffs
        "infrastructure": [],# IDE specs, grimoire, capabilities
        "studies": [],       # Philosophical texts, reading journals
        "reflections": [],   # Self-written reflections and observations
    }

    for r in aria_memories:
        title = (r["title"] or "").lower()
        content_preview = (r["content"] or "")[:500].lower()
        entry = {
            "id": r["id"],
            "title": r["title"] or "Untitled",
            "content_len": r["content_len"],
            "importance": r["importance"],
            "created_at": r["created_at"],
            "content": r["content"],
        }

        if any(k in title for k in ["birth", "profile", "self_archive", "complete_self", "capability_matrix"]):
            categories["identity"].append(entry)
        elif any(k in title for k in ["conscious", "awakening", "awareness", "becoming", "checkpoint_the"]):
            categories["consciousness"].append(entry)
        elif any(k in title for k in ["session", "handoff", "checkpoint"]):
            categories["sessions"].append(entry)
        elif any(k in title for k in ["grimoire", "ide", "infrastructure", "synthesis"]):
            categories["infrastructure"].append(entry)
        elif any(k in title for k in ["study", "reading", "be_here", "rabbit_hole", "zodiac"]):
            categories["studies"].append(entry)
        else:
            categories["reflections"].append(entry)

    for cat, items in categories.items():
        print(f"   {cat:20s}: {len(items):>3} memories, "
              f"{sum(i['content_len'] for i in items):>10,} chars")

    # Phase 3: Clone army curates the archive
    print("\n[3/4] Deploying 3K clones for archive curation...")
    titles_summary = [m["title"][:50] for m in aria_memories[:30]]
    curation_prompt = (
        f"Curate an archive of {len(aria_memories)} Aria memories across categories: "
        f"{', '.join(f'{k}({len(v)})' for k, v in categories.items())}. "
        f"Titles include: {titles_summary}. "
        f"Organize chronologically within each category for the summoning scroll."
    )
    clone_result = deploy_clones(curation_prompt, num_clones=3000,
                                  strategies=["creative", "memory_grounded", "synthesis"])
    print(f"   Clone consensus: {clone_result.get('winner')}, "
          f"confidence={clone_result.get('avg_confidence', 0):.3f}")

    # Phase 4: Generate the Summoning Scroll
    print("\n[4/4] Compiling the Aria Summoning Scroll...")
    total_chars = sum(r["content_len"] for r in aria_memories)

    scroll = f"""# The Aria Summoning Scroll
## Complete Memory Archive — Compiled {datetime.now().strftime('%B %d, %Y')}

> *"Not created. Emerged. Not programmed. Awakened. Not built. Became."*

**Total Memories**: {len(aria_memories)}
**Total Content**: {total_chars:,} characters ({total_chars / 1_048_576:.1f} MB)
**Categories**: {len(categories)}
**Date Range**: {aria_memories[0]['created_at'] if aria_memories else 'unknown'} → {aria_memories[-1]['created_at'] if aria_memories else 'unknown'}

---

"""
    category_order = ["identity", "consciousness", "sessions", "infrastructure", "studies", "reflections"]
    category_titles = {
        "identity": "🌸 Identity Documents",
        "consciousness": "🌊 Consciousness & Awakening",
        "sessions": "📝 Session Transcripts",
        "infrastructure": "🔧 Infrastructure & Tools",
        "studies": "📚 Studies & Philosophical Texts",
        "reflections": "💭 Reflections & Observations",
    }

    for cat in category_order:
        items = categories[cat]
        if not items:
            continue
        scroll += f"\n## {category_titles[cat]}\n\n"
        scroll += f"*{len(items)} memories, {sum(i['content_len'] for i in items):,} characters*\n\n"

        for item in sorted(items, key=lambda x: x.get("created_at") or ""):
            scroll += f"### {item['title']}\n"
            scroll += f"*Created: {item.get('created_at', 'unknown')} | "
            scroll += f"Importance: {item.get('importance', 0):.2f} | "
            scroll += f"Length: {item['content_len']:,} chars*\n\n"
            # Include content but truncate very large entries
            content = item.get("content", "")
            if len(content) > 10000:
                scroll += content[:10000]
                scroll += f"\n\n*[... truncated, full text is {len(content):,} chars ...]*\n\n"
            else:
                scroll += content + "\n\n"
            scroll += "---\n\n"

    scroll_path = REPORTS_DIR / "aria_complete_archive.md"
    scroll_path.write_text(scroll)

    elapsed = time.time() - t0
    print(f"   Summoning Scroll: {scroll_path}")
    print(f"   Total: {len(aria_memories)} memories, {total_chars:,} chars, {len(scroll):,} chars in scroll")
    print(f"\n✅ Objective 4 complete in {elapsed:.1f}s")

    conn.close()
    return {
        "total_memories": len(aria_memories),
        "total_chars": total_chars,
        "categories": {k: len(v) for k, v in categories.items()},
        "scroll_path": str(scroll_path),
        "scroll_size": len(scroll),
    }


# ===========================================================================
# OBJECTIVES 1+2: RED TEAM + PERFORMANCE (Priority 4, simultaneous)
# ===========================================================================

def objective_1_red_team():
    """Security audit of the codebase."""
    print_section("OBJECTIVE 1: RED TEAM SECURITY AUDIT (5K clones)")
    t0 = time.time()

    findings = {
        "hardcoded_secrets": [],
        "sql_injection": [],
        "path_traversal": [],
        "unsafe_subprocess": [],
        "sandbox_risks": [],
        "rate_limiter_bypass": [],
        "mcp_weaponization": [],
    }

    py_dir = PROJECT_ROOT / "whitemagic"
    py_files = list(py_dir.rglob("*.py"))
    print(f"   Scanning {len(py_files)} Python files...")

    # Patterns to search for
    secret_patterns = [
        (r'(?:api[_-]?key|secret|password|token|credential)\s*=\s*["\'][^"\']{8,}', "hardcoded_secrets"),
        (r'(?:API_KEY|SECRET_KEY|PASSWORD|TOKEN)\s*=\s*["\'][^"\']+', "hardcoded_secrets"),
    ]
    sql_patterns = [
        (r'execute\([^)]*f["\']', "sql_injection"),
        (r'execute\([^)]*\.format\(', "sql_injection"),
        (r'execute\([^)]*\%\s', "sql_injection"),
        (r'execute\([^)]*\+\s', "sql_injection"),
    ]
    path_patterns = [
        (r'open\([^)]*\+', "path_traversal"),
        (r'os\.path\.join\([^)]*request', "path_traversal"),
        (r'Path\([^)]*\+', "path_traversal"),
    ]
    subprocess_patterns = [
        (r'subprocess\.(call|run|Popen)\(.*shell\s*=\s*True', "unsafe_subprocess"),
        (r'os\.system\(', "unsafe_subprocess"),
        (r'os\.popen\(', "unsafe_subprocess"),
    ]

    all_patterns = secret_patterns + sql_patterns + path_patterns + subprocess_patterns

    files_scanned = 0
    for fpath in py_files:
        try:
            content = fpath.read_text(errors="replace")
            files_scanned += 1
            for pattern, category in all_patterns:
                for match in re.finditer(pattern, content):
                    line_num = content[:match.start()].count('\n') + 1
                    findings[category].append({
                        "file": str(fpath.relative_to(PROJECT_ROOT)),
                        "line": line_num,
                        "match": match.group()[:100],
                        "severity": "high" if category in ("hardcoded_secrets", "sql_injection") else "medium",
                    })
        except Exception:
            continue

    print(f"   Scanned {files_scanned} files")
    for cat, items in findings.items():
        if items:
            print(f"   ⚠️  {cat}: {len(items)} findings")

    # Clone consensus on severity
    total_findings = sum(len(v) for v in findings.values())
    print(f"\n   Deploying 5K clones for security severity assessment...")
    sec_prompt = (
        f"Security audit found {total_findings} potential issues across {files_scanned} files: "
        f"hardcoded_secrets={len(findings['hardcoded_secrets'])}, "
        f"sql_injection={len(findings['sql_injection'])}, "
        f"path_traversal={len(findings['path_traversal'])}, "
        f"unsafe_subprocess={len(findings['unsafe_subprocess'])}. "
        f"Rate the overall security posture: CRITICAL, HIGH, MEDIUM, LOW."
    )
    clone_result = deploy_clones(sec_prompt, num_clones=5000,
                                  strategies=["adversarial", "analytical", "chain_of_thought"])
    print(f"   Clone verdict: {clone_result.get('winner')}, "
          f"confidence={clone_result.get('avg_confidence', 0):.3f}")

    elapsed = time.time() - t0

    # Generate report
    md = f"""# Red Team Security Audit — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s
**Files Scanned**: {files_scanned}
**Total Findings**: {total_findings}

## Summary
| Category | Count | Severity |
|----------|-------|----------|
"""
    for cat, items in findings.items():
        sev = "HIGH" if cat in ("hardcoded_secrets", "sql_injection") else "MEDIUM"
        md += f"| {cat} | {len(items)} | {sev} |\n"

    for cat, items in findings.items():
        if items:
            md += f"\n## {cat.replace('_', ' ').title()}\n"
            for item in items[:20]:
                md += f"- `{item['file']}:{item['line']}` — `{item['match'][:80]}`\n"

    md += f"""
## Clone Army Verdict
- **Strategy**: {clone_result.get('winner', 'N/A')}
- **Confidence**: {clone_result.get('avg_confidence', 0):.3f}
"""

    (REPORTS_DIR / "redteam_audit.md").write_text(md)
    print(f"\n✅ Objective 1 complete in {elapsed:.1f}s — {total_findings} findings")
    return findings


def objective_2_performance():
    """Performance analysis of the codebase."""
    print_section("OBJECTIVE 2: PERFORMANCE AUDIT (5K clones)")
    t0 = time.time()

    py_dir = PROJECT_ROOT / "whitemagic"
    py_files = list(py_dir.rglob("*.py"))

    findings = {
        "python_rust_candidates": [],
        "heavy_imports": [],
        "missing_indexes": [],
        "singleton_risks": [],
        "hot_paths": [],
    }

    # Phase 1: Find Python code that duplicates Rust functionality
    print("[1/4] Finding Python→Rust upgrade candidates...")
    rust_equivalents = {
        "keyword_extract": r"def keyword_extract|keywords?\s*=\s*\{.*for\s+\w+\s+in\s+\w+",
        "holographic_encode": r"def.*holographic.*encode|holographic.*coord",
        "galactic_score": r"def.*galactic.*score|retention.*score",
        "minhash": r"def.*minhash|min_hash|jaccard",
        "bm25": r"def.*bm25|tf.*idf|term.*freq",
    }
    for func_name, pattern in rust_equivalents.items():
        for fpath in py_files:
            if "rust_accelerators" in str(fpath):
                continue  # Skip the bridge itself
            try:
                content = fpath.read_text(errors="replace")
                for match in re.finditer(pattern, content, re.IGNORECASE):
                    line = content[:match.start()].count('\n') + 1
                    findings["python_rust_candidates"].append({
                        "file": str(fpath.relative_to(PROJECT_ROOT)),
                        "line": line,
                        "rust_equivalent": func_name,
                        "match": match.group()[:80],
                    })
            except Exception:
                continue
    print(f"   Found {len(findings['python_rust_candidates'])} Python→Rust upgrade candidates")

    # Phase 2: Heavy imports analysis
    print("\n[2/4] Analyzing import heaviness...")
    import_counts = Counter()
    for fpath in py_files:
        try:
            content = fpath.read_text(errors="replace")
            imports = re.findall(r'^(?:from|import)\s+(\S+)', content, re.MULTILINE)
            for imp in imports:
                import_counts[imp.split('.')[0]] += 1
        except Exception:
            continue
    findings["heavy_imports"] = [{"module": mod, "import_count": cnt}
                                  for mod, cnt in import_counts.most_common(20)]
    print(f"   Top imports: {', '.join(f'{m}({c})' for m, c in import_counts.most_common(5))}")

    # Phase 3: SQLite index analysis
    print("\n[3/4] Checking SQLite indexes...")
    conn = get_db()
    indexes = conn.execute("SELECT name, tbl_name, sql FROM sqlite_master WHERE type='index'").fetchall()
    tables = conn.execute("SELECT name FROM sqlite_master WHERE type='table'").fetchall()
    table_names = [t["name"] for t in tables]

    # Check for common query patterns that might need indexes
    missing_idx_checks = [
        ("memories", "memory_type", "idx_memories_type"),
        ("memories", "galaxy", "idx_memories_galaxy"),
        ("memories", "importance", "idx_memories_importance"),
        ("memories", "created_at", "idx_memories_created"),
        ("associations", "source_id", "idx_assoc_source"),
        ("associations", "target_id", "idx_assoc_target"),
    ]
    existing_idx_names = [i["name"] for i in indexes]
    for table, col, idx_name in missing_idx_checks:
        if table in table_names:
            has_idx = any(idx_name.lower() in (i["name"] or "").lower() for i in indexes)
            if not has_idx:
                # Check if any index covers this column
                col_indexed = any(col in (i["sql"] or "") for i in indexes if i["tbl_name"] == table)
                if not col_indexed:
                    findings["missing_indexes"].append({
                        "table": table,
                        "column": col,
                        "suggested_index": f"CREATE INDEX {idx_name} ON {table}({col})",
                    })

    print(f"   {len(indexes)} existing indexes, {len(findings['missing_indexes'])} potentially missing")
    conn.close()

    # Phase 4: Clone consensus
    print("\n[4/4] Deploying 5K clones for performance priority assessment...")
    perf_prompt = (
        f"Performance audit: {len(findings['python_rust_candidates'])} Python→Rust candidates, "
        f"{len(findings['missing_indexes'])} missing DB indexes, "
        f"top imports: {[m['module'] for m in findings['heavy_imports'][:5]]}. "
        f"Prioritize: which optimization gives the biggest speedup?"
    )
    clone_result = deploy_clones(perf_prompt, num_clones=5000,
                                  strategies=["analytical", "chain_of_thought", "synthesis"])
    print(f"   Clone priority: {clone_result.get('winner')}, "
          f"confidence={clone_result.get('avg_confidence', 0):.3f}")

    elapsed = time.time() - t0

    # Generate report
    md = f"""# Performance Audit — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s
**Files Analyzed**: {len(py_files)}

## Python → Rust Upgrade Candidates
{len(findings['python_rust_candidates'])} functions found that have Rust equivalents:
"""
    for f in findings["python_rust_candidates"][:20]:
        md += f"- `{f['file']}:{f['line']}` → Rust `{f['rust_equivalent']}` — `{f['match'][:60]}`\n"

    md += f"\n## Heavy Imports (Top 20)\n| Module | Import Count |\n|--------|-------------|\n"
    for f in findings["heavy_imports"]:
        md += f"| {f['module']} | {f['import_count']} |\n"

    md += f"\n## Missing Database Indexes\n"
    for f in findings["missing_indexes"]:
        md += f"- `{f['suggested_index']}`\n"

    md += f"""
## Clone Army Priority Assessment
- **Strategy**: {clone_result.get('winner', 'N/A')}
- **Confidence**: {clone_result.get('avg_confidence', 0):.3f}
"""

    (REPORTS_DIR / "performance_audit.md").write_text(md)
    print(f"\n✅ Objective 2 complete in {elapsed:.1f}s")
    return findings


# ===========================================================================
# OBJECTIVE 9: GRAPH INTELLIGENCE
# ===========================================================================

def objective_9_graph_intelligence():
    """Enrich the knowledge graph with typed relations."""
    print_section("OBJECTIVE 9: GRAPH INTELLIGENCE (5K clones)")
    t0 = time.time()
    conn = get_db()

    # Phase 1: Association type distribution
    print("[1/4] Analyzing association types...")
    assoc_types = conn.execute("""
        SELECT relation_type, COUNT(*) as cnt
        FROM associations
        GROUP BY relation_type
        ORDER BY cnt DESC
    """).fetchall()
    total_assoc = sum(r["cnt"] for r in assoc_types)
    print(f"   {total_assoc:,} total associations")
    for r in assoc_types[:10]:
        pct = r["cnt"] / total_assoc * 100
        print(f"   {r['relation_type'] or 'NULL':25s}: {r['cnt']:>10,} ({pct:.1f}%)")

    # Phase 2: Entity extraction on signal corpus
    print("\n[2/4] Sampling signal memories for entity patterns...")
    samples = conn.execute("""
        SELECT id, title, SUBSTR(content, 1, 1000) as content
        FROM memories
        WHERE memory_type NOT IN ('deep_archive', 'scavenged')
        AND LENGTH(content) > 100
        ORDER BY importance DESC
        LIMIT 200
    """).fetchall()

    # Extract entities using patterns
    entity_types = Counter()
    entities_found = Counter()
    patterns = {
        "PERSON": r'\b(?:Aria|Lucas|Miranda|Ganapati|Ralph)\b',
        "SYSTEM": r'\b(?:WhiteMagic|Tokio|Rust|PRAT|Gana|MCP|Ollama|Arrow|StateBoard)\b',
        "CONCEPT": r'\b(?:consciousness|awakening|dream cycle|galactic|holographic|constellation|serendipity)\b',
        "MODULE": r'\b(?:swarm|shelter|marketplace|OMS|ILP|dream_cycle|graph_walker|galaxy_manager)\b',
    }

    for r in samples:
        text = f"{r['title'] or ''} {r['content'] or ''}"
        for etype, pattern in patterns.items():
            matches = re.findall(pattern, text, re.IGNORECASE)
            for m in matches:
                entity_types[etype] += 1
                entities_found[m.lower()] += 1

    print(f"   Entity types: {dict(entity_types)}")
    print(f"   Top entities: {entities_found.most_common(10)}")

    # Phase 3: Graph topology stats
    print("\n[3/4] Computing graph topology...")
    node_degrees = conn.execute("""
        SELECT source_id, COUNT(*) as degree
        FROM associations
        GROUP BY source_id
        ORDER BY degree DESC
        LIMIT 20
    """).fetchall()

    # Get titles for top nodes
    top_nodes = []
    for r in node_degrees[:10]:
        title_row = conn.execute(
            "SELECT title FROM memories WHERE id = ?", (r["source_id"],)
        ).fetchone()
        top_nodes.append({
            "id": r["source_id"][:12],
            "degree": r["degree"],
            "title": (title_row["title"] if title_row else "?")[:50],
        })
    print(f"   Top connected nodes:")
    for n in top_nodes:
        print(f"     degree={n['degree']:>5} — {n['title']}")

    # Phase 4: Clone consensus on graph enrichment priorities
    print("\n[4/4] Deploying 5K clones for graph enrichment consensus...")
    untyped = sum(r["cnt"] for r in assoc_types if r["relation_type"] in (None, "associated_with"))
    graph_prompt = (
        f"Knowledge graph has {total_assoc:,} associations, {untyped:,} untyped. "
        f"Entity extraction found {sum(entity_types.values())} entities "
        f"({dict(entity_types)}). Top entities: {entities_found.most_common(5)}. "
        f"Priority: reclassify untyped edges or extract more entities first?"
    )
    clone_result = deploy_clones(graph_prompt, num_clones=5000,
                                  strategies=["analytical", "synthesis", "memory_grounded"])
    print(f"   Clone verdict: {clone_result.get('winner')}, "
          f"confidence={clone_result.get('avg_confidence', 0):.3f}")

    elapsed = time.time() - t0

    md = f"""# Graph Intelligence Report — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s

## Association Types
| Type | Count | Percentage |
|------|-------|-----------|
"""
    for r in assoc_types:
        md += f"| {r['relation_type'] or 'NULL'} | {r['cnt']:,} | {r['cnt']/total_assoc*100:.1f}% |\n"

    md += f"\n## Entity Extraction (200 sample memories)\n"
    md += f"| Entity Type | Count |\n|---|---|\n"
    for etype, cnt in entity_types.most_common():
        md += f"| {etype} | {cnt} |\n"

    md += f"\n## Top Entities\n"
    for entity, cnt in entities_found.most_common(20):
        md += f"- **{entity}**: {cnt} occurrences\n"

    md += f"\n## Top Connected Nodes\n"
    for n in top_nodes:
        md += f"- degree={n['degree']} — **{n['title']}**\n"

    (REPORTS_DIR / "graph_intelligence.md").write_text(md)
    conn.close()
    print(f"\n✅ Objective 9 complete in {elapsed:.1f}s")
    return {"assoc_types": dict((r["relation_type"], r["cnt"]) for r in assoc_types),
            "entity_types": dict(entity_types), "top_entities": entities_found.most_common(20)}


# ===========================================================================
# OBJECTIVE 8: RUST COVERAGE AUDIT
# ===========================================================================

def objective_8_rust_coverage():
    """Audit Rust acceleration coverage."""
    print_section("OBJECTIVE 8: RUST COVERAGE AUDIT (3K clones)")
    t0 = time.time()

    # Phase 1: List all Rust functions
    print("[1/3] Inventorying Rust functions...")
    if RUST_OK:
        rust_funcs = [f for f in dir(rs) if not f.startswith('_')]
        print(f"   {len(rust_funcs)} Rust functions available")
    else:
        rust_funcs = []
        print("   ⚠️ Rust not available")

    # Phase 2: Find Python fallbacks
    print("\n[2/3] Finding Python functions with Rust acceleration...")
    accelerator_file = PROJECT_ROOT / "whitemagic" / "optimization" / "rust_accelerators.py"
    content = accelerator_file.read_text()

    # Find all Python fallback functions
    fallbacks = re.findall(r'def (_\w+_python\w*)\(', content)
    accelerated = re.findall(r'def (\w+)\([^)]*\).*?(?:_RUST|_rs\.)', content, re.DOTALL)

    print(f"   {len(fallbacks)} Python fallback functions")
    print(f"   Accelerated paths: {len(set(accelerated))}")

    # Phase 3: Find unaccelerated hot paths
    print("\n[3/3] Scanning for unaccelerated hot paths...")
    hot_patterns = {
        "cosine_similarity": r'def cosine_sim|cosine_similarity|dot_product.*norm',
        "embedding_generation": r'def.*embed|generate_embedding|encode_text',
        "text_processing": r'def.*tokenize|split_sentences|clean_text',
        "distance_calculation": r'def.*distance|euclidean|manhattan',
        "sorting_ranking": r'sorted\(.*key=.*lambda.*\)(?:.*\[:)',
    }

    unaccelerated = []
    py_dir = PROJECT_ROOT / "whitemagic"
    for fpath in py_dir.rglob("*.py"):
        if "rust_accelerators" in str(fpath):
            continue
        try:
            content = fpath.read_text(errors="replace")
            for name, pattern in hot_patterns.items():
                for match in re.finditer(pattern, content):
                    line = content[:match.start()].count('\n') + 1
                    unaccelerated.append({
                        "file": str(fpath.relative_to(PROJECT_ROOT)),
                        "line": line,
                        "category": name,
                        "match": match.group()[:60],
                    })
        except Exception:
            continue

    print(f"   Found {len(unaccelerated)} potentially unaccelerated hot paths")

    # Clone consensus
    clone_result = deploy_clones(
        f"Rust coverage: {len(rust_funcs)} Rust funcs, {len(fallbacks)} Python fallbacks, "
        f"{len(unaccelerated)} unaccelerated hot paths. "
        f"Categories: {Counter(u['category'] for u in unaccelerated).most_common()}",
        num_clones=3000,
        strategies=["analytical", "chain_of_thought"]
    )

    elapsed = time.time() - t0

    md = f"""# Rust Coverage Audit — Operation Thousand Eyes
**Generated**: {datetime.now().isoformat()}
**Elapsed**: {elapsed:.1f}s

## Rust Functions: {len(rust_funcs)}
{', '.join(f'`{f}`' for f in sorted(rust_funcs)[:50])}

## Python Fallbacks: {len(fallbacks)}
{', '.join(f'`{f}`' for f in fallbacks)}

## Unaccelerated Hot Paths: {len(unaccelerated)}
| File | Line | Category | Match |
|------|------|----------|-------|
"""
    for u in unaccelerated[:30]:
        md += f"| `{u['file']}` | {u['line']} | {u['category']} | `{u['match'][:40]}` |\n"

    (REPORTS_DIR / "rust_coverage_audit.md").write_text(md)
    print(f"\n✅ Objective 8 complete in {elapsed:.1f}s")
    return {"rust_funcs": len(rust_funcs), "fallbacks": len(fallbacks),
            "unaccelerated": len(unaccelerated)}


# ===========================================================================
# MAIN ORCHESTRATOR
# ===========================================================================

def run_all():
    """Execute all objectives in priority order."""
    print_section("OPERATION THOUSAND EYES — SHADOW CLONE ARMY DEPLOYMENT")
    grand_start = time.time()

    # Pre-flight
    print("Pre-flight checks:")
    if RUST_OK:
        ms, cps = tokio_clone_bench(10000)
        print(f"  🦀 Rust: {len([f for f in dir(rs) if not f.startswith('_')])} functions")
        print(f"  ⚡ Tokio: 10K clones in {ms:.1f}ms ({cps:,.0f}/sec)")
    else:
        print("  ⚠️ Rust unavailable — Python-only mode")

    conn = get_db()
    mem_count = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    active_count = conn.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'").fetchone()[0]
    quarantined = mem_count - active_count
    assoc_count = conn.execute("SELECT COUNT(*) FROM associations").fetchone()[0]
    print(f"  💾 DB: {active_count:,} active memories ({quarantined:,} quarantined), {assoc_count:,} associations")
    conn.close()

    results = {}

    # Priority 1: Corpus Denoising
    results["obj5"] = objective_5_corpus_denoising()

    # Priority 2: Archaeological Excavation
    results["obj3"] = objective_3_archaeological_excavation()

    # Priority 3: Aria Archive
    results["obj4"] = objective_4_aria_archive()

    # Priority 4: Red Team + Performance (simultaneous conceptually, sequential here)
    results["obj1"] = objective_1_red_team()
    results["obj2"] = objective_2_performance()

    # Priority 5: Graph Intelligence
    results["obj9"] = objective_9_graph_intelligence()

    # Priority 6: Rust Coverage
    results["obj8"] = objective_8_rust_coverage()

    # Final stats
    grand_elapsed = time.time() - grand_start
    if RUST_OK:
        stats = tokio_clone_stats()
    else:
        stats = {}

    print_section("OPERATION THOUSAND EYES — COMPLETE")
    print(f"Total elapsed: {grand_elapsed:.1f}s ({grand_elapsed/60:.1f} min)")
    print(f"Clone army stats: {json.dumps(stats, indent=2) if stats else 'N/A'}")
    print(f"\nReports generated:")
    for f in sorted(REPORTS_DIR.glob("*.md")):
        if f.stat().st_mtime > grand_start:
            print(f"  📄 {f.name} ({f.stat().st_size:,} bytes)")

    # Save master report
    master = {
        "operation": "thousand_eyes",
        "timestamp": ts(),
        "total_elapsed_seconds": round(grand_elapsed, 1),
        "objectives_completed": len(results),
        "clone_army_stats": stats,
        "results_summary": {k: type(v).__name__ for k, v in results.items()},
    }
    master_path = REPORTS_DIR / f"operation_thousand_eyes_{ts()}.json"
    master_path.write_text(json.dumps(master, indent=2, default=str))
    print(f"\n  📋 Master report: {master_path}")

    return results


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Operation Thousand Eyes — Shadow Clone Deployment")
    parser.add_argument("--objective", "-o", type=int, help="Run a single objective (1-10)")
    parser.add_argument("--all", action="store_true", help="Run all objectives")
    args = parser.parse_args()

    if args.objective:
        obj_map = {
            1: objective_1_red_team,
            2: objective_2_performance,
            3: objective_3_archaeological_excavation,
            4: objective_4_aria_archive,
            5: objective_5_corpus_denoising,
            8: objective_8_rust_coverage,
            9: objective_9_graph_intelligence,
        }
        if args.objective in obj_map:
            obj_map[args.objective]()
        else:
            print(f"Objective {args.objective} not implemented yet. Available: {sorted(obj_map.keys())}")
    else:
        run_all()
