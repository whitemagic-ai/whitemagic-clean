import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_graph.h"

with open(file_path, "r") as f:
    content = f.read()

patch = """
    int32_t* active_nodes = malloc(1000 * sizeof(int32_t));
    int32_t* next_nodes = malloc(1000 * sizeof(int32_t));
    int active_count = 1;
    active_nodes[0] = start_id;
    
    int traversed_edges = 0;
    int total_nodes_visited = 1;
    
    for (int h = 0; h < hops; h++) {
        int next_count = 0;
        
        for (intptr_t i = 0; i < count; i++) {
            intptr_t offset = GRAPH_HEADER_SIZE + (i * GRAPH_SLOT_SIZE);
            int32_t src = *(int32_t*)(addr + offset);
            int32_t tgt = *(int32_t*)(addr + offset + 4);
            
            for (int a = 0; a < active_count; a++) {
                if (src == active_nodes[a]) {
                    // Check if already in next_nodes to avoid explosion
                    int already_in = 0;
                    for (int n = 0; n < next_count; n++) {
                        if (next_nodes[n] == tgt) {
                            already_in = 1;
                            break;
                        }
                    }
                    if (!already_in && next_count < 1000) {
                        next_nodes[next_count++] = tgt;
                    }
                    traversed_edges++;
                    break;
                }
            }
        }
        
        memcpy(active_nodes, next_nodes, next_count * sizeof(int32_t));
        active_count = next_count;
        total_nodes_visited += active_count;
        
        if (active_count == 0) break;
    }
    
    free(active_nodes);
    free(next_nodes);
    
    char buf[256];
    snprintf(buf, sizeof(buf), "{\\"nodes_visited\\":%d,\\"edges_traversed\\":%d}", total_nodes_visited, traversed_edges);
"""

pattern = r'    int32_t\* active_nodes = malloc\(1000 \* sizeof\(int32_t\)\);.*?    snprintf\(buf, sizeof\(buf\), "\\{\\\\"nodes_visited\\\\":%d,\\\\"edges_traversed\\\\":%d\\}", active_count, traversed_edges\);'

content = re.sub(pattern, patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_graph.h logic updated")
