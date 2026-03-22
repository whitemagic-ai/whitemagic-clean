#!/usr/bin/env python3
"""
Verify Universal Solver Bridge
"""
import sys
import os

# Add project root to path
sys.path.insert(0, os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from whitemagic.core.bridge.optimization import solve_optimization

def test_solver():
    print("🌌 Testing Universal Solver (MCP Bridge)...")
    
    nodes = ["Start", "Middle", "End"]
    edges = [["Start", "Middle"], ["Middle", "End"]]
    scores = {"Start": 0.5, "Middle": 0.9, "End": 0.8}
    
    try:
        result = solve_optimization(
            nodes=nodes,
            edges=edges,
            scores=scores,
            budget=2,
            max_iters=10
        )
        
        if result.get("status") == "success":
            print("✅ Solver Success!")
            print(f"   Selected: {result.get('selected_nodes')}")
            print(f"   Algorithm: {result.get('algorithm')}")
            
            # Simple assertion
            selected = result.get('selected_nodes', [])
            if "Middle" in selected:
                print("   - High score node selected (Correct)")
            else:
                print("   ⚠️ High score node MISSED")
                
        else:
            print("❌ Solver Failed")
            print(f"   Message: {result.get('message')}")
            print(f"   Missing: {result.get('missing_module')}")

    except Exception as e:
        print(f"❌ Exception during test: {e}")

if __name__ == "__main__":
    test_solver()
