![Java CI with Gradle](https://github.com/williamfiset/Algorithms/workflows/Java%20CI%20with%20Gradle/badge.svg)
![README Checker](https://github.com/williamfiset/Algorithms/workflows/README%20URL%20Checker/badge.svg)

# Data structure & algorithms
Algorithms and data structures are fundamental to efficient code and good software design. Creating and designing excellent algorithms is required for being an exemplary programmer. This repository's goal is to demonstrate how to correctly implement common data structures and algorithms in the simplest and most elegant ways.


# Data Structures

- [:movie_camera:](https://www.youtube.com/watch?v=q4fnJZr8ztY) [Balanced Trees](src/main/java/com/williamfiset/algorithms/datastructures/balancedtree)
  - [AVL Tree (recursive)](src/main/java/com/williamfiset/algorithms/datastructures/balancedtree/AVLTreeRecursive.java)
  - [Red Black Tree (recursive)](src/main/java/com/williamfiset/algorithms/datastructures/balancedtree/RedBlackTree.java)
- [:movie_camera:](https://www.youtube.com/watch?v=JfSdGQdAzq8) [Binary Search Tree](src/main/java/com/williamfiset/algorithms/datastructures/binarysearchtree/BinarySearchTree.java)
- [Splay Tree](src/main/java/com/williamfiset/algorithms/datastructures/binarysearchtree/SplayTree.java)
- [:movie_camera:](https://www.youtube.com/watch?v=PEnFFiQe1pM) [Dynamic Array](src/main/java/com/williamfiset/algorithms/datastructures/dynamicarray)
  - [Dynamic array (integer only, fast)](src/main/java/com/williamfiset/algorithms/datastructures/dynamicarray/IntArray.java)
- [:movie_camera:](https://www.youtube.com/watch?v=RgITNht_f4Q) [Fenwick Tree](src/main/java/com/williamfiset/algorithms/datastructures/fenwicktree)
  - [Fenwick Tree (range query, point updates)](src/main/java/com/williamfiset/algorithms/datastructures/fenwicktree/FenwickTreeRangeQueryPointUpdate.java)
  - [Fenwick Tree (range update, point query)](src/main/java/com/williamfiset/algorithms/datastructures/fenwicktree/FenwickTreeRangeUpdatePointQuery.java)
- [Fibonacci Heap](src/main/java/com/williamfiset/algorithms/datastructures/fibonacciheap)
- [:movie_camera:](https://www.youtube.com/watch?v=2E54GqF0H4s) [Hashtable](src/main/java/com/williamfiset/algorithms/datastructures/hashtable)
  - [Hashtable (double hashing)](src/main/java/com/williamfiset/algorithms/datastructures/hashtable/HashTableDoubleHashing.java)
  - [Hashtable (linear probing)](src/main/java/com/williamfiset/algorithms/datastructures/hashtable/HashTableLinearProbing.java)
  - [Hashtable (quadratic probing)](src/main/java/com/williamfiset/algorithms/datastructures/hashtable/HashTableQuadraticProbing.java)
  - [Hashtable (separate chaining)](src/main/java/com/williamfiset/algorithms/datastructures/hashtable/HashTableSeparateChaining.java)
- [:movie_camera:](https://www.youtube.com/watch?v=-Yn5DU0_-lw) [Linked List](src/main/java/com/williamfiset/algorithms/datastructures/linkedlist/DoublyLinkedList.java)
- [:movie_camera:](https://www.youtube.com/watch?v=wptevk0bshY) [Priority Queue](src/main/java/com/williamfiset/algorithms/datastructures/priorityqueue)
  - [Min Binary Heap](src/main/java/com/williamfiset/algorithms/datastructures/priorityqueue/BinaryHeap.java)
  - [Min Indexed Binary Heap (sorted key-value pairs, similar to hash-table)](src/main/java/com/williamfiset/algorithms/datastructures/priorityqueue/MinIndexedBinaryHeap.java)
  - [Min D-Heap](src/main/java/com/williamfiset/algorithms/datastructures/priorityqueue/MinDHeap.java)
  - [:movie_camera:](https://www.youtube.com/watch?v=DT8xZ0Uf8wo) [Min Indexed D-Heap (sorted key-value pairs, similar to hash-table)](src/main/java/com/williamfiset/algorithms/datastructures/priorityqueue/MinIndexedDHeap.java)
- [:movie_camera:](https://www.youtube.com/watch?v=KxzhEQ-zpDc) [Queue](src/main/java/com/williamfiset/algorithms/datastructures/queue)
  - [Queue (integer only, fixed size, fast)](src/main/java/com/williamfiset/algorithms/datastructures/queue/IntQueue.java)
  - [Queue (linked list, generic)](src/main/java/com/williamfiset/algorithms/datastructures/queue/Queue.java)
- [Segment Tree](src/main/java/com/williamfiset/algorithms/datastructures/segmenttree)
  - [Segment tree (array based, compact)](src/main/java/com/williamfiset/algorithms/datastructures/segmenttree/CompactSegmentTree.java)
  - [Segment tree (pointer implementation)](src/main/java/com/williamfiset/algorithms/datastructures/segmenttree/Node.java)
- [:movie_camera:](https://youtu.be/uUatD9AudXo) [Sparse Table](src/main/java/com/williamfiset/algorithms/datastructures/sparsetable/SparseTable.java)
- [:movie_camera:](https://www.youtube.com/watch?v=L3ud3rXpIxA) [Stack](src/main/java/com/williamfiset/algorithms/datastructures/stack)
  - [Stack (integer only, fixed size, fast)](src/main/java/com/williamfiset/algorithms/datastructures/stack/IntStack.java)
  - [Stack (linked list, generic)](src/main/java/com/williamfiset/algorithms/datastructures/stack/ListStack.java)
  - [Stack (array, generic)](src/main/java/com/williamfiset/algorithms/datastructures/stack/ArrayStack.java)
- [:movie_camera:](https://www.youtube.com/watch?v=zqKlL3ZpTqs) [Suffix Array](src/main/java/com/williamfiset/algorithms/datastructures/suffixarray)
  - [Suffix Array (O(n²logn) construction)](src/main/java/com/williamfiset/algorithms/datastructures/suffixarray/SuffixArraySlow.java)
  - [Suffix Array (O(nlog²(n)) construction)](src/main/java/com/williamfiset/algorithms/datastructures/suffixarray/SuffixArrayMed.java)
  - [Suffix Array (O(nlog(n)) construction)](src/main/java/com/williamfiset/algorithms/datastructures/suffixarray/SuffixArrayFast.java)
- [Trie](src/main/java/com/williamfiset/algorithms/datastructures/trie/Trie.java)
- [:movie_camera:](https://www.youtube.com/watch?v=ibjEGG7ylHk) [Union Find](src/main/java/com/williamfiset/algorithms/datastructures/unionfind/UnionFind.java)


# Search algorithms

- [Binary search (real numbers)](src/main/java/com/williamfiset/algorithms/search/BinarySearch.java) **- O(log(n))**
- [Interpolation search (discrete discrete)](src/main/java/com/williamfiset/algorithms/search/InterpolationSearch.java) **- O(n) or O(log(log(n))) with uniform input**
- [Ternary search (real numbers)](src/main/java/com/williamfiset/algorithms/search/TernarySearch.java) **- O(log(n))**
- [Ternary search (discrete numbers)](src/main/java/com/williamfiset/algorithms/search/TernarySearchDiscrete.java) **- O(log(n))**

# Sorting algorithms

- [Bubble sort](src/main/java/com/williamfiset/algorithms/sorting/BubbleSort.java) **- O(n<sup>2</sup>)**
- [Bucket sort](src/main/java/com/williamfiset/algorithms/sorting/BucketSort.java) **- Θ(n + k)**
- [Counting sort](src/main/java/com/williamfiset/algorithms/sorting/CountingSort.java) **- O(n + k)**
- [Heapsort](src/main/java/com/williamfiset/algorithms/sorting/Heapsort.java) **- O(nlog(n))**
- [Insertion sort](src/main/java/com/williamfiset/algorithms/sorting/InsertionSort.java) **- O(n<sup>2</sup>)**
- [Mergesort](src/main/java/com/williamfiset/algorithms/sorting/MergeSort.java) **- O(nlog(n))**
- [Quicksort (in-place, Hoare partitioning)](src/main/java/com/williamfiset/algorithms/sorting/QuickSort.java) **- Θ(nlog(n))**
- [Quicksort3 (Dutch National Flag algorithm)](src/main/java/com/williamfiset/algorithms/sorting/QuickSort3.java) **- Θ(nlog(n))**
- [Selection sort](src/main/java/com/williamfiset/algorithms/sorting/SelectionSort.java) **- O(n<sup>2</sup>)**
- [Radix sort](src/main/java/com/williamfiset/algorithms/sorting/RadixSort.java) **- O(n\*w)**

# String algorithms

- [Booth's algorithm (finds lexicographically smallest string rotation)](src/main/java/com/williamfiset/algorithms/strings/BoothsAlgorithm.java) **- O(n)**
- [Knuth-Morris-Pratt algorithm (finds pattern matches in text)](src/main/java/com/williamfiset/algorithms/strings/KMP.java) **- O(n+m)**
- [Longest Common Prefix (LCP) array](src/main/java/com/williamfiset/algorithms/strings/LongestCommonPrefixArray.java) **- O(nlog(n)) bounded by SA construction, otherwise O(n)**
- [:movie_camera:](https://www.youtube.com/watch?v=Ic80xQFWevc) [Longest Common Substring (LCS)](src/main/java/com/williamfiset/algorithms/strings/LongestCommonSubstring.java) **- O(nlog(n)) bounded by SA construction, otherwise O(n)**
- [:movie_camera:](https://www.youtube.com/watch?v=OptoHwC3D-Y) [Longest Repeated Substring (LRS)](src/main/java/com/williamfiset/algorithms/strings/LongestRepeatedSubstring.java) **- O(nlog(n))**
- [Manacher's algorithm (finds all palindromes in text)](src/main/java/com/williamfiset/algorithms/strings/ManachersAlgorithm.java) **- O(n)**
- [Rabin-Karp algorithm (finds pattern match positions in text)](src/main/java/com/williamfiset/algorithms/strings/RabinKarp.java) **- O(n+m)**
- [Substring verification with suffix array](src/main/java/com/williamfiset/algorithms/strings/SubstringVerificationSuffixArray.java) **- O(nlog(n)) SA construction and O(mlog(n)) per query**

# Graph theory

### Tree algorithms

- [:movie_camera:](https://www.youtube.com/watch?v=2FFq2_je7Lg) [Rooting an undirected tree](src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/RootingTree.java) **- O(V+E)**
- [:movie_camera:](https://www.youtube.com/watch?v=OCKvEMF0Xac) [Identifying isomorphic trees](src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/TreeIsomorphism.java) **- O(?)**
- [:movie_camera:](https://www.youtube.com/watch?v=nzF_9bjDzdc) [Tree center(s)](src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/TreeCenter.java) **- O(V+E)**
- [Tree diameter](src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/TreeDiameter.java) **- O(V+E)**
- [:movie_camera:](https://www.youtube.com/watch?v=sD1IoalFomA) [Lowest Common Ancestor (LCA, Euler tour)](src/main/java/com/williamfiset/algorithms/graphtheory/treealgorithms/LowestCommonAncestorEulerTour.java) **- O(1) queries, O(nlogn) preprocessing**


