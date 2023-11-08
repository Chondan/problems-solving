#include <iostream>
#include "utils/util.h"
#include <set>
using namespace std;

class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
	/*
		Time complexity: O(n), Space complexity: O(1)

		The ideas are:
		1. Find lenght of linkedList A and B
		2. Cut x nodes from the head out to make it both equal length
			a. If (length(A) > length(B)) then cut head of A
			b. If (length(B) > length(A)) then cut head of B
		3. Loop through both A and B and compare both of current nodes
	*/
	ListNode* getIntersectionNodeWithBetterApproach(ListNode* headA, ListNode* headB);
	int getLength(ListNode* root);
};

int main(void) {
	Solution solution;

	ListNode* listNodeA1 = new ListNode(4);
	ListNode* listNodeA2 = new ListNode(1);

	ListNode* listNodeA3 = new ListNode(8);
	ListNode* listNodeA4 = new ListNode(4);
	ListNode* listNodeA5 = new ListNode(5);

	ListNode* listNodeB1 = new ListNode(5);
	ListNode* listNodeB2 = new ListNode(6);
	ListNode* listNodeB3 = new ListNode(1);

	// ListNodeA
	listNodeA1->next = listNodeA2;
	listNodeA2->next = listNodeA3;
	listNodeA3->next = listNodeA4;
	listNodeA4->next = listNodeA5;

	// ListNodeB
	listNodeB1->next = listNodeB2;
	listNodeB2->next = listNodeB3;
	listNodeB3->next = listNodeA3;

	ListNode* intersectionNode = solution.getIntersectionNode(listNodeA1, listNodeB1);
	cout << "intersectionNode: " << intersectionNode->val << endl;

	ListNode* intersectionNodeWithBetterApproach = solution.getIntersectionNodeWithBetterApproach(listNodeA1, listNodeB1);
	cout << "intersectionNodeWithBetterApproach: " << intersectionNodeWithBetterApproach->val << endl;
}

ListNode* Solution::getIntersectionNode(ListNode* headA, ListNode* headB) {
	set<ListNode*> memo;

	ListNode* cur = headA;
	while(cur->next != NULL) {
		memo.insert(cur);
		cur = cur->next;
	}
	memo.insert(cur);

	cur = headB;
	while(cur->next != NULL) {
		bool isIntersectionNode = memo.find(cur) != memo.end();
		if (isIntersectionNode) return cur;
		cur = cur->next;
	}
	bool isIntersectionNode = memo.find(cur) != memo.end();
	if (isIntersectionNode) return cur;

	return NULL;
}

ListNode* Solution::getIntersectionNodeWithBetterApproach(ListNode* headA, ListNode* headB) {
	int lenghtA = this->getLength(headA);
	int lengthB = this->getLength(headB);

	if (lenghtA > lengthB) {
		while (lenghtA > lengthB) {
			headA = headA->next;
			lenghtA -= 1;
		}

	} else {
		while (lengthB > lenghtA) {
			headB = headB->next;
			lengthB -= 1;
		}

	}

	while (headA != NULL and headB != NULL) {
		if (headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}

	return NULL;
}

int Solution::getLength(ListNode* root) {
	int length = 0;

	while (root != NULL) {
		length += 1;
		root = root->next;
	}

	return length;
}

