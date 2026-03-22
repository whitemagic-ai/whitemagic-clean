
with open('nexus/src/components/panels/SwarmOrchestrator.tsx', 'r') as f:
    content = f.read()

content = content.replace('import { useState, useEffect } from "react";', 'import { useState } from "react";')
content = content.replace('const [cores, setCores] = useState<AgentCore[]>([', 'const [cores] = useState<AgentCore[]>([')

with open('nexus/src/components/panels/SwarmOrchestrator.tsx', 'w') as f:
    f.write(content)

print("Fixed SwarmOrchestrator TS errors")
