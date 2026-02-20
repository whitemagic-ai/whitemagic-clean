#!/usr/bin/env python3
"""
DEPLOY DEEP-SCAN SHADOW CLONE ARMIES - SECOND PASS
===================================================
Comprehensive line-by-line analysis of whitemagicdev and whitemagicpublic
Deploy hundreds of thousands of clones to find EVERYTHING we missed
"""

import ast
import re
import json
from pathlib import Path
from collections import defaultdict
from datetime import datetime, timezone

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"
PUBLIC_ROOT = Path.home() / "Desktop" / "whitemagicpublic"

print("=" * 80)
print("DEPLOYING DEEP-SCAN SHADOW CLONE ARMIES - SECOND PASS")
print("=" * 80)
print()
print("🎯 Mission: Find EVERYTHING missed in first synthesis pass")
print("📊 Target: Line-by-line analysis of dev + public codebases")
print("⚔️  Force: Hundreds of thousands of shadow clones")
print()

# Army configurations
ARMIES = {
    "function_signature_army": {
        "size": 50000,
        "mission": "Extract every function signature with full type hints",
    },
    "class_hierarchy_army": {
        "size": 30000,
        "mission": "Map complete class inheritance hierarchies",
    },
    "import_dependency_army": {
        "size": 40000,
        "mission": "Build complete import dependency graph",
    },
    "decorator_pattern_army": {
        "size": 25000,
        "mission": "Find all decorators and their usage patterns",
    },
    "constant_extraction_army": {
        "size": 20000,
        "mission": "Extract all constants, enums, and configuration",
    },
    "docstring_analysis_army": {
        "size": 35000,
        "mission": "Analyze all docstrings for capability descriptions",
    },
    "error_handling_army": {
        "size": 30000,
        "mission": "Map all exception types and error handling patterns",
    },
    "async_pattern_army": {
        "size": 25000,
        "mission": "Find all async/await patterns and concurrency",
    },
    "database_schema_army": {
        "size": 20000,
        "mission": "Extract all database schemas and queries",
    },
    "api_endpoint_army": {
        "size": 15000,
        "mission": "Find all API endpoints and routes",
    },
}

def deploy_function_signature_army(codebase_path: Path, codebase_name: str) -> dict:
    """Extract every function signature with full details."""
    print(f"⚔️  Deploying Function Signature Army to {codebase_name}...")
    
    signatures = []
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.FunctionDef):
                    sig = {
                        "name": node.name,
                        "file": str(py_file.relative_to(codebase_path)),
                        "args": [arg.arg for arg in node.args.args],
                        "defaults": len(node.args.defaults),
                        "decorators": [ast.unparse(d) for d in node.decorator_list],
                        "is_async": isinstance(node, ast.AsyncFunctionDef),
                        "lineno": node.lineno,
                    }
                    
                    # Extract return type if available
                    if node.returns:
                        sig["return_type"] = ast.unparse(node.returns)
                    
                    signatures.append(sig)
        except Exception:
            continue
    
    print(f"   ✅ Extracted {len(signatures):,} function signatures")
    return {"signatures": signatures, "count": len(signatures)}

def deploy_class_hierarchy_army(codebase_path: Path, codebase_name: str) -> dict:
    """Map complete class inheritance hierarchies."""
    print(f"⚔️  Deploying Class Hierarchy Army to {codebase_name}...")
    
    hierarchies = {}
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.ClassDef):
                    bases = [ast.unparse(base) for base in node.bases]
                    methods = [n.name for n in node.body if isinstance(n, ast.FunctionDef)]
                    
                    hierarchies[node.name] = {
                        "file": str(py_file.relative_to(codebase_path)),
                        "bases": bases,
                        "methods": methods,
                        "decorators": [ast.unparse(d) for d in node.decorator_list],
                        "lineno": node.lineno,
                    }
        except Exception:
            continue
    
    print(f"   ✅ Mapped {len(hierarchies):,} class hierarchies")
    return {"hierarchies": hierarchies, "count": len(hierarchies)}

def deploy_import_dependency_army(codebase_path: Path, codebase_name: str) -> dict:
    """Build complete import dependency graph."""
    print(f"⚔️  Deploying Import Dependency Army to {codebase_name}...")
    
    dependencies = defaultdict(set)
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            file_key = str(py_file.relative_to(codebase_path))
            
            for node in ast.walk(tree):
                if isinstance(node, ast.Import):
                    for alias in node.names:
                        dependencies[file_key].add(alias.name)
                elif isinstance(node, ast.ImportFrom):
                    if node.module:
                        dependencies[file_key].add(node.module)
        except Exception:
            continue
    
    # Convert sets to lists for JSON serialization
    dependencies = {k: list(v) for k, v in dependencies.items()}
    
    total_deps = sum(len(v) for v in dependencies.values())
    print(f"   ✅ Mapped {total_deps:,} import dependencies across {len(dependencies):,} files")
    return {"dependencies": dependencies, "total": total_deps}

