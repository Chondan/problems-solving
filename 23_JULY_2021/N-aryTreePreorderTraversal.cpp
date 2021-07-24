#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> preorder(Node *root);
    void helper(Node *root, vector<int> &memo);
};

int main(void) {
    Solution solution;
    Node *root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    vector<int> ans = solution.preorder(root);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::preorder(Node *root) {
    vector<int> memo;
    helper(root, memo);

    return memo;
}

void Solution::helper(Node *root, vector<int> &memo) {
    if (!root) return;

    memo.push_back(root->val);

    if (!(root->children).empty()) {
        for (auto child: root->children) {
            this->helper(child, memo);
        }
    }
}