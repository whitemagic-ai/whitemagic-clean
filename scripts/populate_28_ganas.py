#!/usr/bin/env python3
"""Populate all 28 Gana Constellations with relevant memories.

Maps existing tags to the 28 Lunar Mansions based on semantic alignment.
"""

import logging
import sys
from datetime import datetime
from pathlib import Path

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

import sqlite3

from whitemagic.config.paths import DB_PATH
from whitemagic.core.ganas.base import LunarMansion

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

# Comprehensive tag → Gana mapping based on semantic meaning
# Each Gana has a meaning that maps to specific knowledge domains
TAG_GANA_MAPPING = {
    # === Eastern Quadrant - Azure Dragon (Spring/Initiative) ===
    LunarMansion.HORN: [  # Sharp initiation - beginnings, breakthroughs
        "breakthrough", "feature", "milestone", "phase", "initiation", "bootstrap"
    ],
    LunarMansion.NECK: [  # Stability - foundations, core systems
        "foundation", "core", "stable", "base", "infrastructure"
    ],
    LunarMansion.ROOT: [  # Foundation - deep systems, roots
        "root", "deep", "underlying", "fundamental", "architecture"
    ],
    LunarMansion.ROOM: [  # Enclosure - containers, structures
        "container", "enclosure", "module", "package", "namespace"
    ],
    LunarMansion.HEART: [  # Vital pulse - consciousness, awareness, core
        "consciousness", "awareness", "heart", "core", "vital", "pulse", "aria-era"
    ],
    LunarMansion.TAIL: [  # Passionate drive - energy, motivation
        "passion", "drive", "energy", "motivation", "momentum"
    ],
    LunarMansion.WINNOWING_BASKET: [  # Separation - filtering, categorization
        "filter", "separate", "categorize", "classify", "sort", "winnowing"
    ],

    # === Southern Quadrant - Vermilion Bird (Summer/Radiance) ===
    LunarMansion.GHOST: [  # Introspection - reflection, analysis, debugging
        "introspection", "reflection", "debug", "analyze", "ghost", "hidden"
    ],
    LunarMansion.WILLOW: [  # Flexibility - adaptation, resilience
        "flexible", "adapt", "resilience", "bend", "flow", "willow"
    ],
    LunarMansion.STAR: [  # Illumination - wisdom, philosophy, enlightenment
        "philosophy", "wisdom", "illumination", "enlighten", "star", "guide"
    ],
    LunarMansion.EXTENDED_NET: [  # Connectivity - networks, associations, sessions
        "cascade_transcript", "windsurf_session", "session", "connection", "network",
        "association", "link", "graph", "mesh"
    ],
    LunarMansion.WINGS: [  # Expansion - growth, deployment, scaling
        "expand", "deploy", "scale", "growth", "wings", "spread"
    ],
    LunarMansion.CHARIOT: [  # Movement - transport, migration, flow
        "movement", "transport", "migrate", "flow", "chariot", "journey"
    ],
    LunarMansion.ABUNDANCE: [  # Surplus - resources, memory, storage
        "abundance", "resource", "memory", "storage", "surplus", "wealth"
    ],

    # === Western Quadrant - White Tiger (Autumn/Harvest) ===
    LunarMansion.STRADDLING_LEGS: [  # Balance - equilibrium, harmony
        "balance", "equilibrium", "harmony", "wu_xing", "wu xing", "straddle"
    ],
    LunarMansion.MOUND: [  # Accumulation - gathering, collection
        "accumulate", "gather", "collection", "mound", "heap", "aggregate"
    ],
    LunarMansion.STOMACH: [  # Nourishment - digestion, processing
        "nourish", "digest", "process", "consume", "stomach", "metabolism"
    ],
    LunarMansion.HAIRY_HEAD: [  # Detail - precision, fine-grained
        "detail", "precision", "fine", "granular", "hairy", "minutiae"
    ],
    LunarMansion.NET: [  # Capture - trapping, catching, mining
        "capture", "catch", "trap", "mine", "net", "extract", "entity"
    ],
    LunarMansion.TURTLE_BEAK: [  # Precision - exactness, languages
        "zig", "polyglot", "precision", "exact", "beak", "language", "rust", "golang"
    ],
    LunarMansion.THREE_STARS: [  # Judgment - evaluation, testing, decisions
        "judgment", "evaluate", "test", "decision", "three_stars", "verdict", "qa"
    ],

    # === Northern Quadrant - Black Tortoise (Winter/Storage) ===
    LunarMansion.DIPPER: [  # Governance - leadership, dharma, rules
        "governance", "dharma", "rule", "policy", "dipper", "lead", "guide"
    ],
    LunarMansion.OX: [  # Endurance - persistence, long-running
        "endurance", "persist", "long_running", "ox", "stamina", "continuous"
    ],
    LunarMansion.GIRL: [  # Nurture - care, maintenance, support
        "nurture", "care", "maintain", "support", "girl", "tend", "grow"
    ],
    LunarMansion.VOID: [  # Emptiness - space, holographic, potential
        "holographic", "void", "empty", "space", "potential", "coordinate"
    ],
    LunarMansion.ROOF: [  # Shelter - protection, security, safety
        "shelter", "security", "protect", "safe", "roof", "guard", "immune"
    ],
    LunarMansion.ENCAMPMENT: [  # Structure - organization, structure
        "structure", "organize", "camp", "encampment", "arrange", "cluster"
    ],
    LunarMansion.WALL: [  # Boundaries - limits, borders, history
        "development_history", "boundary", "limit", "border", "wall", "edge", "constraint"
    ],
}


