import pty
import os
import sys

master, slave = pty.openpty()
import subprocess
proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=slave,
    stdout=slave,
    stderr=slave
)
os.close(slave)

# read output
output = os.read(master, 1024)
print("init:", output.decode().strip())

os.write(master, b'{"op":"ping"}\n')
res = os.read(master, 1024)
print("res:", res.decode().strip())

proc.kill()
