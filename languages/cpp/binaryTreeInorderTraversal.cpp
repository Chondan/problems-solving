#include <vector>
#include <iostream>
using namespace std; 

template <typename T>
void displayVector(vector<T> input) {
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
    vector<int> inorderTraversal(TreeNode* root);
    void helper(TreeNode *root, vector<int> &v);
};

int main(void) {
	TreeNode *root = new TreeNode(1);
	root->left = NULL;
	root->right = new TreeNode(2, new TreeNode(3), NULL);

	TreeNode *root2;

	Solution solution;
	vector<int> ans = solution.inorderTraversal(root);

	displayVector<int>(ans);
}

vector<int> Solution::inorderTraversal(TreeNode* root) {
	vector<int> ans;
	this->helper(root, ans);
	return ans;
}

void Solution::helper(TreeNode *root, vector<int> &v) {
	if (root == NULL) return;
	this->helper(root->left, v);
	v.push_back(root->val);
	this->helper(root->right, v);	
}
