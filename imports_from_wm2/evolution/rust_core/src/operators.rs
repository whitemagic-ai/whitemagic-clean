/*!
Genetic operators: mutation, crossover, selection
*/

use crate::genome::Genome;
use rand::prelude::*;

/// Mutate a genome
pub fn mutate(genome: &mut Genome, rng: &mut impl Rng) {
    if genome.genes.is_empty() {
        return;
    }
    
    // Choose mutation type
    let mutation_type = rng.gen_range(0..4);
    
    match mutation_type {
        0 => mutate_expression(genome, rng),
        1 => mutate_add_gene(genome, rng),
        2 => mutate_remove_gene(genome, rng),
        _ => mutate_swap_genes(genome, rng),
    }
}

/// Mutate gene expression levels
fn mutate_expression(genome: &mut Genome, rng: &mut impl Rng) {
    let idx = rng.gen_range(0..genome.genes.len());
    genome.genes[idx].mutate_expression(rng);
}

/// Add a random gene (duplicate existing)
fn mutate_add_gene(genome: &mut Genome, rng: &mut impl Rng) {
    if genome.genes.len() >= 100 {
        return; // Max size
    }
    
    let idx = rng.gen_range(0..genome.genes.len());
    let mut new_gene = genome.genes[idx].clone();
    new_gene.expression_level = rng.gen_range(0.1..=1.0);
    genome.genes.push(new_gene);
}

/// Remove a random gene
fn mutate_remove_gene(genome: &mut Genome, rng: &mut impl Rng) {
    if genome.genes.len() <= 20 {
        return; // Min size
    }
    
    let idx = rng.gen_range(0..genome.genes.len());
    genome.genes.remove(idx);
}

/// Swap two genes
fn mutate_swap_genes(genome: &mut Genome, rng: &mut impl Rng) {
    if genome.genes.len() < 2 {
        return;
    }
    
    let idx1 = rng.gen_range(0..genome.genes.len());
    let idx2 = rng.gen_range(0..genome.genes.len());
    genome.genes.swap(idx1, idx2);
}

/// Multi-point crossover
pub fn crossover(parent1: &Genome, parent2: &Genome, rng: &mut impl Rng) -> Genome {
    let min_len = parent1.genes.len().min(parent2.genes.len());
    let max_len = parent1.genes.len().max(parent2.genes.len());
    
    if min_len == 0 {
        return parent1.clone();
    }
    
    // Determine child size (between parents)
    let child_size = rng.gen_range(min_len..=max_len);
    
    // Multi-point crossover (2-3 crossover points)
    let num_points = rng.gen_range(2..=3);
    let mut crossover_points: Vec<usize> = (0..num_points)
        .map(|_| rng.gen_range(0..min_len))
        .collect();
    crossover_points.sort();
    
    let mut child_genes = Vec::with_capacity(child_size);
    let mut use_parent1 = true;
    let mut point_idx = 0;
    
    for i in 0..child_size {
        // Switch parent at crossover points
        if point_idx < crossover_points.len() && i >= crossover_points[point_idx] {
            use_parent1 = !use_parent1;
            point_idx += 1;
        }
        
        // Select gene from appropriate parent
        let gene = if use_parent1 {
            if i < parent1.genes.len() {
                parent1.genes[i].clone()
            } else {
                parent2.genes[i % parent2.genes.len()].clone()
            }
        } else {
            if i < parent2.genes.len() {
                parent2.genes[i].clone()
            } else {
                parent1.genes[i % parent1.genes.len()].clone()
            }
        };
        
        child_genes.push(gene);
    }
    
    Genome::new(
        format!("child_{}", rng.gen::<u64>()),
        parent1.generation.max(parent2.generation) + 1,
        child_genes,
    )
}

/// Tournament selection
pub fn select_tournament<'a>(
    population: &'a [Genome],
    tournament_size: usize,
    rng: &mut impl Rng,
) -> &'a Genome {
    let mut best: Option<&Genome> = None;
    let mut best_fitness = f64::NEG_INFINITY;
    
    for _ in 0..tournament_size {
        let idx = rng.gen_range(0..population.len());
        let candidate = &population[idx];
        
        if candidate.fitness > best_fitness {
            best_fitness = candidate.fitness;
            best = Some(candidate);
        }
    }
    
    best.unwrap_or(&population[0])
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::genome::GeneCategory;
    
    #[test]
    fn test_mutation() {
        let mut rng = thread_rng();
        let genes = vec![
            Gene::new("gene1".to_string(), GeneCategory::Architecture, 0.5),
            Gene::new("gene2".to_string(), GeneCategory::Feature, 0.5),
        ];
        
        let mut genome = Genome::new("test".to_string(), 0, genes);
        let original_len = genome.genes.len();
        
        mutate(&mut genome, &mut rng);
        
        // Genome should still be valid
        assert!(genome.genes.len() >= 2); // Min size
        assert!(genome.genes.len() <= 100); // Max size
    }
    
    #[test]
    fn test_crossover() {
        let mut rng = thread_rng();
        
        let genes1 = vec![
            Gene::new("gene1".to_string(), GeneCategory::Architecture, 0.5),
            Gene::new("gene2".to_string(), GeneCategory::Feature, 0.5),
        ];
        let genes2 = vec![
            Gene::new("gene3".to_string(), GeneCategory::Optimization, 0.5),
            Gene::new("gene4".to_string(), GeneCategory::Biological, 0.5),
        ];
        
        let parent1 = Genome::new("p1".to_string(), 0, genes1);
        let parent2 = Genome::new("p2".to_string(), 0, genes2);
        
        let child = crossover(&parent1, &parent2, &mut rng);
        
        assert!(child.genes.len() >= 2);
        assert_eq!(child.generation, 1);
    }
}
