defmodule WhiteMagic.Bridges.ElixirBridge do
  @moduledoc """
  NIF bridge for Elixir ↔ Rust/Python interop.
  """

  use Rustler, otp_app: :whitemagic, crate: :whitemagic_elixir

  # NIF functions
  def process_embedding(_data), do: :erlang.nif_error(:nif_not_loaded)
  def search_index(_query, _k), do: :erlang.nif_error(:nif_not_loaded)
  def consolidate_memory(_data), do: :erlang.nif_error(:nif_not_loaded)
end
