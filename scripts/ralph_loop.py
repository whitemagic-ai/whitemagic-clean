#!/usr/bin/env python3
"""Ralph Loop Runner — Persistent retry with external deterministic verification.

Based on Geoff Huntley's Ralph Wiggum pattern:
  while :; do cat PROMPT.md | agent ; done

Key principles:
  1. Fresh context per iteration — no chat history pollution
  2. External deterministic verification — exit code 0 = pass
  3. Persistent retry until victory or timeout
  4. State lives in files, not in conversation
  5. Failures are data — deterministically bad is predictable

Usage:
  scripts/wm scripts/ralph_loop.py --list
  scripts/wm scripts/ralph_loop.py --verify-only --campaign IL001
  scripts/wm scripts/ralph_loop.py --campaign IL001 --max-iterations 10 --timeout 300
  scripts/wm scripts/ralph_loop.py --all --timeout 600
"""

from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import threading
import time
from dataclasses import dataclass, field
from datetime import datetime
from pathlib import Path

# Project setup
PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

CAMPAIGNS_DIR = PROJECT_ROOT / "campaigns"
REPORTS_DIR = PROJECT_ROOT / "reports"
REPORTS_DIR.mkdir(exist_ok=True)
DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
LOG_DIR = Path.home() / ".whitemagic" / "logs" / "ralph"
LOG_DIR.mkdir(parents=True, exist_ok=True)

PROMISE_PATTERN = re.compile(r"<promise>(.*?)</promise>", re.DOTALL)


@dataclass
class VerificationResult:
    """Result of running a verification command."""
    command: str
    exit_code: int
    stdout: str
    stderr: str
    elapsed_s: float
    passed: bool


@dataclass
class RalphIteration:
    """Single iteration of a Ralph loop."""
    iteration: int
    timestamp: str
    verifications: list[VerificationResult] = field(default_factory=list)
    promises_found: list[str] = field(default_factory=list)
    all_passed: bool = False
    elapsed_s: float = 0.0


@dataclass
class RalphCampaignResult:
    """Result of running Ralph loop on a campaign."""
    codename: str
    name: str
    iterations: list[RalphIteration] = field(default_factory=list)
    victory: bool = False
    total_elapsed_s: float = 0.0
    verification_commands: list[str] = field(default_factory=list)


def extract_verification_commands(campaign_path: Path) -> list[str]:
    """Extract runnable verification commands from a campaign .md file.

    Looks for a ## Verification section with ```bash code blocks.
    Strips comments and empty lines. Returns list of executable commands.
    """
    content = campaign_path.read_text(errors="replace")

    # Find ## Verification section
    verify_match = re.search(
        r"##\s+Verification\s*\n(.*?)(?=\n##|\Z)",
        content,
        re.DOTALL | re.IGNORECASE,
    )
    if not verify_match:
        return []

    verify_section = verify_match.group(1)

    # Extract bash code blocks
    commands = []
    for block in re.finditer(r"```(?:bash|sh)?\s*\n(.*?)```", verify_section, re.DOTALL):
        block_text = block.group(1)
        for line in block_text.strip().split("\n"):
            line = line.strip()
            if line and not line.startswith("#"):
                commands.append(line)

    return commands


def run_verification(command: str, timeout: float = 30.0) -> VerificationResult:
    """Run a single verification command and return the result."""
    start = time.monotonic()
    try:
        result = subprocess.run(
            command,
            shell=True,
            capture_output=True,
            text=True,
            timeout=timeout,
            cwd=str(PROJECT_ROOT),
            env={**os.environ, "PYTHONPATH": str(PROJECT_ROOT)},
        )
        elapsed = time.monotonic() - start
        return VerificationResult(
            command=command,
            exit_code=result.returncode,
            stdout=result.stdout[:2000],
            stderr=result.stderr[:2000],
            elapsed_s=round(elapsed, 3),
            passed=result.returncode == 0,
        )
    except subprocess.TimeoutExpired:
        elapsed = time.monotonic() - start
        return VerificationResult(
            command=command,
            exit_code=-1,
            stdout="",
            stderr="TIMEOUT",
            elapsed_s=round(elapsed, 3),
            passed=False,
        )
    except Exception as e:
        elapsed = time.monotonic() - start
        return VerificationResult(
            command=command,
            exit_code=-2,
            stdout="",
            stderr=str(e),
            elapsed_s=round(elapsed, 3),
            passed=False,
        )


