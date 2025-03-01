// Implement a Stack using Arrays
#include <bits/stdc++.h>
using namespace std;

class MyStack {
  private:
    int arr[1000];
    int top;

  public:
    MyStack() { top = -1; }

    int pop();
    void push(int);
    bool isEmpty();
    bool isFull();
    int topElement();
};

void MyStack ::push(int x) {
    if(top+1>=1000)
        return;
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top<0)
        return -1;
    int x = arr[top];
    top--;
    return x;
}

int MyStack ::topElement() {
    if(top<0)
        return -1;
    return arr[top];
}

bool MyStack ::isEmpty() {
    return top == -1;
}

bool MyStack ::isFull() {
    return top == 999;
}

int main() {
    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.topElement() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}

// Time Complexity: O(1) for all operations
// Space Complexity: O(N) for N elements in the stack