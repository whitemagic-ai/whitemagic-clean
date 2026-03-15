defmodule ScoutSwarm do
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    payload = Jason.encode!(%{type: "file_scout", path: "test.py", size: 100, interesting: true, score: 20})
    WhiteMagic.EventRing.Nif.push_event(404, 1234, 4.0, payload)
    IO.puts("Sent payload: #{payload}")
    
    payload_end = Jason.encode!(%{type: "swarm_complete", files_scanned: 1})
    WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, payload_end)
    Process.sleep(100)
  end
end

ScoutSwarm.run()
