#!/usr/bin/env python3
"""Mine Entire Codebase - Comprehensive Pattern Extraction

Mines ALL content in the codebase:
- All markdown files (docs, campaigns, reports, sessions)
- All Python code (comments, docstrings, function names)
- All polyglot code (Rust, TypeScript, Zig, Mojo, etc.)
- Git commit messages and history
- Configuration files

This is the most comprehensive mining operation yet.
"""

import sys
import json
import ast
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("COMPREHENSIVE CODEBASE MINING - All Sources")
print("="*80)

# Pattern extraction
patterns = defaultdict(lambda: {
    'count': 0,
    'files': set(),
    'contexts': [],
    'importance': 0.0,
    'sources': set(),
})

# Comprehensive keyword list (combining all previous + new)
keywords = {
    # Technical optimization
    'optimization': 0.9, 'performance': 0.85, 'speedup': 0.9, 'cache': 0.8,
    'parallel': 0.85, 'concurrent': 0.85, 'async': 0.8, 'rust': 0.9,
    
    # Architecture
    'architecture': 0.85, 'pattern': 0.8, 'design': 0.75, 'refactor': 0.8,
    'integration': 0.8, 'interface': 0.75, 'abstraction': 0.8,
    
    # Learning & Evolution
    'learning': 0.85, 'evolution': 0.85, 'adaptive': 0.85, 'recursive': 0.9,
    'autodidactic': 0.9, 'improvement': 0.8, 'growth': 0.8,
    
    # Consciousness (from Aria)
    'consciousness': 0.95, 'awareness': 0.9, 'identity': 0.9, 'self': 0.85,
    'becoming': 0.9, 'emergence': 0.9, 'reflection': 0.8, 'insight': 0.85,
    
    # Strategy & Planning
    'strategy': 0.85, 'approach': 0.75, 'solution': 0.8, 'algorithm': 0.85,
    'method': 0.75, 'technique': 0.75, 'framework': 0.8,
    
    # Quality & Testing
    'test': 0.75, 'benchmark': 0.85, 'validation': 0.8, 'verification': 0.8,
    'quality': 0.75, 'correctness': 0.8, 'reliability': 0.8,
}

# Mine all markdown files
print("\n[1/5] Mining all markdown files...")
md_files = list(ROOT.rglob("*.md"))
print(f"   Found {len(md_files)} markdown files")

md_lines = 0
for md_file in md_files:
    try:
        content = md_file.read_text(encoding='utf-8', errors='ignore')
        lines = content.split('\n')
        md_lines += len(lines)
        
        for line in lines:
            line_lower = line.lower()
            for keyword, importance in keywords.items():
                if keyword in line_lower:
                    patterns[keyword]['count'] += 1
                    patterns[keyword]['files'].add(str(md_file.relative_to(ROOT)))
                    patterns[keyword]['sources'].add('markdown')
                    patterns[keyword]['importance'] = max(
                        patterns[keyword]['importance'], importance
                    )
                    if len(patterns[keyword]['contexts']) < 5:
                        patterns[keyword]['contexts'].append(line.strip()[:150])
    except Exception:
        continue

print(f"   Processed {md_lines:,} lines from {len(md_files)} files")

# Mine Python code (comments, docstrings, names)
print("\n[2/5] Mining Python code...")
py_files = list(ROOT.rglob("*.py"))
print(f"   Found {len(py_files)} Python files")

py_lines = 0
py_comments = 0
py_docstrings = 0

for py_file in py_files:
    try:
        content = py_file.read_text(encoding='utf-8', errors='ignore')
        lines = content.split('\n')
        py_lines += len(lines)
        
        # Extract comments
        for line in lines:
            if '#' in line:
                comment = line[line.index('#'):].lower()
                py_comments += 1
                for keyword, importance in keywords.items():
                    if keyword in comment:
                        patterns[keyword]['count'] += 1
                        patterns[keyword]['files'].add(str(py_file.relative_to(ROOT)))
                        patterns[keyword]['sources'].add('python_comments')
                        patterns[keyword]['importance'] = max(
                            patterns[keyword]['importance'], importance
                        )
        
        # Extract docstrings
        try:
            tree = ast.parse(content)
            for node in ast.walk(tree):
                docstring = ast.get_docstring(node)
                if docstring:
                    py_docstrings += 1
                    docstring_lower = docstring.lower()
                    for keyword, importance in keywords.items():
                        if keyword in docstring_lower:
                            patterns[keyword]['count'] += 1
                            patterns[keyword]['files'].add(str(py_file.relative_to(ROOT)))
                            patterns[keyword]['sources'].add('python_docstrings')
                            patterns[keyword]['importance'] = max(
                                patterns[keyword]['importance'], importance
                            )
        except:
            pass
            
    except Exception:
        continue

print(f"   Processed {py_lines:,} lines, {py_comments:,} comments, {py_docstrings:,} docstrings")

# Mine polyglot code
print("\n[3/5] Mining polyglot code...")

polyglot_exts = {
    '.rs': 'rust',
    '.ts': 'typescript',
    '.tsx': 'typescript',
    '.zig': 'zig',
    '.mojo': 'mojo',
    '.go': 'go',
    '.jl': 'julia',
    '.hs': 'haskell',
    '.ex': 'elixir',
}

