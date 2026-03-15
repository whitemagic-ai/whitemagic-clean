import { useState } from 'react';
import WuXingWheel from './WuXingWheel';
import GanaActivityHeatmap from './GanaActivityHeatmap';
import DharmaMetricsPanel from './DharmaMetricsPanel';
import { useNexusStore } from '../../store/nexus';
import { Activity, ShieldCheck, Zap, AlertTriangle } from 'lucide-react';

interface HarmonyStats {
  cpu: number;
  memory: number;
  energy: number;
  dharma: number;
  sattvic: number;
  rajasic: number;
  tamasic: number;
  phase?: "WOOD" | "FIRE" | "EARTH" | "METAL" | "WATER";
}

const HarmonyDashboard: React.FC = () => {
  const { wuXingPhase } = useNexusStore();
  
  // Mock data for now, later we'll connect this to IPC
  const [stats] = useState<HarmonyStats>({
    cpu: 12,
    memory: 45,
    energy: 88,
    dharma: 100,
    sattvic: 60,
    rajasic: 30,
    tamasic: 10,
    phase: "EARTH"
  });

  const getPhaseColor = () => {
    switch (wuXingPhase) {
      case 'wood': return 'text-green-400';
      case 'fire': return 'text-red-400';
      case 'earth': return 'text-yellow-400';
      case 'metal': return 'text-gray-400';
      case 'water': return 'text-blue-400';
      default: return 'text-purple-400';
    }
  };

  return (
    <div className="flex flex-col h-full bg-gray-900 text-gray-100 p-6 overflow-y-auto">
      <div className="flex justify-between items-center mb-8">
        <h1 className="text-2xl font-light tracking-wider flex items-center gap-3">
          <Activity className={getPhaseColor()} />
          Harmony Vector
        </h1>
        <div className="px-3 py-1 rounded-full bg-gray-800 border border-gray-700 text-sm">
          Phase: <span className={getPhaseColor() + " capitalize font-medium"}>{wuXingPhase}</span>
        </div>
      </div>

      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-4 gap-6 mb-8">
        {/* Metric Cards */}
        <div className="bg-gray-800 p-5 rounded-xl border border-gray-700 flex flex-col items-center justify-center relative overflow-hidden group">
          <div className="absolute inset-0 bg-gradient-to-br from-blue-500/10 to-transparent opacity-0 group-hover:opacity-100 transition-opacity" />
          <Zap className="w-8 h-8 text-blue-400 mb-3" />
          <div className="text-3xl font-mono mb-1">{stats.energy}%</div>
          <div className="text-xs text-gray-400 uppercase tracking-widest">Coherence</div>
        </div>

        <div className="bg-gray-800 p-5 rounded-xl border border-gray-700 flex flex-col items-center justify-center relative overflow-hidden group">
          <div className="absolute inset-0 bg-gradient-to-br from-green-500/10 to-transparent opacity-0 group-hover:opacity-100 transition-opacity" />
          <ShieldCheck className="w-8 h-8 text-green-400 mb-3" />
          <div className="text-3xl font-mono mb-1">{stats.dharma}%</div>
          <div className="text-xs text-gray-400 uppercase tracking-widest">Dharma Score</div>
        </div>

        <div className="bg-gray-800 p-5 rounded-xl border border-gray-700 flex flex-col items-center justify-center relative overflow-hidden group">
          <div className="absolute inset-0 bg-gradient-to-br from-amber-500/10 to-transparent opacity-0 group-hover:opacity-100 transition-opacity" />
          <Activity className="w-8 h-8 text-amber-400 mb-3" />
          <div className="text-3xl font-mono mb-1">{stats.cpu}%</div>
          <div className="text-xs text-gray-400 uppercase tracking-widest">Processing Load</div>
        </div>

        <div className="bg-gray-800 p-5 rounded-xl border border-gray-700 flex flex-col items-center justify-center relative overflow-hidden group">
          <div className="absolute inset-0 bg-gradient-to-br from-purple-500/10 to-transparent opacity-0 group-hover:opacity-100 transition-opacity" />
          <AlertTriangle className="w-8 h-8 text-purple-400 mb-3" />
          <div className="text-3xl font-mono mb-1">{stats.tamasic}%</div>
          <div className="text-xs text-gray-400 uppercase tracking-widest">Entropy (Tamas)</div>
        </div>
      </div>


      <div className="grid grid-cols-1 lg:grid-cols-3 gap-6">
        {/* Left Column: Guna Distribution & Wu Xing */}
        <div className="col-span-1 lg:col-span-2 space-y-6 flex flex-col h-full">
          <div className="bg-gray-800 rounded-xl border border-gray-700 p-6">
            <h2 className="text-lg font-light mb-6 text-gray-300">Guna Distribution (Process Intent)</h2>
            <div className="space-y-6">
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-teal-400 text-sm tracking-wide">SATTVA (Purity / Read)</span>
                  <span className="text-teal-400 font-mono text-sm">{stats.sattvic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-teal-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.sattvic}%` }} />
                </div>
              </div>
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-amber-400 text-sm tracking-wide">RAJAS (Activity / Write)</span>
                  <span className="text-amber-400 font-mono text-sm">{stats.rajasic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-amber-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.rajasic}%` }} />
                </div>
              </div>
              <div>
                <div className="flex justify-between mb-2">
                  <span className="text-violet-400 text-sm tracking-wide">TAMAS (Inertia / Delete)</span>
                  <span className="text-violet-400 font-mono text-sm">{stats.tamasic}%</span>
                </div>
                <div className="w-full bg-gray-900 rounded-full h-2 overflow-hidden">
                  <div className="bg-violet-400 h-2 rounded-full transition-all duration-1000 ease-out" style={{ width: `${stats.tamasic}%` }} />
                </div>
              </div>
            </div>
          </div>
          
          <div className="flex-1 bg-gray-800 rounded-xl border border-gray-700 p-4">
            <GanaActivityHeatmap />
          </div>
        </div>

        {/* Right Column: WuXing and Dharma */}
        <div className="col-span-1 flex flex-col gap-6 h-full">
          <div className="h-[250px]">
             <WuXingWheel currentPhase={stats.phase || 'EARTH'} />
          </div>
          <div className="flex-1 min-h-[300px]">
            <DharmaMetricsPanel />
          </div>
        </div>
      </div>
    </div>
  );
};

export default HarmonyDashboard;
