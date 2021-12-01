#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode *root);
    void helper(TreeNode *root, int &firstMinimumValue, int &secondMinimumValue, int &maxValue);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(2, new TreeNode(2), new TreeNode(5, new TreeNode(5), new TreeNode(7)));
    int ans = solution.findSecondMinimumValue(root);
    cout << "ans: " << ans << endl;
}

int Solution::findSecondMinimumValue(TreeNode *root) {
    int firstMinimumValue = INT_MAX, secondMinimumValue = INT_MAX, maxValue = INT_MIN;
    this->helper(root, firstMinimumValue, secondMinimumValue, maxValue);

    if (maxValue == INT_MAX) {
        if (firstMinimumValue == INT_MAX) return -1;
        else return secondMinimumValue;
    } else {
        return secondMinimumValue == INT_MAX ? -1 : secondMinimumValue;
    }
}

// Traversal
void Solution::helper(TreeNode *root, int &firstMinimumValue, int &secondMinimumValue, int &maxValue) {

    if (!root) return;
    this->helper(root->left, firstMinimumValue, secondMinimumValue, maxValue);

    int value = root->val;
    maxValue = max(maxValue, value);
    // cout << "value: " << value << ", firstMinimumValue: " << firstMinimumValue << ", secondMinimumValue: " << secondMinimumValue << endl;
    if (value < firstMinimumValue) {
        secondMinimumValue = firstMinimumValue;
        firstMinimumValue = value;
    }  else if (value > firstMinimumValue) {
        if (value < secondMinimumValue) {
            secondMinimumValue = value;
        }
    }

    this->helper(root->right, firstMinimumValue, secondMinimumValue, maxValue);
}