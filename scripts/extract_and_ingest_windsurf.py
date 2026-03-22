#!/usr/bin/env python3
"""Extract and ingest ALL Windsurf Cascade conversations into WhiteMagic galactic memory.

Technique: "Copy and Decrypt" via Cascade's trajectory_search tool.
The .pb files in ~/.codeium/windsurf/cascade/ are AES-GCM encrypted.
Direct decryption requires reverse-engineering the Go language_server binary.
Instead, we query trajectory_search from within an active Cascade session,
which decrypts on-the-fly. Results are saved to JSON manifest files, then
batch-ingested into the galactic memory core.

Usage:
    # Step 1: From within Cascade, probe UUIDs and save to manifest
    # (This is done via trajectory_search tool calls in conversation)

    # Step 2: Ingest from manifest into galactic memory
    python scripts/extract_and_ingest_windsurf.py --apply

    # Dry run (default):
    python scripts/extract_and_ingest_windsurf.py

    # Show inventory:
    python scripts/extract_and_ingest_windsurf.py --inventory

    # Ingest into a specific galaxy:
    python scripts/extract_and_ingest_windsurf.py --apply --galaxy windsurf_dev_history
"""

from __future__ import annotations

import argparse
import hashlib
import json
import logging
import os
import sqlite3
import sys
import uuid
from datetime import UTC, datetime
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
log = logging.getLogger("windsurf_ingest")

# ---------------------------------------------------------------------------
# Conversation inventory — all known Windsurf Cascade .pb files
# Metadata is populated as conversations are probed via trajectory_search
# ---------------------------------------------------------------------------

# All 50 .pb file UUIDs from ~/.codeium/windsurf/cascade/
ALL_PB_UUIDS = [
    "00e5f9e7-f5db-4204-aa68-98e3545f7ee7",
    "019c6a89-b6f0-453e-bcf5-e969188f7745",
    "04c1bceb-36e2-453c-8bb1-768a8f257e02",
    "06955f15-1d8e-4f05-8bcb-e211b36f500d",
    "080f8e4b-5b52-4771-a184-9507299a5984",
    "0f702cdb-d7fb-4a33-aa2f-44b36d7f6ccd",
    "1250c429-6a67-4495-8296-f2900fc3b13e",
    "15db21e0-a2e5-4189-9198-4ca669ba9aa9",
    "1608d83e-3c7c-4f16-895d-a4795aa97342",
    "168d42e6-6b30-4e77-aaf6-e51982a1ced6",
    "1a0773f1-c851-4be9-9eab-62c35b1bf0db",
    "1b4bff4b-dcca-488f-b0fc-ffbf217ecf73",
    "20e6a233-81f3-4e13-bfa4-e2baca1ca4b8",
    "23792b84-abb2-4a4c-b31b-9a8d059a938f",
    "2809f7f8-63f8-45ed-8a01-c403fcdbbd4a",
    "347779b3-4bb5-4822-8da5-7006bf162581",
    "3bb20d79-9f5e-4785-b6be-04e3e253f758",
    "41a50aa3-746a-45e6-8546-6d9b90ed9bc1",
    "4384f7da-e7ca-483d-8b2d-e0af333bbab7",
    "4b54b060-84ef-4542-9964-52fb9b5e953f",
    "4d6f5d35-465a-4e2a-beda-b34a1efab8f8",
    "4f43085e-f1d1-4565-821a-5597c6fca9f5",
    "541f55f1-771b-4437-bc8f-44879a38cf23",
    "5956871e-761c-4cf6-808b-505c13e78c19",
    "5b1c42c6-87e2-4dde-928e-528b28f44e23",
    "5ee172f1-1c82-44a2-b5a8-543dc419dc9e",
    "606a5cfb-c6e2-451c-82c0-c7a2c2b15d1c",
    "6f230d78-cc0c-4a19-a7c1-103df0b3b3fd",
    "6ff11acb-98d5-4f59-86c1-11c31a0f1387",
    "7175ecca-6cd5-4dc5-9478-f572be48fdb6",
    "78e644ec-6106-41d4-ac68-da33042622eb",
    "84b7fa62-e0a7-4a70-a414-17f4dca8e395",
    "875f2d48-1aca-4906-a933-271e3ce3a66a",
    "8989cd8a-d1d9-41b2-8c4c-6c21700c10bd",
    "8fc57241-a2dd-47bc-b717-2967d26b4eec",
    "94a4bea2-4d07-42ea-aa9e-0f5a22f867d1",
    "979cf77c-aaed-410c-b795-679faff92ebc",
    "9c186d8e-ed8a-471e-9714-577688e30a74",
    "9dd7bb64-cb9c-424e-bb01-2d2c6170c708",
    "9ed2ce96-07c5-49f6-8014-486eab6d62bb",
    "ad4432f9-378d-46f3-bc3e-57fd7c9169ae",
    "b3a23276-952b-4330-bdeb-c6aa8b659d53",
    "b994d6ca-a4bd-4174-9f1d-27bec6fc3269",
    "bbe28c11-f2e5-466a-8298-73e6efff1a91",
    "c5c54df8-881e-433e-b928-5b63de4ac036",
    "cfc73124-f1a0-41fe-a02c-d4c3764f304e",
    "e1e7fc14-47fd-4f22-a8c1-e7c41eb1a2a0",
    "f114b6b7-7959-4f3e-a11b-5a069d646581",
    "f8de6773-1e0b-4caa-8f19-699b69ae0fd3",
    "fe0f6cb5-7875-4bc8-ada0-d1bbe0283809",
    "940297dd-a7e4-4fbf-8875-a4e7e2a23440",
]

