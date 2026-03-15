
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
