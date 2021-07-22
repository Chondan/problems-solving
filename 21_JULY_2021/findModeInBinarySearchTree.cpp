#include <unordered_map>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode *root);
    void helper(TreeNode *root, int &mostFrequently, unordered_map<int, vector<int>> &freq, unordered_map<int, int> &memo);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(5, new TreeNode(3, new TreeNode(1), new TreeNode(3)), new TreeNode(8, new TreeNode(8), new TreeNode(9)));
    vector<int> ans = solution.findMode(root);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::findMode(TreeNode *root) {
    int mostFrequently = 0;
    unordered_map<int, int> memo;
    unordered_map<int, vector<int>> freq;

    helper(root, mostFrequently, freq, memo);

    return freq[mostFrequently];
}

void Solution::helper(TreeNode *root, int &mostFrequently, unordered_map<int, vector<int>> &freq, unordered_map<int, int> &memo) {
    if (!root) return;

    this->helper(root->left, mostFrequently, freq, memo);

    int val = root->val;
    if (memo.find(val) == memo.end()) {
        memo[val] = 1;
    } else {
        memo[val]++;
    }
    freq[memo[val]].push_back(val);
    mostFrequently = max(mostFrequently, memo[val]);

    this->helper(root->right, mostFrequently, freq, memo);
}