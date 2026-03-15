import { useState, useEffect, useRef } from "react";
import { Canvas, useFrame } from "@react-three/fiber";
import { OrbitControls, Stars, Text, Float, MeshDistortMaterial } from "@react-three/drei";
import { Brain, Sparkles, Filter, RefreshCw, Layers } from "lucide-react";
import * as THREE from "three";

interface Cluster {
  id: string;
  center: [number, number, number, number];
  size: number;
  label: string;
  macro_summary: string;
  principles: string[];
  memories: string[];
  quadrant: string;
}

interface Attractor {
  id: string;
  center: [number, number, number, number];
  mass: number;
  event_horizon: number;
  density: number;
}

function HolographicCore({ clusters, attractors, onClusterSelect }: { clusters: Cluster[], attractors: Attractor[], onClusterSelect: (c: Cluster) => void }) {
  const groupRef = useRef<THREE.Group>(null);

  useFrame((state) => {
    if (groupRef.current) {
      groupRef.current.rotation.y += 0.001; // Slower rotation for 4D clarity
      groupRef.current.rotation.x = Math.sin(state.clock.elapsedTime * 0.1) * 0.05;
    }
  });

  return (
    <group ref={groupRef}>
      <Stars radius={100} depth={50} count={5000} factor={4} saturation={0} fade speed={1} />
      <ambientLight intensity={0.5} />
      <pointLight position={[10, 10, 10]} intensity={1} />
      <pointLight position={[-10, -10, -10]} intensity={0.5} color="#8b5cf6" />
      <pointLight position={[0, 0, 10]} intensity={0.5} color="#22d3ee" />

      {/* Cyberbrain Attractors (Gravity Wells) */}
      {attractors.map((attr, i) => (
        <Float key={`attr-${i}`} speed={2} rotationIntensity={1.5} floatIntensity={1}>
          <mesh position={[attr.center[0] * 10, attr.center[1] * 10, attr.center[2] * 10]}>
            <sphereGeometry args={[attr.mass * 0.5, 32, 32]} />
            <MeshDistortMaterial
              color="#0f172a"
              emissive="#3b82f6"
              emissiveIntensity={0.5}
              distort={0.4}
              speed={2}
              transparent
              opacity={0.8}
            />
          </mesh>
          <mesh position={[attr.center[0] * 10, attr.center[1] * 10, attr.center[2] * 10]}>
            <sphereGeometry args={[attr.event_horizon * 1.5, 32, 32]} />
            <meshBasicMaterial color="#3b82f6" transparent opacity={0.1} wireframe />
          </mesh>
        </Float>
      ))}

      {/* Memory Clusters */}
      {clusters.map((cluster) => {
        const color =
          cluster.quadrant === "Technical" ? "#22d3ee" :
          cluster.quadrant === "Philosophical" ? "#c084fc" :
          cluster.quadrant === "Architectural" ? "#fbbf24" :
          "#4ade80";

        return (
          <group key={cluster.id} position={[cluster.center[0] * 10, cluster.center[1] * 10, cluster.center[2] * 10]}>
            <Float speed={1.5} rotationIntensity={1} floatIntensity={2}>
              <mesh onClick={() => onClusterSelect(cluster)}>
                <sphereGeometry args={[Math.max(0.5, Math.log10(cluster.size)), 16, 16]} />
                <meshStandardMaterial color={color} transparent opacity={0.8} roughness={0.2} metalness={0.8} />
              </mesh>
            </Float>
            <Text
              position={[0, Math.max(0.5, Math.log10(cluster.size)) + 0.5, 0]}
              fontSize={0.4}
              color="white"
              anchorX="center"
              anchorY="middle"
              outlineWidth={0.05}
              outlineColor="#000000"
            >
              {cluster.label}
            </Text>
          </group>
        );
      })}

      {/* Connections based on 4th dimension (temporal proximity / semantic link) */}
      <lineSegments>
        <bufferGeometry>
          <float32BufferAttribute
            attach="attributes-position"
            args={[new Float32Array(), 3]}
            count={clusters.length * 2}
            array={new Float32Array(
              clusters.flatMap((c1, i) => {
                const nearest = clusters
                  .slice(i + 1)
                  .map(c2 => ({
                    c2,
                    dist: Math.hypot(c1.center[0] - c2.center[0], c1.center[1] - c2.center[1], c1.center[2] - c2.center[2])
                  }))
                  .sort((a, b) => a.dist - b.dist)[0];
                
                if (nearest && nearest.dist < 5) {
                  return [
                    c1.center[0] * 10, c1.center[1] * 10, c1.center[2] * 10,
                    nearest.c2.center[0] * 10, nearest.c2.center[1] * 10, nearest.c2.center[2] * 10
                  ];
                }
                return [];
              })
            )}
            itemSize={3}
          />
        </bufferGeometry>
        <lineBasicMaterial color="#334155" transparent opacity={0.3} />
      </lineSegments>
    </group>
  );
}

