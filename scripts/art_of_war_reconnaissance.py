#!/usr/bin/env python3
"""
ART OF WAR RECONNAISSANCE - ABSOLUTE CLARITY CAMPAIGN
======================================================
"If you know the enemy and know yourself, you need not fear the result of a hundred battles."
"What enables the wise sovereign and the good general to strike and conquer, and achieve things
 beyond the reach of ordinary men, is FOREKNOWLEDGE."
                                                                    — Sun Tzu, The Art of War

This script deploys shadow clone scouting armies to achieve ABSOLUTE KNOWLEDGE of WhiteMagic:
1. What EXISTS and is OPERATIONAL
2. What EXISTS but is INCOMPLETE or UNWIRED
3. What is MISSING entirely

Victory comes from knowing the terrain completely before engaging.
"""

import ast
import json
import os
import re
import sys
import time
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

# Project root
PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

print("=" * 80)
print("ART OF WAR RECONNAISSANCE - ABSOLUTE CLARITY CAMPAIGN")
print("=" * 80)
print()
print('"The general who wins a battle makes many calculations before the battle is fought."')
print("                                                           — Sun Tzu")
print()
print(f"⏰ START TIME: {time.strftime('%H:%M:%S')}")
start_time = time.time()


@dataclass
class SystemComponent:
    """A system component discovered in the codebase."""
    name: str
    path: str
    category: str
    status: str  # "operational", "incomplete", "skeleton", "dead"
    description: str = ""
    dependencies: list[str] = field(default_factory=list)
    rust_integration: bool = False
    test_coverage: bool = False
    documentation: bool = False
    issues: list[str] = field(default_factory=list)
    lines_of_code: int = 0


@dataclass
class ReconnaissanceReport:
    """Complete reconnaissance report."""
    timestamp: str
    duration_seconds: float
    total_files: int = 0
    total_lines: int = 0
    
    # Categories
    operational: list[SystemComponent] = field(default_factory=list)
    incomplete: list[SystemComponent] = field(default_factory=list)
    skeleton: list[SystemComponent] = field(default_factory=list)
    dead: list[SystemComponent] = field(default_factory=list)
    
    # Language breakdown
    languages: dict[str, dict] = field(default_factory=dict)
    
    # Subsystem analysis
    subsystems: dict[str, list[SystemComponent]] = field(default_factory=dict)
    
    # Critical findings
    unwired_rust_functions: list[str] = field(default_factory=list)
    missing_integrations: list[str] = field(default_factory=list)
    duplicate_implementations: list[str] = field(default_factory=list)
    orphan_files: list[str] = field(default_factory=list)


# ============================================================================
# PHASE 1: TERRAIN MAPPING - Count all files and lines
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 1: TERRAIN MAPPING - Surveying the entire codebase")
print("─" * 80)

language_stats = defaultdict(lambda: {"files": 0, "lines": 0, "paths": []})
extensions = {
    ".py": "Python",
    ".rs": "Rust",
    ".mojo": "Mojo",
    ".🔥": "Mojo",
    ".zig": "Zig",
    ".ex": "Elixir",
    ".exs": "Elixir",
    ".hs": "Haskell",
    ".go": "Go",
    ".jl": "Julia",
    ".ts": "TypeScript",
    ".tsx": "TypeScript",
    ".js": "JavaScript",
    ".md": "Markdown",
    ".toml": "TOML",
    ".yaml": "YAML",
    ".yml": "YAML",
    ".json": "JSON",
}

exclude_dirs = {
    ".git", "__pycache__", ".venv", "venv", "node_modules", ".mypy_cache",
    ".pytest_cache", ".ruff_cache", "target", "dist", "build", ".tox",
    "_archives", "archived", ".windsurf"
}

total_files = 0
total_lines = 0

