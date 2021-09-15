#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {3,2,1};
    int ans = solution.findLHS(nums);
    cout << "ans: " << ans << endl;
}

int Solution::findLHS(vector<int> &nums) {
    unordered_map<int, int> freq;
    for (int num: nums) {
        ++freq[num];
    }

    int ans = 0;
    for (int num: nums) {
        if (freq.find(num + 1) != freq.end()) {
            ans = max(ans, freq[num] + freq[num + 1]);
        }
    }

    return ans;
}