import json
import math
import sqlite3
import numpy as np
from whitemagic.core.memory.embeddings import _unpack_embedding, EMBEDDING_DIM

def find_poles():
    print("🔍 Analyzing embedding space for semantic poles...")
    
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
    
    # Calculate mean vector
    mean_vec = np.mean(X, axis=0)
    
    # Save mean vector
    mean_path = "core_system/data/semantic_mean_vector.json"
    with open(mean_path, "w") as f:
        json.dump(mean_vec.tolist(), f)
    print(f"✅ Updated semantic mean vector at {mean_path}")
    
    # Center X
    X_centered = X - mean_vec
    
    # Find poles using PCA or just max variance directions
    # For now, let's find the vectors furthest from the mean in opposite directions
    # 1. Logic vs Emotion (we'll look for keywords to find the initial seed, then find neighbors)
    
    def find_extreme_by_keywords(pos_kws, neg_kws):
        # Find memories matching keywords to get a direction
        pos_indices = []
        neg_indices = []
        
        for i, mid in enumerate(ids):
            # Fetch content for keywords
            row = conn.execute("SELECT title, content FROM memories WHERE id = ?", (mid,)).fetchone()
            if not row: continue
            text = (row[0] or "") + " " + (row[1] or "")
            text = text.lower()
            
            if any(kw in text for kw in pos_kws):
                pos_indices.append(i)
            if any(kw in text for kw in neg_kws):
                neg_indices.append(i)
        
        if not pos_indices or not neg_indices:
            return None, None
            
        # Get mean direction for pos and neg
        pos_dir = np.mean(X_centered[pos_indices], axis=0)
        neg_dir = np.mean(X_centered[neg_indices], axis=0)
        
        # Normalize
        pos_dir /= np.linalg.norm(pos_dir)
        neg_dir /= np.linalg.norm(neg_dir)
        
        # Find furthest in these directions
        pos_scores = X_centered @ pos_dir
        neg_scores = X_centered @ neg_dir
        
        best_pos_idx = np.argmax(pos_scores)
        best_neg_idx = np.argmax(neg_scores)
        
        return ids[best_pos_idx], ids[best_neg_idx]

    print("📍 Finding Logic <-> Emotion poles...")
    logic_id, emotion_id = find_extreme_by_keywords(
        ["logic", "strategy", "algorithm", "code", "technical", "implementation", "audit"],
        ["emotion", "feeling", "joy", "fear", "love", "wonder", "sacred", "intuition"]
    )
    
    print(f"   Logic Anchor:   {logic_id}")
    print(f"   Emotion Anchor: {emotion_id}")
    
    print("📍 Finding Macro <-> Micro poles...")
    macro_id, micro_id = find_extreme_by_keywords(
        ["macro", "pattern", "principle", "wisdom", "overview", "philosophy", "insight"],
        ["micro", "detail", "specific", "log", "raw", "debug", "traceback", "line"]
    )
    
    print(f"   Macro Anchor:   {macro_id}")
    print(f"   Micro Anchor:   {micro_id}")
    
    # Output the constants for encoder.py
    print("\n🚀 Updated Constants for CoordinateEncoder in whitemagic/core/intelligence/hologram/encoder.py:")
    print(f"    ANCHOR_LOGIC_ID = \"{logic_id}\"")
    print(f"    ANCHOR_EMOTION_ID = \"{emotion_id}\"")
    print(f"    ANCHOR_MICRO_ID = \"{micro_id}\"")
    print(f"    ANCHOR_MACRO_ID = \"{macro_id}\"")

if __name__ == "__main__":
    find_poles()
