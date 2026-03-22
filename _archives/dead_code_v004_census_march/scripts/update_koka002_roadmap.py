
file_path = "/home/lucas/Desktop/whitemagicdev/campaigns/KOKA002_enhancement_roadmap.md"

with open(file_path, "r") as f:
    content = f.read()

# VC-01
content = content.replace("- [ ] Batch commands in single JSON payload", "- [x] Batch commands in single JSON payload")
content = content.replace("- [ ] Sequential and parallel execution modes", "- [x] Sequential and parallel execution modes")
content = content.replace("- [ ] Target: 10 commands < 5x single command latency", "- [x] Target: 10 commands < 5x single command latency")

# VC-03
content = content.replace("- [ ] Heartbeat mechanism (ping/pong every 30s)", "- [x] Heartbeat mechanism (ping/pong every 30s)")
content = content.replace("- [ ] Automatic restart on missed heartbeats", "- [x] Automatic restart on missed heartbeats")
content = content.replace("- [ ] Health metrics exposed via `stats()` endpoint", "- [x] Health metrics exposed via `stats()` endpoint")

# VC-04
content = content.replace("- [ ] Lazy pool initialization (on first use)", "- [x] Lazy pool initialization (on first use)")
content = content.replace("- [ ] Pool scaling based on load (min 1, max 4)", "- [x] Pool scaling based on load (min 1, max 4)")
content = content.replace("- [ ] Pool shrink after 5min idle", "- [x] Pool shrink after 5min idle")

# VC-05
content = content.replace("- [ ] POSIX shared memory segment for Koka-Python data", "- [x] POSIX shared memory segment for Koka-Python data")
content = content.replace("- [ ] Zero-copy transfer for embeddings (384-dim vectors)", "- [x] Zero-copy transfer for embeddings (384-dim vectors)")
content = content.replace("- [ ] Benchmark: 1000 embeddings transfer < 1ms", "- [x] Benchmark: 1000 embeddings transfer < 1ms")

with open(file_path, "w") as f:
    f.write(content)

print("KOKA002 roadmap updated!")
