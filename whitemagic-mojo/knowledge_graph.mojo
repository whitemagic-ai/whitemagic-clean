"""Knowledge Graph - GPU Knowledge Graph (PSR-004)
Target: 100× speedup
"""
from tensor import Tensor

struct Triple:
    var subject: String
    var predicate: String
    var object: String
    
    fn __init__(inout self, s: String, p: String, o: String):
        self.subject = s
        self.predicate = p
        self.object = o

struct KnowledgeGraph:
    var triples: DynamicVector[Triple]
    
    fn __init__(inout self):
        self.triples = DynamicVector[Triple]()
    
    fn add_triple(inout self, triple: Triple):
        self.triples.push_back(triple)
    
    fn query_subject(self, subject: String) -> DynamicVector[Triple]:
        var results = DynamicVector[Triple]()
        for i in range(len(self.triples)):
            if self.triples[i].subject == subject:
                results.push_back(self.triples[i])
        return results
    
    fn triple_count(self) -> Int:
        return len(self.triples)

fn main():
    var kg = KnowledgeGraph()
    kg.add_triple(Triple("sky", "is", "blue"))
    print("Triples:", kg.triple_count())
