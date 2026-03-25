import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.core.acceleration.hybrid_dispatcher_v2 import get_dispatcher
from whitemagic.core.acceleration.koka_native_bridge import get_koka_bridge

def main():
    print("Testing Hybrid Dispatcher Fast Brain Hook...")
    
    # Pre-register the unified_fast_brain in Koka Bridge 
    bridge = get_koka_bridge()
    bridge._binaries["unified_fast_brain"] = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain"
    
    dispatcher = get_dispatcher()
    status = dispatcher.health_check()
    
    print("Dispatcher Health Check Result:")
    import json
    print(json.dumps(status, indent=2))
    
    if status.get("fast_brain", {}).get("active"):
        print("Success! Unified Fast Brain is recognized by the main Python dispatcher.")
    else:
        print("Failed to recognize Fast Brain.")

if __name__ == "__main__":
    main()
