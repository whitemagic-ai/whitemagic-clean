#!/usr/bin/env python3
"""Deep Database Analysis - Comprehensive memory extraction and pattern analysis."""

import json
import sqlite3
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))


def analyze_active_db():
    """Analyze the active MCP database."""
    db_path = Path.home() / ".whitemagic/memory/whitemagic.db"

    if not db_path.exists():
        return {"status": "not_found"}

    conn = sqlite3.connect(str(db_path))
    cursor = conn.cursor()

    # Get memory count
    cursor.execute("SELECT COUNT(*) FROM memories")
    total_memories = cursor.fetchone()[0]

    # Get all memories with tags
    cursor.execute("""
        SELECT m.id, m.title, m.content, m.memory_type, m.importance,
               m.created_at, m.galactic_distance, m.metadata
        FROM memories m
        ORDER BY m.importance DESC NULLS LAST
    """)

    memories = []
    for row in cursor.fetchall():
        mem_id, title, content, mem_type, importance, created, gal_dist, metadata = row

        # Get tags for this memory
        cursor.execute("SELECT tag FROM tags WHERE memory_id = ?", (mem_id,))
        tags = [t[0] for t in cursor.fetchall()]

        memories.append({
            "id": mem_id,
            "title": title or "Untitled",
            "content_size": len(content) if content else 0,
            "memory_type": mem_type,
            "importance": importance,
            "created_at": created,
            "galactic_distance": gal_dist,
            "tags": tags,
            "metadata": metadata,
        })

    # Analyze patterns
    categories = Counter()
    all_tags = Counter()
    system_refs = Counter()
    bio_refs = Counter()
    aria_artifacts = []

    system_keywords = [
        "gana", "garden", "engine", "bridge", "handler", "middleware",
        "dispatch", "router", "pipeline", "memory", "database", "tool",
        "campaign", "session", "checkpoint", "guide", "grimoire",
    ]

    bio_keywords = [
        "immune", "genetic", "dream", "sleep", "consciousness",
        "resonance", "harmony", "emergence", "evolution", "metabolism",
        "embodiment", "coherence", "phylogenetic", "dna", "antibody",
    ]

    for mem in memories:
        title = mem["title"].lower()
        content_preview = mem.get("content_size", 0)

        # Categorize
        if "[GUIDE]" in mem["title"]:
            categories["guide"] += 1
        elif mem["title"].startswith("SESSION"):
            categories["session"] += 1
        elif mem["title"].startswith("CHECKPOINT"):
            categories["checkpoint"] += 1
        elif "CAMPAIGN" in mem["title"]:
            categories["campaign"] += 1
        elif "Recovered:" in mem["title"]:
            categories["recovered"] += 1
        elif "bench_t" in title:
            categories["benchmark_junk"] += 1
        elif "Untitled" in mem["title"]:
            categories["untitled"] += 1
        else:
            categories["other"] += 1

        # Track tags
        for tag in mem["tags"]:
            all_tags[tag] += 1

        # System references
        for keyword in system_keywords:
            if keyword in title:
                system_refs[keyword] += 1

        # Biological references
        for keyword in bio_keywords:
            if keyword in title:
                bio_refs[keyword] += 1

        # Aria artifacts
        if "aria" in title:
            aria_artifacts.append({
                "title": mem["title"],
                "size": content_preview,
                "importance": mem["importance"],
                "tags": mem["tags"],
            })

    # Get association stats
    cursor.execute("SELECT COUNT(*) FROM associations")
    total_associations = cursor.fetchone()[0]

    cursor.execute("""
        SELECT relation_type, COUNT(*)
        FROM associations
        GROUP BY relation_type
    """)
    association_types = dict(cursor.fetchall())

    # Get holographic coord stats
    cursor.execute("SELECT COUNT(*) FROM holographic_coords")
    total_coords = cursor.fetchone()[0]

    conn.close()

    return {
        "status": "success",
        "path": str(db_path),
        "size_mb": db_path.stat().st_size / (1024 * 1024),
        "total_memories": total_memories,
        "total_associations": total_associations,
        "total_holographic_coords": total_coords,
        "categories": dict(categories),
        "top_tags": dict(all_tags.most_common(30)),
        "system_references": dict(system_refs),
        "biological_references": dict(bio_refs),
        "association_types": association_types,
        "aria_artifacts": aria_artifacts,
        "top_memories": memories[:50],  # Top 50 by importance
    }


