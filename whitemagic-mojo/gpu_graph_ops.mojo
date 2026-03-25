"""GPU Graph Ops - Mojo 0.26.1 CPU fallback"""

fn spmv_csr(values: List[Float32], col_idx: List[Int], row_ptr: List[Int], x: List[Float32]) -> List[Float32]:
    """Sparse matrix-vector multiply (CSR format)."""
    var n = len(row_ptr) - 1
    var y = List[Float32]()
    for i in range(n):
        var sum: Float32 = 0.0
        for j in range(row_ptr[i], row_ptr[i + 1]):
            if j < len(values) and j < len(col_idx):
                if col_idx[j] < len(x):
                    sum += values[j] * x[col_idx[j]]
        y.append(sum)
    return y^

fn main():
    print("GPU Graph Ops v0.26.1 (CPU fallback)")
