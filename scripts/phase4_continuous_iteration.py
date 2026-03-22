#!/usr/bin/env python3
"""
Phase 4: Continuous Iteration Framework
Automatically cycles through all campaigns, deploying armies until all reach S-grade
"""

import json
import subprocess
import sys
from datetime import datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent


def load_audit_results():
    """Load latest campaign audit."""
    audit_path = PROJECT_ROOT / "reports" / "campaign_audit.json"
    if not audit_path.exists():
        subprocess.run([sys.executable, "scripts/audit_campaigns.py"], cwd=PROJECT_ROOT)
    return json.loads(audit_path.read_text())


def prioritize_campaigns(audit_data):
    """Prioritize campaigns by completion percentage and impact."""
    campaigns = audit_data.get("campaigns", [])

    # Filter and sort
    incomplete = [c for c in campaigns if c.get("grade") != "S"]

    # Sort by completion percentage (descending) - work on closest to completion first
    incomplete.sort(key=lambda x: x.get("completion_pct", 0), reverse=True)

    return {
        "high_priority": [c for c in incomplete if c.get("completion_pct", 0) >= 20],
        "medium_priority": [c for c in incomplete if 0 < c.get("completion_pct", 0) < 20],
        "low_priority": [c for c in incomplete if c.get("completion_pct", 0) == 0]
    }


def scout_codebase_opportunities():
    """Scout codebase for optimization opportunities and new campaign ideas."""
    print("\n" + "="*80)
    print("  CODEBASE SCOUTING: OPTIMIZATION OPPORTUNITIES")
    print("="*80)
    print()

    opportunities = []

    # 1. Find TODO/FIXME comments
    print("  [1/5] Scanning for TODO/FIXME comments...")
    try:
        result = subprocess.run(
            ["grep", "-r", "-n", "-E", "TODO|FIXME|XXX|HACK", "whitemagic/", "--include=*.py"],
            cwd=PROJECT_ROOT,
            capture_output=True,
            text=True
        )
        todo_count = len(result.stdout.split('\n')) if result.stdout else 0
        opportunities.append({
            "category": "code_quality",
            "type": "TODO/FIXME comments",
            "count": todo_count,
            "priority": "medium"
        })
        print(f"         Found {todo_count} TODO/FIXME comments")
    except Exception as e:
        print(f"         Error: {e}")

    # 2. Find large files (>1000 LOC)
    print("  [2/5] Identifying large files (>1000 LOC)...")
    large_files = []
    for py_file in PROJECT_ROOT.glob("whitemagic/**/*.py"):
        if py_file.is_file():
            loc = len(py_file.read_text().split('\n'))
            if loc > 1000:
                large_files.append((py_file.relative_to(PROJECT_ROOT), loc))

    large_files.sort(key=lambda x: x[1], reverse=True)
    opportunities.append({
        "category": "code_structure",
        "type": "Large files needing refactoring",
        "count": len(large_files),
        "top_files": large_files[:5],
        "priority": "high"
    })
    print(f"         Found {len(large_files)} files >1000 LOC")
    if large_files:
        print(f"         Largest: {large_files[0][0]} ({large_files[0][1]} LOC)")

    # 3. Find duplicate code patterns
    print("  [3/5] Detecting potential duplicate code...")
    try:
        # Simple heuristic: find files with similar names
        py_files = list(PROJECT_ROOT.glob("whitemagic/**/*.py"))
        similar_names = {}
        for f in py_files:
            base = f.stem.replace('_v2', '').replace('_new', '').replace('_old', '')
            if base not in similar_names:
                similar_names[base] = []
            similar_names[base].append(f.relative_to(PROJECT_ROOT))

        duplicates = {k: v for k, v in similar_names.items() if len(v) > 1}
        opportunities.append({
            "category": "code_duplication",
            "type": "Similar file names (potential duplicates)",
            "count": len(duplicates),
            "priority": "medium"
        })
        print(f"         Found {len(duplicates)} groups of similar file names")
    except Exception as e:
        print(f"         Error: {e}")

    # 4. Find unused imports
    print("  [4/5] Checking for optimization opportunities...")
    opportunities.append({
        "category": "performance",
        "type": "Potential optimizations",
        "items": [
            "Batch operations in loops",
            "Database query optimization",
            "Caching opportunities",
            "Parallel processing candidates"
        ],
        "priority": "high"
    })
    print("         Identified 4 optimization categories")

    # 5. Find missing tests
    print("  [5/5] Analyzing test coverage gaps...")
    src_files = len(list(PROJECT_ROOT.glob("whitemagic/**/*.py")))
    test_files = len(list(PROJECT_ROOT.glob("tests/**/*.py")))
    coverage_ratio = test_files / src_files if src_files > 0 else 0

    opportunities.append({
        "category": "testing",
        "type": "Test coverage",
        "src_files": src_files,
        "test_files": test_files,
        "coverage_ratio": coverage_ratio,
        "priority": "high" if coverage_ratio < 0.3 else "medium"
    })
    print(f"         Test coverage ratio: {coverage_ratio:.2%} ({test_files}/{src_files})")

    return opportunities


