// C++ Program for converting singly linked list
// into circular linked list.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function that convert singly linked list
// into circular linked list.
Node *circular(Node *head) {

    // declare a node variable curr and
    // assign head node into curr node.
    Node *curr = head;

    // check that while curr->next is not equal
    // to NULL then curr points to next node.
    while (curr->next != nullptr)
        curr = curr->next;

    // assign curr->next to the head node.
    curr->next = head;

    return head;
}

void printList(Node *head) {
    Node *curr = head;

    do {
        cout << curr->data << " ";
        curr = curr->next;

    } while (curr != head);
    cout << endl;
}

int main() {

    // create a hard coded list
    // 10->12->14->16
    Node *head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(14);
    head->next->next->next = new Node(16);

    head = circular(head);

    printList(head);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)