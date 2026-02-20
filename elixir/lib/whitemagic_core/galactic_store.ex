defmodule WhiteMagicCore.GalacticStore do
  @moduledoc """
  High-performance concurrent memory store using Elixir's actor model.
  
  Replaces SQLite bottleneck with:
  - ETS tables for fast in-memory access
  - GenServer for coordinated writes
  - Periodic persistence to disk
  - Connection pooling via Registry
  """
  
  use GenServer
  require Logger
  
  @table_name :galactic_memories
  @index_table :galactic_index
  @persist_interval 60_000  # Persist every 60 seconds
  
  # Client API
  
  def start_link(opts \\ []) do
    GenServer.start_link(__MODULE__, opts, name: __MODULE__)
  end
  
  @doc """
  Store a memory with holographic coordinates.
  """
  def store_memory(memory_id, content, metadata \\ %{}) do
    GenServer.call(__MODULE__, {:store, memory_id, content, metadata})
  end
  
  @doc """
  Retrieve a memory by ID.
  """
  def get_memory(memory_id) do
    case :ets.lookup(@table_name, memory_id) do
      [{^memory_id, content, metadata, _timestamp}] ->
        {:ok, %{id: memory_id, content: content, metadata: metadata}}
      [] ->
        {:error, :not_found}
    end
  end
  
  @doc """
  Search memories by query (uses ETS match patterns).
  """
  def search_memories(query, limit \\ 100) do
    GenServer.call(__MODULE__, {:search, query, limit})
  end
  
  @doc """
  Batch write multiple memories (atomic operation).
  """
  def batch_write(memories) do
    GenServer.call(__MODULE__, {:batch_write, memories})
  end
  
  @doc """
  Get statistics about the store.
  """
  def stats do
    GenServer.call(__MODULE__, :stats)
  end
  
  # Server Callbacks
  
  @impl true
  def init(_opts) do
    # Create ETS tables
    :ets.new(@table_name, [:named_table, :set, :public, read_concurrency: true])
    :ets.new(@index_table, [:named_table, :bag, :public, read_concurrency: true])
    
    # Schedule periodic persistence
    schedule_persist()
    
    # Try to load from disk
    load_from_disk()
    
    Logger.info("GalacticStore initialized with ETS tables")
    
    {:ok, %{
      write_count: 0,
      read_count: 0,
      last_persist: System.monotonic_time(:second)
    }}
  end
  
  @impl true
  def handle_call({:store, memory_id, content, metadata}, _from, state) do
    timestamp = System.system_time(:second)
    
    # Store in main table
    :ets.insert(@table_name, {memory_id, content, metadata, timestamp})
    
    # Update indexes (tags, galactic coordinates, etc.)
    update_indexes(memory_id, metadata)
    
    {:reply, :ok, %{state | write_count: state.write_count + 1}}
  end
  
  @impl true
  def handle_call({:search, query, limit}, _from, state) do
    results = perform_search(query, limit)
    {:reply, {:ok, results}, %{state | read_count: state.read_count + 1}}
  end
  
  @impl true
  def handle_call({:batch_write, memories}, _from, state) do
    timestamp = System.system_time(:second)
    
    # Atomic batch insert
    entries = Enum.map(memories, fn %{id: id, content: content, metadata: metadata} ->
      {id, content, metadata, timestamp}
    end)
    
    :ets.insert(@table_name, entries)
    
    # Update indexes for all
    Enum.each(memories, fn %{id: id, metadata: metadata} ->
      update_indexes(id, metadata)
    end)
    
    {:reply, {:ok, length(memories)}, %{state | write_count: state.write_count + length(memories)}}
  end
  
  @impl true
  def handle_call(:stats, _from, state) do
    memory_count = :ets.info(@table_name, :size)
    index_count = :ets.info(@index_table, :size)
    
    stats = %{
      memory_count: memory_count,
      index_count: index_count,
      write_count: state.write_count,
      read_count: state.read_count,
      last_persist: state.last_persist,
      uptime_seconds: System.monotonic_time(:second) - state.last_persist
    }
    
    {:reply, stats, state}
  end
  
  @impl true
  def handle_info(:persist, state) do
    persist_to_disk()
    schedule_persist()
    
    {:noreply, %{state | last_persist: System.monotonic_time(:second)}}
  end
  
  # Private Functions
  
  defp update_indexes(memory_id, metadata) do
    # Index by tags
    if tags = Map.get(metadata, :tags) do
      Enum.each(tags, fn tag ->
        :ets.insert(@index_table, {{:tag, tag}, memory_id})
      end)
    end
    
    # Index by galactic zone
    if zone = Map.get(metadata, :galactic_zone) do
      :ets.insert(@index_table, {{:zone, zone}, memory_id})
    end
    
    # Index by memory type
    if type = Map.get(metadata, :memory_type) do
      :ets.insert(@index_table, {{:type, type}, memory_id})
    end
  end
  
  defp perform_search(query, limit) do
    case query do
      {:tag, tag} ->
        :ets.lookup(@index_table, {:tag, tag})
        |> Enum.take(limit)
        |> Enum.map(fn {_, memory_id} -> get_memory(memory_id) end)
        |> Enum.filter(&match?({:ok, _}, &1))
        |> Enum.map(fn {:ok, mem} -> mem end)
      
      {:zone, zone} ->
        :ets.lookup(@index_table, {:zone, zone})
        |> Enum.take(limit)
        |> Enum.map(fn {_, memory_id} -> get_memory(memory_id) end)
        |> Enum.filter(&match?({:ok, _}, &1))
        |> Enum.map(fn {:ok, mem} -> mem end)
      
      _ ->
        # Full scan (fallback)
        :ets.tab2list(@table_name)
        |> Enum.take(limit)
        |> Enum.map(fn {id, content, metadata, _ts} ->
          %{id: id, content: content, metadata: metadata}
        end)
    end
  end
  
  defp persist_to_disk do
    # Persist ETS tables to disk using :ets.tab2file
    data_dir = Path.join([System.user_home!(), ".whitemagic", "galactic_store"])
    File.mkdir_p!(data_dir)
    
    main_file = Path.join(data_dir, "memories.ets")
    index_file = Path.join(data_dir, "indexes.ets")
    
    :ets.tab2file(@table_name, String.to_charlist(main_file))
    :ets.tab2file(@index_table, String.to_charlist(index_file))
    
    Logger.debug("Persisted galactic store to disk")
  end
  
  defp load_from_disk do
    data_dir = Path.join([System.user_home!(), ".whitemagic", "galactic_store"])
    main_file = Path.join(data_dir, "memories.ets")
    index_file = Path.join(data_dir, "indexes.ets")
    
    if File.exists?(main_file) do
      :ets.file2tab(String.to_charlist(main_file))
      Logger.info("Loaded memories from disk")
    end
    
    if File.exists?(index_file) do
      :ets.file2tab(String.to_charlist(index_file))
      Logger.info("Loaded indexes from disk")
    end
  end
  
  defp schedule_persist do
    Process.send_after(self(), :persist, @persist_interval)
  end
end