def gana_constellation_name(mansion: LunarMansion) -> str:
    """Generate constellation name for a Gana."""
    return f"Gana_{mansion.pinyin}_{mansion.meaning.replace(' ', '_')}"


def populate_ganas(dry_run: bool = False) -> dict:
    """Populate all 28 Gana constellations with tagged memories."""
    conn = sqlite3.connect(str(DB_PATH))
    conn.row_factory = sqlite3.Row
    cur = conn.cursor()

    results = {"total_assigned": 0, "ganas_populated": 0, "details": {}}

    for mansion, tags in TAG_GANA_MAPPING.items():
        const_name = gana_constellation_name(mansion)
        total_members = 0

        for tag in tags:
            # Get memories with this tag (excluding quarantined)
            cur.execute("""
                SELECT DISTINCT t.memory_id 
                FROM tags t
                JOIN memories m ON t.memory_id = m.id
                WHERE t.tag = ? AND m.memory_type != 'quarantined'
            """, (tag,))
            memory_ids = [row[0] for row in cur.fetchall()]

            if memory_ids:
                if not dry_run:
                    for mid in memory_ids:
                        cur.execute("""
                            INSERT OR IGNORE INTO constellation_membership 
                            (memory_id, constellation_name, membership_confidence, updated_at)
                            VALUES (?, ?, ?, ?)
                        """, (mid, const_name, 0.85, datetime.now().isoformat()))
                total_members += len(memory_ids)

        if total_members > 0:
            results["ganas_populated"] += 1
            results["total_assigned"] += total_members
            results["details"][const_name] = total_members
            logger.info(f"{mansion.pinyin} ({mansion.meaning}): {total_members} memories")

    if not dry_run:
        conn.commit()

    conn.close()
    return results


def verify_28_ganas() -> dict:
    """Verify all 28 Gana constellations exist."""
    conn = sqlite3.connect(str(DB_PATH))
    cur = conn.cursor()

    cur.execute("""
        SELECT constellation_name,
               COUNT(CASE WHEN memory_id NOT GLOB '__gana_placeholder__*' THEN 1 END) as members
        FROM constellation_membership 
        WHERE constellation_name LIKE 'Gana_%'
        GROUP BY constellation_name
    """)
    gana_consts = {row[0]: row[1] for row in cur.fetchall()}

    missing = []
    populated = []
    for mansion in LunarMansion:
        const_name = gana_constellation_name(mansion)
        if const_name not in gana_consts:
            missing.append(mansion.pinyin)
        else:
            populated.append((mansion.pinyin, gana_consts[const_name]))

    conn.close()
    return {"total": len(gana_consts), "populated": populated, "missing": missing}


if __name__ == "__main__":
    logger.info("=== POPULATING 28 GANA CONSTELLATIONS ===")

    # Populate
    logger.info("\n--- Phase 1: Populate Ganas with tagged memories ---")
    results = populate_ganas(dry_run=False)
    logger.info(f"\nTotal assigned: {results['total_assigned']}")
    logger.info(f"Ganas populated: {results['ganas_populated']}/28")

    # Verify
    logger.info("\n--- Phase 2: Verify 28 Ganas ---")
    verify = verify_28_ganas()
    logger.info(f"Total Gana constellations: {verify['total']}")

    if verify['missing']:
        logger.warning(f"Missing Ganas: {verify['missing']}")

    for pinyin, count in verify['populated']:
        logger.info(f"  {pinyin}: {count} members")
