// Find if a given value is present in a Circular Linked List or not
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

bool searchNode(Node* head, int x)
{
    if(head == NULL)
        return false;
    Node* curr = head;
    do
    {
        if(curr->data == x)
            return true;
        curr = curr->next;
    } while(curr != head);
    return false;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    cout<<searchNode(head, 20);
    cout<<endl<<searchNode(head, 25);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)