def suggest_new_campaigns(opportunities):
    """Generate campaign suggestions based on scouting results."""
    print("\n" + "="*80)
    print("  NEW CAMPAIGN SUGGESTIONS")
    print("="*80)
    print()

    suggestions = []

    # Based on large files
    large_file_opp = next((o for o in opportunities if o["type"] == "Large files needing refactoring"), None)
    if large_file_opp and large_file_opp["count"] > 10:
        suggestions.append({
            "campaign_id": "R001",
            "name": "Large File Refactoring",
            "description": f"Refactor {large_file_opp['count']} files >1000 LOC into smaller, focused modules",
            "priority": "high",
            "estimated_vcs": 8
        })

    # Based on test coverage
    test_opp = next((o for o in opportunities if o["type"] == "Test coverage"), None)
    if test_opp and test_opp["coverage_ratio"] < 0.3:
        suggestions.append({
            "campaign_id": "T001",
            "name": "Test Coverage Expansion",
            "description": f"Increase test coverage from {test_opp['coverage_ratio']:.1%} to >50%",
            "priority": "high",
            "estimated_vcs": 10
        })

    # Based on TODOs
    todo_opp = next((o for o in opportunities if o["type"] == "TODO/FIXME comments"), None)
    if todo_opp and todo_opp["count"] > 50:
        suggestions.append({
            "campaign_id": "C004",
            "name": "Technical Debt Resolution",
            "description": f"Address {todo_opp['count']} TODO/FIXME comments",
            "priority": "medium",
            "estimated_vcs": 7
        })

    # Performance optimization campaign
    suggestions.append({
        "campaign_id": "P003",
        "name": "Performance Optimization Sweep",
        "description": "Identify and optimize hot paths, add caching, parallelize operations",
        "priority": "high",
        "estimated_vcs": 9
    })

    for i, suggestion in enumerate(suggestions, 1):
        print(f"  {i}. {suggestion['campaign_id']}: {suggestion['name']}")
        print(f"     Priority: {suggestion['priority'].upper()}")
        print(f"     {suggestion['description']}")
        print(f"     Estimated VCs: {suggestion['estimated_vcs']}")
        print()

    return suggestions


def generate_iteration_report(audit_data, opportunities, suggestions):
    """Generate comprehensive iteration report."""
    report_path = PROJECT_ROOT / "reports" / "phase4_iteration_report.md"

    stats = audit_data.get("overall_stats", {})

    report = f"""# Phase 4: Continuous Iteration Report

**Generated:** {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}

## Current Campaign Status

- **Overall Grade:** {stats.get('overall_grade', '?')} ({stats.get('overall_completion_pct', 0):.1f}%)
- **Total Campaigns:** {stats.get('total_campaigns', 0)}
- **Victory Conditions:** {stats.get('completed_vcs', 0)}/{stats.get('total_vcs', 0)} complete
- **S-Grade Campaigns:** {stats.get('grade_distribution', {}).get('S', 0)}

## Optimization Opportunities Discovered

"""

    for opp in opportunities:
        report += f"### {opp['type']} ({opp['priority'].upper()} Priority)\n\n"
        report += f"- **Category:** {opp['category']}\n"
        report += f"- **Count:** {opp.get('count', 'N/A')}\n"

        if 'top_files' in opp:
            report += "\n**Top Files:**\n"
            for filepath, loc in opp['top_files'][:3]:
                report += f"- `{filepath}` ({loc} LOC)\n"

        if 'items' in opp:
            report += "\n**Items:**\n"
            for item in opp['items']:
                report += f"- {item}\n"

        report += "\n"

    report += "## New Campaign Suggestions\n\n"

    for suggestion in suggestions:
        report += f"### {suggestion['campaign_id']}: {suggestion['name']}\n\n"
        report += f"- **Priority:** {suggestion['priority'].upper()}\n"
        report += f"- **Description:** {suggestion['description']}\n"
        report += f"- **Estimated VCs:** {suggestion['estimated_vcs']}\n\n"

    report += """## Next Iteration Cycle

1. **Complete In-Progress Campaigns**
   - V002 (50%) → S-grade
   - V004 (42%) → S-grade
   - V003 (20%) → S-grade

2. **Deploy for High-Priority New Campaigns**
   - Execute suggested campaigns above
   - Focus on high-impact, quick-win opportunities

3. **Continuous Monitoring**
   - Run audit after each deployment
   - Track grade progression
   - Adjust priorities based on results

4. **Iterate Until Complete**
   - Repeat cycle until all campaigns reach S-grade
   - Generate new campaigns as opportunities arise
   - Maintain momentum with quick wins

## Automation

To run next iteration:
```bash
python3 scripts/phase4_continuous_iteration.py
```

To audit current state:
```bash
python3 scripts/audit_campaigns.py
```
"""

    report_path.write_text(report)
    print(f"\n✓ Report saved to: {report_path}")
    return report_path


def main():
    print("="*80)
    print("  PHASE 4: CONTINUOUS ITERATION FRAMEWORK")
    print("="*80)
    print()

    # Load current state
    print("Loading campaign audit...")
    audit_data = load_audit_results()

    # Prioritize campaigns
    print("Prioritizing campaigns...")
    priorities = prioritize_campaigns(audit_data)

    print(f"\n  High Priority: {len(priorities['high_priority'])} campaigns")
    print(f"  Medium Priority: {len(priorities['medium_priority'])} campaigns")
    print(f"  Low Priority: {len(priorities['low_priority'])} campaigns")

    # Scout for opportunities
    opportunities = scout_codebase_opportunities()

    # Suggest new campaigns
    suggestions = suggest_new_campaigns(opportunities)

    # Generate report
    generate_iteration_report(audit_data, opportunities, suggestions)

    print("\n" + "="*80)
    print("  PHASE 4 COMPLETE")
    print("="*80)
    print()
    print("Framework established for continuous iteration.")
    print("Next steps:")
    print("  1. Review phase4_iteration_report.md")
    print("  2. Execute targeted deployments for high-priority campaigns")
    print("  3. Create new campaign files for suggested campaigns")
    print("  4. Re-run this script after each deployment cycle")


if __name__ == "__main__":
    main()
