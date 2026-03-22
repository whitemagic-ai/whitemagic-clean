#!/usr/bin/env python3
"""S025 Phase 3: System-to-Garden Mapping.

Analyzes codebase subsystems and maps them to gardens based on:
1. File composition (which files belong to each system)
2. Cross-system dependencies
3. Primary vs operating garden assignments
"""

from __future__ import annotations

import json
import sys
from collections import defaultdict
from pathlib import Path
from typing import Any

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.garden_directory import GardenDirectory

# System definitions based on codebase structure
SYSTEM_DEFINITIONS: dict[str, dict[str, Any]] = {
    "memory": {
        "description": "Memory storage, retrieval, and consolidation",
        "paths": ["whitemagic/core/memory/", "whitemagic/core/intelligence/hologram/"],
        "keywords": ["memory", "store", "recall", "embed", "association", "galactic"],
    },
    "dream": {
        "description": "Dream cycle, sleep phases, nocturnal processing",
        "paths": ["whitemagic/core/dreaming/", "whitemagic/core/intelligence/synthesis/"],
        "keywords": ["dream", "sleep", "cycle", "serendipity", "consolidation"],
    },
    "mcp": {
        "description": "MCP tool dispatch, routing, and handling",
        "paths": ["whitemagic/tools/"],
        "keywords": ["mcp", "tool", "dispatch", "handler", "router"],
    },
    "immune": {
        "description": "Security, defense, pattern immunity",
        "paths": ["whitemagic/core/immune/"],
        "keywords": ["immune", "defense", "antibod", "security", "protect"],
    },
    "evolution": {
        "description": "Evolutionary algorithms, phylogenetics",
        "paths": ["whitemagic/core/evolution/", "whitemagic/agents/phylogenetics"],
        "keywords": ["evolution", "phylogen", "genome", "selection", "mutate"],
    },
    "governance": {
        "description": "Governance, policy, doctrine",
        "paths": ["whitemagic/core/governance/", "whitemagic/agents/doctrine"],
        "keywords": ["govern", "policy", "doctrine", "rule", "dharma"],
    },
    "resonance": {
        "description": "Resonance engine, harmony, emotional processing",
        "paths": ["whitemagic/core/resonance/"],
        "keywords": ["resonance", "harmony", "emotion", "feeling"],
    },
    "consciousness": {
        "description": "Consciousness, awareness, embodiment",
        "paths": ["whitemagic/core/consciousness/"],
        "keywords": ["conscious", "aware", "embodiment", "coherence"],
    },
    "agents": {
        "description": "Agent systems, campaigns, clone armies",
        "paths": ["whitemagic/agents/"],
        "keywords": ["agent", "campaign", "clone", "army", "lieutenant"],
    },
    "cli": {
        "description": "Command-line interface",
        "paths": ["whitemagic/cli/"],
        "keywords": ["cli", "command", "argparse", "terminal"],
    },
    "embedding": {
        "description": "Embedding generation and vector search",
        "paths": ["whitemagic/core/memory/embeddings"],
        "keywords": ["embedding", "vector", "similarity", "encode"],
    },
    "graph": {
        "description": "Knowledge graph, associations, constellations",
        "paths": ["whitemagic/core/intelligence/"],
        "keywords": ["graph", "edge", "node", "constellation", "cluster"],
    },
    "search": {
        "description": "Search, FTS, hybrid retrieval",
        "paths": ["whitemagic/search/"],
        "keywords": ["search", "fts", "query", "retrieve", "recall"],
    },
    "storage": {
        "description": "Storage, persistence, backup",
        "paths": ["whitemagic/storage/", "whitemagic/core/memory/sqlite"],
        "keywords": ["storage", "persist", "backup", "save", "load"],
    },
    "security": {
        "description": "Security, sandboxing, input validation",
        "paths": ["whitemagic/core/boundaries/", "whitemagic/tools/sandbox"],
        "keywords": ["security", "sandbox", "validat", "sanitize"],
    },
    "acceleration": {
        "description": "Rust/Mojo/Zig acceleration, SIMD",
        "paths": ["whitemagic/acceleration/", "whitemagic-rust/", "whitemagic-mojo/", "whitemagic-zig/"],
        "keywords": ["accelerat", "simd", "rust", "mojo", "zig", "native"],
    },
    "alchemy": {
        "description": "Alchemical transformation, synthesis",
        "paths": ["whitemagic/alchemy/"],
        "keywords": ["alchemy", "nigredo", "albedo", "rubedo", "transmut"],
    },
    "grimoire": {
        "description": "Grimoire, sacred texts, wisdom",
        "paths": ["whitemagic/grimoire/"],
        "keywords": ["grimoire", "sacred", "wisdom", "spell"],
    },
    "zodiac": {
        "description": "Zodiac, astrological mappings",
        "paths": ["whitemagic/zodiac/", "whitemagic/core/zodiac/"],
        "keywords": ["zodiac", "astro", "sign", "mansion"],
    },
    "bridge": {
        "description": "Polyglot bridges, language interop",
        "paths": ["whitemagic/bridge/", "whitemagic/core/bridge/"],
        "keywords": ["bridge", "interop", "polyglot", "ffi"],
    },
    "gardens": {
        "description": "Garden system, emotional modules",
        "paths": ["whitemagic/gardens/", "whitemagic/core/gardens/"],
        "keywords": ["garden", "emotion", "joy", "love", "wisdom"],
    },
}


