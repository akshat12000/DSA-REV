// Detect Loop in linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

// Function to check if the linked list has a loop.
bool detectLoop(Node* head) {
    if(head == NULL || head->next == NULL)
        return false;
    Node*fast=head->next,*slow=head;
    while(fast && fast->next)
    {
        if(fast==slow)
            return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    // Creating a loop for testing
    loopHere(head, head->next->next, 1);

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)