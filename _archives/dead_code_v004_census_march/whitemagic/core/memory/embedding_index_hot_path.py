"""Embedding Index Hot Path - Koka + Mojo + GPU Accelerated
Target: 50-100x speedup for semantic similarity via Koka ring buffer
"""
import subprocess
from typing import List

import numpy as np

# Koka bridge integration
try:
    from whitemagic.core.acceleration.koka_bridge import KokaRuntime
    _KOKA_AVAILABLE = True
except ImportError:
    _KOKA_AVAILABLE = False

# GPU availability check
_GPU_AVAILABLE = False

def _init_gpu():
    global _GPU_AVAILABLE
    if _GPU_AVAILABLE:
        return True
    try:
        import torch
        _GPU_AVAILABLE = torch.cuda.is_available()
        return _GPU_AVAILABLE
    except ImportError:
        return False

# Mojo availability check
_MOJO_AVAILABLE = False

def _init_mojo():
    global _MOJO_AVAILABLE
    if _MOJO_AVAILABLE:
        return True
    try:
        result = subprocess.run(["mojo", "--version"], capture_output=True, timeout=5)
        _MOJO_AVAILABLE = result.returncode == 0
        return _MOJO_AVAILABLE
    except:
        return False

# Hot path: Fast cosine similarity with Koka → Rust → GPU
def fast_cosine_similarity_gpu(emb1: np.ndarray, emb2: np.ndarray) -> float:
    """
    Koka-accelerated cosine similarity with GPU fallback.
    Hot path: Koka → Rust for all vectors, GPU for 1000+ dims
    """
    # Try Koka first (routes to Rust SIMD)
    if _KOKA_AVAILABLE:
        try:
            koka = KokaRuntime()
            return koka.cosine_similarity(emb1.tolist(), emb2.tolist())
        except Exception:
            pass  # Fall through
    
    # GPU fallback for large vectors
    if _init_gpu() and len(emb1) >= 1000:
        import torch
        t1 = torch.from_numpy(emb1).cuda()
        t2 = torch.from_numpy(emb2).cuda()
        dot = torch.dot(t1, t2)
        norm1 = torch.norm(t1)
        norm2 = torch.norm(t2)
        return float(dot / (norm1 * norm2)) if norm1 > 0 and norm2 > 0 else 0.0
    
    # CPU fallback
    dot = np.dot(emb1, emb2)
    norm1 = np.linalg.norm(emb1)
    norm2 = np.linalg.norm(emb2)
    return float(dot / (norm1 * norm2)) if norm1 > 0 and norm2 > 0 else 0.0

# Hot path: Batch similarity computation with GPU
def batch_similarity_gpu(
    query_emb: np.ndarray,
    corpus_embs: List[np.ndarray]
) -> List[float]:
    """
    Batch similarity computation - GPU parallelized.
    Hot path: 10+ vectors → GPU batch processing.
    """
    if not _init_gpu() or len(corpus_embs) < 10:
        # CPU fallback
        return [fast_cosine_similarity_gpu(query_emb, e) for e in corpus_embs]
    
    # GPU batch hot path
    import torch
    
    # Stack corpus embeddings
    corpus_matrix = np.stack(corpus_embs)
    
    query_t = torch.from_numpy(query_emb).cuda()
    corpus_t = torch.from_numpy(corpus_matrix).cuda()
    
    # Batch dot products: (1, D) @ (D, N) = (1, N)
    dots = torch.matmul(query_t.unsqueeze(0), corpus_t.T).squeeze(0)
    
    # Batch norms
    query_norm = torch.norm(query_t)
    corpus_norms = torch.norm(corpus_t, dim=1)
    
    # Cosine similarities
    similarities = dots / (query_norm * corpus_norms)
    
    results = similarities.cpu().numpy().tolist()
    
    # Cleanup
    del query_t, corpus_t, dots, query_norm, corpus_norms, similarities
    torch.cuda.empty_cache()
    
    return results

