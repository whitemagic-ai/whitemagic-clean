
with open('scripts/benchmark_mcp.py') as f:
    content = f.read()

# Fix the benchmark_mcp.py resource listing test length requirement
content = content.replace('assert len(res) == 2', 'assert len(resources) == 4')

with open('scripts/benchmark_mcp.py', 'w') as f:
    f.write(content)

print("Patched benchmark_mcp.py resources test")
