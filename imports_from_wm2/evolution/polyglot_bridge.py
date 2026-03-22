"""
Polyglot Bridge for HyperEvolution Engine

Integrates Rust, Mojo, Julia, and Zig components with Python orchestration.
Provides unified interface for all acceleration layers.
"""

import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any

import numpy as np

# Try to import Rust core
try:
    import hyperevolution_core as rust_core
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    print("⚠️  Rust core not available - install with: cd rust_core && maturin develop")

# Mojo and Julia will be called via subprocess for now
MOJO_AVAILABLE = Path("mojo_acceleration/fitness_accelerator.mojo").exists()
JULIA_AVAILABLE = Path("julia_analysis/statistical_analysis.jl").exists()
ZIG_AVAILABLE = Path("zig_storage/genome_storage.zig").exists()


@dataclass
class PolyglotConfig:
    """Configuration for polyglot acceleration"""
    use_rust: bool = True
    use_mojo: bool = False  # Requires Mojo installation
    use_julia: bool = True
    use_zig: bool = False   # Requires Zig compilation
    rust_threads: int = 0   # 0 = auto-detect
    mojo_batch_size: int = 10000
    julia_analysis: bool = True


class RustBridge:
    """Bridge to Rust parallel evolution core"""

    def __init__(self, config: PolyglotConfig):
        self.config = config
        self.available = RUST_AVAILABLE and config.use_rust

    def create_engine(self, evolution_config: dict[str, Any], gene_library: list[dict]) -> Any:
        """Create Rust evolution engine"""
        if not self.available:
            return None

        # Convert Python config to Rust config
        rust_config = rust_core.EvolutionConfig(
            population_size=evolution_config["population_size"],
            num_generations=evolution_config["num_generations"],
            mutation_rate=evolution_config["mutation_rate"],
            crossover_rate=evolution_config["crossover_rate"],
            selection_pressure=evolution_config["selection_pressure"],
            elitism_rate=evolution_config["elitism_rate"],
        )

        # Convert gene library
        rust_genes = []
        for gene_dict in gene_library:
            category_map = {
                "architecture": rust_core.GeneCategory.Architecture,
                "feature": rust_core.GeneCategory.Feature,
                "optimization": rust_core.GeneCategory.Optimization,
                "biological": rust_core.GeneCategory.Biological,
                "intelligence": rust_core.GeneCategory.Intelligence,
                "polyglot": rust_core.GeneCategory.Polyglot,
            }
            category = category_map.get(gene_dict["category"].lower(), rust_core.GeneCategory.Feature)

            rust_gene = rust_core.Gene(
                gene_dict["name"],
                category,
                gene_dict.get("expression_level", 0.5)
            )
            rust_genes.append(rust_gene)

        return rust_core.HyperEvolutionCore(rust_config, rust_genes)

    def run_evolution(self, engine: Any, generations: int) -> dict[str, Any]:
        """Run evolution using Rust engine"""
        if not self.available or engine is None:
            return {}

        metrics = engine.evolve(generations)

        return {
            "total_lineages_simulated": metrics.total_lineages_simulated,
            "generations_completed": metrics.generations_completed,
            "best_fitness": metrics.best_fitness,
            "average_fitness": metrics.average_fitness,
            "diversity": metrics.diversity,
            "throughput_lineages_per_sec": metrics.throughput_lineages_per_sec,
            "duration_seconds": metrics.duration_seconds,
        }

    def get_best_genome(self, engine: Any) -> dict | None:
        """Get best genome from Rust engine"""
        if not self.available or engine is None:
            return None

        genome = engine.get_best_genome()
        if genome is None:
            return None

        return {
            "genome_id": genome.genome_id,
            "generation": genome.generation,
            "fitness": genome.fitness,
            "gene_count": genome.gene_count(),
        }


