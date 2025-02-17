// Count the number of times a given value occurs in a linked list
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

int count(struct Node* head, int key) {
    int count = 0;
    Node *curr = head;
    while(curr!=NULL)
    {
        if(curr->data == key)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    cout << count(head, 10) << endl;
    cout << count(head, 20) << endl;
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)