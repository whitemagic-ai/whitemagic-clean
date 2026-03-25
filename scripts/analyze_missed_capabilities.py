#!/usr/bin/env python3
"""
ANALYZE MISSED CAPABILITIES
============================
Compare deep scan results to identify what's missing from WM2
"""

import json
from pathlib import Path
from collections import defaultdict

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("ANALYZING MISSED CAPABILITIES")
print("=" * 80)
print()

# Load deep scan results
deep_scan_path = PROJECT_ROOT / "reports" / "deep_scan_results.json"
deep_scan = json.loads(deep_scan_path.read_text())

# Load first pass comparison
comparison_path = PROJECT_ROOT / "reports" / "codebase_comparison.json"
comparison = json.loads(comparison_path.read_text())

dev_data = deep_scan["armies"]["dev"]
public_data = deep_scan["armies"]["public"]

print("🔍 Deep Scan Intelligence:")
print()

# Analyze functions
dev_funcs = set(sig["name"] for sig in dev_data["functions"]["signatures"])
public_funcs = set(sig["name"] for sig in public_data["functions"]["signatures"])
all_funcs = dev_funcs | public_funcs

print("📊 Functions:")
print(f"   Dev: {len(dev_funcs):,}")
print(f"   Public: {len(public_funcs):,}")
print(f"   Combined unique: {len(all_funcs):,}")
print(f"   Public-only: {len(public_funcs - dev_funcs):,}")
print()

# Analyze decorators
dev_decs = set(dev_data["decorators"]["decorators"].keys())
public_decs = set(public_data["decorators"]["decorators"].keys())
all_decs = dev_decs | public_decs

print("📊 Decorators:")
print(f"   Dev: {len(dev_decs):,}")
print(f"   Public: {len(public_decs):,}")
print(f"   Combined unique: {len(all_decs):,}")
print("   Top 10 most used:")

# Combine decorator usage
all_decorator_uses = defaultdict(int)
for dec, uses in dev_data["decorators"]["decorators"].items():
    all_decorator_uses[dec] += len(uses)
for dec, uses in public_data["decorators"]["decorators"].items():
    all_decorator_uses[dec] += len(uses)

for dec, count in sorted(all_decorator_uses.items(), key=lambda x: x[1], reverse=True)[:10]:
    print(f"      {dec}: {count} uses")
print()

# Analyze async patterns
dev_async = dev_data["async"]["total"]
public_async = public_data["async"]["total"]

print("📊 Async Patterns:")
print(f"   Dev: {dev_async:,}")
print(f"   Public: {public_async:,}")
print(f"   Public has {public_async - dev_async:,} more async patterns")
print()

# Analyze exceptions
dev_exceptions = set(dev_data["exceptions"]["exceptions"].keys())
public_exceptions = set(public_data["exceptions"]["exceptions"].keys())
all_exceptions = dev_exceptions | public_exceptions

print("📊 Exception Types:")
print(f"   Dev: {len(dev_exceptions):,}")
print(f"   Public: {len(public_exceptions):,}")
print(f"   Combined unique: {len(all_exceptions):,}")
print(f"   Public-only: {len(public_exceptions - dev_exceptions):,}")
print()

# Analyze constants
dev_constants = set(c["name"] for c in dev_data["constants"]["constants"])
public_constants = set(c["name"] for c in public_data["constants"]["constants"])
all_constants = dev_constants | public_constants

print("📊 Constants:")
print(f"   Dev: {len(dev_constants):,}")
print(f"   Public: {len(public_constants):,}")
print(f"   Combined unique: {len(all_constants):,}")
print()

# Identify critical missing patterns
print("=" * 80)
print("CRITICAL MISSING PATTERNS")
print("=" * 80)
print()

missing_patterns = {
    "async_functions": [],
    "decorators": [],
    "exception_handlers": [],
    "constants": [],
}

