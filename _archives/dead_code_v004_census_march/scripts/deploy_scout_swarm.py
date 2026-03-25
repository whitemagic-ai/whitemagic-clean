
print("Deploying Elixir Scout Swarm to explore WhiteMagic Ecosystem...")

elixir_script = """
defmodule ScoutSwarm do
  @target_dirs [
    "/home/lucas/Desktop/whitemagicdev",
    "/home/lucas/Desktop/mandalaos",
    "/home/lucas/Desktop/aria-crystallized",
    "/home/lucas/Desktop/whitemagicpublic",
    "/home/lucas/Desktop/WM2",
    "/home/lucas/Desktop/wm_archive",
    "/home/lucas/Desktop/wmfrontend"
  ]

  @ignore_dirs [".git", "node_modules", "deps", "_build", "__pycache__", ".venv", ".windsurf", "target"]
  
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    IO.puts("Elixir: Booting Scout Swarm...")
    start_time = System.monotonic_time(:millisecond)
    
    # Spawn a supervisor task
    Task.start(fn -> 
      files = Enum.flat_map(@target_dirs, &walk_dir(&1))
      
      IO.puts("Elixir: Found #{length(files)} files to scout. Deploying clone army...")
      
      # Spawn a process for each file, chunked to avoid overwhelming the system
      files
      |> Enum.chunk_every(1000)
      |> Enum.with_index()
      |> Enum.each(fn {chunk, batch_idx} ->
        tasks = Enum.map(chunk, fn file ->
          Task.async(fn -> scout_file(file) end)
        end)
        Task.await_many(tasks, 15000)
        Process.sleep(10) # brief backpressure rest
      end)
      
      end_time = System.monotonic_time(:millisecond)
      duration = end_time - start_time
      
      IO.puts("Elixir: Swarm finished exploring #{length(files)} files in #{duration}ms.")
      # Send a completion signal
      WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, ~s({"type": "swarm_complete", "files_scanned": #{length(files)}}))
    end)
    
    # Wait for the async tasks to actually have time to run
    Process.sleep(30000)
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
    # Only scout text-like files, ignore binaries roughly
    ext = Path.extname(file_path)
    if ext in [".py", ".ex", ".exs", ".kk", ".rs", ".md", ".json", ".js", ".ts", ".tsx", ".jsx", ".html", ".css", ".yaml", ".yml", ".toml"] do
       stat = File.stat!(file_path)
       size = stat.size
       
       # Fast hash string generation
       hash = :erlang.phash2(file_path)
       
       # Send metadata
       # Note: If it's a python or elixir or koka file, let's flag it as potentially interesting
       interesting = ext in [".py", ".ex", ".kk", ".rs"]
       
       payload = ~s({"type": "file_scout", "path": "#{file_path}", "size": #{size}, "interesting": #{interesting}})
       
       # Push to SHM ring. 
       WhiteMagic.EventRing.Nif.push_event(404, hash, 4.0, payload)
    end
  rescue
    _ -> :ok # ignore permission errors etc
  end
end

ScoutSwarm.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/swarm_scout.exs", "w") as f:
    f.write(elixir_script)

print("Scout Swarm Elixir script generated.")