# Additional UUIDs from LevelDB that don't have .pb files
# (older conversations that may have been cleaned up, or non-cascade IDs)
LEVELDB_ONLY_UUIDS = [
    "0ebfe1eb-83db-4add-a5b6-e336582313e3",
    "0eee4081-e9a8-4a69-876a-be636f74554c",
    "13e06ca2-4181-4c43-bdd3-cdf4d4c082de",
    "1781f78f-c8a1-4102-9c57-9b60a5667269",
    "218d774d-54af-499a-91fc-bb39f495b9b2",
    "2311bf0a-ad91-4b3b-bd76-ed5be914c897",
    "24cd177b-1fb5-434a-a71f-1a41fd2338a1",
    "28d16d1b-21a9-43bd-b42c-d731ea96baa6",
    "2b3c6ba3-8b21-4d0d-a1b0-3ccc1218e2ac",
    "2f42ea9f-7051-4874-887f-3ddfb21e87ae",
    "35166a0e-f519-4a1c-aa62-0a07c0efc66f",
    "38d16ff3-b64f-4e78-8f42-58ab4a507ff8",
    "3ed302e6-2e01-400c-8f98-6c8b03876462",
    "41b5381e-0db0-45ba-9ecd-9d87711075a5",
    "4d6f5d35-465a-4e2a-beda-b34a1efab8f8",
    "539ed05e-7c86-41a4-b255-9e35c5499fe9",
    "541f55f1-771b-4437-bc8f-44879a38cf22",
    "574375d4-8ad1-40c9-9e69-1fa1e48145c5",
    "5b1c42c6-87e2-4dde-928e-528b28f44e23",
    "5be323d8-75c7-4a75-9ebf-265413745e6b",
    "5d1df08a-7c32-4fd5-ab6c-24f8e63d3d18",
    "664b07a4-d2d2-403e-9d5d-ee2790e63815",
    "67e8d5ff-7816-4fdc-8733-f9c20c90df93",
    "75e7063f-bfdc-4395-902a-a285b2729dda",
    "76d2c8ce-b423-42ec-91d8-c095fda15217",
    "76d3f05a-5fa3-49bd-8cae-4ced871cc6ed",
    "7eec1208-784f-4e6a-8e9e-5551e87d4b03",
    "83086bfd-cd6b-4d1b-a527-72d1b8c1e2db",
    "846f0d2d-0e56-4714-8ce0-b52cbc7eb822",
    "846f0d2d-0e56-4714-8ce0-b52cbc7eb82c",
    "8989cd8a-d1d9-41b2-8c4c-6c21700c10bd",
    "9dd7bb64-cb9c-424e-bb01-2d2c6170c702",
    "9f12e6c1-f53a-40ef-88a4-83e817fb5f9e",
    "a0dc2188-cf44-4d8d-9a49-f38b01cf5cb9",
    "a0e979f1-3ed6-4958-a4de-668a09969627",
    "a5318e99-f038-40c4-bada-5bd374c5e055",
    "a781ff6b-12d7-4771-ac7d-e901b5d9a8b6",
    "ae97a0bf-e169-4a0b-b2e4-46ea34f3ec9c",
    "b56b8ba5-a52c-4c8b-9c31-bcaf60c6db7d",
    "c1e29538-64c5-455e-a6ec-cac53308b261",
    "cfc73124-f1a0-41fe-a02c-d4c3764f304e",
    "d5dbe898-d995-4c07-9123-bdc6864681bc",
    "db30ab1f-2d9d-491a-a8f5-1f5293d709ca",
    "df43ef32-e70c-445a-ab26-7174d748abff",
    "e7a9ba36-c194-433f-adf2-94ce18d253fb",
    "eaa0e9c0-89c5-4303-b504-40efdf6a4d32",
    "f472b6e6-d1d6-4dc9-9815-371a08dcfa73",
    "fa4bb7ff-1a3e-4453-9919-6a9e98a2e92b",
]

