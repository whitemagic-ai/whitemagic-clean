"""Constellation Bridge - Rust-accelerated clustering algorithms.

Phase 1 VC5: Translate constellations.py clustering to Rust.
"""
from __future__ import annotations

from typing import Any

import numpy as np

# Try to load Rust module
_rs = None
try:
    import whitemagic_rs as _rs
except Exception:
    pass


def cluster_hdbscan(
    points: np.ndarray,
    min_cluster_size: int = 5,
    min_samples: int = 3
) -> tuple[np.ndarray, dict[str, Any]]:
    """HDBSCAN clustering with Rust acceleration fallback.
    
    Returns (labels, cluster_info) where labels[i] is cluster id for point i
    (-1 for noise points).
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'hdbscan_cluster'):
        try:
            # Convert numpy to list for Rust
            points_list = points.tolist()
            labels_list = _rs.hdbscan_cluster(points_list, min_cluster_size, min_samples)
            labels = np.array(labels_list)
            
            # Build cluster info
            n_clusters = len(set(labels_list)) - (1 if -1 in labels_list else 0)
            n_noise = list(labels_list).count(-1)
            
            return labels, {
                "n_clusters": n_clusters,
                "n_noise": n_noise,
                "backend": "rust"
            }
        except Exception:
            pass
    
    # Try Python hdbscan
    try:
        import hdbscan
        clusterer = hdbscan.HDBSCAN(
            min_cluster_size=min_cluster_size,
            min_samples=min_samples,
            metric='euclidean'
        )
        labels = clusterer.fit_predict(points)
        return labels, {
            "n_clusters": len(set(labels)) - (1 if -1 in labels else 0),
            "n_noise": list(labels).count(-1),
            "backend": "hdbscan"
        }
    except ImportError:
        pass
    
    # Fallback: simple grid-based clustering
    return _grid_cluster(points, min_cluster_size)


def _grid_cluster(
    points: np.ndarray,
    min_cluster_size: int
) -> tuple[np.ndarray, dict[str, Any]]:
    """Simple grid-based density clustering fallback."""
    n_points = len(points)
    labels = np.full(n_points, -1, dtype=int)
    
    # Compute grid cell size based on point spread
    if n_points < 2:
        return labels, {"n_clusters": 0, "n_noise": n_points, "backend": "grid"}
    
    # Use 5th and 95th percentiles for robust range estimation
    mins = np.percentile(points, 5, axis=0)
    maxs = np.percentile(points, 95, axis=0)
    ranges = maxs - mins
    
    # Cell size: divide range into ~10 bins per dimension
    cell_size = np.mean(ranges) / 10 if np.mean(ranges) > 0 else 1.0
    
    # Assign points to grid cells
    cells: dict[tuple[int, ...], list[int]] = {}
    for i, point in enumerate(points):
        cell = tuple(((point - mins) / cell_size).astype(int))
        if cell not in cells:
            cells[cell] = []
        cells[cell].append(i)
    
    # Find dense cells (clusters)
    cluster_id = 0
    for cell, indices in cells.items():
        if len(indices) >= min_cluster_size:
            for idx in indices:
                labels[idx] = cluster_id
            cluster_id += 1
    
    return labels, {
        "n_clusters": cluster_id,
        "n_noise": int((labels == -1).sum()),
        "backend": "grid"
    }


def compute_centroid(points: np.ndarray) -> np.ndarray:
    """Compute centroid of points with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_centroid'):
        try:
            return np.array(_rs.compute_centroid(points.tolist()))
        except Exception:
            pass
    
    # NumPy fallback
    return np.mean(points, axis=0)


def compute_radius(points: np.ndarray, centroid: np.ndarray | None = None) -> float:
    """Compute average radius (distance from centroid)."""
    if centroid is None:
        centroid = compute_centroid(points)
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_radius'):
        try:
            return float(_rs.compute_radius(points.tolist(), centroid.tolist()))
        except Exception:
            pass
    
    # NumPy fallback
    distances = np.linalg.norm(points - centroid, axis=1)
    return float(np.mean(distances))


def hungarian_matching(
    cost_matrix: np.ndarray
) -> tuple[list[tuple[int, int]], float]:
    """Optimal assignment using Hungarian algorithm with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'hungarian_solve'):
        try:
            result = _rs.hungarian_solve(cost_matrix.tolist())
            assignments = [(int(a), int(b)) for a, b in result["assignments"]]
            return assignments, float(result["cost"])
        except Exception:
            pass
    
    # scipy fallback
    try:
        from scipy.optimize import linear_sum_assignment
        row_ind, col_ind = linear_sum_assignment(cost_matrix)
        cost = cost_matrix[row_ind, col_ind].sum()
        return list(zip(row_ind.tolist(), col_ind.tolist())), float(cost)
    except ImportError:
        pass
    
    # Greedy fallback
    n, m = cost_matrix.shape
    size = min(n, m)
    assignments = []
    total_cost = 0.0
    used_cols = set()
    
    for row in range(size):
        min_cost = float('inf')
        best_col = -1
        for col in range(m):
            if col not in used_cols and cost_matrix[row, col] < min_cost:
                min_cost = cost_matrix[row, col]
                best_col = col
        if best_col >= 0:
            assignments.append((row, best_col))
            total_cost += min_cost
            used_cols.add(best_col)
    
    return assignments, total_cost


class ConstellationBridge:
    """Rust-accelerated constellation detection."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def detect_constellations(
        self,
        points: np.ndarray,
        min_cluster_size: int = 5,
        member_ids: list[str] | None = None
    ) -> list[dict[str, Any]]:
        """Detect constellations (clusters) in 5D holographic space.
        
        Returns list of constellation dicts with centroid, radius, members.
        """
        labels, info = cluster_hdbscan(points, min_cluster_size)
        
        constellations = []
        unique_labels = set(labels) - {-1}
        
        for cluster_id in unique_labels:
            mask = labels == cluster_id
            cluster_points = points[mask]
            
            centroid = compute_centroid(cluster_points)
            radius = compute_radius(cluster_points, centroid)
            
            constellation = {
                "id": int(cluster_id),
                "centroid": centroid.tolist(),
                "radius": radius,
                "size": int(mask.sum()),
                "member_indices": np.where(mask)[0].tolist(),
            }
            
            if member_ids:
                constellation["member_ids"] = [
                    member_ids[i] for i in constellation["member_indices"]
                ]
            
            constellations.append(constellation)
        
        # Sort by size descending
        constellations.sort(key=lambda x: x["size"], reverse=True)
        
        return constellations
    
    def get_backend(self) -> str:
        """Report which clustering backend is active."""
        if _rs is not None and hasattr(_rs, 'hdbscan_cluster'):
            return "rust"
        try:
            import hdbscan
            return "hdbscan"
        except ImportError:
            return "grid"


def get_constellation_bridge() -> ConstellationBridge:
    """Get constellation bridge instance."""
    return ConstellationBridge()
