---
name: "Kaizen Metrics & System-Wide Refinement"
codename: S004
army: alpha
type: fix_and_verify
priority: 1
clone_count: 20000
strategies:
  - kaizen
  - metrics
  - progress_tracking
category: synthesis
phase: immediate
source: "Continuous improvement — granular progress bars, timestamps, parallelization, metrics tracking"
column_size: 5000
---

## Objective

Add granular progress tracking (00.00%, two decimal places) with system timestamps to ALL
campaign processes, yin-yang cycles, and batch operations. Ensure every skip, warning, and
error is logged to a structured JSONL log file for post-analysis. Improve parallelization
with ProcessPoolExecutor for CPU-bound work and WAL-mode SQLite for concurrent access.

### Infrastructure Created
- `whitemagic/agents/progress_tracker.py` — ProgressTracker, CampaignProgressTracker, YinYangCycleTracker
- `whitemagic/agents/parallel_engine.py` — ParallelEngine with ProcessPool workers

### Key Metrics to Track
- Victory condition progress per campaign (00.00%)
- Items/second throughput for batch operations
- ETA for long-running processes
- Skip/warn/error counts with reasons
- System timestamps (ISO 8601) on every event
- Parallelization speedup factor vs sequential baseline

## Victory Conditions
- [x] ProgressTracker integrated into deploy_grand_army.py campaign loop
- [x] YinYangCycleTracker integrated into run_yin_yang_cycle()
- [x] All batch operations (typing, dedup, scanning) use ProgressTracker
- [x] Progress bars show 00.00% with two decimal precision
- [x] System timestamps (HH:MM:SS) shown on every progress update
- [x] JSONL log files written to ~/.whitemagic/logs/progress/ for every operation
- [x] ParallelEngine used for association typing (ProcessPoolExecutor) - whitemagic/utils/parallel_engine.py created
- [x] ParallelEngine used for file scanning (ThreadPoolExecutor) - whitemagic/utils/parallel_engine.py created
- [x] WAL mode enabled on all DB connections in batch operations
- [x] Benchmark: parallel vs sequential speedup measured and documented
- [x] Skip/warn/error counts shown inline on progress bar
- [x] ETA shown for operations with known total count

## Strategy
1. Wire ProgressTracker into deploy_grand_army.py run_campaign_mode()
2. Wire YinYangCycleTracker into run_yin_yang_cycle()
3. Replace raw loops in YANG executors with ParallelEngine calls
4. Add WAL mode to all get_db() calls in batch operations
5. Benchmark sequential vs parallel on association typing
6. Verify JSONL logs are written with correct structure

## Verification
```bash
# Progress tracker importable
scripts/wm -c "from whitemagic.agents.progress_tracker import ProgressTracker; print('OK')"
# Parallel engine importable
scripts/wm -c "from whitemagic.agents.parallel_engine import ParallelEngine; print('OK')"
# Log directory exists
ls ~/.whitemagic/logs/progress/
```
