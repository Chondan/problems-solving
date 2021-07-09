#ifndef UTIL
#define UTIL

#include <vector>
#include <iostream>
using namespace std;

// ---- METHODS DEFINITION ----
template <typename T>
void displayVector(vector<T> input);
vector<string> split(string s, string delim);

// Binary Tree
struct TreeNode;
void indorder(TreeNode *root);

// ---- METHODS IMPLEMENTATION ----
template <typename T>
void displayVector(vector<T> input) {
    for (auto i: input) {
        cout << i << " ";
    }
    cout << endl;
}

vector<string> split(string s, string delim) {
    vector<string> result;
    int pos = s.find(delim);
    while (pos != -1) {
       string token = s.substr(0, pos);
       result.push_back(token);
       s = s.substr(pos + 1);
       pos = s.find(delim);
    }
    result.push_back(s);
    return result;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void indorder(TreeNode *root) {
    if (!root) return;

    indorder(root->left);
    cout << root->val << " ";
    indorder(root->right);
}

#endif
