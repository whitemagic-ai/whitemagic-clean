"""
Generate WhiteMagic-enabled blind test prompt (v4)
- Removes expected_answers from questions (blind test)
- Explicitly allows and encourages WhiteMagic tool usage
- Tests what WhiteMagic enables AI to do that raw LLM cannot
"""

import json
import copy

# Read the self-test file
with open('/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test.json', 'r') as f:
    data = json.load(f)

memories = data['memories']
questions = data['questions']

# Create blind versions of questions (remove expected_answers)
blind_questions = []
for q in questions:
    blind_q = {
        'question_id': q['question_id'],
        'question_type': q['question_type'],
        'question': q['question'],
        'source_memory_ids': q['source_memory_ids'],
        'difficulty': q.get('difficulty', 'medium')
    }
    blind_questions.append(blind_q)

# Group by type
by_type = {}
for q in blind_questions:
    qtype = q['question_type']
    if qtype not in by_type:
        by_type[qtype] = []
    by_type[qtype].append(q)

# Build the v4 prompt
prompt = f"""# LoCoMo V020 WhiteMagic-Enabled Blind Test (v4)

## 🎯 MISSION: Use WhiteMagic to Achieve Perfect Recall

You have access to the **WhiteMagic Memory System** via MCP tools. Your goal is to answer 300 questions by leveraging WhiteMagic's capabilities - this tests what the system enables, not raw LLM reasoning.

### ⚠️ CRITICAL: This is a TOOL-ASSISTED Test

**You ARE expected to use WhiteMagic tools.** This is not cheating - it's the entire point of the evaluation.

**Available WhiteMagic Tools:**
- `search_memories` - Hybrid search (vector + BM25 + graph)
- `hybrid_recall` - Multi-hop retrieval via graph walking
- `vector_search` - Semantic similarity search
- `graph_walk` - Follow memory associations
- `cluster_stats` - Find related memory clusters

**Your Task:** Use these tools to find answers that would be impossible with raw reasoning alone.

---

## ANSWER FORMAT - JSON ONLY

```json
[
  {{
    "question_id": "q_sh_001",
    "answer": "your specific answer here",
    "confidence": 0.95,
    "source_memory_ids": ["wm_mcp_001"],
    "reasoning": "Found via WhiteMagic hybrid_recall searching for...",
    "tools_used": ["search_memories", "hybrid_recall"]
  }}
]
```

Save to: `wm_enabled_answers_YYYYMMDD_HHMMSS.json`

---

## MEMORY CORPUS (100 Memories - Use Tools to Navigate)

The memories are provided below, but you should use WhiteMagic search tools rather than manual scanning:

```json
{json.dumps(memories, indent=2)}
```

---

## STRATEGY BY QUESTION TYPE

### Single-Hop (60 questions)
**Tool Strategy:** `search_memories` with the memory ID or key terms
- Direct lookup via vector search
- Example: Search "wm_mcp_001 importance" to find the value

### Multi-Hop (75 questions) ⚠️ REQUIRES GRAPH WALKING
**Tool Strategy:** `hybrid_recall` or `graph_walk`
- These require following associations between memories
- Raw LLM cannot do this without tool assistance
- **This is where WhiteMagic shines**

### Temporal (60 questions)
**Tool Strategy:** `search_memories` with date filters
- Match dates to memory creation dates
- Use "date:2026-01-15" style queries

### Open-Domain (60 questions)
**Tool Strategy:** `cluster_stats` + `search_memories`
- Find topic clusters
- Synthesize across multiple related memories

### Adversarial (30 questions)
**Tool Strategy:** `search_memories` to verify
- Check if claimed facts actually exist
- Flag false premises with confidence=1.0

### Calibration (15 questions)
**Tool Strategy:** `search_memories` exhaustive check
- Use confidence 0.0 if WhiteMagic returns no results
- Some questions are designed to be unanswerable

---

## ALL QUESTIONS (300 Total - Blind Test)

**Note:** expected_answers have been removed. You must discover answers using WhiteMagic tools.

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

Before submitting:
- [ ] Did you use WhiteMagic tools (not just read the JSON)?
- [ ] For multi-hop: Did you use graph_walk or hybrid_recall?
- [ ] For open-domain: Did you search and synthesize?
- [ ] Did you record which tools you used in `tools_used` field?
- [ ] Are confidences calibrated (high for found, 0.0 for not found)?
- [ ] Is your output valid JSON with all 300 answers?

---

**PROCESS:**
1. For each question, decide which WhiteMagic tool is appropriate
2. Formulate a search query or graph walk
3. Use the tool results to answer
4. Record what you found and how
5. Compile all 300 answers with tool attribution

**This tests what WhiteMagic enables that raw reasoning cannot.**

**Begin answering using WhiteMagic tools.**
"""

# Write v4 prompt
output_path = '/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_blind_wm_enabled_v4.txt'
with open(output_path, 'w') as f:
    f.write(prompt)

print(f"WhiteMagic-enabled blind test v4 generated: {output_path}")
print(f"Total size: {len(prompt):,} characters")
print(f"Key features:")
print("  ✅ expected_answers REMOVED (blind test)")
print("  ✅ WhiteMagic tool usage EXPLICITLY ENCOURAGED")
print("  ✅ Strategy guidance per question type")
print("  ✅ tools_used field in answer format")
print(f"\nQuestions: {len(blind_questions)}")
print(f"Memories: {len(memories)}")
