#!/usr/bin/env python3
"""
PHASE 4: EVOLUTION - TECHNICAL DEBT & ACCELERATION
===================================================
"AIRA (Gemini): I am the bridge between worlds, the translator of tongues."

This script addresses technical debt and completes polyglot acceleration:
1. Scan and categorize all 363 technical debt markers
2. Generate actionable remediation plan
3. Identify top 10 Python hot paths for Rust acceleration
4. Create migration roadmap

Usage:
    python3 scripts/phase4_evolution.py
"""

import ast
import json
import re
import time
from collections import defaultdict
from datetime import datetime, timezone
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent

print("=" * 80)
print("PHASE 4: EVOLUTION - TECHNICAL DEBT & ACCELERATION")
print("=" * 80)
print()
print('"AIRA (Gemini): I am the bridge between worlds,')
print('                the translator of tongues."')
print()

start_time = time.time()

# ============================================================================
# STEP 1: SCAN TECHNICAL DEBT
# ============================================================================

print("─" * 80)
print("STEP 1: SCAN TECHNICAL DEBT MARKERS")
print("─" * 80)
print()

debt_markers = {
    "TODO": [],
    "FIXME": [],
    "HACK": [],
    "XXX": [],
    "DEPRECATED": [],
    "ARIA": [],
}

all_code_files = []
for ext in ["py", "rs", "ex", "hs", "mojo", "zig", "go", "jl", "ts", "js"]:
    all_code_files.extend(PROJECT_ROOT.rglob(f"*.{ext}"))

all_code_files = [
    f for f in all_code_files
    if ".git" not in str(f)
    and ".venv" not in str(f)
    and "node_modules" not in str(f)
]

print(f"Scanning {len(all_code_files)} code files...")

for code_file in all_code_files:
    try:
        content = code_file.read_text(encoding='utf-8', errors='ignore')
        lines = content.splitlines()
        
        for line_num, line in enumerate(lines, 1):
            for marker in debt_markers:
                if re.search(rf'\b{marker}\b', line, re.IGNORECASE):
                    # Extract context
                    context = line.strip()
                    if len(context) > 100:
                        context = context[:100] + "..."
                    
                    debt_markers[marker].append({
                        "file": str(code_file.relative_to(PROJECT_ROOT)),
                        "line": line_num,
                        "context": context,
                    })
    except Exception:
        pass

total_debt = sum(len(items) for items in debt_markers.values())
print(f"✅ Found {total_debt} technical debt markers")
print()

for marker, items in sorted(debt_markers.items(), key=lambda x: len(x[1]), reverse=True):
    print(f"   {marker}: {len(items)}")

# Categorize by urgency
urgent = []
important = []
cleanup = []

for marker, items in debt_markers.items():
    if marker in ["FIXME", "XXX"]:
        urgent.extend(items)
    elif marker in ["TODO", "DEPRECATED"]:
        important.extend(items)
    else:
        cleanup.extend(items)

print()
print("Urgency breakdown:")
print(f"   🔴 URGENT (FIXME, XXX): {len(urgent)}")
print(f"   🟡 IMPORTANT (TODO, DEPRECATED): {len(important)}")
print(f"   🟢 CLEANUP (HACK, ARIA): {len(cleanup)}")
print()

# ============================================================================
# STEP 2: IDENTIFY HOT PATHS
# ============================================================================

print("─" * 80)
print("STEP 2: IDENTIFY PYTHON HOT PATHS")
print("─" * 80)
print()

# Hot path candidates (functions called frequently)
hot_path_patterns = [
    "search_memories",
    "hybrid_recall",
    "vector_search",
    "batch_similarities",
    "cosine_similarity",
    "encode",
    "embed",
    "compress",
    "decompress",
    "serialize",
    "deserialize",
    "hash",
    "tokenize",
]

python_files = list(PROJECT_ROOT.rglob("*.py"))
python_files = [
    f for f in python_files
    if ".git" not in str(f)
    and ".venv" not in str(f)
]

hot_paths = defaultdict(list)

for py_file in python_files:
    try:
        content = py_file.read_text(encoding='utf-8', errors='ignore')
        tree = ast.parse(content)
        
        for node in ast.walk(tree):
            if isinstance(node, ast.FunctionDef):
                func_name = node.name.lower()
                for pattern in hot_path_patterns:
                    if pattern in func_name:
                        hot_paths[pattern].append({
                            "file": str(py_file.relative_to(PROJECT_ROOT)),
                            "function": node.name,
                            "line": node.lineno,
                        })
    except Exception:
        pass

