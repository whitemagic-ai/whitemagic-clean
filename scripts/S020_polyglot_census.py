#!/usr/bin/env python3
"""S020 Polyglot Census — Complete Language Breakdown for WhiteMagic.

Analyzes the entire codebase to provide:
1. Complete LOC breakdown by language
2. Hot path identification (Python files that should be translated)
3. Polyglot acceleration opportunities
4. Target distribution calculation

Usage:
    python scripts/S020_polyglot_census.py
"""

from __future__ import annotations

import json
import re
import subprocess
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

# Project root
PROJECT_ROOT = Path("/home/lucas/Desktop/whitemagicdev")


@dataclass
class LanguageStats:
    """Statistics for a single language."""
    name: str
    extension: str
    files: int = 0
    total_lines: int = 0
    code_lines: int = 0  # Non-comment, non-blank
    comment_lines: int = 0
    blank_lines: int = 0
    
    # Hot path analysis
    hot_candidates: list[dict[str, Any]] = field(default_factory=list)
    
    def to_dict(self) -> dict[str, Any]:
        return {
            "name": self.name,
            "extension": self.extension,
            "files": self.files,
            "total_lines": self.total_lines,
            "code_lines": self.code_lines,
            "comment_lines": self.comment_lines,
            "blank_lines": self.blank_lines,
            "hot_candidates": len(self.hot_candidates),
        }


@dataclass
class FileAnalysis:
    """Detailed analysis of a single file."""
    path: str
    language: str
    total_lines: int
    code_lines: int
    is_hot_candidate: bool = False
    translation_recommendation: str = ""
    hot_path_reason: str = ""
    
    def to_dict(self) -> dict[str, Any]:
        return {
            "path": self.path,
            "language": self.language,
            "lines": self.total_lines,
            "code_lines": self.code_lines,
            "is_hot": self.is_hot_candidate,
            "recommendation": self.translation_recommendation if self.is_hot_candidate else None,
            "reason": self.hot_path_reason if self.is_hot_candidate else None,
        }


