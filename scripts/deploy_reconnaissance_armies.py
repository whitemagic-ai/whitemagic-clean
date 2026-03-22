#!/usr/bin/env python3
"""
RECONNAISSANCE SHADOW CLONE ARMIES
===================================
Deploy multiple scouting armies to map remaining opportunities
"""

import ast
import json
import re
import sys
from collections import defaultdict
from datetime import UTC, datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

print("=" * 80)
print("DEPLOYING RECONNAISSANCE SHADOW CLONE ARMIES")
print("=" * 80)
print()

# ============================================================================
# ARMY 1: MODULE COMPLEXITY SCOUT
# ============================================================================

def scout_module_complexity():
    """Scout for complex modules that could be simplified."""
    print("🔍 ARMY 1: Module Complexity Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"
    complex_modules = []

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        try:
            content = py_file.read_text(encoding='utf-8')
            lines = content.splitlines()

            # Parse AST
            tree = ast.parse(content)

            # Count complexity indicators
            classes = [n for n in ast.walk(tree) if isinstance(n, ast.ClassDef)]
            functions = [n for n in ast.walk(tree) if isinstance(n, ast.FunctionDef)]
            imports = [n for n in ast.walk(tree) if isinstance(n, (ast.Import, ast.ImportFrom))]

            # Calculate complexity score
            complexity = len(classes) * 10 + len(functions) * 2 + len(lines) * 0.1

            if complexity > 100:  # High complexity threshold
                complex_modules.append({
                    "path": str(py_file.relative_to(PROJECT_ROOT)),
                    "lines": len(lines),
                    "classes": len(classes),
                    "functions": len(functions),
                    "imports": len(imports),
                    "complexity": round(complexity, 1),
                })
        except Exception:
            continue

    # Sort by complexity
    complex_modules.sort(key=lambda x: x["complexity"], reverse=True)

    print(f"   Found {len(complex_modules)} high-complexity modules")
    print()
    print("   Top 10 complexity targets:")
    for i, mod in enumerate(complex_modules[:10], 1):
        print(f"   {i:2}. {mod['path']}")
        print(f"       Lines: {mod['lines']:,} | Classes: {mod['classes']} | Functions: {mod['functions']} | Score: {mod['complexity']}")

    print()
    return complex_modules

# ============================================================================
# ARMY 2: PATTERN DUPLICATION SCOUT
# ============================================================================

def scout_pattern_duplication():
    """Scout for duplicate patterns that could be unified."""
    print("🔍 ARMY 2: Pattern Duplication Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"
    patterns = defaultdict(list)

    # Common patterns to look for
    pattern_signatures = {
        "manager_pattern": r"class\s+\w+Manager",
        "engine_pattern": r"class\s+\w+Engine",
        "handler_pattern": r"class\s+\w+Handler",
        "get_stats": r"def\s+get_stats\s*\(",
        "to_dict": r"def\s+to_dict\s*\(",
        "from_dict": r"def\s+from_dict\s*\(",
        "initialize": r"def\s+initialize\s*\(",
        "cleanup": r"def\s+cleanup\s*\(",
    }

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        try:
            content = py_file.read_text(encoding='utf-8')

            for pattern_name, pattern_regex in pattern_signatures.items():
                matches = re.findall(pattern_regex, content)
                if matches:
                    patterns[pattern_name].append({
                        "file": str(py_file.relative_to(PROJECT_ROOT)),
                        "count": len(matches),
                    })
        except Exception:
            continue

    print("   Pattern duplication analysis:")
    for pattern_name, occurrences in sorted(patterns.items(), key=lambda x: len(x[1]), reverse=True):
        total_count = sum(o["count"] for o in occurrences)
        print(f"   {pattern_name}: {len(occurrences)} files, {total_count} occurrences")

    print()
    return dict(patterns)

# ============================================================================
# ARMY 3: BIOLOGICAL SUBSYSTEM SCOUT
# ============================================================================

def scout_biological_subsystems():
    """Scout biological subsystems for integration opportunities."""
    print("🔍 ARMY 3: Biological Subsystem Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"

    # Biological keywords
    bio_keywords = {
        "immune": ["immune", "antibod", "pathogen", "threat", "defense"],
        "evolution": ["evolv", "mutat", "select", "phylo", "genetic"],
        "dream": ["dream", "sleep", "consolidat", "rem"],
        "metabolism": ["metabol", "decay", "lifecycle", "retention"],
        "consciousness": ["conscious", "aware", "coherence", "embodiment"],
        "resonance": ["resonan", "harmony", "vibrat", "frequency"],
        "emergence": ["emerg", "serendip", "novelty", "ecology"],
    }

    subsystem_files = defaultdict(list)

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        try:
            content = py_file.read_text(encoding='utf-8').lower()

            for subsystem, keywords in bio_keywords.items():
                if any(kw in content for kw in keywords):
                    subsystem_files[subsystem].append(str(py_file.relative_to(PROJECT_ROOT)))
        except Exception:
            continue

    print("   Biological subsystem distribution:")
    for subsystem, files in sorted(subsystem_files.items(), key=lambda x: len(x[1]), reverse=True):
        print(f"   {subsystem}: {len(files)} files")

    print()
    return dict(subsystem_files)

# ============================================================================
# ARMY 4: POLYGLOT ACCELERATION SCOUT
# ============================================================================

def scout_polyglot_candidates():
    """Scout for hot paths that could benefit from Rust/Mojo."""
    print("🔍 ARMY 4: Polyglot Acceleration Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"

    # Hot path indicators
    hot_indicators = {
        "vector_ops": [r"cosine", r"dot_product", r"normalize", r"embedding"],
        "search_ops": [r"search", r"query", r"index", r"rank"],
        "ml_ops": [r"predict", r"infer", r"train", r"model"],
        "compression": [r"compress", r"encode", r"serialize", r"pickle"],
        "crypto": [r"hash", r"encrypt", r"sign", r"verify"],
    }

    candidates = defaultdict(list)

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        try:
            content = py_file.read_text(encoding='utf-8').lower()
            tree = ast.parse(py_file.read_text(encoding='utf-8'))

            # Look for loops (performance-critical)
            has_loops = any(isinstance(n, (ast.For, ast.While)) for n in ast.walk(tree))

            for category, patterns in hot_indicators.items():
                if any(re.search(p, content) for p in patterns):
                    if has_loops:  # Extra points for loops
                        candidates[category].append({
                            "file": str(py_file.relative_to(PROJECT_ROOT)),
                            "has_loops": True,
                        })
        except Exception:
            continue

    print("   Polyglot acceleration candidates:")
    for category, files in sorted(candidates.items(), key=lambda x: len(x[1]), reverse=True):
        loop_count = sum(1 for f in files if f.get("has_loops"))
        print(f"   {category}: {len(files)} files ({loop_count} with loops)")

    print()
    return dict(candidates)

# ============================================================================
# ARMY 5: WM2 MIGRATION SCOUT
# ============================================================================

def scout_wm2_migration_targets():
    """Scout for modules ready for WM2 migration."""
    print("🔍 ARMY 5: WM2 Migration Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"

    # WM2 base class candidates
    base_class_patterns = {
        "BaseEngine": [r"class\s+\w+Engine", r"def\s+process", r"def\s+execute"],
        "BaseManager": [r"class\s+\w+Manager", r"def\s+get_\w+", r"def\s+set_\w+"],
        "BaseHandler": [r"class\s+\w+Handler", r"def\s+handle", r"def\s+dispatch"],
    }

    migration_targets = defaultdict(list)

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        try:
            content = py_file.read_text(encoding='utf-8')

            for base_class, patterns in base_class_patterns.items():
                matches = sum(1 for p in patterns if re.search(p, content))
                if matches >= 2:  # At least 2 pattern matches
                    migration_targets[base_class].append({
                        "file": str(py_file.relative_to(PROJECT_ROOT)),
                        "pattern_matches": matches,
                    })
        except Exception:
            continue

    print("   WM2 migration targets by base class:")
    for base_class, targets in sorted(migration_targets.items(), key=lambda x: len(x[1]), reverse=True):
        print(f"   {base_class}: {len(targets)} candidates")

    print()
    return dict(migration_targets)

# ============================================================================
# ARMY 6: TECHNICAL DEBT SCOUT
# ============================================================================

def scout_technical_debt():
    """Scout for technical debt markers."""
    print("🔍 ARMY 6: Technical Debt Scout")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"

    debt_markers = {
        "TODO": r"#\s*TODO",
        "FIXME": r"#\s*FIXME",
        "HACK": r"#\s*HACK",
        "XXX": r"#\s*XXX",
        "DEPRECATED": r"#\s*DEPRECATED",
        "NOTE": r"#\s*NOTE",
    }

    debt_counts = defaultdict(int)
    debt_files = defaultdict(list)

    for py_file in whitemagic_dir.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')

            for marker, pattern in debt_markers.items():
                matches = re.findall(pattern, content, re.IGNORECASE)
                if matches:
                    debt_counts[marker] += len(matches)
                    debt_files[marker].append(str(py_file.relative_to(PROJECT_ROOT)))
        except Exception:
            continue

    print("   Technical debt markers:")
    total_debt = sum(debt_counts.values())
    for marker, count in sorted(debt_counts.items(), key=lambda x: x[1], reverse=True):
        print(f"   {marker}: {count} occurrences in {len(debt_files[marker])} files")

    print(f"   Total debt markers: {total_debt}")
    print()
    return {"counts": dict(debt_counts), "files": dict(debt_files)}

# ============================================================================
# MAIN RECONNAISSANCE DEPLOYMENT
# ============================================================================

def main():
    start_time = datetime.now(UTC)

    # Deploy all reconnaissance armies
    results = {
        "timestamp": start_time.isoformat(),
        "armies": {},
    }

    results["armies"]["complexity"] = scout_module_complexity()
    results["armies"]["patterns"] = scout_pattern_duplication()
    results["armies"]["biological"] = scout_biological_subsystems()
    results["armies"]["polyglot"] = scout_polyglot_candidates()
    results["armies"]["wm2_migration"] = scout_wm2_migration_targets()
    results["armies"]["technical_debt"] = scout_technical_debt()

    # Save comprehensive report
    report_path = PROJECT_ROOT / "reports" / "reconnaissance_report.json"
    report_path.write_text(json.dumps(results, indent=2))

    print()
    print("=" * 80)
    print("RECONNAISSANCE COMPLETE")
    print("=" * 80)
    print(f"Report: {report_path}")
    print()

    # Summary
    print("STRATEGIC INTELLIGENCE SUMMARY:")
    print()
    print(f"   High-complexity modules: {len(results['armies']['complexity'])}")
    print(f"   Pattern duplications: {len(results['armies']['patterns'])} types")
    print(f"   Biological subsystems: {len(results['armies']['biological'])} categories")
    print(f"   Polyglot candidates: {sum(len(v) for v in results['armies']['polyglot'].values())} files")
    print(f"   WM2 migration targets: {sum(len(v) for v in results['armies']['wm2_migration'].values())} files")
    print(f"   Technical debt markers: {results['armies']['technical_debt']['counts']}")
    print()

    duration = (datetime.now(UTC) - start_time).total_seconds()
    print(f"Reconnaissance duration: {duration:.1f}s")
    print()
    print("✅ All reconnaissance armies have reported back!")

if __name__ == "__main__":
    main()
