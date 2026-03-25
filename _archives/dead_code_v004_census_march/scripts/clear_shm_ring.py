import os
try:
    os.remove("/dev/shm/whitemagic_event_ring")
    print("Cleared SHM ring buffer.")
except Exception as e:
    print(f"Error clearing: {e}")
