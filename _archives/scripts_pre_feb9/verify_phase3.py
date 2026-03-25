import os
import sys
import unittest
import asyncio
import json
import sqlite3
from pathlib import Path

# Add staging to path
sys.path.append(os.path.abspath("staging/core_system"))

from whitemagic.interfaces.api.rate_limit import RateLimiter
from whitemagic.interfaces.terminal.executor import Executor
from whitemagic.interfaces.api.exec_service import _read_allowlist_file
from whitemagic.core.memory.migrations.runner import MigrationRunner, Migration

class TestPhase3Fixes(unittest.TestCase):
    def test_rate_limiter_concurrency(self):
        """Test RateLimiter thread-safety (asyncio.Lock)."""
        limit = 50
        limiter = RateLimiter(max_requests=limit, window_seconds=10)
        
        async def run_requests():
            tasks = [limiter.check_rate_limit("user1") for _ in range(limit + 10)]
            results = await asyncio.gather(*tasks)
            return results
        
        results = asyncio.run(run_requests())
        successes = [r for r in results if r is True]
        failures = [r for r in results if r is False]
        
        self.assertEqual(len(successes), limit)
        self.assertEqual(len(failures), 10)

    def test_sandbox_bypass_prevention(self):
        """Test that sandbox branding doesn't bypass allowlist."""
        # Executor reads sandbox_cmd from env var
        os.environ["WHITEMAGIC_EXEC_SANDBOX_CMD"] = "firejail --quiet"
        ex = Executor() 
        
        # 'dangerous_command_xyz' should be blocked by SafeExecutor allowlist
        result = ex.execute("dangerous_command_xyz", args=["--force"])
        self.assertIn("Security Error", result.stderr)
        self.assertEqual(result.exit_code, -1)

    def test_path_traversal_sanitization(self):
        """Test that user_key is sanitized in allowlist lookups."""
        async def run_check():
            # Try a traversal key
            res = await _read_allowlist_file("../../../etc/passwd")
            return res
        
        res = asyncio.run(run_check())
        self.assertEqual(res, {}) # Should return empty dict for non-existent (sanitized) file

    def test_migration_atomicity(self):
        """Test that migration batches are atomic."""
        db_path = Path("test_migrations_atomic.db")
        if db_path.exists(): db_path.unlink()
        
        class SuccessMigration(Migration):
            def upgrade(self, conn): conn.execute("CREATE TABLE t1 (id INT)")
            def downgrade(self, conn): pass

        class FailMigration(Migration):
            def upgrade(self, conn): 
                conn.execute("CREATE TABLE t2 (id INT)")
                raise ValueError("Planned failure")
            def downgrade(self, conn): pass

        runner = MigrationRunner(db_path)
        # Fix: MigrationRunner doesn't have add_migration, use internal list
        runner._migrations = [
            SuccessMigration(1, "Success"),
            FailMigration(2, "Fail")
        ]
        
        res = runner.upgrade()
        self.assertEqual(len(res["errors"]), 1)
        
        # Verify t1 was NOT created (or was rolled back)
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table' AND name='t1'")
        self.assertIsNone(cursor.fetchone(), "Table t1 should have been rolled back")
        conn.close()
        
        if os.path.exists(db_path): os.remove(db_path)

    def test_consolidate_memory_json(self):
        """Test that consolidate_memory uses valid JSON."""
        # We'll mock a small run of ingest_text_file
        from scripts.consolidate_memory import ingest_text_file
        
        db_path = "test_memory_json.db"
        if os.path.exists(db_path): os.remove(db_path)
        
        conn = sqlite3.connect(db_path)
        conn.execute("CREATE TABLE memories (id TEXT PRIMARY KEY, memory_type TEXT, content TEXT, metadata TEXT, created_at TEXT)")
        
        test_file = "test_ingest.txt"
        Path(test_file).write_text("Hello World")
        
        success = ingest_text_file(conn, test_file, "text", ["tag1", "tag2"])
        self.assertTrue(success, "ingest_text_file should return True")
        
        cursor = conn.cursor()
        cursor.execute("SELECT metadata FROM memories")
        row = cursor.fetchone()
        self.assertIsNotNone(row, "Should have found the ingested memory row")
        metadata_raw = row[0]
        
        # Try to parse as JSON
        try:
            metadata = json.loads(metadata_raw)
            self.assertEqual(metadata["tags"], ["tag1", "tag2"])
        except json.JSONDecodeError:
            self.fail("Metadata is not valid JSON")
        
        conn.close()
        if os.path.exists(db_path): os.remove(db_path)
        if os.path.exists(test_file): os.remove(test_file)

if __name__ == "__main__":
    unittest.main()
