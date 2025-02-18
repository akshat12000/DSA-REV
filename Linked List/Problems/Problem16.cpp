// C++ implementation of browser history
// using Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

class BrowserHistory {
public:
  
    // Pointer to the current URL
    Node* curr;

    // Constructor to initialize with the homepage
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    // Function to visit a new URL
    void visit(string url) {
        
        // Create a node for this visit
        Node* urlNode = new Node(url);

        // Set the previous node of the 
        // new node to current
        urlNode->prev = curr;

        // Update the next of the current 
        // node to the new node
        curr->next = urlNode;

        // Move the current pointer to the new node
        curr = urlNode;
    }

    // Function to move back by 'step' times
    string back(int step) {
        
        // Pointer to traverse backward
        Node* trav = curr;

        // Travel back `step` times if possible
        while (trav->prev != nullptr && step > 0) {
            trav = trav->prev;
            step--;
        }

        // Update current pointer after moving back
        curr = trav;

        return curr->data;
    }

    // Function to move forward by 'step' times
    string forward(int step) {
        
        // Pointer to traverse forward
        Node* trav = curr;

        // Travel forward `step` times if possible
        while (trav->next != nullptr && step > 0) {
            trav = trav->next;
            step--;
        }

        // Update current pointer after moving forward
        curr = trav;

        return curr->data;
    }
};

int main() {
    
    // Initialize with the homepage
    string homepage = "gfg.org";
    BrowserHistory obj(homepage);

    string url = "google.com";
    obj.visit(url);

    url = "facebook.com";
    obj.visit(url);

    url = "youtube.com";
    obj.visit(url);

    cout << obj.back(1) << endl;

    cout << obj.back(1) << endl;

    cout << obj.forward(1) << endl;

    obj.visit("linkedin.com");

    cout << obj.forward(2) << endl;

    cout << obj.back(2) << endl;

    cout << obj.back(7) << endl;

    return 0;
}

// Time Complexity: The visit function takes O(1) as it involves adding a node. The back and forward functions take O(min(steps, b)) and O(min(steps, f)) respectively, where b is the number of steps backward and f is the number of steps forward.
// Space Complexity: The doubly linked list uses O(n) space, where n is the total number of visited URLs. No additional auxiliary space is used beyond the linked list.