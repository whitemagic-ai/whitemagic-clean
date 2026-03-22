#!/usr/bin/env python3
"""
Archive Duplicates — IL004 Campaign
====================================
Move 2,181+ duplicate memory pairs to archives instead of deletion/quarantine.

Strategy:
1. Find all exact content duplicates via SHA-256 hashing
2. For each duplicate group, score members by: importance * access_count * recency
3. Winner = highest score; losers get archived
4. Before archiving, merge metadata: union tags, repoint associations
5. Export losers to archive JSON files in ~/.whitemagic/memory/archives/
6. Mark losers as archived in DB with pointer to winner
7. Verify zero duplicates remain in active corpus
"""

import hashlib
import json
import sqlite3
from collections import defaultdict
from datetime import datetime
from pathlib import Path

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
ARCHIVE_DIR = Path.home() / ".whitemagic" / "memory" / "archives"
ARCHIVE_DIR.mkdir(parents=True, exist_ok=True)


def compute_content_hash(title: str, content: str) -> str:
    """Compute SHA-256 hash of title + content."""
    combined = f"{title or ''}\x00{content or ''}"
    return hashlib.sha256(combined.encode()).hexdigest()


def score_memory(importance: float, access_count: int, created_at: str) -> float:
    """Score a memory for duplicate resolution.

    Higher score = better candidate to keep.
    Formula: importance * access_count * recency_factor
    """
    importance = importance or 0.5
    access_count = max(access_count or 0, 1)

    # Recency factor: newer memories get slight boost
    try:
        created_dt = datetime.fromisoformat(created_at.replace('Z', '+00:00'))
        days_old = (datetime.now().astimezone() - created_dt).days
        recency_factor = 1.0 / (1.0 + days_old / 365.0)  # Decay over years
    except:
        recency_factor = 0.5

    return importance * access_count * recency_factor


def find_duplicate_groups(conn: sqlite3.Connection) -> dict[str, list[dict]]:
    """Find all duplicate memory groups by content hash.

    Returns: {hash: [memory_dict, ...]} for groups with 2+ members
    """
    print("🔍 Scanning for duplicate content...")
    cur = conn.cursor()

    # Get all active memories
    cur.execute("""
        SELECT id, title, content, importance, access_count, created_at, memory_type
        FROM memories
        WHERE memory_type != 'quarantined' AND memory_type != 'archived'
    """)

    groups = defaultdict(list)
    total_scanned = 0

    for row in cur.fetchall():
        mem_id, title, content, importance, access_count, created_at, mem_type = row

        # Compute hash
        content_hash = compute_content_hash(title or "", content or "")

        # Score this memory
        score = score_memory(importance, access_count, created_at)

        groups[content_hash].append({
            'id': mem_id,
            'title': title,
            'content': content,
            'importance': importance,
            'access_count': access_count,
            'created_at': created_at,
            'memory_type': mem_type,
            'score': score,
            'hash': content_hash
        })

        total_scanned += 1
        if total_scanned % 10000 == 0:
            print(f"  ...scanned {total_scanned:,} memories")

    # Filter to only groups with duplicates
    dup_groups = {h: mems for h, mems in groups.items() if len(mems) > 1}

    print(f"✅ Scanned {total_scanned:,} memories")
    print(f"📦 Found {len(dup_groups):,} duplicate groups")

    # Count total duplicate pairs
    total_pairs = sum(len(mems) - 1 for mems in dup_groups.values())
    print(f"🔗 Total duplicate pairs: {total_pairs:,}")

    return dup_groups


def get_memory_metadata(conn: sqlite3.Connection, mem_id: str) -> dict:
    """Get all metadata for a memory: tags, associations, coordinates."""
    cur = conn.cursor()

    # Get tags
    cur.execute("SELECT tag FROM tags WHERE memory_id = ?", (mem_id,))
    tags = [row[0] for row in cur.fetchall()]

    # Get associations (both directions)
    cur.execute("""
        SELECT target_id, association_type, strength
        FROM associations
        WHERE source_id = ?
    """, (mem_id,))
    outgoing = [{'target': row[0], 'type': row[1], 'strength': row[2]}
                for row in cur.fetchall()]

    cur.execute("""
        SELECT source_id, association_type, strength
        FROM associations
        WHERE target_id = ?
    """, (mem_id,))
    incoming = [{'source': row[0], 'type': row[1], 'strength': row[2]}
                for row in cur.fetchall()]

    # Get holographic coordinates
    cur.execute("""
        SELECT x, y, z, w, v
        FROM holographic_coordinates
        WHERE memory_id = ?
    """, (mem_id,))
    coords_row = cur.fetchone()
    coords = list(coords_row) if coords_row else None

    return {
        'tags': tags,
        'outgoing_associations': outgoing,
        'incoming_associations': incoming,
        'coordinates': coords
    }


def merge_metadata(conn: sqlite3.Connection, winner_id: str, loser_id: str):
    """Merge loser's metadata into winner before archiving loser."""
    cur = conn.cursor()

    # Merge tags (union)
    cur.execute("""
        INSERT OR IGNORE INTO tags (memory_id, tag)
        SELECT ?, tag FROM tags WHERE memory_id = ?
    """, (winner_id, loser_id))

    # Repoint associations from loser to winner
    # Outgoing: loser -> X becomes winner -> X
    cur.execute("""
        UPDATE associations
        SET source_id = ?
        WHERE source_id = ?
        AND NOT EXISTS (
            SELECT 1 FROM associations
            WHERE source_id = ? AND target_id = associations.target_id
        )
    """, (winner_id, loser_id, winner_id))

    # Incoming: X -> loser becomes X -> winner
    cur.execute("""
        UPDATE associations
        SET target_id = ?
        WHERE target_id = ?
        AND NOT EXISTS (
            SELECT 1 FROM associations
            WHERE source_id = associations.source_id AND target_id = ?
        )
    """, (winner_id, loser_id, winner_id))

    # Delete any remaining associations pointing to loser
    cur.execute("DELETE FROM associations WHERE source_id = ? OR target_id = ?",
                (loser_id, loser_id))

    conn.commit()


