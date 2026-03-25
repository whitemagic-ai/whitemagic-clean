#!/usr/bin/env python3
"""
Strategy Distillation Engine
=============================
Turns raw extracted patterns into actionable strategies — no LLM required.

Pipeline:
  1. Load memories + holographic coordinates
  2. Cluster memories by coordinate-space grid (x, y bucketed at 0.2 resolution)
  3. Run Rust pattern extraction PER MEMORY (provenance tracking)
  4. Aggregate patterns within each cluster; frequency = signal strength
  5. Filter noise, rank by frequency, pick top N per category
  6. Synthesize a strategy document per cluster via template
  7. Persist as high-gravity (importance=1.0, w=1.5) strategy memories
  8. Write reports/strategy_book.md

Usage:
  .venv/bin/python scripts/distill_strategies.py
  .venv/bin/python scripts/distill_strategies.py --top-n 20
  .venv/bin/python scripts/distill_strategies.py --dry-run
"""

import sys
import json
import hashlib
import sqlite3
import time
from pathlib import Path
from collections import Counter, defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

MEM_DB = ROOT / "memory" / "whitemagic.db"

# ---------------------------------------------------------------------------
# Stopwords for theme extraction
# ---------------------------------------------------------------------------
STOPWORDS = {
    # English function words
    "the","a","an","is","are","was","were","be","been","being","have","has",
    "had","do","does","did","will","would","could","should","may","might",
    "shall","can","need","used","to","of","in","for","on","with","at","by",
    "from","as","into","through","during","before","after","above","below",
    "between","out","off","over","under","again","further","then","once",
    "here","there","when","where","why","how","all","each","every","both",
    "few","more","most","other","some","such","no","nor","not","only","own",
    "same","so","than","too","very","just","because","but","and","or","if",
    "while","that","this","these","those","it","its","my","your","his","her",
    "our","their","what","which","who","whom","i","me","we","us","you","he",
    "him","she","they","them","about","also","any","like","new","one","two",
    "has","get","set","run","use","make","add","now","up","down","been",
    "much","many","well","having","doing","going","being",
    # Code / technical noise
    "file","files","code","test","tests","using","based","used","first","last",
    "next","back","into",
    # YAML frontmatter / markdown structure words
    "title","created","tags","complete","phase","---","###","##","#",
    "true","false","null","none","type","version","date","name","path",
    "status","note","notes","description","summary","overview","example",
    # Common action words too generic for themes
    "return","returns","call","called","check","called","found","find",
    "create","created","update","updated","delete","deleted","insert",
    "include","included","import","imported","export","exported",
    "start","started","stop","stopped","begin","end","done","end",
    # Time words
    "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec",
    "today","yesterday","week","month","year","session","day",
    # Markdown / formatting
    "ref","see","link","http","https","www","com","org","github",
    "via","doc","docs","api","url","id","src","lib","bin","pkg",
}

# Memory types to EXCLUDE from pattern extraction (noise sources)
_NOISY_TYPES = {"recovered_file", "token_economy", "audit", "depth_gauge"}


# ---------------------------------------------------------------------------
# Stage 1 — Load
# ---------------------------------------------------------------------------
def load_memories(conn, content_lazy=False):
    """Load all memories that have holographic coordinates.
    If content_lazy=True, content is loaded as None to save RAM."""
    
    # Only load content if not lazy
    col = "NULL as content" if content_lazy else "m.content"
    rule = "" if content_lazy else "AND LENGTH(m.content) > 40"
    
    rows = conn.execute(f"""
        SELECT m.id, {col}, m.title, m.memory_type, m.importance,
               h.x, h.y, h.z, h.w
        FROM memories m
        JOIN holographic_coords h ON m.id = h.memory_id
        WHERE m.content IS NOT NULL {rule}
    """).fetchall()

    memories = {}
    for (mid, content, title, mtype, importance, x, y, z, w) in rows:
        memories[mid] = {
            "content":   content,
            "title":     title or "",
            "type":      mtype or "",
            "importance": importance or 0.0,
            "x": x, "y": y, "z": z, "w": w,
        }
    return memories


