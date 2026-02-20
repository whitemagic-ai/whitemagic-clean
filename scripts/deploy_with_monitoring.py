#!/usr/bin/env python3
"""Robust Deployment Wrapper with Real-Time Monitoring
====================================================
Wraps deploy_grand_army.py with comprehensive monitoring, checkpointing, and recovery.
"""

import argparse
import json
import os
import signal
import subprocess
import sys
import threading
import time
from pathlib import Path
from typing import Any

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from scripts.monitor_deployment import DeploymentMonitor

# Global monitor instance for signal handling
monitor = None


def signal_handler(signum, frame):
    """Handle interrupts gracefully"""
    print("\n\n⚠️  Deployment interrupted by user")
    if monitor:
        print("\n📊 Generating partial report...")
        report = monitor.generate_final_report()
        report_path = monitor.log_dir / f"partial_report_{monitor.session_id}.md"
        report_path.write_text(report)
        print(f"✅ Partial report saved: {report_path}")
    sys.exit(130)


def parse_deployment_output(line: str, monitor: DeploymentMonitor) -> dict[str, Any] | None:
    """Parse deployment output and extract metrics"""
    line = line.strip()
    
    # Campaign start: [Col-1] -> C001: Campaign Name
    if " -> " in line and ":" in line:
        parts = line.split(" -> ", 1)
        if len(parts) == 2:
            campaign_info = parts[1].split(":", 1)
            if len(campaign_info) == 2:
                code = campaign_info[0].strip()
                name = campaign_info[1].strip()
                return {"event": "campaign_start", "code": code, "name": name}
    
    # Phase indicators
    if "[1/4] Recon:" in line:
        return {"event": "phase", "phase": "recon"}
    elif "[2/4] Deploy:" in line:
        # Extract clone count
        if "clones" in line:
            try:
                count_str = line.split("Deploy:")[1].split("clones")[0].strip()
                count = int(count_str.replace(",", ""))
                return {"event": "phase", "phase": "deploy", "clones": count}
            except (ValueError, IndexError):
                pass
        return {"event": "phase", "phase": "deploy"}
    elif "[3/4] Scan:" in line:
        return {"event": "phase", "phase": "scan"}
    elif "[4/4] Victory check" in line:
        return {"event": "phase", "phase": "verify"}
    
    # Findings
    if "Findings:" in line:
        try:
            findings = int(line.split("Findings:")[1].strip())
            return {"event": "findings", "count": findings}
        except (ValueError, IndexError):
            pass
    
    # Victory conditions
    if "Victory:" in line and "conditions met" in line:
        try:
            # Parse "⚠️ Victory: 3/11 conditions met"
            vc_part = line.split("Victory:")[1].split("conditions")[0].strip()
            met, total = map(int, vc_part.split("/"))
            return {"event": "victory", "met": met, "total": total}
        except (ValueError, IndexError):
            pass
    
    # Targets found
    if "Targets found:" in line:
        try:
            targets = int(line.split("Targets found:")[1].split(",")[0].strip())
            return {"event": "targets", "count": targets}
        except (ValueError, IndexError):
            pass
    
    # DB stats
    if "DB:" in line and "mem" in line:
        try:
            db_part = line.split("DB:")[1].strip()
            mem_count = int(db_part.split("mem")[0].strip().replace(",", ""))
            return {"event": "db_stats", "memories": mem_count}
        except (ValueError, IndexError):
            pass
    
    return None


