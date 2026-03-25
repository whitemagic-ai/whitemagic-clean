defmodule ScoutSwarm do
  @target_dirs [
    "/home/lucas/Desktop/whitemagicdev",
    "/home/lucas/Desktop/mandalaos"
  ]

  @ignore_dirs [".git", "node_modules", "deps", "_build", "__pycache__", ".venv", ".windsurf", "target"]
  
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    IO.puts("Elixir: Booting Scout Swarm...")
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    
    IO.puts("Elixir: Found #{length(files)} files to scout. Deploying clone army...")
    
    # Process 5000 files to test
    target_files = Enum.take(files, 5000)
    
    target_files
    |> Enum.chunk_every(100)
    |> Enum.each(fn chunk ->
      tasks = Enum.map(chunk, fn file ->
        Task.async(fn -> scout_file(file) end)
      end)
      Task.await_many(tasks, 5000)
      Process.sleep(5)
    end)
    
    WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, ~s({"type": "swarm_complete", "files_scanned": #{length(target_files)}}))
    IO.puts("Elixir: Sent 5000 files to ring buffer and completion signal.")
    Process.sleep(1000)
  end
  
  def walk_dir(dir) do
    cond do
      not File.exists?(dir) -> []
      not File.dir?(dir) -> [dir]
      true ->
        case File.ls(dir) do
          {:ok, files} ->
            files
            |> Enum.reject(fn f -> f in @ignore_dirs end)
            |> Enum.flat_map(fn f -> 
               path = Path.join(dir, f)
               if File.dir?(path) do
                 walk_dir(path)
               else
                 [path]
               end
            end)
          _ -> []
        end
    end
  end
  
  def scout_file(file_path) do
    ext = Path.extname(file_path)
    if ext in [".py", ".ex", ".exs", ".kk", ".rs", ".md", ".json", ".js", ".ts", ".tsx", ".jsx", ".html", ".css", ".yaml", ".yml", ".toml"] do
       stat = File.stat!(file_path)
       size = stat.size
       hash = :erlang.phash2(file_path)
       interesting = ext in [".py", ".ex", ".kk", ".rs"]
       # escape path just in case
       safe_path = String.replace(file_path, "\\"", "\\\\\\"")
       payload = ~s({"type": "file_scout", "path": "#{safe_path}", "size": #{size}, "interesting": #{interesting}})
       WhiteMagic.EventRing.Nif.push_event(404, hash, 4.0, payload)
    end
  rescue
    _ -> :ok
  end
end

ScoutSwarm.run()
