import { useRef, useEffect, useState } from "react";
import { Leaf, Cloud, Wifi, TreeDeciduous, Activity } from "lucide-react";
import { useNexusStore } from "../../store/nexus";
import { invoke } from "@tauri-apps/api/core";

function Waveform({
  values,
  color,
  width = 60,
  height = 18,
}: {
  values: number[];
  color: string;
  width?: number;
  height?: number;
}) {
  const canvasRef = useRef<HTMLCanvasElement>(null);

  useEffect(() => {
    const canvas = canvasRef.current;
    if (!canvas) return;
    const ctx = canvas.getContext("2d");
    if (!ctx) return;

    ctx.clearRect(0, 0, width, height);
    ctx.strokeStyle = color;
    ctx.lineWidth = 1.5;
    ctx.beginPath();

    const step = width / (values.length - 1);
    values.forEach((v, i) => {
      const y = height - (v / 100) * height;
      if (i === 0) ctx.moveTo(0, y);
      else ctx.lineTo(i * step, y);
    });
    ctx.stroke();
  }, [values, color, width, height]);

  return (
    <canvas
      ref={canvasRef}
      width={width}
      height={height}
      className="opacity-80"
    />
  );
}

export default function StatusBar() {

  useEffect(() => {
    // Try to get IPC status from Rust backend
    const checkIpc = async () => {
      try {
        if ((window as any).__TAURI_INTERNALS__) {
          const res = await invoke("get_ipc_status");
          console.log("IPC Status:", res);
        }
      } catch (e) {
        console.error(e);
      }
    };
    checkIpc();
    const interval = setInterval(checkIpc, 5000);
    return () => clearInterval(interval);
  }, []);

  const status = useNexusStore((s) => s.status);
  const [cpuHistory, setCpuHistory] = useState<number[]>(Array(20).fill(0));
  const [memHistory, setMemHistory] = useState<number[]>(Array(20).fill(0));
  const [activityHistory, setActivityHistory] = useState<number[]>(
    Array(20).fill(0)
  );

  useEffect(() => {
    const interval = setInterval(() => {
      setCpuHistory((prev) => {
        const v = Math.min(
          100,
          Math.max(0, status.cpu + (Math.random() - 0.5) * 8)
        );
        return [...prev.slice(1), v];
      });
      setMemHistory((prev) => {
        const pct = (status.memory / 16) * 100;
        const v = Math.min(
          100,
          Math.max(0, pct + (Math.random() - 0.5) * 4)
        );
        return [...prev.slice(1), v];
      });
      setActivityHistory((prev) => {
        const v = 20 + Math.random() * 30;
        return [...prev.slice(1), v];
      });
    }, 500);
    return () => clearInterval(interval);
  }, [status]);

  return (
    <footer className="flex items-center justify-between px-4 py-1.5 bg-wm-surface border-t border-wm-border text-xs flex-shrink-0 select-none">
      {/* Roots (Hardware) */}
      <div className="flex items-center gap-3">
        <div className="flex items-center gap-1.5">
          <Leaf size={12} className="text-green-400" />
          <span className="text-gray-500">Roots</span>
        </div>
        <div className="flex items-center gap-2">
          <span className="text-gray-500 w-8">CPU</span>
          <Waveform values={cpuHistory} color="#4ade80" />
          <span
            className={`w-10 text-right ${
              status.cpu > 80 ? "text-red-400" : "text-green-400"
            }`}
          >
            {Math.round(status.cpu || 0)}%
          </span>
        </div>
        <div className="flex items-center gap-2">
          <span className="text-gray-500 w-8">RAM</span>
          <Waveform values={memHistory} color="#38bdf8" />
          <span className="w-12 text-right text-cyan-400">
            {(status.memory || 0).toFixed(1)}GB
          </span>
        </div>
      </div>


      {/* Pulse Telemetry (Ported from hub) */}
      <div className="flex items-center gap-4 px-3 py-1 bg-[#1e1e2e] rounded-md border border-[#3b3b4f] mx-auto">
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

      {/* Trunk (WhiteMagic Core) */}
      <div className="flex items-center gap-3">
        <div className="flex items-center gap-1.5">
          <TreeDeciduous size={12} className="text-wm-purple-400" />
          <span className="text-gray-500">Trunk</span>
        </div>
        <Waveform values={activityHistory} color="#a855f7" width={80} />
        <span className="text-gray-400">
          {status.memoryCount || 0} memories
        </span>
        <span className="text-gray-400">
          {status.patternCount || 0} patterns
        </span>
        <span
          className={`flex items-center gap-1 ${
            status.dharmaOk ? "text-green-400" : "text-red-400"
          }`}
        >
          <span
            className={`w-1.5 h-1.5 rounded-full ${
              status.dharmaOk
                ? "bg-green-500 animate-pulse"
                : "bg-red-500"
            }`}
          />
          Dharma
        </span>
      </div>

      {/* Canopy (Connections) */}
      <div className="flex items-center gap-3">
        <div className="flex items-center gap-1.5">
          <Cloud size={12} className="text-wm-cyan-400" />
          <span className="text-gray-500">Canopy</span>
        </div>
        <div className="flex items-center gap-2">
          <span
            className={`w-1.5 h-1.5 rounded-full ${
              status.apiConnected ? "bg-green-500" : "bg-yellow-500"
            }`}
          />
          <span className="text-gray-400">API</span>
        </div>
        <div className="flex items-center gap-2">
          <Wifi size={10} className="text-gray-500" />
          <span className="text-gray-400">v0.1.0</span>
        </div>
      </div>
    </footer>
  );
}
