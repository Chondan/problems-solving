#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void display(vector<vector<T>> input) {
	for (auto outer: input) {
		for (auto inner: outer) {
			cout << inner << " ";
		}
		cout << endl;
	}
}

class Solution {
public:
	vector<vector<int>> generate(int numRows);
};

int main(void) {
	Solution solution;
	vector<vector<int>> ans = solution.generate(4);
	cout << "ans size: " << ans.size() << endl;
	display(ans);
}

vector<vector<int>> Solution::generate(int numRows) {
	vector<vector<int>> ans;
	for (int i = 0; i < numRows; i++) {
		vector<int> inner;
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				inner.push_back(1);
			} else {
				int num = ans[i - 1][j] + ans[i - 1][j - 1];
				inner.push_back(num);
			}
		}
		ans.push_back(inner);		
	}

	return ans;
}