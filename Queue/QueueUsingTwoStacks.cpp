// Implement a Queue using two stacks s1 and s2.
#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        if(output.empty() && input.empty())
            return -1;
        if(output.empty())
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int x = output.top();
        output.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}

// Time Complexity: O(1) for enqueue operation and O(n) for dequeue operation.
// Space Complexity: O(n) for stack space.