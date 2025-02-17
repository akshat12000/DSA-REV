// Deletion and Reverse in Circular Linked List
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}

// Function to reverse a circular linked list
Node* reverse(Node* head) {
    if (head == NULL||head->next == head)
        return head;
    Node *prev=NULL,*curr=head;
    Node* temp = curr->next;
    do
    {
        prev = curr;
        curr = temp;
        temp = curr->next;
        curr->next = prev;
        
    }while(curr!=head);
    return prev;
}

// Function to delete a node from the circular linked list
Node* deleteNode(Node* head, int key) {
    if (head == NULL)
        return head;
    Node* curr = head;
    Node* prev = head;
    if(head->data == key)
    {
        do{
            prev = prev->next;
        }while(prev->next!=head);
        Node* temp = head;
        prev->next = head->next;
        head = head->next;
        delete(temp);
    }else{
        do{
            if(curr->data == key)
            {
                Node* temp = curr;
                prev->next = curr->next;
                delete(temp);
                break;
            }
            prev = curr;
            curr = curr->next;
        }while(curr!=head);
    }
    return head;
}

int main() {
    struct Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    
    cout << "Original List:\n";
    printList(head);
    cout<<"\n";

    head = deleteNode(head, 3);
    cout << "List after deletion of 3:\n";
    printList(head);
    cout<<"\n";

    head = reverse(head);
    cout << "List after reversal:\n";
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)