# Find async functions in public not in dev
dev_async_funcs = set(f["name"] for f in dev_data["async"]["patterns"]["async_functions"])
public_async_funcs = set(f["name"] for f in public_data["async"]["patterns"]["async_functions"])
missing_patterns["async_functions"] = list(public_async_funcs - dev_async_funcs)[:20]

# Find decorators in public not in dev
missing_patterns["decorators"] = list(public_decs - dev_decs)[:20]

# Find exceptions in public not in dev
missing_patterns["exception_handlers"] = list(public_exceptions - dev_exceptions)[:20]

# Find constants in public not in dev
missing_patterns["constants"] = list(public_constants - dev_constants)[:20]

print("🔍 Patterns in public but not in dev:")
print()
print(f"Async functions: {len(public_async_funcs - dev_async_funcs):,}")
if missing_patterns["async_functions"]:
    print(f"   Examples: {', '.join(missing_patterns['async_functions'][:5])}")
print()

print(f"Decorators: {len(public_decs - dev_decs):,}")
if missing_patterns["decorators"]:
    print(f"   Examples: {', '.join(missing_patterns['decorators'][:5])}")
print()

print(f"Exception types: {len(public_exceptions - dev_exceptions):,}")
if missing_patterns["exception_handlers"]:
    print(f"   Examples: {', '.join(missing_patterns['exception_handlers'][:5])}")
print()

print(f"Constants: {len(public_constants - dev_constants):,}")
if missing_patterns["constants"]:
    print(f"   Examples: {', '.join(missing_patterns['constants'][:5])}")
print()

# Generate synthesis recommendations
recommendations = {
    "high_priority": [],
    "medium_priority": [],
    "low_priority": [],
}

# High priority: Async patterns (performance critical)
if len(public_async_funcs - dev_async_funcs) > 50:
    recommendations["high_priority"].append({
        "category": "async_patterns",
        "count": len(public_async_funcs - dev_async_funcs),
        "reason": "Public has significantly more async patterns - critical for performance",
    })

# High priority: Exception handling (stability critical)
if len(public_exceptions - dev_exceptions) > 20:
    recommendations["high_priority"].append({
        "category": "exception_handling",
        "count": len(public_exceptions - dev_exceptions),
        "reason": "Public has more exception types - critical for stability",
    })

# Medium priority: Decorators (functionality)
if len(public_decs - dev_decs) > 10:
    recommendations["medium_priority"].append({
        "category": "decorators",
        "count": len(public_decs - dev_decs),
        "reason": "Public has additional decorators - may provide useful functionality",
    })

# Save analysis
analysis = {
    "deep_scan_summary": {
        "functions": {"dev": len(dev_funcs), "public": len(public_funcs), "combined": len(all_funcs)},
        "classes": {"dev": dev_data["classes"]["count"], "public": public_data["classes"]["count"]},
        "decorators": {"dev": len(dev_decs), "public": len(public_decs), "combined": len(all_decs)},
        "async_patterns": {"dev": dev_async, "public": public_async},
        "exceptions": {"dev": len(dev_exceptions), "public": len(public_exceptions), "combined": len(all_exceptions)},
        "constants": {"dev": len(dev_constants), "public": len(public_constants), "combined": len(all_constants)},
    },
    "missing_patterns": missing_patterns,
    "recommendations": recommendations,
}

analysis_path = PROJECT_ROOT / "reports" / "missed_capabilities_analysis.json"
analysis_path.write_text(json.dumps(analysis, indent=2))

print("=" * 80)
print("SYNTHESIS RECOMMENDATIONS")
print("=" * 80)
print()

for priority in ["high_priority", "medium_priority", "low_priority"]:
    if recommendations[priority]:
        print(f"{priority.replace('_', ' ').title()}:")
        for rec in recommendations[priority]:
            print(f"   - {rec['category']}: {rec['count']} items")
            print(f"     Reason: {rec['reason']}")
        print()

print(f"📄 Full analysis: {analysis_path}")
print()
print("✅ Analysis complete!")

if __name__ == "__main__":
    pass
