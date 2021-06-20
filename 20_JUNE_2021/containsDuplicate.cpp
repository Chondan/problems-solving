#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums);
	bool containsDuplicate2(vector<int> &nums);
};

int main(void) {
	Solution solution;
	vector<int> input = {1, 2, 3, 4};
	bool ans = solution.containsDuplicate2(input);
	cout << "ans: " << ans << endl;
}

bool Solution::containsDuplicate(vector<int> &nums) {

	unordered_map<int, bool> memo;
	for (int i = 0; i < nums.size(); i++) {
		if (memo.find(nums[i]) == memo.end()) {
			memo[nums[i]] = true;
		} else {
			return true;
		} 
	}

	return false;
}

bool Solution::containsDuplicate2(vector<int> &nums) {
	set<int> memo;
	for (int i = 0; i < nums.size(); i++) {
		if (memo.find(nums[i]) == memo.end()) {
			memo.insert(nums[i]);
		} else {
			return true;
		}
	}

	return false;
}