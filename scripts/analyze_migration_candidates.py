#!/usr/bin/env python3
"""
Polyglot Migration Candidate Analyzer
Identifies Python files best suited for Rust/Zig/Go migration
"""

import ast
import os
from pathlib import Path

# Keywords indicating performance-critical code
HOT_PATH_INDICATORS = [
    'embedding', 'cosine', 'similarity', 'search', 'vector', 'numpy',
    'np.dot', 'np.array', 'torch', 'tensorflow', 'batch', 'simd',
    'parallel', 'thread', 'asyncio', 'rayon', 'hnsw', 'index',
    'consolidation', 'mining', 'association', 'graph', 'traversal'
]

# Migration priority scores
def score_file(filepath: Path, content: str) -> dict:
    """Score a Python file for migration priority."""
    score = 0
    reasons = []
    lines = content.split('\n')
    loc = len(lines)

    # Check for hot path indicators
    content_lower = content.lower()
    for indicator in HOT_PATH_INDICATORS:
        if indicator in content_lower:
            score += 2
            if indicator not in [r.split()[0] for r in reasons]:
                reasons.append(f"{indicator} usage")

    # Large files are better migration candidates (amortize FFI overhead)
    if loc > 500:
        score += 3
        reasons.append(f"Large file ({loc} LOC)")
    elif loc > 200:
        score += 2
        reasons.append(f"Medium file ({loc} LOC)")

    # Check for loops/numerical operations
    if 'for ' in content and ('range' in content or 'zip' in content):
        score += 2
        reasons.append("Loop-heavy")

    # Check for existing Rust variants (from monte_carlo)
    rust_variant_exists = False
    for variant_dir in ['monte_carlo_output/rust']:
        variant_path = Path('/home/lucas/Desktop/whitemagicdev') / variant_dir
        if variant_path.exists():
            stem = filepath.stem
            for rust_file in variant_path.glob('*.rs'):
                if stem in rust_file.name:
                    rust_variant_exists = True
                    score += 5
                    reasons.append(f"Rust variant exists: {rust_file.name}")
                    break

    # Check for class definitions (OO code is harder to migrate)
    try:
        tree = ast.parse(content)
        classes = [node for node in ast.walk(tree) if isinstance(node, ast.ClassDef)]
        if len(classes) > 3:
            score -= 2
            reasons.append("Many classes (harder migration)")
    except:
        pass

    return {
        'score': max(0, score),
        'loc': loc,
        'reasons': reasons,
        'rust_variant': rust_variant_exists
    }

def analyze_migration_candidates(directory: Path, max_files: int = 50):
    """Find top migration candidates."""
    candidates = []

    for root, dirs, files in os.walk(directory):
        # Skip excluded directories
        dirs[:] = [d for d in dirs if d not in {
            '_archives', 'monte_carlo_output', '__pycache__', '.git',
            'modular', 'node_modules', 'target', 'tests', 'scripts'
        } and not d.startswith('.')]

        for file in files:
            if file.endswith('.py'):
                filepath = Path(root) / file
                try:
                    with open(filepath, encoding='utf-8', errors='ignore') as f:
                        content = f.read()

                    analysis = score_file(filepath, content)
                    if analysis['score'] > 3:  # Threshold for candidate
                        candidates.append({
                            'path': str(filepath.relative_to(directory)),
                            'score': analysis['score'],
                            'loc': analysis['loc'],
                            'reasons': analysis['reasons'],
                            'rust_variant': analysis['rust_variant']
                        })
                except Exception:
                    pass

    # Sort by score descending
    candidates.sort(key=lambda x: x['score'], reverse=True)
    return candidates[:max_files]

def generate_report(candidates: list) -> str:
    """Generate migration candidate report."""
    lines = []
    lines.append("╔══════════════════════════════════════════════════════════════════════╗")
    lines.append("║        TOP POLYGLOT MIGRATION CANDIDATES (Python → Rust/Zig)        ║")
    lines.append("╠══════════════════════════════════════════════════════════════════════╣")
    lines.append(f"║  Analyzed: {len(candidates)} high-priority files{'':>37}║")
    lines.append("╚══════════════════════════════════════════════════════════════════════╝")
    lines.append("")

    # Priority tiers
    tiers = {
        '🔥 CRITICAL (Score 10+)': [c for c in candidates if c['score'] >= 10],
        '⚡ HIGH (Score 7-9)': [c for c in candidates if 7 <= c['score'] <= 9],
        '📈 MEDIUM (Score 5-6)': [c for c in candidates if 5 <= c['score'] <= 6],
        '💡 LOW (Score 3-4)': [c for c in candidates if c['score'] < 5],
    }

    for tier_name, tier_candidates in tiers.items():
        if tier_candidates:
            lines.append(f"\n{tier_name}")
            lines.append("─" * 70)
            for c in tier_candidates[:10]:  # Top 10 per tier
                rust_badge = " [R]" if c['rust_variant'] else ""
                lines.append(f"  Score {c['score']:2} │ {c['path']}{rust_badge}")
                lines.append(f"         │ {c['loc']:>4} LOC │ {', '.join(c['reasons'][:3])}")

    # Summary stats
    lines.append("\n")
    lines.append("═" * 70)
    lines.append("MIGRATION STATISTICS")
    lines.append("═" * 70)

    total_loc = sum(c['loc'] for c in candidates)
    with_variants = len([c for c in candidates if c['rust_variant']])

    lines.append(f"  Total candidates: {len(candidates)} files")
    lines.append(f"  Total LOC: {total_loc:,} lines")
    lines.append(f"  With Rust variants: {with_variants} files (fast-track migration)")
    lines.append("")
    lines.append("MIGRATION RECOMMENDATIONS:")
    lines.append("  1. Priority: Files with existing Rust variants (proven patterns)")
    lines.append("  2. Target: Large numerical/embedding/search modules first")
    lines.append("  3. Strategy: Keep Python API, move core logic to Rust/Zig")

    return '\n'.join(lines)

if __name__ == '__main__':
    root = Path('/home/lucas/Desktop/whitemagicdev')
    candidates = analyze_migration_candidates(root)
    report = generate_report(candidates)
    print(report)

    # Save to file
    output_path = root / 'reports' / 'migration_candidates.md'
    output_path.parent.mkdir(exist_ok=True)
    with open(output_path, 'w') as f:
        f.write("# Polyglot Migration Candidates\n\n")
        f.write("Analysis of Python files best suited for Rust/Zig migration.\n\n")
        f.write(f"```\n{report}\n```\n")
    print(f"\n\nReport saved to: {output_path}")
