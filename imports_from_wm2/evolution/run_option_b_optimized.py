#!/usr/bin/env python3
"""
Option B: Massive Scale Evolution with Optimized Parameters

Using optimal parameters from Option C: mut=0.20, sel=0.25, eli=0.02
Population: 500K, Generations: 200
Expected: 100M simulations, ~13 minutes, fitness >0.69
"""

import hyperevolution_core as rust
import time
import json
from dataclasses import dataclass, asdict
import psutil

@dataclass
class MassiveScaleResults:
    population: int
    generations: int
    total_simulations: int
    mutation_rate: float
    selection_pressure: float
    elitism_rate: float
    crossover_rate: float
    best_fitness: float
    avg_fitness: float
    diversity: float
    throughput: float
    duration: float
    peak_memory_mb: float
    best_genome_size: int

def run_massive_scale():
    """Run Option B with optimal parameters"""
    
    print("=" * 80)
    print("OPTION B: MASSIVE SCALE EVOLUTION")
    print("=" * 80)
    print()
    
    # Optimal parameters from Option C
    population = 500_000
    generations = 200
    mutation_rate = 0.20
    selection_pressure = 0.25
    elitism_rate = 0.02
    crossover_rate = 0.7
    
    print("Configuration:")
    print(f"  Population: {population:,}")
    print(f"  Generations: {generations}")
    print(f"  Total simulations: {population * generations:,}")
    print(f"  Mutation rate: {mutation_rate}")
    print(f"  Selection pressure: {selection_pressure}")
    print(f"  Elitism rate: {elitism_rate}")
    print(f"  Crossover rate: {crossover_rate}")
    print()
    
    print("Expected performance (from Option C):")
    print("  Throughput: ~132,000 lineages/sec")
    print("  Duration: ~13 minutes")
    print("  Fitness: 0.69-0.70 (target)")
    print()
    
    # Create gene library
    print("📚 Creating gene library (1,000 genes)...")
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
    
    print(f"   ✅ {len(genes)} genes created")
    print()
    
    # Check available memory
    process = psutil.Process()
    available_memory = psutil.virtual_memory().available / 1024 / 1024
    print(f"💾 Available memory: {available_memory:,.0f} MB")
    
    estimated_memory = population * 0.001  # ~1KB per genome
    print(f"   Estimated usage: {estimated_memory:,.0f} MB")
    
    if estimated_memory > available_memory * 0.5:
        print("   ⚠️  WARNING: May need streaming for memory safety")
        print("   Consider using streaming_evolution.py instead")
        response = input("   Continue anyway? (y/n): ")
        if response.lower() != 'y':
            print("   Aborted. Use streaming_evolution.py for safety.")
            return
    else:
        print("   ✅ Memory sufficient, proceeding without streaming")
    print()
    
    # Create evolution config
    print("🔧 Initializing evolution engine...")
    config = rust.EvolutionConfig(
        population,
        generations,
        mutation_rate,
        crossover_rate,
        selection_pressure,
        elitism_rate,
    )
    
    engine = rust.HyperEvolutionCore(config, genes)
    print("   ✅ Engine ready")
    print()
    
    # Monitor memory
    start_memory = process.memory_info().rss / 1024 / 1024
    peak_memory = start_memory
    
    print("🚀 Starting evolution...")
    print("=" * 80)
    print()
    
    start_time = time.time()
    
    try:
        metrics = engine.evolve(generations)
        duration = time.time() - start_time
        
        end_memory = process.memory_info().rss / 1024 / 1024
        peak_memory = max(peak_memory, end_memory)
        
        print()
        print("=" * 80)
        print("✅ EVOLUTION COMPLETE")
        print("=" * 80)
        print()
        
        # Display results
        print("📊 RESULTS:")
        print(f"   Best fitness: {metrics.best_fitness:.4f}")
        print(f"   Average fitness: {metrics.average_fitness:.4f}")
        print(f"   Diversity: {metrics.diversity:.2%}")
        print(f"   Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
        print(f"   Duration: {duration:.1f}s ({duration/60:.1f} minutes)")
        print(f"   Peak memory: {peak_memory:.0f} MB")
        print()
        
        # Calculate improvements
        third_pass_fitness = 0.6816
        improvement = ((metrics.best_fitness / third_pass_fitness) - 1) * 100
        
        print("📈 COMPARISON TO THIRD PASS:")
        print(f"   Third pass fitness: {third_pass_fitness:.4f}")
        print(f"   Option B fitness: {metrics.best_fitness:.4f}")
        print(f"   Improvement: {improvement:+.2f}%")
        print()
        
        # Save results
        results = MassiveScaleResults(
            population=population,
            generations=generations,
            total_simulations=population * generations,
            mutation_rate=mutation_rate,
            selection_pressure=selection_pressure,
            elitism_rate=elitism_rate,
            crossover_rate=crossover_rate,
            best_fitness=metrics.best_fitness,
            avg_fitness=metrics.average_fitness,
            diversity=metrics.diversity,
            throughput=metrics.throughput_lineages_per_sec,
            duration=duration,
            peak_memory_mb=peak_memory,
            best_genome_size=len(metrics.best_genome.genes),
        )
        
        with open("option_b_results.json", 'w') as f:
            json.dump(asdict(results), f, indent=2)
        
        print("💾 Results saved to option_b_results.json")
        print()
        
        # Victory assessment
        if metrics.best_fitness > 0.69:
            print("🏆 VICTORY: Fitness target exceeded!")
        elif metrics.best_fitness > 0.68:
            print("✅ SUCCESS: Excellent fitness achieved!")
        else:
            print("✅ COMPLETE: Good results, consider longer evolution for higher fitness")
        
        print()
        print("Next: Generate final comparison across all passes")
        
    except Exception as e:
        print(f"❌ ERROR: {e}")
        print()
        print("If memory error, try streaming_evolution.py instead")
        raise

if __name__ == "__main__":
    run_massive_scale()
