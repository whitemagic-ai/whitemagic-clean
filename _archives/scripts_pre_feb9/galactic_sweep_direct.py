#!/usr/bin/env python3
"""
Direct Galactic Sweep — bypasses heavy system init.
Operates directly on SQLite to tag all memories with retention scores + galactic distance.
"""

import sqlite3
import sys
import time
import math
from datetime import datetime
from pathlib import Path

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"


def compute_retention_score(row):
    """
    Compute a multi-signal retention score from raw DB row fields.
    
    Designed to create a meaningful galactic distribution:
    - PATTERN / actively-used memories → CORE (high retention)
    - LONG_TERM / recently created → INNER_RIM
    - SHORT_TERM → MID_BAND  
    - scavenged (bulk-ingested reference) → OUTER_RIM
    - deep_archive (bulk-ingested, never accessed) → FAR_EDGE
    """
    importance = row["importance"] or 0.5
    row["neuro_score"] or 1.0
    emotional_valence = abs(row["emotional_valence"] or 0.0)
    recall_count = row["recall_count"] or 0
    access_count = row["access_count"] or 0
    is_protected = row["is_protected"] or 0
    mem_type = (row["memory_type"] or "").lower()
    title = row["title"] or ""
    content = str(row["content"] or "")

    # ── Signal 1: Type baseline (strong differentiator) ──
    # This is the primary axis since most memories have identical numeric fields
    type_baselines = {
        "pattern": 0.92,       # Distilled wisdom → CORE
        "long_term": 0.75,    # Important memories → INNER_RIM
        "short_term": 0.55,   # Working memory → MID_BAND
        "scavenged": 0.35,    # Bulk-ingested reference → MID_BAND/OUTER_RIM
        "deep_archive": 0.20, # Deep bulk storage → OUTER_RIM/FAR_EDGE
    }
    s_type = type_baselines.get(mem_type, 0.40)

    # ── Signal 2: Activity (ever been accessed or recalled?) ──
    if recall_count > 5:
        s_activity = 1.0
    elif recall_count > 0 or access_count > 0:
        s_activity = 0.6 + min(0.4, (recall_count + access_count) / 20.0)
    else:
        s_activity = 0.0  # Never touched

    # ── Signal 3: Recency ──
    created = row["created_at"] or ""
    try:
        if isinstance(created, str) and created:
            ts = datetime.fromisoformat(created[:26].split('+')[0].split('Z')[0])
            age_days = max(0, (datetime.now() - ts).days)
        else:
            age_days = 9999
    except Exception:
        age_days = 9999
    # Exponential decay: half-life of 30 days
    s_recency = math.exp(-0.693 * age_days / 30.0)

    # ── Signal 4: Emotional resonance ──
    s_emotion = min(1.0, emotional_valence * 1.5)  # Amplify emotional signal

    # ── Signal 5: Content richness ──
    # Longer, richer content with meaningful titles score higher
    content_len = len(content)
    if content_len > 5000:
        s_richness = 0.8
    elif content_len > 1000:
        s_richness = 0.5
    elif content_len > 200:
        s_richness = 0.3
    else:
        s_richness = 0.1
    
    # Title quality bonus: meaningful titles vs bare filenames
    title_lower = title.lower()
    if any(kw in title_lower for kw in ['pattern', 'insight', 'wisdom', 'principle', 'strategy']):
        s_richness = min(1.0, s_richness + 0.3)
    elif any(kw in title_lower for kw in ['recovered:', 'report', 'assessment', 'analysis']):
        s_richness = min(1.0, s_richness + 0.15)

    # ── Signal 6: Protection / importance flags ──
    s_protection = 1.0 if is_protected else 0.0
    s_importance = min(1.0, importance)

    # ── Weighted composite ──
    # Type baseline is the strongest signal (35%) since most numeric fields are defaults
    # Richness gets 20% to spread within types based on content quality
    score = (
        s_type * 0.35
        + s_activity * 0.10
        + s_recency * 0.10
        + s_emotion * 0.05
        + s_richness * 0.20
        + s_importance * 0.10
        + s_protection * 0.10
    )

    # Content-hash-based jitter to spread within zones (±0.05)
    import hashlib
    h = int(hashlib.md5((row["id"] or "").encode()).hexdigest()[:8], 16)
    jitter = ((h % 1000) / 1000.0 - 0.5) * 0.10
    score += jitter

    return max(0.0, min(1.0, score))


