"""
Julia Statistical Analysis Module for HyperEvolution Engine

Advanced statistical analysis of evolution metrics using Julia's
scientific computing capabilities.
"""

module EvolutionStatistics

using Statistics
using StatsBase
using Distributions
using LinearAlgebra
using Plots

export EvolutionAnalyzer, analyze_run, generate_report

"""
Statistical analyzer for evolution runs
"""
struct EvolutionAnalyzer
    fitness_history::Vector{Float64}
    diversity_history::Vector{Float64}
    population_snapshots::Vector{Matrix{Float64}}
    generation_count::Int
end

"""
Create analyzer from evolution data
"""
function EvolutionAnalyzer(
    fitness_history::Vector{Float64},
    diversity_history::Vector{Float64},
    population_snapshots::Vector{Matrix{Float64}}
)
    EvolutionAnalyzer(
        fitness_history,
        diversity_history,
        population_snapshots,
        length(fitness_history)
    )
end

"""
Compute fitness trend using linear regression
"""
function fitness_trend(analyzer::EvolutionAnalyzer)::Float64
    n = length(analyzer.fitness_history)
    if n < 2
        return 0.0
    end
    
    x = collect(1:n)
    y = analyzer.fitness_history
    
    # Linear regression
    x_mean = mean(x)
    y_mean = mean(y)
    
    numerator = sum((x .- x_mean) .* (y .- y_mean))
    denominator = sum((x .- x_mean).^2)
    
    if denominator == 0
        return 0.0
    end
    
    slope = numerator / denominator
    
    # Normalize to -1 to 1 range
    max_slope = (maximum(y) - minimum(y)) / n
    return clamp(slope / max_slope, -1.0, 1.0)
end

"""
Detect convergence generation
"""
function convergence_generation(analyzer::EvolutionAnalyzer; threshold::Float64=0.01)::Int
    n = length(analyzer.fitness_history)
    if n < 10
        return n
    end
    
    # Look for plateau (variance < threshold for 10+ generations)
    for i in 10:n
        window = analyzer.fitness_history[i-9:i]
        if std(window) < threshold
            return i - 9
        end
    end
    
    return n
end

"""
Calculate diversity metrics
"""
function diversity_metrics(analyzer::EvolutionAnalyzer)::Dict{String, Float64}
    if isempty(analyzer.diversity_history)
        return Dict{String, Float64}()
    end
    
    Dict(
        "initial_diversity" => analyzer.diversity_history[1],
        "final_diversity" => analyzer.diversity_history[end],
        "mean_diversity" => mean(analyzer.diversity_history),
        "min_diversity" => minimum(analyzer.diversity_history),
        "max_diversity" => maximum(analyzer.diversity_history),
        "diversity_trend" => fitness_trend(
            EvolutionAnalyzer(
                analyzer.diversity_history,
                Float64[],
                Matrix{Float64}[],
                length(analyzer.diversity_history)
            )
        )
    )
end

"""
Detect speciation events (sudden diversity increases)
"""
function detect_speciation_events(analyzer::EvolutionAnalyzer; threshold::Float64=0.1)::Vector{Int}
    events = Int[]
    
    if length(analyzer.diversity_history) < 2
        return events
    end
    
    for i in 2:length(analyzer.diversity_history)
        delta = analyzer.diversity_history[i] - analyzer.diversity_history[i-1]
        if delta > threshold
            push!(events, i)
        end
    end
    
    events
end

"""
Detect extinction events (sudden diversity decreases)
"""
function detect_extinction_events(analyzer::EvolutionAnalyzer; threshold::Float64=0.1)::Vector{Int}
    events = Int[]
    
    if length(analyzer.diversity_history) < 2
        return events
    end
    
    for i in 2:length(analyzer.diversity_history)
        delta = analyzer.diversity_history[i-1] - analyzer.diversity_history[i]
        if delta > threshold
            push!(events, i)
        end
    end
    
    events
end

"""
Calculate fitness improvement rate
"""
function improvement_rate(analyzer::EvolutionAnalyzer)::Float64
    if length(analyzer.fitness_history) < 2
        return 0.0
    end
    
    initial = analyzer.fitness_history[1]
    final = analyzer.fitness_history[end]
    generations = length(analyzer.fitness_history)
    
    (final - initial) / generations
end

"""
Analyze population structure from snapshots
"""
function population_structure_analysis(analyzer::EvolutionAnalyzer)::Dict{String, Any}
    if isempty(analyzer.population_snapshots)
        return Dict{String, Any}()
    end
    
    # Analyze final population
    final_pop = analyzer.population_snapshots[end]
    
    Dict{String, Any}(
        "population_size" => size(final_pop, 1),
        "gene_count_mean" => mean(final_pop[:, 1]),
        "gene_count_std" => std(final_pop[:, 1]),
        "expression_mean" => mean(final_pop[:, 2]),
        "expression_std" => std(final_pop[:, 2]),
        "fitness_distribution" => fit(Histogram, final_pop[:, 3], nbins=20)
    )
