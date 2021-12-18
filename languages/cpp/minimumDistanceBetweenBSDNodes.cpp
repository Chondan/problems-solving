#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <climits>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode *root);
    void generateNodeValues(TreeNode *root, vector<int> &nodeValues);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6));
    int ans = solution.minDiffInBST(root);
    cout << "ans: " << ans << endl;
}

int Solution::minDiffInBST(TreeNode *root) {
    vector<int> nodeValues;
    generateNodeValues(root, nodeValues);
    // To make sure that the number of elements is >= 3 to allow us to compare 2 contigous value (both left and right)
    nodeValues.push_back(INT_MAX);

    // Sort min to max and then compare 2 contiguous value
    int minDiff = INT_MAX - 1;
    sort(nodeValues.begin(), nodeValues.end());
    for (int i = 1; i < nodeValues.size() - 1; i++) {
	int contigousDiffLeft = abs(nodeValues[i - 1] - nodeValues[i]);
	int contigousDiffRight = abs(nodeValues[i] - nodeValues[i + 1]);
	int minContigousDiff = min(contigousDiffLeft, contigousDiffRight);
	minDiff = min(minDiff, minContigousDiff);	
    }

    return minDiff;
}

void Solution::generateNodeValues(TreeNode *root, vector<int> &nodeValues) {
    if (!root) return;

    this->generateNodeValues(root->left, nodeValues);

    int nodeValue = root->val; 
    nodeValues.push_back(nodeValue);

    this->generateNodeValues(root->right, nodeValues);
}
