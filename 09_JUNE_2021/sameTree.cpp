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
    bool isSameTree(TreeNode *p, TreeNode *q);
    void helper(TreeNode *p, TreeNode *q, bool &isSame);
};

int main(void) {
	Solution solution;

	TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(1));
	TreeNode *root2 = new TreeNode(1, new TreeNode(2), new TreeNode(1));

	bool ans = solution.isSameTree(root1, root2);
	cout << "ans: " << ans << endl;

}

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
	bool ans = true;
	this->helper(p, q, ans);
	return ans;
}

void Solution::helper(TreeNode *p, TreeNode *q, bool &isSame) {

	if (p == NULL && q == NULL) return;
	if (p == NULL || q == NULL) {
		isSame = false;
		return;
	}
	if (p->val != q->val) {
		isSame = false;
		return;
	}	

	this->helper(p->left, q->left, isSame);
	this->helper(p->right, q->right, isSame);
}