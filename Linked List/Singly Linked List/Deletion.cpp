// Deletion in a Singly Linked List at a given position
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

Node* deleteNode(Node* head, int pos)
{
    if(head == NULL)
        return NULL;
    if(pos == 1)
    {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* curr = head;
    for(int i=1; i<=pos-2 && curr!=NULL; i++)
    {
        curr = curr->next;
    }
    if(curr==NULL || curr->next==NULL)
        return head;
    Node* temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

void printList(Node* head)
{
    Node* curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printList(head);
    cout<<endl;
    head = deleteNode(head, 2);
    printList(head);
    cout<<endl;
    head = deleteNode(head, 1);
    printList(head);
    cout<<endl;
    head = deleteNode(head, 2);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)