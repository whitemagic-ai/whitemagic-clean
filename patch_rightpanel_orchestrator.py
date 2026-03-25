
with open('nexus/src/components/panels/RightPanel.tsx', 'r') as f:
    content = f.read()

# Add SwarmOrchestrator import and to RightPanel tabs
if "SwarmOrchestrator" not in content:
    content = content.replace('import CascadeActionPanel from "./CascadeActionPanel";', 'import CascadeActionPanel from "./CascadeActionPanel";\nimport SwarmOrchestrator from "./SwarmOrchestrator";')
    content = content.replace('{activeTab === "orchestrator" && (', '{activeTab === "orchestrator" && <SwarmOrchestrator />}\n      {/* Legacy orchestrator stub (removed) */}\n      {false && (')

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Injected SwarmOrchestrator into RightPanel")
