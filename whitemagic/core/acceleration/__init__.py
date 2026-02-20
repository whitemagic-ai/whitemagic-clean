"""Acceleration modules — SIMD, FFI, and polyglot-accelerated operations."""

from .elixir_bridge import (
    elixir_bridge_status,
    elixir_cascade_execute,
    elixir_cascade_pipeline,
    elixir_harmony_status,
    elixir_publish_garden_event,
)
from .go_mesh_bridge import (
    go_mesh_status,
    mesh_agent_status,
    mesh_distribute_task,
    mesh_sync_memory,
)
from .haskell_bridge import (
    haskell_bridge_status,
    haskell_check_boundaries,
    haskell_evaluate_rules,
    haskell_maturity_assess,
)
from .julia_bridge import (
    julia_batch_forecast,
    julia_bridge_status,
    julia_forecast_metric,
    julia_importance_distribution,
)
from .mojo_bridge import (
    mojo_batch_encode,
    mojo_neuro_score,
    mojo_quantize,
    mojo_status,
)
# Unified SIMD bridge (replaces 6 individual modules)
from .simd_unified import (
    # Cosine operations
    batch_cosine,
    cosine_similarity,
    # Distance operations
    cosine_similarity_zig,
    pairwise_distance_matrix,
    top_k_nearest,
    # Holographic 5D operations
    holographic_5d_centroid,
    holographic_5d_distance,
    holographic_5d_knn,
    # Constellation operations
    grid_density_scan,
    # Keyword extraction
    extract_keywords,
    # Vector batch operations
    batch_centroid,
    batch_normalize,
    batch_topk_cosine,
    # Status functions
    simd_status,
    simd_constellation_status,
    simd_distance_status,
    simd_holographic_status,
    simd_keywords_status,
    simd_vector_batch_status,
)
from .state_board_bridge import StateBoardBridge, get_state_board
from .event_ring_bridge import EventRingBridge, get_event_ring
from .dispatch_bridge import DispatchBridge, get_dispatch

__all__ = [
    "cosine_similarity", "batch_cosine", "simd_status",
    "extract_keywords", "simd_keywords_status",
    "pairwise_distance_matrix", "cosine_similarity_zig", "top_k_nearest",
    "simd_distance_status",
    "holographic_5d_distance", "holographic_5d_knn", "holographic_5d_centroid",
    "simd_holographic_status",
    "grid_density_scan", "simd_constellation_status",
    "batch_topk_cosine", "batch_normalize", "batch_centroid",
    "simd_vector_batch_status",
    "mojo_batch_encode", "mojo_quantize", "mojo_neuro_score", "mojo_status",
    "haskell_check_boundaries", "haskell_maturity_assess",
    "haskell_evaluate_rules", "haskell_bridge_status",
    "elixir_cascade_execute", "elixir_cascade_pipeline",
    "elixir_publish_garden_event", "elixir_harmony_status",
    "elixir_bridge_status",
    "mesh_sync_memory", "mesh_agent_status", "mesh_distribute_task",
    "go_mesh_status",
    "julia_importance_distribution", "julia_forecast_metric",
    "julia_batch_forecast", "julia_bridge_status",
    "StateBoardBridge", "get_state_board",
    "EventRingBridge", "get_event_ring",
    "DispatchBridge", "get_dispatch",
]
