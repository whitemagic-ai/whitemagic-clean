#!/usr/bin/env python3
"""
Re-index Failed Memories
========================
Script to verify all 193k living memories can be indexed with null safety.
Uses the fixed FastBatchEncoder with proper null coalescing.
"""

import sqlite3
import time
import sys
import json
import logging
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.intelligence.hologram.batch_encoder import FastBatchEncoder

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)


def parse_timestamp(ts_str):
    """Parse timestamp string to Unix timestamp with format flexibility."""
    if not ts_str:
        return int(time.time())
    try:
        # Handle ISO 8601 with T separator
        ts_str = ts_str[:19].replace('T', ' ')
        return int(time.mktime(time.strptime(ts_str, '%Y-%m-%d %H:%M:%S')))
    except:
        return int(time.time())


def main():
    db_path = Path(__file__).parent.parent / "memory" / "whitemagic.db"
    
    if not db_path.exists():
        logger.error(f"Database not found at {db_path}")
        return
    
    logger.info("=" * 60)
    logger.info("RE-INDEXING FAILED MEMORIES")
    logger.info("Phase 24: Mojo Optimization")
    logger.info("=" * 60)
    
    conn = sqlite3.connect(db_path)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    
    # Find memories that were likely to have failed (None importance/neuro_score)
    cursor.execute("""
        SELECT COUNT(*) FROM memories 
        WHERE (memory_type IS NULL OR memory_type != 'substrate')
        AND (importance IS NULL OR neuro_score IS NULL)
    """)
    null_count = cursor.fetchone()[0]
    logger.info(f"Memories with NULL importance or neuro_score: {null_count}")
    
    # Fetch all living memories for re-indexing
    cursor.execute("""
        SELECT id, content, title, metadata, memory_type, importance, neuro_score,
               emotional_valence, created_at, updated_at
        FROM memories
        WHERE memory_type IS NULL OR memory_type != 'substrate'
        ORDER BY id
    """)
    
    rows = cursor.fetchall()
    total = len(rows)
    logger.info(f"Total living memories to verify indexing: {total}")
    
    encoder = FastBatchEncoder()
    
    # Process in batches
    batch_size = 1000
    indexed = 0
    errors = 0
    start_time = time.time()
    
    for i in range(0, total, batch_size):
        batch_rows = rows[i:i+batch_size]
        batch_memories = []
        
        for row in batch_rows:
            # Parse tags from metadata if present
            tags = []
            try:
                if row['metadata']:
                    meta = json.loads(row['metadata'])
                    tags = meta.get('tags', [])
            except:
                pass
            
            mem = {
                'id': row['id'],
                'content': row['content'] or '',
                'title': row['title'] or '',
                'tags': tags,
                'memory_type': row['memory_type'],
                'importance': row['importance'],
                'neuro_score': row['neuro_score'],
                'emotional_valence': row['emotional_valence'],
                'joy_score': 0.0,
                'resonance_score': 0.0,
                'created_timestamp': parse_timestamp(row['created_at']),
            }
            batch_memories.append(mem)
        
        try:
            results = encoder.encode_batch(batch_memories)
            indexed += len(results)
        except Exception as e:
            errors += len(batch_rows)
            logger.error(f"Batch error at {i}: {e}")
        
        if (i + batch_size) % 10000 == 0 or i + batch_size >= total:
            elapsed = time.time() - start_time
            rate = indexed / elapsed if elapsed > 0 else 0
            pct = (i + batch_size) / total * 100
            logger.info(f"Progress: {min(i+batch_size, total):,}/{total:,} ({pct:.1f}%) | Rate: {rate:.0f}/sec | Errors: {errors}")
    
    elapsed = time.time() - start_time
    
    logger.info("=" * 60)
    logger.info(f"COMPLETE: {indexed:,} memories verified in {elapsed:.1f}s")
    logger.info(f"Rate: {indexed/elapsed:.0f} memories/second")
    logger.info(f"Errors: {errors}")
    success_rate = (indexed/(indexed+errors))*100 if (indexed+errors) > 0 else 0
    logger.info(f"Success Rate: {success_rate:.1f}%")
    logger.info("=" * 60)
    
    conn.close()


if __name__ == "__main__":
    main()
