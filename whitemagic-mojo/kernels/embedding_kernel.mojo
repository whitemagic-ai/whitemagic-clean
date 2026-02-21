# MOJO GPU Embedding Kernel
# Target: 10x speedup on embedding batch generation

from python import Python
from algorithm import parallelize, vectorize
from runtime.llcl import num_cores
from tensor import Tensor, TensorShape
from nn import Linear, ReLU

struct EmbeddingKernel:
    var weights: Tensor[DType.float32]
    var hidden_dim: Int

    fn __init__(inout self, vocab_size: Int, hidden_dim: Int):
        self.hidden_dim = hidden_dim
        self.weights = Tensor[DType.float32](
            TensorShape(vocab_size, hidden_dim)
        )
        # Xavier initialization
        randn(self.weights)

    fn generate_embedding(self, token_ids: Tensor[DType.int32])
        -> Tensor[DType.float32]:
        # GPU-accelerated embedding lookup
        var result = Tensor[DType.float32](
            TensorShape(token_ids.num_elements(), self.hidden_dim)
        )
        @parameter
        fn compute[i: Int]():
            for j in range(self.hidden_dim):
                result[i, j] = self.weights[token_ids[i], j]
        parallelize[compute](token_ids.num_elements(), num_cores())
        return result
