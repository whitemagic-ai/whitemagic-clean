"""SQLite Batch Bridge - Rust-accelerated database batch operations.

Phase 1 VC2: Translate sqlite_backend.py batch processing to Rust.
"""
from __future__ import annotations

import sqlite3
import threading
from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


class BatchInserter:
    """Rust-accelerated batch insertion for SQLite."""
    
    def __init__(self, conn: sqlite3.Connection) -> None:
        self.conn = conn
        self._lock = threading.Lock()
    
    def insert_memories_batch(
        self, 
        memories: list[dict[str, Any]], 
        batch_size: int = 1000
    ) -> int:
        """Batch insert memories with Rust acceleration.
        
        Returns number of records inserted.
        """
        if not memories:
            return 0
        
        # Try Rust fast path
        if _rs is not None and hasattr(_rs, 'batch_insert_memories'):
            try:
                return int(_rs.batch_insert_memories(self.conn, memories, batch_size))
            except Exception:
                pass
        
        # Python fallback with optimized executemany
        with self._lock:
            cursor = self.conn.cursor()
            inserted = 0
            
            for i in range(0, len(memories), batch_size):
                batch = memories[i:i + batch_size]
                cursor.executemany(
                    """INSERT OR REPLACE INTO memories 
                       (id, content, memory_type, created_at, updated_at, 
                        access_count, emotional_valence, importance, metadata, title)
                       VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""",
                    [
                        (
                            m.get('id'),
                            m.get('content'),
                            m.get('memory_type', 'SHORT_TERM'),
                            m.get('created_at'),
                            m.get('updated_at'),
                            m.get('access_count', 0),
                            m.get('emotional_valence', 0.0),
                            m.get('importance', 0.5),
                            m.get('metadata', '{}'),
                            m.get('title')
                        )
                        for m in batch
                    ]
                )
                inserted += len(batch)
            
            self.conn.commit()
            return inserted
    
    def insert_associations_batch(
        self,
        associations: list[tuple[str, str, float]],
        batch_size: int = 1000
    ) -> int:
        """Batch insert associations with Rust acceleration."""
        if not associations:
            return 0
        
        # Try Rust fast path
        if _rs is not None and hasattr(_rs, 'batch_insert_associations'):
            try:
                return int(_rs.batch_insert_associations(self.conn, associations, batch_size))
            except Exception:
                pass
        
        # Python fallback
        with self._lock:
            cursor = self.conn.cursor()
            inserted = 0
            
            for i in range(0, len(associations), batch_size):
                batch = associations[i:i + batch_size]
                cursor.executemany(
                    "INSERT OR REPLACE INTO associations (source_id, target_id, strength) VALUES (?, ?, ?)",
                    batch
                )
                inserted += len(batch)
            
            self.conn.commit()
            return inserted


class BatchQueryExecutor:
    """Rust-accelerated batch queries for SQLite."""
    
    def __init__(self, conn: sqlite3.Connection) -> None:
        self.conn = conn
    
    def fetch_batch(
        self,
        query: str,
        params: tuple[Any, ...] = (),
        batch_size: int = 1000
    ) -> list[sqlite3.Row]:
        """Fetch results in batches with Rust acceleration."""
        # Try Rust fast path
        if _rs is not None and hasattr(_rs, 'fetch_batch'):
            try:
                return list(_rs.fetch_batch(self.conn, query, params, batch_size))
            except Exception:
                pass
        
        # Python fallback
        cursor = self.conn.cursor()
        cursor.execute(query, params)
        return cursor.fetchall()
    
    def vacuum_and_analyze(self) -> None:
        """Optimize database with VACUUM and ANALYZE."""
        # Try Rust fast path
        if _rs is not None and hasattr(_rs, 'vacuum_analyze'):
            try:
                _rs.vacuum_analyze(self.conn)
                return
            except Exception:
                pass
        
        # Python fallback
        self.conn.execute("VACUUM")
        self.conn.execute("ANALYZE")


def get_batch_inserter(conn: sqlite3.Connection) -> BatchInserter:
    """Get a batch inserter for the connection."""
    return BatchInserter(conn)


def get_batch_query_executor(conn: sqlite3.Connection) -> BatchQueryExecutor:
    """Get a batch query executor for the connection."""
    return BatchQueryExecutor(conn)
