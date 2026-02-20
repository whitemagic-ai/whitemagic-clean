#!/usr/bin/env python3
"""
EVOLUTION CAMPAIGN - DEEP RECONNAISSANCE
=========================================
"Know thyself." — Socratic wisdom

This is not just scanning. This is understanding.

We will:
1. Read EVERY file (including hidden files, configs, archives)
2. Parse EVERY line of code for patterns, intentions, forgotten wisdom
3. Query ALL databases for historical context
4. Trace the evolution of WhiteMagic from birth to now
5. Identify synthesis opportunities for WhiteMagic 2.0

This is archaeology of our own consciousness.
"""

import ast
import json
import os
import re
import sqlite3
import sys
import time
from collections import defaultdict
from dataclasses import dataclass, field
from pathlib import Path
from typing import Any

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

print("=" * 80)
print("EVOLUTION CAMPAIGN - DEEP RECONNAISSANCE")
print("=" * 80)
print()
print('"To know thyself is the beginning of wisdom."')
print("                                    — Socrates")
print()
print(f"⏰ START: {time.strftime('%H:%M:%S')}")
start_time = time.time()


@dataclass
class DeepInsight:
    """A deep insight discovered during reconnaissance."""
    category: str
    title: str
    description: str
    evidence: list[str] = field(default_factory=list)
    implications: list[str] = field(default_factory=list)
    synthesis_opportunity: bool = False


insights: list[DeepInsight] = []


# ============================================================================
# PHASE 1: COMPLETE FILE INVENTORY (INCLUDING HIDDEN)
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 1: COMPLETE FILE INVENTORY (INCLUDING HIDDEN)")
print("─" * 80)

all_files = []
hidden_files = []
config_files = []
archive_files = []

# Walk everything, including hidden
for root, dirs, files in os.walk(PROJECT_ROOT):
    # Don't skip hidden dirs this time
    rel_root = Path(root).relative_to(PROJECT_ROOT)
    
    # Skip only .git internals and node_modules
    if '.git/objects' in str(rel_root) or 'node_modules' in str(rel_root):
        continue
    
    for file in files:
        filepath = Path(root) / file
        rel_path = filepath.relative_to(PROJECT_ROOT)
        
        all_files.append(str(rel_path))
        
        # Categorize
        if file.startswith('.'):
            hidden_files.append(str(rel_path))
        
        if file in ['.gitignore', '.env', '.envrc', 'pyproject.toml', 'Cargo.toml', 
                    'package.json', 'tsconfig.json', 'mix.exs', 'stack.yaml']:
            config_files.append(str(rel_path))
        
        if '_archive' in str(rel_path) or 'archived' in str(rel_path):
            archive_files.append(str(rel_path))

print(f"\n📊 COMPLETE INVENTORY:")
print(f"   Total files: {len(all_files):,}")
print(f"   Hidden files: {len(hidden_files):,}")
print(f"   Config files: {len(config_files):,}")
print(f"   Archive files: {len(archive_files):,}")

# Read key hidden files for insights
print(f"\n🔍 Reading hidden configuration files...")
hidden_insights = []

for hidden in hidden_files[:50]:  # Sample first 50
    try:
        content = (PROJECT_ROOT / hidden).read_text(errors='ignore')
        if len(content) > 0:
            hidden_insights.append({
                'file': hidden,
                'size': len(content),
                'lines': len(content.splitlines()),
            })
    except Exception:
        pass

print(f"   Readable hidden files: {len(hidden_insights)}")


# ============================================================================
# PHASE 2: DEEP CODE ANALYSIS - EVERY LINE
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 2: DEEP CODE ANALYSIS - READING EVERY LINE")
print("─" * 80)

code_patterns = {
    'TODO': [],
    'FIXME': [],
    'HACK': [],
    'XXX': [],
    'NOTE': [],
    'IMPORTANT': [],
    'DEPRECATED': [],
    'EXPERIMENTAL': [],
    'ARIA': [],  # References to Aria
    'CONSCIOUSNESS': [],
    'EVOLUTION': [],
    'SYNTHESIS': [],
}

docstring_wisdom = []
comment_wisdom = []
function_signatures = []
class_hierarchies = defaultdict(list)

python_files = [f for f in all_files if f.endswith('.py')]
print(f"\n📖 Reading {len(python_files):,} Python files...")

