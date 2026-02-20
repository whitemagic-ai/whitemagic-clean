#!/usr/bin/env python3
"""V001: The Great Codebase Census — AST-based full codebase analysis.

Scans every Python file under the project root (excluding .venv, __pycache__,
_archives, .mypy_cache, .ruff_cache, egg-info), plus counts polyglot files.
Builds:
1. Complete import dependency graph
2. Reverse dependency map (who imports whom)
3. Dead code report (0 importers, no __main__)
4. Functional category classification
5. Biological subsystem mapping
6. Quality scorecard (docstrings, type hints, tests)
7. Redundancy detection (import similarity)

Outputs:
  reports/import_graph.json   — full graph data
  reports/dead_code.json      — dead code candidates
  reports/great_census.md     — comprehensive human-readable report

Usage:
    .venv/bin/python scripts/codebase_census.py
"""

from __future__ import annotations

import ast
import json
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

ROOT = Path(__file__).resolve().parent.parent
WHITEMAGIC = ROOT / "whitemagic"
SCRIPTS = ROOT / "scripts"
TESTS = ROOT / "tests"
REPORTS = ROOT / "reports"

# Directories to scan for Python files (relative to ROOT)
SCAN_DIRS = ["whitemagic", "scripts", "tests", "eval", "examples"]

# Directories/patterns to skip
SKIP_PATTERNS = {
    "__pycache__", ".venv", ".mypy_cache", ".ruff_cache",
    "_archives", "whitemagic.egg-info", ".pytest_cache",
    "node_modules", ".git",
}

# Polyglot file extensions to count
POLYGLOT_EXTENSIONS: dict[str, list[str]] = {
    "Rust": [".rs"],
    "TypeScript": [".ts", ".tsx"],
    "Elixir": [".ex", ".exs"],
    "Haskell": [".hs"],
    "Zig": [".zig"],
    "Mojo": [".mojo"],
    "Go": [".go"],
    "Julia": [".jl"],
    "Markdown": [".md"],
}

# ---------------------------------------------------------------------------
# Functional categories
# ---------------------------------------------------------------------------

