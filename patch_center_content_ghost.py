
with open('nexus/src/components/center/CenterContent.tsx', 'r') as f:
    content = f.read()

# Add GhostTextAutocompletion
if "GhostTextAutocompletion" not in content:
    content = content.replace('import GlobalSearch from "./GlobalSearch";', 'import GlobalSearch from "./GlobalSearch";\nimport GhostTextAutocompletion from "./GhostTextAutocompletion";')
    content = content.replace('return (', 'return (\n    <>\n      <GhostTextAutocompletion />')
    content = content.replace('    </div>\n  );\n}', '    </div>\n    </>\n  );\n}')

with open('nexus/src/components/center/CenterContent.tsx', 'w') as f:
    f.write(content)

print("Patched CenterContent with GhostTextAutocompletion")
