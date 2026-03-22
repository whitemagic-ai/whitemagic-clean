#!/usr/bin/env python3
"""Final Gana Diagnostic - Test all 28 Ganas after fixes"""

import json
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.tools.unified_api import call_tool

# Test cases for each Gana (2 tools per Gana for comprehensive coverage)
GANA_TESTS = {
    "gana_horn": [
        ("session_status", {}),
        ("focus_session", {}),
    ],
    "gana_neck": [
        ("create_memory", {"content": "test", "title": "test", "tags": ["test"]}),
        ("update_memory", {"memory_id": "test", "updates": {"content": "updated"}}),
    ],
    "gana_root": [
        ("health_report", {}),
        ("rust_status", {}),
    ],
    "gana_room": [
        ("sandbox.status", {}),
        ("hermit.status", {}),
    ],
    "gana_heart": [
        ("context.status", {}),
        ("scratchpad", {}),
    ],
    "gana_tail": [
        ("simd.status", {}),
        ("list_cascade_patterns", {}),
    ],
    "gana_winnowing_basket": [
        ("search_memories", {"query": "test"}),
        ("vector.status", {}),
    ],
    "gana_ghost": [
        ("gnosis", {"compact": True}),
        ("capabilities", {}),
    ],
    "gana_willow": [
        ("rate_limiter.stats", {}),
        ("grimoire_list", {}),
    ],
    "gana_star": [
        ("governor_validate", {}),
        ("forge.status", {}),
    ],
    "gana_extended_net": [
        ("cluster_stats", {}),
        ("pattern_search", {"query": "test"}),
    ],
    "gana_wings": [
        ("mesh.status", {}),
        ("export_memories", {"format": "json"}),
    ],
    "gana_chariot": [
        ("archaeology_stats", {}),
        ("kg.status", {}),
    ],
    "gana_abundance": [
        ("dream_status", {}),
        ("memory.lifecycle_stats", {}),
    ],
    "gana_straddling_legs": [
        ("harmony_vector", {}),
        ("wu_xing_balance", {}),
    ],
    "gana_mound": [
        ("get_yin_yang_balance", {}),
        ("get_metrics_summary", {}),
    ],
    "gana_stomach": [
        ("task.list", {}),
        ("pipeline.list", {}),
    ],
    "gana_hairy_head": [
        ("anomaly.status", {}),
        ("karma_report", {}),
    ],
    "gana_net": [
        ("prompt.list", {}),
        ("karma.verify_chain", {}),
    ],
    "gana_turtle_beak": [
        ("edge_stats", {}),
        ("bitnet_status", {}),
    ],
    "gana_three_stars": [
        ("ensemble.status", {}),
        ("reasoning.bicameral", {"query": "test"}),
    ],
    "gana_dipper": [
        ("homeostasis.status", {}),
        ("starter_packs.list", {}),
    ],
    "gana_ox": [
        ("swarm.status", {}),
        ("worker.status", {}),
    ],
    "gana_girl": [
        ("agent.list", {}),
        ("agent.heartbeat", {"agent_id": "test"}),
    ],
    "gana_void": [
        ("galaxy.list", {}),
        ("galaxy.status", {}),
    ],
    "gana_roof": [
        ("ollama.models", {}),
        ("shelter.status", {}),
    ],
    "gana_encampment": [
        ("broker.status", {}),
        ("sangha_chat_read", {}),
    ],
    "gana_wall": [
        ("vote.list", {}),
        ("engagement.status", {}),
    ],
}

