defmodule WhitemagicCore.GanYing.Supervisor do
  use Supervisor

  @moduledoc """
  Supervises the Gan Ying subsystem: EventBus + DreamScheduler.

  Restart strategy: :rest_for_one — if the EventBus crashes, the
  DreamScheduler (which depends on it) is also restarted.
  """

  def start_link(opts \\ []) do
    Supervisor.start_link(__MODULE__, opts, name: __MODULE__)
  end

  @impl true
  def init(_init_arg) do
    children = [
      # FAST Lane Pool - dedicated workers for <100ms latency events
      {WhitemagicCore.GanYing.FastLanePool, pool_size: 8},
      
      # MEDIUM Lane Pool - for <1s latency events  
      {WhitemagicCore.GanYing.MediumLanePool, pool_size: 4},
      
      # Main Event Bus coordinator
      WhitemagicCore.GanYing.EventBus,
      
      # Dream scheduler for background processing
      WhitemagicCore.GanYing.DreamScheduler
    ]

    Supervisor.init(children, strategy: :rest_for_one)
  end
end
