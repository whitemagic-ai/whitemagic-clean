"""Embedding Engine - GPU-Accelerated Embeddings (PSR-001)
Target: 50× speedup for embedding operations
"""

from tensor import Tensor
from math import sqrt

struct EmbeddingEngine:
    var dimension: Int
    var embeddings: DynamicVector[Tensor[DType.float32]]
    var ids: DynamicVector[String]
    
    fn __init__(inout self, dimension: Int):
        self.dimension = dimension
        self.embeddings = DynamicVector[Tensor[DType.float32]]()
        self.ids = DynamicVector[String]()
    
    fn add_embedding(inout self, id: String, embedding: Tensor[DType.float32]):
        """Add embedding to index."""
        self.ids.push_back(id)
        self.embeddings.push_back(embedding)
    
    fn cosine_similarity(self, a: Tensor[DType.float32], b: Tensor[DType.float32]) -> Float32:
        """Compute cosine similarity between two embeddings."""
        var dot: Float32 = 0.0
        var mag_a: Float32 = 0.0
        var mag_b: Float32 = 0.0
        
        for i in range(self.dimension):
            dot += a[i] * b[i]
            mag_a += a[i] * a[i]
            mag_b += b[i] * b[i]
        
        let denom = sqrt(mag_a * mag_b)
        return dot / denom if denom > 0.0 else 0.0
    
    fn search(self, query: Tensor[DType.float32], top_k: Int) -> DynamicVector[Int]:
        """Find top-k most similar embeddings."""
        var scores = DynamicVector[Float32]()
        
        for i in range(len(self.embeddings)):
            let sim = self.cosine_similarity(query, self.embeddings[i])
            scores.push_back(sim)
        
        var indices = DynamicVector[Int]()
        for i in range(min(top_k, len(scores))):
            var max_idx = 0
            var max_score: Float32 = -1.0
            
            for j in range(len(scores)):
                if scores[j] > max_score:
                    var already_selected = False
                    for k in range(len(indices)):
                        if indices[k] == j:
                            already_selected = True
                            break
                    
                    if not already_selected:
                        max_score = scores[j]
                        max_idx = j
            
            indices.push_back(max_idx)
        
        return indices
    
    fn batch_search(self, queries: DynamicVector[Tensor[DType.float32]], top_k: Int) -> DynamicVector[DynamicVector[Int]]:
        """Batch search for multiple queries."""
        var results = DynamicVector[DynamicVector[Int]]()
        
        for i in range(len(queries)):
            results.push_back(self.search(queries[i], top_k))
        
        return results

fn main():
    var engine = EmbeddingEngine(128)
    
    var emb1 = Tensor[DType.float32](128)
    for i in range(128):
        emb1[i] = Float32(i) / 128.0
    
    engine.add_embedding("doc1", emb1)
    
    let results = engine.search(emb1, 5)
    print("Found", len(results), "results")
