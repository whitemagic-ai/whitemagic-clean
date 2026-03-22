#!/usr/bin/env python3
"""Comprehensive Test of All 28 Ganas - Sequential & Parallel Execution

Tests all 28 Ganas with multiple tools each, analyzes patterns, and tests parallel execution.
"""

import json
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from typing import Any

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.tools.unified_api import call_tool

# Comprehensive test cases for all 28 Ganas (3-5 tools per Gana)
GANA_TEST_SUITE = {
    "gana_horn": [
        ("session_status", {}),
        ("focus_session", {}),
        ("create_session", {"session_id": "test_session"}),
        ("checkpoint_session", {}),
    ],
    "gana_neck": [
        ("create_memory", {"content": "test memory", "title": "test", "tags": ["test"]}),
        ("search_memories", {"query": "test"}),
        ("update_memory", {"memory_id": "test_id", "updates": {"content": "updated"}}),
    ],
    "gana_root": [
        ("health_report", {}),
        ("rust_status", {}),
        ("state.summary", {}),
    ],
    "gana_room": [
        ("sandbox.status", {}),
        ("hermit.status", {}),
        ("security.monitor_status", {}),
    ],
    "gana_heart": [
        ("context.status", {}),
        ("scratchpad", {}),
        ("working_memory.status", {}),
    ],
    "gana_tail": [
        ("simd.status", {}),
        ("list_cascade_patterns", {}),
        ("execute_cascade", {"pattern": "sequential", "tools": ["health_report"]}),
    ],
    "gana_winnowing_basket": [
        ("search_memories", {"query": "test", "limit": 5}),
        ("vector.status", {}),
        ("hybrid_recall", {"query": "test"}),
    ],
    "gana_ghost": [
        ("gnosis", {"compact": True}),
        ("capabilities", {}),
        ("graph_topology", {}),
    ],
    "gana_willow": [
        ("rate_limiter.stats", {}),
        ("grimoire_list", {}),
        ("cast_oracle", {}),
    ],
    "gana_star": [
        ("governor_validate", {}),
        ("forge.status", {}),
        ("dharma_rules", {}),
    ],
    "gana_extended_net": [
        ("cluster_stats", {}),
        ("pattern_search", {"query": "test"}),
        ("community.status", {}),
    ],
    "gana_wings": [
        ("mesh.status", {}),
        ("export_memories", {"format": "json"}),
    ],
    "gana_chariot": [
        ("archaeology_stats", {}),
        ("kg.status", {}),
        ("windsurf_stats", {}),
    ],
    "gana_abundance": [
        ("dream_status", {}),
        ("memory.lifecycle_stats", {}),
        ("serendipity_surface", {}),
    ],
    "gana_straddling_legs": [
        ("harmony_vector", {}),
        ("wu_xing_balance", {}),
        ("evaluate_ethics", {}),
    ],
    "gana_mound": [
        ("get_yin_yang_balance", {}),
        ("get_metrics_summary", {}),
        ("track_metric", {"metric": "test", "value": 1.0}),
    ],
    "gana_stomach": [
        ("task.list", {}),
        ("pipeline.list", {}),
        ("pipeline.status", {}),
    ],
    "gana_hairy_head": [
        ("anomaly.status", {}),
        ("karma_report", {}),
        ("salience.spotlight", {}),
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
        ("think", {"query": "test"}),
    ],
    "gana_dipper": [
        ("homeostasis.status", {}),
        ("starter_packs.list", {}),
        ("cognitive.mode", {}),
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
        ("garden_status", {}),
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


class GanaAnalyzer:
    """Analyze Gana test results for patterns and anti-patterns."""

    def __init__(self):
        self.results = {}
        self.patterns = {
            "fast_tools": [],  # <100ms
            "medium_tools": [],  # 100ms-1s
            "slow_tools": [],  # >1s
            "very_slow_tools": [],  # >5s
            "error_patterns": {},
            "success_patterns": {},
            "token_heavy": [],  # Large response payloads
            "token_light": [],  # Small response payloads
        }

    def test_tool(self, gana: str, tool: str, args: dict) -> dict[str, Any]:
        """Test a single tool and record metrics."""
        start = time.perf_counter()
        try:
            result = call_tool(tool, **args)
            latency = (time.perf_counter() - start) * 1000

            # Analyze result
            status = result.get("status") if isinstance(result, dict) else "unknown"
            response_size = len(str(result))

            # Categorize by latency
            if latency < 100:
                self.patterns["fast_tools"].append((gana, tool, latency))
            elif latency < 1000:
                self.patterns["medium_tools"].append((gana, tool, latency))
            elif latency < 5000:
                self.patterns["slow_tools"].append((gana, tool, latency))
            else:
                self.patterns["very_slow_tools"].append((gana, tool, latency))

            # Categorize by response size
            if response_size < 500:
                self.patterns["token_light"].append((gana, tool, response_size))
            elif response_size > 5000:
                self.patterns["token_heavy"].append((gana, tool, response_size))

            # Track success/error patterns
            if status == "success":
                self.patterns["success_patterns"][tool] = self.patterns["success_patterns"].get(tool, 0) + 1
            elif status == "error":
                error_msg = result.get("message", result.get("error", "Unknown"))[:100]
                if error_msg not in self.patterns["error_patterns"]:
                    self.patterns["error_patterns"][error_msg] = []
                self.patterns["error_patterns"][error_msg].append((gana, tool))

            return {
                "gana": gana,
                "tool": tool,
                "status": status,
                "latency_ms": round(latency, 2),
                "response_size": response_size,
                "success": status == "success",
            }
        except Exception as e:
            latency = (time.perf_counter() - start) * 1000
            error_msg = str(e)[:100]
            if error_msg not in self.patterns["error_patterns"]:
                self.patterns["error_patterns"][error_msg] = []
            self.patterns["error_patterns"][error_msg].append((gana, tool))

            return {
                "gana": gana,
                "tool": tool,
                "status": "exception",
                "latency_ms": round(latency, 2),
                "error": error_msg,
                "success": False,
            }

    def run_sequential_tests(self):
        """Run all tests sequentially."""
        print("="*80)
        print("SEQUENTIAL TESTING - All 28 Ganas")
        print("="*80)

        total_start = time.perf_counter()
        all_results = []

        for gana_name in sorted(GANA_TEST_SUITE.keys()):
            print(f"\n{gana_name}:")
            tests = GANA_TEST_SUITE[gana_name]

            for tool_name, args in tests:
                result = self.test_tool(gana_name, tool_name, args)
                all_results.append(result)

                status_icon = "✓" if result["success"] else "✗"
                print(f"  {status_icon} {tool_name:40s} {result['latency_ms']:7.1f}ms")

        total_time = time.perf_counter() - total_start

        self.results["sequential"] = {
            "total_time_s": round(total_time, 2),
            "total_tests": len(all_results),
            "passed": sum(1 for r in all_results if r["success"]),
            "failed": sum(1 for r in all_results if not r["success"]),
            "results": all_results,
        }

        print(f"\nSequential Total: {total_time:.2f}s")
        print(f"Passed: {self.results['sequential']['passed']}/{len(all_results)}")

    def run_parallel_tests(self, max_workers: int = 10):
        """Run tests in parallel using ThreadPoolExecutor."""
        print("\n" + "="*80)
        print(f"PARALLEL TESTING - {max_workers} Workers")
        print("="*80)

        # Flatten all tests
        all_tests = []
        for gana_name, tests in GANA_TEST_SUITE.items():
            for tool_name, args in tests:
                all_tests.append((gana_name, tool_name, args))

        total_start = time.perf_counter()
        results = []

        with ThreadPoolExecutor(max_workers=max_workers) as executor:
            futures = {
                executor.submit(self.test_tool, gana, tool, args): (gana, tool)
                for gana, tool, args in all_tests
            }

            completed = 0
            for future in as_completed(futures):
                result = future.result()
                results.append(result)
                completed += 1

                if completed % 10 == 0:
                    print(f"  Completed: {completed}/{len(all_tests)}")

        total_time = time.perf_counter() - total_start

        self.results["parallel"] = {
            "total_time_s": round(total_time, 2),
            "total_tests": len(results),
            "passed": sum(1 for r in results if r["success"]),
            "failed": sum(1 for r in results if not r["success"]),
            "max_workers": max_workers,
            "speedup": round(self.results["sequential"]["total_time_s"] / total_time, 2),
            "results": results,
        }

        print(f"\nParallel Total: {total_time:.2f}s")
        print(f"Passed: {self.results['parallel']['passed']}/{len(results)}")
        print(f"Speedup: {self.results['parallel']['speedup']}x")

    def analyze_patterns(self):
        """Analyze and report patterns."""
        print("\n" + "="*80)
        print("PATTERN ANALYSIS")
        print("="*80)

        # Performance patterns
        print("\n📊 Performance Distribution:")
        print(f"  Fast (<100ms):      {len(self.patterns['fast_tools'])} tools")
        print(f"  Medium (100ms-1s):  {len(self.patterns['medium_tools'])} tools")
        print(f"  Slow (1-5s):        {len(self.patterns['slow_tools'])} tools")
        print(f"  Very Slow (>5s):    {len(self.patterns['very_slow_tools'])} tools")

        if self.patterns['very_slow_tools']:
            print("\n⚠️  Very Slow Tools (>5s):")
            for gana, tool, latency in sorted(self.patterns['very_slow_tools'], key=lambda x: x[2], reverse=True)[:5]:
                print(f"    {gana}.{tool}: {latency:.0f}ms")

        # Token efficiency
        print("\n💬 Token Efficiency:")
        print(f"  Light (<500 chars):  {len(self.patterns['token_light'])} tools")
        print(f"  Heavy (>5000 chars): {len(self.patterns['token_heavy'])} tools")

        if self.patterns['token_heavy']:
            print("\n📦 Token-Heavy Tools (>5000 chars):")
            for gana, tool, size in sorted(self.patterns['token_heavy'], key=lambda x: x[2], reverse=True)[:5]:
                print(f"    {gana}.{tool}: {size:,} chars")

        # Error patterns
        if self.patterns['error_patterns']:
            print(f"\n❌ Error Patterns ({len(self.patterns['error_patterns'])} unique):")
            for error_msg, occurrences in list(self.patterns['error_patterns'].items())[:5]:
                print(f"    {error_msg}")
                print(f"      Affects: {len(occurrences)} tools")

        # Success rate by Gana
        gana_success = {}
        for result in self.results.get("sequential", {}).get("results", []):
            gana = result["gana"]
            if gana not in gana_success:
                gana_success[gana] = {"passed": 0, "total": 0}
            gana_success[gana]["total"] += 1
            if result["success"]:
                gana_success[gana]["passed"] += 1

        print("\n✅ Success Rate by Gana:")
        for gana in sorted(gana_success.keys()):
            stats = gana_success[gana]
            rate = (stats["passed"] / stats["total"] * 100) if stats["total"] > 0 else 0
            icon = "✓" if rate == 100 else "⚠" if rate >= 75 else "✗"
            print(f"  {icon} {gana:30s} {stats['passed']}/{stats['total']} ({rate:.0f}%)")

    def generate_recommendations(self):
        """Generate improvement recommendations."""
        print("\n" + "="*80)
        print("RECOMMENDATIONS")
        print("="*80)

        recommendations = []

        # Performance recommendations
        if len(self.patterns['very_slow_tools']) > 0:
            recommendations.append({
                "category": "Performance",
                "priority": "High",
                "issue": f"{len(self.patterns['very_slow_tools'])} tools take >5s",
                "suggestion": "Add caching, optimize queries, or add async variants"
            })

        # Token efficiency recommendations
        if len(self.patterns['token_heavy']) > 10:
            recommendations.append({
                "category": "Token Efficiency",
                "priority": "Medium",
                "issue": f"{len(self.patterns['token_heavy'])} tools return >5KB responses",
                "suggestion": "Add compact mode, pagination, or summary options"
            })

        # Error handling recommendations
        if self.patterns['error_patterns']:
            recommendations.append({
                "category": "Error Handling",
                "priority": "High",
                "issue": f"{len(self.patterns['error_patterns'])} unique error patterns",
                "suggestion": "Improve error messages, add fallbacks, create stubs for missing features"
            })

        # Parallel execution recommendations
        if "parallel" in self.results and self.results["parallel"]["speedup"] < 3:
            recommendations.append({
                "category": "Parallelization",
                "priority": "Medium",
                "issue": f"Only {self.results['parallel']['speedup']}x speedup with parallel execution",
                "suggestion": "Reduce shared state, optimize DB connections, use connection pooling"
            })

        for i, rec in enumerate(recommendations, 1):
            print(f"\n{i}. [{rec['priority']}] {rec['category']}")
            print(f"   Issue: {rec['issue']}")
            print(f"   Suggestion: {rec['suggestion']}")

        return recommendations

    def save_report(self, filepath: Path):
        """Save comprehensive report to JSON."""
        report = {
            "summary": {
                "sequential_time_s": self.results.get("sequential", {}).get("total_time_s"),
                "parallel_time_s": self.results.get("parallel", {}).get("total_time_s"),
                "speedup": self.results.get("parallel", {}).get("speedup"),
                "total_tests": self.results.get("sequential", {}).get("total_tests"),
                "pass_rate": round(
                    self.results.get("sequential", {}).get("passed", 0) /
                    self.results.get("sequential", {}).get("total_tests", 1) * 100, 1
                ),
            },
            "patterns": {
                "fast_tools_count": len(self.patterns["fast_tools"]),
                "slow_tools_count": len(self.patterns["slow_tools"]),
                "very_slow_tools": [
                    {"gana": g, "tool": t, "latency_ms": l}
                    for g, t, l in self.patterns["very_slow_tools"]
                ],
                "token_heavy_count": len(self.patterns["token_heavy"]),
                "error_patterns": {
                    msg: [{"gana": g, "tool": t} for g, t in tools]
                    for msg, tools in self.patterns["error_patterns"].items()
                },
            },
            "detailed_results": self.results,
        }

        with open(filepath, 'w') as f:
            json.dump(report, f, indent=2)

        print(f"\n✓ Report saved to: {filepath}")


def main():
    analyzer = GanaAnalyzer()

    # Run sequential tests
    analyzer.run_sequential_tests()

    # Run parallel tests
    analyzer.run_parallel_tests(max_workers=10)

    # Analyze patterns
    analyzer.analyze_patterns()

    # Generate recommendations
    analyzer.generate_recommendations()

    # Save report
    report_path = Path(__file__).parent.parent / "reports" / "gana_comprehensive_test.json"
    analyzer.save_report(report_path)

    return 0


if __name__ == "__main__":
    sys.exit(main())
