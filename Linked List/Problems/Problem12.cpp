// Reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Function to reverse a doubly linked list
DLLNode* reverseDLL(DLLNode* head) {
    if(head == NULL)
        return head;
    DLLNode* prevN = NULL, *curr = head, *temp = curr->next;
    while(curr!=NULL)
    {
        curr->next = curr->prev;
        curr->prev = temp;   
        prevN = curr;
        curr = temp;
        if(temp)
            temp = temp->next;
    }
    return prevN;
}

int main() {
    DLLNode *head = new DLLNode(10);
    DLLNode *tail = head;
    push(&tail, 20);
    push(&tail, 30);
    push(&tail, 40);

    cout << "Original Doubly linked list:" << endl;
    printList(head);
    cout<<endl;

    head = reverseDLL(head);
    cout << "\nReversed Doubly linked list:" << endl;
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)