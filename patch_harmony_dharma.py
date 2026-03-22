
with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()

if "DharmaMetricsPanel" not in content:
    content = content.replace("import GanaActivityHeatmap from './GanaActivityHeatmap';", "import GanaActivityHeatmap from './GanaActivityHeatmap';\nimport DharmaMetricsPanel from './DharmaMetricsPanel';")

    # Let's adjust the grid layout to fit it all
    grid_update = """      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6 mb-6">
        {/* Core Harmony Metrics */}
        <div className="col-span-1 lg:col-span-3 flex gap-4">
"""

    # We will just append Dharma Metrics to the bottom row
    dharma_block = """
        {/* Dharma Metrics Panel */}
        <div className="col-span-1 lg:col-span-3">
          <DharmaMetricsPanel />
        </div>
      </div>
"""

    content = content.replace('      </div>\n    </div>\n  );\n}', '      </div>\n' + dharma_block + '    </div>\n  );\n}')

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

print("Injected DharmaMetricsPanel into HarmonyDashboard")
