#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = solution.findDisappearedNumbers(nums);
    cout << "ans:" << endl;
    displayVector<int>(ans);
}

vector<int> Solution::findDisappearedNumbers(vector<int> &nums) {
    vector<int> frequency(nums.size(), 0);
    for (int num: nums) {
        int index = num - 1;
        frequency[index]++;
    }

    vector<int> ans;
    for (int i = 0; i < nums.size(); i++) {
        if (frequency[i] == 0) {
            int num = i + 1;
            ans.push_back(num);
        }
    }

    return ans;
}