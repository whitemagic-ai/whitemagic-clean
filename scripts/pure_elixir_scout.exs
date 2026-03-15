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
    IO.puts("Elixir: Booting Scout Swarm...")
    
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    
    IO.puts("Elixir: Found #{length(files)} files to scout. Deploying clone army...")
    
    out_file = File.open!("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl", [:write, :utf8])
    
    files
    |> Task.async_stream(fn file -> scout_file(file) end, max_concurrency: 100, timeout: 15000)
    |> Stream.filter(fn {:ok, res} -> res != nil end)
    |> Enum.each(fn {:ok, res} -> 
      IO.write(out_file, Jason.encode!(res) <> "\n")
    end)
    
    File.close(out_file)
    IO.puts("Elixir: Swarm finished exploring #{length(files)} files.")
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
       
       interesting_score = 
         if size > 0 and size < 100000 do
           case File.read(file_path) do
             {:ok, content} -> 
               score1 = if String.contains?(content, "Mandala"), do: 10, else: 0
               score2 = if String.contains?(content, "AI"), do: 5, else: 0
               score3 = if String.contains?(content, "WhiteMagic"), do: 5, else: 0
               score4 = if String.contains?(content, "Campaign"), do: 5, else: 0
               score5 = if String.contains?(content, "Agent"), do: 5, else: 0
               score6 = if String.contains?(content, "Fast Brain"), do: 10, else: 0
               score7 = if String.contains?(content, "Memory"), do: 5, else: 0
               score1 + score2 + score3 + score4 + score5 + score6 + score7
             _ -> 0
           end
         else
           0
         end
       
       if interesting_score >= 10 do
           %{
             type: "file_scout",
             path: file_path,
             size: size,
             interesting: true,
             score: interesting_score
           }
       else
           nil
       end
    else
       nil
    end
  rescue
    _ -> nil
  end
end

ScoutSwarm.run()
