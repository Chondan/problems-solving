#include <queue>
#include <vector>
#include <iostream>
#include "utils/util.h"
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root);
};

int main(void) {
    Solution solution;
    // TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode *root = new TreeNode(3, new TreeNode(9, new TreeNode(15), new TreeNode(7)), new TreeNode(20));
    // TreeNode *root = new TreeNode(5, new TreeNode(2), new TreeNode(-3));
    vector<double> ans = solution.averageOfLevels(root);
    cout << "ans" << endl;
    displayVector<double>(ans);
}

vector<double> Solution::averageOfLevels(TreeNode *root) {
    vector<double> averageValues;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int currentSize = q.size(); 
        double currentSum = 0;
        for (int i = 1; i <= currentSize; i++) {
            TreeNode *front = q.front();
            q.pop();
            currentSum += front->val;

            if (front->left) {
                q.push(front->left);
            }

            if (front->right) {
                q.push(front->right);
            }
        }
        averageValues.push_back(currentSum / currentSize);
    }

    return averageValues;
}