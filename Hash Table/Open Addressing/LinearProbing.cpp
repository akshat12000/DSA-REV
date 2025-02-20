// Open Addressing: Linear Probing
// Linear Probing is a collision resolution technique in open addressing. When a new key is inserted and the hash function generates an index that is already occupied, we move to the next index and check if it is empty. If it is empty, we insert the key at that index. If it is not empty, we move to the next index and so on until we find an empty index. This is called linear probing because we are probing the next index linearly.
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
        // Linear probing: If the index is already occupied, move to the next index
        while(arr[index] != -1 && arr[index] != -2 && arr[index] != key) {
            index = (index + 1) % capacity;
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
        while(arr[index] != -1 && size>0) {
            if(arr[index] == key) {
                arr[index] = -2;
                size--;
                return;
            }
            index = (index + 1) % capacity;
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
            index = (index + 1) % capacity;
            i++;
        }
        return false;
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
    HashTable h(10);
    h.insert(5);
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(45);
    h.insert(55);
    h.insert(65);
    h.insert(75);
    h.insert(85);
    h.insert(95);
    h.insert(105);
    h.display();
    h.remove(5);
    h.remove(15);
    h.remove(25);
    h.remove(35);
    h.remove(45);
    h.display();
    cout << h.search(5) << endl;
    cout << h.search(85) << endl;
    return 0;
}

// Time Complexity: Insertion: O(n), Deletion: O(n), Search: O(n)
// Space Complexity: O(n)