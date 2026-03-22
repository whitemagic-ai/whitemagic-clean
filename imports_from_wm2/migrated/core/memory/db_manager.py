"""
WM2 Migration: whitemagic/core/memory/db_manager.py
===================================================
Migrated from WM1 using BaseManager + Serializable + MetricCollector
"""

from typing import Any

from wm2.core import BaseManager
from wm2.core.metrics import MetricCollector, tracked
from wm2.core.serializable import Serializable


class DbManager(BaseManager, Serializable, MetricCollector):
    """Migrated db_manager using WM2 unified patterns."""

    def __init__(self, name: str = "db_manager"):
        BaseManager.__init__(self, name=name)
        MetricCollector.__init__(self)

    @tracked
    def get_stats(self) -> dict[str, Any]:
        """Get comprehensive statistics (auto-tracked)."""
        return {
            **BaseManager.get_stats(self),
            **MetricCollector.get_stats(self),
        }

    # TODO: Migrate specific methods from WM1
