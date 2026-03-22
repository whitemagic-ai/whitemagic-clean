#!/usr/bin/env julia
"""Test Julia statistical analysis with real data"""

include("julia_analysis/statistical_analysis.jl")
using .EvolutionStatistics

println("📊 JULIA STATISTICAL ANALYSIS - LIVE TEST")
println("=" ^ 80)

# Simulate evolution data
fitness_history = [0.605, 0.628, 0.642, 0.654, 0.660, 0.665, 0.667, 0.670, 0.671, 0.675]
diversity_history = [0.919, 0.913, 0.913, 0.913, 0.915, 0.913, 0.913, 0.916, 0.913, 0.912]

println("Test data: $(length(fitness_history)) generations")
println()

# Create analyzer
analyzer = EvolutionAnalyzer(fitness_history, diversity_history, Matrix{Float64}[])

# Run analysis
println("🔍 Running analysis...")
results = analyze_run(analyzer)

println()
println("✅ RESULTS:")
println("   Fitness trend: $(round(results["fitness_trend"], digits=3))")
println("   Convergence generation: $(results["convergence_generation"])")
println("   Improvement rate: $(round(results["improvement_rate"], digits=4))")

if haskey(results, "diversity_metrics")
    div = results["diversity_metrics"]
    println("   Initial diversity: $(round(div["initial_diversity"]*100, digits=1))%")
    println("   Final diversity: $(round(div["final_diversity"]*100, digits=1))%")
    println("   Mean diversity: $(round(div["mean_diversity"]*100, digits=1))%")
end

println("   Speciation events: $(length(results["speciation_events"]))")
println("   Extinction events: $(length(results["extinction_events"]))")
println()

# Generate report
println("📝 Generating report...")
report = generate_report(analyzer)
println()
println(report)

println()
println("✅ JULIA ANALYSIS COMPLETE!")
