#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int> &nums);
};

int main(void) {
    Solution solution;
    vector<int> nums = {1,2,2,3,1,4,2};
    int ans = solution.findShortestSubArray(nums);
    cout << "ans: " << ans << endl;
}

int Solution::findShortestSubArray(vector<int> &nums) {
    unordered_map<int, vector<int>> indices;
    int maxFreq = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];

        if (indices.find(num) == indices.end()) {
            indices[num].push_back(1); // store the length of array
        } else {
            indices[num][0]++;
        }

        indices[num].push_back(i);
        int freq = indices[num][0];
        maxFreq = max(maxFreq, freq);
    }

    int ans = INT_MAX;
    for (auto index: indices) {
        int freq = index.second[0];
        if (freq == maxFreq) {
            int firstIndex = index.second[1];
            int lastIndex = index.second[freq];

            ans = min(ans, lastIndex - firstIndex + 1);
        }
    }

    return ans;
}