"""
WM2 Migration: whitemagic/core/memory/manager.py
================================================
Migrated from WM1 using BaseManager + Serializable + MetricCollector
"""

from wm2.core import BaseManager
from wm2.core.serializable import Serializable
from wm2.core.metrics import MetricCollector, tracked
from typing import Dict, Any


class Manager(BaseManager, Serializable, MetricCollector):
    """Migrated manager using WM2 unified patterns."""
    
    def __init__(self, name: str = "manager"):
        BaseManager.__init__(self, name=name)
        MetricCollector.__init__(self)
    
    @tracked
    def get_stats(self) -> Dict[str, Any]:
        """Get comprehensive statistics (auto-tracked)."""
        return {
            **BaseManager.get_stats(self),
            **MetricCollector.get_stats(self),
        }
    
    # TODO: Migrate specific methods from WM1
