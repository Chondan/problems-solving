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
    // Smarte way
    int minDiffInBST2(TreeNode *root);
    void helper(TreeNode *root, int &minDiff, int &prevNodeValue);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(6));
    int ans = solution.minDiffInBST2(root);
    cout << "ans: " << ans << endl;
}

int Solution::minDiffInBST(TreeNode *root) {
    vector<int> nodeValues;
    generateNodeValues(root, nodeValues);
    // To make sure that the number of elements is >= 3 to allow us to compare 2 contigous value (both left and right)
    nodeValues.push_back(INT_MAX);

    // Compare 2 contiguous value
    int minDiff = INT_MAX - 1;
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

int Solution::minDiffInBST2(TreeNode *root) {
    int minDiff = INT_MAX, prevNodeValue = INT_MAX;
    helper(root, minDiff, prevNodeValue);
    return minDiff;
}

void Solution::helper(TreeNode *root, int &minDiff, int &prevNodeValue) {
    if (!root) return;

    this->helper(root->left, minDiff, prevNodeValue);

    // Compate parent with its child
    minDiff = min(minDiff, abs(prevNodeValue - root->val));
    prevNodeValue = root->val;

    this->helper(root->right, minDiff, prevNodeValue);
}
