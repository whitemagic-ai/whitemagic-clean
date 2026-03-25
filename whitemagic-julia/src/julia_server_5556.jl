#!/usr/bin/env julia
# Minimal Julia ZMQ server on port 5556 (avoiding 5555 conflicts)
using ZMQ, JSON3, Sockets

const PORT = 5556

ctx = Context()
socket = Socket(ctx, REP)
bind(socket, "tcp://127.0.0.1:$PORT")
println("Julia ZMQ Server on port $PORT")

while true
    try
        msg = recv(socket)
        req = JSON3.read(msg, Dict)
        cmd = get(req, "command", "")
        
        resp = if cmd == "ping"
            Dict("command" => cmd, "status" => "ok", "pong" => true, "julia_version" => string(VERSION))
        elseif cmd == "rrf"
            # Reciprocal Rank Fusion implementation
            lists = get(req, "lists", [])
            k = get(req, "k", 60.0)
            result = rrf_fuse(lists, k)
            Dict("command" => cmd, "status" => "ok", "result" => result)
        elseif cmd == "pagerank"
            # Simple PageRank
            edges = get(req, "edges", [])
            damping = get(req, "damping", 0.85)
            iters = get(req, "iterations", 100)
            result = pagerank(edges, damping, iters)
            Dict("command" => cmd, "status" => "ok", "result" => result)
        else
            Dict("command" => cmd, "status" => "unknown", "julia_version" => string(VERSION))
        end
        
        send(socket, JSON3.write(resp))
    catch e
        println("Error: $e")
        send(socket, JSON3.write(Dict("status" => "error", "message" => string(e))))
    end
end

function rrf_fuse(lists::Vector, k::Float64)
    scores = Dict{String, Float64}()
    for list in lists
        for (rank, item) in enumerate(list)
            id = string(item)
            scores[id] = get(scores, id, 0.0) + 1.0 / (k + rank)
        end
    end
    sorted = sort(collect(scores), by=x->x[2], rev=true)
    return [Dict("id" => k, "score" => v) for (k, v) in sorted]
end

function pagerank(edges::Vector, damping::Float64, iters::Int)
    # Simplified PageRank - return stub for now
    nodes = unique(vcat([[string(e[1]), string(e[2])] for e in edges]...))
    n = length(nodes)
    if n == 0
        return Dict{String, Float64}()
    end
    pr = Dict(node => 1.0 / n for node in nodes)
    return pr
end
