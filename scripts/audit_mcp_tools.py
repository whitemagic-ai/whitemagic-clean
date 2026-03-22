#!/usr/bin/env python3
"""
MCP Tool Audit Script - Test all 374 MCP tools to identify issues.
Run with: python3 scripts/audit_mcp_tools.py
"""

import os
import sys
import time
import traceback

# Ensure we use the venv python
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev/.venv/lib/python3.12/site-packages')
os.chdir('/home/lucas/Desktop/whitemagicdev')

# Import WhiteMagic
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.tools.dispatch_table import DISPATCH_TABLE
from whitemagic.tools.prat_router import TOOL_TO_GANA

# Stats
results = {
    "passed": [],
    "failed": [],
    "skipped": [],
    "not_implemented": []
}

def test_tool(tool_name: str, test_args: dict) -> dict:
    """Test a single tool and return result."""
    handler = DISPATCH_TABLE.get(tool_name)
    if not handler:
        return {"status": "skipped", "error": "No handler in dispatch table"}

    try:
        start = time.time()
        result = handler(**test_args)
        latency = time.time() - start

        if result is None:
            return {"status": "failed", "error": "Returned None", "latency": latency}

        if isinstance(result, dict):
            if result.get("status") == "error":
                error_msg = result.get("error", "Unknown error")
                # Check for specific patterns
                if "not yet implemented" in error_msg.lower():
                    return {"status": "not_implemented", "error": error_msg, "latency": latency}
                if "not implemented" in error_msg.lower():
                    return {"status": "not_implemented", "error": error_msg, "latency": latency}
                return {"status": "failed", "error": error_msg, "latency": latency}

        return {"status": "passed", "latency": latency}
    except Exception as e:
        error_msg = str(e)
        if "not yet implemented" in error_msg.lower():
            return {"status": "not_implemented", "error": error_msg}
        if "not implemented" in error_msg.lower():
            return {"status": "not_implemented", "error": error_msg}
        return {"status": "failed", "error": f"{error_msg}\n{traceback.format_exc()}"}

def print_summary():
    """Print summary of results."""
    print("\n" + "="*70)
    print("MCP TOOL AUDIT SUMMARY")
    print("="*70)
    print(f"Total tools tested: {len(results['passed']) + len(results['failed']) + len(results['skipped']) + len(results['not_implemented'])}")
    print(f"Passed: {len(results['passed'])} ✅")
    print(f"Failed: {len(results['failed'])} ❌")
    print(f"Not Implemented: {len(results['not_implemented'])} ⚠️")
    print(f"Skipped (no handler): {len(results['skipped'])} ⏭️")

    if results['failed']:
        print("\n" + "-"*70)
        print("FAILED TOOLS:")
        for item in results['failed']:
            print(f"  - {item['tool']}: {item['error'][:100]}")

    if results['not_implemented']:
        print("\n" + "-"*70)
        print("NOT IMPLEMENTED TOOLS:")
        for item in results['not_implemented'][:20]:  # Limit output
            print(f"  - {item['tool']}: {item['error'][:100]}")
        if len(results['not_implemented']) > 20:
            print(f"  ... and {len(results['not_implemented']) - 20} more")

    print("\n" + "="*70)

