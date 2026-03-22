
with open('nexus/src/components/panels/LeftPanel.tsx', 'r') as f:
    content = f.read()

# Add back the tab bar that was removed by the crude string replacement
tab_bar = """
  return (
    <div className="flex flex-col h-full bg-wm-bg-panel border-r border-wm-border">
      {/* Tab bar */}
      <div className="flex border-b border-wm-border flex-shrink-0">
        {tabs.map((t) => {
          const Icon = t.icon;
          return (
            <button
              key={t.id}
              onClick={() => useNexusStore.getState().setLeftTab(t.id)}
              className={`flex-1 p-2 flex items-center justify-center transition ${
                tab === t.id
                  ? "text-wm-purple-400 border-b-2 border-wm-purple-400 bg-wm-purple-500/10"
                  : "text-gray-500 hover:text-gray-300 hover:bg-wm-border/30"
              }`}
              title={t.title}
            >
              <Icon size={14} />
            </button>
          );
        })}
      </div>

      <div className="overflow-y-auto flex-1 py-2">
"""

content = content.replace('  return (\n    <div className="flex flex-col h-full bg-wm-bg-panel border-r border-wm-border">\n      {/* ... keeping the rest of the file minimal ... */}\n      <div className="overflow-y-auto flex-1 py-2">', tab_bar)

with open('nexus/src/components/panels/LeftPanel.tsx', 'w') as f:
    f.write(content)

print("Restored LeftPanel tab bar")
