# WM2 Evolution Module - Integration Guide

**How to integrate the evolution engine with WhiteMagic and run your first massive simulation**

---

## 🚀 Quick Start

### 1. Install Dependencies

```bash
cd /home/lucas/Desktop/WM2
pip install numpy rayon dataclasses-json
```

### 2. Run First Evolution

```python
from WM2.evolution import HyperEvolutionEngine

# Create engine with massive scale
engine = HyperEvolutionEngine(
    population_size=10_000_000,  # 10 million lineages
    num_generations=10_000,       # 10K generations
    mutation_rate=0.15,           # High variance
    crossover_rate=0.7,
    selection_pressure=0.2,
    elitism_rate=0.01,
)

# Run evolution
print("🧬 Starting massive evolution simulation...")
metrics = engine.run_evolution(
    dream_integration=True,
    kaizen_integration=True
)

print(f"\n✅ Evolution complete!")
print(f"   Lineages simulated: {metrics.total_lineages_simulated:,}")
print(f"   Best fitness: {metrics.best_fitness.aggregate:.3f}")
print(f"   Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
```

---

## 🔗 Integration with WhiteMagic

### Option 1: Standalone Mode

Run evolution independently, then extract insights:

```python
from WM2.evolution import (
    HyperEvolutionEngine,
    extract_actionable_insights,
    generate_code_from_genome
)
from pathlib import Path

# Run evolution
engine = HyperEvolutionEngine(population_size=1_000_000, num_generations=1000)
metrics = engine.run_evolution()

# Extract insights
insights = extract_actionable_insights(
    metrics=metrics.__dict__,
    population=engine.population,
    generation=engine.generation
)

# Generate code from best genome
best = engine.get_best_genome()
mutations = generate_code_from_genome(
    best,
    codebase_root=Path("/home/lucas/Desktop/whitemagicdev")
)

# Review mutations
for mutation in mutations:
    print(f"📝 {mutation.mutation_type}: {mutation.description}")
    print(f"   Target: {mutation.target_file}")
    print(f"   Impact: {mutation.estimated_impact:.2f}")
```

### Option 2: Dream Cycle Integration

Integrate with WhiteMagic's dream cycle for continuous evolution:

```python
import sys
sys.path.insert(0, "/home/lucas/Desktop/whitemagicdev")

from WM2.evolution import HyperEvolutionEngine, integrate_with_dream_cycle
from whitemagic.core.dreaming.dream_cycle import get_dream_cycle

# Create evolution engine
engine = HyperEvolutionEngine(
    population_size=100_000,  # Smaller for continuous runs
    num_generations=100,
    mutation_rate=0.15,
)

# Get WhiteMagic dream cycle
dream_cycle = get_dream_cycle()

# Integrate evolution with dreams
evo_dream = integrate_with_dream_cycle(engine, dream_cycle)

# Start dream cycle (evolution will run during idle periods)
dream_cycle.start()

print("🌙 Dream cycle started with evolution integration")
print("   Evolution will run during idle periods")
print("   Check dream_cycle.status() to see evolution reports")
```

### Option 3: Kaizen Integration

Use kaizen engine to analyze evolution results:

```python
from WM2.evolution import (
    HyperEvolutionEngine,
    extract_improvement_proposals
)

# Run evolution
engine = HyperEvolutionEngine(population_size=500_000, num_generations=500)
metrics = engine.run_evolution()

# Extract kaizen proposals
proposals = extract_improvement_proposals(
    evolution_engine=engine,
    population=engine.population,
    metrics=metrics.__dict__,
    generation=engine.generation
)

# Review proposals by priority
print(f"\n🔧 Kaizen Analysis: {len(proposals)} proposals")
for proposal in proposals[:10]:  # Top 10
    print(f"\n[Priority {proposal.priority}] {proposal.title}")
    print(f"   Category: {proposal.category}")
    print(f"   Impact: {proposal.impact}, Effort: {proposal.effort}")
    print(f"   Auto-fixable: {proposal.auto_fixable}")
    if proposal.fix_action:
        print(f"   Fix: {proposal.fix_action}")
```

