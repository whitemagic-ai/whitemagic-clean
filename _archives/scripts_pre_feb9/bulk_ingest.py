#!/usr/bin/env python3
"""
Bulk memory ingestion — pulls memories from all archive sources into the
holographic memory core (memory/whitemagic.db).

Sources (in priority order):
  1. Legacy SQLite DB   — 570 new memories + 653 holographic_coords + akashic_seeds
  2. events.jsonl       — filtered to meaningful types only (1,448 est.)
  3. emotions.jsonl     — 11 rich emotional memories
  4. awareness.jsonl    — 398 self-awareness snapshots
  5. resonance_history  — 803 resonance events
  6. depth_gauge        — 226 session-layer records
  7. token_economy      — 1,123 token-usage records
  8. recovered_memories — 4,255 file-scan + anthropology entries
  9. audit/*.jsonl      — daily audit logs (~726 total)

Deduplication: content-hash based.  Legacy coords are preserved as-is;
everything else gets coordinates encoded via CoordinateEncoder at the end.
"""

import json
import hashlib
import sqlite3
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent          # project root
MEM_DB = ROOT / "memory" / "whitemagic.db"

# ---------------------------------------------------------------------------
# Source paths
# ---------------------------------------------------------------------------
LEGACY_DB = ROOT / "archive/restoration/legacy_data_backup/homedirectory_dot_whitemagic_backup/memory/whitemagic.db"
# The recovered_config copy is byte-identical to the backup above — skip it.

EVENTS_FILE     = ROOT / "archive/restoration/magicbackup/.whitemagic/events.jsonl"
EMOTIONS_FILE   = ROOT / "archive/restoration/magicbackup/.whitemagic/emotional_memories/emotions.jsonl"
AWARENESS_FILE  = ROOT / "archive/restoration/magicbackup/.whitemagic/awareness.jsonl"
RESONANCE_FILE  = ROOT / "archive/restoration/magicbackup/.whitemagic/resonance_history.jsonl"
DEPTH_FILE      = ROOT / "archive/restoration/magicbackup/.whitemagic/depth_gauge.jsonl"
TOKEN_FILE      = ROOT / "archive/restoration/magicbackup/.whitemagic/token_economy.jsonl"
RECOVERED_FILE  = ROOT / "data/recovered_memories.jsonl"
AUDIT_DIR       = ROOT / "archive/restoration/magicbackup/.whitemagic/audit"

# Only these event types are worth ingesting (skip 31K voice_expressed / system_started)
EVENTS_WHITELIST = {"memory_created", "oracle_cast", "pattern_detected", "memory_recalled"}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------
def content_hash(text: str) -> str:
    return hashlib.sha256(text.encode()).hexdigest()[:16]


def load_existing(db_path) -> tuple[set, set]:
    """Return (set of existing IDs, set of content-hashes) for dedup."""
    conn = sqlite3.connect(str(db_path))
    rows = conn.execute("SELECT id, content FROM memories").fetchall()
    conn.close()
    ids = {r[0] for r in rows}
    chashes = {content_hash(r[1]) for r in rows if r[1]}
    return ids, chashes


