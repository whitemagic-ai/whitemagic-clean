"""🚀 Memory Cache - LRU Cache for Frequently Accessed Memories

Implements an LRU (Least Recently Used) cache for the UnifiedMemory system
to reduce database query latency for hot memories.

Part of Phase 3 Recursive Evolution - First approved adaptation.
"""

import logging
from collections import OrderedDict
from datetime import datetime
from typing import Any, Dict, Optional

logger = logging.getLogger(__name__)


class MemoryCache:
    """LRU cache for memory objects with metrics tracking."""
    
    def __init__(self, max_size: int = 1000):
        """Initialize the cache.
        
        Args:
            max_size: Maximum number of entries to cache (default: 1000)
        """
        self.cache: OrderedDict[str, Dict[str, Any]] = OrderedDict()
        self.max_size = max_size
        self.hits = 0
        self.misses = 0
        self.evictions = 0
        self.invalidations = 0
        self.created_at = datetime.now()
        
        logger.info(f"💾 MemoryCache initialized (max_size={max_size})")
    
    def get(self, key: str) -> Optional[Dict[str, Any]]:
        """Get a value from the cache.
        
        Args:
            key: Memory ID to retrieve
            
        Returns:
            Cached memory dict or None if not found
        """
        if key in self.cache:
            self.hits += 1
            # Move to end (most recently used)
            self.cache.move_to_end(key)
            logger.debug(f"💨 Cache HIT: {key[:8]}... (hit_rate={self.hit_rate:.1%})")
            return self.cache[key]
        
        self.misses += 1
        logger.debug(f"❌ Cache MISS: {key[:8]}... (hit_rate={self.hit_rate:.1%})")
        return None
    
    def put(self, key: str, value: Dict[str, Any]) -> None:
        """Put a value into the cache.
        
        Args:
            key: Memory ID
            value: Memory dict to cache
        """
        if key in self.cache:
            # Update existing entry and move to end
            self.cache.move_to_end(key)
            self.cache[key] = value
        else:
            # Add new entry
            self.cache[key] = value
            
            # Evict oldest if over capacity
            if len(self.cache) > self.max_size:
                evicted_key, _ = self.cache.popitem(last=False)
                self.evictions += 1
                logger.debug(f"🗑️ Cache EVICT: {evicted_key[:8]}... (size={len(self.cache)})")
    
    def invalidate(self, key: str) -> None:
        """Invalidate a cache entry.
        
        Args:
            key: Memory ID to invalidate
        """
        if key in self.cache:
            del self.cache[key]
            self.invalidations += 1
            logger.debug(f"🔄 Cache INVALIDATE: {key[:8]}...")
    
    def clear(self) -> None:
        """Clear all cache entries."""
        count = len(self.cache)
        self.cache.clear()
        logger.info(f"🧹 Cache CLEARED: {count} entries removed")
    
    @property
    def hit_rate(self) -> float:
        """Calculate cache hit rate."""
        total = self.hits + self.misses
        return self.hits / total if total > 0 else 0.0
    
    @property
    def size(self) -> int:
        """Current cache size."""
        return len(self.cache)
    
    def stats(self) -> Dict[str, Any]:
        """Get cache statistics.
        
        Returns:
            Dict with cache metrics
        """
        total_requests = self.hits + self.misses
        uptime = (datetime.now() - self.created_at).total_seconds()
        
        return {
            'hits': self.hits,
            'misses': self.misses,
            'evictions': self.evictions,
            'invalidations': self.invalidations,
            'total_requests': total_requests,
            'hit_rate': self.hit_rate,
            'size': self.size,
            'max_size': self.max_size,
            'utilization': self.size / self.max_size if self.max_size > 0 else 0.0,
            'uptime_seconds': uptime,
            'requests_per_second': total_requests / uptime if uptime > 0 else 0.0
        }
    
    def get_summary(self) -> str:
        """Get a human-readable summary of cache stats."""
        stats = self.stats()
        return (
            f"MemoryCache Stats:\n"
            f"  Hit Rate: {stats['hit_rate']:.1%}\n"
            f"  Hits: {stats['hits']:,} | Misses: {stats['misses']:,}\n"
            f"  Size: {stats['size']:,}/{stats['max_size']:,} ({stats['utilization']:.1%})\n"
            f"  Evictions: {stats['evictions']:,} | Invalidations: {stats['invalidations']:,}\n"
            f"  Uptime: {stats['uptime_seconds']:.1f}s | RPS: {stats['requests_per_second']:.2f}"
        )


# Singleton instance getter
_cache_instance: Optional[MemoryCache] = None


def get_memory_cache(max_size: int = 1000) -> MemoryCache:
    """Get the singleton MemoryCache instance.
    
    Args:
        max_size: Maximum cache size (only used on first call)
        
    Returns:
        MemoryCache instance
    """
    global _cache_instance
    if _cache_instance is None:
        _cache_instance = MemoryCache(max_size=max_size)
    return _cache_instance


def reset_memory_cache() -> None:
    """Reset the singleton cache instance (mainly for testing)."""
    global _cache_instance
    if _cache_instance:
        _cache_instance.clear()
    _cache_instance = None