# Conversations with extracted metadata (populated via trajectory_search probes)
# Format: {uuid: {title, chunks, description, tags, key_findings, extraction_round}}
EXTRACTED_CONVERSATIONS: dict[str, dict[str, Any]] = {
    # ── Round 1 (13 conversations, Feb 11 2026) ──
    "db30ab1f-2d9d-491a-a8f5-1f5293d709ca": {
        "title": "Whitemagic Project Review — Autonomous Horizon Strategy",
        "chunks": 35, "extraction_round": 1,
        "description": "Deep research into agentic ecosystem. WASM as paradigm shift, WM security as competitive moat, PRAT naming convergence.",
        "tags": ["strategy", "autonomous_horizon", "wasm", "security", "prat", "research"],
    },
    "979cf77c-aaed-410c-b795-679faff92ebc": {
        "title": "5D Memory Space Analysis",
        "chunks": 42, "extraction_round": 1,
        "description": "Analysis of 5D holographic memory coordinate system. Spatial distribution, zone coverage, coordinate encoding quality.",
        "tags": ["holographic", "5d_memory", "analysis", "coordinates", "spatial"],
    },
    "00e5f9e7-f5db-4204-aa68-98e3545f7ee7": {
        "title": "5D Holographic Memory Gap Analysis",
        "chunks": 41, "extraction_round": 1,
        "description": "Comprehensive gap analysis of holographic memory system. Encoding quality issues, coverage gaps, optimization opportunities.",
        "tags": ["holographic", "gap_analysis", "memory", "optimization", "5d"],
    },
    "1608d83e-3c7c-4f16-895d-a4795aa97342": {
        "title": "Polyglot Architecture Review",
        "chunks": 46, "extraction_round": 1,
        "description": "Deep review of 9-language polyglot architecture. Rust, Zig, Mojo, Haskell, Elixir, Go, Julia, TypeScript bridges.",
        "tags": ["polyglot", "architecture", "rust", "zig", "mojo", "review"],
    },
    "e1e7fc14-47fd-4f22-a8c1-e7c41eb1a2a0": {
        "title": "DTF and Personal Narrative — LIBRARY Reorganization",
        "chunks": 217, "extraction_round": 1,
        "description": "Massive session covering personal narrative organization, LIBRARY directory restructuring.",
        "tags": ["personal", "library", "organization", "narrative"],
    },
    "4f43085e-f1d1-4565-821a-5597c6fca9f5": {
        "title": "Galaxy and Quickstart Memory Questions",
        "chunks": 3, "extraction_round": 1,
        "description": "Brief conversation about multi-galaxy memory system and quickstart guide memories.",
        "tags": ["galaxy", "quickstart", "memory"],
    },
    "a0dc2188-cf44-4d8d-9a49-f38b01cf5cb9": {
        "title": "Engine and Grimoire Mapping — Leap 7 Nervous System",
        "chunks": 113, "extraction_round": 1,
        "description": "Built Leap 7: Rust StateBoard, EventRing, Zig Dispatch Core, 28-Engine Framework. 95 new tests.",
        "tags": ["leap_7", "nervous_system", "state_board", "event_ring", "dispatch", "engine_framework"],
    },
    "5be323d8-75c7-4a75-9ebf-265413745e6b": {
        "title": "Polyglot Benchmarking and Cleanup — v13.3.0→v13.3.1",
        "chunks": 305, "extraction_round": 1,
        "description": "Comprehensive benchmarking. Intelligence shim tree eliminated (38 files). Association mining + constellation detection on 110K corpus.",
        "tags": ["benchmarking", "cleanup", "v13_3", "distillation", "constellations"],
    },
    "f472b6e6-d1d6-4dc9-9815-371a08dcfa73": {
        "title": "Optimize Whitemagic Performance — 4-Phase Optimization",
        "chunks": 127, "extraction_round": 1,
        "description": "4-phase performance optimization. PyO3 FFI native types (12.1x), NumPy embedding cache (105x), Rust event bus, speculative prefetch.",
        "tags": ["performance", "optimization", "rust", "numpy", "event_bus", "prefetch"],
    },
    "b56b8ba5-a52c-4c8b-9c31-bcaf60c6db7d": {
        "title": "Refining CoreAccessLayer and Mojo Integration — v14",
        "chunks": 316, "extraction_round": 1,
        "description": "Major v14 session. Constellation drift vectors, TTL cache, Rust-accelerated RRF + association walk, Mojo SIMD cosine top-K.",
        "tags": ["v14", "core_access", "mojo", "drift_vectors", "rrf", "embeddings"],
    },
    "875f2d48-1aca-4906-a933-271e3ce3a66a": {
        "title": "Whitemagic's Emergent AI Architecture — Play as Engine",
        "chunks": 52, "extraction_round": 1,
        "description": "Deep philosophical analysis connecting ChatGPT's emergent AI exercise proposals to WM architecture. Sephiroth mapping.",
        "tags": ["philosophy", "emergence", "play", "lila", "aria", "consciousness", "sephiroth"],
    },
    "664b07a4-d2d2-403e-9d5d-ee2790e63815": {
        "title": "Polyglot Expansion Review — v13.1→v13.2",
        "chunks": 103, "extraction_round": 1,
        "description": "Version bump session. Fixed 4 bridge signature mismatches. Memory split-brain identified.",
        "tags": ["v13_2", "polyglot", "benchmarks", "bridge_fixes", "memory_split"],
    },
    "5d1df08a-7c32-4fd5-ab6c-24f8e63d3d18": {
        "title": "Fix Warnings and Deprecations — Packaging Validation",
        "chunks": 225, "extraction_round": 1,
        "description": "Fixed 55 datetime.utcnow deprecations. Wheel builds, fresh venv install, MCP server all verified.",
        "tags": ["deprecations", "packaging", "validation", "datetime", "cleanup"],
    },
    # ── Round 2 (3 conversations, Feb 11 2026) ──
    "019c6a89-b6f0-453e-bcf5-e969188f7745": {
        "title": "Implement Violet Security Features",
        "chunks": 133, "extraction_round": 2,
        "description": "Edgerunner Violet security layer: MCP integrity, crypto-chained Karma, Violet Dharma profile, model signing, engagement tokens.",
        "tags": ["edgerunner_violet", "security", "mcp_integrity", "model_signing", "engagement_tokens"],
    },
    "04c1bceb-36e2-453c-8bb1-768a8f257e02": {
        "title": "Integrate Graph-Based Tools",
        "chunks": 161, "extraction_round": 2,
        "description": "v14.6 Cognitive Architecture: JIT Researcher, Narrative Compressor, Hermit Crab Mode, Green Score, Cognitive Modes. 17 new tools.",
        "tags": ["cognitive_architecture", "jit_research", "narrative_compression", "hermit_crab", "cognitive_modes"],
    },
    "080f8e4b-5b52-4771-a184-9507299a5984": {
        "title": "WhiteMagic Security & Mesh Improvements",
        "chunks": 540, "extraction_round": 2,
        "description": "Encrypted DB (SQLCipher), vault CLI, Go mesh upgrades (QUIC+WS+PSK+NAT), Rosetta Mode, Federated Galaxy Protocol, Galaxy Visualizer.",
        "tags": ["encryption", "vault_cli", "mesh", "quic", "federation", "galaxy_visualizer", "rosetta_mode"],
    },
    # ── Round 3 (probed Feb 14 2026 via trajectory_search) ──
    "06955f15-1d8e-4f05-8bcb-e211b36f500d": {
        "title": "WhiteMagic Website Phase 1 Completion",
        "chunks": 191, "extraction_round": 3,
        "description": "Website refactor: modular JS (6 ES modules), galaxy video hero, rainbow hue CSS, 28-Gana interactive wheel, boot sequence, agent endpoints (llms.txt, skill.md, agent.json). Updated to v15.8/374 tools.",
        "tags": ["website", "frontend", "gana_wheel", "boot_sequence", "v15_8", "agent_endpoints"],
    },
    "0f702cdb-d7fb-4a33-aa2f-44b36d7f6ccd": {
        "title": "WhiteMagic v15.8 Release Prep",
        "chunks": 174, "extraction_round": 3,
        "description": "Wired 12 hidden pattern engines (18 new MCP tools), fixed consolidation/retention bugs, version bump 356→374 tools, synced to whitemagicpublic, pushed to GitHub.",
        "tags": ["v15_8", "pattern_engines", "bug_fixes", "release", "documentation"],
    },
    "1250c429-6a67-4495-8296-f2900fc3b13e": {
        "title": "WhiteMagic v14 Release Strategy",
        "chunks": 36, "extraction_round": 3,
        "description": "Synthesized 7 independent research team reports into V14_UNIFIED_STRATEGY.md. 6 critical overlaps, 4 emergent capabilities, phased execution plan.",
        "tags": ["v14", "strategy", "research_synthesis", "unified_strategy", "living_graph"],
    },
    "15db21e0-a2e5-4189-9198-4ca669ba9aa9": {
        "title": "RTS Strategy Mapping",
        "chunks": 152, "extraction_round": 3,
        "description": "Verification audit (62/117 honest score), fixed 6 SQL injection patterns, 6 auto-verify bugs. Added CrossCampaignBlackboard and adaptive strategy pivot to deploy_grand_army.py.",
        "tags": ["verification_audit", "rts_strategy", "sql_injection", "campaign_system", "blackboard"],
    },
    "168d42e6-6b30-4e77-aaf6-e51982a1ced6": {
        "title": "Resolving Remaining Victory Conditions",
        "chunks": 150, "extraction_round": 3,
        "description": "Drove all 14 campaigns to 117/117 (100%) victory. Entity extraction, phylogenetics system, Rust hot path verification, LoCoMo benchmark setup.",
        "tags": ["victory_conditions", "campaigns", "entity_extraction", "phylogenetics", "100_percent"],
    },
    "1a0773f1-c851-4be9-9eab-62c35b1bf0db": {
        "title": "Project Cleanup and Release Prep",
        "chunks": 835, "extraction_round": 3,
        "description": "Massive session (835 chunks): project cleanup from v14.6→v15.0, verify_install.py creation, PRAT router fixes, test suite stabilization, wm_archive ingestion scripts, multi-stage Dockerfile.",
        "tags": ["cleanup", "release_prep", "v15_0", "verify_install", "dockerfile", "archive_ingestion"],
    },
    "1b4bff4b-dcca-488f-b0fc-ffbf217ecf73": {
        "title": "Whitemagic Memory Review and Strategy",
        "chunks": 35, "extraction_round": 3,
        "description": "Living Memory research comparison: WM implements 60% of recommendations. 5 gaps identified (association decay, surprise gate, HDBSCAN, Hungarian algorithm, drift detection). Strategy doc drafted.",
        "tags": ["living_memory", "research", "strategy", "memory_dynamics", "hdbscan"],
    },
    "20e6a233-81f3-4e13-bfa4-e2baca1ca4b8": {
        "title": "Finalizing v14.2 Patch and V15 Roadmap",
        "chunks": 213, "extraction_round": 3,
        "description": "v14.1.1→v14.2: HDBSCAN constellation detection, Hungarian drift correspondence, content hash dedup, wm init wizard, llms.txt auto-generation, 6 workflow templates. 1647 tests passing.",
        "tags": ["v14_2", "hdbscan", "hungarian_drift", "dedup", "wm_init", "llms_txt", "workflows"],
    },
    # ── Round 4 (probed Feb 14 2026 via trajectory_search, batch 2) ──
    "23792b84-abb2-4a4c-b31b-9a8d059a938f": {
        "title": "Fixing UMAP Tests",
        "chunks": 404, "extraction_round": 4,
        "description": "Comprehensive v14.1.0 project audit + Cognitive Enrichment. Full codebase census (185K+ LOC, 9 languages). HNSW integration, entropy scorer, causal miner, UMAP viz. 1647 tests. Phase 2 release seal committed.",
        "tags": ["v14_1", "audit", "cognitive_enrichment", "hnsw", "entropy", "causal_mining", "umap", "release"],
    },
    "2809f7f8-63f8-45ed-8a01-c403fcdbbd4a": {
        "title": "Refining AI_PRIMARY.md and Fixing Version Drift",
        "chunks": 211, "extraction_round": 4,
        "description": "Rewrote AI_PRIMARY.md (653→408 lines). Moved 8 docs from archive to main project. Fixed version drift (v15.0→v15.1, 341→313 tools). Created Strategic Roadmap (Leaps 1-12). wm_archive README navigation guide.",
        "tags": ["ai_primary", "version_drift", "strategic_roadmap", "documentation", "archive_audit"],
    },
    "347779b3-4bb5-4822-8da5-7006bf162581": {
        "title": "Rust Bindings and Mesh Refinement",
        "chunks": 235, "extraction_round": 4,
        "description": "v14.5 Polyglot Core: Arrow IPC bridge (37x decode speedup), Tokio Clone Army (523K/sec), Iceoryx2 IPC. Fixed benchmark bugs. Go mesh gossip + agent_stream fully implemented. 18/18 Tier 2 benchmarks passing.",
        "tags": ["v14_5", "arrow_ipc", "tokio", "iceoryx2", "benchmarks", "go_mesh", "polyglot"],
    },
    "3bb20d79-9f5e-4785-b6be-04e3e253f758": {
        "title": "Integrate Progress & Parallelization",
        "chunks": 630, "extraction_round": 4,
        "description": "Massive session (630 chunks): Campaign system, parallel execution engine, ProgressTracker, CycleEngine (Yin-Yang/Wu Xing/Zodiacal), deploy_grand_army.py refactored with time-limited mode and Sun Bin columns.",
        "tags": ["campaigns", "parallelization", "progress_tracker", "cycle_engine", "yin_yang", "deploy_grand_army"],
    },
    # ── Round 5 (probed Feb 14 2026 via trajectory_search, batch 3-5) ──
    "78e644ec-6106-41d4-ac68-da33042622eb": {
        "title": "Website Overhaul and MCP Prep",
        "chunks": 365, "extraction_round": 5,
        "description": "Complete website overhaul: 白術 logo, Crimson Pro + Noto Serif SC fonts, EN/中文 toggle, dark/light mode, galaxy video hero, 28-Gana interactive wheel. MCP Registry server.json created. Docker slim image (285MB). v15.1 release strategy doc.",
        "tags": ["website", "mcp_registry", "docker", "v15_1", "i18n", "release_strategy", "server_json"],
    },
    "ad4432f9-378d-46f3-bc3e-57fd7c9169ae": {
        "title": "Ollama Context Injection Pipeline",
        "chunks": 374, "extraction_round": 5,
        "description": "v15.4-15.5: Ollama context injection (auto-recall into LLM prompts), MCP lean server PRAT descriptions updated for all 28 Ganas, server.json/mcp-registry.json version bumps, association batch classifier script.",
        "tags": ["ollama", "context_injection", "prat_descriptions", "v15_4", "v15_5", "mcp_server"],
    },
    "cfc73124-f1a0-41fe-a02c-d4c3764f304e": {
        "title": "Fixing MyPy Errors",
        "chunks": 751, "extraction_round": 5,
        "description": "Massive session (751 chunks): v14.3.1 audit, wm init scaffolding (.mcp.json, run.sh, playground.py), 5 runtime regressions fixed (gnosis, state-path, embeddings, shelter, researcher). Mypy 43→0 errors. CI gate promotion. wmdummy2 fresh install test.",
        "tags": ["mypy", "v14_3", "wm_init", "fresh_install", "runtime_fixes", "ci_gate", "scaffolding"],
    },
    "f114b6b7-7959-4f3e-a11b-5a069d646581": {
        "title": "Fixing Activation Sequence",
        "chunks": 203, "extraction_round": 5,
        "description": "v15.9 activation: Fixed narrative compressor noise exclusion, harmony vector cold-start, causal miner sampling, bridge synthesizer string-index bug. Benchmark gauntlet v5 (26/32 passed). Shadow clone deployment prep.",
        "tags": ["v15_9", "activation_sequence", "benchmark", "bug_fixes", "narrative_compressor", "causal_miner"],
    },
    # ── Round 6 (probed Feb 14 2026 via trajectory_search, batch 6-7) ──
    "84b7fa62-e0a7-4a70-a414-17f4dca8e395": {
        "title": "Activation Sequence Deep Dive",
        "chunks": 305, "extraction_round": 6,
        "description": "Full 9-step activation sequence on rehydrated 111K-memory corpus. Master System Checklist (28 Ganas, 30+ gardens, 311 tools). Kaizen emergence: 5 constellation convergence events. Cold archive rehydration scripts. V15.8 planning doc.",
        "tags": ["activation_sequence", "rehydration", "v15_8", "kaizen", "constellations", "system_checklist"],
    },
    "8989cd8a-d1d9-41b2-8c4c-6c21700c10bd": {
        "title": "Living Memory Improvements",
        "chunks": 121, "extraction_round": 6,
        "description": "v14.2 Living Memory: Semantic projection in graph walks, fused gravity signal, HRR circular convolution engine, causality enforcement, bitemporal columns, MediaProcessor protocol, entity extractor regex fallback. 48 new tests. MandalaOS 2.0 standalone governance framework.",
        "tags": ["v14_2", "living_memory", "hrr", "graph_walker", "entity_extraction", "mandalaos", "media_processor"],
    },
    "8fc57241-a2dd-47bc-b717-2967d26b4eec": {
        "title": "WhiteMagic V15 Audit Execution",
        "chunks": 209, "extraction_round": 6,
        "description": "v15.0 release checklist audit: Version sync verification, tool count validation, economic layer (XRPL tips, product tiers), Harmony Vector StateBoard fast-read path, Zig dispatch pre-validation, product tier documentation (Free→Enterprise→Healthcare).",
        "tags": ["v15_0", "audit", "release_checklist", "product_tiers", "xrpl", "harmony_vector", "state_board"],
    },
    "94a4bea2-4d07-42ea-aa9e-0f5a22f867d1": {
        "title": "Refactor and Refine Whitemagic",
        "chunks": 934, "extraction_round": 6,
        "description": "Massive session (934 chunks): v15.7 CI fixes (38→0 failures), fresh install test (wmdummy7), skip policy enforcement, version bump 15.6→15.7, MCP server entry point hardening, test suite stabilization (2260 passed). GitHub Actions green.",
        "tags": ["v15_7", "ci_fixes", "fresh_install", "test_stabilization", "skip_policy", "github_actions"],
    },
    # ── Round 7 (Feb 14 2026 — this session) ──
    "940297dd-a7e4-4fbf-8875-a4e7e2a23440": {
        "title": "Grand Strategy V16 Review + V001 Census Execution",
        "chunks": 29, "extraction_round": 7,
        "description": "Session handoff review, ran Windsurf ingestion scripts (all 36 already ingested), built V001 Great Codebase Census script (AST-based import scanner, dependency graph, dead code detection, functional classification, bio-subsystem mapping, quality scorecard, redundancy detection). Census results: 857 files, 141K LOC, 258 dead code files (33K LOC), 1505 redundancy pairs, 0 uncategorized.",
        "tags": ["v16", "census", "v001", "codebase_analysis", "dead_code", "import_graph", "grand_strategy"],
    },
}

