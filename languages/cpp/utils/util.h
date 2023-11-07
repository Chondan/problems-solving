#ifndef UTIL
#define UTIL

#include <vector>
#include <iostream>
using namespace std;

// ---- METHODS DEFINITION ----
template <typename T>
void displayVector(vector<T> input);

template <typename T>
void displayVectorVector(vector<vector<T>> input);

// String
vector<string> split(string s, string delim);

// Binary Tree
struct TreeNode;
void indorder(TreeNode *root);

// Char
int charToInt(char c);
char intToChar(int n);
bool isUpperCase(char c);

// Node
class Node;

// ---- METHODS IMPLEMENTATION ----
template <typename T>
void displayVector(vector<T> input) {
    for (auto i: input) {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void displayVectorVector(vector<vector<T>> input) {
    for (vector<T> outer: input) {
        for (T inner: outer) {
            cout << inner << " ";
        }
        cout << endl;
    }
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
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

void indorder(TreeNode *root) {
    if (!root) return;

    indorder(root->left);
    cout << root->val << " ";
    indorder(root->right);
}

int charToInt(char c) {
    return c - '0';
}

char intToChar(int n) {
    return n + '0';
}

bool isUpperCase(char c) {
    int ascii = c;
    if (ascii < 65 || ascii > 90) return false;
    return true;
}

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

#endif