# ---------------------------------------------------------------------------
# Stage 2 — Cluster
# ---------------------------------------------------------------------------
def cluster_memories(memories, resolution=5):
    """Grid-bucket memories by (x, y) at given resolution.
    resolution=5 → buckets at 0.2 intervals.  Matches SubClusteringEngine."""
    clusters = defaultdict(list)
    for mid, mem in memories.items():
        cx = round(mem["x"] * resolution)
        cy = round(mem["y"] * resolution)
        clusters[(cx, cy)].append(mid)
    return clusters


# ---------------------------------------------------------------------------
# Stage 3 — Per-memory extraction (provenance)
# ---------------------------------------------------------------------------
def extract_per_memory(memories, min_confidence=0.3):
    """Run Rust extraction on each memory individually.  Returns per-memory pattern sets.
    Skips noisy memory types (recovered_file scans, operational metrics, etc.)."""
    import whitemagic_rs

    results = {}
    skipped = 0
    for mid, mem in memories.items():
        if mem.get("type") in _NOISY_TYPES:
            skipped += 1
            continue
        try:
            (_, _, sols, antis, heurs, opts, _) = \
                whitemagic_rs.extract_patterns_from_content([mem["content"]], min_confidence)
            if sols or antis or heurs or opts:
                results[mid] = {
                    "solutions":    sols,
                    "anti_patterns": antis,
                    "heuristics":   heurs,
                    "optimizations": opts,
                }
        except Exception:
            pass
    print(f"      (skipped {skipped} noisy-type memories)")
    return results


# ---------------------------------------------------------------------------
# Stage 4 — Aggregate + frequency count per cluster
# ---------------------------------------------------------------------------
def aggregate_clusters(clusters, per_memory):
    """For each cluster, count how often each pattern appears across member memories."""
    agg = {}
    for (cx, cy), mem_ids in clusters.items():
        solutions    = Counter()
        anti_patterns = Counter()
        heuristics   = Counter()
        optimizations = Counter()

        for mid in mem_ids:
            pm = per_memory.get(mid)
            if not pm:
                continue
            for s in pm["solutions"]:      solutions[s] += 1
            for a in pm["anti_patterns"]:  anti_patterns[a] += 1
            for h in pm["heuristics"]:     heuristics[h] += 1
            for o in pm["optimizations"]:  optimizations[o] += 1

        total = len(solutions) + len(anti_patterns) + len(heuristics) + len(optimizations)
        if total == 0:
            continue

        agg[(cx, cy)] = {
            "mem_ids":        mem_ids,
            "solutions":      solutions,
            "anti_patterns":  anti_patterns,
            "heuristics":     heuristics,
            "optimizations":  optimizations,
            "total_patterns": total,
        }
    return agg


# ---------------------------------------------------------------------------
# Stage 5 — Filter + rank
# ---------------------------------------------------------------------------
_NOISE_PREFIXES = (
    # System event log messages
    "Memory encoded:",
    "A new memory formed:",
    "The system captured a new thought:",
    "Event:",
    # Code / config fragments
    "opt :=",
    "return ",
    "env ",
    "package ",
    "import ",
    "@printf",            # Julia macro calls
    # Markdown / YAML structure
    "---",
    "title:",
    "created:",
    "tags:",
)

