import re

with open('nexus/src/components/panels/LeftPanel.tsx') as f:
    content = f.read()

# Fix the dummy SAMPLE_TREE data missing path properties
content = content.replace('{ name: "whitemagic", type: "folder", children: [', '{ name: "whitemagic", type: "folder", path: "/workspace/whitemagic", children: [')
content = content.replace('{ name: "core", type: "folder", children: [', '{ name: "core", type: "folder", path: "/workspace/whitemagic/core", children: [')
content = content.replace('{ name: "resonance", type: "folder", children: [', '{ name: "resonance", type: "folder", path: "/workspace/whitemagic/core/resonance", children: [')
content = content.replace('{ name: "governor.py", type: "file" },', '{ name: "governor.py", type: "file", path: "/workspace/whitemagic/core/resonance/governor.py" },')
content = content.replace('{ name: "gardens", type: "folder", children: [', '{ name: "gardens", type: "folder", path: "/workspace/whitemagic/gardens", children: [')
content = content.replace('{ name: "joy/", type: "folder", children: [] },', '{ name: "joy/", type: "folder", path: "/workspace/whitemagic/gardens/joy", children: [] },')
content = content.replace('{ name: "love/", type: "folder", children: [] },', '{ name: "love/", type: "folder", path: "/workspace/whitemagic/gardens/love", children: [] },')
content = content.replace('{ name: "wisdom/", type: "folder", children: [] },', '{ name: "wisdom/", type: "folder", path: "/workspace/whitemagic/gardens/wisdom", children: [] },')
content = content.replace('{ name: "dharma/", type: "folder", children: [', '{ name: "dharma/", type: "folder", path: "/workspace/whitemagic/gardens/dharma", children: [')
content = content.replace('{ name: "synthesis.py", type: "file" },', '{ name: "synthesis.py", type: "file", path: "/workspace/whitemagic/gardens/dharma/synthesis.py" },')
content = content.replace('{ name: "tools", type: "folder", children: [', '{ name: "tools", type: "folder", path: "/workspace/whitemagic/tools", children: [')
content = content.replace('{ name: "registry.py", type: "file" },', '{ name: "registry.py", type: "file", path: "/workspace/whitemagic/tools/registry.py" },')
content = content.replace('{ name: "unified_api.py", type: "file" },', '{ name: "unified_api.py", type: "file", path: "/workspace/whitemagic/tools/unified_api.py" },')
content = content.replace('{ name: "__init__.py", type: "file" },', '{ name: "__init__.py", type: "file", path: "/workspace/whitemagic/__init__.py" },')
content = content.replace('{ name: "run_mcp.py", type: "file" },', '{ name: "run_mcp.py", type: "file", path: "/workspace/whitemagic/run_mcp.py" },')
# Just delete the other unused sample nodes to avoid having to fix them all
content = re.sub(r'\{ name: "cascade", type: "folder"[\s\S]*?\{ name: "run_mcp\.py", type: "file", path: "/workspace/whitemagic/run_mcp\.py" \},\n    \]\n  \}\n\];', '{ name: "run_mcp.py", type: "file", path: "/workspace/whitemagic/run_mcp.py" },\n    ]\n  }\n];', content)

# Fix the window.__TAURI_INTERNALS__ ts errors
content = content.replace('if (window.__TAURI_INTERNALS__) {', 'if ((window as any).__TAURI_INTERNALS__) {')

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

with open('nexus/src/components/status/StatusBar.tsx') as f:
    sb = f.read()
    sb = sb.replace('if (window.__TAURI_INTERNALS__) {', 'if ((window as any).__TAURI_INTERNALS__) {')
    with open('nexus/src/components/status/StatusBar.tsx', 'w') as f:
        f.write(sb)

with open('nexus/src/store/editor.ts') as f:
    ed = f.read()
    ed = ed.replace('if (window.__TAURI_INTERNALS__) {', 'if ((window as any).__TAURI_INTERNALS__) {')
    with open('nexus/src/store/editor.ts', 'w') as f:
        f.write(ed)

with open('nexus/src/components/center/GlobalSearch.tsx') as f:
    gs = f.read()
    gs = gs.replace('if (window.__TAURI_INTERNALS__) {', 'if ((window as any).__TAURI_INTERNALS__) {')
    with open('nexus/src/components/center/GlobalSearch.tsx', 'w') as f:
        f.write(gs)

print("Fixed LeftPanel.tsx and TAURI_INTERNALS TS errors")
