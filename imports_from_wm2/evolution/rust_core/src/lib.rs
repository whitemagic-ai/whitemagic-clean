/*!
Rust Parallel Evolution Core for WM2 HyperEvolution Engine

High-performance parallel evolution engine using Rayon for data parallelism.
Designed to process millions of lineages per second.

Key optimizations:
- SIMD-friendly data structures
- Lock-free parallel evaluation
- Memory-efficient genome representation
- Zero-copy serialization where possible
*/

use pyo3::prelude::*;
use rayon::prelude::*;
use rand::prelude::*;
use serde::{Deserialize, Serialize};
use std::sync::atomic::{AtomicU64, Ordering};
use parking_lot::RwLock;

mod genome;
mod fitness;
mod operators;
mod population;

pub use genome::{Gene, Genome, GeneCategory};
pub use fitness::{FitnessVector, FitnessEvaluator};
pub use operators::{mutate, crossover, select_tournament};
pub use population::Population;

/// Evolution configuration
#[derive(Debug, Clone, Serialize, Deserialize)]
#[pyclass]
pub struct EvolutionConfig {
    #[pyo3(get, set)]
    pub population_size: usize,
    #[pyo3(get, set)]
    pub num_generations: usize,
    #[pyo3(get, set)]
    pub mutation_rate: f64,
    #[pyo3(get, set)]
    pub crossover_rate: f64,
    #[pyo3(get, set)]
    pub selection_pressure: f64,
    #[pyo3(get, set)]
    pub elitism_rate: f64,
    #[pyo3(get, set)]
    pub tournament_size: usize,
}

#[pymethods]
impl EvolutionConfig {
    #[new]
    pub fn new(
        population_size: usize,
        num_generations: usize,
        mutation_rate: f64,
        crossover_rate: f64,
        selection_pressure: f64,
        elitism_rate: f64,
    ) -> Self {
        Self {
            population_size,
            num_generations,
            mutation_rate,
            crossover_rate,
            selection_pressure,
            elitism_rate,
            tournament_size: 5,
        }
    }
}

/// Evolution metrics tracked during run
#[derive(Debug, Clone, Serialize, Deserialize)]
#[pyclass]
pub struct EvolutionMetrics {
    #[pyo3(get)]
    pub total_lineages_simulated: u64,
    #[pyo3(get)]
    pub generations_completed: usize,
    #[pyo3(get)]
    pub best_fitness: f64,
    #[pyo3(get)]
    pub average_fitness: f64,
    #[pyo3(get)]
    pub diversity: f64,
    #[pyo3(get)]
    pub throughput_lineages_per_sec: f64,
    #[pyo3(get)]
    pub duration_seconds: f64,
}

#[pymethods]
impl EvolutionMetrics {
    fn to_dict(&self) -> PyResult<String> {
        Ok(serde_json::to_string(self).unwrap())
    }
}

/// Main parallel evolution engine
#[pyclass]
pub struct HyperEvolutionCore {
    config: EvolutionConfig,
    population: Population,
    evaluator: FitnessEvaluator,
    generation: usize,
    lineages_simulated: AtomicU64,
    best_genome: RwLock<Option<Genome>>,
    best_fitness: RwLock<f64>,
}

#[pymethods]
impl HyperEvolutionCore {
    #[new]
    pub fn new(config: EvolutionConfig, gene_library: Vec<Gene>) -> Self {
        let population = Population::initialize(config.population_size, &gene_library);
        let evaluator = FitnessEvaluator::new();
        
        Self {
            config,
            population,
            evaluator,
            generation: 0,
            lineages_simulated: AtomicU64::new(0),
            best_genome: RwLock::new(None),
            best_fitness: RwLock::new(0.0),
        }
    }
    
