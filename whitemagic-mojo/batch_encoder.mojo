"""Batch Encoder - GPU Batch Encoding (PSR-002)
Target: 50× speedup for batch encoding
"""

from tensor import Tensor

struct BatchEncoder:
    var dimension: Int
    var batch_size: Int
    
    fn __init__(inout self, dimension: Int, batch_size: Int):
        self.dimension = dimension
        self.batch_size = batch_size
    
    fn encode_batch(self, inputs: DynamicVector[Tensor[DType.float32]]) -> Tensor[DType.float32]:
        """Encode a batch of inputs."""
        let actual_batch_size = len(inputs)
        var result = Tensor[DType.float32](actual_batch_size * self.dimension)
        
        for b in range(actual_batch_size):
            for d in range(self.dimension):
                result[b * self.dimension + d] = inputs[b][d]
        
        return result
    
    fn normalize_batch(self, batch: Tensor[DType.float32], num_items: Int) -> Tensor[DType.float32]:
        """Normalize batch of vectors."""
        var result = Tensor[DType.float32](num_items * self.dimension)
        
        for i in range(num_items):
            var magnitude: Float32 = 0.0
            
            for d in range(self.dimension):
                let val = batch[i * self.dimension + d]
                magnitude += val * val
            
            magnitude = magnitude ** 0.5
            
            for d in range(self.dimension):
                let idx = i * self.dimension + d
                result[idx] = batch[idx] / magnitude if magnitude > 0.0 else 0.0
        
        return result
    
    fn compute_pairwise_similarity(self, batch: Tensor[DType.float32], num_items: Int) -> Tensor[DType.float32]:
        """Compute pairwise similarities within batch."""
        var result = Tensor[DType.float32](num_items * num_items)
        
        for i in range(num_items):
            for j in range(num_items):
                var dot: Float32 = 0.0
                
                for d in range(self.dimension):
                    dot += batch[i * self.dimension + d] * batch[j * self.dimension + d]
                
                result[i * num_items + j] = dot
        
        return result

fn main():
    let encoder = BatchEncoder(128, 32)
    
    var inputs = DynamicVector[Tensor[DType.float32]]()
    
    for _ in range(10):
        var vec = Tensor[DType.float32](128)
        for i in range(128):
            vec[i] = Float32(i) / 128.0
        inputs.push_back(vec)
    
    let encoded = encoder.encode_batch(inputs)
    let normalized = encoder.normalize_batch(encoded, 10)
    
    print("Encoded batch shape:", len(inputs), "x", 128)
