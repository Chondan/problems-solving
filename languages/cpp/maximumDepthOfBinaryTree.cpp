#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode *root);
};

int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20, new TreeNode(16), new TreeNode(7));

	int ans = solution.maxDepth(root);
	cout << "ans: " << ans << endl;
}

int Solution::maxDepth(TreeNode *root) {

	if (root == NULL) return 0;
	return 1 + max(this->maxDepth(root->left), this->maxDepth(root->right));
}
