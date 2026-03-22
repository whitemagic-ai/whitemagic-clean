"""
WM2 Core - Unified Framework
=============================
Distilled essence of WhiteMagic 1.0
"""

from .base import BaseComponent, BaseEngine, BaseManager, BaseHandler
from .serialization import Serializable, serialize, serialize_stats
from .lifecycle import Lifecycle, FileBackedLifecycle

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
