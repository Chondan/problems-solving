#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProductDifference(vector<int> &nums);
    // Another approach which is faster
    int maxProductDifference2(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> input = {5, 6, 2, 7, 4};
    int ans = solution.maxProductDifference2(input);
    cout << "ans: " << ans << endl;
}

int Solution::maxProductDifference(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    return nums[len - 1] * nums[len - 2] - nums[0] * nums[1];
}

int Solution::maxProductDifference2(vector<int> &nums) {
    int firstMin = 10e4, secondMin = 10e4;
    int firstMax = INT_MIN, secondMax = INT_MIN;

    for (int num: nums) {
        if (num > firstMax) {
            secondMax = firstMax;
            firstMax = num;
        } else {
            secondMax = max(secondMax, num);
        }

        if (num < firstMin) {
            secondMin = firstMin;
            firstMin = num;
        } else {
            secondMin = min(secondMin, num);
        }
    }

    return firstMax*secondMax - firstMin*secondMin;
}