import { useState, useEffect } from 'react';

import { Terminal, Check, X, Code2, AlertTriangle } from 'lucide-react';
import DiffModal from './DiffModal';

interface ToolCall {
  id: string;
  type: string;
  args: any;
  status: 'pending' | 'approved' | 'rejected' | 'running' | 'completed' | 'failed';
  guna?: 'sattva' | 'rajas' | 'tamas';
}

export default function AgentToolsPanel() {
  const [toolCalls, setToolCalls] = useState<ToolCall[]>([]);
  const [activeDiff, setActiveDiff] = useState<{file: string, original: string, updated: string} | null>(null);

  // In a real implementation, we would listen to Iceoryx2 'wm/commands' channel
  // For now we mock an incoming Tamasic request that needs approval
  useEffect(() => {
    const timer = setTimeout(() => {
      setToolCalls([{
        id: 'tc_' + Date.now(),
        type: 'proposePatch',
        args: {
          file: 'src/main.rs',
          original: 'fn main() {\n  println!("Hello");\n}',
          updated: 'fn main() {\n  println!("Hello MandalaOS");\n}',
        },
        status: 'pending',
        guna: 'tamas' // Needs approval
      }]);
    }, 3000);
    return () => clearTimeout(timer);
  }, []);

  const approveTool = (id: string) => {
    setToolCalls(calls => calls.map(tc => 
      tc.id === id ? { ...tc, status: 'running' } : tc
    ));
    
    // Mock completion
    setTimeout(() => {
      setToolCalls(calls => calls.map(tc => 
        tc.id === id ? { ...tc, status: 'completed' } : tc
      ));
    }, 1500);
  };

  const rejectTool = (id: string) => {
    setToolCalls(calls => calls.map(tc => 
      tc.id === id ? { ...tc, status: 'rejected' } : tc
    ));
  };

  return (
    <div className="flex flex-col h-full bg-gray-900 overflow-hidden">
      <div className="p-3 border-b border-gray-800 flex items-center justify-between bg-gray-900">
        <h3 className="text-sm font-medium text-gray-300 flex items-center gap-2">
          <Terminal className="w-4 h-4 text-blue-400" />
          Karmic Consent Queue
        </h3>
        <div className="px-2 py-0.5 rounded bg-gray-800 text-xs text-gray-400">
          {toolCalls.filter(t => t.status === 'pending').length} Pending
        </div>
      </div>
      
      <div className="flex-1 overflow-y-auto p-2 space-y-2">
        {toolCalls.length === 0 ? (
          <div className="flex flex-col items-center justify-center h-full text-gray-500 gap-2">
            <Check className="w-8 h-8 opacity-20" />
            <span className="text-sm">All operations cleared</span>
          </div>
        ) : (
          toolCalls.map(tc => (
            <div key={tc.id} className="bg-gray-800 border border-gray-700 rounded-lg p-3">
              <div className="flex justify-between items-start mb-2">
                <div className="flex items-center gap-2">
                  {tc.guna === 'tamas' && <AlertTriangle className="w-4 h-4 text-purple-400" />}
                  <span className="font-mono text-sm text-blue-300">{tc.type}</span>
                </div>
                <StatusBadge status={tc.status} />
              </div>
              
              <div className="bg-gray-900 rounded p-2 mb-3 text-xs font-mono text-gray-400 truncate">
                {tc.args.file || JSON.stringify(tc.args)}
              </div>
              
              {tc.status === 'pending' && (
                <div className="flex gap-2">
                  <button 
                    onClick={() => rejectTool(tc.id)}
                    className="flex-1 px-2 py-1.5 rounded bg-gray-700 hover:bg-red-500/20 text-gray-300 hover:text-red-300 transition-colors text-xs flex justify-center items-center gap-1"
                  >
                    <X className="w-3 h-3" /> Reject
                  </button>
                  
                  {tc.type === 'proposePatch' && (
                    <button 
                      onClick={() => setActiveDiff({
                        file: tc.args.file,
                        original: tc.args.original,
                        updated: tc.args.updated
                      })}
                      className="flex-1 px-2 py-1.5 rounded bg-gray-700 hover:bg-gray-600 text-gray-300 transition-colors text-xs flex justify-center items-center gap-1"
                    >
                      <Code2 className="w-3 h-3" /> View Diff
                    </button>
                  )}
                  
                  <button 
                    onClick={() => approveTool(tc.id)}
                    className="flex-1 px-2 py-1.5 rounded bg-blue-600 hover:bg-blue-500 text-white transition-colors text-xs flex justify-center items-center gap-1"
                  >
                    <Check className="w-3 h-3" /> Approve
                  </button>
                </div>
              )}
            </div>
          ))
        )}
      </div>

      {activeDiff && (
        <DiffModal
          isOpen={true}
          file={activeDiff.file}
          original={activeDiff.original}
          updated={activeDiff.updated}
          onClose={() => setActiveDiff(null)}
          onApprove={() => {
            // Find the pending patch and approve it
            const tc = toolCalls.find(c => c.type === 'proposePatch' && c.args.file === activeDiff.file && c.status === 'pending');
            if (tc) approveTool(tc.id);
          }}
        />
      )}
    </div>
  );
}

function StatusBadge({ status }: { status: string }) {
  const styles = {
    pending: 'bg-yellow-500/10 text-yellow-400 border-yellow-500/20',
    running: 'bg-blue-500/10 text-blue-400 border-blue-500/20',
    completed: 'bg-green-500/10 text-green-400 border-green-500/20',
    rejected: 'bg-red-500/10 text-red-400 border-red-500/20',
    failed: 'bg-red-500/10 text-red-400 border-red-500/20',
  }[status] || 'bg-gray-500/10 text-gray-400 border-gray-500/20';

  return (
    <span className={`text-[10px] uppercase tracking-wider px-2 py-0.5 rounded-full border ${styles}`}>
      {status}
    </span>
  );
}
