
defmodule TestRunner do
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    case WhiteMagic.EventRing.Nif.init_shm_ring() do
      :ok -> IO.puts("Elixir: SHM Ring Initialized.")
      error -> 
        IO.puts("Elixir: Failed to initialize: #{inspect(error)}")
        System.halt(1)
    end
    
    IO.puts("Elixir: Sleeping to allow Koka to connect...")
    Process.sleep(1000)
    
    IO.puts("Elixir: Pushing event 1...")
    WhiteMagic.EventRing.Nif.push_event(42, 12345, 1234567.89, "Hello from Elixir!")
    
    IO.puts("Elixir: Pushing event 2...")
    WhiteMagic.EventRing.Nif.push_event(99, 54321, 9876543.21, ~s({"query": "Find fast lane"}))
    
    IO.puts("Elixir: Done pushing. Waiting for Koka to process...")
    Process.sleep(2000)
  end
end

TestRunner.run()
