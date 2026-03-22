
import os
import sys

# Add project root to path
sys.path.insert(0, os.getcwd())

try:
    from whitemagic.inference.local_embedder import LocalEmbedder
    print("Initializing LocalEmbedder...")
    embedder = LocalEmbedder()
    if embedder.is_available:
        print("Embedder available. Testing embedding...")
        vec = embedder.embed_query("This is a test of local inference.")
        if vec is not None and len(vec) > 0:
            print(f"Success! Vector shape: {vec.shape}")
        else:
            print("Failed to generate vector.")
    else:
        print("Embedder not available (imports failed).")
except Exception as e:
    print(f"Error: {e}")
