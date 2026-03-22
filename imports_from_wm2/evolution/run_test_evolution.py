#!/usr/bin/env python3
"""
Test Evolution Runner

Runs the first optimized test evolution:
- 100K lineages × 100 generations
- Reviews insights
- Generates code
- Prepares for scaled-up second pass
"""

import json
import sys
import time
from datetime import datetime
from pathlib import Path

# Add WM2 to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from evolution.hyperevolution_engine import (
    GeneLibrary,
    HyperEvolutionEngine,
)
from evolution.insights_pipeline import extract_actionable_insights
from evolution.polyglot_bridge import create_bridge


def main():
    print("=" * 80)
    print("WM2 HYPEREVOLUTION ENGINE - TEST RUN")
    print("=" * 80)
    print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    print()

    # Initialize polyglot bridge
    print("🔗 Initializing polyglot bridge...")
    bridge = create_bridge(use_rust=True, use_julia=True)
    print()

    # Configuration
    config = {
        "population_size": 100_000,
        "num_generations": 100,
        "mutation_rate": 0.15,
        "crossover_rate": 0.7,
        "selection_pressure": 0.2,
        "elitism_rate": 0.01,
    }

    print("📋 Configuration:")
    for key, value in config.items():
        print(f"   {key}: {value:,}" if isinstance(value, int) else f"   {key}: {value}")
    print()

    # Create gene library
    print("🧬 Creating gene library...")
    gene_library = GeneLibrary.create_comprehensive_library()
    print(f"   Created {len(gene_library)} genes across 6 categories")
    print()

    # Check if Rust is available
    engine_type = bridge.get_best_engine()
    print(f"🚀 Using {engine_type.upper()} engine")
    print()

    if engine_type == "rust":
        # Use Rust engine
        print("⚡ Creating Rust parallel evolution engine...")

        # Convert gene library to dict format for bridge
        gene_dicts = [
            {
                "name": gene.name,
                "category": gene.category,
                "expression_level": gene.expression_level,
            }
            for gene in gene_library
        ]

        rust_engine = bridge.create_evolution_engine(config, gene_dicts)

        if rust_engine:
            print("✅ Rust engine created")
            print()

            # Run evolution
            print("🧬 Starting evolution (100K lineages × 100 generations)...")
            print("   This may take a few minutes...")
            print()

            start_time = time.time()
            metrics = bridge.run_evolution(rust_engine, config["num_generations"])
            duration = time.time() - start_time

            print()
            print("✅ Evolution complete!")
            print()
            print("📊 Results:")
            print(f"   Total lineages: {metrics['total_lineages_simulated']:,}")
            print(f"   Generations: {metrics['generations_completed']}")
            print(f"   Best fitness: {metrics['best_fitness']:.4f}")
            print(f"   Average fitness: {metrics['average_fitness']:.4f}")
            print(f"   Final diversity: {metrics['diversity']:.2%}")
            print(f"   Throughput: {metrics['throughput_lineages_per_sec']:,.0f} lineages/sec")
            print(f"   Duration: {duration:.1f}s")
            print()

            # Get best genome
            best_genome_info = bridge.rust.get_best_genome(rust_engine)
            if best_genome_info:
                print("🏆 Best Genome:")
                print(f"   ID: {best_genome_info['genome_id']}")
                print(f"   Generation: {best_genome_info['generation']}")
                print(f"   Fitness: {best_genome_info['fitness']:.4f}")
                print(f"   Genes: {best_genome_info['gene_count']}")
                print()

            # Save metrics
            output_dir = Path("test_run_results")
            output_dir.mkdir(exist_ok=True)

            metrics_file = output_dir / "metrics.json"
            with open(metrics_file, "w") as f:
                json.dump(metrics, f, indent=2)
            print(f"💾 Metrics saved to {metrics_file}")
            print()

            print("=" * 80)
            print("TEST RUN COMPLETE")
            print("=" * 80)
            print()
            print("Next steps:")
            print("1. Review insights (coming next)")
            print("2. Generate code from best genome")
            print("3. Optimize based on learnings")
            print("4. Run improved second pass")

        else:
            print("❌ Failed to create Rust engine")
            print("   Falling back to Python implementation...")
            run_python_evolution(config, gene_library)
    else:
        # Use Python engine
        print("🐍 Using Python evolution engine...")
        run_python_evolution(config, gene_library)


