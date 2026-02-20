"""Community Detection - GPU Community Detection (PSR-003)
Target: 100× speedup for community detection
"""

from tensor import Tensor

struct CommunityDetection:
    var num_nodes: Int
    var adjacency: Tensor[DType.int32]
    var communities: Tensor[DType.int32]
    
    fn __init__(inout self, num_nodes: Int):
        self.num_nodes = num_nodes
        self.adjacency = Tensor[DType.int32](num_nodes * num_nodes)
        self.communities = Tensor[DType.int32](num_nodes)
        
        for i in range(num_nodes * num_nodes):
            self.adjacency[i] = 0
        
        for i in range(num_nodes):
            self.communities[i] = i
    
    fn add_edge(inout self, source: Int, target: Int):
        """Add edge to graph."""
        self.adjacency[source * self.num_nodes + target] = 1
        self.adjacency[target * self.num_nodes + source] = 1
    
    fn compute_modularity(self) -> Float32:
        """Compute modularity of current community assignment."""
        var m: Float32 = 0.0
        
        for i in range(self.num_nodes):
            for j in range(self.num_nodes):
                if self.adjacency[i * self.num_nodes + j] == 1:
                    m += 1.0
        
        m = m / 2.0
        
        if m == 0.0:
            return 0.0
        
        var modularity: Float32 = 0.0
        
        for i in range(self.num_nodes):
            for j in range(self.num_nodes):
                if self.communities[i] == self.communities[j]:
                    let a_ij = Float32(self.adjacency[i * self.num_nodes + j])
                    
                    var k_i: Float32 = 0.0
                    var k_j: Float32 = 0.0
                    
                    for k in range(self.num_nodes):
                        k_i += Float32(self.adjacency[i * self.num_nodes + k])
                        k_j += Float32(self.adjacency[j * self.num_nodes + k])
                    
                    modularity += a_ij - (k_i * k_j) / (2.0 * m)
        
        return modularity / (2.0 * m)
    
    fn detect_communities(inout self, iterations: Int):
        """Simple community detection via label propagation."""
        for _ in range(iterations):
            for node in range(self.num_nodes):
                var label_counts = Tensor[DType.int32](self.num_nodes)
                
                for i in range(self.num_nodes):
                    label_counts[i] = 0
                
                for neighbor in range(self.num_nodes):
                    if self.adjacency[node * self.num_nodes + neighbor] == 1:
                        let label = self.communities[neighbor]
                        label_counts[label] += 1
                
                var max_count = 0
                var max_label = self.communities[node]
                
                for i in range(self.num_nodes):
                    if label_counts[i] > max_count:
                        max_count = label_counts[i]
                        max_label = i
                
                self.communities[node] = max_label
    
    fn get_community_count(self) -> Int:
        """Get number of unique communities."""
        var unique = Tensor[DType.int32](self.num_nodes)
        
        for i in range(self.num_nodes):
            unique[i] = 0
        
        for i in range(self.num_nodes):
            unique[self.communities[i]] = 1
        
        var count = 0
        for i in range(self.num_nodes):
            count += unique[i]
        
        return count

fn main():
    var detector = CommunityDetection(6)
    
    detector.add_edge(0, 1)
    detector.add_edge(1, 2)
    detector.add_edge(3, 4)
    detector.add_edge(4, 5)
    
    detector.detect_communities(10)
    
    let modularity = detector.compute_modularity()
    print("Modularity:", modularity)
    
    let num_communities = detector.get_community_count()
    print("Communities:", num_communities)
