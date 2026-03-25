import re

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'r') as f:
    content = f.read()

# Fix the broken HTML structure
replacement = """
      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        {/* Left Column: Guna Distribution & Wu Xing */}
        <div className="col-span-1 lg:col-span-2 space-y-6 flex flex-col h-full">
          <div className="bg-gray-800 rounded-xl border border-gray-700 p-6">
            <h2 className="text-lg font-light mb-6 text-gray-300">Guna Distribution (Process Intent)</h2>
            <div className="space-y-6">
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-teal-400 text-sm tracking-wide">SATTVA (Purity / Read)</span>
                  <span className="text-teal-400 font-mono text-sm">{stats.sattvic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-teal-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.sattvic}%` }} />
                </div>
              </div>
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-amber-400 text-sm tracking-wide">RAJAS (Activity / Write)</span>
                  <span className="text-amber-400 font-mono text-sm">{stats.rajasic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-amber-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.rajasic}%` }} />
                </div>
              </div>
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-violet-400 text-sm tracking-wide">TAMAS (Inertia / Delete)</span>
                  <span className="text-violet-400 font-mono text-sm">{stats.tamasic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-violet-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.tamasic}%` }} />
                </div>
              </div>
            </div>
          </div>
          
          <div className="flex-1 bg-gray-800 rounded-xl border border-gray-700 p-4">
            <GanaActivityHeatmap />
          </div>
        </div>

        {/* Right Column: WuXing and Dharma */}
        <div className="col-span-1 flex flex-col gap-6 h-full">
          <div className="h-[250px]">
             <WuXingWheel currentPhase={stats.phase || 'EARTH'} />
          </div>
          <div className="flex-1 min-h-[300px]">
            <DharmaMetricsPanel />
          </div>
        </div>
      </div>
    </div>
  );
};
"""

# Replace everything after the metric cards
content = re.sub(r'      \{/\* Guna Distribution \*/\}[\s\S]*', replacement, content)

# Add imports
if "WuXingWheel" not in content:
    content = content.replace("import { Activity, ShieldCheck, Zap, AlertTriangle } from 'lucide-react';", "import { Activity, ShieldCheck, Zap, AlertTriangle } from 'lucide-react';\nimport WuXingWheel from './WuXingWheel';\nimport GanaActivityHeatmap from './GanaActivityHeatmap';\nimport DharmaMetricsPanel from './DharmaMetricsPanel';")

# Add phase
if "phase:" not in content:
    content = content.replace("  tamasic: number;\n}", '  tamasic: number;\n  phase?: "WOOD" | "FIRE" | "EARTH" | "METAL" | "WATER";\n}')
    content = content.replace("    tamasic: 10\n  });", '    tamasic: 10,\n    phase: "EARTH"\n  });')

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

print("Fixed Harmony Dashboard HTML structure")
