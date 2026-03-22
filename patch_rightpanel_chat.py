import re

with open('nexus/src/components/panels/RightPanel.tsx') as f:
    content = f.read()

# Add logic to handle real user input in the chat
chat_state_injection = """
  const [messages, setMessages] = useState<Message[]>([
    { id: "1", role: "assistant", content: "I am ready. The WhiteMagic core is online." },
  ]);
  const [input, setInput] = useState("");
  const messagesEndRef = useRef<HTMLDivElement>(null);

  const scrollToBottom = () => {
    messagesEndRef.current?.scrollIntoView({ behavior: "smooth" });
  };

  useEffect(() => {
    scrollToBottom();
  }, [messages]);

  const handleSend = () => {
    if (!input.trim()) return;
    
    // Add user message
    const userMsg: Message = { id: Date.now().toString(), role: "user", content: input };
    setMessages(prev => [...prev, userMsg]);
    setInput("");
    
    // In a real implementation, this would send an IPC message to the Rust backend
    // which forwards it to the Python AI core. For now, simulate a response.
    setTimeout(() => {
      const aiMsg: Message = { 
        id: (Date.now() + 1).toString(), 
        role: "assistant", 
        content: `I received your intent. Holographic Context has been injected via Arrow IPC. Auto-executing Sattvic analysis...` 
      };
      setMessages(prev => [...prev, aiMsg]);
    }, 1000);
  };
"""

# Replace the static messages state
content = re.sub(r'const \[messages, setMessages\] = useState<Message\[\]>\(\[\n    \{ id: "1", role: "assistant", content: "Ready\." \},\n  \]\);', chat_state_injection, content)

# Replace the chat input area
chat_input_replacement = """
            {/* Input */}
            <div className="p-3 border-t border-wm-border bg-wm-bg-panel">
              <div className="relative">
                <input
                  type="text"
                  value={input}
                  onChange={(e) => setInput(e.target.value)}
                  onKeyDown={(e) => { if (e.key === 'Enter') handleSend(); }}
                  placeholder="Command the swarm..."
                  className="w-full bg-wm-bg border border-wm-border rounded-lg pl-3 pr-10 py-2 text-sm focus:outline-none focus:border-wm-purple-500/50"
                />
                <button 
                  onClick={handleSend}
                  className="absolute right-2 top-1/2 -translate-y-1/2 text-wm-purple-400 hover:text-wm-purple-300 p-1"
                >
                  <Send size={14} />
                </button>
              </div>
            </div>
"""

content = re.sub(r'\{\/\* Input \*\/\}.*?<\/div>\n            <\/div>', chat_input_replacement, content, flags=re.DOTALL)

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Patched chat in RightPanel.tsx")
