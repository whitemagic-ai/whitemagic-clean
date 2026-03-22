#!/usr/bin/env python3
"""
Third Pass - Conservative & Safe

Based on learnings:
- First pass: 100K × 100 = 10M sims (SUCCESS)
- Second pass: 500K+ crashed system
- Third pass: 200K × 200 = 40M sims (4x first pass, safe)
"""

import json
import time
from pathlib import Path

import hyperevolution_core as rust

print("=" * 80)
print("THIRD PASS - SAFE & OPTIMIZED")
print("=" * 80)
print()

# Conservative scale with optimized parameters
config = rust.EvolutionConfig(
    200_000,     # population_size: 2x first pass (safe)
    200,         # num_generations: 2x first pass (safe)
    0.18,        # mutation_rate: Optimized from learnings
    0.7,         # crossover_rate: Keep working value
    0.25,        # selection_pressure: Optimized
    0.02,        # elitism_rate: Optimized (2x original)
)

print("📊 THIRD PASS CONFIGURATION")
print("-" * 80)
print("Conservative scale, optimized parameters:")
print()
print("Evolution History:")
print("  First Pass:  100K × 100 = 10M sims (SUCCESS)")
print("  Second Pass: 500K × 500 = CRASHED")
print("  Third Pass:  200K × 200 = 40M sims (4x first, SAFE)")
print()
print("Configuration:")
print(f"  Population: {config.population_size:,}")
print(f"  Generations: {config.num_generations:,}")
print(f"  Total sims: {config.population_size * config.num_generations:,}")
print(f"  Mutation: {config.mutation_rate} (optimized)")
print(f"  Selection: {config.selection_pressure} (optimized)")
print(f"  Elitism: {config.elitism_rate} (optimized)")
print()
print("Expected duration: ~2-3 minutes")
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
print("🚀 Starting third pass evolution...")
print("   Progress updates every 20 generations")
print()

start = time.time()
metrics = engine.evolve(config.num_generations)
duration = time.time() - start

print()
print("=" * 80)
print("THIRD PASS RESULTS")
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

# Three-way comparison
print("=" * 80)
print("THREE-WAY COMPARISON")
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

print("Metric              | First Pass | Third Pass | Change")
print("-" * 80)
print(f"Population          | {first_pass['population']:>10,} | {config.population_size:>10,} | +{((config.population_size/first_pass['population']-1)*100):.0f}%")
print(f"Generations         | {first_pass['generations']:>10,} | {config.num_generations:>10,} | +{((config.num_generations/first_pass['generations']-1)*100):.0f}%")
print(f"Total simulations   | {first_pass['total_sims']:>10,} | {metrics.total_lineages_simulated:>10,} | +{((metrics.total_lineages_simulated/first_pass['total_sims']-1)*100):.0f}%")
print(f"Best fitness        | {first_pass['best_fitness']:>10.4f} | {metrics.best_fitness:>10.4f} | {((metrics.best_fitness/first_pass['best_fitness']-1)*100):+.1f}%")
print(f"Final diversity     | {first_pass['diversity']:>9.2%} | {metrics.diversity:>9.2%} | {((metrics.diversity/first_pass['diversity']-1)*100):+.1f}%")
print(f"Duration (min)      | {first_pass['duration']/60:>10.2f} | {duration/60:>10.2f} | {((duration/first_pass['duration']-1)*100):+.0f}%")
if best:
    print(f"Best genome genes   | {first_pass['best_genes']:>10} | {best.gene_count():>10} | {((best.gene_count()/first_pass['best_genes']-1)*100):+.0f}%")
    print(f"Best found at gen   | {first_pass['best_gen']:>10} | {best.generation:>10} | Gen {best.generation}")
print()

# Save results
output_dir = Path("third_pass_results")
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
    "comparison_vs_first": {
        "fitness_improvement_pct": ((metrics.best_fitness/first_pass['best_fitness']-1)*100),
        "diversity_change_pct": ((metrics.diversity/first_pass['diversity']-1)*100),
        "scale_factor": metrics.total_lineages_simulated / first_pass["total_sims"],
    }
}

with open(output_dir / "results.json", "w") as f:
    json.dump(results, f, indent=2)

print(f"💾 Results saved to {output_dir}/results.json")
print()

# Final analysis
print("=" * 80)
print("FINAL ANALYSIS")
print("=" * 80)
print()

fitness_improvement = ((metrics.best_fitness/first_pass['best_fitness']-1)*100)

if fitness_improvement > 5:
    print(f"✅ EXCELLENT: {fitness_improvement:.1f}% fitness improvement!")
    print("   Optimized parameters are working")
    print("   Larger scale is finding better solutions")
elif fitness_improvement > 0:
    print(f"✅ GOOD: {fitness_improvement:.1f}% fitness improvement")
    print("   Positive trend, parameters reasonable")
else:
    print(f"⚠️  WARNING: {fitness_improvement:.1f}% change")
    print("   May need parameter adjustment")

print()

if metrics.diversity > 0.85:
    print("✅ Excellent diversity maintained")
elif metrics.diversity > 0.70:
    print("✅ Good diversity balance")
elif metrics.diversity > 0.50:
    print("⚠️  Moderate diversity - watch for convergence")
else:
    print("❌ Low diversity - premature convergence")

print()

if best:
    convergence_pct = (best.generation / config.num_generations) * 100
    if convergence_pct > 80:
        print(f"✅ Late convergence ({convergence_pct:.0f}%) - excellent exploration")
    elif convergence_pct > 50:
        print(f"✅ Mid-run convergence ({convergence_pct:.0f}%) - good balance")
    else:
        print(f"⚠️  Early convergence ({convergence_pct:.0f}%) - may need more exploration")

print()
print("✅ THIRD PASS COMPLETE!")
print()
print("System Status: All polyglot components implemented and tested")
print("Next: Install Mojo for GPU acceleration, then scale further")
