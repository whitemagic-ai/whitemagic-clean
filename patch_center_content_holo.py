
with open('nexus/src/components/center/CenterContent.tsx', 'r') as f:
    content = f.read()

# Add HolographicView to center content
if "HolographicView" not in content:
    content = content.replace('import ToolGraph from "./ToolGraph";', 'import ToolGraph from "./ToolGraph";\nimport HolographicView from "./HolographicView";')
    content = content.replace('{tab === "tools" && <ToolGraph />}', '{tab === "tools" && <ToolGraph />}\n      {tab === "holographic" && <HolographicView />}')

with open('nexus/src/components/center/CenterContent.tsx', 'w') as f:
    f.write(content)

# Add Tab to Header
with open('nexus/src/components/Header.tsx', 'r') as f:
    content = f.read()

if "Hologram" not in content:
    content = content.replace('{ id: "tools", label: "Tool Graph", icon: Box },', '{ id: "tools", label: "Tool Graph", icon: Box },\n  { id: "holographic", label: "4D Hologram", icon: Globe },')
    # Globe might not be imported, lets just use Box or Network if not, but Network is already imported in header
    content = content.replace('import { Layout, FileText, Activity, Network, Box } from "lucide-react";', 'import { Layout, FileText, Activity, Network, Box, Globe } from "lucide-react";')
    
    with open('nexus/src/components/Header.tsx', 'w') as f:
        f.write(content)

print("Added HolographicView to CenterContent and Header")
