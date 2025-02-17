// C++ Program to delete a node at a specific position
// in Doubly Linked List
#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *prev;
    Node *next;

    Node(int d) {
        data = d;
        prev = nullptr;
          next = nullptr;
    }
};

// Function to delete a node at a specific position
// in the doubly linked list
Node* deleteNode(Node* head, int x) {
    if (head == NULL)
        return head;
    if (x==1)
    {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
    Node* curr = head;
    for(int i=1;i<x && curr!=NULL;i++){
        curr = curr->next;
    }
    if(curr){
        Node *prevN = curr->prev;
        if(prevN)
            prevN->next = curr->next;
        if(curr->next){
            curr->next->prev = prevN;
        }
        delete(curr);
    }
    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // Create a hardcoded doubly linked list:
    // 1 <-> 2 <-> 3
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = deleteNode(head, 2);
    printList(head);

    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)