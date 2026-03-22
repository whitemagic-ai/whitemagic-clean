#!/usr/bin/env python3
"""Fold 9 Potential Gardens into 28 Gana Constellations.

Maps Omega Pulse-identified themes to their appropriate Lunar Mansion:
- zig, polyglot → TURTLE_BEAK (Precision) - language precision
- cascade_transcript, windsurf_session → EXTENDED_NET (Connectivity) - session flows
- development_history → WALL (Boundaries) - code boundaries/history
- philosophy → STAR (Illumination) - wisdom/knowledge
- holographic → VOID (Emptiness) - spatial/empty space
- breakthrough → HORN (Sharp initiation) - new beginnings
- consciousness → HEART (Vital pulse) - core awareness
"""

import logging
import sqlite3
import sys
from datetime import datetime
from pathlib import Path

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

def _ensure_project_root_on_path() -> None:
    project_root = Path(__file__).parent.parent
    root_str = str(project_root)
    if root_str not in sys.path:
        sys.path.insert(0, root_str)


def _get_db_path() -> Path:
    _ensure_project_root_on_path()
    from whitemagic.config.paths import DB_PATH

    return DB_PATH


def _get_lunar_mansion():
    _ensure_project_root_on_path()
    from whitemagic.core.ganas.base import LunarMansion

    return LunarMansion


def _get_theme_gana_mapping() -> dict:
    LunarMansion = _get_lunar_mansion()
    return {
        "zig": LunarMansion.TURTLE_BEAK,
        "polyglot": LunarMansion.TURTLE_BEAK,
        "cascade_transcript": LunarMansion.EXTENDED_NET,
        "windsurf_session": LunarMansion.EXTENDED_NET,
        "development_history": LunarMansion.WALL,
        "philosophy": LunarMansion.STAR,
        "holographic": LunarMansion.VOID,
        "breakthrough": LunarMansion.HORN,
        "consciousness": LunarMansion.HEART,
        "entity:SYSTEM:BM25": LunarMansion.NET,
    }

# Gana constellation naming convention
def gana_constellation_name(mansion) -> str:
    """Generate constellation name for a Gana."""
    return f"Gana_{mansion.pinyin}_{mansion.meaning.replace(' ', '_')}"


def get_current_constellations(conn: sqlite3.Connection) -> dict:
    """Get current constellation membership counts."""
    cur = conn.cursor()
    cur.execute("""
        SELECT constellation_name,
               COUNT(CASE WHEN memory_id NOT GLOB '__gana_placeholder__*' THEN 1 END) as members
        FROM constellation_membership 
        GROUP BY constellation_name
    """)
    return {row[0]: row[1] for row in cur.fetchall()}


def get_tagged_memories(conn: sqlite3.Connection, tag: str) -> list:
    """Get memory IDs for a specific tag."""
    cur = conn.cursor()
    cur.execute("SELECT memory_id FROM tags WHERE tag = ?", (tag,))
    return [row[0] for row in cur.fetchall()]


def create_gana_constellations(conn: sqlite3.Connection, dry_run: bool = False) -> dict:
    """Create or update Gana-aligned constellations."""
    cur = conn.cursor()
    results = {"created": 0, "updated": 0, "members_assigned": 0}
    theme_gana_mapping = _get_theme_gana_mapping()

    # Get current state
    current = get_current_constellations(conn)
    logger.info(f"Current constellations: {len(current)}")

    # Process each theme
    for theme, mansion in theme_gana_mapping.items():
        const_name = gana_constellation_name(mansion)

        # Get memories with this tag
        memory_ids = get_tagged_memories(conn, theme)

        if not memory_ids:
            logger.info(f"No memories found for theme '{theme}'")
            continue

        logger.info(f"Theme '{theme}' → {mansion.pinyin} ({mansion.meaning}): {len(memory_ids)} memories")

        # Check if constellation exists
        if const_name not in current:
            # Create new constellation
            if not dry_run:
                for mid in memory_ids:
                    cur.execute("""
                        INSERT OR IGNORE INTO constellation_membership 
                        (memory_id, constellation_name, membership_confidence, updated_at)
                        VALUES (?, ?, ?, ?)
                    """, (mid, const_name, 0.8, datetime.now().isoformat()))
            results["created"] += 1
            results["members_assigned"] += len(memory_ids)
            logger.info(f"  Created constellation '{const_name}' with {len(memory_ids)} members")
        else:
            # Add to existing
            if not dry_run:
                for mid in memory_ids:
                    cur.execute("""
                        INSERT OR IGNORE INTO constellation_membership 
                        (memory_id, constellation_name, membership_confidence, updated_at)
                        VALUES (?, ?, ?, ?)
                    """, (mid, const_name, 0.8, datetime.now().isoformat()))
            results["updated"] += 1
            results["members_assigned"] += len(memory_ids)
            logger.info(f"  Updated constellation '{const_name}' (+{len(memory_ids)} members)")

    if not dry_run:
        conn.commit()

    return results


def ensure_all_28_ganas(conn: sqlite3.Connection, dry_run: bool = False) -> dict:
    """Ensure all 28 Gana constellations exist (even if empty)."""
    cur = conn.cursor()
    results = {"created": 0}
    LunarMansion = _get_lunar_mansion()

    current = get_current_constellations(conn)

    for mansion in LunarMansion:
        const_name = gana_constellation_name(mansion)

        if const_name not in current:
            logger.info(f"Creating empty Gana constellation: {const_name}")
            if not dry_run:
                # Create placeholder entry (will be populated later)
                cur.execute("""
                    INSERT OR IGNORE INTO constellation_membership 
                    (memory_id, constellation_name, membership_confidence, updated_at)
                    VALUES (?, ?, ?, ?)
                """, (f"__gana_placeholder__:{const_name}", const_name, 0.0, datetime.now().isoformat()))
            results["created"] += 1

    if not dry_run:
        conn.commit()

    return results


def main():
    logger.info("=== FOLDING GARDENS INTO 28 GANAS ===")

    conn = sqlite3.connect(str(_get_db_path()))

    # Step 1: Create Gana-aligned constellations from themes
    logger.info("\n--- Phase 1: Map themes to Ganas ---")
    results1 = create_gana_constellations(conn, dry_run=False)
    logger.info(f"Results: {results1}")

    # Step 2: Ensure all 28 Ganas exist
    logger.info("\n--- Phase 2: Ensure all 28 Ganas ---")
    results2 = ensure_all_28_ganas(conn, dry_run=False)
    logger.info(f"Results: {results2}")

    # Final count
    logger.info("\n--- Final State ---")
    final = get_current_constellations(conn)
    gana_count = sum(1 for name in final.keys() if name.startswith("Gana_"))
    logger.info(f"Total constellations: {len(final)}")
    logger.info(f"Gana constellations: {gana_count}/28")

    conn.close()

    return {"themes_folded": results1, "ganas_created": results2, "total_constellations": len(final)}


if __name__ == "__main__":
    main()
