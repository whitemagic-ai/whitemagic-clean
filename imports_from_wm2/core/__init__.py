"""
WM2 Core - Unified Framework
=============================
Distilled essence of WhiteMagic 1.0
"""

from .base import BaseComponent, BaseEngine, BaseHandler, BaseManager
from .lifecycle import FileBackedLifecycle, Lifecycle
from .serialization import Serializable, serialize, serialize_stats

__all__ = [
    "BaseComponent",
    "BaseEngine",
    "BaseManager",
    "BaseHandler",
    "Serializable",
    "serialize",
    "serialize_stats",
    "Lifecycle",
    "FileBackedLifecycle",
]
