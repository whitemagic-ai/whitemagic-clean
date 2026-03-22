---
name: "The Great Codebase Census"
codename: V001
army: beta
type: discovery
priority: 1
clone_count: 50000
strategies:
  - analytical
  - chain_of_thought
  - synthesis
category: self_discovery
phase: immediate
source: "Grand Strategy v16 — recursive self-discovery"
column_size: 25000
---

## Objective

Deploy shadow clones to read every single Python file (1,117 files, 235K LOC) and
classify the entire codebase. Build a complete import dependency graph, identify
redundancy, dead code, quality gaps, and map every file to its biological subsystem.

This is the foundation campaign — everything else in v16 depends on knowing exactly
what we have.

### Key Questions to Answer
1. Which files are imported by nothing? (Dead code candidates)
2. Which files duplicate functionality? (Merge candidates)
3. Which modules have no tests? (Quality gaps)
4. Which files belong to which biological subsystem? (Organ mapping)
5. What is the actual dependency structure? (Nervous system wiring plan)

## Victory Conditions
- [x] Complete import dependency graph for all 857 Python files (2,353 edges)
- [x] Every file classified into 58 functional categories (0 uncategorized)
- [x] Redundancy report: 1,505 pairs with >60% import similarity identified
- [x] Dead code report: 258 files (33,115 LOC) with 0 importers and no __main__ block
- [x] Bio-metaphor mapping: every file tagged to 10 biological subsystems
- [x] Quality scorecard: docstring 60.8%, type hints 81.5%, test coverage 4.8% per category
- [x] Report: reports/great_census.md + import_graph.json + dead_code.json

## Strategy
1. Build AST-based import scanner for all .py files under whitemagic/
2. Build reverse dependency map (who imports whom)
3. Identify files with 0 reverse dependencies (dead code)
4. Cluster files by import similarity (functional overlap detection)
5. Scan for docstrings, type hints, associated test files
6. Classify each file into functional category + biological subsystem
7. Generate comprehensive census report with actionable recommendations

## Verification
```bash
# Import graph generated
scripts/wm -c "import json; d=json.load(open('reports/import_graph.json')); print(f'Nodes: {len(d[\"nodes\"])}')"
# Census report exists
test -f reports/great_census.md && echo "OK"
# Dead code list
scripts/wm -c "import json; d=json.load(open('reports/dead_code.json')); print(f'Dead: {len(d)}')"
```