def run_ralph_loop(
    campaign_path: Path,
    max_iterations: int = 10,
    timeout: float = 300.0,
    verify_only: bool = False,
    verbose: bool = True,
) -> RalphCampaignResult:
    """Run Ralph loop on a single campaign.

    Each iteration:
    1. Extract verification commands from campaign .md
    2. Run all verification commands
    3. If all pass (exit code 0) → victory
    4. If not → log failures, retry with fresh context
    5. Repeat until max_iterations or timeout
    """
    # Parse campaign metadata
    content = campaign_path.read_text(errors="replace")
    name_match = re.search(r"name:\s*[\"']?(.+?)[\"']?\s*$", content, re.MULTILINE)
    code_match = re.search(r"codename:\s*(\S+)", content, re.MULTILINE)
    name = name_match.group(1) if name_match else campaign_path.stem
    codename = code_match.group(1) if code_match else campaign_path.stem

    commands = extract_verification_commands(campaign_path)
    result = RalphCampaignResult(
        codename=codename,
        name=name,
        verification_commands=commands,
    )

    if not commands:
        if verbose:
            print(f"  [{codename}] No verification commands found — skipping")
        return result

    if verbose:
        print(f"\n  {'='*60}")
        print(f"  RALPH LOOP: {codename} — {name}")
        print(f"  Verification commands: {len(commands)}")
        print(f"  Max iterations: {max_iterations}")
        print(f"  Timeout: {timeout:.0f}s")
        if verify_only:
            print("  MODE: verify-only (no action phase)")
        print(f"  {'='*60}")

    loop_start = time.monotonic()

    for iteration_num in range(1, max_iterations + 1):
        elapsed_total = time.monotonic() - loop_start
        if elapsed_total >= timeout:
            if verbose:
                print(f"\n  ⏰ Timeout after {elapsed_total:.1f}s")
            break

        iter_start = time.monotonic()
        ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        iteration = RalphIteration(iteration=iteration_num, timestamp=ts)

        if verbose:
            print(f"\n  --- Iteration {iteration_num}/{max_iterations} [{ts}] ---")

        # Run all verification commands
        all_passed = True
        for cmd in commands:
            vr = run_verification(cmd, timeout=min(30.0, timeout - elapsed_total))
            iteration.verifications.append(vr)

            icon = "✅" if vr.passed else "❌"
            if verbose:
                print(f"    {icon} [{vr.exit_code}] {cmd[:70]}")
                if not vr.passed and vr.stderr:
                    for line in vr.stderr.strip().split("\n")[:3]:
                        print(f"       {line[:80]}")

            if not vr.passed:
                all_passed = False

        # Check for promise tokens in stdout
        for vr in iteration.verifications:
            for promise in PROMISE_PATTERN.findall(vr.stdout):
                iteration.promises_found.append(promise.strip())
                if verbose:
                    print(f"    🏷️  Promise: {promise.strip()}")

        iteration.all_passed = all_passed
        iteration.elapsed_s = round(time.monotonic() - iter_start, 3)
        result.iterations.append(iteration)

        if all_passed:
            result.victory = True
            if verbose:
                print(f"\n  🏆 VICTORY after {iteration_num} iterations!")
            break

        if verify_only:
            # In verify-only mode, don't retry
            break

        # In full mode, we would trigger an action phase here
        # For now, just retry (the yin-yang cycle handles actions)
        if verbose:
            passed = sum(1 for v in iteration.verifications if v.passed)
            total = len(iteration.verifications)
            print(f"    Progress: {passed}/{total} checks passed — retrying...")

    result.total_elapsed_s = round(time.monotonic() - loop_start, 3)

    # Log to JSONL
    log_path = LOG_DIR / f"{datetime.now().strftime('%Y%m%d_%H%M%S')}_{codename}.jsonl"
    with open(log_path, "w") as f:
        for iteration in result.iterations:
            entry = {
                "ts": iteration.timestamp,
                "iteration": iteration.iteration,
                "all_passed": iteration.all_passed,
                "elapsed_s": iteration.elapsed_s,
                "checks": [
                    {"cmd": v.command[:100], "exit": v.exit_code, "passed": v.passed}
                    for v in iteration.verifications
                ],
                "promises": iteration.promises_found,
            }
            f.write(json.dumps(entry) + "\n")

    if verbose:
        print(f"\n  Log: {log_path}")

    return result


