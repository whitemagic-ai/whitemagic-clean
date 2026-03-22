"""Causal Net — Layer 2: Constraint Detection
Infers directed edges between memory clusters using 4D holographic coordinates.
"""

import logging
import sqlite3
import subprocess
from pathlib import Path

import numpy as np

from whitemagic.utils.fast_json import dumps_str as _json_dumps
from whitemagic.utils.fast_json import loads as _json_loads

logger = logging.getLogger(__name__)

class CausalNet:
    """Causal Net — Layer 2: Constraint Detection
    Infers directed edges between memory clusters using 4D holographic coordinates.
    """

    def __init__(self, db_path: Path):
        self.db_path = db_path

    def infer_dependencies(self, active_clusters: dict[tuple[int, int], list[str]]) -> dict[str, list[str]]:
        """Infer a Directed Acyclic Graph (DAG) between clusters.
        Logic: Calculate the 'flow' between clusters based on coordinate gradients.

        Rust Fast-Path: If whitemagic_rust is available, it handles the coordinate math and DAG generation.
        """
        # Phase B: Rust Fast-Path for v20
        try:
            import whitemagic_rust as rs
            if hasattr(rs, 'synthesis_engine') and hasattr(rs.synthesis_engine, 'infer_dag_from_coords'):
                # Build cluster_data dict for Rust
                cluster_data = {}
                conn = sqlite3.connect(str(self.db_path))
                for key, mids in active_clusters.items():
                    placeholders = ",".join("?" for _ in mids)
                    rows = conn.execute(
                        "SELECT x, y, z, w FROM holographic_coords WHERE memory_id IN (" + placeholders + ")",
                        mids
                    ).fetchall()
                    if rows:
                        arr = np.array(rows)
                        centroid = np.mean(arr, axis=0)
                        cluster_data[str(key)] = {"centroid": centroid.tolist(), "ids": mids}
                conn.close()

                # Call Rust fast-path
                edges = rs.synthesis_engine.infer_dag_from_coords(
                    cluster_data,
                    dist_threshold=0.5,
                    w_threshold=0.001
                )
                if edges:
                    logger.info(f"Rust fast-path: {len(edges)} edges from {len(active_clusters)} clusters")
                    return edges
        except Exception as e:
            logger.debug(f"Rust fast-path unavailable, using Python fallback: {e}")

        # Python fallback
        cluster_data = {}
        conn = sqlite3.connect(str(self.db_path))

        for key, mids in active_clusters.items():
            placeholders = ",".join("?" for _ in mids)
            rows = conn.execute("SELECT x, y, z, w FROM holographic_coords WHERE memory_id IN (" + placeholders + ")", mids).fetchall()
            if not rows:
                continue

            arr = np.array(rows)
            cluster_data[key] = {
                "centroid": np.mean(arr, axis=0),
                "ids": mids,
            }

        conn.close()

        # Build edges
        edges = []
        keys = list(cluster_data.keys())
        for i in range(len(keys)):
            for j in range(len(keys)):
                if i == j:
                    continue
                c1 = cluster_data[keys[i]]
                c2 = cluster_data[keys[j]]

                dist_xyz = np.linalg.norm(c1["centroid"][:3] - c2["centroid"][:3])
                w_diff = c2["centroid"][3] - c1["centroid"][3]

                if dist_xyz < 0.5 and abs(w_diff) > 0.001:
                    if w_diff > 0:
                        edges.append((str(keys[i]), str(keys[j])))
                    else:
                        edges.append((str(keys[j]), str(keys[i])))

        # Phase 2: Julia Resonance Verification
        self.resonance_scores: dict[str, float] = {}
        if edges:
            edges, self.resonance_scores = self._verify_with_julia(nodes=[str(k) for k in cluster_data.keys()], edges=edges)

        return edges  # type: ignore[return-value]

    def _verify_with_julia(self, nodes: list[str], edges: list[tuple[str, str]]) -> tuple[list[tuple[str, str]], dict[str, float]]:
        """Invokes Julia to verify logical 'Ganying' (resonance) across the edges."""
        julia_script = self.db_path.parent.parent / "whitemagic-julia" / "src" / "causal_resonance.jl"
        if not julia_script.exists():
            logger.warning("Julia resonance script not found. Skipping verification.")
            return edges, {}

        payload = _json_dumps({"nodes": nodes, "edges": edges})
        try:
            cmd = ["julia", str(julia_script), payload]
            result = subprocess.run(cmd, capture_output=True, text=True, check=True)
            resonance_scores = _json_loads(result.stdout)

            pruned = []
            for src, dst in edges:
                score = resonance_scores.get(dst, 0.0)
                if score > 0.05:
                    pruned.append((src, dst))

            logger.info(f"Julia Gan Ying verification: {len(edges)} -> {len(pruned)} edges.")
            return pruned, resonance_scores
        except Exception as e:
            logger.error(f"Julia resonance verification failed: {e}")
            return edges, {}

if __name__ == "__main__":
    pass
