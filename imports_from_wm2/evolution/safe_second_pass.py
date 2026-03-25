#!/usr/bin/env python3
"""
Safe Second Pass - Memory-Conscious Evolution

Scaled to avoid memory crash:
- 500K population (vs 1M that crashed)
- 500 generations (vs 1K)
- Still 250M simulations (25x first pass)
"""

import hyperevolution_core as rust
import time
import json
from pathlib import Path

print("=" * 80)
print("SECOND PASS - OPTIMIZED & SAFE")
print("=" * 80)
print()

# Safe configuration - won't crash system
config = rust.EvolutionConfig(
    500_000,     # population_size: 5x larger than first pass (safe)
    500,         # num_generations: 5x longer (safe)
    0.18,        # mutation_rate: +20% (was 0.15)
    0.7,         # crossover_rate: Same as first pass
    0.25,        # selection_pressure: +25% (was 0.20)
    0.02,        # elitism_rate: 2x (was 0.01)
)

print("📊 SAFE OPTIMIZED CONFIGURATION")
print("-" * 80)
print("Scaled to avoid memory crash:")
print()
print("First Pass:")
print("  Population: 100,000")
print("  Generations: 100")
print("  Total sims: 10,000,000")
print("  Best fitness: 0.6748")
print("  Duration: 82.72s")
print()
print("Second Pass (Safe):")
print(f"  Population: {config.population_size:,} (5x)")
print(f"  Generations: {config.num_generations:,} (5x)")
print(f"  Total sims: {config.population_size * config.num_generations:,} (25x)")
print(f"  Mutation rate: {config.mutation_rate} (+20%)")
print(f"  Selection: {config.selection_pressure} (+25%)")
print(f"  Elitism: {config.elitism_rate} (+100%)")
print()
print(f"Expected duration: ~3-4 minutes")
print()

# Create gene library
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

print(f"Gene library: {len(genes)} genes")
print()

# Create engine
print("⚡ Creating Rust evolution engine...")
engine = rust.HyperEvolutionCore(config, genes)
print("✅ Engine created")
print()

# Run evolution
print("🚀 Starting safe optimized evolution...")
print("   Progress updates every 50 generations")
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
    "total_sims": 10_000_000,
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
print(f"Total simulations       | {first_pass['total_sims']:>10,} | {metrics.total_lineages_simulated:>11,} | +{((metrics.total_lineages_simulated/first_pass['total_sims']-1)*100):.0f}%")
print(f"Best fitness            | {first_pass['best_fitness']:>10.4f} | {metrics.best_fitness:>11.4f} | {improvement_fitness:+.1f}%")
print(f"Final diversity         | {first_pass['diversity']:>9.2%} | {metrics.diversity:>10.2%} | {improvement_diversity:+.1f}%")
print(f"Duration (min)          | {first_pass['duration']/60:>10.2f} | {duration/60:>11.2f} | +{((duration/first_pass['duration']-1)*100):.0f}%")
if best:
    print(f"Best genome genes       | {first_pass['best_genes']:>10} | {best.gene_count():>11} | {((best.gene_count()/first_pass['best_genes']-1)*100):+.0f}%")
    print(f"Best found at gen       | {first_pass['best_gen']:>10} | {best.generation:>11} | Gen {best.generation}")
print()

# Save results
output_dir = Path("second_pass_results")
output_dir.mkdir(exist_ok=True)

results = {
    "config": {
        "population_size": config.population_size,
        "num_generations": config.num_generations,
        "mutation_rate": config.mutation_rate,
        "crossover_rate": config.crossover_rate,
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
        "fitness_improvement_pct": improvement_fitness,
        "diversity_change_pct": improvement_diversity,
        "scale_factor": metrics.total_lineages_simulated / first_pass["total_sims"],
    }
}

with open(output_dir / "results.json", "w") as f:
    json.dump(results, f, indent=2)

print(f"💾 Results saved to {output_dir}/results.json")
print()

# Analysis for third pass
print("=" * 80)
print("LEARNINGS FOR THIRD PASS")
print("=" * 80)
print()

if improvement_fitness > 10:
    print("✅ EXCELLENT: >10% fitness improvement!")
    print("   Strategy: Scale up further, parameters working perfectly")
    print("   Third pass: 750K × 750 with same parameters")
elif improvement_fitness > 5:
    print("✅ GOOD: 5-10% fitness improvement")
    print("   Strategy: Keep scaling, maybe tweak mutation slightly")
    print("   Third pass: 750K × 750, mutation 0.19")
elif improvement_fitness > 0:
    print("⚠️  MODEST: <5% fitness improvement")
    print("   Strategy: Need parameter tuning")
    print("   Third pass: Try mutation 0.20 or selection 0.30")
else:
    print("❌ NO IMPROVEMENT: Fitness decreased or flat")
    print("   Strategy: Major rethink needed")
    print("   Third pass: Reduce mutation to 0.12, increase crossover")

print()

if metrics.diversity < 0.5:
    print("⚠️  LOW DIVERSITY: Premature convergence risk")
    print("   → Increase mutation rate or reduce selection pressure")
elif metrics.diversity > 0.85:
    print("⚠️  HIGH DIVERSITY: Not enough exploitation")
    print("   → Increase selection pressure or reduce mutation")
else:
    print("✅ GOOD DIVERSITY: Balanced exploration/exploitation")

print()

if best and best.generation < config.num_generations * 0.3:
    print("⚠️  EARLY CONVERGENCE: Best found too early")
    print("   → Increase mutation or reduce selection pressure")
elif best and best.generation > config.num_generations * 0.9:
    print("✅ LATE DISCOVERY: Good exploration throughout")
    print("   → Parameters allowing continuous improvement")
else:
    print("✅ MID-RUN DISCOVERY: Reasonable convergence timing")

print()
print("✅ SECOND PASS COMPLETE!")
print()
print("Next: Run third pass with optimized parameters based on these results")
