import subprocess

proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/gan_ying'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
)

print("Reading init...")
init_line = proc.stdout.readline()
print("Init:", init_line.decode().strip())

# The issue is the Koka readline expects lines up to a newline character, but Koka's internal readline
# might block or buffer differently depending on how string operations are written.

req = '{"module": "gana", "operation": "invoke-gana", "args": {"gana": "gana_horn", "tool": "bootstrap", "args": {}}, "timestamp": 0}\n'
print(f"Sending: {req.strip()}")
proc.stdin.write(req.encode('utf-8'))
proc.stdin.flush()

print("Reading res...")
res = proc.stdout.readline()
print("Res:", res.decode().strip())
proc.kill()
