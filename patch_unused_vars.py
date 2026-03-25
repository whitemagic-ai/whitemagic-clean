
# Clean up unused imports across files causing TS errors
files_to_clean = [
    'nexus/src/components/AppWithPalette.tsx',
    'nexus/src/components/RadialPalette.tsx',
    'nexus/src/components/center/GhostTextAutocompletion.tsx',
    'nexus/src/components/center/HarmonyDashboard.tsx',
    'nexus/src/components/panels/AgentToolsPanel.tsx',
    'nexus/src/components/panels/CascadeActionPanel.tsx',
    'nexus/src/components/panels/DiffModal.tsx',
    'nexus/src/components/panels/XTermTerminal.tsx',
    'nexus/src/components/RecursiveEvolutionDashboard.tsx'
]

for file in files_to_clean:
    try:
        with open(file, 'r') as f:
            content = f.read()
        
        # Very crude but effective for these specific files
        content = content.replace("import React, { useState, useEffect } from 'react';", "import { useState, useEffect } from 'react';")
        content = content.replace("import React, { useEffect, useState } from 'react';", "import { useEffect, useState } from 'react';")
        content = content.replace("import React, { useState } from 'react';", "import { useState } from 'react';")
        content = content.replace("import React, { useEffect, useRef } from 'react';", "import { useEffect, useRef } from 'react';")
        content = content.replace("import React from 'react';", "")
        content = content.replace("import { Play, RotateCcw, FileEdit, Terminal } from 'lucide-react';", "import { RotateCcw, FileEdit, Terminal } from 'lucide-react';")
        
        with open(file, 'w') as f:
            f.write(content)
    except FileNotFoundError:
        pass

# Fix specific unused vars
with open('nexus/src/components/RecursiveEvolutionDashboard.tsx', 'r') as f:
    content = f.read()
content = content.replace('const [patterns, setPatterns]', 'const [patterns]')
content = content.replace('const [adaptations, setAdaptations]', 'const [adaptations]')
with open('nexus/src/components/RecursiveEvolutionDashboard.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/GhostTextAutocompletion.tsx', 'r') as f:
    content = f.read()
content = content.replace('const handleType = (e: any) => {\n      // call inference backend via Arrow IPC\n      // inject ghost text into editor\n    };', '')
with open('nexus/src/components/center/GhostTextAutocompletion.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/panels/RightPanel.tsx', 'r') as f:
    content = f.read()
content = content.replace('import AgentToolsPanel from "./AgentToolsPanel";', '')
with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Cleaned unused variables")
