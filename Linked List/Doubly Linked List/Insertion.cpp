// Insertion in Doubly Linked List at a given position
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

Node * InsertAtPos(Node * head, int pos, int data) {
    Node * temp = new Node(data);
    if(pos == 1) {
        temp->next = head;
        if(head != NULL) {
            head->prev = temp;
        }
        return temp;
    }
    Node * curr = head;
    for(int i = 1; i <= pos - 2 && curr != NULL; i++) {
        curr = curr->next;
    }
    if(curr == NULL) {
        return head;
    }
    temp->next = curr->next;
    if(curr->next != NULL) {
        curr->next->prev = temp;
    }
    curr->next = temp;
    temp->prev = curr;
    return head;
}

void PrintList(Node * head) {
    Node * curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main() {
    Node * head = new Node(10);
    Node * temp1 = new Node(20);
    Node * temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = InsertAtPos(head, 2, 15);
    PrintList(head);
    cout << endl;
    head = InsertAtPos(head, 1, 5);
    PrintList(head);
    cout << endl;
    head = InsertAtPos(head, 6, 25);
    PrintList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)