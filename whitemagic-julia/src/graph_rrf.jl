"""
    WhiteMagic Graph RRF & Walk Scoring
    =====================================
    Reciprocal Rank Fusion and weighted BFS scoring for memory graph traversal.
    Julia excels here: tight numeric loops, no GIL, native sparse matrix ops.

    Functions:
    - rrf_fuse: Merge N ranked lists via RRF (k=60 default)
    - score_walk_paths: Score BFS paths by multi-signal weighted product
    - pagerank_scores: Fast power-iteration PageRank on adjacency list
    - community_gravity: Gravity pull toward community centroids

    Called from Python via JuliaBridge (JSON over stdio).
"""
module GraphRRF

using Statistics
using LinearAlgebra

export rrf_fuse, score_walk_paths, pagerank_scores, community_gravity

# ---------------------------------------------------------------------------
# Reciprocal Rank Fusion
# ---------------------------------------------------------------------------

"""
    rrf_fuse(ranked_lists, weights, k=60)

Merge multiple ranked lists of memory IDs via Reciprocal Rank Fusion.
Each list is an array of {id, score} dicts. Returns merged ranking.

RRF score = Σ weight_i / (k + rank_i)
"""
function rrf_fuse(ranked_lists::Vector, weights::Vector{Float64}, k::Float64=60.0)
    scores = Dict{String, Float64}()

    for (list_idx, ranked) in enumerate(ranked_lists)
        w = list_idx <= length(weights) ? weights[list_idx] : 1.0
        for (rank, item) in enumerate(ranked)
            id = string(get(item, "id", get(item, "memory_id", "")))
            isempty(id) && continue
            scores[id] = get(scores, id, 0.0) + w / (k + rank)
        end
    end

    # Sort by score descending
    sorted = sort(collect(scores), by=x -> -x[2])
    return [Dict("id" => id, "rrf_score" => score) for (id, score) in sorted]
end

# ---------------------------------------------------------------------------
# Walk Path Scoring
# ---------------------------------------------------------------------------

"""
    score_walk_paths(paths, weights)

Score BFS walk paths by weighted product of edge signals.
Each path: {nodes, edge_weights, relation_types, depth}
Weights: {semantic, gravity, recency, staleness}
"""
function score_walk_paths(paths::Vector, weights::Dict)
    w_sem = get(weights, "semantic", 0.4)
    w_grav = get(weights, "gravity", 0.3)
    w_rec = get(weights, "recency", 0.2)
    w_stale = get(weights, "staleness", 0.1)

    results = []
    for path in paths
        nodes = get(path, "nodes", [])
        edge_sigs = get(path, "edge_signals", [])
        depth = get(path, "depth", length(nodes) - 1)

        if isempty(edge_sigs)
            # No signals: uniform score decayed by depth
            score = 0.5 ^ max(depth, 1)
        else
            # Weighted product across edges
            score = 1.0
            for sig in edge_sigs
                sem = get(sig, "semantic_sim", 0.5)
                grav = get(sig, "galactic_gravity", 0.3)
                rec = get(sig, "recency", 0.5)
                stale = get(sig, "staleness", 0.1)
                edge_score = w_sem * sem + w_grav * grav + w_rec * rec + w_stale * (1.0 - stale)
                score *= clamp(edge_score, 0.0, 1.0)
            end
            # Depth penalty: longer paths get slight discount
            score *= 0.95 ^ max(depth - 1, 0)
        end

        push!(results, Dict(
            "nodes" => nodes,
            "score" => clamp(score, 0.0, 1.0),
            "depth" => depth,
            "terminal_id" => isempty(nodes) ? "" : string(nodes[end]),
        ))
    end

    # Sort by score descending
    sort!(results, by=x -> -x["score"])
    return results
end

# ---------------------------------------------------------------------------
# PageRank (power iteration)
# ---------------------------------------------------------------------------

