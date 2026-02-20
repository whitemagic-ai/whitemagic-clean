"""Emergence Detection - GPU Emergence Detection (PSR-004)
Target: 100× speedup for emergence detection
"""

from tensor import Tensor
from math import sqrt

struct EmergenceDetector:
    var window_size: Int
    var threshold: Float32
    
    fn __init__(inout self, window_size: Int, threshold: Float32):
        self.window_size = window_size
        self.threshold = threshold
    
    fn compute_variance(self, values: Tensor[DType.float32], start: Int, end: Int) -> Float32:
        """Compute variance of values in window."""
        var mean: Float32 = 0.0
        let count = end - start
        
        for i in range(start, end):
            mean += values[i]
        
        mean = mean / Float32(count)
        
        var variance: Float32 = 0.0
        
        for i in range(start, end):
            let diff = values[i] - mean
            variance += diff * diff
        
        variance = variance / Float32(count)
        
        return variance
    
    fn detect_phase_transition(self, time_series: Tensor[DType.float32], length: Int) -> DynamicVector[Int]:
        """Detect phase transitions in time series."""
        var transitions = DynamicVector[Int]()
        
        if length < self.window_size * 2:
            return transitions
        
        for i in range(self.window_size, length - self.window_size):
            let var_before = self.compute_variance(time_series, i - self.window_size, i)
            let var_after = self.compute_variance(time_series, i, i + self.window_size)
            
            let ratio = var_after / var_before if var_before > 0.0 else 0.0
            
            if ratio > self.threshold or (var_before > 0.0 and ratio < 1.0 / self.threshold):
                transitions.push_back(i)
        
        return transitions
    
    fn detect_synchronization(self, series1: Tensor[DType.float32], series2: Tensor[DType.float32], length: Int) -> Float32:
        """Detect synchronization between two time series."""
        var correlation: Float32 = 0.0
        var mean1: Float32 = 0.0
        var mean2: Float32 = 0.0
        
        for i in range(length):
            mean1 += series1[i]
            mean2 += series2[i]
        
        mean1 = mean1 / Float32(length)
        mean2 = mean2 / Float32(length)
        
        var numerator: Float32 = 0.0
        var denom1: Float32 = 0.0
        var denom2: Float32 = 0.0
        
        for i in range(length):
            let diff1 = series1[i] - mean1
            let diff2 = series2[i] - mean2
            
            numerator += diff1 * diff2
            denom1 += diff1 * diff1
            denom2 += diff2 * diff2
        
        let denom = sqrt(denom1 * denom2)
        
        return numerator / denom if denom > 0.0 else 0.0
    
    fn compute_complexity(self, time_series: Tensor[DType.float32], length: Int) -> Float32:
        """Compute complexity measure."""
        var complexity: Float32 = 0.0
        
        for i in range(1, length):
            let diff = time_series[i] - time_series[i - 1]
            complexity += diff * diff
        
        return sqrt(complexity / Float32(length - 1))

fn main():
    let detector = EmergenceDetector(10, 2.0)
    
    var series = Tensor[DType.float32](100)
    
    for i in range(50):
        series[i] = Float32(i) * 0.1
    
    for i in range(50, 100):
        series[i] = 5.0 + Float32(i - 50) * 0.5
    
    let transitions = detector.detect_phase_transition(series, 100)
    print("Phase transitions detected:", len(transitions))
    
    let complexity = detector.compute_complexity(series, 100)
    print("Complexity:", complexity)