# Hot path: Top-K nearest neighbors with GPU
def gpu_topk_nearest(
    query_emb: np.ndarray,
    corpus_embs: List[np.ndarray],
    corpus_ids: List[str],
    k: int = 5
) -> List[tuple[str, float]]:
    """
    Find K nearest neighbors using GPU-accelerated similarity.
    Hot path: GPU FAISS-style search for 1000+ vectors.
    """
    if not _init_gpu() or len(corpus_embs) < 100:
        # CPU fallback with NumPy
        similarities = batch_similarity_gpu(query_emb, corpus_embs)
        indexed = list(zip(corpus_ids, similarities))
        indexed.sort(key=lambda x: x[1], reverse=True)
        return indexed[:k]
    
    # GPU hot path with PyTorch topk
    import torch
    
    corpus_matrix = np.stack(corpus_embs)
    
    query_t = torch.from_numpy(query_emb).cuda()
    corpus_t = torch.from_numpy(corpus_matrix).cuda()
    
    # Compute all similarities
    dots = torch.matmul(query_t.unsqueeze(0), corpus_t.T).squeeze(0)
    query_norm = torch.norm(query_t)
    corpus_norms = torch.norm(corpus_t, dim=1)
    similarities = dots / (query_norm * corpus_norms)
    
    # Top-K selection on GPU
    topk_vals, topk_indices = torch.topk(similarities, min(k, len(corpus_ids)))
    
    results = [
        (corpus_ids[idx], float(val))
        for idx, val in zip(topk_indices.cpu().numpy(), topk_vals.cpu().numpy())
    ]
    
    # Cleanup
    del query_t, corpus_t, dots, query_norm, corpus_norms, similarities, topk_vals, topk_indices
    torch.cuda.empty_cache()
    
    return results

# GPU utilization monitoring
class GPUUtilizationTracker:
    """Track GPU utilization for Phase 3 VC."""
    
    def __init__(self):
        self.peak_utilization = 0.0
        self.samples = []
    
    def sample(self) -> float:
        """Sample current GPU utilization."""
        if not _init_gpu():
            return 0.0
        
        try:
            import torch
            # Memory utilization as proxy
            allocated = torch.cuda.memory_allocated()
            torch.cuda.memory_reserved()
            total = torch.cuda.get_device_properties(0).total_memory
            
            util = (allocated / total) * 100
            self.samples.append(util)
            self.peak_utilization = max(self.peak_utilization, util)
            return util
        except:
            return 0.0
    
    def get_average(self) -> float:
        """Get average utilization."""
        if not self.samples:
            return 0.0
        return sum(self.samples) / len(self.samples)
    
    def meets_target(self, target: float = 80.0) -> bool:
        """Check if GPU utilization meets target."""
        return self.get_average() >= target

# Global tracker for Phase 3 VC
gpu_tracker = GPUUtilizationTracker()

# Hot path: Monkey-patch for seamless integration
def install_hot_paths():
    """Install GPU-accelerated hot paths into embedding_index module."""
    try:
        from whitemagic.core.memory import embedding_index
        
        # Add accelerated functions
        embedding_index.fast_cosine_similarity_gpu = fast_cosine_similarity_gpu
        embedding_index.batch_similarity_gpu = batch_similarity_gpu
        embedding_index.gpu_topk_nearest = gpu_topk_nearest
        embedding_index.gpu_tracker = gpu_tracker
        
        # Patch SimpleEmbedding
        
        def accelerated_similarity(self, emb1, emb2):
            # Convert dict embeddings to numpy if needed
            if isinstance(emb1, dict):
                # Sparse to dense conversion
                keys = sorted(set(emb1.keys()) | set(emb2.keys()))
                v1 = np.array([emb1.get(k, 0.0) for k in keys], dtype=np.float32)
                v2 = np.array([emb2.get(k, 0.0) for k in keys], dtype=np.float32)
                return fast_cosine_similarity_gpu(v1, v2)
            else:
                return fast_cosine_similarity_gpu(
                    np.array(emb1, dtype=np.float32),
                    np.array(emb2, dtype=np.float32)
                )
        
        embedding_index.SimpleEmbedding.similarity = accelerated_similarity
        
        # Track utilization
        if _init_gpu():
            gpu_tracker.sample()
            print("[embedding_index_hot_path] GPU acceleration installed")
            print(f"[embedding_index_hot_path] Current GPU util: {gpu_tracker.sample():.1f}%")
        else:
            print("[embedding_index_hot_path] CPU mode (no GPU available)")
        
        return True
        
    except Exception as e:
        print(f"[embedding_index_hot_path] Note: {e}")
        return False

# Auto-install
install_hot_paths()
