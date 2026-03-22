
with open('nexus/src/components/panels/RightPanel.tsx') as f:
    content = f.read()

# Add event listener for inline context injection
injection = """
  useEffect(() => {
    const handleContext = (e: any) => {
      setTab("chat");

      const { file, selection, range } = e.detail;
      const contextMsg = `I am looking at \\`${file}\\`${range ? ` (lines ${range.startLineNumber}-${range.endLineNumber})` : ''}.`;

      setInput(prev => prev + (prev ? '\\n' : '') + contextMsg);

      if (selection) {
        // You could also add the selection to the chat context internally without showing it in the input box,
        // but for now we'll just focus the chat box.
        const el = document.getElementById('ai-chat-input');
        if (el) el.focus();
      }
    };

    window.addEventListener('open-ai-chat-with-context', handleContext);
    return () => window.removeEventListener('open-ai-chat-with-context', handleContext);
  }, [setTab]);
"""

if "open-ai-chat-with-context" not in content:
    content = content.replace("const scrollToBottom = () => {", injection + "\n  const scrollToBottom = () => {")
    content = content.replace('<input\n                  type="text"', '<input\n                  id="ai-chat-input"\n                  type="text"')

    with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
        f.write(content)
    print("Patched RightPanel with Cmd+L event listener")