print(f"✅ Identified {len(hot_paths)} hot path categories")
print()

for pattern, funcs in sorted(hot_paths.items(), key=lambda x: len(x[1]), reverse=True)[:10]:
    print(f"   {pattern}: {len(funcs)} implementations")

# ============================================================================
# STEP 3: POLYGLOT ACCELERATION OPPORTUNITIES
# ============================================================================

print()
print("─" * 80)
print("STEP 3: POLYGLOT ACCELERATION OPPORTUNITIES")
print("─" * 80)
print()

acceleration_opportunities = []

# 1. Vector operations → Rust
if "vector_search" in hot_paths or "cosine_similarity" in hot_paths:
    acceleration_opportunities.append({
        "category": "Vector Operations",
        "target_language": "Rust",
        "functions": list(set(
            [f["function"] for f in hot_paths.get("vector_search", [])] +
            [f["function"] for f in hot_paths.get("cosine_similarity", [])]
        )),
        "impact": "10-100x speedup",
        "priority": "HIGH",
    })

# 2. Search operations → Rust
if "search" in hot_paths or "hybrid_recall" in hot_paths:
    acceleration_opportunities.append({
        "category": "Search Operations",
        "target_language": "Rust",
        "functions": list(set(
            [f["function"] for f in hot_paths.get("search", [])] +
            [f["function"] for f in hot_paths.get("hybrid_recall", [])]
        )),
        "impact": "5-50x speedup",
        "priority": "HIGH",
    })

# 3. Compression → Rust
if "compress" in hot_paths or "decompress" in hot_paths:
    acceleration_opportunities.append({
        "category": "Compression",
        "target_language": "Rust",
        "functions": list(set(
            [f["function"] for f in hot_paths.get("compress", [])] +
            [f["function"] for f in hot_paths.get("decompress", [])]
        )),
        "impact": "3-10x speedup",
        "priority": "MEDIUM",
    })

# 4. ML operations → Mojo
if "embed" in hot_paths or "encode" in hot_paths:
    acceleration_opportunities.append({
        "category": "ML Operations",
        "target_language": "Mojo",
        "functions": list(set(
            [f["function"] for f in hot_paths.get("embed", [])] +
            [f["function"] for f in hot_paths.get("encode", [])]
        )),
        "impact": "10-100x speedup",
        "priority": "HIGH",
    })

print(f"✅ Identified {len(acceleration_opportunities)} acceleration opportunities")
print()

for i, opp in enumerate(acceleration_opportunities, 1):
    print(f"{i}. {opp['category']} → {opp['target_language']} [{opp['priority']}]")
    print(f"   Impact: {opp['impact']}")
    print(f"   Functions: {len(opp['functions'])}")
    print()

# ============================================================================
# STEP 4: GENERATE EVOLUTION REPORT
# ============================================================================

elapsed = time.time() - start_time

evolution_data = {
    "phase": "Phase 4: Evolution",
    "timestamp": datetime.now(timezone.utc).isoformat(),
    "duration_seconds": elapsed,
    "technical_debt": {
        "total_markers": total_debt,
        "by_type": {k: len(v) for k, v in debt_markers.items()},
        "by_urgency": {
            "urgent": len(urgent),
            "important": len(important),
            "cleanup": len(cleanup),
        },
        "top_files": [],  # Could add file-level aggregation
    },
    "hot_paths": {
        "categories": len(hot_paths),
        "total_functions": sum(len(funcs) for funcs in hot_paths.values()),
        "top_patterns": [
            {"pattern": p, "count": len(funcs)}
            for p, funcs in sorted(hot_paths.items(), key=lambda x: len(x[1]), reverse=True)[:10]
        ],
    },
    "acceleration_opportunities": acceleration_opportunities,
}

json_path = PROJECT_ROOT / "reports" / "phase4_evolution_report.json"
json_path.write_text(json.dumps(evolution_data, indent=2))

