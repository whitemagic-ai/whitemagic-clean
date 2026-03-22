
with open('nexus/src/components/center/HolographicView.tsx') as f:
    content = f.read()

# Fix unused 'i' variable
content = content.replace('{clusters.map((cluster, i) => {', '{clusters.map((cluster) => {')

# Remove invalid className prop from three.js mesh
content = content.replace('<mesh onClick={() => onClusterSelect(cluster)} className="cursor-pointer">', '<mesh onClick={() => onClusterSelect(cluster)}>')

# Add missing args prop to float32BufferAttribute
content = content.replace('attach="attributes-position"\n            count={clusters.length * 2}', 'attach="attributes-position"\n            args={[new Float32Array(), 3]}\n            count={clusters.length * 2}')

with open('nexus/src/components/center/HolographicView.tsx', 'w') as f:
    f.write(content)

print("Fixed HolographicView TypeScript errors")
