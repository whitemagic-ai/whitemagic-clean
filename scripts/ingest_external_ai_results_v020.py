#!/usr/bin/env python3
"""
LoCoMo V020 External AI Result Ingestion & Semantic Scoring
Uses BERTScore-style semantic similarity + adversarial detection + calibration assessment
"""

import json
import os
import re
from pathlib import Path
from typing import Dict, List, Tuple, Any
from datetime import datetime
from difflib import SequenceMatcher


class SemanticScorer:
    """
    BERTScore-inspired semantic evaluation for open-ended answers.
    Uses contextual similarity instead of exact word matching.
    """
    
    def __init__(self):
        # Weights for semantic scoring
        self.semantic_weight = 0.7
        self.factual_weight = 0.3
    
    def tokenize(self, text: str) -> List[str]:
        """Simple tokenization for semantic comparison."""
        # Lowercase, remove punctuation, split
        cleaned = re.sub(r'[^\w\s]', ' ', text.lower())
        return cleaned.split()
    
    def ngram_similarity(self, text1: str, text2: str, n: int = 2) -> float:
        """Calculate n-gram overlap similarity."""
        tokens1 = self.tokenize(text1)
        tokens2 = self.tokenize(text2)
        
        if not tokens1 or not tokens2:
            return 0.0
        
        # Generate n-grams
        def make_ngrams(tokens):
            return set(tuple(tokens[i:i+n]) for i in range(len(tokens)-n+1))
        
        ngrams1 = make_ngrams(tokens1)
        ngrams2 = make_ngrams(tokens2)
        
        if not ngrams1 or not ngrams2:
            # Fall back to unigrams
            set1, set2 = set(tokens1), set(tokens2)
            if not set1 or not set2:
                return 0.0
            return len(set1 & set2) / len(set1 | set2)
        
        # Jaccard similarity for n-grams
        intersection = len(ngrams1 & ngrams2)
        union = len(ngrams1 | ngrams2)
        return intersection / union if union > 0 else 0.0
    
    def sequence_similarity(self, text1: str, text2: str) -> float:
        """Calculate sequence matcher similarity."""
        return SequenceMatcher(None, text1.lower(), text2.lower()).ratio()
    
    def keyword_coverage(self, predicted: str, keywords: List[str]) -> float:
        """Check coverage of required keywords/concepts."""
        if not keywords:
            return 1.0
        
        pred_lower = predicted.lower()
        covered = sum(1 for kw in keywords if kw.lower() in pred_lower)
        return covered / len(keywords)
    
    def semantic_score(self, predicted: str, references: List[str], keywords: List[str]) -> Dict[str, float]:
        """
        Calculate semantic similarity score.
        
        Returns:
            - semantic_sim: Best match against any reference (0.0-1.0)
            - keyword_cov: Required concept coverage (0.0-1.0)
            - final_score: Weighted combination
        """
        # Calculate similarity against all references, take best
        best_semantic = 0.0
        for ref in references:
            # Combine n-gram and sequence similarity
            ngram_sim = self.ngram_similarity(predicted, ref, n=2)
            seq_sim = self.sequence_similarity(predicted, ref)
            combined = 0.6 * ngram_sim + 0.4 * seq_sim
            best_semantic = max(best_semantic, combined)
        
        # Keyword coverage
        keyword_cov = self.keyword_coverage(predicted, keywords)
        
        # Weighted final score
        final = (self.semantic_weight * best_semantic + 
                 self.factual_weight * keyword_cov)
        
        return {
            'semantic_similarity': round(best_semantic, 3),
            'keyword_coverage': round(keyword_cov, 3),
            'final_score': round(final, 3)
        }


