---
name: "Evolution with Validated Fitness"
codename: "EVO005"
army: "beta"
type: "batch_transform"
priority: "P2"
clone_count: 60000
strategies: ["map_reduce", "performance_optimization"]
category: "intelligence"
phase: "week2"
source: "DEEP_ANALYSIS_GENE_EFFICIENCY.md - Phase 2"
column_size: 4
---

## Objective

Run evolution using the expanded gene vault (234+ patterns) with validated fitness function that measures actual performance instead of synthetic gene values. This breaks through the 0.67-0.68 plateau to 0.8+ fitness.

**Breakthrough**: Replace `fitness = sum(gene_values)` with `fitness = actual_speedup_from_benchmarks`

## Victory Conditions

- [ ] Load expanded gene vault (200+ patterns from AST scan)
- [ ] Evolution runs with 200K population × 100 generations
- [ ] Fitness function uses real benchmark results
- [ ] Generated code validates successfully (all 5 tiers)
- [ ] Measured speedup > 1.1x on at least one benchmark
- [ ] Best fitness > 0.70 (breaks plateau!)
- [ ] Diversity maintained > 85%
- [ ] No crashes during evolution
- [ ] Results saved with validation scores
- [ ] New patterns discovered and added to vault
- [ ] Throughput > 100K lineages/sec
- [ ] Complete in < 5 minutes

## Strategy

### Phase 1: Validated Fitness Function (15K clones)
```python
def validated_fitness(genome: Genome) -> float:
    # Generate code from genome
    code = generate_code(genome)
    
    # Validate (5 tiers)
    validation = validator.validate_all(code)
    
    if not validation['passed']:
        return 0.0  # Invalid code
    
    # Extract performance score (Tier 4)
    perf_result = validation['tier_results']['performance']
    
    if 'speedup' in perf_result.details:
        speedup = perf_result.details['speedup']
        # Convert speedup to fitness (1.5x = 0.50, 2.0x = 1.00)
        fitness = min((speedup - 1.0), 1.0)
    else:
        # No baseline, use validation score
        fitness = validation['total_score']
    
    return fitness
```

### Phase 2: Evolution Execution (25K clones)
1. Load expanded vault
2. Configure evolution with optimal parameters
3. Run with validated fitness
4. Track best genomes
5. Save results

### Phase 3: Code Generation & Validation (15K clones)
1. Generate code from top 10 genomes
2. Run full validation on each
3. Measure actual performance
4. Record speedups
5. Identify best improvements

### Phase 4: Pattern Discovery (5K clones)
1. Scan validated code with AST scanner
2. Extract new patterns
3. Add to vault
4. Track pattern effectiveness

## Verification

```python
# Run validated evolution
results = run_validated_evolution(
    vault_path='gene_vault_deep.json',
    population=200_000,
    generations=100
)

assert results['best_fitness'] > 0.70, f"Didn't break plateau: {results['best_fitness']}"
assert results['validated_code_count'] > 0, "No valid code generated"
assert results['new_patterns_found'] > 0, "No new patterns discovered"

print(f"✅ Fitness: {results['best_fitness']:.3f} (broke 0.70 barrier!)")
```

## Success Metrics

- **Best fitness**: > 0.70 (breaks plateau)
- **Valid code**: > 5 genomes generate valid code
- **Speedup**: > 1.1x on at least one benchmark
- **New patterns**: > 10 discovered
- **Vault growth**: +10-20 patterns

## Dependencies

- EVO001 (Rust AST Scanner)
- EVO002 (Validation Framework)
- EVO003 (Benchmark Suite)
- EVO004 (Self-Expanding Vault)

## Enables

- EVO006 (First Improvement Deployment)
