defmodule WhiteMagic.EventRing.Nif do
  use Rustler, otp_app: :whitemagic_core, crate: "whitemagic_elixir"

  # Fallback functions
  def init_shm_ring(), do: :erlang.nif_error(:nif_not_loaded)
  def push_event(_event_type, _sender_hash, _timestamp, _payload), do: :erlang.nif_error(:nif_not_loaded)
end
