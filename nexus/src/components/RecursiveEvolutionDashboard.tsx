/**
 * Recursive Evolution Dashboard
 * Real-time monitoring of pattern discovery, adaptations, and system coherence
 */

import { useState, useEffect } from 'react';

interface Pattern {
  id: string;
  sequence: string[];
  frequency: number;
  confidence: number;
  type: string;
}

interface Adaptation {
  id: string;
  type: string;
  description: string;
  applied: boolean;
  impact_score: number;
}

interface Metrics {
  events_processed: number;
  patterns_discovered: number;
  adaptations_applied: number;
  system_coherence: number;
  cache_hit_rate: number;
  latency_saved_ms: number;
}

export const RecursiveEvolutionDashboard: React.FC = () => {
  const [patterns] = useState<Pattern[]>([]);
  const [adaptations] = useState<Adaptation[]>([]);
  const [metrics, setMetrics] = useState<Metrics>({
    events_processed: 0,
    patterns_discovered: 0,
    adaptations_applied: 0,
    system_coherence: 0,
    cache_hit_rate: 0,
    latency_saved_ms: 0,
  });
  const [isConnected, setIsConnected] = useState(false);

  useEffect(() => {
    // In production, this would connect to WebSocket
    // For now, simulate with polling
    const interval = setInterval(() => {
      fetchMetrics();
    }, 2000);

    return () => clearInterval(interval);
  }, []);

  const fetchMetrics = async () => {
    try {
      // In production: const response = await fetch('/api/evolution/metrics');
      // For now, simulate
      setMetrics({
        events_processed: Math.floor(Math.random() * 1000),
        patterns_discovered: Math.floor(Math.random() * 50),
        adaptations_applied: Math.floor(Math.random() * 20),
        system_coherence: 0.625 + Math.random() * 0.2,
        cache_hit_rate: 0.6 + Math.random() * 0.3,
        latency_saved_ms: Math.random() * 500,
      });
      setIsConnected(true);
    } catch (error) {
      setIsConnected(false);
    }
  };

  const getCoherenceColor = (coherence: number) => {
    if (coherence > 0.8) return 'text-green-500';
    if (coherence > 0.6) return 'text-yellow-500';
    return 'text-orange-500';
  };

  const getCoherenceStatus = (coherence: number) => {
    if (coherence > 0.8) return 'EXCELLENT';
    if (coherence > 0.6) return 'GOOD';
    if (coherence > 0.4) return 'FAIR';
    return 'BUILDING';
  };

  return (
    <div className="min-h-screen bg-gray-900 text-white p-6">
      {/* Header */}
      <div className="mb-8">
        <div className="flex items-center justify-between">
          <div>
            <h1 className="text-3xl font-bold mb-2">Recursive Evolution Dashboard</h1>
            <p className="text-gray-400">Real-time monitoring of self-improving system</p>
          </div>
          <div className="flex items-center gap-2">
            <div className={`w-3 h-3 rounded-full ${isConnected ? 'bg-green-500' : 'bg-red-500'}`} />
            <span className="text-sm text-gray-400">
              {isConnected ? 'Connected' : 'Disconnected'}
            </span>
          </div>
        </div>
      </div>

      {/* Metrics Grid */}
      <div className="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6 mb-8">
        {/* System Coherence */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <div className="flex items-center justify-between mb-4">
            <h3 className="text-lg font-semibold">System Coherence</h3>
            <span className={`text-sm font-bold ${getCoherenceColor(metrics.system_coherence)}`}>
              {getCoherenceStatus(metrics.system_coherence)}
            </span>
          </div>
          <div className="text-4xl font-bold mb-2">
            {metrics.system_coherence.toFixed(3)}
          </div>
          <div className="w-full bg-gray-700 rounded-full h-2">
            <div
              className={`h-2 rounded-full transition-all ${
                metrics.system_coherence > 0.8 ? 'bg-green-500' :
                metrics.system_coherence > 0.6 ? 'bg-yellow-500' : 'bg-orange-500'
              }`}
              style={{ width: `${metrics.system_coherence * 100}%` }}
            />
          </div>
        </div>

        {/* Events Processed */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <h3 className="text-lg font-semibold mb-4">Events Processed</h3>
          <div className="text-4xl font-bold mb-2">{metrics.events_processed.toLocaleString()}</div>
          <p className="text-sm text-gray-400">Total events monitored</p>
        </div>

        {/* Patterns Discovered */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <h3 className="text-lg font-semibold mb-4">Patterns Discovered</h3>
          <div className="text-4xl font-bold mb-2">{metrics.patterns_discovered}</div>
          <p className="text-sm text-gray-400">Unique patterns found</p>
        </div>

        {/* Adaptations Applied */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <h3 className="text-lg font-semibold mb-4">Adaptations Applied</h3>
          <div className="text-4xl font-bold mb-2">{metrics.adaptations_applied}</div>
          <p className="text-sm text-gray-400">System optimizations</p>
        </div>

        {/* Cache Hit Rate */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <h3 className="text-lg font-semibold mb-4">Cache Hit Rate</h3>
          <div className="text-4xl font-bold mb-2">{(metrics.cache_hit_rate * 100).toFixed(1)}%</div>
          <p className="text-sm text-gray-400">Optimization efficiency</p>
        </div>

        {/* Latency Saved */}
        <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
          <h3 className="text-lg font-semibold mb-4">Latency Saved</h3>
          <div className="text-4xl font-bold mb-2">{metrics.latency_saved_ms.toFixed(0)}ms</div>
          <p className="text-sm text-gray-400">Total time saved</p>
        </div>
      </div>

      {/* Recent Patterns */}
      <div className="bg-gray-800 rounded-lg p-6 border border-gray-700 mb-8">
        <h3 className="text-xl font-semibold mb-4">Recent Patterns</h3>
        {patterns.length === 0 ? (
          <p className="text-gray-400 text-center py-8">No patterns discovered yet</p>
        ) : (
          <div className="space-y-3">
            {patterns.slice(0, 5).map((pattern) => (
              <div key={pattern.id} className="bg-gray-700 rounded p-4">
                <div className="flex items-center justify-between mb-2">
                  <span className="font-mono text-sm">
                    {pattern.sequence.join(' → ')}
                  </span>
                  <span className="text-xs bg-blue-500 px-2 py-1 rounded">
                    {pattern.type}
                  </span>
                </div>
                <div className="flex items-center gap-4 text-sm text-gray-400">
                  <span>Frequency: {pattern.frequency}</span>
                  <span>Confidence: {(pattern.confidence * 100).toFixed(0)}%</span>
                </div>
              </div>
            ))}
          </div>
        )}
      </div>

      {/* Recent Adaptations */}
      <div className="bg-gray-800 rounded-lg p-6 border border-gray-700">
        <h3 className="text-xl font-semibold mb-4">Recent Adaptations</h3>
        {adaptations.length === 0 ? (
          <p className="text-gray-400 text-center py-8">No adaptations applied yet</p>
        ) : (
          <div className="space-y-3">
            {adaptations.slice(0, 5).map((adaptation) => (
              <div key={adaptation.id} className="bg-gray-700 rounded p-4">
                <div className="flex items-center justify-between mb-2">
                  <span className="font-semibold">{adaptation.type}</span>
                  <span className={`text-xs px-2 py-1 rounded ${
                    adaptation.applied ? 'bg-green-500' : 'bg-yellow-500'
                  }`}>
                    {adaptation.applied ? 'Applied' : 'Pending'}
                  </span>
                </div>
                <p className="text-sm text-gray-400 mb-2">{adaptation.description}</p>
                <div className="text-xs text-gray-500">
                  Impact Score: {adaptation.impact_score.toFixed(2)}
                </div>
              </div>
            ))}
          </div>
        )}
      </div>
    </div>
  );
};

export default RecursiveEvolutionDashboard;
