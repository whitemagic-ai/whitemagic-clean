import { useState } from 'react';
import { useNexusStore } from '../store/nexus';
import { Network, Database, Shield, Zap, Sparkles, Activity, Settings, Cpu } from 'lucide-react';

const WEDGE_CONFIGS = [
  { id: 'immune', label: 'Immune Guard', icon: Shield, color: 'text-red-400', bgHover: 'hover:bg-red-400/20', guna: 'sattva' },
  { id: 'memory', label: 'Memory Core', icon: Database, color: 'text-blue-400', bgHover: 'hover:bg-blue-400/20', guna: 'rajas' },
  { id: 'mesh', label: 'Mesh Swarm', icon: Network, color: 'text-indigo-400', bgHover: 'hover:bg-indigo-400/20', guna: 'rajas' },
  { id: 'dream', label: 'Dream Engine', icon: Sparkles, color: 'text-purple-400', bgHover: 'hover:bg-purple-400/20', guna: 'sattva' },
  { id: 'hardware', label: 'Hardware', icon: Cpu, color: 'text-gray-400', bgHover: 'hover:bg-gray-400/20', guna: 'tamas' },
  { id: 'energy', label: 'Energy Flux', icon: Zap, color: 'text-yellow-400', bgHover: 'hover:bg-yellow-400/20', guna: 'rajas' },
  { id: 'harmony', label: 'Harmony', icon: Activity, color: 'text-green-400', bgHover: 'hover:bg-green-400/20', guna: 'sattva' },
  { id: 'settings', label: 'System', icon: Settings, color: 'text-slate-400', bgHover: 'hover:bg-slate-400/20', guna: 'tamas' },
];

interface RadialPaletteProps {
  isOpen: boolean;
  onClose: () => void;
}

const RadialPalette: React.FC<RadialPaletteProps> = ({ isOpen, onClose }) => {
  const [activeWedge, setActiveWedge] = useState<string | null>(null);
  const { status } = useNexusStore();

  if (!isOpen) return null;

  return (
    <div className="fixed inset-0 z-50 flex items-center justify-center bg-black/60 backdrop-blur-sm" onClick={onClose}>
      <div 
        className="relative w-96 h-96 rounded-full border border-gray-700/50 flex items-center justify-center"
        onClick={(e) => e.stopPropagation()}
      >
        {/* Center Orb */}
        <div className="absolute w-24 h-24 rounded-full bg-gray-900 border-2 border-gray-700 shadow-[0_0_30px_rgba(0,0,0,0.5)] z-10 flex flex-col items-center justify-center group cursor-pointer hover:border-blue-500/50 transition-colors">
          <div className={`w-3 h-3 rounded-full mb-1 shadow-[0_0_10px] ${status.dharmaOk ? 'bg-green-400 shadow-green-400/50' : 'bg-red-400 shadow-red-400/50'}`} />
          <span className="text-xs text-gray-400 font-mono">BINDÚ</span>
        </div>

        {/* Wedges */}
        {WEDGE_CONFIGS.map((wedge, index) => {
          const angle = (index * 360) / WEDGE_CONFIGS.length;
          const radius = 120;
          const x = Math.cos((angle - 90) * (Math.PI / 180)) * radius;
          const y = Math.sin((angle - 90) * (Math.PI / 180)) * radius;

          const isActive = activeWedge === wedge.id;

          return (
            <div
              key={wedge.id}
              className={`absolute w-16 h-16 rounded-2xl flex flex-col items-center justify-center cursor-pointer transition-all duration-300 ${
                isActive ? 'scale-125 z-20 bg-gray-800 border border-gray-600' : 'hover:scale-110 z-0 bg-gray-900/80 border border-transparent'
              } ${wedge.bgHover}`}
              style={{
                transform: `translate(${x}px, ${y}px) scale(${isActive ? 1.25 : 1})`,
              }}
              onMouseEnter={() => setActiveWedge(wedge.id)}
              onMouseLeave={() => setActiveWedge(null)}
            >
              <wedge.icon className={`w-6 h-6 mb-1 ${wedge.color}`} />
            </div>
          );
        })}

        {/* Info Panel for Active Wedge */}
        {activeWedge && (
          <div className="absolute top-[110%] w-64 p-4 bg-gray-900 border border-gray-700 rounded-xl shadow-2xl text-center backdrop-blur-md">
            <h3 className="text-white font-medium mb-1">
              {WEDGE_CONFIGS.find(w => w.id === activeWedge)?.label}
            </h3>
            <div className="flex justify-center gap-2 mb-2">
              <span className="text-[10px] uppercase tracking-widest text-gray-500 px-2 py-0.5 rounded-full border border-gray-800">
                GUNA: {WEDGE_CONFIGS.find(w => w.id === activeWedge)?.guna}
              </span>
            </div>
            <p className="text-xs text-gray-400">
              Select to route tasks to this agent swarm or view specific telemetry.
            </p>
          </div>
        )}
      </div>
    </div>
  );
};

export default RadialPalette;
