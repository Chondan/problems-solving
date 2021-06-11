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
    bool isSymmetric(TreeNode *root);
   	bool helper(TreeNode *l, TreeNode *r);
};

int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
	root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

	bool ans = solution.isSymmetric(root);
	cout << "ans: " << ans << endl;
}

bool Solution::isSymmetric(TreeNode *root) {
	return helper(root->left, root->right);
}

bool Solution::helper(TreeNode *l, TreeNode *r) {

	if (l == NULL and r == NULL) return true;
	if (l == NULL or r == NULL) return false;
	if (l->val != r->val) return false;

	return helper(l->left, r->right) and helper(l->right, r->left); 
}