CATEGORY_PATTERNS: dict[str, list[str]] = {
    "memory_core": [
        "core/memory/", "core/intelligence/hologram/",
    ],
    "intelligence": [
        "core/intelligence/", "core/patterns/",
    ],
    "tools_handlers": [
        "tools/handlers/", "tools/dispatch",
    ],
    "tools_infrastructure": [
        "tools/", "dispatch_table", "prat_router",
    ],
    "dreaming": [
        "core/dreaming/", "dream",
    ],
    "immune_security": [
        "core/immune/", "security/", "core/autoimmune",
    ],
    "consciousness": [
        "core/consciousness/", "core/embodiment", "coherence",
    ],
    "resonance_harmony": [
        "core/resonance/", "harmony",
    ],
    "emergence_ecology": [
        "core/ecology/", "emergence", "serendipity",
    ],
    "gardens": [
        "gardens/",
    ],
    "agents": [
        "agents/",
    ],
    "cli": [
        "cli/",
    ],
    "config_infra": [
        "config/", "__init__", "__main__", "config.py",
    ],
    "ai_llm": [
        "ai/", "ollama",
    ],
    "payments_economy": [
        "payments/", "marketplace/", "oms/", "shelter/",
    ],
    "interfaces_api": [
        "interfaces/api/", "interfaces/nexus", "interfaces/terminal/",
    ],
    "bridge_polyglot": [
        "core/bridge/", "core/polyglot/", "bridges/", "core/acceleration/",
    ],
    "orchestration": [
        "core/orchestration/", "core/automation/", "automation/",
    ],
    "ganas_zodiac": [
        "core/ganas/", "core/zodiac/", "zodiac/",
    ],
    "governance_dharma": [
        "core/governance/", "dharma/", "core/boundaries/",
    ],
    "autonomous": [
        "autonomous/",
    ],
    "monitoring": [
        "core/monitoring/",
    ],
    "archaeology": [
        "archaeology/",
    ],
    "search": [
        "search/",
    ],
    "cache": [
        "cache/",
    ],
    "prompts": [
        "prompts/",
    ],
    "cascade": [
        "cascade/",
    ],
    "parallel": [
        "parallel/",
    ],
    "integration": [
        "integration/",
    ],
    "auth": [
        "auth/",
    ],
    "benchmarks": [
        "benchmarks/",
    ],
    "plugin": [
        "core/plugin/",
    ],
    "economy": [
        "core/economy/", "core/token_economy",
    ],
    "temporal": [
        "core/temporal/",
    ],
    "intake": [
        "core/intake/",
    ],
    "grimoire": [
        "grimoire/",
    ],
    "nurturing": [
        "core/nurturing/",
    ],
    "optimization": [
        "optimization/",
    ],
    "rosetta": [
        "rosetta",
    ],
    "utils": [
        "utils/",
    ],
    "edge_inference": [
        "edge/", "inference/", "local_ml/",
    ],
    "mesh_federation": [
        "mesh/",
    ],
    "oracle": [
        "oracle/",
    ],
    "execution_safety": [
        "execution/", "safety/",
    ],
    "gratitude": [
        "gratitude/",
    ],
    "hardware": [
        "hardware/",
    ],
    "maintenance": [
        "maintenance/",
    ],
    "metrics": [
        "metrics/",
    ],
    "sessions": [
        "sessions/",
    ],
    "plugins": [
        "plugins/",
    ],
    "docs_interactive": [
        "docs/",
    ],
    "db": [
        "db/",
    ],
    "continuity": [
        "continuity/",
    ],
    "core_misc": [
        "core/alignment/", "core/async_layer", "core/autonomy",
        "core/continuity", "core/engines/", "core/exceptions",
        "core/fusion/", "core/fusions", "core/governor",
        "core/health_monitor", "core/homeostasis", "core/learning/",
        "core/scoring/", "core/semantic_fs", "core/update_checker",
        "core/user", "homeostasis",
    ],
    "mcp_entry": [
        "run_mcp", "mcp_api_bridge", "playground", "seed.py",
        "cycle_engine",
    ],
    "scripts": [
        "scripts/",
    ],
    "tests": [
        "tests/",
    ],
    "eval": [
        "eval/",
    ],
    "examples": [
        "examples/",
    ],
    "immune_toplevel": [
        "immune/",
    ],
    "interfaces_misc": [
        "interfaces/dashboard/", "interfaces/tui",
    ],
    "orchestration_toplevel": [
        "orchestration/",
    ],
    "resonance_toplevel": [
        "resonance/",
    ],
}

# ---------------------------------------------------------------------------
# Biological subsystems
# ---------------------------------------------------------------------------

BIO_PATTERNS: dict[str, list[str]] = {
    "immune": [
        "immune", "antibod", "autoimmune", "security", "threat",
        "defense", "health_check", "health_monitor", "dna.py",
    ],
    "genetic_evolutionary": [
        "phylogenetic", "evolution", "genome", "phenotype", "selection",
        "guideline_evolution", "genetic",
    ],
    "dream_sleep": [
        "dream", "sleep", "narrative_compress", "dream_daemon",
        "dream_synthesis", "dream_state", "dream_cycle",
    ],
    "memory_metabolism": [
        "consolidat", "reconsolidat", "forgetting", "decay",
        "mindful_forgetting", "retention",
    ],
    "consciousness_embodiment": [
        "consciousness", "coherence", "embodiment", "emotional_memory",
        "awareness",
    ],
    "resonance_harmony": [
        "resonance", "harmony", "resonance_engine", "garden_resonance",
        "resonance_amp",
    ],
    "emergence_ecology": [
        "emergence", "serendipity", "ecology", "novelty",
    ],
    "nervous_system": [
        "cycle_engine", "homeostasis", "nervous", "state_board",
        "event_ring", "dispatch_core",
    ],
    "garden_ecosystem": [
        "gardens/",
    ],
    "none": [],
}


