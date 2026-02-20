#!/usr/bin/env python3
"""Shadow Clone Army — Investigate Remaining Gana Issues

Deploys specialized scout clones to diagnose each remaining issue:
1. create_memory - Unknown error
2. search_memories - Slice error
3. serendipity_surface - Parameter mismatch
4. Circuit breaker states

Each clone reports detailed findings for targeted fixes.
"""

import json
import logging
import sys
import traceback
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger(__name__)


class ShadowCloneScout:
    """Individual scout clone for investigating specific issues."""
    
    def __init__(self, name: str):
        self.name = name
        self.findings = []
        self.errors = []
    
    def log(self, msg: str):
        logger.info(f"[{self.name}] {msg}")
        self.findings.append(msg)
    
    def error(self, msg: str):
        logger.error(f"[{self.name}] ✗ {msg}")
        self.errors.append(msg)


class CreateMemoryScout(ShadowCloneScout):
    """Investigate create_memory issue."""
    
    def investigate(self):
        self.log("Investigating create_memory...")
        
        try:
            from whitemagic.tools.unified_api import call_tool
            
            # Test 1: Minimal call
            self.log("Test 1: Minimal parameters")
            result = call_tool("create_memory", content="test", title="test")
            self.log(f"Result type: {type(result)}")
            self.log(f"Result: {str(result)[:200]}")
            
            if isinstance(result, dict):
                if result.get("status") == "error":
                    self.error(f"Error: {result.get('error', 'Unknown')}")
                else:
                    self.log("✓ Minimal call succeeded")
            
            # Test 2: With tags
            self.log("Test 2: With tags parameter")
            result = call_tool("create_memory", content="test2", title="test2", tags=["test"])
            if isinstance(result, dict) and result.get("status") == "error":
                self.error(f"Tags error: {result.get('error', 'Unknown')}")
            else:
                self.log("✓ Tags call succeeded")
            
            # Test 3: Check handler directly
            self.log("Test 3: Direct handler call")
            from whitemagic.tools.handlers.memory import handle_create_memory
            result = handle_create_memory(content="test3", title="test3", tags=["test"])
            self.log(f"Direct handler result: {str(result)[:200]}")
            
        except Exception as e:
            self.error(f"Exception: {e}")
            self.error(traceback.format_exc())


class SearchMemoriesScout(ShadowCloneScout):
    """Investigate search_memories slice error."""
    
    def investigate(self):
        self.log("Investigating search_memories...")
        
        try:
            from whitemagic.tools.unified_api import call_tool
            
            # Test 1: Basic search
            self.log("Test 1: Basic search")
            result = call_tool("search_memories", query="test")
            self.log(f"Result type: {type(result)}")
            
            if isinstance(result, dict) and result.get("status") == "error":
                error_msg = result.get("error", "Unknown")
                self.error(f"Search error: {error_msg}")
                
                # Check if it's the slice error
                if "slice" in error_msg.lower():
                    self.log("Found slice error - investigating middleware")
                    
                    # Check middleware code
                    middleware_file = Path(__file__).parent.parent / "whitemagic" / "tools" / "middleware.py"
                    if middleware_file.exists():
                        content = middleware_file.read_text()
                        if "slice" in content:
                            self.log("Found slice usage in middleware.py")
                            # Find the problematic line
                            for i, line in enumerate(content.split('\n'), 1):
                                if "slice" in line.lower() and "kwargs" in line:
                                    self.log(f"Line {i}: {line.strip()}")
            else:
                self.log("✓ Search succeeded")
            
            # Test 2: With limit
            self.log("Test 2: With limit parameter")
            result = call_tool("search_memories", query="test", limit=5)
            if isinstance(result, dict) and result.get("status") == "error":
                self.error(f"Limit error: {result.get('error', 'Unknown')}")
            
        except Exception as e:
            self.error(f"Exception: {e}")
            self.error(traceback.format_exc())


