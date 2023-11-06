#include <iostream>
#include "utils/util.h"
using namespace std;

/* 
Given a binary tree, determine if it is height-balanced.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/
class Solution {
public:
	bool isBalanced(TreeNode* root);
	int getHeight(TreeNode* root);
};

int main(void) {
	Solution solution;

	TreeNode* treeNode1 = new TreeNode(
		3, 
		new TreeNode(9), 
		new TreeNode(20, new TreeNode(15), new TreeNode(7))
	);
	bool ans1 = solution.isBalanced(treeNode1);
	cout << "ans1: " << ans1 << endl;

	TreeNode* treeNode2 = new TreeNode(
		1, 
		new TreeNode(2, new TreeNode(3, new TreeNode(4), NULL), NULL), 
		new TreeNode(2, NULL, new TreeNode(3, NULL, new TreeNode(4)))
	);
	bool ans2 = solution.isBalanced(treeNode2);
	cout << "ans2: " << ans2 << endl;


}

// Traverse every node to check balance
bool Solution::isBalanced(TreeNode* root) {
    if (root == NULL) return true;

    if (this->getHeight(root) == -1) return false;

    return true;
}

int Solution::getHeight(TreeNode* root) {
	if (root == NULL) return 0;

	int leftHeight = this->getHeight(root->left);
	int rightHeight = this->getHeight(root->right);

	// In case of left subtree or right subtree unbalanced or their heights differ by more than '1', return '-1'
	if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) return -1;

	return 1 + max(leftHeight, rightHeight);
}