def run_deployment_with_monitoring(
    args: argparse.Namespace,
    monitor: DeploymentMonitor,
) -> int:
    """Run deployment with real-time monitoring"""
    
    # If filtering campaigns, create a temporary filtered campaign list
    if args.filter_codes and args.campaigns:
        from whitemagic.agents.campaign_loader import load_all_campaigns
        campaigns_dir = PROJECT_ROOT / "campaigns"
        all_campaigns = load_all_campaigns(campaigns_dir)
        
        filter_codes = [c.strip() for c in args.filter_codes.split(",")]
        filtered = [c for c in all_campaigns if c.codename in filter_codes]
        
        print(f"📋 Filtering campaigns: {len(filtered)}/{len(all_campaigns)} selected")
        for c in filtered:
            print(f"   - {c.codename}: {c.name} ({c.clone_count:,} clones, {len(c.victory_conditions)} VCs)")
        print()
        
        # Pre-register campaigns in monitor
        for c in filtered:
            monitor.start_campaign(c.codename, c.name, c.clone_count, len(c.victory_conditions))
    
    # Build command
    cmd = [sys.executable, str(PROJECT_ROOT / "scripts" / "deploy_grand_army.py")]
    
    if args.campaigns:
        cmd.append("--campaigns")
    if args.time_limit:
        cmd.extend(["--time-limit", str(args.time_limit)])
    if args.yin_yang:
        cmd.append("--yin-yang")
    if args.filter_codes:
        cmd.extend(["--filter", args.filter_codes])
    
    # Convert Path objects to strings for JSON serialization
    args_dict = {k: str(v) if isinstance(v, Path) else v for k, v in vars(args).items()}
    
    monitor.log_checkpoint("deployment_start", {
        "command": " ".join(cmd),
        "args": args_dict,
    })
    
    # Run deployment with real-time output capture
    print(f"🚀 Starting deployment: {' '.join(cmd[2:])}\n")
    
    current_campaign = None
    current_phase = None
    
    try:
        process = subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            bufsize=1,
            universal_newlines=True,
        )
        
        # Monitor output in real-time
        for line in process.stdout:
            # Print line immediately
            print(line, end="", flush=True)
            
            # Parse and update monitor
            event = parse_deployment_output(line, monitor)
            if event:
                event_type = event.get("event")
                
                if event_type == "campaign_start":
                    current_campaign = event["code"]
                    # We'll get clone count and VCs from subsequent lines
                    
                elif event_type == "phase":
                    current_phase = event["phase"]
                    if current_campaign:
                        monitor.update_campaign(current_campaign, phase=current_phase)
                        if "clones" in event:
                            monitor.update_campaign(
                                current_campaign,
                                clones_deployed=event["clones"]
                            )
                
                elif event_type == "findings" and current_campaign:
                    monitor.update_campaign(current_campaign, findings=event["count"])
                
                elif event_type == "victory" and current_campaign:
                    monitor.complete_campaign(
                        current_campaign,
                        vcs_met=event["met"],
                        findings=monitor.campaign_stats[current_campaign].get("findings", 0)
                    )
                    monitor.campaign_stats[current_campaign]["vcs_total"] = event["total"]
                
                # Log all events
                monitor.log_metric(event_type, event, campaign=current_campaign)
        
        return_code = process.wait()
        
        monitor.log_checkpoint("deployment_complete", {
            "return_code": return_code,
            "duration": time.time() - monitor.start_time,
        })
        
        return return_code
        
    except KeyboardInterrupt:
        print("\n⚠️  Interrupted by user")
        process.terminate()
        process.wait(timeout=5)
        return 130
    except Exception as e:
        monitor.log_checkpoint("deployment_error", {
            "error": str(e),
            "type": type(e).__name__,
        })
        raise


def main():
    parser = argparse.ArgumentParser(
        description="Deploy shadow clone armies with real-time monitoring"
    )
    
    # Deployment options (matching deploy_grand_army.py)
    parser.add_argument("--campaigns", action="store_true",
                       help="Run campaign-driven deployment")
    parser.add_argument("--time-limit", type=int, default=300,
                       help="Time limit in seconds (default: 300)")
    parser.add_argument("--yin-yang", action="store_true",
                       help="Enable Yin-Yang autonomous cycle")
    parser.add_argument("--filter-codes", type=str,
                       help="Comma-separated list of campaign codes to run (e.g., S001,S002,S003,S004)")
    
    # Monitoring options
    parser.add_argument("--log-dir", type=Path, default=PROJECT_ROOT / "reports",
                       help="Directory for logs and reports")
    parser.add_argument("--no-monitor", action="store_true",
                       help="Disable real-time monitoring")
    
    args = parser.parse_args()
    
    # Setup monitoring
    global monitor
    monitor = DeploymentMonitor(args.log_dir)
    
    # Setup signal handlers
    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGTERM, signal_handler)
    
    # Run deployment
    try:
        return_code = run_deployment_with_monitoring(args, monitor)
        
        # Generate final report
        print("\n" + "="*70)
        print("📊 GENERATING FINAL REPORT")
        print("="*70 + "\n")
        
        monitor.print_status()
        
        report = monitor.generate_final_report()
        report_path = monitor.log_dir / f"deployment_report_{monitor.session_id}.md"
        report_path.write_text(report)
        
        print(f"\n✅ Final report saved: {report_path}")
        print(f"📋 Checkpoint log: {monitor.checkpoint_log}")
        print(f"📈 Metrics log: {monitor.metrics_log}")
        
        return return_code
        
    except Exception as e:
        print(f"\n❌ Deployment failed: {e}", file=sys.stderr)
        if monitor:
            report = monitor.generate_final_report()
            report_path = monitor.log_dir / f"error_report_{monitor.session_id}.md"
            report_path.write_text(report + f"\n\n## Error\n\n```\n{e}\n```")
            print(f"📋 Error report saved: {report_path}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
