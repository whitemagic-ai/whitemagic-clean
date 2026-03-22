import re

with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()

content = re.sub(r'\{\n        name: "core",', '{ name: "core", path: "/workspace/whitemagic/core",', content)

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

print("Patched core path in LeftPanel")
