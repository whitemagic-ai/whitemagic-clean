//! Synthesis Engine - Multi-Source Synthesis (PSR-004)
//! Target: 30× speedup for synthesis operations

use pyo3::prelude::*;
use std::collections::HashMap;
use rayon::prelude::*;

#[derive(Clone, Debug)]
#[pyclass]
pub struct Source {
    #[pyo3(get)]
    pub id: String,
    #[pyo3(get)]
    pub content: String,
    #[pyo3(get)]
    pub weight: f64,
    #[pyo3(get)]
    pub metadata: HashMap<String, String>,
}

#[pymethods]
impl Source {
    #[new]
    fn new(id: String, content: String, weight: f64) -> Self {
        Self {
            id,
            content,
            weight,
            metadata: HashMap::new(),
        }
    }

    fn add_metadata(&mut self, key: String, value: String) {
        self.metadata.insert(key, value);
    }
}

#[derive(Clone, Debug)]
#[pyclass]
pub struct SynthesisResult {
    #[pyo3(get)]
    pub synthesized_content: String,
    #[pyo3(get)]
    pub source_ids: Vec<String>,
    #[pyo3(get)]
    pub confidence: f64,
    #[pyo3(get)]
    pub common_themes: Vec<String>,
}

#[pymethods]
impl SynthesisResult {
    #[new]
    fn new(synthesized_content: String, source_ids: Vec<String>, confidence: f64, common_themes: Vec<String>) -> Self {
        Self {
            synthesized_content,
            source_ids,
            confidence,
            common_themes,
        }
    }
}

#[pyclass]
pub struct PySynthesisEngine {
    sources: HashMap<String, Source>,
    min_sources: usize,
    min_confidence: f64,
}

#[pymethods]
impl PySynthesisEngine {
    #[new]
    fn new(min_sources: Option<usize>, min_confidence: Option<f64>) -> Self {
        Self {
            sources: HashMap::new(),
            min_sources: min_sources.unwrap_or(2),
            min_confidence: min_confidence.unwrap_or(0.5),
        }
    }

    fn add_source(&mut self, source: Source) {
        self.sources.insert(source.id.clone(), source);
    }

    fn synthesize(&self, source_ids: Vec<String>) -> Option<SynthesisResult> {
        if source_ids.len() < self.min_sources {
            return None;
        }
        
        let sources: Vec<&Source> = source_ids
            .iter()
            .filter_map(|id| self.sources.get(id))
            .collect();
        
        if sources.len() < self.min_sources {
            return None;
        }
        
        let common_themes = self.extract_common_themes(&sources);
        let confidence = self.calculate_confidence(&sources);
        
        if confidence < self.min_confidence {
            return None;
        }
        
        let synthesized = self.merge_content(&sources);
        
        Some(SynthesisResult {
            synthesized_content: synthesized,
            source_ids,
            confidence,
            common_themes,
        })
    }

    fn synthesize_all(&self) -> Vec<SynthesisResult> {
        let source_ids: Vec<String> = self.sources.keys().cloned().collect();
        
        if let Some(result) = self.synthesize(source_ids) {
            vec![result]
        } else {
            Vec::new()
        }
    }

    fn parallel_synthesize(&self, source_groups: Vec<Vec<String>>) -> Vec<SynthesisResult> {
        source_groups
            .par_iter()
            .filter_map(|group| self.synthesize(group.clone()))
            .collect()
    }

    fn find_contradictions(&self, source_ids: Vec<String>) -> Vec<(String, String)> {
        let mut contradictions = Vec::new();
        
        for i in 0..source_ids.len() {
            for j in (i + 1)..source_ids.len() {
                if let (Some(s1), Some(s2)) = (self.sources.get(&source_ids[i]), self.sources.get(&source_ids[j])) {
                    if self.are_contradictory(s1, s2) {
                        contradictions.push((s1.id.clone(), s2.id.clone()));
                    }
                }
            }
        }
        
        contradictions
    }

