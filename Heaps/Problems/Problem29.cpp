// Merge K sorted linked lists and return it as one sorted list.
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

struct CompareNode {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->data > b->data;
    }
};

void push(ListNode*& head, int data) {
    ListNode* newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void PrintList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* mergeLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> minHeap;
    
    for (auto list : lists)
        if (list) minHeap.push(list);

    ListNode dummy(0), *tail = &dummy;
    
    while (!minHeap.empty()) {
        ListNode* node = minHeap.top();
        minHeap.pop();
        tail->next = node;
        tail = tail->next;

        if (node->next) minHeap.push(node->next);
    }

    return dummy.next;
}

ListNode*  externalSort(vector<ListNode*>& lists) {
    ListNode* sortedList = mergeLists(lists);
     return sortedList;
}

int main() {
    int N = 3;
    vector<ListNode*> lists(N, nullptr);

    push(lists[0], 50);
    push(lists[0], 40);
    push(lists[0], 30);

    push(lists[1], 45);
    push(lists[1], 35);

    push(lists[2], 100);
    push(lists[2], 80);
    push(lists[2], 70);
    push(lists[2], 60);
    push(lists[2], 10);

    ListNode* ans = externalSort(lists);
    PrintList(ans);
    return 0;
}

// Time Complexity: O(N*log(K)), where N is the total number of elements in all the lists and K is the number of lists.
// Space Complexity: O(K), where K is the number of lists.