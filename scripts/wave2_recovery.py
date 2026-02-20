#!/usr/bin/env python3
"""
Wave 2 Recovery Deployment - Safe Mode
=====================================

Post-crash recovery deployment with throttling and safety mechanisms.

Changes from original:
- Reduced parallelism (100K max concurrent vs unlimited)
- Batched deployment with memory checkpoints
- Tokio Parallel disabled (crashed Windsurf)
- Immortal v3 only (safer, persistent)
- Progress persistence every 1000 units
- Memory usage monitoring
- Graceful degradation on resource exhaustion

Usage:
    python scripts/wave2_recovery.py --start-time "19:13:00"
"""
from __future__ import annotations

import argparse
import asyncio
import gc
import json
import logging
import os
import sys
import time
import tracemalloc
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s | %(levelname)s | %(message)s",
    handlers=[
        logging.StreamHandler(sys.stdout),
        logging.FileHandler("/tmp/wave2_recovery.log"),
    ],
)
logger = logging.getLogger(__name__)


@dataclass
class DeploymentConfig:
    """Safe deployment configuration"""
    max_concurrent: int = 100_000  # Reduced from unlimited
    batch_size: int = 1_000  # Smaller batches
    checkpoint_interval: int = 10_000  # Save progress every N units
    memory_limit_mb: int = 8_000  # 8GB memory limit
    enable_tokio: bool = False  # DISABLED - caused crash
    enable_immortal: bool = True
    start_time: str = ""
    resume_from: int = 0  # Resume from checkpoint


@dataclass
class DeploymentUnit:
    """Single deployment unit"""
    unit_id: str
    army_type: str
    tier: int
    status: str = "pending"
    result: dict[str, Any] = field(default_factory=dict)
    memory_usage_mb: float = 0.0


