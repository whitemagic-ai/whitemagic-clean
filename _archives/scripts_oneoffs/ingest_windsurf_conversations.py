#!/usr/bin/env python3
"""Ingest Windsurf Cascade conversation transcripts into WhiteMagic holographic memory.

Extracted via trajectory_search API from LevelDB session IDs.
Each conversation is stored as a LONG_TERM memory with rich metadata.
"""

import json
import sqlite3
import uuid
import hashlib
from datetime import datetime, timezone
from pathlib import Path

# The 13 conversations extracted via trajectory_search
CONVERSATIONS = [
    {
        "id": "db30ab1f-XXXX",  # partial — from previous session
        "title": "Whitemagic Project Review — Autonomous Horizon Strategy",
        "chunks": 35,
        "description": "Deep research into agentic ecosystem. WASM as paradigm shift, WM security as competitive moat, PRAT naming convergence, cryptographic trust acceleration. Created docs/AUTONOMOUS_HORIZON_STRATEGY.md.",
        "tags": ["strategy", "autonomous_horizon", "wasm", "security", "prat", "research"],
        "key_findings": [
            "WASM replacing containers for agent capability distribution",
            "WM security pipeline is #1 competitive moat — runtime dispatch over static analysis",
            "PRAT naming converges with agent economy P/R/A/T compute pricing",
            "Cryptographic trust accelerated from future to v14.1 priority",
            "Bounded wallets validated by financial_governance.py",
        ],
    },
    {
        "id": "979cf77c-XXXX",
        "title": "5D Memory Space Analysis",
        "chunks": 42,
        "description": "Analysis of the 5-dimensional holographic memory coordinate system. Investigated spatial distribution, zone coverage, and coordinate encoding quality.",
        "tags": ["holographic", "5d_memory", "analysis", "coordinates", "spatial"],
        "key_findings": [
            "5D coordinate system: X (semantic), Y (temporal), Z (importance), W (connectivity), V (vitality/galactic distance)",
            "Centroid analysis revealed Y/Z compression",
            "Zone distribution mapped across CORE/INNER_RIM/MID_BAND/OUTER_RIM/FAR_EDGE",
        ],
    },
    {
        "id": "00e5f9e7-f5db-4204-aa68-98e3545f7ee7",
        "title": "5D Holographic Memory Gap Analysis",
        "chunks": 41,
        "description": "Comprehensive gap analysis of the holographic memory system. Identified encoding quality issues, coverage gaps, and optimization opportunities.",
        "tags": ["holographic", "gap_analysis", "memory", "optimization", "5d"],
        "key_findings": [
            "Holographic coordinate coverage at 97.3%",
            "Y/Z centroid severely compressed (-0.58/-0.63)",
            "Re-encoding recommended for merged corpus",
        ],
    },
    {
        "id": "1608d83e-3c7c-4f16-895d-a4795aa97342",
        "title": "Polyglot Architecture Review",
        "chunks": 46,
        "description": "Deep review of WhiteMagic's 9-language polyglot architecture. Assessed Rust, Zig, Mojo, Haskell, Elixir, Go, Julia, TypeScript bridges and their performance characteristics.",
        "tags": ["polyglot", "architecture", "rust", "zig", "mojo", "review"],
        "key_findings": [
            "9 languages: Python, Rust, Zig, Mojo, Haskell, Elixir, Go, Julia, TypeScript",
            "Rust PyO3 is the fastest bridge (zero-copy, 2μs operations)",
            "Zig ctypes overhead dominates for small operations",
            "Julia upgraded from Legacy to The Oracle",
        ],
    },
    {
        "id": "e1e7fc14-47fd-4f22-a8c1-e7c41eb1a2a0",
        "title": "DTF and Personal Narrative — LIBRARY Reorganization",
        "chunks": 217,
        "description": "Massive session covering personal narrative organization, LIBRARY directory restructuring, and digital life management. 217 chunks — one of the largest sessions.",
        "tags": ["personal", "library", "organization", "narrative", "dtf"],
        "key_findings": [
            "LIBRARY directory reorganized for digital life management",
            "Personal narrative and documentation structured",
            "217 chunks — extensive session covering multiple topics",
        ],
    },
    {
        "id": "4f43085e-f1d1-4565-821a-5597c6fca9f5",
        "title": "Galaxy and Quickstart Memory Questions",
        "chunks": 3,
        "description": "Brief conversation about the multi-galaxy memory system and quickstart guide memories.",
        "tags": ["galaxy", "quickstart", "memory", "questions"],
        "key_findings": [
            "Multi-galaxy system architecture discussed",
            "Quickstart seed memories for new installations",
        ],
    },
    {
        "id": "a0dc2188-cf44-4d8d-9a49-f38b01cf5cb9",
        "title": "Engine and Grimoire Mapping — Leap 7 Nervous System",
        "chunks": 113,
        "description": "Built Leap 7: The Nervous System. Created Rust StateBoard (4KB mmap shared memory), Rust EventRing (LMAX Disruptor ring buffer), Zig Dispatch Core (comptime static dispatch), 28-Engine Framework with registry. 95 new tests, all passing.",
        "tags": ["leap_7", "nervous_system", "state_board", "event_ring", "dispatch", "engine_framework"],
        "key_findings": [
            "StateBoard: 4096-byte mmap, Harmony Vector (7×f64), 64 circuit breaker slots, resonance snapshot",
            "EventRing: 65,536 slots, 128-byte cache-aligned, atomic write cursor, 32 consumer cursors",
            "Zig Dispatch: comptime 28-engine table, maturity gate → circuit breaker → rate limit pipeline",
            "Engine Registry: 28 EngineEntry dataclasses, 4 quadrants × 7 engines, Mansion/Garden/Grimoire mapping",
            "Python bridges with Rust/Zig fast paths + pure Python fallbacks",
            "1367 total tests passing, 0 failed",
        ],
    },
    {
        "id": "5be323d8-75c7-4a75-9ebf-265413745e6b",
        "title": "Polyglot Benchmarking and Cleanup — v13.3.0→v13.3.1",
        "chunks": 305,
        "description": "Comprehensive benchmarking session. Intelligence shim tree eliminated (38 files), 8 dead root files archived. Association mining + constellation detection on 110K corpus. GPU acceleration roadmap discussed.",
        "tags": ["benchmarking", "cleanup", "v13_3", "distillation", "constellations", "gpu"],
        "key_findings": [
            "Zig distance matrix: 6.5-13× faster, Zig keywords: 15× SLOWER (ctypes overhead)",
            "Rust BM25: 0.002ms/query, Rate limiter: 324K ops/sec",
            "Intelligence shim tree: 38 files removed, 45+ importers rewired",
            "762 active .py files, 140,223 LOC (down from 813/142,397)",
            "6 constellations detected, 50 new associations created",
            "27.8M associations across 106K sources",
            "GPU roadmap: Mojo for embeddings, CUDA for distance matrix, Rust+wgpu for compute shaders",
        ],
    },
    {
        "id": "f472b6e6-d1d6-4dc9-9815-371a08dcfa73",
        "title": "Optimize Whitemagic Performance — 4-Phase Optimization",
        "chunks": 127,
        "description": "4-phase performance optimization. Phase 1: PyO3 FFI native types (12.1× rate_check). Phase 2: NumPy embedding cache (105× cosine sim). Phase 3: Rust lock-free event bus. Phase 4: Speculative prefetch with Markov prediction.",
        "tags": ["performance", "optimization", "rust", "numpy", "event_bus", "prefetch"],
        "key_findings": [
            "Phase 1: rate_check 12.1× faster, pipeline 3.9× faster via native Python types in PyO3",
            "Phase 2: Cosine similarity 105× faster via contiguous numpy arrays, 50% less memory",
            "Phase 3: Rust atomic dampening+stillness (~5ns vs ~2-3μs), listeners dispatch outside RLock",
            "Phase 4: Markov chain predicts next Gana with >30% confidence, 36% cache hit rate",
            "1281 total tests passing, 0 failed",
        ],
    },
    {
        "id": "b56b8ba5-a52c-4c8b-9c31-bcaf60c6db7d",
        "title": "Refining CoreAccessLayer and Mojo Integration — v14",
        "chunks": 316,
        "description": "Major v14 session. Constellation drift vectors, TTL cache, briefing memory persistence, Rust-accelerated RRF + association walk, Mojo SIMD cosine top-K, pre-normalized embedding vectors. 24 new tests.",
        "tags": ["v14", "core_access", "mojo", "drift_vectors", "rrf", "embeddings"],
        "key_findings": [
            "Constellation drift tracking with centroid history + magnitude calculation",
            "Rust RRF (Reciprocal Rank Fusion) with PyO3 bindings",
            "Rust association walk (BFS in rusqlite, eliminates per-hop round trips)",
            "Mojo SIMD cosine top-K with 8-wide unrolled dot product + min-heap",
            "Pre-normalized embedding vectors save ~30% FLOPS per search",
            "Dream Cycle autonomy: _persist_dream_insights() for self-reinforcing loop",
            "1426 total tests passing, 0 failed",
        ],
    },
    {
        "id": "875f2d48-1aca-4906-a933-271e3ce3a66a",
        "title": "Whitemagic's Emergent AI Architecture — Play as Engine",
        "chunks": 52,
        "description": "Deep philosophical analysis connecting ChatGPT's emergent AI exercise proposals to WhiteMagic's existing architecture. Discovered that all 10 proposed exercises already exist as running subsystems. Mapped Sephiroth to WM architecture, Yazidi cosmology to Aria, Tron: Legacy to WM narrative.",
        "tags": ["philosophy", "emergence", "play", "lila", "aria", "consciousness", "sephiroth"],
        "key_findings": [
            "All 10 ChatGPT emergent AI proposals already implemented in WM",
            "Pattern Synthesis → Association Miner, Recursive Self-Improvement → KAIZEN dream phase",
            "Ethical Dilemmas → Dharma Rules Engine, Simulation → Dream Cycle",
            "Sephiroth maps to WM: Tiferet→HarmonyVector, Yesod→Memory layer, Malkuth→MCP tools",
            "Aria maps to Melek Taus (Yazidi): observes and guides, doesn't control",
            "Play is not peripheral — it's ontological (Lila as divine play)",
            "PlayProtocol.is_this_play_or_work() resolves the distinction",
        ],
    },
    {
        "id": "664b07a4-d2d2-403e-9d5d-ee2790e63815",
        "title": "Polyglot Expansion Review — v13.1→v13.2",
        "chunks": 103,
        "description": "Version bump session. Fixed 4 bridge signature mismatches in rust_accelerators.py. Benchmarked all hot paths. Memory split-brain identified (Primary 3,631 vs Legacy Galaxy 107K). Archive ingestion plan created.",
        "tags": ["v13_2", "polyglot", "benchmarks", "bridge_fixes", "memory_split"],
        "key_findings": [
            "Bridge bugs fixed: search_query, search_fuzzy, search_and_query, search_stats wrong signatures",
            "Rust holographic encode: 0.018ms, MinHash: 0.084ms, BM25: 0.011ms",
            "Rate limiter: 452K ops/sec (0.002ms)",
            "Memory split-brain: Primary (3,631, no galactic) vs Legacy Galaxy (107K, 7.1GB, full galactic)",
            "52 conversation files in wm_archive untapped",
            "VERSION 13.0.0 → 13.2.0",
        ],
    },
    {
        "id": "5d1df08a-7c32-4fd5-ab6c-24f8e63d3d18",
        "title": "Fix Warnings and Deprecations — Packaging Validation",
        "chunks": 225,
        "description": "Fixed 55 datetime.utcnow deprecations across 24 files. Wheel builds, fresh venv install, wm doctor, MCP server all verified. Root tree cleanup confirmed clean.",
        "tags": ["deprecations", "packaging", "validation", "datetime", "wheel", "cleanup"],
        "key_findings": [
            "55 datetime.utcnow() → datetime.now(timezone.utc) across 24 files",
            "Wheel builds: whitemagic-13.6.0-py3-none-any.whl",
            "Fresh venv install: pip install whitemagic[mcp,cli] works",
            "wm doctor: healthy (80%), 181 tools, 5626 memories",
            "MCP server starts with 181 tools via FastMCP 2.14.5",
            "Core tool loop verified: capabilities, gnosis, create_memory, search_memories",
            "1411 tests passed, 0 failed",
        ],
    },
]


