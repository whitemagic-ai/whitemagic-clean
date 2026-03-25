"""Hot Path Profiler - Profile and document Python hot paths for translation.

Phase 6: Remaining Hot Paths - Process ~200 files, prioritize by frequency
"""
from __future__ import annotations

import ast
from pathlib import Path
from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def profile_file(file_path: str) -> dict[str, Any]:
    """Profile a Python file for hot path candidates."""
    result = {
        "path": file_path,
        "functions": [],
        "loops": [],
        "hot_candidates": [],
    }
    
    try:
        with open(file_path) as f:
            content = f.read()
        
        tree = ast.parse(content)
        
        for node in ast.walk(tree):
            if isinstance(node, ast.FunctionDef):
                # Check for loops (hot path indicator)
                has_loops = any(
                    isinstance(child, (ast.For, ast.While))
                    for child in ast.walk(node)
                )
                
                # Check for large list operations
                has_list_ops = any(
                    isinstance(child, ast.ListComp)
                    for child in ast.walk(node)
                )
                
                func_info = {
                    "name": node.name,
                    "line": node.lineno,
                    "has_loops": has_loops,
                    "has_list_ops": has_list_ops,
                    "complexity": _estimate_complexity(node),
                }
                
                result["functions"].append(func_info)
                
                # Hot candidate if has loops or list ops
                if has_loops or has_list_ops:
                    result["hot_candidates"].append(func_info)
    
    except Exception as e:
        result["error"] = str(e)
    
    return result


def _estimate_complexity(node: ast.AST) -> str:
    """Estimate code complexity."""
    loop_count = sum(
        1 for child in ast.walk(node)
        if isinstance(child, (ast.For, ast.While))
    )
    
    if loop_count > 3:
        return "high"
    elif loop_count > 0:
        return "medium"
    return "low"


def batch_profile(
    file_paths: list[str],
    max_workers: int = 4
) -> list[dict[str, Any]]:
    """Profile multiple files in parallel."""
    from concurrent.futures import ThreadPoolExecutor
    
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        results = list(executor.map(profile_file, file_paths))
    
    return results


def prioritize_hot_paths(
    profiles: list[dict[str, Any]],
    top_n: int = 50
) -> list[dict[str, Any]]:
    """Prioritize hot paths by estimated impact."""
    all_candidates = []
    
    for profile in profiles:
        for candidate in profile.get("hot_candidates", []):
            candidate["file"] = profile["path"]
            # Score: complexity + location significance
            score = 0
            if candidate["complexity"] == "high":
                score += 3
            elif candidate["complexity"] == "medium":
                score += 2
            
            if candidate["has_loops"]:
                score += 2
            if candidate["has_list_ops"]:
                score += 1
            
            candidate["priority_score"] = score
            all_candidates.append(candidate)
    
    # Sort by priority
    all_candidates.sort(key=lambda x: x["priority_score"], reverse=True)
    return all_candidates[:top_n]


def generate_translation_plan(
    hot_paths: list[dict[str, Any]]
) -> dict[str, Any]:
    """Generate translation plan for hot paths."""
    plan = {
        "total_paths": len(hot_paths),
        "by_complexity": {},
        "recommendations": [],
    }
    
    for path in hot_paths:
        complexity = path["complexity"]
        plan["by_complexity"][complexity] = plan["by_complexity"].get(complexity, 0) + 1
        
        # Generate recommendation
        if path["has_loops"] and path["complexity"] == "high":
            rec = {
                "file": path["file"],
                "function": path["name"],
                "recommendation": "Translate to Rust - high loop count",
                "priority": "P1",
            }
        elif path["has_list_ops"]:
            rec = {
                "file": path["file"],
                "function": path["name"],
                "recommendation": "Consider Zig SIMD for vectorized operations",
                "priority": "P2",
            }
        else:
            rec = {
                "file": path["file"],
                "function": path["name"],
                "recommendation": "Profile before translation",
                "priority": "P3",
            }
        
        plan["recommendations"].append(rec)
    
    return plan


class HotPathProfiler:
    """Profiler for identifying Python hot paths for translation."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
        self._profiles: dict[str, dict[str, Any]] = {}
    
    def scan_directory(
        self,
        directory: str,
        pattern: str = "*.py",
        exclude_dirs: list[str] | None = None
    ) -> dict[str, Any]:
        """Scan directory for hot path candidates."""
        exclude_dirs = exclude_dirs or ["__pycache__", ".git", "_archives"]
        
        path = Path(directory)
        files = [
            str(f) for f in path.rglob(pattern)
            if not any(excl in str(f) for excl in exclude_dirs)
        ]
        
        # Profile all files
        profiles = batch_profile(files[:200])  # Limit to 200 files
        
        # Prioritize
        hot_paths = prioritize_hot_paths(profiles, top_n=50)
        
        # Generate plan
        plan = generate_translation_plan(hot_paths)
        
        return {
            "files_scanned": len(files),
            "profiles_collected": len(profiles),
            "hot_paths_identified": len(hot_paths),
            "translation_plan": plan,
        }
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_hot_path_profiler() -> HotPathProfiler:
    """Get hot path profiler instance."""
    return HotPathProfiler()
