
with open('nexus/src/components/panels/RightPanel.tsx', 'r') as f:
    content = f.read()

# Add AgentToolsPanel as a tab or sub-panel
if "AgentToolsPanel" not in content:
    content = content.replace('import { useNexusStore, type RightTab } from "../../store/nexus";', 'import { useNexusStore, type RightTab } from "../../store/nexus";\nimport AgentToolsPanel from "./AgentToolsPanel";')
    content = content.replace('{activeTab === "orchestrator" && (', '{activeTab === "orchestrator" && (\n          <AgentToolsPanel />\n        )}\n\n        {/* HIDDEN OLD CONTENT */}\n        {false && activeTab === "orchestrator" && (')

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Patched RightPanel.tsx correctly")
