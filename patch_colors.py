
with open('nexus/tailwind.config.js', 'r') as f:
    content = f.read()

# Make sure we have the full color palette from the previous dashboards
if "cyan" not in content:
    content = content.replace("colors: {", "colors: {\n        cyan: { 400: '#22d3ee', 500: '#06b6d4' },")

with open('nexus/tailwind.config.js', 'w') as f:
    f.write(content)

print("Checked tailwind config")