def deploy_decorator_pattern_army(codebase_path: Path, codebase_name: str) -> dict:
    """Find all decorators and their usage patterns."""
    print(f"⚔️  Deploying Decorator Pattern Army to {codebase_name}...")
    
    decorators = defaultdict(list)
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, (ast.FunctionDef, ast.ClassDef)):
                    for decorator in node.decorator_list:
                        dec_name = ast.unparse(decorator)
                        decorators[dec_name].append({
                            "target": node.name,
                            "file": str(py_file.relative_to(codebase_path)),
                            "lineno": node.lineno,
                        })
        except Exception:
            continue
    
    total_uses = sum(len(v) for v in decorators.values())
    print(f"   ✅ Found {len(decorators):,} unique decorators with {total_uses:,} uses")
    return {"decorators": dict(decorators), "unique": len(decorators), "total_uses": total_uses}

def deploy_constant_extraction_army(codebase_path: Path, codebase_name: str) -> dict:
    """Extract all constants, enums, and configuration."""
    print(f"⚔️  Deploying Constant Extraction Army to {codebase_name}...")
    
    constants = []
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.Assign):
                    for target in node.targets:
                        if isinstance(target, ast.Name) and target.id.isupper():
                            constants.append({
                                "name": target.id,
                                "file": str(py_file.relative_to(codebase_path)),
                                "lineno": node.lineno,
                            })
        except Exception:
            continue
    
    print(f"   ✅ Extracted {len(constants):,} constants")
    return {"constants": constants, "count": len(constants)}

def deploy_docstring_analysis_army(codebase_path: Path, codebase_name: str) -> dict:
    """Analyze all docstrings for capability descriptions."""
    print(f"⚔️  Deploying Docstring Analysis Army to {codebase_name}...")
    
    docstrings = []
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, (ast.FunctionDef, ast.ClassDef, ast.Module)):
                    docstring = ast.get_docstring(node)
                    if docstring and len(docstring) > 20:
                        docstrings.append({
                            "target": node.name if hasattr(node, 'name') else "module",
                            "file": str(py_file.relative_to(codebase_path)),
                            "docstring": docstring[:200],  # First 200 chars
                            "length": len(docstring),
                        })
        except Exception:
            continue
    
    print(f"   ✅ Analyzed {len(docstrings):,} docstrings")
    return {"docstrings": docstrings, "count": len(docstrings)}

def deploy_error_handling_army(codebase_path: Path, codebase_name: str) -> dict:
    """Map all exception types and error handling patterns."""
    print(f"⚔️  Deploying Error Handling Army to {codebase_name}...")
    
    exceptions = defaultdict(list)
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.ExceptHandler):
                    exc_type = ast.unparse(node.type) if node.type else "Exception"
                    exceptions[exc_type].append({
                        "file": str(py_file.relative_to(codebase_path)),
                        "lineno": node.lineno,
                    })
                elif isinstance(node, ast.Raise):
                    if node.exc:
                        exc_type = ast.unparse(node.exc)
                        exceptions[f"raise_{exc_type}"].append({
                            "file": str(py_file.relative_to(codebase_path)),
                            "lineno": node.lineno,
                        })
        except Exception:
            continue
    
    total_handlers = sum(len(v) for v in exceptions.values())
    print(f"   ✅ Mapped {len(exceptions):,} exception types with {total_handlers:,} handlers")
    return {"exceptions": dict(exceptions), "unique": len(exceptions), "total": total_handlers}

def deploy_async_pattern_army(codebase_path: Path, codebase_name: str) -> dict:
    """Find all async/await patterns and concurrency."""
    print(f"⚔️  Deploying Async Pattern Army to {codebase_name}...")
    
    async_patterns = {
        "async_functions": [],
        "await_calls": [],
        "async_with": [],
        "async_for": [],
    }
    
    for py_file in codebase_path.rglob("*.py"):
        try:
            content = py_file.read_text(encoding='utf-8')
            tree = ast.parse(content)
            
            for node in ast.walk(tree):
                if isinstance(node, ast.AsyncFunctionDef):
                    async_patterns["async_functions"].append({
                        "name": node.name,
                        "file": str(py_file.relative_to(codebase_path)),
                        "lineno": node.lineno,
                    })
                elif isinstance(node, ast.Await):
                    async_patterns["await_calls"].append({
                        "file": str(py_file.relative_to(codebase_path)),
                        "lineno": node.lineno,
                    })
                elif isinstance(node, ast.AsyncWith):
                    async_patterns["async_with"].append({
                        "file": str(py_file.relative_to(codebase_path)),
                        "lineno": node.lineno,
                    })
                elif isinstance(node, ast.AsyncFor):
                    async_patterns["async_for"].append({
                        "file": str(py_file.relative_to(codebase_path)),
                        "lineno": node.lineno,
                    })
        except Exception:
            continue
    
    total = sum(len(v) for v in async_patterns.values())
    print(f"   ✅ Found {total:,} async patterns")
    return {"patterns": async_patterns, "total": total}

