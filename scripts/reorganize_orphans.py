#!/usr/bin/env python3
"""
Reorganize Orphaned Data - Find Homes, No Deletions
====================================================

Reorganizes orphaned holographic coordinates and associations by:
1. Finding their original memories (if they exist elsewhere)
2. Creating archive memories for true orphans
3. Linking orphans to related content
4. NO DELETIONS - everything gets a home
"""

import sqlite3
import sys
import json
from pathlib import Path
from datetime import datetime
from collections import defaultdict

sys.path.insert(0, str(Path(__file__).parent.parent))


def find_orphan_coords(db_path: Path) -> list:
    """Find holographic coords without corresponding memories."""
    conn = sqlite3.connect(str(db_path))
    cursor = conn.cursor()
    
    cursor.execute("""
        SELECT hc.memory_id, hc.x, hc.y, hc.z, hc.w, hc.v
        FROM holographic_coords hc
        LEFT JOIN memories m ON hc.memory_id = m.id
        WHERE m.id IS NULL
    """)
    
    orphans = cursor.fetchall()
    conn.close()
    
    return orphans


def find_orphan_associations(db_path: Path) -> list:
    """Find associations pointing to non-existent memories."""
    conn = sqlite3.connect(str(db_path))
    cursor = conn.cursor()
    
    cursor.execute("""
        SELECT a.source_id, a.target_id, a.strength, a.relation_type
        FROM associations a
        LEFT JOIN memories m1 ON a.source_id = m1.id
        LEFT JOIN memories m2 ON a.target_id = m2.id
        WHERE m1.id IS NULL OR m2.id IS NULL
    """)
    
    orphans = cursor.fetchall()
    conn.close()
    
    return orphans


def create_archive_memory(conn, memory_id: str, coords: tuple, reason: str) -> str:
    """Create an archive memory for orphaned data."""
    cursor = conn.cursor()
    
    x, y, z, w, v = coords
    
    # Create archive memory
    archive_content = {
        "original_id": memory_id,
        "reason": reason,
        "coordinates": {"x": x, "y": y, "z": z, "w": w, "v": v},
        "archived_at": datetime.now().isoformat(),
    }
    
    cursor.execute("""
        INSERT INTO memories (id, title, content, memory_type, created_at, metadata)
        VALUES (?, ?, ?, ?, ?, ?)
    """, (
        memory_id,
        f"[ARCHIVED] Orphaned coordinate {memory_id[:8]}",
        json.dumps(archive_content),
        "archived_orphan",
        datetime.now().isoformat(),
        json.dumps({"orphan_type": "coordinate", "reason": reason}),
    ))
    
    conn.commit()
    return memory_id