def test_gana(gana_name, tests):
    """Test a single Gana with its test cases."""
    results = {
        "gana": gana_name,
        "passed": 0,
        "failed": 0,
        "errors": [],
        "tools_tested": [],
    }

    for tool_name, args in tests:
        start = time.time()
        try:
            result = call_tool(tool_name, **args)
            latency = (time.time() - start) * 1000

            if isinstance(result, dict):
                status = result.get("status")
                if status == "success":
                    results["passed"] += 1
                    results["tools_tested"].append({
                        "tool": tool_name,
                        "status": "passed",
                        "latency_ms": round(latency, 1)
                    })
                    print(f"  ✓ {tool_name:40s} ({latency:6.1f}ms)")
                elif status == "error":
                    results["failed"] += 1
                    error_msg = result.get("message", result.get("error", "Unknown"))[:100]
                    results["errors"].append({
                        "tool": tool_name,
                        "error": error_msg
                    })
                    results["tools_tested"].append({
                        "tool": tool_name,
                        "status": "failed",
                        "error": error_msg
                    })
                    print(f"  ✗ {tool_name:40s} ERROR: {error_msg}")
                else:
                    # Unknown status
                    results["passed"] += 1
                    results["tools_tested"].append({
                        "tool": tool_name,
                        "status": "unknown",
                        "latency_ms": round(latency, 1)
                    })
                    print(f"  ? {tool_name:40s} ({latency:6.1f}ms) - status: {status}")
            else:
                results["passed"] += 1
                results["tools_tested"].append({
                    "tool": tool_name,
                    "status": "passed",
                    "latency_ms": round(latency, 1)
                })
                print(f"  ✓ {tool_name:40s} ({latency:6.1f}ms)")

        except Exception as e:
            results["failed"] += 1
            error_msg = str(e)[:100]
            results["errors"].append({
                "tool": tool_name,
                "error": error_msg
            })
            results["tools_tested"].append({
                "tool": tool_name,
                "status": "exception",
                "error": error_msg
            })
            print(f"  ✗ {tool_name:40s} EXCEPTION: {error_msg}")

    return results

def main():
    print("="*80)
    print("FINAL GANA DIAGNOSTIC - All 28 Ganas")
    print("="*80)
    print()

    all_results = []
    total_passed = 0
    total_failed = 0

    for gana_name in sorted(GANA_TESTS.keys()):
        print(f"\n{'='*80}")
        print(f"Testing {gana_name}")
        print("="*80)

        tests = GANA_TESTS[gana_name]
        results = test_gana(gana_name, tests)
        all_results.append(results)

        total_passed += results["passed"]
        total_failed += results["failed"]

        pass_rate = (results["passed"] / (results["passed"] + results["failed"]) * 100) if (results["passed"] + results["failed"]) > 0 else 0
        print(f"\n{gana_name}: {results['passed']}/{results['passed'] + results['failed']} passed ({pass_rate:.1f}%)")

    # Summary
    print("\n" + "="*80)
    print("FINAL SUMMARY")
    print("="*80)

    total_tests = total_passed + total_failed
    overall_pass_rate = (total_passed / total_tests * 100) if total_tests > 0 else 0

    print(f"\nTotal Tests: {total_tests}")
    print(f"Passed: {total_passed}")
    print(f"Failed: {total_failed}")
    print(f"Pass Rate: {overall_pass_rate:.1f}%")

    # Gana-level summary
    print("\nGana-level Results:")
    for result in all_results:
        total = result["passed"] + result["failed"]
        rate = (result["passed"] / total * 100) if total > 0 else 0
        status = "✓" if result["failed"] == 0 else "✗"
        print(f"  {status} {result['gana']:30s} {result['passed']}/{total} ({rate:5.1f}%)")

    # Failed tools
    if total_failed > 0:
        print(f"\nFailed Tools ({total_failed}):")
        for result in all_results:
            if result["errors"]:
                print(f"\n  {result['gana']}:")
                for error in result["errors"]:
                    print(f"    - {error['tool']}: {error['error']}")

    # Save report
    report_file = Path(__file__).parent.parent / "reports" / "final_gana_diagnostic.json"
    with open(report_file, 'w') as f:
        json.dump({
            "summary": {
                "total_tests": total_tests,
                "passed": total_passed,
                "failed": total_failed,
                "pass_rate": overall_pass_rate
            },
            "ganas": all_results
        }, f, indent=2)

    print(f"\n✓ Report saved to: {report_file}")

    # Exit code based on pass rate
    if overall_pass_rate >= 95:
        return 0
    elif overall_pass_rate >= 75:
        return 1
    else:
        return 2

if __name__ == "__main__":
    sys.exit(main())
