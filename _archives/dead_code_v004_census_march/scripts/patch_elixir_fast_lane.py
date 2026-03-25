import re

file_path = "/home/lucas/Desktop/whitemagicdev/elixir/lib/whitemagic_core/gan_ying/lane_pools.ex"

with open(file_path, "r") as f:
    content = f.read()

patch = """
  defp process_event(event_type, data) do
    # 1. Ensure the SHM ring is initialized on first use, or at least attempt it safely.
    # We will just try to push to it. If it fails, it might not be initialized, but we can't crash the worker.
    
    event_id = :erlang.phash2(event_type) |> rem(1000)
    sender_hash = :erlang.phash2(self()) |> rem(100000)
    timestamp = System.system_time(:millisecond) / 1000.0
    
    payload = case Jason.encode(data) do
      {:ok, json} -> json
      _ -> "{}"
    end
    
    # Fire and forget into the zero-copy Koka Ring Buffer
    try do
      WhiteMagic.EventRing.Nif.push_event(event_id, sender_hash, timestamp, payload)
    rescue
      _ -> :error
    catch
      :error, :nif_not_loaded -> :nif_not_loaded
    end

    # Route to Python bridge or handle internally
    case event_type do
      "system_health_changed" ->
        :ok
      "mesh_signal" ->
        :ok
      _ ->
        :ok
    end
  end
"""

content = re.sub(r'  defp process_event\(event_type, data\) do.*?    end\n  end', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Elixir FastLaneWorker patched to push to EventRing NIF")
