// Insertion in a Circular Linked List at a given position
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

Node* insertAtPos(Node* head, int pos, int data)
{
    int len = length(head);
    if(pos > len+1 || pos < 1)
        return head;
        
    Node* temp = new Node(data);
    if(head == NULL)
    {
        temp->next = temp;
        head = temp;
        return head;
    }
    if(pos == 1)
    {
        temp->next = head->next;
        head->next = temp;
        swap(head->data, temp->data);
        return head;
    }
    Node* curr = head;
    for(int i=1; i<pos-1; i++)
        curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
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
    head = insertAtPos(head, 1, 25);
    printList(head);
    cout<<endl;
    head = insertAtPos(head, 3, 30);
    printList(head);
    cout<<endl;
    head = insertAtPos(head, 7, 35);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)