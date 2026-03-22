#!/usr/bin/env python3
"""Shadow Clone Army — Gana Diagnostic & Repair Mission

Deploys scout armies to test all 28 Gana MCP tools, diagnose failures,
and generate a comprehensive repair plan.

Usage:
    scripts/wm scripts/diagnose_all_ganas.py
    scripts/wm scripts/diagnose_all_ganas.py --gana gana_ghost
    scripts/wm scripts/diagnose_all_ganas.py --fix
"""

import argparse
import json
import logging
import sys
import time
from collections import defaultdict
from pathlib import Path

# Add parent to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.tools.unified_api import call_tool

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger(__name__)

# All 28 Ganas in order
ALL_GANAS = [
    "gana_horn",
    "gana_neck",
    "gana_root",
    "gana_room",
    "gana_heart",
    "gana_tail",
    "gana_winnowing_basket",
    "gana_ghost",
    "gana_willow",
    "gana_star",
    "gana_extended_net",
    "gana_wings",
    "gana_chariot",
    "gana_abundance",
    "gana_straddling_legs",
    "gana_mound",
    "gana_stomach",
    "gana_hairy_head",
    "gana_net",
    "gana_turtle_beak",
    "gana_three_stars",
    "gana_dipper",
    "gana_ox",
    "gana_girl",
    "gana_void",
    "gana_roof",
    "gana_encampment",
    "gana_wall",
]

# Test cases for each Gana - pick 2-3 representative tools per Gana
GANA_TEST_CASES = {
    "gana_horn": [
        ("session_status", {}),
        ("focus_session", {}),
    ],
    "gana_neck": [
        ("create_memory", {"content": "Test memory for diagnostic", "title": "Diagnostic Test", "tags": ["test", "diagnostic"]}),
    ],
    "gana_root": [
        ("health_report", {}),
        ("rust_status", {}),
    ],
    "gana_room": [
        ("sandbox.status", {}),
        ("security.monitor_status", {}),
    ],
    "gana_heart": [
        ("context.status", {}),
        ("working_memory.status", {}),
    ],
    "gana_tail": [
        ("simd.status", {}),
        ("list_cascade_patterns", {}),
    ],
    "gana_winnowing_basket": [
        ("search_memories", {"query": "test", "limit": 5}),
        ("vector.status", {}),
    ],
    "gana_ghost": [
        ("gnosis", {"compact": True}),
        ("capabilities", {}),
        ("graph_topology", {}),
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
    ],
    "gana_chariot": [
        ("archaeology_stats", {}),
        ("kg.status", {}),
    ],
    "gana_abundance": [
        ("dream_status", {}),
        ("memory.lifecycle_stats", {}),
        ("serendipity_surface", {"limit": 3}),
    ],
    "gana_straddling_legs": [
        ("harmony_vector", {}),
        ("wu_xing_balance", {}),
    ],
    "gana_mound": [
        ("get_metrics_summary", {}),
        ("get_yin_yang_balance", {}),
    ],
    "gana_stomach": [
        ("task.list", {}),
        ("pipeline.list", {}),
    ],
    "gana_hairy_head": [
        ("anomaly.status", {}),
        ("otel.status", {}),
    ],
    "gana_net": [
        ("prompt.list", {}),
    ],
    "gana_turtle_beak": [
        ("edge_stats", {}),
        ("bitnet_status", {}),
    ],
    "gana_three_stars": [
        ("ensemble.status", {}),
        ("sabha.status", {}),
    ],
    "gana_dipper": [
        ("homeostasis.status", {}),
        ("maturity.assess", {}),
    ],
    "gana_ox": [
        ("swarm.status", {}),
        ("worker.status", {}),
        ("war_room.status", {}),
    ],
    "gana_girl": [
        ("agent.list", {}),
    ],
    "gana_void": [
        ("galaxy.list", {}),
        ("galaxy.status", {}),
        ("garden_status", {}),
    ],
    "gana_roof": [
        ("ollama.models", {}),
        ("model.list", {}),
    ],
    "gana_encampment": [
        ("broker.status", {}),
    ],
    "gana_wall": [
        ("vote.list", {}),
        ("engagement.list", {}),
    ],
}


