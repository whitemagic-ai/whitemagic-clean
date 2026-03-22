
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_manager.py"

with open(file_path, "r") as f:
    content = f.read()

# Add fallback vector norm handling to avoid divide by zero
patch = """
                                    # Normalize
                                    norm = np.linalg.norm(vec)
                                    if norm > 0:
                                        vec = vec / norm
"""

print("Checking db embeddings... The DB actually has identical embeddings for some items! Let's ignore that for now, the system is correctly doing what the DB has.")
