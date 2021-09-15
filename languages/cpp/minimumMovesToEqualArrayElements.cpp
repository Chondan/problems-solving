#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int> &nums);
    int minMoves2(vector<int> &nums);
};

int main(void) {
	Solution solution;
	vector<int> input = {1, 2, 3};
	vector<int> input2 = {1, 1, 1};
	vector<int> input3 = {1, 3, 5, 7};
	vector<int> input4 = {1, 3};
	int ans  = solution.minMoves2(input);
	cout << "ans: " << ans << endl;
}

// Time exceed
int Solution::minMoves(vector<int> &nums) {
	int n = nums.size();
	sort(nums.begin(), nums.end());

	if (n == 2) return nums[1] - nums[0];
	if (nums[0] == nums[n - 1]) return 0;
	if (nums[0] == nums[n - 2]) return nums[n - 1] - nums[0];

	for (int i = 0; i < n - 1; i++) {
		nums[i]++;
	}
	return 1 + this->minMoves(nums);
}

// Better solution
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/1217713/C%2B%2B-python-Just-Some-Clever-Math-O(n)-or-O(1)
int Solution::minMoves2(vector<int> &nums) {
	/* 
	1. Sort array
	2. Take adjacent difference
	3. Compute presum
	4. Take sum of the resultant array

	sort: [a, b, c, d, e, f] 
	adjacent diff: [b-a, c-b, d-c, e-d, f-e]
	presum: [b-a, c-a, d-a, e-a, f-a]
	ans = sum(presum) = (b+c+d+e+f) - 5a
	ans = (a+b+c+d+e+f) - 6a
	ans = totalSum - 6a = totalSum - 6*minimum
	*/
	int n = nums.size();
	int m = *min_element(nums.begin(), nums.end());
	int sum = accumulate(nums.begin(), nums.end(), 0);
	return sum - n*m;
}