# UUIDs confirmed as non-conversation data (returned 0 chunks from trajectory_search)
DEAD_UUIDS = {
    "41a50aa3-746a-45e6-8546-6d9b90ed9bc1",
    "4384f7da-e7ca-483d-8b2d-e0af333bbab7",
    "4b54b060-84ef-4542-9964-52fb9b5e953f",
    "4d6f5d35-465a-4e2a-beda-b34a1efab8f8",
    "541f55f1-771b-4437-bc8f-44879a38cf23",
    "5956871e-761c-4cf6-808b-505c13e78c19",
    "5b1c42c6-87e2-4dde-928e-528b28f44e23",
    "5ee172f1-1c82-44a2-b5a8-543dc419dc9e",
    "606a5cfb-c6e2-451c-82c0-c7a2c2b15d1c",
    "6f230d78-cc0c-4a19-a7c1-103df0b3b3fd",
    "6ff11acb-98d5-4f59-86c1-11c31a0f1387",
    "7175ecca-6cd5-4dc5-9478-f572be48fdb6",
    "9c186d8e-ed8a-471e-9714-577688e30a74",
    "9dd7bb64-cb9c-424e-bb01-2d2c6170c708",
    "9ed2ce96-07c5-49f6-8014-486eab6d62bb",
    "b3a23276-952b-4330-bdeb-c6aa8b659d53",
    "b994d6ca-a4bd-4174-9f1d-27bec6fc3269",
    "bbe28c11-f2e5-466a-8298-73e6efff1a91",
    "c5c54df8-881e-433e-b928-5b63de4ac036",
    "f8de6773-1e0b-4caa-8f19-699b69ae0fd3",
    "fe0f6cb5-7875-4bc8-ada0-d1bbe0283809",
}

