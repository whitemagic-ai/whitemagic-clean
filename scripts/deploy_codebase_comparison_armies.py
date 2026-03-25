#!/usr/bin/env python3
"""
CODEBASE COMPARISON SHADOW CLONE ARMIES
========================================
Deploy reconnaissance armies to compare whitemagicdev, whitemagicpublic, and WM2
"""

import ast
import json
from pathlib import Path
from collections import defaultdict
from datetime import datetime, timezone

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"
PUBLIC_ROOT = Path.home() / "Desktop" / "whitemagicpublic"

print("=" * 80)
print("DEPLOYING CODEBASE COMPARISON ARMIES")
print("=" * 80)
print()

def count_loc(directory: Path, pattern: str = "*.py") -> int:
    """Count lines of code."""
    total = 0
    for file in directory.rglob(pattern):
        try:
            total += len(file.read_text(encoding='utf-8').splitlines())
        except Exception:
            pass
    return total

def count_files(directory: Path, pattern: str = "*.py") -> int:
    """Count files."""
    return len(list(directory.rglob(pattern)))

def extract_classes(directory: Path) -> dict:
    """Extract all class definitions."""
    classes = defaultdict(list)
    
    for py_file in directory.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.ClassDef):
                    classes[node.name].append(str(py_file.relative_to(directory)))
        except Exception:
            continue
    
    return dict(classes)

def extract_functions(directory: Path) -> dict:
    """Extract all function definitions."""
    functions = defaultdict(list)
    
    for py_file in directory.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.FunctionDef):
                    if not node.name.startswith('_'):  # Skip private functions
                        functions[node.name].append(str(py_file.relative_to(directory)))
        except Exception:
            continue
    
    return dict(functions)

def extract_imports(directory: Path) -> dict:
    """Extract all import statements."""
    imports = defaultdict(int)
    
    for py_file in directory.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.Import):
                    for alias in node.names:
                        imports[alias.name] += 1
                elif isinstance(node, ast.ImportFrom):
                    if node.module:
                        imports[node.module] += 1
        except Exception:
            continue
    
    return dict(imports)

def analyze_codebase(name: str, directory: Path) -> dict:
    """Comprehensive codebase analysis."""
    print(f"🔍 Analyzing {name}...")
    
    if not directory.exists():
        print(f"   ⚠️  Directory not found: {directory}")
        return {"exists": False}
    
    whitemagic_dir = directory / "whitemagic" if (directory / "whitemagic").exists() else directory
    
    analysis = {
        "exists": True,
        "path": str(directory),
        "metrics": {
            "python_files": count_files(whitemagic_dir, "*.py"),
            "python_loc": count_loc(whitemagic_dir, "*.py"),
            "rust_files": count_files(directory, "*.rs"),
            "rust_loc": count_loc(directory, "*.rs"),
            "mojo_files": count_files(directory, "*.mojo"),
            "mojo_loc": count_loc(directory, "*.mojo"),
        },
        "classes": extract_classes(whitemagic_dir),
        "functions": extract_functions(whitemagic_dir),
        "imports": extract_imports(whitemagic_dir),
    }
    
    print(f"   Python: {analysis['metrics']['python_files']} files, {analysis['metrics']['python_loc']:,} LOC")
    print(f"   Rust: {analysis['metrics']['rust_files']} files, {analysis['metrics']['rust_loc']:,} LOC")
    print(f"   Mojo: {analysis['metrics']['mojo_files']} files, {analysis['metrics']['mojo_loc']:,} LOC")
    print(f"   Classes: {len(analysis['classes'])}")
    print(f"   Functions: {len(analysis['functions'])}")
    print()
    
    return analysis

