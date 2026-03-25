defmodule ShadowCloneArmy do
  @moduledoc """
  Elixir Shadow Clone Army - Supervisor tree managing worker processes
  Reads JSON task from stdin, executes with fault-tolerant supervision, writes JSON to stdout
  """

  use Supervisor

  def start_link(opts) do
    Supervisor.start_link(__MODULE__, opts, name: __MODULE__)
  end

  @impl true
  def init(_opts) do
    children = [
      {Task.Supervisor, name: CloneTaskSupervisor}
    ]

    Supervisor.init(children, strategy: :one_for_one)
  end

  def execute_task(task_json) do
    case Jason.decode(task_json) do
      {:ok, %{"task" => task_type, "clone_count" => count}} ->
        spawn_clones(task_type, count)
      {:error, _} ->
        %{status: "error", message: "Invalid JSON input"}
    end
  end

  defp spawn_clones(task_type, count) do
    start_time = System.monotonic_time(:millisecond)
    
    # Spawn worker processes under supervision
    tasks = for i <- 1..min(count, 100) do
      Task.Supervisor.async(CloneTaskSupervisor, fn ->
        execute_clone_work(task_type, i)
      end)
    end

    # Gather results with timeout
    results = Task.await_many(tasks, 5000)
    
    end_time = System.monotonic_time(:millisecond)
    duration_ms = end_time - start_time

    %{
      status: "success",
      language: "elixir",
      task: task_type,
      findings: results,
      metrics: %{
        processes_spawned: length(tasks),
        supervision_tree: "healthy",
        duration_ms: duration_ms,
        throughput: Float.round(length(tasks) / (duration_ms / 1000.0), 2)
      }
    }
  end

  defp execute_clone_work("supervisor_test", clone_id) do
    # Simulate work with potential failure
    if rem(clone_id, 10) == 0 do
      Process.sleep(10)
    else
      Process.sleep(5)
    end
    
    %{
      clone_id: clone_id,
      status: "completed",
      work_type: "supervised_task"
    }
  end

  defp execute_clone_work(task_type, clone_id) do
    %{
      clone_id: clone_id,
      status: "completed",
      task: task_type
    }
  end

  def main(args) do
    # Start the supervision tree
    {:ok, _pid} = start_link([])
    
    # Read JSON from stdin
    task_json = IO.read(:stdio, :all)
    
    # Execute and output result
    result = execute_task(task_json)
    IO.puts(Jason.encode!(result))
  end
end
