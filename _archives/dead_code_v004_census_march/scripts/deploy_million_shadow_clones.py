import subprocess
import time
import os

print("Deploying MASSIVE Elixir Shadow Clone Army (1,000,000 clones) with PRAT Routing...")

elixir_script = """
defmodule SwarmCommander do
  def run do
    # Force initialize the SHM Ring if not exists
    IO.puts("Elixir: Initializing SHM Ring...")
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    IO.puts("Elixir: Booting 1,000,000 Shadow Clones...")
    
    start_time = System.monotonic_time(:millisecond)
    
    # We will chunk the requests into batches of 100
    1..1000000 
    |> Enum.chunk_every(100)
    |> Enum.each(fn chunk -> 
      for i <- chunk do
        if rem(i, 100) == 0 do
          WhiteMagic.EventRing.Nif.push_event(202, i, 2.0, ~s({"query": "What is the optimal pathing for clone #{i}?"}))
        else
          if rem(i, 50) == 0 do
            # 20,000 clones will ask for PRAT tool routing (search_memories or create_memory)
            if rem(i, 100) == 50 do
              WhiteMagic.EventRing.Nif.push_event(303, i, 3.0, ~s({"prat_route": true, "search_memories": true, "clone_id": #{i}}))
            else
              WhiteMagic.EventRing.Nif.push_event(303, i, 3.0, ~s({"prat_route": true, "create_memory": true, "clone_id": #{i}}))
            end
          else
            WhiteMagic.EventRing.Nif.push_event(101, i, 1.0, ~s({"type": "clone_heartbeat", "clone_id": #{i}}))
          end
        end
      end
    end)
    
    end_time = System.monotonic_time(:millisecond)
    duration = end_time - start_time
    
    IO.puts("Elixir: 1,000,000 Clones finished their telemetry burst in #{duration}ms.")
  end
end

SwarmCommander.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/swarm_massive.exs", "w") as f:
    f.write(elixir_script)

try:
    os.remove("/dev/shm/whitemagic_event_ring")
except Exception:
    pass

subprocess.run(['mix', 'run', '-e', 'WhiteMagic.EventRing.Nif.init_shm_ring()'], cwd='/home/lucas/Desktop/whitemagicdev/elixir')
time.sleep(1)

with open("/home/lucas/Desktop/whitemagicdev/koka_out.log", "w") as out_f:
    koka_proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain'],
        stdout=out_f,
        stderr=subprocess.PIPE,
        text=True
    )

time.sleep(1)

print("Triggering Elixir Swarm...")
elixir_proc = subprocess.Popen(
    ['mix', 'run', '--no-start', 'swarm_massive.exs'],
    cwd='/home/lucas/Desktop/whitemagicdev/elixir',
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

elixir_out, elixir_err = elixir_proc.communicate()
print(f"\\nSwarm Output:\\n{elixir_out}")

print("Waiting a bit for Koka to finish processing...")
time.sleep(3)

koka_proc.terminate()

events_received = 0
queries_resolved = 0
prat_routes = 0
total_time_ms = 0.0
max_time_ms = 0.0

try:
    with open("/home/lucas/Desktop/whitemagicdev/koka_out.log", "r") as f:
        for line in f:
            if "telemetry_processed" in line:
                events_received += 1
            elif "system_resonance_achieved" in line:
                queries_resolved += 1
            elif "prat_routed" in line:
                prat_routes += 1
                
            if "latency" in line:
                try:
                    parts = line.split('"latency":"')
                    if len(parts) > 1:
                        lat = float(parts[1].split('ms"')[0])
                        total_time_ms += lat
                        if lat > max_time_ms:
                            max_time_ms = lat
                except:
                    pass
except FileNotFoundError:
    pass

total_processed = events_received + queries_resolved + prat_routes

print("\\n================ SUMMARY ================")
print("Koka Fast Brain Processed:")
print(f"  - Heartbeats: {events_received:,}")
print(f"  - Vector + Graph Walks: {queries_resolved:,}")
print(f"  - PRAT Tool Routes: {prat_routes:,}")
print(f"  - Total Events: {total_processed:,}")

if total_processed > 0:
    print("\\nLatency Metrics:")
    print(f"  - Average latency per event: {total_time_ms / total_processed:.5f}ms")
    print(f"  - Maximum latency seen: {max_time_ms:.5f}ms")
    
    print(f"  - Estimated Native Throughput: {1000 / (total_time_ms / total_processed):,.0f} events/sec")

print("=========================================")
print("Test Complete.")
