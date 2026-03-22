#!/usr/bin/env python3
"""S025 Phase 2: Function-to-Garden Mapping Scanner.

Extracts functions from Python files and maps them to gardens.
"""

from __future__ import annotations

import ast
import re
import sys
from pathlib import Path
from typing import Any

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.garden_directory import GardenDirectory
from whitemagic.core.garden_function_registry import (
    GardenFunctionRegistry,
    analyze_function_for_garden,
)


def extract_python_functions(content: str) -> list[dict[str, Any]]:
    """Extract all functions from Python file with metadata."""
    functions = []
    try:
        tree = ast.parse(content)

        for node in ast.walk(tree):
            if isinstance(node, (ast.FunctionDef, ast.AsyncFunctionDef)):
                # Get docstring
                docstring = ast.get_docstring(node) or ""

                # Get source code snippet (first 20 lines or 500 chars)
                source_lines = content.split("\n")
                start_line = node.lineno - 1
                end_line = min(start_line + 20, node.end_lineno or start_line + 20)
                source_snippet = "\n".join(source_lines[start_line:end_line])[:500]

                # Get called functions
                dependencies = []
                for child in ast.walk(node):
                    if isinstance(child, ast.Call):
                        if isinstance(child.func, ast.Name):
                            dependencies.append(child.func.id)
                        elif isinstance(child.func, ast.Attribute):
                            dependencies.append(child.func.attr)

                functions.append({
                    "name": node.name,
                    "docstring": docstring,
                    "source": source_snippet,
                    "dependencies": list(set(dependencies))[:20],
                    "is_public": not node.name.startswith("_"),
                    "line": node.lineno,
                })
    except SyntaxError:
        # Fallback to regex
        for match in re.finditer(r"^(?:async\s+)?def\s+(\w+)\s*\(([^)]*)\):", content, re.MULTILINE):
            name = match.group(1)
            # Get following lines as source
            start = match.start()
            end = min(start + 500, len(content))
            source_snippet = content[start:end]

            # Extract docstring
            docstring = ""
            doc_match = re.search(r'"""([^"]*?)"""', source_snippet, re.DOTALL)
            if doc_match:
                docstring = doc_match.group(1)

            functions.append({
                "name": name,
                "docstring": docstring,
                "source": source_snippet,
                "dependencies": [],
                "is_public": not name.startswith("_"),
                "line": content[:start].count("\n") + 1,
            })

    return functions


def scan_python_functions(root: Path, registry: GardenFunctionRegistry, directory: GardenDirectory) -> dict[str, Any]:
    """Scan all Python files and map functions to gardens."""
    stats = {
        "total_functions": 0,
        "by_garden": {},
        "public_functions": 0,
        "files_processed": 0,
        "errors": [],
    }

    # Get all Python files directly from file mappings
    python_files = []
    for fp, mapping in directory._file_mappings.items():
        if mapping.file_type == "python":
            python_files.append((fp, mapping.primary_garden))

    print(f"📂 Scanning {len(python_files)} Python files for functions...")

    for i, (rel_path, file_garden) in enumerate(python_files):
        if (i + 1) % 200 == 0:
            print(f"  Processed {i + 1}/{len(python_files)} files...")

        file_path = root / rel_path
        if not file_path.exists():
            continue

        try:
            content = file_path.read_text(encoding="utf-8", errors="replace")
        except Exception as e:
            stats["errors"].append(f"{rel_path}: {e}")
            continue

        # Extract functions
        functions = extract_python_functions(content)

        for func_data in functions:
            # Analyze function for garden
            mapping = analyze_function_for_garden(
                function_name=func_data["name"],
                file_path=rel_path,
                file_garden=file_garden,
                docstring=func_data["docstring"],
                source_code=func_data["source"],
                dependencies=func_data["dependencies"],
            )

            # Register
            registry.register_function(mapping)

            # Update stats
            stats["total_functions"] += 1
            if mapping.primary_garden not in stats["by_garden"]:
                stats["by_garden"][mapping.primary_garden] = 0
            stats["by_garden"][mapping.primary_garden] += 1
            if func_data["is_public"]:
                stats["public_functions"] += 1

        stats["files_processed"] += 1

    return stats


def main() -> None:
    """Run the function scanner."""
    root = Path(__file__).parent.parent

    print("=" * 60)
    print("🌸 S025 Phase 2: Function-to-Garden Mapping")
    print("=" * 60)
    print()

    # Load file directory first
    from whitemagic.core.garden_directory import GardenDirectory
    file_registry_path = root / "data" / "garden_file_registry.json"
    directory = GardenDirectory(file_registry_path)
    if not directory.load():
        print("❌ File registry not found. Run s025_garden_organization.py first.")
        return

    # Create function registry
    registry_path = root / "data" / "garden_function_registry.json"
    registry = GardenFunctionRegistry(registry_path)

    # Scan
    stats = scan_python_functions(root, registry, directory)

    # Save
    registry.save()
    print(f"\n💾 Function registry saved to {registry_path}")

    # Summary
    print()
    print("=" * 60)
    print("SUMMARY")
    print("=" * 60)
    print(f"Total functions: {stats['total_functions']}")
    print(f"Public functions: {stats['public_functions']}")
    print(f"Files processed: {stats['files_processed']}")
    print(f"Errors: {len(stats['errors'])}")
    print()
    print("Top 5 gardens by function count:")
    for garden, count in sorted(stats["by_garden"].items(), key=lambda x: -x[1])[:5]:
        print(f"  {garden}: {count} functions")


if __name__ == "__main__":
    main()
