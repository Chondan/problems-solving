#include <set>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n);
    bool helper(int n, unordered_map<int, bool> &memo);
    bool isHappy2(int n);
};

int main(void) {
	Solution solution;
	int input = 19;
	bool ans = solution.isHappy(input);
	bool ans2 = solution.isHappy2(input);
	cout << "ans2: " << ans2 << endl;
}

bool Solution::isHappy(int n) {
	unordered_map<int, bool> memo;
	return this->helper(n, memo);
}

bool Solution::helper(int n, unordered_map<int, bool> &memo) {
	if (n == 1) return true;
	bool isCycle = memo.find(n) != memo.end();
	if (n < 4 || isCycle) return false;

	memo[n] = true;
	int sumSquare = 0;
	while (n > 0) {
		sumSquare += pow(n % 10, 2);
		n /= 10;
	}
	return this->helper(sumSquare, memo);
}

bool Solution::isHappy2(int n) {
	int temp = n;
	set<int> memo;
	while (temp != 1) {
		cout << temp << endl;
		if (memo.count(temp)) return false;
		else memo.insert(temp);

		// sum square
		int sumSquare = 0;
		while (temp > 0) {
			sumSquare += pow(temp % 10, 2);
			temp /= 10;
		}
		temp = sumSquare;
	}
	return true;
}