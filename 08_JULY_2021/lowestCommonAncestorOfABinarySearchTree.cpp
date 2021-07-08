#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

int main(void) {
    Solution solution;

    TreeNode *root = new TreeNode(6);
    TreeNode *left = new TreeNode(2, new TreeNode(0), new TreeNode(4, new TreeNode(3), new TreeNode(5)));
    TreeNode *right = new TreeNode(8, new TreeNode(7), new TreeNode(9));
    root->left = left;
    root->right = right;

    TreeNode *ans = solution.lowestCommonAncestor(root, left, right);
    cout << "val: " << ans->val << endl;
}

TreeNode* Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    int low = min(p->val, q->val);
    int high = max(p->val, q->val);

    if (root->val <= low && root->val >= high) return root;

    if (root->val > high) return this->lowestCommonAncestor(root->left, p, q);
    if (root->val < low) return this->lowestCommonAncestor(root->right, p, q);

    return root;
}
