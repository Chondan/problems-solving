#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root);
    void helper(TreeNode *root, bool isLeft, int &sum);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    int ans = solution.sumOfLeftLeaves(root);
    cout << "ans: " << ans << endl;
}

int Solution::sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    this->helper(root, false, sum);
    return sum;
}

void Solution::helper(TreeNode *root, bool isLeft, int &sum) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        if (isLeft) {
            sum += root->val;
        }
        return;
    }

    this->helper(root->left, true, sum);
    this->helper(root->right, false, sum);
}