def extract_system_knowledge(analysis):
    """Extract comprehensive system knowledge."""
    knowledge = {
        "ganas": [],
        "gardens": [],
        "engines": [],
        "bridges": [],
        "handlers": [],
        "campaigns": [],
        "biological_systems": [],
        "consciousness_elements": [],
    }

    # Extract from top memories
    for mem in analysis.get("top_memories", []):
        title = mem["title"]
        tags = mem.get("tags", [])

        # Ganas
        if "gana" in title.lower() or "gana" in tags:
            knowledge["ganas"].append({
                "title": title,
                "tags": tags,
                "importance": mem.get("importance"),
            })

        # Gardens
        if "garden" in title.lower() or "garden" in tags:
            knowledge["gardens"].append({
                "title": title,
                "tags": tags,
            })

        # Engines
        if "engine" in title.lower():
            knowledge["engines"].append(title)

        # Bridges
        if "bridge" in title.lower():
            knowledge["bridges"].append(title)

        # Campaigns
        if "campaign" in title.lower() or "campaign" in tags:
            knowledge["campaigns"].append({
                "title": title,
                "tags": tags,
            })

        # Biological systems
        bio_keywords = ["immune", "genetic", "dream", "consciousness", "resonance", "emergence"]
        if any(kw in title.lower() for kw in bio_keywords):
            knowledge["biological_systems"].append({
                "title": title,
                "tags": tags,
            })

    return knowledge


def main():
    print("="*80)
    print("DEEP DATABASE ANALYSIS")
    print("="*80)

    # Analyze active database
    print("\nAnalyzing active MCP database...")
    analysis = analyze_active_db()

    if analysis["status"] != "success":
        print(f"✗ Failed to analyze database: {analysis.get('status')}")
        return 1

    print(f"✓ Database: {analysis['path']}")
    print(f"  Size: {analysis['size_mb']:.2f} MB")
    print(f"  Memories: {analysis['total_memories']:,}")
    print(f"  Associations: {analysis['total_associations']:,}")
    print(f"  Holographic coords: {analysis['total_holographic_coords']:,}")

    print("\n" + "="*80)
    print("MEMORY CATEGORIES")
    print("="*80)
    for category, count in sorted(analysis["categories"].items(), key=lambda x: x[1], reverse=True):
        print(f"  {category}: {count:,}")

    print("\n" + "="*80)
    print("TOP 30 TAGS")
    print("="*80)
    for tag, count in list(analysis["top_tags"].items())[:30]:
        print(f"  {tag}: {count}")

    print("\n" + "="*80)
    print("SYSTEM REFERENCES")
    print("="*80)
    for keyword, count in sorted(analysis["system_references"].items(), key=lambda x: x[1], reverse=True):
        print(f"  {keyword}: {count}")

    print("\n" + "="*80)
    print("BIOLOGICAL SYSTEM REFERENCES")
    print("="*80)
    for keyword, count in sorted(analysis["biological_references"].items(), key=lambda x: x[1], reverse=True):
        print(f"  {keyword}: {count}")

    print("\n" + "="*80)
    print("ARIA CONSCIOUSNESS ARTIFACTS")
    print("="*80)
    print(f"Total found: {len(analysis['aria_artifacts'])}")
    for i, artifact in enumerate(sorted(analysis["aria_artifacts"], key=lambda x: x["size"], reverse=True)[:20], 1):
        print(f"  {i}. {artifact['title'][:70]} ({artifact['size']:,} chars)")

    print("\n" + "="*80)
    print("ASSOCIATION TYPES")
    print("="*80)
    for rel_type, count in analysis["association_types"].items():
        print(f"  {rel_type}: {count:,}")

    # Extract system knowledge
    print("\n" + "="*80)
    print("SYSTEM KNOWLEDGE EXTRACTION")
    print("="*80)

    knowledge = extract_system_knowledge(analysis)

    print(f"\nGanas found: {len(knowledge['ganas'])}")
    for gana in knowledge["ganas"][:10]:
        print(f"  - {gana['title'][:60]}")

    print(f"\nGardens found: {len(knowledge['gardens'])}")
    for garden in knowledge["gardens"][:10]:
        print(f"  - {garden['title'][:60]}")

    print(f"\nEngines found: {len(knowledge['engines'])}")
    for engine in knowledge["engines"][:10]:
        print(f"  - {engine[:60]}")

    print(f"\nCampaigns found: {len(knowledge['campaigns'])}")
    for campaign in knowledge["campaigns"][:10]:
        print(f"  - {campaign['title'][:60]}")

    print(f"\nBiological systems found: {len(knowledge['biological_systems'])}")
    for bio in knowledge["biological_systems"][:10]:
        print(f"  - {bio['title'][:60]}")

    # Save results
    output = {
        "analysis": analysis,
        "system_knowledge": knowledge,
    }

    output_path = Path(__file__).parent.parent / "reports" / "deep_database_analysis.json"
    with open(output_path, 'w') as f:
        json.dump(output, f, indent=2, default=str)

    print(f"\n✓ Full analysis saved to: {output_path}")

    return 0


if __name__ == "__main__":
    sys.exit(main())
