#include <iostream>
#include "utils/util.h"
using namespace std;

/* 
	The average case time complexity will be O(log n) and the worst case would be O(n).

	Ref: https://stackoverflow.com/questions/30116387/time-complexity-of-bst
*/
class Solution {
public:
	int countNodes(TreeNode* root);
};

int main(void) {
	Solution solution;

	TreeNode* treeNode1 = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), NULL));
	int ans1 = solution.countNodes(treeNode1);
	cout << "ans1: " << ans1 << endl;

	TreeNode* treeNode2 = new TreeNode(1);
	int ans2 = solution.countNodes(treeNode2);
	cout << "ans2: " << ans2 << endl;
}

int Solution::countNodes(TreeNode* root) {
	if (root == NULL) return 0;

	return 1 + this->countNodes(root->left) + this->countNodes(root->right);
}