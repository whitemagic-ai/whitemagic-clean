# Phase 9 Distributed: Node 35
defmodule WhiteMagic.Distributed.Node do
  @moduledoc """
  Distributed node for mesh computing.
  """

  use GenServer
  require Logger

  def start_link(opts) do
    GenServer.start_link(__MODULE__, opts, name: __MODULE__)
  end

  @impl true
  def init(opts) do
    Logger.info("Starting distributed node...")
    {:ok, opts}
  end
end
