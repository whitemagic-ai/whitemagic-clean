"""
WM2 Core - Unified Base Classes
================================
Consolidates 327 __init__(1)->None + 234 __init__(2)->None patterns
"""

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from typing import Any, Dict


@dataclass
class BaseComponent(ABC):
    """Universal base for all WM2 components."""
    name: str
    metadata: Dict[str, Any] = field(default_factory=dict)
    
    def to_dict(self) -> Dict[str, Any]:
        """Standard serialization."""
        return {
            "name": self.name,
            "type": self.__class__.__name__,
            "metadata": self.metadata,
        }
    
    @abstractmethod
    def get_stats(self) -> Dict[str, Any]:
        """Return component statistics."""
        pass


@dataclass
class BaseEngine(BaseComponent):
    """Base for all processing engines."""
    enabled: bool = True
    
    def get_stats(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "enabled": self.enabled,
            "type": "engine",
        }


@dataclass
class BaseManager(BaseComponent):
    """Base for all manager classes."""
    initialized: bool = False
    
    def get_stats(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "initialized": self.initialized,
            "type": "manager",
        }


@dataclass
class BaseHandler(BaseComponent):
    """Base for all handler classes."""
    
    def get_stats(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "type": "handler",
        }
