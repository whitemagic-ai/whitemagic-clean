# Phase 15 AI/ML Kernel: 130
# Optimized for neural network inference

from python import Python
from algorithm import parallelize, vectorize, reduce
from runtime.llcl import num_cores
from tensor import Tensor, TensorShape
from nn import ReLU, Softmax, Linear

struct AIModel:
    var weights: Tensor[DType.float32]
    var biases: Tensor[DType.float32]
    var layers: DynamicVector[Linear]

    fn __init__(inout self, input_dim: Int, hidden_dim: Int, output_dim: Int):
        # Initialize with Xavier initialization
        self.weights = Tensor[DType.float32](TensorShape(input_dim, hidden_dim))
        self.biases = Tensor[DType.float32](TensorShape(hidden_dim))
        self.layers = DynamicVector[Linear]()
        self.layers.append(Linear(input_dim, hidden_dim))
        self.layers.append(Linear(hidden_dim, output_dim))

    fn forward(self, input: Tensor[DType.float32]) -> Tensor[DType.float32]:
        var x = input
        for i in range(len(self.layers)):
            x = self.layers[i].forward(x)
            if i < len(self.layers) - 1:
                x = ReLU(x)
        return Softmax(x)
