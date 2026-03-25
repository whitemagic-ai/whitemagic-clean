# Fresh Clone / Seed Test (Whitemagic v11)

Goal: verify that a brand-new checkout can be installed and run without any personal data, and that all runtime state is created under `WM_STATE_ROOT` (not inside the repo).

## 1) Create A Fresh Directory

Example (Desktop):
```bash
mkdir -p ~/Desktop/whitemagic_seed_test
cd ~/Desktop/whitemagic_seed_test
```

## 2) Get The Code

If you have a remote:
```bash
git clone <YOUR_REPO_URL> whitemagic
cd whitemagic
```

If you are testing locally (no remote yet), copy the repo:
```bash
cp -R /path/to/whitemagic ./whitemagic
cd whitemagic
```

## 3) Create A Clean Venv + Install

```bash
python -m venv .venv
. .venv/bin/activate
python -m pip install --upgrade pip
python -m pip install -e ".[dev,mcp,cli]"
```

## 4) Force A Safe State Root (No Repo Writes)

```bash
export WM_STATE_ROOT=/tmp/whitemagic_seed_state
export WM_DB_PATH=/tmp/whitemagic_seed_state/memory/whitemagic.db
```

## 5) Run The Core Checks

### CLI (Good For Screenshots)
```bash
wm status
wm explore
wm health
```

### CLI (JSON, AI-Friendly)
```bash
wm --json status
wm --json doctor
```

### Tool Contract Smoke
```bash
python audit/tool_smoke.py
```

### Eval Harness (Determinism + Idempotency + Ship Hygiene)
```bash
python eval/run_eval.py --now 2026-01-01T00:00:00Z
```

### OSS Hygiene Scan (No Memory Exfiltration)
```bash
python -c "import json; from whitemagic.tools.unified_api import call_tool; print(json.dumps(call_tool('ship.check'), indent=2, sort_keys=True))"
```

## 6) Expected Outcomes

- `WM_STATE_ROOT` is created and populated (e.g. `/tmp/whitemagic_seed_state/memory`, `/tmp/whitemagic_seed_state/logs`, etc.)
- The repo itself stays clean (no new tracked files are produced by normal runs)
- `ship.check` reports `ok: true`
- `audit/tool_smoke.py` completes without crashing

## Notes

- If you want to override DB path via CLI flags, example:
  `wm --state-root /tmp/whitemagic_seed_state --db-path /tmp/whitemagic_seed_state/memory/whitemagic.db status`
- Local model / embedded inference code is intentionally archived/disabled by default. See `whitemagic/_archived/`.