# Language definitions with file extensions
LANGUAGES = {
    "Python": {
        "extensions": [".py"],
        "comment_patterns": [r"^\s*#", r'^\s*"""', r"^\s*'''"],
        "hot_path_indicators": [
            ("json", "Rust", "JSON serialization hot path"),
            ("sort", "Rust", "Sorting algorithm"),
            ("cosine", "Zig", "Vector similarity"),
            ("embedding", "Zig", "Embedding operations"),
            ("batch", "Rust", "Batch processing"),
            ("simd", "Zig", "SIMD operations"),
            ("hash", "Rust", "Hash operations"),
            ("pool", "Go", "Connection pool"),
            ("async", "Elixir", "Actor model async"),
            ("pattern", "Haskell", "Pattern matching"),
            ("parse", "Rust", "Parsing"),
            ("encode", "Mojo", "Encoding"),
            ("search", "Rust", "Search algorithm"),
            ("graph", "Rust", "Graph operations"),
            ("matrix", "Mojo", "Matrix operations"),
        ]
    },
    "Rust": {
        "extensions": [".rs"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "Zig": {
        "extensions": [".zig"],
        "comment_patterns": [r"^\s*//"],
    },
    "Go": {
        "extensions": [".go"],
        "comment_patterns": [r"^\s*//"],
    },
    "Elixir": {
        "extensions": [".ex", ".exs"],
        "comment_patterns": [r"^\s*#"],
    },
    "Haskell": {
        "extensions": [".hs"],
        "comment_patterns": [r"^\s*--", r"^\s*{-"],
    },
    "Julia": {
        "extensions": [".jl"],
        "comment_patterns": [r"^\s*#"],
    },
    "Mojo": {
        "extensions": [".mojo"],
        "comment_patterns": [r"^\s*#"],
    },
    "TypeScript": {
        "extensions": [".ts", ".tsx"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "JavaScript": {
        "extensions": [".js", ".jsx"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "C": {
        "extensions": [".c", ".h"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "C++": {
        "extensions": [".cpp", ".hpp", ".cc"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "Java": {
        "extensions": [".java"],
        "comment_patterns": [r"^\s*//", r"^\s*/\*"],
    },
    "Markdown": {
        "extensions": [".md"],
        "comment_patterns": [],
    },
    "JSON": {
        "extensions": [".json"],
        "comment_patterns": [],
    },
    "YAML": {
        "extensions": [".yml", ".yaml"],
        "comment_patterns": [r"^\s*#"],
    },
    "TOML": {
        "extensions": [".toml"],
        "comment_patterns": [r"^\s*#"],
    },
    "SQL": {
        "extensions": [".sql"],
        "comment_patterns": [r"^\s*--"],
    },
    "Shell": {
        "extensions": [".sh", ".bash"],
        "comment_patterns": [r"^\s*#"],
    },
}


def find_all_files(root: Path) -> dict[str, list[Path]]:
    """Find all files organized by language."""
    files_by_lang: dict[str, list[Path]] = defaultdict(list)
    
    for lang_name, lang_config in LANGUAGES.items():
        for ext in lang_config["extensions"]:
            # Use find for speed with better exclusions
            exclusions = [
                "-not", "-path", "*/.git/*",
                "-not", "-path", "*/__pycache__/*",
                "-not", "-path", "*/node_modules/*",
                "-not", "-path", "*/.venv/*",
                "-not", "-path", "*/target/*",
                "-not", "-path", "*/build/*",
                "-not", "-path", "*/dist/*",
                "-not", "-path", "*/.pixi/*",
                "-not", "-path", "*/.koka/*",
                "-not", "-path", "*/.mypy_cache/*",
                "-not", "-path", "*/monte_carlo_output/*",
                "-not", "-path", "*/modular/*",
                "-not", "-path", "*/wm_archive/*",
                "-not", "-path", "*/_archives/*",
                "-not", "-path", "*/whitemagic_memory_archive/*",
            ]
            try:
                result = subprocess.run(
                    ["find", str(root), "-type", "f", "-name", f"*{ext}"] + exclusions,
                    capture_output=True,
                    text=True,
                    timeout=60,
                )
                if result.returncode == 0:
                    for line in result.stdout.strip().split("\n"):
                        if line:
                            files_by_lang[lang_name].append(Path(line))
            except Exception:
                pass
    
    return dict(files_by_lang)


def analyze_file(file_path: Path, lang_name: str, lang_config: dict) -> FileAnalysis | None:
    """Analyze a single file for LOC and hot path indicators."""
    try:
        content = file_path.read_text(encoding="utf-8", errors="ignore")
        lines = content.split("\n")
        total_lines = len(lines)
        
        # Count blank and comment lines
        blank_lines = sum(1 for line in lines if not line.strip())
        comment_lines = 0
        in_multiline_comment = False
        
        for line in lines:
            stripped = line.strip()
            if not stripped:
                continue
            
            # Check for multiline comment markers
            if lang_name == "Python":
                if '"""' in stripped or "'''" in stripped:
                    if stripped.count('"""') % 2 == 1 or stripped.count("'''") % 2 == 1:
                        in_multiline_comment = not in_multiline_comment
                    comment_lines += 1
                    continue
            
            if in_multiline_comment:
                comment_lines += 1
                continue
            
            # Check single-line comments
            for pattern in lang_config.get("comment_patterns", []):
                if re.match(pattern, stripped):
                    comment_lines += 1
                    break
        
        code_lines = total_lines - blank_lines - comment_lines
        
        # Hot path analysis (Python only for now)
        is_hot = False
        recommendation = ""
        reason = ""
        
        if lang_name == "Python" and code_lines > 20:
            content_lower = content.lower()
            for indicator, target_lang, description in lang_config.get("hot_path_indicators", []):
                if indicator in content_lower:
                    # Check if it's actually a hot path (in function definition, not just imported)
                    if re.search(rf"def.*{indicator}|{indicator}.*=.*lambda|class.*{indicator}", content_lower):
                        is_hot = True
                        recommendation = f"Translate to {target_lang}"
                        reason = description
                        break
        
        return FileAnalysis(
            path=str(file_path.relative_to(PROJECT_ROOT)),
            language=lang_name,
            total_lines=total_lines,
            code_lines=max(0, code_lines),
            is_hot_candidate=is_hot,
            translation_recommendation=recommendation,
            hot_path_reason=reason,
        )
    except Exception as e:
        print(f"Error analyzing {file_path}: {e}")
        return None


def run_census() -> dict[str, Any]:
    """Run complete polyglot census."""
    print("🔍 S020 Polyglot Census: Analyzing WhiteMagic codebase...")
    print("=" * 70)
    
    # Find all files
    print("\n📁 Scanning for files...")
    files_by_lang = find_all_files(PROJECT_ROOT)
    
    # Analyze each file
    print("\n📊 Analyzing files...")
    stats_by_lang: dict[str, LanguageStats] = {}
    all_files: list[FileAnalysis] = []
    
    for lang_name, files in files_by_lang.items():
        if not files:
            continue
            
        print(f"   Analyzing {len(files)} {lang_name} files...")
        lang_config = LANGUAGES[lang_name]
        stats = LanguageStats(name=lang_name, extension=lang_config["extensions"][0][1:])
        
        for file_path in files:
            analysis = analyze_file(file_path, lang_name, lang_config)
            if analysis:
                stats.files += 1
                stats.total_lines += analysis.total_lines
                stats.code_lines += analysis.code_lines
                all_files.append(analysis)
                
                if analysis.is_hot_candidate:
                    stats.hot_candidates.append({
                        "path": analysis.path,
                        "lines": analysis.code_lines,
                        "recommendation": analysis.translation_recommendation,
                        "reason": analysis.hot_path_reason,
                    })
        
        stats_by_lang[lang_name] = stats
    
    # Calculate percentages
    total_code_lines = sum(s.code_lines for s in stats_by_lang.values())
    
    print("\n" + "=" * 70)
    print("📈 POLYGLOT BREAKDOWN")
    print("=" * 70)
    
    results = []
    for lang_name in sorted(stats_by_lang.keys(), key=lambda x: stats_by_lang[x].code_lines, reverse=True):
        stats = stats_by_lang[lang_name]
        pct = (stats.code_lines / total_code_lines * 100) if total_code_lines > 0 else 0
        
        result = {
            "language": lang_name,
            "files": stats.files,
            "total_lines": stats.total_lines,
            "code_lines": stats.code_lines,
            "percentage": round(pct, 1),
            "hot_candidates": len(stats.hot_candidates),
        }
        results.append(result)
        
        hot_indicator = f" 🔥{len(stats.hot_candidates)} hot" if stats.hot_candidates else ""
        print(f"{lang_name:15} {stats.files:6} files {stats.code_lines:9,} LOC ({pct:5.1f}%){hot_indicator}")
    
    print("\n" + "=" * 70)
    print(f"TOTAL: {sum(s.files for s in stats_by_lang.values())} files, {total_code_lines:,} code lines")
    print("=" * 70)
    
    # Hot candidates summary
    print("\n🔥 HOT PATH CANDIDATES FOR TRANSLATION:")
    print("-" * 70)
    
    hot_files = [f for f in all_files if f.is_hot_candidate]
    hot_files.sort(key=lambda x: x.code_lines, reverse=True)
    
    for f in hot_files[:20]:  # Top 20
        print(f"\n{f.path}")
        print(f"   Lines: {f.code_lines} → {f.translation_recommendation}")
        print(f"   Reason: {f.hot_path_reason}")
    
    if len(hot_files) > 20:
        print(f"\n... and {len(hot_files) - 20} more hot candidates")
    
    # Generate report
    report = {
        "timestamp": "2026-02-21T11:58:00",
        "campaign": "S020",
        "phase": "polyglot_census",
        "summary": {
            "total_files": sum(s.files for s in stats_by_lang.values()),
            "total_code_lines": total_code_lines,
            "languages_count": len(stats_by_lang),
        },
        "by_language": results,
        "hot_candidates": [f.to_dict() for f in hot_files],
        "target_distribution": {
            "Python": "60% (down from 85%)",
            "Rust": "20% (hot paths, JSON, graph)",
            "Zig": "10% (SIMD, vector ops)",
            "Go": "5% (networking, mesh)",
            "Elixir": "3% (concurrency, event bus)",
            "Haskell": "2% (type-safe rules)",
        },
    }
    
    # Save report
    report_path = PROJECT_ROOT / "reports" / "S020_polyglot_census.json"
    report_path.parent.mkdir(exist_ok=True)
    report_path.write_text(json.dumps(report, indent=2))
    print(f"\n💾 Report saved to: {report_path}")
    
    return report


if __name__ == "__main__":
    run_census()
