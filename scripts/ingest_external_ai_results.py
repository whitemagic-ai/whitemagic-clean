#!/usr/bin/env python3
"""
LoCoMo V019 External AI Result Ingestion & Scoring
Compares external AI answers against ground truth, calculates accuracy.
"""

import json
import os
from pathlib import Path
from typing import Dict, List, Tuple, Any
from datetime import datetime


class LoCoMoScorer:
    """Scores external AI answers against ground truth."""
    
    def __init__(self, questions_file: str):
        with open(questions_file) as f:
            data = json.load(f)
        self.questions = {q['question_id']: q for q in data.get('questions', [])}
    
    def normalize_answer(self, answer: str) -> str:
        """Normalize answer for comparison."""
        if not answer:
            return ""
        return ' '.join(str(answer).lower().split())
    
    def calculate_match_score(self, predicted: str, expected: str) -> float:
        """
        Calculate similarity between predicted and expected answers.
        
        Returns 1.0 for exact match, 0.0 for no match.
        Partial credit for similar answers (e.g., "GPT-4" vs "GPT-4 Turbo").
        """
        pred_norm = self.normalize_answer(predicted)
        exp_norm = self.normalize_answer(expected)
        
        # Exact match
        if pred_norm == exp_norm:
            return 1.0
        
        # Contains match (e.g., "GPT-4 Turbo" contains "GPT-4")
        if exp_norm in pred_norm or pred_norm in exp_norm:
            return 0.8
        
        # Word overlap
        pred_words = set(pred_norm.split())
        exp_words = set(exp_norm.split())
        if pred_words and exp_words:
            overlap = len(pred_words & exp_words) / len(exp_words)
            return overlap * 0.6  # Partial credit
        
        return 0.0
    
    def score_answer(self, answer_obj: Dict) -> Tuple[float, str]:
        """
        Score a single answer.
        
        Returns (score, feedback) where score is 0.0-1.0.
        """
        qid = answer_obj.get('question_id')
        if qid not in self.questions:
            return 0.0, f"Unknown question_id: {qid}"
        
        question = self.questions[qid]
        expected = question.get('expected_answer', '')
        predicted = answer_obj.get('answer', '')
        confidence = answer_obj.get('confidence', 0.0)
        
        # Handle NOT_FOUND
        if predicted == 'NOT_FOUND':
            if expected == 'NOT_FOUND':
                return 1.0, "Correctly reported NOT_FOUND"
            return 0.0, "Should have found an answer"
        
        # Calculate match
        match_score = self.calculate_match_score(predicted, expected)
        
        # Confidence calibration check
        calibration = ""
        if confidence >= 0.9 and match_score < 0.5:
            calibration = " (overconfident)"
        elif confidence <= 0.3 and match_score >= 0.8:
            calibration = " (underconfident)"
        
        if match_score >= 0.8:
            return match_score, f"Correct{calibration}"
        elif match_score >= 0.5:
            return match_score, f"Partial match{calibration}"
        else:
            return match_score, f"Incorrect{calibration}"
    
    def score_submission(self, answers_file: str) -> Dict[str, Any]:
        """
        Score a complete submission file.
        
        Returns detailed scoring report.
        """
        with open(answers_file) as f:
            answers = json.load(f)
        
        results = {
            'file': answers_file,
            'timestamp': datetime.now().isoformat(),
            'total_questions': len(self.questions),
            'answered': len(answers),
            'by_type': {},
            'overall_score': 0.0,
            'confidence_calibration': {'overconfident': 0, 'underconfident': 0, 'well_calibrated': 0},
            'details': []
        }
        
        total_score = 0.0
        type_scores = {}
        
        for answer_obj in answers:
            qid = answer_obj.get('question_id')
            if qid not in self.questions:
                continue
            
            question = self.questions[qid]
            qtype = question.get('question_type', 'unknown')
            
            score, feedback = self.score_answer(answer_obj)
            total_score += score
            
            # Track by type
            if qtype not in type_scores:
                type_scores[qtype] = {'count': 0, 'total_score': 0.0, 'correct': 0}
            type_scores[qtype]['count'] += 1
            type_scores[qtype]['total_score'] += score
            if score >= 0.8:
                type_scores[qtype]['correct'] += 1
            
            # Confidence calibration
            confidence = answer_obj.get('confidence', 0.0)
            if confidence >= 0.9 and score < 0.5:
                results['confidence_calibration']['overconfident'] += 1
            elif confidence <= 0.3 and score >= 0.8:
                results['confidence_calibration']['underconfident'] += 1
            else:
                results['confidence_calibration']['well_calibrated'] += 1
            results['details'].append({
                'question_id': qid,
                'question_type': qtype,
                'score': round(score, 3),
                'feedback': feedback,
                'predicted': answer_obj.get('answer', '')[:100],
                'expected': question.get('expected_answer', '')[:100]
            })
        
        # Calculate overall
        answered_count = len(answers)
        if answered_count > 0:
            results['overall_score'] = round(total_score / answered_count * 100, 2)
        
        # Calculate per-type scores
        for qtype, stats in type_scores.items():
            if stats['count'] > 0:
                results['by_type'][qtype] = {
                    'count': stats['count'],
                    'accuracy': round(stats['correct'] / stats['count'] * 100, 1),
                    'avg_score': round(stats['total_score'] / stats['count'], 3)
                }
        
        return results
    
    def compare_submissions(self, submission_files: List[str]) -> str:
        """
        Compare multiple AI submissions and generate a report.
        
        Returns markdown report.
        """
        reports = []
        for f in submission_files:
            reports.append(self.score_submission(f))
        
        # Generate comparison report
        md = ["# LoCoMo V019 External AI Results\n"]
        md.append(f"Comparison of {len(reports)} AI submissions\n")
        md.append(f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n")
        
        # Summary table
        md.append("## Overall Scores\n\n")
        md.append("| AI | Score | Questions | Calibration |\n")
        md.append("|------|-------|-----------|-------------|\n")
        for r in reports:
            fname = Path(r['file']).stem
            cal = f"O:{r['confidence_calibration']['overconfident']} U:{r['confidence_calibration']['underconfident']}"
            md.append(f"| {fname} | {r['overall_score']}% | {r['answered']}/{r['total_questions']} | {cal} |\n")
        
        # By question type
        md.append("\n## Scores by Question Type\n\n")
        all_types = set()
        for r in reports:
            all_types.update(r['by_type'].keys())
        
        for qtype in sorted(all_types):
            md.append(f"\n### {qtype}\n\n")
            md.append("| AI | Accuracy | Avg Score | Count |\n")
            md.append("|------|----------|-----------|-------|\n")
            for r in reports:
                fname = Path(r['file']).stem
                tstats = r['by_type'].get(qtype, {'accuracy': 0, 'avg_score': 0, 'count': 0})
                md.append(f"| {fname} | {tstats['accuracy']}% | {tstats['avg_score']} | {tstats['count']} |\n")
        
        return ''.join(md)


def ingest_results(eval_dir: str = '/home/lucas/Desktop/whitemagicdev/eval') -> str:
    """
    Auto-discover and score all external AI result files.
    
    Returns path to generated report.
    """
    # Find all external_ai_answers files
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
    
    # Score submissions
    questions_file = os.path.join(eval_dir, 'external_ai_questions.json')
    scorer = LoCoMoScorer(questions_file)
    
    # Generate comparison report
    report = scorer.compare_submissions(result_files)
    
    # Save report
    report_path = os.path.join(eval_dir, 'external_ai_comparison_report.md')
    with open(report_path, 'w') as f:
        f.write(report)
    
    print(f"\nReport saved: {report_path}")
    
    # Also print summary
    for r in result_files:
        print(f"\n{os.path.basename(r)}:")
        scores = scorer.score_submission(r)
        print(f"  Overall: {scores['overall_score']}%")
        for qtype, stats in scores['by_type'].items():
            print(f"  {qtype}: {stats['accuracy']}% ({stats['count']} questions)")
    
    return report_path


if __name__ == "__main__":
    report = ingest_results()
    if report:
        print(f"\nComparison complete! View: {report}")
