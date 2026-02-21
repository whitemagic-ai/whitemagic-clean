"""Iceoryx2 IPC Bridge - Cross-process zero-copy communication.

Provides shared memory channels between WhiteMagic processes:
- wm/events: GanYing event bus
- wm/memories: Memory sync announcements  
- wm/commands: Agent coordination
- wm/harmony: Health pulse broadcast
"""

import json
import atexit
from typing import Optional, Dict, Any

# Lazy import of Rust module
_whitemagic_rs = None
_ipc_initialized = False

def _get_rs():
    global _whitemagic_rs
    if _whitemagic_rs is None:
        import whitemagic_rs as rs
        _whitemagic_rs = rs
    return _whitemagic_rs

def init_ipc(node_name: Optional[str] = None) -> Dict[str, Any]:
    """Initialize IPC bridge for this process."""
    global _ipc_initialized
    
    if _ipc_initialized:
        return {"initialized": True, "already": True}
    
    if node_name is None:
        import os
        node_name = f"wm_{os.getpid()}"
    
    rs = _get_rs()
    result = json.loads(rs.ipc_bridge_init(node_name))
    
    if result.get("initialized"):
        _ipc_initialized = True
        atexit.register(shutdown_ipc)
    
    return result

def publish(channel: str, payload: bytes) -> Dict[str, Any]:
    """Publish bytes to an IPC channel."""
    if not _ipc_initialized:
        init_ipc()
    
    rs = _get_rs()
    return json.loads(rs.ipc_bridge_publish(channel, payload))

def publish_json(channel: str, data: dict) -> Dict[str, Any]:
    """Publish JSON-serializable data to an IPC channel."""
    return publish(channel, json.dumps(data).encode())

def get_status() -> Dict[str, Any]:
    """Get IPC bridge status."""
    rs = _get_rs()
    return json.loads(rs.ipc_bridge_status())

def shutdown_ipc():
    """Shutdown IPC (auto-called at exit)."""
    global _ipc_initialized
    _ipc_initialized = False

# Auto-initialize on first use if WM_AUTO_IPC is set
import os
if os.environ.get("WM_AUTO_IPC", "0") == "1":
    init_ipc()
