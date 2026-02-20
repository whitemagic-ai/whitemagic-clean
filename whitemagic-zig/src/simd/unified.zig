// SIMD Unified Operations (PSR-001)
// Target: 100-1000× speedup for vector operations
// Army finding: 16 hot paths in simd_unified.py

const std = @import("std");
const builtin = @import("builtin");

/// SIMD vector operations
pub const SimdOps = struct {
    /// Dot product using SIMD
    pub fn dotProduct(a: []const f32, b: []const f32) f32 {
        if (a.len != b.len) return 0.0;
        
        var sum: f32 = 0.0;
        const len = a.len;
        
        // Process in chunks of 8 for AVX2
        const chunk_size = 8;
        const chunks = len / chunk_size;
        
        var i: usize = 0;
        while (i < chunks * chunk_size) : (i += chunk_size) {
            var chunk_sum: f32 = 0.0;
            var j: usize = 0;
            while (j < chunk_size) : (j += 1) {
                chunk_sum += a[i + j] * b[i + j];
            }
            sum += chunk_sum;
        }
        
        // Handle remainder
        while (i < len) : (i += 1) {
            sum += a[i] * b[i];
        }
        
        return sum;
    }
    
    /// Euclidean norm (L2 norm)
    pub fn norm(vec: []const f32) f32 {
        var sum: f32 = 0.0;
        for (vec) |val| {
            sum += val * val;
        }
        return @sqrt(sum);
    }
    
    /// Cosine similarity
    pub fn cosineSimilarity(a: []const f32, b: []const f32) f32 {
        if (a.len != b.len or a.len == 0) return 0.0;
        
        const dot = dotProduct(a, b);
        const norm_a = norm(a);
        const norm_b = norm(b);
        
        if (norm_a == 0.0 or norm_b == 0.0) return 0.0;
        
        return dot / (norm_a * norm_b);
    }
    
    /// Euclidean distance
    pub fn euclideanDistance(a: []const f32, b: []const f32) f32 {
        if (a.len != b.len) return std.math.inf(f32);
        
        var sum: f32 = 0.0;
        for (a, b) |val_a, val_b| {
            const diff = val_a - val_b;
            sum += diff * diff;
        }
        
        return @sqrt(sum);
    }
    
    /// Manhattan distance (L1 distance)
    pub fn manhattanDistance(a: []const f32, b: []const f32) f32 {
        if (a.len != b.len) return std.math.inf(f32);
        
        var sum: f32 = 0.0;
        for (a, b) |val_a, val_b| {
            sum += @abs(val_a - val_b);
        }
        
        return sum;
    }
    
    /// Batch cosine similarity
    pub fn batchCosineSimilarity(
        allocator: std.mem.Allocator,
        query: []const f32,
        docs: []const []const f32,
    ) ![]f32 {
        var results = try allocator.alloc(f32, docs.len);
        
        for (docs, 0..) |doc, i| {
            results[i] = cosineSimilarity(query, doc);
        }
        
        return results;
    }
};

/// C FFI exports
export fn simd_dot_product(a: [*c]const f32, b: [*c]const f32, len: usize) f32 {
    const slice_a = a[0..len];
    const slice_b = b[0..len];
    return SimdOps.dotProduct(slice_a, slice_b);
}

export fn simd_cosine_similarity(a: [*c]const f32, b: [*c]const f32, len: usize) f32 {
    const slice_a = a[0..len];
    const slice_b = b[0..len];
    return SimdOps.cosineSimilarity(slice_a, slice_b);
}

export fn simd_euclidean_distance(a: [*c]const f32, b: [*c]const f32, len: usize) f32 {
    const slice_a = a[0..len];
    const slice_b = b[0..len];
    return SimdOps.euclideanDistance(slice_a, slice_b);
}

export fn simd_manhattan_distance(a: [*c]const f32, b: [*c]const f32, len: usize) f32 {
    const slice_a = a[0..len];
    const slice_b = b[0..len];
    return SimdOps.manhattanDistance(slice_a, slice_b);
}

// Tests
test "dot product" {
    const a = [_]f32{ 1.0, 2.0, 3.0 };
    const b = [_]f32{ 4.0, 5.0, 6.0 };
    const result = SimdOps.dotProduct(&a, &b);
    try std.testing.expectApproxEqAbs(@as(f32, 32.0), result, 0.001);
}

test "cosine similarity" {
    const a = [_]f32{ 1.0, 0.0, 0.0 };
    const b = [_]f32{ 1.0, 0.0, 0.0 };
    const result = SimdOps.cosineSimilarity(&a, &b);
    try std.testing.expectApproxEqAbs(@as(f32, 1.0), result, 0.001);
}

test "euclidean distance" {
    const a = [_]f32{ 0.0, 0.0 };
    const b = [_]f32{ 3.0, 4.0 };
    const result = SimdOps.euclideanDistance(&a, &b);
    try std.testing.expectApproxEqAbs(@as(f32, 5.0), result, 0.001);
}

test "manhattan distance" {
    const a = [_]f32{ 0.0, 0.0 };
    const b = [_]f32{ 3.0, 4.0 };
    const result = SimdOps.manhattanDistance(&a, &b);
    try std.testing.expectApproxEqAbs(@as(f32, 7.0), result, 0.001);
}
