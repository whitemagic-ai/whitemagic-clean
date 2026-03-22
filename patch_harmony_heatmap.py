import re

with open('nexus/src/components/center/HarmonyDashboard.tsx') as f:
    content = f.read()

# Replace the Guna Distribution radar stub with the GanaActivityHeatmap
if "GanaActivityHeatmap" not in content:
    content = content.replace("import WuXingWheel from './WuXingWheel';", "import WuXingWheel from './WuXingWheel';\nimport GanaActivityHeatmap from './GanaActivityHeatmap';")

    heatmap_block = """
        {/* Gana Activity */}
        <div className="col-span-1 lg:col-span-2">
          <GanaActivityHeatmap />
        </div>
"""

    content = re.sub(r'        \{/\* Guna Distribution \*/\}', heatmap_block + '        {/* Guna Distribution */}', content)

with open('nexus/src/components/center/HarmonyDashboard.tsx', 'w') as f:
    f.write(content)

print("Injected GanaActivityHeatmap into HarmonyDashboard")
