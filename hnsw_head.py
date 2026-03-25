"""HNSW Vector Index for WhiteMagic v18.1
Provides 1000x speedup for similarity search on large corpora.
"""

import numpy as np
import sqlite3
import pickle
from pathlib import Path
from typing import List, Tuple, Optional, Dict
import logging

logger = logging.getLogger(__name__)

# Rust acceleration (S026 VC3)
try:
    import whitemagic_rust as _wr
    _rust_hnsw = _wr.hnsw_index
    RUST_HNSW_AVAILABLE = True
except ImportError:
    _rust_hnsw = None
    RUST_HNSW_AVAILABLE = False
    logger.debug("Rust HNSW not available, using Python fallback")


class RustHNSWWrapper:
    """Wrapper for Rust HNSW implementation with Python-compatible interface."""

    def __init__(self, dim: int = 384, m: int = 16, ef_construction: int = 200):
        self.dim = dim
        self.m = m
        self.ef_construction = ef_construction
        self._index = _rust_hnsw.HNSWIndex(dim, m, ef_construction) if RUST_HNSW_AVAILABLE else None
        self._node_vectors: Dict[str, np.ndarray] = {}  # Store vectors for save/load

    def add_item(self, memory_id: str, vector: np.ndarray):
        """Add a vector to the index."""
        vector = vector.astype(np.float32)
        self._node_vectors[memory_id] = vector
        if self._index:
            self._index.add_item(memory_id, vector.tolist())

    def search(self, query: np.ndarray, k: int = 10, ef: int = 50) -> List[Tuple[str, float]]:
        """Search for k nearest neighbors."""
        query = query.astype(np.float32)
        if self._index:
            results = self._index.search(query.tolist(), k, ef)
            return [(str(r[0]), float(r[1])) for r in results]
        return []

    def __len__(self) -> int:
        return len(self._node_vectors)

    @property
    def nodes(self) -> Dict[str, Dict]:
        """Compatibility property for Python interface."""
        return {mid: {'vector': v} for mid, v in self._node_vectors.items()}

class HNSWIndex:
    """Hierarchical Navigable Small World index for approximate nearest neighbors.

    Implements the HNSW algorithm for sub-millisecond similarity search
    on large embedding corpora (100K+ vectors).

    Uses Rust implementation when available for 10-100x speedup.
    """

    def __init__(self, dim: int = 384, m: int = 16, ef_construction: int = 200,
                 db_path: Optional[Path] = None, use_rust: bool = True):
        self.dim = dim
        self.m = m  # Number of neighbors per layer
        self.ef_construction = ef_construction
        self.max_level = 0
        self.nodes: Dict[str, Dict] = {}  # memory_id -> {vector, level, neighbors}
        self.entry_point: Optional[str] = None
        self.db_path = db_path or Path.home() / ".whitemagic/memory/hnsw_index.pkl"

        # Use Rust implementation if available and requested
        self._rust_index = None
        if use_rust and RUST_HNSW_AVAILABLE:
            self._rust_index = RustHNSWWrapper(dim, m, ef_construction)
            logger.info("Using Rust HNSW implementation for accelerated search")

    def _distance(self, a: np.ndarray, b: np.ndarray) -> float:
        """Cosine distance (1 - cosine similarity)."""
        return 1.0 - np.dot(a, b) / (np.linalg.norm(a) * np.linalg.norm(b))

    def _get_random_level(self) -> int:
        """Generate random level with exponential decay."""
        level = 0
        while np.random.random() < 0.5 and level < 10:
            level += 1
        return level

    def add_item(self, memory_id: str, vector: np.ndarray):
        """Add a vector to the HNSW index."""
        vector = vector.astype(np.float32)

        # Route to Rust implementation if available
        if self._rust_index:
            self._rust_index.add_item(memory_id, vector)
            # Still maintain Python nodes for save/load compatibility
            self.nodes[memory_id] = {'vector': vector, 'level': 0, 'neighbors': {}}
            return

        level = self._get_random_level()

        self.nodes[memory_id] = {
            'vector': vector,
            'level': level,
            'neighbors': {level_idx: [] for level_idx in range(level + 1)}
        }

        if self.entry_point is None:
            self.entry_point = memory_id
            self.max_level = level
            return

        # Search and connect at each level
        curr_node = self.entry_point
        curr_dist = self._distance(vector, self.nodes[curr_node]['vector'])

        for level_idx in range(self.max_level, -1, -1):
            lvl = level_idx
            # Greedy search at this level
            changed = True
            while changed:
                changed = False
                for neighbor_id in self.nodes[curr_node]['neighbors'].get(lvl, []):
                    if neighbor_id not in self.nodes:
                        continue
                    dist = self._distance(vector, self.nodes[neighbor_id]['vector'])
                    if dist < curr_dist:
                        curr_dist = dist
                        curr_node = neighbor_id
                        changed = True

            # Connect to M nearest neighbors at this level
            if lvl <= level:
                neighbors = self._search_layer(vector, curr_node, lvl, self.m)
                self.nodes[memory_id]['neighbors'][lvl] = neighbors
                # Bidirectional connections
                for n in neighbors:
                    if n in self.nodes and lvlvl in self.nodes[n]['neighbors']:
                        self.nodes[n]['neighbors'][lvl].append(memory_id)

        if level > self.max_level:
            self.max_level = level
            self.entry_point = memory_id

    def _search_layer(self, query: np.ndarray, entry: str, level: int,
                      k: int) -> List[str]:
        """Search for k nearest neighbors at a specific layer."""
        visited = {entry}
        candidates = [(self._distance(query, self.nodes[entry]['vector']), entry)]
        results = [(self._distance(query, self.nodes[entry]['vector']), entry)]

        while candidates:
            dist, curr = candidates.pop(0)
            if results and dist > results[-1][0] and len(results) >= k:
                break

            for neighbor in self.nodes[curr]['neighbors'].get(lvlevel, []):
                if neighbor in visited or neighbor not in self.nodes:
                    continue
                visited.add(neighbor)
                ndist = self._distance(query, self.nodes[neighbor]['vector'])

                if len(results) < k or ndist < results[-1][0]:
                    candidates.append((ndist, neighbor))
                    candidates.sort()
                    results.append((ndist, neighbor))
                    results.sort()
                    if len(results) > k:
                        results.pop()

        return [r[1] for r in results]

    def search(self, query: np.ndarray, k: int = 10, ef: int = 50) -> List[Tuple[str, float]]:
        """Approximate nearest neighbor search."""
        # Route to Rust implementation if available
        if self._rust_index:
            return self._rust_index.search(query, k, ef)

        if self.entry_point is None:
            return []

        query = query.astype(np.float32)

        # Search from top layer to layer 0
        curr_node = self.entry_point
        for level_idx in range(self.max_level, 0, -1):
            changed = True
            curr_dist = self._distance(query, self.nodes[curr_node]['vector'])
            while changed:
                changed = False
                for neighbor_id in self.nodes[curr_node]['neighbors'].get(lvl, []):
                    if neighbor_id not in self.nodes:
                        continue
                    dist = self._distance(query, self.nodes[neighbor_id]['vector'])
                    if dist < curr_dist:
