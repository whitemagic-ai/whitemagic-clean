#!/usr/bin/env python3
"""
Database Scout Army - Analyze all WhiteMagic databases for restoration.
Deploys shadow clones to check integrity, count records, and identify best candidate.
"""

import json
import os
import sqlite3
import sys
from datetime import datetime

# Database locations to scout
DB_LOCATIONS = [
    # Active MCP DB
    ("~/.whitemagic/memory/whitemagic.db", "active_main"),
    ("~/.whitemagic/memory/whitemagic.db.bak.1", "active_bak1"),
    ("~/.whitemagic/memory/whitemagic.db.bak.2", "active_bak2"),
    ("~/.whitemagic/memory/whitemagic.db.bak.3", "active_bak3"),
    ("~/.whitemagic/memory/whitemagic.db.pre_ghost_purge_backup", "pre_ghost"),
    ("~/.whitemagic/memory/whitemagic_pre_rehydrate_backup.db", "pre_rehydrate"),

    # Archive DBs
    ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic_hot.db", "archive_hot"),
    ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic_cold.db", "archive_cold"),
    ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic_pre_merge.db", "archive_premerge"),
    ("/home/lucas/Desktop/whitemagic_memory_archive/whitemagic.db.bak", "archive_bak"),

    # wm_archive
    ("/home/lucas/Desktop/wm_archive/whitemagic/memory/whitemagic.db", "wm_archive_main"),

    # Project DBs
    ("/home/lucas/Desktop/whitemagicdev/whitemagic/memory/whitemagic.db", "dev_project"),
    ("/home/lucas/Desktop/whitemagicdev/_memories/whitemagic_hot.db", "dev_hot"),
    ("/home/lucas/Desktop/whitemagicdev/_memories/whitemagic_cold.db", "dev_cold"),
    ("/home/lucas/Desktop/whitemagicdev/_memories/primary_db_pre_merge.db", "dev_premerge"),
]


def scout_database(db_path: str, db_id: str) -> dict:
    """Scout a single database for integrity and content."""
    result = {
        "id": db_id,
        "path": db_path,
        "exists": False,
        "size_mb": 0,
        "integrity": "unknown",
        "memories": 0,
        "associations": 0,
        "tags": 0,
        "fts_entries": 0,
        "holo_coords": 0,
        "embeddings": 0,
        "errors": [],
        "modified": None,
        "recommendation": "unknown"
    }

    # Expand path
    db_path = os.path.expanduser(db_path)

    # Check existence
    if not os.path.exists(db_path):
        result["errors"].append("File not found")
        return result

    result["exists"] = True
    result["size_mb"] = round(os.path.getsize(db_path) / (1024 * 1024), 2)
    result["modified"] = datetime.fromtimestamp(os.path.getmtime(db_path)).isoformat()

    # Check integrity
    try:
        conn = sqlite3.connect(f"file:{db_path}?mode=ro", uri=True)
        conn.execute("PRAGMA integrity_check")
        result["integrity"] = "ok"

        # Count tables
        cursor = conn.execute("SELECT name FROM sqlite_master WHERE type='table'")
        tables = [row[0] for row in cursor.fetchall()]

        # Count memories
        if "memories" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM memories")
            result["memories"] = cursor.fetchone()[0]

        # Count associations
        if "associations" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM associations")
            result["associations"] = cursor.fetchone()[0]

        # Count tags
        if "tags" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM tags")
            result["tags"] = cursor.fetchone()[0]

        # Count FTS entries
        if "fts_index" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM fts_index")
            result["fts_entries"] = cursor.fetchone()[0]

        # Count holographic coords
        if "holographic_coords" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM holographic_coords")
            result["holo_coords"] = cursor.fetchone()[0]

        # Count embeddings (via embeddings.db or in main)
        if "embeddings" in tables:
            cursor = conn.execute("SELECT COUNT(*) FROM embeddings")
            result["embeddings"] = cursor.fetchone()[0]

        conn.close()

        # Generate recommendation
        if result["integrity"] == "ok" and result["memories"] > 1000:
            result["recommendation"] = "excellent"
        elif result["integrity"] == "ok":
            result["recommendation"] = "good"
        else:
            result["recommendation"] = "corrupted"

    except sqlite3.DatabaseError as e:
        result["integrity"] = "corrupted"
        result["errors"].append(f"SQLite error: {str(e)[:100]}")
        result["recommendation"] = "unusable"
    except Exception as e:
        result["errors"].append(f"Error: {str(e)[:100]}")
        result["recommendation"] = "error"

    return result