def run_worktree_parallel(
    campaign_files: list[Path],
    num_worktrees: int,
    max_iterations: int = 10,
    timeout: float = 300.0,
    verify_only: bool = False,
    verbose: bool = True,
) -> list[RalphCampaignResult]:
    """Run N Ralph loops in parallel using git worktrees.

    Each worktree gets its own branch and runs independently.
    Winners are reported; merging is left to the operator.

    Git worktree strategy (Sun Bin parallel):
    1. Create N temporary worktrees from current HEAD
    2. Each worktree runs Ralph loop on its assigned campaign
    3. Results collected, worktrees cleaned up
    """
    import shutil
    from concurrent.futures import ThreadPoolExecutor, as_completed

    git_root = PROJECT_ROOT
    worktree_base = Path("/tmp/ralph_worktrees")
    worktree_base.mkdir(parents=True, exist_ok=True)

    # Distribute campaigns across worktrees round-robin
    worktree_assignments: list[list[Path]] = [[] for _ in range(num_worktrees)]
    for i, cf in enumerate(campaign_files):
        worktree_assignments[i % num_worktrees].append(cf)

    all_results: list[RalphCampaignResult] = []
    results_lock = threading.Lock()
    created_worktrees: list[Path] = []

    def worker(wt_id: int, assigned: list[Path]) -> list[RalphCampaignResult]:
        wt_path = worktree_base / f"ralph_wt_{wt_id}"
        branch_name = f"ralph-wt-{wt_id}-{int(time.time())}"
        worker_results: list[RalphCampaignResult] = []

        try:
            # Create worktree with a new branch
            subprocess.run(
                ["git", "worktree", "add", "-b", branch_name, str(wt_path), "HEAD"],
                cwd=str(git_root),
                capture_output=True,
                timeout=30,
            )
            created_worktrees.append(wt_path)

            if verbose:
                print(f"  [WT-{wt_id}] Created worktree at {wt_path} (branch: {branch_name})")

            for cf in assigned:
                # Run ralph loop using the worktree's campaign file
                wt_campaign = wt_path / "campaigns" / cf.name
                if not wt_campaign.exists():
                    wt_campaign = cf  # fallback to original

                result = run_ralph_loop(
                    wt_campaign,
                    max_iterations=max_iterations,
                    timeout=timeout,
                    verify_only=verify_only,
                    verbose=verbose,
                )
                worker_results.append(result)

                if verbose:
                    icon = "✅" if result.victory else "❌"
                    print(f"  [WT-{wt_id}] {icon} {result.codename}: "
                          f"{len(result.iterations)} iterations, {result.total_elapsed_s:.1f}s")

        except Exception as e:
            if verbose:
                print(f"  [WT-{wt_id}] Error: {e}")
        finally:
            # Cleanup worktree
            try:
                subprocess.run(
                    ["git", "worktree", "remove", "--force", str(wt_path)],
                    cwd=str(git_root),
                    capture_output=True,
                    timeout=30,
                )
                subprocess.run(
                    ["git", "branch", "-D", branch_name],
                    cwd=str(git_root),
                    capture_output=True,
                    timeout=10,
                )
            except Exception:
                pass

        return worker_results

    if verbose:
        print(f"\n  GIT WORKTREE PARALLEL MODE")
        print(f"  Worktrees: {num_worktrees}")
        print(f"  Campaigns: {len(campaign_files)}")
        print(f"  Base: {worktree_base}")

    with ThreadPoolExecutor(max_workers=num_worktrees) as pool:
        futures = {
            pool.submit(worker, i, worktree_assignments[i]): i
            for i in range(num_worktrees)
            if worktree_assignments[i]
        }
        for future in as_completed(futures):
            wt_id = futures[future]
            try:
                results = future.result()
                with results_lock:
                    all_results.extend(results)
            except Exception as e:
                if verbose:
                    print(f"  [WT-{wt_id}] Worker failed: {e}")

    # Cleanup any remaining worktrees
    for wt_path in created_worktrees:
        if wt_path.exists():
            try:
                shutil.rmtree(wt_path, ignore_errors=True)
            except Exception:
                pass

    if verbose:
        victories = sum(1 for r in all_results if r.victory)
        print(f"\n  Worktree parallel complete: {victories}/{len(all_results)} victories")

    return all_results


