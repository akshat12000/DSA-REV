// Find the duplicate elements in the sorted linked list and remove them.
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

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Function to remove duplicates from sorted linked list.
Node* removeDuplicates(Node* head) {
    if(head==NULL||head->next==NULL)
        return head;
    Node*prev=NULL,*curr=head;
    Node*headToReturn = head;
    while(curr!=NULL)
    {
        // skip the same elements
        while(curr && curr->next && curr->data==curr->next->data){
            Node* temp = curr;
            curr=curr->next;
            delete temp;
        }
        if(prev==NULL){
            headToReturn=curr;
        }else{
            prev->next=curr;
        }
        prev=curr;
        if(curr)
            curr = curr->next;
    }
    return headToReturn;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    cout << "Initial Linked List: ";
    print(head);
    cout << "\n";

    Node* result = removeDuplicates(head);
    cout << "Final Linked List: ";
    print(result);
    cout << "\n";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)