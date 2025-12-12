# DSA Quick Reference Guide

## ⚡ Time Complexity Cheat Sheet

### Data Structure Operations
| Data Structure | Access | Search | Insert | Delete | Space |
|----------------|--------|--------|--------|--------|-------|
| **Array** | O(1) | O(n) | O(n) | O(n) | O(n) |
| **Linked List** | O(n) | O(n) | O(1) | O(1) | O(n) |
| **Stack** | O(n) | O(n) | O(1) | O(1) | O(n) |
| **Queue** | O(n) | O(n) | O(1) | O(1) | O(n) |
| **Hash Table** | - | O(1)* | O(1)* | O(1)* | O(n) |
| **Binary Tree** | O(n) | O(n) | O(n) | O(n) | O(n) |
| **BST** | O(log n)* | O(log n)* | O(log n)* | O(log n)* | O(n) |
| **Heap** | - | O(n) | O(log n) | O(log n) | O(n) |
| **Trie** | O(L) | O(L) | O(L) | O(L) | O(N*L) |

*Average case; worst case can be O(n)

### Sorting Algorithms
| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✓ |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ✗ |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✓ |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | ✓ |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | ✗ |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | ✗ |

---

## 🎯 Common Patterns

### 1️⃣ Two Pointers
```cpp
int left = 0, right = n-1;
while(left < right) {
    if(arr[left] + arr[right] == target) return true;
    else if(arr[left] + arr[right] < target) left++;
    else right--;
}
```
**Use for:** Sorted arrays, pair finding, removing duplicates

### 2️⃣ Sliding Window
```cpp
int start = 0, maxLen = 0;
for(int end = 0; end < n; end++) {
    // Add arr[end] to window
    while(/* window invalid */) {
        // Remove arr[start] from window
        start++;
    }
    maxLen = max(maxLen, end - start + 1);
}
```
**Use for:** Subarray/substring problems, max/min in window

### 3️⃣ Fast & Slow Pointers
```cpp
Node* slow = head, *fast = head;
while(fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return true; // Cycle detected
}
```
**Use for:** Cycle detection, finding middle, palindrome check

### 4️⃣ Binary Search
```cpp
int left = 0, right = n-1;
while(left <= right) {
    int mid = left + (right - left) / 2;
    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```
**Use for:** Sorted arrays, finding boundaries, optimization problems

### 5️⃣ BFS (Level Order)
```cpp
queue<Node*> q;
q.push(root);
while(!q.empty()) {
    int size = q.size();
    for(int i = 0; i < size; i++) {
        Node* curr = q.front(); q.pop();
        // Process curr
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}
```
**Use for:** Shortest path, level order, minimum depth

### 6️⃣ DFS (Recursive)
```cpp
void dfs(Node* node) {
    if(!node) return;
    // Process node (preorder)
    dfs(node->left);
    // Process node (inorder)
    dfs(node->right);
    // Process node (postorder)
}
```
**Use for:** Tree traversal, backtracking, path finding

---

## 📊 Common Problem Types

### Arrays
- ✓ Two Sum → Hash map: O(n)
- ✓ Maximum Subarray → Kadane's: O(n)
- ✓ Rotate Array → Reverse: O(n)
- ✓ Missing Number → XOR or Math: O(n)
- ✓ Trapping Rain Water → Two pointers: O(n)

### Strings
- ✓ Valid Anagram → Hash map/Sorting
- ✓ Longest Substring Without Repeating → Sliding window
- ✓ Valid Parentheses → Stack
- ✓ Palindrome Check → Two pointers

### Linked Lists
- ✓ Reverse List → Iterative/Recursive: O(n)
- ✓ Detect Cycle → Fast-slow pointers: O(n)
- ✓ Merge Two Lists → Two pointers: O(n+m)
- ✓ Find Middle → Fast-slow pointers: O(n)

### Trees
- ✓ Max Depth → DFS: O(n)
- ✓ Validate BST → Inorder/Recursion: O(n)
- ✓ Level Order → BFS: O(n)
- ✓ Lowest Common Ancestor → DFS: O(n)
- ✓ Serialize/Deserialize → BFS/DFS: O(n)

### Graphs
- ✓ Number of Islands → DFS/BFS: O(n*m)
- ✓ Clone Graph → DFS/BFS with map: O(V+E)
- ✓ Course Schedule → Topological sort: O(V+E)
- ✓ Shortest Path → BFS: O(V+E)

### Dynamic Programming
- ✓ Climbing Stairs → Bottom-up: O(n)
- ✓ House Robber → DP: O(n)
- ✓ Coin Change → DP: O(n*amount)
- ✓ Longest Increasing Subsequence → DP: O(n²) or O(n log n)

---

## 🔧 Essential Code Snippets

### Array Manipulation
```cpp
// Reverse array
reverse(arr.begin(), arr.end());

// Sort array
sort(arr.begin(), arr.end());

// Find max element
int maxElem = *max_element(arr.begin(), arr.end());

// Binary search
bool found = binary_search(arr.begin(), arr.end(), target);
int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
```

