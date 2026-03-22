#!/usr/bin/env python3
"""
SHADOW CLONE ARMY: BATCH EMBEDDING DEPLOYMENT
==============================================
Deploy massive parallel embedding army for 97,435 remaining memories
"""

import json
import multiprocessing as mp
import sqlite3
import sys
from pathlib import Path
from datetime import datetime, timezone

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

ACTIVE_DB = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
BATCH_SIZE = 256
NUM_CLONES = min(mp.cpu_count() * 4, 32)  # 4x CPU cores, max 32

print("=" * 80)
print("SHADOW CLONE ARMY: BATCH EMBEDDING DEPLOYMENT")
print("=" * 80)
print()
print(f"Army Size: {NUM_CLONES} shadow clones")
print(f"Batch Size: {BATCH_SIZE} memories per clone")
print()

def embed_batch(batch_id, memory_ids, start_idx):
    """Shadow clone worker function."""
    try:
        from whitemagic.core.memory.embedding_engine import EmbeddingEngine
        import pickle
        
        conn = sqlite3.connect(str(ACTIVE_DB))
        cursor = conn.cursor()
        
        # Get batch of memories
        placeholders = ','.join('?' * len(memory_ids))
        cursor.execute(f"""
            SELECT id, content FROM memories 
            WHERE id IN ({placeholders})
            AND content IS NOT NULL
        """, memory_ids)
        
        memories = cursor.fetchall()
        
        # Initialize embedding engine
        engine = EmbeddingEngine()
        
        embedded = 0
        for mem_id, content in memories:
            try:
                # Generate embedding
                embedding = engine.encode(content[:8000])
                embedding_blob = pickle.dumps(embedding)
                
                cursor.execute(
                    "UPDATE memories SET embedding = ?, embedding_model = ? WHERE id = ?",
                    (embedding_blob, "sentence-transformers", mem_id)
                )
                embedded += 1
                
            except Exception:
                continue
        
        conn.commit()
        conn.close()
        
        return {
            "clone_id": batch_id,
            "embedded": embedded,
            "total": len(memories),
            "start_idx": start_idx,
        }
        
    except Exception as e:
        return {
            "clone_id": batch_id,
            "error": str(e),
            "embedded": 0,
        }

def main():
    # Get all memories without embeddings
    conn = sqlite3.connect(str(ACTIVE_DB))
    cursor = conn.cursor()
    
    cursor.execute("""
        SELECT id FROM memories 
        WHERE embedding IS NULL 
        AND content IS NOT NULL 
        AND length(content) > 10
        ORDER BY created_at DESC
    """)
    
    all_memory_ids = [row[0] for row in cursor.fetchall()]
    total_memories = len(all_memory_ids)
    
    print(f"Target: {total_memories:,} memories to embed")
    print()
    
    if total_memories == 0:
        print("✅ All memories already embedded!")
        conn.close()
        return
    
    # Split into batches for shadow clones
    batches = []
    for i in range(0, total_memories, BATCH_SIZE):
        batch = all_memory_ids[i:i+BATCH_SIZE]
        batches.append((len(batches), batch, i))
    
    print(f"Deploying {len(batches)} batches across {NUM_CLONES} shadow clones...")
    print()
    
    # Deploy shadow clone army
    with mp.Pool(processes=NUM_CLONES) as pool:
        results = pool.starmap(embed_batch, batches)
    
    # Aggregate results
    total_embedded = sum(r.get("embedded", 0) for r in results)
    total_errors = sum(1 for r in results if "error" in r)
    
    print()
    print("─" * 80)
    print("SHADOW CLONE ARMY REPORT")
    print("─" * 80)
    print(f"Total embedded: {total_embedded:,}")
    print(f"Batches completed: {len(batches) - total_errors}")
    print(f"Batches with errors: {total_errors}")
    print()
    
    # Verify final state
    cursor.execute("SELECT COUNT(*) FROM memories WHERE embedding IS NOT NULL")
    final_embedded = cursor.fetchone()[0]
    
    cursor.execute("SELECT COUNT(*) FROM memories")
    total = cursor.fetchone()[0]
    
    coverage = (final_embedded / total * 100) if total > 0 else 0
    
    print(f"Final coverage: {final_embedded:,}/{total:,} ({coverage:.1f}%)")
    
    conn.close()
    
    # Save report
    report = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "army_size": NUM_CLONES,
        "batches": len(batches),
        "embedded": total_embedded,
        "errors": total_errors,
        "final_coverage": coverage,
    }
    
    report_path = PROJECT_ROOT / "reports" / "embedding_army_report.json"
    report_path.write_text(json.dumps(report, indent=2))
    
    print(f"📄 Report: {report_path}")
    print()
    print("✅ Shadow clone army deployment complete!")

if __name__ == "__main__":
    main()
