#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> postorder(Node *root);
    void helper(Node *root, vector<int> &memo);
};

int main(void) {
    Solution solution;
    Node *root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    vector<int> ans = solution.postorder(root);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::postorder(Node *root) {
    vector<int> memo;
    helper(root, memo);

    return memo;
}

void Solution::helper(Node *root, vector<int> &memo) {
    if (!root) return;

    if (!(root->children).empty()) {
        for (auto child: root->children) {
            this->helper(child, memo);
        }
    }

    memo.push_back(root->val);
}