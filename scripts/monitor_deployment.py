#!/usr/bin/env python3
"""Real-Time Deployment Monitor with Progress Tracking
=====================================================
Provides granular progress bars, checkpoint logs, and metrics for shadow clone deployments.
"""

import json
import sys
import time
from collections import defaultdict
from datetime import datetime
from pathlib import Path
from typing import Any

try:
    from rich.console import Console
    from rich.progress import Progress, SpinnerColumn, BarColumn, TextColumn, TimeElapsedColumn
    from rich.live import Live
    from rich.table import Table
    from rich.panel import Panel
    from rich.layout import Layout
    RICH_AVAILABLE = True
except ImportError:
    RICH_AVAILABLE = False
    print("⚠️  Install 'rich' for enhanced progress tracking: pip install rich")


class DeploymentMonitor:
    """Real-time monitoring for shadow clone deployments"""
    
    def __init__(self, log_dir: Path):
        self.log_dir = log_dir
        self.log_dir.mkdir(parents=True, exist_ok=True)
        self.session_id = datetime.now().strftime("%Y%m%d_%H%M%S")
        self.checkpoint_log = log_dir / f"checkpoint_{self.session_id}.jsonl"
        self.metrics_log = log_dir / f"metrics_{self.session_id}.jsonl"
        self.console = Console() if RICH_AVAILABLE else None
        
        # Metrics
        self.start_time = time.time()
        self.campaign_stats = defaultdict(lambda: {
            "clones_deployed": 0,
            "findings": 0,
            "vcs_met": 0,
            "vcs_total": 0,
            "phase": "queued",
            "start_time": None,
            "end_time": None,
        })
        self.global_stats = {
            "total_clones": 0,
            "total_findings": 0,
            "total_vcs_met": 0,
            "total_vcs": 0,
            "campaigns_completed": 0,
            "campaigns_total": 0,
        }
    
    def log_checkpoint(self, event: str, data: dict[str, Any]):
        """Log a checkpoint event"""
        checkpoint = {
            "timestamp": datetime.now().isoformat(),
            "elapsed": time.time() - self.start_time,
            "event": event,
            "data": data,
        }
        with open(self.checkpoint_log, "a") as f:
            f.write(json.dumps(checkpoint) + "\n")
    
    def log_metric(self, metric_name: str, value: Any, campaign: str | None = None):
        """Log a metric"""
        metric = {
            "timestamp": datetime.now().isoformat(),
            "elapsed": time.time() - self.start_time,
            "metric": metric_name,
            "value": value,
            "campaign": campaign,
        }
        with open(self.metrics_log, "a") as f:
            f.write(json.dumps(metric) + "\n")
    
    def update_campaign(self, campaign_code: str, **kwargs):
        """Update campaign stats"""
        stats = self.campaign_stats[campaign_code]
        stats.update(kwargs)
        
        # Update global stats
        if "clones_deployed" in kwargs:
            self.global_stats["total_clones"] += kwargs["clones_deployed"]
        if "findings" in kwargs:
            self.global_stats["total_findings"] += kwargs["findings"]
        if kwargs.get("phase") == "completed":
            self.global_stats["campaigns_completed"] += 1
    
    def start_campaign(self, campaign_code: str, campaign_name: str, clone_count: int, vcs_total: int):
        """Mark campaign as started"""
        self.campaign_stats[campaign_code].update({
            "name": campaign_name,
            "phase": "recon",
            "start_time": time.time(),
            "vcs_total": vcs_total,
        })
        self.global_stats["campaigns_total"] += 1
        self.global_stats["total_vcs"] += vcs_total
        
        self.log_checkpoint("campaign_start", {
            "campaign": campaign_code,
            "name": campaign_name,
            "clones": clone_count,
            "vcs": vcs_total,
        })
    
    def complete_campaign(self, campaign_code: str, vcs_met: int, findings: int):
        """Mark campaign as completed"""
        stats = self.campaign_stats[campaign_code]
        stats.update({
            "phase": "completed",
            "end_time": time.time(),
            "vcs_met": vcs_met,
            "findings": findings,
        })
        self.global_stats["total_vcs_met"] += vcs_met
        
        duration = stats["end_time"] - stats["start_time"]
        self.log_checkpoint("campaign_complete", {
            "campaign": campaign_code,
            "duration": duration,
            "vcs_met": vcs_met,
            "vcs_total": stats["vcs_total"],
            "findings": findings,
        })
    
    def generate_progress_table(self) -> Table:
        """Generate rich table with campaign progress"""
        table = Table(title="Shadow Clone Deployment Progress")
        table.add_column("Campaign", style="cyan")
        table.add_column("Phase", style="yellow")
        table.add_column("Clones", justify="right", style="green")
        table.add_column("VCs", justify="right")
        table.add_column("Findings", justify="right", style="magenta")
        table.add_column("Duration", justify="right")
        
        for code, stats in sorted(self.campaign_stats.items()):
            if stats["phase"] == "queued":
                continue
            
            phase_emoji = {
                "recon": "🔍",
                "deploy": "⚔️",
                "scan": "📊",
                "verify": "✅",
                "completed": "🎯",
            }.get(stats["phase"], "❓")
            
            duration = ""
            if stats["start_time"]:
                elapsed = (stats["end_time"] or time.time()) - stats["start_time"]
                duration = f"{elapsed:.1f}s"
            
            vcs_str = f"{stats['vcs_met']}/{stats['vcs_total']}"
            if stats['vcs_total'] > 0:
                pct = int(stats['vcs_met'] / stats['vcs_total'] * 100)
                vcs_str += f" ({pct}%)"
            
            table.add_row(
                code,
                f"{phase_emoji} {stats['phase']}",
                f"{stats['clones_deployed']:,}",
                vcs_str,
                str(stats['findings']),
                duration,
            )
        
        return table
    
    def generate_summary_panel(self) -> Panel:
        """Generate summary panel"""
        elapsed = time.time() - self.start_time
        
        summary = f"""
[bold cyan]Total Clones Deployed:[/] {self.global_stats['total_clones']:,}
[bold green]Campaigns Completed:[/] {self.global_stats['campaigns_completed']}/{self.global_stats['campaigns_total']}
[bold yellow]Victory Conditions:[/] {self.global_stats['total_vcs_met']}/{self.global_stats['total_vcs']} ({int(self.global_stats['total_vcs_met']/self.global_stats['total_vcs']*100) if self.global_stats['total_vcs'] else 0}%)
[bold magenta]Total Findings:[/] {self.global_stats['total_findings']}
[bold white]Elapsed Time:[/] {elapsed:.1f}s
        """.strip()
        
        return Panel(summary, title="Deployment Summary", border_style="blue")
    
    def print_status(self):
        """Print current status"""
        if RICH_AVAILABLE and self.console:
            self.console.clear()
            self.console.print(self.generate_summary_panel())
            self.console.print()
            self.console.print(self.generate_progress_table())
        else:
            # Fallback to simple text output
            print("\n" + "="*70)
            print(f"DEPLOYMENT STATUS (Elapsed: {time.time() - self.start_time:.1f}s)")
            print("="*70)
            print(f"Campaigns: {self.global_stats['campaigns_completed']}/{self.global_stats['campaigns_total']}")
            print(f"Clones: {self.global_stats['total_clones']:,}")
            print(f"VCs: {self.global_stats['total_vcs_met']}/{self.global_stats['total_vcs']}")
            print(f"Findings: {self.global_stats['total_findings']}")
            print()
    
    def generate_final_report(self) -> str:
        """Generate final deployment report"""
        elapsed = time.time() - self.start_time
        
        report = f"""# Shadow Clone Deployment Report
**Session ID**: {self.session_id}
**Duration**: {elapsed:.1f}s ({elapsed/60:.1f} minutes)

## Summary

- **Total Clones Deployed**: {self.global_stats['total_clones']:,}
- **Campaigns Completed**: {self.global_stats['campaigns_completed']}/{self.global_stats['campaigns_total']}
- **Victory Conditions Met**: {self.global_stats['total_vcs_met']}/{self.global_stats['total_vcs']} ({int(self.global_stats['total_vcs_met']/self.global_stats['total_vcs']*100) if self.global_stats['total_vcs'] else 0}%)
- **Total Findings**: {self.global_stats['total_findings']}
- **Throughput**: {self.global_stats['total_clones']/elapsed:.0f} clones/sec

## Campaign Details

| Campaign | Clones | VCs Met | Findings | Duration |
|----------|--------|---------|----------|----------|
"""
        
        for code, stats in sorted(self.campaign_stats.items()):
            if stats["phase"] == "queued":
                continue
            
            duration = ""
            if stats["start_time"] and stats["end_time"]:
                duration = f"{stats['end_time'] - stats['start_time']:.1f}s"
            
            report += f"| {code} | {stats['clones_deployed']:,} | {stats['vcs_met']}/{stats['vcs_total']} | {stats['findings']} | {duration} |\n"
        
        report += f"""
## Checkpoint Log

See: `{self.checkpoint_log.name}`

## Metrics Log

See: `{self.metrics_log.name}`

## Next Steps

"""
        
        # Identify incomplete campaigns
        incomplete = [(code, stats) for code, stats in self.campaign_stats.items() 
                     if stats.get("vcs_met", 0) < stats.get("vcs_total", 1)]
        
        if incomplete:
            report += "### Incomplete Campaigns\n\n"
            for code, stats in incomplete[:10]:
                pct = int(stats.get("vcs_met", 0) / stats.get("vcs_total", 1) * 100)
                report += f"- **{code}**: {pct}% complete ({stats.get('vcs_met', 0)}/{stats.get('vcs_total', 0)} VCs)\n"
        
        return report


if __name__ == "__main__":
    # Test the monitor
    monitor = DeploymentMonitor(Path("reports"))
    
    monitor.start_campaign("TEST001", "Test Campaign", 10000, 5)
    monitor.update_campaign("TEST001", phase="deploy", clones_deployed=10000)
    time.sleep(1)
    monitor.update_campaign("TEST001", phase="scan", findings=3)
    time.sleep(1)
    monitor.complete_campaign("TEST001", vcs_met=3, findings=3)
    
    monitor.print_status()
    print("\n" + monitor.generate_final_report())
