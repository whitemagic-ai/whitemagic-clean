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
    
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    
    IO.puts("Elixir: Found #{length(files)} files to scout. Deploying clone army...")
    
    # Process sequentially but batched to ensure we don't overwhelm Koka's 1024 ring buffer
    files
    |> Enum.chunk_every(100)
    |> Enum.each(fn chunk ->
      Enum.each(chunk, &scout_file/1)
      Process.sleep(5) # Let Koka drain the ring
    end)
    
    IO.puts("Elixir: Swarm finished exploring #{length(files)} files.")
    
    payload_end = Jason.encode!(%{type: "swarm_complete", files_scanned: length(files)})
    WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, payload_end)
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
       
       interesting_score = 0
       if size > 0 and size < 50000 do
         case File.read(file_path) do
           {:ok, content} -> 
             score1 = if String.contains?(content, "Mandala"), do: 10, else: 0
             score2 = if String.contains?(content, "AI"), do: 5, else: 0
             score3 = if String.contains?(content, "WhiteMagic"), do: 5, else: 0
             score4 = if String.contains?(content, "Campaign"), do: 5, else: 0
             score5 = if String.contains?(content, "Agent"), do: 5, else: 0
             score6 = if String.contains?(content, "Fast Brain"), do: 10, else: 0
             score7 = if String.contains?(content, "Memory"), do: 5, else: 0
             interesting_score = score1 + score2 + score3 + score4 + score5 + score6 + score7
           _ -> :ok
         end
       end
       
       hash = :erlang.phash2(file_path)
       is_interesting = interesting_score >= 10
       
       if is_interesting do
           map = %{
             type: "file_scout",
             path: file_path,
             size: size,
             interesting: true,
             score: interesting_score
           }
           payload = Jason.encode!(map)
           WhiteMagic.EventRing.Nif.push_event(404, hash, 4.0, payload)
       end
    end
  rescue
    _ -> :ok
  end
end

ScoutSwarm.run()
