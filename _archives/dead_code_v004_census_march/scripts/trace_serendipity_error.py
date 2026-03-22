#!/usr/bin/env python3
"""Trace serendipity_surface through the full middleware stack"""

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

import logging
logging.basicConfig(level=logging.DEBUG)

# Patch the middleware wrapper to show exceptions
from whitemagic.tools import middleware

original_wrap = middleware._wrap

def debug_wrap(mw, next_fn, name):
    wrapped = original_wrap(mw, next_fn, name)
    def debug_wrapped(ctx):
        print(f"\n>>> Entering middleware: {name}")
        print(f"    Tool: {ctx.tool_name}")
        try:
            result = wrapped(ctx)
            print(f"<<< Exiting middleware: {name} - Result status: {result.get('status') if isinstance(result, dict) else 'N/A'}")
            return result
        except Exception as e:
            print(f"!!! Exception in middleware {name}: {e}")
            import traceback
            traceback.print_exc()
            raise
    return debug_wrapped

middleware._wrap = debug_wrap

# Now test
from whitemagic.tools.unified_api import call_tool

print("="*80)
print("Testing serendipity_surface with full middleware trace")
print("="*80)

result = call_tool("serendipity_surface")
print(f"\nFinal result: {result.get('status') if isinstance(result, dict) else result}")