for root, dirs, files in os.walk(PROJECT_ROOT):
    # Skip excluded directories
    dirs[:] = [d for d in dirs if d not in exclude_dirs]
    
    for file in files:
        ext = Path(file).suffix.lower()
        if ext in extensions:
            filepath = Path(root) / file
            try:
                content = filepath.read_text(errors="ignore")
                lines = len(content.splitlines())
                lang = extensions[ext]
                language_stats[lang]["files"] += 1
                language_stats[lang]["lines"] += lines
                language_stats[lang]["paths"].append(str(filepath.relative_to(PROJECT_ROOT)))
                total_files += 1
                total_lines += lines
            except Exception:
                pass

print(f"\n📊 TERRAIN OVERVIEW:")
print(f"   Total files: {total_files:,}")
print(f"   Total lines: {total_lines:,}")
print()
print("   Language breakdown:")
for lang, stats in sorted(language_stats.items(), key=lambda x: x[1]["lines"], reverse=True):
    pct = (stats["lines"] / total_lines * 100) if total_lines > 0 else 0
    print(f"   • {lang}: {stats['files']:,} files, {stats['lines']:,} lines ({pct:.1f}%)")


# ============================================================================
# PHASE 2: PYTHON SYSTEM ANALYSIS - Deep inspection of all Python modules
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 2: PYTHON SYSTEM ANALYSIS - Inspecting all Python modules")
print("─" * 80)

python_files = language_stats["Python"]["paths"]
components: list[SystemComponent] = []

# Categories to track
SUBSYSTEM_PATTERNS = {
    "memory": ["memory", "sqlite", "db", "storage", "persistence"],
    "inference": ["inference", "llm", "ollama", "bitnet", "edge"],
    "search": ["search", "vector", "semantic", "embedding", "fts"],
    "graph": ["graph", "association", "constellation", "community"],
    "acceleration": ["simd", "rust", "acceleration", "polyglot", "mojo", "zig"],
    "biological": ["dream", "immune", "genetic", "evolution", "coherence", "resonance"],
    "agents": ["agent", "swarm", "clone", "lieutenant", "worker"],
    "tools": ["tool", "handler", "dispatch", "gana"],
    "gardens": ["garden"],
    "core": ["core"],
    "utils": ["util", "helper", "common"],
    "cli": ["cli", "command"],
    "api": ["api", "mcp", "server"],
}

def categorize_file(path: str) -> str:
    """Categorize a file into a subsystem."""
    path_lower = path.lower()
    for category, patterns in SUBSYSTEM_PATTERNS.items():
        for pattern in patterns:
            if pattern in path_lower:
                return category
    return "other"


