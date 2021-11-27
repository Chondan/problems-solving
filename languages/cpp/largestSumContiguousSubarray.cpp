// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int maxSubArraySum(vector<int> arr);
};

int main(void) {
	Solution solution;
	vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	int ans = solution.maxSubArraySum(arr);
	cout << "ans: " << ans << endl;
}

int Solution::maxSubArraySum(vector<int> arr) {
	int maxAtTheLatestIndex = arr[0];
	int globalMax = maxAtTheLatestIndex;
	for (int i = 1; i < arr.size(); i++) {
		maxAtTheLatestIndex = max(arr[i], maxAtTheLatestIndex + arr[i]);	
		globalMax = max(globalMax, maxAtTheLatestIndex);
	}

	return globalMax;
}