# ---------------------------------------------------------------------------
# Legacy DB import
# ---------------------------------------------------------------------------
def import_legacy(live_conn, existing_ids, existing_chashes):
    if not LEGACY_DB.exists():
        print("  LEGACY DB not found — skipped")
        return 0, 0, 0, 0

    legacy = sqlite3.connect(str(LEGACY_DB))

    # --- memories ---
    rows = legacy.execute(
        "SELECT id, content, memory_type, created_at, accessed_at, access_count, "
        "emotional_valence, importance, metadata, title, "
        "neuro_score, novelty_score, recall_count, half_life_days, is_protected, "
        "gana_processed, gana_context, quadrant "
        "FROM memories"
    ).fetchall()

    mem_imported = 0
    for (mem_id, content, mem_type, created_at, accessed_at, access_count,
         ev_val, importance, metadata_raw, title,
         neuro, novelty, recall_ct, half_life, is_prot,
         gana_proc, gana_ctx, quadrant) in rows:

        if mem_id in existing_ids:
            continue
        if content and content_hash(content) in existing_chashes:
            continue

        # Merge legacy-only fields into metadata
        meta = json.loads(metadata_raw) if metadata_raw else {}
        if gana_proc:  meta["gana_processed"] = gana_proc
        if gana_ctx:   meta["gana_context"]   = gana_ctx
        if quadrant:   meta["quadrant"]       = quadrant

        live_conn.execute(
            "INSERT OR IGNORE INTO memories "
            "(id, content, memory_type, created_at, updated_at, accessed_at, "
            " access_count, emotional_valence, importance, neuro_score, "
            " novelty_score, recall_count, half_life_days, is_protected, metadata, title) "
            "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
            (mem_id, content, mem_type, created_at, created_at, accessed_at,
             access_count, ev_val, importance, neuro,
             novelty, recall_ct, half_life, is_prot, json.dumps(meta), title)
        )
        existing_ids.add(mem_id)
        if content:
            existing_chashes.add(content_hash(content))
        mem_imported += 1

    # --- tags ---
    tags = legacy.execute("SELECT memory_id, tag FROM tags").fetchall()
    tag_imported = 0
    for mem_id, tag in tags:
        if mem_id in existing_ids:          # only for memories we care about
            try:
                live_conn.execute(
                    "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?,?)",
                    (mem_id, tag)
                )
                tag_imported += 1
            except Exception:
                pass

    # --- holographic_coords  (preserve legacy coords as-is) ---
    coords = legacy.execute("SELECT memory_id, x, y, z, w FROM holographic_coords").fetchall()
    coord_imported = 0
    for mem_id, x, y, z, w in coords:
        # Only insert if the memory exists in live now AND coord not already there
        exists = live_conn.execute("SELECT 1 FROM memories WHERE id=?", (mem_id,)).fetchone()
        if not exists:
            continue
        already = live_conn.execute(
            "SELECT 1 FROM holographic_coords WHERE memory_id=?", (mem_id,)
        ).fetchone()
        if already:
            continue
        live_conn.execute(
            "INSERT INTO holographic_coords (memory_id, x, y, z, w) VALUES (?,?,?,?,?)",
            (mem_id, x, y, z, w)
        )
        coord_imported += 1

    # --- akashic_seeds ---
    seeds = legacy.execute("SELECT id, content, bloom_conditions, planted_at, "
                           "times_bloomed, last_bloomed, potency, keywords FROM akashic_seeds").fetchall()
    seed_imported = 0
    for seed in seeds:
        try:
            live_conn.execute(
                "INSERT OR IGNORE INTO akashic_seeds "
                "(id, content, bloom_conditions, planted_at, times_bloomed, last_bloomed, potency, keywords) "
                "VALUES (?,?,?,?,?,?,?,?)",
                seed
            )
            seed_imported += 1
        except Exception:
            pass

    legacy.close()
    return mem_imported, tag_imported, coord_imported, seed_imported


# ---------------------------------------------------------------------------
# JSONL → memory converters
# ---------------------------------------------------------------------------
def _event_to_mem(ev):
    data = ev.get("data", {})
    text = data.get("text", "")
    orig = data.get("original_data", {})
    story = data.get("story", "")
    etype = ev.get("type", "event")

    parts = []
    if text:   parts.append(text)
    if orig:   parts.append(f"[{etype}] {json.dumps(orig, ensure_ascii=False)}")
    if story:  parts.append(f"session: {story}")
    content = " | ".join(parts) if parts else json.dumps(ev)

    tags = [etype, ev.get("source", "")]
    meta = {"source": "events.jsonl", "event_type": etype}
    return content, etype, ev.get("timestamp", ""), tags, meta


def _emotion_to_mem(em):
    parts = []
    if em.get("description"):       parts.append(em["description"])
    if em.get("felt_experience"):   parts.append(f"Felt: {em['felt_experience']}")
    if em.get("context"):           parts.append(f"Context: {em['context']}")
    content = " | ".join(parts)

    tags = em.get("tags", []) + [em.get("emotion_type", "")]
    meta = {"source": "emotions.jsonl",
            "emotion_type": em.get("emotion_type"),
            "intensity": em.get("intensity")}
    return content, "emotion", em.get("timestamp", ""), tags, meta


def _awareness_to_mem(item):
    parts = []
    if item.get("patterns"):    parts.append("Patterns: " + ", ".join(item["patterns"]))
    if item.get("adjustments"): parts.append("Adjustments: " + ", ".join(item["adjustments"]))
    snap = item.get("snapshot", {})
    if snap: parts.append(f"Snapshot: {json.dumps(snap)}")
    content = " | ".join(parts) if parts else json.dumps(item)

    meta = {"source": "awareness.jsonl",
            "drift": item.get("drift", {}),
            "meta": item.get("meta", {})}
    return content, "awareness", item.get("timestamp", ""), ["awareness", "self_aware"], meta


