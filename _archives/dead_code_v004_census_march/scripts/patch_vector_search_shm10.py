import ast

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    source = f.read()

try:
    ast.parse(source)
    print("Syntax OK")
except IndentationError as e:
    print(f"Indentation error at line {e.lineno}: {e.msg}")
