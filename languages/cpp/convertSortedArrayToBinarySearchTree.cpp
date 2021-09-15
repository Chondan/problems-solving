#include <vector>
#include <iostream>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &nums);
    TreeNode* createBST(int start, int end, vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {-10, -3, 0, 5, 9};
    vector<int> nums2 = {0, 1, 2, 3, 4, 5};
    TreeNode *ans = solution.sortedArrayToBST(nums2);
    cout << "ans:" << endl;
    indorder(ans);
}

TreeNode* Solution::sortedArrayToBST(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    return this->createBST(start, end, nums);
}

TreeNode* Solution::createBST(int start, int end, vector<int> &nums) {
    if (start > end) return NULL;

    int middle = (start + end) / 2;
    TreeNode *root = new TreeNode(nums[middle]);
    root->left = this->createBST(start, middle - 1, nums);
    root->right = this->createBST(middle + 1, end, nums);
    return root;
}