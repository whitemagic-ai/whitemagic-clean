# Elixir Hot Path Translations - OTP Concurrency
# Phase E: 8 functions for GenServer pools and parallel processing

defmodule HotPaths do
  @moduledoc """
  OTP-based parallel processing for association mining,
  batch operations, and distributed coordination.
  """

  use GenServer
  require Logger

  # ===================================================================
  # GenServer Pool for Association Mining
  # ===================================================================

  @doc """
  Start a pool of workers for parallel association mining.
  """
  def start_mining_pool(pool_size \\ 4) do
    1..pool_size
    |> Enum.map(fn i ->
      GenServer.start_link(__MODULE__, %{}, name: :"miner_#{i}")
    end)
    |> Enum.map(&elem(&1, 1))
  end

  @doc """
  Parallel batch mining with worker pool.
  """
  def batch_mine_parallel(memories, similarity_threshold \\ 0.3, max_proposals \\ 100) do
    pool = start_mining_pool()
    
    # Split memories into chunks
    chunk_size = max(1, div(length(memories), length(pool)))
    chunks = Enum.chunk_every(memories, chunk_size)
    
    # Distribute to workers
    tasks = Enum.zip(pool, chunks)
    |> Enum.map(fn {worker, chunk} ->
      Task.async(fn ->
        GenServer.call(worker, {:mine_proposals, chunk, similarity_threshold, max_proposals})
      end)
    end)
    
    # Collect results
    results = Task.await_many(tasks, 30_000)
    List.flatten(results)
    |> Enum.take(max_proposals)
  end

  @doc """
  Parallel sort using merge sort with concurrent merging.
  """
  def parallel_sort(list, reverse \\ false, depth \\ 0)
  def parallel_sort([], _, _), do: []
  def parallel_sort([x], _, _), do: [x]
  
  def parallel_sort(list, reverse, depth) do
    len = length(list)
    mid = div(len, 2)
    {left, right} = Enum.split(list, mid)
    
    # Use Task for parallel sorting at top levels
    if depth < 3 do
      [sorted_left, sorted_right] = 
        [left, right]
        |> Enum.map(&Task.async(fn -> parallel_sort(&1, reverse, depth + 1) end))
        |> Task.await_many()
      
      merge(sorted_left, sorted_right, reverse)
    else
      # Sequential below depth 3
      sorted_left = parallel_sort(left, reverse, depth + 1)
      sorted_right = parallel_sort(right, reverse, depth + 1)
      merge(sorted_left, sorted_right, reverse)
    end
  end

  defp merge(left, right, reverse) do
    compare = if reverse, do: &>=/2, else: &<=/2
    do_merge(left, right, [], compare)
  end
  
  defp do_merge([], right, acc, _), do: Enum.reverse(acc, right)
  defp do_merge(left, [], acc, _), do: Enum.reverse(acc, left)
  defp do_merge([h1 | t1], [h2 | t2], acc, compare) do
    if compare.(h1, h2) do
      do_merge(t1, [h2 | t2], [h1 | acc], compare)
    else
      do_merge([h1 | t1], t2, [h2 | acc], compare)
    end
  end

  @doc """
  Async batch store with backpressure.
  """
  def async_batch_store(memories, backend_fn, batch_size \\ 100, concurrency \\ 4) do
    memories
    |> Enum.chunk_every(batch_size)
    |> Enum.map(fn batch ->
      Task.async(fn ->
        Enum.map(batch, &backend_fn.(&1))
      end)
    end)
    |> Enum.chunk_every(concurrency)
    |> Enum.flat_map(fn chunk ->
      Task.await_many(chunk, 60_000)
      |> List.flatten()
    end)
  end

  @doc """
  Concurrent archival sweep with GenStage-like backpressure.
  """
  def concurrent_sweep(memories, batch_size \\ 1000, max_concurrent \\ 4) do
    memories
    |> Enum.chunk_every(batch_size)
    |> Enum.map(fn batch ->
      Task.async(fn ->
        analyze_decay_batch(batch)
      end)
    end)
    |> Enum.chunk_every(max_concurrent)
    |> Enum.reduce([], fn chunk, acc ->
      results = Task.await_many(chunk, 30_000)
      to_archive = results
      |> List.flatten()
      |> Enum.filter(& &1.should_forget)
      |> Enum.map(& &1.memory_id)
      
      acc ++ to_archive
    end)
  end

  defp analyze_decay_batch(batch) do
    now = System.system_time(:second)
    
    Enum.map(batch, fn mem ->
      last_access = Map.get(mem, "accessed_at", Map.get(mem, "created_at", 0))
      days_since = (now - last_access) / 86400
      
      importance = Map.get(mem, "importance", 0.5)
      half_life = Map.get(mem, "half_life_days", 30.0)
      
      effective_half_life = half_life * (1 + importance)
      decay = :math.exp(-days_since / effective_half_life)
      
      %{
        memory_id: Map.get(mem, "id"),
        decay_factor: decay,
        should_forget: decay < 0.1 && !Map.get(mem, "is_protected", false),
        days_since_access: days_since
      }
    end)
  end

  @doc """
  Parallel file loading for campaign batches.
  """
  def parallel_file_load(file_paths, max_concurrent \\ 4) do
    file_paths
    |> Enum.map(fn path ->
      Task.async(fn -> load_campaign_file(path) end)
    end)
    |> Enum.chunk_every(max_concurrent)
    |> Enum.flat_map(fn chunk ->
      Task.await_many(chunk, 10_000)
      |> Enum.filter(& &1 != nil)
    end)
  end

  defp load_campaign_file(path) do
    case File.read(path) do
      {:ok, content} ->
        parse_frontmatter(content, path)
      {:error, _} ->
        nil
    end
  end

  defp parse_frontmatter(content, path) do
    if String.starts_with?(content, "---") do
      parts = String.split(content, "---", parts: 3)
      if length(parts) >= 3 do
        # Simple YAML-like parsing
        [_, frontmatter, _] = parts
        
        %{
          path: path,
          name: extract_field(frontmatter, "name") || "Unknown",
          codename: extract_field(frontmatter, "codename") || "???",
          priority: extract_field(frontmatter, "priority") || "P3",
          status: extract_field(frontmatter, "status") || "PLANNED"
        }
      else
        nil
      end
    else
      nil
    end
  end

  defp extract_field(text, field) do
    regex = Regex.compile!("^#{field}:\\s*(.+)$", [:multiline])
    case Regex.run(regex, text) do
      [_, value] -> String.trim(value)
      _ -> nil
    end
  end

  @doc """
  Actor-based salience arbitration.
  """
  def arbitrate_salience(candidates, current_load \\ 0.5, max_concurrent \\ 5) do
    # Create priority queue using heap-like structure
    scored = Enum.map(candidates, fn c ->
      urgency = Map.get(c, "urgency", 0.5)
      importance = Map.get(c, "importance", 0.5)
      energy = Map.get(c, "energy_cost", 0.3)
      
      time_pressure = 1.0 + current_load
      adjusted_urgency = urgency * time_pressure
      score = adjusted_urgency * 0.4 + importance * 0.4 - energy * 0.2
      
      {Map.get(c, "id"), max(0.0, min(1.0, score))}
    end)
    
    scored
    |> Enum.sort_by(fn {_, score} -> -score end)
    |> Enum.take(max_concurrent)
    |> Enum.map(fn {id, _} -> id end)
  end

  @doc """
  Distributed aggregate findings using CRDT-like merging.
  """
  def distributed_aggregate(findings, strategy \\ "consensus") do
    case strategy do
      "consensus" ->
        counts = Enum.reduce(findings, %{}, fn finding, acc ->
          Map.update(acc, finding, 1, &(&1 + 1))
        end)
        
        {top, count} = Enum.max_by(counts, fn {_, c} -> c end)
        total = length(findings)
        
        %{
          consensus: top,
          confidence: count / total,
          total: total,
          distribution: counts
        }
        
      "union" ->
        unique = Enum.uniq(findings)
        %{
          findings: unique,
          count: length(unique),
          strategy: "union"
        }
        
      _ ->
        %{findings: findings, strategy: "passthrough"}
    end
  end

  @doc """
  OTP GenServer callbacks.
  """
  @impl true
  def init(state) do
    {:ok, state}
  end

  @impl true
  def handle_call({:mine_proposals, memories, threshold, max_count}, _from, state) do
    # Keyword extraction (simplified)
    results = mine_proposals_chunk(memories, threshold, max_count)
    {:reply, results, state}
  end

  defp mine_proposals_chunk(memories, threshold, max_count) do
    # Simplified mining logic
    n = length(memories)
    
    for i <- 0..(n-1), j <- (i+1)..(n-1), reduce: [] do
      acc ->
        if length(acc) >= max_count do
          acc
        else
          m1 = Enum.at(memories, i)
          m2 = Enum.at(memories, j)
          
          tags1 = extract_keywords(Map.get(m1, "content", ""))
          tags2 = extract_keywords(Map.get(m2, "content", ""))
          
          sim = jaccard_sim(tags1, tags2)
          
          if sim >= threshold do
            acc ++ [%{
              source_id: Map.get(m1, "id"),
              target_id: Map.get(m2, "id"),
              strength: Float.round(sim, 3),
              shared_keywords: Enum.take(Enum.uniq(tags1 ++ tags2), 10)
            }]
          else
            acc
          end
        end
    end
  end

  defp extract_keywords(text) do
    text
    |> String.downcase()
    |> String.split(~r/[^a-z0-9_]+/)
    |> Enum.filter(&String.length(&1) > 2)
    |> Enum.take(50)
  end

  defp jaccard_sim(a, b) do
    set_a = MapSet.new(a)
    set_b = MapSet.new(b)
    
    intersection = MapSet.size(MapSet.intersection(set_a, set_b))
    union = MapSet.size(MapSet.union(set_a, set_b))
    
    if union > 0, do: intersection / union, else: 0.0
  end
end
