
with open('nexus/src/components/center/CenterContent.tsx') as f:
    content = f.read()

# Replace Dashboard with HarmonyDashboard
content = content.replace('import Dashboard from "./Dashboard";', 'import HarmonyDashboard from "./HarmonyDashboard";')
content = content.replace('{tab === "dashboard" && <Dashboard />}', '{tab === "dashboard" && <HarmonyDashboard />}')

with open('nexus/src/components/center/CenterContent.tsx', 'w') as f:
    f.write(content)

print("Patched CenterContent.tsx")
