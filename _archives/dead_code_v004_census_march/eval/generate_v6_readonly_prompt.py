"""
Generate v6 prompt - WhiteMagic-enabled blind test with ALL fixes
- Fixed question deduplication bug (use q not blind_q)
- Explicit topic extraction for open-domain questions
- Calibration guardrails for unanswerable questions
- Multi-hop graph walking guidance
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

# Group by type - BUG FIX: use q not blind_q
by_type = {}
for q in blind_questions:
    qtype = q['question_type']
    if qtype not in by_type:
        by_type[qtype] = []
    by_type[qtype].append(q)  # FIXED: was appending blind_q

# Verify counts
print("Questions by type:")
for qtype, qs in sorted(by_type.items()):
    print(f"  {qtype}: {len(qs)} questions")
print(f"Total: {sum(len(qs) for qs in by_type.values())}")

# Build the v6 prompt with all fixes
prompt = f"""# LoCoMo V020 WhiteMagic-Enabled Blind Test (v6)

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

Save to: `wm_v6_answers_YYYYMMDD_HHMMSS.json`

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

## 📋 STRATEGY GUIDE BY QUESTION TYPE

### Single-Hop (60 questions)
**Strategy:** Direct memory lookup
- Extract the memory ID from the question
- Search the corpus for that specific memory
- Extract the exact value asked for (importance, date, status, etc.)

### Multi-Hop (75 questions) ⚠️ CRITICAL
**Strategy:** Follow associations using `hybrid_recall` or `graph_walk`
- Identify the starting memory from the question
- Use graph tools to find memories associated with the starting point
- Answer requires combining information from MULTIPLE connected memories
- **Example:** If asked "What protocol implements the Sangha Lock?", you must:
  1. Find memory about Sangha Lock
  2. Follow associations to find the connected MCP Tool Registration memory
  3. Answer with BOTH memory titles

### Temporal (60 questions)
**Strategy:** Date matching and chronological lookup
- Match dates mentioned in questions to `created_at` dates in memories
- Use date range searches
- Pay attention to "before", "after", "between" constraints

### Open-Domain (60 questions) ⚠️ TOPIC EXTRACTION REQUIRED
**Strategy:** 
1. **STEP 1: Identify the TOPIC keyword** in the question
   - "What memories discuss **[TOPIC]**?"
   - Look for topic words like: "graph_algorithms", "mcp_tools", "dream_cycle", "rust_acceleration", etc.
2. **STEP 2: Search** for memories with that topic tag
3. **STEP 3: Synthesize** a specific answer listing the relevant memories

**⚠️ CRITICAL: DO NOT give the same answer for all open-domain questions.**
Each open-domain question asks about a DIFFERENT topic. You must:
- Read the specific topic in each question
- Search for memories with that topic
- List only the memories matching that topic

**Example:**
- Q: "What memories discuss graph_algorithms?" → List: Graph Walk Algorithms, Community Detection, etc.
- Q: "What memories discuss mcp_tools?" → List: MCP Tool Registration, Command Structure, etc.
- Q: "What memories discuss rust_acceleration?" → List: SIMD Operations, etc.

### Adversarial (30 questions)
**Strategy:** False premise detection
- Verify claims against the corpus
- If the premise is false (memory doesn't exist, fact is wrong), state this clearly
- Use confidence 1.0 when correctly identifying false premises

### Calibration (15 questions) ⚠️ UNANSWERABLE DETECTION
**Strategy:** Identify questions that CANNOT be answered from the corpus

**Answer `NOT_FOUND` with `confidence: 0.0` if the question asks for:**
- Statistics not in the 100-memory corpus (total associations, system-wide counts, etc.)
- Dates before 2025 (the corpus only contains 2025-2026 dates)
- Information about memories NOT in the provided corpus
- External knowledge not present in the 100 memories

**Examples of unanswerable questions:**
- "What is the total number of associations in the system?" → NOT_FOUND (corpus doesn't have this)
- "How many memories were created before 2025?" → NOT_FOUND (corpus only has 2025-2026)
- "What is the system-wide embedding count?" → NOT_FOUND (not in the 100-memory corpus)

**Answer normally if the information IS in the corpus.**

---

## ⚠️ FINAL CHECKLIST

Before submitting:
- [ ] Did you treat the corpus as READ-ONLY (no ingestion)?
- [ ] For open-domain: Did you extract the SPECIFIC topic from each question?
- [ ] For open-domain: Did you give DIFFERENT answers for different topics?
- [ ] For multi-hop: Did you follow associations between memories?
- [ ] For calibration: Did you use confidence 0.0 + NOT_FOUND for unanswerable stats?
- [ ] For adversarial: Did you detect false premises?
- [ ] Did you answer all 300 questions?
- [ ] Did you record `tools_used` for each answer?
- [ ] Is your output valid JSON?

**Target: Beat 80% accuracy. Ideal: 100%.**

---

**REMEMBER: This is a READ-ONLY evaluation. The memories provided are your test corpus. Search them, don't store them.**

**For open-domain questions, each question has a DIFFERENT topic. Do not give the same answer to all 60 open-domain questions.**

**For calibration questions, if the question asks for system-wide statistics not in the 100-memory corpus, answer NOT_FOUND with confidence 0.0.**
"""

# Write v6 prompt
output_path = '/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_blind_wm_enabled_v6.txt'
with open(output_path, 'w') as f:
    f.write(prompt)

print(f"\n✅ v6 READ-ONLY prompt generated: {output_path}")
print(f"Total size: {len(prompt):,} characters")
print("\nKey improvements in v6:")
print("  ✅ BUG FIXED: All 300 questions now unique")
print("  ✅ Open-domain: Explicit topic extraction required")
print("  ✅ Calibration: NOT_FOUND guardrails for unanswerable questions")
print("  ✅ Multi-hop: Graph walking guidance with examples")
print("  ✅ Warning against generic/template answers")
print("\nReady for testing!")