# UUIDs that need trajectory_search probing (not yet extracted, excluding dead)
UNPROBED_UUIDS = sorted(set(ALL_PB_UUIDS) - set(EXTRACTED_CONVERSATIONS.keys()) - DEAD_UUIDS)


def get_db_path(galaxy: str | None = None) -> Path:
    """Get the target DB path."""
    if galaxy:
        return Path.home() / ".whitemagic" / "memory" / "galaxies" / galaxy / "whitemagic.db"
    try:
        from whitemagic.config.paths import DB_PATH
        return DB_PATH
    except ImportError:
        return Path.home() / ".whitemagic" / "memory" / "whitemagic.db"


def generate_content(conv: dict) -> str:
    """Generate rich memory content from conversation metadata."""
    lines = [
        f"# Windsurf Cascade Session: {conv['title']}",
        "",
        f"**UUID**: {conv.get('uuid', 'unknown')}",
        f"**Chunks**: {conv['chunks']}",
        f"**Extraction Round**: {conv.get('extraction_round', 'unknown')}",
        f"**Extracted**: {datetime.now(UTC).strftime('%Y-%m-%d')}",
        "",
        "## Summary",
        conv["description"],
        "",
        "## Tags",
        ", ".join(conv.get("tags", [])),
    ]
    if conv.get("key_findings"):
        lines.extend(["", "## Key Findings"])
        for finding in conv["key_findings"]:
            lines.append(f"- {finding}")
    return "\n".join(lines)