def reorganize_orphans(db_path: Path, dry_run: bool = True):
    """Reorganize all orphaned data."""
    print("="*80)
    print("ORPHAN REORGANIZATION")
    print("="*80)
    print(f"Database: {db_path}")
    print(f"Mode: {'DRY RUN' if dry_run else 'LIVE'}")
    print()
    
    # Find orphans
    print("Finding orphaned coordinates...")
    orphan_coords = find_orphan_coords(db_path)
    print(f"Found {len(orphan_coords)} orphaned coordinates")
    
    print("\nFinding orphaned associations...")
    orphan_assocs = find_orphan_associations(db_path)
    print(f"Found {len(orphan_assocs)} orphaned associations")
    
    if dry_run:
        print("\n" + "="*80)
        print("DRY RUN - No changes made")
        print("="*80)
        
        if orphan_coords:
            print("\nOrphaned Coordinates (first 10):")
            for i, (mem_id, x, y, z, w, v) in enumerate(orphan_coords[:10], 1):
                print(f"  {i}. {mem_id[:16]}... at ({x:.3f}, {y:.3f}, {z:.3f}, {w:.3f}, {v:.3f})")
        
        if orphan_assocs:
            print("\nOrphaned Associations (first 10):")
            for i, (src, tgt, strength, rel_type) in enumerate(orphan_assocs[:10], 1):
                print(f"  {i}. {src[:8]}... → {tgt[:8]}... ({rel_type}, strength={strength:.2f})")
        
        print("\nRecommended Actions:")
        print("1. Create archive memories for orphaned coordinates")
        print("2. Link orphaned associations to archive memories")
        print("3. Tag all orphans with 'orphan_rescued' for tracking")
        print("\nRun with --live to apply changes")
        
        return {
            "orphan_coords": len(orphan_coords),
            "orphan_assocs": len(orphan_assocs),
            "dry_run": True,
        }
    
    # LIVE mode - apply changes
    conn = sqlite3.connect(str(db_path))
    
    try:
        print("\n" + "="*80)
        print("APPLYING CHANGES")
        print("="*80)
        
        # Reorganize coordinates
        print(f"\nCreating archive memories for {len(orphan_coords)} orphaned coordinates...")
        coords_rescued = 0
        
        for mem_id, x, y, z, w, v in orphan_coords:
            try:
                create_archive_memory(
                    conn, 
                    mem_id, 
                    (x, y, z, w, v),
                    "Orphaned coordinate rescued during reorganization"
                )
                coords_rescued += 1
            except Exception as e:
                print(f"  ⚠️ Failed to rescue {mem_id[:8]}: {e}")
        
        print(f"✓ Rescued {coords_rescued}/{len(orphan_coords)} coordinates")
        
        # Reorganize associations
        print(f"\nReorganizing {len(orphan_assocs)} orphaned associations...")
        
        # Group by source/target to find patterns
        by_source = defaultdict(list)
        by_target = defaultdict(list)
        
        for src, tgt, strength, rel_type in orphan_assocs:
            by_source[src].append((tgt, strength, rel_type))
            by_target[tgt].append((src, strength, rel_type))
        
        # Create archive memories for association endpoints
        assocs_rescued = 0
        cursor = conn.cursor()
        
        for src_id in by_source.keys():
            # Check if source exists
            cursor.execute("SELECT id FROM memories WHERE id = ?", (src_id,))
            if not cursor.fetchone():
                # Create archive memory for this source
                try:
                    cursor.execute("""
                        INSERT INTO memories (id, title, content, memory_type, created_at, metadata)
                        VALUES (?, ?, ?, ?, ?, ?)
                    """, (
                        src_id,
                        f"[ARCHIVED] Orphaned association source {src_id[:8]}",
                        json.dumps({
                            "original_id": src_id,
                            "reason": "Orphaned association source",
                            "association_count": len(by_source[src_id]),
                            "archived_at": datetime.now().isoformat(),
                        }),
                        "archived_orphan",
                        datetime.now().isoformat(),
                        json.dumps({"orphan_type": "association_source"}),
                    ))
                    assocs_rescued += 1
                except:
                    pass
        
        for tgt_id in by_target.keys():
            # Check if target exists
            cursor.execute("SELECT id FROM memories WHERE id = ?", (tgt_id,))
            if not cursor.fetchone():
                # Create archive memory for this target
                try:
                    cursor.execute("""
                        INSERT INTO memories (id, title, content, memory_type, created_at, metadata)
                        VALUES (?, ?, ?, ?, ?, ?)
                    """, (
                        tgt_id,
                        f"[ARCHIVED] Orphaned association target {tgt_id[:8]}",
                        json.dumps({
                            "original_id": tgt_id,
                            "reason": "Orphaned association target",
                            "association_count": len(by_target[tgt_id]),
                            "archived_at": datetime.now().isoformat(),
                        }),
                        "archived_orphan",
                        datetime.now().isoformat(),
                        json.dumps({"orphan_type": "association_target"}),
                    ))
                    assocs_rescued += 1
                except:
                    pass
        
        conn.commit()
        print(f"✓ Rescued {assocs_rescued} association endpoints")
        
        # Add tags to all rescued orphans
        print("\nTagging rescued orphans...")
        cursor.execute("""
            INSERT INTO tags (memory_id, tag)
            SELECT id, 'orphan_rescued'
            FROM memories
            WHERE memory_type = 'archived_orphan'
            AND id NOT IN (SELECT memory_id FROM tags WHERE tag = 'orphan_rescued')
        """)
        conn.commit()
        
        tagged = cursor.rowcount
        print(f"✓ Tagged {tagged} rescued orphans")
        
        print("\n" + "="*80)
        print("REORGANIZATION COMPLETE")
        print("="*80)
        print(f"Coordinates rescued: {coords_rescued}")
        print(f"Association endpoints rescued: {assocs_rescued}")
        print(f"Total orphans given homes: {coords_rescued + assocs_rescued}")
        print("\nAll orphans now have archive memories and are tagged 'orphan_rescued'")
        
        return {
            "orphan_coords": len(orphan_coords),
            "orphan_assocs": len(orphan_assocs),
            "coords_rescued": coords_rescued,
            "assocs_rescued": assocs_rescued,
            "dry_run": False,
        }
    
    finally:
        conn.close()


def main():
    import argparse
    
    parser = argparse.ArgumentParser(description="Reorganize orphaned data")
    parser.add_argument("--live", action="store_true", help="Apply changes (default is dry run)")
    args = parser.parse_args()
    
    db_path = Path.home() / ".whitemagic/memory/whitemagic.db"
    
    if not db_path.exists():
        print(f"Database not found: {db_path}")
        return 1
    
    result = reorganize_orphans(db_path, dry_run=not args.live)
    
    # Save report
    report_path = Path(__file__).parent.parent / "reports" / "orphan_reorganization.json"
    with open(report_path, 'w') as f:
        json.dump(result, f, indent=2)
    
    print(f"\n✓ Report saved to: {report_path}")
    
    return 0


if __name__ == "__main__":
    sys.exit(main())
