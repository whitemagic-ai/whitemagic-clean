#!/usr/bin/env python3
"""Deep Error Trace - Capture actual error details from tool calls"""

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.tools.unified_api import call_tool
import json

def test_tool(name, **kwargs):
    """Test a tool and capture full error details."""
    print(f"\n{'='*80}")
    print(f"Testing: {name}")
    print(f"Args: {kwargs}")
    print("="*80)
    
    result = call_tool(name, **kwargs)
    
    print(f"Result type: {type(result)}")
    print(f"Result keys: {result.keys() if isinstance(result, dict) else 'N/A'}")
    print("\nFull result:")
    print(json.dumps(result, indent=2, default=str))
    
    return result

# Test search_memories
test_tool("search_memories", query="test")

# Test serendipity_surface
test_tool("serendipity_surface")

# Test with limit
test_tool("serendipity_surface", limit=5)
