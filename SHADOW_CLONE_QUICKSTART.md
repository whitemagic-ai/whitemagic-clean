# Shadow Clone Army — Quick Reference

## Quick Start

```bash
# List all available campaigns and objectives
scripts/wm scripts/deploy_grand_army.py --list

# Run all markdown campaigns (5-min default)
scripts/wm scripts/deploy_grand_army.py --campaigns

# Yin-Yang autonomous mode (recon → action → verify → repeat)
scripts/wm scripts/deploy_grand_army.py --campaigns --yin-yang

# Time-limited deployment (10 min)
scripts/wm scripts/deploy_grand_army.py --campaigns --time-limit 600

# Sun Bin parallel columns (5 simultaneous)
scripts/wm scripts/deploy_grand_army.py --campaigns --columns 5

# Filter by phase
scripts/wm scripts/deploy_grand_army.py --campaigns --phase immediate

# Filter by category
scripts/wm scripts/deploy_grand_army.py --campaigns --category security

# Show campaign status without deploying
scripts/wm scripts/deploy_grand_army.py --status
```

## Built-in Armies (Operation Iron Lotus)

```bash
# Deploy all three
scripts/wm scripts/deploy_grand_army.py --all

# Single army
scripts/wm scripts/deploy_grand_army.py --army alpha   # 10K consensus
scripts/wm scripts/deploy_grand_army.py --army beta    # 70K map-reduce
scripts/wm scripts/deploy_grand_army.py --army gamma   # 240K+ brute-force

# Single objective
scripts/wm scripts/deploy_grand_army.py --objective alpha.security_classification
```

## Original 10 Objectives (Operation Thousand Eyes)

```bash
scripts/wm scripts/deploy_shadow_clones.py --all          # Run all 10
scripts/wm scripts/deploy_shadow_clones.py --objective 5   # Corpus denoising
scripts/wm scripts/deploy_shadow_clones.py --objective 3   # Archaeological excavation
```

## Campaign System

Campaigns live in `campaigns/*.md` with YAML frontmatter. Each defines:
- **codename**: e.g. `V004`, `IL002`
- **army**: `alpha` (10K), `beta` (50-100K), `gamma` (100K+)
- **priority**: 1 (critical) → 4 (polish)
- **victory_conditions**: All must be met for success
- **strategies**: `adversarial`, `analytical`, `chain_of_thought`, `creative`, `synthesis`, `memory_grounded`

### Campaign Prefixes
| Prefix | Meaning | Count |
|--------|---------|-------|
| `IL###` | Iron Lotus follow-ups | 5 |
| `F###` | Foundation prerequisites | 2 |
| `I###` | Intelligence/polish | 4 |
| `S###` | Synthesis campaigns | 4 |
| `V###` | v16 Grand Strategy | 10 |

### Phase Order
1. **immediate** — Critical fixes (IL001-IL005)
2. **foundation** — Prerequisites (F001-F002, V003)
3. **infrastructure** — Core systems (V005, V006)
4. **intelligence** — Analysis & improvement (V004, V007-V010, I001-I004)

## Architecture

```
┌─────────────────────────────────────────┐
│         deploy_grand_army.py            │
│  (orchestrator, campaign loader, YY)    │
├──────────┬──────────┬───────────────────┤
│  Alpha   │  Beta    │  Gamma            │
│  10K     │  70K     │  240K+            │
│ Consensus│Map-Reduce│ Brute-Force       │
├──────────┴──────────┴───────────────────┤
│         Rust Tokio Clone Army           │
│    (whitemagic_rs.tokio_deploy_clones)  │
│         934K clones/sec peak            │
├─────────────────────────────────────────┤
│  campaign_loader.py  │  campaign_metrics │
│  progress_tracker.py │  parallel/sched.  │
└─────────────────────────────────────────┘
```

## Key Files
| File | Purpose |
|------|---------|
| `scripts/deploy_grand_army.py` | Main orchestrator (3,268 LOC) |
| `scripts/deploy_shadow_clones.py` | Original 10-objective script (1,340 LOC) |
| `campaigns/*.md` | 25 campaign doctrine files |
| `whitemagic/agents/campaign_loader.py` | YAML frontmatter parser |
| `whitemagic/agents/campaign_metrics.py` | Per-army/objective tracking |
| `whitemagic/agents/progress_tracker.py` | Granular progress |
| `whitemagic/parallel/scheduler.py` | Priority task scheduler |
| `whitemagic/optimization/rust_accelerators.py` | Tokio clone backend |
| `whitemagic/config/concurrency.py` | Worker/async limits |
| `reports/` | Generated after-action reports |

## Tactics
- **Yin-Yang**: Autonomous recon→action→verify→repeat cycles
- **Sun Bin**: Multi-column parallel deployment (like ancient Chinese formations)
- **Ralph Escalation**: After 3 stagnant cycles, spawn dare-to-die corps
- **Cross-Campaign Blackboard**: Shared intelligence with dependency-aware deferral
- **Adaptive Pivot**: Automatic strategy fallback on stagnation

## Pre-Flight Check
```bash
# Verify Rust bridge
scripts/wm -c "import whitemagic_rs; print(f'Rust: {len([f for f in dir(whitemagic_rs) if not f.startswith(\"_\")])} functions')"

# Verify Tokio clones
scripts/wm -c "from whitemagic.optimization.rust_accelerators import tokio_clone_bench; ms, cps = tokio_clone_bench(10000); print(f'{cps:,.0f} clones/sec')"

# Verify DB
scripts/wm -c "import sqlite3, os; c=sqlite3.connect(os.path.expanduser('~/.whitemagic/memory/whitemagic.db')); print(c.execute('PRAGMA integrity_check(1)').fetchone()[0])"
```
