import re

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'r') as f:
    content = f.read()

# Add WuXingWheel import and usage
if "WuXingWheel" not in content:
    content = content.replace("import { Activity, Shield, Zap, AlertTriangle, Layers, Database } from 'lucide-react';", "import { Activity, Shield, Zap, AlertTriangle, Layers, Database } from 'lucide-react';\nimport WuXingWheel from './WuXingWheel';")
    
    # Inject it into the dashboard grid layout
    wuxing_block = """
        {/* Wu Xing Wheel */}
        <div className="col-span-1 lg:col-span-1">
          <WuXingWheel currentPhase={stats.phase} />
        </div>
        
        {/* Radar/Guna Distribution could go here but we just push it to col-span-2 */}
        <div className="col-span-1 lg:col-span-2">
"""
    
    content = re.sub(r'        \{/\* Guna Distribution \*/\}', wuxing_block + '        {/* Guna Distribution */}', content)
    
    # Add phase to mock stats
    content = content.replace('      setStats({\n        coherence: 0.88,', '      setStats({\n        coherence: 0.88,\n        phase: "EARTH" as any,')
    content = content.replace('  entropy: number;\n}', '  entropy: number;\n  phase: "WOOD" | "FIRE" | "EARTH" | "METAL" | "WATER";\n}')
    content = content.replace('const [stats] = useState<HarmonyStats>({\n    coherence: 0.88,\n    dharmaScore: 1.0,\n    load: 0.12,\n    entropy: 0.10,\n  });', 'const [stats] = useState<HarmonyStats>({\n    coherence: 0.88,\n    dharmaScore: 1.0,\n    load: 0.12,\n    entropy: 0.10,\n    phase: "EARTH",\n  });')

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

print("Injected WuXingWheel into HarmonyDashboard")