class MojoBridge:
    """Bridge to Mojo fitness acceleration"""

    def __init__(self, config: PolyglotConfig):
        self.config = config
        self.available = MOJO_AVAILABLE and config.use_mojo

    def evaluate_batch(
        self,
        gene_counts: np.ndarray,
        expression_levels: np.ndarray,
    ) -> np.ndarray:
        """Evaluate fitness for batch using Mojo"""
        if not self.available:
            # Fallback to numpy
            return self._numpy_fallback(gene_counts, expression_levels)

        # TODO: Call Mojo via FFI or subprocess
        # For now, use numpy fallback
        return self._numpy_fallback(gene_counts, expression_levels)

    def _numpy_fallback(
        self,
        gene_counts: np.ndarray,
        expression_levels: np.ndarray,
    ) -> np.ndarray:
        """Numpy fallback for fitness evaluation"""
        size_factors = 1.0 - (gene_counts - 20.0) / 80.0
        maintainability = size_factors * 0.5 + 0.3
        correctness = expression_levels * 0.6 + 0.2
        elegance = (1.0 - gene_counts / 100.0) * 0.5 + 0.3

        aggregate = (
            correctness * 0.4 +
            maintainability * 0.3 +
            elegance * 0.3
        )

        return np.clip(aggregate, 0.0, 1.0)


class JuliaBridge:
    """Bridge to Julia statistical analysis"""

    def __init__(self, config: PolyglotConfig):
        self.config = config
        self.available = JULIA_AVAILABLE and config.use_julia
        self.module_path = Path("julia_analysis/statistical_analysis.jl")

    def analyze_evolution(
        self,
        fitness_history: list[float],
        diversity_history: list[float],
    ) -> dict[str, Any]:
        """Run Julia statistical analysis"""
        if not self.available:
            return self._python_fallback(fitness_history, diversity_history)

        # Create temporary data file
        data = {
            "fitness_history": fitness_history,
            "diversity_history": diversity_history,
        }

        data_file = Path("/tmp/evolution_data.json")
        with open(data_file, "w") as f:
            json.dump(data, f)

        # Call Julia script
        julia_script = f"""
        using JSON
        include("{self.module_path.absolute()}")
        using .EvolutionStatistics
        
        data = JSON.parsefile("{data_file}")
        fitness = data["fitness_history"]
        diversity = data["diversity_history"]
        
        analyzer = EvolutionAnalyzer(fitness, diversity, Matrix{{Float64}}[])
        results = analyze_run(analyzer)
        
        println(JSON.json(results))
        """

        try:
            result = subprocess.run(
                ["julia", "-e", julia_script],
                capture_output=True,
                text=True,
                timeout=30,
            )

            if result.returncode == 0:
                # Parse JSON output
                output_lines = result.stdout.strip().split('\n')
                json_line = output_lines[-1]  # Last line should be JSON
                return json.loads(json_line)
            else:
                print(f"Julia error: {result.stderr}")
                return self._python_fallback(fitness_history, diversity_history)

        except Exception as e:
            print(f"Julia execution failed: {e}")
            return self._python_fallback(fitness_history, diversity_history)

    def _python_fallback(
        self,
        fitness_history: list[float],
        diversity_history: list[float],
    ) -> dict[str, Any]:
        """Python fallback for statistical analysis"""
        if not fitness_history:
            return {}

        # Simple statistics
        fitness_trend = (fitness_history[-1] - fitness_history[0]) / len(fitness_history)

        # Find convergence (plateau detection)
        convergence_gen = len(fitness_history)
        for i in range(10, len(fitness_history)):
            window = fitness_history[i-9:i+1]
            if np.std(window) < 0.01:
                convergence_gen = i - 9
                break

        return {
            "fitness_trend": fitness_trend,
            "convergence_generation": convergence_gen,
            "improvement_rate": fitness_trend,
            "diversity_metrics": {
                "initial_diversity": diversity_history[0] if diversity_history else 0.0,
                "final_diversity": diversity_history[-1] if diversity_history else 0.0,
                "mean_diversity": np.mean(diversity_history) if diversity_history else 0.0,
            }
        }


