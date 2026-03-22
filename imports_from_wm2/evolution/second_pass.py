#!/usr/bin/env python3
"""
Second Pass - Optimized Evolution

Uses learnings from first pass:
- 10x larger population (1M vs 100K)
- 10x more generations (1K vs 100)
- Optimized parameters based on actual results
"""

import json
import time
from pathlib import Path

import hyperevolution_core as rust

print("=" * 80)
print("SECOND PASS - OPTIMIZED EVOLUTION")
print("=" * 80)
print()

# Optimized configuration based on first pass learnings
config = rust.EvolutionConfig(
    1_000_000,   # population_size: 10x larger (was 100K)
    1_000,       # num_generations: 10x longer (was 100)
    0.18,        # mutation_rate: +20% (was 0.15)
    0.7,         # crossover_rate: Same as first pass
    0.25,        # selection_pressure: +25% (was 0.20)
    0.02,        # elitism_rate: 2x (was 0.01)
)

print("📊 OPTIMIZED CONFIGURATION")
print("-" * 80)
print("Based on first pass learnings:")
print()
print("First Pass Results:")
print("  Population: 100,000")
print("  Generations: 100")
print("  Best fitness: 0.6748")
print("  Final diversity: 91.22%")
print("  Duration: 82.72s")
print()
print("Second Pass (Optimized):")
print(f"  Population: {config.population_size:,} (+900%)")
print(f"  Generations: {config.num_generations:,} (+900%)")
print(f"  Mutation rate: {config.mutation_rate} (+20%)")
print(f"  Selection pressure: {config.selection_pressure} (+25%)")
print(f"  Elitism rate: {config.elitism_rate} (+100%)")
print()
print(f"Total simulations: {config.population_size * config.num_generations:,}")
print("Expected duration: ~13-14 minutes")
print()

# Create gene library (same as first pass)
genes = []
categories = [
    rust.GeneCategory.Architecture,
    rust.GeneCategory.Feature,
    rust.GeneCategory.Optimization,
    rust.GeneCategory.Biological,
    rust.GeneCategory.Intelligence,
    rust.GeneCategory.Polyglot,
]

for i in range(1000):
    genes.append(rust.Gene(f"gene_{i}", categories[i % 6], 0.5))

print(f"Gene library: {len(genes)} genes (6 categories)")
print()

# Create engine
print("⚡ Creating Rust evolution engine...")
engine = rust.HyperEvolutionCore(config, genes)
print("✅ Engine created")
print()

# Run evolution
print("🚀 Starting optimized evolution...")
print("   Progress updates every 100 generations")
print()

start = time.time()
metrics = engine.evolve(config.num_generations)
duration = time.time() - start

print()
print("=" * 80)
print("SECOND PASS RESULTS")
print("=" * 80)
print()

# Results
print("📊 Performance:")
print(f"   Total lineages: {metrics.total_lineages_simulated:,}")
print(f"   Generations: {metrics.generations_completed:,}")
print(f"   Duration: {duration:.2f}s ({duration/60:.2f} min)")
print(f"   Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
print()

print("🧬 Evolution:")
print(f"   Best fitness: {metrics.best_fitness:.4f}")
print(f"   Average fitness: {metrics.average_fitness:.4f}")
print(f"   Final diversity: {metrics.diversity:.2%}")
print()

# Get best genome
best = engine.get_best_genome()
if best:
    print("🏆 Best Genome:")
    print(f"   ID: {best.genome_id}")
    print(f"   Generation: {best.generation}")
    print(f"   Fitness: {best.fitness:.4f}")
    print(f"   Genes: {best.gene_count()}")
    print()

# Comparison with first pass
print("=" * 80)
print("COMPARISON: FIRST PASS vs SECOND PASS")
print("=" * 80)
print()

first_pass = {
    "population": 100_000,
    "generations": 100,
    "best_fitness": 0.6748,
    "diversity": 0.9122,
    "duration": 82.72,
    "best_gen": 90,
    "best_genes": 22,
}

improvement_fitness = ((metrics.best_fitness - first_pass["best_fitness"]) /
                       first_pass["best_fitness"] * 100)
improvement_diversity = ((metrics.diversity - first_pass["diversity"]) /
                         first_pass["diversity"] * 100)

print("Metric                  | First Pass | Second Pass | Change")
print("-" * 80)
print(f"Population              | {first_pass['population']:>10,} | {config.population_size:>11,} | +{((config.population_size/first_pass['population']-1)*100):.0f}%")
print(f"Generations             | {first_pass['generations']:>10,} | {config.num_generations:>11,} | +{((config.num_generations/first_pass['generations']-1)*100):.0f}%")
print(f"Best fitness            | {first_pass['best_fitness']:>10.4f} | {metrics.best_fitness:>11.4f} | {improvement_fitness:+.1f}%")
print(f"Final diversity         | {first_pass['diversity']:>9.2%} | {metrics.diversity:>10.2%} | {improvement_diversity:+.1f}%")
print(f"Duration (min)          | {first_pass['duration']/60:>10.2f} | {duration/60:>11.2f} | +{((duration/first_pass['duration']-1)*100):.0f}%")
if best:
    print(f"Best genome genes       | {first_pass['best_genes']:>10} | {best.gene_count():>11} | {((best.gene_count()/first_pass['best_genes']-1)*100):+.0f}%")
print()

# Save results
output_dir = Path("second_pass_results")
output_dir.mkdir(exist_ok=True)

results = {
    "config": {
        "population_size": config.population_size,
        "num_generations": config.num_generations,
        "mutation_rate": config.mutation_rate,
        "selection_pressure": config.selection_pressure,
        "elitism_rate": config.elitism_rate,
    },
    "metrics": {
        "total_lineages": metrics.total_lineages_simulated,
        "generations_completed": metrics.generations_completed,
        "best_fitness": metrics.best_fitness,
        "average_fitness": metrics.average_fitness,
        "diversity": metrics.diversity,
        "throughput": metrics.throughput_lineages_per_sec,
        "duration": duration,
    },
    "best_genome": {
        "id": best.genome_id if best else None,
        "generation": best.generation if best else None,
        "fitness": best.fitness if best else None,
        "gene_count": best.gene_count() if best else None,
    },
    "comparison": {
        "fitness_improvement": improvement_fitness,
        "diversity_change": improvement_diversity,
    }
}

with open(output_dir / "results.json", "w") as f:
    json.dump(results, f, indent=2)

print(f"💾 Results saved to {output_dir}/results.json")
print()

# Recommendations for third pass
print("=" * 80)
print("RECOMMENDATIONS FOR THIRD PASS")
print("=" * 80)
print()

if improvement_fitness > 5:
    print("✅ Significant fitness improvement - current parameters working well")
    print("   → Keep similar configuration, maybe increase generations to 2K")
elif improvement_fitness > 0:
    print("⚠️  Modest fitness improvement - parameters need tuning")
    print("   → Try higher mutation rate (0.20) or stronger selection (0.30)")
else:
    print("❌ No fitness improvement - major changes needed")
    print("   → Reconsider fitness function or try different gene library")

print()

if metrics.diversity < 0.5:
    print("⚠️  Low diversity - risk of premature convergence")
    print("   → Increase mutation rate or add diversity injection")
elif metrics.diversity > 0.9:
    print("⚠️  Very high diversity - may need more exploitation")
    print("   → Increase selection pressure or reduce mutation rate")
else:
    print("✅ Good diversity balance")

print()
print("✅ SECOND PASS COMPLETE!")