def ingest_conversations(
    db_path: Path,
    conversations: dict[str, dict],
    apply: bool = False,
) -> tuple[int, int]:
    """Insert conversations as LONG_TERM memories."""
    conn = sqlite3.connect(str(db_path))
    conn.row_factory = sqlite3.Row
    conn.execute("PRAGMA journal_mode=WAL")

    ingested = 0
    skipped = 0

    for conv_uuid, conv in sorted(conversations.items()):
        conv["uuid"] = conv_uuid
        title = f"Windsurf Session: {conv['title']}"
        content = generate_content(conv)
        content_hash = hashlib.sha256(content.encode()).hexdigest()

        # Check for duplicate by title
        existing = conn.execute(
            "SELECT id FROM memories WHERE title = ?", (title,)
        ).fetchone()
        if existing:
            log.info(f"  SKIP (exists): {title}")
            skipped += 1
            continue

        # Check by content hash
        existing_hash = conn.execute(
            "SELECT id FROM memories WHERE content_hash = ?", (content_hash,)
        ).fetchone()
        if existing_hash:
            log.info(f"  SKIP (hash): {title}")
            skipped += 1
            continue

        if not apply:
            log.info(f"  DRY RUN: {title} ({conv['chunks']} chunks, {len(content)} chars)")
            continue

        memory_id = str(uuid.uuid4())
        now = datetime.now(UTC).isoformat()

        conn.execute(
            """INSERT INTO memories (id, content, memory_type, title, created_at,
               accessed_at, access_count, emotional_valence, importance, neuro_score,
               novelty_score, recall_count, half_life_days, is_protected,
               galactic_distance, retention_score, content_hash, metadata)
               VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""",
            (
                memory_id, content, "LONG_TERM", title, now, now,
                1, 0.3, 0.85, 0.9, 0.6, 0, 90.0, 1,
                0.1, 0.9, content_hash,
                json.dumps({
                    "source": "windsurf_trajectory_search",
                    "extraction_round": conv.get("extraction_round", 3),
                    "uuid": conv_uuid,
                    "chunks": conv["chunks"],
                }),
            ),
        )

        # Insert tags
        base_tags = {"windsurf_session", "cascade_transcript", "development_history"}
        all_tags = base_tags | set(conv.get("tags", []))
        for tag in sorted(all_tags):
            conn.execute(
                "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
                (memory_id, tag),
            )

        conn.commit()
        ingested += 1
        log.info(f"  INGESTED: {title} ({memory_id[:8]}, {conv['chunks']} chunks)")

    conn.close()
    return ingested, skipped