    fn source_count(&self) -> usize {
        self.sources.len()
    }
}

impl PySynthesisEngine {
    fn extract_common_themes(&self, sources: &[&Source]) -> Vec<String> {
        let mut theme_counts: HashMap<String, usize> = HashMap::new();
        
        for source in sources {
            let words: Vec<String> = source.content
                .split_whitespace()
                .map(|s| s.to_lowercase())
                .collect();
            
            for word in words {
                if word.len() > 3 {
                    *theme_counts.entry(word).or_insert(0) += 1;
                }
            }
        }
        
        let threshold = sources.len() / 2;
        theme_counts
            .into_iter()
            .filter(|(_, count)| *count >= threshold)
            .map(|(theme, _)| theme)
            .collect()
    }

    fn calculate_confidence(&self, sources: &[&Source]) -> f64 {
        if sources.is_empty() {
            return 0.0;
        }
        
        let total_weight: f64 = sources.iter().map(|s| s.weight).sum();
        let avg_weight = total_weight / sources.len() as f64;
        
        let agreement = self.calculate_agreement(sources);
        
        (avg_weight + agreement) / 2.0
    }

    fn calculate_agreement(&self, sources: &[&Source]) -> f64 {
        if sources.len() < 2 {
            return 1.0;
        }
        
        let mut agreement_sum = 0.0;
        let mut comparisons = 0;
        
        for i in 0..sources.len() {
            for j in (i + 1)..sources.len() {
                let similarity = self.content_similarity(&sources[i].content, &sources[j].content);
                agreement_sum += similarity;
                comparisons += 1;
            }
        }
        
        if comparisons == 0 {
            return 0.0;
        }
        
        agreement_sum / comparisons as f64
    }

    fn content_similarity(&self, a: &str, b: &str) -> f64 {
        let words_a: HashSet<String> = a.split_whitespace().map(|s| s.to_lowercase()).collect();
        let words_b: HashSet<String> = b.split_whitespace().map(|s| s.to_lowercase()).collect();
        
        let intersection = words_a.intersection(&words_b).count();
        let union = words_a.union(&words_b).count();
        
        if union == 0 {
            return 0.0;
        }
        
        intersection as f64 / union as f64
    }

    fn merge_content(&self, sources: &[&Source]) -> String {
        sources
            .iter()
            .map(|s| s.content.as_str())
            .collect::<Vec<&str>>()
            .join(" ")
    }

    fn are_contradictory(&self, s1: &Source, s2: &Source) -> bool {
        let similarity = self.content_similarity(&s1.content, &s2.content);
        similarity < 0.2
    }
}

use std::collections::HashSet;

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_engine_creation() {
        let engine = PySynthesisEngine::new(Some(2), Some(0.5));
        assert_eq!(engine.source_count(), 0);
    }

    #[test]
    fn test_add_source() {
        let mut engine = PySynthesisEngine::new(None, None);
        let source = Source::new("s1".to_string(), "content".to_string(), 1.0);
        
        engine.add_source(source);
        assert_eq!(engine.source_count(), 1);
    }

    #[test]
    fn test_synthesize() {
        let mut engine = PySynthesisEngine::new(Some(2), Some(0.0));
        
        engine.add_source(Source::new("s1".to_string(), "hello world".to_string(), 1.0));
        engine.add_source(Source::new("s2".to_string(), "hello there".to_string(), 1.0));
        
        let result = engine.synthesize(vec!["s1".to_string(), "s2".to_string()]);
        assert!(result.is_some());
    }

    #[test]
    fn test_find_contradictions() {
        let mut engine = PySynthesisEngine::new(None, None);
        
        engine.add_source(Source::new("s1".to_string(), "the sky is blue".to_string(), 1.0));
        engine.add_source(Source::new("s2".to_string(), "completely different content".to_string(), 1.0));
        
        let contradictions = engine.find_contradictions(vec!["s1".to_string(), "s2".to_string()]);
        assert!(!contradictions.is_empty());
    }
}
