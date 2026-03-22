/*!
Population management and utilities
*/

use crate::genome::{Gene, Genome};
use rand::prelude::*;
use rayon::prelude::*;

/// Population of genomes
pub struct Population {
    pub genomes: Vec<Genome>,
}

impl Population {
    /// Initialize random population
    pub fn initialize(size: usize, gene_library: &[Gene]) -> Self {
        let genomes: Vec<Genome> = (0..size)
            .into_par_iter()
            .map(|i| {
                let mut rng = thread_rng();
                Genome::random(
                    format!("genome_{}", i),
                    0,
                    gene_library,
                    &mut rng,
                )
            })
            .collect();
        
        Self { genomes }
    }
    
    /// Create population from existing genomes
    pub fn from_genomes(genomes: Vec<Genome>) -> Self {
        Self { genomes }
    }
    
    /// Get population size
    pub fn size(&self) -> usize {
        self.genomes.len()
    }
    
    /// Get best genome in population
    pub fn get_best(&self) -> Option<&Genome> {
        self.genomes.iter()
            .max_by(|a, b| a.fitness.partial_cmp(&b.fitness).unwrap())
    }
    
    /// Get top N genomes
    pub fn get_top_n(&self, n: usize) -> Vec<Genome> {
        let mut sorted = self.genomes.clone();
        sorted.sort_by(|a, b| b.fitness.partial_cmp(&a.fitness).unwrap());
        sorted.into_iter().take(n).collect()
    }
    
    /// Calculate average fitness
    pub fn average_fitness(&self) -> f64 {
        if self.genomes.is_empty() {
            return 0.0;
        }
        
        let sum: f64 = self.genomes.iter().map(|g| g.fitness).sum();
        sum / self.genomes.len() as f64
    }
    
    /// Calculate population diversity
    pub fn diversity(&self) -> f64 {
        if self.genomes.len() < 2 {
            return 1.0;
        }
        
        // Calculate unique genome signatures
        let signatures: std::collections::HashSet<_> = 
            self.genomes.iter().map(|g| g.signature()).collect();
        
        signatures.len() as f64 / self.genomes.len() as f64
    }
    
    /// Get fitness statistics
    pub fn fitness_stats(&self) -> (f64, f64, f64, f64) {
        if self.genomes.is_empty() {
            return (0.0, 0.0, 0.0, 0.0);
        }
        
        let fitnesses: Vec<f64> = self.genomes.iter().map(|g| g.fitness).collect();
        
        let min = fitnesses.iter().cloned().fold(f64::INFINITY, f64::min);
        let max = fitnesses.iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        let mean = fitnesses.iter().sum::<f64>() / fitnesses.len() as f64;
        
        // Calculate standard deviation
        let variance = fitnesses.iter()
            .map(|f| (f - mean).powi(2))
            .sum::<f64>() / fitnesses.len() as f64;
        let std_dev = variance.sqrt();
        
        (min, max, mean, std_dev)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::genome::GeneCategory;
    
    #[test]
    fn test_population_init() {
        let gene_library = vec![
            Gene::new("gene1".to_string(), GeneCategory::Architecture, 0.5),
            Gene::new("gene2".to_string(), GeneCategory::Feature, 0.5),
        ];
        
        let pop = Population::initialize(100, &gene_library);
        
        assert_eq!(pop.size(), 100);
        assert!(pop.diversity() > 0.5); // Should be diverse
    }
    
    #[test]
    fn test_population_stats() {
        let genes = vec![
            Gene::new("gene1".to_string(), GeneCategory::Architecture, 0.5),
        ];
        
        let mut genomes = vec![];
        for i in 0..10 {
            let mut genome = Genome::new(format!("g{}", i), 0, genes.clone());
            genome.fitness = i as f64 / 10.0;
            genomes.push(genome);
        }
        
        let pop = Population::from_genomes(genomes);
        let (min, max, mean, _std) = pop.fitness_stats();
        
        assert_eq!(min, 0.0);
        assert_eq!(max, 0.9);
        assert!((mean - 0.45).abs() < 0.01);
    }
}