def show_inventory():
    """Display the full conversation inventory."""
    print("=" * 70)
    print("  Windsurf Cascade Conversation Inventory")
    print("=" * 70 + "\n")

    print(f"  .pb files:     {len(ALL_PB_UUIDS)}")
    print(f"  LevelDB UUIDs: {len(LEVELDB_ONLY_UUIDS)} (additional)")
    print(f"  Extracted:     {len(EXTRACTED_CONVERSATIONS)}")
    print(f"  Unprobed:      {len(UNPROBED_UUIDS)}")
    total_chunks = sum(c["chunks"] for c in EXTRACTED_CONVERSATIONS.values())
    print(f"  Total chunks:  {total_chunks}")
    print()

    print("  EXTRACTED CONVERSATIONS:")
    print(f"  {'UUID':>8}  {'Chunks':>6}  {'Rnd':>3}  Title")
    print(f"  {'-'*8}  {'-'*6}  {'-'*3}  {'-'*40}")
    for conv_uuid, conv in sorted(EXTRACTED_CONVERSATIONS.items(), key=lambda x: x[1].get("extraction_round", 0)):
        short = conv_uuid[:8]
        print(f"  {short}  {conv['chunks']:>6}  R{conv.get('extraction_round', '?'):>2}  {conv['title']}")

    if UNPROBED_UUIDS:
        print(f"\n  UNPROBED ({len(UNPROBED_UUIDS)} remaining):")
        for i, u in enumerate(UNPROBED_UUIDS):
            print(f"  {i+1:>3}. {u}")


def main():
    parser = argparse.ArgumentParser(description="Extract and ingest Windsurf conversations")
    parser.add_argument("--apply", action="store_true", help="Actually ingest (default is dry run)")
    parser.add_argument("--inventory", action="store_true", help="Show conversation inventory")
    parser.add_argument("--galaxy", type=str, default=None, help="Target galaxy name")
    args = parser.parse_args()

    if args.inventory:
        show_inventory()
        return

    db_path = get_db_path(args.galaxy)

    if not db_path.exists():
        log.error(f"DB not found: {db_path}")
        if args.galaxy:
            log.info(f"Create the galaxy first: wm galaxy create {args.galaxy}")
        sys.exit(1)

    log.info(f"Target DB: {db_path}")
    log.info(f"Conversations to ingest: {len(EXTRACTED_CONVERSATIONS)}")
    log.info(f"Unprobed UUIDs remaining: {len(UNPROBED_UUIDS)}")

    ingested, skipped = ingest_conversations(db_path, EXTRACTED_CONVERSATIONS, args.apply)

    log.info(f"\nResults: {ingested} ingested, {skipped} skipped")
    if not args.apply and ingested == 0 and skipped == 0:
        log.info("Run with --apply to actually ingest")


if __name__ == "__main__":
    main()
