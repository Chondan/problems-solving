#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
	// Using DP
	int jump1(vector<int> &nums) {
		int n = nums.size();
		vector<int> jumps(n+1, INT_MAX);
		jumps[0] = 0;

		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if(nums[j] + j >= i) {
					jumps[i] = min(jumps[i], jumps[j] + 1);
				}
			}
		}
		return jumps[n-1];
	}
	// Optimal Solution
	int jump2(vector<int> &nums) {
		// steps -> current steps we can explore
		// jumps -> our ans
		// maxReach -> maximum where we can go
		// When steps become 0 means we need to jump and update
		// next steps based on maxReach

		// nums = [2, 3, 1, 1, 1, 1, 2, 1, 3]
		// jumps = 0
		// steps = 2
		// maxReach = 2
		// --- i = 1 ---
		// maxReach = max(2, 3 + 1) = 4
		// steps = 1
		// --- i = 2 ---
		// maxReach = max(4, 1 + 2) = 4
		// steps = 0
		// update steps to 4 - 2 = 2
		// jumps = 1
		// --- i = 3 ---
		// maxReach = max(4, 1 + 3) = 4
		// steps = 1
		// --- i = 4 ---
		// maxReach = max(4, 1 + 4) = 5
		// steps = 0
		// steps = 5 - 4 = 1
		// jumps = 2

		int n = nums.size();
		int steps = nums[0], jumps = 0, maxReach = nums[0];
		if (n == 1) return 0;
		for (int i = 1; i < n - 1; i++) {
			maxReach = max(maxReach, nums[i] + i);
			steps--;
			if (!steps) {
				steps = maxReach - i;
				jumps++;
			}
		}
		return jumps + 1;
	}
};

int main(void) {
	Solution solution;

	vector<int> array = { 2, 3, 1, 1, 1, 1, 2, 1, 3 };

	int minJump = solution.jump2(array);
	cout << "minJump: " << minJump << endl;
}
