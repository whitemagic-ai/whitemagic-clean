#!/usr/bin/env python3
"""
Option C: Parameter Optimization via Grid Search

Find optimal parameters through systematic testing.
"""

import hyperevolution_core as rust
import time
import json
from dataclasses import dataclass, asdict
from typing import List, Tuple
import itertools

@dataclass
class ParameterTest:
    mutation_rate: float
    selection_pressure: float
    elitism_rate: float
    best_fitness: float
    avg_fitness: float
    diversity: float
    throughput: float
    duration: float

class ParameterOptimizer:
    def __init__(self):
        self.gene_library = self._create_gene_library()
        self.results: List[ParameterTest] = []
        
    def _create_gene_library(self):
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
        return genes
    
    def test_parameters(
        self,
        mutation_rate: float,
        selection_pressure: float,
        elitism_rate: float,
        population: int = 100_000,
        generations: int = 100
    ) -> ParameterTest:
        """Test a specific parameter combination"""
        
        config = rust.EvolutionConfig(
            population,
            generations,
            mutation_rate,
            0.7,  # crossover_rate (keep constant)
            selection_pressure,
            elitism_rate,
        )
        
        engine = rust.HyperEvolutionCore(config, self.gene_library)
        
        start = time.time()
        metrics = engine.evolve(generations)
        duration = time.time() - start
        
        result = ParameterTest(
            mutation_rate=mutation_rate,
            selection_pressure=selection_pressure,
            elitism_rate=elitism_rate,
            best_fitness=metrics.best_fitness,
            avg_fitness=metrics.average_fitness,
            diversity=metrics.diversity,
            throughput=metrics.throughput_lineages_per_sec,
            duration=duration,
        )
        
        self.results.append(result)
        return result
    
    def grid_search(
        self,
        mutation_rates: List[float],
        selection_pressures: List[float],
        elitism_rates: List[float],
        sample_size: int = 9
    ):
        """Run grid search over parameter space"""
        
        print("=" * 80)
        print("PARAMETER OPTIMIZATION - GRID SEARCH")
        print("=" * 80)
        print()
        
        # Generate all combinations
        all_combinations = list(itertools.product(
            mutation_rates,
            selection_pressures,
            elitism_rates
        ))
        
        print(f"Total combinations: {len(all_combinations)}")
        print(f"Testing: {min(sample_size, len(all_combinations))} combinations")
        print()
        
        # Sample if needed
        import random
        if len(all_combinations) > sample_size:
            combinations = random.sample(all_combinations, sample_size)
        else:
            combinations = all_combinations
        
        # Test each combination
        for idx, (mut, sel, eli) in enumerate(combinations, 1):
            print(f"🧪 Test {idx}/{len(combinations)}: "
                  f"mut={mut:.2f}, sel={sel:.2f}, eli={eli:.2f}")
            
            result = self.test_parameters(mut, sel, eli)
            
            print(f"   fitness={result.best_fitness:.4f}, "
                  f"diversity={result.diversity:.2%}, "
                  f"throughput={result.throughput:,.0f}/s, "
                  f"duration={result.duration:.1f}s")
            print()
    
    def find_best(self) -> Tuple[ParameterTest, str]:
        """Find best parameter combination"""
        
        if not self.results:
            return None, "No results"
        
        # Find best by different criteria
        best_fitness = max(self.results, key=lambda r: r.best_fitness)
        best_diversity = max(self.results, key=lambda r: r.diversity)
        best_throughput = max(self.results, key=lambda r: r.throughput)
        
        # Composite score: fitness (60%) + diversity (20%) + throughput (20%)
        def composite_score(r: ParameterTest) -> float:
            norm_fitness = r.best_fitness / max(x.best_fitness for x in self.results)
            norm_diversity = r.diversity / max(x.diversity for x in self.results)
            norm_throughput = r.throughput / max(x.throughput for x in self.results)
            return norm_fitness * 0.6 + norm_diversity * 0.2 + norm_throughput * 0.2
        
        best_composite = max(self.results, key=composite_score)
        
        return best_composite, "composite_score"
    
    def generate_report(self):
        """Generate comprehensive report"""
        
        print()
        print("=" * 80)
        print("PARAMETER OPTIMIZATION REPORT")
        print("=" * 80)
        print()
        
        if not self.results:
            print("No results to report")
            return
        
        print(f"Total tests: {len(self.results)}")
        print()
        
        # Best by each metric
        best_fitness = max(self.results, key=lambda r: r.best_fitness)
        best_diversity = max(self.results, key=lambda r: r.diversity)
        best_throughput = max(self.results, key=lambda r: r.throughput)
        
        print("🏆 BEST BY METRIC:")
        print()
        print(f"Best Fitness: {best_fitness.best_fitness:.4f}")
        print(f"  Parameters: mut={best_fitness.mutation_rate:.2f}, "
              f"sel={best_fitness.selection_pressure:.2f}, "
              f"eli={best_fitness.elitism_rate:.2f}")
        print()
        
        print(f"Best Diversity: {best_diversity.diversity:.2%}")
        print(f"  Parameters: mut={best_diversity.mutation_rate:.2f}, "
              f"sel={best_diversity.selection_pressure:.2f}, "
              f"eli={best_diversity.elitism_rate:.2f}")
        print()
        
        print(f"Best Throughput: {best_throughput.throughput:,.0f}/s")
        print(f"  Parameters: mut={best_throughput.mutation_rate:.2f}, "
              f"sel={best_throughput.selection_pressure:.2f}, "
              f"eli={best_throughput.elitism_rate:.2f}")
        print()
        
        # Composite best
        best_composite, _ = self.find_best()
        print("🎯 RECOMMENDED (Composite Score):")
        print(f"  Mutation Rate: {best_composite.mutation_rate:.2f}")
        print(f"  Selection Pressure: {best_composite.selection_pressure:.2f}")
        print(f"  Elitism Rate: {best_composite.elitism_rate:.2f}")
        print()
        print(f"  Expected Fitness: {best_composite.best_fitness:.4f}")
        print(f"  Expected Diversity: {best_composite.diversity:.2%}")
        print(f"  Expected Throughput: {best_composite.throughput:,.0f}/s")
        print()
        
        # Compare to baseline (0.18, 0.25, 0.02)
        baseline_params = (0.18, 0.25, 0.02)
        baseline_results = [r for r in self.results 
                          if (r.mutation_rate, r.selection_pressure, r.elitism_rate) == baseline_params]
        
        if baseline_results:
            baseline = baseline_results[0]
            fitness_improvement = ((best_composite.best_fitness / baseline.best_fitness) - 1) * 100
            diversity_improvement = ((best_composite.diversity / baseline.diversity) - 1) * 100
            
            print("📊 IMPROVEMENT OVER BASELINE:")
            print(f"  Fitness: {fitness_improvement:+.2f}%")
            print(f"  Diversity: {diversity_improvement:+.2f}%")
            print()
    
    def save_results(self, filename: str = "parameter_optimization_results.json"):
        """Save all results"""
        
        best_composite, _ = self.find_best()
        
        data = {
            "total_tests": len(self.results),
            "best_parameters": {
                "mutation_rate": best_composite.mutation_rate,
                "selection_pressure": best_composite.selection_pressure,
                "elitism_rate": best_composite.elitism_rate,
                "crossover_rate": 0.7,
            },
            "expected_performance": {
                "best_fitness": best_composite.best_fitness,
                "diversity": best_composite.diversity,
                "throughput": best_composite.throughput,
            },
            "all_results": [asdict(r) for r in self.results]
        }
        
        with open(filename, 'w') as f:
            json.dump(data, f, indent=2)
        
        print(f"💾 Results saved to {filename}")


if __name__ == "__main__":
    print("=" * 80)
    print("OPTION C: PARAMETER OPTIMIZATION")
    print("=" * 80)
    print()
    
    optimizer = ParameterOptimizer()
    
    # Define parameter ranges
    mutation_rates = [0.16, 0.18, 0.20]
    selection_pressures = [0.23, 0.25, 0.27]
    elitism_rates = [0.01, 0.02, 0.03]
    
    print("Parameter ranges:")
    print(f"  Mutation rates: {mutation_rates}")
    print(f"  Selection pressures: {selection_pressures}")
    print(f"  Elitism rates: {elitism_rates}")
    print(f"  Total combinations: {len(mutation_rates) * len(selection_pressures) * len(elitism_rates)}")
    print()
    
    # Run grid search (sample 9 combinations)
    optimizer.grid_search(
        mutation_rates=mutation_rates,
        selection_pressures=selection_pressures,
        elitism_rates=elitism_rates,
        sample_size=9
    )
    
    # Generate report
    optimizer.generate_report()
    
    # Save results
    optimizer.save_results()
    
    print()
    print("✅ PARAMETER OPTIMIZATION COMPLETE")
    print()
    print("Next: Run Option B with optimized parameters")