def list_campaigns():
    """List all campaigns with their verification command counts."""
    print(f"\nCampaigns in {CAMPAIGNS_DIR}/:")
    print(f"{'='*70}")

    campaigns = sorted(CAMPAIGNS_DIR.glob("*.md"))
    total_cmds = 0
    for path in campaigns:
        content = path.read_text(errors="replace")
        code_match = re.search(r"codename:\s*(\S+)", content, re.MULTILINE)
        name_match = re.search(r"name:\s*[\"']?(.+?)[\"']?\s*$", content, re.MULTILINE)
        codename = code_match.group(1) if code_match else path.stem
        name = name_match.group(1) if name_match else path.stem

        commands = extract_verification_commands(path)
        total_cmds += len(commands)
        icon = "✅" if commands else "⚠️"
        print(f"  {icon} [{codename}] {name[:45]:<45s} {len(commands)} checks")

    print(f"{'='*70}")
    print(f"  Total: {len(campaigns)} campaigns, {total_cmds} verification commands\n")


def generate_report(results: list[RalphCampaignResult]) -> Path:
    """Generate reports/ralph_integration_results.md from run results."""
    lines = [
        "# Ralph Loop Integration Results",
        f"\nGenerated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}",
        f"\n## Summary\n",
        f"| Campaign | Iterations | Victory | Elapsed | Checks |",
        f"|----------|-----------|---------|---------|--------|",
    ]

    victories = 0
    for r in results:
        icon = "✅" if r.victory else "❌"
        iters = len(r.iterations)
        if r.iterations:
            last = r.iterations[-1]
            passed = sum(1 for v in last.verifications if v.passed)
            total = len(last.verifications)
            checks = f"{passed}/{total}"
        else:
            checks = "0/0"
        lines.append(
            f"| {r.codename} | {iters} | {icon} | {r.total_elapsed_s:.1f}s | {checks} |"
        )
        if r.victory:
            victories += 1

    lines.append(f"\n**{victories}/{len(results)} campaigns verified**")

    # Detail per campaign
    for r in results:
        lines.append(f"\n## {r.codename}: {r.name}\n")
        if not r.verification_commands:
            lines.append("No verification commands found.\n")
            continue

        lines.append(f"**Commands ({len(r.verification_commands)}):**\n")
        for cmd in r.verification_commands:
            lines.append(f"```bash\n{cmd}\n```\n")

        if r.iterations:
            last = r.iterations[-1]
            lines.append(f"**Last iteration ({last.iteration}):**\n")
            for v in last.verifications:
                icon = "✅" if v.passed else "❌"
                lines.append(f"- {icon} `{v.command[:70]}` (exit {v.exit_code}, {v.elapsed_s:.3f}s)")

    path = REPORTS_DIR / "ralph_integration_results.md"
    path.write_text("\n".join(lines))
    return path


