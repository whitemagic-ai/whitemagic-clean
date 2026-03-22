import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.h"

with open(file_path, "r") as f:
    content = f.read()

patch = """
#include <immintrin.h>
#include <stdio.h>
#include <string.h>

// Vectorized AVX2 cosine similarity
static inline float dot_avx2(float* restrict v1, float* restrict v2) {
    __m256 sum_dot = _mm256_setzero_ps();
    __m256 temp_v1, temp_v2;
    int i = 0;
    
    // Process 8 floats at a time
    for (; i <= 384 - 8; i += 8) {
        temp_v1 = _mm256_loadu_ps(&v1[i]);
        temp_v2 = _mm256_loadu_ps(&v2[i]);
        sum_dot = _mm256_add_ps(sum_dot, _mm256_mul_ps(temp_v1, temp_v2));
    }
    
    float dot_arr[8];
    _mm256_storeu_ps(dot_arr, sum_dot);
    
    float dot = 0.0f;
    for (int j = 0; j < 8; j++) dot += dot_arr[j];
    
    // Tail
    for (; i < 384; i++) {
        dot += v1[i] * v2[i];
    }
    
    return dot;
}

#pragma GCC push_options
#pragma GCC optimize("O3,unroll-loops,tree-vectorize")
static inline kk_string_t kk_shm_search_top5(int64_t addr, kk_integer_t count_val, kk_integer_t query_id_val, kk_context_t* ctx) {
    intptr_t count = kk_integer_clamp_ssize_t(count_val, ctx);
    intptr_t query_id = kk_integer_clamp_ssize_t(query_id_val, ctx);
    
    intptr_t header_size = 64;
    intptr_t slot_size = 1540;
    
    intptr_t query_off = header_size + (query_id * slot_size);
    float* q_vec = (float*)(addr + query_off + 4);
    
    // Top 5 buffer (min heap effectively as sorted array)
    float top_scores[5] = {-2.0f, -2.0f, -2.0f, -2.0f, -2.0f};
    int32_t top_ids[5] = {-1, -1, -1, -1, -1};
    
    for (intptr_t i = 0; i < count; i++) {
        intptr_t item_off = header_size + (i * slot_size);
        int32_t item_id = *(int32_t*)(addr + item_off);
        float* item_vec = (float*)(addr + item_off + 4);
        
        float score = dot_avx2(q_vec, item_vec);
        
        // Insert into sorted top 5
        if (score > top_scores[4]) {
            int insert_idx = 4;
            while (insert_idx > 0 && score > top_scores[insert_idx - 1]) {
                top_scores[insert_idx] = top_scores[insert_idx - 1];
                top_ids[insert_idx] = top_ids[insert_idx - 1];
                insert_idx--;
            }
            top_scores[insert_idx] = score;
            top_ids[insert_idx] = item_id;
        }
    }
    
    char buf[1024];
    snprintf(buf, sizeof(buf), "[{\\"id\\":%d,\\"score\\":%f},{\\"id\\":%d,\\"score\\":%f},{\\"id\\":%d,\\"score\\":%f},{\\"id\\":%d,\\"score\\":%f},{\\"id\\":%d,\\"score\\":%f}]",
        top_ids[0], top_scores[0],
        top_ids[1], top_scores[1],
        top_ids[2], top_scores[2],
        top_ids[3], top_scores[3],
        top_ids[4], top_scores[4]);
        
    return kk_string_alloc_dup_utf8(ctx, buf);
}
#pragma GCC pop_options
#endif
"""

pattern = r'#include <immintrin\.h>.*?#endif'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("shm_search.h C-level hot loop optimization applied!")