### String Operations
```cpp
// Reverse string
reverse(s.begin(), s.end());

// Check palindrome
bool isPalindrome = (s == string(s.rbegin(), s.rend()));

// Convert to lowercase
transform(s.begin(), s.end(), s.begin(), ::tolower);

// Split string
istringstream iss(str);
vector<string> tokens;
string token;
while(iss >> token) tokens.push_back(token);
```

### STL Containers
```cpp
// Vector
vector<int> v = {1, 2, 3};
v.push_back(4);
v.pop_back();
v.size();
v.empty();

// Set (unique, sorted)
set<int> s;
s.insert(1);
s.erase(1);
s.count(1); // returns 0 or 1

// Map
map<int, int> m;
m[key] = value;
m.count(key);
m.erase(key);

// Queue
queue<int> q;
q.push(1);
q.pop();
q.front();
q.empty();

// Stack
stack<int> st;
st.push(1);
st.pop();
st.top();
st.empty();

// Priority Queue (Max Heap)
priority_queue<int> pq;
pq.push(1);
pq.pop();
pq.top();

// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;

// Deque
deque<int> dq;
dq.push_front(1);
dq.push_back(2);
dq.pop_front();
dq.pop_back();
```

---

## 💡 Problem-Solving Framework

### Step 1: Understand
- [ ] Read problem carefully
- [ ] Identify input/output
- [ ] Ask clarifying questions
- [ ] Note constraints

### Step 2: Example
- [ ] Work through small example
- [ ] Identify edge cases
- [ ] Verify understanding

### Step 3: Approach
- [ ] Brute force first
- [ ] Identify pattern
- [ ] Optimize approach
- [ ] Analyze complexity

### Step 4: Code
- [ ] Write clean code
- [ ] Handle edge cases
- [ ] Use meaningful names
- [ ] Add comments if needed

### Step 5: Test
- [ ] Test with examples
- [ ] Test edge cases
- [ ] Verify complexity

---

## 🎓 Common Edge Cases

### Arrays
- Empty array: `[]`
- Single element: `[1]`
- All same elements: `[5, 5, 5]`
- Sorted/reverse sorted
- Negative numbers

### Strings
- Empty string: `""`
- Single character: `"a"`
- All same characters: `"aaaa"`
- Special characters
- Case sensitivity

### Trees
- Empty tree: `NULL`
- Single node
- Skewed tree (only left or right)
- Perfect binary tree

### Graphs
- Disconnected graph
- Single node
- Cycles
- Self-loops
- Multiple edges

### Numbers
- Zero: `0`
- Negative: `-5`
- Large numbers: `INT_MAX`
- Overflow cases

---

## 🚀 Optimization Checklist

- [ ] Can I use a hash map for O(1) lookups?
- [ ] Is the data sorted? Can I use binary search?
- [ ] Can I use two pointers?
- [ ] Is this a sliding window problem?
- [ ] Can I use BFS/DFS?
- [ ] Is there a mathematical formula?
- [ ] Can I use dynamic programming?
- [ ] Can I precompute values?
- [ ] Can I use greedy approach?
- [ ] Can I reduce space complexity?

---

## 📝 Interview Tips

### Before Interview
1. Practice on whiteboard/paper
2. Review company-specific patterns
3. Practice explaining your thought process
4. Prepare questions to ask

### During Interview
1. **Clarify** requirements before coding
2. **Communicate** your approach
3. **Start simple** with brute force
4. **Optimize** step by step
5. **Test** your solution
6. **Discuss** trade-offs

### Red Flags to Avoid
- ❌ Jumping into code immediately
- ❌ Not considering edge cases
- ❌ Ignoring time/space complexity
- ❌ Being silent while coding
- ❌ Not testing the solution

---

## 🔢 Math Formulas

### Common Sequences
- Sum of first n numbers: `n(n+1)/2`
- Sum of squares: `n(n+1)(2n+1)/6`
- Power of 2: `1 << n` = 2ⁿ
- Check power of 2: `(n & (n-1)) == 0`

### Bit Manipulation
- Get bit: `(n >> i) & 1`
- Set bit: `n | (1 << i)`
- Clear bit: `n & ~(1 << i)`
- Toggle bit: `n ^ (1 << i)`
- Count set bits: `__builtin_popcount(n)`

### Array Indices
- Parent: `(i-1)/2`
- Left child: `2*i + 1`
- Right child: `2*i + 2`

---

## 📚 Must-Know STL Functions

```cpp
// Algorithm
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
*max_element(v.begin(), v.end());
*min_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);
count(v.begin(), v.end(), value);
find(v.begin(), v.end(), value);

// Lower/Upper bound
lower_bound(v.begin(), v.end(), x); // >=x
upper_bound(v.begin(), v.end(), x); // >x

// Remove duplicates
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// Next/Previous permutation
next_permutation(v.begin(), v.end());
prev_permutation(v.begin(), v.end());
```

---

**Quick Tip:** When stuck, try:
1. Draw it out
2. Work through small example
3. Think of similar problems
4. Consider data structures that fit
5. Start with brute force, then optimize

---

*Use this guide as a quick reference during practice and interviews!*
