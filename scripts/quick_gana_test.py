#!/usr/bin/env python3
"""Quick Gana Test - Fast diagnostic for all 28 Ganas"""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.tools.unified_api import call_tool

# Test one tool per Gana
tests = [
    ("gana_horn", "session_status", {}),
    ("gana_neck", "create_memory", {"content": "test", "title": "test", "tags": ["test"]}),
    ("gana_root", "health_report", {}),
    ("gana_room", "sandbox.status", {}),
    ("gana_heart", "context.status", {}),
    ("gana_tail", "simd.status", {}),
    ("gana_winnowing_basket", "vector.status", {}),
    ("gana_ghost", "gnosis", {"compact": True}),
    ("gana_willow", "rate_limiter.stats", {}),
    ("gana_star", "governor_validate", {}),
    ("gana_extended_net", "cluster_stats", {}),
    ("gana_wings", "mesh.status", {}),
    ("gana_chariot", "archaeology_stats", {}),
    ("gana_abundance", "dream_status", {}),
    ("gana_straddling_legs", "harmony_vector", {}),
    ("gana_mound", "get_yin_yang_balance", {}),
    ("gana_stomach", "task.list", {}),
    ("gana_hairy_head", "anomaly.status", {}),
    ("gana_net", "prompt.list", {}),
    ("gana_turtle_beak", "edge_stats", {}),
    ("gana_three_stars", "ensemble.status", {}),
    ("gana_dipper", "homeostasis.status", {}),
    ("gana_ox", "swarm.status", {}),
    ("gana_girl", "agent.list", {}),
    ("gana_void", "galaxy.list", {}),
    ("gana_roof", "ollama.models", {}),
    ("gana_encampment", "broker.status", {}),
    ("gana_wall", "vote.list", {}),
]

passed = 0
failed = 0
errors = []

for gana, tool, args in tests:
    try:
        result = call_tool(tool, **args)
        if isinstance(result, dict) and result.get("status") == "error":
            failed += 1
            errors.append(f"{gana}.{tool}: {result.get('error', 'Unknown')[:80]}")
            print(f"✗ {gana:30s} {tool:30s} ERROR")
        else:
            passed += 1
            print(f"✓ {gana:30s} {tool:30s} OK")
    except Exception as e:
        failed += 1
        errors.append(f"{gana}.{tool}: {str(e)[:80]}")
        print(f"✗ {gana:30s} {tool:30s} EXCEPTION: {str(e)[:50]}")

print(f"\n{'='*80}")
print(f"RESULTS: {passed}/{len(tests)} passed ({passed/len(tests)*100:.1f}%)")
print(f"{'='*80}")

if errors:
    print(f"\nERRORS ({len(errors)}):")
    for err in errors[:10]:
        print(f"  - {err}")
    if len(errors) > 10:
        print(f"  ... and {len(errors)-10} more")

sys.exit(0 if failed == 0 else 1)