def analyze_systems(directory: GardenDirectory) -> dict[str, Any]:
    """Analyze systems and map to gardens."""
    system_mappings: dict[str, dict[str, Any]] = {}

    for system_id, system_def in SYSTEM_DEFINITIONS.items():
        # Find files belonging to this system
        system_files = []
        garden_counts: dict[str, int] = defaultdict(int)

        for fp, mapping in directory._file_mappings.items():
            # Check if file belongs to this system
            belongs = False
            for path_prefix in system_def.get("paths", []):
                if path_prefix in fp:
                    belongs = True
                    break

            if not belongs:
                # Check keywords
                fp_lower = fp.lower()
                for kw in system_def.get("keywords", []):
                    if kw in fp_lower:
                        belongs = True
                        break

            if belongs:
                system_files.append(fp)
                garden_counts[mapping.primary_garden] += 1

        # Determine primary and operating gardens
        if garden_counts:
            sorted_gardens = sorted(garden_counts.items(), key=lambda x: -x[1])
            primary_garden = sorted_gardens[0][0]
            operating_gardens = [g for g, c in sorted_gardens[1:4] if c > 0]
        else:
            primary_garden = "mystery"
            operating_gardens = []

        system_mappings[system_id] = {
            "description": system_def.get("description", ""),
            "primary_garden": primary_garden,
            "operating_gardens": operating_gardens,
            "file_count": len(system_files),
            "garden_distribution": dict(garden_counts),
            "sample_files": system_files[:10],
        }

    return system_mappings


def generate_system_report(system_mappings: dict[str, Any], output_path: Path) -> None:
    """Generate human-readable system mapping report."""
    lines = [
        "# S025: System-to-Garden Mapping Report",
        "",
        "## System Overview",
        "",
        "| System | Primary Garden | Operating Gardens | Files |",
        "|--------|---------------|-------------------|-------|",
    ]

    for system_id, mapping in sorted(system_mappings.items(), key=lambda x: -x[1]["file_count"]):
        ops = ", ".join(mapping["operating_gardens"][:2]) if mapping["operating_gardens"] else "-"
        lines.append(f"| {system_id} | {mapping['primary_garden']} | {ops} | {mapping['file_count']} |")

    lines.extend([
        "",
        "## Detailed Mappings",
        "",
    ])

    for system_id, mapping in sorted(system_mappings.items()):
        lines.append(f"### {system_id}")
        lines.append("")
        lines.append(f"**Description**: {mapping['description']}")
        lines.append(f"**Primary Garden**: {mapping['primary_garden']}")
        lines.append(f"**Operating Gardens**: {', '.join(mapping['operating_gardens']) or 'none'}")
        lines.append(f"**File Count**: {mapping['file_count']}")
        lines.append("")
        lines.append("**Garden Distribution**:")
        lines.append("")
        for garden, count in sorted(mapping["garden_distribution"].items(), key=lambda x: -x[1]):
            lines.append(f"- {garden}: {count}")
        lines.append("")
        if mapping["sample_files"]:
            lines.append("**Sample Files**:")
            lines.append("")
            for fp in mapping["sample_files"]:
                lines.append(f"- `{fp}`")
            lines.append("")

    output_path.write_text("\n".join(lines))
    print(f"📄 System report saved to {output_path}")


def main() -> None:
    """Run the system scanner."""
    root = Path(__file__).parent.parent

    print("=" * 60)
    print("🌸 S025 Phase 3: System-to-Garden Mapping")
    print("=" * 60)
    print()

    # Load file directory
    file_registry_path = root / "data" / "garden_file_registry.json"
    directory = GardenDirectory(file_registry_path)
    if not directory.load():
        print("❌ File registry not found. Run s025_garden_organization.py first.")
        return

    # Analyze systems
    system_mappings = analyze_systems(directory)

    # Save system mappings
    system_registry_path = root / "data" / "garden_system_registry.json"
    system_registry_path.parent.mkdir(parents=True, exist_ok=True)
    system_registry_path.write_text(json.dumps(system_mappings, indent=2))
    print(f"💾 System registry saved to {system_registry_path}")

    # Generate report
    report_path = root / "reports" / "garden_system_mapping.md"
    report_path.parent.mkdir(parents=True, exist_ok=True)
    generate_system_report(system_mappings, report_path)

    # Summary
    print()
    print("=" * 60)
    print("SUMMARY")
    print("=" * 60)
    print(f"Systems analyzed: {len(system_mappings)}")

    # Count garden assignments
    garden_systems: dict[str, list[str]] = defaultdict(list)
    for system_id, mapping in system_mappings.items():
        garden_systems[mapping["primary_garden"]].append(system_id)

    print()
    print("Garden → Systems:")
    for garden, systems in sorted(garden_systems.items()):
        if systems:
            print(f"  {garden}: {', '.join(systems)}")


if __name__ == "__main__":
    main()
