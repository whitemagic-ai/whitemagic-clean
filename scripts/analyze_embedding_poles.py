import json
import math
import sqlite3
import numpy as np
from whitemagic.core.memory.embeddings import _unpack_embedding, EMBEDDING_DIM

def find_poles():
    print("🔍 Performing SVD-based PCA on embedding space for optimal 5D alignment...")
    
    db_path = "memory/whitemagic.db"
    conn = sqlite3.connect(db_path)
    
    # Load all embeddings
    rows = conn.execute("SELECT memory_id, embedding FROM memory_embeddings").fetchall()
    if not rows:
        print("❌ No embeddings found.")
        return

    ids = []
    vecs = []
    for r in rows:
        vec = _unpack_embedding(r[1])
        if len(vec) == EMBEDDING_DIM:
            ids.append(r[0])
            vecs.append(vec)
            
    X = np.array(vecs)
    print(f"Loaded {len(ids)} embeddings.")
    
    # 1. Calculate and save mean vector
    mean_vec = np.mean(X, axis=0)
    mean_path = "core_system/data/semantic_mean_vector.json"
    with open(mean_path, "w") as f:
        json.dump(mean_vec.tolist(), f)
    print(f"✅ Updated semantic mean vector at {mean_path}")
    
    # 2. Perform SVD for Principal Components
    X_centered = X - mean_vec
    # full_matrices=False gives us the economy SVD
    u, s, vh = np.linalg.svd(X_centered, full_matrices=False)
    
    # Principal components are the rows of vh
    pc1 = vh[0]
    pc2 = vh[1]
    
    # Calculate explained variance ratio
    total_var = np.sum(s**2)
    explained_variance = (s**2) / total_var
    
    # Save PCA components
    pca_path = "core_system/data/semantic_pca_components.json"
    with open(pca_path, "w") as f:
        json.dump({
            "x_axis": pc1.tolist(),
            "y_axis": pc2.tolist(),
            "explained_variance": explained_variance[:2].tolist()
        }, f)
    print(f"✅ Saved PCA components to {pca_path}")
    print(f"   Explained Variance: X={explained_variance[0]*100:.1f}%, Y={explained_variance[1]*100:.1f}%")

    # 3. Find the "extreme" memories for these PCA axes
    projections = X_centered @ vh[:2].T # Shape (N, 2)
    
    best_x_pos = np.argmax(projections[:, 0])
    best_x_neg = np.argmin(projections[:, 0])
    best_y_pos = np.argmax(projections[:, 1])
    best_y_neg = np.argmin(projections[:, 1])
    
    logic_id = ids[best_x_pos]
    emotion_id = ids[best_x_neg]
    macro_id = ids[best_y_pos]
    micro_id = ids[best_y_neg]
    
    print("\n🚀 Updated Constants for CoordinateEncoder in whitemagic/core/intelligence/hologram/encoder.py:")
    print(f"    ANCHOR_LOGIC_ID = \"{logic_id}\"")
    print(f"    ANCHOR_EMOTION_ID = \"{emotion_id}\"")
    print(f"    ANCHOR_MICRO_ID = \"{micro_id}\"")
    print(f"    ANCHOR_MACRO_ID = \"{macro_id}\"")

if __name__ == "__main__":
    find_poles()