class SerendipitySurfaceScout(ShadowCloneScout):
    """Investigate serendipity_surface parameter mismatch."""
    
    def investigate(self):
        self.log("Investigating serendipity_surface...")
        
        try:
            # Check handler signature
            handler_file = Path(__file__).parent.parent / "whitemagic" / "tools" / "handlers" / "dreaming.py"
            
            if handler_file.exists():
                content = handler_file.read_text()
                
                # Find the handler function
                if "def handle_serendipity_surface" in content:
                    self.log("Found handler function")
                    
                    # Extract function signature
                    lines = content.split('\n')
                    for i, line in enumerate(lines):
                        if "def handle_serendipity_surface" in line:
                            # Get function signature (may span multiple lines)
                            sig_lines = [line]
                            j = i + 1
                            while j < len(lines) and ')' not in lines[j-1]:
                                sig_lines.append(lines[j])
                                j += 1
                            
                            signature = '\n'.join(sig_lines)
                            self.log(f"Signature: {signature}")
                            
                            # Check if limit is in signature
                            if "limit" not in signature:
                                self.error("Handler does NOT accept 'limit' parameter")
                                
                                # Find the SerendipityEngine.surface() call
                                for k in range(i, min(i+50, len(lines))):
                                    if "SerendipityEngine" in lines[k] and "surface" in lines[k]:
                                        self.log(f"Line {k+1}: {lines[k].strip()}")
                            else:
                                self.log("Handler accepts 'limit' parameter")
                            break
            
            # Test the call
            from whitemagic.tools.unified_api import call_tool
            
            self.log("Test 1: Without limit")
            result = call_tool("serendipity_surface")
            if isinstance(result, dict) and result.get("status") == "error":
                self.error(f"No-limit error: {result.get('error', 'Unknown')}")
            
            self.log("Test 2: With limit")
            result = call_tool("serendipity_surface", limit=5)
            if isinstance(result, dict) and result.get("status") == "error":
                error_msg = result.get("error", "Unknown")
                self.error(f"With-limit error: {error_msg}")
                
                if "unexpected keyword argument" in error_msg:
                    self.log("Confirmed: Handler doesn't accept limit parameter")
            
        except Exception as e:
            self.error(f"Exception: {e}")
            self.error(traceback.format_exc())


class CircuitBreakerScout(ShadowCloneScout):
    """Investigate circuit breaker states."""
    
    def investigate(self):
        self.log("Investigating circuit breaker states...")
        
        try:
            # Check circuit breaker status
            from whitemagic.core.systems.circuit_breaker import CircuitBreaker
            
            cb = CircuitBreaker()
            
            # Get all circuit states
            self.log("Checking circuit breaker states...")
            
            # Try to access internal state
            if hasattr(cb, '_circuits'):
                circuits = cb._circuits
                self.log(f"Found {len(circuits)} circuits")
                
                for tool_name, state in circuits.items():
                    if state.get('state') == 'OPEN':
                        self.error(f"Circuit OPEN for: {tool_name}")
                        self.log(f"  Failures: {state.get('failures', 0)}")
                        self.log(f"  Last failure: {state.get('last_failure_time', 'Unknown')}")
            
            # Test specific tools that were failing
            from whitemagic.tools.unified_api import call_tool
            
            test_tools = ["task.list", "pipeline.list", "create_memory"]
            
            for tool in test_tools:
                self.log(f"Testing {tool}...")
                result = call_tool(tool)
                
                if isinstance(result, dict):
                    if result.get("status") == "error":
                        error = result.get("error", "")
                        if "circuit" in error.lower() or "breaker" in error.lower():
                            self.error(f"{tool}: Circuit breaker triggered")
                        else:
                            self.log(f"{tool}: Error (not circuit breaker): {error[:80]}")
                    else:
                        self.log(f"✓ {tool} succeeded")
            
        except Exception as e:
            self.error(f"Exception: {e}")
            self.error(traceback.format_exc())


def main():
    logger.info("="*80)
    logger.info("Shadow Clone Army — Issue Investigation")
    logger.info("="*80 + "\n")
    
    scouts = [
        CreateMemoryScout("CREATE_MEMORY"),
        SearchMemoriesScout("SEARCH_MEMORIES"),
        SerendipitySurfaceScout("SERENDIPITY"),
        CircuitBreakerScout("CIRCUIT_BREAKER"),
    ]
    
    results = {}
    
    for scout in scouts:
        logger.info(f"\n{'='*80}")
        logger.info(f"Deploying {scout.name} Scout")
        logger.info("="*80)
        
        scout.investigate()
        
        results[scout.name] = {
            "findings": scout.findings,
            "errors": scout.errors,
            "error_count": len(scout.errors),
        }
    
    # Save results
    report_file = Path(__file__).parent.parent / "reports" / "issue_investigation.json"
    report_file.parent.mkdir(exist_ok=True)
    
    with open(report_file, 'w') as f:
        json.dump(results, f, indent=2)
    
    logger.info(f"\n{'='*80}")
    logger.info("INVESTIGATION SUMMARY")
    logger.info("="*80)
    
    total_errors = sum(r["error_count"] for r in results.values())
    
    for scout_name, data in results.items():
        logger.info(f"\n{scout_name}:")
        logger.info(f"  Findings: {len(data['findings'])}")
        logger.info(f"  Errors: {data['error_count']}")
        
        if data['errors']:
            for error in data['errors'][:3]:
                logger.info(f"    - {error}")
    
    logger.info(f"\n✓ Investigation complete. Report saved to: {report_file}")
    logger.info(f"Total errors found: {total_errors}")
    
    return 0 if total_errors == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
