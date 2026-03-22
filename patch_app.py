
with open('nexus/src/App.tsx') as f:
    content = f.read()

content = content.replace("import CommandPalette from \"./components/CommandPalette\";", "import CommandPalette from \"./components/CommandPalette\";\nimport AppWithPalette from \"./components/AppWithPalette\";")

# Replace App with a wrapper to AppWithPalette
content = """import AppWithPalette from "./components/AppWithPalette";

export default function App() {
  return <AppWithPalette />;
}
"""

with open('nexus/src/App.tsx', 'w') as f:
    f.write(content)

print("Patched App.tsx")