---

## 🎯 Use Cases

### Use Case 1: Optimize Specific Subsystem

Focus evolution on improving a specific part of WhiteMagic:

```python
from WM2.evolution import GeneLibrary, HyperEvolutionEngine

# Create focused gene library (only optimization genes)
library = GeneLibrary.create_comprehensive_library()
opt_genes = [g for g in library if g.category == "optimization"]

# Create engine with focused library
engine = HyperEvolutionEngine(population_size=1_000_000, num_generations=2000)
engine.gene_library = opt_genes

# Run evolution
metrics = engine.run_evolution()

# Best genome will have optimal optimization genes
best = engine.get_best_genome()
print(f"Best optimization configuration:")
for gene in best.genes:
    print(f"  - {gene.name}: {gene.expression_level:.2f}")
```

### Use Case 2: Discover Novel Architectures

Let evolution explore completely new architectures:

```python
# High mutation rate for exploration
engine = HyperEvolutionEngine(
    population_size=5_000_000,
    num_generations=5000,
    mutation_rate=0.25,  # High mutation for exploration
    crossover_rate=0.8,   # High crossover for recombination
    selection_pressure=0.1,  # Low pressure to maintain diversity
)

# Run with novelty search (focus on different, not just better)
metrics = engine.run_evolution()

# Analyze diversity of solutions
from WM2.evolution import extract_actionable_insights

insights = extract_actionable_insights(
    metrics=metrics.__dict__,
    population=engine.population,
    generation=engine.generation
)

# Look for "discovery" category insights
discoveries = [i for i in insights["insights"] if i["category"] == "discovery"]
for discovery in discoveries:
    print(f"💡 {discovery['title']}")
    print(f"   {discovery['description']}")
```

### Use Case 3: Continuous Background Evolution

Run evolution 24/7 in background, applying improvements automatically:

```python
import time
from WM2.evolution import (
    HyperEvolutionEngine,
    extract_actionable_insights,
    generate_code_from_genome,
    apply_mutations_to_codebase
)
from pathlib import Path

def continuous_evolution_daemon():
    """Run evolution continuously, applying improvements"""
    
    codebase = Path("/home/lucas/Desktop/whitemagicdev")
    generation_count = 0
    
    while True:
        print(f"\n🧬 Starting evolution cycle {generation_count}")
        
        # Run evolution
        engine = HyperEvolutionEngine(
            population_size=1_000_000,
            num_generations=1000
        )
        metrics = engine.run_evolution()
        
        # Extract insights
        insights = extract_actionable_insights(
            metrics=metrics.__dict__,
            population=engine.population,
            generation=engine.generation
        )
        
        # Generate code from best genome
        best = engine.get_best_genome()
        mutations = generate_code_from_genome(best, codebase)
        
        # Apply mutations (dry run first)
        results = apply_mutations_to_codebase(
            mutations, codebase, dry_run=True
        )
        
        print(f"   Would apply {results['mutations_applied']} mutations")
        
        # If high-confidence, apply for real
        high_confidence = [
            m for m in mutations 
            if m.estimated_impact > 0.8
        ]
        
        if high_confidence:
            print(f"   Applying {len(high_confidence)} high-confidence mutations")
            apply_mutations_to_codebase(
                high_confidence, codebase, dry_run=False
            )
        
        generation_count += 1
        
        # Sleep between cycles
        time.sleep(3600)  # 1 hour

# Run daemon
# continuous_evolution_daemon()  # Uncomment to run
```

---

## 📊 Monitoring Evolution

### Check Progress

```python
# During evolution, check progress
print(f"Generation {engine.generation}/{engine.num_generations}")
print(f"Best fitness: {engine.best_fitness:.3f}")
print(f"Population size: {len(engine.population)}")

# Check diversity
diversity = engine._calculate_diversity(engine.population)
print(f"Diversity: {diversity:.2%}")
```

