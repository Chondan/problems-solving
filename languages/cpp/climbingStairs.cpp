#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n);
};

int Solution::climbStairs(int n) {
	Solution solution;
	static unordered_map<int, int> memo;

	if (memo.find(n) != memo.end()) return memo[n];
	if (n == 1 || n == 2 || n == 3) return n;


	int ans = 0;
	for (int i = 1; i <= 2; i++) {
		int remain = n - i;
		ans += solution.climbStairs(remain);
	}
	memo[n] = ans;
	return memo[n];
}