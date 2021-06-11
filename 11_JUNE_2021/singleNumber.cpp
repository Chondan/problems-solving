#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums);
	int singleNumber2(vector<int> &nums);
};

int main(void) {
	Solution solution;
	vector<int> input = {4, 1, 2, 1, 2};
	int ans = solution.singleNumber3(input);
	cout << "ans: " << ans << endl;
}

int Solution::singleNumber(vector<int> &nums) {

	set<int> memo;
	for (auto num: nums) {
		if (memo.find(num) == memo.end()) {
			memo.insert(num);
		} else {
			memo.erase(num);
		}
	}

	int ans = *memo.begin();
	return ans;	
}

int Solution::singleNumber2(vector<int> &nums) {

	// XOR Operator 0 ^ 1 = 1, 0 ^ 0 = 0, 1 ^ 1 = 0
	int ans = 0;
	for (auto num: nums) {
		ans ^= num;
	}
	return ans;
}
