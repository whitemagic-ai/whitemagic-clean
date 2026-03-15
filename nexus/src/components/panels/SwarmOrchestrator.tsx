import { useState } from "react";
import { Brain, Zap, Activity, Database, GitBranch, Cpu, Play, CheckCircle, RefreshCw } from "lucide-react";

// Represents a CyberBrain specialized core/agent
interface AgentCore {
  id: string;
  name: string;
  role: "executive" | "logic" | "memory" | "sensory" | "motor";
  status: "idle" | "working" | "sleeping" | "error";
  currentTask?: string;
  load: number; // 0-100
}

export default function SwarmOrchestrator() {
  const [cores] = useState<AgentCore[]>([
    { id: "c1", name: "Global Integrator", role: "executive", status: "working", currentTask: "Aligning subsystem goals", load: 45 },
    { id: "c2", name: "Deductive Engine", role: "logic", status: "idle", load: 5 },
    { id: "c3", name: "SimHash Indexer", role: "memory", status: "working", currentTask: "Consolidating recent episodes", load: 78 },
    { id: "c4", name: "Gan Ying Monitor", role: "sensory", status: "working", currentTask: "Listening to file system events", load: 12 },
    { id: "c5", name: "Tool Dispatcher", role: "motor", status: "idle", load: 2 },
  ]);

  const getRoleIcon = (role: string) => {
    switch (role) {
      case "executive": return <Brain className="text-purple-400" size={16} />;
      case "logic": return <GitBranch className="text-blue-400" size={16} />;
      case "memory": return <Database className="text-amber-400" size={16} />;
      case "sensory": return <Activity className="text-green-400" size={16} />;
      case "motor": return <Zap className="text-red-400" size={16} />;
      default: return <Cpu className="text-gray-400" size={16} />;
    }
  };

  return (
    <div className="flex flex-col h-full bg-wm-bg text-gray-200">
      <div className="p-3 border-b border-wm-border flex justify-between items-center bg-wm-bg-panel">
        <h3 className="text-sm font-semibold flex items-center gap-2">
          <Cpu size={16} className="text-wm-purple-400" />
          CyberBrain Cores
        </h3>
        <button className="p-1 hover:bg-wm-surface rounded text-gray-400">
          <RefreshCw size={14} />
        </button>
      </div>

      <div className="flex-1 overflow-y-auto p-3 space-y-3">
        {cores.map(core => (
          <div key={core.id} className="bg-wm-surface border border-wm-border rounded-lg p-3 relative overflow-hidden group transition-all hover:border-wm-purple-500/30">
            {/* Load indicator background bar */}
            <div 
              className="absolute bottom-0 left-0 h-1 bg-wm-purple-500/20 transition-all duration-1000"
              style={{ width: `${core.load}%` }}
            />
            
            <div className="flex items-start justify-between mb-2">
              <div className="flex items-center gap-2">
                {getRoleIcon(core.role)}
                <span className="font-medium text-sm text-gray-200">{core.name}</span>
              </div>
              <div className="flex items-center gap-1.5 text-[10px] uppercase tracking-wider font-mono">
                {core.status === 'working' && <span className="text-blue-400 flex items-center gap-1"><RefreshCw size={10} className="animate-spin" /> {core.status}</span>}
                {core.status === 'idle' && <span className="text-green-400 flex items-center gap-1"><CheckCircle size={10} /> {core.status}</span>}
                {core.status === 'sleeping' && <span className="text-gray-500 flex items-center gap-1">Zzz</span>}
              </div>
            </div>
            
            {core.currentTask ? (
              <div className="text-xs text-gray-400 font-mono mt-1 truncate">
                {">"} {core.currentTask}
              </div>
            ) : (
              <div className="text-xs text-gray-600 font-mono mt-1 italic">
                Awaiting instructions...
              </div>
            )}
            
            <div className="mt-3 flex gap-2 opacity-0 group-hover:opacity-100 transition-opacity">
              <button className="flex-1 py-1 text-xs bg-wm-bg border border-wm-border rounded hover:bg-wm-purple-500/10 hover:text-wm-purple-300 transition-colors flex items-center justify-center gap-1">
                <Play size={10} /> Wake
              </button>
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
