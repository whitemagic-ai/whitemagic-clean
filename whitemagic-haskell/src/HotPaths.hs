-- Haskell Hot Path Translations
-- Phase C: Pattern matching, lazy clustering, tree algorithms

module HotPaths where

import Data.List (sortBy, foldl', nub, intersect, union, maximumBy)
import Data.Function (on)
import Data.Set (Set)
import qualified Data.Set as Set
import Data.Map (Map)
import qualified Data.Map as Map
import Data.Maybe (fromMaybe)
import Control.Parallel (par, pseq)
import Control.Parallel.Strategies (parMap, rdeepseq, parList, using)

-- | Jaccard similarity with lazy set operations
jaccardSimilarity :: (Ord a) => Set a -> Set a -> Double
jaccardSimilarity a b
    | Set.null a && Set.null b = 1.0
    | Set.null a || Set.null b = 0.0
    | otherwise = fromIntegral (Set.size intersection) / fromIntegral (Set.size un)
    where
        intersection = Set.intersection a b
        un = Set.union a b

-- | Batch Jaccard with parallel evaluation
batchJaccard :: (Ord a) => Set a -> [Set a] -> [Double]
batchJaccard query candidates =
    parMap rdeepseq (jaccardSimilarity query) candidates

-- | Lazy similarity-based clustering
clusterBySimilarity :: (a -> a -> Double) -> Double -> Int -> [a] -> [[Int]]
clusterBySimilarity simFunc threshold minSize items =
    let n = length items
        -- Build similarity graph lazily
        edges = [(i, j) | i <- [0..n-1], j <- [i+1..n-1]
                       , simFunc (items !! i) (items !! j) >= threshold]
        -- Union-Find (Disjoint Set Union)
        parent = Map.fromList [(i, i) | i <- [0..n-1]]
        clusters = foldl' (unionEdge items) parent edges
        -- Group by root
        grouped = Map.fromListWith (++) [(find clusters i, [i]) | i <- [0..n-1]]
    in filter (\c -> length c >= minSize) (Map.elems grouped)

unionEdge :: [a] -> Map Int Int -> (Int, Int) -> Map Int Int
unionEdge items parent (i, j) =
    let rootI = find parent i
        rootJ = find parent j
    in if rootI /= rootJ
        then Map.insert rootI rootJ parent
        else parent

find :: Map Int Int -> Int -> Int
find parent i =
    case Map.lookup i parent of
        Just p | p /= i -> find parent p
        _ -> i

-- | Recursive tree clustering with lazy evaluation
recursiveCluster :: (a -> a -> Double) -> Double -> [a] -> [[a]]
recursiveCluster _ _ [] = []
recursiveCluster simFunc threshold items =
    let (cluster, rest) = growCluster simFunc threshold items []
    in if length cluster >= 3
        then cluster : recursiveCluster simFunc threshold rest
        else recursiveCluster simFunc threshold rest

-- | Grow cluster greedily
growCluster :: (a -> a -> Double) -> Double -> [a] -> [a] -> ([a], [a])
growCluster _ _ [] acc = (acc, [])
growCluster simFunc threshold (x:xs) acc
    | null acc = growCluster simFunc threshold xs [x]
    | any (\y -> simFunc x y >= threshold) acc = 
        let (cluster, rest) = growCluster simFunc threshold xs (x:acc)
        in (cluster, rest)
    | otherwise = (acc, x:xs)

-- | Exhaustive pattern matching for boundary detection
-- (replaces Python's _patterns_complement)
patternsComplement :: (Eq b, Ord b) => Map String b -> Map String b -> Bool
def 
patternsComplement a b =
    let typeA = Map.lookup "type" a
        typeB = Map.lookup "type" b
        impA = Map.lookup "importance" a
        impB = Map.lookup "importance" b
    in case (typeA, typeB, impA, impB) of
        (Just tA, Just tB, Just iA, Just iB) ->
            tA /= tB && abs (iA - iB) < 0.3
        _ -> False

-- | Lazy zone distribution with stream fusion
zoneDistribution :: [Double] -> Map String Int
zoneDistribution distances =
    foldl' (\m d -> Map.insertWith (+) (classifyZone d) 1 m) Map.empty distances
    where
        classifyZone d
            | d < 0.15  = "CORE"
            | d < 0.40  = "INNER_RIM"
            | d < 0.65  = "MID_BAND"
            | d < 0.85  = "OUTER_RIM"
            | otherwise = "FAR_EDGE"

-- | Recursive string similarity (for title matching)
titleSimilarity :: String -> String -> Double
titleSimilarity a b
    | a == b = 1.0
    | a `isInfixOf` b || b `isInfixOf` a = 0.8
    | otherwise = keywordJaccard (extractKeywords a) (extractKeywords b)
    where
        isInfixOf needle haystack = needle `elem` (init . tails $ haystack)
        tails [] = [[]]
        tails x@(_:xs) = x : tails xs

-- | Extract keywords with lazy evaluation
extractKeywords :: String -> Set String
extractKeywords = Set.fromList . filter (\w -> length w > 2) . words . map toLower
    where
        toLower c = if c >= 'A' && c <= 'Z' then toEnum (fromEnum c + 32) else c

-- | Keyword Jaccard
keywordJaccard :: Set String -> Set String -> Double
keywordJaccard = jaccardSimilarity

-- | Functional KD-Tree for nearest neighbors (lazy construction)
data KDTree a = Empty | Node { point :: a, left :: KDTree a, right :: KDTree a, axis :: Int }

buildKDTree :: ([a] -> a -> a -> Ordering) -> Int -> [a] -> KDTree a
buildKDTree _ _ [] = Empty
buildKDTree cmp depth points =
    let axis = depth `mod` length (head points)
        sorted = sortBy (cmp points) points
        mid = length sorted `div` 2
        (leftPoints, point:rightPoints) = splitAt mid sorted
    in Node { point = point
            , left = buildKDTree cmp (depth + 1) leftPoints
            , right = buildKDTree cmp (depth + 1) rightPoints
            , axis = axis
            }

-- | Nearest neighbor search in KD-Tree
nearestNeighbor :: (a -> a -> Double) -> KDTree a -> a -> Maybe (a, Double)
nearestNeighbor _ Empty _ = Nothing
nearestNeighbor distFunc tree query =
    let search t q depth best =
            case t of
                Empty -> best
                Node { point = p, left = l, right = r, axis = ax } ->
                    let axisDist = undefined -- Would need vector access
                        nextBranch = if axisDist < 0 then l else r
                        otherBranch = if axisDist < 0 then r else l
                        d = distFunc p q
                        newBest = case best of
                            Nothing -> Just (p, d)
                            Just (_, bd) -> if d < bd then Just (p, d) else best
                    in search otherBranch q (depth + 1) (search nextBranch q (depth + 1) newBest)
    in search tree query 0 Nothing

-- | Mature functional sorting (mergesort with fusion)
mergesort :: (Ord a) => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs =
    let (left, right) = splitAt (length xs `div` 2) xs
        sortedLeft = mergesort left
        sortedRight = mergesort right
    in merge sortedLeft sortedRight

merge :: (Ord a) => [a] -> [a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys)
    | x <= y    = x : merge xs (y:ys)
    | otherwise = y : merge (x:xs) ys

-- | Lazy sorted streams (infinite list pattern)
sortedStream :: (Ord a) => [a] -> [a]
sortedStream = mergesort

-- | Tree-based complexity estimation
estimateComplexity :: Int -> Int -> String
estimateComplexity loopCount recursionDepth
    | loopCount > 3 || recursionDepth > 5 = "high"
    | loopCount > 0 || recursionDepth > 2 = "medium"
    | otherwise = "low"

-- | Parallel fold for importance aggregation
parallelImportanceFold :: [(String, Double)] -> Map String Double
parallelImportanceFold items =
    let chunks = chunkList 100 items
        partials = parMap rdeepseq (foldl' insertImp Map.empty) chunks
    in foldl' (Map.unionWith (+)) Map.empty partials
    where
        insertImp m (k, v) = Map.insertWith (+) k v m
        chunkList _ [] = []
        chunkList n xs = take n xs : chunkList n (drop n xs)

-- | Reconsolidation prioritization with lazy sorting
prioritizeReconsolidation :: [(String, Double, Double)] -> [(String, Double)]
prioritizeReconsolidation items =
    let scored = [(id, importance * 0.7 + recency * 0.3)
                 | (id, importance, recency) <- items]
    in sortBy (flip compare `on` snd) scored

-- | Formal pattern composition
composePatterns :: [a -> Bool] -> a -> Bool
composePatterns predicates x = all ($ x) predicates

-- | Main exports for FFI
exports :: [(String, a)]
exports =
    [ ("jaccardSimilarity", undefined)
    , ("clusterBySimilarity", undefined)
    , ("patternsComplement", undefined)
    , ("zoneDistribution", undefined)
    , ("titleSimilarity", undefined)
    , ("mergesort", undefined)
    , ("nearestNeighbor", undefined)
    , ("parallelImportanceFold", undefined)
    , ("prioritizeReconsolidation", undefined)
    , ("composePatterns", undefined)
    ]
