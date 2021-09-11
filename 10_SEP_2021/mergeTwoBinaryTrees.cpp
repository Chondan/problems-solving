#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2);
};

int main(void) {
    Solution solution;
    TreeNode *root1 = new TreeNode(1, new TreeNode(3, new TreeNode(5), NULL), new TreeNode(2));    
    TreeNode *root2 = new TreeNode(2, new TreeNode(1, NULL, new TreeNode(4)), new TreeNode(3, NULL, new TreeNode(7)));
    TreeNode *ans = solution.mergeTrees(root1, root2);
    cout << "ans: " << endl;
    indorder(ans);
}

TreeNode* Solution::mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    root1->val += root2->val;
    root1->left = this->mergeTrees(root1->left, root2->left);
    root1->right = this->mergeTrees(root1->right, root2->right);

    return root1;
}

