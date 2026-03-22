"""
WM2 - Serializable Mixin
=========================
Unified serialization for all WM2 components
Replaces 127 individual to_dict implementations
"""

import json
from typing import Any, Dict, Type, TypeVar, get_type_hints
from datetime import datetime
from pathlib import Path

T = TypeVar('T', bound='Serializable')


class Serializable:
    """
    Unified serialization mixin with auto-introspection.
    
    Automatically serializes all public attributes based on type hints.
    Handles common types: str, int, float, bool, dict, list, datetime, Path.
    """
    
    def to_dict(self) -> Dict[str, Any]:
        """Convert object to dictionary using type introspection."""
        result = {}
        
        # Get type hints for this class
        hints = get_type_hints(self.__class__)
        
        for attr_name, attr_type in hints.items():
            if attr_name.startswith('_'):
                continue  # Skip private attributes
            
            if not hasattr(self, attr_name):
                continue  # Skip if attribute doesn't exist
            
            value = getattr(self, attr_name)
            result[attr_name] = self._serialize_value(value)
        
        # Also include any public attributes not in type hints
        for attr_name in dir(self):
            if attr_name.startswith('_') or callable(getattr(self, attr_name)):
                continue
            
            if attr_name not in result:
                value = getattr(self, attr_name)
                result[attr_name] = self._serialize_value(value)
        
        return result
    
    def _serialize_value(self, value: Any) -> Any:
        """Serialize a single value to JSON-compatible format."""
        if value is None:
            return None
        
        # Handle datetime
        if isinstance(value, datetime):
            return value.isoformat()
        
        # Handle Path
        if isinstance(value, Path):
            return str(value)
        
        # Handle Serializable objects
        if isinstance(value, Serializable):
            return value.to_dict()
        
        # Handle lists
        if isinstance(value, (list, tuple)):
            return [self._serialize_value(v) for v in value]
        
        # Handle dicts
        if isinstance(value, dict):
            return {k: self._serialize_value(v) for k, v in value.items()}
        
        # Handle primitives
        if isinstance(value, (str, int, float, bool)):
            return value
        
        # Fallback: convert to string
        return str(value)
    
    @classmethod
    def from_dict(cls: Type[T], data: Dict[str, Any]) -> T:
        """Create object from dictionary using type hints."""
        hints = get_type_hints(cls)
        kwargs = {}
        
        for key, value in data.items():
            if key in hints:
                expected_type = hints[key]
                kwargs[key] = cls._deserialize_value(value, expected_type)
            else:
                kwargs[key] = value
        
        return cls(**kwargs)
    
    @classmethod
    def _deserialize_value(cls, value: Any, expected_type: Type) -> Any:
        """Deserialize a value to the expected type."""
        if value is None:
            return None
        
        # Handle datetime
        if expected_type == datetime:
            if isinstance(value, str):
                return datetime.fromisoformat(value)
            return value
        
        # Handle Path
        if expected_type == Path:
            return Path(value)
        
        # Handle primitives
        if expected_type in (str, int, float, bool):
            return expected_type(value)
        
        # Handle lists
        if hasattr(expected_type, '__origin__') and expected_type.__origin__ == list:
            return [value] if not isinstance(value, list) else value
        
        # Handle dicts
        if hasattr(expected_type, '__origin__') and expected_type.__origin__ == dict:
            return value if isinstance(value, dict) else {}
        
        return value
    
    def to_json(self, **kwargs) -> str:
        """Convert to JSON string."""
        return json.dumps(self.to_dict(), **kwargs)
    
    @classmethod
    def from_json(cls: Type[T], json_str: str) -> T:
        """Create object from JSON string."""
        data = json.loads(json_str)
        return cls.from_dict(data)
    
    def __repr__(self) -> str:
        """String representation showing key attributes."""
        attrs = []
        for key, value in self.to_dict().items():
            if not key.startswith('_'):
                attrs.append(f"{key}={repr(value)}")
        
        return f"{self.__class__.__name__}({', '.join(attrs[:5])}{'...' if len(attrs) > 5 else ''})"
