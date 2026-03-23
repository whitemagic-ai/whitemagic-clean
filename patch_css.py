
with open('nexus/src/index.css') as f:
    content = f.read()

# Fix the CSS @import order issue
if "@import url" in content:
    lines = content.split('\n')
    imports = [line for line in lines if line.startswith('@import')]
    other = [line for line in lines if not line.startswith('@import')]

    new_content = '\n'.join(imports + other)

    with open('nexus/src/index.css', 'w') as f:
        f.write(new_content)
    print("Patched index.css")
