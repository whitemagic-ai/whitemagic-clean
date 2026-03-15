
defmodule TestRunner do
  def run do
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    WhiteMagic.EventRing.Nif.push_event(101, 1, 1.0, ~s({"type": "clone_heartbeat", "clone_id": 1}))
    WhiteMagic.EventRing.Nif.push_event(202, 2, 2.0, ~s({"query": "What is the optimal pathing?"}))
    WhiteMagic.EventRing.Nif.push_event(303, 3, 3.0, ~s({"prat_route": true, "search_memories": true}))
  end
end
TestRunner.run()
