import time
import uuid
import random
import logging
import os
import sys
from pathlib import Path
from datetime import datetime

# Simple ASCII Progress Bar with explicit flushing
def print_progress(current, total, bar_length=40):
    percent = float(current) / total
    arrow = '-' * int(round(percent * bar_length) - 1) + '>'
    spaces = ' ' * (bar_length - len(arrow))
    sys.stdout.write(f"\rInserting Memories: [{arrow + spaces}] {int(percent * 100)}% ({current}/{total})")
    sys.stdout.flush()

from whitemagic.core.memory.sqlite_backend import SQLiteBackend
from whitemagic.core.memory.unified_types import Memory, MemoryType

logging.basicConfig(level=logging.WARNING)

def run_stress_test(num_memories=5000, batch_size=100):
    db_path = Path("stress_test_v21.db")
    if db_path.exists():
        db_path.unlink()
    
    # Force use of the backend which now has Koka fallbacks
    backend = SQLiteBackend(db_path)
    
    print(f"\n🚀 Starting v21 Polyglot Stress Test (Reliable Feedback Mode)")
    print(f"   Target: {num_memories} memories")
    print(f"   Batch Size: {batch_size}")
    print(f"   Database: {db_path}\n")

    start_time = time.perf_counter()
    
    def generate_memory(idx):
        m_id = str(uuid.uuid4())
        return Memory(
            id=m_id,
            content=f"Stress test entry {idx}. Verifying v21 polyglot stability.",
            memory_type=MemoryType.SHORT_TERM,
            created_at=datetime.now(),
            importance=random.random(),
            title=f"Worker Load {idx}",
            tags=["v21-stress", "polyglot-test"]
        )

    total_inserted = 0
    print_progress(0, num_memories)

    for i in range(0, num_memories, batch_size):
        current_batch_size = min(batch_size, num_memories - total_inserted)
        for j in range(current_batch_size):
            m = generate_memory(total_inserted + j)
            try:
                # Each store call triggers Koka transaction logic with timeout/fallbacks
                backend.store(m)
            except Exception as e:
                sys.stdout.write(f"\n❌ Error storing memory {total_inserted + j}: {e}\n")
                sys.stdout.flush()
                continue
        
        total_inserted += current_batch_size
        print_progress(total_inserted, num_memories)

    end_time = time.perf_counter()
    duration = end_time - start_time
    ops_per_sec = total_inserted / duration if duration > 0 else 0

    print(f"\n\n✅ Stress Test Complete")
    print(f"   Total Inserted: {total_inserted}")
    print(f"   Duration: {duration:.2f}s")
    print(f"   Throughput: {ops_per_sec:.2f} ops/s")
    
    if db_path.exists():
        db_path.unlink()

if __name__ == "__main__":
    # 5000 items is enough to verify scale and stability without hanging the environment
    run_stress_test(num_memories=5000, batch_size=100)