export default function HolographicView() {
  const [clusters, setClusters] = useState<Cluster[]>([]);
  const [attractors, setAttractors] = useState<Attractor[]>([]);
  const [selectedCluster, setSelectedCluster] = useState<Cluster | null>(null);
  const [loading, setLoading] = useState(true);

  const fetchTopology = async () => {
    setLoading(true);
    try {
      // Mock data for UI layout without backend
      setTimeout(() => {
        setClusters([
          { id: "1", center: [0, 0, 0, 0], size: 100, label: "Core Router", macro_summary: "Main message bus", principles: [], memories: [], quadrant: "Architectural" },
          { id: "2", center: [2, 1, -1, 0], size: 50, label: "Memory DB", macro_summary: "SQLite layer", principles: [], memories: [], quadrant: "Technical" },
          { id: "3", center: [-2, -1, 2, 0], size: 75, label: "Dharma Ethics", macro_summary: "Boundary testing", principles: [], memories: [], quadrant: "Philosophical" },
        ]);
        setAttractors([
          { id: "a1", center: [0, 0, 0, 0], mass: 2, event_horizon: 3, density: 1 }
        ]);
        setLoading(false);
      }, 500);
    } catch (err) {
      console.error(err);
      setLoading(false);
    }
  };

  useEffect(() => {
    fetchTopology();
  }, []);

  return (
    <div className="relative w-full h-full bg-[#0a0a0f] overflow-hidden rounded-xl border border-wm-border shadow-2xl">
      {/* HUD Overlay */}
      <div className="absolute top-4 left-4 z-10 p-3 bg-wm-bg-panel/80 backdrop-blur-md rounded-lg border border-wm-border">
        <h2 className="text-sm font-semibold text-wm-purple-300 flex items-center gap-2 mb-2">
          <Brain size={16} />
          4D Cyberbrain Topology
        </h2>
        <div className="text-xs text-gray-400 space-y-1">
          <div className="flex justify-between gap-4">
            <span>Clusters:</span>
            <span className="text-gray-200">{clusters.length}</span>
          </div>
          <div className="flex justify-between gap-4">
            <span>Gravity Wells:</span>
            <span className="text-gray-200">{attractors.length}</span>
          </div>
        </div>
        <div className="mt-3 flex gap-2">
          <button onClick={fetchTopology} className="p-1.5 bg-wm-surface rounded hover:bg-wm-purple-500/20 text-gray-400 hover:text-wm-purple-300 transition-colors">
            <RefreshCw size={14} className={loading ? "animate-spin" : ""} />
          </button>
          <button className="p-1.5 bg-wm-surface rounded hover:bg-wm-purple-500/20 text-gray-400 hover:text-wm-purple-300 transition-colors">
            <Filter size={14} />
          </button>
        </div>
      </div>

      {/* Main 3D Canvas */}
      <div className="w-full h-full cursor-move">
        <Canvas camera={{ position: [0, 0, 15], fov: 60 }}>
          <OrbitControls enablePan={true} enableZoom={true} enableRotate={true} />
          {!loading && <HolographicCore clusters={clusters} attractors={attractors} onClusterSelect={setSelectedCluster} />}
        </Canvas>
      </div>

      {/* Loading State */}
      {loading && (
        <div className="absolute inset-0 flex items-center justify-center bg-[#0a0a0f]/50 z-20">
          <div className="flex flex-col items-center gap-3">
            <Sparkles className="w-8 h-8 text-wm-purple-400 animate-pulse" />
            <span className="text-sm text-gray-400 font-mono">Synthesizing topology...</span>
          </div>
        </div>
      )}

      {/* Detail Panel */}
      {selectedCluster && (
        <div className="absolute bottom-4 right-4 z-10 w-80 max-h-96 overflow-y-auto bg-wm-bg-panel/90 backdrop-blur-md rounded-lg border border-wm-border p-4 shadow-xl">
          <div className="flex justify-between items-start mb-3">
            <h3 className="text-sm font-semibold text-white flex items-center gap-2">
              <Layers size={14} className="text-wm-purple-400" />
              {selectedCluster.label}
            </h3>
            <button onClick={() => setSelectedCluster(null)} className="text-gray-500 hover:text-gray-300">
              ×
            </button>
          </div>
          <div className="space-y-3 text-xs">
            <div>
              <span className="text-gray-500 block mb-1">Macro Summary</span>
              <p className="text-gray-300 bg-wm-surface p-2 rounded">{selectedCluster.macro_summary}</p>
            </div>
            <div className="grid grid-cols-2 gap-2">
              <div className="bg-wm-surface p-2 rounded">
                <span className="text-gray-500 block">Quadrant</span>
                <span className="text-gray-300">{selectedCluster.quadrant}</span>
              </div>
              <div className="bg-wm-surface p-2 rounded">
                <span className="text-gray-500 block">Size</span>
                <span className="text-gray-300">{selectedCluster.size} nodes</span>
              </div>
            </div>
          </div>
        </div>
      )}
    </div>
  );
}
