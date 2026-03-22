import re

with open('nexus/src/components/RadialPalette.tsx') as f:
    content = f.read()
content = content.replace("import { useState, useEffect } from 'react';", "import { useState } from 'react';")
with open('nexus/src/components/RadialPalette.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/GhostTextAutocompletion.tsx') as f:
    content = f.read()
content = content.replace("import { useEffect, useRef } from 'react';", "import { useEffect } from 'react';")
with open('nexus/src/components/center/GhostTextAutocompletion.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/GlobalSearch.tsx') as f:
    content = f.read()
content = content.replace("import { Search, FileText } from 'lucide-react';\nimport { invoke } from '@tauri-apps/api/core';\nimport { invoke } from '@tauri-apps/api/core';", "import { Search, FileText } from 'lucide-react';\nimport { invoke } from '@tauri-apps/api/core';")
content = content.replace("id: res.file,", "")
with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()
content = content.replace("import { useEffect, useState } from 'react';", "import { useState } from 'react';")
with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/panels/BottomPanel.tsx') as f:
    content = f.read()
content = content.replace('import TerminalPanel from "./TerminalPanel";\n', '')
with open('nexus/src/components/panels/BottomPanel.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()
# Completely remove SAMPLE_TREE from LeftPanel.tsx as it is not used anyway
content = re.sub(r'const SAMPLE_TREE: TreeNode\[\] = \[[\s\S]*?\];', '', content)
with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

print("Final TS cleanup pass")