### View History

```python
# After evolution, view fitness history
import matplotlib.pyplot as plt

plt.figure(figsize=(12, 6))

# Fitness over time
plt.subplot(1, 2, 1)
plt.plot(metrics.fitness_history)
plt.title("Fitness Over Time")
plt.xlabel("Generation")
plt.ylabel("Average Fitness")

# Diversity over time
plt.subplot(1, 2, 2)
plt.plot(metrics.diversity_history)
plt.title("Diversity Over Time")
plt.xlabel("Generation")
plt.ylabel("Population Diversity")

plt.tight_layout()
plt.savefig("evolution_progress.png")
```

### Export Results

```python
import json

# Export metrics
with open("evolution_metrics.json", "w") as f:
    json.dump({
        "total_lineages": metrics.total_lineages_simulated,
        "generations": metrics.generations_completed,
        "throughput": metrics.throughput_lineages_per_sec,
        "best_fitness": metrics.best_fitness.__dict__,
        "convergence_gen": metrics.convergence_generation,
    }, f, indent=2)

# Export best genome
best = engine.get_best_genome()
with open("best_genome.json", "w") as f:
    json.dump({
        "genome_id": best.genome_id,
        "generation": best.generation,
        "fitness": best.fitness,
        "genes": [
            {
                "name": g.name,
                "category": g.category,
                "expression": g.expression_level
            }
            for g in best.genes
        ]
    }, f, indent=2)
```

---

## 🔧 Configuration

### Tuning Parameters

```python
# For fast convergence (exploit)
engine = HyperEvolutionEngine(
    mutation_rate=0.05,      # Low mutation
    crossover_rate=0.9,      # High crossover
    selection_pressure=0.3,  # Strong selection
    elitism_rate=0.05,       # Keep top 5%
)

# For exploration (explore)
engine = HyperEvolutionEngine(
    mutation_rate=0.25,      # High mutation
    crossover_rate=0.5,      # Lower crossover
    selection_pressure=0.1,  # Weak selection
    elitism_rate=0.01,       # Keep top 1%
)

# For balanced evolution (recommended)
engine = HyperEvolutionEngine(
    mutation_rate=0.15,      # Medium mutation
    crossover_rate=0.7,      # Medium-high crossover
    selection_pressure=0.2,  # Medium selection
    elitism_rate=0.01,       # Keep top 1%
)
```

### Environment Configuration

```python
# Vary environmental pressure
engine = HyperEvolutionEngine(...)

# Override environment in run
metrics = engine.run_evolution()

# Environment changes automatically every 1000 generations
# You can also set custom environments:
custom_env = {
    "resource_constrained": True,  # Emphasize efficiency
    "high_load": True,              # Emphasize scalability
    "innovation_pressure": 0.8,     # Emphasize novelty
}
```

---

## 🎓 Best Practices

### 1. Start Small

Don't jump to 10M lineages immediately:

```python
# Start with 100K to test
engine = HyperEvolutionEngine(population_size=100_000, num_generations=100)
metrics = engine.run_evolution()

# If it works, scale up
engine = HyperEvolutionEngine(population_size=1_000_000, num_generations=1000)
metrics = engine.run_evolution()

# Then go massive
engine = HyperEvolutionEngine(population_size=10_000_000, num_generations=10000)
metrics = engine.run_evolution()
```

### 2. Monitor Diversity

Always check diversity to prevent premature convergence:

```python
# After each run
if metrics.diversity_history[-1] < 0.1:
    print("⚠️ Low diversity - increase mutation rate")
```

### 3. Extract Insights

Always run insights pipeline to learn from evolution:

```python
insights = extract_actionable_insights(
    metrics=metrics.__dict__,
    population=engine.population,
    generation=engine.generation
)

# Review and apply recommendations
for rec in insights["recommendations"][:5]:
    print(f"[{rec['priority']}] {rec['mutation_name']}")
    print(f"    {rec['description']}")
```

### 4. Validate Generated Code

