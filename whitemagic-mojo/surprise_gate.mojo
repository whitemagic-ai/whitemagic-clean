"""Surprise Gate - GPU Novelty Detection (PSR-001)
Target: 100× speedup for novelty detection
"""

from tensor import Tensor
from math import sqrt

struct SurpriseGate:
    var dimension: Int
    var history: DynamicVector[Tensor[DType.float32]]
    var threshold: Float32
    
    fn __init__(inout self, dimension: Int, threshold: Float32):
        self.dimension = dimension
        self.history = DynamicVector[Tensor[DType.float32]]()
        self.threshold = threshold
    
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
    
    fn is_novel(self, vector: Tensor[DType.float32]) -> Bool:
        """Check if vector is novel compared to history."""
        if len(self.history) == 0:
            return True
        
        var max_similarity: Float32 = 0.0
        
        for i in range(len(self.history)):
            let sim = self.cosine_similarity(vector, self.history[i])
            if sim > max_similarity:
                max_similarity = sim
        
        return max_similarity < self.threshold
    
    fn add_to_history(inout self, vector: Tensor[DType.float32]):
        """Add vector to history."""
        self.history.push_back(vector)
    
    fn compute_surprise(self, vector: Tensor[DType.float32]) -> Float32:
        """Compute surprise score (1 - max_similarity)."""
        if len(self.history) == 0:
            return 1.0
        
        var max_similarity: Float32 = 0.0
        
        for i in range(len(self.history)):
            let sim = self.cosine_similarity(vector, self.history[i])
            if sim > max_similarity:
                max_similarity = sim
        
        return 1.0 - max_similarity
    
    fn history_size(self) -> Int:
        """Get history size."""
        return len(self.history)

fn main():
    var gate = SurpriseGate(128, 0.9)
    
    var vec1 = Tensor[DType.float32](128)
    for i in range(128):
        vec1[i] = Float32(i) / 128.0
    
    let is_novel = gate.is_novel(vec1)
    print("Is novel:", is_novel)
    
    gate.add_to_history(vec1)
    
    let surprise = gate.compute_surprise(vec1)
    print("Surprise score:", surprise)
