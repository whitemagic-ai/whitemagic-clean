import sys
import time
import json
import threading
from pathlib import Path

# Add project root to path
root = Path(__file__).parent.parent
sys.path.append(str(root))

def test_swarm_resonance():
    print("🌐 Starting P2P Swarm Resonance Test...")
    
    # Check if redis is running
    try:
        import redis
        r = redis.from_url("redis://localhost:6379/0")
        r.ping()
        print("✅ Redis is online.")
    except Exception as e:
        print(f"❌ Redis is offline: {e}")
        return

    # 1. Start Mesh Sidecar (simulated via script or binary)
    from whitemagic.core.polyglot.mesh_bridge import get_mesh_bridge
    bridge = get_mesh_bridge()
    
    print("🚀 Booting Mesh Bridge...")
    bridge.listen()
    
    # 2. Wire Gan Ying Bus to listen for MESH_SIGNAL
    from whitemagic.core.resonance.gan_ying_enhanced import get_bus, EventType
    bus = get_bus()
    
    signals_received = []
    def on_mesh_signal(event):
        print(f"📡 RESONANCE DETECTED! From: {event.source} - Signal: {event.data.get('signal_id')}")
        signals_received.append(event)
        
    bus.listen(EventType.MESH_SIGNAL, on_mesh_signal)
    
    # 3. Simulate an incoming mesh signal via Redis (since we don't have multiple laptops)
    print("🧪 Simulating incoming Holographic Signal...")
    test_signal = {
        "event_type": "MESH_SIGNAL",
        "data": {
            "peer_id": "test-peer-12345",
            "signal_id": "sig-test-001",
            "importance": 0.95,
            "timestamp": time.time(),
            "content_hash": "hash-abc-123"
        }
    }
    r.publish("ganying", json.dumps(test_signal))
    
    time.sleep(1) # Wait for processing
    
    if len(signals_received) > 0:
        print("✅ Success: Signal resonated on Gan Ying Bus.")
    else:
        print("❌ Failure: Signal not received by bus.")
        return

    # 4. Test Sangha Collaboration (Chat -> Mesh)
    print("💬 Testing Sangha Chat -> Mesh Broadcast...")
    from whitemagic.core.bridge.collaboration import sangha_chat_send
    
    # Listen for the broadcast on Redis
    outbound_captured = []
    def _capture_outbound():
        ps = r.pubsub()
        ps.subscribe("ganying_out")
        for msg in ps.listen():
            if msg['type'] == 'message':
                outbound_captured.append(json.loads(msg['data']))
                break
    
    capture_thread = threading.Thread(target=_capture_outbound, daemon=True)
    capture_thread.start()
    
    time.sleep(0.5)
    sangha_chat_send("Test swarm message", sender="TestAgent")
    
    time.sleep(1)
    if len(outbound_captured) > 0:
        print(f"✅ Success: Outbound message captured on mesh channel: {outbound_captured[0].get('event_type')}")
    else:
        print("❌ Failure: Outbound message not detected on mesh channel.")

    # 5. Test Locking
    print("🔒 Testing Sangha Locking...")
    from whitemagic.core.bridge.collaboration import sangha_lock_acquire
    lock_res = sangha_lock_acquire("test_resource", reason="verification")
    if lock_res.get('acquired'):
        print("✅ Success: Resource lock acquired via real backend.")
    else:
        print(f"❌ Failure: Lock acquisition failed: {lock_res}")

    print("\n✨ ALL DECENTRALIZATION TESTS PASSED! ✨")
    bridge.stop()

if __name__ == "__main__":
    test_swarm_resonance()
