#include <iostream>
#include <stack>
#include <set>
#include <string>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    string tree2str(TreeNode *root);
    string helper(TreeNode * root, string &str);
    string tree2str2(TreeNode *root);
    string tree2str3(TreeNode *root);
};

int main(void) {
    Solution solution;
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL), new TreeNode(3));
    string ans = solution.tree2str3(root);
    cout << "ans: " << ans << endl;
}

// --- Approach 1: Recursion ---
string Solution::tree2str(TreeNode *root) {
    string ans = "";
    return this->helper(root, ans);
}

string Solution::helper(TreeNode *root, string &str) {
    if (!root) return str;

    str += to_string(root->val);

    if (root->left) {
        str += "(";
        str = this->helper(root->left, str);
        str += ")";
    } 

    if (root->right) {
        if (!root->left) {
            str += "()";
        }
        str += "(";
        str = this->helper(root->right, str);
        str += ")";
    }

    return str;
}

// --- Approach 2: Recursion ---
string Solution::tree2str2(TreeNode *root) {
    if (!root) return "";
    if (!root->left && !root->right) return to_string(root->val);
    if (root->left && !root->right) return to_string(root->val) + "(" + this->tree2str2(root->left) + ")"; 

    return to_string(root->val) + "(" + this->tree2str2(root->left) + ")" + "(" + this->tree2str2(root->right) + ")";
}

// --- Approach 3: Iterative Method Using Stack ---
string Solution::tree2str3(TreeNode *root) {

    stack<TreeNode *> s;
    set<TreeNode *> visited;
    s.push(root);

    string ans = "";
    while (!s.empty()) {
        TreeNode *top = s.top();

        bool alreadyVisited = visited.find(top) != visited.end();
        if (alreadyVisited) {
            ans += ")";
            s.pop();
        } else {
            ans += "(" + to_string(top->val);
            visited.insert(top);

            if (top->right) s.push(top->right);
            if (top->left) s.push(top->left);
        }
    }
    return ans;
}
