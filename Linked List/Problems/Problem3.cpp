// Delete every Kth node
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(NULL) {}
};

void append(Node*& head, Node*& tail, int new_data) {
    Node* new_node = new Node(new_data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

/* Function to get the middle of the linked list*/
/*K will always be in range */
Node* deleteK(Node* head, int k) {
    if (head == NULL)
        return head;
    int pos = 1;
    Node* curr = head;
    while(curr!=NULL)
    {
        if(pos%k==0){
            curr->data = 0;
        }
        pos++;
        curr = curr->next;
    }
    Node*prev=NULL;
    curr = head;
    while(curr!=NULL)
    {
        if(curr->data==0)
        {
            if(prev){
                Node* temp = curr;
                curr = curr->next;
                prev->next = temp->next;
                delete temp;
            }else{
                Node* temp = curr;
                curr = curr->next;
                head = curr;
                delete temp;
            }
        }else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    append(head, tail, 1);
    append(head, tail, 2);
    append(head, tail, 3);
    append(head, tail, 4);
    append(head, tail, 5);
    append(head, tail, 6);
    append(head, tail, 7);
    append(head, tail, 8);
    append(head, tail, 9);
    append(head, tail, 10);
    append(head, tail, 11);
    append(head, tail, 12);

    head = deleteK(head, 3);
    Node* curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)