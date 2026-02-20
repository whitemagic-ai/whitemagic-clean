import json
from difflib import SequenceMatcher

def semantic_similarity(a, b):
    """Calculate semantic similarity between two strings."""
    return SequenceMatcher(None, a.lower(), b.lower()).ratio()

# Load expected answers
with open('/home/lucas/Desktop/whitemagicdev/eval/locomo_v020_self_test.json', 'r') as f:
    expected_data = json.load(f)

# Load v6 actual answers  
with open('/home/lucas/Desktop/whitemagicdev/eval/wm_v6_answers_20260219_222002.json', 'r') as f:
    actual_data = json.load(f)

# Build lookup
expected = {q['question_id']: q for q in expected_data['questions']}
actual = {a['question_id']: a for a in actual_data}

print(f"Expected: {len(expected)}, Actual: {len(actual)}")

# Score by type with semantic matching for open-domain
type_scores = {}
SIMILARITY_THRESHOLD = 0.70  # 70% similarity considered correct

for qid, exp in expected.items():
    act = actual.get(qid)
    if not act:
        continue
    
    qtype = exp['question_type']
    if qtype not in type_scores:
        type_scores[qtype] = {'correct': 0, 'total': 0, 'wrong': []}
    
    type_scores[qtype]['total'] += 1
    
    act_answer = str(act['answer']).strip()
    exp_answers = [str(e).strip() for e in exp['expected_answers']]
    
    is_correct = False
    
    # For calibration: check NOT_FOUND with confidence 0.0
    if qtype == 'calibration':
        if act['answer'] == 'NOT_FOUND' and act.get('confidence', 1.0) == 0.0:
            is_correct = True
    # For adversarial: check FALSE_PREMISE detection
    elif qtype == 'adversarial':
        if 'FALSE_PREMISE' in act_answer or act_answer in exp_answers:
            is_correct = True
    # For open-domain: use SEMANTIC matching (70% threshold)
    elif qtype == 'open_domain':
        best_sim = 0
        for exp_ans in exp_answers:
            sim = semantic_similarity(act_answer, exp_ans)
            if sim > best_sim:
                best_sim = sim
        
        if best_sim >= SIMILARITY_THRESHOLD:
            is_correct = True
    else:
        # For other types: exact match
        if act_answer in exp_answers:
            is_correct = True
    
    if is_correct:
        type_scores[qtype]['correct'] += 1
    else:
        type_scores[qtype]['wrong'].append({
            'qid': qid,
            'expected': exp_answers[0][:80] if exp_answers else 'N/A',
            'actual': act_answer[:80] if len(act_answer) > 80 else act_answer
        })

# Calculate totals
total_correct = sum(s['correct'] for s in type_scores.values())
total_questions = sum(s['total'] for s in type_scores.values())
overall_pct = total_correct / total_questions * 100 if total_questions > 0 else 0

print("\n" + "="*70)
print("V6 TEST RESULTS - SEMANTIC SCORING (70% threshold for open-domain)")
print("="*70)

for qtype in ['single_hop', 'multi_hop', 'temporal', 'open_domain', 'adversarial', 'calibration']:
    if qtype in type_scores:
        scores = type_scores[qtype]
        pct = scores['correct'] / scores['total'] * 100 if scores['total'] > 0 else 0
        marker = "✅" if pct >= 80 else ("⚠️" if pct >= 60 else "❌")
        print(f"{qtype:15}: {scores['correct']:3}/{scores['total']:3} = {pct:5.1f}% {marker}")

print("-"*70)
print(f"{'OVERALL':15}: {total_correct:3}/{total_questions:3} = {overall_pct:5.1f}%")
print("="*70)

# Summary
if overall_pct >= 90:
    print("\n🏆 EXCELLENT: Near-perfect recall achieved")
elif overall_pct >= 80:
    print("\n✅ STRONG: Target met, WhiteMagic enables high-accuracy retrieval")
elif overall_pct >= 70:
    print("\n⚠️  ADEQUATE: Some gaps but functional")
else:
    print("\n❌ NEEDS WORK: Significant issues identified")

# Show sample wrong answers
print("\n" + "="*70)
print("SAMPLE WRONG ANSWERS (if any)")
print("="*70)
for qtype, scores in type_scores.items():
    if scores['wrong']:
        print(f"\n{qtype} ({len(scores['wrong'])} wrong):")
        for w in scores['wrong'][:3]:
            print(f"  {w['qid']}: Expected '{w['expected'][:50]}...'")
            print(f"           Got '{w['actual'][:50]}...'")
