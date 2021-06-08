#include <vector>
#include <iostream>
using namespace std;

void displayVector(vector<vector<int>> input) {
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[i].size(); j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int> numbers, int target);
};

int main(void) {
	Solution solution;
	vector<int> input = {5, 4, 3, 2, 1};
	int target = 5;
	vector<vector<int>> ans = solution.threeSum(input, target);
	displayVector(ans);
}

vector<vector<int>> Solution::threeSum(vector<int> numbers, int target) {
	vector<vector<int>> ans;
	vector<int> inner;

	for (int i = 0; i < numbers.size() - 2; i++) {
		for (int j = i + 1; j < numbers.size() - 1; j++) {
			for (int k = j + 1; k < numbers.size(); k++) {
				if (i + j + k == target) {
					inner = {numbers[i], numbers[j], numbers[k]};
					ans.push_back(inner);
				}	
			}
		}	
	}
	return ans;
}