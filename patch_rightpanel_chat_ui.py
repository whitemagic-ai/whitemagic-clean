import re

with open('nexus/src/components/panels/RightPanel.tsx') as f:
    content = f.read()

# Make the chat UI look more like Windsurf Cascade
# Add context pills to user messages
pill_replacement = """                  <div
                    className={`max-w-[85%] rounded-lg px-3 py-2 text-sm ${
                      msg.role === "user"
                        ? "bg-wm-purple-500/20 text-gray-200"
                        : "bg-wm-bg text-gray-300"
                    }`}
                  >
                    {/* Windsurf-style Context Pill */}
                    {msg.role === "user" && msg.content.includes("I am looking at") && (
                      <div className="flex items-center gap-1.5 mb-2 px-2 py-1 bg-wm-purple-500/10 border border-wm-purple-500/30 rounded-md text-[10px] text-wm-purple-300 w-fit">
                        <Code2 size={10} />
                        <span>Current File Context</span>
                      </div>
                    )}

                    {/* Tool Call Status for Assistant */}
                    {msg.role === "assistant" && msg.content.includes("Holographic") && (
                      <div className="flex flex-col gap-2 mb-2">
                        <div className="flex items-center gap-2 text-[10px] bg-[#0d1117] border border-gray-800 rounded p-1.5 text-gray-400">
                          <Search size={10} className="text-blue-400" />
                          <span className="font-mono">arrow_ipc.search_holographic()</span>
                          <span className="ml-auto text-green-400 flex items-center gap-1"><Check size={10}/> Done</span>
                        </div>
                        <div className="flex items-center gap-2 text-[10px] bg-[#0d1117] border border-gray-800 rounded p-1.5 text-gray-400">
                          <Terminal size={10} className="text-purple-400" />
                          <span className="font-mono">sutra.evaluate_intent()</span>
                          <span className="ml-auto text-green-400 flex items-center gap-1"><Check size={10}/> Safe</span>
                        </div>
                      </div>
                    )}

                    {msg.content.replace(/I am looking at `.*`\\.\\s*/, '')}
                  </div>"""

content = re.sub(r'                  <div\n                    className=\{`max-w-\[85%\] rounded-lg px-3 py-2 text-sm \$\{\n                      msg\.role === "user"\n                        \? "bg-wm-purple-500/20 text-gray-200"\n                        : "bg-wm-bg text-gray-300"\n                    \}`\}\n                  >\n                    \{msg\.content\}\n                  <\/div>', pill_replacement, content)

# Make sure imports are present
if "Code2" not in content:
    content = content.replace("import {\n  Send,", "import {\n  Send,\n  Code2,\n  Terminal,\n  Check,")

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Patched RightPanel.tsx chat UI to resemble Cascade")