_NOISE_SUBSTRINGS = (
    "TETRAGRAM",           # Unicode character database entries
    "MUSICAL SYMBOL",
    "standalone_parallel", # Go test names
    "APPENDIX:",           # License boilerplate
    "py | themes:",        # Anthropology metadata
    "[file:",              # Recovered-file entries
    "allkeys-",            # Keysym data
    "Patterns: High parallel efficiency",  # Awareness snapshot boilerplate
    "Adjustments: Continue parallel ops",
    "Snapshot: {\"files\"",
    "JuliaSmoothOptimizers/",  # Julia package URLs
    "@ref)",               # Julia doc cross-references
    "/tmp/",               # Temporary file paths
    "md\", \"title\":",    # Event metadata JSON fragments
    "| themes:",           # Anthropology theme scores
    "topology extensions", # CPU feature detection noise
    # Julia SciML / autodiff documentation (high-frequency noise clusters)
    "These methods are recommended for",
    "SciMLBase",
    "AbstractSciML",
    "RecursiveArrayTools",
    "ChainRulesCore",
    "pullbacks/pushforwards",
    "sparse Jacobian, one should",
    "nonallocating",
    "SavedValues",
    "cache_operator",
    "the solution still acts like a function",
    # Go module cache test output
    "$GOPATH",
    "go list -m",
    "org/issue/",          # GitHub issue reference noise
)


def _quality_ok(text):
    """Quick quality gate on a pattern string."""
    t = text.strip()
    if len(t) < 30:
        return False
    # Skip raw code / dict literals / markdown structure
    if t[0] in ("'", "{", "[", "#", "`", "-", "|", "*", "0", "1", "2", "3",
                "4", "5", "6", "7", "8", "9") or t.startswith("//"):
        return False
    if "':" in t[:10]:        # Python dict repr
        return False
    if t.startswith(("/", "http:", "https:", "ftp:")):
        return False
    # Known noise prefixes
    for prefix in _NOISE_PREFIXES:
        if t.startswith(prefix):
            return False
    # Known noise substrings
    for sub in _NOISE_SUBSTRINGS:
        if sub in t:
            return False
    return True


def top_patterns(counter, n=5):
    """Return up to n quality-filtered patterns, ranked by frequency."""
    out = []
    for text, freq in counter.most_common():
        if _quality_ok(text):
            out.append((text.strip(), freq))
            if len(out) >= n:
                break
    return out


# ---------------------------------------------------------------------------
# Stage 6 — Theme extraction + strategy synthesis
# ---------------------------------------------------------------------------
def derive_theme(memories, mem_ids, n_terms=3):
    """Derive a cluster theme from memory titles and content.
    Titles get 3x weight; noisy memory types are skipped.
    Content is trimmed to avoid pulling in YAML frontmatter."""
    freq = Counter()
    for mid in mem_ids[:80]:
        mem = memories.get(mid)
        if not mem or mem.get("type") in _NOISY_TYPES:
            continue
        # Titles are curated — weight them heavily
        for word in (mem.get("title") or "").split():
            w = word.lower().strip(".,;:!?()[]{}\"'`-_/#*|")
            if w and w not in STOPWORDS and len(w) > 2 and not w.isdigit():
                freq[w] += 3
        # Content: skip YAML frontmatter block (between --- markers)
        content = mem.get("content") or ""
        # Strip leading frontmatter
        if content.startswith("---"):
            end_idx = content.find("---", 3)
            if end_idx != -1:
                content = content[end_idx + 3:]
        # Take first 200 chars of actual content
        for word in content[:200].split():
            w = word.lower().strip(".,;:!?()[]{}\"'`-_/#*|")
            if w and w not in STOPWORDS and len(w) > 2 and not w.isdigit():
                freq[w] += 1
    top = [w for w, _ in freq.most_common(n_terms)]
    return " / ".join(top) if top else "General"


# Axis label helpers
def _x_label(x):  return "Emotional" if x >= 0 else "Logical"
def _y_label(y):  return "Macro"     if y >= 0 else "Micro"


