"""Consolidation Bridge - Rust-accelerated memory consolidation.

Phase 1 VC7: Translate consolidation.py batch operations to Rust.
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


def compute_jaccard_similarity(set_a: set[str], set_b: set[str]) -> float:
    """Compute Jaccard similarity with Rust acceleration."""
    if not set_a and not set_b:
        return 1.0
    if not set_a or not set_b:
        return 0.0
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'jaccard_similarity'):
        try:
            return float(_rs.jaccard_similarity(list(set_a), list(set_b)))
        except Exception:
            pass
    
    # Python fallback
    intersection = len(set_a & set_b)
    union = len(set_a | set_b)
    return intersection / union if union > 0 else 0.0


def compute_tag_similarity(tags_a: set[str], tags_b: set[str]) -> float:
    """Compute tag overlap similarity with Rust acceleration."""
    return compute_jaccard_similarity(tags_a, tags_b)


def cluster_by_similarity(
    items: list[dict[str, Any]],
    similarity_fn: Any,
    threshold: float = 0.3,
    min_cluster_size: int = 3
) -> list[list[int]]:
    """Cluster items by similarity with Rust acceleration."""
    n = len(items)
    if n < min_cluster_size:
        return []
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'cluster_by_similarity'):
        try:
            # Convert to similarity matrix for Rust
            similarity_matrix = []
            for i in range(n):
                row = []
                for j in range(n):
                    if i == j:
                        row.append(1.0)
                    elif i < j:
                        sim = similarity_fn(items[i], items[j])
                        row.append(sim)
                    else:
                        row.append(similarity_matrix[j][i])  # Symmetric
                similarity_matrix.append(row)
            
            clusters = _rs.cluster_by_similarity(similarity_matrix, threshold, min_cluster_size)
            return [list(c) for c in clusters]
        except Exception:
            pass
    
    # Python fallback: agglomerative clustering
    parent = list(range(n))
    
    def find(x: int) -> int:
        if parent[x] != x:
            parent[x] = find(parent[x])
        return parent[x]
    
    def union(x: int, y: int) -> None:
        px, py = find(x), find(y)
        if px != py:
            parent[px] = py
    
    # Union similar items
    for i in range(n):
        for j in range(i + 1, n):
            if similarity_fn(items[i], items[j]) >= threshold:
                union(i, j)
    
    # Build clusters
    clusters: dict[int, list[int]] = {}
    for i in range(n):
        root = find(i)
        if root not in clusters:
            clusters[root] = []
        clusters[root].append(i)
    
    # Filter by min size
    return [indices for indices in clusters.values() if len(indices) >= min_cluster_size]


def compute_cluster_centroid(features: list[list[float]]) -> list[float]:
    """Compute centroid of feature vectors with Rust acceleration."""
    if not features:
        return []
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_centroid_batch'):
        try:
            return list(_rs.compute_centroid_batch(features))
        except Exception:
            pass
    
    # NumPy fallback
    arr = np.array(features)
    return arr.mean(axis=0).tolist()


class ConsolidationBridge:
    """Rust-accelerated memory consolidation operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def consolidate_batch(
        self,
        memories: list[dict[str, Any]],
        min_cluster_size: int = 3,
        tag_overlap_threshold: float = 0.3
    ) -> dict[str, Any]:
        """Run consolidation on batch of memories.
        
        Returns dict with clusters, strategies, and metrics.
        """
        if len(memories) < min_cluster_size:
            return {"clusters": [], "strategies": [], "memories_analyzed": len(memories)}
        
        # Extract tags for each memory
        memory_tags = [
            set(m.get('tags', [])) | set(m.get('auto_tags', []))
            for m in memories
        ]
        
        # Define similarity function
        def tag_sim(i: int, j: int) -> float:
            return compute_tag_similarity(memory_tags[i], memory_tags[j])
        
        # Cluster memories
        cluster_indices = cluster_by_similarity(
            memories,
            lambda a, b: tag_sim(memories.index(a), memories.index(b)),
            threshold=tag_overlap_threshold,
            min_cluster_size=min_cluster_size
        )
        
        # Build cluster objects
        clusters = []
        for indices in cluster_indices:
            cluster_memories = [memories[i] for i in indices]
            shared_tags = set.intersection(*[
                set(m.get('tags', [])) | set(m.get('auto_tags', []))
                for m in cluster_memories
            ]) if cluster_memories else set()
            
            cluster = {
                "memory_indices": indices,
                "memory_count": len(indices),
                "shared_tags": list(shared_tags)[:10],
                "avg_importance": sum(m.get('importance', 0.5) for m in cluster_memories) / len(cluster_memories),
                "total_access": sum(m.get('access_count', 0) for m in cluster_memories),
            }
            clusters.append(cluster)
        
        # Synthesize strategies from strong clusters
        strategies = []
        for cluster in clusters:
            if cluster["avg_importance"] > 0.7 or cluster["total_access"] > 20:
                strategy = {
                    "theme": cluster["shared_tags"][0] if cluster["shared_tags"] else "general",
                    "derived_from": cluster["memory_count"],
                    "importance": cluster["avg_importance"],
                }
                strategies.append(strategy)
        
        return {
            "clusters": clusters,
            "strategies": strategies,
            "memories_analyzed": len(memories),
            "clusters_found": len(clusters),
            "strategies_synthesized": len(strategies),
        }
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_consolidation_bridge() -> ConsolidationBridge:
    """Get consolidation bridge instance."""
    return ConsolidationBridge()
