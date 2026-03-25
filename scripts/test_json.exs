defmodule TestJson do
  def run do
    try do
      # Test if Jason is available
      map = %{type: "test", interesting: true}
      json = Jason.encode!(map)
      IO.puts("JSON works: #{json}")
    rescue
      e -> IO.puts("Error: #{inspect(e)}")
    end
  end
end
TestJson.run()
