import time
import uuid
import random
import logging
from pathlib import Path
from whitemagic.core.memory.sqlite_backend import SQLiteBackend
from whitemagic.core.memory.unified_types import Memory, MemoryType
from datetime import datetime

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("stress_test")

def run_stress_test(num_memories=10000, batch_size=1000):
    db_path = Path("stress_test_v21.db")
    if db_path.exists():
        db_path.unlink()
    
    backend = SQLiteBackend(db_path)
    logger.info(f"Starting 10K Worker Stress Test (v21 Polyglot Architecture) - Scale Verification")
    
    start_time = time.perf_counter()
    
    def generate_batch(size, offset):
        batch = []
        for i in range(size):
            m_id = str(uuid.uuid4())
            m = Memory(
                id=m_id,
                content=f"Stress test content for worker {offset + i}. Testing high-concurrency polyglot persistence.",
                memory_type=MemoryType.SHORT_TERM,
                created_at=datetime.now(),
                importance=random.random(),
                title=f"Worker Task {offset + i}",
                tags=["stress-test", "v21", "scaling"]
            )
            batch.append(m)
        return batch

    total_inserted = 0
    for i in range(0, num_memories, batch_size):
        batch = generate_batch(batch_size, i)
        for m in batch:
            backend.store(m)
        total_inserted += len(batch)
        logger.info(f"Inserted {total_inserted} memories...")

    end_time = time.perf_counter()
    duration = end_time - start_time
    logger.info(f"Test Complete: {total_inserted} memories in {duration:.2f}s ({total_inserted/duration:.2f} ops/s)")
    
    if db_path.exists():
        db_path.unlink()

if __name__ == "__main__":
    run_stress_test()
