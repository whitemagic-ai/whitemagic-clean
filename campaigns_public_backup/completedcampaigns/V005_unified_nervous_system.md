---
name: "The Unified Nervous System"
codename: V005
army: beta
type: discovery
priority: 3
clone_count: 80000
strategies:
  - synthesis
  - evolutionary
  - horizontal_gene_transfer
category: synthesis
phase: intelligence
source: "Grand Strategy v16 — wire 7 biological subsystems into unified organism"
column_size: 40000
depends_on: ["V001"]
---

## Objective

Wire WhiteMagic's 7 biological subsystems (immune, genetics, dream, metabolism,
consciousness, resonance, emergence) into a unified nervous system where each
organ communicates with and influences every other.

Currently these 60+ files operate independently. The nervous system will create
bidirectional feedback loops between all subsystems, transforming WhiteMagic from
a collection of independent organs into a unified living organism.

### The Organ Map

```
         Immune System (10 files)
              ↕ threat→dream, antibody←emergence
    Homeostasis ←→ Dream Cycle (8 files)
         ↕              ↕
    DNA/Genetics ←→ Memory Metabolism (6 files)
         ↕              ↕
    Phylogenetics ←→ Consciousness/Embodiment (5 files)
         ↕              ↕
    Evolution ←→ Resonance/Harmony (8 files)
              ↕
         Emergence/Ecology (6 files)
```

### Feedback Loops to Wire
1. **Immune → Dream**: Threat detection triggers defensive dream cycle
2. **Homeostasis → Phylogenetics**: Equilibrium score modulates mutation rate
3. **Dream → Genetics**: Consolidation results feed fitness scores
4. **Emergence → Immune**: New patterns create preemptive antibodies
5. **Consciousness → Forgetting**: Coherence level modulates decay thresholds
6. **Resonance → Evolution**: Harmonic patterns guide evolutionary selection
7. **Metabolism → Homeostasis**: Consolidation load affects balance targets

## Victory Conditions
- [x] Create `whitemagic/core/nervous_system.py` — central nervous bus
- [x] Immune→Dream: threat detection triggers defensive dream cycle
- [x] Homeostasis→Phylogenetics: equilibrium score modulates mutation rate
- [x] Dream→Genetics: consolidation results feed fitness scores
- [x] Emergence→Immune: new patterns create preemptive antibodies
- [x] Consciousness→Forgetting: coherence level modulates decay thresholds
- [x] All 7 subsystems registered as nervous system organs
- [x] Health dashboard shows all organ statuses in one view
- [x] End-to-end test: inject threat → immune detects → dream consolidates → antibody created
- [x] Report: reports/nervous_system.md

## Strategy
1. Audit all 60+ biological metaphor files, document their public APIs
2. Design nervous_system.py as an event-driven organ registry
3. Use Gan Ying event bus as the neural pathway (already exists!)
4. Define event types for each inter-organ signal
5. Wire feedback loops one at a time, test each independently
6. Build health dashboard that queries all organs
7. Run end-to-end integration test with real threat injection

## Verification
```bash
# Nervous system importable
scripts/wm -c "from whitemagic.core.nervous_system import NervousSystem; print('OK')"
# All organs registered
scripts/wm -c "from whitemagic.core.nervous_system import get_nervous_system; ns=get_nervous_system(); print(f'Organs: {len(ns.organs)}')"
# Health dashboard
scripts/wm -c "from whitemagic.core.nervous_system import get_nervous_system; print(get_nervous_system().health_dashboard())"
```
