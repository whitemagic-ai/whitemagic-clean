import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.h"

with open(file_path, "r") as f:
    content = f.read()

patch = """
#pragma GCC push_options
#pragma GCC optimize("O3,unroll-loops,tree-vectorize")
static inline double kk_shm_cosine_sim(int64_t addr, kk_integer_t off1, kk_integer_t off2, kk_integer_t dim, kk_context_t* ctx) {
    intptr_t o1 = kk_integer_clamp_ssize_t(off1, ctx);
    intptr_t o2 = kk_integer_clamp_ssize_t(off2, ctx);
    intptr_t d = kk_integer_clamp_ssize_t(dim, ctx);
    
    float* restrict v1 = (float*)(addr + o1);
    float* restrict v2 = (float*)(addr + o2);
    
    float dot = 0.0f;
    float mag1 = 0.0f;
    float mag2 = 0.0f;
    
    // Hint to compiler to vectorize
    #pragma GCC ivdep
    for (intptr_t i = 0; i < d; i++) {
        float a = v1[i];
        float b = v2[i];
        dot += a * b;
        mag1 += a * a;
        mag2 += b * b;
    }
    
    if (mag1 == 0.0f || mag2 == 0.0f) return 0.0;
    return (double)(dot / (sqrtf(mag1) * sqrtf(mag2)));
}
#pragma GCC pop_options
"""

pattern = r'// C-optimized cosine similarity.*?return dot / \(sqrt\(mag1\) \* sqrt\(mag2\)\);\n\}'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("shm_search.h SIMD optimizations applied!")
