/*!
Genome representation and gene structures
*/

use pyo3::prelude::*;
use serde::{Deserialize, Serialize};
use rand::prelude::*;
use std::collections::HashMap;

/// Gene category classification
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Serialize, Deserialize)]
#[pyclass]
pub enum GeneCategory {
    Architecture,
    Feature,
    Optimization,
    Biological,
    Intelligence,
    Polyglot,
}

#[pymethods]
impl GeneCategory {
    fn __repr__(&self) -> String {
        format!("{:?}", self)
    }
}

/// A single gene in the genome
#[derive(Debug, Clone, Serialize, Deserialize)]
#[pyclass]
pub struct Gene {
    #[pyo3(get, set)]
    pub name: String,
    #[pyo3(get, set)]
    pub category: GeneCategory,
    #[pyo3(get, set)]
    pub expression_level: f64,  // 0.0 to 1.0
    #[pyo3(get, set)]
    pub allele: String,
}

#[pymethods]
impl Gene {
    #[new]
    pub fn new(name: String, category: GeneCategory, expression_level: f64) -> Self {
        Self {
            name: name.clone(),
            category,
            expression_level: expression_level.clamp(0.0, 1.0),
            allele: "default".to_string(),
        }
    }
    
    fn __repr__(&self) -> String {
        format!("Gene({}, {:?}, {:.2})", self.name, self.category, self.expression_level)
    }
}

impl Gene {
    /// Create a random gene from a template
    pub fn random_from_template(template: &Gene, rng: &mut impl Rng) -> Self {
        Self {
            name: template.name.clone(),
            category: template.category,
            expression_level: rng.gen_range(0.1..=1.0),
            allele: template.allele.clone(),
        }
    }
    
    /// Mutate the gene's expression level
    pub fn mutate_expression(&mut self, rng: &mut impl Rng) {
        let delta = rng.gen_range(-0.2..=0.2);
        self.expression_level = (self.expression_level + delta).clamp(0.1, 1.0);
    }
}

/// Complete genome representing a WhiteMagic configuration
#[derive(Debug, Clone, Serialize, Deserialize)]
#[pyclass]
pub struct Genome {
    #[pyo3(get, set)]
    pub genome_id: String,
    #[pyo3(get, set)]
    pub generation: usize,
    #[pyo3(get)]
    pub genes: Vec<Gene>,
    #[pyo3(get, set)]
    pub fitness: f64,
    #[pyo3(get, set)]
    pub epigenetic_marks: HashMap<String, f64>,
}

#[pymethods]
impl Genome {
    #[new]
    pub fn new(genome_id: String, generation: usize, genes: Vec<Gene>) -> Self {
        Self {
            genome_id,
            generation,
            genes,
            fitness: 0.0,
            epigenetic_marks: HashMap::new(),
        }
    }
    
    /// Get number of genes
    pub fn gene_count(&self) -> usize {
        self.genes.len()
    }
    
    /// Get genes by category
    pub fn genes_by_category(&self, category: GeneCategory) -> Vec<Gene> {
        self.genes.iter()
            .filter(|g| g.category == category)
            .cloned()
            .collect()
    }
    
    fn __repr__(&self) -> String {
        format!("Genome({}, gen={}, genes={}, fitness={:.3})", 
            &self.genome_id[..8], self.generation, self.genes.len(), self.fitness)
    }
}

impl Genome {
    /// Create a random genome from gene library
    pub fn random(
        genome_id: String,
        generation: usize,
        gene_library: &[Gene],
        rng: &mut impl Rng,
    ) -> Self {
        // Random genome size between 20-100 genes
        let num_genes = rng.gen_range(20..=100);
        
        // Randomly sample genes from library
        let mut genes = Vec::with_capacity(num_genes);
        for _ in 0..num_genes {
            let template = &gene_library[rng.gen_range(0..gene_library.len())];
            genes.push(Gene::random_from_template(template, rng));
        }
        
        Self {
            genome_id,
            generation,
            genes,
            fitness: 0.0,
            epigenetic_marks: HashMap::new(),
        }
    }
    
    /// Calculate genome signature for deduplication
    pub fn signature(&self) -> String {
        let mut sig_parts: Vec<String> = self.genes.iter()
            .map(|g| format!("{}:{:.2}", g.name, g.expression_level))
            .collect();
        sig_parts.sort();
        sig_parts.join("_")
    }
    
    /// Calculate diversity contribution
    pub fn diversity_score(&self, other: &Genome) -> f64 {
        // Jaccard distance based on gene names
        let genes1: std::collections::HashSet<_> = 
            self.genes.iter().map(|g| &g.name).collect();
        let genes2: std::collections::HashSet<_> = 
            other.genes.iter().map(|g| &g.name).collect();
        
        let intersection = genes1.intersection(&genes2).count();
        let union = genes1.union(&genes2).count();
        
        if union == 0 {
            0.0
        } else {
            1.0 - (intersection as f64 / union as f64)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    
    #[test]
    fn test_gene_creation() {
        let gene = Gene::new(
            "test_gene".to_string(),
            GeneCategory::Optimization,
            0.5
        );
        assert_eq!(gene.name, "test_gene");
        assert_eq!(gene.category, GeneCategory::Optimization);
        assert_eq!(gene.expression_level, 0.5);
    }
    
    #[test]
    fn test_genome_random() {
        let mut rng = thread_rng();
        let library = vec![
            Gene::new("gene1".to_string(), GeneCategory::Architecture, 0.5),
            Gene::new("gene2".to_string(), GeneCategory::Feature, 0.5),
        ];
        
        let genome = Genome::random(
            "test_id".to_string(),
            0,
            &library,
            &mut rng
        );
        
        assert!(genome.genes.len() >= 20);
        assert!(genome.genes.len() <= 100);
    }
}
