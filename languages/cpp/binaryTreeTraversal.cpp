#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void display(vector<T> input) {
	for (auto i: input) {
		cout << i << " ";
	}
	cout << endl;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root);
    void helperPreorder(TreeNode *root, vector<int> &result);
    vector<int> postorderTraversal(TreeNode *root);
    void helperPostorder(TreeNode *root, vector<int> &result);
};

int main(void) {
	Solution solution;
	TreeNode *root = new TreeNode(1);
	root->left = NULL;
	root->right = new TreeNode(2, new TreeNode(3), NULL);
	vector<int> ansPre = solution.preorderTraversal(root);
	vector<int> ansPost = solution.postorderTraversal(root);
	cout << "Preorder" << endl;
	display<int>(ansPre);
	cout << "Postorder" << endl;
	display<int>(ansPost);
}

vector<int> Solution::preorderTraversal(TreeNode *root) {
	vector<int> result;
	this->helperPreorder(root, result);
	return result;
}

void Solution::helperPreorder(TreeNode *root, vector<int> &result) {
	// center, left, right
	if (root == NULL) return;

	result.push_back(root->val);
	this->helperPreorder(root->left, result);
	this->helperPreorder(root->right, result);
}

vector<int> Solution::postorderTraversal(TreeNode *root) {
	vector<int> result;
	this->helperPostorder(root, result);
	return result;
}

void Solution::helperPostorder(TreeNode *root, vector<int> &result) {
	// center, left, right
	if (root == NULL) return;

	this->helperPostorder(root->left, result);
	this->helperPostorder(root->right, result);
	result.push_back(root->val);
}
