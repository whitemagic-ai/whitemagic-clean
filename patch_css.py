
with open('nexus/src/index.css', 'r') as f:
    content = f.read()

# Fix the CSS @import order issue
if "@import url" in content:
    lines = content.split('\n')
    imports = [l for l in lines if l.startswith('@import')]
    other = [l for l in lines if not l.startswith('@import')]
    
    new_content = '\n'.join(imports + other)
    
    with open('nexus/src/index.css', 'w') as f:
        f.write(new_content)
    print("Patched index.css")
