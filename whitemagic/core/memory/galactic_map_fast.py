"""Fast Galactic Map using Zig implementation (100-1000× speedup).

Python wrapper for the Zig galactic coordinate system.
Falls back to pure Python if Zig library unavailable.
"""

import ctypes
import logging
import os
from pathlib import Path

logger = logging.getLogger(__name__)

# Try to load Zig library
_zig_lib = None
_zig_available = False

def _load_zig_lib():
    global _zig_lib, _zig_available
    
    # Look for compiled Zig library
    lib_paths = [
        Path("whitemagic-zig/zig-out/lib/libwhitemagic_galactic.so"),
        Path("whitemagic-zig/zig-out/lib/libwhitemagic_galactic.dylib"),
        Path("whitemagic-zig/zig-out/lib/whitemagic_galactic.dll"),
        Path("whitemagic-zig/zig-out/lib/libwhitemagic.so"),
        Path("whitemagic-zig/zig-out/lib/libwhitemagic.dylib"),
        Path("whitemagic-zig/zig-out/lib/whitemagic.dll"),
    ]
    
    for lib_path in lib_paths:
        if lib_path.exists():
            try:
                _zig_lib = ctypes.CDLL(str(lib_path))
                
                # Define function signatures
                _zig_lib.galactic_compute_distance.argtypes = [
                    ctypes.c_float,  # access
                    ctypes.c_float,  # neuro
                    ctypes.c_float,  # temporal
                    ctypes.c_float,  # salience
                    ctypes.c_float,  # connection
                ]
                _zig_lib.galactic_compute_distance.restype = ctypes.c_float
                
                _zig_lib.galactic_classify_zone.argtypes = [ctypes.c_float]
                _zig_lib.galactic_classify_zone.restype = ctypes.c_uint8
                
                _zig_lib.galactic_compute_batch.argtypes = [
                    ctypes.POINTER(ctypes.c_float),  # access_scores
                    ctypes.POINTER(ctypes.c_float),  # neuro_scores
                    ctypes.POINTER(ctypes.c_float),  # temporal_scores
                    ctypes.POINTER(ctypes.c_float),  # salience_scores
                    ctypes.POINTER(ctypes.c_float),  # connection_scores
                    ctypes.c_size_t,                 # count
                    ctypes.POINTER(ctypes.c_float),  # out_distances
                ]
                _zig_lib.galactic_compute_batch.restype = None
                
                _zig_available = True
                logger.info(f"Loaded Zig galactic_map from {lib_path}")
                return
            except Exception as e:
                logger.warning(f"Failed to load Zig library from {lib_path}: {e}")
                continue
    
    logger.warning("Zig galactic_map not available, using Python fallback")

_load_zig_lib()


def compute_distance_fast(
    access_score: float,
    neuro_score: float,
    temporal_score: float,
    salience_score: float,
    connection_score: float,
) -> float:
    """Compute galactic distance using Zig (100-1000× faster).
    
    Falls back to Python if Zig unavailable.
    """
    if _zig_available and _zig_lib:
        return _zig_lib.galactic_compute_distance(
            access_score,
            neuro_score,
            temporal_score,
            salience_score,
            connection_score,
        )
    else:
        # Python fallback
        weights = [0.3, 0.25, 0.2, 0.15, 0.1]
        scores = [access_score, neuro_score, temporal_score, salience_score, connection_score]
        weighted_sum = sum(s * w for s, w in zip(scores, weights))
        distance = 1.0 - weighted_sum
        return max(0.0, min(1.0, distance))


def classify_zone_fast(distance: float) -> int:
    """Classify galactic zone from distance (Zig).
    
    Returns: 0=CORE, 1=INNER_RIM, 2=MID_BAND, 3=OUTER_RIM, 4=FAR_EDGE
    """
    if _zig_available and _zig_lib:
        return int(_zig_lib.galactic_classify_zone(distance))
    else:
        # Python fallback
        if distance < 0.15:
            return 0  # CORE
        elif distance < 0.40:
            return 1  # INNER_RIM
        elif distance < 0.65:
            return 2  # MID_BAND
        elif distance < 0.85:
            return 3  # OUTER_RIM
        else:
            return 4  # FAR_EDGE


def compute_distances_batch(
    access_scores: list[float],
    neuro_scores: list[float],
    temporal_scores: list[float],
    salience_scores: list[float],
    connection_scores: list[float],
) -> list[float]:
    """Batch compute galactic distances (Zig, 100-1000× faster).
    
    All input lists must be same length.
    """
    count = len(access_scores)
    if not (len(neuro_scores) == len(temporal_scores) == len(salience_scores) == len(connection_scores) == count):
        raise ValueError("All input lists must have same length")
    
    if _zig_available and _zig_lib and count > 0:
        # Convert to ctypes arrays
        access_arr = (ctypes.c_float * count)(*access_scores)
        neuro_arr = (ctypes.c_float * count)(*neuro_scores)
        temporal_arr = (ctypes.c_float * count)(*temporal_scores)
        salience_arr = (ctypes.c_float * count)(*salience_scores)
        connection_arr = (ctypes.c_float * count)(*connection_scores)
        out_arr = (ctypes.c_float * count)()
        
        # Call Zig
        _zig_lib.galactic_compute_batch(
            access_arr,
            neuro_arr,
            temporal_arr,
            salience_arr,
            connection_arr,
            count,
            out_arr,
        )
        
        return list(out_arr)
    else:
        # Python fallback
        return [
            compute_distance_fast(a, n, t, s, c)
            for a, n, t, s, c in zip(access_scores, neuro_scores, temporal_scores, salience_scores, connection_scores)
        ]


def is_zig_available() -> bool:
    """Check if Zig galactic_map is available."""
    return _zig_available
