#!/usr/bin/env python3
"""
Run evolution with real gene library from WhiteMagic codebase
Safer approach: 200K × 100 to avoid crashes
"""

import json
import time

import hyperevolution_core as rust


def load_real_gene_library():
    """Load gene library from seed vault"""
    print("📚 Loading gene library from WhiteMagic codebase...")

    with open("gene_library_seed_vault.json") as f:
        library = json.load(f)

    genes = []
    for gene_data in library['genes']:
        category_map = {
            'Architecture': rust.GeneCategory.Architecture,
            'Feature': rust.GeneCategory.Feature,
            'Optimization': rust.GeneCategory.Optimization,
            'Biological': rust.GeneCategory.Biological,
            'Intelligence': rust.GeneCategory.Intelligence,
            'Polyglot': rust.GeneCategory.Polyglot,
        }

        category = category_map.get(gene_data['category'], rust.GeneCategory.Feature)
        genes.append(rust.Gene(gene_data['name'], category, gene_data['value']))

    print(f"   ✅ Loaded {len(genes)} real genes")
    print(f"   📊 Categories: {library['categories']}")
    return genes

def main():
    print("=" * 80)
    print("EVOLUTION WITH REAL GENE LIBRARY")
    print("=" * 80)
    print()

    # Load real genes
    genes = load_real_gene_library()
    print()

    # Safe configuration (200K × 100)
    population = 200_000
    generations = 100

    # Optimal parameters from Option C
    config = rust.EvolutionConfig(
        population,
        generations,
        0.20,  # mutation_rate (best throughput)
        0.7,   # crossover_rate
        0.25,  # selection_pressure
        0.02,  # elitism_rate
    )

    print("Configuration:")
    print(f"  Population: {population:,}")
    print(f"  Generations: {generations}")
    print(f"  Total simulations: {population * generations:,}")
    print(f"  Gene library: {len(genes)} real patterns from WhiteMagic")
    print()

    # Run evolution
    print("🚀 Starting evolution with real genes...")
    print("=" * 80)
    print()

    engine = rust.HyperEvolutionCore(config, genes)

    start = time.time()
    metrics = engine.evolve(generations)
    duration = time.time() - start

    print()
    print("=" * 80)
    print("✅ EVOLUTION COMPLETE")
    print("=" * 80)
    print()

    # Results
    print("📊 RESULTS:")
    print(f"   Best fitness: {metrics.best_fitness:.4f}")
    print(f"   Average fitness: {metrics.average_fitness:.4f}")
    print(f"   Diversity: {metrics.diversity:.2%}")
    print(f"   Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
    print(f"   Duration: {duration:.1f}s ({duration/60:.1f} minutes)")
    print()

    # Save results
    results = {
        'population': population,
        'generations': generations,
        'total_simulations': population * generations,
        'gene_library_size': len(genes),
        'gene_library_source': 'WhiteMagic codebase (whitemagicdev + whitemagicpublic)',
        'best_fitness': metrics.best_fitness,
        'avg_fitness': metrics.average_fitness,
        'diversity': metrics.diversity,
        'throughput': metrics.throughput_lineages_per_sec,
        'duration': duration,
        'generations_completed': metrics.generations_completed,
    }

    with open("real_gene_library_results.json", 'w') as f:
        json.dump(results, f, indent=2)

    print("💾 Results saved to real_gene_library_results.json")
    print()

    # Analysis
    print("🧬 EVOLUTION ANALYSIS:")
    print(f"   Generations completed: {metrics.generations_completed}")
    print(f"   Total lineages simulated: {metrics.total_lineages_simulated:,}")
    print()

    # Compare to synthetic library
    print("📈 COMPARISON:")
    print("   Synthetic library (1000 generic genes): fitness ~0.68")
    print(f"   Real library (34 WhiteMagic patterns): fitness {metrics.best_fitness:.4f}")
    print()

    if metrics.best_fitness > 0.68:
        print("🎯 Real genes performed BETTER than synthetic!")
    elif metrics.best_fitness > 0.65:
        print("✅ Real genes performed comparably to synthetic")
    else:
        print("📊 Real genes need more patterns (expand library)")

    print()
    print("Next: Implement validation to test if these genes produce working code!")

if __name__ == "__main__":
    main()
