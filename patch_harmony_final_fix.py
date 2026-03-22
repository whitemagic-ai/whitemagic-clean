
with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()

# Make sure imports are present and correct
if "GanaActivityHeatmap" not in content:
    content = content.replace("import { Activity, ShieldCheck, Zap, AlertTriangle } from 'lucide-react';", "import { Activity, ShieldCheck, Zap, AlertTriangle } from 'lucide-react';\nimport WuXingWheel from './WuXingWheel';\nimport GanaActivityHeatmap from './GanaActivityHeatmap';\nimport DharmaMetricsPanel from './DharmaMetricsPanel';")

# Ensure export default is at the end
if "export default HarmonyDashboard;" not in content:
    content += "\nexport default HarmonyDashboard;\n"

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

# Clean up unused vars in Dharma and GanaActivity
with open('nexus/src/components/center/DharmaMetricsPanel.tsx') as f:
    dharma = f.read()
dharma = dharma.replace("import React, { useEffect, useState } from 'react';", "import { useEffect, useState } from 'react';")
dharma = dharma.replace("import { Shield, AlertTriangle, CheckCircle, Info } from 'lucide-react';", "import { Shield, AlertTriangle, CheckCircle } from 'lucide-react';")
with open('nexus/src/components/center/DharmaMetricsPanel.tsx', 'w') as f:
    f.write(dharma)

with open('nexus/src/components/center/GanaActivityHeatmap.tsx') as f:
    gana = f.read()
gana = gana.replace("import React, { useEffect, useRef, useState } from 'react';", "import { useEffect, useRef, useState } from 'react';")
gana = gana.replace(".startAngle((d, i) => i * angleStep)", ".startAngle((_d, i) => i * angleStep)")
gana = gana.replace(".endAngle((d, i) => (i + 1) * angleStep)", ".endAngle((_d, i) => (i + 1) * angleStep)")
gana = gana.replace("const paths = g.selectAll('path')", "g.selectAll('path')")
with open('nexus/src/components/center/GanaActivityHeatmap.tsx', 'w') as f:
    f.write(gana)

print("Fixed Harmony Dashboard imports and exports")
