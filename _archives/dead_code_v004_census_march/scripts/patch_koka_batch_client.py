import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_batch_client.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix the subprocess call to use stdbuf for proper unbuffered IO
patch = """
            try:
                proc = subprocess.Popen(
                    ['stdbuf', '-o0', '-i0', str(binary)],
                    stdin=subprocess.PIPE,
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    bufsize=1  # Line buffered
                )
"""

pattern = r'            try:\n                proc = subprocess\.Popen\(\n                    \[str\(binary\)\],\n                    stdin=subprocess\.PIPE,\n                    stdout=subprocess\.PIPE,\n                    stderr=subprocess\.PIPE,\n                    text=True,\n                    bufsize=1  # Line buffered\n                \)'

new_content = re.sub(pattern, patch.lstrip(), content)

with open(file_path, "w") as f:
    f.write(new_content)

print("koka_batch_client.py patched successfully to use stdbuf!")
