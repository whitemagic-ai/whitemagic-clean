#!/usr/bin/env python3
"""Ingest Windsurf Cascade conversations (Round 2) into WhiteMagic memory.

Extracted via trajectory_search API probing of LevelDB session UUIDs.
3 new conversations found in this round.

Usage:
    python scripts/ingest_windsurf_round2.py              # Dry run (default)
    python scripts/ingest_windsurf_round2.py --apply       # Actually ingest
"""

import argparse
import hashlib
import json
import logging
import os
import sqlite3
import sys
import uuid
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
log = logging.getLogger("ingest_windsurf_r2")

# ---------------------------------------------------------------------------
# Round 2 conversations extracted via trajectory_search
# ---------------------------------------------------------------------------

CONVERSATIONS = [
    {
        "uuid": "019c6a89-b6f0-453e-bcf5-e969188f7745",
        "title": "Implement Violet Security Features",
        "chunks": 133,
        "description": (
            "Implemented the Edgerunner Violet security layer: MCP integrity "
            "fingerprinting (SHA-256), crypto-chained Karma with red/blue ops "
            "classification, Violet Dharma profile (5 rules), OpenSSF model "
            "signing verification, scope-of-engagement tokens (HMAC-SHA256), "
            "and security circuit breakers. 15 new MCP tools, 70 tests passing. "
            "Fixed Haskell FFI bypass for Python-only profiles."
        ),
        "tags": [
            "edgerunner_violet", "security", "mcp_integrity", "model_signing",
            "engagement_tokens", "security_breaker", "dharma_violet",
            "windsurf_session", "v15_session",
        ],
        "key_artifacts": [
            "whitemagic/security/mcp_integrity.py",
            "whitemagic/security/model_signing.py",
            "whitemagic/security/engagement_tokens.py",
            "whitemagic/security/security_breaker.py",
            "whitemagic/tools/handlers/violet_security.py",
            "tests/unit/test_violet_security.py (70 tests)",
        ],
    },
    {
        "uuid": "04c1bceb-36e2-453c-8bb1-768a8f257e02",
        "title": "Integrate Graph-Based Tools",
        "chunks": 161,
        "description": (
            "Implemented v14.6 Cognitive Architecture: JIT Memory Researcher "
            "(iterative plan-search-reflect), Narrative Compressor (dream phase "
            "clustering), Hermit Crab Mode (encrypted memory withdrawal with "
            "HMAC-SHA256 ledger), Green Score Telemetry (edge vs cloud metrics), "
            "and Cognitive Modes (Explorer/Executor/Reflector/Balanced/Guardian). "
            "17 new tools across 5 Ganas, 69 tests passing. 305 dispatch table entries."
        ),
        "tags": [
            "cognitive_architecture", "jit_research", "narrative_compression",
            "hermit_crab", "green_score", "cognitive_modes", "v14_6",
            "windsurf_session", "v15_session",
        ],
        "key_artifacts": [
            "whitemagic/core/intelligence/researcher.py",
            "whitemagic/core/dreaming/narrative_compressor.py",
            "whitemagic/security/hermit_crab.py",
            "whitemagic/core/monitoring/green_score.py",
            "whitemagic/core/intelligence/cognitive_modes.py",
            "tests/unit/test_v14_2_features.py (69 tests)",
        ],
    },
    {
        "uuid": "080f8e4b-5b52-4771-a184-9507299a5984",
        "title": "WhiteMagic Security & Mesh Improvements",
        "chunks": 540,
        "description": (
            "Massive session covering: encrypted_db.py (unified encryption with "
            "OS keychain integration, passphrase validation, SQLCipher migration), "
            "vault CLI (status/encrypt-db/decrypt-db/lock), Go mesh upgrades "
            "(TCP+QUIC+WebSocket transports, PSK peer auth, NAT traversal), "
            "Rosetta Mode (WM_TERMINOLOGY=standard for enterprise adoption), "
            "Federated Galaxy Protocol (mesh/federation.go — remote galaxy mounting), "
            "and Galaxy Visualizer (D3 force-directed star cluster in Nexus). "
            "All 3 strategic suggestions from external AI review implemented."
        ),
        "tags": [
            "encryption", "encrypted_db", "vault_cli", "mesh", "quic",
            "psk_auth", "nat_traversal", "rosetta_mode", "federation",
            "galaxy_visualizer", "nexus", "d3", "windsurf_session", "v15_session",
        ],
        "key_artifacts": [
            "whitemagic/core/memory/encrypted_db.py",
            "whitemagic/cli/cli_app.py (vault commands)",
            "mesh/main.go (QUIC+WS+PSK+NAT)",
            "mesh/federation.go",
            "whitemagic/rosetta.py",
            "nexus/src/components/center/GalaxyVisualizer.tsx",
        ],
    },
]