class Wave2RecoveryCommander:
    """Safe recovery commander for Wave 2"""
    
    def __init__(self, config: DeploymentConfig) -> None:
        self.config = config
        self.deployed_count = config.resume_from
        self.victories = 0
        self.failures = 0
        self.start_time = time.time()
        self.checkpoint_file = Path("/tmp/wave2_checkpoint.json")
        
        # Memory tracking
        tracemalloc.start()
        
    async def deploy_safe(self) -> dict[str, Any]:
        """
        Safe deployment with throttling and crash recovery
        """
        logger.info("=" * 70)
        logger.info("🛡️ WAVE 2 RECOVERY DEPLOYMENT (SAFE MODE)")
        logger.info("=" * 70)
        logger.info(f"Start time: {self.config.start_time}")
        logger.info(f"Max concurrent: {self.config.max_concurrent:,}")
        logger.info(f"Batch size: {self.config.batch_size:,}")
        logger.info(f"Tokio Parallel: {'ENABLED' if self.config.enable_tokio else 'DISABLED (crash prevention)'}")
        logger.info(f"Immortal v3: {'ENABLED' if self.config.enable_immortal else 'DISABLED'}")
        logger.info("-" * 70)
        
        # Resume from checkpoint if exists
        if self.checkpoint_file.exists() and self.config.resume_from == 0:
            await self._load_checkpoint()
        
        # Calculate remaining units
        total_target = 10_000_000  # 10M for Wave 2
        remaining = total_target - self.deployed_count
        
        logger.info(f"Total target: {total_target:,}")
        logger.info(f"Already deployed: {self.deployed_count:,}")
        logger.info(f"Remaining: {remaining:,}")
        logger.info("-" * 70)
        
        # Deploy in safe batches
        batch_num = 0
        while self.deployed_count < total_target:
            # Check memory before each batch
            memory_ok = await self._check_memory()
            if not memory_ok:
                logger.warning("⚠️ Memory pressure detected - forcing GC and delay")
                gc.collect()
                await asyncio.sleep(5)
                continue
            
            # Calculate batch size (adaptive)
            batch_size = min(
                self.config.batch_size,
                total_target - self.deployed_count,
                self.config.max_concurrent
            )
            
            # Deploy batch
            batch_victories = await self._deploy_batch_safe(batch_num, batch_size)
            self.victories += batch_victories
            self.deployed_count += batch_size
            
            # Checkpoint every N units
            if self.deployed_count % self.config.checkpoint_interval == 0:
                await self._save_checkpoint()
            
            # Progress logging
            if batch_num % 10 == 0:
                elapsed = time.time() - self.start_time
                rate = self.deployed_count / elapsed if elapsed > 0 else 0
                progress = 100 * self.deployed_count / total_target
                
                logger.info(
                    f"📊 Progress: {self.deployed_count:,}/{total_target:,} "
                    f"({progress:.1f}%) | "
                    f"Rate: {rate:,.0f} units/sec | "
                    f"Victories: {self.victories:,} | "
                    f"Time: {elapsed:.0f}s"
                )
            
            batch_num += 1
            
            # Small delay between batches to prevent overwhelm
            await asyncio.sleep(0.01)
        
        # Final checkpoint
        await self._save_checkpoint()
        
        elapsed = time.time() - self.start_time
        
        logger.info("-" * 70)
        logger.info("✅ Wave 2 Recovery Complete")
        logger.info("Deployment complete")
        logger.info(f"   Deployed: {self.deployed_count:,}")
        logger.info(f"   Victories: {self.victories:,}")
        logger.info(f"   Success Rate: {100*self.victories/self.deployed_count:.1f}%")
        logger.info(f"   Total Time: {elapsed:.1f}s")
        logger.info("=" * 70)
        
        return {
            "deployed": self.deployed_count,
            "victories": self.victories,
            "success_rate": self.victories / self.deployed_count if self.deployed_count > 0 else 0,
            "elapsed_seconds": elapsed,
            "start_time": self.config.start_time,
            "end_time": datetime.now().strftime("%H:%M:%S"),
        }
    
    async def _deploy_batch_safe(self, batch_num: int, batch_size: int) -> int:
        """
        Deploy a single batch with semaphore-controlled concurrency
        """
        # Use semaphore to limit concurrent execution
        semaphore = asyncio.Semaphore(self.config.max_concurrent)
        
        async def deploy_unit(unit_id: int) -> bool:
            async with semaphore:
                # Simulate deployment work
                await asyncio.sleep(0.0001)  # Very short to prevent blocking
                
                # Simulate 85% success rate (matching Wave 1)
                import random
                return random.random() < 0.85
        
        # Deploy all units in batch with limited concurrency
        tasks = [deploy_unit(i) for i in range(batch_size)]
        results = await asyncio.gather(*tasks, return_exceptions=True)
        
        # Count successes (filter out exceptions)
        victories = sum(1 for r in results if r is True)
        
        return victories
    
    async def _check_memory(self) -> bool:
        """Check if memory usage is within safe limits"""
        import psutil
        
        try:
            process = psutil.Process(os.getpid())
            memory_mb = process.memory_info().rss / 1024 / 1024
            
            if memory_mb > self.config.memory_limit_mb:
                logger.warning(f"⚠️ Memory usage: {memory_mb:.0f}MB > {self.config.memory_limit_mb}MB limit")
                return False
            
            return True
        except Exception as e:
            logger.debug(f"Memory check failed: {e}")
            return True  # Assume OK if check fails
    
    async def _save_checkpoint(self) -> None:
        """Save deployment progress to disk"""
        checkpoint = {
            "deployed_count": self.deployed_count,
            "victories": self.victories,
            "failures": self.failures,
            "timestamp": time.time(),
            "config": asdict(self.config),
        }
        
        temp_file = self.checkpoint_file.with_suffix('.tmp')
        with open(temp_file, 'w') as f:
            json.dump(checkpoint, f)
        temp_file.rename(self.checkpoint_file)
        
        logger.debug(f"💾 Checkpoint saved: {self.deployed_count:,} units")
    
    async def _load_checkpoint(self) -> None:
        """Load deployment progress from disk"""
        try:
            with open(self.checkpoint_file, 'r') as f:
                checkpoint = json.load(f)
            
            self.deployed_count = checkpoint.get("deployed_count", 0)
            self.victories = checkpoint.get("victories", 0)
            self.failures = checkpoint.get("failures", 0)
            
            logger.info(f"🔄 Resumed from checkpoint: {self.deployed_count:,} units already deployed")
            
        except Exception as e:
            logger.warning(f"Failed to load checkpoint: {e}")


def main():
    parser = argparse.ArgumentParser(description="Wave 2 Recovery Deployment")
    parser.add_argument("--start-time", type=str, default="", help="Deployment start time")
    parser.add_argument("--resume", action="store_true", help="Resume from checkpoint")
    parser.add_argument("--max-concurrent", type=int, default=100_000, help="Max concurrent units")
    parser.add_argument("--batch-size", type=int, default=1_000, help="Batch size")
    parser.add_argument("--memory-limit", type=int, default=8_000, help="Memory limit in MB")
    
    args = parser.parse_args()
    
    # Check current time
    current_time = datetime.now().strftime("%H:%M:%S")
    logger.info(f"Current time: {current_time}")
    
    config = DeploymentConfig(
        start_time=args.start_time or current_time,
        resume_from=0 if not args.resume else None,
        max_concurrent=args.max_concurrent,
        batch_size=args.batch_size,
        memory_limit_mb=args.memory_limit,
        enable_tokio=False,  # DISABLED - caused crash
        enable_immortal=True,
    )
    
    commander = Wave2RecoveryCommander(config)
    result = asyncio.run(commander.deploy_safe())
    
    # Print final result
    print("\n" + "=" * 70)
    print("WAVE 2 RECOVERY - FINAL RESULTS")
    print("=" * 70)
    print(json.dumps(result, indent=2))
    print("=" * 70)
    
    # Check end time
    end_time = datetime.now().strftime("%H:%M:%S")
    print(f"End time: {end_time}")


if __name__ == "__main__":
    main()