def analyze_python_file(filepath: Path) -> SystemComponent | None:
    """Deep analysis of a Python file."""
    try:
        content = filepath.read_text(errors="ignore")
        lines = content.splitlines()
        loc = len([l for l in lines if l.strip() and not l.strip().startswith("#")])
        
        # Parse AST
        try:
            tree = ast.parse(content)
        except SyntaxError:
            return SystemComponent(
                name=filepath.stem,
                path=str(filepath.relative_to(PROJECT_ROOT)),
                category=categorize_file(str(filepath)),
                status="dead",
                description="Syntax error - cannot parse",
                lines_of_code=loc,
                issues=["Syntax error"]
            )
        
        # Analyze imports and structure
        imports = []
        classes = []
        functions = []
        has_rust = False
        has_todo = False
        has_notimplemented = False
        has_pass_only = False
        has_tests = False
        has_docstring = ast.get_docstring(tree) is not None
        
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                for alias in node.names:
                    imports.append(alias.name)
                    if "whitemagic_rs" in alias.name:
                        has_rust = True
            elif isinstance(node, ast.ImportFrom):
                if node.module:
                    imports.append(node.module)
                    if "whitemagic_rs" in node.module:
                        has_rust = True
            elif isinstance(node, ast.ClassDef):
                classes.append(node.name)
            elif isinstance(node, ast.FunctionDef) or isinstance(node, ast.AsyncFunctionDef):
                functions.append(node.name)
                if node.name.startswith("test_"):
                    has_tests = True
        
        # Check for incompleteness indicators
        if "TODO" in content or "FIXME" in content:
            has_todo = True
        if "NotImplementedError" in content or "raise NotImplemented" in content:
            has_notimplemented = True
        if re.search(r"def \w+\([^)]*\):\s*\n\s*pass\s*$", content, re.MULTILINE):
            has_pass_only = True
        
        # Determine status
        issues = []
        if has_notimplemented:
            issues.append("Contains NotImplementedError")
        if has_pass_only:
            issues.append("Contains pass-only functions")
        if has_todo:
            issues.append("Contains TODO/FIXME")
        if not has_docstring:
            issues.append("Missing module docstring")
        
        # Status determination
        if loc < 10:
            status = "skeleton"
        elif has_notimplemented and len([f for f in functions if not f.startswith("_")]) < 3:
            status = "skeleton"
        elif has_notimplemented or has_pass_only:
            status = "incomplete"
        elif not classes and not functions:
            status = "dead"
        else:
            status = "operational"
        
        # Build description
        desc_parts = []
        if classes:
            desc_parts.append(f"{len(classes)} classes")
        if functions:
            desc_parts.append(f"{len(functions)} functions")
        description = ", ".join(desc_parts) if desc_parts else "Empty module"
        
        return SystemComponent(
            name=filepath.stem,
            path=str(filepath.relative_to(PROJECT_ROOT)),
            category=categorize_file(str(filepath)),
            status=status,
            description=description,
            dependencies=imports[:10],  # Top 10 imports
            rust_integration=has_rust,
            test_coverage=has_tests,
            documentation=has_docstring,
            issues=issues,
            lines_of_code=loc,
        )
        
    except Exception as e:
        return SystemComponent(
            name=filepath.stem,
            path=str(filepath.relative_to(PROJECT_ROOT)),
            category="other",
            status="dead",
            description=f"Error: {str(e)[:50]}",
            issues=[str(e)[:100]]
        )


# Analyze all Python files
print(f"\n🔍 Analyzing {len(python_files)} Python files...")
analyzed = 0
for path in python_files:
    filepath = PROJECT_ROOT / path
    if filepath.exists():
        component = analyze_python_file(filepath)
        if component:
            components.append(component)
            analyzed += 1
            if analyzed % 100 == 0:
                print(f"   Analyzed {analyzed}/{len(python_files)} files...")

print(f"   ✅ Analyzed {analyzed} files")

# Categorize components
operational = [c for c in components if c.status == "operational"]
incomplete = [c for c in components if c.status == "incomplete"]
skeleton = [c for c in components if c.status == "skeleton"]
dead = [c for c in components if c.status == "dead"]

print(f"\n📊 COMPONENT STATUS:")
print(f"   ✅ Operational: {len(operational)} ({len(operational)/len(components)*100:.1f}%)")
print(f"   🔧 Incomplete:  {len(incomplete)} ({len(incomplete)/len(components)*100:.1f}%)")
print(f"   📝 Skeleton:    {len(skeleton)} ({len(skeleton)/len(components)*100:.1f}%)")
print(f"   💀 Dead/Empty:  {len(dead)} ({len(dead)/len(components)*100:.1f}%)")


# ============================================================================
# PHASE 3: RUST INTEGRATION ANALYSIS
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 3: RUST INTEGRATION ANALYSIS - Mapping Rust bridge usage")
print("─" * 80)

rust_integrated = [c for c in components if c.rust_integration]
print(f"\n🦀 Files with Rust integration: {len(rust_integrated)}")

