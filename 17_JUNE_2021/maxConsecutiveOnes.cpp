#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums);
};

int main(void) {
	Solution solution;
	vector<int> input = {1, 1, 0, 1, 1, 1};
	int ans = solution.findMaxConsecutiveOnes(input); // 3
	cout << "ans: " << ans << endl;
}

int Solution::findMaxConsecutiveOnes(vector<int> &nums) {

	int ans = INT_MIN;
	int con = 0;
	for (auto num: nums) {
		if (num == 1) {
			con++;
		} else {
			ans = max(ans, con);
			con = 0;
		}
	}
	ans = max(ans, con);

	return ans;
}