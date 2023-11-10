#include <iostream>
#include "utils/util.h"
using namespace std;

/* 
	Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.
	Ref: https://leetcode.com/problems/palindrome-linked-list/
*/
class Solution {
public:
	bool isPalindrome(ListNode* head);
	/* 
		Solution: https://leetcode.com/problems/palindrome-linked-list/solutions/4215499/c-solution-beats-94-using-2-pointer-approach/
	*/
	bool isPalindromeWithBetterApproach(ListNode* head);
};

int main(void) {
	Solution solution;

	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(2);
	head1->next->next->next = new ListNode(1);
	bool ans1 = solution.isPalindrome(head1);
	cout << "ans1: " << ans1 << endl;

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(2);
	bool ans2 = solution.isPalindrome(head2);
	cout << "ans2: " << ans2 << endl;

	bool ansWithBetterApproach1 = solution.isPalindromeWithBetterApproach(head1);
	cout << "ansWithBetterApproach1: " << ansWithBetterApproach1 << endl;

	bool ansWithBetterApproach2 = solution.isPalindromeWithBetterApproach(head2);
	cout << "ansWithBetterApproach2: " << ansWithBetterApproach2 << endl;
}

bool Solution::isPalindrome(ListNode* head) {
	string numbers = "";
	int length = 0;
	while (head != NULL) {
		numbers += to_string(head->val);
		length += 1;
		head = head->next;
	}

	// Two pointers
	int left = 0, right = length - 1;
	while (left <= right) {
		if (numbers[left] != numbers[right]) return false;
		left += 1;
		right -= 1;
	}

	return true;
}

bool Solution::isPalindromeWithBetterApproach(ListNode* head) {
	// 1. Use floyd's algorithm to find middle node (slow and fast node)
	// 2. Create a new node to reverse the first half of the linked list

	ListNode* slow = head;
	ListNode* fast = head;
	ListNode* prev = NULL;

	while (fast != NULL and fast->next != NULL) {
		head = head->next;
		fast = fast->next->next;

		slow->next = prev;
		prev = slow;
		slow = head;
	}

	// If the lenght of linked list is "odd". Move the slow which is the middle to the next (No need to compare the middle value)
	if (fast != NULL) {
		slow = slow->next;
	}

	// Checking palindrome
	while(prev != NULL and slow != NULL) {
		if (prev->val != slow->val) return false;
		prev = prev->next;
		slow = slow->next;
	}

	return true;
}