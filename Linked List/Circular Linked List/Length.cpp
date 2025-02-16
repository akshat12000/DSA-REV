// Length of a Circular Linked List
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int length(Node* head)
{
    if(head == NULL)
        return 0;
    int len = 0;
    Node* curr = head;
    do
    {
        len++;
        curr = curr->next;
    } while(curr != head);
    return len;
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = head;
    cout<<length(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)