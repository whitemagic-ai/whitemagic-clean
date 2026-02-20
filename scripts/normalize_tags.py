#!/usr/bin/env python3
"""Normalize and consolidate tags across the memory corpus.

Consolidates bulk/noise tags (archive, scavenged, etc.) by prefixing with
underscore, merges near-identical tags, and reports tag distribution.

Usage:
    python scripts/normalize_tags.py --report         # show tag distribution
    python scripts/normalize_tags.py --dry-run        # preview changes
    python scripts/normalize_tags.py                  # apply normalization
    python scripts/normalize_tags.py --delete archive # delete specific tag
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

# Tags to prefix with underscore (bulk/noise tags that dilute semantics)
BULK_RENAMES: dict[str, str] = {
    "archive": "_archive",
    "archived": "_archive",
    "scavenged": "_scavenged",
    "imported": "_imported",
    "bulk_import": "_bulk_import",
    "bulk-import": "_bulk_import",
    "external": "_external",
    "auto_tagged": "_auto_tagged",
    "auto-tagged": "_auto_tagged",
}

# Near-identical tag merges (old → canonical)
MERGE_MAP: dict[str, str] = {
    "golang": "go",
    "golang_ecosystem": "go",
    "go-lang": "go",
    "javascript": "js",
    "typescript": "ts",
    "python3": "python",
    "py": "python",
    "rust-lang": "rust",
    "haskell-lang": "haskell",
    "elixir-lang": "elixir",
    "whitmagic": "whitemagic",
    "white_magic": "whitemagic",
    "wm": "whitemagic",
    "mem": "memory",
    "memories": "memory",
    "sys": "system",
    "config": "configuration",
    "cfg": "configuration",
    "dev": "development",
    "docs": "documentation",
    "doc": "documentation",
    "test": "testing",
    "tests": "testing",
}


def main() -> None:
    parser = argparse.ArgumentParser(description="Normalize tags in the Data Sea")
    parser.add_argument("--report", action="store_true", help="Show tag frequency report only")
    parser.add_argument("--dry-run", action="store_true", help="Preview changes without applying")
    parser.add_argument("--delete", type=str, help="Delete a specific tag from all memories")
    parser.add_argument("--top", type=int, default=50, help="Show top N tags in report (default: 50)")
    args = parser.parse_args()

    from whitemagic.core.memory.unified import get_unified_memory

    um = get_unified_memory()
    backend = um.backend

    if args.report:
        _show_report(backend, args.top)
        return

    if args.delete:
        count = backend.delete_tag(args.delete)
        print(f"Deleted tag '{args.delete}' from {count} memories.")
        return

    # Build rename plan from current tags
    stats = backend.get_tag_stats()
    tag_set = {tag for tag, _ in stats}

    plan: list[tuple[str, str, int]] = []  # (old, new, count)
    for tag, count in stats:
        tag_lower = tag.lower().strip()
        # Check bulk renames
        if tag_lower in BULK_RENAMES:
            new_tag = BULK_RENAMES[tag_lower]
            if new_tag != tag:
                plan.append((tag, new_tag, count))
                continue
        # Check merge map
        if tag_lower in MERGE_MAP:
            new_tag = MERGE_MAP[tag_lower]
            if new_tag != tag:
                plan.append((tag, new_tag, count))
                continue
        # Normalize case: if tag has uppercase and lowercase version exists, merge
        if tag != tag_lower and tag_lower in tag_set:
            plan.append((tag, tag_lower, count))

    if not plan:
        print("No tags to normalize. Everything looks clean.")
        return

    print(f"\n📋 Tag normalization plan ({len(plan)} renames):\n")
    total_affected = 0
    for old, new, count in sorted(plan, key=lambda x: -x[2]):
        print(f"  {old:30s} → {new:30s}  ({count:,} memories)")
        total_affected += count

    print(f"\n  Total memory-tag rows affected: {total_affected:,}")

    if args.dry_run:
        print("\n  (Use without --dry-run to apply)")
        return

    print("\nApplying...")
    applied = 0
    for old, new, _ in plan:
        count = backend.rename_tag(old, new)
        applied += count

    print(f"\n✅ Normalized {applied:,} tag entries across {len(plan)} renames.")

    # Show updated top tags
    print("\nUpdated top 20 tags:")
    for tag, count in backend.get_tag_stats()[:20]:
        print(f"  {tag:30s}  {count:>6,}")
    print()


def _show_report(backend: object, top_n: int) -> None:
    """Display tag frequency distribution."""
    stats = backend.get_tag_stats()
    total_tags = sum(c for _, c in stats)
    unique_tags = len(stats)

    print(f"\n📊 Tag Report: {unique_tags:,} unique tags, {total_tags:,} total assignments\n")
    print(f"  {'Tag':30s}  {'Count':>8s}  {'%':>6s}")
    print(f"  {'─' * 30}  {'─' * 8}  {'─' * 6}")
    for tag, count in stats[:top_n]:
        pct = (count / total_tags * 100) if total_tags else 0
        print(f"  {tag:30s}  {count:>8,}  {pct:>5.1f}%")

    if len(stats) > top_n:
        remaining = sum(c for _, c in stats[top_n:])
        print(f"  {'... + ' + str(len(stats) - top_n) + ' more':30s}  {remaining:>8,}")
    print()


if __name__ == "__main__":
    main()
