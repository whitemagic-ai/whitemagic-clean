import re

# Fix LeftPanel.tsx remaining sample tree path
with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()

content = re.sub(r'\{\n            name: "resonance",', '{ name: "resonance", path: "/workspace/whitemagic/core/resonance",', content)

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

# Fix GlobalSearch
with open('nexus/src/components/center/GlobalSearch.tsx') as f:
    content = f.read()

content = content.replace("openFile({\n          name: fileName,", "openFile({\n          path: res.file,\n          name: fileName,")

with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
    f.write(content)

print("Patched remaining TS errors")
