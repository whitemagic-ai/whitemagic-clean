#!/usr/bin/env julia
# Julia Persistent Server — ZMQ-based graph/math server for WhiteMagic
# Eliminates 3.7s JIT startup by running once and serving requests via ZMQ
# Usage: julia julia_server.jl [--bind tcp://127.0.0.1:5555]

using ZMQ, JSON3

include("graph_rrf.jl")
using .GraphRRF

const DEFAULT_BIND = "tcp://127.0.0.1:5555"

function handle_request(req::Dict)
    cmd = get(req, "command", "")
    
    if cmd == "rrf_fuse"
        lists = get(req, "lists", [])
        weights = Float64.(get(req, "weights", ones(length(lists))))
        k = Float64(get(req, "k", 60))
        return Dict("fused" => rrf_fuse(lists, weights, k))
        
    elseif cmd == "pagerank"
        node_ids = get(req, "node_ids", [])
        edges = get(req, "edges", [])
        damping = Float64(get(req, "damping", 0.85))
        return Dict("pagerank" => pagerank_scores(node_ids, edges, damping))
        
    elseif cmd == "score_walk_paths"
        paths = get(req, "paths", [])
        weights = Dict(string(k) => Float64(v) for (k, v) in get(req, "weights", Dict()))
        return Dict("scored_paths" => score_walk_paths(paths, weights))
        
    elseif cmd == "community_gravity"
        vec = Float64.(get(req, "vector", []))
        centroids = [Float64.(c) for c in get(req, "centroids", [])]
        cids = get(req, "community_ids", [])
        return Dict("gravity" => community_gravity(vec, centroids, cids))
        
    elseif cmd == "ping"
        return Dict("pong" => true, "julia_version" => string(VERSION))
        
    else
        return Dict("error" => "unknown command: $cmd")
    end
end

function main(bind_addr=DEFAULT_BIND)
    ctx = Context()
    socket = Socket(ctx, REP)
    bind(socket, bind_addr)
    
    println("Julia graph server listening on $bind_addr")
    println("Commands: rrf_fuse, pagerank, score_walk_paths, community_gravity, ping")
    
    while true
        msg = recv(socket)
        req = JSON3.read(msg, Dict)
        resp = handle_request(req)
        send(socket, JSON3.write(resp))
    end
    
    close(socket)
    close(ctx)
end

# If run directly (not included)
if abspath(PROGRAM_FILE) == @__FILE__
    bind_addr = length(ARGS) >= 1 ? ARGS[1] : DEFAULT_BIND
    main(bind_addr)
end