    /// Run evolution for specified number of generations
    pub fn evolve(&mut self, generations: usize) -> PyResult<EvolutionMetrics> {
        let start = std::time::Instant::now();
        let initial_lineages = self.lineages_simulated.load(Ordering::Relaxed);
        
        for gen in 0..generations {
            self.generation += 1;
            
            // Parallel fitness evaluation
            self.evaluate_population();
            
            // Track best genome
            self.update_best();
            
            // Selection and reproduction
            let new_population = self.reproduce();
            
            // Replace population
            self.population = new_population;
            
            // Update lineages count
            self.lineages_simulated.fetch_add(
                self.config.population_size as u64,
                Ordering::Relaxed
            );
            
            // Progress logging every 10 generations
            if gen % 10 == 0 {
                let best = *self.best_fitness.read();
                let avg = self.population.average_fitness();
                let div = self.population.diversity();
                println!("Gen {}: best={:.3}, avg={:.3}, div={:.3}", 
                    self.generation, best, avg, div);
            }
        }
        
        let duration = start.elapsed().as_secs_f64();
        let total_lineages = self.lineages_simulated.load(Ordering::Relaxed);
        let lineages_this_run = total_lineages - initial_lineages;
        
        Ok(EvolutionMetrics {
            total_lineages_simulated: total_lineages,
            generations_completed: generations,
            best_fitness: *self.best_fitness.read(),
            average_fitness: self.population.average_fitness(),
            diversity: self.population.diversity(),
            throughput_lineages_per_sec: lineages_this_run as f64 / duration,
            duration_seconds: duration,
        })
    }
    
    /// Get the best genome found so far
    pub fn get_best_genome(&self) -> PyResult<Option<Genome>> {
        Ok(self.best_genome.read().clone())
    }
    
    /// Get current population size
    pub fn population_size(&self) -> usize {
        self.population.size()
    }
    
    /// Get current generation
    pub fn current_generation(&self) -> usize {
        self.generation
    }
}

impl HyperEvolutionCore {
    /// Evaluate fitness for entire population in parallel
    fn evaluate_population(&mut self) {
        self.population.genomes.par_iter_mut().for_each(|genome| {
            genome.fitness = self.evaluator.evaluate(genome);
        });
    }
    
    /// Update best genome tracker
    fn update_best(&self) {
        if let Some(best_in_pop) = self.population.get_best() {
            let mut best_fitness = self.best_fitness.write();
            if best_in_pop.fitness > *best_fitness {
                *best_fitness = best_in_pop.fitness;
                *self.best_genome.write() = Some(best_in_pop.clone());
            }
        }
    }
    
    /// Reproduce population using selection, crossover, and mutation
    fn reproduce(&self) -> Population {
        let elite_count = (self.config.population_size as f64 * self.config.elitism_rate) as usize;
        let offspring_count = self.config.population_size - elite_count;
        
        // Get elites
        let mut elites = self.population.get_top_n(elite_count);
        
        // Generate offspring in parallel
        let offspring: Vec<Genome> = (0..offspring_count)
            .into_par_iter()
            .map(|_| {
                let mut rng = thread_rng();
                
                // Tournament selection for parents
                let parent1 = select_tournament(
                    &self.population.genomes,
                    self.config.tournament_size,
                    &mut rng
                );
                let parent2 = select_tournament(
                    &self.population.genomes,
                    self.config.tournament_size,
                    &mut rng
                );
                
                // Crossover
                let mut child = if rng.gen::<f64>() < self.config.crossover_rate {
                    crossover(parent1, parent2, &mut rng)
                } else {
                    parent1.clone()
                };
                
                // Mutation
                if rng.gen::<f64>() < self.config.mutation_rate {
                    mutate(&mut child, &mut rng);
                }
                
                child
            })
            .collect();
        
        // Combine elites and offspring
        elites.extend(offspring);
        
        Population::from_genomes(elites)
    }
}

/// Python module initialization
#[pymodule]
fn hyperevolution_core(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_class::<Gene>()?;
    m.add_class::<Genome>()?;
    m.add_class::<GeneCategory>()?;
    m.add_class::<FitnessVector>()?;
    m.add_class::<EvolutionConfig>()?;
    m.add_class::<EvolutionMetrics>()?;
    m.add_class::<HyperEvolutionCore>()?;
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;
    
    #[test]
    fn test_evolution_basic() {
        let config = EvolutionConfig::new(
            1000,   // population
            10,     // generations
            0.15,   // mutation rate
            0.7,    // crossover rate
            0.2,    // selection pressure
            0.01,   // elitism rate
        );
        
        let gene_library = vec![
            Gene::new("test_gene".to_string(), GeneCategory::Optimization, 0.5),
        ];
        
        let mut engine = HyperEvolutionCore::new(config, gene_library);
        let metrics = engine.evolve(10).unwrap();
        
        assert_eq!(metrics.generations_completed, 10);
        assert!(metrics.total_lineages_simulated >= 10000);
        assert!(metrics.throughput_lineages_per_sec > 0.0);
    }
}
