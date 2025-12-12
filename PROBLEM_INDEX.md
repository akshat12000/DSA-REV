# Problem Index by Topic

> Complete index of all implemented problems organized by data structure and algorithm type

---

## Arrays

### Searching
1. **Binary Search** - `Arrays/Searching/BinarySearch.cpp`
   - Time: O(log n), Space: O(1)
   - Find element in sorted array

### Sorting
1. **Merge Sort** - `Arrays/Sorting/MergeSort.cpp`
   - Time: O(n log n), Space: O(n)
   - Stable, divide-and-conquer sorting

2. **Quick Sort** - `Arrays/Sorting/QuickSort.cpp`
   - Time: O(n log n) avg, O(n²) worst, Space: O(log n)
   - In-place, partition-based sorting

### Two Pointers
1. **Pair Sum** - `Arrays/TwoPointers/Problem1.cpp`
   - Find pair with given sum in sorted array

2. **Closest Pair from Two Arrays** - `Arrays/TwoPointers/Problem2.cpp`
   - Find pair from two sorted arrays closest to target

3. **Problem 3** - `Arrays/TwoPointers/Problem3.cpp`

4. **Problem 4** - `Arrays/TwoPointers/Problem4.cpp`

5. **Problem 5** - `Arrays/TwoPointers/Problem5.cpp`

6. **Trapping Rain Water** - `Arrays/TwoPointers/Problem6.cpp`
   - Calculate water trapped between bars

### Sliding Window
1. **Subarray with Given Sum** - `Arrays/SlidingWindow/Problem1.cpp`
   - Find index range of subarray with target sum

2. **Maximum of All Subarrays of Size K** - `Arrays/SlidingWindow/Problem2.cpp`
   - Find maximum in each window of size K using deque

3. **Problem 3** - `Arrays/SlidingWindow/Problem3.cpp`

4. **Problem 4** - `Arrays/SlidingWindow/Problem4.cpp`

5. **Problem 5** - `Arrays/SlidingWindow/Problem5.cpp`

6. **Problem 6** - `Arrays/SlidingWindow/Problem6.cpp`

7. **Problem 7** - `Arrays/SlidingWindow/Problem7.cpp`

8. **Problem 8** - `Arrays/SlidingWindow/Problem8.cpp`

9. **Problem 9** - `Arrays/SlidingWindow/Problem9.cpp`

10. **Problem 10** - `Arrays/SlidingWindow/Problem10.cpp`

11. **Problem 11** - `Arrays/SlidingWindow/Problem11.cpp`

**Total Array Problems: 24+**

---

## Linked Lists

### Singly Linked List
1. **Insertion** - `Linked List/Singly Linked List/Insertion.cpp`
   - Insert at beginning, end, or position

2. **Deletion** - `Linked List/Singly Linked List/Deletion.cpp`
   - Delete from beginning, end, or position

3. **Traversal** - `Linked List/Singly Linked List/Traversal.cpp`
   - Iterate through linked list

4. **Searching** - `Linked List/Singly Linked List/Searching.cpp`
   - Find element in linked list

5. **Length** - `Linked List/Singly Linked List/Length.cpp`
   - Calculate length of linked list

### Doubly Linked List
- Basic operations implementation

### Circular Linked List
- Circular structure implementation

### Linked List Problems
- Various problems in `Linked List/Problems/` directory

---

## Stacks

### Implementations
1. **Stack Using Arrays** - `Stack/StackUsingArrays.cpp`
   - Array-based implementation
   - All operations: O(1)

2. **Stack Using Singly Linked List** - `Stack/StackUsingSinglyLinkedList.cpp`
   - Dynamic size implementation
   - All operations: O(1)

### Stack Problems
- Problems in `Stack/Problems/` directory

---

## Queues

### Implementations
1. **Queue Using Array** - `Queue/QueueUsingArray.cpp`
   - Fixed size implementation
   - All operations: O(1)

2. **Queue Using Linked List** - `Queue/QueueUsingLinkedList.cpp`
   - Dynamic size implementation
   - All operations: O(1)

3. **Queue Using Two Stacks** - `Queue/QueueUsingTwoStacks.cpp`
   - Enqueue: O(1), Dequeue: O(n) worst case

