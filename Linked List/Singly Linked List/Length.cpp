// Find Length of a Linked List (Iterative)
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

int main()
{
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    int len=0;
    Node* curr=head;
    while(curr!=NULL)
    {
        len++;
        curr=curr->next;
    }
    cout<<len;
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)