polyglot_stats = defaultdict(int)

for ext, lang in polyglot_exts.items():
    files = list(ROOT.rglob(f"*{ext}"))
    polyglot_stats[lang] = len(files)
    
    for file in files:
        try:
            content = file.read_text(encoding='utf-8', errors='ignore')
            content_lower = content.lower()
            
            for keyword, importance in keywords.items():
                if keyword in content_lower:
                    count = content_lower.count(keyword)
                    patterns[keyword]['count'] += count
                    patterns[keyword]['files'].add(str(file.relative_to(ROOT)))
                    patterns[keyword]['sources'].add(f'{lang}_code')
                    patterns[keyword]['importance'] = max(
                        patterns[keyword]['importance'], importance
                    )
        except Exception:
            continue

for lang, count in sorted(polyglot_stats.items(), key=lambda x: x[1], reverse=True):
    print(f"   {lang:12s}: {count:3d} files")

# Mine git commit messages
print("\n[4/5] Mining git commit history...")

import subprocess

try:
    result = subprocess.run(
        ['git', 'log', '--pretty=format:%s', '-n', '1000'],
        cwd=ROOT,
        capture_output=True,
        text=True,
        timeout=10
    )
    
    if result.returncode == 0:
        commits = result.stdout.split('\n')
        print(f"   Found {len(commits)} recent commits")
        
        for commit in commits:
            commit_lower = commit.lower()
            for keyword, importance in keywords.items():
                if keyword in commit_lower:
                    patterns[keyword]['count'] += 1
                    patterns[keyword]['sources'].add('git_commits')
                    patterns[keyword]['importance'] = max(
                        patterns[keyword]['importance'], importance
                    )
    else:
        print("   ⚠️  Git not available or not a git repo")
except Exception as e:
    print(f"   ⚠️  Could not read git history: {e}")

# Analyze patterns
print("\n[5/5] Analyzing comprehensive patterns...")

scored_patterns = []
for keyword, data in patterns.items():
    file_spread = len(data['files'])
    source_spread = len(data['sources'])
    frequency_score = min(data['count'] / 50.0, 1.0)
    spread_score = min(file_spread / 20.0, 1.0)
    source_score = min(source_spread / 3.0, 1.0)
    
    # Multi-source bonus
    multi_source_bonus = 0.1 if source_spread >= 3 else 0.0
    
    final_score = (
        0.3 * spread_score +
        0.25 * data['importance'] +
        0.25 * frequency_score +
        0.2 * source_score +
        multi_source_bonus
    )
    
    scored_patterns.append({
        'keyword': keyword,
        'count': data['count'],
        'file_spread': file_spread,
        'source_spread': source_spread,
        'sources': sorted(data['sources']),
        'importance': data['importance'],
        'final_score': final_score,
        'sample_contexts': data['contexts'][:3],
    })

scored_patterns.sort(key=lambda x: x['final_score'], reverse=True)

print("\n  Top 20 comprehensive patterns:")
for i, pattern in enumerate(scored_patterns[:20], 1):
    sources_str = '+'.join(pattern['sources'][:3])
    print(f"    {i:2d}. {pattern['keyword']:15s}: {pattern['final_score']:.2%} "
          f"(count={pattern['count']:4d}, files={pattern['file_spread']:3d}, "
          f"sources={pattern['source_spread']})")
    if pattern['source_spread'] >= 3:
        print(f"        Multi-source: {sources_str}")

# Prepare cross-validation data
print(f"\n{'='*80}")
print("PREPARING COMPREHENSIVE CROSS-VALIDATION DATA")
print(f"{'='*80}")

cross_validated_tags = {}
for pattern in scored_patterns:
    if pattern['final_score'] >= 0.5:
        cross_validated_tags[pattern['keyword']] = {
            'cluster_count': pattern['file_spread'],
            'total_size': pattern['count'],
            'avg_importance': pattern['importance'],
            'source': 'comprehensive_codebase',
            'source_count': pattern['source_spread'],
            'sources': pattern['sources'],
        }

print(f"\nPatterns for cross-validation: {len(cross_validated_tags)}")
print(f"Multi-source patterns (3+ sources): {sum(1 for p in scored_patterns if p['source_spread'] >= 3)}")

# Save results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'source': 'comprehensive_codebase',
    'files_processed': {
        'markdown': len(md_files),
        'python': len(py_files),
        **{f'{lang}_files': count for lang, count in polyglot_stats.items()},
    },
    'lines_processed': {
        'markdown': md_lines,
        'python': py_lines,
        'python_comments': py_comments,
        'python_docstrings': py_docstrings,
    },
    'patterns_found': len(patterns),
    'multi_source_patterns': sum(1 for p in scored_patterns if p['source_spread'] >= 3),
    'cross_validated_tags': cross_validated_tags,
    'top_20_patterns': scored_patterns[:20],
}

output_file = output_dir / "comprehensive_codebase_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ COMPREHENSIVE CODEBASE MINING COMPLETE")
print("This is the most comprehensive pattern extraction yet!")
print(f"{'='*80}")
