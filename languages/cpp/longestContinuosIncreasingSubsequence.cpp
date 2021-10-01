#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {1,3,5,4,7};
    int ans = solution.findLengthOfLCIS(nums);
    cout << "ans: " << ans << endl;
}

int Solution::findLengthOfLCIS(vector<int> &nums) {
    int count = 1;
    int ans = count;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            ans = max(ans, count);
            count = 1;
        } else {
            count ++;
        }
    }

    return max(ans, count);
}