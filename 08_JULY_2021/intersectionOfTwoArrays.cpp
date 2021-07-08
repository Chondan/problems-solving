#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "../util/util.h"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2);
    vector<int> intersection2(vector<int> &nums1, vector<int> &nums2);
};

int main(void) {
    Solution solution;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> ans = solution.intersection2(nums1, nums2);
    cout << "ans:" << endl;
    displayVector(ans);
}

vector<int> Solution::intersection(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> memo;
    for (int num: nums1) {
        if (memo.find(num) == memo.end()) {
            memo[num] = 1;
        }
    }

    vector<int> ans;
    for (int num: nums2) {
        if (memo.find(num) != memo.end()) {
            if (memo[num] != 0) {
                ans.push_back(num);
                memo[num]--;
            }
        }
    }

    return ans;
}

vector<int> Solution::intersection2(vector<int> &nums1, vector<int> &nums2) {
    unordered_set<int> memo;
    for (int num: nums1) {
        memo.insert(num);
    }

    vector<int> ans;
    for (int num: nums2) {
        if (memo.find(num) != memo.end()) {
            ans.push_back(num);
            memo.erase(num);
        }
    }

    return ans;
}
