#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode *root, int val);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
    int val = 2;
    TreeNode *ans = solution.searchBST(root, val);
    cout << "nodeVal: " << ans->val << endl;
}

TreeNode* Solution::searchBST(TreeNode *root, int val) {
    TreeNode *cur = root;
    while (cur) {
        int nodeValue = cur->val;
        if (val > nodeValue) {
            cur = cur->right;
        } else if (val < nodeValue) {
            cur = cur->left;
        } else {
            return cur;
        }
    }

    return NULL;
}