"""Acceleration modules — SIMD, FFI, and polyglot-accelerated operations."""

try:
    from .elixir_bridge import (
        elixir_bridge_status,
        elixir_cascade_execute,
        elixir_cascade_pipeline,
        has_elixir,
    )
except ImportError:
    has_elixir = False

    def elixir_bridge_status() -> dict:
        return {"status": "error", "message": "Elixir bridge not available or archived."}

    def elixir_cascade_execute(*args, **kwargs):
        raise NotImplementedError("Elixir bridge not available or archived.")

    def elixir_cascade_pipeline(*args, **kwargs):
        raise NotImplementedError("Elixir bridge not available or archived.")

try:
    from .go_mesh_bridge import (
        go_mesh_status,
        mesh_agent_status,
        mesh_distribute_task,
        mesh_sync_memory,
    )
except ImportError:
    def go_mesh_status() -> dict:
        return {"status": "error", "message": "Go mesh bridge not available."}

    def mesh_agent_status(*args, **kwargs):
        raise NotImplementedError("Go mesh bridge not available.")

    def mesh_distribute_task(*args, **kwargs):
        raise NotImplementedError("Go mesh bridge not available.")

    def mesh_sync_memory(*args, **kwargs):
        raise NotImplementedError("Go mesh bridge not available.")

try:
    from .haskell_bridge import (
        haskell_bridge_status,
        haskell_check_boundaries,
        haskell_evaluate_rules,
        haskell_maturity_assess,
    )
except ImportError:
    def haskell_bridge_status() -> dict:
        return {"status": "error", "message": "Haskell bridge not available."}

    def haskell_check_boundaries(*args, **kwargs):
        raise NotImplementedError("Haskell bridge not available.")

    def haskell_evaluate_rules(*args, **kwargs):
        raise NotImplementedError("Haskell bridge not available.")

    def haskell_maturity_assess(*args, **kwargs):
        raise NotImplementedError("Haskell bridge not available.")

try:
    from .julia_bridge import (
        julia_batch_forecast,
        julia_bridge_status,
        julia_forecast_metric,
        julia_importance_distribution,
    )
except ImportError:
    def julia_batch_forecast(*args, **kwargs):
        raise NotImplementedError("Julia bridge not available.")

    def julia_bridge_status() -> dict:
        return {"status": "error", "message": "Julia bridge not available."}

    def julia_forecast_metric(*args, **kwargs):
        raise NotImplementedError("Julia bridge not available.")

    def julia_importance_distribution(*args, **kwargs):
        raise NotImplementedError("Julia bridge not available.")

try:
    from .mojo_bridge import (
        mojo_batch_encode,
        mojo_neuro_score,
        mojo_quantize,
        mojo_status,
    )
except ImportError:
    def mojo_batch_encode(*args, **kwargs):
        raise NotImplementedError("Mojo bridge not available.")

    def mojo_neuro_score(*args, **kwargs):
        raise NotImplementedError("Mojo bridge not available.")

    def mojo_quantize(*args, **kwargs):
        raise NotImplementedError("Mojo bridge not available.")

    def mojo_status() -> dict:
        return {"status": "error", "message": "Mojo bridge not available."}

from .dispatch_bridge import DispatchBridge, get_dispatch
from .event_ring_bridge import EventRingBridge, get_event_ring
from .mojo_bridge import (
    mojo_batch_encode,
    mojo_neuro_score,
    mojo_quantize,
    mojo_status,
)

# Unified SIMD bridge (replaces 6 individual modules)
from .simd_unified import (
    # Vector batch operations
    batch_centroid,
    # Cosine operations
    batch_cosine,
    batch_normalize,
    batch_topk_cosine,
    cosine_similarity,
    # Distance operations
    cosine_similarity_zig,
    # Keyword extraction
    extract_keywords,
    # Constellation operations
    grid_density_scan,
    # Holographic 5D operations
    holographic_5d_centroid,
    holographic_5d_distance,
    holographic_5d_knn,
    pairwise_distance_matrix,
    simd_constellation_status,
    simd_distance_status,
    simd_holographic_status,
    simd_keywords_status,
    # Status functions
    simd_status,
    simd_vector_batch_status,
    top_k_nearest,
)
from .state_board_bridge import StateBoardBridge, get_state_board

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
