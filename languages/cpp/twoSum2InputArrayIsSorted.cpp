#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void display(vector<T> input) {
	for (auto i: input) {
		cout << i << " ";
	}
	cout << endl;
}

class Solution {
public:
	// return the indices of the two numbers
    vector<int> twoSum(vector<int> &numbers, int target);
};

int main(void) {
	Solution solution;
	vector<int> input = {2, 7, 11, 15};
	int target = 9;
	vector<int> ans = solution.twoSum(input, target);
	cout << "ans: " << endl;
	display(ans);
}

vector<int> Solution::twoSum(vector<int> &numbers, int target) {

	vector<int> ans(2, -1);
	int l = 0, r = numbers.size() - 1;
	while (l < r) {
		int sum = numbers[l] + numbers[r];
		cout << sum << endl;
		if (sum < target) {
			l++;
		} else if (sum > target) {
			r--;
		} else {
			ans[0] = l + 1;
			ans[1] = r + 1;
			break;
		} 
		if (l < 0 || r >= numbers.size()) break;
	}
	return ans;

}