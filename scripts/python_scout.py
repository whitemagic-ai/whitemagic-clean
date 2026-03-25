#!/usr/bin/env python3
"""
WhiteMagic Python Scout - Archival & Polyglot Migration Analysis
Scouts the Python codebase to find:
1. Archival candidates (unused, redundant, test-only files)
2. Polyglot migration candidates by language specialization
"""

import ast
from pathlib import Path
from dataclasses import dataclass, field
from typing import List

@dataclass
class FileAnalysis:
    path: str
    loc: int
    imports: List[str] = field(default_factory=list)
    functions: List[str] = field(default_factory=list)
    classes: List[str] = field(default_factory=list)
    has_main: bool = False
    is_test: bool = False
    is_script: bool = False
    docstring: str = ""
    
    # Scores
    archival_score: int = 0
    mojo_score: int = 0
    elixir_score: int = 0
    rust_score: int = 0
    koka_score: int = 0
    go_score: int = 0
    
    # Reasons
    archival_reasons: List[str] = field(default_factory=list)
    mojo_reasons: List[str] = field(default_factory=list)
    elixir_reasons: List[str] = field(default_factory=list)
    rust_reasons: List[str] = field(default_factory=list)
    koka_reasons: List[str] = field(default_factory=list)
    go_reasons: List[str] = field(default_factory=list)

# Target directories for Python files
TARGET_DIRS = ['whitemagic', 'scripts', 'tests', 'eval', 'geneseed', 'nexus', 'sdk', 'haskell', 'elixir', 'koka-clones']
EXCLUDE_DIRS = {'_archives', '__pycache__', '.git', 'node_modules', 'target', 'build', 
                'modular', 'monte_carlo_output', '.venv', 'dist'}

def analyze_file(filepath: Path) -> FileAnalysis:
    """Analyze a Python file for archival and migration potential."""
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        lines = content.split('\n')
        loc = len(lines)
    except Exception:
        return None
    
    rel_path = str(filepath.relative_to(Path('/home/lucas/Desktop/whitemagicdev')))
    analysis = FileAnalysis(path=rel_path, loc=loc)
    
    # Parse AST
    try:
        tree = ast.parse(content)
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                for alias in node.names:
                    analysis.imports.append(alias.name)
            elif isinstance(node, ast.ImportFrom):
                if node.module:
                    analysis.imports.append(node.module)
            elif isinstance(node, ast.FunctionDef):
                analysis.functions.append(node.name)
            elif isinstance(node, ast.ClassDef):
                analysis.classes.append(node.name)
            elif isinstance(node, ast.If) and hasattr(node.test, 'left'):
                # Check for if __name__ == '__main__'
                if isinstance(node.test.left, ast.Name) and node.test.left.id == '__name__':
                    analysis.has_main = True
    except:
        pass
    
    # File type detection
    if 'test' in filepath.name.lower() or filepath.parent.name == 'tests':
        analysis.is_test = True
    if 'script' in filepath.parent.name.lower() or filepath.parent.name == 'scripts':
        analysis.is_script = True
    
    # === ARCHIVAL SCORING ===
    content_lower = content.lower()
    
    # High archival indicators
    if loc < 20:
        analysis.archival_score += 5
        analysis.archival_reasons.append(f"Tiny file ({loc} LOC)")
    elif loc < 50:
        analysis.archival_score += 3
        analysis.archival_reasons.append(f"Small file ({loc} LOC)")
    
    if not analysis.functions and not analysis.classes:
        analysis.archival_score += 4
        analysis.archival_reasons.append("No functions or classes (stub/dead)")
    
    if 'deprecated' in content_lower or 'obsolete' in content_lower:
        analysis.archival_score += 5
        analysis.archival_reasons.append("Marked deprecated/obsolete")
    
    if 'todo' in content_lower and loc < 100:
        analysis.archival_score += 2
        analysis.archival_reasons.append("TODO-only stub")
    
    # Very low usage = archival candidate
    if len(analysis.functions) == 1 and loc < 30:
        analysis.archival_score += 3
        analysis.archival_reasons.append("Single-function utility")
    
    # === MOJO SCORING (Numerical/AI workloads) ===
    mojo_indicators = [
        ('numpy', 3), ('torch', 3), ('tensorflow', 3), ('jax', 3),
        ('embedding', 2), ('vector', 2), ('matrix', 2), ('tensor', 2),
        ('simd', 3), ('parallel', 1), ('batch', 1), ('gpu', 2),
        ('simd.cosine', 3), ('@parameter', 2)
    ]
    for indicator, score in mojo_indicators:
        if indicator in content_lower:
            analysis.mojo_score += score
            if indicator not in analysis.mojo_reasons:
                analysis.mojo_reasons.append(indicator)
    
    if analysis.mojo_score > 5 and loc > 100:
        analysis.mojo_score += 2
        analysis.mojo_reasons.append("Substantial numerical code")
    
    # === ELIXIR SCORING (Concurrency/Genserver patterns) ===
    elixir_indicators = [
        ('asyncio', 2), ('concurrent', 2), ('genserver', 3), ('agent', 1),
        ('task.', 1), ('supervisor', 2), ('gen_server', 3), ('spawn', 1),
        ('message', 1), ('mailbox', 2), ('pubsub', 2), ('event', 1),
        ('worker', 1), ('queue', 1), ('pipeline', 2)
    ]
    for indicator, score in elixir_indicators:
        if indicator in content_lower:
            analysis.elixir_score += score
            if indicator not in analysis.elixir_reasons:
                analysis.elixir_reasons.append(indicator)
    
    if 'class' in content_lower and any('worker' in f.lower() for f in analysis.classes):
        analysis.elixir_score += 2
        analysis.elixir_reasons.append("Worker class pattern")
    
    # === RUST SCORING (Performance/memory safety) ===
    rust_indicators = [
        ('unsafe', 2), ('cython', 2), ('cffi', 2), ('rust', 1),
        ('memory', 1), ('buffer', 1), ('simd', 3), ('rayon', 3),
        ('performance', 1), ('hot', 1), ('critical', 1), ('path', 1),
        ('search', 1), ('index', 1), ('graph', 1), ('hnsw', 3)
    ]
    for indicator, score in rust_indicators:
        if indicator in content_lower:
            analysis.rust_score += score
            if indicator not in analysis.rust_reasons:
                analysis.rust_reasons.append(indicator)
    
    # Already identified hot paths
    if any(x in rel_path for x in ['hot_path', 'embed', 'search', 'consolidat', 'miner']):
        analysis.rust_score += 3
        analysis.rust_reasons.append("Known hot path")
    
    # === KOKA SCORING (Effect-based patterns) ===
    koka_indicators = [
        ('effect', 2), ('handler', 2), ('resume', 2), ('control', 1),
        ('exception', 1), ('raise', 1), ('with ', 1), ('context', 1),
        ('state', 1), ('io', 1), ('transaction', 2), ('comp', 1),
        ('functional', 1), ('monad', 2), ('functor', 2)
    ]
    for indicator, score in koka_indicators:
        if indicator in content_lower:
            analysis.koka_score += score
            if indicator not in analysis.koka_reasons:
                analysis.koka_reasons.append(indicator)
    
    # Decorator-heavy files = effect candidates
    decorator_count = content.count('@')
    if decorator_count > 5:
        analysis.koka_score += 1
        analysis.koka_reasons.append(f"{decorator_count} decorators")
    
    # === GO SCORING (Networking/mesh protocols) ===
    go_indicators = [
        ('http', 1), ('grpc', 2), ('websocket', 2), ('socket', 1),
        ('server', 1), ('client', 1), ('protocol', 1), ('mesh', 2),
        ('network', 1), ('request', 1), ('response', 1), ('api', 1),
        ('goroutine', 3), ('channel', 2), ('jsonrpc', 2)
    ]
    for indicator, score in go_indicators:
        if indicator in content_lower:
            analysis.go_score += score
            if indicator not in analysis.go_reasons:
                analysis.go_reasons.append(indicator)
    
    if 'mesh' in rel_path.lower():
        analysis.go_score += 3
        analysis.go_reasons.append("Mesh module")
    
    return analysis

