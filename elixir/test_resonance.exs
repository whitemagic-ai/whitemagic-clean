
defmodule TestRunner do
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    case WhiteMagic.EventRing.Nif.init_shm_ring() do
      :ok -> IO.puts("Elixir: SHM Ring Initialized.")
      error -> IO.puts("Elixir: Failed to initialize: #{inspect(error)}")
    end
    Process.sleep(500)
    
    IO.puts("Elixir: Sending event 1")
    WhiteMagic.EventRing.Nif.push_event(101, 555, 1.0, ~s({"type": "clone_heartbeat", "cpu": 45}))
    
    IO.puts("Elixir: Sending event 2")
    WhiteMagic.EventRing.Nif.push_event(202, 777, 2.0, ~s({"query": "How does the SHM architecture improve vector search latency?"}))
    
    Process.sleep(1000)
  end
end
TestRunner.run()
