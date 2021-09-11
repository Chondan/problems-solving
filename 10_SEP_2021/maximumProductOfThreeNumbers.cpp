#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int> &nums);
    int getProduct(vector<int> &nums, int index1, int index2, int index3);

    int maximumProduct2(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {1, 4, 2, 3};
    int ans = solution.maximumProduct2(nums);
    cout << "ans: " << ans << endl;
}

int Solution::maximumProduct(vector<int> &nums) {
    if (nums.size() == 3) return this->getProduct(nums, 0, 1, 2);

    // Sort asc
    sort(nums.begin(), nums.end());

    // Get all possible values
    int lastIndex = nums.size() - 1;
    int possibleMax1 = this->getProduct(nums, 0, 1, 2); // first 3 
    int possibleMax2 = this->getProduct(nums, lastIndex, lastIndex - 1, lastIndex - 2); // last 3
    int possibleMax3 = this->getProduct(nums, 0, 1, lastIndex); // first2 + last1
    int possibleMax4 = this->getProduct(nums, 0, lastIndex, lastIndex - 1); // first1 + last2

    return max(max(possibleMax1, possibleMax2), max(possibleMax3, possibleMax4));
}

int Solution::getProduct(vector<int> &nums, int index1, int index2, int index3) {
    return nums[index1] * nums[index2] * nums[index3];
}

/* Another approach which is better: Single Scan
    We need not necessarily sort the given nums array to find the maximum product.
    Instead, we can only find the required 2 smallest values(min1 and min2) and
    three lasrgest values(max1, max2, max3) in the nums array, by iterating over 
    the nums array only once.
*/
int Solution::maximumProduct2(vector<int> &nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

    for (int num: nums) {
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num <= min2) {
            min2 = num;
        }  

        if (num >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num >= max2) {
            max3 = max2;
            max2 = num;
        } else if (num >= max3) {
            max3 = num;
        }
    }
    return max(min1 * min2 * max1, max1 * max2 * max3);
}