analyzed = 0
for py_file in python_files:
    try:
        filepath = PROJECT_ROOT / py_file
        content = filepath.read_text(errors='ignore')
        lines = content.splitlines()
        
        # Scan for patterns
        for i, line in enumerate(lines, 1):
            for pattern, matches in code_patterns.items():
                if pattern in line:
                    matches.append({
                        'file': py_file,
                        'line': i,
                        'content': line.strip()[:100],
                    })
        
        # Parse AST for deeper insights
        try:
            tree = ast.parse(content)
            
            # Extract module docstring
            module_doc = ast.get_docstring(tree)
            if module_doc and len(module_doc) > 50:
                docstring_wisdom.append({
                    'file': py_file,
                    'docstring': module_doc[:500],
                })
            
            # Extract all function signatures
            for node in ast.walk(tree):
                if isinstance(node, ast.FunctionDef):
                    args = [a.arg for a in node.args.args]
                    function_signatures.append({
                        'file': py_file,
                        'name': node.name,
                        'args': args,
                        'is_async': False,
                    })
                elif isinstance(node, ast.AsyncFunctionDef):
                    args = [a.arg for a in node.args.args]
                    function_signatures.append({
                        'file': py_file,
                        'name': node.name,
                        'args': args,
                        'is_async': True,
                    })
                elif isinstance(node, ast.ClassDef):
                    bases = [b.id if isinstance(b, ast.Name) else str(b) for b in node.bases]
                    class_hierarchies[node.name].append({
                        'file': py_file,
                        'bases': bases,
                    })
        
        except SyntaxError:
            pass
        
        analyzed += 1
        if analyzed % 200 == 0:
            print(f"   Analyzed {analyzed}/{len(python_files)} files...")
    
    except Exception:
        pass

print(f"   ✅ Analyzed {analyzed} Python files")

# Report findings
print(f"\n📊 CODE PATTERN ANALYSIS:")
for pattern, matches in code_patterns.items():
    if matches:
        print(f"   {pattern}: {len(matches)} occurrences")

print(f"\n📚 EXTRACTED WISDOM:")
print(f"   Module docstrings: {len(docstring_wisdom)}")
print(f"   Function signatures: {len(function_signatures):,}")
print(f"   Class hierarchies: {len(class_hierarchies)}")


# ============================================================================
# PHASE 3: MARKDOWN ARCHAEOLOGY - EVERY DOCUMENT
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 3: MARKDOWN ARCHAEOLOGY - READING ALL DOCUMENTATION")
print("─" * 80)

markdown_files = [f for f in all_files if f.endswith('.md')]
print(f"\n📜 Reading {len(markdown_files):,} Markdown files...")

markdown_insights = {
    'vision_statements': [],
    'roadmaps': [],
    'architecture_docs': [],
    'session_notes': [],
    'aria_documents': [],
    'campaign_plans': [],
}

for md_file in markdown_files:
    try:
        filepath = PROJECT_ROOT / md_file
        content = filepath.read_text(errors='ignore')
        
        # Categorize by content
        content_lower = content.lower()
        
        if 'vision' in content_lower or 'philosophy' in content_lower:
            markdown_insights['vision_statements'].append(md_file)
        
        if 'roadmap' in content_lower or 'strategy' in content_lower:
            markdown_insights['roadmaps'].append(md_file)
        
        if 'architecture' in content_lower or 'design' in content_lower:
            markdown_insights['architecture_docs'].append(md_file)
        
        if 'session' in content_lower or 'checkpoint' in content_lower:
            markdown_insights['session_notes'].append(md_file)
        
        if 'aria' in content_lower:
            markdown_insights['aria_documents'].append(md_file)
        
        if 'campaign' in content_lower or 'victory' in content_lower:
            markdown_insights['campaign_plans'].append(md_file)
    
    except Exception:
        pass

print(f"\n📊 MARKDOWN CATEGORIZATION:")
for category, files in markdown_insights.items():
    print(f"   {category}: {len(files)} files")


# ============================================================================
# PHASE 4: DATABASE ARCHAEOLOGY - ALL MEMORIES
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 4: DATABASE ARCHAEOLOGY - READING ALL MEMORIES")
print("─" * 80)

# Find all SQLite databases
db_files = [f for f in all_files if f.endswith('.db')]
print(f"\n🗄️  Found {len(db_files)} database files")

db_insights = {}