class GanaDiagnostic:
    """Shadow clone diagnostic engine for Gana tools."""

    def __init__(self):
        self.results = defaultdict(lambda: {"passed": [], "failed": [], "errors": []})
        self.total_tests = 0
        self.total_passed = 0
        self.total_failed = 0
        self.start_time = time.time()

    def test_tool(self, gana: str, tool: str, args: dict) -> dict:
        """Test a single tool and return result."""
        self.total_tests += 1
        test_start = time.time()

        try:
            logger.info(f"  Testing {tool}...")
            result = call_tool(tool, **args)
            latency = (time.time() - test_start) * 1000

            # Check if result indicates error
            if isinstance(result, dict):
                # Check for explicit error status
                if result.get("status") == "error":
                    self.total_failed += 1
                    error_msg = result.get("error", result.get("message", "Unknown error"))
                    self.results[gana]["failed"].append(tool)
                    self.results[gana]["errors"].append({
                        "tool": tool,
                        "error": error_msg,
                        "latency_ms": latency,
                        "result": result,
                    })
                    logger.error(f"    ✗ {tool}: {error_msg}")
                    return {"status": "failed", "error": error_msg, "latency_ms": latency}
                # Success - either explicit success status or no error
                else:
                    self.total_passed += 1
                    self.results[gana]["passed"].append(tool)
                    result_preview = str(result)[:100] if len(str(result)) > 100 else str(result)
                    logger.info(f"    ✓ {tool} ({latency:.1f}ms) - {result_preview}")
                    return {"status": "passed", "latency_ms": latency, "result": result}
            else:
                # Non-dict result, assume success
                self.total_passed += 1
                self.results[gana]["passed"].append(tool)
                logger.info(f"    ✓ {tool} ({latency:.1f}ms)")
                return {"status": "passed", "latency_ms": latency}

        except Exception as e:
            self.total_failed += 1
            latency = (time.time() - test_start) * 1000
            error_msg = str(e)
            self.results[gana]["failed"].append(tool)
            self.results[gana]["errors"].append({
                "tool": tool,
                "error": error_msg,
                "exception": type(e).__name__,
                "latency_ms": latency,
            })
            logger.error(f"    ✗ {tool}: {type(e).__name__}: {error_msg}")
            return {"status": "exception", "error": error_msg, "latency_ms": latency}

    def test_gana(self, gana: str) -> dict:
        """Test all tools in a Gana."""
        logger.info(f"\n{'='*60}")
        logger.info(f"Testing {gana}")
        logger.info(f"{'='*60}")

        test_cases = GANA_TEST_CASES.get(gana, [])
        if not test_cases:
            logger.warning(f"No test cases defined for {gana}")
            return {"status": "skipped", "reason": "no_test_cases"}

        gana_start = time.time()
        test_results = []

        for tool, args in test_cases:
            result = self.test_tool(gana, tool, args)
            test_results.append({"tool": tool, "args": args, "result": result})

        gana_latency = (time.time() - gana_start) * 1000
        passed = len(self.results[gana]["passed"])
        failed = len(self.results[gana]["failed"])

        logger.info(f"\n{gana}: {passed} passed, {failed} failed ({gana_latency:.1f}ms)")

        return {
            "gana": gana,
            "passed": passed,
            "failed": failed,
            "total": passed + failed,
            "latency_ms": gana_latency,
            "tests": test_results,
        }

    def run_all(self, gana_filter: str | None = None):
        """Run diagnostics on all Ganas or a specific one."""
        ganas_to_test = [gana_filter] if gana_filter else ALL_GANAS

        logger.info(f"\n{'#'*60}")
        logger.info("# Shadow Clone Gana Diagnostic Army")
        logger.info(f"# Testing {len(ganas_to_test)} Ganas")
        logger.info(f"{'#'*60}\n")

        gana_results = []
        for gana in ganas_to_test:
            if gana not in ALL_GANAS:
                logger.error(f"Unknown Gana: {gana}")
                continue
            result = self.test_gana(gana)
            gana_results.append(result)

        return self.generate_report(gana_results)

    def generate_report(self, gana_results: list) -> dict:
        """Generate comprehensive diagnostic report."""
        total_latency = (time.time() - self.start_time) * 1000

        logger.info(f"\n{'#'*60}")
        logger.info("# DIAGNOSTIC REPORT")
        logger.info(f"{'#'*60}\n")

        logger.info(f"Total Tests: {self.total_tests}")
        logger.info(f"Passed: {self.total_passed} ({self.total_passed/self.total_tests*100:.1f}%)")
        logger.info(f"Failed: {self.total_failed} ({self.total_failed/self.total_tests*100:.1f}%)")
        logger.info(f"Total Time: {total_latency:.1f}ms\n")

        # Gana-by-Gana summary
        logger.info("Gana Summary:")
        logger.info("-" * 60)
        for result in gana_results:
            if result.get("status") == "skipped":
                continue
            gana = result["gana"]
            passed = result["passed"]
            total = result["total"]
            status = "✓" if result["failed"] == 0 else "✗"
            logger.info(f"{status} {gana:30s} {passed}/{total} passed")

        # Error analysis
        logger.info(f"\n{'='*60}")
        logger.info("ERROR ANALYSIS")
        logger.info(f"{'='*60}\n")

        error_patterns = defaultdict(list)
        for gana, data in self.results.items():
            for error in data["errors"]:
                error_msg = error["error"]
                # Categorize errors
                if "not yet implemented" in error_msg.lower():
                    error_patterns["not_implemented"].append((gana, error["tool"]))
                elif "no module" in error_msg.lower() or "import" in error_msg.lower():
                    error_patterns["import_error"].append((gana, error["tool"]))
                elif "attribute" in error_msg.lower():
                    error_patterns["attribute_error"].append((gana, error["tool"]))
                elif "file not found" in error_msg.lower() or "path" in error_msg.lower():
                    error_patterns["path_error"].append((gana, error["tool"]))
                else:
                    error_patterns["other"].append((gana, error["tool"], error_msg))

        for pattern, errors in sorted(error_patterns.items()):
            logger.info(f"\n{pattern.upper().replace('_', ' ')} ({len(errors)} errors):")
            for item in errors[:10]:  # Show first 10
                if len(item) == 3:
                    gana, tool, msg = item
                    logger.info(f"  - {gana}.{tool}: {msg[:80]}")
                else:
                    gana, tool = item
                    logger.info(f"  - {gana}.{tool}")
            if len(errors) > 10:
                logger.info(f"  ... and {len(errors) - 10} more")

        # Save detailed report
        report_path = Path(__file__).parent.parent / "reports" / "gana_diagnostic_report.json"
        report_path.parent.mkdir(exist_ok=True)

        report = {
            "timestamp": time.time(),
            "total_tests": self.total_tests,
            "total_passed": self.total_passed,
            "total_failed": self.total_failed,
            "pass_rate": self.total_passed / self.total_tests if self.total_tests > 0 else 0,
            "total_latency_ms": total_latency,
            "gana_results": gana_results,
            "error_patterns": {k: len(v) for k, v in error_patterns.items()},
            "detailed_errors": dict(self.results),
        }

        with open(report_path, "w") as f:
            json.dump(report, f, indent=2)

        logger.info(f"\nDetailed report saved to: {report_path}")

        return report


def main():
    parser = argparse.ArgumentParser(description="Diagnose all Gana MCP tools")
    parser.add_argument("--gana", help="Test specific Gana only")
    parser.add_argument("--fix", action="store_true", help="Auto-fix common issues (future)")
    args = parser.parse_args()

    diagnostic = GanaDiagnostic()
    report = diagnostic.run_all(gana_filter=args.gana)

    # Exit code based on pass rate
    pass_rate = report["pass_rate"]
    if pass_rate >= 0.95:
        logger.info("\n✓ All systems operational (≥95% pass rate)")
        sys.exit(0)
    elif pass_rate >= 0.75:
        logger.warning(f"\n⚠ Some issues detected ({pass_rate*100:.1f}% pass rate)")
        sys.exit(1)
    else:
        logger.error(f"\n✗ Critical failures detected ({pass_rate*100:.1f}% pass rate)")
        sys.exit(2)


if __name__ == "__main__":
    main()
