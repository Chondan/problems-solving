#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {0, 0, 3, 2};
    int ans = solution.dominantIndex(nums);
    cout << "ans: " << ans << endl;
}

int Solution::dominantIndex(vector<int> &nums) {
    int twiceMax = INT_MIN, actuallyMax = INT_MIN;
    int maxIndex = -1;
    for (int i = 0; i < nums.size(); i++) {
        int candidate = nums[i];

        int currentTwice = 2 * candidate;
        actuallyMax = max(actuallyMax, candidate);

        if (actuallyMax < currentTwice) {
            maxIndex = actuallyMax * 2 == currentTwice && actuallyMax >= twiceMax ? i : -1;
        }

        twiceMax = max(twiceMax, candidate * 2);
    }

    return maxIndex;
}