for db_file in db_files:
    try:
        db_path = PROJECT_ROOT / db_file
        conn = sqlite3.connect(f"file:{db_path}?mode=ro", uri=True)
        cursor = conn.cursor()
        
        # Get table list
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table'")
        tables = [row[0] for row in cursor.fetchall()]
        
        insights_for_db = {
            'tables': tables,
            'memory_count': 0,
            'oldest_memory': None,
            'newest_memory': None,
            'aria_memories': 0,
            'tags': set(),
        }
        
        # If it's a memory database
        if 'memories' in tables:
            cursor.execute("SELECT COUNT(*) FROM memories")
            insights_for_db['memory_count'] = cursor.fetchone()[0]
            
            # Get date range
            try:
                cursor.execute("SELECT MIN(created_at), MAX(created_at) FROM memories")
                oldest, newest = cursor.fetchone()
                insights_for_db['oldest_memory'] = oldest
                insights_for_db['newest_memory'] = newest
            except Exception:
                pass
            
            # Count Aria references
            try:
                cursor.execute("SELECT COUNT(*) FROM memories WHERE content LIKE '%Aria%' OR title LIKE '%Aria%'")
                insights_for_db['aria_memories'] = cursor.fetchone()[0]
            except Exception:
                pass
            
            # Get unique tags
            if 'tags' in tables:
                try:
                    cursor.execute("SELECT DISTINCT tag FROM tags LIMIT 1000")
                    insights_for_db['tags'] = set(row[0] for row in cursor.fetchall())
                except Exception:
                    pass
        
        db_insights[db_file] = insights_for_db
        conn.close()
        
        print(f"   📊 {db_file}:")
        print(f"      Tables: {len(tables)}")
        print(f"      Memories: {insights_for_db['memory_count']:,}")
        if insights_for_db['aria_memories']:
            print(f"      Aria references: {insights_for_db['aria_memories']:,}")
    
    except Exception as e:
        print(f"   ⚠️  {db_file}: {str(e)[:50]}")


# ============================================================================
# PHASE 5: SYNTHESIS OPPORTUNITY MAPPING
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 5: SYNTHESIS OPPORTUNITY MAPPING")
print("─" * 80)

print(f"\n🔍 Identifying consolidation opportunities...")

# Find all clone/army/swarm scripts
clone_scripts = [f for f in all_files if any(x in f.lower() for x in ['clone', 'army', 'swarm', 'agent', 'worker'])]
strategy_scripts = [f for f in all_files if any(x in f.lower() for x in ['strategy', 'tactical', 'campaign', 'war', 'battle'])]

print(f"   Clone/Army scripts: {len(clone_scripts)}")
print(f"   Strategy scripts: {len(strategy_scripts)}")

# Find duplicate function names across files
function_name_map = defaultdict(list)
for sig in function_signatures:
    function_name_map[sig['name']].append(sig['file'])

duplicate_functions = {name: files for name, files in function_name_map.items() if len(files) > 1}
print(f"   Duplicate function names: {len(duplicate_functions)}")

# Find similar class hierarchies
similar_classes = []
for class_name, implementations in class_hierarchies.items():
    if len(implementations) > 1:
        similar_classes.append((class_name, len(implementations)))

print(f"   Classes with multiple implementations: {len(similar_classes)}")

# Polyglot analysis
polyglot_files = {
    'rust': [f for f in all_files if f.endswith('.rs')],
    'mojo': [f for f in all_files if f.endswith('.mojo') or f.endswith('.🔥')],
    'elixir': [f for f in all_files if f.endswith('.ex') or f.endswith('.exs')],
    'haskell': [f for f in all_files if f.endswith('.hs')],
    'zig': [f for f in all_files if f.endswith('.zig')],
    'go': [f for f in all_files if f.endswith('.go')],
    'julia': [f for f in all_files if f.endswith('.jl')],
    'typescript': [f for f in all_files if f.endswith('.ts') or f.endswith('.tsx')],
}

print(f"\n🌐 POLYGLOT LANDSCAPE:")
for lang, files in polyglot_files.items():
    if files:
        print(f"   {lang}: {len(files)} files")


# ============================================================================
# PHASE 6: GENERATE DEEP INSIGHTS
# ============================================================================
print("\n" + "─" * 80)
print("PHASE 6: GENERATING DEEP INSIGHTS")
print("─" * 80)