class ZigBridge:
    """Bridge to Zig genome storage"""

    def __init__(self, config: PolyglotConfig):
        self.config = config
        self.available = ZIG_AVAILABLE and config.use_zig
        self.storage_path = Path("zig_storage/genome_storage.zig")

    def save_genomes(self, genomes: list[dict], output_file: str) -> bool:
        """Save genomes using Zig storage"""
        if not self.available:
            return self._python_fallback_save(genomes, output_file)

        # TODO: Compile and call Zig storage
        # For now, use Python fallback
        return self._python_fallback_save(genomes, output_file)

    def _python_fallback_save(self, genomes: list[dict], output_file: str) -> bool:
        """Python fallback for genome storage"""
        try:
            with open(output_file, 'w') as f:
                json.dump(genomes, f)
            return True
        except Exception as e:
            print(f"Save failed: {e}")
            return False


class PolyglotBridge:
    """
    Unified bridge for all polyglot components.
    
    Automatically selects best available implementation for each operation.
    """

    def __init__(self, config: PolyglotConfig | None = None):
        self.config = config or PolyglotConfig()

        # Initialize bridges
        self.rust = RustBridge(self.config)
        self.mojo = MojoBridge(self.config)
        self.julia = JuliaBridge(self.config)
        self.zig = ZigBridge(self.config)

        # Report availability
        self._report_availability()

    def _report_availability(self):
        """Report which components are available"""
        print("🔗 Polyglot Bridge Status:")
        print(f"   Rust:  {'✅' if self.rust.available else '❌'} (parallel evolution)")
        print(f"   Mojo:  {'✅' if self.mojo.available else '❌'} (fitness acceleration)")
        print(f"   Julia: {'✅' if self.julia.available else '❌'} (statistical analysis)")
        print(f"   Zig:   {'✅' if self.zig.available else '❌'} (genome storage)")

    def get_best_engine(self) -> str:
        """Get name of best available engine"""
        if self.rust.available:
            return "rust"
        return "python"

    def create_evolution_engine(
        self,
        evolution_config: dict[str, Any],
        gene_library: list[dict],
    ) -> Any:
        """Create evolution engine using best available implementation"""
        if self.rust.available:
            return self.rust.create_engine(evolution_config, gene_library)
        return None

    def run_evolution(
        self,
        engine: Any,
        generations: int,
    ) -> dict[str, Any]:
        """Run evolution using best available implementation"""
        if self.rust.available and engine is not None:
            return self.rust.run_evolution(engine, generations)
        return {}

    def analyze_results(
        self,
        fitness_history: list[float],
        diversity_history: list[float],
    ) -> dict[str, Any]:
        """Analyze results using Julia or Python fallback"""
        return self.julia.analyze_evolution(fitness_history, diversity_history)

    def get_capabilities(self) -> dict[str, bool]:
        """Get dictionary of available capabilities"""
        return {
            "rust_parallel_evolution": self.rust.available,
            "mojo_fitness_acceleration": self.mojo.available,
            "julia_statistical_analysis": self.julia.available,
            "zig_genome_storage": self.zig.available,
        }


# Convenience function
def create_bridge(
    use_rust: bool = True,
    use_mojo: bool = False,
    use_julia: bool = True,
    use_zig: bool = False,
) -> PolyglotBridge:
    """Create polyglot bridge with specified configuration"""
    config = PolyglotConfig(
        use_rust=use_rust,
        use_mojo=use_mojo,
        use_julia=use_julia,
        use_zig=use_zig,
    )
    return PolyglotBridge(config)


if __name__ == "__main__":
    # Test the bridge
    print("Testing Polyglot Bridge...\n")

    bridge = create_bridge()

    print("\nCapabilities:")
    for name, available in bridge.get_capabilities().items():
        status = "✅" if available else "❌"
        print(f"  {status} {name}")

    print(f"\nBest engine: {bridge.get_best_engine()}")
    print("\nPolyglot bridge ready!")
