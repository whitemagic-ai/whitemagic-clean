// Standalone Rust runner for massive scale evolution
// Safer than Python for large populations - no GIL, better memory management

use hyperevolution_core::{
    EvolutionConfig, HyperEvolutionCore, Gene, GeneCategory,
};
use std::time::Instant;
use std::fs;

fn load_gene_library() -> Vec<Gene> {
    // Load from JSON file
    let json_str = fs::read_to_string("../gene_library_seed_vault.json")
        .expect("Failed to read gene library");
    
    let library: serde_json::Value = serde_json::from_str(&json_str)
        .expect("Failed to parse gene library");
    
    let mut genes = Vec::new();
    
    if let Some(gene_array) = library["genes"].as_array() {
        for gene_obj in gene_array {
            let name = gene_obj["name"].as_str().unwrap_or("unknown");
            let category_str = gene_obj["category"].as_str().unwrap_or("Feature");
            let value = gene_obj["value"].as_f64().unwrap_or(0.5) as f32;
            
            let category = match category_str {
                "Architecture" => GeneCategory::Architecture,
                "Optimization" => GeneCategory::Optimization,
                "Biological" => GeneCategory::Biological,
                "Intelligence" => GeneCategory::Intelligence,
                "Polyglot" => GeneCategory::Polyglot,
                _ => GeneCategory::Feature,
            };
            
            genes.push(Gene::new(name.to_string(), category, value as f64));
        }
    }
    
    println!("✅ Loaded {} genes from seed vault", genes.len());
    genes
}

fn main() {
    println!("================================================================================");
    println!("RUST MASSIVE SCALE EVOLUTION - OPTION B");
    println!("================================================================================");
    println!();
    
    // Configuration from Option C optimal parameters
    let population = 500_000;
    let generations = 200;
    let mutation_rate = 0.20;
    let crossover_rate = 0.7;
    let selection_pressure = 0.25;
    let elitism_rate = 0.02;
    
    println!("Configuration:");
    println!("  Population: {}", population);
    println!("  Generations: {}", generations);
    println!("  Mutation rate: {}", mutation_rate);
    println!("  Selection pressure: {}", selection_pressure);
    println!("  Elitism rate: {}", elitism_rate);
    println!();
    
    // Load real gene library
    println!("📚 Loading gene library from WhiteMagic codebase...");
    let genes = load_gene_library();
    println!();
    
    // Create config
    let config = EvolutionConfig::new(
        population,
        generations,
        mutation_rate,
        crossover_rate,
        selection_pressure,
        elitism_rate,
    );
    
    // Create engine
    println!("🔧 Initializing evolution engine...");
    let mut engine = HyperEvolutionCore::new(config, genes);
    println!("   ✅ Engine ready");
    println!();
    
    // Run evolution
    println!("🚀 Starting evolution...");
    println!("================================================================================");
    println!();
    
    let start = Instant::now();
    let result = engine.evolve(generations);
    let duration = start.elapsed();
    
    // Handle Result
    let metrics = match result {
        Ok(m) => m,
        Err(e) => {
            eprintln!("❌ Evolution failed: {:?}", e);
            std::process::exit(1);
        }
    };
    
    println!();
    println!("================================================================================");
    println!("✅ EVOLUTION COMPLETE");
    println!("================================================================================");
    println!();
    
    // Display results
    println!("📊 RESULTS:");
    println!("   Best fitness: {:.4}", metrics.best_fitness);
    println!("   Average fitness: {:.4}", metrics.average_fitness);
    println!("   Diversity: {:.2}%", metrics.diversity * 100.0);
    println!("   Throughput: {:.0} lineages/sec", metrics.throughput_lineages_per_sec);
    println!("   Duration: {:.1}s ({:.1} minutes)", duration.as_secs_f64(), duration.as_secs_f64() / 60.0);
    println!("   Total lineages: {}", metrics.total_lineages_simulated);
    println!();
    
    // Save results
    let results = serde_json::json!({
        "population": population,
        "generations": generations,
        "total_simulations": population * generations,
        "mutation_rate": mutation_rate,
        "selection_pressure": selection_pressure,
        "elitism_rate": elitism_rate,
        "crossover_rate": crossover_rate,
        "best_fitness": metrics.best_fitness,
        "avg_fitness": metrics.average_fitness,
        "diversity": metrics.diversity,
        "throughput": metrics.throughput_lineages_per_sec,
        "duration_seconds": duration.as_secs_f64(),
        "generations_completed": metrics.generations_completed,
    });
    
    fs::write("../option_b_rust_results.json", serde_json::to_string_pretty(&results).unwrap())
        .expect("Failed to write results");
    
    println!("💾 Results saved to option_b_rust_results.json");
    println!();
    
    // Compare to third pass
    let third_pass_fitness = 0.6816;
    let improvement = ((metrics.best_fitness / third_pass_fitness) - 1.0) * 100.0;
    
    println!("📈 COMPARISON TO THIRD PASS:");
    println!("   Third pass fitness: {:.4}", third_pass_fitness);
    println!("   Option B fitness: {:.4}", metrics.best_fitness);
    println!("   Improvement: {:+.2}%", improvement);
    println!();
    
    if metrics.best_fitness > 0.69 {
        println!("🏆 VICTORY: Fitness target exceeded!");
    } else if metrics.best_fitness > 0.68 {
        println!("✅ SUCCESS: Excellent fitness achieved!");
    } else {
        println!("✅ COMPLETE: Good results!");
    }
}
