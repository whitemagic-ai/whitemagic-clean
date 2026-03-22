import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.h"

with open(file_path, "r") as f:
    content = f.read()

# Replace kk_shm_cosine_sim with our new kk_shm_search_top5
patch = """
#pragma GCC push_options
#pragma GCC optimize("O3,unroll-loops,tree-vectorize")
static inline kk_string_t kk_shm_search_top5(int64_t addr, kk_integer_t kk_count, kk_integer_t kk_query_idx, kk_context_t* ctx) {
    intptr_t count = kk_integer_clamp_ssize_t(kk_count, ctx);
    intptr_t query_idx = kk_integer_clamp_ssize_t(kk_query_idx, ctx);
    intptr_t dim = 384;
    intptr_t header_size = 64;
    intptr_t slot_size = 1540; // 4 bytes id + 384*4 bytes vector

    intptr_t query_off = header_size + (query_idx * slot_size) + 4;
    float* restrict q_vec = (float*)(addr + query_off);

    // Pre-calculate query magnitude
    float q_mag = 0.0f;
    for (int i = 0; i < dim; i++) {
        q_mag += q_vec[i] * q_vec[i];
    }
    
    // We want top 5 scores
    float best_scores[5] = {-2.0f, -2.0f, -2.0f, -2.0f, -2.0f};
    int32_t best_ids[5] = {0, 0, 0, 0, 0};

    for (intptr_t i = 0; i < count; i++) {
        intptr_t item_off = header_size + (i * slot_size);
        int32_t item_id = *(int32_t*)(addr + item_off);
        float* restrict vec = (float*)(addr + item_off + 4);
        
        float dot = 0.0f;
        float v_mag = 0.0f;
        
        #pragma GCC ivdep
        for (intptr_t j = 0; j < dim; j++) {
            float a = q_vec[j];
            float b = vec[j];
            dot += a * b;
            v_mag += b * b;
        }
        
        float score = 0.0f;
        if (q_mag > 0.0f && v_mag > 0.0f) {
            score = dot / (sqrtf(q_mag) * sqrtf(v_mag));
        }
        
        if (score > best_scores[4]) {
            best_scores[4] = score;
            best_ids[4] = item_id;
            
            // Bubble up
            for (int k = 4; k > 0; k--) {
                if (best_scores[k] > best_scores[k-1]) {
                    float tmp_s = best_scores[k-1];
                    best_scores[k-1] = best_scores[k];
                    best_scores[k] = tmp_s;
                    
                    int32_t tmp_i = best_ids[k-1];
                    best_ids[k-1] = best_ids[k];
                    best_ids[k] = tmp_i;
                } else {
                    break;
                }
            }
        }
    }

    char buf[512];
    snprintf(buf, sizeof(buf), "[{\\"id\\":%d,\\"score\\":%.6f},{\\"id\\":%d,\\"score\\":%.6f},{\\"id\\":%d,\\"score\\":%.6f},{\\"id\\":%d,\\"score\\":%.6f},{\\"id\\":%d,\\"score\\":%.6f}]",
             best_ids[0], best_scores[0],
             best_ids[1], best_scores[1],
             best_ids[2], best_scores[2],
             best_ids[3], best_scores[3],
             best_ids[4], best_scores[4]);

    return kk_string_alloc_dup_utf8(buf, ctx);
}
#pragma GCC pop_options
"""

pattern = r'#pragma GCC push_options.*?#pragma GCC pop_options'
content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.h patched with kk_shm_search_top5!")
