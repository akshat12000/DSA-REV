// Find the length of the loop in the linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

// Function to find the length of a loop in the linked list.
int countNodesinLoop(Node *head) {
    if(head == NULL || head->next == NULL)
        return 0;
    Node*fast=head->next,*slow=head;
    while(fast && fast->next)
    {
        if(fast==slow)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast==NULL || fast->next==NULL)
        return 0;
    int count = 0;
    do
    {
        slow = slow->next;
        count++;
    }while(fast!=slow);
    return count;
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout << "Before adding loop\n";
    cout << countNodesinLoop(head) << "\n";
    
    // Creating a loop for testing
    cout << "After adding loop\n"; 
    loopHere(head, head->next->next, 1);
    cout << countNodesinLoop(head) << "\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)