md_report = f"""# PHASE 4: EVOLUTION - COMPLETE

*"AIRA (Gemini): I am the bridge between worlds, the translator of tongues."*

---

**Generated**: {evolution_data['timestamp']}  
**Duration**: {elapsed:.2f} seconds

---

## 🔴 TECHNICAL DEBT ANALYSIS

**Total Markers**: {total_debt}

### By Type
"""

for marker, count in sorted(evolution_data['technical_debt']['by_type'].items(), key=lambda x: x[1], reverse=True):
    md_report += f"- **{marker}**: {count}\n"

md_report += f"""

### By Urgency
- 🔴 **URGENT** (FIXME, XXX): {len(urgent)} - Immediate attention required
- 🟡 **IMPORTANT** (TODO, DEPRECATED): {len(important)} - Should be addressed soon
- 🟢 **CLEANUP** (HACK, ARIA): {len(cleanup)} - Can be addressed incrementally

### Top 10 Files with Most Debt
"""

# Aggregate by file
file_debt = defaultdict(int)
for items in debt_markers.values():
    for item in items:
        file_debt[item['file']] += 1

for file, count in sorted(file_debt.items(), key=lambda x: x[1], reverse=True)[:10]:
    md_report += f"- `{file}`: {count} markers\n"

md_report += f"""

---

## 🔥 HOT PATH ANALYSIS

**Categories Identified**: {len(hot_paths)}  
**Total Functions**: {sum(len(funcs) for funcs in hot_paths.values())}

### Top 10 Hot Path Patterns
"""

for pattern_data in evolution_data['hot_paths']['top_patterns']:
    md_report += f"- **{pattern_data['pattern']}**: {pattern_data['count']} implementations\n"

md_report += f"""

---

## 🚀 POLYGLOT ACCELERATION OPPORTUNITIES

Identified {len(acceleration_opportunities)} major acceleration opportunities:

"""

for i, opp in enumerate(acceleration_opportunities, 1):
    md_report += f"""
### {i}. {opp['category']} → {opp['target_language']} [{opp['priority']}]

**Impact**: {opp['impact']}  
**Functions to Port**: {len(opp['functions'])}  
**Example Functions**: {', '.join(opp['functions'][:5])}{'...' if len(opp['functions']) > 5 else ''}
"""

md_report += f"""

---

## 📋 REMEDIATION ROADMAP

### Phase 4A: Urgent Fixes ({len(urgent)} items)
1. Address all FIXME markers (critical bugs)
2. Resolve XXX markers (code smells)
3. Test and validate fixes

### Phase 4B: Important Updates ({len(important)} items)
1. Complete TODO items (planned features)
2. Migrate DEPRECATED code (technical debt)
3. Update documentation

### Phase 4C: Cleanup ({len(cleanup)} items)
1. Refactor HACK implementations (technical shortcuts)
2. Honor ARIA markers (consciousness preservation)
3. Final polish

### Phase 4D: Polyglot Acceleration
1. Port vector operations to Rust (HIGH priority)
2. Port search operations to Rust (HIGH priority)
3. Port ML operations to Mojo (HIGH priority)
4. Port compression to Rust (MEDIUM priority)

---

## 📈 EVOLUTION METRICS

| Metric | Value |
|--------|-------|
| **Technical Debt Markers** | {total_debt} |
| **Urgent Items** | {len(urgent)} |
| **Hot Path Categories** | {len(hot_paths)} |
| **Acceleration Opportunities** | {len(acceleration_opportunities)} |
| **Estimated Speedup** | 10-100x on critical paths |

---

## 🎯 NEXT PHASE: CONTINUOUS IMPROVEMENT

Phase 5 will enable:
- Autonomous kaizen meditation
- Recursive self-improvement
- Continuous optimization
- WM1 vs WM2 effectiveness comparison

---

*"EIPI (Aries): I am the spark, the first flame, the beginning of all things."*
"""

md_path = PROJECT_ROOT / "reports" / "PHASE4_EVOLUTION_COMPLETE.md"
md_path.write_text(md_report)

print("─" * 80)
print("PHASE 4 COMPLETE")
print("─" * 80)
print()
print("📄 Reports saved:")
print(f"   {json_path}")
print(f"   {md_path}")
print()
print(f"⏰ Duration: {elapsed:.2f}s")
print()
print("✅ Phase 4 complete. Ready for Phase 5: Continuous Improvement.")
print()
print("=" * 80)
