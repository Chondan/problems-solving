#include <iostream>
#include <vector>
#include "./utils/util.h"
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = solution.findDuplicates(nums);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::findDuplicates(vector<int> &nums) {
    vector<int> duplicates;

    for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        int absValue = abs(value);
        int index = absValue - 1;

        if (nums[index] < 0) {
            duplicates.push_back(absValue);
        } else {
            nums[index] *= -1;
        }
    }

    return duplicates;
}