4. **Stack Using Queue** - `Queue/StackUsingQueue.cpp`
   - Push: O(n), Pop: O(1)

5. **Multiple Queues in Single Array** - `Queue/MultipleQueuesInSingleArray.cpp`
   - Space-efficient implementation

### Queue Problems
1-9. Various problems in `Queue/Problems/` directory
   - Problem 7: Minimum depth of binary tree
   - Problem 8: Graph traversal (Time: O(V+E))
   - Problem 9: Flatten multilevel linked list

---

## Binary Trees

### Special Trees
1. **Degenerate Binary Tree** - `Binary Tree/DegenrateBinaryTree.cpp`
   - Every parent has one child

2. **Skewed Binary Tree** - `Binary Tree/SkewedBinaryTree.cpp`
   - All nodes lean left or right

### Binary Tree Problems (35 Problems)
1. **Full Binary Tree Check** - `Binary Tree/Problems/Problem1.cpp`
   - Check if every node has 0 or 2 children

2. **Inorder Traversal** - `Binary Tree/Problems/Problem2.cpp`
   - Left-Root-Right traversal

3. **Problem 3** - `Binary Tree/Problems/Problem3.cpp`

4. **Problem 4** - `Binary Tree/Problems/Problem4.cpp`

5. **Problem 5** - `Binary Tree/Problems/Problem5.cpp`

...continuing through...

35. **Problem 35** - `Binary Tree/Problems/Problem35.cpp`

**Common Topics Covered:**
- Tree traversals (Inorder, Preorder, Postorder, Level Order)
- Tree height and depth
- Balanced tree checking
- Diameter calculation
- Lowest common ancestor
- Path sum problems
- Tree views (left, right, top, bottom)
- Vertical order traversal
- Boundary traversal
- Mirror and symmetric trees
- Serialization and deserialization

---

## Graphs

### Graph Representations
1. **Adjacency Matrix** - `Graphs/AdjacencyMatrixRepresentation.cpp`
   - Space: O(V²), Edge check: O(1)

2. **Adjacency List** - `Graphs/AdjacencyListRepresentation.cpp`
   - Space: O(V+E), Better for sparse graphs

### Graph Problems (36+ Problems)
1. **BFS on Disconnected Graph** - `Graphs/Problems/Problem1.cpp`
   - Handle multiple components
   - Time: O(V+E), Space: O(V)

2. **DFS Traversal** - `Graphs/Problems/Problem2.cpp`
   - Recursive depth-first search
   - Time: O(V+E), Space: O(V)

3. **Problem 3** - `Graphs/Problems/Problem3.cpp`

4. **Problem 4** - `Graphs/Problems/Problem4.cpp`

5. **Problem 5** - `Graphs/Problems/Problem5.cpp`

...continuing through...

36. **Problem 36** - `Graphs/Problems/Problem36.cpp`

**Common Topics Covered:**
- Graph traversals (BFS, DFS)
- Connected components
- Cycle detection
- Shortest path algorithms
- Topological sorting
- Minimum spanning tree
- Strongly connected components
- Bipartite graph check
- Dijkstra's algorithm
- Bellman-Ford algorithm
- Floyd-Warshall algorithm

---

## Heaps

### Implementation
1. **Min Heap Implementation** - `Heaps/Implementation.cpp`
   - Complete binary tree structure
   - Insert: O(log n)
   - Extract Min: O(log n)
   - Get Min: O(1)
   - Delete: O(log n)
   - Build Heap: O(n)

### Heap Problems
- Problems in `Heaps/Problems/` directory

**Common Applications:**
- Priority Queue
- Heap Sort
- K largest/smallest elements
- Median in stream
- Merge K sorted arrays

---

## Hash Tables

### Collision Resolution Methods

#### Chaining
1. **Simple Chaining** - `Hash Table/Chaining/SimpleChaining.cpp`
   - Each slot contains linked list

2. **Rehashing** - `Hash Table/Chaining/Rehashing.cpp`
   - Dynamic resizing when load factor increases

#### Open Addressing
- Linear probing
- Quadratic probing
- Double hashing

**Operations:** Average O(1), Worst O(n)

---

## Tries

