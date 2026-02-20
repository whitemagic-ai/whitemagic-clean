//! Graph Engine - Core Graph Operations (PSR-003)
//! Target: 30× speedup for graph operations

use pyo3::prelude::*;
use std::collections::{HashMap, HashSet, VecDeque};
use rayon::prelude::*;

#[derive(Clone, Debug)]
#[pyclass]
pub struct GraphEdge {
    #[pyo3(get)]
    pub source: String,
    #[pyo3(get)]
    pub target: String,
    #[pyo3(get)]
    pub weight: f64,
    #[pyo3(get)]
    pub edge_type: String,
}

#[pymethods]
impl GraphEdge {
    #[new]
    fn new(source: String, target: String, weight: f64, edge_type: String) -> Self {
        Self {
            source,
            target,
            weight,
            edge_type,
        }
    }
}

#[pyclass]
pub struct PyGraphEngine {
    adjacency: HashMap<String, Vec<GraphEdge>>,
    reverse_adjacency: HashMap<String, Vec<GraphEdge>>,
}

#[pymethods]
impl PyGraphEngine {
    #[new]
    fn new() -> Self {
        Self {
            adjacency: HashMap::new(),
            reverse_adjacency: HashMap::new(),
        }
    }

    fn add_edge(&mut self, edge: GraphEdge) {
        self.adjacency
            .entry(edge.source.clone())
            .or_insert_with(Vec::new)
            .push(edge.clone());
        
        self.reverse_adjacency
            .entry(edge.target.clone())
            .or_insert_with(Vec::new)
            .push(edge);
    }

    fn get_neighbors(&self, node: String) -> Vec<GraphEdge> {
        self.adjacency.get(&node).cloned().unwrap_or_default()
    }

    fn get_predecessors(&self, node: String) -> Vec<GraphEdge> {
        self.reverse_adjacency.get(&node).cloned().unwrap_or_default()
    }

    fn bfs(&self, start: String, max_depth: Option<usize>) -> Vec<String> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        let mut result = Vec::new();
        
        queue.push_back((start.clone(), 0));
        visited.insert(start);
        
        let depth_limit = max_depth.unwrap_or(usize::MAX);
        
        while let Some((node, depth)) = queue.pop_front() {
            if depth > depth_limit {
                break;
            }
            
            result.push(node.clone());
            
            if let Some(edges) = self.adjacency.get(&node) {
                for edge in edges {
                    if !visited.contains(&edge.target) {
                        visited.insert(edge.target.clone());
                        queue.push_back((edge.target.clone(), depth + 1));
                    }
                }
            }
        }
        
        result
    }

    fn dfs(&self, start: String, max_depth: Option<usize>) -> Vec<String> {
        let mut visited = HashSet::new();
        let mut stack = Vec::new();
        let mut result = Vec::new();
        
        stack.push((start.clone(), 0));
        
        let depth_limit = max_depth.unwrap_or(usize::MAX);
        
        while let Some((node, depth)) = stack.pop() {
            if depth > depth_limit || visited.contains(&node) {
                continue;
            }
            
            visited.insert(node.clone());
            result.push(node.clone());
            
            if let Some(edges) = self.adjacency.get(&node) {
                for edge in edges.iter().rev() {
                    if !visited.contains(&edge.target) {
                        stack.push((edge.target.clone(), depth + 1));
                    }
                }
            }
        }
        
        result
    }

    fn shortest_path(&self, start: String, end: String) -> Option<Vec<String>> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        let mut parent: HashMap<String, String> = HashMap::new();
        
        queue.push_back(start.clone());
        visited.insert(start.clone());
        
        while let Some(node) = queue.pop_front() {
            if node == end {
                let mut path = vec![end.clone()];
                let mut current = end;
                
                while let Some(p) = parent.get(&current) {
                    path.push(p.clone());
                    current = p.clone();
                }
                
                path.reverse();
                return Some(path);
            }
            
            if let Some(edges) = self.adjacency.get(&node) {
                for edge in edges {
                    if !visited.contains(&edge.target) {
                        visited.insert(edge.target.clone());
                        parent.insert(edge.target.clone(), node.clone());
                        queue.push_back(edge.target.clone());
                    }
                }
            }
        }
        
        None
    }

    fn node_count(&self) -> usize {
        let mut nodes = HashSet::new();
        for node in self.adjacency.keys() {
            nodes.insert(node);
        }
        for node in self.reverse_adjacency.keys() {
            nodes.insert(node);
        }
        nodes.len()
    }

    fn edge_count(&self) -> usize {
        self.adjacency.values().map(|v| v.len()).sum()
    }

    fn degree(&self, node: String) -> usize {
        self.adjacency.get(&node).map(|v| v.len()).unwrap_or(0)
    }

    fn in_degree(&self, node: String) -> usize {
        self.reverse_adjacency.get(&node).map(|v| v.len()).unwrap_or(0)
    }

    fn get_connected_component(&self, start: String) -> Vec<String> {
        self.bfs(start, None)
    }

    fn parallel_bfs(&self, starts: Vec<String>, max_depth: Option<usize>) -> Vec<Vec<String>> {
        starts
            .par_iter()
            .map(|start| self.bfs(start.clone(), max_depth))
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_engine_creation() {
        let engine = PyGraphEngine::new();
        assert_eq!(engine.node_count(), 0);
    }

    #[test]
    fn test_add_edge() {
        let mut engine = PyGraphEngine::new();
        let edge = GraphEdge::new("a".to_string(), "b".to_string(), 1.0, "link".to_string());
        
        engine.add_edge(edge);
        assert_eq!(engine.edge_count(), 1);
    }

    #[test]
    fn test_bfs() {
        let mut engine = PyGraphEngine::new();
        engine.add_edge(GraphEdge::new("a".to_string(), "b".to_string(), 1.0, "link".to_string()));
        engine.add_edge(GraphEdge::new("b".to_string(), "c".to_string(), 1.0, "link".to_string()));
        
        let visited = engine.bfs("a".to_string(), None);
        assert!(visited.len() >= 2);
    }

    #[test]
    fn test_shortest_path() {
        let mut engine = PyGraphEngine::new();
        engine.add_edge(GraphEdge::new("a".to_string(), "b".to_string(), 1.0, "link".to_string()));
        engine.add_edge(GraphEdge::new("b".to_string(), "c".to_string(), 1.0, "link".to_string()));
        
        let path = engine.shortest_path("a".to_string(), "c".to_string());
        assert!(path.is_some());
        assert_eq!(path.unwrap().len(), 3);
    }

    #[test]
    fn test_degree() {
        let mut engine = PyGraphEngine::new();
        engine.add_edge(GraphEdge::new("a".to_string(), "b".to_string(), 1.0, "link".to_string()));
        engine.add_edge(GraphEdge::new("a".to_string(), "c".to_string(), 1.0, "link".to_string()));
        
        assert_eq!(engine.degree("a".to_string()), 2);
        assert_eq!(engine.in_degree("b".to_string()), 1);
    }
}
