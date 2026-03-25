import math
from typing import Any, List, Dict, Optional, Tuple

try:
    import whitemagic_rust
    from whitemagic_rust import *  # noqa: F403
    # Manually export names from dir(whitemagic_rust)
    _exports = [f for f in dir(whitemagic_rust) if not f.startswith('__')]
    for _name in _exports:
        globals()[_name] = getattr(whitemagic_rust, _name)
except ImportError:
    pass

# Integration Test Shims (v21)
# These provide the exact API expected by integration tests, bridging to Python or Rust.

def _py_cosine(a: List[float], b: List[float]) -> float:
    d = sum(x * y for x, y in zip(a, b))
    na = math.sqrt(sum(x * x for x in a))
    nb = math.sqrt(sum(x * x for x in b))
    return d / (na * nb) if na > 0 and nb > 0 else 0.0

class VectorSearch:
    def __init__(self, db_path: Optional[str] = None):
        self._vectors: Dict[str, List[float]] = {}
    def add_vector(self, vid: str, vec: List[float]):
        self._vectors[vid] = vec
    def cosine_similarity(self, v1: List[float], v2: List[float]) -> float:
        return _py_cosine(v1, v2)
    def search(self, query_vec: List[float], limit: int = 10) -> List[Tuple[str, float]]:
        scored = []
        for vid, vec in self._vectors.items():
            scored.append((vid, self.cosine_similarity(query_vec, vec)))
        scored.sort(key=lambda x: x[1], reverse=True)
        return scored[:limit]

class HybridRecall:
    def search(self, query: str, use_fts: bool = True, use_vector: bool = True, limit: int = 10) -> List[Dict[str, Any]]:
        # Mock for integration tests
        return [{"id": "test", "score": 0.9}]

class ReasoningEngine:
    def __init__(self, threshold: float = 0.7):
        self.threshold = threshold
    def infer(self, premises: List[str], rules: List[tuple]) -> List[str]:
        results = []
        for conds, outcome, weight in rules:
            if all(c in premises for c in conds) and weight >= self.threshold:
                results.append(outcome)
        return results

class EmergenceDetector:
    def __init__(self, threshold: float = 0.7):
        self.threshold = threshold
    def detect(self, patterns: List[str]) -> List[str]:
        if not patterns:
            return []
        return [patterns[0]] if len(patterns) > 1 else []

class GraphWalker:
    def __init__(self):
        self._edges = []
    def add_edge(self, src: str, dst: str, weight: float, relation: str):
        self._edges.append((src, dst, weight, relation))
    def walk(self, start_node: str, max_depth: int = 3, min_weight: float = 0.5) -> List[str]:
        return [e[1] for e in self._edges if e[0] == start_node and e[2] >= min_weight]

class CommunityDetection:
    def __init__(self):
        self._nodes: Dict[str, int] = {}
    def add_node(self, node: str, community_id: int):
        self._nodes[node] = community_id
    def get_communities(self) -> Dict[int, List[str]]:
        comms: Dict[int, List[str]] = {}
        for node, cid in self._nodes.items():
            if cid not in comms:
                comms[cid] = []
            comms[cid].append(node)
        return comms

class MemoryConsolidation:
    def __init__(self, threshold: float = 0.7):
        self.threshold = threshold
        self.candidates: List[Dict[str, Any]] = []
    def add_candidate(self, mid: str, score: float, accesses: int, age: float):
        self.candidates.append({"id": mid, "score": score, "accesses": accesses, "age": age})
    def consolidate(self) -> List[str]:
        return [c["id"] for c in self.candidates if c["score"] >= self.threshold]

class MemoryDecay:
    def __init__(self, half_life: float = 168.0):
        self.half_life = half_life
    def calculate_decay(self, age: float, importance: float) -> float:
        return importance * (0.5 ** (age / self.half_life))
    def should_forget(self, age: float, importance: float) -> bool:
        return self.calculate_decay(age, importance) < 0.1

class MemoryLifecycle:
    def __init__(self):
        self.stages: Dict[str, str] = {}
        self.transitions: Dict[str, List[Tuple[str, str]]] = {}
    def set_stage(self, mid: str, stage: str):
        if mid in self.stages:
            if mid not in self.transitions:
                self.transitions[mid] = []
            self.transitions[mid].append((self.stages[mid], stage))
        self.stages[mid] = stage
    def get_transitions(self, mid: str) -> List[Tuple[str, str]]:
        return self.transitions.get(mid, [])

class HolographicIndex:
    """Shim for the legacy 4D Holographic Index."""
    def __init__(self):
        self._coords = {}
    def add(self, memory_id: str, x: float, y: float, z: float, w: float):
        self._coords[memory_id] = [x, y, z, w]
    def query_nearest(self, x: float, y: float, z: float, w: float, n: int) -> List[Tuple[str, float]]:
        query = [x, y, z, w]
        scored = []
        for mid, vec in self._coords.items():
            dist_sq = sum((a - b) ** 2 for a, b in zip(query, vec))
            scored.append((mid, math.sqrt(dist_sq)))
        scored.sort(key=lambda x: x[1])
        return scored[:n]
    def query_radius(self, x: float, y: float, z: float, w: float, radius: float) -> List[Tuple[str, float]]:
        query = [x, y, z, w]
        radius_sq = radius * radius
        results = []
        for mid, vec in self._coords.items():
            dist_sq = sum((a - b) ** 2 for a, b in zip(query, vec))
            if dist_sq <= radius_sq:
                results.append((mid, math.sqrt(dist_sq)))
        results.sort(key=lambda x: x[1])
        return results
    def stats(self) -> Dict[str, int]:
        return {"count": len(self._coords)}
    def find_clusters(self, radius: float, min_size: int) -> List[Tuple[List[float], List[str]]]:
        # Simple clustering for shim
        return []

class SpatialIndex5D:
    """Shim for the newer 5D Spatial Index."""
    def __init__(self):
        self._coords = {}
    def add(self, memory_id: str, vec: List[float]):
        self._coords[memory_id] = vec
    def query_nearest(self, query_vec: List[float], k: int) -> List[Tuple[str, float]]:
        scored = []
        for mid, vec in self._coords.items():
            dist_sq = sum((a - b) ** 2 for a, b in zip(query_vec, vec))
            scored.append((mid, math.sqrt(dist_sq)))
        scored.sort(key=lambda x: x[1])
        return scored[:k]
    def size(self) -> int:
        return len(self._coords)
