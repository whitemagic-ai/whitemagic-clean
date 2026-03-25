"""GPU Inference - Mojo 0.26.1 CPU fallback"""

fn linear_layer(input: List[Float32], weights: List[List[Float32]], bias: List[Float32]) -> List[Float32]:
    """Linear layer forward pass."""
    var result = List[Float32]()
    for i in range(len(weights)):
        var sum: Float32 = 0.0
        for j in range(len(input)):
            if j < len(weights[i]):
                sum += input[j] * weights[i][j]
        if i < len(bias):
            sum += bias[i]
        result.append(sum)
    return result^

fn relu(v: List[Float32]) -> List[Float32]:
    """ReLU activation."""
    var result = List[Float32]()
    for i in range(len(v)):
        result.append(v[i] if v[i] > 0.0 else 0.0)
    return result^

fn main():
    print("GPU Inference v0.26.1 (CPU fallback)")
