# DSA - Revision & Practice Repository

A comprehensive collection of **140+ Data Structures and Algorithms** implementations and problems solved in C++.

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Problems](https://img.shields.io/badge/Problems-140+-green.svg)](PROBLEM_INDEX.md)
[![Topics](https://img.shields.io/badge/Topics-9-orange.svg)](DSA_REVISION_NOTES.md)

---

## 📚 Documentation

- **[Complete Revision Notes](DSA_REVISION_NOTES.md)** - Comprehensive guide with concepts, implementations, and patterns
- **[Quick Reference Guide](QUICK_REFERENCE.md)** - Cheat sheet for interviews and quick revision
- **[Problem Index](PROBLEM_INDEX.md)** - Complete list of all 140+ problems organized by topic

---

## 🗂️ Repository Structure

```
DSA/
├── Arrays/                    # 24+ problems
│   ├── Searching/            # Binary Search
│   ├── Sorting/              # Merge Sort, Quick Sort
│   ├── TwoPointers/          # 6 problems
│   └── SlidingWindow/        # 11 problems
│
├── Linked List/              # 10+ problems
│   ├── Singly Linked List/   # Basic operations
│   ├── Doubly Linked List/   # DLL implementation
│   ├── Circular Linked List/ # Circular structure
│   └── Problems/             # Various problems
│
├── Stack/                    # 5+ problems
│   ├── StackUsingArrays.cpp
│   ├── StackUsingSinglyLinkedList.cpp
│   └── Problems/
│
├── Queue/                    # 14+ problems
│   ├── QueueUsingArray.cpp
│   ├── QueueUsingLinkedList.cpp
│   ├── QueueUsingTwoStacks.cpp
│   ├── StackUsingQueue.cpp
│   └── Problems/             # 9 problems
│
├── Binary Tree/              # 37 problems
│   ├── DegenrateBinaryTree.cpp
│   ├── SkewedBinaryTree.cpp
│   └── Problems/             # 35 problems
│
├── Graphs/                   # 38+ problems
│   ├── AdjacencyMatrixRepresentation.cpp
│   ├── AdjacencyListRepresentation.cpp
│   └── Problems/             # 36+ problems
│
├── Heaps/                    # 5+ problems
│   ├── Implementation.cpp    # Min Heap
│   └── Problems/
│
├── Hash Table/               # 2+ implementations
│   ├── Chaining/            # Simple Chaining, Rehashing
│   └── Open Addressing/
│
└── Trie/                     # 7 problems
    ├── SearchInsertAndDeleteInTrie.cpp
    └── Problems/             # 6 problems
```

---

## 🎯 Topics Covered

### Data Structures
- ✅ Arrays & Strings
- ✅ Linked Lists (Singly, Doubly, Circular)
- ✅ Stacks & Queues
- ✅ Binary Trees
- ✅ Graphs
- ✅ Heaps (Min Heap, Max Heap)
- ✅ Hash Tables (Chaining, Open Addressing)
- ✅ Tries

### Algorithms
- ✅ Searching (Binary Search)
- ✅ Sorting (Merge Sort, Quick Sort)
- ✅ Two Pointers Technique
- ✅ Sliding Window
- ✅ Graph Traversals (BFS, DFS)
- ✅ Tree Traversals (Inorder, Preorder, Postorder, Level Order)
- ✅ Recursion & Backtracking

### Problem-Solving Patterns
- Two Pointers
- Sliding Window
- Fast & Slow Pointers
- Binary Search
- BFS/DFS Traversal
- Divide and Conquer
- Greedy Algorithms
- Dynamic Programming (in various problems)

---

## 📊 Progress Overview

| Category | Problems Solved | Status |
|----------|-----------------|--------|
| Arrays | 24+ | ✅ |
| Linked Lists | 10+ | ✅ |
| Stacks | 5+ | ✅ |
| Queues | 14+ | ✅ |
| Binary Trees | 37 | ✅ |
| Graphs | 38+ | ✅ |
| Heaps | 5+ | ✅ |
| Hash Tables | 2+ | ✅ |
| Tries | 7 | ✅ |
| **Total** | **140+** | **✅** |

---

## 🚀 Quick Start

### Prerequisites
- C++ Compiler (GCC/MinGW recommended)
- Basic understanding of C++ and DSA concepts

### Compilation & Execution
```bash
# Compile a C++ file
g++ -o output filename.cpp

# Run the executable
./output

# Or in Windows
output.exe
```

### Example: Running Binary Search
```bash
cd Arrays/Searching
g++ -o binarysearch BinarySearch.cpp
./binarysearch
```

---

## 📖 How to Use This Repository

### For Learning
1. Start with **[Revision Notes](DSA_REVISION_NOTES.md)** to understand concepts
2. Study the implementation in the relevant folder
3. Try solving related problems
4. Review and optimize your solutions

### For Interview Preparation
1. Use **[Quick Reference Guide](QUICK_REFERENCE.md)** for rapid revision
2. Practice problems category-wise from **[Problem Index](PROBLEM_INDEX.md)**
3. Focus on common patterns and techniques
4. Time yourself while solving problems

### For Revision
1. Quickly review implementations
2. Check time/space complexity
3. Practice similar problem types
4. Focus on areas that need improvement

---

## 💡 Key Features

✅ **Clean Code** - Well-commented, readable implementations  
✅ **Complexity Analysis** - Time and space complexity mentioned  
✅ **Multiple Approaches** - Different solutions where applicable  
✅ **Test Cases** - Working examples included  
✅ **Comprehensive Coverage** - 140+ problems across 9 major topics  
✅ **Interview Focused** - Common patterns and techniques  

---

## 🎓 Complexity Reference

### Common Time Complexities
| Complexity | Name | Example |
|------------|------|---------|
| O(1) | Constant | Array access, Hash lookup |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Linear search, Traversal |
| O(n log n) | Linearithmic | Merge sort, Quick sort |
| O(n²) | Quadratic | Nested loops |
| O(2ⁿ) | Exponential | Recursive Fibonacci |

---

## 📝 Code Templates

### Array Problems
```cpp
// Two Pointers
int left = 0, right = n-1;
while(left < right) {
    // Process
}

// Sliding Window
for(int end = 0; end < n; end++) {
    // Expand window
    while(/* shrink condition */) {
        // Shrink window
    }
}
```

### Tree Problems
```cpp
// DFS Template
void dfs(Node* node) {
    if(!node) return;
    dfs(node->left);
    dfs(node->right);
}

// BFS Template
queue<Node*> q;
q.push(root);
while(!q.empty()) {
    Node* curr = q.front();
    q.pop();
    // Process
}
```

### Graph Problems
```cpp
// BFS
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()) {
        // Process
    }
}

// DFS
void dfs(int node) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}
```

---

## 🔗 Resources

### Official Documentation
- [C++ Reference](https://en.cppreference.com/)
- [STL Documentation](https://www.cplusplus.com/reference/stl/)

### Practice Platforms
- [LeetCode](https://leetcode.com/)
- [HackerRank](https://www.hackerrank.com/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [Codeforces](https://codeforces.com/)

### Learning Resources
- [Revision Notes](DSA_REVISION_NOTES.md) - This repository
- [Quick Reference](QUICK_REFERENCE.md) - This repository
- [Problem Index](PROBLEM_INDEX.md) - This repository

---

## 🤝 Contributing

This is a personal learning repository, but suggestions are welcome! Feel free to:
- Report issues or bugs
- Suggest optimizations
- Share alternative approaches

---

## 📄 License

This repository is for educational purposes. Feel free to use the code for learning and practice.

---

## 👤 Author

**Akshat**  
📧 Contact: [GitHub Profile](https://github.com/akshat12000)

---

## ⭐ Acknowledgments

- Problems inspired by various coding platforms (LeetCode, GeeksforGeeks, HackerRank)
- Implementations based on standard algorithms and data structures
- Created for personal revision and interview preparation

---

## 📈 Future Plans

- [ ] Add more dynamic programming problems
- [ ] Implement advanced graph algorithms
- [ ] Add segment tree and Fenwick tree
- [ ] Include system design patterns
- [ ] Add more optimization techniques

---

**Happy Coding! 🚀**

*Last Updated: December 2025*
