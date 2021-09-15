#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    static void traverseInorder(TreeNode *root);
};

class Solution {
public:
    TreeNode* invertTree(TreeNode *root);
    void helper(TreeNode *root);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(4);
    TreeNode *left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode *right = new TreeNode(7, new TreeNode(6), new TreeNode(9));
    root->left = left;
    root->right = right;
    TreeNode *ans = solution.invertTree(root);
    TreeNode::traverseInorder(ans);
}

TreeNode* Solution::invertTree(TreeNode *root) {
    this->helper(root);
    return root;
}

void Solution::helper(TreeNode *root) {
    if (!root) return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    this->invertTree(root->left);
    this->invertTree(root->right);
}

void TreeNode::traverseInorder(TreeNode *root) {
    if (!root) return;
    TreeNode::traverseInorder(root->left);
    cout << root->val << endl;
    TreeNode::traverseInorder(root->right);
}