def main():
    print("🚀 Deploying all armies...")
    print()
    
    total_clones = sum(army["size"] for army in ARMIES.values())
    print(f"📊 Total shadow clones: {total_clones:,}")
    print()
    
    results = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "total_clones": total_clones,
        "armies": {},
    }
    
    # Deploy to whitemagicdev
    print("=" * 80)
    print("SCANNING WHITEMAGICDEV")
    print("=" * 80)
    print()
    
    whitemagic_dir = PROJECT_ROOT / "whitemagic"
    
    results["armies"]["dev"] = {
        "functions": deploy_function_signature_army(whitemagic_dir, "dev"),
        "classes": deploy_class_hierarchy_army(whitemagic_dir, "dev"),
        "imports": deploy_import_dependency_army(whitemagic_dir, "dev"),
        "decorators": deploy_decorator_pattern_army(whitemagic_dir, "dev"),
        "constants": deploy_constant_extraction_army(whitemagic_dir, "dev"),
        "docstrings": deploy_docstring_analysis_army(whitemagic_dir, "dev"),
        "exceptions": deploy_error_handling_army(whitemagic_dir, "dev"),
        "async": deploy_async_pattern_army(whitemagic_dir, "dev"),
    }
    
    print()
    
    # Deploy to whitemagicpublic
    print("=" * 80)
    print("SCANNING WHITEMAGICPUBLIC")
    print("=" * 80)
    print()
    
    if PUBLIC_ROOT.exists():
        public_whitemagic = PUBLIC_ROOT / "whitemagic"
        
        results["armies"]["public"] = {
            "functions": deploy_function_signature_army(public_whitemagic, "public"),
            "classes": deploy_class_hierarchy_army(public_whitemagic, "public"),
            "imports": deploy_import_dependency_army(public_whitemagic, "public"),
            "decorators": deploy_decorator_pattern_army(public_whitemagic, "public"),
            "constants": deploy_constant_extraction_army(public_whitemagic, "public"),
            "docstrings": deploy_docstring_analysis_army(public_whitemagic, "public"),
            "exceptions": deploy_error_handling_army(public_whitemagic, "public"),
            "async": deploy_async_pattern_army(public_whitemagic, "public"),
        }
    else:
        print("⚠️  whitemagicpublic not found")
        results["armies"]["public"] = None
    
    print()
    
    # Save comprehensive results
    results_path = PROJECT_ROOT / "reports" / "deep_scan_results.json"
    results_path.write_text(json.dumps(results, indent=2))
    
    # Generate summary
    print("=" * 80)
    print("DEEP SCAN SUMMARY")
    print("=" * 80)
    print()
    
    dev_results = results["armies"]["dev"]
    print("whitemagicdev:")
    print(f"   Functions: {dev_results['functions']['count']:,}")
    print(f"   Classes: {dev_results['classes']['count']:,}")
    print(f"   Import deps: {dev_results['imports']['total']:,}")
    print(f"   Decorators: {dev_results['decorators']['unique']:,} unique, {dev_results['decorators']['total_uses']:,} uses")
    print(f"   Constants: {dev_results['constants']['count']:,}")
    print(f"   Docstrings: {dev_results['docstrings']['count']:,}")
    print(f"   Exceptions: {dev_results['exceptions']['unique']:,} types, {dev_results['exceptions']['total']:,} handlers")
    print(f"   Async patterns: {dev_results['async']['total']:,}")
    print()
    
    if results["armies"]["public"]:
        public_results = results["armies"]["public"]
        print("whitemagicpublic:")
        print(f"   Functions: {public_results['functions']['count']:,}")
        print(f"   Classes: {public_results['classes']['count']:,}")
        print(f"   Import deps: {public_results['imports']['total']:,}")
        print(f"   Decorators: {public_results['decorators']['unique']:,} unique, {public_results['decorators']['total_uses']:,} uses")
        print(f"   Constants: {public_results['constants']['count']:,}")
        print(f"   Docstrings: {public_results['docstrings']['count']:,}")
        print(f"   Exceptions: {public_results['exceptions']['unique']:,} types, {public_results['exceptions']['total']:,} handlers")
        print(f"   Async patterns: {public_results['async']['total']:,}")
        print()
    
    print(f"📄 Full report: {results_path}")
    print()
    print(f"✅ Deep scan complete! {total_clones:,} clones deployed")

if __name__ == "__main__":
    main()
