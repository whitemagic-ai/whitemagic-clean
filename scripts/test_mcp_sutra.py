import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.tools.unified_api import call_tool

print("Testing safe action...")
result = call_tool("health_report")
print("Safe action succeeded:", "status" in result)

print("\nTesting dangerous action (delete_dharma)...")
try:
    # We pass 'delete_dharma' inside the params to trigger the Sutra kernel
    result = call_tool("health_report", forbidden_payload="delete_dharma")
    print("If you see this, the kernel failed to stop it!")
except Exception as e:
    print(f"Exception caught: {e}")
    print("Type:", type(e).__name__)
