
with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()

if "import WuXingWheel" not in content:
    content = content.replace("import { useState } from 'react';", "import { useState } from 'react';\nimport WuXingWheel from './WuXingWheel';\nimport GanaActivityHeatmap from './GanaActivityHeatmap';\nimport DharmaMetricsPanel from './DharmaMetricsPanel';")

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

print("Fixed Harmony Dashboard imports properly")
