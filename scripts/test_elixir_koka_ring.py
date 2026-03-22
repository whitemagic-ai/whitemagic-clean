import subprocess
import time

print("Setting up End-to-End SHM Ring Pipeline Test...")

# 1. Start Elixir Producer FIRST because it will CREATE the SHM segment
elixir_script = """
defmodule TestRunner do
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    case WhiteMagic.EventRing.Nif.init_shm_ring() do
      :ok -> IO.puts("Elixir: SHM Ring Initialized.")
      error ->
        IO.puts("Elixir: Failed to initialize: #{inspect(error)}")
        System.halt(1)
    end

    IO.puts("Elixir: Sleeping to allow Koka to connect...")
    Process.sleep(1000)

    IO.puts("Elixir: Pushing event 1...")
    WhiteMagic.EventRing.Nif.push_event(42, 12345, 1234567.89, "Hello from Elixir!")

    IO.puts("Elixir: Pushing event 2...")
    WhiteMagic.EventRing.Nif.push_event(99, 54321, 9876543.21, ~s({"query": "Find fast lane"}))

    IO.puts("Elixir: Done pushing. Waiting for Koka to process...")
    Process.sleep(2000)
  end
end

TestRunner.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/test_ring.exs", "w") as f:
    f.write(elixir_script)

print("Starting Elixir Producer...")
elixir_proc = subprocess.Popen(
    ['mix', 'run', '--no-start', 'test_ring.exs'],
    cwd='/home/lucas/Desktop/whitemagicdev/elixir',
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

# Wait a moment to ensure Elixir has initialized the ring
time.sleep(1.5)

# 2. Start Koka Consumer
koka_proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_ring_consumer'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    bufsize=1
)

# Monitor Koka output
try:
    for i in range(5):
        line = koka_proc.stdout.readline()
        if not line: break
        print(f"Koka: {line.strip()}")
        if "event_received" in line and "Find fast lane" in line:
            break
except Exception as e:
    print(f"Error reading koka: {e}")

# Check Elixir output
elixir_out, elixir_err = elixir_proc.communicate()
print(f"\nElixir Output:\n{elixir_out}")
if elixir_err:
    print(f"Elixir Errors:\n{elixir_err}")

koka_proc.kill()
print("Test Complete.")