def _resonance_to_mem(item):
    data = item.get("data", {})
    etype = item.get("event_type", "")
    conf  = item.get("confidence", 0)
    content = f"[resonance:{etype}] confidence={conf} | {json.dumps(data)}"

    meta = {"source": "resonance_history.jsonl", "confidence": conf, "event_type": etype}
    return content, "resonance", item.get("timestamp", ""), ["resonance", etype], meta


def _depth_to_mem(item):
    layer = item.get("layer", "")
    cr    = item.get("compression_ratio", 0)
    wo    = item.get("work_output", {})
    tokens = item.get("token_usage", 0)
    content = f"[depth:{layer}] compression={cr:.1f}x | tokens={tokens} | work={json.dumps(wo)}"

    meta = {"source": "depth_gauge.jsonl", "layer": layer, "compression_ratio": cr}
    return content, "depth_gauge", item.get("timestamp", ""), ["depth_gauge", layer], meta


def _token_to_mem(item):
    op   = item.get("operation_type", "")
    desc = item.get("description", "")
    toks = item.get("api_tokens", 0)
    cpu  = item.get("local_cpu_ms", 0)
    content = f"[token:{op}] {desc} | api_tokens={toks} cpu_ms={cpu}"

    meta = {"source": "token_economy.jsonl"}
    return content, "token_economy", item.get("timestamp", ""), ["token_economy", op], meta


def _recovered_to_mem(item):
    name  = item.get("name", "")
    path  = item.get("path", "")
    anthro = item.get("anthropology", {})
    chapters = anthro.get("chapters", []) if isinstance(anthro, dict) else []
    top = sorted(chapters, key=lambda c: c.get("score", 0), reverse=True)[:3]
    chap_str = ", ".join(f"{c.get('title','?')}:{c.get('score',0)}" for c in top)
    content = f"[file:{name}] {path} | themes: {chap_str}" if chap_str else f"[file:{name}] {path}"

    meta = {"source": "recovered_memories.jsonl", "anthropology": anthro}
    return content, "recovered_file", "", ["recovered", "anthropology"], meta


def _audit_to_mem(item):
    action = item.get("action", item.get("type", "audit"))
    detail = item.get("detail", item.get("data", ""))
    ts     = item.get("timestamp", "")
    content = f"[audit:{action}] {json.dumps(detail) if isinstance(detail, dict) else str(detail)}"

    meta = {"source": "audit"}
    return content, "audit", ts, ["audit", action], meta


# ---------------------------------------------------------------------------
# Generic JSONL ingester
# ---------------------------------------------------------------------------
def ingest_jsonl(live_conn, filepath, converter, existing_ids, existing_chashes,
                 event_filter=None):
    imported = skipped_dup = skipped_filter = 0

    with open(filepath) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
            except json.JSONDecodeError:
                continue

            if event_filter and obj.get("type") not in event_filter:
                skipped_filter += 1
                continue

            content, mem_type, timestamp, tags, meta = converter(obj)
            if not content or len(content) < 5:
                continue

            mem_id = content_hash(content)
            if mem_id in existing_ids or mem_id in existing_chashes:
                skipped_dup += 1
                continue

            try:
                live_conn.execute(
                    "INSERT OR IGNORE INTO memories "
                    "(id, content, memory_type, created_at, updated_at, metadata, title) "
                    "VALUES (?,?,?,?,?,?,?)",
                    (mem_id, content, mem_type, timestamp, timestamp,
                     json.dumps(meta), content[:80])
                )
                for tag in tags:
                    if tag:
                        live_conn.execute(
                            "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?,?)",
                            (mem_id, tag)
                        )
                imported += 1
                existing_ids.add(mem_id)
                existing_chashes.add(mem_id)
            except Exception as e:
                print(f"    INSERT error ({mem_id[:8]}): {e}")

    return imported, skipped_dup, skipped_filter


