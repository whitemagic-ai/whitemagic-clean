#!/usr/bin/env python3
"""Quantum-Inspired Engine (Option A) — Implementation of Grover-inspired search
and simulated annealing for graph optimization.
"""

import math
import random
import logging
from typing import List, Any, Callable, Optional
from dataclasses import dataclass

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

@dataclass
class QuantumState:
    """Representation of a 'superposition' state for a set of items."""
    items: List[str]
    amplitudes: List[float]  # Probabilities/Weights
    
    def normalize(self):
        total = sum(self.amplitudes)
        if total > 0:
            self.amplitudes = [a / total for a in self.amplitudes]

class QuantumInspiredEngine:
    """Engine implementing quantum-inspired algorithms for classical optimization."""
    
    def __init__(self):
        self.stats = {"grover_runs": 0, "annealing_runs": 0}

    def grover_search(self, items: List[Any], oracle: Callable[[Any], bool], iterations: Optional[int] = None) -> List[Any]:
        """Grover-inspired search: Amplifies 'amplitudes' of items matching the oracle."""
        n = len(items)
        if n == 0: return []
        
        # Initial uniform superposition
        amplitudes = [1.0 / math.sqrt(n)] * n
        
        if iterations is None:
            iterations = int(math.pi / 4 * math.sqrt(n))
        
        for _ in range(iterations):
            # 1. Oracle: Flip phase of matching items
            for i in range(n):
                if oracle(items[i]):
                    amplitudes[i] *= -1
            
            # 2. Diffusion (Inversion about the mean)
            mean = sum(amplitudes) / n
            for i in range(n):
                amplitudes[i] = 2 * mean - amplitudes[i]
        
        # Calculate probabilities from amplitudes
        probs = [a**2 for a in amplitudes]
        indexed_probs = sorted(enumerate(probs), key=lambda x: x[1], reverse=True)
        
        results = []
        for idx, prob in indexed_probs:
            if prob > (1.0 / n): # Threshold for 'found' items
                results.append(items[idx])
        
        self.stats["grover_runs"] += 1
        return results

    def simulated_annealing(self, initial_state: Any, neighbor_func: Callable[[Any], Any], 
                            energy_func: Callable[[Any], float], temp_init: float = 100.0, 
                            cooling_rate: float = 0.95, iterations: int = 1000) -> Any:
        """Simulated Annealing (Adiabatic-inspired) for finding optimal configurations."""
        current_state = initial_state
        current_energy = energy_func(current_state)
        best_state = current_state
        best_energy = current_energy
        
        temp = temp_init
        
        for i in range(iterations):
            neighbor = neighbor_func(current_state)
            neighbor_energy = energy_func(neighbor)
            
            # Acceptance probability (Metropolis-Hastings)
            if neighbor_energy < current_energy:
                accept = True
            else:
                p = math.exp((current_energy - neighbor_energy) / temp)
                accept = random.random() < p
                
            if accept:
                current_state = neighbor
                current_energy = neighbor_energy
                
                if current_energy < best_energy:
                    best_state = current_state
                    best_energy = current_energy
            
            temp *= cooling_rate
            if temp < 0.001: break
            
        self.stats["annealing_runs"] += 1
        return best_state

if __name__ == "__main__":
    # Self-test
    engine = QuantumInspiredEngine()
    
    # Test Grover
    data = [f"item_{i}" for i in range(100)]
    target = "item_42"
    found = engine.grover_search(data, lambda x: x == target)
    print(f"Grover search target: {target}, Found: {found}")
    
    # Test Annealing (simple number minimization)
    best = engine.simulated_annealing(100, lambda x: x + random.uniform(-10, 10), lambda x: x**2)
    print(f"Annealing best state for x^2: {best}")
