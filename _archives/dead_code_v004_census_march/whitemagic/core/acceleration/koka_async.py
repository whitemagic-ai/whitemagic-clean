#!/usr/bin/env python3
"""Async Koka Bridge - Non-blocking I/O for higher throughput.

Provides async/await interface to Koka binaries for maximum performance.
Target: 50K+ ops/sec via async batching.
"""

import asyncio
import json
import time
from typing import List, Optional
from dataclasses import dataclass
from collections import deque

_DEFAULT_ASYNC_KOKA_TIMEOUT_S = 5.0


@dataclass
class PendingCommand:
    cmd: dict
    future: asyncio.Future
    timestamp: float


class AsyncKokaRuntime:
    """Async interface to Koka binaries with batching."""
    
    def __init__(self, koka_dir: str = "./whitemagic-koka", max_batch_size: int = 100):
        self.koka_dir = koka_dir
        self.max_batch_size = max_batch_size
        self.pending: deque[PendingCommand] = deque()
        self.batch_interval = 0.01  # 10ms batching window
        self._batch_task: Optional[asyncio.Task] = None
        self._running = False
        self.metrics = {
            "commands_submitted": 0,
            "commands_executed": 0,
            "batches_sent": 0,
            "avg_batch_size": 0.0
        }
    
    async def start(self):
        """Start the async runtime."""
        self._running = True
        self._batch_task = asyncio.create_task(self._batch_processor())
    
    async def stop(self):
        """Stop the async runtime."""
        self._running = False
        if self._batch_task:
            self._batch_task.cancel()
            try:
                await self._batch_task
            except asyncio.CancelledError:
                pass
        
        # Process remaining pending commands
        while self.pending:
            await self._execute_batch()
    
    async def submit(self, cmd: dict) -> dict:
        """Submit a command and await result."""
        future = asyncio.get_event_loop().create_future()
        pending = PendingCommand(cmd, future, time.perf_counter())
        self.pending.append(pending)
        self.metrics["commands_submitted"] += 1
        
        # Trigger immediate execution if batch is full
        if len(self.pending) >= self.max_batch_size:
            asyncio.create_task(self._execute_batch())
        
        return await future
    
    async def batch_submit(self, cmds: List[dict]) -> List[dict]:
        """Submit multiple commands as a batch."""
        futures = []
        for cmd in cmds:
            future = asyncio.get_event_loop().create_future()
            pending = PendingCommand(cmd, future, time.perf_counter())
            self.pending.append(pending)
            futures.append(future)
        
        self.metrics["commands_submitted"] += len(cmds)
        
        # Execute immediately for batch submissions
        await self._execute_batch()
        
        return await asyncio.gather(*futures)
    
    async def _batch_processor(self):
        """Background task to process batches."""
        while self._running:
            await asyncio.sleep(self.batch_interval)
            if self.pending:
                await self._execute_batch()
    
    async def _execute_batch(self):
        """Execute a batch of pending commands."""
        if not self.pending:
            return
        
        # Collect batch
        batch: List[PendingCommand] = []
        while self.pending and len(batch) < self.max_batch_size:
            batch.append(self.pending.popleft())
        
        if not batch:
            return
        
        # Execute batch via subprocess
        start = time.perf_counter()
        
        try:
            # Use unified_runtime_v3 for batch processing
            proc = await asyncio.create_subprocess_exec(
                f"{self.koka_dir}/unified_runtime_v3",
                stdin=asyncio.subprocess.PIPE,
                stdout=asyncio.subprocess.PIPE
            )
            
            # Read startup
            await asyncio.wait_for(proc.stdout.readline(), timeout=2.0)
            
            # Send batch command
            batch_cmd = {
                "op": "batch",
                "cmds": [p.cmd for p in batch]
            }
            proc.stdin.write(json.dumps(batch_cmd).encode() + b"\n")
            await proc.stdin.drain()
            
            # Read response
            response = await asyncio.wait_for(proc.stdout.readline(), timeout=_DEFAULT_ASYNC_KOKA_TIMEOUT_S)
            result = json.loads(response.decode())
            
            # Close
            proc.stdin.write(b'{"op":"quit"}\n')
            await proc.stdin.drain()
            await asyncio.wait_for(proc.wait(), timeout=1.0)
            
            # Resolve futures
            if "results" in result:
                for i, pending in enumerate(batch):
                    if i < len(result["results"]):
                        pending.future.set_result(result["results"][i])
                    else:
                        pending.future.set_result({"error": "missing result"})
            else:
                # Single result for all
                for pending in batch:
                    pending.future.set_result(result)
            
            # Update metrics
            time.perf_counter() - start
            self.metrics["commands_executed"] += len(batch)
            self.metrics["batches_sent"] += 1
            self.metrics["avg_batch_size"] = (
                (self.metrics["avg_batch_size"] * (self.metrics["batches_sent"] - 1) + len(batch))
                / self.metrics["batches_sent"]
            )
            
        except Exception as e:
            try:
                proc.kill()
                await asyncio.wait_for(proc.wait(), timeout=1.0)
            except Exception:
                pass
            # Fail all pending commands in batch
            for pending in batch:
                pending.future.set_exception(e)
    
    def get_metrics(self) -> dict:
        """Get runtime metrics."""
        return {
            **self.metrics,
            "pending_commands": len(self.pending),
            "batch_interval_ms": self.batch_interval * 1000,
            "max_batch_size": self.max_batch_size
        }


