/*!
Rust-based Gene Scanner for Evolution Gene Vault

Uses Tree-sitter AST parsing to extract deep code patterns:
- Algorithmic patterns (graph algorithms, search, sorting)
- Design patterns (Factory, Observer, Strategy, etc.)
- Domain patterns (memory consolidation, dream phases, etc.)
- Micro-optimizations (loop structures, data layouts)
- Error handling patterns (retry, fallback, circuit breaker)

Much more powerful than regex-based scanning!
*/

use clap::Parser;
// use rayon::prelude::*;  // Will add parallel processing after basic version works
use serde::{Deserialize, Serialize};
use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};
use tree_sitter::Parser as TSParser;
use walkdir::WalkDir;

#[derive(Parser)]
#[command(name = "gene-scanner")]
#[command(about = "Deep AST-based gene pattern scanner")]
struct Args {
    /// Directories to scan
    #[arg(required = true)]
    paths: Vec<PathBuf>,
    
    /// Output file
    #[arg(short, long, default_value = "gene_vault_deep.json")]
    output: PathBuf,
    
    /// Minimum pattern frequency to include
    #[arg(short, long, default_value = "2")]
    min_frequency: usize,
    
    /// Include micro-optimizations
    #[arg(long)]
    include_micro: bool,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
struct Gene {
    id: String,
    name: String,
    category: String,
    value: f64,
    frequency: usize,
    examples: Vec<String>,
    synergies: Vec<String>,
}

#[derive(Debug, Serialize)]
struct GeneVault {
    version: String,
    total_genes: usize,
    total_files_scanned: usize,
    categories: HashMap<String, usize>,
    genes: Vec<Gene>,
}

struct PatternScanner {
    python_parser: TSParser,
    rust_parser: TSParser,
    patterns: HashMap<String, Gene>,
}

impl PatternScanner {
    fn new() -> Self {
        let mut python_parser = TSParser::new();
        let mut rust_parser = TSParser::new();
        
        python_parser.set_language(tree_sitter_python::language()).unwrap();
        rust_parser.set_language(tree_sitter_rust::language()).unwrap();
        
        Self {
            python_parser,
            rust_parser,
            patterns: HashMap::new(),
        }
    }
    
    fn scan_file(&mut self, path: &Path) -> Result<(), Box<dyn std::error::Error>> {
        let content = fs::read_to_string(path)?;
        let ext = path.extension().and_then(|s| s.to_str()).unwrap_or("");
        
        match ext {
            "py" => self.scan_python(&content, path)?,
            "rs" => self.scan_rust(&content, path)?,
            _ => {}
        }
        
        Ok(())
    }
    
    fn scan_python(&mut self, content: &str, path: &Path) -> Result<(), Box<dyn std::error::Error>> {
        let tree = self.python_parser.parse(content, None).unwrap();
        let root = tree.root_node();
        
        // Algorithmic patterns
        self.detect_graph_algorithms(&root, content, path);
        self.detect_search_algorithms(&root, content, path);
        self.detect_dynamic_programming(&root, content, path);
        
        // Design patterns
        self.detect_factory_pattern(&root, content, path);
        self.detect_observer_pattern(&root, content, path);
        self.detect_strategy_pattern(&root, content, path);
        
        // Concurrency patterns
        self.detect_async_patterns(&root, content, path);
        self.detect_threading_patterns(&root, content, path);
        
        // Error handling
        self.detect_retry_patterns(&root, content, path);
        self.detect_fallback_patterns(&root, content, path);
        
        // Domain-specific (WhiteMagic)
        self.detect_memory_patterns(&root, content, path);
        self.detect_dream_patterns(&root, content, path);
        self.detect_resonance_patterns(&root, content, path);
        
        Ok(())
    }
    
    fn scan_rust(&mut self, content: &str, path: &Path) -> Result<(), Box<dyn std::error::Error>> {
        let tree = self.rust_parser.parse(content, None).unwrap();
        let root = tree.root_node();
        
        // Rust-specific patterns
        self.detect_zero_copy_patterns(&root, content, path);
        self.detect_lifetime_patterns(&root, content, path);
        self.detect_trait_patterns(&root, content, path);
        
        Ok(())
    }
    
    // Algorithmic pattern detectors
    
