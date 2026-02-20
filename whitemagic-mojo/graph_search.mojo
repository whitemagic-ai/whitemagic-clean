"""Graph Search - GPU Graph Operations (PSR-002)
Target: 100× speedup for graph search
"""

from tensor import Tensor

struct GraphSearch:
    var num_nodes: Int
    var adjacency: Tensor[DType.int32]
    
    fn __init__(inout self, num_nodes: Int):
        self.num_nodes = num_nodes
        self.adjacency = Tensor[DType.int32](num_nodes * num_nodes)
        
        for i in range(num_nodes * num_nodes):
            self.adjacency[i] = 0
    
    fn add_edge(inout self, source: Int, target: Int):
        """Add edge to graph."""
        self.adjacency[source * self.num_nodes + target] = 1
    
    fn bfs(self, start: Int, max_depth: Int) -> DynamicVector[Int]:
        """Breadth-first search."""
        var visited = Tensor[DType.int32](self.num_nodes)
        for i in range(self.num_nodes):
            visited[i] = 0
        
        var queue = DynamicVector[Int]()
        var result = DynamicVector[Int]()
        
        queue.push_back(start)
        visited[start] = 1
        
        var depth = 0
        
        while len(queue) > 0 and depth < max_depth:
            let current = queue[0]
            queue.pop_front()
            result.push_back(current)
            
            for neighbor in range(self.num_nodes):
                if self.adjacency[current * self.num_nodes + neighbor] == 1 and visited[neighbor] == 0:
                    visited[neighbor] = 1
                    queue.push_back(neighbor)
            
            depth += 1
        
        return result
    
    fn shortest_path(self, start: Int, end: Int) -> Int:
        """Find shortest path length."""
        var visited = Tensor[DType.int32](self.num_nodes)
        var distance = Tensor[DType.int32](self.num_nodes)
        
        for i in range(self.num_nodes):
            visited[i] = 0
            distance[i] = -1
        
        var queue = DynamicVector[Int]()
        queue.push_back(start)
        visited[start] = 1
        distance[start] = 0
        
        while len(queue) > 0:
            let current = queue[0]
            queue.pop_front()
            
            if current == end:
                return distance[end]
            
            for neighbor in range(self.num_nodes):
                if self.adjacency[current * self.num_nodes + neighbor] == 1 and visited[neighbor] == 0:
                    visited[neighbor] = 1
                    distance[neighbor] = distance[current] + 1
                    queue.push_back(neighbor)
        
        return -1

fn main():
    var graph = GraphSearch(10)
    
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    graph.add_edge(2, 3)
    
    let path = graph.bfs(0, 5)
    print("BFS visited", len(path), "nodes")
    
    let dist = graph.shortest_path(0, 3)
    print("Shortest path length:", dist)
