// Node at a given index in linked list
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

int GetNth(Node *head, int index) {
    if(head==NULL)
        return -1;
    Node* curr = head;
    int pos = 1;
    while(curr && pos!=index)
    {
        curr = curr->next;
        pos++;
    }
    if(curr==NULL)
        return -1;
    return curr->data;
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printList(head);
    cout << GetNth(head, 4) << "\n";
    cout << GetNth(head, 6) << "\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)