def synthesize_strategy(cx, cy, data, memories, seq_num, resolution=5):
    """Build a strategy document from a single cluster's aggregated patterns."""
    x_real = cx / resolution
    y_real = cy / resolution

    theme = derive_theme(memories, data["mem_ids"])

    sols  = top_patterns(data["solutions"],     n=5)
    antis = top_patterns(data["anti_patterns"], n=4)
    heurs = top_patterns(data["heuristics"],    n=5)
    opts  = top_patterns(data["optimizations"], n=4)

    # Need at least 3 real patterns to warrant a strategy
    if len(sols) + len(antis) + len(heurs) + len(opts) < 3:
        return None

    lines = []
    lines.append(f"# Strategy #{seq_num}: {theme}")
    lines.append("")
    lines.append(
        f"**Zone**: {_x_label(x_real)}-{_y_label(y_real)} "
        f"(x={x_real:.2f}, y={y_real:.2f}) | "
        f"{len(data['mem_ids'])} source memories"
    )
    lines.append("")

    if sols:
        lines.append("## What Works")
        for txt, freq in sols:
            suffix = f" _(×{freq})_" if freq > 1 else ""
            lines.append(f"- {txt}{suffix}")
        lines.append("")

    if antis:
        lines.append("## Watch Out For")
        for txt, freq in antis:
            suffix = f" _(×{freq})_" if freq > 1 else ""
            lines.append(f"- {txt}{suffix}")
        lines.append("")

    if heurs:
        lines.append("## Rules of Thumb")
        for txt, freq in heurs:
            suffix = f" _(×{freq})_" if freq > 1 else ""
            lines.append(f"- {txt}{suffix}")
        lines.append("")

    if opts:
        lines.append("## Performance Insights")
        for txt, freq in opts:
            suffix = f" _(×{freq})_" if freq > 1 else ""
            lines.append(f"- {txt}{suffix}")
        lines.append("")

    return {
        "num":     seq_num,
        "theme":   theme,
        "cx": cx, "cy": cy,
        "x": x_real, "y": y_real,
        "content": "\n".join(lines),
        "mem_count":     len(data["mem_ids"]),
        "pattern_count": len(sols) + len(antis) + len(heurs) + len(opts),
    }


