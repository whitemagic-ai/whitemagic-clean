import json
import subprocess

proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/gan_ying'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

print("Reading init:", proc.stdout.readline().strip())

req = json.dumps({"module": "gana", "operation": "invoke-gana", "args": {"gana": "gana_horn", "tool": "bootstrap", "args": {}}, "timestamp": 0})
print(f"Sending: {req}")
proc.stdin.write(req + '\n')
proc.stdin.flush()

print("Reading res:", proc.stdout.readline().strip())
proc.kill()
