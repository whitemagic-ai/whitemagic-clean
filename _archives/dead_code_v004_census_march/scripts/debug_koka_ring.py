import subprocess
import time

print("Checking full event processing...")

koka_proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_fast_brain'],
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

time.sleep(1)

elixir_script = """
defmodule TestRunner do
  def run do
    WhiteMagic.EventRing.Nif.init_shm_ring()
    Process.sleep(100)
    
    WhiteMagic.EventRing.Nif.push_event(101, 1, 1.0, ~s({"type": "clone_heartbeat", "clone_id": 1}))
    WhiteMagic.EventRing.Nif.push_event(202, 2, 2.0, ~s({"query": "What is the optimal pathing?"}))
    WhiteMagic.EventRing.Nif.push_event(303, 3, 3.0, ~s({"prat_route": true, "search_memories": true}))
  end
end
TestRunner.run()
"""

with open("/home/lucas/Desktop/whitemagicdev/elixir/swarm_test.exs", "w") as f:
    f.write(elixir_script)

elixir_proc = subprocess.Popen(
    ['mix', 'run', '--no-start', 'swarm_test.exs'],
    cwd='/home/lucas/Desktop/whitemagicdev/elixir',
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

elixir_proc.wait()
time.sleep(1)

koka_proc.terminate()
koka_out, _ = koka_proc.communicate()

for line in koka_out.split('\\n'):
    if "status" in line:
        print(line)
