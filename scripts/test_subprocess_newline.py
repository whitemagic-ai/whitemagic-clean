import subprocess

proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
)

print("Reading init...")
init_line = proc.stdout.readline()
print("Init:", init_line.decode().strip())

print("Sending batch command with \\n...")
proc.stdin.write(b'{"mode":"sequential","request_id":"test-123","commands":[{"id":0,"op":"ping","payload":{}},{"id":1,"op":"ping","payload":{}}]}\n')
proc.stdin.flush()

print("Reading batch response...")
res = proc.stdout.readline()
print("Response:", res.decode().strip())

proc.kill()
