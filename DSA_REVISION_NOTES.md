# Data Structures and Algorithms - Revision Notes

> A comprehensive guide covering essential DSA concepts with C++ implementations

---

## Table of Contents
1. [Arrays](#arrays)
2. [Linked Lists](#linked-lists)
3. [Stacks](#stacks)
4. [Queues](#queues)
5. [Binary Trees](#binary-trees)
6. [Graphs](#graphs)
7. [Heaps](#heaps)
8. [Hash Tables](#hash-tables)
9. [Tries](#tries)

---

## Arrays

### Searching Algorithms

#### Binary Search
- **Time Complexity:** O(log n)
- **Space Complexity:** O(1)
- **Key Points:**
  - Works only on sorted arrays
  - Uses divide and conquer approach
  - Calculate mid: `mid = l + (r-l)/2` (prevents overflow)
  - Three cases: element found, search left half, search right half

```cpp
int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

### Sorting Algorithms

#### Merge Sort
- **Time Complexity:** O(n log n) in all cases
- **Space Complexity:** O(n)
- **Key Points:**
  - Stable sorting algorithm
  - Divide and conquer approach
  - Divides array into two halves, sorts them, then merges

#### Quick Sort
- **Time Complexity:** 
  - Best/Average: O(n log n)
  - Worst: O(n²)
- **Space Complexity:** O(log n) for recursion stack
- **Key Points:**
  - In-place sorting algorithm
  - Uses pivot element
  - Partition around pivot

### Two Pointers Technique

**Common Problems:**
1. **Pair Sum in Sorted Array**
   - Two pointers at start and end
   - Move based on sum comparison
   - Time: O(n), Space: O(1)

2. **Closest Pair from Two Sorted Arrays**
   - One pointer at start of first array
   - One pointer at end of second array
   - Track minimum difference

3. **Trapping Rain Water**
   - Calculate water trapped between bars
   - Two pointer approach from both ends

**Pattern:**
```cpp
int left = 0, right = n-1;
while(left < right) {
    // Process based on condition
    if(condition) left++;
    else right--;
}
```

### Sliding Window Technique

**Common Problems:**
1. **Subarray with Given Sum**
   - Expand window by moving right pointer
   - Shrink window by moving left pointer
   - Time: O(n)

2. **Maximum of All Subarrays of Size K**
   - Use deque to maintain maximum
   - Remove elements outside window
   - Remove smaller elements from back
   - Time: O(n)

**Pattern:**
```cpp
int i = 0, j = 0;
while(j < n) {
    // Add current element to window
    // Check if window size is valid
    // Shrink window if needed
    j++;
}
```

---

## Linked Lists

### Types
1. **Singly Linked List** - Each node points to next
2. **Doubly Linked List** - Each node points to next and previous
3. **Circular Linked List** - Last node points to first

### Basic Operations

#### Node Structure
```cpp
struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
```

#### Common Operations
1. **Insertion**
   - At beginning: O(1)
   - At end: O(n) for singly, O(1) with tail pointer
   - At position: O(n)

2. **Deletion**
   - At beginning: O(1)
   - At end: O(n) for singly
   - At position: O(n)

3. **Traversal**: O(n)

4. **Searching**: O(n)

5. **Length Calculation**: O(n)

### Key Concepts
- Always check for NULL pointers
- Use dummy nodes for easier edge case handling
- Two pointer technique for cycle detection
- Fast-slow pointer for finding middle

---

## Stacks

### Implementation Methods
1. **Using Arrays**
2. **Using Linked Lists**

### Stack Using Arrays
```cpp
class Stack {
    int arr[1000];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if(top >= 999) return;
        arr[++top] = x;
    }
    int pop() {
        if(top < 0) return -1;
        return arr[top--];
    }
    int peek() {
        if(top < 0) return -1;
        return arr[top];
    }
    bool isEmpty() { return top == -1; }
};
```

### Operations
- **Push**: O(1)
- **Pop**: O(1)
- **Peek/Top**: O(1)
- **isEmpty**: O(1)

### Applications
- Expression evaluation
- Parenthesis matching
- Backtracking algorithms
- Function call management (recursion)

---

## Queues

### Implementation Methods
1. **Using Arrays**
2. **Using Linked Lists**

### Queue Using Arrays
```cpp
class Queue {
    int arr[100005];
    int front, rear;
public:
    Queue() { front = 0; rear = 0; }
    void push(int x) {
        arr[rear++] = x;
    }
    int pop() {
        if(front == rear) return -1;
        return arr[front++];
    }
    int getFront() {
        if(front == rear) return -1;
        return arr[front];
    }
    bool isEmpty() { return front == rear; }
};
```

### Operations
- **Enqueue**: O(1)
- **Dequeue**: O(1)
- **Front**: O(1)
- **isEmpty**: O(1)

### Special Types
1. **Queue Using Two Stacks**
   - Enqueue: O(1)
   - Dequeue: O(n) worst case

2. **Stack Using Queue**
   - Push: O(n)
   - Pop: O(1)

3. **Multiple Queues in Single Array**
   - Efficient space utilization

### Applications
- BFS in graphs
- Level order traversal in trees
- CPU scheduling
- Buffer management

---

## Binary Trees

### Types of Binary Trees
1. **Full Binary Tree** - Every node has 0 or 2 children
2. **Complete Binary Tree** - All levels filled except possibly last
3. **Perfect Binary Tree** - All internal nodes have 2 children, all leaves at same level
4. **Degenerate Tree** - Every parent has only one child
5. **Skewed Binary Tree** - All nodes skewed to left or right

### Node Structure
```cpp
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
```

### Tree Traversals

#### 1. Inorder (Left-Root-Right)
```cpp
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```
- For BST: gives sorted order
- Time: O(n), Space: O(h) where h is height

#### 2. Preorder (Root-Left-Right)
- Used to create copy of tree
- Used to get prefix expression

#### 3. Postorder (Left-Right-Root)
- Used to delete tree
- Used to get postfix expression

#### 4. Level Order
- Uses queue
- BFS approach

### Common Problems (35+ Implemented)
- Tree height/depth calculation
- Checking if tree is balanced
- Diameter of tree
- Lowest common ancestor
- Path sum problems
- View problems (left, right, top, bottom)
- Vertical order traversal
- Boundary traversal
- Mirror/symmetric tree
- Serialize/deserialize tree

### Key Concepts
- **Height of tree**: O(n)
- **Balanced tree**: |height(left) - height(right)| ≤ 1
- **Diameter**: Longest path between any two nodes
- **Level**: Distance from root (root is at level 0)

---

## Graphs

### Representation

#### 1. Adjacency Matrix
- 2D array of size V×V
- Space: O(V²)
- Edge check: O(1)
- Good for dense graphs

#### 2. Adjacency List
- Array of vectors/lists
- Space: O(V+E)
- Edge check: O(degree)
- Good for sparse graphs

### Graph Traversals

#### BFS (Breadth-First Search)
```cpp
void bfs(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        
        for(int x : adj[curr]) {
            if(!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
```
- **Time:** O(V+E)
- **Space:** O(V)
- **Uses:** Shortest path in unweighted graph, level order traversal

#### DFS (Depth-First Search)
```cpp
void dfs(vector<vector<int>>& adj, int s, vector<bool>& visited) {
    visited[s] = true;
    cout << s << " ";
    
    for(int i : adj[s]) {
        if(!visited[i]) {
            dfs(adj, i, visited);
        }
    }
}
```
- **Time:** O(V+E)
- **Space:** O(V)
- **Uses:** Cycle detection, topological sorting, path finding

### Common Problems (36+ Implemented)
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

### Key Concepts
- **Directed vs Undirected**
- **Weighted vs Unweighted**
- **Cyclic vs Acyclic**
- **Connected vs Disconnected**
- **DAG** (Directed Acyclic Graph)

---

## Heaps

### Min Heap Implementation
```cpp
class MinHeap {
    int *harr;
    int capacity;
    int heap_size;
public:
    MinHeap(int cap);
    void MinHeapify(int i);
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return harr[0]; }
    void deleteKey(int i);
    void insertKey(int k);
};
```

### Operations
- **Insert**: O(log n)
- **Extract Min/Max**: O(log n)
- **Get Min/Max**: O(1)
- **Delete**: O(log n)
- **Heapify**: O(log n)
- **Build Heap**: O(n)

### Properties
1. **Complete Binary Tree**
2. **Heap Property:**
   - Min Heap: Parent ≤ Children
   - Max Heap: Parent ≥ Children

### Applications
- Priority Queue
- Heap Sort (O(n log n))
- K largest/smallest elements
- Median in stream
- Merge K sorted arrays

### Key Formulas
- For node at index i:
  - Parent: (i-1)/2
  - Left child: 2*i + 1
  - Right child: 2*i + 2

---

## Hash Tables

### Collision Resolution

#### 1. Chaining
- Each slot contains a linked list
- Simple implementation
- Load factor can exceed 1

```cpp
class HashTable {
    vector<list<int>> table;
    int capacity;
public:
    void insert(int key);
    void remove(int key);
    bool search(int key);
};
```

#### 2. Open Addressing
- All elements stored in hash table itself
- Probing required: Linear, Quadratic, Double Hashing

### Operations
- **Insert**: Average O(1), Worst O(n)
- **Delete**: Average O(1), Worst O(n)
- **Search**: Average O(1), Worst O(n)

### Hash Functions
- Division Method: h(k) = k mod m
- Multiplication Method
- Universal Hashing

### Load Factor
- α = n/m (n = number of keys, m = table size)
- Keep α < 0.7 for good performance
- **Rehashing** when load factor exceeds threshold

### Applications
- Fast lookup
- Counting frequencies
- Two sum problem
- Subarray sum problems
- Anagram checking

---

## Tries

### Structure
```cpp
struct TrieNode {
    TrieNode* childNode[26];
    int wordCount;
    
    TrieNode() {
        wordCount = 0;
        for(int i = 0; i < 26; i++) {
            childNode[i] = NULL;
        }
    }
};
```

### Operations

#### Insert
```cpp
void insert(TrieNode* root, string& key) {
    TrieNode* curr = root;
    for(char c : key) {
        if(curr->childNode[c - 'a'] == NULL) {
            curr->childNode[c - 'a'] = new TrieNode();
        }
        curr = curr->childNode[c - 'a'];
    }
    curr->wordCount++;
}
```
- **Time:** O(L) where L is length of word
- **Space:** O(L)

#### Search
```cpp
bool search(TrieNode* root, string& key) {
    TrieNode* curr = root;
    for(char c : key) {
        if(curr->childNode[c - 'a'] == NULL)
            return false;
        curr = curr->childNode[c - 'a'];
    }
    return curr->wordCount > 0;
}
```
- **Time:** O(L)

#### Delete
- Mark wordCount as 0 or delete node if no children

### Common Problems
1. **Word Break Problem** - O(N²)
2. **Longest Common Prefix** - O(N*M)
3. **Count Distinct Substrings** - O(N²)
4. **Auto-complete/Search Suggestions**
5. **Shortest Unique Prefix**
6. **Count Inversions** - O(N*M)

### Applications
- Dictionary implementation
- Auto-complete feature
- Spell checker
- IP routing (Longest prefix matching)
- Phone directory

### Space Optimization
- Compressed Trie (Patricia Trie)
- Ternary Search Tree

---

## Important Algorithms Summary

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |

### Searching Algorithms
| Algorithm | Time | Space | Requirement |
|-----------|------|-------|-------------|
| Linear Search | O(n) | O(1) | None |
| Binary Search | O(log n) | O(1) | Sorted array |
| Jump Search | O(√n) | O(1) | Sorted array |
| Interpolation Search | O(log log n) | O(1) | Uniformly distributed sorted array |

---

## Problem-Solving Patterns

### 1. Two Pointers
- **Use when:** Working with sorted array, finding pairs/triplets
- **Examples:** Two sum, container with most water, remove duplicates

### 2. Sliding Window
- **Use when:** Need to track contiguous subarray/substring
- **Examples:** Maximum sum subarray, longest substring without repeating chars

### 3. Fast & Slow Pointers
- **Use when:** Detecting cycles, finding middle element
- **Examples:** Linked list cycle, finding middle of linked list

### 4. Divide and Conquer
- **Use when:** Problem can be divided into independent subproblems
- **Examples:** Merge sort, quick sort, binary search

### 5. Dynamic Programming
- **Use when:** Overlapping subproblems, optimal substructure
- **Examples:** Fibonacci, longest common subsequence, knapsack

### 6. Greedy Algorithms
- **Use when:** Local optimal choices lead to global optimum
- **Examples:** Activity selection, Huffman coding, Kruskal's algorithm

### 7. Backtracking
- **Use when:** Need to explore all possible solutions
- **Examples:** N-Queens, Sudoku solver, permutations

### 8. BFS/DFS
- **Use when:** Graph/tree traversal needed
- **Examples:** Shortest path, connected components, topological sort

---

## Time Complexity Quick Reference

### Common Time Complexities (Best to Worst)
1. **O(1)** - Constant
2. **O(log n)** - Logarithmic (Binary search)
3. **O(n)** - Linear (Single loop)
4. **O(n log n)** - Linearithmic (Efficient sorting)
5. **O(n²)** - Quadratic (Nested loops)
6. **O(n³)** - Cubic (Triple nested loops)
7. **O(2ⁿ)** - Exponential (Recursive subproblems)
8. **O(n!)** - Factorial (Permutations)

### Space Complexity Considerations
- **In-place algorithms:** O(1) extra space
- **Recursive algorithms:** O(h) where h is recursion depth
- **Dynamic Programming:** Often O(n) or O(n²) for memoization

---

## Tips for Coding Interviews

### Before Coding
1. **Understand the problem completely**
2. **Ask clarifying questions**
3. **Think about edge cases**
4. **Discuss approach before coding**
5. **Analyze time and space complexity**

### While Coding
1. **Start with brute force if needed**
2. **Optimize step by step**
3. **Write clean, readable code**
4. **Use meaningful variable names**
5. **Handle edge cases**

### Common Edge Cases
- Empty input (null, empty array/string)
- Single element
- Duplicate elements
- Negative numbers
- Integer overflow
- Very large inputs

### Optimization Techniques
1. Use hash maps for O(1) lookups
2. Use sorting when appropriate
3. Consider two pointers for arrays
4. Use sliding window for subarrays
5. Use binary search on sorted data
6. Consider BFS for shortest path
7. Use DFS for exhaustive search
8. Dynamic programming for overlapping subproblems

---

## Resources and Practice

### Problem Count by Topic
- **Arrays:** 30+ problems (Searching, Sorting, Two Pointers, Sliding Window)
- **Binary Trees:** 35+ problems
- **Graphs:** 36+ problems
- **Linked Lists:** Multiple implementations and problems
- **Stacks & Queues:** Various implementations and applications
- **Heaps:** Implementation and problems
- **Hash Tables:** Chaining and Open Addressing
- **Tries:** Core operations and 6+ problems

### Next Steps
1. Practice more dynamic programming problems
2. Implement advanced graph algorithms
3. Study system design patterns
4. Solve company-specific problems
5. Time yourself while solving problems

---

## Appendix: Code Templates

### Generic DFS Template
```cpp
void dfs(Node* node, vector<bool>& visited) {
    if(node == NULL || visited[node->id]) return;
    visited[node->id] = true;
    // Process node
    for(Node* neighbor : node->neighbors) {
        dfs(neighbor, visited);
    }
}
```

### Generic BFS Template
```cpp
void bfs(Node* start) {
    queue<Node*> q;
    set<Node*> visited;
    q.push(start);
    visited.insert(start);
    
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        // Process curr
        for(Node* neighbor : curr->neighbors) {
            if(visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}
```

### Binary Search Template
```cpp
int binarySearch(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

### Sliding Window Template
```cpp
int slidingWindow(vector<int>& arr, int k) {
    int windowSum = 0, maxSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    maxSum = windowSum;
    
    for(int i = k; i < arr.size(); i++) {
        windowSum += arr[i] - arr[i-k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
```

---

**Last Updated:** December 2025  
**Total Problems Solved:** 100+  
**Repository:** [DSA-REV](https://github.com/akshat12000/DSA-REV)

---

*These notes are compiled from hands-on implementation and problem-solving practice. Each concept has been implemented and tested with multiple examples.*
