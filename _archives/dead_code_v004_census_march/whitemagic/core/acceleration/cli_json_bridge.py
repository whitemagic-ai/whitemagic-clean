"""Hot Path JSON Bridge - Rust-accelerated JSON serialization for CLI.

Phase 1 VC1: Translate cli_app.py JSON hot path to Rust.
"""
from __future__ import annotations

import json
from typing import Any

# Try to load Rust library
_lib = None
try:
    # Try via whitemagic_rs
    import whitemagic_rs as _rs
    _lib = _rs
except Exception:
    pass


def fast_json_dumps(data: dict[str, Any]) -> bytes:
    """Serialize dict to JSON bytes using Rust orjson speed.
    
    Backend priority: Rust > orjson > stdlib json
    Returns bytes for HTTP responses, IPC, file I/O.
    """
    # Try Rust first (fastest path)
    if _lib is not None:
        try:
            if hasattr(_lib, 'serialize_response_json'):
                return _lib.serialize_response_json(data)
        except Exception:
            pass
    
    # Try orjson (4-6x faster than stdlib)
    try:
        import orjson
        return orjson.dumps(data, option=orjson.OPT_NON_STR_KEYS)
    except ImportError:
        pass
    
    # Python fallback
    return json.dumps(data, separators=(',', ':')).encode('utf-8')


def fast_json_dumps_str(data: dict[str, Any]) -> str:
    """Serialize dict to JSON string.
    
    Backend priority: Rust > orjson > stdlib json
    Returns str for API compatibility.
    """
    return fast_json_dumps(data).decode('utf-8')


def fast_json_loads(data: bytes | str) -> Any:
    """Deserialize JSON using fastest available backend.
    
    Backend priority: Rust > orjson > stdlib json
    """
    # Try Rust first
    if _lib is not None:
        try:
            if hasattr(_lib, 'deserialize_request_json'):
                return _lib.deserialize_request_json(data)
        except Exception:
            pass
    
    # Try orjson
    try:
        import orjson
        if isinstance(data, str):
            data = data.encode('utf-8')
        return orjson.loads(data)
    except ImportError:
        pass
    
    # Python fallback
    if isinstance(data, bytes):
        data = data.decode('utf-8')
    return json.loads(data)


class CLIJsonBridge:
    """Rust-accelerated JSON serialization for CLI hot paths."""
    
    @staticmethod
    def dumps(data: dict[str, Any]) -> bytes:
        return fast_json_dumps(data)
    
    @staticmethod
    def dumps_str(data: dict[str, Any]) -> str:
        return fast_json_dumps_str(data)
    
    @staticmethod
    def loads(data: bytes | str) -> Any:
        return fast_json_loads(data)
    
    @staticmethod
    def get_backend() -> str:
        """Report which backend is active."""
        if _lib is not None and hasattr(_lib, 'serialize_response_json'):
            return "rust"
        try:
            import orjson
            return "orjson"
        except ImportError:
            return "json"


# Module-level convenience functions
dumps = fast_json_dumps
dumps_str = fast_json_dumps_str
loads = fast_json_loads
get_backend = CLIJsonBridge.get_backend
