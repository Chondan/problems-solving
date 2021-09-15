#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

class Solution {
public:
    ListNode* removeElements(ListNode *head, int val);
	static void display(ListNode *head);
};

int main(void) {
	Solution solution;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next = new ListNode(6);

	ListNode *head2 = new ListNode(7, new ListNode(7, new ListNode(7, new ListNode(7))));

	int val = 6;
	ListNode *ans = solution.removeElements(head, val);
	Solution::display(ans);
}

ListNode* Solution::removeElements(ListNode *head, int val) {
	ListNode *cur = head;

	while (cur && cur->val == val) {
		head = cur->next;
		cur = head;
	}

	while (cur && cur->next) {
		if (cur->next->val == val) {
			cur->next = cur->next->next;
			continue;
		}

		cur = cur->next;
	}

	return head;
}

void Solution::display(ListNode *head) {
	ListNode *cur = head;

	while (cur) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}