def run_python_evolution(config, gene_library):
    """Run evolution using pure Python implementation"""
    print("⚡ Creating Python evolution engine...")

    engine = HyperEvolutionEngine(
        population_size=config["population_size"],
        num_generations=config["num_generations"],
        mutation_rate=config["mutation_rate"],
        crossover_rate=config["crossover_rate"],
        selection_pressure=config["selection_pressure"],
        elitism_rate=config["elitism_rate"],
    )

    # Override gene library
    engine.gene_library = gene_library

    print("✅ Engine created")
    print()

    # Run evolution
    print("🧬 Starting evolution (100K lineages × 100 generations)...")
    print("   This will take longer with Python (10-20 minutes)...")
    print("   Progress updates every 10 generations...")
    print()

    start_time = time.time()
    metrics = engine.run_evolution()
    duration = time.time() - start_time

    print()
    print("✅ Evolution complete!")
    print()
    print("📊 Results:")
    print(f"   Total lineages: {metrics.total_lineages_simulated:,}")
    print(f"   Generations: {metrics.generations_completed}")
    print(f"   Best fitness: {metrics.best_fitness.aggregate():.4f}")
    print(f"   Throughput: {metrics.throughput_lineages_per_sec:,.0f} lineages/sec")
    print(f"   Duration: {duration:.1f}s ({duration/60:.1f} min)")
    print()

    # Extract insights
    print("💡 Extracting insights...")
    insights = extract_actionable_insights(
        metrics=metrics.__dict__,
        population=engine.population,
        generation=engine.generation,
    )

    print(f"   Generated {len(insights['insights'])} insights")
    print(f"   Generated {len(insights['recommendations'])} recommendations")
    print()

    # Show top insights
    print("🔍 Top Insights:")
    for insight in insights["insights"][:3]:
        print(f"   • {insight['title']}")
        print(f"     {insight['description'][:100]}...")
    print()

    # Show top recommendations
    print("📝 Top Recommendations:")
    for rec in insights["recommendations"][:3]:
        print(f"   [{rec['priority']}] {rec['mutation_name']}")
        print(f"       {rec['description']}")
    print()

    # Generate code from best genome
    print("🔨 Generating code from best genome...")
    best = engine.get_best_genome()

    if best:
        from evolution.code_generator import generate_code_from_genome

        mutations = generate_code_from_genome(
            best,
            codebase_root=Path("/home/lucas/Desktop/whitemagicdev")
        )

        print(f"   Generated {len(mutations)} code mutations")
        print()

        # Show sample mutations
        print("📄 Sample Mutations:")
        for mutation in mutations[:3]:
            print(f"   • {mutation.mutation_type}: {mutation.target_file}")
            print(f"     Impact: {mutation.estimated_impact:.2f}")
        print()

    # Save results
    output_dir = Path("test_run_results")
    output_dir.mkdir(exist_ok=True)

    # Save insights
    insights_file = output_dir / "insights.json"
    with open(insights_file, "w") as f:
        json.dump(insights, f, indent=2)
    print(f"💾 Insights saved to {insights_file}")

    # Save summary
    summary_file = output_dir / "summary.md"
    with open(summary_file, "w") as f:
        f.write(insights["summary"])
    print(f"💾 Summary saved to {summary_file}")
    print()

    print("=" * 80)
    print("TEST RUN COMPLETE")
    print("=" * 80)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\n\n⚠️  Interrupted by user")
        sys.exit(1)
    except Exception as e:
        print(f"\n\n❌ Error: {e}")
        import traceback
        traceback.print_exc()
        sys.exit(1)
