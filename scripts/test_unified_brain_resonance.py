import subprocess
import time

print("Setting up Unified Fast Brain Resonance Test...")

elixir_script = """
defmodule TestRunner do
  def run do
    IO.puts("Elixir: Initializing SHM Ring...")
    case WhiteMagic.EventRing.Nif.init_shm_ring() do
      :ok -> IO.puts("Elixir: SHM Ring Initialized.")
      error -> IO.puts("Elixir: Failed to initialize: #{inspect(error)}")
    end
    Process.sleep(500)
    
    IO.puts("Elixir: Sending event 1")
    WhiteMagic.EventRing.Nif.push_event(101, 555, 1.0, ~s({"type": "clone_heartbeat", "cpu": 45}))
    
    IO.puts("Elixir: Sending event 2")
    WhiteMagic.EventRing.Nif.push_event(202, 777, 2.0, ~s({"query": "How does the SHM architecture improve vector search latency?"}))
    
    Process.sleep(1000)
  end
end
TestRunner.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/test_resonance.exs", "w") as f:
    f.write(elixir_script)

koka_proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    text=True,
    bufsize=1
)

time.sleep(1)

elixir_proc = subprocess.Popen(
    ['mix', 'run', '--no-start', 'test_resonance.exs'],
    cwd='/home/lucas/Desktop/whitemagicdev/elixir',
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

try:
    for i in range(5):
        line = koka_proc.stdout.readline()
        if not line: break
        print(f"Koka: {line.strip()}")
        if "system_resonance_achieved" in line:
            print("Successfully hit the resonance loop!")
except Exception as e:
    print(f"Error reading koka: {e}")

elixir_out, elixir_err = elixir_proc.communicate()
print(f"Elixir Out:\n{elixir_out}")
if elixir_err:
    print(f"Elixir Err:\n{elixir_err}")

koka_proc.kill()
print("Test Complete.")
