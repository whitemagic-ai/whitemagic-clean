#!/usr/bin/env python3
"""
Progress Tracking with Memory Monitoring - Priority 1 Mutation (arch_002)

Prevents crashes with early warning system.
"""

import time
from dataclasses import dataclass

import psutil
from rich.console import Console
from rich.progress import (
    BarColumn,
    Progress,
    SpinnerColumn,
    TextColumn,
    TimeRemainingColumn,
)
from rich.table import Table


@dataclass
class ProgressMetrics:
    generation: int
    best_fitness: float
    avg_fitness: float
    diversity: float
    memory_mb: float
    throughput: float
    timestamp: float

class ProgressTracker:
    """Track evolution progress with memory monitoring"""

    def __init__(self, total_generations: int):
        self.metrics: list[ProgressMetrics] = []
        self.process = psutil.Process()
        self.total_generations = total_generations
        self.start_time = time.time()
        self.console = Console()

        # Memory thresholds
        self.memory_warning_threshold = 0.80  # 80% of available
        self.memory_critical_threshold = 0.90  # 90% of available

    def update(self, gen: int, best_fitness: float, avg_fitness: float,
               diversity: float, throughput: float):
        """Update progress with current metrics"""
        memory_mb = self.process.memory_info().rss / 1024 / 1024

        metric = ProgressMetrics(
            generation=gen,
            best_fitness=best_fitness,
            avg_fitness=avg_fitness,
            diversity=diversity,
            memory_mb=memory_mb,
            throughput=throughput,
            timestamp=time.time()
        )

        self.metrics.append(metric)

        # Check memory
        self._check_memory(memory_mb)

        # Display progress
        if gen % 10 == 0:
            self._display_progress(metric)

    def _check_memory(self, memory_mb: float):
        """Check memory usage and warn if high"""
        available_mb = psutil.virtual_memory().available / 1024 / 1024
        usage_ratio = memory_mb / (memory_mb + available_mb)

        if usage_ratio > self.memory_critical_threshold:
            self.console.print(f"[bold red]🚨 CRITICAL: Memory usage {memory_mb:.0f} MB ({usage_ratio:.0%})[/bold red]")
            self.console.print("[yellow]Consider reducing population size or using streaming evolution[/yellow]")
        elif usage_ratio > self.memory_warning_threshold:
            self.console.print(f"[yellow]⚠️  WARNING: High memory usage {memory_mb:.0f} MB ({usage_ratio:.0%})[/yellow]")

    def _display_progress(self, metric: ProgressMetrics):
        """Display formatted progress update"""
        elapsed = time.time() - self.start_time
        progress_pct = (metric.generation / self.total_generations) * 100

        table = Table(show_header=False, box=None)
        table.add_row("Generation", f"{metric.generation}/{self.total_generations} ({progress_pct:.1f}%)")
        table.add_row("Best Fitness", f"{metric.best_fitness:.4f}")
        table.add_row("Avg Fitness", f"{metric.avg_fitness:.4f}")
        table.add_row("Diversity", f"{metric.diversity:.2%}")
        table.add_row("Memory", f"{metric.memory_mb:.0f} MB")
        table.add_row("Throughput", f"{metric.throughput:,.0f} lineages/sec")
        table.add_row("Elapsed", f"{elapsed:.1f}s")

        self.console.print(table)
        self.console.print()

    def get_summary(self) -> dict:
        """Get summary statistics"""
        if not self.metrics:
            return {}

        return {
            "total_generations": len(self.metrics),
            "final_best_fitness": self.metrics[-1].best_fitness,
            "fitness_improvement": self.metrics[-1].best_fitness - self.metrics[0].best_fitness,
            "final_diversity": self.metrics[-1].diversity,
            "peak_memory_mb": max(m.memory_mb for m in self.metrics),
            "avg_throughput": sum(m.throughput for m in self.metrics) / len(self.metrics),
            "total_duration": self.metrics[-1].timestamp - self.metrics[0].timestamp,
        }

    def save_metrics(self, filename: str = "evolution_metrics.json"):
        """Save all metrics to file"""
        import json

        data = {
            "metrics": [
                {
                    "generation": m.generation,
                    "best_fitness": m.best_fitness,
                    "avg_fitness": m.avg_fitness,
                    "diversity": m.diversity,
                    "memory_mb": m.memory_mb,
                    "throughput": m.throughput,
                    "timestamp": m.timestamp,
                }
                for m in self.metrics
            ],
            "summary": self.get_summary(),
        }

        with open(filename, "w") as f:
            json.dump(data, f, indent=2)

        self.console.print(f"[green]💾 Metrics saved to {filename}[/green]")


class RichProgressBar:
    """Rich progress bar for evolution"""

    def __init__(self, total_generations: int):
        self.total_generations = total_generations
        self.progress = Progress(
            SpinnerColumn(),
            TextColumn("[progress.description]{task.description}"),
            BarColumn(),
            TextColumn("[progress.percentage]{task.percentage:>3.0f}%"),
            TimeRemainingColumn(),
        )
        self.task = None

    def __enter__(self):
        self.progress.__enter__()
        self.task = self.progress.add_task(
            "[cyan]Evolving...",
            total=self.total_generations
        )
        return self

    def __exit__(self, *args):
        self.progress.__exit__(*args)

    def update(self, advance: int = 1):
        """Update progress bar"""
        if self.task is not None:
            self.progress.update(self.task, advance=advance)
