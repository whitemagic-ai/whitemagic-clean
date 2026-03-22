#!/usr/bin/env python3
"""
Ingest Recent Windsurf Sessions
================================
Systematically ingest missing Windsurf conversations from Feb 10-17
"""

import hashlib
import json
import sqlite3
from datetime import datetime
from pathlib import Path

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"

# Sessions to ingest (from ls output, newest first)
SESSIONS = [
    {
        "id": "8d9685e4-b5a7-4b60-8b2e-65603fd87866",
        "date": "2026-02-17",
        "title": "Current Session",
        "tags": ["windsurf", "session", "feb17", "current"],
    },
    {
        "id": "74e27380-4b29-4dfd-913b-be932957f187",
        "date": "2026-02-17",
        "title": "Autonomous Code Generation Enhancement",
        "tags": ["windsurf", "session", "feb17", "code_generation"],
    },
    {
        "id": "45697f4b-5c7d-4db7-a087-5d2bb49e89b9",
        "date": "2026-02-17",
        "title": "Resolve Rust Build Issues & PSR Implementation",
        "tags": ["windsurf", "session", "feb17", "rust", "psr"],
    },
    {
        "id": "e2dbec70-18bb-4f64-9831-7d22dc90c15d",
        "date": "2026-02-17",
        "title": "Complete I-Series, Start P-Series",
        "tags": ["windsurf", "session", "feb17", "campaigns"],
    },
    {
        "id": "825b7b4d-abb6-4a82-95a0-597b0545ccb8",
        "date": "2026-02-16",
        "title": "Deploy PSR Campaigns",
        "tags": ["windsurf", "session", "feb16", "psr", "deployment"],
    },
    {
        "id": "9d8f3f53-441b-4d65-96a4-f9012db30fa5",
        "date": "2026-02-16",
        "title": "Accelerating Batch Embeddings",
        "tags": ["windsurf", "session", "feb16", "embeddings", "acceleration"],
    },
    {
        "id": "124c9ac3-8c7f-4aa6-8d4e-9acd23b2bc77",
        "date": "2026-02-15",
        "title": "Gene Library Expansion Campaigns",
        "tags": ["windsurf", "session", "feb15", "evolution", "genes"],
    },
    {
        "id": "d4e1e68d-f993-4730-9477-26b54f3f4e46",
        "date": "2026-02-15",
        "title": "Polyglot Synthesis Loop",
        "tags": ["windsurf", "session", "feb15", "polyglot", "synthesis"],
    },
]

def content_hash(text: str) -> str:
    """Generate SHA-256 hash of content."""
    return hashlib.sha256(text.encode('utf-8')).hexdigest()

def check_exists(session_id: str) -> bool:
    """Check if session already ingested."""
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE title LIKE ? OR content LIKE ?",
        (f"%{session_id}%", f"%{session_id}%")
    )
    count = cursor.fetchone()[0]
    conn.close()
    return count > 0

def ingest_session(session: dict, content: str) -> dict:
    """Ingest a session into WhiteMagic DB."""

    if not content or len(content) < 100:
        return {"status": "skipped", "reason": "content_too_short"}

    # Check if already exists
    if check_exists(session["id"]):
        return {"status": "skipped", "reason": "already_exists"}

    # Generate memory
    memory_id = hashlib.sha256(session["id"].encode()).hexdigest()[:16]
    now = datetime.now().isoformat()
    c_hash = content_hash(content)

    title = f"Windsurf Session: {session['title']}"

    # Store in DB
    conn = sqlite3.connect(DB_PATH)
    conn.execute("PRAGMA journal_mode=WAL")

    try:
        conn.execute(
            """INSERT INTO memories (id, content, memory_type, title, created_at,
               accessed_at, access_count, importance, emotional_valence,
               content_hash, metadata, neuro_score, galactic_distance)
               VALUES (?, ?, 'LONG_TERM', ?, ?, ?, 1, 0.85, 0.0, ?, ?, 1.0, 0.5)""",
            (
                memory_id,
                content,
                title,
                now,
                now,
                c_hash,
                json.dumps({
                    "source": "windsurf",
                    "session_id": session["id"],
                    "date": session["date"],
                    "ingested_at": now,
                }),
            ),
        )

        # Add tags
        for tag in session["tags"]:
            conn.execute(
                "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
                (memory_id, tag),
            )

        conn.commit()

        # Rebuild FTS
        try:
            conn.execute("INSERT INTO memories_fts(memories_fts) VALUES('rebuild')")
            conn.commit()
        except:
            pass

        conn.close()

        return {
            "status": "success",
            "memory_id": memory_id,
            "title": title,
            "content_length": len(content),
        }

    except Exception as e:
        conn.close()
        return {"status": "error", "error": str(e)}

def main():
    print("=" * 80)
    print("INGESTING RECENT WINDSURF SESSIONS")
    print("=" * 80)
    print()

    print(f"Target DB: {DB_PATH}")
    print(f"Sessions to process: {len(SESSIONS)}")
    print()

    results = []

    for session in SESSIONS:
        print(f"Processing: {session['title']}")
        print(f"  ID: {session['id']}")
        print(f"  Date: {session['date']}")

        # For now, mark as pending trajectory_search
        result = {
            "session": session,
            "status": "pending_extraction",
        }
        results.append(result)
        print("  Status: Pending trajectory_search")
        print()

    print("=" * 80)
    print("EXTRACTION PLAN")
    print("=" * 80)
    print()
    print("Next steps:")
    print("1. Use trajectory_search to extract each session")
    print("2. Save extracted content")
    print("3. Ingest into WhiteMagic DB")
    print("4. Verify ingestion")
    print()
    print(f"Total sessions: {len(SESSIONS)}")

    # Save plan
    plan_path = Path(__file__).parent.parent / "reports" / "windsurf_ingestion_plan.json"
    plan_path.write_text(json.dumps({"sessions": SESSIONS, "results": results}, indent=2))
    print(f"\nPlan saved: {plan_path}")

if __name__ == "__main__":
    main()
