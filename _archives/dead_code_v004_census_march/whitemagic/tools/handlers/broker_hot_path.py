"""Broker Hot Path - Zig-Accelerated Message Broker
Target: 100-1000x speedup for Redis pub/sub
"""
import ctypes
import json
import os

_zig_lib = None

def _load_zig_lib():
    global _zig_lib
    if _zig_lib is None:
        lib_path = os.path.join(
            os.path.dirname(__file__),
            "../../../whitemagic-zig/zig-out/lib/libbroker.so"
        )
        if os.path.exists(lib_path):
            _zig_lib = ctypes.CDLL(lib_path)
            _zig_lib.broker_init.argtypes = [ctypes.c_size_t]
            _zig_lib.broker_init.restype = ctypes.c_bool
            _zig_lib.get_broker_timestamp_ns.argtypes = []
            _zig_lib.get_broker_timestamp_ns.restype = ctypes.c_int64
    return _zig_lib is not None

class BrokerMessage(ctypes.Structure):
    _fields_ = [
        ("channel", ctypes.c_char * 128),
        ("channel_len", ctypes.c_uint32),
        ("payload", ctypes.c_char * 4096),
        ("payload_len", ctypes.c_uint32),
        ("timestamp_ns", ctypes.c_int64),
        ("msg_id", ctypes.c_char * 64),
        ("id_len", ctypes.c_uint32),
        ("priority", ctypes.c_uint8),
    ]

def fast_publish(channel: str, payload: dict, priority: int = 0) -> bool:
    """Publish message via Zig-accelerated broker."""
    if not _load_zig_lib():
        return False
    
    msg = BrokerMessage()
    channel_bytes = channel.encode('utf-8')[:127]
    payload_bytes = json.dumps(payload).encode('utf-8')[:4095]
    
    msg.channel = channel_bytes.ljust(128, b'\x00')
    msg.channel_len = len(channel_bytes)
    msg.payload = payload_bytes.ljust(4096, b'\x00')
    msg.payload_len = len(payload_bytes)
    msg.timestamp_ns = _zig_lib.get_broker_timestamp_ns()
    msg.priority = priority
    
    # Generate ID via Zig
    msg_id = f"msg_{msg.timestamp_ns}_{os.urandom(4).hex()}".encode('utf-8')[:63]
    msg.msg_id = msg_id.ljust(64, b'\x00')
    msg.id_len = len(msg_id)
    
    return _zig_lib.broker_publish(ctypes.byref(msg))

def install_hot_paths():
    """Install broker hot paths."""
    try:
        if _load_zig_lib():
            _zig_lib.broker_init(100000)
            print("[broker_hot_path] Zig broker initialized")
        return True
    except Exception as e:
        print(f"[broker_hot_path] {e}")
        return False

install_hot_paths()
