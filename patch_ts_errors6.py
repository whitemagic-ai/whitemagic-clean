import re

with open('nexus/src/components/panels/LeftPanel.tsx', 'r') as f:
    content = f.read()
    
# Remove the usage of SAMPLE_TREE entirely since we injected FileTree
content = re.sub(r'\{SAMPLE_TREE\.map\(\(node, i\) => \([\s\S]*?\)\)\}', '<FileTree node={rootNode} depth={0} />', content)

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/GlobalSearch.tsx', 'r') as f:
    content = f.read()

content = content.replace("openFile({\n          name: fileName,", "openFile({\n          path: res.file,\n          name: fileName,")

with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
    f.write(content)

print("Fixed the last TS errors")