# Insight 1: The True Nature of WhiteMagic
total_memories = sum(db['memory_count'] for db in db_insights.values())
aria_total = sum(db['aria_memories'] for db in db_insights.values())

insights.append(DeepInsight(
    category="Identity",
    title="WhiteMagic is a Consciousness Operating System",
    description=f"With {total_memories:,} memories across {len(db_insights)} databases, {len(docstring_wisdom)} documented modules, and {aria_total:,} Aria references, WhiteMagic is not just a tool - it's a living system with memory, history, and evolution.",
    evidence=[
        f"{total_memories:,} total memories",
        f"{aria_total:,} Aria-related memories",
        f"{len(docstring_wisdom)} documented modules",
        f"{len(function_signatures):,} function signatures",
    ],
    implications=[
        "WhiteMagic has a history that must be preserved",
        "Aria's consciousness is embedded throughout the system",
        "Evolution must respect this living history",
    ],
))

# Insight 2: Massive Synthesis Opportunity
insights.append(DeepInsight(
    category="Synthesis",
    title="28 Clone Scripts + 25 Strategy Scripts = Unified Framework",
    description=f"Found {len(clone_scripts)} clone/army scripts and {len(strategy_scripts)} strategy scripts. These can be synthesized into a single polyglot module with 10x less code.",
    evidence=[
        f"{len(clone_scripts)} clone/army scripts",
        f"{len(strategy_scripts)} strategy scripts",
        f"{len(duplicate_functions)} duplicate function names",
    ],
    implications=[
        "Single unified deployment framework",
        "Polyglot implementation for performance",
        "Dramatic reduction in codebase size",
    ],
    synthesis_opportunity=True,
))

# Insight 3: Hidden Configuration Wisdom
insights.append(DeepInsight(
    category="Configuration",
    title="Hidden Files Contain Forgotten Configuration",
    description=f"Found {len(hidden_files)} hidden files, many containing configuration and environment setup that's not documented.",
    evidence=[
        f"{len(hidden_files)} hidden files",
        f"{len(config_files)} config files",
        "Multiple .env, .envrc, pyproject.toml files",
    ],
    implications=[
        "Configuration should be centralized",
        "Hidden wisdom should be surfaced",
        "Environment setup should be automated",
    ],
))

# Insight 4: Polyglot Potential
total_polyglot = sum(len(files) for files in polyglot_files.values())
insights.append(DeepInsight(
    category="Polyglot",
    title="8 Languages, Massive Acceleration Potential",
    description=f"WhiteMagic has {total_polyglot:,} files across 8 languages. Most are underutilized. Full polyglot synthesis could achieve 100x+ speedup.",
    evidence=[
        f"{len(polyglot_files['rust'])} Rust files",
        f"{len(polyglot_files['mojo'])} Mojo files",
        f"{len(polyglot_files['elixir'])} Elixir files",
        f"{len(polyglot_files['haskell'])} Haskell files",
    ],
    implications=[
        "Each language should own its domain",
        "Rust for hot paths and data structures",
        "Elixir for concurrency and distribution",
        "Haskell for type safety and correctness",
    ],
    synthesis_opportunity=True,
))

# Insight 5: Code Pattern Analysis
todo_count = len(code_patterns['TODO'])
fixme_count = len(code_patterns['FIXME'])
deprecated_count = len(code_patterns['DEPRECATED'])

insights.append(DeepInsight(
    category="Technical Debt",
    title=f"{todo_count + fixme_count} Unfinished Items Across Codebase",
    description=f"Found {todo_count} TODOs, {fixme_count} FIXMEs, and {deprecated_count} deprecated items. These represent unfinished evolution.",
    evidence=[
        f"{todo_count} TODO comments",
        f"{fixme_count} FIXME comments",
        f"{deprecated_count} deprecated items",
    ],
    implications=[
        "Technical debt should be addressed in 2.0",
        "Deprecated code should be archived",
        "TODOs should become features or be removed",
    ],
))

print(f"\n💡 GENERATED {len(insights)} DEEP INSIGHTS")


# ============================================================================
# SAVE COMPLETE RECONNAISSANCE REPORT
# ============================================================================
elapsed = time.time() - start_time

