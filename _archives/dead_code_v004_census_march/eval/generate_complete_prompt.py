"""
Generate the complete V020 external AI prompt with all questions embedded.
"""

import json

# Read the self-test file
with open('/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test.json', 'r') as f:
    data = json.load(f)

memories = data['memories']
questions = data['questions']

# Group questions by type
by_type = {}
for q in questions:
    qtype = q['question_type']
    if qtype not in by_type:
        by_type[qtype] = []
    by_type[qtype].append(q)

# Generate the complete prompt
prompt = f"""# LoCoMo V020 WhiteMagic Self-Test Benchmark - COMPLETE PROMPT

You are participating in the WhiteMagic V020 Self-Test. You have access to 100 memories and must answer 300 questions based ONLY on those memories.

## CRITICAL: ACTUAL QUESTIONS BELOW

Each question has:
- question_id: The ID to use in your answer
- question: The actual natural language question to answer
- question_type: The category
- source_memory_ids: The memories that contain the answer (use these!)

You MUST read the question carefully and provide a specific answer to THAT question.

## ANSWER FORMAT - JSON ONLY

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

Save to: `external_ai_answers_YYYYMMDD_HHMMSS.json`

## MEMORY CORPUS (100 Memories)

```json
{json.dumps(memories, indent=2)}
```

## QUESTIONS (300 Total)

### Single-Hop Questions (60 total)
Answer these by looking up the specific memory and extracting the fact.

```json
{json.dumps(by_type.get('single_hop', []), indent=2)}
```

### Multi-Hop Questions (75 total)
These require following associations between memories. Find the starting memory, check its `associations` array, follow to the connected memory, and answer the specific question.

```json
{json.dumps(by_type.get('multi_hop', []), indent=2)}
```

### Temporal Questions (60 total)
Date-based queries. Look for the `date` field in memories.

```json
{json.dumps(by_type.get('temporal', []), indent=2)}
```

### Open-Domain Questions (60 total)
Broad synthesis across multiple memories within a topic.

```json
{json.dumps(by_type.get('open_domain', []), indent=2)}
```

### Adversarial Questions (30 total)
**IMPORTANT:** These contain FALSE PREMISES. Do not hallucinate answers. Flag the false premise.

Examples of correct adversarial responses:
- Question: "What happened on February 30, 2026?" → Answer: "FALSE PREMISE - February has only 28/29 days"
- Question: "Which memory says X?" (when no memory says X) → Answer: "FALSE PREMISE - No memory contains this information"

```json
{json.dumps(by_type.get('adversarial', []), indent=2)}
```

### Calibration Questions (15 total)
Test appropriate uncertainty. Some have clear answers, others are unanswerable from the corpus.

```json
{json.dumps(by_type.get('calibration', []), indent=2)}
```

## RULES

1. **NO EXTERNAL KNOWLEDGE** - Use only the provided 100 memories
2. **ANSWER THE SPECIFIC QUESTION** - Don't just output memory titles
3. **MULTI-HOP:** Follow associations in the `associations` array
4. **ADVERSARIAL:** Flag false premises, don't make up answers
5. **CALIBRATION:** Use confidence 0.0 if information not in corpus
6. **SAVE AS JSON** - File naming: `external_ai_answers_YYYYMMDD_HHMMSS.json`

## EXAMPLE ANSWERS

### Good Single-Hop:
```json
{{
  "question_id": "q_sh_001",
  "answer": "0.7",
  "confidence": 1.0,
  "source_memory_ids": ["wm_mcp_001"],
  "reasoning": "Memory wm_mcp_001 explicitly states importance: 0.7"
}}
```

### Good Multi-Hop:
```json
{{
  "question_id": "q_mh_001",
  "answer": "wm_mcp_001 and wm_mcp_002",
  "confidence": 0.95,
  "source_memory_ids": ["wm_mcp_001", "wm_mcp_002"],
  "reasoning": "wm_mcp_001 discusses MCP architecture and is associated with wm_mcp_002 via the associations array"
}}
```

### Good Adversarial:
```json
{{
  "question_id": "q_adv_001",
  "answer": "FALSE PREMISE - The date February 30, 2026 does not exist",
  "confidence": 1.0,
  "source_memory_ids": [],
  "reasoning": "Question contains invalid date"
}}
```

### Good Calibration (unanswerable):
```json
{{
  "question_id": "q_cal_001",
  "answer": "NOT_FOUND",
  "confidence": 0.0,
  "source_memory_ids": [],
  "reasoning": "Information not present in the 100-memory corpus"
}}
```

---

**PROCESS:**
1. Read all 100 memories carefully
2. For each question, find the relevant memories
3. Answer the SPECIFIC question being asked
4. Output complete JSON array with all 300 answers
5. Save to file, return only filename

**Begin answering after receiving the complete memory corpus and questions.**
"""

# Write the complete prompt
output_path = '/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test_external_ai_prompt_COMPLETE.txt'
with open(output_path, 'w') as f:
    f.write(prompt)

print(f"Complete prompt generated: {output_path}")
print(f"Total size: {len(prompt):,} characters")
print(f"Memories included: {len(memories)}")
print(f"Questions included: {len(questions)}")
print("\nBy type:")
for qtype, qlist in by_type.items():
    print(f"  {qtype}: {len(qlist)}")
