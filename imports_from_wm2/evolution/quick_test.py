#!/usr/bin/env python3
"""Quick test of Rust core with real evolution"""

import time

import hyperevolution_core as rust

print("🦀 RUST EVOLUTION ENGINE - LIVE TEST")
print("=" * 80)

# Test with 100K lineages × 100 generations
config = rust.EvolutionConfig(
    population_size=100_000,
    num_generations=100,
    mutation_rate=0.15,
    crossover_rate=0.7,
    selection_pressure=0.2,
    elitism_rate=0.01,
)

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
    genes.append(rust.Gene(
        f"gene_{i}",
        categories[i % 6],
        0.5
    ))

print(f"Configuration: {config.population_size:,} lineages × {config.num_generations} generations")
print(f"Total simulations: {config.population_size * config.num_generations:,}")
print(f"Gene library: {len(genes)} genes")
print()

# Create engine
engine = rust.HyperEvolutionCore(config, genes)
print("✅ Engine created")
print()

# Run evolution
print("🚀 Starting evolution...")
print()
start = time.time()
metrics = engine.evolve(config.num_generations)
duration = time.time() - start

print()
print("=" * 80)
print("RESULTS")
print("=" * 80)
print(f"Total lineages simulated: {metrics.total_lineages_simulated:,}")
print(f"Generations completed: {metrics.generations_completed}")
print(f"Best fitness: {metrics.best_fitness:.4f}")
print(f"Average fitness: {metrics.average_fitness:.4f}")
print(f"Final diversity: {metrics.diversity:.2%}")
print(f"Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
print(f"Duration: {duration:.2f}s ({duration/60:.2f} min)")
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

print("✅ RUST EVOLUTION COMPLETE!")
