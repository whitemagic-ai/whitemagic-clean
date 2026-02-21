defmodule WhitemagicCore.GanYing.FastLanePool do
  @moduledoc """
  Pool of workers for FAST lane events (<100ms latency target).
  
  Handles: system_started, system_health_changed, mesh_signal, etc.
  """
  use GenServer
  require Logger
  
  @max_mailbox_size 50  # Lower threshold for FAST lane
  @target_latency_ms 100
  
  # Client API
  
  def start_link(opts) do
    pool_size = Keyword.get(opts, :pool_size, 8)
    GenServer.start_link(__MODULE__, %{pool_size: pool_size}, name: __MODULE__)
  end
  
  def emit(event_type, data, _opts \\ []) do
    GenServer.cast(__MODULE__, {:emit_fast, event_type, data})
  end
  
  def stats() do
    GenServer.call(__MODULE__, :stats)
  end
  
  # Server Callbacks
  
  @impl true
  def init(%{pool_size: size}) do
    workers = Enum.map(1..size, fn i ->
      {:ok, pid} = WhitemagicCore.GanYing.FastLaneWorker.start_link(id: i)
      pid
    end)
    
    {:ok, %{
      workers: workers,
      next_worker: 0,
      emitted: 0,
      dropped: 0
    }}
  end
  
  @impl true
  def handle_cast({:emit_fast, event_type, data}, state) do
    # Round-robin to next worker
    worker_idx = rem(state.next_worker, length(state.workers))
    worker = Enum.at(state.workers, worker_idx)
    
    # Check backpressure
    case Process.info(worker, :message_queue_len) do
      {:message_queue_len, len} when len < @max_mailbox_size ->
        send(worker, {:process, event_type, data, System.monotonic_time()})
        {:noreply, %{state | 
          next_worker: worker_idx + 1,
          emitted: state.emitted + 1
        }}
      
      _ ->
        Logger.warning("FAST lane backpressure: dropping #{event_type}")
        {:noreply, %{state | dropped: state.dropped + 1}}
    end
  end
  
  @impl true
  def handle_call(:stats, _from, state) do
    total = state.emitted + state.dropped
    drop_rate = if total > 0, do: state.dropped / total, else: 0.0
    
    {:reply, %{
      emitted: state.emitted,
      dropped: state.dropped,
      drop_rate: drop_rate,
      workers: length(state.workers)
    }, state}
  end
end


defmodule WhitemagicCore.GanYing.FastLaneWorker do
  @moduledoc """
  Individual FAST lane worker with latency tracking.
  """
  use GenServer
  require Logger
  
  def start_link(id: id) do
    GenServer.start_link(__MODULE__, %{id: id}, name: String.to_atom("fast_lane_#{id}"))
  end
  
  @impl true
  def init(%{id: id}) do
    {:ok, %{id: id, processed: 0, total_latency_us: 0, violations: 0}}
  end
  
  @impl true
  def handle_info({:process, event_type, data, start_time}, state) do
    # Process the event
    process_event(event_type, data)
    
    # Calculate latency
    end_time = System.monotonic_time()
    latency_us = System.convert_time_unit(end_time - start_time, :native, :microsecond)
    
    # Log if exceeding target (100ms = 100,000µs)
    violations = if latency_us > 100_000 do
      Logger.warning("FAST lane latency exceeded: #{div(latency_us, 1000)}ms for #{event_type}")
      state.violations + 1
    else
      state.violations
    end
    
    {:noreply, %{state | 
      processed: state.processed + 1,
      total_latency_us: state.total_latency_us + latency_us,
      violations: violations
    }}
  end
  
  defp process_event(event_type, data) do
    # Route to Python bridge or handle internally
    case event_type do
      "system_health_changed" ->
        # Update health metrics
        :ok
        
      "mesh_signal" ->
        # Forward to mesh consumer
        :ok
        
      _ ->
        # Default processing
        :ok
    end
  end
end


defmodule WhitemagicCore.GanYing.MediumLanePool do
  @moduledoc """
  Pool of workers for MEDIUM lane events (<1s latency target).
  """
  use GenServer
  require Logger
  
  @max_mailbox_size 200
  @target_latency_ms 1000
  
  def start_link(opts) do
    pool_size = Keyword.get(opts, :pool_size, 4)
    GenServer.start_link(__MODULE__, %{pool_size: pool_size}, name: __MODULE__)
  end
  
  def emit(event_type, data) do
    GenServer.cast(__MODULE__, {:emit_medium, event_type, data})
  end
  
  @impl true
  def init(%{pool_size: size}) do
    workers = Enum.map(1..size, fn i ->
      {:ok, pid} = WhitemagicCore.GanYing.MediumLaneWorker.start_link(id: i)
      pid
    end)
    
    {:ok, %{
      workers: workers,
      next_worker: 0,
      emitted: 0,
      dropped: 0
    }}
  end
  
  @impl true
  def handle_cast({:emit_medium, event_type, data}, state) do
    worker_idx = rem(state.next_worker, length(state.workers))
    worker = Enum.at(state.workers, worker_idx)
    
    case Process.info(worker, :message_queue_len) do
      {:message_queue_len, len} when len < @max_mailbox_size ->
        send(worker, {:process, event_type, data})
        {:noreply, %{state | 
          next_worker: worker_idx + 1,
          emitted: state.emitted + 1
        }}
      
      _ ->
        Logger.warning("MEDIUM lane backpressure: dropping #{event_type}")
        {:noreply, %{state | dropped: state.dropped + 1}}
    end
  end
end


defmodule WhitemagicCore.GanYing.MediumLaneWorker do
  @moduledoc """
  Individual MEDIUM lane worker.
  """
  use GenServer
  require Logger
  
  def start_link(id: id) do
    GenServer.start_link(__MODULE__, %{id: id}, name: String.to_atom("medium_lane_#{id}"))
  end
  
  @impl true
  def init(%{id: id}) do
    {:ok, %{id: id, processed: 0}}
  end
  
  @impl true
  def handle_info({:process, event_type, data}, state) do
    # Process medium-priority event
    process_event(event_type, data)
    {:noreply, %{state | processed: state.processed + 1}}
  end
  
  defp process_event(_event_type, _data) do
    # Medium lane processing
    :ok
  end
end