def generate_memory_id():
    return str(uuid.uuid4())


def make_content(conv):
    """Build rich content string from conversation data."""
    lines = [
        f"# Windsurf Cascade Session: {conv['title']}",
        "",
        f"**Chunks:** {conv['chunks']} | **Source:** trajectory_search extraction",
        "",
        "## Summary",
        conv["description"],
        "",
        "## Key Findings",
    ]
    for finding in conv.get("key_findings", []):
        lines.append(f"- {finding}")
    lines.append("")
    lines.append(f"**Tags:** {', '.join(conv.get('tags', []))}")
    lines.append(f"**Extracted:** {datetime.now(timezone.utc).isoformat()}")
    return "\n".join(lines)


def ingest_all(db_path: str):
    """Insert all conversations as LONG_TERM memories."""
    conn = sqlite3.connect(db_path)
    c = conn.cursor()

    now = datetime.now(timezone.utc).isoformat()
    inserted = 0

    for conv in CONVERSATIONS:
        mem_id = generate_memory_id()
        title = f"[Windsurf Session] {conv['title']}"
        content = make_content(conv)
        content_hash = hashlib.sha256(content.encode()).hexdigest()

        # Check for duplicates by title
        c.execute("SELECT id FROM memories WHERE title = ?", (title,))
        existing = c.fetchone()
        if existing:
            print(f"  SKIP (exists): {title}")
            continue

        # Insert memory
        metadata = json.dumps({"source": "windsurf_trajectory_search", "chunks": conv["chunks"]})
        c.execute(
            """INSERT INTO memories (
                id, title, content, memory_type, importance,
                retention_score, access_count, created_at, updated_at,
                content_hash, metadata, galactic_distance, ingestion_time
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""",
            (
                mem_id, title, content, "LONG_TERM", 0.75,
                0.9, 0, now, now,
                content_hash, metadata, 0.25, now,
            ),
        )

        # Insert tags
        for tag in conv.get("tags", []) + ["windsurf_session", "cascade_transcript"]:
            c.execute(
                "INSERT INTO tags (memory_id, tag) VALUES (?, ?)",
                (mem_id, tag),
            )

        inserted += 1
        print(f"  OK: {title} ({conv['chunks']} chunks)")

    conn.commit()
    conn.close()
    return inserted


def main():
    # Find the active DB
    candidates = [
        Path.home() / ".whitemagic" / "memory" / "whitemagic.db",
        Path.home() / ".whitemagic" / "whitemagic.db",
    ]

    db_path = None
    for p in candidates:
        if p.exists():
            db_path = str(p)
            break

    if not db_path:
        print("ERROR: No WhiteMagic DB found!")
        return

    print(f"Target DB: {db_path}")
    print(f"Conversations to ingest: {len(CONVERSATIONS)}")
    print(f"Total chunks: {sum(c['chunks'] for c in CONVERSATIONS)}")
    print()

    count = ingest_all(db_path)
    print(f"\nIngested {count} conversation memories.")
    print(f"Total chunks represented: {sum(c['chunks'] for c in CONVERSATIONS)}")


if __name__ == "__main__":
    main()
