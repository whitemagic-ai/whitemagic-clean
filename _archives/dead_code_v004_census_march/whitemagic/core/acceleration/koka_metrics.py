"""Koka Metrics Exporter - Prometheus format.

Exports metrics from Koka binaries to Prometheus.
"""

import json
import time
from typing import Dict, Any


class KokaMetricsExporter:
    """Export Koka metrics in Prometheus format."""
    
    def __init__(self):
        self.metrics: Dict[str, Any] = {}
    
    def record_ipc_latency(self, binary: str, latency_ms: float):
        """Record IPC latency."""
        key = f"koka_ipc_latency_ms{{binary="{binary}"}}"
        self.metrics[key] = latency_ms
    
    def record_throughput(self, binary: str, ops_per_sec: float):
        """Record throughput."""
        key = f"koka_throughput_ops{{binary="{binary}"}}"
        self.metrics[key] = ops_per_sec
    
    def record_process_status(self, binary: str, status: str):
        """Record process status."""
        key = f"koka_process_running{{binary="{binary}"}}"
        self.metrics[key] = 1 if status == "running" else 0
    
    def export_prometheus(self) -> str:
        """Export in Prometheus format."""
        lines = []
        for key, value in self.metrics.items():
            lines.append(f"# HELP {key.split('{')[0]} Koka metric")
            lines.append(f"# TYPE {key.split('{')[0]} gauge")
            lines.append(f"{key} {value}")
        return "\n".join(lines)
