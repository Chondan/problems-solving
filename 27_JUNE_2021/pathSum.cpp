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
    bool hasPathSum(TreeNode *root, int targetSum);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2)), NULL);
    root->right = new TreeNode(8, new TreeNode(13), new TreeNode(4, NULL, new TreeNode(1)));
    int targetSum = 22;
    bool ans = solution.hasPathSum(root, targetSum);
    cout << "ans: " << ans << endl;
}

bool Solution::hasPathSum(TreeNode *root, int targetSum) {
    if (root == NULL) return false;

    int remain = targetSum - root->val;
    // return true if the tree has a 'root-to-leaf' path such that
    // adding up all the values along the path equals 'targetSum'.
    if (remain == 0 && root->left == NULL && root->right == NULL) return true;

    return this->hasPathSum(root->left, remain) || this->hasPathSum(root->right, remain);
}