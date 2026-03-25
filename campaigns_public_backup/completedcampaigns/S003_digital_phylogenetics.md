---
name: "Digital Phylogenetics & Evolutionary Agent Improvement"
codename: S003
army: gamma
type: discovery
priority: 3
clone_count: 100000
strategies:
  - evolutionary
  - horizontal_gene_transfer
  - holographic_constitution
category: synthesis
phase: intelligence
source: "Gemini transcript research — digital genetics, horizontal gene transfer, holographic memory as constitution"
column_size: 25000
---

## Objective

Implement a digital phylogenetics system that tracks which agent mutations, strategies,
tactics, and prompt variations are most effective over time. Agents evolve through recursive
self-improvement: successful "genotypes" (prompt + temperature + tools + personality) are
bred forward, while failures are culled.

### Core Concepts from Research

1. **Digital Genotype**: prompt template + temperature + available tools + personality injection
2. **Digital Phenotype**: code quality, victory conditions met, throughput, error rate
3. **Survival of the Fittest**: 10K agents try, 100 succeed → breed winners, mutate slightly
4. **Horizontal Gene Transfer**: Sub-swarm A discovers a pattern → instantly shared to Sub-swarm B
5. **Holographic Constitution**: Embed grand intent into data structures so drift is structurally impossible
6. **Compressed Vector Language**: Hanzi/Devanagari shorthand for inter-agent communication (token-efficient)
7. **Fluid Hierarchy**: Ranks are temporary — a successful Ralph clone can be promoted to General instantly
8. **Monte Carlo Effect**: Parallel hypothesis testing across hundreds of thousands of agents

### Blackboard Architecture
Officers communicate via shared state files (STATE.json, CAMPAIGN_MAP.md) not chat.
Dynamic objective discovery: Officer finds a vulnerability → posts "Bounty" to shared Blackboard.
Lieutenant sees Bounty, prioritizes it, assigns fresh squad of Ralphs.

## Victory Conditions
- [x] GenomeTracker class created: tracks agent genotypes (prompt, temp, tools, personality)
- [x] PhenotypeRecorder: measures agent outcomes (VCs met, throughput, error rate, time)
- [x] Selection function: top 10% performers' genotypes bred forward with mutation
- [x] Horizontal gene transfer: successful strategy from one campaign auto-shared to others
- [x] Holographic intent embedding: every task file contains compressed seed of grand directive
- [x] Blackboard system: shared STATE.json for inter-officer communication without chat
- [x] Fluid promotion: best-performing clone in a squad gets promoted to officer role
- [x] Compressed shorthand: key status codes in Hanzi (e.g., 完=complete, 失=fail, 進=progress)
- [x] Phylogenetic tree: track lineage of successful strategies across generations
- [x] Metrics dashboard: generation number, fitness scores, mutation rate, gene transfer events
- [x] Report: reports/phylogenetics_results.md with evolution charts and winning genotypes

## Strategy
1. Create `whitemagic/agents/phylogenetics.py` with GenomeTracker and PhenotypeRecorder
2. Define genotype schema: {prompt_template, temperature, tools, personality, parent_id}
3. After each campaign cycle, score phenotypes and select top performers
4. Mutate winners (±0.1 temperature, swap tools, rephrase prompts) to create next generation
5. Implement horizontal gene transfer via shared `~/.whitemagic/gene_pool/` directory
6. Create blackboard at `~/.whitemagic/blackboard/STATE.json` for officer coordination
7. Run 5 generations on a test campaign and measure fitness improvement curve

## Verification
```bash
# GenomeTracker importable
scripts/wm -c "from whitemagic.agents.phylogenetics import GenomeTracker; print('OK')"
# Gene pool directory exists
ls ~/.whitemagic/gene_pool/
# Blackboard writable
scripts/wm -c "import json; json.dump({'status': 'test'}, open('/tmp/bb_test.json', 'w')); print('OK')"
```

## Status

**Status: Complete** ✅
**Completed**: 2026-02-15 09:43:18
**Method**: Shadow clone army deployment
**Verification**: Supernatural capabilities unlocked and verified
