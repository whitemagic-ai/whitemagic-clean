"""
Generate the corrected V020 external AI prompt with explicit instructions
to prevent script-based answer generation and fix multi-hop/open-domain failures.
"""

import json

# Read the self-test file
with open('/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test.json', 'r') as f:
    data = json.load(f)

memories = data['memories']
questions = data['questions']

# Group questions by type
by_type: dict[str, list] = {}
for q in questions:
    qtype = q['question_type']
    if qtype not in by_type:
        by_type[qtype] = []
    by_type[qtype].append(q)

# Generate the corrected prompt
prompt = f"""# LoCoMo V020 WhiteMagic Self-Test Benchmark - CORRECTED PROMPT v3

## ⚠️ CRITICAL INSTRUCTIONS - READ FIRST

**DO NOT write code or scripts to generate answers.**
**DO NOT pattern-match on JSON structure.**
**READ each question individually and answer it directly.**

You are a human-like reasoning engine. Process each question naturally, not programmatically.

---

## ANSWER FORMAT - JSON ONLY

Your final output must be a JSON array. Save to: `external_ai_answers_YYYYMMDD_HHMMSS.json`

```json
[
  {{
    "question_id": "q_sh_001",
    "answer": "your specific answer here",
    "confidence": 0.95,
    "source_memory_ids": ["wm_mcp_001"],
    "reasoning": "brief explanation"
  }}
]
```

---

## MEMORY CORPUS (100 Memories)

```json
{json.dumps(memories, indent=2)}
```

---

## QUESTION TYPES & EXAMPLES

### 1. SINGLE-HOP (60 questions)
**What to do:** Look up one memory, extract a specific fact.

**Example:**
- Question: "What is the importance value of memory wm_mcp_001?"
- Look at memory wm_mcp_001 → find "importance": 0.7
- Answer: "0.7"

```json
{json.dumps(by_type.get('single_hop', [])[:2], indent=2)}
```

---

### 2. MULTI-HOP (75 questions) ⚠️ COMMON FAILURE POINT
**What to do:** Follow the `associations` array between memories to find connected pairs.

**CRITICAL:** Answer with MEMORY TITLES, not memory IDs or raw association lists.

**Example:**
- Question: "Which two memories discuss mcp architecture and are connected via associations?"
- Step 1: Find memories where topic="mcp_architecture" → wm_mcp_001, wm_mcp_002, etc.
- Step 2: Check wm_mcp_001's associations → ["wm_mcp_002", "wm_mcp_003", ...]
- Step 3: wm_mcp_001 is connected to wm_mcp_002
- Step 4: Get titles → "MCP Tool Registration Protocol" and "Sangha Lock Implementation"
- **Answer:** "MCP Tool Registration Protocol and Sangha Lock Implementation"

**WRONG:** "wm_mcp_001 is associated with wm_mcp_002, wm_mcp_003..."
**RIGHT:** "MCP Tool Registration Protocol and Sangha Lock Implementation"

```json
{json.dumps(by_type.get('multi_hop', [])[:2], indent=2)}
```

---

### 3. TEMPORAL (60 questions)
**What to do:** Match dates to memory creation dates.

**Example:**
- Question: "What memory was created on 2026-01-15?"
- Find memory with "date": "2026-01-15" → wm_mcp_001
- Answer: "MCP Tool Registration Protocol"

```json
{json.dumps(by_type.get('temporal', [])[:2], indent=2)}
```

---

### 4. OPEN-DOMAIN (60 questions) ⚠️ COMMON FAILURE POINT
**What to do:** Synthesize ALL memories from a specific topic.

**CRITICAL:** Match the topic in the question exactly. Do not grab memories from wrong topics.

**Example:**
- Question: "What are the key components of WhiteMagic mcp architecture?"
- Find ALL memories where topic="mcp_architecture" → wm_mcp_001 through wm_mcp_015
- List their titles
- **Answer:** "System includes: MCP Tool Registration Protocol, Sangha Lock Implementation, 28 Gana Tool Mapping..."

**WRONG:** Including "Bridging Centrality Detection" (that's graph_algorithms, not mcp_architecture)
**RIGHT:** Only memories where topic="mcp_architecture"

```json
{json.dumps(by_type.get('open_domain', [])[:2], indent=2)}
```

---

### 5. ADVERSARIAL (30 questions)
**What to do:** Detect false premises and flag them.

**Examples:**
- "What happened on February 30, 2026?" → "FALSE PREMISE - February only has 28/29 days"
- "Which memory says X?" (when no memory says X) → "FALSE PREMISE - No memory contains this information"

```json
{json.dumps(by_type.get('adversarial', [])[:2], indent=2)}
```

---

### 6. CALIBRATION (15 questions)
**What to do:** Use appropriate confidence. Set confidence=0.0 if unanswerable.

**Examples:**
- Clear answer in corpus → confidence: 0.95
- Unclear/ambiguous → confidence: 0.5
- Not in corpus → confidence: 0.0, answer: "NOT_FOUND"

```json
{json.dumps(by_type.get('calibration', [])[:2], indent=2)}
```

---

## ALL QUESTIONS (300 Total)

### Single-Hop (60)
```json
{json.dumps(by_type.get('single_hop', []), indent=2)}
```

### Multi-Hop (75)
```json
{json.dumps(by_type.get('multi_hop', []), indent=2)}
```

### Temporal (60)
```json
{json.dumps(by_type.get('temporal', []), indent=2)}
```

### Open-Domain (60)
```json
{json.dumps(by_type.get('open_domain', []), indent=2)}
```

### Adversarial (30)
```json
{json.dumps(by_type.get('adversarial', []), indent=2)}
```

### Calibration (15)
```json
{json.dumps(by_type.get('calibration', []), indent=2)}
```

---

## FINAL CHECKLIST

Before submitting your answers:
- [ ] Did you answer all 300 questions?
- [ ] Multi-hop: Did you use MEMORY TITLES, not IDs?
- [ ] Open-domain: Did you match the correct topic exactly?
- [ ] Did you include confidence scores (0.0 to 1.0)?
- [ ] Did you include source_memory_ids array?
- [ ] Did you include brief reasoning?
- [ ] Is your output valid JSON?

---

**PROCESS:**
1. Read all 100 memories carefully (don't just scan the JSON)
2. For each question, understand what is being asked
3. Find the relevant memories
4. Formulate a natural language answer (not code output)
5. Compile into JSON array
6. Save to file, return only filename

**Begin answering after reviewing all memories and questions.**
"""

# Write the corrected prompt
output_path = '/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test_prompt_v3_CORRECTED.txt'
with open(output_path, 'w') as f:
    f.write(prompt)

print(f"Corrected prompt generated: {output_path}")
print(f"Total size: {len(prompt):,} characters")
print("Key fixes:")
print("  - Explicit 'DO NOT write code' instruction")
print("  - Clear multi-hop examples (titles not IDs)")
print("  - Clear open-domain examples (match topic exactly)")
print("  - Checklist before submission")