end

"""
Comprehensive analysis of evolution run
"""
function analyze_run(analyzer::EvolutionAnalyzer)::Dict{String, Any}
    Dict{String, Any}(
        "fitness_trend" => fitness_trend(analyzer),
        "convergence_generation" => convergence_generation(analyzer),
        "improvement_rate" => improvement_rate(analyzer),
        "diversity_metrics" => diversity_metrics(analyzer),
        "speciation_events" => detect_speciation_events(analyzer),
        "extinction_events" => detect_extinction_events(analyzer),
        "population_structure" => population_structure_analysis(analyzer)
    )
end

"""
Generate visualization plots
"""
function generate_plots(analyzer::EvolutionAnalyzer, output_dir::String="./plots")
    mkpath(output_dir)
    
    # Fitness over time
    p1 = plot(
        analyzer.fitness_history,
        title="Fitness Evolution",
        xlabel="Generation",
        ylabel="Average Fitness",
        legend=false,
        linewidth=2
    )
    savefig(p1, joinpath(output_dir, "fitness_evolution.png"))
    
    # Diversity over time
    p2 = plot(
        analyzer.diversity_history,
        title="Diversity Evolution",
        xlabel="Generation",
        ylabel="Population Diversity",
        legend=false,
        linewidth=2,
        color=:green
    )
    savefig(p2, joinpath(output_dir, "diversity_evolution.png"))
    
    # Combined plot
    p3 = plot(
        analyzer.fitness_history,
        label="Fitness",
        xlabel="Generation",
        ylabel="Normalized Value",
        linewidth=2
    )
    plot!(p3, analyzer.diversity_history, label="Diversity", linewidth=2)
    savefig(p3, joinpath(output_dir, "combined_evolution.png"))
    
    println("Plots saved to $output_dir")
end

"""
Generate comprehensive report
"""
function generate_report(analyzer::EvolutionAnalyzer)::String
    analysis = analyze_run(analyzer)
    
    report = """
    # Evolution Analysis Report
    
    ## Summary Statistics
    
    - **Generations**: $(analyzer.generation_count)
    - **Convergence Generation**: $(analysis["convergence_generation"])
    - **Fitness Trend**: $(round(analysis["fitness_trend"], digits=3))
    - **Improvement Rate**: $(round(analysis["improvement_rate"], digits=4)) per generation
    
    ## Diversity Metrics
    
    """
    
    div_metrics = analysis["diversity_metrics"]
    for (key, value) in div_metrics
        report *= "- **$(replace(key, "_" => " ") |> titlecase)**: $(round(value, digits=3))\n"
    end
    
    report *= """
    
    ## Evolutionary Events
    
    - **Speciation Events**: $(length(analysis["speciation_events"]))
    - **Extinction Events**: $(length(analysis["extinction_events"]))
    
    """
    
    if !isempty(analysis["speciation_events"])
        report *= "- Speciation at generations: $(join(analysis["speciation_events"], ", "))\n"
    end
    
    if !isempty(analysis["extinction_events"])
        report *= "- Extinctions at generations: $(join(analysis["extinction_events"], ", "))\n"
    end
    
    report *= """
    
    ## Population Structure
    
    """
    
    if haskey(analysis, "population_structure") && !isempty(analysis["population_structure"])
        pop_struct = analysis["population_structure"]
        report *= "- **Population Size**: $(pop_struct["population_size"])\n"
        report *= "- **Mean Gene Count**: $(round(pop_struct["gene_count_mean"], digits=1))\n"
        report *= "- **Gene Count Std Dev**: $(round(pop_struct["gene_count_std"], digits=2))\n"
        report *= "- **Mean Expression**: $(round(pop_struct["expression_mean"], digits=3))\n"
    end
    
    report
end

end # module

# Example usage
if abspath(PROGRAM_FILE) == @__FILE__
    using .EvolutionStatistics
    
    # Simulate some data
    fitness_history = cumsum(randn(100) .* 0.01 .+ 0.005) .+ 0.5
    diversity_history = 1.0 .- (collect(1:100) ./ 100) .* 0.7 .+ randn(100) .* 0.05
    
    analyzer = EvolutionAnalyzer(fitness_history, diversity_history, Matrix{Float64}[])
    
    # Run analysis
    results = analyze_run(analyzer)
    println("Analysis Results:")
    for (key, value) in results
        println("  $key: $value")
    end
    
    # Generate report
    report = generate_report(analyzer)
    println("\n" * report)
    
    println("\nJulia statistical analysis module ready!")
end
