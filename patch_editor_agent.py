
with open('nexus/src/components/center/MonacoEditor.tsx') as f:
    content = f.read()

# Add inline agent command (Cmd+L like Windsurf)
injection = """
    // Add Windsurf/Cascade-style inline agent command (Cmd+L)
    editor.addCommand(monaco.KeyMod.CtrlCmd | monaco.KeyCode.KeyL, () => {
      const selection = editor.getSelection();
      const text = editor.getModel().getValueInRange(selection);
      
      // Trigger the AI chat with the selected context
      const event = new CustomEvent('open-ai-chat-with-context', {
        detail: {
          file: state.activeFile,
          selection: text,
          range: selection,
        }
      });
      window.dispatchEvent(event);
    });
"""

if "KeyL" not in content:
    content = content.replace("state.saveFile(state.activeFile);\n      }\n    });", "state.saveFile(state.activeFile);\n      }\n    });" + injection)

    with open('nexus/src/components/center/MonacoEditor.tsx', 'w') as f:
        f.write(content)
    print("Patched MonacoEditor with Cmd+L inline agent shortcut")