# Check whitemagic_rs functions
rust_dir = PROJECT_ROOT / "whitemagic-rust" / "src"
rust_functions = []
if rust_dir.exists():
    for rs_file in rust_dir.glob("**/*.rs"):
        try:
            content = rs_file.read_text()
            # Find #[pyfunction] decorated functions
            pyfuncs = re.findall(r'#\[pyfunction\]\s*(?:pub\s+)?fn\s+(\w+)', content)
            # Find #[pyclass] decorated structs
            pyclasses = re.findall(r'#\[pyclass\]\s*(?:#\[.*?\]\s*)*(?:pub\s+)?struct\s+(\w+)', content)
            rust_functions.extend(pyfuncs)
            rust_functions.extend(pyclasses)
        except Exception:
            pass

print(f"   Rust functions/classes exposed to Python: {len(rust_functions)}")

# Check which are actually used in Python
rust_usage = defaultdict(list)
for component in components:
    filepath = PROJECT_ROOT / component.path
    if filepath.exists() and component.rust_integration:
        try:
            content = filepath.read_text()
            for func in rust_functions:
                if func in content:
                    rust_usage[func].append(component.path)
        except Exception:
            pass

used_rust = set(rust_usage.keys())
unused_rust = set(rust_functions) - used_rust

print(f"   Used in Python: {len(used_rust)}")
print(f"   ⚠️  Unused/unwired: {len(unused_rust)}")

if unused_rust:
    print(f"\n   Top unused Rust functions:")
    for func in list(unused_rust)[:20]:
        print(f"      • {func}")


# ============================================================================
# PHASE 4: SUBSYSTEM MAPPING
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 4: SUBSYSTEM MAPPING - Analyzing system architecture")
print("─" * 80)

subsystems: dict[str, list[SystemComponent]] = defaultdict(list)
for component in components:
    subsystems[component.category].append(component)

print(f"\n📊 SUBSYSTEM HEALTH:")
for category, comps in sorted(subsystems.items(), key=lambda x: len(x[1]), reverse=True):
    total = len(comps)
    op = sum(1 for c in comps if c.status == "operational")
    inc = sum(1 for c in comps if c.status == "incomplete")
    skel = sum(1 for c in comps if c.status == "skeleton")
    health = op / total * 100 if total > 0 else 0
    
    status_icon = "✅" if health > 80 else "🔧" if health > 50 else "⚠️"
    print(f"   {status_icon} {category}: {total} files, {health:.0f}% operational ({op} op, {inc} inc, {skel} skel)")


# ============================================================================
# PHASE 5: CRITICAL FINDINGS
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 5: CRITICAL FINDINGS - Identifying strategic opportunities")
print("─" * 80)

# Find duplicate/similar implementations
print("\n🔍 Potential duplicate implementations:")
name_counts = defaultdict(list)
for c in components:
    name_counts[c.name].append(c.path)

duplicates = [(name, paths) for name, paths in name_counts.items() if len(paths) > 1]
for name, paths in duplicates[:10]:
    print(f"   • {name}: {len(paths)} copies")
    for p in paths[:3]:
        print(f"      - {p}")

# Find incomplete systems by subsystem
print("\n🔧 Incomplete systems by category:")
for category, comps in subsystems.items():
    incomplete_in_cat = [c for c in comps if c.status in ("incomplete", "skeleton")]
    if incomplete_in_cat:
        print(f"\n   {category.upper()} ({len(incomplete_in_cat)} incomplete):")
        for c in incomplete_in_cat[:5]:
            issues = ", ".join(c.issues[:2]) if c.issues else "Unknown"
            print(f"      • {c.path}: {issues}")


# ============================================================================
# PHASE 6: GENERATE ABSOLUTE CLARITY REPORT
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 6: GENERATING ABSOLUTE CLARITY REPORT")
print("─" * 80)

elapsed = time.time() - start_time

