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
    start = System.monotonic_time(:millisecond)
    files = Enum.flat_map(@target_dirs, &walk_dir(&1))
    dur = System.monotonic_time(:millisecond) - start
    IO.puts("Elixir: Found #{length(files)} files to scout in #{dur}ms.")
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
