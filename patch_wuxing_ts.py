
with open('nexus/src/components/center/WuXingWheel.tsx', 'r') as f:
    content = f.read()

content = content.replace("import React, { useEffect, useRef } from 'react';", "import { useEffect, useRef } from 'react';")

with open('nexus/src/components/center/WuXingWheel.tsx', 'w') as f:
    f.write(content)

print("Fixed WuXingWheel TS error")