def main():
    parser = argparse.ArgumentParser(
        description="Ralph Loop Runner — persistent retry with external verification",
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    parser.add_argument("--list", action="store_true",
                        help="List all campaigns and their verification commands")
    parser.add_argument("--campaign", type=str,
                        help="Run Ralph loop on a specific campaign codename")
    parser.add_argument("--all", action="store_true",
                        help="Run Ralph loop on all campaigns with verification commands")
    parser.add_argument("--verify-only", action="store_true",
                        help="Only verify, don't retry (single pass)")
    parser.add_argument("--max-iterations", type=int, default=10,
                        help="Maximum iterations per campaign (default: 10)")
    parser.add_argument("--timeout", type=float, default=300.0,
                        help="Timeout in seconds per campaign (default: 300)")
    parser.add_argument("--quiet", action="store_true",
                        help="Suppress verbose output")
    parser.add_argument("--worktree", type=int, default=0,
                        help="Run N parallel Ralph loops on N git worktrees (branches)")

    args = parser.parse_args()

    if args.list:
        list_campaigns()
        return

    if not args.campaign and not args.all:
        parser.print_help()
        print("\nExamples:")
        print("  scripts/wm scripts/ralph_loop.py --list")
        print("  scripts/wm scripts/ralph_loop.py --verify-only --campaign IL001")
        print("  scripts/wm scripts/ralph_loop.py --campaign IL001 --max-iterations 10")
        print("  scripts/wm scripts/ralph_loop.py --all --timeout 600")
        return

    # Find campaign files
    campaign_files = []
    if args.campaign:
        for path in CAMPAIGNS_DIR.glob("*.md"):
            content = path.read_text(errors="replace")
            if re.search(rf"codename:\s*{re.escape(args.campaign)}\b", content):
                campaign_files.append(path)
                break
        if not campaign_files:
            print(f"Campaign '{args.campaign}' not found in {CAMPAIGNS_DIR}/")
            sys.exit(1)
    else:
        campaign_files = sorted(CAMPAIGNS_DIR.glob("*.md"))

    # Run Ralph loops
    ts = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"\n{'='*70}")
    print(f"  RALPH LOOP RUNNER")
    print(f"  Timestamp: {ts}")
    print(f"  Campaigns: {len(campaign_files)}")
    mode_str = 'verify-only' if args.verify_only else f'loop (max {args.max_iterations} iterations)'
    if args.worktree > 0:
        mode_str += f' + {args.worktree} git worktrees'
    print(f"  Mode: {mode_str}")
    print(f"  Timeout: {args.timeout:.0f}s per campaign")
    print(f"{'='*70}")

    results = []
    if args.worktree > 0:
        results = run_worktree_parallel(
            campaign_files,
            num_worktrees=args.worktree,
            max_iterations=args.max_iterations,
            timeout=args.timeout,
            verify_only=args.verify_only,
            verbose=not args.quiet,
        )
    else:
        for path in campaign_files:
            result = run_ralph_loop(
                path,
                max_iterations=args.max_iterations,
                timeout=args.timeout,
                verify_only=args.verify_only,
                verbose=not args.quiet,
            )
            results.append(result)

    # Generate report
    report_path = generate_report(results)

    # Summary
    victories = sum(1 for r in results if r.victory)
    total = len(results)
    print(f"\n{'='*70}")
    print(f"  RALPH LOOP COMPLETE")
    print(f"  Verified: {victories}/{total} campaigns")
    print(f"  Report: {report_path}")
    print(f"{'='*70}\n")


if __name__ == "__main__":
    main()
