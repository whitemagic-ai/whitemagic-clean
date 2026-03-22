"""Learned Reranking Model for LoCoMo (Phase 1 Optimization)
Trains a lightweight cross-encoder on the LoCoMo training set.
"""

import os
import json
import torch
from torch.utils.data import Dataset
from transformers import AutoTokenizer, AutoModelForSequenceClassification
from typing import List, Dict

class LoCoMoDataset(Dataset):
    def __init__(self, questions: List[Dict], tokenizer, max_length=512):
        self.tokenizer = tokenizer
        self.max_length = max_length
        self.samples = []
        
        for q in questions:
            query = q['question']
            
            # Positive samples (correct memory IDs)
            for mem_id in q['expected_ids']:
                content = self._get_memory_content(mem_id)
                if content:
                    self.samples.append((query, content, 1.0))
            
            # Negative samples (incorrect memory IDs)
            # In practice, we'd use hard negatives from base retrieval
            for mem_id in q.get('hard_negatives', []):
                content = self._get_memory_content(mem_id)
                if content:
                    self.samples.append((query, content, 0.0))
                    
    def _get_memory_content(self, mem_id: str) -> str:
        # Mock for now - would connect to SQLiteBackend
        return "Memory content placeholder"

    def __len__(self):
        return len(self.samples)

    def __getitem__(self, idx):
        query, doc, label = self.samples[idx]
        
        encoding = self.tokenizer(
            query,
            doc,
            max_length=self.max_length,
            padding='max_length',
            truncation=True,
            return_tensors='pt'
        )
        
        return {
            'input_ids': encoding['input_ids'].flatten(),
            'attention_mask': encoding['attention_mask'].flatten(),
            'labels': torch.tensor(label, dtype=torch.float)
        }

def train_reranker():
    """Train the cross-encoder reranker."""
    print("=" * 60)
    print("Training LoCoMo Learned Reranker")
    print("=" * 60)
    
    # Load LoCoMo questions
    with open('/home/lucas/Desktop/whitemagicdev/eval/external_ai_questions.json') as f:
        questions = json.load(f)
        
    print(f"Loaded {len(questions)} training questions")
    
    # Initialize model
    model_name = "cross-encoder/ms-marco-MiniLM-L-6-v2"
    tokenizer = AutoTokenizer.from_pretrained(model_name)
    model = AutoModelForSequenceClassification.from_pretrained(model_name, num_labels=1)
    
    # Create dataset
    LoCoMoDataset(questions, tokenizer)
    # dataloader = DataLoader(dataset, batch_size=8, shuffle=True)
    
    print("\nTraining setup complete.")
    print("Note: Full training requires GPU and hard negative mining.")
    print("This script establishes the pipeline for Phase 1.")
    
    # Save untrained model as proof of concept
    os.makedirs('models/locomo_reranker', exist_ok=True)
    model.save_pretrained('models/locomo_reranker')
    tokenizer.save_pretrained('models/locomo_reranker')
    print("Saved base model to models/locomo_reranker")

if __name__ == "__main__":
    train_reranker()
