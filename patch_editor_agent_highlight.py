import re

with open('nexus/src/components/center/MonacoEditor.tsx', 'r') as f:
    content = f.read()

# Add context menu item for inline agent, not just hotkey
injection = """
  const handleEditorDidMount = (editor: any, monaco: any) => {
    editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyS, () => {
      const state = useEditorStore.getState();
      if (state.activeFile) {
        state.saveFile(state.activeFile);
      }
    });

    // Add Windsurf/Cascade-style inline agent command (Cmd+L)
    const triggerAgent = () => {
      const selection = editor.getSelection();
      const text = editor.getModel().getValueInRange(selection);
      const state = useEditorStore.getState();
      
      const event = new CustomEvent('open-ai-chat-with-context', {
        detail: {
          file: state.activeFile,
          selection: text,
          range: selection,
        }
      });
      window.dispatchEvent(event);
    };

    editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyL, triggerAgent);
    
    // Add right-click context menu action
    editor.addAction({
      id: 'aria-inline-agent',
      label: 'Ask ARIA about this...',
      contextMenuGroupId: 'navigation',
      contextMenuOrder: 1.5,
      run: triggerAgent
    });
  };
"""

content = re.sub(r'  const handleEditorDidMount = \(editor: any, monaco: any\) => \{[\s\S]*?  \};\n', injection, content)

with open('nexus/src/components/center/MonacoEditor.tsx', 'w') as f:
    f.write(content)

print("Patched MonacoEditor with context menu agent action")
