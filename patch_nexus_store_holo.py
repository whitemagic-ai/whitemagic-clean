
with open('nexus/src/store/nexus.ts') as f:
    content = f.read()

content = content.replace('export type CenterTab = "editor" | "dashboard" | "graph" | "tools";', 'export type CenterTab = "editor" | "dashboard" | "graph" | "tools" | "holographic";')

with open('nexus/src/store/nexus.ts', 'w') as f:
    f.write(content)

print("Added holographic tab to store")
