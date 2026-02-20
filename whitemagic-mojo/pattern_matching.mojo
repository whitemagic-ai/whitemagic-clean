"""Pattern Matching - GPU Pattern Matching (PSR-004)
Target: 100× speedup for pattern matching
"""

from tensor import Tensor

struct Pattern:
    var pattern: String
    var frequency: Int
    
    fn __init__(inout self, pattern: String, frequency: Int):
        self.pattern = pattern
        self.frequency = frequency

struct PatternMatcher:
    var patterns: DynamicVector[Pattern]
    var min_frequency: Int
    
    fn __init__(inout self, min_frequency: Int):
        self.patterns = DynamicVector[Pattern]()
        self.min_frequency = min_frequency
    
    fn extract_patterns(inout self, texts: DynamicVector[String]):
        """Extract patterns from texts."""
        var pattern_counts = DynamicVector[Int]()
        var unique_patterns = DynamicVector[String]()
        
        for text_idx in range(len(texts)):
            let text = texts[text_idx]
            
            for i in range(len(text) - 2):
                var pattern = String("")
                pattern = text[i:i+3]
                
                var found = False
                var found_idx = 0
                
                for j in range(len(unique_patterns)):
                    if unique_patterns[j] == pattern:
                        found = True
                        found_idx = j
                        break
                
                if found:
                    pattern_counts[found_idx] += 1
                else:
                    unique_patterns.push_back(pattern)
                    pattern_counts.push_back(1)
        
        for i in range(len(unique_patterns)):
            if pattern_counts[i] >= self.min_frequency:
                self.patterns.push_back(Pattern(unique_patterns[i], pattern_counts[i]))
    
    fn match_pattern(self, text: String, pattern: String) -> Bool:
        """Check if pattern exists in text."""
        if len(pattern) > len(text):
            return False
        
        for i in range(len(text) - len(pattern) + 1):
            var matches = True
            
            for j in range(len(pattern)):
                if text[i + j] != pattern[j]:
                    matches = False
                    break
            
            if matches:
                return True
        
        return False
    
    fn get_top_patterns(self, n: Int) -> DynamicVector[Pattern]:
        """Get top N patterns by frequency."""
        var sorted_patterns = self.patterns
        
        for i in range(len(sorted_patterns)):
            for j in range(i + 1, len(sorted_patterns)):
                if sorted_patterns[j].frequency > sorted_patterns[i].frequency:
                    let temp = sorted_patterns[i]
                    sorted_patterns[i] = sorted_patterns[j]
                    sorted_patterns[j] = temp
        
        var results = DynamicVector[Pattern]()
        
        for i in range(min(n, len(sorted_patterns))):
            results.push_back(sorted_patterns[i])
        
        return results
    
    fn pattern_count(self) -> Int:
        """Get pattern count."""
        return len(self.patterns)

fn main():
    var matcher = PatternMatcher(2)
    
    var texts = DynamicVector[String]()
    texts.push_back("hello world")
    texts.push_back("hello there")
    texts.push_back("world peace")
    
    matcher.extract_patterns(texts)
    
    print("Patterns found:", matcher.pattern_count())
    
    let top = matcher.get_top_patterns(5)
    print("Top patterns:", len(top))
