import subprocess

print("Starting Koka process...")
proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

print("Reading init line...")
print("Init:", proc.stdout.readline().strip())

print("Sending single ping...")
proc.stdin.write('{"op":"ping"}\n')
proc.stdin.flush()

print("Reading response...")
print("Response:", proc.stdout.readline().strip())

print("Sending quit...")
proc.stdin.write('quit\n')
proc.stdin.flush()
print("Done.")