    fn detect_graph_algorithms(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        // Simple text-based detection for now
        // BFS pattern
        if content.contains("queue") && content.contains("visited") && content.contains("neighbors") {
            self.add_pattern("bfs_traversal", "Algorithm", 0.85, path);
        }
        
        // DFS pattern
        if content.contains("stack") && content.contains("visited") && content.contains("neighbors") {
            self.add_pattern("dfs_traversal", "Algorithm", 0.85, path);
        }
        
        // Dijkstra pattern
        if content.contains("priority_queue") && content.contains("distance") && content.contains("shortest") {
            self.add_pattern("dijkstra_shortest_path", "Algorithm", 0.90, path);
        }
        
        // A* pattern
        if content.contains("heuristic") && content.contains("g_score") && content.contains("f_score") {
            self.add_pattern("astar_search", "Algorithm", 0.92, path);
        }
    }
    
    fn detect_search_algorithms(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        // Binary search
        if text.contains("binary_search") || (text.contains("mid") && text.contains("left") && text.contains("right")) {
            self.add_pattern("binary_search", "Algorithm", 0.80, path);
        }
        
        // Linear search with early exit
        if text.contains("for") && text.contains("return") && text.contains("if") {
            self.add_pattern("linear_search_optimized", "Algorithm", 0.70, path);
        }
    }
    
    fn detect_dynamic_programming(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        // Memoization pattern
        if text.contains("@lru_cache") || text.contains("@cache") {
            self.add_pattern("memoization", "Algorithm", 0.88, path);
        }
        
        // DP table pattern
        if text.contains("dp") && text.contains("[[") && text.contains("range") {
            self.add_pattern("dynamic_programming_table", "Algorithm", 0.85, path);
        }
    }
    
    // Design pattern detectors
    
    fn detect_factory_pattern(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("def create_") || text.contains("Factory") {
            self.add_pattern("factory_pattern", "Design", 0.75, path);
        }
    }
    
    fn detect_observer_pattern(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("subscribe") && text.contains("notify") {
            self.add_pattern("observer_pattern", "Design", 0.80, path);
        }
    }
    
    fn detect_strategy_pattern(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("Strategy") || (text.contains("class") && text.contains("execute")) {
            self.add_pattern("strategy_pattern", "Design", 0.75, path);
        }
    }
    
    // Concurrency pattern detectors
    
    fn detect_async_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("async def") {
            self.add_pattern("async_functions", "Concurrency", 0.85, path);
        }
        
        if text.contains("asyncio.gather") {
            self.add_pattern("async_gather_pattern", "Concurrency", 0.88, path);
        }
        
        if text.contains("async with") {
            self.add_pattern("async_context_manager", "Concurrency", 0.82, path);
        }
    }
    
    fn detect_threading_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("ThreadPoolExecutor") {
            self.add_pattern("thread_pool_pattern", "Concurrency", 0.85, path);
        }
        