Always dry-run before applying mutations:

```python
# Generate code
mutations = generate_code_from_genome(best, codebase)

# Dry run first
results = apply_mutations_to_codebase(mutations, codebase, dry_run=True)
print(f"Would apply {results['mutations_applied']} mutations")

# Review, then apply
if input("Apply? (y/n): ").lower() == "y":
    apply_mutations_to_codebase(mutations, codebase, dry_run=False)
```

### 5. Save Checkpoints

Save evolution state periodically:

```python
import pickle

# Save checkpoint
checkpoint = {
    "generation": engine.generation,
    "population": engine.population,
    "best_fitness": engine.best_fitness,
    "metrics": metrics,
}

with open("evolution_checkpoint.pkl", "wb") as f:
    pickle.dump(checkpoint, f)

# Resume from checkpoint
with open("evolution_checkpoint.pkl", "rb") as f:
    checkpoint = pickle.load(f)
    
engine.generation = checkpoint["generation"]
engine.population = checkpoint["population"]
engine.best_fitness = checkpoint["best_fitness"]
```

---

## 🐛 Troubleshooting

### Issue: Slow Performance

**Problem**: Evolution running slower than expected

**Solutions**:
1. Reduce population size
2. Reduce number of genes per genome
3. Use Rust core (when implemented)
4. Run on machine with more cores

```python
# Optimize for speed
engine = HyperEvolutionEngine(
    population_size=100_000,  # Smaller population
    num_generations=1000,
)
```

### Issue: Premature Convergence

**Problem**: Population converges too quickly, loses diversity

**Solutions**:
1. Increase mutation rate
2. Decrease selection pressure
3. Add diversity injection
4. Use fitness sharing

```python
# Prevent premature convergence
engine = HyperEvolutionEngine(
    mutation_rate=0.20,      # Higher mutation
    selection_pressure=0.15,  # Lower pressure
)
```

### Issue: No Improvement

**Problem**: Fitness not improving over generations

**Solutions**:
1. Check fitness function
2. Increase selection pressure
3. Verify gene library has useful genes
4. Try different crossover strategy

```python
# Stronger selection
engine = HyperEvolutionEngine(
    selection_pressure=0.3,  # Stronger selection
    elitism_rate=0.05,       # Keep more elites
)
```

### Issue: Memory Usage

**Problem**: Running out of memory with large populations

**Solutions**:
1. Reduce population size
2. Use memory-efficient genome storage
3. Implement streaming evaluation
4. Use Zig storage layer (when implemented)

```python
# Reduce memory usage
engine = HyperEvolutionEngine(
    population_size=500_000,  # Smaller population
)
```

---

## 📚 Additional Resources

### Documentation
- `README.md` - Complete module documentation
- `IMPLEMENTATION_SUMMARY.md` - Technical details
- `INTEGRATION_GUIDE.md` - This file

### WhiteMagic Integration
- Dream Cycle: `/home/lucas/Desktop/whitemagicdev/whitemagic/core/dreaming/dream_cycle.py`
- Kaizen Engine: `/home/lucas/Desktop/whitemagicdev/whitemagic/core/intelligence/synthesis/kaizen_engine.py`
- Emergence Engine: `/home/lucas/Desktop/whitemagicdev/whitemagic/core/intelligence/agentic/emergence_engine.py`

### Examples
- See `hyperevolution_engine.py` for core implementation
- See `dream_integration.py` for dream cycle integration
- See `code_generator.py` for code generation examples

---

## 🎯 Next Steps

1. **Run first simulation** (100K lineages, 100 generations)
2. **Review insights** from insights pipeline
3. **Generate code** from best genome
4. **Validate mutations** with dry run
5. **Scale up** to millions of lineages
6. **Integrate with dream cycle** for continuous evolution
7. **Implement Rust core** for 100x speedup
8. **Deploy evolution daemon** for 24/7 improvement

---

**Ready to evolve WhiteMagic? Start with the Quick Start section above!** 🧬✨
