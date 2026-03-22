import re

with open('nexus/src/components/panels/RightPanel.tsx') as f:
    content = f.read()

# Fix the duplicate imports in RightPanel.tsx
# First, strip out all the messed up duplicated imports at the top
content = re.sub(r'import \{\n  Code2,\n  Terminal,\n  Check,\n  Send,\n  Bot,\n  User,\n  Sparkles,\n  Radio,\n  Users,\n\} from "lucide-react";', '', content)
content = re.sub(r'import \{\n  Code2,\n  Terminal,\n  Check, useState, useRef, useEffect \} from "react";', 'import { useState, useRef, useEffect } from "react";', content)
content = re.sub(r'import \{\n  Code2,\n  Terminal,\n  Check,\n\} from "lucide-react";', '', content)
content = re.sub(r'import \{\n  Code2,\n  Terminal,\n  Check, useNexusStore, type RightTab \} from "\.\.\/\.\.\/store\/nexus";', 'import { useNexusStore, type RightTab } from "../../store/nexus";', content)

# Now inject a clean set of imports right after the react import
clean_imports = """
import {
  Send,
  Bot,
  User,
  Sparkles,
  Radio,
  Users,
  Code2,
  Terminal,
  Check,
  Search
} from "lucide-react";
"""
content = re.sub(r'import \{ useState, useRef, useEffect \} from "react";', 'import { useState, useRef, useEffect } from "react";' + clean_imports, content)

with open('nexus/src/components/panels/RightPanel.tsx', 'w') as f:
    f.write(content)

print("Fixed RightPanel.tsx imports")