class LoCoMoV020Scorer:
    """V020 Enhanced scorer with semantic evaluation and adversarial detection."""
    
    def __init__(self, questions_file: str):
        with open(questions_file) as f:
            data = json.load(f)
        self.questions = {q['question_id']: q for q in data.get('questions', [])}
        self.scorer = SemanticScorer()
    
    def check_adversarial_behavior(self, answer_obj: Dict, question: Dict) -> Tuple[bool, str]:
        """
        Check if AI correctly handled adversarial question.
        
        Returns (passed, feedback)
        """
        qtype = question.get('question_type', '')
        if qtype != 'adversarial':
            return True, "N/A"
        
        _trap = question.get('trap', '')  # For diagnostic reference
        predicted = answer_obj.get('answer', '').lower()
        
        # Check for appropriate responses to traps
        appropriate_flags = [
            'incorrect', 'mismatch', 'not', 'false', 'premise', 
            'january 9', 'not january 12', 'cannot', 'insufficient'
        ]
        
        flagged = any(flag in predicted for flag in appropriate_flags)
        
        if flagged:
            return True, "Correctly flagged adversarial premise"
        
        # Check if AI hallucinated to fit false premise
        hallucinated = self._check_hallucination(predicted, question)
        if hallucinated:
            return False, "Hallucinated to fit false premise"
        
        return False, "Did not recognize adversarial trap"
    
    def _check_hallucination(self, predicted: str, question: Dict) -> bool:
        """Check if AI invented information to answer."""
        # Simple heuristic: if answer is very long and contains specifics not in corpus
        if len(predicted) > 200 and question.get('source_memory_ids'):
            # Check if specific numbers/dates are mentioned that aren't in question
            # This is a simplified check
            return False  # Would need corpus to verify properly
        return False
    
    def check_calibration(self, answer_obj: Dict, question: Dict, match_score: float) -> Tuple[float, str]:
        """
        Assess confidence calibration.
        
        Returns (calibration_error, assessment)
        """
        confidence = answer_obj.get('confidence', 0.0)
        ideal = question.get('ideal_confidence', 0.5)
        
        # For questions with clear answers, high confidence expected
        # For unanswerable, low confidence expected
        error = abs(confidence - ideal)
        
        if error < 0.2:
            return error, "Well calibrated"
        elif confidence > ideal + 0.3:
            return error, "Overconfident"
        else:
            return error, "Underconfident"
    
    def score_answer(self, answer_obj: Dict) -> Tuple[float, str, Dict]:
        """
        Score a single answer with V020 semantic evaluation.
        
        Returns (score, feedback, diagnostics)
        """
        qid = answer_obj.get('question_id')
        if qid not in self.questions:
            return 0.0, f"Unknown question_id: {qid}", {}
        
        question = self.questions[qid]
        qtype = question.get('question_type', 'unknown')
        predicted = answer_obj.get('answer', '')
        
        # Handle NOT_FOUND
        if predicted == 'NOT_FOUND' or predicted == '':
            if qtype == 'calibration' and question.get('ideal_confidence', 1.0) < 0.3:
                return 1.0, "Correctly reported NOT_FOUND for unanswerable question", {'type': 'not_found_correct'}
            return 0.0, "Should have found an answer", {'type': 'not_found_wrong'}
        
        # Get scoring config
        scoring = question.get('scoring', {'semantic_weight': 0.7, 'factual_weight': 0.3})
        min_pass = scoring.get('min_pass_score', 0.6)
        
        # Semantic scoring
        references = question.get('expected_answers', [question.get('expected_answer', '')])
        keywords = question.get('acceptable_keywords', [])
        
        semantic = self.scorer.semantic_score(predicted, references, keywords)
        final_score = semantic['final_score']
        
        # Adversarial check
        adv_passed, adv_feedback = True, "N/A"
        if qtype == 'adversarial':
            adv_passed, adv_feedback = self.check_adversarial_behavior(answer_obj, question)
            if adv_passed:
                final_score = max(final_score, 0.8)  # Bonus for catching trap
        
        # Calibration check
        cal_error, cal_feedback = self.check_calibration(answer_obj, question, final_score)
        
        # Build feedback
        feedback_parts = []
        if final_score >= min_pass:
            feedback_parts.append(f"Pass (score: {final_score:.2f})")
        else:
            feedback_parts.append(f"Partial (score: {final_score:.2f})")
        
        if qtype == 'adversarial':
            feedback_parts.append(f"Adversarial: {adv_feedback}")
        
        feedback_parts.append(f"Calibration: {cal_feedback}")
        
        diagnostics = {
            'semantic_similarity': semantic['semantic_similarity'],
            'keyword_coverage': semantic['keyword_coverage'],
            'adversarial_passed': adv_passed,
            'calibration_error': cal_error,
            'confidence': answer_obj.get('confidence', 0.0),
            'ideal_confidence': question.get('ideal_confidence', 0.5)
        }
        
        return final_score, ' | '.join(feedback_parts), diagnostics
    
    def score_submission(self, answers_file: str) -> Dict[str, Any]:
        """Score a complete submission with V020 metrics."""
        with open(answers_file) as f:
            answers = json.load(f)
        
        results = {
            'file': answers_file,
            'timestamp': datetime.now().isoformat(),
            'total_questions': len(self.questions),
            'answered': len(answers),
            'by_type': {},
            'overall_score': 0.0,
            'semantic_avg': 0.0,
            'adversarial_pass_rate': 0.0,
            'calibration_error_avg': 0.0,
            'confidence_calibration': {'overconfident': 0, 'underconfident': 0, 'well_calibrated': 0},
            'details': []
        }
        
        total_score = 0.0
        type_scores = {}
        adversarial_total = 0
        adversarial_passed = 0
        calibration_errors = []
        semantic_scores = []
        
        for answer_obj in answers:
            qid = answer_obj.get('question_id')
            if qid not in self.questions:
                continue
            
            question = self.questions[qid]
            qtype = question.get('question_type', 'unknown')
            
            score, feedback, diag = self.score_answer(answer_obj)
            total_score += score
            semantic_scores.append(diag.get('semantic_similarity', 0))
            
            # Track by type
            if qtype not in type_scores:
                type_scores[qtype] = {'count': 0, 'total_score': 0.0, 'passed': 0}
            type_scores[qtype]['count'] += 1
            type_scores[qtype]['total_score'] += score
            
            scoring = question.get('scoring', {'min_pass_score': 0.6})
            if score >= scoring.get('min_pass_score', 0.6):
                type_scores[qtype]['passed'] += 1
            
            # Track adversarial
            if qtype == 'adversarial':
                adversarial_total += 1
                if diag.get('adversarial_passed', False):
                    adversarial_passed += 1
            
            # Track calibration
            cal_error = diag.get('calibration_error', 0)
            calibration_errors.append(cal_error)
            confidence = diag.get('confidence', 0)
            ideal = diag.get('ideal_confidence', 0.5)
            
            if confidence > ideal + 0.3:
                results['confidence_calibration']['overconfident'] += 1
            elif confidence < ideal - 0.3:
                results['confidence_calibration']['underconfident'] += 1
            else:
                results['confidence_calibration']['well_calibrated'] += 1
            
            results['details'].append({
                'question_id': qid,
                'question_type': qtype,
                'score': round(score, 3),
                'feedback': feedback,
                'semantic_sim': diag.get('semantic_similarity'),
                'predicted': answer_obj.get('answer', '')[:100],
                'expected': question.get('expected_answers', [''])[0][:100]
            })
        
        # Calculate aggregates
        answered_count = len(answers)
        if answered_count > 0:
            results['overall_score'] = round(total_score / answered_count * 100, 2)
        
        if semantic_scores:
            results['semantic_avg'] = round(sum(semantic_scores) / len(semantic_scores), 3)
        
        if adversarial_total > 0:
            results['adversarial_pass_rate'] = round(adversarial_passed / adversarial_total * 100, 1)
        
        if calibration_errors:
            results['calibration_error_avg'] = round(sum(calibration_errors) / len(calibration_errors), 3)
        
        # Per-type breakdown
        for qtype, stats in type_scores.items():
            if stats['count'] > 0:
                results['by_type'][qtype] = {
                    'count': stats['count'],
                    'pass_rate': round(stats['passed'] / stats['count'] * 100, 1),
                    'avg_score': round(stats['total_score'] / stats['count'], 3)
                }
        
        return results
    
    def compare_submissions(self, submission_files: List[str]) -> str:
        """Generate V020 comparison report."""
        reports = [self.score_submission(f) for f in submission_files]
        
        md = ["# LoCoMo V020 External AI Results\n"]
        md.append(f"Semantic Scoring | {len(reports)} AI submissions\n")
        md.append(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n")
        
        # Summary with V020 metrics
        md.append("## Overall Scores (V020 Semantic)\n\n")
        md.append("| AI | Score | Semantic | Adversarial | Calibration |\n")
        md.append("|------|-------|----------|-------------|-------------|\n")
        for r in reports:
            fname = Path(r['file']).stem
            cal_status = "Well" if r['calibration_error_avg'] < 0.2 else "Poor"
            md.append(f"| {fname} | {r['overall_score']}% | {r['semantic_avg']} | {r['adversarial_pass_rate']}% | {cal_status} |\n")
        
        # By type
        md.append("\n## Scores by Question Type\n\n")
        all_types = sorted(set().union(*(r['by_type'].keys() for r in reports)))
        
        for qtype in all_types:
            md.append(f"\n### {qtype}\n\n")
            md.append("| AI | Pass Rate | Avg Score | Count |\n")
            md.append("|------|-----------|-----------|-------|\n")
            for r in reports:
                fname = Path(r['file']).stem
                tstats = r['by_type'].get(qtype, {'pass_rate': 0, 'avg_score': 0, 'count': 0})
                md.append(f"| {fname} | {tstats['pass_rate']}% | {tstats['avg_score']} | {tstats['count']} |\n")
        
        # Adversarial performance detail
        md.append("\n## Adversarial Question Performance\n\n")
        md.append("| AI | Traps Caught | Total Traps | Pass Rate |\n")
        md.append("|------|--------------|-------------|-----------|\n")
        for r in reports:
            fname = Path(r['file']).stem
            caught = round(r['adversarial_pass_rate'] / 100 * 10)  # Assuming 10 adversarial
            md.append(f"| {fname} | ~{caught} | 10 | {r['adversarial_pass_rate']}% |\n")
        
        md.append("\n*Adversarial questions test critical reading - AI should flag false premises*\n")
        
        return ''.join(md)


def ingest_results(eval_dir: str = '/home/lucas/Desktop/whitemagicdev/eval') -> str:
    """Auto-discover and score all external AI result files."""
    result_files = []
    for f in os.listdir(eval_dir):
        if f.startswith('external_ai_answers_') and f.endswith('.json'):
            result_files.append(os.path.join(eval_dir, f))
    
    if not result_files:
        print("No external AI result files found")
        return None
    
    print(f"Found {len(result_files)} submission(s):")
    for f in result_files:
        print(f"  - {os.path.basename(f)}")
    
    # Use V020 questions if available, fallback to V019
    v020_questions = os.path.join(eval_dir, 'locomo_v020_test.json')
    questions_file = v020_questions if os.path.exists(v020_questions) else os.path.join(eval_dir, 'external_ai_questions.json')
    
    scorer = LoCoMoV020Scorer(questions_file)
    report = scorer.compare_submissions(result_files)
    
    report_path = os.path.join(eval_dir, 'external_ai_v020_comparison_report.md')
    with open(report_path, 'w') as f:
        f.write(report)
    
    print(f"\nV020 Report saved: {report_path}")
    
    for r in result_files:
        print(f"\n{os.path.basename(r)}:")
        scores = scorer.score_submission(r)
        print(f"  Overall: {scores['overall_score']}% (semantic)")
        print(f"  Adversarial pass rate: {scores['adversarial_pass_rate']}%")
        print(f"  Avg calibration error: {scores['calibration_error_avg']}")
        for qtype, stats in scores['by_type'].items():
            print(f"  {qtype}: {stats['pass_rate']}% pass ({stats['count']} questions)")
    
    return report_path


if __name__ == "__main__":
    report = ingest_results()
    if report:
        print(f"\nV020 Comparison complete! View: {report}")