def scout_directory(root: Path) -> List[FileAnalysis]:
    """Scout all Python files in target directories."""
    results = []
    
    for target_dir in TARGET_DIRS:
        target_path = root / target_dir
        if not target_path.exists():
            continue
        
        for py_file in target_path.rglob('*.py'):
            # Skip excluded directories
            if any(excluded in str(py_file) for excluded in EXCLUDE_DIRS):
                continue
            
            analysis = analyze_file(py_file)
            if analysis:
                results.append(analysis)
    
    return results

def generate_report(results: List[FileAnalysis]) -> str:
    """Generate comprehensive scout report."""
    lines = []
    lines.append("╔══════════════════════════════════════════════════════════════════════╗")
    lines.append("║           WHITEMAGIC PYTHON SCOUT - CAMPAIGN REPORT                  ║")
    lines.append("╠══════════════════════════════════════════════════════════════════════╣")
    lines.append(f"║  Scanned: {len(results)} Python files{'':>42}║")
    total_loc = sum(r.loc for r in results)
    lines.append(f"║  Total LOC: {total_loc:,}{'':>51}║")
    lines.append("╚══════════════════════════════════════════════════════════════════════╝")
    
    # === ARCHIVAL CANDIDATES ===
    archival = [r for r in results if r.archival_score >= 5]
    archival.sort(key=lambda x: x.archival_score, reverse=True)
    
    lines.append("\n")
    lines.append("📦 ARCHIVAL CANDIDATES (High Score = Better Archive Target)")
    lines.append("─" * 70)
    lines.append(f"Found {len(archival)} files with archival_score >= 5")
    lines.append("")
    
    for r in archival[:15]:
        lines.append(f"  Score {r.archival_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.archival_reasons[:2])}")
    
    if len(archival) > 15:
        lines.append(f"  ... and {len(archival) - 15} more")
    
    # === MOJO CANDIDATES ===
    mojo = [r for r in results if r.mojo_score >= 5]
    mojo.sort(key=lambda x: x.mojo_score, reverse=True)
    
    lines.append("\n")
    lines.append("🔥 MOJO CANDIDATES (Numerical/AI/SIMD Workloads)")
    lines.append("─" * 70)
    lines.append(f"Found {len(mojo)} files with mojo_score >= 5")
    lines.append("")
    
    for r in mojo[:10]:
        lines.append(f"  Score {r.mojo_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.mojo_reasons[:3])}")
    
    # === ELIXIR CANDIDATES ===
    elixir = [r for r in results if r.elixir_score >= 5]
    elixir.sort(key=lambda x: x.elixir_score, reverse=True)
    
    lines.append("\n")
    lines.append("⚡ ELIXIR CANDIDATES (Concurrency/GenServer/Worker Patterns)")
    lines.append("─" * 70)
    lines.append(f"Found {len(elixir)} files with elixir_score >= 5")
    lines.append("")
    
    for r in elixir[:10]:
        lines.append(f"  Score {r.elixir_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.elixir_reasons[:3])}")
    
    # === RUST CANDIDATES ===
    rust = [r for r in results if r.rust_score >= 5]
    rust.sort(key=lambda x: x.rust_score, reverse=True)
    
    lines.append("\n")
    lines.append("🦀 RUST CANDIDATES (Performance/Memory Safety/Hot Paths)")
    lines.append("─" * 70)
    lines.append(f"Found {len(rust)} files with rust_score >= 5")
    lines.append("")
    
    for r in rust[:10]:
        lines.append(f"  Score {r.rust_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.rust_reasons[:3])}")
    
    # === KOKA CANDIDATES ===
    koka = [r for r in results if r.koka_score >= 4]
    koka.sort(key=lambda x: x.koka_score, reverse=True)
    
    lines.append("\n")
    lines.append("🎯 KOKA CANDIDATES (Effect-Based/Functional Patterns)")
    lines.append("─" * 70)
    lines.append(f"Found {len(koka)} files with koka_score >= 4")
    lines.append("")
    
    for r in koka[:8]:
        lines.append(f"  Score {r.koka_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.koka_reasons[:3])}")
    
    # === GO CANDIDATES ===
    go = [r for r in results if r.go_score >= 4]
    go.sort(key=lambda x: x.go_score, reverse=True)
    
    lines.append("\n")
    lines.append("🐹 GO CANDIDATES (Networking/Mesh/Protocol Handlers)")
    lines.append("─" * 70)
    lines.append(f"Found {len(go)} files with go_score >= 4")
    lines.append("")
    
    for r in go[:8]:
        lines.append(f"  Score {r.go_score:2} │ {r.path}")
        lines.append(f"         │ {r.loc:>4} LOC │ {', '.join(r.go_reasons[:3])}")
    
    # === SUMMARY ===
    lines.append("\n")
    lines.append("═" * 70)
    lines.append("CAMPAIGN SUMMARY")
    lines.append("═" * 70)
    
    archival_loc = sum(r.loc for r in archival)
    mojo_loc = sum(r.loc for r in mojo)
    elixir_loc = sum(r.loc for r in elixir)
    rust_loc = sum(r.loc for r in rust)
    koka_loc = sum(r.loc for r in koka)
    go_loc = sum(r.loc for r in go)
    
    lines.append(f"  Archival candidates:  {len(archival):3} files │ {archival_loc:>7,} LOC")
    lines.append(f"  Mojo candidates:      {len(mojo):3} files │ {mojo_loc:>7,} LOC")
    lines.append(f"  Elixir candidates:    {len(elixir):3} files │ {elixir_loc:>7,} LOC")
    lines.append(f"  Rust candidates:      {len(rust):3} files │ {rust_loc:>7,} LOC")
    lines.append(f"  Koka candidates:      {len(koka):3} files │ {koka_loc:>7,} LOC")
    lines.append(f"  Go candidates:        {len(go):3} files │ {go_loc:>7,} LOC")
    lines.append("")
    lines.append("ESTIMATED IMPACT:")
    potential_reduction = archival_loc + (mojo_loc + elixir_loc + rust_loc) // 3  # Assume 1/3 migrate
    lines.append(f"  Potential Python LOC reduction: ~{potential_reduction:,} lines")
    lines.append(f"  New polyglot coverage: +{(mojo_loc + elixir_loc + rust_loc + koka_loc + go_loc):,} LOC")
    
    return '\n'.join(lines)

if __name__ == '__main__':
    root = Path('/home/lucas/Desktop/whitemagicdev')
    results = scout_directory(root)
    report = generate_report(results)
    print(report)
    
    # Save report
    output_path = root / 'reports' / 'python_scout_campaign.md'
    output_path.parent.mkdir(exist_ok=True)
    with open(output_path, 'w') as f:
        f.write("# Python Scout Campaign Report\n\n")
        f.write(f"```\n{report}\n```\n")
    print(f"\n\nReport saved to: {output_path}")
