import subprocess
import time

print("Starting Koka process...")
proc = subprocess.Popen(
    ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
    stdin=subprocess.PIPE,
    stdout=subprocess.PIPE,
    stderr=subprocess.PIPE,
    text=True,
    bufsize=1
)

time.sleep(0.5)

print("Reading init line...")
print("Init:", proc.stdout.readline().strip())

print("Sending batch command...")
batch_req = '{"mode":"sequential","request_id":"test-123","commands":[{"id":0,"op":"ping","payload":{}},{"id":1,"op":"ping","payload":{}}]}\n'
proc.stdin.write(batch_req)
proc.stdin.flush()

print("Waiting for response...")
start = time.time()
response = proc.stdout.readline().strip()
end = time.time()
print(f"Response: {response}")
print(f"Time: {(end-start)*1000:.2f}ms")

proc.kill()
