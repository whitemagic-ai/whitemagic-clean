
with open('nexus/src/components/panels/BottomPanel.tsx') as f:
    content = f.read()

# Replace the old terminal panel with the new XTermTerminal
if "XTermTerminal" not in content:
    content = content.replace('import TerminalPanel from "./TerminalPanel";', 'import XTermTerminal from "./XTermTerminal";\nimport TerminalPanel from "./TerminalPanel";')
    content = content.replace('{activeTab === "terminal" && <TerminalPanel />}', '{activeTab === "terminal" && <XTermTerminal />}')

with open('nexus/src/components/panels/BottomPanel.tsx', 'w') as f:
    f.write(content)

print("Patched BottomPanel.tsx to use XTermTerminal")