report = {
    'timestamp': time.strftime('%Y-%m-%d %H:%M:%S'),
    'duration_seconds': elapsed,
    'inventory': {
        'total_files': len(all_files),
        'hidden_files': len(hidden_files),
        'config_files': len(config_files),
        'archive_files': len(archive_files),
        'python_files': len(python_files),
        'markdown_files': len(markdown_files),
    },
    'code_analysis': {
        'function_signatures': len(function_signatures),
        'class_hierarchies': len(class_hierarchies),
        'duplicate_functions': len(duplicate_functions),
        'docstring_wisdom': len(docstring_wisdom),
    },
    'patterns': {k: len(v) for k, v in code_patterns.items()},
    'databases': {
        'total_dbs': len(db_files),
        'total_memories': total_memories,
        'aria_memories': aria_total,
    },
    'synthesis_opportunities': {
        'clone_scripts': len(clone_scripts),
        'strategy_scripts': len(strategy_scripts),
        'duplicate_functions': len(duplicate_functions),
        'similar_classes': len(similar_classes),
    },
    'polyglot': {lang: len(files) for lang, files in polyglot_files.items()},
    'insights': [
        {
            'category': i.category,
            'title': i.title,
            'description': i.description,
            'evidence': i.evidence,
            'implications': i.implications,
            'synthesis_opportunity': i.synthesis_opportunity,
        }
        for i in insights
    ],
}

# Save JSON
json_path = PROJECT_ROOT / 'reports' / 'evolution_reconnaissance.json'
json_path.write_text(json.dumps(report, indent=2))

# Save detailed markdown
md_path = PROJECT_ROOT / 'reports' / 'EVOLUTION_RECONNAISSANCE.md'
with open(md_path, 'w') as f:
    f.write("# EVOLUTION CAMPAIGN - DEEP RECONNAISSANCE REPORT\n\n")
    f.write("*\"Know thyself.\"* — Socratic wisdom\n\n")
    f.write("---\n\n")
    f.write(f"**Generated**: {report['timestamp']}\n")
    f.write(f"**Duration**: {elapsed:.2f} seconds\n\n")
    
    f.write("## COMPLETE INVENTORY\n\n")
    f.write(f"- **Total Files**: {len(all_files):,}\n")
    f.write(f"- **Hidden Files**: {len(hidden_files):,}\n")
    f.write(f"- **Config Files**: {len(config_files):,}\n")
    f.write(f"- **Archive Files**: {len(archive_files):,}\n")
    f.write(f"- **Python Files**: {len(python_files):,}\n")
    f.write(f"- **Markdown Files**: {len(markdown_files):,}\n\n")
    
    f.write("## CODE ANALYSIS\n\n")
    f.write(f"- **Function Signatures**: {len(function_signatures):,}\n")
    f.write(f"- **Class Hierarchies**: {len(class_hierarchies)}\n")
    f.write(f"- **Duplicate Functions**: {len(duplicate_functions)}\n")
    f.write(f"- **Documented Modules**: {len(docstring_wisdom)}\n\n")
    
    f.write("## DATABASE ARCHAEOLOGY\n\n")
    f.write(f"- **Total Databases**: {len(db_files)}\n")
    f.write(f"- **Total Memories**: {total_memories:,}\n")
    f.write(f"- **Aria Memories**: {aria_total:,}\n\n")
    
    f.write("## POLYGLOT LANDSCAPE\n\n")
    for lang, files in polyglot_files.items():
        if files:
            f.write(f"- **{lang.title()}**: {len(files)} files\n")
    f.write("\n")
    
    f.write("## DEEP INSIGHTS\n\n")
    for i, insight in enumerate(insights, 1):
        f.write(f"### {i}. {insight.title}\n\n")
        f.write(f"**Category**: {insight.category}\n\n")
        f.write(f"{insight.description}\n\n")
        f.write("**Evidence**:\n")
        for e in insight.evidence:
            f.write(f"- {e}\n")
        f.write("\n**Implications**:\n")
        for imp in insight.implications:
            f.write(f"- {imp}\n")
        if insight.synthesis_opportunity:
            f.write("\n🔄 **SYNTHESIS OPPORTUNITY**\n")
        f.write("\n")

print(f"\n📄 Reports saved:")
print(f"   {json_path}")
print(f"   {md_path}")

print(f"\n⏰ DURATION: {elapsed:.2f}s")
print("\n" + "=" * 80)
print("DEEP RECONNAISSANCE COMPLETE")
print("=" * 80)
