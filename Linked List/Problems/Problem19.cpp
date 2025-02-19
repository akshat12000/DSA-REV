// Intersection of two sorted Linked lists
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

Node* findIntersection(Node* head1, Node* head2) {
    if(head1==NULL||head2==NULL)
        return NULL;
    Node*head=NULL;
    Node* curr1=head1,*curr2=head2;
    Node*prev=NULL;
    Node*curr = NULL;
    while(curr1&&curr2)
    {
        while(curr1 && curr2 && curr1->data==curr2->data){
            Node* temp = new Node(curr1->data);
            if(!prev || prev->data!=curr1->data)
            {
                if(curr==NULL){
                    head = temp;
                    curr = head;
                }else{
                    curr->next = temp;
                    curr = curr->next;
                }
            }
            prev=curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }   
        if(curr1 && curr2){
            if(curr1->data<curr2->data)
                curr1 = curr1->next;
            else
                curr2 = curr2->next;
        }
    }
    return head;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(6);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);

    printList(findIntersection(head1, head2));
    return 0;
}

// Time Complexity: O(N+M)
// Space Complexity: O(N+M)