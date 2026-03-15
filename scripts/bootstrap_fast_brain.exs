defmodule FastBrainBootstrap do
  def run do
    IO.puts("Bootstrapping Koka Fast Brain with highly interesting ecosystem files...")
    
    # Init SHM
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    # Load targets
    files = File.stream!("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl")
    |> Stream.map(&Jason.decode!/1)
    |> Enum.sort_by(fn %{"score" => score, "size" => size} -> {score, size} end, :desc)
    |> Enum.take(2000)
    
    IO.puts("Selected top #{length(files)} files to stream.")
    
    files
    |> Enum.chunk_every(20)
    |> Enum.each(fn chunk ->
      Enum.each(chunk, fn %{"path" => path, "size" => _size, "score" => score} ->
         if File.exists?(path) do
             content = 
               case File.open(path, [:read, :utf8]) do
                 {:ok, pid} -> 
                   data = IO.binread(pid, 2000)
                   File.close(pid)
                   if data == :eof, do: "", else: data
                 _ -> ""
               end
               
             if is_binary(content) and String.length(content) > 0 do
                 safe_content = content
                   |> String.chunk(:printable)
                   |> Enum.filter(&String.valid?/1)
                   |> Enum.join("")
                   
                 if String.length(safe_content) > 0 do
                     hash = :erlang.phash2(path)
                     
                     map = %{
                       type: "knowledge_ingest",
                       path: path,
                       score: score,
                       content: safe_content
                     }
                     
                     try do
                       payload = Jason.encode!(map)
                       WhiteMagic.EventRing.Nif.push_event(405, hash, 5.0, payload)
                     rescue
                       _ -> :ok # silently skip failing encodings
                     end
                 end
             end
         end
      end)
      Process.sleep(50) # drain time
    end)
    
    WhiteMagic.EventRing.Nif.push_event(999, 0, 9.9, Jason.encode!(%{type: "bootstrap_complete", files: length(files)}))
    IO.puts("Bootstrap push complete.")
  end
end

FastBrainBootstrap.run()