### Core Operations
1. **Search, Insert, and Delete** - `Trie/SearchInsertAndDeleteInTrie.cpp`
   - All operations: O(L) where L is word length
   - Space: O(N*L) for N words

### Trie Problems (6 Problems)
1. **Word Break Problem** - `Trie/Problems/Problem1.cpp`
   - Time: O(N²), Space: O(N)
   - Check if string can be segmented

2. **Longest Common Prefix** - `Trie/Problems/Problem2.cpp`
   - Time: O(N*M), Space: O(N*M)
   - Find LCP using Trie

3. **Count Distinct Substrings (Suffix Trie)** - `Trie/Problems/Problem3.cpp`
   - Time: O(n²), Space: O(n²)
   - Use suffix trie approach

4. **Count Distinct Substrings** - `Trie/Problems/Problem4.cpp`
   - Time: O(N*M), Space: O(N*M)

5. **Shortest Unique Prefix** - `Trie/Problems/Problem5.cpp`
   - Time: O(N*M), Space: O(N*M)
   - Find shortest unique prefix for each word

6. **Count Inversions Using Trie** - `Trie/Problems/Problem6.cpp`
   - Time: O(N*M), Space: O(N*M)
   - Where M is number of bits

---

## Problem Count Summary

| Data Structure | Implementation | Problems | Total |
|----------------|----------------|----------|-------|
| **Arrays** | 3 | 21+ | 24+ |
| **Linked Lists** | 5+ | Multiple | 10+ |
| **Stacks** | 2 | Multiple | 5+ |
| **Queues** | 5 | 9+ | 14+ |
| **Binary Trees** | 2 | 35 | 37 |
| **Graphs** | 2 | 36+ | 38+ |
| **Heaps** | 1 | Multiple | 5+ |
| **Hash Tables** | 2 | - | 2+ |
| **Tries** | 1 | 6 | 7 |

**Grand Total: 140+ Problems Implemented**

---

## Navigation Guide

### By Difficulty Level

#### Beginner
- Binary Search
- Linear traversals
- Stack/Queue using arrays
- Basic tree traversals
- Simple hash table operations

#### Intermediate
- Two pointers problems
- Sliding window problems
- BFS/DFS on graphs
- Heap operations
- Trie operations
- Tree problems (height, diameter, views)

#### Advanced
- Dynamic programming on trees
- Complex graph algorithms
- Optimization problems
- Trie-based complex problems
- Advanced tree problems (serialization, LCA)

### By Company Focus

#### FAANG Common
- Two Sum variants
- Tree traversals
- Graph BFS/DFS
- Sliding window
- Dynamic programming
- Design problems (Stack, Queue using other DS)

#### Competitive Programming
- Segment trees (if implemented)
- Advanced graph algorithms
- Trie applications
- Optimization problems
- Complex mathematical problems

---

## How to Use This Index

1. **Learning Path:**
   - Start with basic implementations
   - Move to simple problems
   - Progress to advanced topics

2. **Interview Prep:**
   - Focus on common patterns
   - Practice multiple problems of same type
   - Time yourself

3. **Revision:**
   - Quickly locate problem types
   - Review implementations
   - Check complexity analysis

4. **Topic Deep Dive:**
   - Study all problems in one category
   - Understand patterns
   - Compare different approaches

---

## File Naming Convention

- **Implementation files:** Descriptive names (e.g., `BinarySearch.cpp`)
- **Problem files:** Numbered (e.g., `Problem1.cpp`, `Problem2.cpp`)
- **Special implementations:** Descriptive names (e.g., `QueueUsingTwoStacks.cpp`)

## Code Quality Features

✓ Clean, readable code  
✓ Proper comments  
✓ Time complexity mentioned  
✓ Space complexity mentioned  
✓ Working implementations  
✓ Test cases included  

---

**Repository Structure:**
```
DSA/
├── Arrays/
│   ├── Searching/
│   ├── Sorting/
│   ├── TwoPointers/
│   └── SlidingWindow/
├── Linked List/
├── Stack/
├── Queue/
├── Binary Tree/
├── Graphs/
├── Heaps/
├── Hash Table/
└── Trie/
```

---

*This index is automatically generated from the DSA repository structure.*  
*Last Updated: December 2025*
