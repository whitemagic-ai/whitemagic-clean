import re

with open('nexus/src/components/status/StatusBar.tsx') as f:
    content = f.read()

pulse_ui = """
      <div className="flex items-center gap-4 px-3 py-1 bg-[#1e1e2e] rounded-md border border-[#3b3b4f]">
        <div className="flex items-center gap-2">
          <Activity size={12} className="text-green-400" />
          <span className="font-mono tracking-widest text-[10px] text-green-400">PULSE</span>
        </div>
        <div className="flex items-center gap-1.5 opacity-80">
          <Waveform values={activityHistory} color="#4ade80" />
        </div>
        <div className="flex items-center gap-3 border-l border-[#3b3b4f] pl-3">
          <div className="flex flex-col">
            <span className="text-[9px] text-gray-500 uppercase">Tokens/s</span>
            <span className="text-[10px] text-gray-300 font-mono">1.2k</span>
          </div>
          <div className="flex flex-col">
            <span className="text-[9px] text-gray-500 uppercase">Context</span>
            <span className="text-[10px] text-blue-300 font-mono">84%</span>
          </div>
        </div>
      </div>
"""

# Let's be very explicit with where we put it. Right after the CPU/RAM metrics:
content = re.sub(r'(<div className="w-16">.*?</div>\n        </div>\n      </div>)', r'\1\n' + pulse_ui, content, flags=re.DOTALL)

with open('nexus/src/components/status/StatusBar.tsx', 'w') as f:
    f.write(content)

print("Fixed StatusBar TS error properly")
