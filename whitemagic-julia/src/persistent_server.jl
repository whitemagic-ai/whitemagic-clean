# Julia Persistent Server - Eliminates JIT Startup Penalty
# Provides ZMQ-based RPC for graph operations

using ZMQ, JSON

const SERVER_VERSION = "1.0.0"
const CONTEXT = ZMQ.Context()

# Graph operations (ported from graph_rrf.jl)
function rrf_fuse(lists::Vector{Vector{String}}, weights::Vector{Float64}, k::Int=60)
    score_map = Dict{String, Float64}()
    
    for (list_idx, list) in enumerate(lists)
        weight = weights[list_idx]
        for (rank, item) in enumerate(list)
            if !haskey(score_map, item)
                score_map[item] = 0.0
            end
            # RRF formula: sum(weight / (k + rank))
            score_map[item] += weight / (k + rank)
        end
    end
    
    # Sort by score descending
    sorted = sort(collect(score_map), by=x->x[2], rev=true)
    return [item for (item, score) in sorted]
end

function pagerank(edges::Vector{Tuple{String, String}}, 
                  weights::Vector{Float64},
                  damping::Float64=0.85,
                  iterations::Int=100,
                  tol::Float64=1e-6)
    # Build adjacency list
    nodes = Set{String}()
    for (src, dst) in edges
        push!(nodes, src, dst)
    end
    node_list = collect(nodes)
    node_idx = Dict(node => i for (i, node) in enumerate(node_list))
    n = length(node_list)
    
    # Initialize ranks
    ranks = fill(1.0 / n, n)
    
    # Power iteration
    for iter in 1:iterations
        new_ranks = fill((1.0 - damping) / n, n)
        
        for (edge_idx, (src, dst)) in enumerate(edges)
            if haskey(node_idx, src) && haskey(node_idx, dst)
                src_i = node_idx[src]
                dst_i = node_idx[dst]
                new_ranks[dst_i] += damping * ranks[src_i] * weights[edge_idx]
            end
        end
        
        # Check convergence
        diff = sum(abs.(new_ranks - ranks))
        ranks = new_ranks
        
        if diff < tol
            break
        end
    end
    
    return Dict(node_list[i] => ranks[i] for i in 1:n)
end

function walk_scoring(seed::String,
                      edges::Vector{Tuple{String, String}},
                      node_scores::Dict{String, Float64},
                      max_depth::Int=5,
                      decay::Float64=0.9)
    visited = Set{String}([seed])
    current_level = Dict(seed => 1.0)
    all_scores = Dict{String, Float64}()
    
    for depth in 1:max_depth
        next_level = Dict{String, Float64}()
        
        for (node, score) in current_level
            # Find neighbors
            for (src, dst) in edges
                neighbor = nothing
                if src == node && !(dst in visited)
                    neighbor = dst
                elseif dst == node && !(src in visited)
                    neighbor = src
                end
                
                if neighbor !== nothing
                    weight = get(node_scores, neighbor, 0.5)
                    new_score = score * decay * (0.5 + 0.5 * weight)
                    next_level[neighbor] = get(next_level, neighbor, 0.0) + new_score
                    push!(visited, neighbor)
                end
            end
        end
        
        # Merge scores
        for (node, score) in next_level
            all_scores[node] = get(all_scores, node, 0.0) + score / depth
        end
        
        current_level = next_level
        if isempty(current_level)
            break
        end
    end
    
    # Sort and return
    sorted = sort(collect(all_scores), by=x->x[2], rev=true)
    return Dict(item => score for (item, score) in sorted)
end

function handle_request(request)
    method = get(request, "method", "")
    params = get(request, "params", Dict())
    
    try
        if method == "rrf_fuse"
            lists = [Vector{String}(l) for l in params["lists"]]
            weights = Vector{Float64}(params["weights"])
            k = get(params, "k", 60)
            result = rrf_fuse(lists, weights, k)
            return Dict("status" => "success", "result" => result)
            
        elseif method == "pagerank"
            edges = [(string(src), string(dst)) for (src, dst) in params["edges"]]
            weights = Vector{Float64}(params["weights"])
            damping = get(params, "damping", 0.85)
            result = pagerank(edges, weights, damping)
            return Dict("status" => "success", "result" => result)
            
        elseif method == "walk_scoring"
            seed = params["seed"]
            edges = [(string(src), string(dst)) for (src, dst) in params["edges"]]
            node_scores = Dict{String, Float64}(params["node_scores"])
            result = walk_scoring(seed, edges, node_scores)
            return Dict("status" => "success", "result" => result)
            
        elseif method == "health"
            return Dict("status" => "success", "version" => SERVER_VERSION)
            
        else
            return Dict("status" => "error", "error" => "Unknown method: $method")
        end
    catch e
        return Dict("status" => "error", "error" => string(e))
    end
end

function main()
    port = parse(Int, get(ENV, "JULIA_SERVER_PORT", "5555"))
    
    socket = ZMQ.Socket(CONTEXT, ZMQ.REP)
    ZMQ.bind(socket, "tcp://127.0.0.1:$port")
    
    println("Julia Graph Server v$SERVER_VERSION started on port $port")
    println("Methods available: rrf_fuse, pagerank, walk_scoring, health")
    
    while true
        try
            # Receive request
            msg = ZMQ.recv(socket)
            request_str = String(msg)
            request = JSON.parse(request_str)
            
            # Process
            response = handle_request(request)
            
            # Send response
            response_json = JSON.json(response)
            ZMQ.send(socket, response_json)
            
        catch e
            println("Error handling request: $e")
            error_response = JSON.json(Dict("status" => "error", "error" => string(e)))
            ZMQ.send(socket, error_response)
        end
    end
end

main()
