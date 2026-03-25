"""Metrics bridge — Hologram and metric tracking."""
import logging
from typing import Any

logger = logging.getLogger(__name__)


def get_metrics_summary() -> dict[str, Any]:
    """Get summary of all tracked metrics."""
    from whitemagic.core.memory.hologram import HologramCache

    cache = HologramCache()
    stats = cache.get_stats()

    return {
        "status": "success",
        "metrics": {
            "hologram_entries": stats.get("entry_count", 0),
            "cache_size_mb": stats.get("size_mb", 0.0),
            "hit_rate": stats.get("hit_rate", 0.0),
        }
    }
