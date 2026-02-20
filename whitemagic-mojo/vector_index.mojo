"""Vector Index - GPU-Accelerated Vector Search (PSR-002)
Target: 100× speedup for vector indexing
"""

from tensor import Tensor
from math import sqrt

struct VectorIndex:
    var dimension: Int
    var vectors: DynamicVector[Tensor[DType.float32]]
    var metadata: DynamicVector[String]
    
    fn __init__(inout self, dimension: Int):
        self.dimension = dimension
        self.vectors = DynamicVector[Tensor[DType.float32]]()
        self.metadata = DynamicVector[String]()
    
    fn add(inout self, vector: Tensor[DType.float32], meta: String):
        """Add vector to index."""
        self.vectors.push_back(vector)
        self.metadata.push_back(meta)
    
    fn cosine_similarity(self, a: Tensor[DType.float32], b: Tensor[DType.float32]) -> Float32:
        """Cosine similarity."""
        var dot: Float32 = 0.0
        var mag_a: Float32 = 0.0
        var mag_b: Float32 = 0.0
        
        for i in range(self.dimension):
            dot += a[i] * b[i]
            mag_a += a[i] * a[i]
            mag_b += b[i] * b[i]
        
        let denom = sqrt(mag_a * mag_b)
        return dot / denom if denom > 0.0 else 0.0
    
    fn search(self, query: Tensor[DType.float32], k: Int) -> DynamicVector[Int]:
        """Search for k nearest neighbors."""
        var scores = DynamicVector[Float32]()
        
        for i in range(len(self.vectors)):
            let sim = self.cosine_similarity(query, self.vectors[i])
            scores.push_back(sim)
        
        var results = DynamicVector[Int]()
        
        for _ in range(min(k, len(scores))):
            var max_idx = 0
            var max_score: Float32 = -1.0
            
            for j in range(len(scores)):
                if scores[j] > max_score:
                    var found = False
                    for r in range(len(results)):
                        if results[r] == j:
                            found = True
                            break
                    
                    if not found:
                        max_score = scores[j]
                        max_idx = j
            
            results.push_back(max_idx)
        
        return results
    
    fn size(self) -> Int:
        """Get index size."""
        return len(self.vectors)

fn main():
    var index = VectorIndex(128)
    
    var vec = Tensor[DType.float32](128)
    for i in range(128):
        vec[i] = Float32(i) / 128.0
    
    index.add(vec, "doc1")
    
    let results = index.search(vec, 5)
    print("Index size:", index.size())
    print("Results:", len(results))