@dataclass
class FileInfo:
    """Census data for a single Python file."""
    path: str  # relative to project root
    module: str  # dotted module path
    loc: int = 0
    imports: list[str] = field(default_factory=list)  # modules this file imports
    imported_by: list[str] = field(default_factory=list)  # files that import this
    category: str = "uncategorized"
    bio_subsystem: str = "none"
    has_docstring: bool = False
    has_type_hints: bool = False
    has_main_block: bool = False
    class_count: int = 0
    function_count: int = 0
    docstring_pct: float = 0.0
    type_hint_pct: float = 0.0
    test_file: str | None = None
    is_dead: bool = False
    import_set: set[str] = field(default_factory=set)  # for similarity


def path_to_module(filepath: Path, root: Path) -> str:
    """Convert a file path to a dotted module path."""
    rel = filepath.relative_to(root)
    parts = list(rel.parts)
    if parts[-1] == "__init__.py":
        parts = parts[:-1]
    else:
        parts[-1] = parts[-1].replace(".py", "")
    return ".".join(parts)


def resolve_import(import_name: str, current_module: str, level: int = 0) -> str:
    """Resolve a relative import to an absolute module path."""
    if level == 0:
        return import_name
    # Relative import: go up 'level' packages from current_module
    parts = current_module.split(".")
    if level > len(parts):
        return import_name or current_module
    base = ".".join(parts[:-level]) if level <= len(parts) else ""
    if import_name:
        return f"{base}.{import_name}" if base else import_name
    return base


def analyze_file(filepath: Path, root: Path) -> FileInfo | None:
    """Analyze a single Python file using AST."""
    rel_path = str(filepath.relative_to(root))
    module = path_to_module(filepath, root)

    try:
        source = filepath.read_text(encoding="utf-8", errors="replace")
    except Exception:
        return None

    loc = len([ln for ln in source.splitlines() if ln.strip() and not ln.strip().startswith("#")])

    try:
        tree = ast.parse(source, filename=str(filepath))
    except SyntaxError:
        return FileInfo(path=rel_path, module=module, loc=loc)

    info = FileInfo(path=rel_path, module=module, loc=loc)
    imports: set[str] = set()

    # Module-level docstring
    if (tree.body and isinstance(tree.body[0], ast.Expr)
            and isinstance(tree.body[0].value, ast.Constant)):
        info.has_docstring = True

    # Walk the AST
    functions_with_hints = 0
    functions_with_docstrings = 0
    total_functions = 0

    for node in ast.walk(tree):
        # Imports
        if isinstance(node, ast.Import):
            for alias in node.names:
                imports.add(alias.name.split(".")[0])
                if alias.name.startswith("whitemagic"):
                    imports.add(alias.name)
        elif isinstance(node, ast.ImportFrom):
            if node.module:
                resolved = resolve_import(node.module, module, node.level or 0)
                imports.add(resolved.split(".")[0])
                if resolved.startswith("whitemagic") or node.module.startswith("whitemagic"):
                    imports.add(resolved)
                    imports.add(node.module)
            elif node.level:
                resolved = resolve_import("", module, node.level)
                if resolved:
                    imports.add(resolved)

        # Classes
        elif isinstance(node, ast.ClassDef):
            info.class_count += 1

        # Functions
        elif isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
            total_functions += 1
            # Check for docstring
            if (node.body and isinstance(node.body[0], ast.Expr)
                    and isinstance(node.body[0].value, ast.Constant)):
                functions_with_docstrings += 1
            # Check for return type annotation
            if node.returns is not None:
                functions_with_hints += 1
            # Check for any arg annotations
            elif any(arg.annotation for arg in node.args.args):
                functions_with_hints += 1

        # __main__ block
        elif isinstance(node, ast.If):
            if (isinstance(node.test, ast.Compare)
                    and isinstance(node.test.left, ast.Name)
                    and node.test.left.id == "__name__"):
                info.has_main_block = True

    info.function_count = total_functions
    info.imports = sorted(imports)
    info.import_set = imports

    # Calculate percentages
    if total_functions > 0:
        info.docstring_pct = round(functions_with_docstrings / total_functions * 100, 1)
        info.type_hint_pct = round(functions_with_hints / total_functions * 100, 1)

    info.has_type_hints = functions_with_hints > 0

    return info


