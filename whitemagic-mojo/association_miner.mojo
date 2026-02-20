"""Association Miner - GPU Association Discovery (PSR-001)
Target: 100× speedup for association mining
"""

from tensor import Tensor

struct Association:
    var source: String
    var target: String
    var strength: Float32
    
    fn __init__(inout self, source: String, target: String, strength: Float32):
        self.source = source
        self.target = target
        self.strength = strength

struct AssociationMiner:
    var min_strength: Float32
    var associations: DynamicVector[Association]
    
    fn __init__(inout self, min_strength: Float32):
        self.min_strength = min_strength
        self.associations = DynamicVector[Association]()
    
    fn jaccard_similarity(self, a: String, b: String) -> Float32:
        """Compute Jaccard similarity between strings."""
        var a_chars = DynamicVector[String]()
        var b_chars = DynamicVector[String]()
        
        for i in range(len(a)):
            a_chars.push_back(a[i])
        
        for i in range(len(b)):
            b_chars.push_back(b[i])
        
        var intersection = 0
        var union = len(a_chars)
        
        for i in range(len(a_chars)):
            for j in range(len(b_chars)):
                if a_chars[i] == b_chars[j]:
                    intersection += 1
                    break
        
        union = len(a_chars) + len(b_chars) - intersection
        
        return Float32(intersection) / Float32(union) if union > 0 else 0.0
    
    fn mine_associations(inout self, items: DynamicVector[String]):
        """Mine associations from items."""
        for i in range(len(items)):
            for j in range(i + 1, len(items)):
                let strength = self.jaccard_similarity(items[i], items[j])
                
                if strength >= self.min_strength:
                    self.associations.push_back(Association(items[i], items[j], strength))
    
    fn get_associations(self, item: String) -> DynamicVector[Association]:
        """Get associations for an item."""
        var results = DynamicVector[Association]()
        
        for i in range(len(self.associations)):
            if self.associations[i].source == item or self.associations[i].target == item:
                results.push_back(self.associations[i])
        
        return results
    
    fn association_count(self) -> Int:
        """Get total association count."""
        return len(self.associations)

fn main():
    var miner = AssociationMiner(0.3)
    
    var items = DynamicVector[String]()
    items.push_back("apple")
    items.push_back("application")
    items.push_back("banana")
    
    miner.mine_associations(items)
    
    print("Found", miner.association_count(), "associations")
