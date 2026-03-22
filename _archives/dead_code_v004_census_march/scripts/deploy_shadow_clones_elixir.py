import subprocess
import time

print("Deploying Elixir Shadow Clone Army...")

elixir_script = """
defmodule SwarmCommander do
  def run do
    try do
      WhiteMagic.EventRing.Nif.init_shm_ring()
    rescue _ -> :ok
    end
    Process.sleep(100)
    
    IO.puts("Elixir: Booting 10,000 Shadow Clones...")
    
    start_time = System.monotonic_time(:millisecond)
    
    # Koka will process sequentially so if we send 10k at once, the ring buffer (capacity 65k) will hold them.
    # However, Elixir `Task.async` might spawn too many concurrent threads. Let's chunk them.
    
    1..10000 
    |> Enum.chunk_every(1000)
    |> Enum.each(fn chunk -> 
      tasks = for i <- chunk do
        Task.async(fn -> 
          if rem(i, 100) == 0 do
            WhiteMagic.EventRing.Nif.push_event(202, i, 2.0, ~s({"query": "What is the optimal pathing for clone #{i}?"}))
          else
            if rem(i, 50) == 0 do
              WhiteMagic.EventRing.Nif.push_event(303, i, 3.0, ~s({"prat_route": true, "search_memories": true, "clone_id": #{i}}))
            else
              WhiteMagic.EventRing.Nif.push_event(101, i, 1.0, ~s({"type": "clone_heartbeat", "clone_id": #{i}}))
            end
          end
          :ok
        end)
      end
      Task.await_many(tasks, :infinity)
      Process.sleep(10) # Let Koka catch up
    end)
    
    end_time = System.monotonic_time(:millisecond)
    duration = end_time - start_time
    
    IO.puts("Elixir: 10,000 Clones finished their telemetry burst in #{duration}ms.")
  end
end

SwarmCommander.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/swarm_test.exs", "w") as f:
    f.write(elixir_script)

koka_proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain'],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

time.sleep(1)

print("Triggering Elixir Swarm...")
elixir_proc = subprocess.Popen(
    ['mix', 'run', '--no-start', 'swarm_test.exs'],
    cwd='/home/lucas/Desktop/whitemagicdev/elixir',
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

elixir_out, elixir_err = elixir_proc.communicate()
print(f"\\nSwarm Output:\\n{elixir_out}")

# Wait longer for Koka to process all 10k events
print("Waiting for Koka to finish processing...")
time.sleep(5)

koka_proc.terminate()
koka_out, _ = koka_proc.communicate()

events_received = 0
queries_resolved = 0
prat_routes = 0
total_time_ms = 0.0
max_time_ms = 0.0

for line in koka_out.split('\\n'):
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

total_processed = events_received + queries_resolved + prat_routes

print(f"Koka Fast Brain processed {events_received} heartbeats, {queries_resolved} semantic graph walks, and {prat_routes} PRAT tool routes.")
if total_processed > 0:
    print(f"Average processing time per event: {total_time_ms / total_processed:.4f}ms")
    print(f"Max latency: {max_time_ms:.4f}ms")

print("Test Complete.")
