
with open('nexus/src/components/panels/RightPanel.tsx', 'r') as f:
    content = f.read()

# Add Fast Context / Global Search to the chat input (like Windsurf's @ command)
injection = """
  const handleInput = (e: React.ChangeEvent<HTMLInputElement>) => {
    const val = e.target.value;
    setInput(val);
    
    // Simple mock of @-mentions for context
    if (val.endsWith('@')) {
      // Trigger a contextual menu (in a real app, this would open a popup)
      console.log("Trigger fast context search");
      // Pre-fill some holographic context
      setTimeout(() => {
        setInput(prev => prev + "workspace ");
      }, 500);
    }
  };
"""

if "handleInput" not in content:
    content = content.replace("const handleSend =", injection + "\n  const handleSend =")
    content = content.replace('onChange={(e) => setInput(e.target.value)}', 'onChange={handleInput}')
    
    with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
        f.write(content)
    print("Patched RightPanel with @-mention fast context search stub")
