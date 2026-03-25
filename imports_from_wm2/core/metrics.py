"""
WM2 - Metric Collection System
================================
Unified metrics collection for all WM2 components
Replaces 63 individual get_stats implementations
"""

import time
from typing import Any, Dict, Callable, Optional
from functools import wraps
from datetime import datetime, timezone
from collections import defaultdict


class MetricCollector:
    """
    Unified metric collection mixin with decorator support.
    
    Automatically tracks:
    - Method call counts
    - Execution times
    - Success/failure rates
    - Custom metrics
    """
    
    def __init__(self):
        self._metrics: Dict[str, Any] = defaultdict(lambda: {
            'count': 0,
            'total_time': 0.0,
            'errors': 0,
            'last_called': None,
        })
        self._custom_metrics: Dict[str, Any] = {}
        self._created_at = datetime.now(timezone.utc)
    
    def get_stats(self) -> Dict[str, Any]:
        """Get comprehensive statistics for this component."""
        uptime = (datetime.now(timezone.utc) - self._created_at).total_seconds()
        
        stats = {
            'component': self.__class__.__name__,
            'uptime_seconds': round(uptime, 2),
            'created_at': self._created_at.isoformat(),
            'methods': {},
            'custom': self._custom_metrics.copy(),
        }
        
        # Aggregate method metrics
        for method_name, metrics in self._metrics.items():
            if metrics['count'] > 0:
                avg_time = metrics['total_time'] / metrics['count']
                success_rate = (metrics['count'] - metrics['errors']) / metrics['count']
                
                stats['methods'][method_name] = {
                    'calls': metrics['count'],
                    'avg_time_ms': round(avg_time * 1000, 2),
                    'total_time_s': round(metrics['total_time'], 2),
                    'errors': metrics['errors'],
                    'success_rate': round(success_rate, 3),
                    'last_called': metrics['last_called'],
                }
        
        # Add summary
        total_calls = sum(m['count'] for m in self._metrics.values())
        total_errors = sum(m['errors'] for m in self._metrics.values())
        
        stats['summary'] = {
            'total_calls': total_calls,
            'total_errors': total_errors,
            'error_rate': round(total_errors / total_calls, 3) if total_calls > 0 else 0.0,
            'methods_tracked': len([m for m in self._metrics.values() if m['count'] > 0]),
        }
        
        return stats
    
    def record_metric(self, name: str, value: Any):
        """Record a custom metric."""
        self._custom_metrics[name] = value
    
    def increment_metric(self, name: str, amount: int = 1):
        """Increment a custom counter metric."""
        if name not in self._custom_metrics:
            self._custom_metrics[name] = 0
        self._custom_metrics[name] += amount
    
    def _record_call(self, method_name: str, duration: float, error: bool = False):
        """Internal: Record a method call."""
        metrics = self._metrics[method_name]
        metrics['count'] += 1
        metrics['total_time'] += duration
        metrics['last_called'] = datetime.now(timezone.utc).isoformat()
        
        if error:
            metrics['errors'] += 1


def tracked(func: Callable) -> Callable:
    """
    Decorator to automatically track method metrics.
    
    Usage:
        @tracked
        def my_method(self):
            ...
    """
    @wraps(func)
    def wrapper(self, *args, **kwargs):
        if not isinstance(self, MetricCollector):
            # If not a MetricCollector, just call the function
            return func(self, *args, **kwargs)
        
        start_time = time.time()
        error = False
        
        try:
            result = func(self, *args, **kwargs)
            return result
        except Exception as e:
            error = True
            raise
        finally:
            duration = time.time() - start_time
            self._record_call(func.__name__, duration, error)
    
    return wrapper


class PerformanceMonitor(MetricCollector):
    """
    Extended metric collector with performance thresholds.
    
    Automatically warns when methods exceed time thresholds.
    """
    
    def __init__(self, slow_threshold_ms: float = 100.0):
        super().__init__()
        self.slow_threshold_ms = slow_threshold_ms
        self._slow_calls: list = []
    
    def _record_call(self, method_name: str, duration: float, error: bool = False):
        """Record call and check for slow performance."""
        super()._record_call(method_name, duration, error)
        
        duration_ms = duration * 1000
        if duration_ms > self.slow_threshold_ms:
            self._slow_calls.append({
                'method': method_name,
                'duration_ms': round(duration_ms, 2),
                'timestamp': datetime.now(timezone.utc).isoformat(),
            })
            
            # Keep only last 100 slow calls
            if len(self._slow_calls) > 100:
                self._slow_calls = self._slow_calls[-100:]
    
    def get_stats(self) -> Dict[str, Any]:
        """Get stats including slow call warnings."""
        stats = super().get_stats()
        
        stats['performance'] = {
            'slow_threshold_ms': self.slow_threshold_ms,
            'slow_calls_count': len(self._slow_calls),
            'recent_slow_calls': self._slow_calls[-10:],  # Last 10
        }
        
        return stats
