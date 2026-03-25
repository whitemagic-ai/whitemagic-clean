
with open('nexus/src/components/center/MonacoEditor.tsx', 'r') as f:
    content = f.read()

# Add save file command
if "saveFile =" not in content:
    content = content.replace("const updateContent = useEditorStore((s) => s.updateContent);", "const updateContent = useEditorStore((s) => s.updateContent);\n  const saveFile = useEditorStore((s) => s.saveFile);")

# Inject handleEditorDidMount for Cmd+S mapping
injection = """
  const handleEditorDidMount = (editor: any, monaco: any) => {
    editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyS, () => {
      const state = useEditorStore.getState();
      if (state.activeFile) {
        state.saveFile(state.activeFile);
      }
    });
  };
"""

if "handleEditorDidMount" not in content:
    content = content.replace("const currentFile = openFiles.find((f) => f.path === activeFile);", injection + "\n  const currentFile = openFiles.find((f) => f.path === activeFile);")
    
    # Add onMount prop to Editor
    content = content.replace("<Editor", "<Editor\n        onMount={handleEditorDidMount}")

with open('nexus/src/components/center/MonacoEditor.tsx', 'w') as f:
    f.write(content)

print("Patched MonacoEditor.tsx with save command")
