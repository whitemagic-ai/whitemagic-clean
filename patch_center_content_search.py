
with open('nexus/src/components/center/CenterContent.tsx', 'r') as f:
    content = f.read()

# Add GlobalSearch
if "GlobalSearch" not in content:
    content = content.replace('import ToolGraph from "./ToolGraph";', 'import ToolGraph from "./ToolGraph";\nimport GlobalSearch from "./GlobalSearch";')
    content = content.replace('{tab === "tools" && <ToolGraph />}', '{tab === "tools" && <ToolGraph />}\n      {tab === "search" && <GlobalSearch />}')

with open('nexus/src/components/center/CenterContent.tsx', 'w') as f:
    f.write(content)

print("Patched CenterContent with GlobalSearch")
