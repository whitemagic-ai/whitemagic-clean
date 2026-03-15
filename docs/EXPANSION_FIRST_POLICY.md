# Expansion First Policy

## Principle
Before creating new code, always check:

1. **Dead code first**: Check `reports/dead_code.json` for archived modules that could be restored
2. **Redundancy check**: Check `reports/import_graph.json` for similar implementations
3. **Existing patterns**: Search codebase for similar functionality before inventing

## Enforcement

### Pre-Creation Checklist
When proposing new code:

```python
# Step 1: Check dead code archive
import json
dead = json.loads(Path("reports/dead_code.json").read_text())
similar_dead = [f for f in dead if "keyword" in f["path"]]

# Step 2: Check import graph for similar modules
graph = json.loads(Path("reports/import_graph.json").read_text())
similar_nodes = [n for n in graph["nodes"] if "keyword" in n["id"]]

# Step 3: Only if no match found, proceed with creation
if not similar_dead and not similar_nodes:
    # Safe to create new
    pass
```

### Decision Tree

```
Need new functionality?
    │
    ├─► Check dead_code.json ──► Found? ──► Restore & adapt
    │                              │
    │                              └─► Not found
    │                                    │
    ├─► Check import_graph.json ──► Found? ──► Extend existing
    │                                    │
    │                                    └─► Not found
    │                                          │
    └─► Check redundancy pairs ──► Found? ──► Consolidate
                                             │
                                             └─► Not found
                                                   │
                                                   └─► CREATE NEW
```

## Metrics

- **Re-use ratio**: Target 70%+ of new features built from existing code
- **Dead code revival**: Track restored modules
- **Redundancy reduction**: Track merged implementations

## Files

- `reports/dead_code.json` — Archived modules available for restoration
- `reports/import_graph.json` — Current module dependency graph
- `reports/great_census.md` — Redundancy pairs section

---

*Part of S020 Phase 6: Anti-Reinvention Protocol*
