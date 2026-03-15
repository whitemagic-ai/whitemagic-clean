
import { X, Check, FileCode2 } from 'lucide-react';
import * as Diff from 'diff';

interface DiffModalProps {
  isOpen: boolean;
  onClose: () => void;
  onApprove: () => void;
  file: string;
  original: string;
  updated: string;
}

export default function DiffModal({ isOpen, onClose, onApprove, file, original, updated }: DiffModalProps) {
  if (!isOpen) return null;

  const diff = Diff.diffLines(original || '', updated || '');

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/80 backdrop-blur-sm p-4">
      <div className="bg-gray-900 border border-gray-700 rounded-xl w-full max-w-4xl h-[80vh] flex flex-col shadow-2xl">
        <div className="flex items-center justify-between p-4 border-b border-gray-800">
          <div className="flex items-center gap-2 text-gray-300">
            <FileCode2 className="w-5 h-5 text-blue-400" />
            <h2 className="font-mono text-sm">{file}</h2>
          </div>
          <button onClick={onClose} className="p-1 hover:bg-gray-800 rounded text-gray-400 hover:text-white transition-colors">
            <X className="w-5 h-5" />
          </button>
        </div>
        
        <div className="flex-1 overflow-auto p-4 font-mono text-sm bg-[#0d1117]">
          {diff.map((part, i) => {
            const color = part.added ? 'bg-green-500/20 text-green-300' : 
                         part.removed ? 'bg-red-500/20 text-red-300' : 'text-gray-400';
            const prefix = part.added ? '+' : part.removed ? '-' : ' ';
            
            return (
              <div key={i} className={`whitespace-pre ${color}`}>
                {part.value.split('\n').filter((l, idx, arr) => !(idx === arr.length-1 && l === '')).map((line, j) => (
                  <div key={j} className="flex">
                    <span className="w-6 opacity-50 select-none">{prefix}</span>
                    <span>{line}</span>
                  </div>
                ))}
              </div>
            );
          })}
        </div>

        <div className="p-4 border-t border-gray-800 flex justify-end gap-3 bg-gray-900/50">
          <button 
            onClick={onClose}
            className="px-4 py-2 rounded bg-gray-800 text-gray-300 hover:bg-gray-700 transition-colors"
          >
            Reject Change
          </button>
          <button 
            onClick={() => { onApprove(); onClose(); }}
            className="px-4 py-2 rounded bg-blue-600 text-white flex items-center gap-2 hover:bg-blue-500 transition-colors"
          >
            <Check className="w-4 h-4" />
            Approve & Apply
          </button>
        </div>
      </div>
    </div>
  );
}
