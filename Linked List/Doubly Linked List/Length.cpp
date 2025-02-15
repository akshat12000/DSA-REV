// Length of a Doubly Linked List
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

int length(Node* head)
{
    int len = 0;
    Node* curr = head;
    while(curr != NULL)
    {
        len++;
        curr = curr->next;
    }
    return len;
}

int main()
{
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    cout << "Length of the Doubly Linked List: " << length(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)