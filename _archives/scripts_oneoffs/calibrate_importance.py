#!/usr/bin/env python3
"""Importance Calibration Batch Script (v14.3).

Recalibrates memory importance scores using multi-signal scoring:
  1. Content richness (length, structure)
  2. WhiteMagic keyword density
  3. Access frequency / recency
  4. Protection status
  5. Memory type weighting

Usage:
    python scripts/calibrate_importance.py                  # Dry run (default)
    python scripts/calibrate_importance.py --apply          # Apply changes
    python scripts/calibrate_importance.py --report         # Stats only
    python scripts/calibrate_importance.py --min-delta 0.1  # Only change if delta >= 0.1
"""

from __future__ import annotations

import argparse
import os
import sqlite3
import sys
import time
from datetime import datetime

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")

# Multi-signal keyword sets
WM_CORE_KEYWORDS = {
    "whitemagic", "gana", "dharma", "harmony", "holographic", "galactic",
    "mcp", "prat", "constellation", "association", "lifecycle", "retention",
    "maturity", "homeostasis", "bicameral", "gnosis", "wu xing", "grimoire",
    "polyglot", "mandala", "governor", "circuit breaker", "karma", "dream",
}

WM_TECH_KEYWORDS = {
    "rust", "zig", "haskell", "elixir", "mojo", "nexus", "simd", "embedding",
    "fts5", "sqlite", "hdbscan", "hnsw", "merkle", "ed25519", "pipeline",
    "dispatcher", "accelerator", "benchmark", "swarm", "agent", "broker",
}

SESSION_KEYWORDS = {"session handoff", "session_handoff", "handoff", "checkpoint"}

# Memory type weights (base importance floor)
TYPE_WEIGHTS = {
    "LONG_TERM": 0.5,
    "CORE": 0.7,
    "PATTERN": 0.6,
    "INSIGHT": 0.65,
    "SHORT_TERM": 0.3,
    "WORKING": 0.25,
}


def calibrate_score(
    title: str | None,
    content: str | None,
    memory_type: str,
    access_count: int,
    is_protected: bool,
    created_at: str | None,
) -> float:
    """Compute a calibrated importance score from multiple signals."""
    text = f"{title or ''} {content or ''}".lower()
    score = TYPE_WEIGHTS.get(memory_type, 0.4)

    # Signal 1: Content richness
    text_len = len(text.strip())
    if text_len > 2000:
        score += 0.10
    elif text_len > 500:
        score += 0.05
    elif text_len < 30:
        score -= 0.15

    # Signal 2: Core keyword density
    core_hits = sum(1 for kw in WM_CORE_KEYWORDS if kw in text)
    tech_hits = sum(1 for kw in WM_TECH_KEYWORDS if kw in text)
    total_hits = core_hits + tech_hits
    if total_hits >= 8:
        score += 0.20
    elif total_hits >= 5:
        score += 0.12
    elif total_hits >= 2:
        score += 0.05

    # Signal 3: Session handoff bonus
    if any(kw in text for kw in SESSION_KEYWORDS):
        score += 0.15

    # Signal 4: Access frequency
    if access_count >= 20:
        score += 0.10
    elif access_count >= 5:
        score += 0.05

    # Signal 5: Protection status
    if is_protected:
        score = max(score, 0.7)

    # Signal 6: Age — older memories that survived are more important
    if created_at:
        try:
            dt = datetime.fromisoformat(created_at.replace("Z", "+00:00"))
            age_days = (datetime.now(dt.tzinfo) - dt).days if dt.tzinfo else (datetime.now() - dt).days
            if age_days > 90:
                score += 0.05
        except Exception:
            pass

    return max(0.05, min(1.0, round(score, 3)))


def main() -> None:
    parser = argparse.ArgumentParser(description="Importance Calibration Batch (v14.3)")
    parser.add_argument("--apply", action="store_true", help="Apply calibrated scores (default: dry run)")
    parser.add_argument("--report", action="store_true", help="Stats report only, no calibration")
    parser.add_argument("--min-delta", type=float, default=0.05,
                        help="Minimum importance change to apply (default: 0.05)")
    parser.add_argument("--db", default=DB_PATH, help=f"Database path (default: {DB_PATH})")
    args = parser.parse_args()

    if not os.path.exists(args.db):
        print(f"Database not found: {args.db}")
        sys.exit(1)

    conn = sqlite3.connect(args.db)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA synchronous=NORMAL")

    # Current stats
    cur = conn.execute("""
        SELECT COUNT(*),
               AVG(importance),
               COUNT(CASE WHEN importance > 0.7 THEN 1 END),
               COUNT(CASE WHEN importance BETWEEN 0.4 AND 0.7 THEN 1 END),
               COUNT(CASE WHEN importance < 0.4 THEN 1 END),
               COUNT(CASE WHEN is_protected = 1 THEN 1 END)
        FROM memories
    """)
    total, avg_imp, high, mid, low, protected = cur.fetchone()
    avg_imp = avg_imp or 0

    print(f"=== Importance Calibration {'(DRY RUN)' if not args.apply else '(APPLYING)'} ===")
    print(f"  Total memories: {total:,}")
    print(f"  Current avg importance: {avg_imp:.3f}")
    print(f"  Distribution: high(>0.7)={high:,}  mid(0.4-0.7)={mid:,}  low(<0.4)={low:,}")
    print(f"  Protected: {protected:,}")

    if args.report:
        conn.close()
        return

    # Calibrate
    t0 = time.perf_counter()
    cur = conn.execute("""
        SELECT id, title, content, memory_type, importance, access_count, is_protected, created_at
        FROM memories
    """)

    updates: list[tuple[float, str]] = []
    boosted = dampened = unchanged = 0

    for mem_id, title, content, mem_type, current_imp, access_count, is_protected, created_at in cur:
        new_imp = calibrate_score(title, content, mem_type or "SHORT_TERM",
                                  access_count or 0, bool(is_protected), created_at)
        delta = abs(new_imp - (current_imp or 0.5))
        if delta >= args.min_delta:
            updates.append((new_imp, mem_id))
            if new_imp > (current_imp or 0.5):
                boosted += 1
            else:
                dampened += 1
        else:
            unchanged += 1

    elapsed = time.perf_counter() - t0

    print(f"\n  Calibration computed in {elapsed:.1f}s")
    print(f"  Would boost: {boosted:,}")
    print(f"  Would dampen: {dampened:,}")
    print(f"  Unchanged (delta < {args.min_delta}): {unchanged:,}")

    if args.apply and updates:
        print(f"\n  Applying {len(updates):,} updates...")
        t1 = time.perf_counter()
        conn.executemany("UPDATE memories SET importance = ? WHERE id = ?", updates)
        conn.commit()
        t2 = time.perf_counter()
        print(f"  Applied in {t2 - t1:.1f}s")

        # Post-calibration stats
        cur = conn.execute("SELECT AVG(importance) FROM memories")
        new_avg = cur.fetchone()[0] or 0
        print(f"\n  New avg importance: {new_avg:.3f} (was {avg_imp:.3f}, delta {new_avg - avg_imp:+.3f})")
    elif not args.apply:
        print("\n  Dry run — no changes made. Use --apply to execute.")

    conn.close()
    print("\nDone.")


if __name__ == "__main__":
    main()
