import { useEffect, useState } from 'react';
import { Shield, AlertTriangle, CheckCircle } from 'lucide-react';

interface DharmaMetrics {
  systemScore: number;
  recentEvaluations: Array<{
    action: string;
    score: number;
    concerns: string[];
    timestamp: string;
  }>;
  principleDistribution: Record<string, number>;
  boundaryViolations: number;
}

export default function DharmaMetricsPanel() {
  const [metrics, setMetrics] = useState<DharmaMetrics | null>(null);

  useEffect(() => {
    setMetrics(mockDharmaMetrics());
    const interval = setInterval(() => setMetrics(mockDharmaMetrics()), 10000);
    return () => clearInterval(interval);
  }, []);

  if (!metrics) return null;

  return (
    <div className="bg-wm-bg-panel rounded-xl border border-wm-border p-4 flex flex-col h-full">
      <div className="flex justify-between items-center mb-4">
        <h3 className="text-sm font-semibold flex items-center gap-2 text-gray-200">
          <Shield className="w-4 h-4 text-green-400" />
          Dharma Rules Engine
        </h3>
        <div className="flex items-center gap-2">
          <span className="text-xs text-gray-400">System Score</span>
          <span className={`text-lg font-bold ${metrics.systemScore >= 0.8 ? 'text-green-400' : 'text-amber-400'}`}>
            {(metrics.systemScore * 100).toFixed(1)}%
          </span>
        </div>
      </div>

      <div className="grid grid-cols-2 gap-4 mb-6">
        <div className="bg-wm-bg p-3 rounded-lg border border-wm-border">
          <div className="text-xs text-gray-500 mb-1 flex justify-between">
            <span>Violations (24h)</span>
            {metrics.boundaryViolations > 0 ? (
              <AlertTriangle className="w-3 h-3 text-red-400" />
            ) : (
              <CheckCircle className="w-3 h-3 text-green-400" />
            )}
          </div>
          <div className="text-xl font-semibold text-gray-200">{metrics.boundaryViolations}</div>
        </div>

        <div className="bg-wm-bg p-3 rounded-lg border border-wm-border">
          <div className="text-xs text-gray-500 mb-1">Active Rules</div>
          <div className="text-xl font-semibold text-gray-200">{Object.keys(metrics.principleDistribution).length}</div>
        </div>
      </div>

      <div className="flex-1 overflow-y-auto">
        <h4 className="text-xs font-medium text-gray-500 uppercase mb-2">Recent Evaluations (Zodiac Ledger)</h4>
        <div className="space-y-2">
          {metrics.recentEvaluations.map((eval_item, i) => (
            <div key={i} className="text-xs bg-wm-bg p-2 rounded border border-wm-border">
              <div className="flex justify-between items-start mb-1">
                <span className="font-mono text-blue-300 truncate pr-2">{eval_item.action}</span>
                <span className={eval_item.score >= 0.8 ? 'text-green-400' : 'text-amber-400'}>
                  {eval_item.score.toFixed(2)}
                </span>
              </div>
              {eval_item.concerns.length > 0 && (
                <div className="text-amber-500/80 mt-1 flex items-start gap-1">
                  <AlertTriangle className="w-3 h-3 mt-0.5 shrink-0" />
                  <span className="truncate">{eval_item.concerns[0]}</span>
                </div>
              )}
              <div className="text-gray-600 mt-1 text-[10px]">{eval_item.timestamp}</div>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}

function mockDharmaMetrics(): DharmaMetrics {
  return {
    systemScore: 0.94 + (Math.random() * 0.05),
    boundaryViolations: 0,
    principleDistribution: {
      'non-harm': 45,
      'truthfulness': 30,
      'consent': 15,
      'balance': 10
    },
    recentEvaluations: [
      {
        action: 'fs.write(nexus/src/App.tsx)',
        score: 0.98,
        concerns: [],
        timestamp: new Date().toLocaleTimeString()
      },
      {
        action: 'shell.exec(npm run build)',
        score: 0.85,
        concerns: ['High compute cost'],
        timestamp: new Date(Date.now() - 5000).toLocaleTimeString()
      },
      {
        action: 'memory.create(User Preferences)',
        score: 0.99,
        concerns: [],
        timestamp: new Date(Date.now() - 15000).toLocaleTimeString()
      }
    ]
  };
}
