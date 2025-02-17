// Reverse a linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* reverseList(struct Node* head) {
    if(head == NULL)
        return head;
    Node *curr = head, *prev = NULL, *temp = head->next;
    while(curr!=NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = temp;
        if(temp!=NULL)
            temp=temp->next;
    }
    return prev;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = reverseList(head);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)