#include <iostream>
#include <unordered_map>
#include "./utils/util.h"
using namespace std;

class Solution {
private:
    unordered_map<int, bool> memo;
public:
    bool findTarget(TreeNode *root, int k);
    void helper(TreeNode *root, int k, bool &ans);
};

int main(void) {
    Solution solution;
    TreeNode *left = new TreeNode(3, new TreeNode(2), new TreeNode(4));
    TreeNode *right = new TreeNode(6, NULL, new TreeNode(7));
    TreeNode *root = new TreeNode(5, left, right);
    int k = 9;
    bool ans = solution.findTarget(root, k);
    cout << "ans: " << ans << endl;
}

bool Solution::findTarget(TreeNode *root, int k) {  
    bool ans = false;
    this->helper(root, k, ans);
    return ans;
}

void Solution::helper(TreeNode *root, int k, bool &ans) {
    if (!root || ans) return;

    this->helper(root->left, k, ans);

    // Check value here
    int val = root->val;
    int remaining = k - val;
    if (memo[val]) {
        ans = true;
    } else {
        this->memo[remaining] = true;
    }

    this->helper(root->right, k, ans);
}