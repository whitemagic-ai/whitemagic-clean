---
name: SQL Injection Remediation
codename: IL001
army: alpha
type: fix_and_verify
priority: 1
clone_count: 10000
strategies: [adversarial, analytical, chain_of_thought]
category: security
phase: immediate
source: "Operation Iron Lotus AAR 2026-02-13 — 15 HIGH severity findings"
---

# SQL Injection Remediation

## Objective
Fix ALL 15 HIGH severity SQL injection vectors identified by Operation Iron Lotus.
Every `execute(f"...")` and `execute("...".format(` pattern in security-critical
files must be converted to parameterized queries `execute("... ? ...", (params,))`.

This is not optional. SQL injection is the #1 web vulnerability (OWASP Top 10).
Even in a local-first system, these patterns are unacceptable — they represent
sloppy engineering and will block any serious deployment.

## Victory Conditions
- [ ] All 15 identified SQL injection vectors converted to parameterized queries
- [ ] Zero `execute(f"` patterns remain in whitemagic/ directory
- [ ] Zero `execute("...".format(` patterns remain in whitemagic/ directory
- [ ] Zero `execute("..." %` patterns remain in whitemagic/ directory
- [ ] Each fix preserves the original query semantics (no broken queries)
- [ ] Re-scan with security_classification lieutenant confirms 0 HIGH SQL findings
- [ ] Existing test suite still passes after all fixes

## Targets
| File | Line | Type |
|------|------|------|
| whitemagic/db/optimizer.py | 292 | f-string SQL |
| whitemagic/core/memory/sqlite_backend.py | 137 | f-string SQL |
| whitemagic/core/memory/sqlite_backend.py | 204 | f-string SQL |
| whitemagic/core/memory/sqlite_backend.py | 717 | f-string SQL |
| whitemagic/core/memory/sqlite_backend.py | 729 | f-string SQL |
| whitemagic/core/memory/association_miner.py | 518 | f-string SQL |
| whitemagic/core/memory/constellations.py | 465 | f-string SQL |
| whitemagic/core/memory/db_manager.py | 42 | f-string SQL PRAGMA |
| whitemagic/core/memory/graph_engine.py | 175 | f-string SQL |
| whitemagic/core/memory/graph_engine.py | 182 | f-string SQL |
| whitemagic/core/memory/graph_engine.py | 562 | f-string SQL |
| whitemagic/core/intelligence/hologram/consolidation.py | 162 | f-string SQL |
| whitemagic/core/intelligence/synthesis/predictive_engine.py | 855 | f-string SQL |
| whitemagic/core/intelligence/synthesis/causal_net.py | 34 | f-string SQL |
| whitemagic/interfaces/api/routes/openai_compat.py | 15 | hardcoded_secrets |

## Strategy
1. For each target file, read the offending line and surrounding context
2. Convert the f-string/format SQL to parameterized query with ? placeholders
3. Ensure all dynamic values are passed as tuple parameters
4. For PRAGMA statements (db_manager.py), use proper quoting/escaping
5. For the hardcoded secret (openai_compat.py), move to environment variable
6. Deploy 10K verification clones to confirm each fix is semantically correct
7. Run full re-scan to verify 0 remaining vectors

## Verification
```bash
# Must return 0 matches
grep -rn 'execute(f"' whitemagic/ --include="*.py" | grep -v '#.*execute' | wc -l
grep -rn 'execute(f'"'"'' whitemagic/ --include="*.py" | wc -l
grep -rn '\.format(' whitemagic/ --include="*.py" | grep 'execute' | wc -l

# Re-run security scan
scripts/wm scripts/deploy_grand_army.py --objective alpha.security_classification
# Must show 0 HIGH findings
```
