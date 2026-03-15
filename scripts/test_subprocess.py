import subprocess
import time
import sys

proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
)

print("Reading init...")
init_line = proc.stdout.readline()
print("Init:", init_line.decode().strip())

print("Sending single ping...")
proc.stdin.write(b'{"op":"ping"}\n')
proc.stdin.flush()

print("Reading ping response...")
res = proc.stdout.readline()
print("Response:", res.decode().strip())

proc.kill()
