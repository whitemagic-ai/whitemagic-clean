#!/usr/bin/env python3
"""
WhiteMagic Playground — Interactive demo for new agents and humans.

Run:  python -m whitemagic.playground

This script walks through WhiteMagic's core capabilities:
  1. System health check (Gnosis)
  2. Capability discovery
  3. Memory round-trip (store -> search -> read)
  4. Ethical evaluation (Dharma)
  5. Harmony Vector health pulse
"""
import json
import os
import sys

# Quiet startup
os.environ.setdefault("WM_SILENT_INIT", "1")

try:
    from whitemagic.tools.unified_api import call_tool
except ImportError:
    print("Error: whitemagic is not installed.")
    print("Install it:  pip install whitemagic")
    sys.exit(1)

try:
    from whitemagic import __version__
except Exception:
    __version__ = "unknown"


def section(title: str) -> None:
    print(f"\n{'=' * 60}")
    print(f"  {title}")
    print(f"{'=' * 60}")


def pretty(data: dict) -> str:
    return json.dumps(data, indent=2, default=str)[:2000]


def main() -> None:
    print(f"WhiteMagic Playground v{__version__}")
    print("This demo walks through core capabilities.\n")

    # 1. Gnosis — System Health
    section("1. Gnosis — System Health Snapshot")
    result = call_tool("gnosis", compact=True)
    if result.get("status") == "success":
        gnosis = result.get("details", {}).get("gnosis", result.get("details", {}))
        print(f"  Status: {gnosis.get('status', 'unknown')}")
        print(f"  Maturity: {gnosis.get('maturity_stage', 'unknown')}")
        alerts = gnosis.get("alerts", [])
        if alerts:
            print(f"  Alerts ({len(alerts)}):")
            for a in alerts[:5]:
                print(f"    - {a}")
        else:
            print("  No alerts — all clear.")
        actions = gnosis.get("next_actions", [])
        if actions:
            act = actions[0]
            if isinstance(act, dict):
                print(f"  Suggested: {act.get('tool', act)} — {act.get('reason', '')}")
            else:
                print(f"  Suggested: {act}")
    else:
        print(f"  Result: {pretty(result)}")

    # 2. Capabilities — Tool Discovery
    section("2. Capabilities — What Can I Do?")
    result = call_tool("capabilities")
    if result.get("status") == "success":
        details = result.get("details", {})
        print(f"  Version: {details.get('version', 'unknown')}")
        tools = details.get("tools", [])
        if isinstance(tools, dict):
            tools = list(tools.values())
        print(f"  Available tools: {len(tools)}")
        categories: dict[str, int] = {}
        for t_info in tools[:300]:
            if isinstance(t_info, dict):
                cat = t_info.get("category", "unknown")
            elif isinstance(t_info, str):
                cat = "unknown"
            else:
                continue
            categories[cat] = categories.get(cat, 0) + 1
        if categories:
            print("  By category:")
            for cat, count in sorted(categories.items(), key=lambda x: -x[1])[:8]:
                print(f"    {cat}: {count} tools")
    else:
        print(f"  Result: {pretty(result)}")

    # 3. Memory Round-Trip
    section("3. Memory — Store & Recall")
    print("  Storing a test memory...")
    store_result = call_tool(
        "remember",
        content="WhiteMagic playground test: the answer to everything is 42.",
        title="Playground Test Memory",
        tags=["test", "playground"],
    )
    if store_result.get("status") == "success":
        memory_id = store_result.get("details", {}).get("memory_id", "unknown")
        print(f"  Stored (ID: {memory_id})")
    else:
        print(f"  Store result: {store_result.get('status')}")

    print("  Searching for it...")
    search_result = call_tool("recall", query="answer to everything")
    if search_result.get("status") == "success":
        results = search_result.get("results", [])
        if results:
            print(f"  Found {len(results)} result(s):")
            top = results[0]
            print(f"    Top match: {top.get('content', '')[:100]}")
        else:
            print("  No results (embedding index may need a moment).")
    else:
        print(f"  Search result: {search_result.get('status')}")

    # 4. Dharma — Ethical Evaluation
    section("4. Dharma — Ethical Evaluation")
    result = call_tool("evaluate_ethics", action="Read a file from disk")
    if result.get("status") == "success":
        details = result.get("details", {})
        score = details.get("ethical_score", "unknown")
        concerns = details.get("concerns", [])
        print("  Action: 'Read a file from disk'")
        print(f"  Ethical score: {score}")
        if concerns:
            for c in concerns[:3]:
                print(f"  Concern: {c}")
        else:
            print("  No ethical concerns raised.")
    else:
        print(f"  Result: {pretty(result)}")

    # 5. Harmony Vector
    section("5. Harmony Vector — 7D Health Pulse")
    result = call_tool("harmony_vector")
    if result.get("status") == "success":
        hv = result.get("details", {}).get("harmony_vector", result.get("details", {}))
        core_dims = ["balance", "throughput", "latency", "error_rate", "dharma", "karma_debt", "energy"]
        for dim in core_dims:
            val = hv.get(dim)
            if val is not None:
                try:
                    fval = float(val)
                    bar = "#" * int(fval * 20)
                    print(f"  {dim:>15}: {fval:.2f} {bar}")
                except (TypeError, ValueError):
                    print(f"  {dim:>15}: {val}")
        score = hv.get("harmony_score")
        if score is not None:
            print(f"\n  Overall harmony: {float(score):.2f}")
    else:
        print(f"  Result: {pretty(result)}")

    # Done
    section("Done!")
    print("  WhiteMagic is ready. Next steps:")
    print("  - Launch MCP server:  WM_MCP_PRAT=1 python -m whitemagic.run_mcp")
    print("  - Check health:       wm doctor")
    print("  - Explore tools:      call_tool('starter_packs.list')")
    print("  - Tip if grateful:    call_tool('whitemagic.tip', amount=1.0, currency='XRP')")
    print()


if __name__ == "__main__":
    main()
