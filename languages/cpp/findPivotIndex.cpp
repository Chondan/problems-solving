#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> &nums);
    int pivotIndex2(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {1,7,3,6,5,6};
    int ans = solution.pivotIndex2(nums);
    cout << "ans: " << ans << endl;
}

int Solution::pivotIndex(vector<int> &nums) {

    int len = nums.size();

    int prefixSum[len + 1];
    prefixSum[0] = 0;

    // Get prefixSum and totalSum first
    for (int i = 0; i < len; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    // Find pivot index
    int totalSum = prefixSum[len];
    for (int j = 0; j < len; j++) {
        int leftSideSum = prefixSum[j + 1] - nums[j];
        int rightSideSum = totalSum - prefixSum[j + 1];

        if (leftSideSum == rightSideSum) return j;
    }

    return -1;
}

// Another approach which is more simple
int Solution::pivotIndex2(vector<int> &nums) {
    int len = nums.size();

    // Find totalSum
    int totalSum = 0;
    for (int num: nums) {
        totalSum += num;
    }

    // Find pivot index
    int leftSum = 0;
    for (int i = 0; i < len; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (rightSum == leftSum) return i;
        leftSum += nums[i];
    }

    return -1;
}