def compare_codebases(dev_analysis: dict, public_analysis: dict, wm2_analysis: dict) -> dict:
    """Compare three codebases."""
    print("📊 Comparing codebases...")
    print()
    
    comparison = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "codebases": {
            "whitemagicdev": dev_analysis,
            "whitemagicpublic": public_analysis,
            "WM2": wm2_analysis,
        },
        "differences": {},
    }
    
    # Compare classes
    dev_classes = set(dev_analysis.get("classes", {}).keys())
    public_classes = set(public_analysis.get("classes", {}).keys())
    wm2_classes = set(wm2_analysis.get("classes", {}).keys())
    
    comparison["differences"]["classes"] = {
        "dev_only": list(dev_classes - public_classes - wm2_classes),
        "public_only": list(public_classes - dev_classes - wm2_classes),
        "wm2_only": list(wm2_classes - dev_classes - public_classes),
        "common_all": list(dev_classes & public_classes & wm2_classes),
        "missing_from_wm2": list((dev_classes | public_classes) - wm2_classes),
    }
    
    # Compare functions
    dev_funcs = set(dev_analysis.get("functions", {}).keys())
    public_funcs = set(public_analysis.get("functions", {}).keys())
    wm2_funcs = set(wm2_analysis.get("functions", {}).keys())
    
    comparison["differences"]["functions"] = {
        "dev_only": list(dev_funcs - public_funcs - wm2_funcs)[:50],  # Limit to 50
        "public_only": list(public_funcs - dev_funcs - wm2_funcs)[:50],
        "wm2_only": list(wm2_funcs - dev_funcs - public_funcs)[:50],
        "common_all": list(dev_funcs & public_funcs & wm2_funcs)[:50],
        "missing_from_wm2": list((dev_funcs | public_funcs) - wm2_funcs)[:100],
    }
    
    # LOC comparison
    comparison["differences"]["loc"] = {
        "dev_python": dev_analysis.get("metrics", {}).get("python_loc", 0),
        "public_python": public_analysis.get("metrics", {}).get("python_loc", 0),
        "wm2_python": wm2_analysis.get("metrics", {}).get("python_loc", 0),
        "wm2_rust": wm2_analysis.get("metrics", {}).get("rust_loc", 0),
        "wm2_mojo": wm2_analysis.get("metrics", {}).get("mojo_loc", 0),
    }
    
    return comparison

def main():
    # Analyze all three codebases
    dev_analysis = analyze_codebase("whitemagicdev", PROJECT_ROOT)
    public_analysis = analyze_codebase("whitemagicpublic", PUBLIC_ROOT)
    wm2_analysis = analyze_codebase("WM2", WM2_ROOT)
    
    # Compare
    comparison = compare_codebases(dev_analysis, public_analysis, wm2_analysis)
    
    # Save results
    results_path = PROJECT_ROOT / "reports" / "codebase_comparison.json"
    results_path.write_text(json.dumps(comparison, indent=2))
    
    # Summary
    print("=" * 80)
    print("COMPARISON SUMMARY")
    print("=" * 80)
    print()
    
    print("Classes missing from WM2:")
    missing_classes = comparison["differences"]["classes"]["missing_from_wm2"]
    print(f"   Total: {len(missing_classes)}")
    if missing_classes:
        print(f"   Examples: {', '.join(missing_classes[:10])}")
    print()
    
    print("Functions missing from WM2:")
    missing_funcs = comparison["differences"]["functions"]["missing_from_wm2"]
    print(f"   Total: {len(missing_funcs)}")
    if missing_funcs:
        print(f"   Examples: {', '.join(missing_funcs[:10])}")
    print()
    
    print("LOC Comparison:")
    loc = comparison["differences"]["loc"]
    print(f"   whitemagicdev: {loc['dev_python']:,} Python LOC")
    print(f"   whitemagicpublic: {loc['public_python']:,} Python LOC")
    print(f"   WM2: {loc['wm2_python']:,} Python + {loc['wm2_rust']:,} Rust + {loc['wm2_mojo']:,} Mojo LOC")
    print()
    
    print(f"📄 Full report: {results_path}")
    print()
    print("✅ Codebase comparison complete!")

if __name__ == "__main__":
    main()
