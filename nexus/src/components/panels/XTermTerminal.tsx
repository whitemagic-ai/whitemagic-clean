import { useEffect, useRef } from 'react';
import { Terminal } from '@xterm/xterm';
import { FitAddon } from '@xterm/addon-fit';
import { WebLinksAddon } from '@xterm/addon-web-links';
import '@xterm/xterm/css/xterm.css';
import { Play } from 'lucide-react';

export default function XTermTerminal() {
  const terminalRef = useRef<HTMLDivElement>(null);
  const term = useRef<Terminal | null>(null);
  const fitAddon = useRef<FitAddon | null>(null);

  useEffect(() => {
    if (!terminalRef.current) return;

    term.current = new Terminal({
      theme: {
        background: '#0a0a0f', // wm-bg
        foreground: '#e0e0e0',
        cursor: '#a855f7', // wm-purple-400
        selectionBackground: 'rgba(168, 85, 247, 0.3)',
      },
      fontFamily: "'JetBrains Mono', monospace",
      fontSize: 13,
      cursorBlink: true,
    });

    fitAddon.current = new FitAddon();
    term.current.loadAddon(fitAddon.current);
    term.current.loadAddon(new WebLinksAddon());

    term.current.open(terminalRef.current);
    fitAddon.current.fit();

    // Initial message
    term.current.writeln('\x1b[38;2;168;85;247m🔮 WhiteMagic Cascade Terminal\x1b[0m');
    term.current.writeln('Agent execution environment initialized.\n');
    term.current.write('\x1b[38;2;34;211;238m➜\x1b[0m \x1b[38;2;74;222;128m~\x1b[0m ');

    // Handle resize
    const handleResize = () => {
      fitAddon.current?.fit();
    };
    window.addEventListener('resize', handleResize);

    // Basic echo for testing
    let input = '';
    term.current.onData(data => {
      const code = data.charCodeAt(0);
      if (code === 13) { // Enter
        term.current?.write('\r\n');
        if (input.trim() === 'cascade test') {
          term.current?.writeln('\x1b[38;2;251;191;36m[Cascade]\x1b[0m Running test suite across 4 workers...');
        } else if (input.trim() === 'clear') {
          term.current?.clear();
        } else if (input.trim()) {
          term.current?.writeln(`bash: ${input}: command not found`);
        }
        input = '';
        term.current?.write('\x1b[38;2;34;211;238m➜\x1b[0m \x1b[38;2;74;222;128m~\x1b[0m ');
      } else if (code === 127) { // Backspace
        if (input.length > 0) {
          input = input.slice(0, -1);
          term.current?.write('\b \b');
        }
      } else if (code < 32 && code !== 9) {
        // Control chars
      } else {
        input += data;
        term.current?.write(data);
      }
    });

    return () => {
      window.removeEventListener('resize', handleResize);
      term.current?.dispose();
    };
  }, []);

  return (
    <div className="w-full h-full relative">
      <div className="absolute top-2 right-4 z-10 flex gap-2">
        <div className="px-2 py-1 bg-gray-800 rounded border border-gray-700 text-xs text-gray-400 flex items-center gap-1.5">
          <Play size={10} className="text-green-400" />
          Auto-Execute: <span className="text-white">ON</span>
        </div>
      </div>
      <div ref={terminalRef} className="w-full h-full p-2" />
    </div>
  );
}
