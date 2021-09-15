#include <vector>
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node *root);
};

int main(void) {
    Solution solution;
    Node *root = new Node(1, {new Node(3, {new Node(5), new Node(6)}), new Node(2), new Node(4)});
    int ans = solution.maxDepth(root);
    cout << "ans: " << ans << endl;
}

int Solution::maxDepth(Node *root) {
    if (root == NULL) return 0;
    
    int ans = 1;
    for (Node *child: root->children) {
        int depth = 1 + this->maxDepth(child);
        ans = max(ans, depth);
    }
    return ans;
}