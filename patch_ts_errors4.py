
# Additional cleanup
with open('nexus/src/components/center/GlobalSearch.tsx') as f:
    content = f.read()
content = content.replace("import { Search, FileText } from 'lucide-react';", "import { Search, FileText } from 'lucide-react';\nimport { invoke } from '@tauri-apps/api/core';")
with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/MonacoEditor.tsx') as f:
    content = f.read()
content = content.replace("const saveFile = useEditorStore((s) => s.saveFile);", "")
with open('nexus/src/components/center/MonacoEditor.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()
content = content.replace("const [stats, setStats]", "const [stats]")
with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/panels/AgentToolsPanel.tsx') as f:
    content = f.read()
content = content.replace("import { useNexusStore } from '../../store/nexus';", "")
content = content.replace("import { Terminal, Check, X, Code2, AlertTriangle, Play } from 'lucide-react';", "import { Terminal, Check, X, Code2, AlertTriangle } from 'lucide-react';")
with open('nexus/src/components/panels/AgentToolsPanel.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/panels/CascadeActionPanel.tsx') as f:
    content = f.read()
content = content.replace("import { invoke } from '@tauri-apps/api/core';", "")
with open('nexus/src/components/panels/CascadeActionPanel.tsx', 'w') as f:
    f.write(content)

print("Additional TS cleanup done")