def deploy_scout_army():
    """Deploy scout clones to analyze all databases."""
    print("="*70)
    print("DATABASE SCOUT ARMY DEPLOYMENT")
    print("="*70)
    print(f"Deploying {len(DB_LOCATIONS)} scout clones to analyze databases...")
    print()

    results = []
    for db_path, db_id in DB_LOCATIONS:
        print(f"Scout {db_id}: {db_path} ...", end=" ", flush=True)
        result = scout_database(db_path, db_id)
        results.append(result)

        if result["exists"]:
            status = "✅" if result["integrity"] == "ok" else "❌"
            print(f"{status} {result['size_mb']}MB | {result['memories']} memories | {result['recommendation']}")
        else:
            print("⏭️ not found")

    return results


def generate_report(results: list) -> dict:
    """Generate restoration recommendation report."""
    print("\n" + "="*70)
    print("DATABASE RESTORATION ANALYSIS")
    print("="*70)

    # Filter valid candidates
    valid_dbs = [r for r in results if r["exists"] and r["integrity"] == "ok" and r["memories"] > 0]
    corrupted_dbs = [r for r in results if r["exists"] and r["integrity"] != "ok"]

    # Sort by memory count (descending)
    valid_dbs.sort(key=lambda x: x["memories"], reverse=True)

    print(f"\nValid database candidates: {len(valid_dbs)}")
    print(f"Corrupted databases: {len(corrupted_dbs)}")

    if corrupted_dbs:
        print("\n❌ CORRUPTED DATABASES:")
        for db in corrupted_dbs[:5]:
            print(f"  - {db['id']}: {db['path']}")
            print(f"    Size: {db['size_mb']}MB | Errors: {', '.join(db['errors'][:2])}")

    if valid_dbs:
        print("\n✅ TOP RESTORATION CANDIDATES:")
        for i, db in enumerate(valid_dbs[:5], 1):
            print(f"\n{i}. {db['id'].upper()}")
            print(f"   Path: {db['path']}")
            print(f"   Size: {db['size_mb']} MB")
            print(f"   Memories: {db['memories']:,}")
            print(f"   Associations: {db['associations']:,}")
            print(f"   Tags: {db['tags']:,}")
            print(f"   FTS: {db['fts_entries']:,} | Holo: {db['holo_coords']:,} | Embeddings: {db['embeddings']:,}")
            print(f"   Modified: {db['modified']}")

            if i == 1:
                print("   ⭐ RECOMMENDED FOR RESTORATION")

    # Best candidate
    best = valid_dbs[0] if valid_dbs else None

    return {
        "valid_candidates": len(valid_dbs),
        "corrupted_count": len(corrupted_dbs),
        "best_candidate": best,
        "all_results": results
    }


def main():
    # Deploy scouts
    results = deploy_scout_army()

    # Generate report
    report = generate_report(results)

    # Save full report
    report_path = "/home/lucas/Desktop/whitemagicdev/reports/db_scout_report.json"
    os.makedirs(os.path.dirname(report_path), exist_ok=True)
    with open(report_path, "w") as f:
        json.dump(report, f, indent=2, default=str)

    print(f"\n📄 Full report saved to: {report_path}")

    # Return best candidate for restoration
    if report["best_candidate"]:
        best = report["best_candidate"]
        print("\n🎯 RECOMMENDED ACTION:")
        print(f"   Restore from: {best['path']}")
        print("   Restore to: ~/.whitemagic/memory/whitemagic.db")
        print("\n   Command:")
        print(f"   cp {best['path']} ~/.whitemagic/memory/whitemagic.db")
        return 0
    else:
        print("\n❌ No valid database candidates found!")
        return 1


if __name__ == "__main__":
    sys.exit(main())
