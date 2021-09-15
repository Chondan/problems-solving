#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot);
    bool hasSameStructure(TreeNode *root1, TreeNode *root2);
};

int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2, new TreeNode(0), NULL)), new TreeNode(5));
	TreeNode *subRoot = new TreeNode(4, new TreeNode(1), new TreeNode(2));
	bool ans = solution.isSubtree(root, subRoot);
	cout << "ans: " << ans << endl;
}

bool Solution::isSubtree(TreeNode *root, TreeNode *subRoot) {
	if (!root) return false;
	if (this->hasSameStructure(root, subRoot)) return true;

	return this->isSubtree(root->left, subRoot) || this->isSubtree(root->right, subRoot);
}

bool Solution::hasSameStructure(TreeNode *root1, TreeNode *root2) {
	if (!root1 && !root2) return true;
	if (!root1 || !root2) return false;
	if (root1->val != root2->val) return false;

	return this->hasSameStructure(root1->left, root2->left) && this->hasSameStructure(root1->right, root2->right);
}