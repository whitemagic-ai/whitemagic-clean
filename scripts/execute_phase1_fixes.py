#!/usr/bin/env python3
"""Execute Phase 1 Automated Fixes from Omega Pulse V22 Action Plan.

This script runs all auto-fixable Kaizen proposals:
1. Fix untitled memories
2. Auto-tag untagged memories
3. Prune broken associations
4. Merge exact duplicate titles
"""

import logging
import sys
from pathlib import Path

# Add project root to path
project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)


def fix_untitled():
    """Fix untitled memories using TitleGenerator."""
    logger.info("--- Fixing Untitled Memories ---")
    try:
        from whitemagic.core.intelligence.synthesis.title_generator import (
            get_title_generator,
        )
        tg = get_title_generator()
        result = tg.fix_all(dry_run=False)
        logger.info(f"Fixed {result['fixed']} untitled memories, skipped {result['skipped']}")
        return result
    except Exception as e:
        logger.error(f"Error fixing untitled: {e}")
        return {"error": str(e)}


def auto_tag_untagged():
    """Auto-tag memories without tags."""
    logger.info("--- Auto-Tagging Untagged Memories ---")
    try:
        from whitemagic.core.intelligence.synthesis.tag_normalizer import (
            get_tag_normalizer,
        )
        tn = get_tag_normalizer()
        result = tn.auto_tag_untagged(dry_run=False)
        logger.info(f"Tagged {result['tagged']} memories, skipped {result['skipped']}")
        return result
    except Exception as e:
        logger.error(f"Error auto-tagging: {e}")
        return {"error": str(e)}


def prune_broken_associations():
    """Prune broken associations (high-strength links to decayed memories)."""
    logger.info("--- Pruning Broken Associations ---")
    try:
        from whitemagic.core.intelligence.core_access import get_core_access
        cal = get_core_access()
        broken = cal.find_broken_associations(limit=1000)

        if not broken:
            logger.info("No broken associations found")
            return {"pruned": 0}

        # Get DB connection and prune
        import sqlite3

        from whitemagic.config.paths import DB_PATH
        conn = sqlite3.connect(str(DB_PATH))
        cur = conn.cursor()

        pruned = 0
        for assoc in broken:
            # Delete association - correct column names are source_id and target_id
            cur.execute(
                "DELETE FROM associations WHERE source_id = ? OR target_id = ?",
                (assoc["source_id"], assoc["target_id"])
            )
            pruned += cur.rowcount

        conn.commit()
        conn.close()
        logger.info(f"Pruned {pruned} broken associations")
        return {"pruned": pruned, "sample": broken[:5]}
    except Exception as e:
        logger.error(f"Error pruning associations: {e}")
        return {"error": str(e)}


def merge_exact_duplicates():
    """Merge memories with exact duplicate titles."""
    logger.info("--- Merging Exact Duplicate Titles ---")
    try:
        import sqlite3

        from whitemagic.config.paths import DB_PATH

        conn = sqlite3.connect(str(DB_PATH))
        conn.row_factory = sqlite3.Row
        cur = conn.cursor()

        # Find duplicate titles
        cur.execute("""
            SELECT title, COUNT(*) as cnt
            FROM memories
            WHERE memory_type != 'quarantined'
            GROUP BY title
            HAVING cnt > 1
            ORDER BY cnt DESC
        """)
        duplicates = cur.fetchall()

        if not duplicates:
            logger.info("No exact duplicate titles found")
            return {"merged": 0}

        merged = 0
        kept_ids = []
        for dup in duplicates[:100]:  # Limit to first 100 groups
            title = dup["title"]
            dup["cnt"]

            # Get all memories with this title
            cur.execute(
                "SELECT id, created_at FROM memories WHERE title = ? AND memory_type != 'quarantined' ORDER BY created_at DESC",
                (title,)
            )
            mems = cur.fetchall()

            if len(mems) < 2:
                continue

            # Keep the newest, mark others for merge
            keep_id = mems[0]["id"]
            merge_ids = [m["id"] for m in mems[1:]]

            # For now, just log - actual merge requires careful handling of associations
            merged += len(merge_ids)
            kept_ids.append(keep_id)

        conn.close()
        logger.info(f"Found {merged} candidates for merging across {len(duplicates)} duplicate title groups")
        logger.info("Note: Actual merge requires careful association migration - logging only")
        return {"merged_candidates": merged, "duplicate_groups": len(duplicates)}
    except Exception as e:
        logger.error(f"Error merging duplicates: {e}")
        return {"error": str(e)}


def main():
    """Run all Phase 1 fixes."""
    logger.info("=== PHASE 1 AUTOMATED FIXES ===")
    logger.info("Starting execution...")

    results = {
        "untitled": fix_untitled(),
        "auto_tag": auto_tag_untagged(),
        "broken_associations": prune_broken_associations(),
        "duplicates": merge_exact_duplicates(),
    }

    logger.info("\n=== PHASE 1 COMPLETE ===")
    for name, result in results.items():
        if "error" in result:
            logger.warning(f"{name}: ERROR - {result['error']}")
        else:
            logger.info(f"{name}: {result}")

    return results


if __name__ == "__main__":
    main()