def classify_category(filepath: str) -> str:
    """Classify file into a functional category."""
    for category, patterns in CATEGORY_PATTERNS.items():
        for pat in patterns:
            if pat in filepath:
                return category
    return "uncategorized"


def classify_bio(filepath: str, content_lower: str = "") -> str:
    """Classify file into a biological subsystem."""
    fp_lower = filepath.lower()
    for subsystem, patterns in BIO_PATTERNS.items():
        if subsystem == "none":
            continue
        for pat in patterns:
            if pat in fp_lower:
                return subsystem
    return "none"


def find_test_file(module_path: str, test_dir: Path) -> str | None:
    """Find the corresponding test file for a module."""
    # whitemagic/core/memory/sqlite_backend.py -> test_sqlite_backend.py
    basename = module_path.split(".")[-1]
    candidates = [
        f"test_{basename}.py",
        f"test_{basename}s.py",
    ]
    for candidate in candidates:
        matches = list(test_dir.rglob(candidate))
        if matches:
            return str(matches[0].relative_to(test_dir.parent))
    return None


def compute_import_similarity(a: set[str], b: set[str]) -> float:
    """Jaccard similarity of import sets."""
    if not a and not b:
        return 0.0
    intersection = a & b
    union = a | b
    if not union:
        return 0.0
    return len(intersection) / len(union)