def archive_memory(conn: sqlite3.Connection, memory: dict, winner_id: str,
                   archive_batch: list):
    """Archive a duplicate memory to JSON and mark as archived in DB."""
    mem_id = memory['id']

    # Get full metadata
    metadata = get_memory_metadata(conn, mem_id)

    # Create archive record
    archive_record = {
        'id': mem_id,
        'title': memory['title'],
        'content': memory['content'],
        'importance': memory['importance'],
        'access_count': memory['access_count'],
        'created_at': memory['created_at'],
        'memory_type': memory['memory_type'],
        'archived_at': datetime.now().isoformat(),
        'archived_reason': 'duplicate_content',
        'duplicate_of': winner_id,
        'content_hash': memory['hash'],
        'metadata': metadata
    }

    archive_batch.append(archive_record)

    # Mark as archived in DB (don't delete, just mark)
    cur = conn.cursor()
    cur.execute("""
        UPDATE memories
        SET memory_type = 'archived',
            metadata = json_set(COALESCE(metadata, '{}'), '$.duplicate_of', ?)
        WHERE id = ?
    """, (winner_id, mem_id))

    # Remove from holographic coordinates (archived memories don't need coords)
    cur.execute("DELETE FROM holographic_coordinates WHERE memory_id = ?", (mem_id,))

    conn.commit()


def process_duplicate_groups(conn: sqlite3.Connection, dup_groups: dict):
    """Process all duplicate groups: pick winner, archive losers."""
    print("\n🏆 Processing duplicate groups...")

    archive_batch = []
    total_groups = len(dup_groups)
    total_archived = 0

    for idx, (content_hash, memories) in enumerate(dup_groups.items(), 1):
        # Sort by score (highest first)
        memories.sort(key=lambda m: m['score'], reverse=True)

        winner = memories[0]
        losers = memories[1:]

        if idx % 100 == 0:
            print(f"  ...processing group {idx:,}/{total_groups:,}")

        # Process each loser
        for loser in losers:
            # Merge metadata into winner
            merge_metadata(conn, winner['id'], loser['id'])

            # Archive loser
            archive_memory(conn, loser, winner['id'], archive_batch)
            total_archived += 1

        # Save archive batch every 500 memories
        if len(archive_batch) >= 500:
            save_archive_batch(archive_batch)
            archive_batch = []

    # Save remaining
    if archive_batch:
        save_archive_batch(archive_batch)

    print(f"✅ Archived {total_archived:,} duplicate memories")
    return total_archived


def save_archive_batch(archive_batch: list):
    """Save a batch of archived memories to JSON file."""
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    filename = ARCHIVE_DIR / f"duplicates_{timestamp}.json"

    with open(filename, 'w') as f:
        json.dump({
            'archived_at': datetime.now().isoformat(),
            'reason': 'IL004_content_deduplication',
            'count': len(archive_batch),
            'memories': archive_batch
        }, f, indent=2)

    print(f"  💾 Saved {len(archive_batch)} memories to {filename.name}")


def verify_deduplication(conn: sqlite3.Connection):
    """Verify that no duplicates remain in active corpus."""
    print("\n🔍 Verifying deduplication...")
    cur = conn.cursor()

    # Count duplicate groups in active memories
    cur.execute("""
        SELECT content, COUNT(*) as c
        FROM memories
        WHERE memory_type NOT IN ('quarantined', 'archived')
        GROUP BY content
        HAVING c > 1
    """)

    dup_groups = cur.fetchall()

    if dup_groups:
        print(f"⚠️  WARNING: {len(dup_groups)} duplicate groups still exist!")
        for content, count in dup_groups[:5]:
            print(f"  - {count} copies of: {content[:50]}...")
        return False

    # Count active memories
    cur.execute("""
        SELECT COUNT(*) FROM memories
        WHERE memory_type NOT IN ('quarantined', 'archived')
    """)
    active_count = cur.fetchone()[0]

    # Count archived memories
    cur.execute("SELECT COUNT(*) FROM memories WHERE memory_type = 'archived'")
    archived_count = cur.fetchone()[0]

    print("✅ Zero duplicate groups remain")
    print(f"📊 Active memories: {active_count:,}")
    print(f"📦 Archived memories: {archived_count:,}")

    return True


def main():
    """Main execution: find duplicates, archive losers, verify."""
    print("=" * 70)
    print("  IL004: Content Deduplication via Archival")
    print("=" * 70)
    print()

    # Connect to database
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row

    try:
        # Find duplicate groups
        dup_groups = find_duplicate_groups(conn)

        if not dup_groups:
            print("\n✅ No duplicates found! Database is clean.")
            return

        # Process duplicates
        archived_count = process_duplicate_groups(conn, dup_groups)

        # Verify
        success = verify_deduplication(conn)

        print()
        print("=" * 70)
        if success:
            print(f"✅ IL004 COMPLETE: {archived_count:,} duplicates archived")
            print(f"📁 Archives saved to: {ARCHIVE_DIR}")
        else:
            print("⚠️  Deduplication incomplete - manual review needed")
        print("=" * 70)

    finally:
        conn.close()


if __name__ == "__main__":
    main()