def retention_to_distance(retention, is_protected, is_pinned=False):
    """Convert retention score to galactic distance (inverse)."""
    if is_protected or is_pinned:
        return 0.0
    return max(0.0, min(1.0, 1.0 - retention))


def classify_zone(distance):
    if distance < 0.15:
        return "CORE"
    elif distance < 0.40:
        return "INNER_RIM"
    elif distance < 0.65:
        return "MID_BAND"
    elif distance < 0.85:
        return "OUTER_RIM"
    else:
        return "FAR_EDGE"


def main():
    dry_run = "--dry-run" in sys.argv
    batch_size = 2000

    print("🌌 Galactic Sweep — Direct DB Mode")
    print("=" * 60)

    if not DB_PATH.exists():
        print(f"❌ Database not found: {DB_PATH}")
        sys.exit(1)

    conn = sqlite3.connect(str(DB_PATH))
    conn.row_factory = sqlite3.Row

    total = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    print(f"📊 Database: {total:,} memories at {DB_PATH}")

    if dry_run:
        print("🔍 DRY RUN — no changes will be written\n")

    # Process in batches
    zone_counts = {"CORE": 0, "INNER_RIM": 0, "MID_BAND": 0, "OUTER_RIM": 0, "FAR_EDGE": 0}
    total_ret = 0.0
    total_dist = 0.0
    processed = 0
    now_iso = datetime.now().isoformat()
    updates = []
    start = time.perf_counter()

    cursor = conn.execute(
        "SELECT id, content, memory_type, created_at, accessed_at, access_count, "
        "emotional_valence, importance, neuro_score, novelty_score, recall_count, "
        "half_life_days, is_protected, metadata, title FROM memories"
    )

    for row in cursor:
        retention = compute_retention_score(row)
        is_prot = bool(row["is_protected"])
        distance = retention_to_distance(retention, is_prot)
        zone = classify_zone(distance)

        zone_counts[zone] += 1
        total_ret += retention
        total_dist += distance
        processed += 1

        updates.append((distance, retention, now_iso, row["id"]))

        # Print first 10
        if processed <= 10:
            title = (row["title"] or str(row["content"])[:50]).strip()[:50]
            print(
                f"  [{zone:>10}] dist={distance:.3f} ret={retention:.3f} "
                f"| {title}"
            )

        # Batch write
        if not dry_run and len(updates) >= batch_size:
            conn.executemany(
                "UPDATE memories SET galactic_distance=?, retention_score=?, last_retention_sweep=? WHERE id=?",
                updates,
            )
            conn.commit()
            updates = []

        if processed % 10000 == 0:
            elapsed = time.perf_counter() - start
            rate = processed / elapsed if elapsed > 0 else 0
            print(f"  ... {processed:,}/{total:,} ({rate:.0f}/s)")

    # Final batch
    if not dry_run and updates:
        conn.executemany(
            "UPDATE memories SET galactic_distance=?, retention_score=?, last_retention_sweep=? WHERE id=?",
            updates,
        )
        conn.commit()

    elapsed = time.perf_counter() - start
    conn.close()

    print(f"\n{'✅ Galactic Sweep Complete!' if not dry_run else '✅ Dry Run Complete!'}")
    print(f"   Memories processed: {processed:,}/{total:,}")
    print(f"   Duration: {elapsed:.2f}s ({processed / max(elapsed, 0.01):.0f}/s)")
    print()
    print("📊 Zone Distribution:")
    n = max(processed, 1)
    for zone_name, count in zone_counts.items():
        pct = count / n * 100
        bar = "█" * int(pct / 2)
        print(f"  {zone_name:>12}: {count:6,} ({pct:5.1f}%) {bar}")

    print(f"\n   📈 Avg retention: {total_ret / n:.4f}")
    print(f"   📐 Avg distance:  {total_dist / n:.4f}")

    if dry_run:
        print("\n🔁 Run without --dry-run to persist changes.")


if __name__ == "__main__":
    main()