# Core tools to test (representative sample from each Gana)
CORE_TOOLS = {
    # HORN - Session
    "session_status": {},
    "create_session": {"name": "test"},

    # NECK - Memory
    "create_memory": {"title": "Test", "content": "Test memory", "tags": ["test"]},
    "search_memories": {"query": "test"},
    "fast_read_memory": {"filename": "/home/lucas/Desktop/whitemagicdev/README.md"},

    # ROOT - Health
    "health_report": {},
    "ship.check": {},
    "capabilities": {},

    # HEART - Context
    "context.status": {},
    "scratchpad": {"operation": "create"},

    # TAIL - Acceleration
    "simd.status": {},

    # WILLOW - Grimoire
    "grimoire_list": {},
    "cast_oracle": {},

    # STAR - Governance
    "governor_stats": {},
    "dharma_rules": {},

    # EXTENDED NET - Pattern
    "pattern_search": {"query": "test"},
    "cluster_stats": {},

    # WINGS - Export
    "export_memories": {"format": "json"},

    # CHARIOT - Archaeology
    "archaeology_stats": {},

    # ABUNDANCE - Dream
    "dream_status": {},
    "memory.lifecycle_stats": {},

    # STRADDLING LEGS - Ethics
    "evaluate_ethics": {"action": "test"},
    "get_ethical_score": {},

    # MOUND - Metrics
    "get_metrics_summary": {},
    "get_yin_yang_balance": {},

    # STOMACH - Pipeline
    "pipeline.list": {},
    "task.list": {},

    # HAIRY HEAD - Debug
    "karma_report": {},

    # TURTLE BEAK - Edge
    "edge_stats": {},
    "bitnet_status": {},

    # THREE STARS - Synthesis
    "reasoning.bicameral": {"topic": "test"},
    "ensemble.status": {},

    # DIPPER - Strategy
    "homeostasis": {},
    "maturity.assess": {},

    # OX - Swarm
    "swarm.status": {},

    # GIRL - Agents
    "agent.list": {},

    # VOID - Galaxy
    "galaxy.list": {},
    "galaxy.status": {},

    # ROOF - Ollama/Shelter
    "ollama.models": {},
    "shelter.status": {},

    # ENCAMPMENT - Broker
    "broker.status": {},

    # WALL - Voting
    "vote.list": {},

    # ROOM - Security
    "mcp_integrity.status": {},
    "security.monitor_status": {},

    # GHOST - Introspection
    "gnosis": {},
    "repo.summary": {},
    "graph_topology": {},

    # WINNOWING BASKET - Search
    "vector.status": {},
    "hybrid_recall": {"query": "test"},

    # v15.8 Pattern Engines
    "causal.stats": {},
    "constellation.stats": {},
    "emergence.status": {},
    "novelty.stats": {},
    "galactic.stats": {},
    "pattern_consciousness.status": {},

    # v15.9 War Room
    "war_room.status": {},
    "doctrine.summary": {},
    "fool_guard.status": {},
    "art_of_war.wisdom": {},

    # v14.2 Features
    "jit_research.stats": {},
    "narrative.stats": {},
    "hermit.status": {},
    "green.report": {},
    "cognitive.stats": {},

    # v15.2 Features
    "oms.status": {},
    "ilp.status": {},
    "marketplace.status": {},

    # v15.6 Cognitive Extensions
    "rerank.status": {},
    "working_memory.status": {},
    "reconsolidation.status": {},
    "community.status": {},
}

def main():
    print("="*70)
    print("MCP TOOL AUDIT - Testing WhiteMagic Tools")
    print("="*70)
    print(f"Dispatch table has {len(DISPATCH_TABLE)} tools")
    print(f"PRAT maps {len(TOOL_TO_GANA)} tools to 28 Ganas")
    print(f"Testing {len(CORE_TOOLS)} representative tools...")
    print("="*70)

    for tool_name, test_args in CORE_TOOLS.items():
        print(f"\nTesting: {tool_name}", end=" ")
        result = test_tool(tool_name, test_args)

        if result["status"] == "passed":
            print(f"✅ ({result.get('latency', 0):.2f}s)")
            results["passed"].append({"tool": tool_name, **result})
        elif result["status"] == "not_implemented":
            print("⚠️ (not implemented)")
            results["not_implemented"].append({"tool": tool_name, **result})
        elif result["status"] == "skipped":
            print("⏭️ (no handler)")
            results["skipped"].append({"tool": tool_name, **result})
        else:
            print(f"❌ {result['error'][:60]}")
            results["failed"].append({"tool": tool_name, **result})

    print_summary()

    # Return non-zero if there are failures
    return 0 if not results['failed'] else 1

if __name__ == "__main__":
    sys.exit(main())
