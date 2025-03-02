// Implement a Queue using Array
#include <bits/stdc++.h>
using namespace std;

struct QueueNode {
    int data;
    QueueNode *next;
};

class MyQueue {
  private:
    int arr[100005];
    int front;
    int rear;

  public:
    MyQueue() {
        front = 0;
        rear = 0;
    }

    void push(int);
    int pop();
    int getFront();
    bool isEmpty();
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.getFront() << endl;
    q.pop();
    cout << q.getFront() << endl;
    q.pop();
    cout << q.getFront() << endl;
    q.pop();
    cout << q.isEmpty() << endl;
    return 0;
}

// Function to push an element x in a queue.
void MyQueue ::push(int x) {
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop() {
    if(front == rear) return -1;
    int ele = arr[front];
    arr[front++]=-1;
    return ele;
}

// Function to return front element of the queue.
int MyQueue ::getFront() {
    if(front == rear) return -1;
    return arr[front];
}

// Function to check if queue is empty.
bool MyQueue ::isEmpty() {
    return front == rear;
}

// Time Complexity: O(1) for all operations.
// Space Complexity: O(N) for the array.
