defmodule ScoutSwarm do
  @target_dirs [
    "/home/lucas/Desktop/whitemagicdev"
  ]

  @ignore_dirs [".git", "node_modules", "deps", "_build", "__pycache__", ".venv", ".windsurf", "target"]
  
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    IO.puts("Elixir: Booting Scout Swarm...")
    
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    
    files
    |> Enum.take(10)
    |> Enum.each(fn file ->
       scout_file(file)
    end)
    
    payload_end = Jason.encode!(%{type: "swarm_complete", files_scanned: 10})
    WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, payload_end)
    Process.sleep(100)
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
       
       map = %{
         type: "file_scout",
         path: file_path,
         size: size,
         interesting: true,
         score: 10
       }
       payload = Jason.encode!(map)
       WhiteMagic.EventRing.Nif.push_event(404, hash, 4.0, payload)
       IO.puts("Sent file: #{file_path}")
    end
  rescue
    _ -> :ok
  end
end

ScoutSwarm.run()
