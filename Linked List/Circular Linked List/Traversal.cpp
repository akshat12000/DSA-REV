// Traversal of Circular Linked List
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

void printList(Node *head)
{
    if(head==NULL) return;
    Node *curr=head;
    do
    {
        cout<<(curr->data)<<" ";
        curr=curr->next;
    } while (curr!=head);    
}

int main()
{
    Node *head=new Node(10);
    head->next=new Node(5);
    head->next->next=new Node(20);
    head->next->next->next=new Node(15);
    head->next->next->next->next=head;
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)