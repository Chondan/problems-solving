#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    static void display(ListNode *head) {
        ListNode *cur = head;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        
        while (cur != NULL && cur->next != NULL) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return head;
    }
};

int main(void) {
   Solution solution;
   ListNode *input = new ListNode(1);
   input->next = new ListNode(1);
   input->next->next = new ListNode(1);
   input->next->next->next = new ListNode(2);
   input->next->next->next->next = new ListNode(3);
   input->next->next->next->next->next = new ListNode(3);

   ListNode *ans = solution.deleteDuplicates(input);
   ListNode::display(ans);
}