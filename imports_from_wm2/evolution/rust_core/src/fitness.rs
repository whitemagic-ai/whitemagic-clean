/*!
Multi-dimensional fitness evaluation
*/

use pyo3::prelude::*;
use serde::{Deserialize, Serialize};
use crate::genome::Genome;

/// 8-dimensional fitness vector
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[pyclass]
pub struct FitnessVector {
    #[pyo3(get, set)]
    pub performance: f64,
    #[pyo3(get, set)]
    pub correctness: f64,
    #[pyo3(get, set)]
    pub maintainability: f64,
    #[pyo3(get, set)]
    pub scalability: f64,
    #[pyo3(get, set)]
    pub robustness: f64,
    #[pyo3(get, set)]
    pub innovation: f64,
    #[pyo3(get, set)]
    pub integration: f64,
    #[pyo3(get, set)]
    pub elegance: f64,
}

#[pymethods]
impl FitnessVector {
    #[new]
    pub fn new(
        performance: f64,
        correctness: f64,
        maintainability: f64,
        scalability: f64,
        robustness: f64,
        innovation: f64,
        integration: f64,
        elegance: f64,
    ) -> Self {
        Self {
            performance,
            correctness,
            maintainability,
            scalability,
            robustness,
            innovation,
            integration,
            elegance,
        }
    }
    
    /// Aggregate fitness score (weighted average)
    pub fn aggregate(&self) -> f64 {
        (self.performance * 0.15 +
         self.correctness * 0.20 +
         self.maintainability * 0.10 +
         self.scalability * 0.15 +
         self.robustness * 0.15 +
         self.innovation * 0.10 +
         self.integration * 0.10 +
         self.elegance * 0.05)
    }
    
    fn __repr__(&self) -> String {
        format!("FitnessVector(agg={:.3}, perf={:.2}, corr={:.2})", 
            self.aggregate(), self.performance, self.correctness)
    }
}

impl Default for FitnessVector {
    fn default() -> Self {
        Self {
            performance: 0.5,
            correctness: 0.5,
            maintainability: 0.5,
            scalability: 0.5,
            robustness: 0.5,
            innovation: 0.5,
            integration: 0.5,
            elegance: 0.5,
        }
    }
}

/// Fitness evaluator
pub struct FitnessEvaluator {
    // Could hold cached data, models, etc.
}

impl FitnessEvaluator {
    pub fn new() -> Self {
        Self {}
    }
    
    /// Evaluate a genome's fitness
    pub fn evaluate(&self, genome: &Genome) -> f64 {
        let vector = self.evaluate_vector(genome);
        vector.aggregate()
    }
    
    /// Evaluate full fitness vector
    pub fn evaluate_vector(&self, genome: &Genome) -> FitnessVector {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        
        // Performance: based on optimization genes
        let opt_genes = genome.genes.iter()
            .filter(|g| matches!(g.category, crate::genome::GeneCategory::Optimization))
            .count();
        let performance = (opt_genes as f64 / genome.genes.len() as f64) * 0.5 + 0.3;
        
        // Correctness: based on gene expression consistency
        let avg_expression: f64 = genome.genes.iter()
            .map(|g| g.expression_level)
            .sum::<f64>() / genome.genes.len() as f64;
        let correctness = avg_expression * 0.6 + 0.2;
        
        // Maintainability: inversely proportional to genome size
        let size_factor = 1.0 - (genome.genes.len() as f64 - 20.0) / 80.0;
        let maintainability = size_factor * 0.5 + 0.3;
        
        // Scalability: based on architecture genes
        let arch_genes = genome.genes.iter()
            .filter(|g| matches!(g.category, crate::genome::GeneCategory::Architecture))
            .count();
        let scalability = (arch_genes as f64 / genome.genes.len() as f64) * 0.6 + 0.2;
        
        // Robustness: based on diversity of gene categories
        let categories: std::collections::HashSet<_> = 
            genome.genes.iter().map(|g| g.category).collect();
        let robustness = (categories.len() as f64 / 6.0) * 0.5 + 0.3;
        
        // Innovation: based on feature and intelligence genes
        let innovative_genes = genome.genes.iter()
            .filter(|g| matches!(g.category, 
                crate::genome::GeneCategory::Feature | 
                crate::genome::GeneCategory::Intelligence))
            .count();
        let innovation = (innovative_genes as f64 / genome.genes.len() as f64) * 0.6 + 0.2;
        
        // Integration: based on biological genes
        let bio_genes = genome.genes.iter()
            .filter(|g| matches!(g.category, crate::genome::GeneCategory::Biological))
            .count();
        let integration = (bio_genes as f64 / genome.genes.len() as f64) * 0.5 + 0.3;
        
        // Elegance: inversely proportional to complexity
        let elegance = (1.0 - (genome.genes.len() as f64 / 100.0)) * 0.5 + 0.3;
        
        // Add stochastic noise (±0.1) to each dimension
        FitnessVector {
            performance: (performance + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            correctness: (correctness + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            maintainability: (maintainability + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            scalability: (scalability + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            robustness: (robustness + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            innovation: (innovation + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            integration: (integration + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
            elegance: (elegance + rng.gen_range(-0.1..=0.1)).clamp(0.0, 1.0),
        }
    }
}

impl Default for FitnessEvaluator {
    fn default() -> Self {
        Self::new()
    }
}
