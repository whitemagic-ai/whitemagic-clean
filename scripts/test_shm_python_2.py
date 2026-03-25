import subprocess
import time

print("Starting Koka SHM consumer...")
proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_consumer'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

# Wait 2 seconds to see what it prints
time.sleep(1)

# Check if process is still alive
if proc.poll() is not None:
    print(f"Process died with exit code {proc.poll()}")
    print("Stderr:", proc.stderr.read())
else:
    print("Process is running")
    print("Trying to read a line...")
    line = proc.stdout.readline()
    print("Line:", line.strip())

proc.kill()
