#include <unordered_map>
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

class Solution {
public:
    vector<int> getRow(int rowIndex);
};

int main(void) {
	Solution solution;
	int input = 29;
	vector<int> ans = solution.getRow(input);
	cout << "ans" << endl;
	display<int>(ans);
}

vector<int> Solution::getRow(int rowIndex) {
	vector<vector<int>> memo(rowIndex + 1);
	for (int i = 0; i <= rowIndex; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				memo[i].push_back(1);
			} else {
				memo[i].push_back(memo[i - 1][j] + memo[i - 1][j - 1]);
			}		
		}
	}
	return memo[rowIndex];
}