
import subprocess
import time
import os

binary_path = "./whitemagic-koka/batch_ipc"
print(f"Testing binary: {binary_path}")

cmd = ["stdbuf", "-oL", binary_path]
proc = subprocess.Popen(
    cmd,
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

print("Process started, waiting for output...")
start_time = time.time()
while True:
    line = proc.stdout.readline()
    if line:
        print(f"Received line: {repr(line)}")
        break
    if time.time() - start_time > 5:
        print("Timed out after 5 seconds waiting for stdout.")
        break
    time.sleep(0.1)

print("Checking stderr...")
stderr_output = proc.stderr.read(100) # Non-blocking might be better but let's try
if stderr_output:
    print(f"Stderr: {repr(stderr_output)}")

proc.terminate()
