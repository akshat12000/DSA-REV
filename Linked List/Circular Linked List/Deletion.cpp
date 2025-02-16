// Deletion in Circular Linked List at a given position
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

Node* deleteAtPos (Node* head, int pos)
{
    int len = length(head);
    if(pos > len || pos < 1)
        return head;

    if(head == NULL)
        return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    if(pos == 1)
    {
        Node* temp = head->next;
        head->data = temp->data;
        head->next = temp->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for(int i=1; i<pos-1; i++)
        curr = curr->next;
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

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
    head = deleteAtPos(head, 2);
    printList(head);
    cout<<endl;
    head = deleteAtPos(head, 1);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)