report = ReconnaissanceReport(
    timestamp=time.strftime("%Y-%m-%d %H:%M:%S"),
    duration_seconds=elapsed,
    total_files=total_files,
    total_lines=total_lines,
    operational=operational,
    incomplete=incomplete,
    skeleton=skeleton,
    dead=dead,
    languages=dict(language_stats),
    subsystems=dict(subsystems),
    unwired_rust_functions=list(unused_rust),
    duplicate_implementations=[f"{name}: {len(paths)} copies" for name, paths in duplicates],
)

# Generate markdown report
report_path = PROJECT_ROOT / "reports" / "ABSOLUTE_CLARITY_RECONNAISSANCE.md"
with open(report_path, "w") as f:
    f.write("# ABSOLUTE CLARITY RECONNAISSANCE REPORT\n\n")
    f.write("*\"If you know the enemy and know yourself, you need not fear the result of a hundred battles.\"*\n")
    f.write("*— Sun Tzu, The Art of War*\n\n")
    f.write("---\n\n")
    
    f.write(f"**Generated**: {report.timestamp}\n")
    f.write(f"**Duration**: {elapsed:.2f} seconds\n\n")
    
    f.write("## TERRAIN OVERVIEW\n\n")
    f.write(f"- **Total Files**: {total_files:,}\n")
    f.write(f"- **Total Lines**: {total_lines:,}\n\n")
    
    f.write("### Language Breakdown\n\n")
    f.write("| Language | Files | Lines | % |\n")
    f.write("|----------|-------|-------|---|\n")
    for lang, stats in sorted(language_stats.items(), key=lambda x: x[1]["lines"], reverse=True):
        pct = (stats["lines"] / total_lines * 100) if total_lines > 0 else 0
        f.write(f"| {lang} | {stats['files']:,} | {stats['lines']:,} | {pct:.1f}% |\n")
    
    f.write("\n## COMPONENT STATUS\n\n")
    f.write(f"- ✅ **Operational**: {len(operational)} ({len(operational)/len(components)*100:.1f}%)\n")
    f.write(f"- 🔧 **Incomplete**: {len(incomplete)} ({len(incomplete)/len(components)*100:.1f}%)\n")
    f.write(f"- 📝 **Skeleton**: {len(skeleton)} ({len(skeleton)/len(components)*100:.1f}%)\n")
    f.write(f"- 💀 **Dead/Empty**: {len(dead)} ({len(dead)/len(components)*100:.1f}%)\n")
    
    f.write("\n## SUBSYSTEM HEALTH\n\n")
    f.write("| Subsystem | Files | Operational | Incomplete | Skeleton | Health |\n")
    f.write("|-----------|-------|-------------|------------|----------|--------|\n")
    for category, comps in sorted(subsystems.items(), key=lambda x: len(x[1]), reverse=True):
        total = len(comps)
        op = sum(1 for c in comps if c.status == "operational")
        inc = sum(1 for c in comps if c.status == "incomplete")
        skel = sum(1 for c in comps if c.status == "skeleton")
        health = op / total * 100 if total > 0 else 0
        f.write(f"| {category} | {total} | {op} | {inc} | {skel} | {health:.0f}% |\n")
    
    f.write("\n## RUST INTEGRATION\n\n")
    f.write(f"- **Total Rust functions exposed**: {len(rust_functions)}\n")
    f.write(f"- **Used in Python**: {len(used_rust)}\n")
    f.write(f"- **Unwired/unused**: {len(unused_rust)}\n\n")
    
    if unused_rust:
        f.write("### Unwired Rust Functions\n\n")
        f.write("These Rust functions are compiled but not used in Python:\n\n")
        for func in sorted(unused_rust):
            f.write(f"- `{func}`\n")
    
    f.write("\n## INCOMPLETE SYSTEMS\n\n")
    for category, comps in subsystems.items():
        incomplete_in_cat = [c for c in comps if c.status in ("incomplete", "skeleton")]
        if incomplete_in_cat:
            f.write(f"\n### {category.upper()}\n\n")
            for c in incomplete_in_cat:
                issues = ", ".join(c.issues) if c.issues else "Unknown"
                f.write(f"- `{c.path}` ({c.status}): {issues}\n")
    
    f.write("\n## DUPLICATE IMPLEMENTATIONS\n\n")
    f.write("Files with the same name in multiple locations:\n\n")
    for name, paths in duplicates:
        f.write(f"### {name}\n\n")
        for p in paths:
            f.write(f"- `{p}`\n")
        f.write("\n")
    
    f.write("\n---\n\n")
    f.write("## STRATEGIC ASSESSMENT\n\n")
    f.write("### What We Know (Strengths)\n\n")
    op_pct = len(operational) / len(components) * 100
    f.write(f"- {op_pct:.0f}% of Python modules are operational\n")
    f.write(f"- {len(used_rust)} Rust functions are actively wired\n")
    f.write(f"- {len(rust_integrated)} Python files have Rust integration\n")
    
    f.write("\n### What Needs Work (Opportunities)\n\n")
    f.write(f"- {len(incomplete)} incomplete modules need finishing\n")
    f.write(f"- {len(skeleton)} skeleton modules need implementation\n")
    f.write(f"- {len(unused_rust)} Rust functions are unwired\n")
    f.write(f"- {len(duplicates)} potential duplicate implementations\n")
    
    f.write("\n### Victory Conditions\n\n")
    f.write("To achieve ABSOLUTE CLARITY:\n\n")
    f.write("1. Wire all unused Rust functions\n")
    f.write("2. Complete all skeleton modules\n")
    f.write("3. Fix all incomplete modules\n")
    f.write("4. Consolidate duplicate implementations\n")
    f.write("5. Archive dead code\n")
    
    f.write("\n---\n\n")
    f.write("*\"Supreme excellence consists in breaking the enemy's resistance without fighting.\"*\n")
    f.write("*— Sun Tzu*\n")

