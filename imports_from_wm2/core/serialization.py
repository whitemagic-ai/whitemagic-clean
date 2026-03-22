"""
WM2 Core - Unified Serialization
=================================
Consolidates 137 to_dict(1)->dict[str, Any] patterns
"""

from typing import Any, Protocol


class Serializable(Protocol):
    """Protocol for serializable objects."""

    def to_dict(self) -> dict[str, Any]:
        """Convert to dictionary representation."""
        ...


def serialize(obj: Any) -> dict[str, Any]:
    """Universal serialization function."""
    if hasattr(obj, 'to_dict'):
        return obj.to_dict()
    elif hasattr(obj, '__dict__'):
        return {k: v for k, v in obj.__dict__.items() if not k.startswith('_')}
    else:
        return {"value": str(obj), "type": type(obj).__name__}


def serialize_stats(obj: Any) -> dict[str, Any]:
    """Universal stats serialization."""
    if hasattr(obj, 'get_stats'):
        return obj.get_stats()
    elif hasattr(obj, 'stats'):
        return obj.stats()
    else:
        return serialize(obj)
