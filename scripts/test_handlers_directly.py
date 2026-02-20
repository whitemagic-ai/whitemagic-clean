#!/usr/bin/env python3
"""Test handlers directly to bypass middleware"""

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

print("Testing search_memories handler directly...")
try:
    from whitemagic.tools.handlers.memory import handle_search_memories
    result = handle_search_memories(query="test", limit=5)
    print(f"✓ search_memories works: {type(result)}")
    print(f"  Keys: {result.keys() if isinstance(result, dict) else 'N/A'}")
    if isinstance(result, dict) and result.get('status') == 'error':
        print(f"  ERROR: {result.get('error', 'Unknown')}")
except Exception as e:
    print(f"✗ search_memories failed: {e}")
    import traceback
    traceback.print_exc()

print("\nTesting serendipity_surface handler directly...")
try:
    from whitemagic.tools.handlers.synthesis import handle_serendipity_surface
    result = handle_serendipity_surface()
    print(f"✓ serendipity_surface works: {type(result)}")
    print(f"  Keys: {result.keys() if isinstance(result, dict) else 'N/A'}")
    if isinstance(result, dict) and result.get('status') == 'error':
        print(f"  ERROR: {result.get('error', 'Unknown')}")
except Exception as e:
    print(f"✗ serendipity_surface failed: {e}")
    import traceback
    traceback.print_exc()

print("\nTesting via dispatch table...")
try:
    from whitemagic.tools.dispatch_table import DISPATCH_TABLE
    
    handler = DISPATCH_TABLE.get("search_memories")
    print(f"search_memories handler: {handler}")
    if handler:
        result = handler(query="test", limit=5)
        print(f"  Result: {type(result)}, status={result.get('status') if isinstance(result, dict) else 'N/A'}")
    
    handler = DISPATCH_TABLE.get("serendipity_surface")
    print(f"serendipity_surface handler: {handler}")
    if handler:
        result = handler()
        print(f"  Result: {type(result)}, status={result.get('status') if isinstance(result, dict) else 'N/A'}")
        
except Exception as e:
    print(f"✗ Dispatch table test failed: {e}")
    import traceback
    traceback.print_exc()
