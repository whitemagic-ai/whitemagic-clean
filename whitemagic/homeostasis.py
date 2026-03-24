"""Homeostasis module compatibility shim"""

import time
from typing import Dict, Any
from collections import deque

class HomeostaticMonitor:
    """Monitors and maintains system homeostasis"""
    
    def __init__(self) -> None:
        self.metrics = deque(maxlen=1000)
        self.thresholds = {
            'memory_usage': 0.8,
            'cpu_usage': 0.9,
            'response_time': 2.0
        }
        self.status = 'balanced'
    
    def monitor_initialization(self) -> bool:
        """Initialize monitoring"""
        self.metrics.clear()
        self.status = 'initializing'
        return True
    
    def check_status(self) -> Dict[str, Any]:
        """Check system status"""
        current_time = time.time()
        
        # Calculate recent metrics
        recent_metrics = [m for m in self.metrics 
                         if current_time - m.get('timestamp', 0) < 300]  # Last 5 min
        
        if not recent_metrics:
            return {
                'status': 'unknown',
                'metrics': {},
                'alerts': []
            }
        
        # Aggregate metrics
        avg_memory = sum(m.get('memory_usage', 0) for m in recent_metrics) / len(recent_metrics)
        avg_cpu = sum(m.get('cpu_usage', 0) for m in recent_metrics) / len(recent_metrics)
        avg_response = sum(m.get('response_time', 0) for m in recent_metrics) / len(recent_metrics)
        
        # Check thresholds
        alerts = []
        if avg_memory > self.thresholds['memory_usage']:
            alerts.append(f"High memory usage: {avg_memory:.2%}")
        if avg_cpu > self.thresholds['cpu_usage']:
            alerts.append(f"High CPU usage: {avg_cpu:.2%}")
        if avg_response > self.thresholds['response_time']:
            alerts.append(f"High response time: {avg_response:.2f}s")
        
        # Determine status
        if alerts:
            self.status = 'imbalanced'
        else:
            self.status = 'balanced'
        
        return {
            'status': self.status,
            'metrics': {
                'memory_usage': avg_memory,
                'cpu_usage': avg_cpu,
                'response_time': avg_response
            },
            'alerts': alerts
        }
    
    def record_metric(self, metric: str, value: float) -> None:
        """Record a system metric"""
        self.metrics.append({
            'metric': metric,
            'value': value,
            'timestamp': time.time()
        })
    
    def set_threshold(self, metric: str, threshold: float) -> None:
        """Set alert threshold for a metric"""
        self.thresholds[metric] = threshold
    
    def get_balance(self) -> float:
        """Get system balance score (0-1)"""
        status = self.check_status()
        
        # Calculate balance based on how far from thresholds
        balance = 1.0
        
        for metric, threshold in self.thresholds.items():
            value = status['metrics'].get(metric, 0)
            if metric == 'response_time':
                # Lower is better for response time
                if value > threshold:
                    balance -= min(0.5, (value - threshold) / threshold)
            else:
                # Lower is better for usage metrics
                if value > threshold:
                    balance -= min(0.5, (value - threshold) / (1.0 - threshold))
        
        return max(0.0, balance)


class Homeostasis(HomeostaticMonitor):
    pass

# Global instance
_homeostasis = HomeostaticMonitor()

def get_homeostasis() -> HomeostaticMonitor:
    """Get the global homeostasis monitor"""
    return _homeostasis

# Re-export
__all__ = ['HomeostaticMonitor', 'Homeostasis', 'get_homeostasis']
