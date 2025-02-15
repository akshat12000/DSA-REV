// Find a node in a doubly linked list
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

Node* search(Node* head, int x)
{
    Node* curr = head;
    while (curr != NULL)
    {
        if (curr->data == x)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    if (search(head, 20) != NULL)
        cout << "Found\n";
    else
        cout << "Not Found\n";

    if (search(head, 40) != NULL)
        cout << "Found\n";
    else
        cout << "Not Found\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)