def run_census() -> dict[str, Any]:
    """Run the full codebase census."""
    print("V001: The Great Codebase Census")
    print("=" * 60)

    # Phase 1: Scan all Python files
    print("\n[Phase 1] Scanning Python files...")
    py_files: list[Path] = []
    for scan_dir_name in SCAN_DIRS:
        scan_dir = ROOT / scan_dir_name
        if scan_dir.is_dir():
            for f in sorted(scan_dir.rglob("*.py")):
                if not any(skip in f.parts for skip in SKIP_PATTERNS):
                    py_files.append(f)

    # Phase 1b: Count polyglot files
    polyglot_stats: dict[str, dict[str, int]] = {}
    for lang, exts in POLYGLOT_EXTENSIONS.items():
        file_count = 0
        line_count = 0
        for ext in exts:
            for f in ROOT.rglob(f"*{ext}"):
                if any(skip in f.parts for skip in SKIP_PATTERNS):
                    continue
                file_count += 1
                try:
                    line_count += sum(
                        1 for ln in f.read_text(errors="replace").splitlines()
                        if ln.strip() and not ln.strip().startswith("//")
                        and not ln.strip().startswith("#")
                        and not ln.strip().startswith("--")
                    )
                except Exception:
                    pass
        if file_count > 0:
            polyglot_stats[lang] = {"files": file_count, "loc": line_count}
    print(f"  Polyglot: {sum(s['files'] for s in polyglot_stats.values())} files across {len(polyglot_stats)} languages")

    files: dict[str, FileInfo] = {}
    module_to_path: dict[str, str] = {}

    for filepath in py_files:
        info = analyze_file(filepath, ROOT)
        if info:
            files[info.path] = info
            module_to_path[info.module] = info.path
            # Also index partial module paths
            parts = info.module.split(".")
            for i in range(1, len(parts) + 1):
                partial = ".".join(parts[:i])
                if partial not in module_to_path:
                    module_to_path[partial] = info.path

    print(f"  Scanned: {len(files)} files")

    # Phase 2: Build reverse dependency map
    print("\n[Phase 2] Building dependency graph...")
    for path, info in files.items():
        for imp in info.imports:
            if imp in module_to_path:
                target_path = module_to_path[imp]
                if target_path in files and target_path != path:
                    files[target_path].imported_by.append(path)

    # Phase 3: Classify files
    print("\n[Phase 3] Classifying files...")
    for path, info in files.items():
        info.category = classify_category(path)
        info.bio_subsystem = classify_bio(path)
        info.test_file = find_test_file(info.module, TESTS)
        # Dead code: no importers, no __main__, not __init__.py
        info.is_dead = (
            len(info.imported_by) == 0
            and not info.has_main_block
            and not path.endswith("__init__.py")
            and "test" not in path.lower()
        )

    # Phase 4: Redundancy detection
    print("\n[Phase 4] Detecting redundancy...")
    redundancy_pairs: list[dict] = []
    paths_list = list(files.keys())
    for i in range(len(paths_list)):
        for j in range(i + 1, len(paths_list)):
            a = files[paths_list[i]]
            b = files[paths_list[j]]
            if len(a.import_set) < 3 or len(b.import_set) < 3:
                continue
            sim = compute_import_similarity(a.import_set, b.import_set)
            if sim >= 0.6:
                redundancy_pairs.append({
                    "file_a": a.path,
                    "file_b": b.path,
                    "similarity": round(sim, 3),
                    "shared_imports": sorted(a.import_set & b.import_set),
                })

    redundancy_pairs.sort(key=lambda x: x["similarity"], reverse=True)
    print(f"  Redundancy pairs (≥60% import similarity): {len(redundancy_pairs)}")

    # Phase 5: Gather statistics
    print("\n[Phase 5] Computing statistics...")
    total_loc = sum(f.loc for f in files.values())
    total_classes = sum(f.class_count for f in files.values())
    total_functions = sum(f.function_count for f in files.values())

    category_stats: dict[str, dict] = defaultdict(lambda: {"files": 0, "loc": 0})
    bio_stats: dict[str, dict] = defaultdict(lambda: {"files": 0, "loc": 0})

    dead_code: list[dict] = []

    for info in files.values():
        category_stats[info.category]["files"] += 1
        category_stats[info.category]["loc"] += info.loc
        bio_stats[info.bio_subsystem]["files"] += 1
        bio_stats[info.bio_subsystem]["loc"] += info.loc
        if info.is_dead:
            dead_code.append({
                "path": info.path,
                "module": info.module,
                "loc": info.loc,
                "category": info.category,
                "bio_subsystem": info.bio_subsystem,
                "function_count": info.function_count,
                "class_count": info.class_count,
            })

    dead_code.sort(key=lambda x: x["loc"], reverse=True)

    # Files with test coverage
    files_with_tests = sum(1 for f in files.values() if f.test_file)
    avg_docstring = sum(f.docstring_pct for f in files.values()) / max(len(files), 1)
    avg_type_hints = sum(f.type_hint_pct for f in files.values()) / max(len(files), 1)

    # Top importers (most dependencies)
    top_importers = sorted(files.values(), key=lambda f: len(f.imports), reverse=True)[:20]
    # Most imported (most dependents)
    top_imported = sorted(files.values(), key=lambda f: len(f.imported_by), reverse=True)[:20]
    # Largest files
    largest = sorted(files.values(), key=lambda f: f.loc, reverse=True)[:20]

    # Polyglot totals
    polyglot_files_total = sum(s["files"] for s in polyglot_stats.values())
    polyglot_loc_total = sum(s["loc"] for s in polyglot_stats.values())

    results = {
        "summary": {
            "total_files": len(files),
            "total_loc": total_loc,
            "total_classes": total_classes,
            "total_functions": total_functions,
            "dead_code_files": len(dead_code),
            "dead_code_loc": sum(d["loc"] for d in dead_code),
            "files_with_tests": files_with_tests,
            "test_coverage_pct": round(files_with_tests / max(len(files), 1) * 100, 1),
            "avg_docstring_pct": round(avg_docstring, 1),
            "avg_type_hint_pct": round(avg_type_hints, 1),
            "redundancy_pairs": len(redundancy_pairs),
            "polyglot_files": polyglot_files_total,
            "polyglot_loc": polyglot_loc_total,
            "grand_total_files": len(files) + polyglot_files_total,
            "grand_total_loc": total_loc + polyglot_loc_total,
        },
        "polyglot": polyglot_stats,
        "category_stats": dict(category_stats),
        "bio_stats": dict(bio_stats),
        "dead_code": dead_code,
        "redundancy_pairs": redundancy_pairs[:50],  # top 50
        "top_importers": [{"path": f.path, "imports": len(f.imports)} for f in top_importers],
        "top_imported": [{"path": f.path, "imported_by": len(f.imported_by)} for f in top_imported],
        "largest_files": [{"path": f.path, "loc": f.loc} for f in largest],
    }

    # Phase 6: Build import graph JSON
    print("\n[Phase 6] Building import graph JSON...")
    nodes = []
    edges = []
    for info in files.values():
        nodes.append({
            "id": info.path,
            "module": info.module,
            "loc": info.loc,
            "category": info.category,
            "bio_subsystem": info.bio_subsystem,
            "is_dead": info.is_dead,
            "importers": len(info.imported_by),
            "dependencies": len(info.imports),
        })
        for imp in info.imports:
            if imp in module_to_path:
                target = module_to_path[imp]
                if target != info.path:
                    edges.append({"source": info.path, "target": target})

    import_graph = {
        "nodes": nodes,
        "edges": edges,
        "generated": "V001_great_codebase_census",
    }

    # Phase 7: Generate reports
    print("\n[Phase 7] Generating reports...")
    REPORTS.mkdir(exist_ok=True)

    # import_graph.json
    with open(REPORTS / "import_graph.json", "w") as f:
        json.dump(import_graph, f, indent=2)
    print(f"  Written: reports/import_graph.json ({len(nodes)} nodes, {len(edges)} edges)")

    # dead_code.json
    with open(REPORTS / "dead_code.json", "w") as f:
        json.dump(dead_code, f, indent=2)
    print(f"  Written: reports/dead_code.json ({len(dead_code)} files)")

    # great_census.md
    md = generate_census_report(results, files, import_graph)
    with open(REPORTS / "great_census.md", "w") as f:
        f.write(md)
    print("  Written: reports/great_census.md")

    print("\n" + "=" * 60)
    print(f"Python: {len(files)} files, {total_loc:,} LOC")
    print(f"Polyglot: {polyglot_files_total} files, {polyglot_loc_total:,} LOC ({len(polyglot_stats)} languages)")
    print(f"Grand total: {len(files) + polyglot_files_total} files, {total_loc + polyglot_loc_total:,} LOC")
    print(f"Dead code: {len(dead_code)} files ({sum(d['loc'] for d in dead_code):,} LOC)")
    print(f"Redundancy pairs: {len(redundancy_pairs)}")
    test_pct = results["summary"]["test_coverage_pct"]  # type: ignore[index]
    print(f"Test coverage: {test_pct}%")

    return results