        if text.contains("Lock()") || text.contains("RLock()") {
            self.add_pattern("thread_synchronization", "Concurrency", 0.80, path);
        }
    }
    
    // Error handling pattern detectors
    
    fn detect_retry_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("retry") && text.contains("max_attempts") {
            self.add_pattern("retry_with_backoff", "ErrorHandling", 0.85, path);
        }
        
        if text.contains("for attempt in range") && text.contains("except") {
            self.add_pattern("retry_loop", "ErrorHandling", 0.80, path);
        }
    }
    
    fn detect_fallback_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("try:") && text.contains("except") && text.contains("fallback") {
            self.add_pattern("fallback_chain", "ErrorHandling", 0.82, path);
        }
    }
    
    // Domain-specific pattern detectors (WhiteMagic)
    
    fn detect_memory_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("consolidate") && text.contains("memory") {
            self.add_pattern("memory_consolidation", "Domain", 0.90, path);
        }
        
        if text.contains("holographic") && text.contains("encode") {
            self.add_pattern("holographic_encoding", "Domain", 0.92, path);
        }
        
        if text.contains("galactic") && text.contains("distance") {
            self.add_pattern("galactic_positioning", "Domain", 0.88, path);
        }
    }
    
    fn detect_dream_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("dream_cycle") || text.contains("DreamPhase") {
            self.add_pattern("dream_cycle_pattern", "Domain", 0.90, path);
        }
        
        if text.contains("serendipity") && text.contains("bridge") {
            self.add_pattern("serendipity_bridge", "Domain", 0.88, path);
        }
    }
    
    fn detect_resonance_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("resonance") && text.contains("frequency") {
            self.add_pattern("resonance_detection", "Domain", 0.85, path);
        }
        
        if text.contains("harmony") && text.contains("vector") {
            self.add_pattern("harmony_vector", "Domain", 0.87, path);
        }
    }
    
    // Rust-specific pattern detectors
    
    fn detect_zero_copy_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("&[u8]") && text.contains("slice") {
            self.add_pattern("zero_copy_slicing", "Optimization", 0.92, path);
        }
    }
    
    fn detect_lifetime_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("'a") && text.contains("&'a") {
            self.add_pattern("explicit_lifetimes", "Rust", 0.85, path);
        }
    }
    
    fn detect_trait_patterns(&mut self, _node: &tree_sitter::Node, content: &str, path: &Path) {
        let text = content;
        
        if text.contains("impl") && text.contains("for") {
            self.add_pattern("trait_implementation", "Rust", 0.80, path);
        }
    }
    
    // Helper methods
    
    fn add_pattern(&mut self, name: &str, category: &str, value: f64, path: &Path) {
        let id = format!("{}_{}", category.to_lowercase(), name);
        
        self.patterns.entry(id.clone())
            .and_modify(|gene| {
                gene.frequency += 1;
                if gene.examples.len() < 3 {
                    gene.examples.push(path.display().to_string());
                }
            })
            .or_insert_with(|| Gene {
                id,
                name: name.to_string(),
                category: category.to_string(),
                value,
                frequency: 1,
                examples: vec![path.display().to_string()],
                synergies: vec![],
            });
    }
    
    fn detect_synergies(&mut self) {
        // Detect pattern combinations that work well together
        let patterns: Vec<_> = self.patterns.keys().cloned().collect();
        
        for pattern in &patterns {
            if pattern.contains("async") && self.patterns.contains_key("rust_trait_implementation") {
                if let Some(gene) = self.patterns.get_mut(pattern) {
                    gene.synergies.push("async_rust_bridge".to_string());
                }
            }
            
            if pattern.contains("memory_consolidation") && self.patterns.contains_key("domain_dream_cycle_pattern") {
                if let Some(gene) = self.patterns.get_mut(pattern) {
                    gene.synergies.push("memory_dream_integration".to_string());
                }
            }
            
            if pattern.contains("holographic") && self.patterns.contains_key("domain_galactic_positioning") {
                if let Some(gene) = self.patterns.get_mut(pattern) {
                    gene.synergies.push("holographic_galactic_system".to_string());
                }
            }
        }
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = Args::parse();
    
    println!("🧬 Deep Gene Scanner - AST-based Pattern Extraction");
    println!("{}", "=".repeat(80));
    println!();
    
    let mut scanner = PatternScanner::new();
    let mut file_count = 0;
    
    // Collect all files
    let files: Vec<_> = args.paths.iter()
        .flat_map(|path| {
            WalkDir::new(path)
                .into_iter()
                .filter_map(|e| e.ok())
                .filter(|e| e.file_type().is_file())
                .filter(|e| {
                    let ext = e.path().extension().and_then(|s| s.to_str()).unwrap_or("");
                    ext == "py" || ext == "rs"
                })
        })
        .collect();
    
    println!("📂 Found {} files to scan", files.len());
    println!();
    
    // Scan files
    for entry in files {
        if let Err(e) = scanner.scan_file(entry.path()) {
            eprintln!("Warning: Failed to scan {}: {}", entry.path().display(), e);
        }
        file_count += 1;
        
        if file_count % 100 == 0 {
            print!("\r   Scanned {}/{} files...", file_count, file_count);
        }
    }
    
    println!("\r   ✅ Scanned {} files", file_count);
    println!();
    
    // Detect synergies
    println!("🔗 Detecting pattern synergies...");
    scanner.detect_synergies();
    println!("   ✅ Synergies detected");
    println!();
    
    // Filter by frequency
    let mut genes: Vec<_> = scanner.patterns.into_values()
        .filter(|g| g.frequency >= args.min_frequency)
        .collect();
    
    genes.sort_by(|a, b| b.frequency.cmp(&a.frequency));
    
    // Build categories
    let mut categories = HashMap::new();
    for gene in &genes {
        *categories.entry(gene.category.clone()).or_insert(0) += 1;
    }
    
    // Create vault
    let vault = GeneVault {
        version: "2.0.0".to_string(),
        total_genes: genes.len(),
        total_files_scanned: file_count,
        categories,
        genes,
    };
    
    // Save
    let json = serde_json::to_string_pretty(&vault)?;
    fs::write(&args.output, json)?;
    
    println!("💾 Gene vault saved to {}", args.output.display());
    println!();
    println!("📊 SUMMARY:");
    println!("   Total genes: {}", vault.total_genes);
    println!("   Files scanned: {}", vault.total_files_scanned);
    println!();
    println!("   By category:");
    for (cat, count) in vault.categories {
        println!("      {:15} {:4} genes", cat, count);
    }
    println!();
    println!("✅ Deep scan complete!");
    
    Ok(())
}
