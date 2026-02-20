#!/usr/bin/env julia
# Minimal Julia server for testing
using ZMQ, JSON3, Sockets

ctx = Context()
socket = Socket(ctx, REP)
bind(socket, "tcp://127.0.0.1:5555")
println("Julia server on port 5555")

while true
    msg = recv(socket)
    req = JSON3.read(msg, Dict)
    resp = Dict("command" => get(req, "command", ""), "status" => "ok", "julia_version" => string(VERSION))
    send(socket, JSON3.write(resp))
end