def generate_census_report(results: dict, files: dict[str, FileInfo], graph: dict) -> str:
    """Generate the comprehensive markdown census report."""
    s = results["summary"]
    lines = [
        "# The Great Codebase Census — V001 Report",
        "",
        f"**Generated**: {__import__('datetime').datetime.now().strftime('%Y-%m-%d %H:%M')}",
        f"**Scope**: Full project root ({', '.join(SCAN_DIRS)} + polyglot)",
        "",
        "---",
        "",
        "## Executive Summary",
        "",
        "| Metric | Value |",
        "|--------|-------|",
        f"| Python files | {s['total_files']} |",
        f"| Lines of code | {s['total_loc']:,} |",
        f"| Classes | {s['total_classes']} |",
        f"| Functions | {s['total_functions']:,} |",
        f"| Dead code files | {s['dead_code_files']} ({s['dead_code_loc']:,} LOC) |",
        f"| Files with tests | {s['files_with_tests']} ({s['test_coverage_pct']}%) |",
        f"| Avg docstring coverage | {s['avg_docstring_pct']}% |",
        f"| Avg type hint coverage | {s['avg_type_hint_pct']}% |",
        f"| High-redundancy pairs | {s['redundancy_pairs']} |",
        f"| Import graph nodes | {len(graph['nodes'])} |",
        f"| Import graph edges | {len(graph['edges'])} |",
        f"| Polyglot files | {s.get('polyglot_files', 0)} ({s.get('polyglot_loc', 0):,} LOC) |",
        f"| **Grand total** | **{s.get('grand_total_files', s['total_files'])} files, {s.get('grand_total_loc', s['total_loc']):,} LOC** |",
        "",
        "---",
        "",
        "## Functional Categories",
        "",
        "| Category | Files | LOC | % of Total |",
        "|----------|-------|-----|------------|",
    ]

    cat_sorted = sorted(results["category_stats"].items(), key=lambda x: x[1]["loc"], reverse=True)
    for cat, stats in cat_sorted:
        pct = round(stats["loc"] / max(s["total_loc"], 1) * 100, 1)
        lines.append(f"| {cat} | {stats['files']} | {stats['loc']:,} | {pct}% |")

    lines.extend([
        "",
        "---",
        "",
        "## Biological Subsystems",
        "",
        "| Subsystem | Files | LOC |",
        "|-----------|-------|-----|",
    ])

    bio_sorted = sorted(results["bio_stats"].items(), key=lambda x: x[1]["loc"], reverse=True)
    for sub, stats in bio_sorted:
        lines.append(f"| {sub} | {stats['files']} | {stats['loc']:,} |")

    # Dead code section
    lines.extend([
        "",
        "---",
        "",
        "## Dead Code Candidates",
        "",
        f"**{s['dead_code_files']} files** with 0 importers and no `__main__` block "
        f"({s['dead_code_loc']:,} LOC).",
        "",
        "| File | LOC | Category | Bio | Classes | Functions |",
        "|------|-----|----------|-----|---------|-----------|",
    ])

    for dc in results["dead_code"][:50]:
        lines.append(
            f"| `{dc['path']}` | {dc['loc']} | {dc['category']} | "
            f"{dc['bio_subsystem']} | {dc['class_count']} | {dc['function_count']} |"
        )

    if len(results["dead_code"]) > 50:
        lines.append("| ... | | | | | |")
        lines.append(f"| *+{len(results['dead_code']) - 50} more* | | | | | |")

    # Top imported
    lines.extend([
        "",
        "---",
        "",
        "## Most-Imported Files (Hub Nodes)",
        "",
        "These are the most critical files — breaking changes here affect the most code.",
        "",
        "| File | Imported By |",
        "|------|-------------|",
    ])

    for item in results["top_imported"]:
        lines.append(f"| `{item['path']}` | {item['imported_by']} |")

    # Top importers
    lines.extend([
        "",
        "---",
        "",
        "## Most Dependencies (Complex Files)",
        "",
        "| File | Dependencies |",
        "|------|-------------|",
    ])

    for item in results["top_importers"]:
        lines.append(f"| `{item['path']}` | {item['imports']} |")

    # Largest files
    lines.extend([
        "",
        "---",
        "",
        "## Largest Files",
        "",
        "| File | LOC |",
        "|------|-----|",
    ])

    for item in results["largest_files"]:
        lines.append(f"| `{item['path']}` | {item['loc']:,} |")

    # Redundancy
    lines.extend([
        "",
        "---",
        "",
        "## High-Redundancy Pairs (≥60% Import Similarity)",
        "",
        f"**{s['redundancy_pairs']} pairs** with ≥60% Jaccard import similarity.",
        "",
        "| File A | File B | Similarity |",
        "|--------|--------|------------|",
    ])

    for pair in results["redundancy_pairs"][:30]:
        lines.append(f"| `{pair['file_a']}` | `{pair['file_b']}` | {pair['similarity']:.1%} |")

    if len(results["redundancy_pairs"]) > 30:
        lines.append(f"| *+{len(results['redundancy_pairs']) - 30} more* | | |")

    # Quality scorecard by category
    lines.extend([
        "",
        "---",
        "",
        "## Quality Scorecard by Category",
        "",
        "| Category | Files | Avg Docstring% | Avg TypeHint% | With Tests |",
        "|----------|-------|----------------|---------------|------------|",
    ])

    cat_quality: dict[str, dict] = defaultdict(lambda: {
        "count": 0, "doc_sum": 0.0, "hint_sum": 0.0, "tested": 0
    })
    for info in files.values():
        q = cat_quality[info.category]
        q["count"] += 1
        q["doc_sum"] += info.docstring_pct
        q["hint_sum"] += info.type_hint_pct
        if info.test_file:
            q["tested"] += 1

    for cat, q in sorted(cat_quality.items(), key=lambda x: x[1]["count"], reverse=True):
        avg_doc = round(q["doc_sum"] / max(q["count"], 1), 1)
        avg_hint = round(q["hint_sum"] / max(q["count"], 1), 1)
        lines.append(f"| {cat} | {q['count']} | {avg_doc}% | {avg_hint}% | {q['tested']} |")

    # Polyglot breakdown
    polyglot = results.get("polyglot", {})
    if polyglot:
        lines.extend([
            "",
            "---",
            "",
            "## Polyglot Breakdown",
            "",
            "| Language | Files | LOC | % of Grand Total |",
            "|----------|-------|-----|------------------|",
        ])
        grand_loc = s.get("grand_total_loc", s["total_loc"])
        # Add Python first
        py_pct = round(s["total_loc"] / max(grand_loc, 1) * 100, 1)
        lines.append(f"| **Python** | **{s['total_files']}** | **{s['total_loc']:,}** | **{py_pct}%** |")
        for lang_name, lang_stats in sorted(polyglot.items(), key=lambda x: x[1]["loc"], reverse=True):
            pct = round(lang_stats["loc"] / max(grand_loc, 1) * 100, 1)
            lines.append(f"| {lang_name} | {lang_stats['files']} | {lang_stats['loc']:,} | {pct}% |")

    # Recommendations
    lines.extend([
        "",
        "---",
        "",
        "## Recommendations",
        "",
        "### Immediate Actions (V002 Python Reduction Input)",
        "",
        f"1. **Review {s['dead_code_files']} dead code files** — "
        f"{s['dead_code_loc']:,} LOC potentially removable",
        f"2. **Review {s['redundancy_pairs']} redundancy pairs** — "
        f"merge candidates for LOC reduction",
        f"3. **Improve test coverage** — only {s['test_coverage_pct']}% of files have tests",
        f"4. **Improve docstrings** — average {s['avg_docstring_pct']}% coverage",
        f"5. **Improve type hints** — average {s['avg_type_hint_pct']}% coverage",
        "",
        "### V005 Nervous System Input",
        "",
    ])

    for sub, stats in bio_sorted:
        if sub != "none":
            lines.append(f"- **{sub}**: {stats['files']} files, {stats['loc']:,} LOC")

    lines.extend([
        "",
        "### V006 Rust Hot Path Input",
        "",
        "See `reports/import_graph.json` for the full dependency graph. "
        "Hub nodes (most-imported files) are the highest-value Rust acceleration targets.",
        "",
        "---",
        "",
        "*Generated by V001: The Great Codebase Census*",
    ])

    return "\n".join(lines) + "\n"


if __name__ == "__main__":
    run_census()
