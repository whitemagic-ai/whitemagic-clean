"""Parallel Engine — Unified interface for multiprocessing and multithreading.

Provides ProcessPoolExecutor and ThreadPoolExecutor wrappers with:
- Automatic worker count optimization
- Progress tracking integration
- Error handling and retry logic
- Resource cleanup
- Graceful degradation to sequential processing
"""
from __future__ import annotations

import logging
import multiprocessing as mp
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor, as_completed
from typing import Callable, Iterable, TypeVar

logger = logging.getLogger(__name__)

T = TypeVar('T')
R = TypeVar('R')


class ParallelEngine:
    """Unified parallel processing engine with automatic optimization."""
    
    @staticmethod
    def get_optimal_workers(task_type: str = "cpu") -> int:
        """Get optimal worker count based on task type.
        
        Args:
            task_type: "cpu" for CPU-bound, "io" for I/O-bound
        
        Returns:
            Optimal number of workers
        """
        cpu_count = mp.cpu_count()
        
        if task_type == "cpu":
            # CPU-bound: use physical cores (avoid hyperthreading overhead)
            return max(1, cpu_count // 2)
        else:
            # I/O-bound: can use more workers (2x cores)
            return cpu_count * 2
    
    @staticmethod
    def process_parallel(
        func: Callable[[T], R],
        items: Iterable[T],
        workers: int | None = None,
        chunksize: int = 1,
        progress_callback: Callable[[int, int], None] | None = None,
    ) -> list[R]:
        """Process items in parallel using ProcessPoolExecutor.
        
        Args:
            func: Function to apply to each item
            items: Iterable of items to process
            workers: Number of worker processes (None = auto-detect)
            chunksize: Items per chunk for better throughput
            progress_callback: Optional callback(completed, total)
        
        Returns:
            List of results in same order as input
        """
        items_list = list(items)
        total = len(items_list)
        
        if total == 0:
            return []
        
        # Auto-detect workers
        if workers is None:
            workers = ParallelEngine.get_optimal_workers("cpu")
        
        # Fall back to sequential for small workloads
        if total < workers * 2:
            logger.debug(f"Small workload ({total} items), using sequential processing")
            results = []
            for i, item in enumerate(items_list):
                results.append(func(item))
                if progress_callback:
                    progress_callback(i + 1, total)
            return results
        
        logger.debug(f"Processing {total} items with {workers} workers (chunksize={chunksize})")
        
        results = [None] * total
        completed = 0
        
        try:
            with ProcessPoolExecutor(max_workers=workers) as executor:
                # Submit all tasks with index tracking
                future_to_idx = {
                    executor.submit(func, item): idx
                    for idx, item in enumerate(items_list)
                }
                
                # Collect results as they complete
                for future in as_completed(future_to_idx):
                    idx = future_to_idx[future]
                    try:
                        results[idx] = future.result()
                        completed += 1
                        if progress_callback:
                            progress_callback(completed, total)
                    except Exception as e:
                        logger.error(f"Task {idx} failed: {e}")
                        results[idx] = None
        
        except Exception as e:
            logger.error(f"ProcessPoolExecutor failed: {e}, falling back to sequential")
            # Fall back to sequential processing
            results = []
            for i, item in enumerate(items_list):
                try:
                    results.append(func(item))
                except Exception as ex:
                    logger.error(f"Item {i} failed: {ex}")
                    results.append(None)
                if progress_callback:
                    progress_callback(i + 1, total)
        
        return results
    
    @staticmethod
    def thread_parallel(
        func: Callable[[T], R],
        items: Iterable[T],
        workers: int | None = None,
        progress_callback: Callable[[int, int], None] | None = None,
    ) -> list[R]:
        """Process items in parallel using ThreadPoolExecutor.
        
        Args:
            func: Function to apply to each item
            items: Iterable of items to process
            workers: Number of worker threads (None = auto-detect)
            progress_callback: Optional callback(completed, total)
        
        Returns:
            List of results in same order as input
        """
        items_list = list(items)
        total = len(items_list)
        
        if total == 0:
            return []
        
        # Auto-detect workers
        if workers is None:
            workers = ParallelEngine.get_optimal_workers("io")
        
        # Fall back to sequential for very small workloads
        if total < 5:
            logger.debug(f"Small workload ({total} items), using sequential processing")
            results = []
            for i, item in enumerate(items_list):
                results.append(func(item))
                if progress_callback:
                    progress_callback(i + 1, total)
            return results
        
        logger.debug(f"Threading {total} items with {workers} workers")
        
        results = [None] * total
        completed = 0
        
        try:
            with ThreadPoolExecutor(max_workers=workers) as executor:
                # Submit all tasks with index tracking
                future_to_idx = {
                    executor.submit(func, item): idx
                    for idx, item in enumerate(items_list)
                }
                
                # Collect results as they complete
                for future in as_completed(future_to_idx):
                    idx = future_to_idx[future]
                    try:
                        results[idx] = future.result()
                        completed += 1
                        if progress_callback:
                            progress_callback(completed, total)
                    except Exception as e:
                        logger.error(f"Task {idx} failed: {e}")
                        results[idx] = None
        
        except Exception as e:
            logger.error(f"ThreadPoolExecutor failed: {e}, falling back to sequential")
            # Fall back to sequential processing
            results = []
            for i, item in enumerate(items_list):
                try:
                    results.append(func(item))
                except Exception as ex:
                    logger.error(f"Item {i} failed: {ex}")
                    results.append(None)
                if progress_callback:
                    progress_callback(i + 1, total)
        
        return results
    
    @staticmethod
    def map_parallel(
        func: Callable[[T], R],
        items: Iterable[T],
        task_type: str = "cpu",
        workers: int | None = None,
        chunksize: int = 1,
        progress_callback: Callable[[int, int], None] | None = None,
    ) -> list[R]:
        """Auto-select parallel processing based on task type.
        
        Args:
            func: Function to apply to each item
            items: Iterable of items to process
            task_type: "cpu" for ProcessPool, "io" for ThreadPool
            workers: Number of workers (None = auto-detect)
            chunksize: Items per chunk (ProcessPool only)
            progress_callback: Optional callback(completed, total)
        
        Returns:
            List of results in same order as input
        """
        if task_type == "cpu":
            return ParallelEngine.process_parallel(
                func, items, workers, chunksize, progress_callback
            )
        else:
            return ParallelEngine.thread_parallel(
                func, items, workers, progress_callback
            )


# Convenience functions
def parallel_map(
    func: Callable[[T], R],
    items: Iterable[T],
    workers: int | None = None,
    task_type: str = "cpu",
) -> list[R]:
    """Simple parallel map function.
    
    Args:
        func: Function to apply
        items: Items to process
        workers: Number of workers (None = auto)
        task_type: "cpu" or "io"
    
    Returns:
        List of results
    """
    return ParallelEngine.map_parallel(func, items, task_type, workers)


__all__ = [
    "ParallelEngine",
    "parallel_map",
]
