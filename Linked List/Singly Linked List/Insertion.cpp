// Insertion in a Singly Linked List at a given position
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

Node* insert(Node* head, int pos, int data)
{
    Node* temp = new Node(data);
    if(pos==1){
        temp->next = head;
        return temp;
    }
    Node* curr = head;
    for(int i=1; i<=pos-2 && curr!=NULL; i++)
    {
        curr = curr->next;
    }
    if(curr==NULL)
        return head;
    temp->next = curr->next;
    curr->next = temp;
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
    head = insert(head, 2, 15);
    printList(head);
    cout<<endl;
    head = insert(head, 4, 25);
    printList(head);
    cout<<endl;
    head = insert(head,1,5);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Auxiliary Space: O(1)