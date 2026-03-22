import re

with open('scripts/benchmark_mcp.py') as f:
    content = f.read()

# Fix the benchmark_mcp.py issues related to unified_api imports and tempdir limits
# In the parallel test, use prat_router directly to avoid unified_api loop
replacement = """    def call_parallel():
        from whitemagic.tools.prat_router import route_prat_call
        def single_call(_i):
            return route_prat_call("gana_chariot", "archaeology", {"search_term": "rust"})
        
        with ThreadPoolExecutor(max_workers=n) as ex:
            futs = [ex.submit(single_call, i) for i in range(n)]
            results = [f.result() for f in futs]
            return len(results) == n"""

content = re.sub(r'    def call_parallel\(\):\n        from whitemagic\.tools\.unified_api import call_tool\n        def single_call\(_i\):\n            return call_tool\("archaeology", search_term="rust"\)\n        \n        with ThreadPoolExecutor\(max_workers=n\) as ex:\n            futs = \[ex\.submit\(single_call, i\) for i in range\(n\)\]\n            results = \[f\.result\(\) for f in futs\]\n            return len\(results\) == n', replacement, content)

with open('scripts/benchmark_mcp.py', 'w') as f:
    f.write(content)

print("Patched benchmark_mcp.py")
