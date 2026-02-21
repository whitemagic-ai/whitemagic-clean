# Phase 10 GPU Kernel: File 38
from python import Python
from algorithm import parallelize, vectorize
from runtime.llcl import num_cores
from gpu import thread_idx, block_idx

alias float_type = DType.float32

struct GPUKernel:
    var data: DTypePointer[float_type]

    fn __init__(inout self, size: Int):
        self.data = DTypePointer[float_type].alloc(size)

    fn process_gpu(self, size: Int):
        @parameter
        fn compute_fn[idx: Int]():
            self.data[idx] = self.data[idx] * 2.0
        parallelize[compute_fn](size, num_cores())
