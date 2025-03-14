// Merge K sorted linked lists
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

struct myComp{
    bool operator()(Node*&l1,Node*&l2){
        return l1->data>l2->data;
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    Node*head=NULL;
    priority_queue<Node*,vector<Node*>,myComp>pq;
    for(auto l:arr){
        if(l)
            pq.push(l);
    }
    Node*curr=head;
    while(!pq.empty()){
        auto x= pq.top();
        pq.pop();
        if(curr){
            curr->next=x;
        }
        if(head==NULL){
            head=x;
        }
        curr=x;
        if(x->next!=NULL)
            pq.push(x->next);
    }
    return head;
}

int main() {

    int k = 3; // Number of linked lists
    int n = 4; // Number of elements in each list

    // an array of pointers storing the head nodes
    // of the linked lists
    vector<Node*> arr(k);
    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);

    // Merge all lists
    Node* head = mergeKLists(arr);
    printList(head);
    return 0;
}

// Time Complexity: O(NlogK)
// Space Complexity: O(K)