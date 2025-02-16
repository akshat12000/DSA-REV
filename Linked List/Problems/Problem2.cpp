// Find the kth node from the end of the linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

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

// Function to find the data of kth node from the end of a linked list.
int getKthFromLast(Node *head, int k) {
    if(head == NULL)
        return -1;
    Node*slow = head;
    Node*fast = head;
    while(k-- && fast){
        fast=fast->next;
    }
    // cout<<k<<" "<<!fast<<"\n";
    if(k>=0 && !fast)
        return -1;
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    printList(head);
    cout << getKthFromLast(head, 4) << "\n";
    cout << getKthFromLast(head, 6) << "\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)