class AsyncKokaPool:
    """Pool of async Koka runtimes for parallel processing."""
    
    def __init__(self, koka_dir: str = "./whitemagic-koka", pool_size: int = 4):
        self.koka_dir = koka_dir
        self.pool_size = pool_size
        self.runtimes: List[AsyncKokaRuntime] = []
        self._round_robin = 0
    
    async def start(self):
        """Start all runtimes in pool."""
        for i in range(self.pool_size):
            rt = AsyncKokaRuntime(self.koka_dir)
            await rt.start()
            self.runtimes.append(rt)
    
    async def stop(self):
        """Stop all runtimes."""
        for rt in self.runtimes:
            await rt.stop()
        self.runtimes.clear()
    
    async def submit(self, cmd: dict) -> dict:
        """Submit command to next available runtime."""
        idx = self._round_robin % len(self.runtimes)
        self._round_robin += 1
        return await self.runtimes[idx].submit(cmd)
    
    async def batch_submit(self, cmds: List[dict]) -> List[dict]:
        """Distribute batch across pool."""
        # Distribute commands round-robin
        batches: List[List[dict]] = [[] for _ in range(self.pool_size)]
        for i, cmd in enumerate(cmds):
            batches[i % self.pool_size].append(cmd)
        
        # Execute in parallel
        futures = []
        for i, batch in enumerate(batches):
            if batch:
                futures.append(self.runtimes[i].batch_submit(batch))
        
        results = await asyncio.gather(*futures)
        
        # Flatten results preserving order
        flat_results = []
        result_indices = [0] * self.pool_size
        for i, cmd in enumerate(cmds):
            pool_idx = i % self.pool_size
            if result_indices[pool_idx] < len(results[pool_idx]):
                flat_results.append(results[pool_idx][result_indices[pool_idx]])
                result_indices[pool_idx] += 1
        
        return flat_results
    
    def get_metrics(self) -> dict:
        """Get aggregate metrics."""
        all_metrics = [rt.get_metrics() for rt in self.runtimes]
        return {
            "pool_size": self.pool_size,
            "total_commands_submitted": sum(m["commands_submitted"] for m in all_metrics),
            "total_commands_executed": sum(m["commands_executed"] for m in all_metrics),
            "total_batches_sent": sum(m["batches_sent"] for m in all_metrics),
            "avg_batch_size": sum(m["avg_batch_size"] for m in all_metrics) / len(all_metrics) if all_metrics else 0,
            "per_runtime": all_metrics
        }


# Convenience functions
async def koka_emit(source: str, event: str, koka_dir: str = "./whitemagic-koka") -> dict:
    """Async emit event."""
    rt = AsyncKokaRuntime(koka_dir)
    await rt.start()
    result = await rt.submit({"op": "emit", "source": source, "event": event})
    await rt.stop()
    return result


async def koka_batch_emit(events: List[tuple], koka_dir: str = "./whitemagic-koka") -> List[dict]:
    """Async batch emit events."""
    rt = AsyncKokaRuntime(koka_dir)
    await rt.start()
    cmds = [{"op": "emit", "source": s, "event": e} for s, e in events]
    results = await rt.batch_submit(cmds)
    await rt.stop()
    return results