"""
    pagerank_scores(node_ids, edges, damping=0.85, max_iter=50, tol=1e-6)

Compute PageRank scores for a memory subgraph.
node_ids: array of string IDs
edges: array of {source, target, weight} dicts
Returns: array of {id, pagerank} dicts sorted descending.
"""
function pagerank_scores(
    node_ids::Vector,
    edges::Vector,
    damping::Float64=0.85,
    max_iter::Int=50,
    tol::Float64=1e-6,
)
    n = length(node_ids)
    n == 0 && return []

    # Build index
    idx = Dict(string(id) => i for (i, id) in enumerate(node_ids))

    # Build weighted adjacency (column-stochastic)
    W = zeros(Float64, n, n)
    for edge in edges
        src = string(get(edge, "source", ""))
        tgt = string(get(edge, "target", ""))
        w = Float64(get(edge, "weight", 1.0))
        (haskey(idx, src) && haskey(idx, tgt)) || continue
        W[idx[tgt], idx[src]] += w
    end

    # Normalize columns (dangling nodes get uniform)
    col_sums = sum(W, dims=1)
    for j in 1:n
        if col_sums[j] > 0
            W[:, j] ./= col_sums[j]
        else
            W[:, j] .= 1.0 / n  # dangling
        end
    end

    # Power iteration
    r = fill(1.0 / n, n)
    teleport = fill(1.0 / n, n)
    for _ in 1:max_iter
        r_new = damping .* (W * r) .+ (1.0 - damping) .* teleport
        norm(r_new - r, 1) < tol && break
        r = r_new
    end

    # Return sorted results
    results = [Dict("id" => string(node_ids[i]), "pagerank" => r[i]) for i in 1:n]
    sort!(results, by=x -> -x["pagerank"])
    return results
end

# ---------------------------------------------------------------------------
# Community Gravity
# ---------------------------------------------------------------------------

"""
    community_gravity(memory_vec, community_centroids, community_ids)

Compute gravity pull of a query vector toward each community centroid.
Returns community_ids sorted by cosine similarity to memory_vec.
"""
function community_gravity(
    memory_vec::Vector{Float64},
    community_centroids::Vector,
    community_ids::Vector,
)
    isempty(community_centroids) && return []
    q_norm = norm(memory_vec)
    q_norm == 0 && return []

    results = []
    for (i, centroid) in enumerate(community_centroids)
        c = Float64.(centroid)
        c_norm = norm(c)
        c_norm == 0 && continue
        sim = dot(memory_vec, c) / (q_norm * c_norm)
        cid = i <= length(community_ids) ? string(community_ids[i]) : string(i)
        push!(results, Dict("community_id" => cid, "gravity" => clamp(sim, 0.0, 1.0)))
    end

    sort!(results, by=x -> -x["gravity"])
    return results
end

# ---------------------------------------------------------------------------
# Main: JSON stdio protocol
# ---------------------------------------------------------------------------

using JSON3

function main()
    input = read(stdin, String)
    isempty(strip(input)) && return

    req = JSON3.read(input, Dict)
    cmd = get(req, "command", "")

    result = if cmd == "rrf_fuse"
        lists = get(req, "lists", [])
        weights = Float64.(get(req, "weights", ones(length(lists))))
        k = Float64(get(req, "k", 60))
        Dict("fused" => rrf_fuse(lists, weights, k))

    elseif cmd == "score_walk_paths"
        paths = get(req, "paths", [])
        weights = Dict(string(k) => Float64(v) for (k, v) in get(req, "weights", Dict()))
        Dict("scored_paths" => score_walk_paths(paths, weights))

    elseif cmd == "pagerank"
        node_ids = get(req, "node_ids", [])
        edges = get(req, "edges", [])
        damping = Float64(get(req, "damping", 0.85))
        Dict("pagerank" => pagerank_scores(node_ids, edges, damping))

    elseif cmd == "community_gravity"
        vec = Float64.(get(req, "vector", []))
        centroids = [Float64.(c) for c in get(req, "centroids", [])]
        cids = get(req, "community_ids", [])
        Dict("gravity" => community_gravity(vec, centroids, cids))

    else
        Dict("error" => "unknown command: $cmd")
    end

    println(JSON3.write(result))
end

end  # module GraphRRF

# Entry point
using .GraphRRF
import JSON3
GraphRRF.main()
