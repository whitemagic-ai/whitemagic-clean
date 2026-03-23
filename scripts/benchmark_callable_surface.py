#!/usr/bin/env python3
"""Callable surface benchmark + consistency harness.

Focused nightly validation for the unified callable surface, PRAT native paths,
registration counts, integrity counts, and a few latency-sensitive tools.

Usage:
    python3 scripts/benchmark_callable_surface.py
    WM_BENCHMARK_QUIET=1 python3 scripts/benchmark_callable_surface.py
"""
from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import argparse  # noqa: E402
import json  # noqa: E402
import os  # noqa: E402
import time  # noqa: E402
from collections.abc import Callable  # noqa: E402
from statistics import mean  # noqa: E402
from typing import Any  # noqa: E402

from whitemagic.run_mcp import _register_prat_tools, get_registered_tool_definitions  # noqa: E402
from whitemagic.runtime_status import get_runtime_status  # noqa: E402
from whitemagic.security.mcp_integrity import McpIntegrity  # noqa: E402
from whitemagic.security.security_breaker import get_security_monitor  # noqa: E402
from whitemagic.tools.dispatch_table import dispatch  # noqa: E402
from whitemagic.tools.prat_router import route_prat_call, validate_mapping  # noqa: E402
from whitemagic.tools.registry import TOOL_REGISTRY  # noqa: E402
from whitemagic.tools.tool_surface import get_surface_counts  # noqa: E402
from whitemagic.tools.unified_api import call_tool  # noqa: E402

REPORTS_DIR = ROOT / "reports" / "benchmarks"


def sample(fn: Callable[[], Any], runs: int) -> dict[str, Any]:
    durations: list[float] = []
    for _ in range(runs):
        t0 = time.perf_counter()
        fn()
        durations.append((time.perf_counter() - t0) * 1000)
    return {
        "runs": runs,
        "avg_ms": round(mean(durations), 3),
        "min_ms": round(min(durations), 3),
        "max_ms": round(max(durations), 3),
    }


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description='Benchmark callable surface + count consistency')
    parser.add_argument('--save', action='store_true', help='Save a timestamped JSON report under reports/benchmarks')
    parser.add_argument('--compare', type=str, default='', help='Path to a prior JSON report to compare against')
    return parser.parse_args()


def _load_json(path_str: str) -> dict[str, Any]:
    return json.loads(Path(path_str).read_text(encoding='utf-8'))


def _benchmark_regressions(current: dict[str, Any], previous: dict[str, Any]) -> dict[str, Any]:
    regressions: dict[str, Any] = {}
    current_bench = current.get('benchmarks', {})
    previous_bench = previous.get('benchmarks', {})
    for name, metrics in current_bench.items():
        prev = previous_bench.get(name)
        if not prev:
            continue
        delta = round(metrics.get('avg_ms', 0.0) - prev.get('avg_ms', 0.0), 3)
        regressions[name] = {
            'current_avg_ms': metrics.get('avg_ms', 0.0),
            'previous_avg_ms': prev.get('avg_ms', 0.0),
            'delta_avg_ms': delta,
        }
    return regressions


def main() -> None:
    args = _parse_args()
    quiet = os.getenv("WM_BENCHMARK_QUIET", "").strip().lower() in ("1", "true", "yes")
    monitor = get_security_monitor()
    monitor.reset()

    benches = {
        "dispatch_gana_ghost_native_quiet": sample(
            lambda: dispatch("gana_ghost", operation="search", _internal_benchmark=True), 12
        ),
        "dispatch_gana_winnowing_native_quiet": sample(
            lambda: dispatch("gana_winnowing_basket", operation="search", _internal_benchmark=True), 12
        ),
        "route_prat_gana_ghost_native_quiet": sample(
            lambda: route_prat_call("gana_ghost", operation="search", _internal_benchmark=True), 12
        ),
        "route_prat_gana_winnowing_native_quiet": sample(
            lambda: route_prat_call("gana_winnowing_basket", _internal_benchmark=True), 12
        ),
        "call_tool_health_report": sample(
            lambda: call_tool("health_report"), 8
        ),
        "call_tool_capabilities_light": sample(
            lambda: call_tool("capabilities", include_tools=False, include_env=False), 8
        ),
        "call_tool_manifest_summary": sample(
            lambda: call_tool("manifest", format="summary"), 8
        ),
        "call_tool_anomaly_status": sample(
            lambda: call_tool("anomaly.status"), 8
        ),
        "call_tool_search_memories_small": sample(
            lambda: call_tool("search_memories", query="whitemagic", limit=5), 5
        ),
    }

    counts = get_surface_counts()
    mapping = validate_mapping(TOOL_REGISTRY)
    runtime = get_runtime_status()
    integrity = McpIntegrity(storage_dir=None)
    snapshot = integrity.snapshot()
    verify = integrity.verify()

    result = {
        "timestamp": time.strftime('%Y-%m-%dT%H:%M:%S'),
        "quiet_mode": quiet,
        "surface_counts": counts,
        "registration_counts": {
            "classic": len(get_registered_tool_definitions(lite_mode=False)),
            "lite": len(get_registered_tool_definitions(lite_mode=True)),
            "prat": _register_prat_tools(""),
        },
        "mapping": mapping,
        "runtime_status": runtime.get("status"),
        "integrity": {
            "tools_fingerprinted": snapshot["tools_fingerprinted"],
            "verified": verify["verified"],
            "baseline_count": verify["baseline_count"],
            "current_count": verify["current_count"],
        },
        "benchmarks": benches,
        "security_status": monitor.status(),
    }

    if args.compare:
        result['comparison'] = _benchmark_regressions(result, _load_json(args.compare))

    if args.save:
        REPORTS_DIR.mkdir(parents=True, exist_ok=True)
        filename = f"callable_surface_{time.strftime('%Y%m%d_%H%M%S')}.json"
        report_path = REPORTS_DIR / filename
        report_path.write_text(json.dumps(result, indent=2, sort_keys=True), encoding='utf-8')
        result['report_path'] = str(report_path)

    print(json.dumps(result, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
