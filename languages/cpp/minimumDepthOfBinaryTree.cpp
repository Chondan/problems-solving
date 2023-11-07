#include <iostream>
#include "utils/util.h"
using namespace std;

/* 
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node 
down to the nearest leaf node.

Ref: https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
*/
class Solution {
public:
	int minDepth(TreeNode* root);
};

int main(void) {
	Solution solution;

	TreeNode* treeNode1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
	int ans1 = solution.minDepth(treeNode1);
	cout << "ans1: " << ans1 << endl;

	TreeNode* treeNode2 = new TreeNode(2, NULL, new TreeNode(3, NULL, new TreeNode(4, NULL, new TreeNode(5, NULL, new TreeNode(6)))));
	int ans2 = solution.minDepth(treeNode2);
	cout << "ans2: " << ans2 << endl;
}

int Solution::minDepth(TreeNode* root) {
	if (root == NULL) return 0;

	if (root->left == NULL and root->right != NULL) {
		return 1 + this->minDepth(root->right);
	} else if (root->right == NULL and root->left != NULL) {
		return 1 + this->minDepth(root->left);
	} else {
		return 1 + min(this->minDepth(root->left), this->minDepth(root->right));
	}
}