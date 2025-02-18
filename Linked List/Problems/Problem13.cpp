// Pairwise swap a linked list
#include <bits/stdc++.h>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

/*
  Pairwise swap a linked list
  The input list will have at least one element
*/

Node* pairWiseSwap(Node* head) {
    if(head==NULL || head->next == NULL)
        return head;
    Node* headToReturn = head->next;
    Node*prev=head, *curr=head->next;
    Node*nPrev=NULL;
    Node*temp = curr->next;
    while(curr!=NULL)
    {
        curr->next = prev;
        prev->next = temp;
        if(nPrev)
            nPrev->next = curr;
        nPrev = prev;
        prev = temp;
        if(temp)
            curr = temp->next;
        else
            curr = NULL;
        if(curr)
            temp = curr->next;
    }
    return headToReturn;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    cout << "Original Linked List: ";
    printList(head);
    head = pairWiseSwap(head);
    cout << "Linked List after Pairwise Swapping: ";
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)