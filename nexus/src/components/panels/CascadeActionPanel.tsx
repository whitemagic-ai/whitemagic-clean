import { useState } from 'react';
import { RotateCcw, FileEdit, Terminal } from 'lucide-react';


interface ActionPlan {
  id: string;
  description: string;
  steps: {
    type: 'edit' | 'terminal' | 'read';
    target: string;
    status: 'pending' | 'running' | 'success' | 'failed';
    detail?: string;
  }[];
}

// Mimics the Cascade multi-step action execution panel
export default function CascadeActionPanel() {
  const [activePlan, setActivePlan] = useState<ActionPlan | null>({
    id: 'plan_1',
    description: 'Refactor Rust IPC bridge to use channels',
    steps: [
      { type: 'read', target: 'src/ipc.rs', status: 'success' },
      { type: 'edit', target: 'src/ipc.rs', status: 'running', detail: 'Replacing Mutex with channel receiver' },
      { type: 'edit', target: 'src/main.rs', status: 'pending', detail: 'Update IPC init' },
      { type: 'terminal', target: 'cargo check', status: 'pending' },
    ]
  });

  if (!activePlan) return null;

  return (
    <div className="bg-gray-900 border-t border-gray-800 p-3 flex flex-col gap-2">
      <div className="flex items-center justify-between text-xs font-medium text-gray-300">
        <span className="flex items-center gap-1.5">
          <span className="w-2 h-2 rounded-full bg-blue-500 animate-pulse" />
          Cascade is acting...
        </span>
        <button 
          className="px-2 py-1 bg-red-500/10 text-red-400 hover:bg-red-500/20 rounded border border-red-500/20 transition-colors"
          onClick={() => setActivePlan(null)}
        >
          Cancel
        </button>
      </div>
      
      <div className="text-sm text-gray-200 mb-1">{activePlan.description}</div>
      
      <div className="flex flex-col gap-1.5">
        {activePlan.steps.map((step, i) => (
          <div key={i} className="flex items-center gap-2 text-xs bg-gray-800 p-2 rounded border border-gray-700">
            {step.type === 'edit' && <FileEdit className={`w-3.5 h-3.5 ${step.status === 'success' ? 'text-green-400' : 'text-blue-400'}`} />}
            {step.type === 'terminal' && <Terminal className={`w-3.5 h-3.5 ${step.status === 'success' ? 'text-green-400' : 'text-purple-400'}`} />}
            {step.type === 'read' && <RotateCcw className={`w-3.5 h-3.5 ${step.status === 'success' ? 'text-green-400' : 'text-gray-400'}`} />}
            
            <div className="flex-1 truncate">
              <span className="text-gray-300 font-mono mr-2">{step.target}</span>
              {step.detail && <span className="text-gray-500">{step.detail}</span>}
            </div>
            
            {step.status === 'running' && <span className="text-blue-400 font-mono text-[10px] animate-pulse">RUNNING</span>}
            {step.status === 'success' && <span className="text-green-400 font-mono text-[10px]">DONE</span>}
            {step.status === 'pending' && <span className="text-gray-500 font-mono text-[10px]">WAITING</span>}
          </div>
        ))}
      </div>
    </div>
  );
}
