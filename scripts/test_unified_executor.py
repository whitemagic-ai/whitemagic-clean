import asyncio
import sys
from datetime import datetime

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.autonomous.executor.continuous_executor import ContinuousExecutor, ExecutorConfig, Objective
from whitemagic.core.intelligence.nervous_system import get_nervous_system

async def main():
    print("🧠 Booting Unified Executor + Nervous System test...")
    config = ExecutorConfig(max_iterations=5, max_time_seconds=10)
    executor = ContinuousExecutor(config)
    
    # Add dummy objectives
    for i in range(3):
        executor.add_objective(Objective(description=f"Test objective {i}", priority=5))
        
    print("🚀 Running continuous loop...")
    # Need to override should_stop to eventually stop since we mocked the limit earlier in tests
    # We will just let it run its 5 iterations
    
    # Run
    await executor.run_continuous()
    
    print("\n📊 Results:")
    print(f"Completed: {len(executor.completed)}")
    print(f"Failed: {len(executor.failed)}")
    
    stats = executor.get_rust_stats()
    print(f"Rust Daemon Stats: {stats}")
    
    ns = get_nervous_system()
    print(f"Nervous System Active: {ns.is_active}")
    print(f"Nervous System Stats: {ns._stats}")

if __name__ == "__main__":
    asyncio.run(main())
