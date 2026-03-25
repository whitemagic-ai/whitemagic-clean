import subprocess

proc = subprocess.Popen(
    ['stdbuf', '-o0', '-i0', '/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True
)

print("Reading init...")
init_line = proc.stdout.readline()
print("Init:", init_line.strip())

print("Sending batch command...")
proc.stdin.write('{"mode":"sequential","request_id":"test-123","commands":[{"id":0,"op":"ping","payload":{}},{"id":1,"op":"ping","payload":{}}]}\n')
proc.stdin.flush()

print("Reading batch response...")
res = proc.stdout.readline()
print("Response:", res.strip())

proc.kill()