# ---------------------------------------------------------------------------
# Stage 7 — Persist
# ---------------------------------------------------------------------------
def persist_strategies(conn, strategies):
    """Insert/update strategy memories with high importance and gravity."""
    for strat in strategies:
        sid = hashlib.sha256(
            f"strategy:{strat['theme']}:{strat['cx']}:{strat['cy']}".encode()
        ).hexdigest()[:16]

        existing = conn.execute("SELECT 1 FROM memories WHERE id=?", (sid,)).fetchone()
        title = f"Strategy: {strat['theme']}"
        meta  = json.dumps({"cluster": f"{strat['cx']},{strat['cy']}",
                            "pattern_count": strat["pattern_count"]})

        if existing:
            conn.execute(
                "UPDATE memories SET content=?, title=?, importance=1.0, "
                "memory_type='strategy', metadata=?, updated_at=datetime('now') "
                "WHERE id=?",
                (strat["content"], title, meta, sid)
            )
        else:
            conn.execute(
                "INSERT INTO memories "
                "(id, content, memory_type, created_at, updated_at, importance, title, metadata) "
                "VALUES (?,?,'strategy',datetime('now'),datetime('now'),1.0,?,?)",
                (sid, strat["content"], title, meta)
            )

        # Tags
        for tag in ["strategy", "distilled", strat["theme"].split(" / ")[0].strip()]:
            conn.execute("INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?,?)",
                         (sid, tag))

        # Holographic coord — cluster centroid, w=1.5 (high gravity)
        conn.execute(
            "INSERT OR REPLACE INTO holographic_coords (memory_id, x, y, z, w) "
            "VALUES (?,?,?,?,?)",
            (sid, strat["x"], strat["y"], 0.0, 1.5)
        )

        # FTS entry
        conn.execute(
            "INSERT OR REPLACE INTO memories_fts (id, title, content, tags_text) "
            "VALUES (?,?,?,?)",
            (sid, title, strat["content"], "strategy distilled")
        )

    conn.commit()
    return len(strategies)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    import argparse
    parser = argparse.ArgumentParser(description="Distill patterns into strategies")
    parser.add_argument("--top-n",        type=int,  default=30,  help="Max strategies")
    parser.add_argument("--min-memories", type=int,  default=3,   help="Min memories/cluster")
    parser.add_argument("--confidence",   type=float,default=0.3, help="Pattern min confidence")
    parser.add_argument("--dry-run",      action="store_true",    help="Skip persistence")
    args = parser.parse_args()

    start = time.time()
    print("=" * 62)
    print("  STRATEGY DISTILLATION ENGINE")
    print("=" * 62)

    conn = sqlite3.connect(str(MEM_DB))

    # 1
    print("\n  [1] Loading memories …", flush=True)
    memories = load_memories(conn)
    print(f"      {len(memories)} memories with coordinates")

    # 2
    print("  [2] Clustering …", flush=True)
    raw_clusters = cluster_memories(memories)
    clusters = {k: v for k, v in raw_clusters.items() if len(v) >= args.min_memories}
    print(f"      {len(clusters)} clusters (≥{args.min_memories} memories each, "
          f"{sum(len(v) for v in clusters.values())} total)")

    # 3
    print("  [3] Per-memory pattern extraction (Rust) …", flush=True)
    per_memory = extract_per_memory(memories, min_confidence=args.confidence)
    raw_count = sum(
        len(pm["solutions"]) + len(pm["anti_patterns"]) +
        len(pm["heuristics"]) + len(pm["optimizations"])
        for pm in per_memory.values()
    )
    print(f"      {len(per_memory)} memories yielded patterns — {raw_count} total")

    # 4
    print("  [4] Aggregating by cluster …", flush=True)
    agg = aggregate_clusters(clusters, per_memory)
    print(f"      {len(agg)} clusters with signal")

    # 5 + 6
    print("  [5] Synthesizing strategies …", flush=True)
    # Rank clusters by average pattern frequency — clusters where the same
    # pattern repeats across many member memories carry stronger signal than
    # clusters with many one-off patterns.
    def _avg_freq(data):
        all_counts = list(data["solutions"].values()) + \
                     list(data["anti_patterns"].values()) + \
                     list(data["heuristics"].values()) + \
                     list(data["optimizations"].values())
        return sum(all_counts) / len(all_counts) if all_counts else 0

    ranked = sorted(agg.items(), key=lambda item: _avg_freq(item[1]), reverse=True)
    ranked = ranked[:args.top_n]

    strategies = []
    for (cx, cy), data in ranked:
        strat = synthesize_strategy(cx, cy, data, memories, len(strategies) + 1)
        if strat:
            strategies.append(strat)

    print(f"      {len(strategies)} strategies synthesized")

    # 7 — Write report
    report_path = ROOT / "reports" / "strategy_book.md"
    with open(report_path, "w") as f:
        f.write("# Strategy Book\n\n")
        f.write(f"*Distilled from {len(memories)} memories across {len(agg)} pattern-rich clusters.*\n")
        f.write("*Engine: Rust pattern extraction + holographic coordinate clustering.*\n")
        f.write(f"*Generated: {time.strftime('%Y-%m-%d %H:%M')}*\n\n")
        f.write("---\n\n")
        for strat in strategies:
            f.write(strat["content"])
            f.write("\n\n---\n\n")
    print(f"      Report written: {report_path}")

    # 8 — Persist
    if not args.dry_run:
        print("  [6] Persisting strategy memories …", flush=True)
        n = persist_strategies(conn, strategies)
        print(f"      {n} strategies stored (importance=1.0, gravity=1.5)")

    conn.close()

    elapsed = time.time() - start
    print(f"\n{'=' * 62}")
    print(f"  DONE — {len(strategies)} strategies in {elapsed:.1f}s")
    print(f"{'=' * 62}")

    # Summary table
    print(f"\n  {'#':>3}  {'Theme':<42} {'Mems':>5} {'Pats':>5}")
    print("  " + "─" * 58)
    for s in strategies:
        print(f"  {s['num']:>3}  {s['theme'][:42]:<42} {s['mem_count']:>5} {s['pattern_count']:>5}")


if __name__ == "__main__":
    main()
