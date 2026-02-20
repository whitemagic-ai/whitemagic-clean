"""
Generate v5 prompt - WhiteMagic-enabled blind test with NO ingestion
Explicitly clarifies that memories are READ-ONLY reference data, not to be ingested
"""

import json

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

print(f"Questions by type:")
for qtype, qs in by_type.items():
    print(f"  {qtype}: {len(qs)} questions")

# Build the v5 prompt
prompt = f"""# LoCoMo V020 WhiteMagic-Enabled Blind Test (v5)

## 🚫 CRITICAL: DO NOT INGEST MEMORIES

**⚠️ READ-ONLY TEST - NO DATABASE OPERATIONS ⚠️**

The 100 memories in this file are **REFERENCE DATA** for this test only. **DO NOT**:
- Ingest them into WhiteMagic's database
- Create, store, or persist these memories
- Modify any database state
- Run any `create_memory`, `store`, or ingestion operations

**The memories JSON below is your ONLY corpus.** Answer questions by reading it directly, not by importing it.

---

## 🎯 MISSION: Use WhiteMagic Search Tools on Read-Only Corpus

You have access to WhiteMagic's **search and retrieval tools** to navigate the provided memory corpus. Your goal: answer 300 questions using the memory data provided in this file.

### What WhiteMagic Tools Help With:
- **Hybrid search** (`search_memories`) - Find relevant memories via vector + BM25
- **Graph walking** (`hybrid_recall`) - Follow associations for multi-hop questions
- **Cluster analysis** (`cluster_stats`) - Find related memory groups
- **Semantic search** (`vector_search`) - Match concepts

### What You MUST NOT Do:
- Ingest these test memories into the live database
- Treat this as a data import task
- Modify the corpus in any way

---

## ANSWER FORMAT - JSON ONLY

```json
[
  {{
    "question_id": "q_sh_001",
    "answer": "your specific answer here",
    "confidence": 0.95,
    "source_memory_ids": ["wm_mcp_001"],
    "reasoning": "Found by searching the provided corpus for...",
    "tools_used": ["search_memories"]
  }}
]
```

Save to: `wm_v5_answers_YYYYMMDD_HHMMSS.json`

---

## 📚 MEMORY CORPUS (100 Memories - READ ONLY)

**Use WhiteMagic search tools to navigate this corpus. Do NOT import it.**

```json
{json.dumps(memories, indent=2)}
```

---

## ❓ QUESTIONS (300 Total - Blind Test)

**Answer these using ONLY the memory corpus above. No expected_answers provided.**

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

## STRATEGY GUIDE

### Single-Hop
Search the corpus for the specific memory ID mentioned in the question.

### Multi-Hop
Use `hybrid_recall` or `graph_walk` to trace associations between memories in the provided corpus.

### Temporal
Match dates mentioned in questions to memory creation dates in the corpus.

### Open-Domain
Search for topic keywords, synthesize across multiple memories.

### Adversarial
Verify claims against the corpus. If false, answer indicating the false premise.

### Calibration
Use confidence 0.0 if the answer cannot be found in the provided corpus.

---

## ⚠️ FINAL CHECKLIST

Before submitting:
- [ ] Did you treat the corpus as READ-ONLY (no ingestion)?
- [ ] Did you use WhiteMagic search tools to navigate?
- [ ] Did you answer all 300 questions?
- [ ] Did you record `tools_used` for each answer?
- [ ] Are confidences calibrated (high for found, 0.0 for not found)?
- [ ] Is your output valid JSON?

**Target: Beat 80% accuracy. Ideal: 100%.**

---

**REMEMBER: This is a READ-ONLY evaluation. The memories provided are your test corpus. Search them, don't store them.**
"""

# Write v5 prompt
output_path = '/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_blind_wm_enabled_v5.txt'
with open(output_path, 'w') as f:
    f.write(prompt)

print(f"v5 READ-ONLY prompt generated: {output_path}")
print(f"Total size: {len(prompt):,} characters")
print(f"\nKey clarifications:")
print("  🚫 NO ingestion - explicit ban on create_memory/store")
print("  📖 READ-ONLY corpus - reference data only")
print("  🔍 Search tools only - no persistence operations")
print(f"\nQuestions: {len(blind_questions)}")
print(f"Memories: {len(memories)}")
