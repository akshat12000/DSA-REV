// Open Addressing: Double Hashing
// Double Hashing is a collision resolution technique in open addressing. When a new key is inserted and the hash function generates an index that is already occupied, we move to the next index by adding i * hash2(key). If the next index is also occupied, we move to the next index by adding (i+1) * hash2(key) and so on until we find an empty index. This is called double hashing because we are using two hash functions to find the next index.
#include<bits/stdc++.h>
using namespace std;

class HashTable {
    int *arr;
    int size;
    int capacity;
public:
    HashTable(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
        for(int i = 0; i < capacity; i++) {
            arr[i] = -1;
        }
    }

    int hash(int key) {
        return key % capacity;
    }

    void insert(int key) {
        if(size == capacity) {
            cout << "Table is full" << endl;
            return;
        }
        int index = hash(key);
        int i = 1;

        // Double hashing: If the index is already occupied, move to the next index by adding i * hash2(key)
        while(arr[index] != -1 && arr[index] != -2 && arr[index] != key) {
            index = (hash(key) + i * hash2(key)) % capacity;
            i++;
        }
        if(arr[index] == key) {
            cout << "Key already exists" << endl;
            return;
        }
        arr[index] = key;
        size++;
    }

    void remove(int key) {
        int index = hash(key);
        int i = 1;
        while(arr[index] != -1 && size > 0) {
            if(arr[index] == key) {
                arr[index] = -2;
                size--;
                return;
            }
            index = (hash(key) + i * hash2(key)) % capacity;
            i++;
        }
        cout << "Key not found" << endl;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 1;
        while(arr[index] != -1) {
            if(i > capacity) {
                break;
            }
            if(arr[index] == key) {
                return true;
            }
            index = (hash(key) + i * hash2(key)) % capacity;
            i++;
        }
        return false;
    }

    int hash2(int key) {
        return 7 - (key % 7);
    }

    void display() {
        for(int i = 0; i < capacity; i++) {
            if(arr[i] != -1 && arr[i] != -2) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(22);
    ht.insert(9);
    ht.insert(16);
    ht.insert(19);
    ht.display();
    ht.remove(15);
    ht.remove(7);
    ht.remove(9);
    ht.display();
    cout << ht.search(15) << endl;
    cout << ht.search(20) << endl;
    return 0;
}

// Time Complexity:
// The time complexity of search, insert, and delete operations in a hash table using double hashing is O(1) on average. In the worst case, the time complexity is O(n).
// Space Complexity:
// The space complexity of a hash table using double hashing is O(n).