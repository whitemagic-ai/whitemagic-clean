defmodule ScoutSwarm do
  @target_dirs [
    "/home/lucas/Desktop/whitemagicdev"
  ]

  @ignore_dirs [".git", "node_modules", "deps", "_build", "__pycache__", ".venv", ".windsurf", "target"]
  
  def run do
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    IO.puts("Found #{length(files)} files.")
    
    tasks = Task.async_stream(Enum.take(files, 50), fn file -> 
      IO.puts("Processing #{file}")
    end, max_concurrency: 10)
    
    Stream.run(tasks)
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
end

ScoutSwarm.run()