# ---------------------------------------------------------------------------
# Holographic coordinate encoding for newly-inserted memories
# ---------------------------------------------------------------------------
def encode_missing_coords(live_conn):
    sys.path.insert(0, str(ROOT))
    from whitemagic.intelligence.hologram.encoder import CoordinateEncoder
    encoder = CoordinateEncoder()

    rows = live_conn.execute("""
        SELECT m.id, m.content, m.metadata, m.memory_type, m.title
        FROM memories m
        LEFT JOIN holographic_coords h ON m.id = h.memory_id
        WHERE h.memory_id IS NULL
    """).fetchall()

    encoded = 0
    for mem_id, content, meta_raw, mem_type, title in rows:
        try:
            meta = json.loads(meta_raw) if meta_raw else {}
            tag_rows = live_conn.execute(
                "SELECT tag FROM tags WHERE memory_id=?", (mem_id,)
            ).fetchall()
            mem_dict = {
                "content": content or "",
                "type":    mem_type or "",
                "tags":    [r[0] for r in tag_rows],
                "title":   title or "",
                "metadata": meta,
            }
            coords = encoder.encode(mem_dict)
            live_conn.execute(
                "INSERT OR IGNORE INTO holographic_coords (memory_id, x, y, z, w) "
                "VALUES (?,?,?,?,?)",
                (mem_id, coords.x, coords.y, coords.z, coords.w)
            )
            encoded += 1
        except Exception as e:
            print(f"    Coord-encode error ({mem_id[:8]}): {e}")
            break          # likely an encoder import failure — don't spam

    return encoded


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    start = time.time()
    print("=" * 62)
    print("  HOLOGRAPHIC MEMORY — BULK INGEST")
    print("=" * 62)

    existing_ids, existing_chashes = load_existing(MEM_DB)
    print(f"\n  Live DB baseline: {len(existing_ids)} memories")

    live = sqlite3.connect(str(MEM_DB))
    total_new = 0

    # 1) Legacy DB
    print("\n  [1/8] Legacy DB …", flush=True)
    mems, tags, coords, seeds = import_legacy(live, existing_ids, existing_chashes)
    print(f"        +{mems} memories, +{tags} tags, +{coords} coords, +{seeds} akashic_seeds")
    total_new += mems

    # 2) Filtered events
    print("\n  [2/8] Events (filtered) …", flush=True)
    n, dup, filt = ingest_jsonl(live, EVENTS_FILE, _event_to_mem,
                                existing_ids, existing_chashes,
                                event_filter=EVENTS_WHITELIST)
    print(f"        +{n} imported  ({dup} dedup-skipped, {filt} type-filtered)")
    total_new += n

    # 3) Emotions
    print("\n  [3/8] Emotions …", flush=True)
    n, dup, _ = ingest_jsonl(live, EMOTIONS_FILE, _emotion_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    # 4) Awareness
    print("\n  [4/8] Awareness …", flush=True)
    n, dup, _ = ingest_jsonl(live, AWARENESS_FILE, _awareness_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    # 5) Resonance history
    print("\n  [5/8] Resonance history …", flush=True)
    n, dup, _ = ingest_jsonl(live, RESONANCE_FILE, _resonance_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    # 6) Depth gauge
    print("\n  [6/8] Depth gauge …", flush=True)
    n, dup, _ = ingest_jsonl(live, DEPTH_FILE, _depth_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    # 7) Token economy
    print("\n  [7/8] Token economy …", flush=True)
    n, dup, _ = ingest_jsonl(live, TOKEN_FILE, _token_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    # 8) Recovered file-scans
    print("\n  [8/8] Recovered file-scans …", flush=True)
    n, dup, _ = ingest_jsonl(live, RECOVERED_FILE, _recovered_to_mem,
                             existing_ids, existing_chashes)
    print(f"        +{n} imported  ({dup} dedup-skipped)")
    total_new += n

    live.commit()
    print(f"\n  --- commit: +{total_new} new memories ---")

    # 9) Audit logs (bonus)
    if AUDIT_DIR.exists():
        print("\n  [+] Audit logs …", flush=True)
        audit_total = 0
        for audit_file in sorted(AUDIT_DIR.glob("*.jsonl")):
            n, _, _ = ingest_jsonl(live, audit_file, _audit_to_mem,
                                   existing_ids, existing_chashes)
            audit_total += n
        print(f"        +{audit_total} audit records")
        total_new += audit_total
        live.commit()

    # 10) Encode holographic coords for all memories that lack them
    print("\n  [coord] Encoding holographic coordinates …", flush=True)
    encoded = encode_missing_coords(live)
    print(f"        Encoded {encoded} new coordinate sets")
    live.commit()

    live.close()
    elapsed = time.time() - start

    print("\n" + "=" * 62)
    print(f"  DONE — +{total_new} memories ingested, {encoded} coords encoded")
    print(f"  Total time: {elapsed:.2f}s")
    print("=" * 62)


if __name__ == "__main__":
    main()
