// Open Addressing: Quadratic Probing
// Quadratic Probing is a collision resolution technique in open addressing. When a new key is inserted and the hash function generates an index that is already occupied, we move to the next index by adding i^2. If the next index is also occupied, we move to the next index by adding (i+1)^2 and so on until we find an empty index. This is called quadratic probing because we are probing the next index quadratically.
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

        // Quadratic probing: If the index is already occupied, move to the next index by adding i^2
        while(arr[index] != -1 && arr[index] != -2 && arr[index] != key) {
            index = (index + i*i) % capacity;
            i++;
        }
        if(arr[index] == key) {
            cout << "Key already exists" << endl;
            return;
        }
        arr[index] = key;
        size++;
    }

    void remove(int key)
    {
        int index = hash(key);
        int i = 1;
        while(arr[index] != -1 && size > 0) {
            if(arr[index] == key) {
                arr[index] = -2;
                size--;
                return;
            }
            index = (index + i*i) % capacity;
            i++;
        }
        cout << "Key not found" << endl;
    }

    bool search(int key)
    {
        int index = hash(key);
        int i = 1;
        while(arr[index] != -1) {
            if(i > capacity) {
                break;
            }
            if(arr[index] == key) {
                return true;
            }
            index = (index + i*i) % capacity;
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

int main()
{
    HashTable ht(10);
    ht.insert(10);
    ht.insert(20);
    ht.insert(35);
    ht.insert(40);
    ht.insert(52);
    ht.display();
    ht.remove(10);
    ht.remove(15);
    ht.display();
    cout << ht.search(20) << endl;
    cout << ht.search(15) << endl;
    return 0;
}

// Time complexity: Insert, remove, search, display: O(n)
// Space complexity: O(n)