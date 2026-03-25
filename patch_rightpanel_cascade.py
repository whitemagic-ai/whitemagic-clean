
with open('nexus/src/components/panels/RightPanel.tsx', 'r') as f:
    content = f.read()

# Make sure imports are present
if "CascadeActionPanel" not in content:
    content = content.replace("import AgentToolsPanel from \"./AgentToolsPanel\";", "import AgentToolsPanel from \"./AgentToolsPanel\";\nimport CascadeActionPanel from \"./CascadeActionPanel\";")
    
    # Inject it between the messages list and the input area
    content = content.replace("{/* Input */}", "<CascadeActionPanel />\n            {/* Input */}")

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Patched RightPanel.tsx to include CascadeActionPanel")
