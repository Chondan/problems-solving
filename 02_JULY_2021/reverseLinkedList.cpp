#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    static void display(ListNode *head);
};

class Solution {
public:
    ListNode* reverseList(ListNode *head);
};

int main(void) {
    Solution solution;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *ans = solution.reverseList(head);
    ListNode::display(ans);
}

ListNode* Solution::reverseList(ListNode *head) {

    ListNode *cur = head;
    ListNode *prev = NULL;

    while (cur) {
        ListNode *temp = cur->next;
        cur->next = prev;
        if (!temp) break; 
        prev  = cur;
        cur = temp; 
    }
    return cur;
}

void ListNode::display(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}