def generate_content(conv: dict) -> str:
    """Generate rich memory content from conversation metadata."""
    lines = [
        f"# Windsurf Session: {conv['title']}",
        "",
        f"**UUID**: {conv['uuid']}",
        f"**Chunks**: {conv['chunks']}",
        f"**Extracted**: {datetime.now(timezone.utc).strftime('%Y-%m-%d')} (Round 2)",
        "",
        "## Summary",
        conv["description"],
        "",
        "## Key Artifacts",
    ]
    for artifact in conv.get("key_artifacts", []):
        lines.append(f"- {artifact}")
    lines.append("")
    lines.append("## Tags")
    lines.append(", ".join(conv["tags"]))
    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Ingest Windsurf Round 2 conversations")
    parser.add_argument("--apply", action="store_true", help="Actually ingest (default is dry run)")
    args = parser.parse_args()

    from whitemagic.config.paths import DB_PATH

    if not DB_PATH.exists():
        log.error(f"DB not found: {DB_PATH}")
        sys.exit(1)

    conn = sqlite3.connect(str(DB_PATH))
    conn.row_factory = sqlite3.Row

    log.info(f"DB: {DB_PATH}")
    log.info(f"Conversations to ingest: {len(CONVERSATIONS)}")

    ingested = 0
    skipped = 0

    for conv in CONVERSATIONS:
        title = f"Windsurf Session: {conv['title']}"

        # Check for duplicate by title
        existing = conn.execute(
            "SELECT id FROM memories WHERE title = ?", (title,)
        ).fetchone()

        if existing:
            log.info(f"  SKIP (exists): {title}")
            skipped += 1
            continue

        content = generate_content(conv)
        content_hash = hashlib.sha256(content.encode()).hexdigest()

        # Also check by content hash
        existing_hash = conn.execute(
            "SELECT id FROM memories WHERE content_hash = ?", (content_hash,)
        ).fetchone()
        if existing_hash:
            log.info(f"  SKIP (hash match): {title}")
            skipped += 1
            continue

        memory_id = str(uuid.uuid4())
        now = datetime.now(timezone.utc).isoformat()

        if not args.apply:
            log.info(f"  DRY RUN: {title} ({len(content)} chars, {len(conv['tags'])} tags)")
            continue

        # Insert memory
        conn.execute(
            """INSERT INTO memories (id, content, memory_type, title, created_at,
               accessed_at, access_count, emotional_valence, importance, neuro_score,
               novelty_score, recall_count, half_life_days, is_protected,
               galactic_distance, retention_score, content_hash, metadata)
               VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""",
            (
                memory_id, content, "LONG_TERM", title, now, now,
                1, 0.3, 0.8, 0.9, 0.7, 0, 90.0, 1,
                0.15, 0.85, content_hash,
                json.dumps({
                    "source": "windsurf_trajectory_search",
                    "extraction_round": 2,
                    "uuid": conv["uuid"],
                    "chunks": conv["chunks"],
                }),
            ),
        )

        # Insert tags
        for tag in conv["tags"]:
            conn.execute(
                "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
                (memory_id, tag),
            )

        conn.commit()
        ingested += 1
        log.info(f"  INGESTED: {title} ({memory_id[:8]})")

    conn.close()

    log.info(f"\nResults: {ingested} ingested, {skipped} skipped")
    if not args.apply and ingested == 0 and skipped == 0:
        log.info("Run with --apply to actually ingest")


if __name__ == "__main__":
    main()
