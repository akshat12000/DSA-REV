// A C++ program to print all values
// smaller than a given value in Binary
// Heap
#include <bits/stdc++.h>
using namespace std;

// A class for Min Heap
class MinHeap {
	// pointer to array of elements in heap
	int* harr;

	// maximum possible size of min heap
	int capacity;
	int heap_size; // Current no. of elements.
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with root at
	// given index
	void MinHeapify(int);

	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	// Inserts a new key 'k'
	void insertKey(int k);

	// Function to print all nodes smaller than k
	void printSmallerThan(int k, int pos);
};

// Function to print all elements smaller than k
void MinHeap::printSmallerThan(int x, int pos = 0)
{
	/* Make sure item exists */
	if (pos >= heap_size)
		return;

	if (harr[pos] >= x) {
		/* Skip this node and its descendants,
		as they are all >= x . */
		return;
	}

	cout << harr[pos] << " ";

	printSmallerThan(x, left(pos));
	printSmallerThan(x, right(pos));
}

// Constructor: Builds a heap from a given
// array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::insertKey(int k)
{
	if (heap_size == capacity) {
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

// A recursive method to heapify a subtree with
// root at given index. This method assumes that
// the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}

// Driver program to test above functions
int main()
{
	MinHeap h(50);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	h.insertKey(80);
	h.insertKey(6);
	h.insertKey(150);
	h.insertKey(77);
	h.insertKey(120);

	// Print all nodes smaller than 100.
	int x = 100;
	h.printSmallerThan(x);

	return 0;
}

// Time Complexity: O(N) where N is the number of nodes in the heap.
// Space Complexity: O(N) where N is the number of nodes in the heap.