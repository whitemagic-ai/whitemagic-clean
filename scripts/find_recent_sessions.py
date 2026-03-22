#!/usr/bin/env python3
"""
Find the most recent Windsurf Cascade session UUIDs by .pb file modification time.

Outputs UUIDs sorted by recency (newest first), one per line.
The AI assistant can then use trajectory_search on each to identify
which is the prior conversation session.

Usage:
    python scripts/find_recent_sessions.py           # Top 5 most recent
    python scripts/find_recent_sessions.py -n 10     # Top 10
    python scripts/find_recent_sessions.py --json    # JSON output
    python scripts/find_recent_sessions.py --exclude <current-uuid>  # Skip active session
"""

import argparse
import json
from datetime import datetime
from pathlib import Path

CASCADE_DIR = Path.home() / ".codeium" / "windsurf" / "cascade"


def find_recent_sessions(
    n: int = 5,
    exclude: str | None = None,
) -> list[dict]:
    """Find the N most recently modified .pb session files."""
    if not CASCADE_DIR.exists():
        return []

    sessions = []
    for pb_file in CASCADE_DIR.glob("*.pb"):
        uuid = pb_file.stem
        if exclude and uuid.startswith(exclude):
            continue

        stat = pb_file.stat()
        sessions.append({
            "uuid": uuid,
            "modified": datetime.fromtimestamp(stat.st_mtime).isoformat(),
            "size_kb": round(stat.st_size / 1024, 1),
            "path": str(pb_file),
        })

    # Sort by modification time, newest first
    sessions.sort(key=lambda s: s["modified"], reverse=True)
    return sessions[:n]


def main() -> None:
    parser = argparse.ArgumentParser(description="Find recent Windsurf Cascade sessions")
    parser.add_argument("-n", type=int, default=5, help="Number of recent sessions to show")
    parser.add_argument("--exclude", help="UUID prefix to exclude (e.g., current active session)")
    parser.add_argument("--json", action="store_true", help="Output as JSON")
    args = parser.parse_args()

    sessions = find_recent_sessions(n=args.n, exclude=args.exclude)

    if not sessions:
        print("No Windsurf Cascade sessions found.", file=__import__("sys").stderr)
        return

    if args.json:
        print(json.dumps(sessions, indent=2))
    else:
        print(f"{'#':>2}  {'UUID':36}  {'Modified':19}  {'Size':>8}")
        print("-" * 72)
        for i, s in enumerate(sessions, 1):
            mod = s["modified"][:19]
            print(f"{i:>2}  {s['uuid']}  {mod}  {s['size_kb']:>7.1f}KB")

        print()
        print("To probe a session, the AI should call:")
        print(f'  trajectory_search(ID="{sessions[0]["uuid"]}", Query="", SearchType="cascade")')
        if len(sessions) > 1:
            print()
            print(f"The most recent session is likely #{1} (newest .pb file).")
            print(f"The prior session (for ingestion) is likely #{2}.")


if __name__ == "__main__":
    main()
