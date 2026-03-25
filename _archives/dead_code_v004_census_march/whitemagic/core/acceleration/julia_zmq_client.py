"""Julia ZMQ Client — Persistent connection to eliminate JIT startup cost.
===========================================================
Starts julia_server.jl as background process, communicates via ZMQ REQ/REP.
Falls back to subprocess mode if server unavailable.
"""
from __future__ import annotations

import logging
import subprocess
import threading
import time
from pathlib import Path
from typing import Any

logger = logging.getLogger(__name__)

_JULIA_SERVER_PROC: subprocess.Popen | None = None
_JULIA_ZMQ_SOCKET: Any = None
_JULIA_LOCK = threading.Lock()
_SERVER_URL = "tcp://127.0.0.1:5555"
_JULIA_DIR = Path(__file__).resolve().parent.parent.parent.parent.parent / "whitemagic-julia" / "src"


def _ensure_zmq():
    """Lazy import zmq to avoid dependency issues."""
    try:
        import zmq
        return zmq
    except ImportError:
        return None


def _start_julia_server() -> bool:
    """Start the Julia ZMQ server as background process."""
    global _JULIA_SERVER_PROC
    
    # Check if already running
    try:
        import zmq
        ctx = zmq.Context()
        sock = ctx.socket(zmq.REQ)
        sock.setsockopt(zmq.RCVTIMEO, 500)
        sock.connect(_SERVER_URL)
        sock.send_json({"command": "ping"})
        resp = sock.recv_json()
        if resp.get("pong") or resp.get("status") == "ok":
            logger.debug("Julia server already running")
            return True
    except Exception:
        pass
    
    server_file = _JULIA_DIR / "julia_server_min.jl"
    if not server_file.exists():
        logger.error("Julia server file not found: %s", server_file)
        return False
    
    try:
        proc = subprocess.Popen(
            ["julia", str(server_file)],
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
            start_new_session=True,
        )
        _JULIA_SERVER_PROC = proc
        
        # Wait for server to be ready
        import zmq
        ctx = zmq.Context()
        sock = ctx.socket(zmq.REQ)
        sock.setsockopt(zmq.RCVTIMEO, 2000)
        sock.connect(_SERVER_URL)
        
        for _ in range(10):  # 10 retries, ~3.7s JIT time
            try:
                sock.send_json({"command": "ping"})
                resp = sock.recv_json()
                if resp.get("pong") or resp.get("status") == "ok":
                    logger.info("Julia ZMQ server ready (JIT warmup complete)")
                    sock.close()
                    return True
            except Exception:
                time.sleep(0.5)
        
        sock.close()
        logger.warning("Julia server startup timeout")
        return False
        
    except Exception as e:
        logger.error("Failed to start Julia server: %s", e)
        return False


def julia_zmq_call(command: str, **params) -> dict[str, Any] | None:
    """Call Julia via ZMQ (persistent connection, no JIT startup per call)."""
    zmq = _ensure_zmq()
    if zmq is None:
        return None
    
    with _JULIA_LOCK:
        if not _start_julia_server():
            return None
        
        try:
            ctx = zmq.Context()
            sock = ctx.socket(zmq.REQ)
            sock.setsockopt(zmq.RCVTIMEO, 5000)  # 5s timeout
            sock.setsockopt(zmq.SNDTIMEO, 5000)
            sock.connect(_SERVER_URL)
            
            request = {"command": command, **params}
            sock.send_json(request)
            response = sock.recv_json()
            
            sock.close()
            ctx.term()
            return response
            
        except Exception as e:
            logger.debug("Julia ZMQ call failed: %s", e)
            return None


def julia_rrf_fuse_zmq(lists: list[list[dict]], weights: list[float] | None = None, k: float = 60.0) -> list[dict] | None:
    """RRF fusion via ZMQ (persistent Julia, no JIT per call)."""
    weights = weights or [1.0] * len(lists)
    resp = julia_zmq_call("rrf_fuse", lists=lists, weights=weights, k=k)
    if resp and "fused" in resp:
        return resp["fused"]
    return None


def julia_pagerank_zmq(node_ids: list[str], edges: list[dict], damping: float = 0.85) -> dict[str, float] | None:
    """PageRank via ZMQ."""
    resp = julia_zmq_call("pagerank", node_ids=node_ids, edges=edges, damping=damping)
    if resp and "pagerank" in resp:
        return resp["pagerank"]
    return None


def julia_zmq_status() -> dict[str, Any]:
    """Get Julia ZMQ client status."""
    zmq = _ensure_zmq()
    if zmq is None:
        return {"available": False, "reason": "zmq not installed"}
    
    ping = julia_zmq_call("ping")
    return {
        "available": ping is not None,
        "server_running": ping is not None,
        "julia_version": ping.get("julia_version") if ping else None,
        "server_url": _SERVER_URL,
    }
