import { useState } from 'react';
import { Search, FileText } from 'lucide-react';
import { invoke } from '@tauri-apps/api/core';
import { useEditorStore } from '../../store/editor';

interface SearchResult {
  file: string;
  line: number;
  content: string;
  match: string;
}

export default function GlobalSearch() {
  const [query, setQuery] = useState('');
  const [results, setResults] = useState<SearchResult[]>([]);
  const [searching, setSearching] = useState(false);
  const openFile = useEditorStore(s => s.openFile);

  const handleSearch = async (e: React.FormEvent) => {
    e.preventDefault();
    if (!query.trim()) return;
    
    setSearching(true);
    try {
      // In a real implementation this would call ripgrep via Tauri
      // For now, we simulate a fast Arrow IPC search
      setTimeout(() => {
        setResults([
          { file: '/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py', line: 114, content: '                self._processes[module] = [p for p in self._processes[module] if p.poll() is None]', match: 'process' },
          { file: '/home/lucas/Desktop/whitemagicdev/nexus/src-tauri/src/ipc.rs', line: 42, content: '        let node = match NodeBuilder::new().create::<ipc::Service>() {', match: 'node' },
        ]);
        setSearching(false);
      }, 300);
    } catch (e) {
      console.error(e);
      setSearching(false);
    }
  };

  const handleResultClick = async (res: SearchResult) => {
    try {
      if ((window as any).__TAURI_INTERNALS__) {
        const content = await invoke<string>("read_file", { filePath: res.file });
        const fileName = res.file.split('/').pop() || res.file;
        
        openFile({
          path: res.file,
          name: fileName,
          language: fileName.endsWith(".ts") || fileName.endsWith(".tsx") ? "typescript" : 
                   fileName.endsWith(".rs") ? "rust" : 
                   fileName.endsWith(".py") ? "python" : "plaintext",
          content,
          dirty: false
        });
      }
    } catch (e) {
      console.error("Failed to open file", e);
    }
  };

  return (
    <div className="h-full flex flex-col bg-gray-900 text-gray-200">
      <div className="p-4 border-b border-gray-800 bg-gray-900">
        <form onSubmit={handleSearch} className="relative">
          <Search className="absolute left-3 top-1/2 -translate-y-1/2 text-gray-500 w-4 h-4" />
          <input
            autoFocus
            type="text"
            value={query}
            onChange={e => setQuery(e.target.value)}
            placeholder="Search codebase (Fast Context via Arrow IPC)..."
            className="w-full bg-gray-800 border border-gray-700 rounded-lg pl-10 pr-4 py-2 text-sm focus:outline-none focus:border-blue-500/50 focus:ring-1 focus:ring-blue-500/50 transition-all"
          />
        </form>
      </div>

      <div className="flex-1 overflow-y-auto p-2">
        {searching && (
          <div className="text-center p-8 text-gray-500 text-sm animate-pulse">
            Scanning 5D Holographic Map...
          </div>
        )}
        
        {!searching && results.length > 0 && (
          <div className="space-y-1">
            <div className="px-3 py-2 text-xs font-medium text-gray-500 uppercase tracking-wider">
              {results.length} results found
            </div>
            {results.map((res, i) => (
              <button
                key={i}
                onClick={() => handleResultClick(res)}
                className="w-full text-left p-3 hover:bg-gray-800 rounded-lg group transition-colors border border-transparent hover:border-gray-700"
              >
                <div className="flex items-center gap-2 mb-1.5">
                  <FileText className="w-3.5 h-3.5 text-blue-400" />
                  <span className="text-xs text-blue-300 truncate">{res.file}</span>
                  <span className="text-[10px] text-gray-500 ml-auto">Line {res.line}</span>
                </div>
                <div className="text-xs font-mono text-gray-400 bg-[#0d1117] p-2 rounded truncate border border-gray-800 group-hover:border-gray-600">
                  {res.content}
                </div>
              </button>
            ))}
          </div>
        )}
        
        {!searching && query && results.length === 0 && (
          <div className="text-center p-8 text-gray-500 text-sm">
            No matches found in the active context.
          </div>
        )}
      </div>
    </div>
  );
}