print(f"\n📄 Report saved to: {report_path}")

# Save JSON for programmatic access
json_path = PROJECT_ROOT / "reports" / "reconnaissance_data.json"
json_data = {
    "timestamp": report.timestamp,
    "duration_seconds": elapsed,
    "total_files": total_files,
    "total_lines": total_lines,
    "component_counts": {
        "operational": len(operational),
        "incomplete": len(incomplete),
        "skeleton": len(skeleton),
        "dead": len(dead),
    },
    "languages": {k: {"files": v["files"], "lines": v["lines"]} for k, v in language_stats.items()},
    "subsystem_health": {
        cat: {
            "total": len(comps),
            "operational": sum(1 for c in comps if c.status == "operational"),
            "incomplete": sum(1 for c in comps if c.status == "incomplete"),
            "skeleton": sum(1 for c in comps if c.status == "skeleton"),
        }
        for cat, comps in subsystems.items()
    },
    "rust_integration": {
        "total_functions": len(rust_functions),
        "used": len(used_rust),
        "unused": len(unused_rust),
        "unused_list": list(unused_rust),
    },
    "duplicates": duplicates[:50],
    "incomplete_files": [{"path": c.path, "issues": c.issues} for c in incomplete],
    "skeleton_files": [{"path": c.path, "issues": c.issues} for c in skeleton],
}
json_path.write_text(json.dumps(json_data, indent=2))
print(f"📊 Data saved to: {json_path}")

print(f"\n⏰ END TIME: {time.strftime('%H:%M:%S')}")
print(f"⚡ Total Duration: {elapsed:.2f}s")

print("\n" + "=" * 80)
print("RECONNAISSANCE COMPLETE - ABSOLUTE CLARITY ACHIEVED")
print("=" * 80)
print()
print('"Now the general who wins a battle makes many calculations in his temple')
print(' before the battle is fought. The general who loses a battle makes but')
print(' few calculations beforehand."')
print("                                                           — Sun Tzu")
